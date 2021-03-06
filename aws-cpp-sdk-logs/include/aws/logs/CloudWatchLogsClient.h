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
#pragma once
#include <aws/logs/CloudWatchLogs_EXPORTS.h>
#include <aws/logs/CloudWatchLogsErrors.h>
#include <aws/core/client/AWSError.h>
#include <aws/core/client/ClientConfiguration.h>
#include <aws/core/client/AWSClient.h>
#include <aws/core/utils/memory/stl/AWSString.h>
#include <aws/core/utils/json/JsonSerializer.h>
#include <aws/logs/model/CreateExportTaskResult.h>
#include <aws/logs/model/DescribeDestinationsResult.h>
#include <aws/logs/model/DescribeExportTasksResult.h>
#include <aws/logs/model/DescribeLogGroupsResult.h>
#include <aws/logs/model/DescribeLogStreamsResult.h>
#include <aws/logs/model/DescribeMetricFiltersResult.h>
#include <aws/logs/model/DescribeSubscriptionFiltersResult.h>
#include <aws/logs/model/FilterLogEventsResult.h>
#include <aws/logs/model/GetLogEventsResult.h>
#include <aws/logs/model/PutDestinationResult.h>
#include <aws/logs/model/PutLogEventsResult.h>
#include <aws/logs/model/TestMetricFilterResult.h>
#include <aws/core/NoResult.h>
#include <aws/core/client/AsyncCallerContext.h>
#include <aws/core/http/HttpTypes.h>
#include <future>
#include <functional>

namespace Aws
{

namespace Http
{
  class HttpClient;
  class HttpClientFactory;
} // namespace Http

namespace Utils
{
  template< typename R, typename E> class Outcome;

namespace Threading
{
  class Executor;
} // namespace Threading

namespace Json
{
  class JsonValue;
} // namespace Json
} // namespace Utils

namespace Auth
{
  class AWSCredentials;
  class AWSCredentialsProvider;
} // namespace Auth

namespace Client
{
  class RetryStrategy;
} // namespace Client

namespace CloudWatchLogs
{

namespace Model
{
        class CancelExportTaskRequest;
        class CreateExportTaskRequest;
        class CreateLogGroupRequest;
        class CreateLogStreamRequest;
        class DeleteDestinationRequest;
        class DeleteLogGroupRequest;
        class DeleteLogStreamRequest;
        class DeleteMetricFilterRequest;
        class DeleteRetentionPolicyRequest;
        class DeleteSubscriptionFilterRequest;
        class DescribeDestinationsRequest;
        class DescribeExportTasksRequest;
        class DescribeLogGroupsRequest;
        class DescribeLogStreamsRequest;
        class DescribeMetricFiltersRequest;
        class DescribeSubscriptionFiltersRequest;
        class FilterLogEventsRequest;
        class GetLogEventsRequest;
        class PutDestinationRequest;
        class PutDestinationPolicyRequest;
        class PutLogEventsRequest;
        class PutMetricFilterRequest;
        class PutRetentionPolicyRequest;
        class PutSubscriptionFilterRequest;
        class TestMetricFilterRequest;

        typedef Aws::Utils::Outcome<NoResult, Aws::Client::AWSError<CloudWatchLogsErrors>> CancelExportTaskOutcome;
        typedef Aws::Utils::Outcome<CreateExportTaskResult, Aws::Client::AWSError<CloudWatchLogsErrors>> CreateExportTaskOutcome;
        typedef Aws::Utils::Outcome<NoResult, Aws::Client::AWSError<CloudWatchLogsErrors>> CreateLogGroupOutcome;
        typedef Aws::Utils::Outcome<NoResult, Aws::Client::AWSError<CloudWatchLogsErrors>> CreateLogStreamOutcome;
        typedef Aws::Utils::Outcome<NoResult, Aws::Client::AWSError<CloudWatchLogsErrors>> DeleteDestinationOutcome;
        typedef Aws::Utils::Outcome<NoResult, Aws::Client::AWSError<CloudWatchLogsErrors>> DeleteLogGroupOutcome;
        typedef Aws::Utils::Outcome<NoResult, Aws::Client::AWSError<CloudWatchLogsErrors>> DeleteLogStreamOutcome;
        typedef Aws::Utils::Outcome<NoResult, Aws::Client::AWSError<CloudWatchLogsErrors>> DeleteMetricFilterOutcome;
        typedef Aws::Utils::Outcome<NoResult, Aws::Client::AWSError<CloudWatchLogsErrors>> DeleteRetentionPolicyOutcome;
        typedef Aws::Utils::Outcome<NoResult, Aws::Client::AWSError<CloudWatchLogsErrors>> DeleteSubscriptionFilterOutcome;
        typedef Aws::Utils::Outcome<DescribeDestinationsResult, Aws::Client::AWSError<CloudWatchLogsErrors>> DescribeDestinationsOutcome;
        typedef Aws::Utils::Outcome<DescribeExportTasksResult, Aws::Client::AWSError<CloudWatchLogsErrors>> DescribeExportTasksOutcome;
        typedef Aws::Utils::Outcome<DescribeLogGroupsResult, Aws::Client::AWSError<CloudWatchLogsErrors>> DescribeLogGroupsOutcome;
        typedef Aws::Utils::Outcome<DescribeLogStreamsResult, Aws::Client::AWSError<CloudWatchLogsErrors>> DescribeLogStreamsOutcome;
        typedef Aws::Utils::Outcome<DescribeMetricFiltersResult, Aws::Client::AWSError<CloudWatchLogsErrors>> DescribeMetricFiltersOutcome;
        typedef Aws::Utils::Outcome<DescribeSubscriptionFiltersResult, Aws::Client::AWSError<CloudWatchLogsErrors>> DescribeSubscriptionFiltersOutcome;
        typedef Aws::Utils::Outcome<FilterLogEventsResult, Aws::Client::AWSError<CloudWatchLogsErrors>> FilterLogEventsOutcome;
        typedef Aws::Utils::Outcome<GetLogEventsResult, Aws::Client::AWSError<CloudWatchLogsErrors>> GetLogEventsOutcome;
        typedef Aws::Utils::Outcome<PutDestinationResult, Aws::Client::AWSError<CloudWatchLogsErrors>> PutDestinationOutcome;
        typedef Aws::Utils::Outcome<NoResult, Aws::Client::AWSError<CloudWatchLogsErrors>> PutDestinationPolicyOutcome;
        typedef Aws::Utils::Outcome<PutLogEventsResult, Aws::Client::AWSError<CloudWatchLogsErrors>> PutLogEventsOutcome;
        typedef Aws::Utils::Outcome<NoResult, Aws::Client::AWSError<CloudWatchLogsErrors>> PutMetricFilterOutcome;
        typedef Aws::Utils::Outcome<NoResult, Aws::Client::AWSError<CloudWatchLogsErrors>> PutRetentionPolicyOutcome;
        typedef Aws::Utils::Outcome<NoResult, Aws::Client::AWSError<CloudWatchLogsErrors>> PutSubscriptionFilterOutcome;
        typedef Aws::Utils::Outcome<TestMetricFilterResult, Aws::Client::AWSError<CloudWatchLogsErrors>> TestMetricFilterOutcome;

        typedef std::future<CancelExportTaskOutcome> CancelExportTaskOutcomeCallable;
        typedef std::future<CreateExportTaskOutcome> CreateExportTaskOutcomeCallable;
        typedef std::future<CreateLogGroupOutcome> CreateLogGroupOutcomeCallable;
        typedef std::future<CreateLogStreamOutcome> CreateLogStreamOutcomeCallable;
        typedef std::future<DeleteDestinationOutcome> DeleteDestinationOutcomeCallable;
        typedef std::future<DeleteLogGroupOutcome> DeleteLogGroupOutcomeCallable;
        typedef std::future<DeleteLogStreamOutcome> DeleteLogStreamOutcomeCallable;
        typedef std::future<DeleteMetricFilterOutcome> DeleteMetricFilterOutcomeCallable;
        typedef std::future<DeleteRetentionPolicyOutcome> DeleteRetentionPolicyOutcomeCallable;
        typedef std::future<DeleteSubscriptionFilterOutcome> DeleteSubscriptionFilterOutcomeCallable;
        typedef std::future<DescribeDestinationsOutcome> DescribeDestinationsOutcomeCallable;
        typedef std::future<DescribeExportTasksOutcome> DescribeExportTasksOutcomeCallable;
        typedef std::future<DescribeLogGroupsOutcome> DescribeLogGroupsOutcomeCallable;
        typedef std::future<DescribeLogStreamsOutcome> DescribeLogStreamsOutcomeCallable;
        typedef std::future<DescribeMetricFiltersOutcome> DescribeMetricFiltersOutcomeCallable;
        typedef std::future<DescribeSubscriptionFiltersOutcome> DescribeSubscriptionFiltersOutcomeCallable;
        typedef std::future<FilterLogEventsOutcome> FilterLogEventsOutcomeCallable;
        typedef std::future<GetLogEventsOutcome> GetLogEventsOutcomeCallable;
        typedef std::future<PutDestinationOutcome> PutDestinationOutcomeCallable;
        typedef std::future<PutDestinationPolicyOutcome> PutDestinationPolicyOutcomeCallable;
        typedef std::future<PutLogEventsOutcome> PutLogEventsOutcomeCallable;
        typedef std::future<PutMetricFilterOutcome> PutMetricFilterOutcomeCallable;
        typedef std::future<PutRetentionPolicyOutcome> PutRetentionPolicyOutcomeCallable;
        typedef std::future<PutSubscriptionFilterOutcome> PutSubscriptionFilterOutcomeCallable;
        typedef std::future<TestMetricFilterOutcome> TestMetricFilterOutcomeCallable;
} // namespace Model

