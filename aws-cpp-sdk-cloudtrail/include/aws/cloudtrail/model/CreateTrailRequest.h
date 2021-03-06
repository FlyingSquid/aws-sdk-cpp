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
#include <aws/cloudtrail/CloudTrail_EXPORTS.h>
#include <aws/cloudtrail/CloudTrailRequest.h>
#include <aws/core/utils/memory/stl/AWSString.h>

namespace Aws
{
namespace CloudTrail
{
namespace Model
{

  /**
   * <p>Specifies the settings for each trail.</p>
   */
  class AWS_CLOUDTRAIL_API CreateTrailRequest : public CloudTrailRequest
  {
  public:
    CreateTrailRequest();
    Aws::String SerializePayload() const override;

    Aws::Http::HeaderValueCollection GetRequestSpecificHeaders() const override;


    /**
     * <p>Specifies the name of the trail. The name must meet the following
     * requirements:</p> <ul> <li>Contain only ASCII letters (a-z, A-Z), numbers (0-9),
     * periods (.), underscores (_), or dashes (-)</li> <li>Start with a letter or
     * number, and end with a letter or number</li> <li>Be between 3 and 128
     * characters</li> <li>Have no adjacent periods, underscores or dashes. Names like
     * <code>my-_namespace</code> and <code>my--namespace</code> are invalid.</li>
     * <li>Not be in IP address format (for example, 192.168.5.4)</li> </ul>
     */
    inline const Aws::String& GetName() const{ return m_name; }

    /**
     * <p>Specifies the name of the trail. The name must meet the following
     * requirements:</p> <ul> <li>Contain only ASCII letters (a-z, A-Z), numbers (0-9),
     * periods (.), underscores (_), or dashes (-)</li> <li>Start with a letter or
     * number, and end with a letter or number</li> <li>Be between 3 and 128
     * characters</li> <li>Have no adjacent periods, underscores or dashes. Names like
     * <code>my-_namespace</code> and <code>my--namespace</code> are invalid.</li>
     * <li>Not be in IP address format (for example, 192.168.5.4)</li> </ul>
     */
    inline void SetName(const Aws::String& value) { m_nameHasBeenSet = true; m_name = value; }

    /**
     * <p>Specifies the name of the trail. The name must meet the following
     * requirements:</p> <ul> <li>Contain only ASCII letters (a-z, A-Z), numbers (0-9),
     * periods (.), underscores (_), or dashes (-)</li> <li>Start with a letter or
     * number, and end with a letter or number</li> <li>Be between 3 and 128
     * characters</li> <li>Have no adjacent periods, underscores or dashes. Names like
     * <code>my-_namespace</code> and <code>my--namespace</code> are invalid.</li>
     * <li>Not be in IP address format (for example, 192.168.5.4)</li> </ul>
     */
    inline void SetName(Aws::String&& value) { m_nameHasBeenSet = true; m_name = value; }

    /**
     * <p>Specifies the name of the trail. The name must meet the following
     * requirements:</p> <ul> <li>Contain only ASCII letters (a-z, A-Z), numbers (0-9),
     * periods (.), underscores (_), or dashes (-)</li> <li>Start with a letter or
     * number, and end with a letter or number</li> <li>Be between 3 and 128
     * characters</li> <li>Have no adjacent periods, underscores or dashes. Names like
     * <code>my-_namespace</code> and <code>my--namespace</code> are invalid.</li>
     * <li>Not be in IP address format (for example, 192.168.5.4)</li> </ul>
     */
    inline void SetName(const char* value) { m_nameHasBeenSet = true; m_name.assign(value); }

    /**
     * <p>Specifies the name of the trail. The name must meet the following
     * requirements:</p> <ul> <li>Contain only ASCII letters (a-z, A-Z), numbers (0-9),
     * periods (.), underscores (_), or dashes (-)</li> <li>Start with a letter or
     * number, and end with a letter or number</li> <li>Be between 3 and 128
     * characters</li> <li>Have no adjacent periods, underscores or dashes. Names like
     * <code>my-_namespace</code> and <code>my--namespace</code> are invalid.</li>
     * <li>Not be in IP address format (for example, 192.168.5.4)</li> </ul>
     */
    inline CreateTrailRequest& WithName(const Aws::String& value) { SetName(value); return *this;}

