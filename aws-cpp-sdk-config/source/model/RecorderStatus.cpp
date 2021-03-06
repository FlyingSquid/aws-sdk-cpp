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
#include <aws/config/model/RecorderStatus.h>
#include <aws/core/utils/HashingUtils.h>
#include <aws/core/Globals.h>

using namespace Aws::Utils;

static const int Pending_HASH = HashingUtils::HashString("Pending");
static const int Success_HASH = HashingUtils::HashString("Success");
static const int Failure_HASH = HashingUtils::HashString("Failure");

namespace Aws
{
  namespace ConfigService
  {
    namespace Model
    {
      namespace RecorderStatusMapper
      {


        RecorderStatus GetRecorderStatusForName(const Aws::String& name)
        {
          int hashCode = HashingUtils::HashString(name.c_str());
          if (hashCode == Pending_HASH)
          {
            return RecorderStatus::Pending;
          }
          else if (hashCode == Success_HASH)
          {
            return RecorderStatus::Success;
          }
          else if (hashCode == Failure_HASH)
          {
            return RecorderStatus::Failure;
          }
          EnumParseOverflowContainer* overflowContainer = g_enumOverflow.load();
          if(overflowContainer)
          {
            overflowContainer->StoreOverflow(hashCode, name);
            return static_cast<RecorderStatus>(hashCode);
          }

          return RecorderStatus::NOT_SET;
        }

        Aws::String GetNameForRecorderStatus(RecorderStatus enumValue)
        {
          switch(enumValue)
          {
          case RecorderStatus::Pending:
            return "Pending";
          case RecorderStatus::Success:
            return "Success";
          case RecorderStatus::Failure:
            return "Failure";
          default:
            EnumParseOverflowContainer* overflowContainer = g_enumOverflow.load();
            if(overflowContainer)
            {
              return overflowContainer->RetrieveOverflow(static_cast<int>(enumValue));
            }

            return "";
          }
        }

      } // namespace RecorderStatusMapper
    } // namespace Model
  } // namespace ConfigService
} // namespace Aws
