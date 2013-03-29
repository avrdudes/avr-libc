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
	Basically the inverse of gmtime_r(). We assume the values in timeptr represent
	UTC, thus time zone and DST do not apply.
	
	Unlike mktime(), we do not attempt to 'normalize' timeptr... saves some cpu cycles.
*/

#include <time.h>

time_t
mk_gmtime(struct tm * timeptr)
{

	time_t          ret;
	long            tmp;
	int             n, m, d, leaps;

	/* n = years since epoch */
	n = timeptr->tm_year - 100;

	/* compute leap days prior to timeptr */
	leaps = 0;
	if (n) {
		m = n - 1;
		leaps = m / 4;
		leaps -= m / 100;
		leaps++;
	}
	/* compute days elapsed since EPOCH to the beginning of the year */
	tmp = 365L * n + leaps;

	m = timeptr->tm_mday - 1;
	d = 0;

	/* Special case January */
	if (timeptr->tm_mon == 0) {
		d += m;
	}
	/* Special case February */
	else if (timeptr->tm_mon == 1) {
		n = m + 31;
		d += n;
	} else {
		d += 29;
		if (is_leap_year(timeptr->tm_year + 1900))
			d++;

		m = timeptr->tm_mon - 1;

		n = m / 2;
		m -= n * 2;

		n *= 61;
		d += n;

		if (m) {
			d += 30;
			if (timeptr->tm_mon > 6)
				d++;
		}
		d += timeptr->tm_mday - 1;
	}

	tmp += d;

	/* convert days into seconds */
	ret = 86400LL * tmp;

	/* add time of day */
	tmp = 3600L * timeptr->tm_hour;
	tmp += 60L * timeptr->tm_min;
	tmp += timeptr->tm_sec;

	ret += tmp;

	return ret;
}
