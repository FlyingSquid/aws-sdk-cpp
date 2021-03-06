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
#include <aws/ssm/model/InstanceInformationFilterKey.h>
#include <aws/core/utils/HashingUtils.h>
#include <aws/core/Globals.h>

using namespace Aws::Utils;

static const int InstanceIds_HASH = HashingUtils::HashString("InstanceIds");
static const int AgentVersion_HASH = HashingUtils::HashString("AgentVersion");
static const int PingStatus_HASH = HashingUtils::HashString("PingStatus");
static const int PlatformTypes_HASH = HashingUtils::HashString("PlatformTypes");

namespace Aws
{
  namespace SSM
  {
    namespace Model
    {
      namespace InstanceInformationFilterKeyMapper
      {


        InstanceInformationFilterKey GetInstanceInformationFilterKeyForName(const Aws::String& name)
        {
          int hashCode = HashingUtils::HashString(name.c_str());
          if (hashCode == InstanceIds_HASH)
          {
            return InstanceInformationFilterKey::InstanceIds;
          }
          else if (hashCode == AgentVersion_HASH)
          {
            return InstanceInformationFilterKey::AgentVersion;
          }
          else if (hashCode == PingStatus_HASH)
          {
            return InstanceInformationFilterKey::PingStatus;
          }
          else if (hashCode == PlatformTypes_HASH)
          {
            return InstanceInformationFilterKey::PlatformTypes;
          }
          EnumParseOverflowContainer* overflowContainer = g_enumOverflow.load();
          if(overflowContainer)
          {
            overflowContainer->StoreOverflow(hashCode, name);
            return static_cast<InstanceInformationFilterKey>(hashCode);
          }

          return InstanceInformationFilterKey::NOT_SET;
        }

        Aws::String GetNameForInstanceInformationFilterKey(InstanceInformationFilterKey enumValue)
        {
          switch(enumValue)
          {
          case InstanceInformationFilterKey::InstanceIds:
            return "InstanceIds";
          case InstanceInformationFilterKey::AgentVersion:
            return "AgentVersion";
          case InstanceInformationFilterKey::PingStatus:
            return "PingStatus";
          case InstanceInformationFilterKey::PlatformTypes:
            return "PlatformTypes";
          default:
            EnumParseOverflowContainer* overflowContainer = g_enumOverflow.load();
            if(overflowContainer)
            {
              return overflowContainer->RetrieveOverflow(static_cast<int>(enumValue));
            }

            return "";
          }
        }

      } // namespace InstanceInformationFilterKeyMapper
    } // namespace Model
  } // namespace SSM
} // namespace Aws
