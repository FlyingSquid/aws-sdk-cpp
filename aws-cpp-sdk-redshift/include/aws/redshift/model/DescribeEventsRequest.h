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
#include <aws/redshift/Redshift_EXPORTS.h>
#include <aws/redshift/RedshiftRequest.h>
#include <aws/core/utils/memory/stl/AWSString.h>
#include <aws/redshift/model/SourceType.h>

namespace Aws
{
namespace Redshift
{
namespace Model
{

  /**
   * <p> </p>
   */
  class AWS_REDSHIFT_API DescribeEventsRequest : public RedshiftRequest
  {
  public:
    DescribeEventsRequest();
    Aws::String SerializePayload() const override;


    /**
     * <p> The identifier of the event source for which events will be returned. If
     * this parameter is not specified, then all sources are included in the response.
     * </p> <p>Constraints:</p> <p>If <i>SourceIdentifier</i> is supplied,
     * <i>SourceType</i> must also be provided.</p> <ul> <li>Specify a cluster
     * identifier when <i>SourceType</i> is <code>cluster</code>.</li> <li>Specify a
     * cluster security group name when <i>SourceType</i> is
     * <code>cluster-security-group</code>.</li> <li>Specify a cluster parameter group
     * name when <i>SourceType</i> is <code>cluster-parameter-group</code>.</li>
     * <li>Specify a cluster snapshot identifier when <i>SourceType</i> is
     * <code>cluster-snapshot</code>.</li> </ul>
     */
    inline const Aws::String& GetSourceIdentifier() const{ return m_sourceIdentifier; }

    /**
     * <p> The identifier of the event source for which events will be returned. If
     * this parameter is not specified, then all sources are included in the response.
     * </p> <p>Constraints:</p> <p>If <i>SourceIdentifier</i> is supplied,
     * <i>SourceType</i> must also be provided.</p> <ul> <li>Specify a cluster
     * identifier when <i>SourceType</i> is <code>cluster</code>.</li> <li>Specify a
     * cluster security group name when <i>SourceType</i> is
     * <code>cluster-security-group</code>.</li> <li>Specify a cluster parameter group
     * name when <i>SourceType</i> is <code>cluster-parameter-group</code>.</li>
     * <li>Specify a cluster snapshot identifier when <i>SourceType</i> is
     * <code>cluster-snapshot</code>.</li> </ul>
     */
    inline void SetSourceIdentifier(const Aws::String& value) { m_sourceIdentifierHasBeenSet = true; m_sourceIdentifier = value; }

    /**
     * <p> The identifier of the event source for which events will be returned. If
     * this parameter is not specified, then all sources are included in the response.
     * </p> <p>Constraints:</p> <p>If <i>SourceIdentifier</i> is supplied,
     * <i>SourceType</i> must also be provided.</p> <ul> <li>Specify a cluster
     * identifier when <i>SourceType</i> is <code>cluster</code>.</li> <li>Specify a
     * cluster security group name when <i>SourceType</i> is
     * <code>cluster-security-group</code>.</li> <li>Specify a cluster parameter group
     * name when <i>SourceType</i> is <code>cluster-parameter-group</code>.</li>
     * <li>Specify a cluster snapshot identifier when <i>SourceType</i> is
     * <code>cluster-snapshot</code>.</li> </ul>
     */
    inline void SetSourceIdentifier(Aws::String&& value) { m_sourceIdentifierHasBeenSet = true; m_sourceIdentifier = value; }

    /**
     * <p> The identifier of the event source for which events will be returned. If
     * this parameter is not specified, then all sources are included in the response.
     * </p> <p>Constraints:</p> <p>If <i>SourceIdentifier</i> is supplied,
     * <i>SourceType</i> must also be provided.</p> <ul> <li>Specify a cluster
     * identifier when <i>SourceType</i> is <code>cluster</code>.</li> <li>Specify a
     * cluster security group name when <i>SourceType</i> is
     * <code>cluster-security-group</code>.</li> <li>Specify a cluster parameter group
     * name when <i>SourceType</i> is <code>cluster-parameter-group</code>.</li>
     * <li>Specify a cluster snapshot identifier when <i>SourceType</i> is
     * <code>cluster-snapshot</code>.</li> </ul>
     */
    inline void SetSourceIdentifier(const char* value) { m_sourceIdentifierHasBeenSet = true; m_sourceIdentifier.assign(value); }

