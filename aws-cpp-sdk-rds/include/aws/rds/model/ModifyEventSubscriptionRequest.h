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
#include <aws/rds/RDS_EXPORTS.h>
#include <aws/rds/RDSRequest.h>
#include <aws/core/utils/memory/stl/AWSString.h>
#include <aws/core/utils/memory/stl/AWSVector.h>

namespace Aws
{
namespace RDS
{
namespace Model
{

  /**
   * <p/>
   */
  class AWS_RDS_API ModifyEventSubscriptionRequest : public RDSRequest
  {
  public:
    ModifyEventSubscriptionRequest();
    Aws::String SerializePayload() const override;


    /**
     * <p>The name of the RDS event notification subscription.</p>
     */
    inline const Aws::String& GetSubscriptionName() const{ return m_subscriptionName; }

    /**
     * <p>The name of the RDS event notification subscription.</p>
     */
    inline void SetSubscriptionName(const Aws::String& value) { m_subscriptionNameHasBeenSet = true; m_subscriptionName = value; }

    /**
     * <p>The name of the RDS event notification subscription.</p>
     */
    inline void SetSubscriptionName(Aws::String&& value) { m_subscriptionNameHasBeenSet = true; m_subscriptionName = value; }

    /**
     * <p>The name of the RDS event notification subscription.</p>
     */
    inline void SetSubscriptionName(const char* value) { m_subscriptionNameHasBeenSet = true; m_subscriptionName.assign(value); }

    /**
     * <p>The name of the RDS event notification subscription.</p>
     */
    inline ModifyEventSubscriptionRequest& WithSubscriptionName(const Aws::String& value) { SetSubscriptionName(value); return *this;}

    /**
     * <p>The name of the RDS event notification subscription.</p>
     */
    inline ModifyEventSubscriptionRequest& WithSubscriptionName(Aws::String&& value) { SetSubscriptionName(value); return *this;}

    /**
     * <p>The name of the RDS event notification subscription.</p>
     */
    inline ModifyEventSubscriptionRequest& WithSubscriptionName(const char* value) { SetSubscriptionName(value); return *this;}

    /**
     * <p> The Amazon Resource Name (ARN) of the SNS topic created for event
     * notification. The ARN is created by Amazon SNS when you create a topic and
     * subscribe to it. </p>
     */
    inline const Aws::String& GetSnsTopicArn() const{ return m_snsTopicArn; }

    /**
     * <p> The Amazon Resource Name (ARN) of the SNS topic created for event
     * notification. The ARN is created by Amazon SNS when you create a topic and
     * subscribe to it. </p>
     */
    inline void SetSnsTopicArn(const Aws::String& value) { m_snsTopicArnHasBeenSet = true; m_snsTopicArn = value; }

    /**
     * <p> The Amazon Resource Name (ARN) of the SNS topic created for event
     * notification. The ARN is created by Amazon SNS when you create a topic and
     * subscribe to it. </p>
     */
    inline void SetSnsTopicArn(Aws::String&& value) { m_snsTopicArnHasBeenSet = true; m_snsTopicArn = value; }

    /**
     * <p> The Amazon Resource Name (ARN) of the SNS topic created for event
     * notification. The ARN is created by Amazon SNS when you create a topic and
     * subscribe to it. </p>
     */
    inline void SetSnsTopicArn(const char* value) { m_snsTopicArnHasBeenSet = true; m_snsTopicArn.assign(value); }

    /**
     * <p> The Amazon Resource Name (ARN) of the SNS topic created for event
     * notification. The ARN is created by Amazon SNS when you create a topic and
     * subscribe to it. </p>
     */
    inline ModifyEventSubscriptionRequest& WithSnsTopicArn(const Aws::String& value) { SetSnsTopicArn(value); return *this;}

    /**
     * <p> The Amazon Resource Name (ARN) of the SNS topic created for event
     * notification. The ARN is created by Amazon SNS when you create a topic and
     * subscribe to it. </p>
     */
    inline ModifyEventSubscriptionRequest& WithSnsTopicArn(Aws::String&& value) { SetSnsTopicArn(value); return *this;}

    /**
     * <p> The Amazon Resource Name (ARN) of the SNS topic created for event
     * notification. The ARN is created by Amazon SNS when you create a topic and
     * subscribe to it. </p>
     */
    inline ModifyEventSubscriptionRequest& WithSnsTopicArn(const char* value) { SetSnsTopicArn(value); return *this;}

