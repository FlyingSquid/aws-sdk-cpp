/*
 * Copyright 2010-2016 Amazon.com, Inc. or its affiliates. All Rights Reserved.
 *
 * Licensed under the Apache License, Version 2.0 (the "License").
 * You may not use this file except in compliance with the License.
 * A copy of the License is located at
 *
 *  http://aws.amazon.com/apache2.0
 *
 * or in the "license" file accompanying this file. This file is distributed
 * on an "AS IS" BASIS, WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either
 * express or implied. See the License for the specific language governing
 * permissions and limitations under the License.
 */

#include <aws/core/client/AWSClient.h>
#include <aws/core/AmazonWebServiceRequest.h>
#include <aws/core/auth/AWSAuthSigner.h>
#include <aws/core/client/AWSError.h>
#include <aws/core/client/AWSErrorMarshaller.h>
#include <aws/core/client/ClientConfiguration.h>
#include <aws/core/client/CoreErrors.h>
#include <aws/core/client/RetryStrategy.h>
#include <aws/core/http/HttpClient.h>
#include <aws/core/http/HttpClientFactory.h>
#include <aws/core/http/HttpResponse.h>
#include <aws/core/utils/stream/ResponseStream.h>
#include <aws/core/utils/json/JsonSerializer.h>
#include <aws/core/utils/Outcome.h>
#include <aws/core/utils/StringUtils.h>
#include <aws/core/utils/xml/XmlSerializer.h>
#include <aws/core/utils/memory/stl/AWSStringStream.h>
#include <aws/core/utils/logging/LogMacros.h>
#include <aws/core/Globals.h>
#include <thread>


using namespace Aws;
using namespace Aws::Client;
using namespace Aws::Http;
using namespace Aws::Utils;
using namespace Aws::Utils::Json;
using namespace Aws::Utils::Xml;

static const int SUCCESS_RESPONSE_MIN = 200;
static const int SUCCESS_RESPONSE_MAX = 299;
static const char* LOG_TAG = "AWSClient";

std::atomic<int> AWSClient::s_refCount(0);

void AWSClient::InitializeGlobalStatics()
{
    int currentRefCount = s_refCount.load();
    if (!currentRefCount)
    {      
        int expectedRefCount = 0;    
        Utils::EnumParseOverflowContainer* expectedPtrValue = nullptr;
        Utils::EnumParseOverflowContainer* container = Aws::New<Utils::EnumParseOverflowContainer>(LOG_TAG);        
        if (!s_refCount.compare_exchange_strong(expectedRefCount, 1) ||
             !g_enumOverflow.compare_exchange_strong(expectedPtrValue, container))
        {
            Aws::Delete(container);
        }        
    }
    else
    {
        ++s_refCount;
    }
}

void AWSClient::CleanupGlobalStatics()
{
    int currentRefCount = s_refCount.load(); 
    Utils::EnumParseOverflowContainer* expectedPtrValue = g_enumOverflow.load();

    if (currentRefCount == 1)
    {
        if (s_refCount.compare_exchange_strong(currentRefCount, 0) &&
             g_enumOverflow.compare_exchange_strong(expectedPtrValue, nullptr))
        {
            Aws::Delete(expectedPtrValue);           
            return;
        }        
    }

    --s_refCount;
}

AWSClient::AWSClient(const std::shared_ptr<Aws::Http::HttpClientFactory const>& clientFactory,
    const Aws::Client::ClientConfiguration& configuration,
    const std::shared_ptr<Aws::Client::AWSAuthSigner>& signer,
    const std::shared_ptr<AWSErrorMarshaller>& errorMarshaller, const char* hostHeaderOverride) :
    m_clientFactory(clientFactory),
    m_httpClient(clientFactory->CreateHttpClient(configuration)),
    m_signer(signer),
    m_errorMarshaller(errorMarshaller),
    m_retryStrategy(configuration.retryStrategy),
    m_writeRateLimiter(configuration.writeRateLimiter),
    m_readRateLimiter(configuration.readRateLimiter),
    m_userAgent(configuration.userAgent),
    m_hostHeaderOverride(hostHeaderOverride)
{
    InitializeGlobalStatics();
}