  class CloudWatchLogsClient;

    typedef std::function<void(const CloudWatchLogsClient*, const Model::CancelExportTaskRequest&, const Model::CancelExportTaskOutcome&, const std::shared_ptr<const Aws::Client::AsyncCallerContext>&) > CancelExportTaskResponseReceivedHandler;
    typedef std::function<void(const CloudWatchLogsClient*, const Model::CreateExportTaskRequest&, const Model::CreateExportTaskOutcome&, const std::shared_ptr<const Aws::Client::AsyncCallerContext>&) > CreateExportTaskResponseReceivedHandler;
    typedef std::function<void(const CloudWatchLogsClient*, const Model::CreateLogGroupRequest&, const Model::CreateLogGroupOutcome&, const std::shared_ptr<const Aws::Client::AsyncCallerContext>&) > CreateLogGroupResponseReceivedHandler;
    typedef std::function<void(const CloudWatchLogsClient*, const Model::CreateLogStreamRequest&, const Model::CreateLogStreamOutcome&, const std::shared_ptr<const Aws::Client::AsyncCallerContext>&) > CreateLogStreamResponseReceivedHandler;
    typedef std::function<void(const CloudWatchLogsClient*, const Model::DeleteDestinationRequest&, const Model::DeleteDestinationOutcome&, const std::shared_ptr<const Aws::Client::AsyncCallerContext>&) > DeleteDestinationResponseReceivedHandler;
    typedef std::function<void(const CloudWatchLogsClient*, const Model::DeleteLogGroupRequest&, const Model::DeleteLogGroupOutcome&, const std::shared_ptr<const Aws::Client::AsyncCallerContext>&) > DeleteLogGroupResponseReceivedHandler;
    typedef std::function<void(const CloudWatchLogsClient*, const Model::DeleteLogStreamRequest&, const Model::DeleteLogStreamOutcome&, const std::shared_ptr<const Aws::Client::AsyncCallerContext>&) > DeleteLogStreamResponseReceivedHandler;
    typedef std::function<void(const CloudWatchLogsClient*, const Model::DeleteMetricFilterRequest&, const Model::DeleteMetricFilterOutcome&, const std::shared_ptr<const Aws::Client::AsyncCallerContext>&) > DeleteMetricFilterResponseReceivedHandler;
    typedef std::function<void(const CloudWatchLogsClient*, const Model::DeleteRetentionPolicyRequest&, const Model::DeleteRetentionPolicyOutcome&, const std::shared_ptr<const Aws::Client::AsyncCallerContext>&) > DeleteRetentionPolicyResponseReceivedHandler;
    typedef std::function<void(const CloudWatchLogsClient*, const Model::DeleteSubscriptionFilterRequest&, const Model::DeleteSubscriptionFilterOutcome&, const std::shared_ptr<const Aws::Client::AsyncCallerContext>&) > DeleteSubscriptionFilterResponseReceivedHandler;
    typedef std::function<void(const CloudWatchLogsClient*, const Model::DescribeDestinationsRequest&, const Model::DescribeDestinationsOutcome&, const std::shared_ptr<const Aws::Client::AsyncCallerContext>&) > DescribeDestinationsResponseReceivedHandler;
    typedef std::function<void(const CloudWatchLogsClient*, const Model::DescribeExportTasksRequest&, const Model::DescribeExportTasksOutcome&, const std::shared_ptr<const Aws::Client::AsyncCallerContext>&) > DescribeExportTasksResponseReceivedHandler;
    typedef std::function<void(const CloudWatchLogsClient*, const Model::DescribeLogGroupsRequest&, const Model::DescribeLogGroupsOutcome&, const std::shared_ptr<const Aws::Client::AsyncCallerContext>&) > DescribeLogGroupsResponseReceivedHandler;
    typedef std::function<void(const CloudWatchLogsClient*, const Model::DescribeLogStreamsRequest&, const Model::DescribeLogStreamsOutcome&, const std::shared_ptr<const Aws::Client::AsyncCallerContext>&) > DescribeLogStreamsResponseReceivedHandler;
    typedef std::function<void(const CloudWatchLogsClient*, const Model::DescribeMetricFiltersRequest&, const Model::DescribeMetricFiltersOutcome&, const std::shared_ptr<const Aws::Client::AsyncCallerContext>&) > DescribeMetricFiltersResponseReceivedHandler;
    typedef std::function<void(const CloudWatchLogsClient*, const Model::DescribeSubscriptionFiltersRequest&, const Model::DescribeSubscriptionFiltersOutcome&, const std::shared_ptr<const Aws::Client::AsyncCallerContext>&) > DescribeSubscriptionFiltersResponseReceivedHandler;
    typedef std::function<void(const CloudWatchLogsClient*, const Model::FilterLogEventsRequest&, const Model::FilterLogEventsOutcome&, const std::shared_ptr<const Aws::Client::AsyncCallerContext>&) > FilterLogEventsResponseReceivedHandler;
    typedef std::function<void(const CloudWatchLogsClient*, const Model::GetLogEventsRequest&, const Model::GetLogEventsOutcome&, const std::shared_ptr<const Aws::Client::AsyncCallerContext>&) > GetLogEventsResponseReceivedHandler;
    typedef std::function<void(const CloudWatchLogsClient*, const Model::PutDestinationRequest&, const Model::PutDestinationOutcome&, const std::shared_ptr<const Aws::Client::AsyncCallerContext>&) > PutDestinationResponseReceivedHandler;
    typedef std::function<void(const CloudWatchLogsClient*, const Model::PutDestinationPolicyRequest&, const Model::PutDestinationPolicyOutcome&, const std::shared_ptr<const Aws::Client::AsyncCallerContext>&) > PutDestinationPolicyResponseReceivedHandler;
    typedef std::function<void(const CloudWatchLogsClient*, const Model::PutLogEventsRequest&, const Model::PutLogEventsOutcome&, const std::shared_ptr<const Aws::Client::AsyncCallerContext>&) > PutLogEventsResponseReceivedHandler;
    typedef std::function<void(const CloudWatchLogsClient*, const Model::PutMetricFilterRequest&, const Model::PutMetricFilterOutcome&, const std::shared_ptr<const Aws::Client::AsyncCallerContext>&) > PutMetricFilterResponseReceivedHandler;
    typedef std::function<void(const CloudWatchLogsClient*, const Model::PutRetentionPolicyRequest&, const Model::PutRetentionPolicyOutcome&, const std::shared_ptr<const Aws::Client::AsyncCallerContext>&) > PutRetentionPolicyResponseReceivedHandler;
    typedef std::function<void(const CloudWatchLogsClient*, const Model::PutSubscriptionFilterRequest&, const Model::PutSubscriptionFilterOutcome&, const std::shared_ptr<const Aws::Client::AsyncCallerContext>&) > PutSubscriptionFilterResponseReceivedHandler;
    typedef std::function<void(const CloudWatchLogsClient*, const Model::TestMetricFilterRequest&, const Model::TestMetricFilterOutcome&, const std::shared_ptr<const Aws::Client::AsyncCallerContext>&) > TestMetricFilterResponseReceivedHandler;