    /**
     * <p> The type of source that will be generating the events. For example, if you
     * want to be notified of events generated by a DB instance, you would set this
     * parameter to db-instance. if this value is not specified, all events are
     * returned. </p> <p>Valid values: db-instance | db-parameter-group |
     * db-security-group | db-snapshot</p>
     */
    inline const Aws::String& GetSourceType() const{ return m_sourceType; }

    /**
     * <p> The type of source that will be generating the events. For example, if you
     * want to be notified of events generated by a DB instance, you would set this
     * parameter to db-instance. if this value is not specified, all events are
     * returned. </p> <p>Valid values: db-instance | db-parameter-group |
     * db-security-group | db-snapshot</p>
     */
    inline void SetSourceType(const Aws::String& value) { m_sourceTypeHasBeenSet = true; m_sourceType = value; }

    /**
     * <p> The type of source that will be generating the events. For example, if you
     * want to be notified of events generated by a DB instance, you would set this
     * parameter to db-instance. if this value is not specified, all events are
     * returned. </p> <p>Valid values: db-instance | db-parameter-group |
     * db-security-group | db-snapshot</p>
     */
    inline void SetSourceType(Aws::String&& value) { m_sourceTypeHasBeenSet = true; m_sourceType = value; }

    /**
     * <p> The type of source that will be generating the events. For example, if you
     * want to be notified of events generated by a DB instance, you would set this
     * parameter to db-instance. if this value is not specified, all events are
     * returned. </p> <p>Valid values: db-instance | db-parameter-group |
     * db-security-group | db-snapshot</p>
     */
    inline void SetSourceType(const char* value) { m_sourceTypeHasBeenSet = true; m_sourceType.assign(value); }

    /**
     * <p> The type of source that will be generating the events. For example, if you
     * want to be notified of events generated by a DB instance, you would set this
     * parameter to db-instance. if this value is not specified, all events are
     * returned. </p> <p>Valid values: db-instance | db-parameter-group |
     * db-security-group | db-snapshot</p>
     */
    inline ModifyEventSubscriptionRequest& WithSourceType(const Aws::String& value) { SetSourceType(value); return *this;}

    /**
     * <p> The type of source that will be generating the events. For example, if you
     * want to be notified of events generated by a DB instance, you would set this
     * parameter to db-instance. if this value is not specified, all events are
     * returned. </p> <p>Valid values: db-instance | db-parameter-group |
     * db-security-group | db-snapshot</p>
     */
    inline ModifyEventSubscriptionRequest& WithSourceType(Aws::String&& value) { SetSourceType(value); return *this;}

    /**
     * <p> The type of source that will be generating the events. For example, if you
     * want to be notified of events generated by a DB instance, you would set this
     * parameter to db-instance. if this value is not specified, all events are
     * returned. </p> <p>Valid values: db-instance | db-parameter-group |
     * db-security-group | db-snapshot</p>
     */
    inline ModifyEventSubscriptionRequest& WithSourceType(const char* value) { SetSourceType(value); return *this;}

    /**
     * <p> A list of event categories for a SourceType that you want to subscribe to.
     * You can see a list of the categories for a given SourceType in the <a
     * href="http://docs.aws.amazon.com/AmazonRDS/latest/UserGuide/USER_Events.html">Events</a>
     * topic in the Amazon RDS User Guide or by using the
     * <b>DescribeEventCategories</b> action. </p>
     */
    inline const Aws::Vector<Aws::String>& GetEventCategories() const{ return m_eventCategories; }

    /**
     * <p> A list of event categories for a SourceType that you want to subscribe to.
     * You can see a list of the categories for a given SourceType in the <a
     * href="http://docs.aws.amazon.com/AmazonRDS/latest/UserGuide/USER_Events.html">Events</a>
     * topic in the Amazon RDS User Guide or by using the
     * <b>DescribeEventCategories</b> action. </p>
     */
    inline void SetEventCategories(const Aws::Vector<Aws::String>& value) { m_eventCategoriesHasBeenSet = true; m_eventCategories = value; }

