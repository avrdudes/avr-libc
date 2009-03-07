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

/* Test of addition.  Rounding.
   $Id$
 */
#include <stdio.h>
#include <stdlib.h>
#include "progmem.h"

union lofl_u {
    long lo;
    float fl;
};

volatile union lofl_u v = { .lo = 1 };

PROGMEM const struct {		/* Table of test cases:  x + y = z	*/
    union lofl_u x, y, z;
} t[] = {

    /* The remainder is exactly 0.5: look the smart rounding direction. */
    { { .fl = 0x0.8p0 }, { .fl = 0x0.0000008p0 }, { .fl = 0x0.800000p0 } },
    { { .fl = 0x0.8p0 }, { .fl = 0x0.0000010p0 }, { .fl = 0x0.800001p0 } },
    { { .fl = 0x0.8p0 }, { .fl = 0x0.0000018p0 }, { .fl = 0x0.800002p0 } },
    { { .fl = 0x0.8p0 }, { .fl = 0x0.0000020p0 }, { .fl = 0x0.800002p0 } },
    { { .fl = 0x0.8p0 }, { .fl = 0x0.0000028p0 }, { .fl = 0x0.800002p0 } },
    { { .fl = 0x0.8p0 }, { .fl = 0x0.0000030p0 }, { .fl = 0x0.800003p0 } },
    { { .fl = 0x0.8p0 }, { .fl = 0x0.0000038p0 }, { .fl = 0x0.800004p0 } },
    { { .fl = 0x0.8p0 }, { .fl = 0x0.0000040p0 }, { .fl = 0x0.800004p0 } },

    /* The remainder is exactly 0.5, subtraction.	*/
    { { .fl = 0x0.9p0 }, { .fl = -0x0.0000008p0 }, { .fl = 0x0.900000p0 } },
    { { .fl = 0x0.9p0 }, { .fl = -0x0.0000010p0 }, { .fl = 0x0.8fffffp0 } },
    { { .fl = 0x0.9p0 }, { .fl = -0x0.0000018p0 }, { .fl = 0x0.8ffffep0 } },
    { { .fl = 0x0.9p0 }, { .fl = -0x0.0000020p0 }, { .fl = 0x0.8ffffep0 } },
    { { .fl = 0x0.9p0 }, { .fl = -0x0.0000028p0 }, { .fl = 0x0.8ffffep0 } },
    { { .fl = 0x0.9p0 }, { .fl = -0x0.0000030p0 }, { .fl = 0x0.8ffffdp0 } },
    { { .fl = 0x0.9p0 }, { .fl = -0x0.0000038p0 }, { .fl = 0x0.8ffffcp0 } },
    { { .fl = 0x0.9p0 }, { .fl = -0x0.0000040p0 }, { .fl = 0x0.8ffffcp0 } },

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
    union lofl_u x,y,z;
    int i;
    
    for (i = 0; i < (int) (sizeof(t) / sizeof(t[0])); i++) {
	x.lo = pgm_read_dword (& t[i].x);
	y.lo = pgm_read_dword (& t[i].y);
	z.lo = pgm_read_dword (& t[i].z);
	v.fl = x.fl + y.fl;
	/* Comparison is integer to verify the zero sign.	*/
	if (v.lo != z.lo)
	    x_exit (i+1);
    }
    return 0;
}
