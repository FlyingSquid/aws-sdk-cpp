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
#include <aws/devicefarm/model/DeviceAttribute.h>
#include <aws/core/utils/HashingUtils.h>
#include <aws/core/Globals.h>

using namespace Aws::Utils;

static const int ARN_HASH = HashingUtils::HashString("ARN");
static const int PLATFORM_HASH = HashingUtils::HashString("PLATFORM");
static const int FORM_FACTOR_HASH = HashingUtils::HashString("FORM_FACTOR");
static const int MANUFACTURER_HASH = HashingUtils::HashString("MANUFACTURER");

namespace Aws
{
  namespace DeviceFarm
  {
    namespace Model
    {
      namespace DeviceAttributeMapper
      {


        DeviceAttribute GetDeviceAttributeForName(const Aws::String& name)
        {
          int hashCode = HashingUtils::HashString(name.c_str());
          if (hashCode == ARN_HASH)
          {
            return DeviceAttribute::ARN;
          }
          else if (hashCode == PLATFORM_HASH)
          {
            return DeviceAttribute::PLATFORM;
          }
          else if (hashCode == FORM_FACTOR_HASH)
          {
            return DeviceAttribute::FORM_FACTOR;
          }
          else if (hashCode == MANUFACTURER_HASH)
          {
            return DeviceAttribute::MANUFACTURER;
          }
          EnumParseOverflowContainer* overflowContainer = g_enumOverflow.load();
          if(overflowContainer)
          {
            overflowContainer->StoreOverflow(hashCode, name);
            return static_cast<DeviceAttribute>(hashCode);
          }

          return DeviceAttribute::NOT_SET;
        }

        Aws::String GetNameForDeviceAttribute(DeviceAttribute enumValue)
        {
          switch(enumValue)
          {
          case DeviceAttribute::ARN:
            return "ARN";
          case DeviceAttribute::PLATFORM:
            return "PLATFORM";
          case DeviceAttribute::FORM_FACTOR:
            return "FORM_FACTOR";
          case DeviceAttribute::MANUFACTURER:
            return "MANUFACTURER";
          default:
            EnumParseOverflowContainer* overflowContainer = g_enumOverflow.load();
            if(overflowContainer)
            {
              return overflowContainer->RetrieveOverflow(static_cast<int>(enumValue));
            }

            return "";
          }
        }

      } // namespace DeviceAttributeMapper
    } // namespace Model
  } // namespace DeviceFarm
} // namespace Aws