    /**
     * <p> A list of event categories for a SourceType that you want to subscribe to.
     * You can see a list of the categories for a given SourceType in the <a
     * href="http://docs.aws.amazon.com/AmazonRDS/latest/UserGuide/USER_Events.html">Events</a>
     * topic in the Amazon RDS User Guide or by using the
     * <b>DescribeEventCategories</b> action. </p>
     */
    inline void SetEventCategories(Aws::Vector<Aws::String>&& value) { m_eventCategoriesHasBeenSet = true; m_eventCategories = value; }

    /**
     * <p> A list of event categories for a SourceType that you want to subscribe to.
     * You can see a list of the categories for a given SourceType in the <a
     * href="http://docs.aws.amazon.com/AmazonRDS/latest/UserGuide/USER_Events.html">Events</a>
     * topic in the Amazon RDS User Guide or by using the
     * <b>DescribeEventCategories</b> action. </p>
     */
    inline ModifyEventSubscriptionRequest& WithEventCategories(const Aws::Vector<Aws::String>& value) { SetEventCategories(value); return *this;}

    /**
     * <p> A list of event categories for a SourceType that you want to subscribe to.
     * You can see a list of the categories for a given SourceType in the <a
     * href="http://docs.aws.amazon.com/AmazonRDS/latest/UserGuide/USER_Events.html">Events</a>
     * topic in the Amazon RDS User Guide or by using the
     * <b>DescribeEventCategories</b> action. </p>
     */
    inline ModifyEventSubscriptionRequest& WithEventCategories(Aws::Vector<Aws::String>&& value) { SetEventCategories(value); return *this;}

    /**
     * <p> A list of event categories for a SourceType that you want to subscribe to.
     * You can see a list of the categories for a given SourceType in the <a
     * href="http://docs.aws.amazon.com/AmazonRDS/latest/UserGuide/USER_Events.html">Events</a>
     * topic in the Amazon RDS User Guide or by using the
     * <b>DescribeEventCategories</b> action. </p>
     */
    inline ModifyEventSubscriptionRequest& AddEventCategories(const Aws::String& value) { m_eventCategoriesHasBeenSet = true; m_eventCategories.push_back(value); return *this; }

    /**
     * <p> A list of event categories for a SourceType that you want to subscribe to.
     * You can see a list of the categories for a given SourceType in the <a
     * href="http://docs.aws.amazon.com/AmazonRDS/latest/UserGuide/USER_Events.html">Events</a>
     * topic in the Amazon RDS User Guide or by using the
     * <b>DescribeEventCategories</b> action. </p>
     */
    inline ModifyEventSubscriptionRequest& AddEventCategories(Aws::String&& value) { m_eventCategoriesHasBeenSet = true; m_eventCategories.push_back(value); return *this; }

    /**
     * <p> A list of event categories for a SourceType that you want to subscribe to.
     * You can see a list of the categories for a given SourceType in the <a
     * href="http://docs.aws.amazon.com/AmazonRDS/latest/UserGuide/USER_Events.html">Events</a>
     * topic in the Amazon RDS User Guide or by using the
     * <b>DescribeEventCategories</b> action. </p>
     */
    inline ModifyEventSubscriptionRequest& AddEventCategories(const char* value) { m_eventCategoriesHasBeenSet = true; m_eventCategories.push_back(value); return *this; }

    /**
     * <p> A Boolean value; set to <b>true</b> to activate the subscription. </p>
     */
    inline bool GetEnabled() const{ return m_enabled; }

    /**
     * <p> A Boolean value; set to <b>true</b> to activate the subscription. </p>
     */
    inline void SetEnabled(bool value) { m_enabledHasBeenSet = true; m_enabled = value; }

    /**
     * <p> A Boolean value; set to <b>true</b> to activate the subscription. </p>
     */
    inline ModifyEventSubscriptionRequest& WithEnabled(bool value) { SetEnabled(value); return *this;}

  private:
    Aws::String m_subscriptionName;
    bool m_subscriptionNameHasBeenSet;
    Aws::String m_snsTopicArn;
    bool m_snsTopicArnHasBeenSet;
    Aws::String m_sourceType;
    bool m_sourceTypeHasBeenSet;
    Aws::Vector<Aws::String> m_eventCategories;
    bool m_eventCategoriesHasBeenSet;
    bool m_enabled;
    bool m_enabledHasBeenSet;
  };

} // namespace Model
} // namespace RDS
} // namespace Aws