    /**
     * <p>Specifies the name of the trail. The name must meet the following
     * requirements:</p> <ul> <li>Contain only ASCII letters (a-z, A-Z), numbers (0-9),
     * periods (.), underscores (_), or dashes (-)</li> <li>Start with a letter or
     * number, and end with a letter or number</li> <li>Be between 3 and 128
     * characters</li> <li>Have no adjacent periods, underscores or dashes. Names like
     * <code>my-_namespace</code> and <code>my--namespace</code> are invalid.</li>
     * <li>Not be in IP address format (for example, 192.168.5.4)</li> </ul>
     */
    inline CreateTrailRequest& WithName(Aws::String&& value) { SetName(value); return *this;}

    /**
     * <p>Specifies the name of the trail. The name must meet the following
     * requirements:</p> <ul> <li>Contain only ASCII letters (a-z, A-Z), numbers (0-9),
     * periods (.), underscores (_), or dashes (-)</li> <li>Start with a letter or
     * number, and end with a letter or number</li> <li>Be between 3 and 128
     * characters</li> <li>Have no adjacent periods, underscores or dashes. Names like
     * <code>my-_namespace</code> and <code>my--namespace</code> are invalid.</li>
     * <li>Not be in IP address format (for example, 192.168.5.4)</li> </ul>
     */
    inline CreateTrailRequest& WithName(const char* value) { SetName(value); return *this;}

    /**
     * <p>Specifies the name of the Amazon S3 bucket designated for publishing log
     * files. See <a
     * href="http://docs.aws.amazon.com/awscloudtrail/latest/userguide/create_trail_naming_policy.html">Amazon
     * S3 Bucket Naming Requirements</a>.</p>
     */
    inline const Aws::String& GetS3BucketName() const{ return m_s3BucketName; }

    /**
     * <p>Specifies the name of the Amazon S3 bucket designated for publishing log
     * files. See <a
     * href="http://docs.aws.amazon.com/awscloudtrail/latest/userguide/create_trail_naming_policy.html">Amazon
     * S3 Bucket Naming Requirements</a>.</p>
     */
    inline void SetS3BucketName(const Aws::String& value) { m_s3BucketNameHasBeenSet = true; m_s3BucketName = value; }

    /**
     * <p>Specifies the name of the Amazon S3 bucket designated for publishing log
     * files. See <a
     * href="http://docs.aws.amazon.com/awscloudtrail/latest/userguide/create_trail_naming_policy.html">Amazon
     * S3 Bucket Naming Requirements</a>.</p>
     */
    inline void SetS3BucketName(Aws::String&& value) { m_s3BucketNameHasBeenSet = true; m_s3BucketName = value; }

    /**
     * <p>Specifies the name of the Amazon S3 bucket designated for publishing log
     * files. See <a
     * href="http://docs.aws.amazon.com/awscloudtrail/latest/userguide/create_trail_naming_policy.html">Amazon
     * S3 Bucket Naming Requirements</a>.</p>
     */
    inline void SetS3BucketName(const char* value) { m_s3BucketNameHasBeenSet = true; m_s3BucketName.assign(value); }

    /**
     * <p>Specifies the name of the Amazon S3 bucket designated for publishing log
     * files. See <a
     * href="http://docs.aws.amazon.com/awscloudtrail/latest/userguide/create_trail_naming_policy.html">Amazon
     * S3 Bucket Naming Requirements</a>.</p>
     */
    inline CreateTrailRequest& WithS3BucketName(const Aws::String& value) { SetS3BucketName(value); return *this;}

    /**
     * <p>Specifies the name of the Amazon S3 bucket designated for publishing log
     * files. See <a
     * href="http://docs.aws.amazon.com/awscloudtrail/latest/userguide/create_trail_naming_policy.html">Amazon
     * S3 Bucket Naming Requirements</a>.</p>
     */
    inline CreateTrailRequest& WithS3BucketName(Aws::String&& value) { SetS3BucketName(value); return *this;}

