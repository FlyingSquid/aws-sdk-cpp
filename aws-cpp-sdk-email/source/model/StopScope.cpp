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
#include <aws/email/model/StopScope.h>
#include <aws/core/utils/HashingUtils.h>
#include <aws/core/Globals.h>

using namespace Aws::Utils;

static const int RuleSet_HASH = HashingUtils::HashString("RuleSet");

namespace Aws
{
  namespace SES
  {
    namespace Model
    {
      namespace StopScopeMapper
      {


        StopScope GetStopScopeForName(const Aws::String& name)
        {
          int hashCode = HashingUtils::HashString(name.c_str());
          if (hashCode == RuleSet_HASH)
          {
            return StopScope::RuleSet;
          }
          EnumParseOverflowContainer* overflowContainer = g_enumOverflow.load();
          if(overflowContainer)
          {
            overflowContainer->StoreOverflow(hashCode, name);
            return static_cast<StopScope>(hashCode);
          }

          return StopScope::NOT_SET;
        }

        Aws::String GetNameForStopScope(StopScope enumValue)
        {
          switch(enumValue)
          {
          case StopScope::RuleSet:
            return "RuleSet";
          default:
            EnumParseOverflowContainer* overflowContainer = g_enumOverflow.load();
            if(overflowContainer)
            {
              return overflowContainer->RetrieveOverflow(static_cast<int>(enumValue));
            }

            return "";
          }
        }

      } // namespace StopScopeMapper
    } // namespace Model
  } // namespace SES
} // namespace Aws
