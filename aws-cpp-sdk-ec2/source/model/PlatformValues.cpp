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
#include <aws/ec2/model/PlatformValues.h>
#include <aws/core/utils/HashingUtils.h>
#include <aws/core/Globals.h>

using namespace Aws::Utils;

static const int Windows_HASH = HashingUtils::HashString("Windows");

namespace Aws
{
  namespace EC2
  {
    namespace Model
    {
      namespace PlatformValuesMapper
      {


        PlatformValues GetPlatformValuesForName(const Aws::String& name)
        {
          int hashCode = HashingUtils::HashString(name.c_str());
          if (hashCode == Windows_HASH)
          {
            return PlatformValues::Windows;
          }
          EnumParseOverflowContainer* overflowContainer = g_enumOverflow.load();
          if(overflowContainer)
          {
            overflowContainer->StoreOverflow(hashCode, name);
            return static_cast<PlatformValues>(hashCode);
          }

          return PlatformValues::NOT_SET;
        }

        Aws::String GetNameForPlatformValues(PlatformValues enumValue)
        {
          switch(enumValue)
          {
          case PlatformValues::Windows:
            return "Windows";
          default:
            EnumParseOverflowContainer* overflowContainer = g_enumOverflow.load();
            if(overflowContainer)
            {
              return overflowContainer->RetrieveOverflow(static_cast<int>(enumValue));
            }

            return "";
          }
        }

      } // namespace PlatformValuesMapper
    } // namespace Model
  } // namespace EC2
} // namespace Aws
