/*
 * Copyright (c) 2012 Michael Duane Rice All rights reserved.
 * Copyright (c) 2025 Georg-Johann Lay  # Get rid of sprintf.
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

/*
    Standard strftime(). This is a memory hungry monster.
*/

#include <stdint.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <bits/best_as.h>
#include "time-private.h"
#include "sectionname.h"

#define AS __BEST_AS

// Like PSTR, but for AS.
#define ASSTR(s) \
    (__extension__({ static const AS char __c[] = (s); &__c[0]; }))

// We want AS_NULL to be 0x000000 literally, not something
// like 0x800000 for __memx (or for __flashx due to PR121277).
#define AS_NULL ((const AS char*) 0)

static const AS char strfwkdays[] =
    "Sunday Monday Tuesday Wednesday Thursday Friday Saturday ";

static const AS char strfmonths[] =
    "January February March April May June July August September October"
    " November December ";

ATTRIBUTE_CLIB_SECTION
static uint8_t
pgm_copystring (const char AS *p, uint8_t i, char *b, uint8_t len)
{
    char c;
    uint8_t ret = 0;

    while (i)
    {
        c = *p++;
        if (c == ' ')
            i--;
    }

    c = *p++;
    while (c != ' ' && len--)
    {
        *b++ = c;
        ret++;
        c = *p++;
    }
    *b = 0;
    return ret;
}


/* Convert unsigned NUM to a string in S, where we are only interested in
   the digits as specified by BITS.  S is *NOT* NULL-terminated and has
   enough space for what we are doing.
   The number of stored chars equals popcount(|BITS|).
   BITS < 0: Fill with leading blanks (only BITS = -0x3 is supported for now).
   BITS > 0: Fill with leading 0's.  */

ATTRIBUTE_CLIB_SECTION
//static
uint8_t
u2s (char *s, int8_t bits, uint16_t num)
{
    uint8_t pos = strlen (utoa (num, s + 5, 10));
    uint8_t n_digs = 0;

    for (uint8_t b = abs (bits); b & 0x1f; b <<= 1, ++pos)
    {
        if (b & 0x10)
            s[n_digs++] = pos < 5 ? '0' : s[pos];
    }

    if (bits == -0x3 && s[0] == '0')
        s[0] = ' ';

    return n_digs;
}


