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
#include <aws/autoscaling/AutoScaling_EXPORTS.h>
#include <aws/autoscaling/AutoScalingRequest.h>
#include <aws/core/utils/memory/stl/AWSString.h>
#include <aws/core/utils/memory/stl/AWSVector.h>

namespace Aws
{
namespace AutoScaling
{
namespace Model
{

  /**
   */
  class AWS_AUTOSCALING_API SuspendProcessesRequest : public AutoScalingRequest
  {
  public:
    SuspendProcessesRequest();
    Aws::String SerializePayload() const override;


    /**
     * <p>The name or Amazon Resource Name (ARN) of the Auto Scaling group.</p>
     */
    inline const Aws::String& GetAutoScalingGroupName() const{ return m_autoScalingGroupName; }

    /**
     * <p>The name or Amazon Resource Name (ARN) of the Auto Scaling group.</p>
     */
    inline void SetAutoScalingGroupName(const Aws::String& value) { m_autoScalingGroupNameHasBeenSet = true; m_autoScalingGroupName = value; }

    /**
     * <p>The name or Amazon Resource Name (ARN) of the Auto Scaling group.</p>
     */
    inline void SetAutoScalingGroupName(Aws::String&& value) { m_autoScalingGroupNameHasBeenSet = true; m_autoScalingGroupName = value; }

    /**
     * <p>The name or Amazon Resource Name (ARN) of the Auto Scaling group.</p>
     */
    inline void SetAutoScalingGroupName(const char* value) { m_autoScalingGroupNameHasBeenSet = true; m_autoScalingGroupName.assign(value); }

    /**
     * <p>The name or Amazon Resource Name (ARN) of the Auto Scaling group.</p>
     */
    inline SuspendProcessesRequest& WithAutoScalingGroupName(const Aws::String& value) { SetAutoScalingGroupName(value); return *this;}

    /**
     * <p>The name or Amazon Resource Name (ARN) of the Auto Scaling group.</p>
     */
    inline SuspendProcessesRequest& WithAutoScalingGroupName(Aws::String&& value) { SetAutoScalingGroupName(value); return *this;}

    /**
     * <p>The name or Amazon Resource Name (ARN) of the Auto Scaling group.</p>
     */
    inline SuspendProcessesRequest& WithAutoScalingGroupName(const char* value) { SetAutoScalingGroupName(value); return *this;}

    /**
     * <p>One or more of the following processes:</p> <ul>
     * <li><p><code>Launch</code></p></li> <li><p><code>Terminate</code></p></li>
     * <li><p><code>HealthCheck</code></p></li>
     * <li><p><code>ReplaceUnhealthy</code></p></li>
     * <li><p><code>AZRebalance</code></p></li>
     * <li><p><code>AlarmNotification</code></p></li>
     * <li><p><code>ScheduledActions</code></p></li>
     * <li><p><code>AddToLoadBalancer</code></p></li> </ul>
     */
    inline const Aws::Vector<Aws::String>& GetScalingProcesses() const{ return m_scalingProcesses; }

    /**
     * <p>One or more of the following processes:</p> <ul>
     * <li><p><code>Launch</code></p></li> <li><p><code>Terminate</code></p></li>
     * <li><p><code>HealthCheck</code></p></li>
     * <li><p><code>ReplaceUnhealthy</code></p></li>
     * <li><p><code>AZRebalance</code></p></li>
     * <li><p><code>AlarmNotification</code></p></li>
     * <li><p><code>ScheduledActions</code></p></li>
     * <li><p><code>AddToLoadBalancer</code></p></li> </ul>
     */
    inline void SetScalingProcesses(const Aws::Vector<Aws::String>& value) { m_scalingProcessesHasBeenSet = true; m_scalingProcesses = value; }

    /**
     * <p>One or more of the following processes:</p> <ul>
     * <li><p><code>Launch</code></p></li> <li><p><code>Terminate</code></p></li>
     * <li><p><code>HealthCheck</code></p></li>
     * <li><p><code>ReplaceUnhealthy</code></p></li>
     * <li><p><code>AZRebalance</code></p></li>
     * <li><p><code>AlarmNotification</code></p></li>
     * <li><p><code>ScheduledActions</code></p></li>
     * <li><p><code>AddToLoadBalancer</code></p></li> </ul>
     */
    inline void SetScalingProcesses(Aws::Vector<Aws::String>&& value) { m_scalingProcessesHasBeenSet = true; m_scalingProcesses = value; }