    /**
     * <p> The identifier of the event source for which events will be returned. If
     * this parameter is not specified, then all sources are included in the response.
     * </p> <p>Constraints:</p> <p>If <i>SourceIdentifier</i> is supplied,
     * <i>SourceType</i> must also be provided.</p> <ul> <li>Specify a cluster
     * identifier when <i>SourceType</i> is <code>cluster</code>.</li> <li>Specify a
     * cluster security group name when <i>SourceType</i> is
     * <code>cluster-security-group</code>.</li> <li>Specify a cluster parameter group
     * name when <i>SourceType</i> is <code>cluster-parameter-group</code>.</li>
     * <li>Specify a cluster snapshot identifier when <i>SourceType</i> is
     * <code>cluster-snapshot</code>.</li> </ul>
     */
    inline DescribeEventsRequest& WithSourceIdentifier(const Aws::String& value) { SetSourceIdentifier(value); return *this;}

    /**
     * <p> The identifier of the event source for which events will be returned. If
     * this parameter is not specified, then all sources are included in the response.
     * </p> <p>Constraints:</p> <p>If <i>SourceIdentifier</i> is supplied,
     * <i>SourceType</i> must also be provided.</p> <ul> <li>Specify a cluster
     * identifier when <i>SourceType</i> is <code>cluster</code>.</li> <li>Specify a
     * cluster security group name when <i>SourceType</i> is
     * <code>cluster-security-group</code>.</li> <li>Specify a cluster parameter group
     * name when <i>SourceType</i> is <code>cluster-parameter-group</code>.</li>
     * <li>Specify a cluster snapshot identifier when <i>SourceType</i> is
     * <code>cluster-snapshot</code>.</li> </ul>
     */
    inline DescribeEventsRequest& WithSourceIdentifier(Aws::String&& value) { SetSourceIdentifier(value); return *this;}

    /**
     * <p> The identifier of the event source for which events will be returned. If
     * this parameter is not specified, then all sources are included in the response.
     * </p> <p>Constraints:</p> <p>If <i>SourceIdentifier</i> is supplied,
     * <i>SourceType</i> must also be provided.</p> <ul> <li>Specify a cluster
     * identifier when <i>SourceType</i> is <code>cluster</code>.</li> <li>Specify a
     * cluster security group name when <i>SourceType</i> is
     * <code>cluster-security-group</code>.</li> <li>Specify a cluster parameter group
     * name when <i>SourceType</i> is <code>cluster-parameter-group</code>.</li>
     * <li>Specify a cluster snapshot identifier when <i>SourceType</i> is
     * <code>cluster-snapshot</code>.</li> </ul>
     */
    inline DescribeEventsRequest& WithSourceIdentifier(const char* value) { SetSourceIdentifier(value); return *this;}

    /**
     * <p> The event source to retrieve events for. If no value is specified, all
     * events are returned. </p> <p>Constraints:</p> <p>If <i>SourceType</i> is
     * supplied, <i>SourceIdentifier</i> must also be provided.</p> <ul> <li>Specify
     * <code>cluster</code> when <i>SourceIdentifier</i> is a cluster identifier.</li>
     * <li>Specify <code>cluster-security-group</code> when <i>SourceIdentifier</i> is
     * a cluster security group name.</li> <li>Specify
     * <code>cluster-parameter-group</code> when <i>SourceIdentifier</i> is a cluster
     * parameter group name.</li> <li>Specify <code>cluster-snapshot</code> when
     * <i>SourceIdentifier</i> is a cluster snapshot identifier.</li> </ul>
     */
    inline const SourceType& GetSourceType() const{ return m_sourceType; }

