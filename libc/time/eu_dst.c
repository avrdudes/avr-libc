/*
 * (c)2012 Michael Duane Rice All rights reserved.
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
 * POSSIBILITY OF SUCH DAMAGE.
 */

/* $Id$ */

#include <time.h>
#include <stdint.h>

#include "sectionname.h"

ATTRIBUTE_CLIB_SECTION
int eu_dst (const time_t *timer, int32_t *z)
{
    struct tm utc;
    (void) z;

    gmtime_r (timer, &utc);

    // Tip: March and October are both 31-day long
    const uint8_t current_month = utc.tm_mon;
    const uint8_t current_day = utc.tm_mday;
    const uint8_t current_hour = utc.tm_hour;
    const uint8_t current_weekday = utc.tm_wday;

    if (current_month == MARCH || current_month == OCTOBER)
    {
        // Daylight saving hour (UTC)
        // See https://en.wikipedia.org/wiki/Daylight_saving_time_by_country
        const uint8_t daylight_saving_hour = 1;

        // Do NOT switch:
        // - before the last week (of March/October) or
        // - before Sunday 01:00
        const uint8_t before_switching =
            (current_day + (7 - current_weekday) <= 31
             || (current_weekday == SUNDAY
                 && current_hour < daylight_saving_hour));

        return (current_month == MARCH) == (before_switching != 0)
            ? 0
            : ONE_HOUR;
    }

    // Return one hour offset if current date is between March and October
    // or past the switching time, in which case both tests return false
    return current_month < MARCH || current_month > OCTOBER
        ? 0
        : ONE_HOUR;
}
