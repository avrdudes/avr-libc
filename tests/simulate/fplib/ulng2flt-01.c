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

/* Test of conversion: unsigned long --> float
   $Id$
 */
#include <stdio.h>
#include <stdlib.h>
#include "progmem.h"

union lofl_u {
    long lo;
    float fl;
};

volatile union lofl_u v = { 1 };

PROGMEM const struct {		/* Table of test cases:  x, (float)x	*/
    unsigned long x;
    union lofl_u z;
} t[] = {

    { 0, { .fl = 0.0 } },
    { 10,	  { .fl = 1e+1 } },
    { 100,	  { .fl = 1e+2 } },
    { 1000,	  { .fl = 1e+3 } },
    { 10000,	  { .fl = 1e+4 } },
    { 100000,	  { .fl = 1e+5 } },
    { 1000000,	  { .fl = 1e+6 } },
    { 10000000,	  { .fl = 1e+7 } },
    { 100000000,  { .fl = 1e+8 } },
    { 1000000000, { .fl = 1e+9 } },
    { 12,	  { .fl = 1.2e+1 } },
    { 123,	  { .fl = 1.23e+2 } },
    { 1234,	  { .fl = 1.234e+3 } },
    { 12345,	  { .fl = 1.2345e+4 } },
    { 123456,	  { .fl = 1.23456e+5 } },
    { 1234567,	  { .fl = 1.234567e+6 } },
    { 12345678,	  { .fl = 1.2345678e+7 } },
    { 123456780,  { .fl = 1.2345678e+8 } },
    { 1234567800, { .fl = 1.2345678e+9 } },
    
    /* max value	*/
    { 0xffffffff, { .fl = 0x1p+32 } },

    /* all possible shifts	*/    
    { 0x00000001, { .fl = 0x1p+00 } },
    { 0x00000002, { .fl = 0x1p+01 } },
    { 0x00000004, { .fl = 0x1p+02 } },
    { 0x00000008, { .fl = 0x1p+03 } },
    { 0x00000010, { .fl = 0x1p+04 } },
    { 0x00000020, { .fl = 0x1p+05 } },
    { 0x00000040, { .fl = 0x1p+06 } },
    { 0x00000080, { .fl = 0x1p+07 } },
    { 0x00000100, { .fl = 0x1p+08 } },
    { 0x00000200, { .fl = 0x1p+09 } },
    { 0x00000400, { .fl = 0x1p+10 } },
    { 0x00000800, { .fl = 0x1p+11 } },
    { 0x00001000, { .fl = 0x1p+12 } },
    { 0x00002000, { .fl = 0x1p+13 } },
    { 0x00004000, { .fl = 0x1p+14 } },
    { 0x00008000, { .fl = 0x1p+15 } },
    { 0x00010000, { .fl = 0x1p+16 } },
    { 0x00020000, { .fl = 0x1p+17 } },
    { 0x00040000, { .fl = 0x1p+18 } },
    { 0x00080000, { .fl = 0x1p+19 } },
    { 0x00100000, { .fl = 0x1p+20 } },
    { 0x00200000, { .fl = 0x1p+21 } },
    { 0x00400000, { .fl = 0x1p+22 } },
    { 0x00800000, { .fl = 0x1p+23 } },
    { 0x01000000, { .fl = 0x1p+24 } },
    { 0x02000000, { .fl = 0x1p+25 } },
    { 0x04000000, { .fl = 0x1p+26 } },
    { 0x08000000, { .fl = 0x1p+27 } },
    { 0x10000000, { .fl = 0x1p+28 } },
    { 0x20000000, { .fl = 0x1p+29 } },
    { 0x40000000, { .fl = 0x1p+30 } },
    { 0x80000000, { .fl = 0x1p+31 } },
    
    /* bytes order	*/
    { 0x00000102, { .fl = 0x102p+00 } },
    { 0x00010203, { .fl = 0x10203p+00 } },
    { 0x01020304, { .fl = 0x1020304p+00 } },

    /* rounding	*/
    { 0x01000000, { .fl = 0x0.800000p+25 } },
    { 0x01000001, { .fl = 0x0.800000p+25 } },
    { 0x01000002, { .fl = 0x0.800001p+25 } },
    { 0x01000003, { .fl = 0x0.800002p+25 } },
    { 0x01000004, { .fl = 0x0.800002p+25 } },
    { 0x01000005, { .fl = 0x0.800002p+25 } },
    { 0x01000006, { .fl = 0x0.800003p+25 } },
    { 0x01000007, { .fl = 0x0.800004p+25 } },

    { 0x80000000, { .fl = 0x0.800000p+32 } },
    { 0x80000001, { .fl = 0x0.800000p+32 } },
    { 0x8000007f, { .fl = 0x0.800000p+32 } },
    { 0x80000080, { .fl = 0x0.800000p+32 } },
    { 0x80000081, { .fl = 0x0.800001p+32 } },
    { 0x800000ff, { .fl = 0x0.800001p+32 } },
    { 0x80000100, { .fl = 0x0.800001p+32 } },
    { 0x80000101, { .fl = 0x0.800001p+32 } },
    { 0x8000017f, { .fl = 0x0.800001p+32 } },
    { 0x80000180, { .fl = 0x0.800002p+32 } },
    { 0x80000181, { .fl = 0x0.800002p+32 } },
    { 0x800001ff, { .fl = 0x0.800002p+32 } },

    /* smart rounding in case of 0.5 (to even)	*/
    { 0x01000001, { .fl = 0x0.800000p+25 } },
    { 0x01000003, { .fl = 0x0.800002p+25 } },
    { 0x01000005, { .fl = 0x0.800002p+25 } },
    { 0x01000007, { .fl = 0x0.800004p+25 } },
    { 0x01000009, { .fl = 0x0.800004p+25 } },
    { 0x0100000b, { .fl = 0x0.800006p+25 } },
    { 0x0100000d, { .fl = 0x0.800006p+25 } },
    { 0x0100000f, { .fl = 0x0.800008p+25 } },
    { 0x01000011, { .fl = 0x0.800008p+25 } },
    { 0x01000013, { .fl = 0x0.80000ap+25 } },
    { 0x01000015, { .fl = 0x0.80000ap+25 } },
    { 0x01000017, { .fl = 0x0.80000cp+25 } },
    { 0x01000019, { .fl = 0x0.80000cp+25 } },
    { 0x0100001b, { .fl = 0x0.80000ep+25 } },
    { 0x0100001d, { .fl = 0x0.80000ep+25 } },
    { 0x0100001f, { .fl = 0x0.800010p+25 } },

    { 0x7ffffc40, { .fl = 0x0.fffff8p+31 } },
    { 0x7ffffcc0, { .fl = 0x0.fffffap+31 } },
    { 0x7ffffd40, { .fl = 0x0.fffffap+31 } },
    { 0x7ffffdc0, { .fl = 0x0.fffffcp+31 } },
    { 0x7ffffe40, { .fl = 0x0.fffffcp+31 } },
    { 0x7ffffec0, { .fl = 0x0.fffffep+31 } },
    { 0x7fffff40, { .fl = 0x0.fffffep+31 } },
    { 0x7fffffc0, { .fl = 0x1.000000p+31 } },
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
    unsigned long x;
    union lofl_u z;
    int i;
    
    for (i = 0; i < (int) (sizeof(t) / sizeof(t[0])); i++) {
	x    = pgm_read_dword (& t[i].x);
	z.lo = pgm_read_dword (& t[i].z);
#ifdef	__AVR__
	/* Force library's convertion function usage. This is needed for
	   GCC before 4.2	*/
	extern double __floatunsisf (unsigned long);
	v.fl = __floatunsisf (x);
#else
	v.fl = x;
#endif
	if (v.lo != z.lo)
	    x_exit (i+1);
    }
    return 0;
}