  /**
   * <fullname>Amazon CloudWatch Logs API Reference</fullname> <p>This is the
   * <i>Amazon CloudWatch Logs API Reference</i>. Amazon CloudWatch Logs enables you
   * to monitor, store, and access your system, application, and custom log files.
   * This guide provides detailed information about Amazon CloudWatch Logs actions,
   * data types, parameters, and errors. For detailed information about Amazon
   * CloudWatch Logs features and their associated API calls, go to the <a
   * href="http://docs.aws.amazon.com/AmazonCloudWatch/latest/DeveloperGuide">Amazon
   * CloudWatch Developer Guide</a>. </p> <p>Use the following links to get started
   * using the <i>Amazon CloudWatch Logs API Reference</i>:</p> <ul> <li><a
   * href="http://docs.aws.amazon.com/AmazonCloudWatchLogs/latest/APIReference/API_Operations.html">Actions</a>:
   * An alphabetical list of all Amazon CloudWatch Logs actions.</li> <li><a
   * href="http://docs.aws.amazon.com/AmazonCloudWatchLogs/latest/APIReference/API_Types.html">Data
   * Types</a>: An alphabetical list of all Amazon CloudWatch Logs data types.</li>
   * <li><a
   * href="http://docs.aws.amazon.com/AmazonCloudWatchLogs/latest/APIReference/CommonParameters.html">Common
   * Parameters</a>: Parameters that all Query actions can use.</li> <li><a
   * href="http://docs.aws.amazon.com/AmazonCloudWatchLogs/latest/APIReference/CommonErrors.html">Common
   * Errors</a>: Client and server errors that all actions can return.</li> <li><a
   * href="http://docs.aws.amazon.com/general/latest/gr/index.html?rande.html">Regions
   * and Endpoints</a>: Itemized regions and endpoints for all AWS products.</li>
   * </ul> <p>In addition to using the Amazon CloudWatch Logs API, you can also use
   * the following SDKs and third-party libraries to access Amazon CloudWatch Logs
   * programmatically.</p> <ul> <li><a
   * href="http://aws.amazon.com/documentation/sdkforjava/">AWS SDK for Java
   * Documentation</a></li> <li><a
   * href="http://aws.amazon.com/documentation/sdkfornet/">AWS SDK for .NET
   * Documentation</a></li> <li><a
   * href="http://aws.amazon.com/documentation/sdkforphp/">AWS SDK for PHP
   * Documentation</a></li> <li><a
   * href="http://aws.amazon.com/documentation/sdkforruby/">AWS SDK for Ruby
   * Documentation</a></li> </ul> <p>Developers in the AWS developer community also
   * provide their own libraries, which you can find at the following AWS developer
   * centers:</p> <ul> <li><a href="http://aws.amazon.com/java/">AWS Java Developer
   * Center</a></li> <li><a href="http://aws.amazon.com/php/">AWS PHP Developer
   * Center</a></li> <li><a href="http://aws.amazon.com/python/">AWS Python Developer
   * Center</a></li> <li><a href="http://aws.amazon.com/ruby/">AWS Ruby Developer
   * Center</a></li> <li><a href="http://aws.amazon.com/net/">AWS Windows and .NET
   * Developer Center</a></li> </ul>
   */
  class AWS_CLOUDWATCHLOGS_API CloudWatchLogsClient : public Aws::Client::AWSJsonClient
  {
    public:
      typedef Aws::Client::AWSJsonClient BASECLASS;

       /**
        * Initializes client to use DefaultCredentialProviderChain, with default http client factory, and optional client config. If client config
        * is not specified, it will be initialized to default values.
        */
        CloudWatchLogsClient(const Client::ClientConfiguration& clientConfiguration = Client::ClientConfiguration());

       /**
        * Initializes client to use SimpleAWSCredentialsProvider, with default http client factory, and optional client config. If client config
        * is not specified, it will be initialized to default values.
        */
        CloudWatchLogsClient(const Auth::AWSCredentials& credentials, const Client::ClientConfiguration& clientConfiguration = Client::ClientConfiguration());

       /**
        * Initializes client to use specified credentials provider with specified client config. If http client factory is not supplied,
        * the default http client factory will be used
        */
        CloudWatchLogsClient(const std::shared_ptr<Auth::AWSCredentialsProvider>& credentialsProvider,
            const Client::ClientConfiguration& clientConfiguration = Client::ClientConfiguration(),
            const std::shared_ptr<Http::HttpClientFactory const>& httpClientFactory = nullptr);

        virtual ~CloudWatchLogsClient();

        /**
         * <p> Cancels an export task if it is in <code>PENDING</code> or
         * <code>RUNNING</code> state. </p>
         */
        virtual Model::CancelExportTaskOutcome CancelExportTask(const Model::CancelExportTaskRequest& request) const;

        /**
         * <p> Cancels an export task if it is in <code>PENDING</code> or
         * <code>RUNNING</code> state. </p>
         *
         * returns a future to the operation so that it can be executed in parallel to other requests.
         */
        virtual Model::CancelExportTaskOutcomeCallable CancelExportTaskCallable(const Model::CancelExportTaskRequest& request) const;

        /**
         * <p> Cancels an export task if it is in <code>PENDING</code> or
         * <code>RUNNING</code> state. </p>
         *
         * Queues the request into a thread executor and triggers associated callback when operation has finished.
         */
        virtual void CancelExportTaskAsync(const Model::CancelExportTaskRequest& request, const CancelExportTaskResponseReceivedHandler& handler, const std::shared_ptr<const Aws::Client::AsyncCallerContext>& context = nullptr) const;

        /**
         * <p> Creates an <code>ExportTask</code> which allows you to efficiently export
         * data from a Log Group to your Amazon S3 bucket. </p> <p> This is an asynchronous
         * call. If all the required information is provided, this API will initiate an
         * export task and respond with the task Id. Once started,
         * <code>DescribeExportTasks</code> can be used to get the status of an export
         * task. </p> <p> You can export logs from multiple log groups or multiple time
         * ranges to the same Amazon S3 bucket. To separate out log data for each export
         * task, you can specify a prefix that will be used as the Amazon S3 key prefix for
         * all exported objects. </p>
         */
        virtual Model::CreateExportTaskOutcome CreateExportTask(const Model::CreateExportTaskRequest& request) const;

        /**
         * <p> Creates an <code>ExportTask</code> which allows you to efficiently export
         * data from a Log Group to your Amazon S3 bucket. </p> <p> This is an asynchronous
         * call. If all the required information is provided, this API will initiate an
         * export task and respond with the task Id. Once started,
         * <code>DescribeExportTasks</code> can be used to get the status of an export
         * task. </p> <p> You can export logs from multiple log groups or multiple time
         * ranges to the same Amazon S3 bucket. To separate out log data for each export
         * task, you can specify a prefix that will be used as the Amazon S3 key prefix for
         * all exported objects. </p>
         *
         * returns a future to the operation so that it can be executed in parallel to other requests.
         */
        virtual Model::CreateExportTaskOutcomeCallable CreateExportTaskCallable(const Model::CreateExportTaskRequest& request) const;

        /**
         * <p> Creates an <code>ExportTask</code> which allows you to efficiently export
         * data from a Log Group to your Amazon S3 bucket. </p> <p> This is an asynchronous
         * call. If all the required information is provided, this API will initiate an
         * export task and respond with the task Id. Once started,
         * <code>DescribeExportTasks</code> can be used to get the status of an export
         * task. </p> <p> You can export logs from multiple log groups or multiple time
         * ranges to the same Amazon S3 bucket. To separate out log data for each export
         * task, you can specify a prefix that will be used as the Amazon S3 key prefix for
         * all exported objects. </p>
         *
         * Queues the request into a thread executor and triggers associated callback when operation has finished.
         */
        virtual void CreateExportTaskAsync(const Model::CreateExportTaskRequest& request, const CreateExportTaskResponseReceivedHandler& handler, const std::shared_ptr<const Aws::Client::AsyncCallerContext>& context = nullptr) const;

        /**
         * <p> Creates a new log group with the specified name. The name of the log group
         * must be unique within a region for an AWS account. You can create up to 500 log
         * groups per account. </p> <p> You must use the following guidelines when naming a
         * log group: <ul> <li>Log group names can be between 1 and 512 characters
         * long.</li> <li>Allowed characters are a-z, A-Z, 0-9, '_' (underscore), '-'
         * (hyphen), '/' (forward slash), and '.' (period).</li> </ul> </p>
         */
        virtual Model::CreateLogGroupOutcome CreateLogGroup(const Model::CreateLogGroupRequest& request) const;

        /**
         * <p> Creates a new log group with the specified name. The name of the log group
         * must be unique within a region for an AWS account. You can create up to 500 log
         * groups per account. </p> <p> You must use the following guidelines when naming a
         * log group: <ul> <li>Log group names can be between 1 and 512 characters
         * long.</li> <li>Allowed characters are a-z, A-Z, 0-9, '_' (underscore), '-'
         * (hyphen), '/' (forward slash), and '.' (period).</li> </ul> </p>
         *
         * returns a future to the operation so that it can be executed in parallel to other requests.
         */
        virtual Model::CreateLogGroupOutcomeCallable CreateLogGroupCallable(const Model::CreateLogGroupRequest& request) const;

        /**
         * <p> Creates a new log group with the specified name. The name of the log group
         * must be unique within a region for an AWS account. You can create up to 500 log
         * groups per account. </p> <p> You must use the following guidelines when naming a
         * log group: <ul> <li>Log group names can be between 1 and 512 characters
         * long.</li> <li>Allowed characters are a-z, A-Z, 0-9, '_' (underscore), '-'
         * (hyphen), '/' (forward slash), and '.' (period).</li> </ul> </p>
         *
         * Queues the request into a thread executor and triggers associated callback when operation has finished.
         */
        virtual void CreateLogGroupAsync(const Model::CreateLogGroupRequest& request, const CreateLogGroupResponseReceivedHandler& handler, const std::shared_ptr<const Aws::Client::AsyncCallerContext>& context = nullptr) const;

        /**
         * <p> Creates a new log stream in the specified log group. The name of the log
         * stream must be unique within the log group. There is no limit on the number of
         * log streams that can exist in a log group. </p> <p> You must use the following
         * guidelines when naming a log stream: <ul> <li>Log stream names can be between 1
         * and 512 characters long.</li> <li>The ':' colon character is not allowed.</li>
         * </ul> </p>
         */
        virtual Model::CreateLogStreamOutcome CreateLogStream(const Model::CreateLogStreamRequest& request) const;

        /**
         * <p> Creates a new log stream in the specified log group. The name of the log
         * stream must be unique within the log group. There is no limit on the number of
         * log streams that can exist in a log group. </p> <p> You must use the following
         * guidelines when naming a log stream: <ul> <li>Log stream names can be between 1
         * and 512 characters long.</li> <li>The ':' colon character is not allowed.</li>
         * </ul> </p>
         *
         * returns a future to the operation so that it can be executed in parallel to other requests.
         */
        virtual Model::CreateLogStreamOutcomeCallable CreateLogStreamCallable(const Model::CreateLogStreamRequest& request) const;

