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
#include <aws/ds/DirectoryService_EXPORTS.h>
#include <aws/ds/DirectoryServiceRequest.h>
#include <aws/core/utils/memory/stl/AWSString.h>

namespace Aws
{
namespace DirectoryService
{
namespace Model
{

  /**
   * Deletes the local side of an existing trust relationship between the Microsoft
   * AD in the AWS cloud and the external domain.
   */
  class AWS_DIRECTORYSERVICE_API DeleteTrustRequest : public DirectoryServiceRequest
  {
  public:
    DeleteTrustRequest();
    Aws::String SerializePayload() const override;

    Aws::Http::HeaderValueCollection GetRequestSpecificHeaders() const override;


    /**
     * The Trust ID of the trust relationship to be deleted.
     */
    inline const Aws::String& GetTrustId() const{ return m_trustId; }

    /**
     * The Trust ID of the trust relationship to be deleted.
     */
    inline void SetTrustId(const Aws::String& value) { m_trustIdHasBeenSet = true; m_trustId = value; }

    /**
     * The Trust ID of the trust relationship to be deleted.
     */
    inline void SetTrustId(Aws::String&& value) { m_trustIdHasBeenSet = true; m_trustId = value; }

    /**
     * The Trust ID of the trust relationship to be deleted.
     */
    inline void SetTrustId(const char* value) { m_trustIdHasBeenSet = true; m_trustId.assign(value); }

    /**
     * The Trust ID of the trust relationship to be deleted.
     */
    inline DeleteTrustRequest& WithTrustId(const Aws::String& value) { SetTrustId(value); return *this;}

    /**
     * The Trust ID of the trust relationship to be deleted.
     */
    inline DeleteTrustRequest& WithTrustId(Aws::String&& value) { SetTrustId(value); return *this;}

    /**
     * The Trust ID of the trust relationship to be deleted.
     */
    inline DeleteTrustRequest& WithTrustId(const char* value) { SetTrustId(value); return *this;}

  private:
    Aws::String m_trustId;
    bool m_trustIdHasBeenSet;
  };

} // namespace Model
} // namespace DirectoryService
} // namespace Aws
