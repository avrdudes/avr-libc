/*
 * ©2012 Michael Duane Rice All rights reserved.
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
	Re entrant version of gmtime(), this function converts 'binary' time into 'calendar' time.
*/

#include <time.h>
#include <stdlib.h>
#include <inttypes.h>

void
gmtime_r(const time_t * timer, struct tm * timeptr)
{
	int32_t         t;
	ldiv_t          lresult;
	div_t           result;
	uint16_t        days, w;
	int16_t         n, i, d, ly, years;

	/* This first division must be done the long way */
	days = *timer / 86400UL;
	t = *timer % 86400UL;

	/* Epoch was a Saturday */
	w = days + 6;
	n = w % 7;
	timeptr->tm_wday = n;

	/* extract second, minute, and hour */
	lresult = ldiv(t, 60L);
	timeptr->tm_sec = lresult.rem;

	result = div(lresult.quot, 60);
	timeptr->tm_min = result.rem;
	timeptr->tm_hour = result.quot;

	/* map our place in the 100 and 4 year leap cycles. */
	lresult = ldiv((long) days, 36525L);
	years = 100 * lresult.quot;

	lresult = ldiv(lresult.rem, 1461L);
	years += 4 * lresult.quot;
	d = lresult.rem;

	/*
	 * 'd' is number of days into current 4 year cycle, 0 to 1460. years
	 * is evenly divisible by 4, and WILL be a leap year, unless it
	 * equals 100
	 */

	ly = 1;
	if (years == 100)
		ly = 0;

	n = 364 + ly;

	if (d > n) {
		d -= ly;
		ly = 0;
		result = div(d, 365);
		years += result.quot;
		d = result.rem;
	}
	timeptr->tm_year = 100 + years;
	timeptr->tm_yday = d;

	/* special case January */
	if (d < 31) {
		timeptr->tm_mon = 0;
		timeptr->tm_mday = d;
	}
	/* special case February */
	else {
		d -= 31;
		n = 28;
		if (ly)
			n = 29;
		if (d < n) {
			timeptr->tm_mon = 1;
			timeptr->tm_mday = d;
		} else {

			d = d - n + 30;
			result = div(d, 61);
			i = result.quot;
			d = result.rem;

			n = 30;
			if (i > 2)
				n = 31;

			i *= 2;
			if (d >= n) {
				i++;
				d -= n;
			}
			timeptr->tm_mon = i + 1;
			timeptr->tm_mday = d;
		}
	}

	/* tm_mday is 1 based */
	timeptr->tm_mday++;

	/* gmt is never in DST */
	timeptr->tm_isdst = 0;

}