AWSClient::~AWSClient()
{
    CleanupGlobalStatics();
}

void AWSClient::DisableRequestProcessing() 
{ 
    m_httpClient->DisableRequestProcessing(); 
}

void AWSClient::EnableRequestProcessing() 
{ 
    m_httpClient->EnableRequestProcessing();
}

HttpResponseOutcome AWSClient::AttemptExhaustively(const Aws::String& uri,
    const Aws::AmazonWebServiceRequest& request,
    HttpMethod method) const
{
    for (long retries = 0;; retries++)
    {
        HttpResponseOutcome outcome = AttemptOneRequest(uri, request, method);
        if (outcome.IsSuccess() || !m_retryStrategy->ShouldRetry(outcome.GetError(), retries))
        {
            AWS_LOG_TRACE(LOG_TAG, "Request was either successful, or we are now out of retries.");
            return outcome;
        }
        else if(!m_httpClient->IsRequestProcessingEnabled())
        {
            AWS_LOG_TRACE(LOG_TAG, "Request was cancelled externally.");
            return outcome;
        }
        else
        {
            long sleepMillis = m_retryStrategy->CalculateDelayBeforeNextRetry(outcome.GetError(), retries);
            AWS_LOG_WARN(LOG_TAG, "Request failed, now waiting %d ms before attempting again.", sleepMillis);
            m_httpClient->RetryRequestSleep(std::chrono::milliseconds(sleepMillis));
        }
    }
}

HttpResponseOutcome AWSClient::AttemptExhaustively(const Aws::String& uri, HttpMethod method) const
{
    for (long retries = 0;; retries++)
    {
        HttpResponseOutcome outcome = AttemptOneRequest(uri, method);
        if (outcome.IsSuccess() || !m_retryStrategy->ShouldRetry(outcome.GetError(), retries))
        {
            return outcome;
        }
        else
        {
            long sleepMillis = m_retryStrategy->CalculateDelayBeforeNextRetry(outcome.GetError(), retries);
            m_httpClient->RetryRequestSleep(std::chrono::milliseconds(sleepMillis));
        }
    }
}

static bool DoesResponseGenerateError(const std::shared_ptr<HttpResponse>& response)
{
    if (!response) return true;

    int responseCode = static_cast<int>(response->GetResponseCode());
    return response == nullptr || responseCode < SUCCESS_RESPONSE_MIN || responseCode > SUCCESS_RESPONSE_MAX;

}


HttpResponseOutcome AWSClient::AttemptOneRequest(const Aws::String& uri,
    const Aws::AmazonWebServiceRequest& request,
    HttpMethod method) const
{
    std::shared_ptr<HttpRequest> httpRequest(m_clientFactory->CreateHttpRequest(uri, method, request.GetResponseStreamFactory()));
    BuildHttpRequest(request, httpRequest);

    if (!m_signer->SignRequest(*httpRequest))
    {
        AWS_LOG_ERROR(LOG_TAG, "Request signing failed. Returning error.");
        return HttpResponseOutcome(); // TODO: make a real error when error revamp reaches branch (SIGNING_ERROR)
    }

    AWS_LOG_DEBUG(LOG_TAG, "Request Successfully signed");
    std::shared_ptr<HttpResponse> httpResponse(
        m_httpClient->MakeRequest(*httpRequest, m_readRateLimiter.get(), m_writeRateLimiter.get()));

    if (DoesResponseGenerateError(httpResponse))
    {
        AWS_LOG_DEBUG(LOG_TAG, "Request returned error. Attempting to generate appropriate error codes from response");
        return HttpResponseOutcome(BuildAWSError(httpResponse));
    }

    AWS_LOG_DEBUG(LOG_TAG, "Request returned successful response.");

    return HttpResponseOutcome(httpResponse);
}