    /**
     * <p>One or more of the following processes:</p> <ul>
     * <li><p><code>Launch</code></p></li> <li><p><code>Terminate</code></p></li>
     * <li><p><code>HealthCheck</code></p></li>
     * <li><p><code>ReplaceUnhealthy</code></p></li>
     * <li><p><code>AZRebalance</code></p></li>
     * <li><p><code>AlarmNotification</code></p></li>
     * <li><p><code>ScheduledActions</code></p></li>
     * <li><p><code>AddToLoadBalancer</code></p></li> </ul>
     */
    inline SuspendProcessesRequest& WithScalingProcesses(const Aws::Vector<Aws::String>& value) { SetScalingProcesses(value); return *this;}

    /**
     * <p>One or more of the following processes:</p> <ul>
     * <li><p><code>Launch</code></p></li> <li><p><code>Terminate</code></p></li>
     * <li><p><code>HealthCheck</code></p></li>
     * <li><p><code>ReplaceUnhealthy</code></p></li>
     * <li><p><code>AZRebalance</code></p></li>
     * <li><p><code>AlarmNotification</code></p></li>
     * <li><p><code>ScheduledActions</code></p></li>
     * <li><p><code>AddToLoadBalancer</code></p></li> </ul>
     */
    inline SuspendProcessesRequest& WithScalingProcesses(Aws::Vector<Aws::String>&& value) { SetScalingProcesses(value); return *this;}

    /**
     * <p>One or more of the following processes:</p> <ul>
     * <li><p><code>Launch</code></p></li> <li><p><code>Terminate</code></p></li>
     * <li><p><code>HealthCheck</code></p></li>
     * <li><p><code>ReplaceUnhealthy</code></p></li>
     * <li><p><code>AZRebalance</code></p></li>
     * <li><p><code>AlarmNotification</code></p></li>
     * <li><p><code>ScheduledActions</code></p></li>
     * <li><p><code>AddToLoadBalancer</code></p></li> </ul>
     */
    inline SuspendProcessesRequest& AddScalingProcesses(const Aws::String& value) { m_scalingProcessesHasBeenSet = true; m_scalingProcesses.push_back(value); return *this; }

    /**
     * <p>One or more of the following processes:</p> <ul>
     * <li><p><code>Launch</code></p></li> <li><p><code>Terminate</code></p></li>
     * <li><p><code>HealthCheck</code></p></li>
     * <li><p><code>ReplaceUnhealthy</code></p></li>
     * <li><p><code>AZRebalance</code></p></li>
     * <li><p><code>AlarmNotification</code></p></li>
     * <li><p><code>ScheduledActions</code></p></li>
     * <li><p><code>AddToLoadBalancer</code></p></li> </ul>
     */
    inline SuspendProcessesRequest& AddScalingProcesses(Aws::String&& value) { m_scalingProcessesHasBeenSet = true; m_scalingProcesses.push_back(value); return *this; }

    /**
     * <p>One or more of the following processes:</p> <ul>
     * <li><p><code>Launch</code></p></li> <li><p><code>Terminate</code></p></li>
     * <li><p><code>HealthCheck</code></p></li>
     * <li><p><code>ReplaceUnhealthy</code></p></li>
     * <li><p><code>AZRebalance</code></p></li>
     * <li><p><code>AlarmNotification</code></p></li>
     * <li><p><code>ScheduledActions</code></p></li>
     * <li><p><code>AddToLoadBalancer</code></p></li> </ul>
     */
    inline SuspendProcessesRequest& AddScalingProcesses(const char* value) { m_scalingProcessesHasBeenSet = true; m_scalingProcesses.push_back(value); return *this; }

  private:
    Aws::String m_autoScalingGroupName;
    bool m_autoScalingGroupNameHasBeenSet;
    Aws::Vector<Aws::String> m_scalingProcesses;
    bool m_scalingProcessesHasBeenSet;
  };

} // namespace Model
} // namespace AutoScaling
} // namespace Aws
