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

/* Test of fmod() function.
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

PROGMEM const struct {		/* Table of test cases	*/
    union lofl_u x, y;		/* args		*/
    union lofl_u z;		/* fmod(x,y)	*/
} t[] = {

    /* fmod(0,y) --> 0	*/
    { { .fl=  0.0 }, { .fl=  1.0 }, { .fl=  0.0 } },
    { { .fl=  0.0 }, { .fl= -1.0 }, { .fl=  0.0 } },
    { { .fl= -0.0 }, { .fl=  1.0 }, { .fl= -0.0 } },
    { { .fl= -0.0 }, { .fl= -1.0 }, { .fl= -0.0 } },
    
    { { .fl= 0.0 }, { 0x00000001 }, { .fl= 0.0 } },
    { { .fl= 0.0 }, { 0x00000100 }, { .fl= 0.0 } },
    { { .fl= 0.0 }, { 0x00010000 }, { .fl= 0.0 } },
    { { .fl= 0.0 }, { 0x007fffff }, { .fl= 0.0 } },
    { { .fl= 0.0 }, { 0x00800000 }, { .fl= 0.0 } },
    { { .fl= 0.0 }, { 0x7f7fffff }, { .fl= 0.0 } },

    /* fmod(x,+Inf) --> x	*/
    { { 0x00000000 }, { 0x7f800000 }, { 0x00000000 } },
    { { 0x00000001 }, { 0x7f800000 }, { 0x00000001 } },
    { { 0x00000100 }, { 0x7f800000 }, { 0x00000100 } },
    { { 0x00010000 }, { 0x7f800000 }, { 0x00010000 } },
    { { 0x007fffff }, { 0x7f800000 }, { 0x007fffff } },
    { { 0x00800000 }, { 0x7f800000 }, { 0x00800000 } },
    { { 0x7f7fffff }, { 0x7f800000 }, { 0x7f7fffff } },

    { { 0x80000000 }, { 0x7f800000 }, { 0x80000000 } },
    { { 0x80000001 }, { 0x7f800000 }, { 0x80000001 } },
    { { 0x80000100 }, { 0x7f800000 }, { 0x80000100 } },
    { { 0x80010000 }, { 0x7f800000 }, { 0x80010000 } },
    { { 0x807fffff }, { 0x7f800000 }, { 0x807fffff } },
    { { 0x80800000 }, { 0x7f800000 }, { 0x80800000 } },
    { { 0xff7fffff }, { 0x7f800000 }, { 0xff7fffff } },

    /* fmod(x,-Inf) --> x	*/
    { { 0x00000000 }, { 0xff800000 }, { 0x00000000 } },
    { { 0x00000001 }, { 0xff800000 }, { 0x00000001 } },
    { { 0x00000100 }, { 0xff800000 }, { 0x00000100 } },
    { { 0x00010000 }, { 0xff800000 }, { 0x00010000 } },
    { { 0x007fffff }, { 0xff800000 }, { 0x007fffff } },
    { { 0x00800000 }, { 0xff800000 }, { 0x00800000 } },
    { { 0x7f7fffff }, { 0xff800000 }, { 0x7f7fffff } },

    { { 0x80000000 }, { 0xff800000 }, { 0x80000000 } },
    { { 0x80000001 }, { 0xff800000 }, { 0x80000001 } },
    { { 0x80000100 }, { 0xff800000 }, { 0x80000100 } },
    { { 0x80010000 }, { 0xff800000 }, { 0x80010000 } },
    { { 0x807fffff }, { 0xff800000 }, { 0x807fffff } },
    { { 0x80800000 }, { 0xff800000 }, { 0x80800000 } },
    { { 0xff7fffff }, { 0xff800000 }, { 0xff7fffff } },
    
    /* signs	*/
    { { .fl=  5 }, { .fl=  3 }, { .fl=  2 } },
    { { .fl=  5 }, { .fl= -3 }, { .fl=  2 } },
    { { .fl= -5 }, { .fl=  3 }, { .fl= -2 } },
    { { .fl= -5 }, { .fl= -3 }, { .fl= -2 } },

    /* The smallest y	*/
    { { 0x00000001 }, { 0x00000001 }, { .fl=  0.0 } },
    { { 0x007fffff }, { 0x00000001 }, { .fl=  0.0 } },
    { { 0x00800000 }, { 0x00000001 }, { .fl=  0.0 } },
    { { 0x7f7fffff }, { 0x00000001 }, { .fl=  0.0 } },
    
    /* Subnormals, all shift values	*/
    { { 0x00000001 }, { 0x00000001 }, { 0x00000000 } },
    { { 0x00000002 }, { 0x00000001 }, { 0x00000000 } },
    { { 0x00000004 }, { 0x00000003 }, { 0x00000001 } },
    { { 0x00000008 }, { 0x00000007 }, { 0x00000001 } },
    { { 0x00000010 }, { 0x0000000f }, { 0x00000001 } },
    { { 0x00000020 }, { 0x0000001f }, { 0x00000001 } },
    { { 0x00000040 }, { 0x0000003f }, { 0x00000001 } },
    { { 0x00000080 }, { 0x0000007f }, { 0x00000001 } },
    { { 0x00000100 }, { 0x000000ff }, { 0x00000001 } },
    { { 0x00000200 }, { 0x000001ff }, { 0x00000001 } },
    { { 0x00000400 }, { 0x000003ff }, { 0x00000001 } },
    { { 0x00000800 }, { 0x000007ff }, { 0x00000001 } },
    { { 0x00001000 }, { 0x00000fff }, { 0x00000001 } },
    { { 0x00002000 }, { 0x00001fff }, { 0x00000001 } },
    { { 0x00004000 }, { 0x00003fff }, { 0x00000001 } },
    { { 0x00008000 }, { 0x00007fff }, { 0x00000001 } },
    { { 0x00010000 }, { 0x0000ffff }, { 0x00000001 } },
    { { 0x00020000 }, { 0x0001ffff }, { 0x00000001 } },
    { { 0x00040000 }, { 0x0003ffff }, { 0x00000001 } },
    { { 0x00080000 }, { 0x0007ffff }, { 0x00000001 } },
    { { 0x00100000 }, { 0x000fffff }, { 0x00000001 } },
    { { 0x00200000 }, { 0x001fffff }, { 0x00000001 } },
    { { 0x00400000 }, { 0x003fffff }, { 0x00000001 } },

    { { 0x00800000 }, { 0x007fffff }, { 0x00000001 } },
    { { 0x00800001 }, { 0x007fffff }, { 0x00000002 } },
    { { 0x00800001 }, { 0x00800000 }, { 0x00000001 } },
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
	v.fl = fmod (x.fl, y.fl);
	/* Comparison is integer to verify the zero sign.	*/
	if (v.lo != z.lo)
	    x_exit (i+1);
    }
    return 0;
}
