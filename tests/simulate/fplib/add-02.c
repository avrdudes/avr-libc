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

/* Test of addition.  Shift is needed.
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

    /* 1.0 + y	*/
    { { 0x3f800000 }, { 0x3f000000 }, { 0x3fc00000 } },
    { { 0x3f800000 }, { 0x3e800000 }, { 0x3fa00000 } },
    { { 0x3f800000 }, { 0x3e000000 }, { 0x3f900000 } },
    { { 0x3f800000 }, { 0x3d800000 }, { 0x3f880000 } },
    { { 0x3f800000 }, { 0x3d000000 }, { 0x3f840000 } },
    { { 0x3f800000 }, { 0x3c800000 }, { 0x3f820000 } },
    { { 0x3f800000 }, { 0x3c000000 }, { 0x3f810000 } },
    { { 0x3f800000 }, { 0x3b800000 }, { 0x3f808000 } },
    { { 0x3f800000 }, { 0x3b000000 }, { 0x3f804000 } },
    { { 0x3f800000 }, { 0x3a800000 }, { 0x3f802000 } },
    { { 0x3f800000 }, { 0x3a000000 }, { 0x3f801000 } },
    { { 0x3f800000 }, { 0x39800000 }, { 0x3f800800 } },
    { { 0x3f800000 }, { 0x39000000 }, { 0x3f800400 } },
    { { 0x3f800000 }, { 0x38800000 }, { 0x3f800200 } },
    { { 0x3f800000 }, { 0x38000000 }, { 0x3f800100 } },
    { { 0x3f800000 }, { 0x37800000 }, { 0x3f800080 } },
    { { 0x3f800000 }, { 0x37000000 }, { 0x3f800040 } },
    { { 0x3f800000 }, { 0x36800000 }, { 0x3f800020 } },
    { { 0x3f800000 }, { 0x36000000 }, { 0x3f800010 } },
    { { 0x3f800000 }, { 0x35800000 }, { 0x3f800008 } },
    { { 0x3f800000 }, { 0x35000000 }, { 0x3f800004 } },
    { { 0x3f800000 }, { 0x34800000 }, { 0x3f800002 } },
    { { 0x3f800000 }, { 0x34000000 }, { 0x3f800001 } },
    { { 0x3f800000 }, { 0x33800000 }, { 0x3f800000 } },
    { { 0x3f800000 }, { 0x33000000 }, { 0x3f800000 } },
    { { 0x3f800000 }, { 0x00000001 }, { 0x3f800000 } },
    
    /* ~1.0 - y	*/
    { { 0x3f7fffff }, { 0xbe800000 }, { 0x3f3fffff } },
    { { 0x3f7fffff }, { 0xbe000000 }, { 0x3f5fffff } },
    { { 0x3f7fffff }, { 0xbd800000 }, { 0x3f6fffff } },
    { { 0x3f7fffff }, { 0xbd000000 }, { 0x3f77ffff } },
    { { 0x3f7fffff }, { 0xbc800000 }, { 0x3f7bffff } },
    { { 0x3f7fffff }, { 0xbc000000 }, { 0x3f7dffff } },
    { { 0x3f7fffff }, { 0xbb800000 }, { 0x3f7effff } },
    { { 0x3f7fffff }, { 0xbb000000 }, { 0x3f7f7fff } },
    { { 0x3f7fffff }, { 0xba800000 }, { 0x3f7fbfff } },
    { { 0x3f7fffff }, { 0xba000000 }, { 0x3f7fdfff } },
    { { 0x3f7fffff }, { 0xb9800000 }, { 0x3f7fefff } },
    { { 0x3f7fffff }, { 0xb9000000 }, { 0x3f7ff7ff } },
    { { 0x3f7fffff }, { 0xb8800000 }, { 0x3f7ffbff } },
    { { 0x3f7fffff }, { 0xb8000000 }, { 0x3f7ffdff } },
    { { 0x3f7fffff }, { 0xb7800000 }, { 0x3f7ffeff } },
    { { 0x3f7fffff }, { 0xb7000000 }, { 0x3f7fff7f } },
    { { 0x3f7fffff }, { 0xb6800000 }, { 0x3f7fffbf } },
    { { 0x3f7fffff }, { 0xb6000000 }, { 0x3f7fffdf } },
    { { 0x3f7fffff }, { 0xb5800000 }, { 0x3f7fffef } },
    { { 0x3f7fffff }, { 0xb5000000 }, { 0x3f7ffff7 } },
    { { 0x3f7fffff }, { 0xb4800000 }, { 0x3f7ffffb } },
    { { 0x3f7fffff }, { 0xb4000000 }, { 0x3f7ffffd } },
    { { 0x3f7fffff }, { 0xb3800000 }, { 0x3f7ffffe } },
    { { 0x3f7fffff }, { 0xb3000000 }, { 0x3f7ffffe } },
    { { 0x3f7fffff }, { 0xb2800000 }, { 0x3f7fffff } },
    { { 0x3f7fffff }, { 0xb2000000 }, { 0x3f7fffff } },
    { { 0x3f7fffff }, { 0x80000001 }, { 0x3f7fffff } },
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
