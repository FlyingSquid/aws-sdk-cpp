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
#include <aws/sqs/model/AddPermissionRequest.h>
#include <aws/core/utils/StringUtils.h>
#include <aws/core/utils/memory/stl/AWSStringStream.h>

using namespace Aws::SQS::Model;
using namespace Aws::Utils;

AddPermissionRequest::AddPermissionRequest() : 
    m_queueUrlHasBeenSet(false),
    m_labelHasBeenSet(false),
    m_aWSAccountIdsHasBeenSet(false),
    m_actionsHasBeenSet(false)
{
}

Aws::String AddPermissionRequest::SerializePayload() const
{
  Aws::StringStream ss;
  ss << "Action=AddPermission&";
  if(m_queueUrlHasBeenSet)
  {
    ss << "QueueUrl=" << StringUtils::URLEncode(m_queueUrl.c_str()) << "&";
  }
  if(m_labelHasBeenSet)
  {
    ss << "Label=" << StringUtils::URLEncode(m_label.c_str()) << "&";
  }
  if(m_aWSAccountIdsHasBeenSet)
  {
    unsigned aWSAccountIdsCount = 1;
    for(auto& item : m_aWSAccountIds)
    {
      ss << "AWSAccountId." << aWSAccountIdsCount << "="
          << StringUtils::URLEncode(item.c_str()) << "&";
      aWSAccountIdsCount++;
    }
  }
  if(m_actionsHasBeenSet)
  {
    unsigned actionsCount = 1;
    for(auto& item : m_actions)
    {
      ss << "ActionName." << actionsCount << "="
          << StringUtils::URLEncode(item.c_str()) << "&";
      actionsCount++;
    }
  }
  ss << "Version=2012-11-05";
  return ss.str();
}

