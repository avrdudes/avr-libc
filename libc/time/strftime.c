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

/*
    Standard strftime(). This is a memory hungry monster.
*/

#include <stdlib.h>
#include <stdio.h>
#include <time.h>

extern long     __utc_offset;

#ifdef __MEMX

const __memx char strfwkdays[] = "Sunday Monday Tuesday Wednesday Thursday Friday Saturday ";
const __memx char strfmonths[] = "January February March April May June July August September October November December ";

#else

const char      strfwkdays[] = "Sunday Monday Tuesday Wednesday Thursday Friday Saturday ";
const char      strfmonths[] = "January February March April May June July August September October November December ";

#endif

#ifdef __MEMX

unsigned char
pgm_copystring(const char __memx * p, unsigned char i, char *b, unsigned char l)
{

#else

unsigned char
pgm_copystring(const char *p, unsigned char i, char *b, unsigned char l)
{

#endif

    unsigned char   ret, c;

    ret = 0;
    while (i) {
        c = *p++;
        if (c == ' ')
            i--;
    }

    c = *p++;
    while (c != ' ' && l--) {
        *b++ = c;
        ret++;
        c = *p++;
    }
    *b = 0;
    return ret;
}

size_t
strftime(char *buffer, size_t limit, const char *pattern, const struct tm * timeptr)
{
    unsigned int    count, length;
    int             d, w;
    char            c;
    char            _store[26];
    struct week_date wd;

    count = length = 0;
    while (count < limit) {
        c = *pattern++;
        if (c == '%') {
            c = *pattern++;
            if (c == 'E' || c == 'O')
                c = *pattern++;
            switch (c) {
            case ('%'):
                _store[0] = c;
                length = 1;
                break;

            case ('a'):
                length = pgm_copystring(strfwkdays, timeptr->tm_wday, _store, 3);
                break;

            case ('A'):
                length = pgm_copystring(strfwkdays, timeptr->tm_wday, _store, 255);
                break;

            case ('b'):
            case ('h'):
                length = pgm_copystring(strfmonths, timeptr->tm_mon, _store, 3);
                break;

            case ('B'):
                length = pgm_copystring(strfmonths, timeptr->tm_mon, _store, 255);
                break;

            case ('c'):
                asctime_r(timeptr, _store);
                length = 0;
                while (_store[length])
                    length++;
                break;

            case ('C'):
                d = timeptr->tm_year + 1900;
                d /= 100;
                length = sprintf(_store, "%.2d", d);
                break;

            case ('d'):
                length = sprintf(_store, "%.2u", timeptr->tm_mday);
                break;

            case ('D'):
                length = sprintf(_store, "%.2u/%.2u/%.2u", \
                         timeptr->tm_mon + 1, \
                         timeptr->tm_mday, \
                         timeptr->tm_year % 100 \
                    );
                break;

            case ('e'):
                length = sprintf(_store, "%2d", timeptr->tm_mday);
                break;

            case ('F'):
                length = sprintf(_store, "%d-%.2d-%.2d", \
                         timeptr->tm_year + 1900, \
                         timeptr->tm_mon + 1, \
                         timeptr->tm_mday \
                    );
                break;

            case ('g'):
			case ('G'):
				iso_week_date_r(timeptr->tm_year + 1900, timeptr->tm_yday, &wd);
                if (c == 'g') {
                    length = sprintf(_store, "%.2d", wd.year % 100);
                } else {
                    length = sprintf(_store, "%.4d", wd.year);
                }

				break;

            case ('H'):
                length = sprintf(_store, "%.2u", timeptr->tm_hour);
                break;

            case ('I'):
                d = timeptr->tm_hour % 12;
                if (d == 0)
                    d = 12;
                length = sprintf(_store, "%.2u", d);
                break;

            case ('j'):
                length = sprintf(_store, "%.3u", timeptr->tm_yday + 1);
                break;

            case ('m'):
                length = sprintf(_store, "%.2u", timeptr->tm_mon + 1);
                break;

            case ('M'):
                length = sprintf(_store, "%.2u", timeptr->tm_min);
                break;

            case ('n'):
                _store[0] = 10;
                length = 1;
                break;

            case ('p'):
                length = 2;
                _store[0] = 'A';
                if (timeptr->tm_hour > 11)
                    _store[0] = 'P';
                _store[1] = 'M';
                _store[2] = 0;
                break;

            case ('r'):
                d = timeptr->tm_hour % 12;
                if (d == 0)
                    d = 12;
                length = sprintf(_store, "%2d:%.2d:%.2d AM", \
                         d, \
                         timeptr->tm_min, \
                         timeptr->tm_sec \
                    );
                if (timeptr->tm_hour > 11)
                    _store[10] = 'P';
                break;

            case ('R'):
                length = sprintf(_store, "%.2d:%.2d", timeptr->tm_hour, timeptr->tm_min);
                break;

            case ('S'):
                length = sprintf(_store, "%.2u", timeptr->tm_sec);
                break;

            case ('t'):
                length = sprintf(_store, "\t");
                break;

            case ('T'):
                length = sprintf(_store, "%.2d:%.2d:%.2d", \
                         timeptr->tm_hour, \
                         timeptr->tm_min, \
                         timeptr->tm_sec \
                    );
                break;

            case ('u'):
                w = timeptr->tm_wday;
                if (w == 0)
                    w = 7;
                length = sprintf(_store, "%d", w);
                break;

            case ('U'):
                length = sprintf(_store, "%.2u", week_of_year(timeptr, 0));
                break;

			case ('V'):
				iso_week_date_r(timeptr->tm_year + 1900, timeptr->tm_yday, &wd);
                length = sprintf(_store, "%.2u", wd.week);
				break;

            case ('w'):
                length = sprintf(_store, "%u", timeptr->tm_wday);
                break;

            case ('W'):
                w = week_of_year(timeptr, 1);
                length = sprintf(_store, "%.2u", w);
                break;

            case ('x'):
                length = sprintf(_store, "%.2u/%.2u/%.2u", timeptr->tm_mon + 1, timeptr->tm_mday, timeptr->tm_year % 100);
                break;

            case ('X'):
                length = sprintf(_store, "%.2u:%.2u:%.2u", timeptr->tm_hour, timeptr->tm_min, timeptr->tm_sec);
                break;

            case ('y'):
                length = sprintf(_store, "%.2u", timeptr->tm_year % 100);
                break;

            case ('Y'):
                length = sprintf(_store, "%u", timeptr->tm_year + 1900);
                break;

            case ('z'):
                d = __utc_offset / 60;
                w = timeptr->tm_isdst / 60;
                if (w > 0)
                    d += w;
                w = abs(d % 60);
                d = d / 60;
                length = sprintf(_store, "%+.2d%.2d", d, w);
                break;

            default:
                length = 1;
                _store[0] = '?';
                _store[1] = 0;
                break;
            }

            if ((length + count) < limit) {
                count += length;
                for (d = 0; d < (int) length; d++) {
                    *buffer++ = _store[d];
                }
            } else {
                *buffer = 0;
                return count;
            }

        } else {    /* copy a literal */
            *buffer = c;
            buffer++;
            count++;
            if (c == 0)
                return count;
        }
    }

    *buffer = 0;
    return count;
}
