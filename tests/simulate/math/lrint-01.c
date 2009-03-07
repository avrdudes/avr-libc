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

/* Test of lrint() function.
   $Id$
 */
#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include "progmem.h"

#ifndef	__AVR__
# define PRINTFLN(line, fmt, ...)	\
    printf ("\nLine %d: " fmt "\n", line, ##__VA_ARGS__)
# define EXIT(code)	exit ((code) < 255 ? (code) : 100 + (code) % 100)
#else
# if defined(__AVR_ATmega128__)
  /* ATmega128 has enough RAM for sprintf(), print to 0x2000 in XRAM. */
#  define PRINTFLN(line, fmt, ...)	\
    sprintf ((char *)0x2000, "\nLine %d: " fmt "\n", line, ##__VA_ARGS__)
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

/* Result is placed into SRAM variable, allocated at the start of
   memory. This is convinient to debug: read a core dump.	*/
volatile long v = 1;

PROGMEM const struct {		/* Table of test cases.	*/
    union lofl_u x;		/* argument	*/
    long z;			/* result	*/
} t[] = {

    /* Zero	*/
    { { .fl= +0.0 },	0 },
    { { .fl= -0.0 },	0 },
    
    /* A few of normal values	*/
    { { .fl= 0.1 },		0 },
    { { .fl= 0.5 },		0 },
    { { .fl= 0.9 },		1 },
    { { .fl= 1.49999 },		1 },
    { { .fl= 1.5 },		2 },
    { { .fl= 1.9 },		2 },
    { { .fl= 2.5 },		2 },
    { { .fl= 1000000.5 },	1000000 },
    { { .fl= 1000001.5 },	1000002 },
    { { .fl= -0.1 },		0 },
    { { .fl= -0.5 },		0 },
    { { .fl= -0.9 },		-1 },
    { { .fl= -1.49999 },	-1 },
    { { .fl= -1.5 },		-2 },
    { { .fl= -1.9 },		-2 },
    { { .fl= -2.5 },		-2 },
    { { .fl= -1000000.5 },	-1000000 },
    { { .fl= -1000001.5 },	-1000002 },

    /* Subnormal	*/
    { { 0x00000001 }, 0 },
    { { 0x00000100 }, 0 },
    { { 0x00010000 }, 0 },
    { { 0x007fffff }, 0 },
    { { 0x80000001 }, 0 },
    { { 0x80000100 }, 0 },
    { { 0x80010000 }, 0 },
    { { 0x807fffff }, 0 },
    
    /* Margin values (positive).	*/
    { { 0x00800000 }, 0 },		/* the smallest nonzero normal	*/

    { { 0x3effffff }, 0 },
    { { 0x3f000000 }, 0 },		/* 0.5	*/
    { { 0x3f000001 }, 1 },
    { { 0x3f000080 }, 1 },
    { { 0x3f000100 }, 1 },
    { { 0x3f008000 }, 1 },
    { { 0x3f010000 }, 1 },

    { { 0x3f7fffff }, 1 },
    { { 0x3f800000 }, 1 },		/* 1.0	*/
    { { 0x3f800001 }, 1 },

    { { 0x3fbfffff }, 1 },
    { { 0x3fc00000 }, 2 },		/* 1.5	*/
    { { 0x3fc00001 }, 2 },

    { { 0x401fffff }, 2 },
    { { 0x40200000 }, 2 },		/* 2.5	*/
    { { 0x40200001 }, 3 },

    { { .fl= 0x0.fffffcp+23 }, 0x7ffffe },
    { { .fl= 0x0.fffffdp+23 }, 0x7ffffe },
    { { .fl= 0x0.fffffep+23 }, 0x7fffff },
    { { .fl= 0x0.ffffffp+23 }, 0x800000 },
    { { .fl= 0x1.000000p+23 }, 0x800000 },

    { { .fl= 0x0.ffffffp+31 }, 0x7fffff80 },	/* near overflow */

    /* Margin values (negative).	*/
    { { 0x80800000 }, 0 },		/* the smallest nonzero normal	*/

    { { 0xbeffffff }, 0 },
    { { 0xbf000000 }, 0 },		/* -0.5	*/
    { { 0xbf000001 }, -1 },
    { { 0xbf000080 }, -1 },
    { { 0xbf000100 }, -1 },
    { { 0xbf008000 }, -1 },
    { { 0xbf010000 }, -1 },

    { { 0xbf7fffff }, -1 },
    { { 0xbf800000 }, -1 },		/* -1.0	*/
    { { 0xbf800001 }, -1 },

    { { 0xbfbfffff }, -1 },
    { { 0xbfc00000 }, -2 },		/* -1.5	*/
    { { 0xbfc00001 }, -2 },

    { { 0xc01fffff }, -2 },
    { { 0xc0200000 }, -2 },		/* -2.5	*/
    { { 0xc0200001 }, -3 },

    { { .fl= -0x0.fffffcp+23 }, -0x7ffffe },
    { { .fl= -0x0.fffffdp+23 }, -0x7ffffe },
    { { .fl= -0x0.fffffep+23 }, -0x7fffff },
    { { .fl= -0x0.fffffep+23 }, -0x7fffffL },
    { { .fl= -0x0.ffffffp+23 }, -0x800000L },
    { { .fl= -0x1.000000p+23 }, -0x800000L },

    { { .fl= -0x0.ffffffp+31 }, -0x7fffff80L },	/* near overflow */
    { { .fl= -0x1.000000p+31 }, 0x80000000L },

    /* In addition to main(): shift 0xffffff to left .	*/
    { { .fl= 0x0.ffffffp+24 }, 0x00ffffff },
    { { .fl= 0x0.ffffffp+25 }, 0x01fffffe },
    { { .fl= 0x0.ffffffp+26 }, 0x03fffffc },
    { { .fl= 0x0.ffffffp+27 }, 0x07fffff8 },
    { { .fl= 0x0.ffffffp+28 }, 0x0ffffff0 },
    { { .fl= 0x0.ffffffp+29 }, 0x1fffffe0 },
    { { .fl= 0x0.ffffffp+30 }, 0x3fffffc0 },
    { { .fl= 0x0.ffffffp+31 }, 0x7fffff80 },
    { { .fl= -0x0.ffffffp+24 }, -0x00ffffffL },
    { { .fl= -0x0.ffffffp+25 }, -0x01fffffeL },
    { { .fl= -0x0.ffffffp+26 }, -0x03fffffcL },
    { { .fl= -0x0.ffffffp+27 }, -0x07fffff8L },
    { { .fl= -0x0.ffffffp+28 }, -0x0ffffff0L },
    { { .fl= -0x0.ffffffp+29 }, -0x1fffffe0L },
    { { .fl= -0x0.ffffffp+30 }, -0x3fffffc0L },
    { { .fl= -0x0.ffffffp+31 }, -0x7fffff80L },

    /* Positive overflow	*/
    { { .fl= 0x0.800000p+32 }, 0x80000000 },
    { { .fl= 0x0.800001p+32 }, 0x80000000 },
    { { .fl= 0x0.ffffffp+32 }, 0x80000000 },
    { { .fl= 0x0.800000p+33 }, 0x80000000 },
    { { .fl= 0x0.ffffffp+33 }, 0x80000000 },
    { { .lo= 0x7f000000 },     0x80000000 },
    { { .lo= 0x7f7fffff },     0x80000000 },
    { { .lo= 0x7f800000 },     0x80000000 },	/* +Inf	*/

    /* Negative overflow	*/
    { { .fl= -0x0.800000p+32 }, 0x80000000 },
    { { .fl= -0x0.800001p+32 }, 0x80000000 },
    { { .fl= -0x0.ffffffp+32 }, 0x80000000 },
    { { .fl= -0x0.800000p+33 }, 0x80000000 },
    { { .fl= -0x0.ffffffp+33 }, 0x80000000 },
    { { .lo= 0xff000000 },      0x80000000 },
    { { .lo= 0xff7fffff },      0x80000000 },
    { { .lo= 0xff800000 },      0x80000000 },	/* -Inf	*/

    /* NaN	*/
    { { 0x7f800001 },	0x80000000 },
    { { 0x7fc00000 },	0x80000000 },
    { { 0x7fffffff },	0x80000000 },
    { { 0xff800001 },	0x80000000 },
    { { 0xffc00000 },	0x80000000 },
    { { 0xffffffff },	0x80000000 },
};

void x_exit (int index)
{
#ifndef	__AVR__
    fprintf (stderr, "t[%d]:  %#lx\n", index - 1, v);
#endif
    exit (index ? index : -1);
}

int main ()
{
    union lofl_u x;
    long z;
    int i;

    /* Table.	*/    
    for (i = 0; i < (int) (sizeof(t) / sizeof(t[0])); i++) {
	x.lo = pgm_read_dword (& t[i].x);
	z = pgm_read_dword (& t[i].z);
	v = lrint (x.fl);
	if (v != z)
	    x_exit (i+1);
    }

    /* Check all possible shifts. Rounding is not needed. Both signs.
       0x0.800000p+01 --> 1
       0x0.800000p+02 --> 2
       ...
       0x0.800000p+31 --> 0x40000000	*/
    for (x.fl = 1.0, i = 0; i < 31; i++) {
	v = lrint (x.fl);
	if (v != (1L << i)) {
	    PRINTFLN (__LINE__, "i= %d  v= %#lx", i, v);
	    EXIT (100 + i);
	}

	/* Change sign to minus.	*/
	x.lo |= 0x80000000;
	v = lrint (x.fl);
	if (v != -(1L << i)) {
	    PRINTFLN (__LINE__, "i= %d  v= %#lx", i, v);
	    EXIT (200 + i);
	}

	/* Change sign again and increment exponent.	*/
	x.lo += 0x80800000;
    }

    /* Check all possible shits with fraction 0.5, round in zero direction
       0x0.a00000p+02 --> 2	2.5
       0x0.900000p+03 --> 4	4.5
       ...
       0x0.800001p+23 --> 0x400000	*/
    for (i = 2; i < 24; i++) {
	x.fl = 1.0;
	x.lo += (0x800000 * (i-1));	/* exponent	*/
	x.lo |= (0x800000 >> i);	/* += 0.5	*/
	v = lrint (x.fl);
	if (v != (1L << (i-1))) {
	    PRINTFLN (__LINE__, "i= %d  v= %#lx", i, v);
	    EXIT (300 + i);
	}
    }

    /* Rounding with carry. All possible shifts to right. Both signs.
       0x0.ffffffp+00 --> 1
       0x0.ffffffp+01 --> 2
       ...
       0x0.ffffffp+23 --> 0x800000	*/
    for (x.fl = 0x0.ffffffp+00, i = 0; i < 24; i++) {
	v = lrint (x.fl);
	if (v != (1L << i)) {
	    PRINTFLN (__LINE__, "i= %d  v= %#lx", i, v);
	    EXIT (400 + i);
	}

	/* Change sign to minus.	*/
	x.lo |= 0x80000000;
	v = lrint (x.fl);
	if (v != -(1L << i)) {
	    PRINTFLN (__LINE__, "i= %d  v= %#lx", i, v);
	    EXIT (500 + i);
	}

	/* Change sign again and increment exponent.	*/
	x.lo += 0x80800000;
    }
    
    /* Rounding to up. Check a few values between 0.5 to 1.0 (as lrint(0.5)
       is 0, but lrint(0.5+delta) is 1).	*/
    for (i = 0; i < 22; i++) {
	x.fl = 0.5;
	x.lo += 1L<<i;
	v = lrint (x.fl);
	if (v != 1) {
	    PRINTFLN (__LINE__, "i= %d  v= %#lx", i, v);
	    EXIT (600 + i);
	}

	x.fl = 0.5;
	x.lo += ~(1L<<i) & 0x3fffff;
	v = lrint (x.fl);
	if (v != 1) {
	    PRINTFLN (__LINE__, "i= %d  v= %#lx", i, v);
	    EXIT (700 + i);
	}
    }

    return 0;
}
