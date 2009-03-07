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

/* Test of round() function.
   NaN-argument is tested at another place: xxx-nan.c
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

PROGMEM const struct {		/* Table of test cases.	*/
    union lofl_u x;		/* argument	*/
    union lofl_u z;		/* round(x)	*/
} t[] = {

    /* Zero	*/
    { { .fl= +0.0 },	{ .fl= +0.0 } },
    { { .fl= -0.0 },	{ .fl= -0.0 } },

    /* Normal	*/
    { { .fl= 0.1 },		{ .fl= 0.0 } },
    { { .fl= 0.5 },		{ .fl= 1.0 } },
    { { .fl= 0.9 },		{ .fl= 1.0 } },
    { { .fl= 1.49999 },		{ .fl= 1.0 } },
    { { .fl= 1.5 },		{ .fl= 2.0 } },
    { { .fl= 1.9 },		{ .fl= 2.0 } },
    { { .fl= 2.5 },		{ .fl= 3.0 } },
    { { .fl= 1000000.5 },	{ .fl= 1000001.0 } },
    { { .fl= -0.1 },		{ .fl= -0.0 } },
    { { .fl= -0.5 },		{ .fl= -1.0 } },
    { { .fl= -0.9 },		{ .fl= -1.0 } },
    { { .fl= -1.49999 },	{ .fl= -1.0 } },
    { { .fl= -1.5 },		{ .fl= -2.0 } },
    { { .fl= -1.9 },		{ .fl= -2.0 } },
    { { .fl= -2.5 },		{ .fl= -3.0 } },
    { { .fl= -1000000.5 },	{ .fl= -1000001.0 } },

    /* Inf	*/
    { { 0x7f800000 },	{ 0x7f800000 } },
    { { 0xff800000 },	{ 0xff800000 } },
    
    /* Subnormal	*/
    { { 0x00000001 }, { 0x00000000 } },
    { { 0x00000100 }, { 0x00000000 } },
    { { 0x00010000 }, { 0x00000000 } },
    { { 0x007fffff }, { 0x00000000 } },
    { { 0x80000001 }, { .fl= -0.0 } },
    { { 0x80000100 }, { .fl= -0.0 } },
    { { 0x80010000 }, { .fl= -0.0 } },
    { { 0x807fffff }, { .fl= -0.0 } },
    
    /* Margin values (positive).	*/
    { { 0x00800000 }, { .fl= 0.0 } },		/* near 0.0	*/

    { { 0x3effffff }, { .fl= 0.0 } },
    { { 0x3f000000 }, { .fl= 1.0 } },		/* 0.5	*/
    { { 0x3f000001 }, { .fl= 1.0 } },

    { { 0x3f7fffff }, { .fl= 1.0 } },
    { { 0x3f800000 }, { .fl= 1.0 } },		/* 1.0	*/
    { { 0x3f800001 }, { .fl= 1.0 } },

    { { 0x3fbfffff }, { .fl= 1.0 } },
    { { 0x3fc00000 }, { .fl= 2.0 } },		/* 1.5	*/
    { { 0x3fc00001 }, { .fl= 2.0 } },

    { { 0x401fffff }, { .fl= 2.0 } },
    { { 0x40200000 }, { .fl= 3.0 } },		/* 2.5	*/
    { { 0x40200001 }, { .fl= 3.0 } },

    { { .fl= 0x0.fffffep+23 }, { .fl= 0x0.fffffep+23 } },
    { { .fl= 0x0.ffffffp+23 }, { .fl= 0x1.000000p+23 } },
    { { .fl= 0x1.000000p+23 }, { .fl= 0x1.000000p+23 } },

    { { 0x7f7fffff }, { 0x7f7fffff } },		/* the biggest normal */

    /* Margin values (negative).	*/
    { { 0x80800000 }, { .fl= -0.0 } },		/* near 0.0	*/

    { { 0xbeffffff }, { .fl= -0.0 } },
    { { 0xbf000000 }, { .fl= -1.0 } },		/* -0.5	*/
    { { 0xbf000001 }, { .fl= -1.0 } },

    { { 0xbf7fffff }, { .fl= -1.0 } },
    { { 0xbf800000 }, { .fl= -1.0 } },		/* -1.0	*/
    { { 0xbf800001 }, { .fl= -1.0 } },

    { { 0xbfbfffff }, { .fl= -1.0 } },
    { { 0xbfc00000 }, { .fl= -2.0 } },		/* -1.5	*/
    { { 0xbfc00001 }, { .fl= -2.0 } },

    { { 0xc01fffff }, { .fl= -2.0 } },
    { { 0xc0200000 }, { .fl= -3.0 } },		/* -2.5	*/
    { { 0xc0200001 }, { .fl= -3.0 } },

    { { .fl= -0x0.fffffep+23 }, { .fl= -0x0.fffffep+23 } },
    { { .fl= -0x0.ffffffp+23 }, { .fl= -0x1.000000p+23 } },
    { { .fl= -0x1.000000p+23 }, { .fl= -0x1.000000p+23 } },

    { { 0xff7fffff }, { 0xff7fffff } },		/* the smallest normal	*/

    /* All possible shifts	*/
    { { .fl= 0x0.ffffffp-01 }, { .fl= 0.0 } },
    { { .fl= 0x0.ffffffp+00 }, { .fl= 0x1p+00 } },
    { { .fl= 0x0.ffffffp+01 }, { .fl= 0x2p+00 } },
    { { .fl= 0x0.ffffffp+02 }, { .fl= 0x4p+00 } },
    { { .fl= 0x0.ffffffp+03 }, { .fl= 0x8p+00 } },
    { { .fl= 0x0.ffffffp+04 }, { .fl= 0x10p+00 } },
    { { .fl= 0x0.ffffffp+05 }, { .fl= 0x20p+00 } },
    { { .fl= 0x0.ffffffp+06 }, { .fl= 0x40p+00 } },
    { { .fl= 0x0.ffffffp+07 }, { .fl= 0x80p+00 } },
    { { .fl= 0x0.ffffffp+08 }, { .fl= 0x100p+00 } },
    { { .fl= 0x0.ffffffp+09 }, { .fl= 0x200p+00 } },
    { { .fl= 0x0.ffffffp+10 }, { .fl= 0x400p+00 } },
    { { .fl= 0x0.ffffffp+11 }, { .fl= 0x800p+00 } },
    { { .fl= 0x0.ffffffp+12 }, { .fl= 0x1000p+00 } },
    { { .fl= 0x0.ffffffp+13 }, { .fl= 0x2000p+00 } },
    { { .fl= 0x0.ffffffp+14 }, { .fl= 0x4000p+00 } },
    { { .fl= 0x0.ffffffp+15 }, { .fl= 0x8000p+00 } },
    { { .fl= 0x0.ffffffp+16 }, { .fl= 0x10000p+00 } },
    { { .fl= 0x0.ffffffp+17 }, { .fl= 0x20000p+00 } },
    { { .fl= 0x0.ffffffp+18 }, { .fl= 0x40000p+00 } },
    { { .fl= 0x0.ffffffp+19 }, { .fl= 0x80000p+00 } },
    { { .fl= 0x0.ffffffp+20 }, { .fl= 0x100000p+00 } },
    { { .fl= 0x0.ffffffp+21 }, { .fl= 0x200000p+00 } },
    { { .fl= 0x0.ffffffp+22 }, { .fl= 0x400000p+00 } },
    { { .fl= 0x0.ffffffp+23 }, { .fl= 0x800000p+00 } },
    { { .fl= 0x0.ffffffp+24 }, { .fl= 0xffffffp+00 } },
    { { .fl= 0x0.ffffffp+25 }, { .fl= 0xffffffp+01 } },
    { { .fl= 0x0.ffffffp+26 }, { .fl= 0xffffffp+02 } },
    { { .fl= 0x0.ffffffp+27 }, { .fl= 0xffffffp+03 } },
    { { .fl= 0x0.ffffffp+28 }, { .fl= 0xffffffp+04 } },
    { { .fl= 0x0.ffffffp+29 }, { .fl= 0xffffffp+05 } },

    /* '1' in mantissa, shift by 1.	*/
    { { .fl= 0x0.800001p+23 }, { .fl= 0x800002p-01 } },
    { { .fl= 0x0.800002p+23 }, { .fl= 0x800002p-01 } },
    { { .fl= 0x0.800080p+23 }, { .fl= 0x800080p-01 } },
    { { .fl= 0x0.800100p+23 }, { .fl= 0x800100p-01 } },
    { { .fl= 0x0.808000p+23 }, { .fl= 0x808000p-01 } },
    { { .fl= 0x0.810000p+23 }, { .fl= 0x810000p-01 } },
    { { .fl= 0x0.c00000p+23 }, { .fl= 0xc00000p-01 } },
    
    /* '0' in mantissa, shift by 1, negative.	*/
    { { .fl= -0x0.fffffep+23 }, { .fl= -0x7fffffp+00 } },
    { { .fl= -0x0.ffff7ep+23 }, { .fl= -0x7fffbfp+00 } },
    { { .fl= -0x0.fffefep+23 }, { .fl= -0x7fff7fp+00 } },
    { { .fl= -0x0.ff7ffep+23 }, { .fl= -0x7fbfffp+00 } },
    { { .fl= -0x0.fefffep+23 }, { .fl= -0x7f7fffp+00 } },
    { { .fl= -0x0.bffffep+23 }, { .fl= -0x5fffffp+00 } },
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
    union lofl_u x, z;
    int i;
    
    for (i = 0; i < (int) (sizeof(t) / sizeof(t[0])); i++) {
	x.lo = pgm_read_dword (& t[i].x);
	z.lo = pgm_read_dword (& t[i].z);
	v.fl = round (x.fl);
	/* Comparison is integer to verify the zero sign.	*/
	if (v.lo != z.lo)
	    x_exit (i+1);
    }
    return 0;
}