    /**
     * <p>Specifies the name of the Amazon S3 bucket designated for publishing log
     * files. See <a
     * href="http://docs.aws.amazon.com/awscloudtrail/latest/userguide/create_trail_naming_policy.html">Amazon
     * S3 Bucket Naming Requirements</a>.</p>
     */
    inline CreateTrailRequest& WithS3BucketName(const char* value) { SetS3BucketName(value); return *this;}

    /**
     * <p>Specifies the Amazon S3 key prefix that comes after the name of the bucket
     * you have designated for log file delivery. For more information, see <a
     * href="http://docs.aws.amazon.com/awscloudtrail/latest/userguide/cloudtrail-find-log-files.html">Finding
     * Your CloudTrail Log Files</a>. The maximum length is 200 characters.</p>
     */
    inline const Aws::String& GetS3KeyPrefix() const{ return m_s3KeyPrefix; }

    /**
     * <p>Specifies the Amazon S3 key prefix that comes after the name of the bucket
     * you have designated for log file delivery. For more information, see <a
     * href="http://docs.aws.amazon.com/awscloudtrail/latest/userguide/cloudtrail-find-log-files.html">Finding
     * Your CloudTrail Log Files</a>. The maximum length is 200 characters.</p>
     */
    inline void SetS3KeyPrefix(const Aws::String& value) { m_s3KeyPrefixHasBeenSet = true; m_s3KeyPrefix = value; }

    /**
     * <p>Specifies the Amazon S3 key prefix that comes after the name of the bucket
     * you have designated for log file delivery. For more information, see <a
     * href="http://docs.aws.amazon.com/awscloudtrail/latest/userguide/cloudtrail-find-log-files.html">Finding
     * Your CloudTrail Log Files</a>. The maximum length is 200 characters.</p>
     */
    inline void SetS3KeyPrefix(Aws::String&& value) { m_s3KeyPrefixHasBeenSet = true; m_s3KeyPrefix = value; }

    /**
     * <p>Specifies the Amazon S3 key prefix that comes after the name of the bucket
     * you have designated for log file delivery. For more information, see <a
     * href="http://docs.aws.amazon.com/awscloudtrail/latest/userguide/cloudtrail-find-log-files.html">Finding
     * Your CloudTrail Log Files</a>. The maximum length is 200 characters.</p>
     */
    inline void SetS3KeyPrefix(const char* value) { m_s3KeyPrefixHasBeenSet = true; m_s3KeyPrefix.assign(value); }

    /**
     * <p>Specifies the Amazon S3 key prefix that comes after the name of the bucket
     * you have designated for log file delivery. For more information, see <a
     * href="http://docs.aws.amazon.com/awscloudtrail/latest/userguide/cloudtrail-find-log-files.html">Finding
     * Your CloudTrail Log Files</a>. The maximum length is 200 characters.</p>
     */
    inline CreateTrailRequest& WithS3KeyPrefix(const Aws::String& value) { SetS3KeyPrefix(value); return *this;}

    /**
     * <p>Specifies the Amazon S3 key prefix that comes after the name of the bucket
     * you have designated for log file delivery. For more information, see <a
     * href="http://docs.aws.amazon.com/awscloudtrail/latest/userguide/cloudtrail-find-log-files.html">Finding
     * Your CloudTrail Log Files</a>. The maximum length is 200 characters.</p>
     */
    inline CreateTrailRequest& WithS3KeyPrefix(Aws::String&& value) { SetS3KeyPrefix(value); return *this;}

    /**
     * <p>Specifies the Amazon S3 key prefix that comes after the name of the bucket
     * you have designated for log file delivery. For more information, see <a
     * href="http://docs.aws.amazon.com/awscloudtrail/latest/userguide/cloudtrail-find-log-files.html">Finding
     * Your CloudTrail Log Files</a>. The maximum length is 200 characters.</p>
     */
    inline CreateTrailRequest& WithS3KeyPrefix(const char* value) { SetS3KeyPrefix(value); return *this;}

    /**
     * <p>Specifies the name of the Amazon SNS topic defined for notification of log
     * file delivery. The maximum length is 256 characters.</p>
     */
    inline const Aws::String& GetSnsTopicName() const{ return m_snsTopicName; }

    /**
     * <p>Specifies the name of the Amazon SNS topic defined for notification of log
     * file delivery. The maximum length is 256 characters.</p>
     */
    inline void SetSnsTopicName(const Aws::String& value) { m_snsTopicNameHasBeenSet = true; m_snsTopicName = value; }

