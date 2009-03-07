/* Copyright (c) 2008  Dmitry Xmelkov
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

/* Test of frexp() function.
   $Id$
 */
#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include "progmem.h"

#ifndef	__AVR__
# define PRINTFLN(fmt, ...)	\
    printf ("\nLine %d: " fmt "\n", __LINE__, ##__VA_ARGS__)
# define EXIT(code)	exit ((code) < 255 ? (code) : 100 + (code) % 100)
#else
# if defined(__AVR_ATmega128__)
  /* ATmega128 has enough RAM for sprintf(), print to 0x2000 in XRAM. */
#  define PRINTFLN(fmt, ...)	\
    sprintf ((char *)0x2000, "\nLine %d: " fmt "\n", __LINE__, ##__VA_ARGS__)
# else
   /* small AVR */
#  define PRINTFLN(args...)
# endif
# define EXIT	exit
#endif

union lofl_u {
    long lo;
    float fl;
};

volatile union lofl_u vf = { 1 };
int ve = { 1 };

PROGMEM const struct {		/* Table of test cases.	*/
    union lofl_u x;	/* argument			*/
    union lofl_u f;	/* fraction part: frexp(x,*pe)	*/
    int e;		/* exponent: *pe		*/
} t[] = {

    /* zero	*/
    { { 0x00000000 }, { 0x00000000 }, 0 },
    { { 0x80000000 }, { 0x80000000 }, 0 },

    /* subnormal	*/
    { { 0x00000001 }, { .fl = 0.5 },	-148 },
    { { 0x00000003 }, { .fl = 0.75 },	-147 },
    { { 0x00000100 }, { .fl = 0.5 },    -140 },
    { { 0x00010000 }, { .fl = 0.5 },    -132 },
    { { 0x007fffff }, { .fl = 0x0.fffffep+00 }, -126 },

    { { 0x80000001 }, { .fl = -0.5 },	-148 },
    { { 0x80000003 }, { .fl = -0.75 },	-147 },
    { { 0x80000100 }, { .fl = -0.5 },   -140 },
    { { 0x80010000 }, { .fl = -0.5 },   -132 },
    { { 0x807fffff }, { .fl = -0x0.fffffep+00 }, -126 },
    
    /* integral normal	*/
    { { .fl = 0x000001 }, { .fl = 0.5 }, 1 },
    { { .fl = 0x400000 }, { .fl = 0.5 }, 23 },
    { { .fl = 0x7fffff }, { .fl = 0x0.fffffep+00 }, 23 },

    { { .fl = -0x000001 }, { .fl = -0.5 }, 1 },
    { { .fl = -0x400000 }, { .fl = -0.5 }, 23 },
    { { .fl = -0x7fffff }, { .fl = -0x0.fffffep+00 }, 23 },
    
    /* very big	*/
    { { 0x7f000000 }, { .fl = 0.5 }, 128 },
    { { 0x7f7fffff }, { .fl = 0x0.ffffffp+00 }, 128 },

    { { 0xff000000 }, { .fl = -0.5 }, 128 },
    { { 0xff7fffff }, { .fl = -0x0.ffffffp+00 }, 128 },
};

int main ()
{
    union lofl_u x, zf;
    int ze;
    int i;
    
    for (i = 0; i < (int) (sizeof(t) / sizeof(t[0])); i++) {
	x.lo =  pgm_read_dword (& t[i].x);
	zf.lo = pgm_read_dword (& t[i].f);
	ze =    pgm_read_word (& t[i].e);
	vf.fl = frexp (x.fl, & ve);
	if (vf.lo != zf.lo || ve != ze) {
	    PRINTFLN ("t[%d]: %#lx %d", i, vf.lo, ve);
	    EXIT (i + 1);
	}
    }

    /* Check all normal values with fractional 0.5	*/
    for (i = 1; i < 255; i++) {
	/* Positive.	*/
	x.lo = (long)i << 23;
	vf.fl = frexp (x.fl, & ve);
	if (vf.lo != 0x3f000000 || ve != i - 126) {
	    PRINTFLN ("t[%d]: %#lx %d", i, vf.lo, ve);
	    EXIT (i + 100);
	}

	/* Negative.	*/
	x.lo |= 0x80000000;
	vf.fl = frexp (x.fl, & ve);
	if ((unsigned long)vf.lo != 0xbf000000 || ve != i - 126) {
	    PRINTFLN ("t[%d]: %#lx %d", i, vf.lo, ve);
	    EXIT (i + 100);
	}
    }
    
    /* X is not a finite value.	*/
    {
	static PROGMEM const long tnf[] = {
	    0x7f800000,		/* +Inf	*/
	    0xff800000,		/* -Inf	*/
	    0x7f800001,		/* NaN	*/
	    0x7f800100,
	    0x7f810000,
	    0x7fc00000,
	    0x7fffffff,
	    0xff800001,
	    0xff800100,
	    0xff810000,
	    0xffc00000,
	    0xffffffff,
	};
	for (i = 0; i < (int) (sizeof(tnf) / sizeof(tnf[0])); i++) {
	    x.lo = pgm_read_dword (& tnf[i]);
	    ve = 1;
	    vf.fl = frexp (x.fl, & ve);
#ifdef	__AVR__
	    if (vf.lo != x.lo || ve) {
		PRINTFLN ("tnf[%d]: %#lx %d", i, vf.lo, ve);
		EXIT (i + 200);
	    }
#else
	    if (isinf (x.fl)) {
		if (vf.lo != x.lo || ve) {
		    PRINTFLN ("tnf[%d]: %#lx %d", i, vf.lo, ve);
		    EXIT (i + 200);
		}
	    } else {
		if (!isnan (vf.fl) || ve) {
		    PRINTFLN ("tnf[%d]: %#lx %d", i, vf.lo, ve);
		    EXIT (i + 200);
		}
	    }
#endif
	}
    }

#ifdef	__AVR__
    /* NULL is a legal address for Avr-libc realization: skip writing.	*/
    {
	unsigned char r1 = 1;
        vf.fl = frexp (48, (int *)0);
	/* Check __zero_reg__, as it is allocated by 0x0001 address. */
	asm ("mov %0,r1 \n\t clr r1" : "=r"(r1));
	if (r1) EXIT (300);
	if (vf.fl != 0.75) EXIT (301);
    }
#endif

    return 0;
}
