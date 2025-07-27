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

/* Re entrant version of isotime(),  which prints the date and time
   in ISO 8601 format.  */

#include <stdlib.h>
#include <stdint.h>
#include <time.h>
#include "time-private.h"

#include "sectionname.h"

ATTRIBUTE_CLIB_SECTION
void
isotime_r(const struct tm *tmptr, char *buffer)
{
    __print_43210 (tmptr->tm_year + 1900, buffer);
    buffer[0] = buffer[1];
    buffer[1] = buffer[2];
    buffer[2] = buffer[3];
    buffer[3] = buffer[4];
    buffer[4] = '-';
    buffer += 5;

    __print_10 ((uint8_t) tmptr->tm_mon + 1, buffer, '-');
    buffer += 3;

    __print_10 ((uint8_t) tmptr->tm_mday, buffer, ' ');
    buffer += 3;

    __print_10 ((uint8_t) tmptr->tm_hour, buffer, ':');
    buffer += 3;

    __print_10 ((uint8_t) tmptr->tm_min, buffer, ':');
    buffer += 3;

    __print_10 ((uint8_t) tmptr->tm_sec, buffer, '\0');
}
