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

/* Test of conversion: signed long long --> float
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
    long long x;
    union lofl_u z;
} t[] = {

    { 0, { .fl = 0.0 } },
    { 1, { .fl = 1.0 } },
    { 10, { .fl = 1e+1 } },
    { 100, { .fl = 1e+2 } },
    { 1000, { .fl = 1e+3 } },
    { 10000, { .fl = 1e+4 } },
    { 100000, { .fl = 1e+5 } },
    { 1000000, { .fl = 1e+6 } },
    { 10000000, { .fl = 1e+7 } },
    { 100000000, { .fl = 1e+8 } },
    { 1000000000, { .fl = 1e+9 } },
    { 10000000000LL, { .fl = 1e+10 } },
    { 100000000000LL, { .fl = 1e+11 } },
    { 1000000000000LL, { .fl = 1e+12 } },
    { 10000000000000LL, { .fl = 1e+13 } },
    { 100000000000000LL, { .fl = 1e+14 } },
    { 1000000000000000LL, { .fl = 1e+15 } },
    { 10000000000000000LL, { .fl = 1e+16 } },
    { 100000000000000000LL, { .fl = 1e+17 } },
    { 1000000000000000000LL, { .fl = 1e+18 } },

    { 12, { .fl = 1.2e+1 } },
    { 123, { .fl = 1.23e+2 } },
    { 1234, { .fl = 1.234e+3 } },
    { 12345, { .fl = 1.2345e+4 } },
    { 123456, { .fl = 1.23456e+5 } },
    { 1234567, { .fl = 1.234567e+6 } },
    { 12345678, { .fl = 1.2345678e+7 } },
    { 123456780, { .fl = 1.2345678e+8 } },
    { 1234567800, { .fl = 1.2345678e+9 } },
    { 12345678000LL, { .fl = 1.2345678e+10 } },
    { 123456780000LL, { .fl = 1.2345678e+11 } },
    { 1234567800000LL, { .fl = 1.2345678e+12 } },
    { 12345678000000LL, { .fl = 1.2345678e+13 } },
    { 123456780000000LL, { .fl = 1.2345678e+14 } },
    { 1234567800000000LL, { .fl = 1.2345678e+15 } },
    { 12345678000000000LL, { .fl = 1.2345678e+16 } },
    { 123456780000000000LL, { .fl = 1.2345678e+17 } },
    { 1234567800000000000LL, { .fl = 1.2345678e+18 } },
    
    /* max positive	*/
    { 0x7fffffffffffffffLL, { .fl = 0x1p+63 } },
    
    /* some negative values	*/
    { -1, { .fl = -1.0 } },
    { -2, { .fl = -2.0 } },
    { -10, { .fl = -10.0 } },
    { -12345678, { .fl = -1.2345678e+7 } },
    { -1234567800000000000LL, { .fl = -1.2345678e+18 } },
    { -0x7fffffffffffffffLL, { .fl = -0x1p+63 } },

    /* check long long negation	*/
    { 0xff00000000000000LL, { .fl = -0x1p+56 } },
    { 0xffff000000000000LL, { .fl = -0x1p+48 } },
    { 0xffffff0000000000LL, { .fl = -0x1p+40 } },
    { 0xffffffff00000000LL, { .fl = -0x1p+32 } },
    { 0xffffffffff000000LL, { .fl = -0x1p+24 } },
    { 0xffffffffffff0000LL, { .fl = -0x1p+16 } },
    { 0xffffffffffffff00LL, { .fl = -0x1p+8 } },

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
    { 0x0000000100000000LL, { .fl = 0x1p+32 } },
    { 0x0000000200000000LL, { .fl = 0x1p+33 } },
    { 0x0000000400000000LL, { .fl = 0x1p+34 } },
    { 0x0000000800000000LL, { .fl = 0x1p+35 } },
    { 0x0000001000000000LL, { .fl = 0x1p+36 } },
    { 0x0000002000000000LL, { .fl = 0x1p+37 } },
    { 0x0000004000000000LL, { .fl = 0x1p+38 } },
    { 0x0000008000000000LL, { .fl = 0x1p+39 } },
    { 0x0000010000000000LL, { .fl = 0x1p+40 } },
    { 0x0000020000000000LL, { .fl = 0x1p+41 } },
    { 0x0000040000000000LL, { .fl = 0x1p+42 } },
    { 0x0000080000000000LL, { .fl = 0x1p+43 } },
    { 0x0000100000000000LL, { .fl = 0x1p+44 } },
    { 0x0000200000000000LL, { .fl = 0x1p+45 } },
    { 0x0000400000000000LL, { .fl = 0x1p+46 } },
    { 0x0000800000000000LL, { .fl = 0x1p+47 } },
    { 0x0001000000000000LL, { .fl = 0x1p+48 } },
    { 0x0002000000000000LL, { .fl = 0x1p+49 } },
    { 0x0004000000000000LL, { .fl = 0x1p+50 } },
    { 0x0008000000000000LL, { .fl = 0x1p+51 } },
    { 0x0010000000000000LL, { .fl = 0x1p+52 } },
    { 0x0020000000000000LL, { .fl = 0x1p+53 } },
    { 0x0040000000000000LL, { .fl = 0x1p+54 } },
    { 0x0080000000000000LL, { .fl = 0x1p+55 } },
    { 0x0100000000000000LL, { .fl = 0x1p+56 } },
    { 0x0200000000000000LL, { .fl = 0x1p+57 } },
    { 0x0400000000000000LL, { .fl = 0x1p+58 } },
    { 0x0800000000000000LL, { .fl = 0x1p+59 } },
    { 0x1000000000000000LL, { .fl = 0x1p+60 } },
    { 0x2000000000000000LL, { .fl = 0x1p+61 } },
    { 0x4000000000000000LL, { .fl = 0x1p+62 } },
    { 0x8000000000000000LL, { .fl= -0x1p+63 } },
    
    /* bytes order	*/
    { 0x0000000000000102LL, { .fl = 0x102p+00 } },
    { 0x0000000000010203LL, { .fl = 0x10203p+00 } },
    { 0x0000000001020304LL, { .fl = 0x1020304p+00 } },
    { 0x0000000102030400LL, { .fl = 0x1020304p+08 } },
    { 0x0000010203040000LL, { .fl = 0x1020304p+16 } },
    { 0x0001020304000000LL, { .fl = 0x1020304p+24 } },
    { 0x0102030400000000LL, { .fl = 0x1020304p+32 } },

    /* rounding (shift is to left)	*/
    { 0x01000000, { .fl = 0x0.800000p+25 } },
    { 0x01000001, { .fl = 0x0.800000p+25 } },
    { 0x01000002, { .fl = 0x0.800001p+25 } },
    { 0x01000003, { .fl = 0x0.800002p+25 } },
    { 0x01000004, { .fl = 0x0.800002p+25 } },
    { 0x01000005, { .fl = 0x0.800002p+25 } },
    { 0x01000006, { .fl = 0x0.800003p+25 } },
    { 0x01000007, { .fl = 0x0.800004p+25 } },

    { 0x0200000000LL, { .fl = 0x0.800000p+34 } },
    { 0x0200000200LL, { .fl = 0x0.800000p+34 } },
    { 0x0200000400LL, { .fl = 0x0.800001p+34 } },
    { 0x0200000600LL, { .fl = 0x0.800002p+34 } },
    { 0x0200000800LL, { .fl = 0x0.800002p+34 } },
    { 0x0200000a00LL, { .fl = 0x0.800002p+34 } },
    { 0x0200000c00LL, { .fl = 0x0.800003p+34 } },
    { 0x0200000e00LL, { .fl = 0x0.800004p+34 } },

    { 0x040000000000LL, { .fl = 0x0.800000p+43 } },
    { 0x040000040000LL, { .fl = 0x0.800000p+43 } },
    { 0x040000080000LL, { .fl = 0x0.800001p+43 } },
    { 0x0400000c0000LL, { .fl = 0x0.800002p+43 } },
    { 0x040000100000LL, { .fl = 0x0.800002p+43 } },
    { 0x040000140000LL, { .fl = 0x0.800002p+43 } },
    { 0x040000180000LL, { .fl = 0x0.800003p+43 } },
    { 0x0400001c0000LL, { .fl = 0x0.800004p+43 } },

    { 0x08000000000000LL, { .fl = 0x0.800000p+52 } },
    { 0x08000008000000LL, { .fl = 0x0.800000p+52 } },
    { 0x08000010000000LL, { .fl = 0x0.800001p+52 } },
    { 0x08000018000000LL, { .fl = 0x0.800002p+52 } },
    { 0x08000020000000LL, { .fl = 0x0.800002p+52 } },
    { 0x08000028000000LL, { .fl = 0x0.800002p+52 } },
    { 0x08000030000000LL, { .fl = 0x0.800003p+52 } },
    { 0x08000038000000LL, { .fl = 0x0.800004p+52 } },

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

    /* rounding (shift is to right)	*/
    { 0x0800000000000000LL, { .fl = 0x0.800000p+60 } },
    { 0x0800000010000000LL, { .fl = 0x0.800000p+60 } },
    { 0x08000007f0000000LL, { .fl = 0x0.800000p+60 } },
    { 0x0800000800000000LL, { .fl = 0x0.800000p+60 } },
    { 0x0800000810000000LL, { .fl = 0x0.800001p+60 } },
    { 0x0800000ff0000000LL, { .fl = 0x0.800001p+60 } },
    { 0x0800001000000000LL, { .fl = 0x0.800001p+60 } },
    { 0x0800001010000000LL, { .fl = 0x0.800001p+60 } },
    { 0x08000017f0000000LL, { .fl = 0x0.800001p+60 } },
    { 0x0800001800000000LL, { .fl = 0x0.800002p+60 } },
    { 0x0800001810000000LL, { .fl = 0x0.800002p+60 } },
    { 0x0800001ff0000000LL, { .fl = 0x0.800002p+60 } },

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
    
    /* LSB bits in rounding (shift to left)	*/
    { 0x01000000000000LL, { .fl = 0x0.800000p+49 } },
    { 0x01000001000000LL, { .fl = 0x0.800000p+49 } },
    { 0x01000001000001LL, { .fl = 0x0.800001p+49 } },
    { 0x01000001000100LL, { .fl = 0x0.800001p+49 } },
    { 0x01000001010000LL, { .fl = 0x0.800001p+49 } },
    { 0x01000002000000LL, { .fl = 0x0.800001p+49 } },
    { 0x01000002000001LL, { .fl = 0x0.800001p+49 } },

    { 0x01000002ffffffLL, { .fl = 0x0.800001p+49 } },
    { 0x01000003000000LL, { .fl = 0x0.800002p+49 } },

    /* LSB bits in rounding (shift to right)	*/
    { 0x0100000000000000LL, { .fl = 0x0.800000p+57 } },
    { 0x0100000100000000LL, { .fl = 0x0.800000p+57 } },
    { 0x0100000100000001LL, { .fl = 0x0.800001p+57 } },
    { 0x0100000100000100LL, { .fl = 0x0.800001p+57 } },
    { 0x0100000100010000LL, { .fl = 0x0.800001p+57 } },
    { 0x0100000101000000LL, { .fl = 0x0.800001p+57 } },
    { 0x0100000200000000LL, { .fl = 0x0.800001p+57 } },
    { 0x0100000200000001LL, { .fl = 0x0.800001p+57 } },

    { 0x01000002ffffffffLL, { .fl = 0x0.800001p+57 } },
    { 0x0100000300000000LL, { .fl = 0x0.800002p+57 } },
};

void x_exit (int index)
{
#ifndef	__AVR__
    fprintf (stderr, "t[%d] (%#llx):  %#lx (%g)\n",
             index - 1, t[index-1].x, v.lo, v.fl);
#endif
    exit (index ? index : -1);
}

int main ()
{
    long long x;
    union lofl_u z;
    int i;
    
    for (i = 0; i < (int) (sizeof(t) / sizeof(t[0])); i++) {
	x = pgm_read_qword (& t[i].x);
	z.lo = pgm_read_dword (& t[i].z);
	v.fl = x;
	if (v.lo != z.lo)
	    x_exit (i+1);
    }
    return 0;
}
