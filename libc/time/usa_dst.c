/*
 * Copyright (c) 2012 Michael Duane Rice All rights reserved.
 *
 * Redistribution and use in source and binary forms, with or without
 * modification, are permitted provided that the following conditions are
 * met:
 *
 * Redistributions of source code must retain the above copyright notice, this
 * list of conditions and the following disclaimer. Redistributions in binary
 * form must reproduce the above copyright notice, this list of conditions
 * and the following disclaimer in the documentation and/or other materials
 * provided with the distribution. Neither the name of the copyright holders
 * nor the names of contributors may be used to endorse or promote products
 * derived from this software without specific prior written permission.
 *
 * THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS "AS IS"
 * AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE
 * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE
 * ARE DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT OWNER OR CONTRIBUTORS BE
 * LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR
 * CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF
 * SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS
 * INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN
 * CONTRACT, STRICT LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE)
 * ARISING IN ANY WAY OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE
 * POSSIBILITY OF SUCH DAMAGE. */

#include <time.h>
#include <stdint.h>
#include <util/usa_dst.h>

#ifndef DST_START_MONTH
#define DST_START_MONTH MARCH
#endif

#ifndef DST_END_MONTH
#define DST_END_MONTH NOVEMBER
#endif

#ifndef DST_START_WEEK
#define DST_START_WEEK 2
#endif

#ifndef DST_END_WEEK
#define DST_END_WEEK 1
#endif

#include "sectionname.h"

ATTRIBUTE_CLIB_SECTION
int usa_dst (const time_t *timer, int32_t *z)
{
    struct tm tmptr;

    /* Obtain the variables */
    time_t t = *timer + *z;
    gmtime_r (&t, &tmptr);
    uint8_t month = tmptr.tm_mon;
    uint8_t day_of_week = tmptr.tm_wday;
    uint8_t week = week_of_month (&tmptr, 0);
    uint8_t hour = tmptr.tm_hour;

    if (month > DST_START_MONTH && month < DST_END_MONTH)
        return ONE_HOUR;
    else if (month < DST_START_MONTH)
        return 0;
    else if (month > DST_END_MONTH)
        return 0;

    if (month == DST_START_MONTH)
    {
        if (week < DST_START_WEEK)
            return 0;
        else if (week > DST_START_WEEK)
            return ONE_HOUR;

        if (day_of_week > SUNDAY)
            return ONE_HOUR;
        else if (hour >= 2)
            return ONE_HOUR;
        else
            return 0;
    }

    if (week > DST_END_WEEK)
        return 0;
    else if (week < DST_END_WEEK)
        return ONE_HOUR;
    else if (day_of_week > SUNDAY)
        return 0;
    else if (hour >= 1)
        return 0;
    else
        return ONE_HOUR;
}