        /**
         * <p> Creates a new log stream in the specified log group. The name of the log
         * stream must be unique within the log group. There is no limit on the number of
         * log streams that can exist in a log group. </p> <p> You must use the following
         * guidelines when naming a log stream: <ul> <li>Log stream names can be between 1
         * and 512 characters long.</li> <li>The ':' colon character is not allowed.</li>
         * </ul> </p>
         *
         * Queues the request into a thread executor and triggers associated callback when operation has finished.
         */
        virtual void CreateLogStreamAsync(const Model::CreateLogStreamRequest& request, const CreateLogStreamResponseReceivedHandler& handler, const std::shared_ptr<const Aws::Client::AsyncCallerContext>& context = nullptr) const;

        /**
         * <p> Deletes the destination with the specified name and eventually disables all
         * the subscription filters that publish to it. This will not delete the physical
         * resource encapsulated by the destination. </p>
         */
        virtual Model::DeleteDestinationOutcome DeleteDestination(const Model::DeleteDestinationRequest& request) const;

        /**
         * <p> Deletes the destination with the specified name and eventually disables all
         * the subscription filters that publish to it. This will not delete the physical
         * resource encapsulated by the destination. </p>
         *
         * returns a future to the operation so that it can be executed in parallel to other requests.
         */
        virtual Model::DeleteDestinationOutcomeCallable DeleteDestinationCallable(const Model::DeleteDestinationRequest& request) const;

        /**
         * <p> Deletes the destination with the specified name and eventually disables all
         * the subscription filters that publish to it. This will not delete the physical
         * resource encapsulated by the destination. </p>
         *
         * Queues the request into a thread executor and triggers associated callback when operation has finished.
         */
        virtual void DeleteDestinationAsync(const Model::DeleteDestinationRequest& request, const DeleteDestinationResponseReceivedHandler& handler, const std::shared_ptr<const Aws::Client::AsyncCallerContext>& context = nullptr) const;

        /**
         * <p> Deletes the log group with the specified name and permanently deletes all
         * the archived log events associated with it. </p>
         */
        virtual Model::DeleteLogGroupOutcome DeleteLogGroup(const Model::DeleteLogGroupRequest& request) const;

        /**
         * <p> Deletes the log group with the specified name and permanently deletes all
         * the archived log events associated with it. </p>
         *
         * returns a future to the operation so that it can be executed in parallel to other requests.
         */
        virtual Model::DeleteLogGroupOutcomeCallable DeleteLogGroupCallable(const Model::DeleteLogGroupRequest& request) const;

        /**
         * <p> Deletes the log group with the specified name and permanently deletes all
         * the archived log events associated with it. </p>
         *
         * Queues the request into a thread executor and triggers associated callback when operation has finished.
         */
        virtual void DeleteLogGroupAsync(const Model::DeleteLogGroupRequest& request, const DeleteLogGroupResponseReceivedHandler& handler, const std::shared_ptr<const Aws::Client::AsyncCallerContext>& context = nullptr) const;

        /**
         * <p> Deletes a log stream and permanently deletes all the archived log events
         * associated with it. </p>
         */
        virtual Model::DeleteLogStreamOutcome DeleteLogStream(const Model::DeleteLogStreamRequest& request) const;

        /**
         * <p> Deletes a log stream and permanently deletes all the archived log events
         * associated with it. </p>
         *
         * returns a future to the operation so that it can be executed in parallel to other requests.
         */
        virtual Model::DeleteLogStreamOutcomeCallable DeleteLogStreamCallable(const Model::DeleteLogStreamRequest& request) const;

        /**
         * <p> Deletes a log stream and permanently deletes all the archived log events
         * associated with it. </p>
         *
         * Queues the request into a thread executor and triggers associated callback when operation has finished.
         */
        virtual void DeleteLogStreamAsync(const Model::DeleteLogStreamRequest& request, const DeleteLogStreamResponseReceivedHandler& handler, const std::shared_ptr<const Aws::Client::AsyncCallerContext>& context = nullptr) const;

        /**
         * <p> Deletes a metric filter associated with the specified log group. </p>
         */
        virtual Model::DeleteMetricFilterOutcome DeleteMetricFilter(const Model::DeleteMetricFilterRequest& request) const;

        /**
         * <p> Deletes a metric filter associated with the specified log group. </p>
         *
         * returns a future to the operation so that it can be executed in parallel to other requests.
         */
        virtual Model::DeleteMetricFilterOutcomeCallable DeleteMetricFilterCallable(const Model::DeleteMetricFilterRequest& request) const;

        /**
         * <p> Deletes a metric filter associated with the specified log group. </p>
         *
         * Queues the request into a thread executor and triggers associated callback when operation has finished.
         */
        virtual void DeleteMetricFilterAsync(const Model::DeleteMetricFilterRequest& request, const DeleteMetricFilterResponseReceivedHandler& handler, const std::shared_ptr<const Aws::Client::AsyncCallerContext>& context = nullptr) const;

        /**
         * <p> Deletes the retention policy of the specified log group. Log events would
         * not expire if they belong to log groups without a retention policy. </p>
         */
        virtual Model::DeleteRetentionPolicyOutcome DeleteRetentionPolicy(const Model::DeleteRetentionPolicyRequest& request) const;

        /**
         * <p> Deletes the retention policy of the specified log group. Log events would
         * not expire if they belong to log groups without a retention policy. </p>
         *
         * returns a future to the operation so that it can be executed in parallel to other requests.
         */
        virtual Model::DeleteRetentionPolicyOutcomeCallable DeleteRetentionPolicyCallable(const Model::DeleteRetentionPolicyRequest& request) const;

        /**
         * <p> Deletes the retention policy of the specified log group. Log events would
         * not expire if they belong to log groups without a retention policy. </p>
         *
         * Queues the request into a thread executor and triggers associated callback when operation has finished.
         */
        virtual void DeleteRetentionPolicyAsync(const Model::DeleteRetentionPolicyRequest& request, const DeleteRetentionPolicyResponseReceivedHandler& handler, const std::shared_ptr<const Aws::Client::AsyncCallerContext>& context = nullptr) const;

        /**
         * <p> Deletes a subscription filter associated with the specified log group. </p>
         */
        virtual Model::DeleteSubscriptionFilterOutcome DeleteSubscriptionFilter(const Model::DeleteSubscriptionFilterRequest& request) const;

        /**
         * <p> Deletes a subscription filter associated with the specified log group. </p>
         *
         * returns a future to the operation so that it can be executed in parallel to other requests.
         */
        virtual Model::DeleteSubscriptionFilterOutcomeCallable DeleteSubscriptionFilterCallable(const Model::DeleteSubscriptionFilterRequest& request) const;

        /**
         * <p> Deletes a subscription filter associated with the specified log group. </p>
         *
         * Queues the request into a thread executor and triggers associated callback when operation has finished.
         */
        virtual void DeleteSubscriptionFilterAsync(const Model::DeleteSubscriptionFilterRequest& request, const DeleteSubscriptionFilterResponseReceivedHandler& handler, const std::shared_ptr<const Aws::Client::AsyncCallerContext>& context = nullptr) const;

        /**
         * <p> Returns all the destinations that are associated with the AWS account making
         * the request. The list returned in the response is ASCII-sorted by destination
         * name. </p> <p> By default, this operation returns up to 50 destinations. If
         * there are more destinations to list, the response would contain a <code
         * class="code">nextToken</code> value in the response body. You can also limit the
         * number of destinations returned in the response by specifying the <code
         * class="code">limit</code> parameter in the request. </p>
         */
        virtual Model::DescribeDestinationsOutcome DescribeDestinations(const Model::DescribeDestinationsRequest& request) const;

        /**
         * <p> Returns all the destinations that are associated with the AWS account making
         * the request. The list returned in the response is ASCII-sorted by destination
         * name. </p> <p> By default, this operation returns up to 50 destinations. If
         * there are more destinations to list, the response would contain a <code
         * class="code">nextToken</code> value in the response body. You can also limit the
         * number of destinations returned in the response by specifying the <code
         * class="code">limit</code> parameter in the request. </p>
         *
         * returns a future to the operation so that it can be executed in parallel to other requests.
         */
        virtual Model::DescribeDestinationsOutcomeCallable DescribeDestinationsCallable(const Model::DescribeDestinationsRequest& request) const;

        /**
         * <p> Returns all the destinations that are associated with the AWS account making
         * the request. The list returned in the response is ASCII-sorted by destination
         * name. </p> <p> By default, this operation returns up to 50 destinations. If
         * there are more destinations to list, the response would contain a <code
         * class="code">nextToken</code> value in the response body. You can also limit the
         * number of destinations returned in the response by specifying the <code
         * class="code">limit</code> parameter in the request. </p>
         *
         * Queues the request into a thread executor and triggers associated callback when operation has finished.
         */
        virtual void DescribeDestinationsAsync(const Model::DescribeDestinationsRequest& request, const DescribeDestinationsResponseReceivedHandler& handler, const std::shared_ptr<const Aws::Client::AsyncCallerContext>& context = nullptr) const;