    /**
     * <p>Specifies the name of the Amazon SNS topic defined for notification of log
     * file delivery. The maximum length is 256 characters.</p>
     */
    inline void SetSnsTopicName(Aws::String&& value) { m_snsTopicNameHasBeenSet = true; m_snsTopicName = value; }

    /**
     * <p>Specifies the name of the Amazon SNS topic defined for notification of log
     * file delivery. The maximum length is 256 characters.</p>
     */
    inline void SetSnsTopicName(const char* value) { m_snsTopicNameHasBeenSet = true; m_snsTopicName.assign(value); }

    /**
     * <p>Specifies the name of the Amazon SNS topic defined for notification of log
     * file delivery. The maximum length is 256 characters.</p>
     */
    inline CreateTrailRequest& WithSnsTopicName(const Aws::String& value) { SetSnsTopicName(value); return *this;}

    /**
     * <p>Specifies the name of the Amazon SNS topic defined for notification of log
     * file delivery. The maximum length is 256 characters.</p>
     */
    inline CreateTrailRequest& WithSnsTopicName(Aws::String&& value) { SetSnsTopicName(value); return *this;}

    /**
     * <p>Specifies the name of the Amazon SNS topic defined for notification of log
     * file delivery. The maximum length is 256 characters.</p>
     */
    inline CreateTrailRequest& WithSnsTopicName(const char* value) { SetSnsTopicName(value); return *this;}

    /**
     * <p>Specifies whether the trail is publishing events from global services such as
     * IAM to the log files. </p>
     */
    inline bool GetIncludeGlobalServiceEvents() const{ return m_includeGlobalServiceEvents; }

    /**
     * <p>Specifies whether the trail is publishing events from global services such as
     * IAM to the log files. </p>
     */
    inline void SetIncludeGlobalServiceEvents(bool value) { m_includeGlobalServiceEventsHasBeenSet = true; m_includeGlobalServiceEvents = value; }

    /**
     * <p>Specifies whether the trail is publishing events from global services such as
     * IAM to the log files. </p>
     */
    inline CreateTrailRequest& WithIncludeGlobalServiceEvents(bool value) { SetIncludeGlobalServiceEvents(value); return *this;}

    /**
     * <p>Specifies whether the trail is created in the current region or in all
     * regions. The default is false.</p>
     */
    inline bool GetIsMultiRegionTrail() const{ return m_isMultiRegionTrail; }

    /**
     * <p>Specifies whether the trail is created in the current region or in all
     * regions. The default is false.</p>
     */
    inline void SetIsMultiRegionTrail(bool value) { m_isMultiRegionTrailHasBeenSet = true; m_isMultiRegionTrail = value; }

    /**
     * <p>Specifies whether the trail is created in the current region or in all
     * regions. The default is false.</p>
     */
    inline CreateTrailRequest& WithIsMultiRegionTrail(bool value) { SetIsMultiRegionTrail(value); return *this;}

    /**
     * <p>Specifies whether log file integrity validation is enabled. The default is
     * false.</p> <note>When you disable log file integrity validation, the chain of
     * digest files is broken after one hour. CloudTrail will not create digest files
     * for log files that were delivered during a period in which log file integrity
     * validation was disabled. For example, if you enable log file integrity
     * validation at noon on January 1, disable it at noon on January 2, and re-enable
     * it at noon on January 10, digest files will not be created for the log files
     * delivered from noon on January 2 to noon on January 10. The same applies
     * whenever you stop CloudTrail logging or delete a trail.</note>
     */
    inline bool GetEnableLogFileValidation() const{ return m_enableLogFileValidation; }

    /**
     * <p>Specifies whether log file integrity validation is enabled. The default is
     * false.</p> <note>When you disable log file integrity validation, the chain of
     * digest files is broken after one hour. CloudTrail will not create digest files
     * for log files that were delivered during a period in which log file integrity
     * validation was disabled. For example, if you enable log file integrity
     * validation at noon on January 1, disable it at noon on January 2, and re-enable
     * it at noon on January 10, digest files will not be created for the log files
     * delivered from noon on January 2 to noon on January 10. The same applies
     * whenever you stop CloudTrail logging or delete a trail.</note>
     */
    inline void SetEnableLogFileValidation(bool value) { m_enableLogFileValidationHasBeenSet = true; m_enableLogFileValidation = value; }

