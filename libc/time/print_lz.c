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

/* Print U with leading zeros.  BUF has enough space.  */
ATTRIBUTE_CLIB_SECTION
void
__print_43210 (uint16_t u, char *buf)
{
    utoa (u, buf, 10);
    for (size_t len = strlen (buf); len < 5; ++len)
    {
        memmove (buf + 1, buf, len + 1);
        buf[0] = '0';
    }
}

/* Print digit 1 and digit 0 (in base 10) of U to *BUFFER and append C.  */
ATTRIBUTE_CLIB_SECTION
void
__print_10 (uint16_t u, char *buffer, char c)
{
    char b[6];
    __print_43210 (u, b);
    *buffer++ = b[3];
    *buffer++ = b[4];
    *buffer = c;
}