        /**
         * <p> Returns all the export tasks that are associated with the AWS account making
         * the request. The export tasks can be filtered based on <code>TaskId</code> or
         * <code>TaskStatus</code>. </p> <p> By default, this operation returns up to 50
         * export tasks that satisfy the specified filters. If there are more export tasks
         * to list, the response would contain a <code class="code">nextToken</code> value
         * in the response body. You can also limit the number of export tasks returned in
         * the response by specifying the <code class="code">limit</code> parameter in the
         * request. </p>
         */
        virtual Model::DescribeExportTasksOutcome DescribeExportTasks(const Model::DescribeExportTasksRequest& request) const;

        /**
         * <p> Returns all the export tasks that are associated with the AWS account making
         * the request. The export tasks can be filtered based on <code>TaskId</code> or
         * <code>TaskStatus</code>. </p> <p> By default, this operation returns up to 50
         * export tasks that satisfy the specified filters. If there are more export tasks
         * to list, the response would contain a <code class="code">nextToken</code> value
         * in the response body. You can also limit the number of export tasks returned in
         * the response by specifying the <code class="code">limit</code> parameter in the
         * request. </p>
         *
         * returns a future to the operation so that it can be executed in parallel to other requests.
         */
        virtual Model::DescribeExportTasksOutcomeCallable DescribeExportTasksCallable(const Model::DescribeExportTasksRequest& request) const;

        /**
         * <p> Returns all the export tasks that are associated with the AWS account making
         * the request. The export tasks can be filtered based on <code>TaskId</code> or
         * <code>TaskStatus</code>. </p> <p> By default, this operation returns up to 50
         * export tasks that satisfy the specified filters. If there are more export tasks
         * to list, the response would contain a <code class="code">nextToken</code> value
         * in the response body. You can also limit the number of export tasks returned in
         * the response by specifying the <code class="code">limit</code> parameter in the
         * request. </p>
         *
         * Queues the request into a thread executor and triggers associated callback when operation has finished.
         */
        virtual void DescribeExportTasksAsync(const Model::DescribeExportTasksRequest& request, const DescribeExportTasksResponseReceivedHandler& handler, const std::shared_ptr<const Aws::Client::AsyncCallerContext>& context = nullptr) const;

        /**
         * <p> Returns all the log groups that are associated with the AWS account making
         * the request. The list returned in the response is ASCII-sorted by log group
         * name. </p> <p> By default, this operation returns up to 50 log groups. If there
         * are more log groups to list, the response would contain a <code
         * class="code">nextToken</code> value in the response body. You can also limit the
         * number of log groups returned in the response by specifying the <code
         * class="code">limit</code> parameter in the request. </p>
         */
        virtual Model::DescribeLogGroupsOutcome DescribeLogGroups(const Model::DescribeLogGroupsRequest& request) const;

        /**
         * <p> Returns all the log groups that are associated with the AWS account making
         * the request. The list returned in the response is ASCII-sorted by log group
         * name. </p> <p> By default, this operation returns up to 50 log groups. If there
         * are more log groups to list, the response would contain a <code
         * class="code">nextToken</code> value in the response body. You can also limit the
         * number of log groups returned in the response by specifying the <code
         * class="code">limit</code> parameter in the request. </p>
         *
         * returns a future to the operation so that it can be executed in parallel to other requests.
         */
        virtual Model::DescribeLogGroupsOutcomeCallable DescribeLogGroupsCallable(const Model::DescribeLogGroupsRequest& request) const;

        /**
         * <p> Returns all the log groups that are associated with the AWS account making
         * the request. The list returned in the response is ASCII-sorted by log group
         * name. </p> <p> By default, this operation returns up to 50 log groups. If there
         * are more log groups to list, the response would contain a <code
         * class="code">nextToken</code> value in the response body. You can also limit the
         * number of log groups returned in the response by specifying the <code
         * class="code">limit</code> parameter in the request. </p>
         *
         * Queues the request into a thread executor and triggers associated callback when operation has finished.
         */
        virtual void DescribeLogGroupsAsync(const Model::DescribeLogGroupsRequest& request, const DescribeLogGroupsResponseReceivedHandler& handler, const std::shared_ptr<const Aws::Client::AsyncCallerContext>& context = nullptr) const;

        /**
         * <p> Returns all the log streams that are associated with the specified log
         * group. The list returned in the response is ASCII-sorted by log stream name.
         * </p> <p> By default, this operation returns up to 50 log streams. If there are
         * more log streams to list, the response would contain a <code
         * class="code">nextToken</code> value in the response body. You can also limit the
         * number of log streams returned in the response by specifying the <code
         * class="code">limit</code> parameter in the request. This operation has a limit
         * of five transactions per second, after which transactions are throttled. </p>
         */
        virtual Model::DescribeLogStreamsOutcome DescribeLogStreams(const Model::DescribeLogStreamsRequest& request) const;

        /**
         * <p> Returns all the log streams that are associated with the specified log
         * group. The list returned in the response is ASCII-sorted by log stream name.
         * </p> <p> By default, this operation returns up to 50 log streams. If there are
         * more log streams to list, the response would contain a <code
         * class="code">nextToken</code> value in the response body. You can also limit the
         * number of log streams returned in the response by specifying the <code
         * class="code">limit</code> parameter in the request. This operation has a limit
         * of five transactions per second, after which transactions are throttled. </p>
         *
         * returns a future to the operation so that it can be executed in parallel to other requests.
         */
        virtual Model::DescribeLogStreamsOutcomeCallable DescribeLogStreamsCallable(const Model::DescribeLogStreamsRequest& request) const;

        /**
         * <p> Returns all the log streams that are associated with the specified log
         * group. The list returned in the response is ASCII-sorted by log stream name.
         * </p> <p> By default, this operation returns up to 50 log streams. If there are
         * more log streams to list, the response would contain a <code
         * class="code">nextToken</code> value in the response body. You can also limit the
         * number of log streams returned in the response by specifying the <code
         * class="code">limit</code> parameter in the request. This operation has a limit
         * of five transactions per second, after which transactions are throttled. </p>
         *
         * Queues the request into a thread executor and triggers associated callback when operation has finished.
         */
        virtual void DescribeLogStreamsAsync(const Model::DescribeLogStreamsRequest& request, const DescribeLogStreamsResponseReceivedHandler& handler, const std::shared_ptr<const Aws::Client::AsyncCallerContext>& context = nullptr) const;

        /**
         * <p> Returns all the metrics filters associated with the specified log group. The
         * list returned in the response is ASCII-sorted by filter name. </p> <p> By
         * default, this operation returns up to 50 metric filters. If there are more
         * metric filters to list, the response would contain a <code
         * class="code">nextToken</code> value in the response body. You can also limit the
         * number of metric filters returned in the response by specifying the <code
         * class="code">limit</code> parameter in the request. </p>
         */
        virtual Model::DescribeMetricFiltersOutcome DescribeMetricFilters(const Model::DescribeMetricFiltersRequest& request) const;

        /**
         * <p> Returns all the metrics filters associated with the specified log group. The
         * list returned in the response is ASCII-sorted by filter name. </p> <p> By
         * default, this operation returns up to 50 metric filters. If there are more
         * metric filters to list, the response would contain a <code
         * class="code">nextToken</code> value in the response body. You can also limit the
         * number of metric filters returned in the response by specifying the <code
         * class="code">limit</code> parameter in the request. </p>
         *
         * returns a future to the operation so that it can be executed in parallel to other requests.
         */
        virtual Model::DescribeMetricFiltersOutcomeCallable DescribeMetricFiltersCallable(const Model::DescribeMetricFiltersRequest& request) const;

        /**
         * <p> Returns all the metrics filters associated with the specified log group. The
         * list returned in the response is ASCII-sorted by filter name. </p> <p> By
         * default, this operation returns up to 50 metric filters. If there are more
         * metric filters to list, the response would contain a <code
         * class="code">nextToken</code> value in the response body. You can also limit the
         * number of metric filters returned in the response by specifying the <code
         * class="code">limit</code> parameter in the request. </p>
         *
         * Queues the request into a thread executor and triggers associated callback when operation has finished.
         */
        virtual void DescribeMetricFiltersAsync(const Model::DescribeMetricFiltersRequest& request, const DescribeMetricFiltersResponseReceivedHandler& handler, const std::shared_ptr<const Aws::Client::AsyncCallerContext>& context = nullptr) const;

        /**
         * <p> Returns all the subscription filters associated with the specified log
         * group. The list returned in the response is ASCII-sorted by filter name. </p>
         * <p> By default, this operation returns up to 50 subscription filters. If there
         * are more subscription filters to list, the response would contain a <code
         * class="code">nextToken</code> value in the response body. You can also limit the
         * number of subscription filters returned in the response by specifying the <code
         * class="code">limit</code> parameter in the request. </p>
         */
        virtual Model::DescribeSubscriptionFiltersOutcome DescribeSubscriptionFilters(const Model::DescribeSubscriptionFiltersRequest& request) const;

