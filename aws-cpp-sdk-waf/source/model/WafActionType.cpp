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
#include <aws/waf/model/WafActionType.h>
#include <aws/core/utils/HashingUtils.h>
#include <aws/core/Globals.h>

using namespace Aws::Utils;

static const int BLOCK_HASH = HashingUtils::HashString("BLOCK");
static const int ALLOW_HASH = HashingUtils::HashString("ALLOW");
static const int COUNT_HASH = HashingUtils::HashString("COUNT");

namespace Aws
{
  namespace WAF
  {
    namespace Model
    {
      namespace WafActionTypeMapper
      {


        WafActionType GetWafActionTypeForName(const Aws::String& name)
        {
          int hashCode = HashingUtils::HashString(name.c_str());
          if (hashCode == BLOCK_HASH)
          {
            return WafActionType::BLOCK;
          }
          else if (hashCode == ALLOW_HASH)
          {
            return WafActionType::ALLOW;
          }
          else if (hashCode == COUNT_HASH)
          {
            return WafActionType::COUNT;
          }
          EnumParseOverflowContainer* overflowContainer = g_enumOverflow.load();
          if(overflowContainer)
          {
            overflowContainer->StoreOverflow(hashCode, name);
            return static_cast<WafActionType>(hashCode);
          }

          return WafActionType::NOT_SET;
        }

        Aws::String GetNameForWafActionType(WafActionType enumValue)
        {
          switch(enumValue)
          {
          case WafActionType::BLOCK:
            return "BLOCK";
          case WafActionType::ALLOW:
            return "ALLOW";
          case WafActionType::COUNT:
            return "COUNT";
          default:
            EnumParseOverflowContainer* overflowContainer = g_enumOverflow.load();
            if(overflowContainer)
            {
              return overflowContainer->RetrieveOverflow(static_cast<int>(enumValue));
            }

            return "";
          }
        }

      } // namespace WafActionTypeMapper
    } // namespace Model
  } // namespace WAF
} // namespace Aws
