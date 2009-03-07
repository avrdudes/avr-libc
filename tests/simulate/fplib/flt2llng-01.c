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

/* Test of conversion float --> signed long long.
   $Id$
 */
#include <stdio.h>
#include <stdlib.h>
#include "progmem.h"

union lofl_u {
    long lo;
    float fl;
};

volatile long long v = 1;

PROGMEM const struct {		/* Table of test cases.	*/
    union lofl_u x;
    long long z;
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

    /* all shift values	*/
    { { .fl = 0x1p00 },	0x0000000000000001LL },
    { { .fl = 0x1p01 },	0x0000000000000002LL },
    { { .fl = 0x1p02 },	0x0000000000000004LL },
    { { .fl = 0x1p03 },	0x0000000000000008LL },
    { { .fl = 0x1p04 },	0x0000000000000010LL },
    { { .fl = 0x1p05 },	0x0000000000000020LL },
    { { .fl = 0x1p06 },	0x0000000000000040LL },
    { { .fl = 0x1p07 },	0x0000000000000080LL },
    { { .fl = 0x1p08 },	0x0000000000000100LL },
    { { .fl = 0x1p09 },	0x0000000000000200LL },
    { { .fl = 0x1p10 },	0x0000000000000400LL },
    { { .fl = 0x1p11 },	0x0000000000000800LL },
    { { .fl = 0x1p12 },	0x0000000000001000LL },
    { { .fl = 0x1p13 },	0x0000000000002000LL },
    { { .fl = 0x1p14 },	0x0000000000004000LL },
    { { .fl = 0x1p15 },	0x0000000000008000LL },
    { { .fl = 0x1p16 },	0x0000000000010000LL },
    { { .fl = 0x1p17 },	0x0000000000020000LL },
    { { .fl = 0x1p18 },	0x0000000000040000LL },
    { { .fl = 0x1p19 },	0x0000000000080000LL },
    { { .fl = 0x1p20 },	0x0000000000100000LL },
    { { .fl = 0x1p21 },	0x0000000000200000LL },
    { { .fl = 0x1p22 },	0x0000000000400000LL },
    { { .fl = 0x1p23 },	0x0000000000800000LL },
    { { .fl = 0x1p24 },	0x0000000001000000LL },
    { { .fl = 0x1p25 },	0x0000000002000000LL },
    { { .fl = 0x1p26 },	0x0000000004000000LL },
    { { .fl = 0x1p27 },	0x0000000008000000LL },
    { { .fl = 0x1p28 },	0x0000000010000000LL },
    { { .fl = 0x1p29 },	0x0000000020000000LL },
    { { .fl = 0x1p30 },	0x0000000040000000LL },
    { { .fl = 0x1p31 },	0x0000000080000000LL },
    { { .fl = 0x1p32 },	0x0000000100000000LL },
    { { .fl = 0x1p33 },	0x0000000200000000LL },
    { { .fl = 0x1p34 },	0x0000000400000000LL },
    { { .fl = 0x1p35 },	0x0000000800000000LL },
    { { .fl = 0x1p36 },	0x0000001000000000LL },
    { { .fl = 0x1p37 },	0x0000002000000000LL },
    { { .fl = 0x1p38 },	0x0000004000000000LL },
    { { .fl = 0x1p39 },	0x0000008000000000LL },
    { { .fl = 0x1p40 },	0x0000010000000000LL },
    { { .fl = 0x1p41 },	0x0000020000000000LL },
    { { .fl = 0x1p42 },	0x0000040000000000LL },
    { { .fl = 0x1p43 },	0x0000080000000000LL },
    { { .fl = 0x1p44 },	0x0000100000000000LL },
    { { .fl = 0x1p45 },	0x0000200000000000LL },
    { { .fl = 0x1p46 },	0x0000400000000000LL },
    { { .fl = 0x1p47 },	0x0000800000000000LL },
    { { .fl = 0x1p48 },	0x0001000000000000LL },
    { { .fl = 0x1p49 },	0x0002000000000000LL },
    { { .fl = 0x1p50 },	0x0004000000000000LL },
    { { .fl = 0x1p51 },	0x0008000000000000LL },
    { { .fl = 0x1p52 },	0x0010000000000000LL },
    { { .fl = 0x1p53 },	0x0020000000000000LL },
    { { .fl = 0x1p54 },	0x0040000000000000LL },
    { { .fl = 0x1p55 },	0x0080000000000000LL },
    { { .fl = 0x1p56 },	0x0100000000000000LL },
    { { .fl = 0x1p57 },	0x0200000000000000LL },
    { { .fl = 0x1p58 },	0x0400000000000000LL },
    { { .fl = 0x1p59 },	0x0800000000000000LL },
    { { .fl = 0x1p60 },	0x1000000000000000LL },
    { { .fl = 0x1p61 },	0x2000000000000000LL },
    { { .fl = 0x1p62 },	0x4000000000000000LL },
    { { .fl = 0x1p63 }, 0x8000000000000000LL },

    /* negative	*/
    { { .fl = -0x1p00 },	-1 },
    { { .fl = -0x3p00 },	-0x0000000000000003LL },
    { { .fl = -0xffp00 },	-0x00000000000000ffLL },
    { { .fl = -0x100p00 },	-0x0000000000000100LL },
    { { .fl = -0xffffp00 },	-0x000000000000ffffLL },
    { { .fl = -0x10000p00 },	-0x0000000000010000LL },
    { { .fl = -0xffffffp00 },	-0x0000000000ffffffLL },
    { { .fl = -0xffffffp07 },	-0x000000007fffff80LL },
    { { .fl = -0x1000000p07 },	-0x0000000080000000LL },
    { { .fl = -0xffffffp08 },   -0x00000000ffffff00LL },
    { { .fl = -0x1000000p08 },  -0x0000000100000000LL },
    { { .fl = -0xffffffp39 },   -0x7fffff8000000000LL },
    
    /* max values	*/
    { { .fl =  0x0.fffffep+63 },  0x7fffff0000000000LL },
    { { .fl =  0x0.ffffffp+63 },  0x7fffff8000000000LL },
    { { .fl = -0x0.fffffep+63 }, -0x7fffff0000000000LL },
    { { .fl = -0x0.ffffffp+63 }, -0x7fffff8000000000LL },
    { { .fl = -0x1.000000p+63 },  0x8000000000000000LL },
    
    /* Overflow	*/
    { { .fl =  0x1.000000p+63 }, 0x8000000000000000LL },
    { { .fl = -0x1.000002p+63 }, 0x8000000000000000LL },
    { { 0x7f7fffff },		 0x8000000000000000LL },
    { { 0xff7fffff },		 0x8000000000000000LL },

    /* Inf	*/
    { { 0x7f800000 }, 0x8000000000000000LL },
    { { 0xff800000 }, 0x8000000000000000LL },
    
    /* NaN	*/
    { { 0x7f800001 }, 0x8000000000000000LL },
    { { 0x7fc00000 }, 0x8000000000000000LL },
    { { 0x7fffffff }, 0x8000000000000000LL },
    { { 0xff800001 }, 0x8000000000000000LL },
    { { 0xffc00000 }, 0x8000000000000000LL },
    { { 0xffffffff }, 0x8000000000000000LL },
};

void x_exit (int index)
{
#ifndef	__AVR__
    fprintf (stderr, "t[%d]:  %lld (%#llx)\n", index - 1, v, v);
#endif
    exit (index ? index : -1);
}

int main ()
{
    union lofl_u x;
    long long z;
    int i;
    
    for (i = 0; i < (int) (sizeof(t) / sizeof(t[0])); i++) {
	x.lo = pgm_read_dword (& t[i].x);
	z    = pgm_read_qword (& t[i].z);
	v = x.fl;	/* __fixsfdi()	*/
	if (v != z)
	    x_exit (i+1);
    }
    return 0;
}