HttpResponseOutcome AWSClient::AttemptOneRequest(const Aws::String& uri, HttpMethod method) const
{
    std::shared_ptr<HttpRequest> httpRequest(m_clientFactory->CreateHttpRequest(uri, method, Aws::Utils::Stream::DefaultResponseStreamFactoryMethod));
    AddCommonHeaders(*httpRequest);

    if (!m_signer->SignRequest(*httpRequest))
    {
        AWS_LOG_ERROR(LOG_TAG, "Request signing failed. Returning error.");
        return HttpResponseOutcome(); // TODO: make a real error when error revamp reaches branch (SIGNING_ERROR)
    }

    AWS_LOG_DEBUG(LOG_TAG, "Request Successfully signed");
    std::shared_ptr<HttpResponse> httpResponse(
        m_httpClient->MakeRequest(*httpRequest, m_readRateLimiter.get(), m_writeRateLimiter.get()));

    if (DoesResponseGenerateError(httpResponse))
    {
        AWS_LOG_DEBUG(LOG_TAG, "Request returned error. Attempting to generate appropriate error codes from response");
        return HttpResponseOutcome(BuildAWSError(httpResponse));
    }

    AWS_LOG_DEBUG(LOG_TAG, "Request returned successful response.");

    return HttpResponseOutcome(httpResponse);
}

StreamOutcome AWSClient::MakeRequestWithUnparsedResponse(const Aws::String& uri,
    const Aws::AmazonWebServiceRequest& request,
    Http::HttpMethod method) const
{
    HttpResponseOutcome httpResponseOutcome = AttemptExhaustively(uri, request, method);
    if (httpResponseOutcome.IsSuccess())
    {
        return StreamOutcome(AmazonWebServiceResult<Stream::ResponseStream>(
            httpResponseOutcome.GetResult()->SwapResponseStreamOwnership(),
            httpResponseOutcome.GetResult()->GetHeaders(), httpResponseOutcome.GetResult()->GetResponseCode()));
    }

    return StreamOutcome(httpResponseOutcome.GetError());
}

void AWSClient::AddHeadersToRequest(const std::shared_ptr<Aws::Http::HttpRequest>& httpRequest,
    const Http::HeaderValueCollection& headerValues) const
{
    for (auto const& headerValue : headerValues)
    {
        httpRequest->SetHeaderValue(headerValue.first, headerValue.second);
    }

    AddCommonHeaders(*httpRequest);

}

void AWSClient::AddContentBodyToRequest(const std::shared_ptr<Aws::Http::HttpRequest>& httpRequest,
    const std::shared_ptr<Aws::IOStream>& body) const
{
    httpRequest->AddContentBody(body);

    //If there is no body, we have a content length of 0
    if (!body)
    {
        AWS_LOG_TRACE(LOG_TAG, "No content body, removing content-type and content-length headers");
        httpRequest->DeleteHeader(Http::CONTENT_LENGTH_HEADER);
        httpRequest->DeleteHeader(Http::CONTENT_TYPE_HEADER);
    }
    //in the scenario where we are adding a content body as a stream, the request object likely already
    //has a content-length header set and we don't want to seek the stream just to find this information.
    if (body && !httpRequest->HasHeader(Http::CONTENT_LENGTH_HEADER))
    {
        AWS_LOG_TRACE(LOG_TAG, "Found body, but content-length has not been set, attempting to compute content-length");
        body->seekg(0, body->end);
        auto streamSize = body->tellg();
        body->seekg(0, body->beg);
        if (streamSize > 0)
        {
            Aws::StringStream ss;
            ss << streamSize;
            httpRequest->SetContentLength(ss.str());
        }
    }
}

