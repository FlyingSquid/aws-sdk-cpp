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
#include <aws/cognito-identity/CognitoIdentity_EXPORTS.h>
#include <aws/cognito-identity/CognitoIdentityRequest.h>
#include <aws/core/utils/memory/stl/AWSString.h>
#include <aws/core/utils/memory/stl/AWSMap.h>
#include <aws/core/utils/memory/stl/AWSVector.h>

namespace Aws
{
namespace CognitoIdentity
{
namespace Model
{

  /**
   * An object representing a Cognito identity pool.
   */
  class AWS_COGNITOIDENTITY_API UpdateIdentityPoolRequest : public CognitoIdentityRequest
  {
  public:
    UpdateIdentityPoolRequest();
    Aws::String SerializePayload() const override;

    Aws::Http::HeaderValueCollection GetRequestSpecificHeaders() const override;


    /**
     * An identity pool ID in the format REGION:GUID.
     */
    inline const Aws::String& GetIdentityPoolId() const{ return m_identityPoolId; }

    /**
     * An identity pool ID in the format REGION:GUID.
     */
    inline void SetIdentityPoolId(const Aws::String& value) { m_identityPoolIdHasBeenSet = true; m_identityPoolId = value; }

    /**
     * An identity pool ID in the format REGION:GUID.
     */
    inline void SetIdentityPoolId(Aws::String&& value) { m_identityPoolIdHasBeenSet = true; m_identityPoolId = value; }

    /**
     * An identity pool ID in the format REGION:GUID.
     */
    inline void SetIdentityPoolId(const char* value) { m_identityPoolIdHasBeenSet = true; m_identityPoolId.assign(value); }

    /**
     * An identity pool ID in the format REGION:GUID.
     */
    inline UpdateIdentityPoolRequest& WithIdentityPoolId(const Aws::String& value) { SetIdentityPoolId(value); return *this;}

    /**
     * An identity pool ID in the format REGION:GUID.
     */
    inline UpdateIdentityPoolRequest& WithIdentityPoolId(Aws::String&& value) { SetIdentityPoolId(value); return *this;}

    /**
     * An identity pool ID in the format REGION:GUID.
     */
    inline UpdateIdentityPoolRequest& WithIdentityPoolId(const char* value) { SetIdentityPoolId(value); return *this;}

    /**
     * <p>A string that you provide.</p>
     */
    inline const Aws::String& GetIdentityPoolName() const{ return m_identityPoolName; }

    /**
     * <p>A string that you provide.</p>
     */
    inline void SetIdentityPoolName(const Aws::String& value) { m_identityPoolNameHasBeenSet = true; m_identityPoolName = value; }

    /**
     * <p>A string that you provide.</p>
     */
    inline void SetIdentityPoolName(Aws::String&& value) { m_identityPoolNameHasBeenSet = true; m_identityPoolName = value; }

    /**
     * <p>A string that you provide.</p>
     */
    inline void SetIdentityPoolName(const char* value) { m_identityPoolNameHasBeenSet = true; m_identityPoolName.assign(value); }

    /**
     * <p>A string that you provide.</p>
     */
    inline UpdateIdentityPoolRequest& WithIdentityPoolName(const Aws::String& value) { SetIdentityPoolName(value); return *this;}

    /**
     * <p>A string that you provide.</p>
     */
    inline UpdateIdentityPoolRequest& WithIdentityPoolName(Aws::String&& value) { SetIdentityPoolName(value); return *this;}

    /**
     * <p>A string that you provide.</p>
     */
    inline UpdateIdentityPoolRequest& WithIdentityPoolName(const char* value) { SetIdentityPoolName(value); return *this;}

    /**
     * TRUE if the identity pool supports unauthenticated logins.
     */
    inline bool GetAllowUnauthenticatedIdentities() const{ return m_allowUnauthenticatedIdentities; }

    /**
     * TRUE if the identity pool supports unauthenticated logins.
     */
    inline void SetAllowUnauthenticatedIdentities(bool value) { m_allowUnauthenticatedIdentitiesHasBeenSet = true; m_allowUnauthenticatedIdentities = value; }

    /**
     * TRUE if the identity pool supports unauthenticated logins.
     */
    inline UpdateIdentityPoolRequest& WithAllowUnauthenticatedIdentities(bool value) { SetAllowUnauthenticatedIdentities(value); return *this;}

