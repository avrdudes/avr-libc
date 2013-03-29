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
	Daylight Savings function for the USA as of this date
*/

#ifndef EU_DST_H
#define EU_DST_H

#ifdef __cplusplus
extern          "C" {
#endif

#include <time.h>
#include <inttypes.h>

	int             usa_dst(const time_t * timer, int32_t * z) {
		time_t          t;
		struct tm       tmptr;
		uint8_t         month, week, hour, day_of_week, d;
		int             n;

		/* obtain the variables */
		                t = *timer + *z;
		                gmtime_r(&t, &tmptr);
		                month = tmptr.tm_mon;
		                day_of_week = tmptr.tm_wday;
		                week = week_of_month(&tmptr, 0);
		                hour = tmptr.tm_hour;

		if              ((month > MARCH) && (month < NOVEMBER))
			                return ONE_HOUR;

		if              (month < MARCH)
			                return 0;
		if              (month > NOVEMBER)
			                return 0;

		if              (month == MARCH) {

			if (week < 2)
				return 0;
			if (week > 2)
				return ONE_HOUR;

			if (day_of_week > SUNDAY)
				return ONE_HOUR;
			if (hour >= 2)
				return ONE_HOUR;
			return 0;
		}
		if              (week > 1)
			                return 0;
		if              (week < 1)
			                return ONE_HOUR;
		if              (day_of_week > SUNDAY)
			                return 0;
		if              (hour >= 1)
			                return 0;
		                return ONE_HOUR;

	}

#ifdef __cplusplus
}
#endif

#endif