void AWSClient::BuildHttpRequest(const Aws::AmazonWebServiceRequest& request,
    const std::shared_ptr<HttpRequest>& httpRequest) const
{
    //do headers first since the request likely will set content-length as it's own header.
    AddHeadersToRequest(httpRequest, request.GetHeaders());
    AddContentBodyToRequest(httpRequest, request.GetBody());

    // Pass along handlers for processing data sent/received in bytes
    httpRequest->SetDataReceivedEventHandler(request.GetDataReceivedEventHandler());
    httpRequest->SetDataSentEventHandler(request.GetDataSentEventHandler());

    request.AddQueryStringParameters(httpRequest->GetUri());
}

void AWSClient::AddCommonHeaders(HttpRequest& httpRequest) const
{
    if (m_hostHeaderOverride)
    {
        httpRequest.SetHeaderValue(Http::HOST_HEADER, m_hostHeaderOverride);
    }

    httpRequest.SetUserAgent(m_userAgent);
}

Aws::String AWSClient::GeneratePresignedUrl(URI& uri, HttpMethod method, long long expirationInSeconds)
{
    std::shared_ptr<HttpRequest> request = m_clientFactory->CreateHttpRequest(uri, method, Aws::Utils::Stream::DefaultResponseStreamFactoryMethod);
    if (m_signer->PresignRequest(*request, expirationInSeconds))
    {
        return request->GetURIString();
    }

    return "";
}

////////////////////////////////////////////////////////////////////////////
AWSJsonClient::AWSJsonClient(const std::shared_ptr<Aws::Http::HttpClientFactory const>& clientFactory,
    const Aws::Client::ClientConfiguration& configuration,
    const std::shared_ptr<Aws::Client::AWSAuthSigner>& signer,
    const std::shared_ptr<AWSErrorMarshaller>& errorMarshaller,
    const char* hostHeaderOverride) :
    BASECLASS(clientFactory, configuration, signer, errorMarshaller, hostHeaderOverride)
{
}

JsonOutcome AWSJsonClient::MakeRequest(const Aws::String& uri,
    const Aws::AmazonWebServiceRequest& request,
    Http::HttpMethod method) const
{
    HttpResponseOutcome httpOutcome(BASECLASS::AttemptExhaustively(uri, request, method));
    if (!httpOutcome.IsSuccess())
    {
        return JsonOutcome(httpOutcome.GetError());
    }

    if (httpOutcome.GetResult()->GetResponseBody().tellp() > 0)
        //this is stupid, but gcc doesn't pick up the covariant on the dereference so we have to give it a little hint.
        return JsonOutcome(AmazonWebServiceResult<JsonValue>(JsonValue(httpOutcome.GetResult()->GetResponseBody()),
        httpOutcome.GetResult()->GetHeaders(),
        httpOutcome.GetResult()->GetResponseCode()));

    else
        return JsonOutcome(AmazonWebServiceResult<JsonValue>(JsonValue(), httpOutcome.GetResult()->GetHeaders()));
}

JsonOutcome AWSJsonClient::MakeRequest(const Aws::String& uri,
    Http::HttpMethod method) const
{
    HttpResponseOutcome httpOutcome(BASECLASS::AttemptExhaustively(uri, method));
    if (!httpOutcome.IsSuccess())
    {
        return JsonOutcome(httpOutcome.GetError());
    }

    if (httpOutcome.GetResult()->GetResponseBody().tellp() > 0)
    {
        JsonValue jsonValue(httpOutcome.GetResult()->GetResponseBody());
        if (!jsonValue.WasParseSuccessful())
        {
            return JsonOutcome(AWSError<CoreErrors>(CoreErrors::UNKNOWN, "Json Parser Error", jsonValue.GetErrorMessage(), false));
        }

        //this is stupid, but gcc doesn't pick up the covariant on the dereference so we have to give it a little hint.
        return JsonOutcome(AmazonWebServiceResult<JsonValue>(std::move(jsonValue),
            httpOutcome.GetResult()->GetHeaders(),
            httpOutcome.GetResult()->GetResponseCode()));
    }

    return JsonOutcome(AmazonWebServiceResult<JsonValue>(JsonValue(), httpOutcome.GetResult()->GetHeaders()));
}

