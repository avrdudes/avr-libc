/*
 * Copyright (C) 2012 Michael Duane Rice All rights reserved.
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

/* Re-entrant version of asctime(). */

#include <stdlib.h>
#include <stdint.h>
#include <time.h>
#include "time-private.h"

#include "sectionname.h"

#ifdef __MEMX
const __memx char ascmonths[] = "JanFebMarAprMayJunJulAugSepOctNovDec";
const __memx char ascdays[] = "SunMonTueWedThuFriSat";
#else
const char      ascmonths[] = "JanFebMarAprMayJunJulAugSepOctNovDec";
const char      ascdays[] = "SunMonTueWedThuFriSat";
#endif

ATTRIBUTE_CLIB_SECTION
void
asctime_r (const struct tm *timeptr, char *buffer)
{
    // Start with the year, so we can use BUFFER as buffer.
    __print_43210 (timeptr->tm_year + 1900, buffer);
    char *const s_year = buffer + 8 + 3 + 3 + 3 + 3;
    s_year[0] = buffer[1];
    s_year[1] = buffer[2];
    s_year[2] = buffer[3];
    s_year[3] = buffer[4];
    s_year[4] = '\0';

    uint8_t d = timeptr->tm_wday * 3;
    uint8_t m = timeptr->tm_mon * 3;
    for (uint8_t i = 0; i < 3; i++)
    {
        buffer[i] = ascdays[d++];
        buffer[i+4] = ascmonths[m++];
    }
    buffer[3] = buffer[7] = ' ';
    buffer += 8;

    __print_10 ((uint8_t) timeptr->tm_mday, buffer, ' ');
    buffer += 3;

    __print_10 ((uint8_t) timeptr->tm_hour, buffer, ':');
    buffer += 3;

    __print_10 ((uint8_t) timeptr->tm_min, buffer, ':');
    buffer += 3;

    __print_10 ((uint8_t) timeptr->tm_sec, buffer, ' ');
    buffer += 3;
}
