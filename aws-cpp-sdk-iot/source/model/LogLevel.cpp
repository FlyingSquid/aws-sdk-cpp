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
#include <aws/iot/model/LogLevel.h>
#include <aws/core/utils/HashingUtils.h>
#include <aws/core/Globals.h>

using namespace Aws::Utils;

static const int DEBUG_HASH = HashingUtils::HashString("DEBUG");
static const int INFO_HASH = HashingUtils::HashString("INFO");
static const int ERROR__HASH = HashingUtils::HashString("ERROR");
static const int WARN_HASH = HashingUtils::HashString("WARN");
static const int DISABLED_HASH = HashingUtils::HashString("DISABLED");

namespace Aws
{
  namespace IoT
  {
    namespace Model
    {
      namespace LogLevelMapper
      {


        LogLevel GetLogLevelForName(const Aws::String& name)
        {
          int hashCode = HashingUtils::HashString(name.c_str());
          if (hashCode == DEBUG_HASH)
          {
            return LogLevel::DEBUG;
          }
          else if (hashCode == INFO_HASH)
          {
            return LogLevel::INFO;
          }
          else if (hashCode == ERROR__HASH)
          {
            return LogLevel::ERROR_;
          }
          else if (hashCode == WARN_HASH)
          {
            return LogLevel::WARN;
          }
          else if (hashCode == DISABLED_HASH)
          {
            return LogLevel::DISABLED;
          }
          EnumParseOverflowContainer* overflowContainer = g_enumOverflow.load();
          if(overflowContainer)
          {
            overflowContainer->StoreOverflow(hashCode, name);
            return static_cast<LogLevel>(hashCode);
          }

          return LogLevel::NOT_SET;
        }

        Aws::String GetNameForLogLevel(LogLevel enumValue)
        {
          switch(enumValue)
          {
          case LogLevel::DEBUG:
            return "DEBUG";
          case LogLevel::INFO:
            return "INFO";
          case LogLevel::ERROR_:
            return "ERROR";
          case LogLevel::WARN:
            return "WARN";
          case LogLevel::DISABLED:
            return "DISABLED";
          default:
            EnumParseOverflowContainer* overflowContainer = g_enumOverflow.load();
            if(overflowContainer)
            {
              return overflowContainer->RetrieveOverflow(static_cast<int>(enumValue));
            }

            return "";
          }
        }

      } // namespace LogLevelMapper
    } // namespace Model
  } // namespace IoT
} // namespace Aws