const char* MESSAGE_LOWER_CASE = "message";
const char* MESSAGE_CAMEL_CASE = "Message";
const char* ERROR_TYPE_HEADER = "x-amzn-ErrorType";
const char* TYPE = "__type";

AWSError<CoreErrors> AWSJsonClient::BuildAWSError(
    const std::shared_ptr<Aws::Http::HttpResponse>& httpResponse) const
{
    if (!httpResponse)
    {
        return AWSError<CoreErrors>(CoreErrors::NETWORK_CONNECTION, "", "Unable to connect to endpoint", true);
    }

    if (!httpResponse->GetResponseBody() || httpResponse->GetResponseBody().tellp() < 1)
    {
        Aws::StringStream ss;
        ss << "No response body.  Response code: " << httpResponse->GetResponseCode();
        AWS_LOG_ERROR(LOG_TAG, ss.str().c_str());
        return AWSError<CoreErrors>(CoreErrors::UNKNOWN, "", ss.str(), false);
    }

    assert(httpResponse->GetResponseCode() != HttpResponseCode::OK);

    //this is stupid, but gcc doesn't pick up the covariant on the dereference so we have to give it a little hint.
    JsonValue exceptionPayload(httpResponse->GetResponseBody());
    AWS_LOGSTREAM_TRACE(LOG_TAG, "Error response is " << exceptionPayload.WriteReadable());

    Aws::String message(exceptionPayload.ValueExists(MESSAGE_CAMEL_CASE) ? exceptionPayload.GetString(MESSAGE_CAMEL_CASE) :
        exceptionPayload.ValueExists(MESSAGE_LOWER_CASE) ? exceptionPayload.GetString(MESSAGE_LOWER_CASE) : "");

    if (httpResponse->HasHeader(ERROR_TYPE_HEADER))
    {
        return GetErrorMarshaller()->Marshall(httpResponse->GetHeader(ERROR_TYPE_HEADER), message);
    }
    else if (exceptionPayload.ValueExists(TYPE))
    {
        return GetErrorMarshaller()->Marshall(exceptionPayload.GetString(TYPE), message);
    }

    return AWSError<CoreErrors>(CoreErrors::UNKNOWN, "", message, false);
}

/////////////////////////////////////////////////////////////////////////////////////////

AWSXMLClient::AWSXMLClient(const std::shared_ptr<Aws::Http::HttpClientFactory const>& clientFactory,
    const Aws::Client::ClientConfiguration& configuration,
    const std::shared_ptr<Aws::Client::AWSAuthSigner>& signer,
    const std::shared_ptr<AWSErrorMarshaller>& errorMarshaller,
    const char* hostHeaderOverride) :
    BASECLASS(clientFactory, configuration, signer, errorMarshaller, hostHeaderOverride)
{
}

XmlOutcome AWSXMLClient::MakeRequest(const Aws::String& uri,
    const Aws::AmazonWebServiceRequest& request,
    Http::HttpMethod method) const
{
    HttpResponseOutcome httpOutcome(BASECLASS::AttemptExhaustively(uri, request, method));
    if (!httpOutcome.IsSuccess())
    {
        return XmlOutcome(httpOutcome.GetError());
    }

    if (httpOutcome.GetResult()->GetResponseBody().tellp() > 0)
    {
        XmlDocument xmlDoc = XmlDocument::CreateFromXmlStream(httpOutcome.GetResult()->GetResponseBody());

        if (!xmlDoc.WasParseSuccessful())
        {
            AWS_LOG_ERROR(LOG_TAG, "Xml parsing for error failed with message %s", xmlDoc.GetErrorMessage().c_str());
            return AWSError<CoreErrors>(CoreErrors::UNKNOWN, "Xml Parse Error", xmlDoc.GetErrorMessage(), false);
        }

        return XmlOutcome(AmazonWebServiceResult<XmlDocument>(std::move(xmlDoc),
            httpOutcome.GetResult()->GetHeaders(), httpOutcome.GetResult()->GetResponseCode()));
    }

    return XmlOutcome(AmazonWebServiceResult<XmlDocument>(XmlDocument(), httpOutcome.GetResult()->GetHeaders()));
}

