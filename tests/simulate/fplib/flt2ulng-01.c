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

/* Test of conversion float --> unsigned long.
   $Id$
 */
#include <stdio.h>
#include <stdlib.h>
#include "progmem.h"

union lofl_u {
    long lo;
    float fl;
};

volatile unsigned long v = 1;

PROGMEM const struct {		/* Table of test cases.	*/
    union lofl_u x;
    unsigned long z;
} t[] = {

    /* 0.0	*/
    { { 0x00000000 }, 0 },
    { { 0x80000000 }, 0 },

    /* too small	*/
    { { 0x00000001 }, 0 },
    { { 0x007fffff }, 0 },
    { { 0x00800000 }, 0 },
    { { 0x3f7fffff }, 0 },
    { { 0x80000001 }, 0 },
    { { 0x807fffff }, 0 },
    { { 0x80800000 }, 0 },
    { { 0xbf7fffff }, 0 },
    
    /* all shift values	*/
    { { .fl = 0x1p00 },	0x00000001 },
    { { .fl = 0x1p01 },	0x00000002 },
    { { .fl = 0x1p02 },	0x00000004 },
    { { .fl = 0x1p03 },	0x00000008 },
    { { .fl = 0x1p04 },	0x00000010 },
    { { .fl = 0x1p05 },	0x00000020 },
    { { .fl = 0x1p06 },	0x00000040 },
    { { .fl = 0x1p07 },	0x00000080 },
    { { .fl = 0x1p08 },	0x00000100 },
    { { .fl = 0x1p09 },	0x00000200 },
    { { .fl = 0x1p10 },	0x00000400 },
    { { .fl = 0x1p11 },	0x00000800 },
    { { .fl = 0x1p12 },	0x00001000 },
    { { .fl = 0x1p13 },	0x00002000 },
    { { .fl = 0x1p14 },	0x00004000 },
    { { .fl = 0x1p15 },	0x00008000 },
    { { .fl = 0x1p16 },	0x00010000 },
    { { .fl = 0x1p17 },	0x00020000 },
    { { .fl = 0x1p18 },	0x00040000 },
    { { .fl = 0x1p19 },	0x00080000 },
    { { .fl = 0x1p20 },	0x00100000 },
    { { .fl = 0x1p21 },	0x00200000 },
    { { .fl = 0x1p22 },	0x00400000 },
    { { .fl = 0x1p23 },	0x00800000 },
    { { .fl = 0x1p24 },	0x01000000 },
    { { .fl = 0x1p25 },	0x02000000 },
    { { .fl = 0x1p26 },	0x04000000 },
    { { .fl = 0x1p27 },	0x08000000 },
    { { .fl = 0x1p28 },	0x10000000 },
    { { .fl = 0x1p29 },	0x20000000 },
    { { .fl = 0x1p30 },	0x40000000 },
    { { .fl = 0x1p31 },	0x80000000 },
    
    /* max value	*/
    { { .fl = 0x1.fffffep+31 }, 0xffffff00 },
    
    /* rounding (trunc to zero)	*/
    { { 0x3f7fffff }, 0 },
    { { 0x3f800000 }, 1 },
    { { 0x3fffffff }, 1 },
    { { 0x40000000 }, 2 },
    { { 0x403fffff }, 2 },
    { { 0x40400000 }, 3 },
    { { 0x407fffff }, 3 },
    { { .fl = 0x1.000000p+22 }, 0x00400000 },
    { { .fl = 0x1.000002p+22 }, 0x00400000 },

    /* This realization permits negative input, like GCC/x86.	*/
    { { .fl = -0.5 },	0 },
    { { .fl = -1 },     0xffffffff },
    { { .fl = -2 },     0xfffffffe },
    { { .fl = -0x0.7fffffp+32 }, 0x80000100 },
    { { .fl = -0x0.800000p+32 }, 0x80000000 },
    { { .fl = -0x0.800001p+32 }, 0x7fffff00 },
    { { .fl = -0x0.fffffep+32 }, 0x00000200 },
    { { .fl = -0x0.ffffffp+32 }, 0x00000100 },
    { { .fl = -0x0.800000p+33 }, 0 },		/* overflow	*/

    /* Very big numbers (positive and negative).	*/
    { { .fl = 0x0.800000p+56 }, 0 },
    { { .fl = 0x0.ffffffp+56 }, 0 },
    { { .fl = 0x0.800000p+57 }, 0 },
    { { .fl = 0x0.ffffffp+57 }, 0 },
    { { 0x7f000000 },           0 },
    { { 0x7f7fffff },           0 },
    { { .fl = -0x0.800000p+56 }, 0 },
    { { .fl = -0x0.ffffffp+56 }, 0 },
    { { .fl = -0x0.800000p+57 }, 0 },
    { { .fl = -0x0.ffffffp+57 }, 0 },
    { { 0xff000000 },            0 },
    { { 0xff7fffff },            0 },

    /* Inf	*/
    { { 0x7f800000 }, 0 },
    { { 0xff800000 }, 0 },
    
    /* NaN	*/
    { { 0x7f800001 }, 0 },
    { { 0x7fc00000 }, 0 },
    { { 0x7fffffff }, 0 },
    { { 0xff800001 }, 0 },
    { { 0xffc00000 }, 0 },
    { { 0xffffffff }, 0 },
    
#ifdef	__AVR__
    /* Unlike to GCC/x86 this realization does not shifts value
       in overflow case. So with not too big numbers the results
       are different.	*/

    /* Positive overflow	*/
    { { .fl= 0x0.800000p+33 }, 0 },
    { { .fl= 0x0.800001p+33 }, 0 },
    { { .fl= 0x0.ffffffp+33 }, 0 },
    { { .fl= 0x0.800000p+34 }, 0 },
    { { .fl= 0x0.ffffffp+34 }, 0 },
    { { .fl= 0x0.800000p+55 }, 0 },
    { { .fl= 0x0.ffffffp+55 }, 0 },

    /* Negative overflow	*/
    { { .fl= -0x0.800000p+33 }, 0 },	/* no overflow	*/
    { { .fl= -0x0.800001p+33 }, 0 },
    { { .fl= -0x0.ffffffp+33 }, 0 },
    { { .fl= -0x0.800000p+34 }, 0 },
    { { .fl= -0x0.ffffffp+34 }, 0 },
    { { .fl= -0x0.800000p+55 }, 0 },
    { { .fl= -0x0.ffffffp+55 }, 0 },
#endif
};

void x_exit (int index)
{
#ifndef	__AVR__
    fprintf (stderr, "t[%d]:  %lu (%#lx)\n", index - 1, v, v);
#endif
    exit (index ? index : -1);
}

int main ()
{
    union lofl_u x;
    unsigned long z;
    int i;
    
    for (i = 0; i < (int) (sizeof(t) / sizeof(t[0])); i++) {
	x.lo = pgm_read_dword (& t[i].x);
	z    = pgm_read_dword (& t[i].z);
	v = x.fl;
	if (v != z)
	    x_exit (i+1);
    }
    return 0;
}
