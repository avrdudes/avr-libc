/*
 * (C)2012 Michael Duane Rice All rights reserved.
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

/*
    Re entrant version of gmtime(), this function 'breaks down' a Y2K time stamp .
*/

#include <time.h>
#include <stdlib.h>
#include <inttypes.h>

void
gmtime_r(const time_t * timer, struct tm * timeptr)
{
	int32_t         fract;
	ldiv_t          lresult;
	div_t           result;
	uint16_t        days, n, leapyear, years;

	/* break down timer into whole and fractional parts of 1 day */
	days = *timer / 86400UL;
	fract = *timer % 86400UL;

	/* Determine day of week ( the epoch was a Saturday ) */
	n = days + SATURDAY;
	n %= 7;
	timeptr->tm_wday = n;

	/* map our place into the 100 year and 4 year leap cycles. */
	lresult = ldiv((long) days, 36525L);
	years = 100 * lresult.quot;
	lresult = ldiv(lresult.rem, 1461L);
	years += 4 * lresult.quot;
	days = lresult.rem;
	if (years > 100)
		days++;

	/*
         * 'years' is now at a 4 year boundary
         * 'days' is an index into the current 1461 day leap cycle
         * If 'years' != 100, this cycle begins with a 366 day year.
         */
	leapyear = 1;
	if (years == 100)
		leapyear = 0;

	n = 364 + leapyear;

	/*
            Given the length of the first year of this cycle,
            we can proceed to break down year and day of year.
        */
	if (days > n) {
		days -= leapyear;
		leapyear = 0;
		result = div(days, 365);
		years += result.quot;
		days = result.rem;
	}
	timeptr->tm_year = 100 + years;
	timeptr->tm_yday = days;

	/*
            Given the year, day of year, and leap year indicator, we can break down the
            month and day of month.
        */
	n = 59 + leapyear;

	if (days < n) {
		result = div(days, 31);
		timeptr->tm_mon = result.quot;
		timeptr->tm_mday = result.rem;
	} else {
		days -= n;
		result = div(days, 153);
		timeptr->tm_mon = 2 + result.quot * 5;
		result = div(result.rem, 61);
		timeptr->tm_mon += result.quot * 2;
		result = div(result.rem, 31);
		timeptr->tm_mon += result.quot;
		timeptr->tm_mday = result.rem;
	}

	/*
            Break down hour, minute, and second from the fractional day
        */
	lresult = ldiv(fract, 60L);
	timeptr->tm_sec = lresult.rem;
	result = div(lresult.quot, 60);
	timeptr->tm_min = result.rem;
	timeptr->tm_hour = result.quot;

	/*
            Cleanup and return
        */
	timeptr->tm_isdst = 0;	/* gmt is never in DST */
	timeptr->tm_mday++;	/* tm_mday is 1 based */

}
