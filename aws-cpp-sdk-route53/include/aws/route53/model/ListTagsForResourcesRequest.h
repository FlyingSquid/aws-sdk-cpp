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
#include <aws/route53/Route53_EXPORTS.h>
#include <aws/route53/Route53Request.h>
#include <aws/route53/model/TagResourceType.h>
#include <aws/core/utils/memory/stl/AWSVector.h>
#include <aws/core/utils/memory/stl/AWSString.h>

namespace Aws
{
namespace Route53
{
namespace Model
{

  /**
   * <p>A complex type containing information about a request for a list of the tags
   * that are associated with up to 10 specified resources.</p>
   */
  class AWS_ROUTE53_API ListTagsForResourcesRequest : public Route53Request
  {
  public:
    ListTagsForResourcesRequest();
    Aws::String SerializePayload() const override;


    /**
     * <p>The type of the resources.</p> <p>- The resource type for health checks is
     * <code>healthcheck</code>.</p> <p>- The resource type for hosted zones is
     * <code>hostedzone</code>.</p>
     */
    inline const TagResourceType& GetResourceType() const{ return m_resourceType; }

    /**
     * <p>The type of the resources.</p> <p>- The resource type for health checks is
     * <code>healthcheck</code>.</p> <p>- The resource type for hosted zones is
     * <code>hostedzone</code>.</p>
     */
    inline void SetResourceType(const TagResourceType& value) { m_resourceTypeHasBeenSet = true; m_resourceType = value; }

    /**
     * <p>The type of the resources.</p> <p>- The resource type for health checks is
     * <code>healthcheck</code>.</p> <p>- The resource type for hosted zones is
     * <code>hostedzone</code>.</p>
     */
    inline void SetResourceType(TagResourceType&& value) { m_resourceTypeHasBeenSet = true; m_resourceType = value; }

    /**
     * <p>The type of the resources.</p> <p>- The resource type for health checks is
     * <code>healthcheck</code>.</p> <p>- The resource type for hosted zones is
     * <code>hostedzone</code>.</p>
     */
    inline ListTagsForResourcesRequest& WithResourceType(const TagResourceType& value) { SetResourceType(value); return *this;}

    /**
     * <p>The type of the resources.</p> <p>- The resource type for health checks is
     * <code>healthcheck</code>.</p> <p>- The resource type for hosted zones is
     * <code>hostedzone</code>.</p>
     */
    inline ListTagsForResourcesRequest& WithResourceType(TagResourceType&& value) { SetResourceType(value); return *this;}

    /**
     * <p>A complex type that contains the ResourceId element for each resource for
     * which you want to get a list of tags.</p>
     */
    inline const Aws::Vector<Aws::String>& GetResourceIds() const{ return m_resourceIds; }

    /**
     * <p>A complex type that contains the ResourceId element for each resource for
     * which you want to get a list of tags.</p>
     */
    inline void SetResourceIds(const Aws::Vector<Aws::String>& value) { m_resourceIdsHasBeenSet = true; m_resourceIds = value; }

    /**
     * <p>A complex type that contains the ResourceId element for each resource for
     * which you want to get a list of tags.</p>
     */
    inline void SetResourceIds(Aws::Vector<Aws::String>&& value) { m_resourceIdsHasBeenSet = true; m_resourceIds = value; }

    /**
     * <p>A complex type that contains the ResourceId element for each resource for
     * which you want to get a list of tags.</p>
     */
    inline ListTagsForResourcesRequest& WithResourceIds(const Aws::Vector<Aws::String>& value) { SetResourceIds(value); return *this;}

    /**
     * <p>A complex type that contains the ResourceId element for each resource for
     * which you want to get a list of tags.</p>
     */
    inline ListTagsForResourcesRequest& WithResourceIds(Aws::Vector<Aws::String>&& value) { SetResourceIds(value); return *this;}

    /**
     * <p>A complex type that contains the ResourceId element for each resource for
     * which you want to get a list of tags.</p>
     */
    inline ListTagsForResourcesRequest& AddResourceIds(const Aws::String& value) { m_resourceIdsHasBeenSet = true; m_resourceIds.push_back(value); return *this; }

    /**
     * <p>A complex type that contains the ResourceId element for each resource for
     * which you want to get a list of tags.</p>
     */
    inline ListTagsForResourcesRequest& AddResourceIds(Aws::String&& value) { m_resourceIdsHasBeenSet = true; m_resourceIds.push_back(value); return *this; }

    /**
     * <p>A complex type that contains the ResourceId element for each resource for
     * which you want to get a list of tags.</p>
     */
    inline ListTagsForResourcesRequest& AddResourceIds(const char* value) { m_resourceIdsHasBeenSet = true; m_resourceIds.push_back(value); return *this; }

  private:
    TagResourceType m_resourceType;
    bool m_resourceTypeHasBeenSet;
    Aws::Vector<Aws::String> m_resourceIds;
    bool m_resourceIdsHasBeenSet;
  };

} // namespace Model
} // namespace Route53
} // namespace Aws
