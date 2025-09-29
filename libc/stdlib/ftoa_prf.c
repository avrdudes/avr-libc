/* Copyright (c) 2005, Dmitry Xmelkov
   All rights reserved.

   Redistribution and use in source and binary forms, with or without
   modification, are permitted provided that the following conditions are met:

   * Redistributions of source code must retain the above copyright
     notice, this list of conditions and the following disclaimer.
   * Redistributions in binary form must reproduce the above copyright
     notice, this list of conditions and the following disclaimer in
     the documentation and/or other materials provided with the
     distribution.
   * Neither the name of the copyright holders nor the names of
     contributors may be used to endorse or promote products derived
     from this software without specific prior written permission.

  THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS "AS IS"
  AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE
  IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE
  ARE DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT OWNER OR CONTRIBUTORS BE
  LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR
  CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF
  SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS
  INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN
  CONTRACT, STRICT LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE)
  ARISING IN ANY WAY OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE
  POSSIBILITY OF SUCH DAMAGE. */

#include <stdint.h>
#include "ftoa_engine.h"
#include "ftoa_conv.h"
#include "sectionname.h"
#include "alias.h"

ATTRIBUTE_CLIB_SECTION
int
ftoa_prf (float val, char *s, uint8_t width, uint8_t prec, uint8_t flags)
{
    uint8_t sign;
    uint8_t buf[9];

    uint8_t ndigs = prec < 60 ? prec + 1 : 60;
    int exp = __ftoa_engine (val, (char*) buf, 7, ndigs);
    uint8_t vtype = buf[0];

    sign = 0;
    if ((vtype & (FTOA_MINUS | FTOA_NAN)) == FTOA_MINUS)
        sign = '-';
    else if (flags & DTOA_PLUS)
        sign = '+';
    else if (flags & DTOA_SPACE)
        sign = ' ';

    if (vtype & FTOA_NAN)
    {
        ndigs = sign ? 4 : 3;
        width = (width > ndigs) ? width - ndigs : 0;
        if (!(flags & DTOA_LEFT))
        {
            while (width)
            {
                *s++ = ' ';
                width--;
            }
        }
        if (sign)
            *s++ = sign;
        if (flags & DTOA_UPPER)
        {
            *s++ = 'N';  *s++ = 'A';  *s++ = 'N';
        }
        else
        {
            *s++ = 'n';  *s++ = 'a';  *s++ = 'n';
        }
        while (width)
        {
            *s++ = ' ';
            width--;
        }
        *s = '\0';
        return DTOA_NONFINITE;
    }

    if (vtype & FTOA_INF)
    {
        ndigs = sign ? 4 : 3;
        width = (width > ndigs) ? width - ndigs : 0;
        if (!(flags & DTOA_LEFT))
        {
            while (width)
            {
                *s++ = ' ';
                width--;
            }
        }
        if (sign)
            *s++ = sign;
        if (flags & DTOA_UPPER)
        {
            *s++ = 'I';  *s++ = 'N';  *s++ = 'F';
        }
        else
        {
            *s++ = 'i';  *s++ = 'n';  *s++ = 'f';
        }
        while (width)
        {
            *s++ = ' ';
            width--;
        }
        *s = '\0';
        return DTOA_NONFINITE;
    }

    int n = (sign ? 1 : 0) + (exp > 0 ? exp + 1 : 1) + (prec ? prec + 1 : 0);
    width = width > n ? width - n : 0;

    if (!(flags & DTOA_LEFT) && !(flags & DTOA_ZFILL))
    {
        while (width)
        {
            *s++ = ' ';
            width--;
        }
    }
    if (sign)
        *s++ = sign;
    if (!(flags & DTOA_LEFT))
    {
        while (width)
        {
            *s++ = '0';
            width--;
        }
    }

    ndigs += exp;               /* exp is resticted approx. -40 .. +40  */
    sign = buf[1];
    if ((vtype & FTOA_CARRY) && sign == '1')
        ndigs -= 1;
    if ((signed char)ndigs < 1)
        ndigs = 1;
    else if (ndigs > 8)
        ndigs = 8;

    n = exp > 0 ? exp : 0;
    for (;;)
    {
        if (n == -1)
            *s++ = '.';
        flags = (n <= exp && n > exp - ndigs) ? buf[exp - n + 1] : '0';
        if (--n < -prec)
            break;
        *s++ = flags;
    }
    if (n == exp && (sign > '5' || (sign == '5' && !(vtype & FTOA_CARRY))))
        flags = '1';
    *s++ = flags;

    while (width)
    {
        *s++ = ' ';
        width--;
    }
    *s = '\0';

    return 0;
}

DALIAS (ftoa_prf)
int dtoa_prf (double, char*, uint8_t, uint8_t, uint8_t);

LALIAS (ftoa_prf)
int ldtoa_prf (long double, char*, uint8_t, uint8_t, uint8_t);