    /**
     * <p>Optional key:value pairs mapping provider names to provider app IDs.</p>
     */
    inline const Aws::Map<Aws::String, Aws::String>& GetSupportedLoginProviders() const{ return m_supportedLoginProviders; }

    /**
     * <p>Optional key:value pairs mapping provider names to provider app IDs.</p>
     */
    inline void SetSupportedLoginProviders(const Aws::Map<Aws::String, Aws::String>& value) { m_supportedLoginProvidersHasBeenSet = true; m_supportedLoginProviders = value; }

    /**
     * <p>Optional key:value pairs mapping provider names to provider app IDs.</p>
     */
    inline void SetSupportedLoginProviders(Aws::Map<Aws::String, Aws::String>&& value) { m_supportedLoginProvidersHasBeenSet = true; m_supportedLoginProviders = value; }

    /**
     * <p>Optional key:value pairs mapping provider names to provider app IDs.</p>
     */
    inline UpdateIdentityPoolRequest& WithSupportedLoginProviders(const Aws::Map<Aws::String, Aws::String>& value) { SetSupportedLoginProviders(value); return *this;}

    /**
     * <p>Optional key:value pairs mapping provider names to provider app IDs.</p>
     */
    inline UpdateIdentityPoolRequest& WithSupportedLoginProviders(Aws::Map<Aws::String, Aws::String>&& value) { SetSupportedLoginProviders(value); return *this;}

    /**
     * <p>Optional key:value pairs mapping provider names to provider app IDs.</p>
     */
    inline UpdateIdentityPoolRequest& AddSupportedLoginProviders(const Aws::String& key, const Aws::String& value) { m_supportedLoginProvidersHasBeenSet = true; m_supportedLoginProviders[key] = value; return *this; }

    /**
     * <p>Optional key:value pairs mapping provider names to provider app IDs.</p>
     */
    inline UpdateIdentityPoolRequest& AddSupportedLoginProviders(Aws::String&& key, const Aws::String& value) { m_supportedLoginProvidersHasBeenSet = true; m_supportedLoginProviders[key] = value; return *this; }

    /**
     * <p>Optional key:value pairs mapping provider names to provider app IDs.</p>
     */
    inline UpdateIdentityPoolRequest& AddSupportedLoginProviders(const Aws::String& key, Aws::String&& value) { m_supportedLoginProvidersHasBeenSet = true; m_supportedLoginProviders[key] = value; return *this; }

    /**
     * <p>Optional key:value pairs mapping provider names to provider app IDs.</p>
     */
    inline UpdateIdentityPoolRequest& AddSupportedLoginProviders(Aws::String&& key, Aws::String&& value) { m_supportedLoginProvidersHasBeenSet = true; m_supportedLoginProviders[key] = value; return *this; }

    /**
     * <p>Optional key:value pairs mapping provider names to provider app IDs.</p>
     */
    inline UpdateIdentityPoolRequest& AddSupportedLoginProviders(const char* key, Aws::String&& value) { m_supportedLoginProvidersHasBeenSet = true; m_supportedLoginProviders[key] = value; return *this; }

    /**
     * <p>Optional key:value pairs mapping provider names to provider app IDs.</p>
     */
    inline UpdateIdentityPoolRequest& AddSupportedLoginProviders(Aws::String&& key, const char* value) { m_supportedLoginProvidersHasBeenSet = true; m_supportedLoginProviders[key] = value; return *this; }

    /**
     * <p>Optional key:value pairs mapping provider names to provider app IDs.</p>
     */
    inline UpdateIdentityPoolRequest& AddSupportedLoginProviders(const char* key, const char* value) { m_supportedLoginProvidersHasBeenSet = true; m_supportedLoginProviders[key] = value; return *this; }

    /**
     * <p>The "domain" by which Cognito will refer to your users.</p>
     */
    inline const Aws::String& GetDeveloperProviderName() const{ return m_developerProviderName; }

    /**
     * <p>The "domain" by which Cognito will refer to your users.</p>
     */
    inline void SetDeveloperProviderName(const Aws::String& value) { m_developerProviderNameHasBeenSet = true; m_developerProviderName = value; }

