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

/* $ID$ */

/*
    Compute the ISO 8601 week date corresponding to the given year and day of year.
*/

#include <time.h>

void
iso_week_date_r(int y, int yday, struct week_date * iso)
{
    uint16_t        years, n, wday;
    int             weeknum;

    iso->year = y;

    /* compute days elapsed since epoch */
    years = y - 2000;
    n = 365 * years + yday;
    if (years) {
        n++;        /* epoch was a leap year */
        n += (years - 1) / 4;
        if (years > 100)
            n--;
    }

    /* compute ISO8601 day of week (1 ... 7, Monday = 1) */
    wday = n + 6; /* epoch was a Saturday */
    wday %= 7;
    if (wday == 0)
        wday = 7;

    iso->day = wday;

    /* compute tentative week number */
    weeknum = yday + 11 - wday;
    weeknum /= 7;

    /* if 53, it could be week 1 of the following year */
    if (weeknum == 53) {

        /* determine final yday of this year, 364 or 365 */
        n = 364 + is_leap_year(y);

        /* compute yday of this weeks Thursday */
        wday--;       /* revert to zero based week */
        yday -= wday; /* yday of this weeks Monday */
        yday += 3;    /* yday of this weeks Thursday */

        /*
         * If this weeks Thursday is not in this year, its week 1 of
         * the following year
         */
        if (yday > (int) n) {
            iso->year++;
            weeknum = 1;
        }
    }
    iso->week = weeknum;

    /* if zero, it is final week of previous year */
    if (weeknum == 0) {
        y = y - 1;
        iso_week_date_r(y, 364 + is_leap_year(y), iso);
        iso->day = wday;
    }
}