        /**
         * <p> Returns all the subscription filters associated with the specified log
         * group. The list returned in the response is ASCII-sorted by filter name. </p>
         * <p> By default, this operation returns up to 50 subscription filters. If there
         * are more subscription filters to list, the response would contain a <code
         * class="code">nextToken</code> value in the response body. You can also limit the
         * number of subscription filters returned in the response by specifying the <code
         * class="code">limit</code> parameter in the request. </p>
         *
         * returns a future to the operation so that it can be executed in parallel to other requests.
         */
        virtual Model::DescribeSubscriptionFiltersOutcomeCallable DescribeSubscriptionFiltersCallable(const Model::DescribeSubscriptionFiltersRequest& request) const;

        /**
         * <p> Returns all the subscription filters associated with the specified log
         * group. The list returned in the response is ASCII-sorted by filter name. </p>
         * <p> By default, this operation returns up to 50 subscription filters. If there
         * are more subscription filters to list, the response would contain a <code
         * class="code">nextToken</code> value in the response body. You can also limit the
         * number of subscription filters returned in the response by specifying the <code
         * class="code">limit</code> parameter in the request. </p>
         *
         * Queues the request into a thread executor and triggers associated callback when operation has finished.
         */
        virtual void DescribeSubscriptionFiltersAsync(const Model::DescribeSubscriptionFiltersRequest& request, const DescribeSubscriptionFiltersResponseReceivedHandler& handler, const std::shared_ptr<const Aws::Client::AsyncCallerContext>& context = nullptr) const;

        /**
         * <p> Retrieves log events, optionally filtered by a filter pattern from the
         * specified log group. You can provide an optional time range to filter the
         * results on the event <code class="code">timestamp</code>. You can limit the
         * streams searched to an explicit list of <code
         * class="code">logStreamNames</code>. </p> <p> By default, this operation returns
         * as much matching log events as can fit in a response size of 1MB, up to 10,000
         * log events, or all the events found within a time-bounded scan window. If the
         * response includes a <code class="code">nextToken</code>, then there is more data
         * to search, and the search can be resumed with a new request providing the
         * nextToken. The response will contain a list of <code
         * class="code">searchedLogStreams</code> that contains information about which
         * streams were searched in the request and whether they have been searched
         * completely or require further pagination. The <code class="code">limit</code>
         * parameter in the request. can be used to specify the maximum number of events to
         * return in a page. </p>
         */
        virtual Model::FilterLogEventsOutcome FilterLogEvents(const Model::FilterLogEventsRequest& request) const;

        /**
         * <p> Retrieves log events, optionally filtered by a filter pattern from the
         * specified log group. You can provide an optional time range to filter the
         * results on the event <code class="code">timestamp</code>. You can limit the
         * streams searched to an explicit list of <code
         * class="code">logStreamNames</code>. </p> <p> By default, this operation returns
         * as much matching log events as can fit in a response size of 1MB, up to 10,000
         * log events, or all the events found within a time-bounded scan window. If the
         * response includes a <code class="code">nextToken</code>, then there is more data
         * to search, and the search can be resumed with a new request providing the
         * nextToken. The response will contain a list of <code
         * class="code">searchedLogStreams</code> that contains information about which
         * streams were searched in the request and whether they have been searched
         * completely or require further pagination. The <code class="code">limit</code>
         * parameter in the request. can be used to specify the maximum number of events to
         * return in a page. </p>
         *
         * returns a future to the operation so that it can be executed in parallel to other requests.
         */
        virtual Model::FilterLogEventsOutcomeCallable FilterLogEventsCallable(const Model::FilterLogEventsRequest& request) const;

        /**
         * <p> Retrieves log events, optionally filtered by a filter pattern from the
         * specified log group. You can provide an optional time range to filter the
         * results on the event <code class="code">timestamp</code>. You can limit the
         * streams searched to an explicit list of <code
         * class="code">logStreamNames</code>. </p> <p> By default, this operation returns
         * as much matching log events as can fit in a response size of 1MB, up to 10,000
         * log events, or all the events found within a time-bounded scan window. If the
         * response includes a <code class="code">nextToken</code>, then there is more data
         * to search, and the search can be resumed with a new request providing the
         * nextToken. The response will contain a list of <code
         * class="code">searchedLogStreams</code> that contains information about which
         * streams were searched in the request and whether they have been searched
         * completely or require further pagination. The <code class="code">limit</code>
         * parameter in the request. can be used to specify the maximum number of events to
         * return in a page. </p>
         *
         * Queues the request into a thread executor and triggers associated callback when operation has finished.
         */
        virtual void FilterLogEventsAsync(const Model::FilterLogEventsRequest& request, const FilterLogEventsResponseReceivedHandler& handler, const std::shared_ptr<const Aws::Client::AsyncCallerContext>& context = nullptr) const;

        /**
         * <p> Retrieves log events from the specified log stream. You can provide an
         * optional time range to filter the results on the event <code
         * class="code">timestamp</code>. </p> <p> By default, this operation returns as
         * much log events as can fit in a response size of 1MB, up to 10,000 log events.
         * The response will always include a <code class="code">nextForwardToken</code>
         * and a <code class="code">nextBackwardToken</code> in the response body. You can
         * use any of these tokens in subsequent <code class="code">GetLogEvents</code>
         * requests to paginate through events in either forward or backward direction. You
         * can also limit the number of log events returned in the response by specifying
         * the <code class="code">limit</code> parameter in the request. </p>
         */
        virtual Model::GetLogEventsOutcome GetLogEvents(const Model::GetLogEventsRequest& request) const;

        /**
         * <p> Retrieves log events from the specified log stream. You can provide an
         * optional time range to filter the results on the event <code
         * class="code">timestamp</code>. </p> <p> By default, this operation returns as
         * much log events as can fit in a response size of 1MB, up to 10,000 log events.
         * The response will always include a <code class="code">nextForwardToken</code>
         * and a <code class="code">nextBackwardToken</code> in the response body. You can
         * use any of these tokens in subsequent <code class="code">GetLogEvents</code>
         * requests to paginate through events in either forward or backward direction. You
         * can also limit the number of log events returned in the response by specifying
         * the <code class="code">limit</code> parameter in the request. </p>
         *
         * returns a future to the operation so that it can be executed in parallel to other requests.
         */
        virtual Model::GetLogEventsOutcomeCallable GetLogEventsCallable(const Model::GetLogEventsRequest& request) const;

        /**
         * <p> Retrieves log events from the specified log stream. You can provide an
         * optional time range to filter the results on the event <code
         * class="code">timestamp</code>. </p> <p> By default, this operation returns as
         * much log events as can fit in a response size of 1MB, up to 10,000 log events.
         * The response will always include a <code class="code">nextForwardToken</code>
         * and a <code class="code">nextBackwardToken</code> in the response body. You can
         * use any of these tokens in subsequent <code class="code">GetLogEvents</code>
         * requests to paginate through events in either forward or backward direction. You
         * can also limit the number of log events returned in the response by specifying
         * the <code class="code">limit</code> parameter in the request. </p>
         *
         * Queues the request into a thread executor and triggers associated callback when operation has finished.
         */
        virtual void GetLogEventsAsync(const Model::GetLogEventsRequest& request, const GetLogEventsResponseReceivedHandler& handler, const std::shared_ptr<const Aws::Client::AsyncCallerContext>& context = nullptr) const;

        /**
         * <p> Creates or updates a <code>Destination</code>. A destination encapsulates a
         * physical resource (such as a Kinesis stream) and allows you to subscribe to a
         * real-time stream of log events of a different account, ingested through <code
         * class="code">PutLogEvents</code> requests. Currently, the only supported
         * physical resource is a Amazon Kinesis stream belonging to the same account as
         * the destination. </p> <p> A destination controls what is written to its Amazon
         * Kinesis stream through an access policy. By default, PutDestination does not set
         * any access policy with the destination, which means a cross-account user will
         * not be able to call <code>PutSubscriptionFilter</code> against this destination.
         * To enable that, the destination owner must call
         * <code>PutDestinationPolicy</code> after PutDestination. </p>
         */
        virtual Model::PutDestinationOutcome PutDestination(const Model::PutDestinationRequest& request) const;

        /**
         * <p> Creates or updates a <code>Destination</code>. A destination encapsulates a
         * physical resource (such as a Kinesis stream) and allows you to subscribe to a
         * real-time stream of log events of a different account, ingested through <code
         * class="code">PutLogEvents</code> requests. Currently, the only supported
         * physical resource is a Amazon Kinesis stream belonging to the same account as
         * the destination. </p> <p> A destination controls what is written to its Amazon
         * Kinesis stream through an access policy. By default, PutDestination does not set
         * any access policy with the destination, which means a cross-account user will
         * not be able to call <code>PutSubscriptionFilter</code> against this destination.
         * To enable that, the destination owner must call
         * <code>PutDestinationPolicy</code> after PutDestination. </p>
         *
         * returns a future to the operation so that it can be executed in parallel to other requests.
         */
        virtual Model::PutDestinationOutcomeCallable PutDestinationCallable(const Model::PutDestinationRequest& request) const;

