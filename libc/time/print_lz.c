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

/* Auxillary functions for isotime and asctime. */

#include <stdlib.h>
#include <string.h>
#include "time-private.h"

#include "sectionname.h"

/* Print U with 5 digits where the highest one is garbage.
   BUF has enough space.  */

ATTRIBUTE_CLIB_SECTION
void
__print_x3210 (uint16_t u, char *buf)
{
    if (u < 10000)
        u += 10000;

    utoa (u, buf, 10);
}


/* Print digit 1 and digit 0 (in base 10) of U to *BUFFER and append C.
   Returns buffer + 3.  */

ATTRIBUTE_CLIB_SECTION
char*
__print_10 (uint8_t u, char *buffer, char c)
{
    while (u >= 100)
        u -= 100;

    char d1 = '0';
    while (u >= 10)
    {
        u -= 10;
        ++d1;
    }

    *buffer++ = d1;
    *buffer++ = '0' + u;
    *buffer++ = c;

    return buffer;
}