    /**
     * <p> The event source to retrieve events for. If no value is specified, all
     * events are returned. </p> <p>Constraints:</p> <p>If <i>SourceType</i> is
     * supplied, <i>SourceIdentifier</i> must also be provided.</p> <ul> <li>Specify
     * <code>cluster</code> when <i>SourceIdentifier</i> is a cluster identifier.</li>
     * <li>Specify <code>cluster-security-group</code> when <i>SourceIdentifier</i> is
     * a cluster security group name.</li> <li>Specify
     * <code>cluster-parameter-group</code> when <i>SourceIdentifier</i> is a cluster
     * parameter group name.</li> <li>Specify <code>cluster-snapshot</code> when
     * <i>SourceIdentifier</i> is a cluster snapshot identifier.</li> </ul>
     */
    inline void SetSourceType(const SourceType& value) { m_sourceTypeHasBeenSet = true; m_sourceType = value; }

    /**
     * <p> The event source to retrieve events for. If no value is specified, all
     * events are returned. </p> <p>Constraints:</p> <p>If <i>SourceType</i> is
     * supplied, <i>SourceIdentifier</i> must also be provided.</p> <ul> <li>Specify
     * <code>cluster</code> when <i>SourceIdentifier</i> is a cluster identifier.</li>
     * <li>Specify <code>cluster-security-group</code> when <i>SourceIdentifier</i> is
     * a cluster security group name.</li> <li>Specify
     * <code>cluster-parameter-group</code> when <i>SourceIdentifier</i> is a cluster
     * parameter group name.</li> <li>Specify <code>cluster-snapshot</code> when
     * <i>SourceIdentifier</i> is a cluster snapshot identifier.</li> </ul>
     */
    inline void SetSourceType(SourceType&& value) { m_sourceTypeHasBeenSet = true; m_sourceType = value; }

    /**
     * <p> The event source to retrieve events for. If no value is specified, all
     * events are returned. </p> <p>Constraints:</p> <p>If <i>SourceType</i> is
     * supplied, <i>SourceIdentifier</i> must also be provided.</p> <ul> <li>Specify
     * <code>cluster</code> when <i>SourceIdentifier</i> is a cluster identifier.</li>
     * <li>Specify <code>cluster-security-group</code> when <i>SourceIdentifier</i> is
     * a cluster security group name.</li> <li>Specify
     * <code>cluster-parameter-group</code> when <i>SourceIdentifier</i> is a cluster
     * parameter group name.</li> <li>Specify <code>cluster-snapshot</code> when
     * <i>SourceIdentifier</i> is a cluster snapshot identifier.</li> </ul>
     */
    inline DescribeEventsRequest& WithSourceType(const SourceType& value) { SetSourceType(value); return *this;}

    /**
     * <p> The event source to retrieve events for. If no value is specified, all
     * events are returned. </p> <p>Constraints:</p> <p>If <i>SourceType</i> is
     * supplied, <i>SourceIdentifier</i> must also be provided.</p> <ul> <li>Specify
     * <code>cluster</code> when <i>SourceIdentifier</i> is a cluster identifier.</li>
     * <li>Specify <code>cluster-security-group</code> when <i>SourceIdentifier</i> is
     * a cluster security group name.</li> <li>Specify
     * <code>cluster-parameter-group</code> when <i>SourceIdentifier</i> is a cluster
     * parameter group name.</li> <li>Specify <code>cluster-snapshot</code> when
     * <i>SourceIdentifier</i> is a cluster snapshot identifier.</li> </ul>
     */
    inline DescribeEventsRequest& WithSourceType(SourceType&& value) { SetSourceType(value); return *this;}

    /**
     * <p> The beginning of the time interval to retrieve events for, specified in ISO
     * 8601 format. For more information about ISO 8601, go to the <a
     * href="http://en.wikipedia.org/wiki/ISO_8601">ISO8601 Wikipedia page.</a> </p>
     * <p>Example: <code>2009-07-08T18:00Z</code></p>
     */
    inline double GetStartTime() const{ return m_startTime; }

    /**
     * <p> The beginning of the time interval to retrieve events for, specified in ISO
     * 8601 format. For more information about ISO 8601, go to the <a
     * href="http://en.wikipedia.org/wiki/ISO_8601">ISO8601 Wikipedia page.</a> </p>
     * <p>Example: <code>2009-07-08T18:00Z</code></p>
     */
    inline void SetStartTime(double value) { m_startTimeHasBeenSet = true; m_startTime = value; }