        /**
         * <p> Creates or updates a <code>Destination</code>. A destination encapsulates a
         * physical resource (such as a Kinesis stream) and allows you to subscribe to a
         * real-time stream of log events of a different account, ingested through <code
         * class="code">PutLogEvents</code> requests. Currently, the only supported
         * physical resource is a Amazon Kinesis stream belonging to the same account as
         * the destination. </p> <p> A destination controls what is written to its Amazon
         * Kinesis stream through an access policy. By default, PutDestination does not set
         * any access policy with the destination, which means a cross-account user will
         * not be able to call <code>PutSubscriptionFilter</code> against this destination.
         * To enable that, the destination owner must call
         * <code>PutDestinationPolicy</code> after PutDestination. </p>
         *
         * Queues the request into a thread executor and triggers associated callback when operation has finished.
         */
        virtual void PutDestinationAsync(const Model::PutDestinationRequest& request, const PutDestinationResponseReceivedHandler& handler, const std::shared_ptr<const Aws::Client::AsyncCallerContext>& context = nullptr) const;

        /**
         * <p> Creates or updates an access policy associated with an existing
         * <code>Destination</code>. An access policy is an <a
         * href="http://docs.aws.amazon.com/IAM/latest/UserGuide/policies_overview.html">IAM
         * policy document</a> that is used to authorize claims to register a subscription
         * filter against a given destination. </p>
         */
        virtual Model::PutDestinationPolicyOutcome PutDestinationPolicy(const Model::PutDestinationPolicyRequest& request) const;

        /**
         * <p> Creates or updates an access policy associated with an existing
         * <code>Destination</code>. An access policy is an <a
         * href="http://docs.aws.amazon.com/IAM/latest/UserGuide/policies_overview.html">IAM
         * policy document</a> that is used to authorize claims to register a subscription
         * filter against a given destination. </p>
         *
         * returns a future to the operation so that it can be executed in parallel to other requests.
         */
        virtual Model::PutDestinationPolicyOutcomeCallable PutDestinationPolicyCallable(const Model::PutDestinationPolicyRequest& request) const;

        /**
         * <p> Creates or updates an access policy associated with an existing
         * <code>Destination</code>. An access policy is an <a
         * href="http://docs.aws.amazon.com/IAM/latest/UserGuide/policies_overview.html">IAM
         * policy document</a> that is used to authorize claims to register a subscription
         * filter against a given destination. </p>
         *
         * Queues the request into a thread executor and triggers associated callback when operation has finished.
         */
        virtual void PutDestinationPolicyAsync(const Model::PutDestinationPolicyRequest& request, const PutDestinationPolicyResponseReceivedHandler& handler, const std::shared_ptr<const Aws::Client::AsyncCallerContext>& context = nullptr) const;

        /**
         * <p> Uploads a batch of log events to the specified log stream. </p> <p> Every
         * PutLogEvents request must include the <code class="code">sequenceToken</code>
         * obtained from the response of the previous request. An upload in a newly created
         * log stream does not require a <code class="code">sequenceToken</code>. </p> <p>
         * The batch of events must satisfy the following constraints: <ul> <li>The maximum
         * batch size is 1,048,576 bytes, and this size is calculated as the sum of all
         * event messages in UTF-8, plus 26 bytes for each log event.</li> <li>None of the
         * log events in the batch can be more than 2 hours in the future.</li> <li>None of
         * the log events in the batch can be older than 14 days or the retention period of
         * the log group.</li> <li>The log events in the batch must be in chronological
         * ordered by their <code class="code">timestamp</code>.</li> <li>The maximum
         * number of log events in a batch is 10,000.</li> </ul> </p>
         */
        virtual Model::PutLogEventsOutcome PutLogEvents(const Model::PutLogEventsRequest& request) const;

        /**
         * <p> Uploads a batch of log events to the specified log stream. </p> <p> Every
         * PutLogEvents request must include the <code class="code">sequenceToken</code>
         * obtained from the response of the previous request. An upload in a newly created
         * log stream does not require a <code class="code">sequenceToken</code>. </p> <p>
         * The batch of events must satisfy the following constraints: <ul> <li>The maximum
         * batch size is 1,048,576 bytes, and this size is calculated as the sum of all
         * event messages in UTF-8, plus 26 bytes for each log event.</li> <li>None of the
         * log events in the batch can be more than 2 hours in the future.</li> <li>None of
         * the log events in the batch can be older than 14 days or the retention period of
         * the log group.</li> <li>The log events in the batch must be in chronological
         * ordered by their <code class="code">timestamp</code>.</li> <li>The maximum
         * number of log events in a batch is 10,000.</li> </ul> </p>
         *
         * returns a future to the operation so that it can be executed in parallel to other requests.
         */
        virtual Model::PutLogEventsOutcomeCallable PutLogEventsCallable(const Model::PutLogEventsRequest& request) const;

        /**
         * <p> Uploads a batch of log events to the specified log stream. </p> <p> Every
         * PutLogEvents request must include the <code class="code">sequenceToken</code>
         * obtained from the response of the previous request. An upload in a newly created
         * log stream does not require a <code class="code">sequenceToken</code>. </p> <p>
         * The batch of events must satisfy the following constraints: <ul> <li>The maximum
         * batch size is 1,048,576 bytes, and this size is calculated as the sum of all
         * event messages in UTF-8, plus 26 bytes for each log event.</li> <li>None of the
         * log events in the batch can be more than 2 hours in the future.</li> <li>None of
         * the log events in the batch can be older than 14 days or the retention period of
         * the log group.</li> <li>The log events in the batch must be in chronological
         * ordered by their <code class="code">timestamp</code>.</li> <li>The maximum
         * number of log events in a batch is 10,000.</li> </ul> </p>
         *
         * Queues the request into a thread executor and triggers associated callback when operation has finished.
         */
        virtual void PutLogEventsAsync(const Model::PutLogEventsRequest& request, const PutLogEventsResponseReceivedHandler& handler, const std::shared_ptr<const Aws::Client::AsyncCallerContext>& context = nullptr) const;

        /**
         * <p> Creates or updates a metric filter and associates it with the specified log
         * group. Metric filters allow you to configure rules to extract metric data from
         * log events ingested through <code class="code">PutLogEvents</code> requests.
         * </p> <p> The maximum number of metric filters that can be associated with a log
         * group is 100. </p>
         */
        virtual Model::PutMetricFilterOutcome PutMetricFilter(const Model::PutMetricFilterRequest& request) const;

        /**
         * <p> Creates or updates a metric filter and associates it with the specified log
         * group. Metric filters allow you to configure rules to extract metric data from
         * log events ingested through <code class="code">PutLogEvents</code> requests.
         * </p> <p> The maximum number of metric filters that can be associated with a log
         * group is 100. </p>
         *
         * returns a future to the operation so that it can be executed in parallel to other requests.
         */
        virtual Model::PutMetricFilterOutcomeCallable PutMetricFilterCallable(const Model::PutMetricFilterRequest& request) const;

        /**
         * <p> Creates or updates a metric filter and associates it with the specified log
         * group. Metric filters allow you to configure rules to extract metric data from
         * log events ingested through <code class="code">PutLogEvents</code> requests.
         * </p> <p> The maximum number of metric filters that can be associated with a log
         * group is 100. </p>
         *
         * Queues the request into a thread executor and triggers associated callback when operation has finished.
         */
        virtual void PutMetricFilterAsync(const Model::PutMetricFilterRequest& request, const PutMetricFilterResponseReceivedHandler& handler, const std::shared_ptr<const Aws::Client::AsyncCallerContext>& context = nullptr) const;

        /**
         * <p> Sets the retention of the specified log group. A retention policy allows you
         * to configure the number of days you want to retain log events in the specified
         * log group. </p>
         */
        virtual Model::PutRetentionPolicyOutcome PutRetentionPolicy(const Model::PutRetentionPolicyRequest& request) const;

        /**
         * <p> Sets the retention of the specified log group. A retention policy allows you
         * to configure the number of days you want to retain log events in the specified
         * log group. </p>
         *
         * returns a future to the operation so that it can be executed in parallel to other requests.
         */
        virtual Model::PutRetentionPolicyOutcomeCallable PutRetentionPolicyCallable(const Model::PutRetentionPolicyRequest& request) const;

        /**
         * <p> Sets the retention of the specified log group. A retention policy allows you
         * to configure the number of days you want to retain log events in the specified
         * log group. </p>
         *
         * Queues the request into a thread executor and triggers associated callback when operation has finished.
         */
        virtual void PutRetentionPolicyAsync(const Model::PutRetentionPolicyRequest& request, const PutRetentionPolicyResponseReceivedHandler& handler, const std::shared_ptr<const Aws::Client::AsyncCallerContext>& context = nullptr) const;

        /**
         * <p> Creates or updates a subscription filter and associates it with the
         * specified log group. Subscription filters allow you to subscribe to a real-time
         * stream of log events ingested through <code class="code">PutLogEvents</code>
         * requests and have them delivered to a specific destination. Currently, the
         * supported destinations are: <ul> <li> A Amazon Kinesis stream belonging to the
         * same account as the subscription filter, for same-account delivery. </li> <li> A
         * logical destination (used via an ARN of <code>Destination</code>) belonging to a
         * different account, for cross-account delivery. </li> </ul> </p> <p> Currently
         * there can only be one subscription filter associated with a log group. </p>
         */
        virtual Model::PutSubscriptionFilterOutcome PutSubscriptionFilter(const Model::PutSubscriptionFilterRequest& request) const;