    /**
     * <p>The "domain" by which Cognito will refer to your users.</p>
     */
    inline void SetDeveloperProviderName(Aws::String&& value) { m_developerProviderNameHasBeenSet = true; m_developerProviderName = value; }

    /**
     * <p>The "domain" by which Cognito will refer to your users.</p>
     */
    inline void SetDeveloperProviderName(const char* value) { m_developerProviderNameHasBeenSet = true; m_developerProviderName.assign(value); }

    /**
     * <p>The "domain" by which Cognito will refer to your users.</p>
     */
    inline UpdateIdentityPoolRequest& WithDeveloperProviderName(const Aws::String& value) { SetDeveloperProviderName(value); return *this;}

    /**
     * <p>The "domain" by which Cognito will refer to your users.</p>
     */
    inline UpdateIdentityPoolRequest& WithDeveloperProviderName(Aws::String&& value) { SetDeveloperProviderName(value); return *this;}

    /**
     * <p>The "domain" by which Cognito will refer to your users.</p>
     */
    inline UpdateIdentityPoolRequest& WithDeveloperProviderName(const char* value) { SetDeveloperProviderName(value); return *this;}

    /**
     * <p>A list of OpendID Connect provider ARNs.</p>
     */
    inline const Aws::Vector<Aws::String>& GetOpenIdConnectProviderARNs() const{ return m_openIdConnectProviderARNs; }

    /**
     * <p>A list of OpendID Connect provider ARNs.</p>
     */
    inline void SetOpenIdConnectProviderARNs(const Aws::Vector<Aws::String>& value) { m_openIdConnectProviderARNsHasBeenSet = true; m_openIdConnectProviderARNs = value; }

    /**
     * <p>A list of OpendID Connect provider ARNs.</p>
     */
    inline void SetOpenIdConnectProviderARNs(Aws::Vector<Aws::String>&& value) { m_openIdConnectProviderARNsHasBeenSet = true; m_openIdConnectProviderARNs = value; }

    /**
     * <p>A list of OpendID Connect provider ARNs.</p>
     */
    inline UpdateIdentityPoolRequest& WithOpenIdConnectProviderARNs(const Aws::Vector<Aws::String>& value) { SetOpenIdConnectProviderARNs(value); return *this;}

    /**
     * <p>A list of OpendID Connect provider ARNs.</p>
     */
    inline UpdateIdentityPoolRequest& WithOpenIdConnectProviderARNs(Aws::Vector<Aws::String>&& value) { SetOpenIdConnectProviderARNs(value); return *this;}

    /**
     * <p>A list of OpendID Connect provider ARNs.</p>
     */
    inline UpdateIdentityPoolRequest& AddOpenIdConnectProviderARNs(const Aws::String& value) { m_openIdConnectProviderARNsHasBeenSet = true; m_openIdConnectProviderARNs.push_back(value); return *this; }

    /**
     * <p>A list of OpendID Connect provider ARNs.</p>
     */
    inline UpdateIdentityPoolRequest& AddOpenIdConnectProviderARNs(Aws::String&& value) { m_openIdConnectProviderARNsHasBeenSet = true; m_openIdConnectProviderARNs.push_back(value); return *this; }

    /**
     * <p>A list of OpendID Connect provider ARNs.</p>
     */
    inline UpdateIdentityPoolRequest& AddOpenIdConnectProviderARNs(const char* value) { m_openIdConnectProviderARNsHasBeenSet = true; m_openIdConnectProviderARNs.push_back(value); return *this; }

  private:
    Aws::String m_identityPoolId;
    bool m_identityPoolIdHasBeenSet;
    Aws::String m_identityPoolName;
    bool m_identityPoolNameHasBeenSet;
    bool m_allowUnauthenticatedIdentities;
    bool m_allowUnauthenticatedIdentitiesHasBeenSet;
    Aws::Map<Aws::String, Aws::String> m_supportedLoginProviders;
    bool m_supportedLoginProvidersHasBeenSet;
    Aws::String m_developerProviderName;
    bool m_developerProviderNameHasBeenSet;
    Aws::Vector<Aws::String> m_openIdConnectProviderARNs;
    bool m_openIdConnectProviderARNsHasBeenSet;
  };

} // namespace Model
} // namespace CognitoIdentity
} // namespace Aws