    /**
     * <p> The beginning of the time interval to retrieve events for, specified in ISO
     * 8601 format. For more information about ISO 8601, go to the <a
     * href="http://en.wikipedia.org/wiki/ISO_8601">ISO8601 Wikipedia page.</a> </p>
     * <p>Example: <code>2009-07-08T18:00Z</code></p>
     */
    inline DescribeEventsRequest& WithStartTime(double value) { SetStartTime(value); return *this;}

    /**
     * <p> The end of the time interval for which to retrieve events, specified in ISO
     * 8601 format. For more information about ISO 8601, go to the <a
     * href="http://en.wikipedia.org/wiki/ISO_8601">ISO8601 Wikipedia page.</a> </p>
     * <p>Example: <code>2009-07-08T18:00Z</code></p>
     */
    inline double GetEndTime() const{ return m_endTime; }

    /**
     * <p> The end of the time interval for which to retrieve events, specified in ISO
     * 8601 format. For more information about ISO 8601, go to the <a
     * href="http://en.wikipedia.org/wiki/ISO_8601">ISO8601 Wikipedia page.</a> </p>
     * <p>Example: <code>2009-07-08T18:00Z</code></p>
     */
    inline void SetEndTime(double value) { m_endTimeHasBeenSet = true; m_endTime = value; }

    /**
     * <p> The end of the time interval for which to retrieve events, specified in ISO
     * 8601 format. For more information about ISO 8601, go to the <a
     * href="http://en.wikipedia.org/wiki/ISO_8601">ISO8601 Wikipedia page.</a> </p>
     * <p>Example: <code>2009-07-08T18:00Z</code></p>
     */
    inline DescribeEventsRequest& WithEndTime(double value) { SetEndTime(value); return *this;}

    /**
     * <p> The number of minutes prior to the time of the request for which to retrieve
     * events. For example, if the request is sent at 18:00 and you specify a duration
     * of 60, then only events which have occurred after 17:00 will be returned. </p>
     * <p>Default: <code>60</code></p>
     */
    inline long GetDuration() const{ return m_duration; }

    /**
     * <p> The number of minutes prior to the time of the request for which to retrieve
     * events. For example, if the request is sent at 18:00 and you specify a duration
     * of 60, then only events which have occurred after 17:00 will be returned. </p>
     * <p>Default: <code>60</code></p>
     */
    inline void SetDuration(long value) { m_durationHasBeenSet = true; m_duration = value; }

    /**
     * <p> The number of minutes prior to the time of the request for which to retrieve
     * events. For example, if the request is sent at 18:00 and you specify a duration
     * of 60, then only events which have occurred after 17:00 will be returned. </p>
     * <p>Default: <code>60</code></p>
     */
    inline DescribeEventsRequest& WithDuration(long value) { SetDuration(value); return *this;}

    /**
     * <p> The maximum number of response records to return in each call. If the number
     * of remaining response records exceeds the specified <code>MaxRecords</code>
     * value, a value is returned in a <code>marker</code> field of the response. You
     * can retrieve the next set of records by retrying the command with the returned
     * marker value. </p> <p>Default: <code>100</code></p> <p>Constraints: minimum 20,
     * maximum 100.</p>
     */
    inline long GetMaxRecords() const{ return m_maxRecords; }

    /**
     * <p> The maximum number of response records to return in each call. If the number
     * of remaining response records exceeds the specified <code>MaxRecords</code>
     * value, a value is returned in a <code>marker</code> field of the response. You
     * can retrieve the next set of records by retrying the command with the returned
     * marker value. </p> <p>Default: <code>100</code></p> <p>Constraints: minimum 20,
     * maximum 100.</p>
     */
    inline void SetMaxRecords(long value) { m_maxRecordsHasBeenSet = true; m_maxRecords = value; }

    /**
     * <p> The maximum number of response records to return in each call. If the number
     * of remaining response records exceeds the specified <code>MaxRecords</code>
     * value, a value is returned in a <code>marker</code> field of the response. You
     * can retrieve the next set of records by retrying the command with the returned
     * marker value. </p> <p>Default: <code>100</code></p> <p>Constraints: minimum 20,
     * maximum 100.</p>
     */
    inline DescribeEventsRequest& WithMaxRecords(long value) { SetMaxRecords(value); return *this;}

