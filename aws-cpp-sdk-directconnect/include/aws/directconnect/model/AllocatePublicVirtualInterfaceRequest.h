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
#include <aws/directconnect/DirectConnect_EXPORTS.h>
#include <aws/directconnect/DirectConnectRequest.h>
#include <aws/core/utils/memory/stl/AWSString.h>
#include <aws/directconnect/model/NewPublicVirtualInterfaceAllocation.h>

namespace Aws
{
namespace DirectConnect
{
namespace Model
{

  /**
   * <p>Container for the parameters to the AllocatePublicVirtualInterface
   * operation.</p>
   */
  class AWS_DIRECTCONNECT_API AllocatePublicVirtualInterfaceRequest : public DirectConnectRequest
  {
  public:
    AllocatePublicVirtualInterfaceRequest();
    Aws::String SerializePayload() const override;

    Aws::Http::HeaderValueCollection GetRequestSpecificHeaders() const override;


    /**
     * <p>The connection ID on which the public virtual interface is provisioned.</p>
     * <p>Default: None</p>
     */
    inline const Aws::String& GetConnectionId() const{ return m_connectionId; }

    /**
     * <p>The connection ID on which the public virtual interface is provisioned.</p>
     * <p>Default: None</p>
     */
    inline void SetConnectionId(const Aws::String& value) { m_connectionIdHasBeenSet = true; m_connectionId = value; }

    /**
     * <p>The connection ID on which the public virtual interface is provisioned.</p>
     * <p>Default: None</p>
     */
    inline void SetConnectionId(Aws::String&& value) { m_connectionIdHasBeenSet = true; m_connectionId = value; }

    /**
     * <p>The connection ID on which the public virtual interface is provisioned.</p>
     * <p>Default: None</p>
     */
    inline void SetConnectionId(const char* value) { m_connectionIdHasBeenSet = true; m_connectionId.assign(value); }

    /**
     * <p>The connection ID on which the public virtual interface is provisioned.</p>
     * <p>Default: None</p>
     */
    inline AllocatePublicVirtualInterfaceRequest& WithConnectionId(const Aws::String& value) { SetConnectionId(value); return *this;}

    /**
     * <p>The connection ID on which the public virtual interface is provisioned.</p>
     * <p>Default: None</p>
     */
    inline AllocatePublicVirtualInterfaceRequest& WithConnectionId(Aws::String&& value) { SetConnectionId(value); return *this;}

    /**
     * <p>The connection ID on which the public virtual interface is provisioned.</p>
     * <p>Default: None</p>
     */
    inline AllocatePublicVirtualInterfaceRequest& WithConnectionId(const char* value) { SetConnectionId(value); return *this;}

    /**
     * <p>The AWS account that will own the new public virtual interface.</p>
     * <p>Default: None</p>
     */
    inline const Aws::String& GetOwnerAccount() const{ return m_ownerAccount; }

    /**
     * <p>The AWS account that will own the new public virtual interface.</p>
     * <p>Default: None</p>
     */
    inline void SetOwnerAccount(const Aws::String& value) { m_ownerAccountHasBeenSet = true; m_ownerAccount = value; }

    /**
     * <p>The AWS account that will own the new public virtual interface.</p>
     * <p>Default: None</p>
     */
    inline void SetOwnerAccount(Aws::String&& value) { m_ownerAccountHasBeenSet = true; m_ownerAccount = value; }

    /**
     * <p>The AWS account that will own the new public virtual interface.</p>
     * <p>Default: None</p>
     */
    inline void SetOwnerAccount(const char* value) { m_ownerAccountHasBeenSet = true; m_ownerAccount.assign(value); }

    /**
     * <p>The AWS account that will own the new public virtual interface.</p>
     * <p>Default: None</p>
     */
    inline AllocatePublicVirtualInterfaceRequest& WithOwnerAccount(const Aws::String& value) { SetOwnerAccount(value); return *this;}

    /**
     * <p>The AWS account that will own the new public virtual interface.</p>
     * <p>Default: None</p>
     */
    inline AllocatePublicVirtualInterfaceRequest& WithOwnerAccount(Aws::String&& value) { SetOwnerAccount(value); return *this;}

    /**
     * <p>The AWS account that will own the new public virtual interface.</p>
     * <p>Default: None</p>
     */
    inline AllocatePublicVirtualInterfaceRequest& WithOwnerAccount(const char* value) { SetOwnerAccount(value); return *this;}

    /**
     * <p>Detailed information for the public virtual interface to be provisioned.</p>
     * <p>Default: None</p>
     */
    inline const NewPublicVirtualInterfaceAllocation& GetNewPublicVirtualInterfaceAllocation() const{ return m_newPublicVirtualInterfaceAllocation; }

    /**
     * <p>Detailed information for the public virtual interface to be provisioned.</p>
     * <p>Default: None</p>
     */
    inline void SetNewPublicVirtualInterfaceAllocation(const NewPublicVirtualInterfaceAllocation& value) { m_newPublicVirtualInterfaceAllocationHasBeenSet = true; m_newPublicVirtualInterfaceAllocation = value; }

    /**
     * <p>Detailed information for the public virtual interface to be provisioned.</p>
     * <p>Default: None</p>
     */
    inline void SetNewPublicVirtualInterfaceAllocation(NewPublicVirtualInterfaceAllocation&& value) { m_newPublicVirtualInterfaceAllocationHasBeenSet = true; m_newPublicVirtualInterfaceAllocation = value; }

    /**
     * <p>Detailed information for the public virtual interface to be provisioned.</p>
     * <p>Default: None</p>
     */
    inline AllocatePublicVirtualInterfaceRequest& WithNewPublicVirtualInterfaceAllocation(const NewPublicVirtualInterfaceAllocation& value) { SetNewPublicVirtualInterfaceAllocation(value); return *this;}

    /**
     * <p>Detailed information for the public virtual interface to be provisioned.</p>
     * <p>Default: None</p>
     */
    inline AllocatePublicVirtualInterfaceRequest& WithNewPublicVirtualInterfaceAllocation(NewPublicVirtualInterfaceAllocation&& value) { SetNewPublicVirtualInterfaceAllocation(value); return *this;}

  private:
    Aws::String m_connectionId;
    bool m_connectionIdHasBeenSet;
    Aws::String m_ownerAccount;
    bool m_ownerAccountHasBeenSet;
    NewPublicVirtualInterfaceAllocation m_newPublicVirtualInterfaceAllocation;
    bool m_newPublicVirtualInterfaceAllocationHasBeenSet;
  };

} // namespace Model
} // namespace DirectConnect
} // namespace Aws
