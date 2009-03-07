/* Copyright (c) 2007  Dmitry Xmelkov
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
   POSSIBILITY OF SUCH DAMAGE.
 */

/* Test of addition.  NaNs.
   $Id$
 */
#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include "progmem.h"

union lofl_u {
    long lo;
    float fl;
};

volatile union lofl_u v = { .lo = 1 };

PROGMEM const struct {		/* Table of test cases:  x + y = NaN	*/
    union lofl_u x, y;
} t[] = {

    /* Inf - Inf	*/
    { { 0x7f800000 }, { 0xff800000 } },
    { { 0xff800000 }, { 0x7f800000 } },

    /* NaN + NaN	*/
    { { 0x7f800001 }, { 0x7f800001 } },
    { { 0x7f800100 }, { 0x7f800100 } },
    { { 0x7f810000 }, { 0x7f810000 } },
    { { 0x7fffffff }, { 0x7fffffff } },
    { { 0xff800001 }, { 0xff800001 } },
    { { 0xff800100 }, { 0xff800100 } },
    { { 0xff810000 }, { 0xff810000 } },
    { { 0xffffffff }, { 0xffffffff } },

    /* NaN + finite	*/
    { { 0x7f800001 }, { .fl = 1 } },
    { { 0x7f800100 }, { .fl = 1 } },
    { { 0x7f810000 }, { .fl = 1 } },
    { { 0x7fffffff }, { .fl = 1 } },
    { { 0xff800001 }, { .fl = 1 } },
    { { 0xff800100 }, { .fl = 1 } },
    { { 0xff810000 }, { .fl = 1 } },
    { { 0xffffffff }, { .fl = 1 } },

    /* finite + NaN	*/
    { { .fl = 1 }, { 0x7f800001 } },
    { { .fl = 1 }, { 0x7f800100 } },
    { { .fl = 1 }, { 0x7f810000 } },
    { { .fl = 1 }, { 0x7fffffff } },
    { { .fl = 1 }, { 0xff800001 } },
    { { .fl = 1 }, { 0xff800100 } },
    { { .fl = 1 }, { 0xff810000 } },
    { { .fl = 1 }, { 0xffffffff } },

    /* NaN + 0.0	*/
    { { 0x7f800001 }, { 0 } },
    { { 0x7f800100 }, { 0 } },
    { { 0x7f810000 }, { 0 } },
    { { 0x7fffffff }, { 0 } },
    { { 0xff800001 }, { 0 } },
    { { 0xff800100 }, { 0 } },
    { { 0xff810000 }, { 0 } },
    { { 0xffffffff }, { 0 } },

    /* 0.0 + NaN	*/
    { { 0 }, { 0x7f800001 } },
    { { 0 }, { 0x7f800100 } },
    { { 0 }, { 0x7f810000 } },
    { { 0 }, { 0x7fffffff } },
    { { 0 }, { 0xff800001 } },
    { { 0 }, { 0xff800100 } },
    { { 0 }, { 0xff810000 } },
    { { 0 }, { 0xffffffff } },
    
    /* NaN + Inf	*/
    { { 0x7f800001 }, { 0x7f800000 } },
    { { 0x7fffffff }, { 0x7f800000 } },
    { { 0xff800001 }, { 0xff800000 } },
    { { 0xffffffff }, { 0xff800000 } },
    
    /* Inf + NaN	*/
    { { 0x7f800000 }, { 0x7f800001 } },
    { { 0x7f800000 }, { 0x7fffffff } },
    { { 0xff800000 }, { 0xff800001 } },
    { { 0xff800000 }, { 0xffffffff } },
};

void x_exit (int index)
{
#ifndef	__AVR__
    fprintf (stderr, "t[%d]:  %#lx\n", index - 1, v.lo);
#endif
    exit (index ? index : -1);
}

int main ()
{
    union lofl_u x,y;
    int i;
    
    for (i = 0; i < (int) (sizeof(t) / sizeof(t[0])); i++) {
	x.lo = pgm_read_dword (& t[i].x);
	y.lo = pgm_read_dword (& t[i].y);
	v.fl = x.fl + y.fl;
	if (!isnan(v.fl))
	    x_exit (i+1);
    }
    return 0;
}