        /**
         * <p> Creates or updates a subscription filter and associates it with the
         * specified log group. Subscription filters allow you to subscribe to a real-time
         * stream of log events ingested through <code class="code">PutLogEvents</code>
         * requests and have them delivered to a specific destination. Currently, the
         * supported destinations are: <ul> <li> A Amazon Kinesis stream belonging to the
         * same account as the subscription filter, for same-account delivery. </li> <li> A
         * logical destination (used via an ARN of <code>Destination</code>) belonging to a
         * different account, for cross-account delivery. </li> </ul> </p> <p> Currently
         * there can only be one subscription filter associated with a log group. </p>
         *
         * returns a future to the operation so that it can be executed in parallel to other requests.
         */
        virtual Model::PutSubscriptionFilterOutcomeCallable PutSubscriptionFilterCallable(const Model::PutSubscriptionFilterRequest& request) const;

        /**
         * <p> Creates or updates a subscription filter and associates it with the
         * specified log group. Subscription filters allow you to subscribe to a real-time
         * stream of log events ingested through <code class="code">PutLogEvents</code>
         * requests and have them delivered to a specific destination. Currently, the
         * supported destinations are: <ul> <li> A Amazon Kinesis stream belonging to the
         * same account as the subscription filter, for same-account delivery. </li> <li> A
         * logical destination (used via an ARN of <code>Destination</code>) belonging to a
         * different account, for cross-account delivery. </li> </ul> </p> <p> Currently
         * there can only be one subscription filter associated with a log group. </p>
         *
         * Queues the request into a thread executor and triggers associated callback when operation has finished.
         */
        virtual void PutSubscriptionFilterAsync(const Model::PutSubscriptionFilterRequest& request, const PutSubscriptionFilterResponseReceivedHandler& handler, const std::shared_ptr<const Aws::Client::AsyncCallerContext>& context = nullptr) const;

        /**
         * <p> Tests the filter pattern of a metric filter against a sample of log event
         * messages. You can use this operation to validate the correctness of a metric
         * filter pattern. </p>
         */
        virtual Model::TestMetricFilterOutcome TestMetricFilter(const Model::TestMetricFilterRequest& request) const;

        /**
         * <p> Tests the filter pattern of a metric filter against a sample of log event
         * messages. You can use this operation to validate the correctness of a metric
         * filter pattern. </p>
         *
         * returns a future to the operation so that it can be executed in parallel to other requests.
         */
        virtual Model::TestMetricFilterOutcomeCallable TestMetricFilterCallable(const Model::TestMetricFilterRequest& request) const;

        /**
         * <p> Tests the filter pattern of a metric filter against a sample of log event
         * messages. You can use this operation to validate the correctness of a metric
         * filter pattern. </p>
         *
         * Queues the request into a thread executor and triggers associated callback when operation has finished.
         */
        virtual void TestMetricFilterAsync(const Model::TestMetricFilterRequest& request, const TestMetricFilterResponseReceivedHandler& handler, const std::shared_ptr<const Aws::Client::AsyncCallerContext>& context = nullptr) const;


    private:
      void init(const Client::ClientConfiguration& clientConfiguration);

        /**Async helpers**/
        void CancelExportTaskAsyncHelper(const Model::CancelExportTaskRequest& request, const CancelExportTaskResponseReceivedHandler& handler, const std::shared_ptr<const Aws::Client::AsyncCallerContext>& context) const;
        void CreateExportTaskAsyncHelper(const Model::CreateExportTaskRequest& request, const CreateExportTaskResponseReceivedHandler& handler, const std::shared_ptr<const Aws::Client::AsyncCallerContext>& context) const;
        void CreateLogGroupAsyncHelper(const Model::CreateLogGroupRequest& request, const CreateLogGroupResponseReceivedHandler& handler, const std::shared_ptr<const Aws::Client::AsyncCallerContext>& context) const;
        void CreateLogStreamAsyncHelper(const Model::CreateLogStreamRequest& request, const CreateLogStreamResponseReceivedHandler& handler, const std::shared_ptr<const Aws::Client::AsyncCallerContext>& context) const;
        void DeleteDestinationAsyncHelper(const Model::DeleteDestinationRequest& request, const DeleteDestinationResponseReceivedHandler& handler, const std::shared_ptr<const Aws::Client::AsyncCallerContext>& context) const;
        void DeleteLogGroupAsyncHelper(const Model::DeleteLogGroupRequest& request, const DeleteLogGroupResponseReceivedHandler& handler, const std::shared_ptr<const Aws::Client::AsyncCallerContext>& context) const;
        void DeleteLogStreamAsyncHelper(const Model::DeleteLogStreamRequest& request, const DeleteLogStreamResponseReceivedHandler& handler, const std::shared_ptr<const Aws::Client::AsyncCallerContext>& context) const;
        void DeleteMetricFilterAsyncHelper(const Model::DeleteMetricFilterRequest& request, const DeleteMetricFilterResponseReceivedHandler& handler, const std::shared_ptr<const Aws::Client::AsyncCallerContext>& context) const;
        void DeleteRetentionPolicyAsyncHelper(const Model::DeleteRetentionPolicyRequest& request, const DeleteRetentionPolicyResponseReceivedHandler& handler, const std::shared_ptr<const Aws::Client::AsyncCallerContext>& context) const;
        void DeleteSubscriptionFilterAsyncHelper(const Model::DeleteSubscriptionFilterRequest& request, const DeleteSubscriptionFilterResponseReceivedHandler& handler, const std::shared_ptr<const Aws::Client::AsyncCallerContext>& context) const;
        void DescribeDestinationsAsyncHelper(const Model::DescribeDestinationsRequest& request, const DescribeDestinationsResponseReceivedHandler& handler, const std::shared_ptr<const Aws::Client::AsyncCallerContext>& context) const;
        void DescribeExportTasksAsyncHelper(const Model::DescribeExportTasksRequest& request, const DescribeExportTasksResponseReceivedHandler& handler, const std::shared_ptr<const Aws::Client::AsyncCallerContext>& context) const;
        void DescribeLogGroupsAsyncHelper(const Model::DescribeLogGroupsRequest& request, const DescribeLogGroupsResponseReceivedHandler& handler, const std::shared_ptr<const Aws::Client::AsyncCallerContext>& context) const;
        void DescribeLogStreamsAsyncHelper(const Model::DescribeLogStreamsRequest& request, const DescribeLogStreamsResponseReceivedHandler& handler, const std::shared_ptr<const Aws::Client::AsyncCallerContext>& context) const;
        void DescribeMetricFiltersAsyncHelper(const Model::DescribeMetricFiltersRequest& request, const DescribeMetricFiltersResponseReceivedHandler& handler, const std::shared_ptr<const Aws::Client::AsyncCallerContext>& context) const;
        void DescribeSubscriptionFiltersAsyncHelper(const Model::DescribeSubscriptionFiltersRequest& request, const DescribeSubscriptionFiltersResponseReceivedHandler& handler, const std::shared_ptr<const Aws::Client::AsyncCallerContext>& context) const;
        void FilterLogEventsAsyncHelper(const Model::FilterLogEventsRequest& request, const FilterLogEventsResponseReceivedHandler& handler, const std::shared_ptr<const Aws::Client::AsyncCallerContext>& context) const;
        void GetLogEventsAsyncHelper(const Model::GetLogEventsRequest& request, const GetLogEventsResponseReceivedHandler& handler, const std::shared_ptr<const Aws::Client::AsyncCallerContext>& context) const;
        void PutDestinationAsyncHelper(const Model::PutDestinationRequest& request, const PutDestinationResponseReceivedHandler& handler, const std::shared_ptr<const Aws::Client::AsyncCallerContext>& context) const;
        void PutDestinationPolicyAsyncHelper(const Model::PutDestinationPolicyRequest& request, const PutDestinationPolicyResponseReceivedHandler& handler, const std::shared_ptr<const Aws::Client::AsyncCallerContext>& context) const;
        void PutLogEventsAsyncHelper(const Model::PutLogEventsRequest& request, const PutLogEventsResponseReceivedHandler& handler, const std::shared_ptr<const Aws::Client::AsyncCallerContext>& context) const;
        void PutMetricFilterAsyncHelper(const Model::PutMetricFilterRequest& request, const PutMetricFilterResponseReceivedHandler& handler, const std::shared_ptr<const Aws::Client::AsyncCallerContext>& context) const;
        void PutRetentionPolicyAsyncHelper(const Model::PutRetentionPolicyRequest& request, const PutRetentionPolicyResponseReceivedHandler& handler, const std::shared_ptr<const Aws::Client::AsyncCallerContext>& context) const;
        void PutSubscriptionFilterAsyncHelper(const Model::PutSubscriptionFilterRequest& request, const PutSubscriptionFilterResponseReceivedHandler& handler, const std::shared_ptr<const Aws::Client::AsyncCallerContext>& context) const;
        void TestMetricFilterAsyncHelper(const Model::TestMetricFilterRequest& request, const TestMetricFilterResponseReceivedHandler& handler, const std::shared_ptr<const Aws::Client::AsyncCallerContext>& context) const;

      Aws::String m_uri;
      std::shared_ptr<Utils::Threading::Executor> m_executor;
  };

} // namespace CloudWatchLogs
} // namespace Aws