    /**
     * <p>Specifies whether log file integrity validation is enabled. The default is
     * false.</p> <note>When you disable log file integrity validation, the chain of
     * digest files is broken after one hour. CloudTrail will not create digest files
     * for log files that were delivered during a period in which log file integrity
     * validation was disabled. For example, if you enable log file integrity
     * validation at noon on January 1, disable it at noon on January 2, and re-enable
     * it at noon on January 10, digest files will not be created for the log files
     * delivered from noon on January 2 to noon on January 10. The same applies
     * whenever you stop CloudTrail logging or delete a trail.</note>
     */
    inline CreateTrailRequest& WithEnableLogFileValidation(bool value) { SetEnableLogFileValidation(value); return *this;}

    /**
     * <p>Specifies a log group name using an Amazon Resource Name (ARN), a unique
     * identifier that represents the log group to which CloudTrail logs will be
     * delivered. Not required unless you specify CloudWatchLogsRoleArn.</p>
     */
    inline const Aws::String& GetCloudWatchLogsLogGroupArn() const{ return m_cloudWatchLogsLogGroupArn; }

    /**
     * <p>Specifies a log group name using an Amazon Resource Name (ARN), a unique
     * identifier that represents the log group to which CloudTrail logs will be
     * delivered. Not required unless you specify CloudWatchLogsRoleArn.</p>
     */
    inline void SetCloudWatchLogsLogGroupArn(const Aws::String& value) { m_cloudWatchLogsLogGroupArnHasBeenSet = true; m_cloudWatchLogsLogGroupArn = value; }

    /**
     * <p>Specifies a log group name using an Amazon Resource Name (ARN), a unique
     * identifier that represents the log group to which CloudTrail logs will be
     * delivered. Not required unless you specify CloudWatchLogsRoleArn.</p>
     */
    inline void SetCloudWatchLogsLogGroupArn(Aws::String&& value) { m_cloudWatchLogsLogGroupArnHasBeenSet = true; m_cloudWatchLogsLogGroupArn = value; }

    /**
     * <p>Specifies a log group name using an Amazon Resource Name (ARN), a unique
     * identifier that represents the log group to which CloudTrail logs will be
     * delivered. Not required unless you specify CloudWatchLogsRoleArn.</p>
     */
    inline void SetCloudWatchLogsLogGroupArn(const char* value) { m_cloudWatchLogsLogGroupArnHasBeenSet = true; m_cloudWatchLogsLogGroupArn.assign(value); }

    /**
     * <p>Specifies a log group name using an Amazon Resource Name (ARN), a unique
     * identifier that represents the log group to which CloudTrail logs will be
     * delivered. Not required unless you specify CloudWatchLogsRoleArn.</p>
     */
    inline CreateTrailRequest& WithCloudWatchLogsLogGroupArn(const Aws::String& value) { SetCloudWatchLogsLogGroupArn(value); return *this;}

    /**
     * <p>Specifies a log group name using an Amazon Resource Name (ARN), a unique
     * identifier that represents the log group to which CloudTrail logs will be
     * delivered. Not required unless you specify CloudWatchLogsRoleArn.</p>
     */
    inline CreateTrailRequest& WithCloudWatchLogsLogGroupArn(Aws::String&& value) { SetCloudWatchLogsLogGroupArn(value); return *this;}

    /**
     * <p>Specifies a log group name using an Amazon Resource Name (ARN), a unique
     * identifier that represents the log group to which CloudTrail logs will be
     * delivered. Not required unless you specify CloudWatchLogsRoleArn.</p>
     */
    inline CreateTrailRequest& WithCloudWatchLogsLogGroupArn(const char* value) { SetCloudWatchLogsLogGroupArn(value); return *this;}

    /**
     * <p>Specifies the role for the CloudWatch Logs endpoint to assume to write to a
     * user's log group.</p>
     */
    inline const Aws::String& GetCloudWatchLogsRoleArn() const{ return m_cloudWatchLogsRoleArn; }

