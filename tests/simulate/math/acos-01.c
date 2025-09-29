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
   POSSIBILITY OF SUCH DAMAGE. */

/* Test of acos() function. */
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
    union lofl_u z;		/* acos(x)	*/
} t[] = {

    /* Zero	*/
    { { .fl= +0.0 },	{ 0x3fc90fdb }	},	/* Pi/2	*/
    { { .fl= -0.0 },	{ 0x3fc90fdb }	},

    /* Subnormal	*/
    { { 0x00000001 },	{ 0x3fc90fdb }	},
    { { 0x00000100 },	{ 0x3fc90fdb }	},
    { { 0x00010000 },	{ 0x3fc90fdb }	},
    { { 0x007fffff },	{ 0x3fc90fdb }	},
    { { 0x80000001 },	{ 0x3fc90fdb }	},
    { { 0x80000100 },	{ 0x3fc90fdb }	},
    { { 0x80010000 },	{ 0x3fc90fdb }	},
    { { 0x807fffff },	{ 0x3fc90fdb }	},
    
    /* Some values	*/
    { { .fl=  1.0 },	{ .fl = 0.0  } },
    { { .fl= -1.0 },	{ 0x40490fdb } },	/* Pi	*/
};

void x_exit (int index)
{
#ifndef	__AVR__
    fprintf (stderr, "t[%d]:  %#lx\n", index - 1, v.lo);
#endif
    exit (index ? index : -1);
}

static inline unsigned long distance (long a, long b)
{
    unsigned long a1, b1;
    a1 = (a < 0) ? (unsigned long)~a : a + 0x80000000;
    b1 = (b < 0) ? (unsigned long)~b : b + 0x80000000;
    return (a1 > b1) ? a1 - b1 : b1 - a1;
}

int main (void)
{
    union lofl_u x, z;
    int i;
    
    for (i = 0; i < (int) (sizeof(t) / sizeof(t[0])); i++) {
	x.lo = pgm_read_dword (& t[i].x);
	z.lo = pgm_read_dword (& t[i].z);
	v.fl = acosf (x.fl);
	if (v.lo < 0 || distance(v.lo, z.lo) > 1)
	    x_exit (i+1);
    }
    return 0;
}