ATTRIBUTE_CLIB_SECTION
size_t
strftime (char *buffer, size_t limit, const char *pattern,
          const struct tm *timeptr)
{
    int d, w;
    char c;
    char _store[32];
    struct week_date wd;
    const AS char *alt = AS_NULL;
    uint16_t count = 0;
    uint8_t length = 0; // Length in _store[].

    while (count < limit)
    {
        if (alt && *alt == '\0')
            alt = AS_NULL;

        c = alt ? *alt++ : *pattern++;

        if (c == '%')
        {
            c = alt ? *alt++ : *pattern++;

            if (c == 'E' || c == 'O')
                c = alt ? *alt++ : *pattern++;

            switch (c)
            {
                case '%':
                    _store[0] = c;
                    length = 1;
                    break;

                case '\0':
                    *buffer = '\0';
                    return count;

                case 'a':
                    length = pgm_copystring (strfwkdays, timeptr->tm_wday,
                                             _store, 3);
                    break;

                case 'A':
                    length = pgm_copystring (strfwkdays, timeptr->tm_wday,
                                             _store, 255);
                    break;

                case 'b':
                case 'h':
                    length = pgm_copystring (strfmonths, timeptr->tm_mon,
                                             _store, 3);
                    break;

                case 'B':
                    length = pgm_copystring (strfmonths, timeptr->tm_mon,
                                             _store, 255);
                    break;

                case 'c':
                    alt = ASSTR ("%a %b %d %H:%M:%S %Y");
                    length = 0;
                    break;

                case 'C':
                    length = u2s (_store, 0xc, timeptr->tm_year + 1900);
                    break;

                case 'd':
                    length = u2s (_store, 0x3, (uint8_t) timeptr->tm_mday);
                    break;

                case 'D':
                    alt = ASSTR ("%m/%d/%y");
                    length = 0;
                    break;

                case 'e':
                    length = u2s (_store, -0x3, (uint8_t) timeptr->tm_mday);
                    break;

                case 'F':
                    alt = ASSTR ("%Y-%m-%d");
                    length = 0;
                    break;

                case 'g':
                case 'G':
                    iso_week_date_r (timeptr->tm_year + 1900,
                                     timeptr->tm_yday, &wd);
                    length = u2s (_store, c == 'g' ? 0x3 : 0xf, wd.year);
                    break;

                case 'H':
                case 'k':
                    length = u2s (_store, c == 'H' ? 0x3 : -0x3,
                                  (uint8_t) timeptr->tm_hour);
                    break;

                case 'I':
                case 'l':
                {
                    uint8_t d = timeptr->tm_hour;
                    d = d > 11 ? d - 12 : d;
                    length = u2s (_store, c == 'I' ? 0x3 : -0x3,
                                  d == 0 ? 12 : d);
                }
                break;

                case 'j':
                    length = u2s (_store, 0x7, timeptr->tm_yday + 1);
                    break;

                case 'm':
                    length = u2s (_store, 0x3, (uint8_t) timeptr->tm_mon + 1);
                    break;

                case 'M':
                    length = u2s (_store, 0x3, (uint8_t) timeptr->tm_min);
                    break;

                case 'n':
                    _store[0] = '\n';
                    length = 1;
                    break;

                case 'p':
                    _store[0] = timeptr->tm_hour > 11 ? 'P' : 'A';
                    _store[1] = 'M';
                    length = 2;
                    break;

                case 'P':
                    _store[0] = timeptr->tm_hour > 11 ? 'p' : 'a';
                    _store[1] = 'm';
                    length = 2;
                    break;

                case 'r':
                    alt = ASSTR ("%I:%M:%S %p");
                    length = 0;
                    break;

                case 'R':
                    alt = ASSTR ("%H:%M");
                    length = 0;
                    break;

                case 'S':
                    length = u2s (_store, 0x3, (uint8_t) timeptr->tm_sec);
                    break;

                case 't':
                    _store[0] = '\t';
                    length = 1;
                    break;

                case 'T':
                    alt = ASSTR ("%H:%M:%S");
                    length = 0;
                    break;

                case 'u':
                    w = timeptr->tm_wday;
                    _store[0] = w == 0 ? '7' : '0' + w;
                    length = 1;
                    break;

                case 'U':
                    length = u2s (_store, 0x3, week_of_year (timeptr, 0));
                    break;

                case 'V':
                    iso_week_date_r (timeptr->tm_year + 1900,
                                     timeptr->tm_yday, &wd);
                    length = u2s (_store, 0x3, wd.week);
                    break;

                case 'w':
                    _store[0] = '0' + (uint8_t) timeptr->tm_wday;
                    length = 1;
                    break;

                case 'W':
                    length = u2s (_store, 0x3, week_of_year (timeptr, 1));
                    break;

                case 'x':
                    alt = ASSTR ("%m/%d/%y");
                    length = 0;
                    break;

                case 'X':
                    alt = ASSTR ("%H:%M:%S");
                    length = 0;
                    break;

                case 'y':
                case 'Y':
                    length = u2s (_store, c == 'Y' ? 0xf : 0x3,
                                  timeptr->tm_year + 1900);
                    break;

                case 'z':
                    d = __utc_offset / 60;
                    w = timeptr->tm_isdst / 60;
                    if (w > 0)
                        d += w;
                    w = abs (d % 60);
                    d = d / 60;
                    _store[0] = d < 0 ? '-' : '+';
                    u2s (_store + 1, 0x3, abs (d));
                    u2s (_store + 3, 0x3, w);
                    length = 5;
                    break;

                default:
                    _store[0] = '?';
                    length = 1;
                    break;
            }

            if (length + count < limit)
            {
                count += length;
                for (uint8_t d = 0; d < length; ++d)
                    *buffer++ = _store[d];
            }
            else
            {
                *buffer = '\0';
                return count;
            }

        }
        else
        {
            /* copy a literal */
            *buffer++ = c;
            count++;
            if (c == '\0')
                return count;
        }
    }

    *buffer = '\0';
    return count;
}