    /**
     * <p>Specifies the role for the CloudWatch Logs endpoint to assume to write to a
     * user's log group.</p>
     */
    inline void SetCloudWatchLogsRoleArn(const Aws::String& value) { m_cloudWatchLogsRoleArnHasBeenSet = true; m_cloudWatchLogsRoleArn = value; }

    /**
     * <p>Specifies the role for the CloudWatch Logs endpoint to assume to write to a
     * user's log group.</p>
     */
    inline void SetCloudWatchLogsRoleArn(Aws::String&& value) { m_cloudWatchLogsRoleArnHasBeenSet = true; m_cloudWatchLogsRoleArn = value; }

    /**
     * <p>Specifies the role for the CloudWatch Logs endpoint to assume to write to a
     * user's log group.</p>
     */
    inline void SetCloudWatchLogsRoleArn(const char* value) { m_cloudWatchLogsRoleArnHasBeenSet = true; m_cloudWatchLogsRoleArn.assign(value); }

    /**
     * <p>Specifies the role for the CloudWatch Logs endpoint to assume to write to a
     * user's log group.</p>
     */
    inline CreateTrailRequest& WithCloudWatchLogsRoleArn(const Aws::String& value) { SetCloudWatchLogsRoleArn(value); return *this;}

    /**
     * <p>Specifies the role for the CloudWatch Logs endpoint to assume to write to a
     * user's log group.</p>
     */
    inline CreateTrailRequest& WithCloudWatchLogsRoleArn(Aws::String&& value) { SetCloudWatchLogsRoleArn(value); return *this;}

    /**
     * <p>Specifies the role for the CloudWatch Logs endpoint to assume to write to a
     * user's log group.</p>
     */
    inline CreateTrailRequest& WithCloudWatchLogsRoleArn(const char* value) { SetCloudWatchLogsRoleArn(value); return *this;}

    /**
     * <p>Specifies the KMS key ID to use to encrypt the logs delivered by CloudTrail.
     * The value can be a an alias name prefixed by "alias/", a fully specified ARN to
     * an alias, a fully specified ARN to a key, or a globally unique identifier.</p>
     * <p>Examples:</p> <ul> <li>alias/MyAliasName</li>
     * <li>arn:aws:kms:us-east-1:123456789012:alias/MyAliasName</li>
     * <li>arn:aws:kms:us-east-1:123456789012:key/12345678-1234-1234-1234-123456789012</li>
     * <li>12345678-1234-1234-1234-123456789012</li> </ul>
     */
    inline const Aws::String& GetKmsKeyId() const{ return m_kmsKeyId; }

    /**
     * <p>Specifies the KMS key ID to use to encrypt the logs delivered by CloudTrail.
     * The value can be a an alias name prefixed by "alias/", a fully specified ARN to
     * an alias, a fully specified ARN to a key, or a globally unique identifier.</p>
     * <p>Examples:</p> <ul> <li>alias/MyAliasName</li>
     * <li>arn:aws:kms:us-east-1:123456789012:alias/MyAliasName</li>
     * <li>arn:aws:kms:us-east-1:123456789012:key/12345678-1234-1234-1234-123456789012</li>
     * <li>12345678-1234-1234-1234-123456789012</li> </ul>
     */
    inline void SetKmsKeyId(const Aws::String& value) { m_kmsKeyIdHasBeenSet = true; m_kmsKeyId = value; }

    /**
     * <p>Specifies the KMS key ID to use to encrypt the logs delivered by CloudTrail.
     * The value can be a an alias name prefixed by "alias/", a fully specified ARN to
     * an alias, a fully specified ARN to a key, or a globally unique identifier.</p>
     * <p>Examples:</p> <ul> <li>alias/MyAliasName</li>
     * <li>arn:aws:kms:us-east-1:123456789012:alias/MyAliasName</li>
     * <li>arn:aws:kms:us-east-1:123456789012:key/12345678-1234-1234-1234-123456789012</li>
     * <li>12345678-1234-1234-1234-123456789012</li> </ul>
     */
    inline void SetKmsKeyId(Aws::String&& value) { m_kmsKeyIdHasBeenSet = true; m_kmsKeyId = value; }