    /**
     * <p> An optional parameter that specifies the starting point to return a set of
     * response records. When the results of a <a>DescribeEvents</a> request exceed the
     * value specified in <code>MaxRecords</code>, AWS returns a value in the
     * <code>Marker</code> field of the response. You can retrieve the next set of
     * response records by providing the returned marker value in the
     * <code>Marker</code> parameter and retrying the request. </p>
     */
    inline const Aws::String& GetMarker() const{ return m_marker; }

    /**
     * <p> An optional parameter that specifies the starting point to return a set of
     * response records. When the results of a <a>DescribeEvents</a> request exceed the
     * value specified in <code>MaxRecords</code>, AWS returns a value in the
     * <code>Marker</code> field of the response. You can retrieve the next set of
     * response records by providing the returned marker value in the
     * <code>Marker</code> parameter and retrying the request. </p>
     */
    inline void SetMarker(const Aws::String& value) { m_markerHasBeenSet = true; m_marker = value; }

    /**
     * <p> An optional parameter that specifies the starting point to return a set of
     * response records. When the results of a <a>DescribeEvents</a> request exceed the
     * value specified in <code>MaxRecords</code>, AWS returns a value in the
     * <code>Marker</code> field of the response. You can retrieve the next set of
     * response records by providing the returned marker value in the
     * <code>Marker</code> parameter and retrying the request. </p>
     */
    inline void SetMarker(Aws::String&& value) { m_markerHasBeenSet = true; m_marker = value; }

    /**
     * <p> An optional parameter that specifies the starting point to return a set of
     * response records. When the results of a <a>DescribeEvents</a> request exceed the
     * value specified in <code>MaxRecords</code>, AWS returns a value in the
     * <code>Marker</code> field of the response. You can retrieve the next set of
     * response records by providing the returned marker value in the
     * <code>Marker</code> parameter and retrying the request. </p>
     */
    inline void SetMarker(const char* value) { m_markerHasBeenSet = true; m_marker.assign(value); }

    /**
     * <p> An optional parameter that specifies the starting point to return a set of
     * response records. When the results of a <a>DescribeEvents</a> request exceed the
     * value specified in <code>MaxRecords</code>, AWS returns a value in the
     * <code>Marker</code> field of the response. You can retrieve the next set of
     * response records by providing the returned marker value in the
     * <code>Marker</code> parameter and retrying the request. </p>
     */
    inline DescribeEventsRequest& WithMarker(const Aws::String& value) { SetMarker(value); return *this;}

    /**
     * <p> An optional parameter that specifies the starting point to return a set of
     * response records. When the results of a <a>DescribeEvents</a> request exceed the
     * value specified in <code>MaxRecords</code>, AWS returns a value in the
     * <code>Marker</code> field of the response. You can retrieve the next set of
     * response records by providing the returned marker value in the
     * <code>Marker</code> parameter and retrying the request. </p>
     */
    inline DescribeEventsRequest& WithMarker(Aws::String&& value) { SetMarker(value); return *this;}

    /**
     * <p> An optional parameter that specifies the starting point to return a set of
     * response records. When the results of a <a>DescribeEvents</a> request exceed the
     * value specified in <code>MaxRecords</code>, AWS returns a value in the
     * <code>Marker</code> field of the response. You can retrieve the next set of
     * response records by providing the returned marker value in the
     * <code>Marker</code> parameter and retrying the request. </p>
     */
    inline DescribeEventsRequest& WithMarker(const char* value) { SetMarker(value); return *this;}

  private:
    Aws::String m_sourceIdentifier;
    bool m_sourceIdentifierHasBeenSet;
    SourceType m_sourceType;
    bool m_sourceTypeHasBeenSet;
    double m_startTime;
    bool m_startTimeHasBeenSet;
    double m_endTime;
    bool m_endTimeHasBeenSet;
    long m_duration;
    bool m_durationHasBeenSet;
    long m_maxRecords;
    bool m_maxRecordsHasBeenSet;
    Aws::String m_marker;
    bool m_markerHasBeenSet;
  };

} // namespace Model
} // namespace Redshift
} // namespace Aws