XmlOutcome AWSXMLClient::MakeRequest(const Aws::String& uri,
    Http::HttpMethod method) const
{
    HttpResponseOutcome httpOutcome(BASECLASS::AttemptExhaustively(uri, method));
    if (!httpOutcome.IsSuccess())
    {
        return XmlOutcome(httpOutcome.GetError());
    }

    if (httpOutcome.GetResult()->GetResponseBody().tellp() > 0)
    {
        return XmlOutcome(AmazonWebServiceResult<XmlDocument>(
            XmlDocument::CreateFromXmlStream(httpOutcome.GetResult()->GetResponseBody()),
            httpOutcome.GetResult()->GetHeaders(), httpOutcome.GetResult()->GetResponseCode()));
    }

    return XmlOutcome(AmazonWebServiceResult<XmlDocument>(XmlDocument(), httpOutcome.GetResult()->GetHeaders()));
}

AWSError<CoreErrors> AWSXMLClient::BuildAWSError(const std::shared_ptr<Http::HttpResponse>& httpResponse) const
{
    if (!httpResponse)
    {
        return AWSError<CoreErrors>(CoreErrors::NETWORK_CONNECTION, "", "Unable to connect to endpoint", true);
    }

    if (httpResponse->GetResponseBody().tellp() < 1)
    {
        Aws::StringStream ss;
        ss << "No response body.  Response code: " << httpResponse->GetResponseCode();
        AWS_LOG_ERROR(LOG_TAG, ss.str().c_str());
        return AWSError<CoreErrors>(CoreErrors::UNKNOWN, "", ss.str(), false);
    }

    assert(httpResponse->GetResponseCode() != HttpResponseCode::OK);

    // When trying to build an AWS Error from a response which is an FStream, we need to rewind the
    // file pointer back to the beginning in order to correctly read the input using the XML string iterator
    if ((httpResponse->GetResponseBody().tellp() > 0)
        && (httpResponse->GetResponseBody().tellg() > 0))
    {
        httpResponse->GetResponseBody().seekg(0);
    }

    XmlDocument doc = XmlDocument::CreateFromXmlStream(httpResponse->GetResponseBody());
    AWS_LOGSTREAM_TRACE(LOG_TAG, "Error response is " << doc.ConvertToString());
    if (doc.WasParseSuccessful())
    {
        XmlNode errorNode = doc.GetRootElement();
        if (errorNode.GetName() != "Error")
        {
            errorNode = doc.GetRootElement().FirstChild("Error");
        }

        if (!errorNode.IsNull())
        {
            XmlNode codeNode = errorNode.FirstChild("Code");
            XmlNode messageNode = errorNode.FirstChild("Message");

            if (!(codeNode.IsNull() || messageNode.IsNull()))
            {
                return GetErrorMarshaller()->Marshall(StringUtils::Trim(codeNode.GetText().c_str()),
                    StringUtils::Trim(messageNode.GetText().c_str()));
            }
        }
    }

    // An error occurred attempting to parse the httpResponse as an XML stream, so we're just
    // going to dump the XML parsing error and the http response code as a string
    Aws::StringStream ss;
    ss << "Unable to generate a proper httpResponse from the response stream.   Response code: " << httpResponse->GetResponseCode();
    return GetErrorMarshaller()->Marshall(StringUtils::Trim(doc.GetErrorMessage().c_str()), ss.str().c_str());

}