    /**
     * <p>Specifies the KMS key ID to use to encrypt the logs delivered by CloudTrail.
     * The value can be a an alias name prefixed by "alias/", a fully specified ARN to
     * an alias, a fully specified ARN to a key, or a globally unique identifier.</p>
     * <p>Examples:</p> <ul> <li>alias/MyAliasName</li>
     * <li>arn:aws:kms:us-east-1:123456789012:alias/MyAliasName</li>
     * <li>arn:aws:kms:us-east-1:123456789012:key/12345678-1234-1234-1234-123456789012</li>
     * <li>12345678-1234-1234-1234-123456789012</li> </ul>
     */
    inline void SetKmsKeyId(const char* value) { m_kmsKeyIdHasBeenSet = true; m_kmsKeyId.assign(value); }

    /**
     * <p>Specifies the KMS key ID to use to encrypt the logs delivered by CloudTrail.
     * The value can be a an alias name prefixed by "alias/", a fully specified ARN to
     * an alias, a fully specified ARN to a key, or a globally unique identifier.</p>
     * <p>Examples:</p> <ul> <li>alias/MyAliasName</li>
     * <li>arn:aws:kms:us-east-1:123456789012:alias/MyAliasName</li>
     * <li>arn:aws:kms:us-east-1:123456789012:key/12345678-1234-1234-1234-123456789012</li>
     * <li>12345678-1234-1234-1234-123456789012</li> </ul>
     */
    inline CreateTrailRequest& WithKmsKeyId(const Aws::String& value) { SetKmsKeyId(value); return *this;}

    /**
     * <p>Specifies the KMS key ID to use to encrypt the logs delivered by CloudTrail.
     * The value can be a an alias name prefixed by "alias/", a fully specified ARN to
     * an alias, a fully specified ARN to a key, or a globally unique identifier.</p>
     * <p>Examples:</p> <ul> <li>alias/MyAliasName</li>
     * <li>arn:aws:kms:us-east-1:123456789012:alias/MyAliasName</li>
     * <li>arn:aws:kms:us-east-1:123456789012:key/12345678-1234-1234-1234-123456789012</li>
     * <li>12345678-1234-1234-1234-123456789012</li> </ul>
     */
    inline CreateTrailRequest& WithKmsKeyId(Aws::String&& value) { SetKmsKeyId(value); return *this;}

    /**
     * <p>Specifies the KMS key ID to use to encrypt the logs delivered by CloudTrail.
     * The value can be a an alias name prefixed by "alias/", a fully specified ARN to
     * an alias, a fully specified ARN to a key, or a globally unique identifier.</p>
     * <p>Examples:</p> <ul> <li>alias/MyAliasName</li>
     * <li>arn:aws:kms:us-east-1:123456789012:alias/MyAliasName</li>
     * <li>arn:aws:kms:us-east-1:123456789012:key/12345678-1234-1234-1234-123456789012</li>
     * <li>12345678-1234-1234-1234-123456789012</li> </ul>
     */
    inline CreateTrailRequest& WithKmsKeyId(const char* value) { SetKmsKeyId(value); return *this;}

  private:
    Aws::String m_name;
    bool m_nameHasBeenSet;
    Aws::String m_s3BucketName;
    bool m_s3BucketNameHasBeenSet;
    Aws::String m_s3KeyPrefix;
    bool m_s3KeyPrefixHasBeenSet;
    Aws::String m_snsTopicName;
    bool m_snsTopicNameHasBeenSet;
    bool m_includeGlobalServiceEvents;
    bool m_includeGlobalServiceEventsHasBeenSet;
    bool m_isMultiRegionTrail;
    bool m_isMultiRegionTrailHasBeenSet;
    bool m_enableLogFileValidation;
    bool m_enableLogFileValidationHasBeenSet;
    Aws::String m_cloudWatchLogsLogGroupArn;
    bool m_cloudWatchLogsLogGroupArnHasBeenSet;
    Aws::String m_cloudWatchLogsRoleArn;
    bool m_cloudWatchLogsRoleArnHasBeenSet;
    Aws::String m_kmsKeyId;
    bool m_kmsKeyIdHasBeenSet;
  };

} // namespace Model
} // namespace CloudTrail
} // namespace Aws
