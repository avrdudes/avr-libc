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

/* Test of ldexp function.  Without NaNs.
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
    union lofl_u x;
    int y;
    union lofl_u z;		/* z = ldexp(x,y)	*/
} t[] = {

    /* x == 0	*/
    { { 0 },	0,	{ 0 }	},
    { { 0 },	1,	{ 0 }	},
    { { 0 },	-1,	{ 0 }	},
    { { 0 },	32767,	{ 0 }	},
    { { 0 },	-32768,	{ 0 }	},
    { { 0x80000000 }, 0,  { 0x80000000 }	},
    { { 0x80000000 }, -1, { 0x80000000 }	},
    
    /* normal --> normal	*/
    { { .fl = 1. }, 0,	  { .fl = 1. }		},
    { { .fl = 1. }, 1,	  { .fl = 2. }		},
    { { .fl = 1. }, -1,   { .fl = .5 }		},
    { { .fl = 1. }, 127,  { 0x7f000000 }	},
    { { .fl = 1. }, -126, { 0x00800000 }	},
    { { .fl = -1. },	0,	{ .fl = -1. }	},
    { { .fl = -1. },	1,	{ .fl = -2. }	},
    { { .fl = -1. },	-1,	{ .fl = -.5 }	},
    { { .fl = -1. },	127,	{ 0xff000000 }	},
    { { .fl = -1. },	-126,	{ 0x80800000 }	},

    /* normal --> subnormal	*/
    { { .fl = 1. },	-127,	{ 0x00400000 }	},
    { { .fl = 1. },	-149,	{ 0x00000001 }	},
    { { .fl = -1. },	-127,	{ 0x80400000 }	},
    { { .fl = -1. },	-149,	{ 0x80000001 }	},
    
    /* subnormal <<= N	*/
    { { 0x00000001 },	0,	{ 0x00000001 }	},
    { { 0x00000001 },	1,	{ 0x00000002 }	},
    { { 0x00000001 },	2,	{ 0x00000004 }	},
    { { 0x00000001 },	22,	{ 0x00400000 }	},
    { { 0x00000001 },	23,	{ 0x00800000 }	},
    { { 0x00000001 },	24,	{ 0x01000000 }	},
    { { 0x00000001 },	25,	{ 0x01800000 }	},
    { { 0x00000001 },	149,	{ 0x3f800000 }	},
    { { 0x00000001 },	276,	{ 0x7f000000 }	},
    { { 0x00000001 },	277,	{ 0x7f800000 }	},	/* overflow	*/
    
    /* subnormal >>= N	*/
    { { 0x00400000 },	0,	{ 0x00400000 }	},
    { { 0x00400000 },	-1,	{ 0x00200000 }	},
    { { 0x00400000 },	-2,	{ 0x00100000 }	},
    { { 0x00400000 },	-22,	{ 0x00000001 }	},
    { { 0x00400000 },	-23,	{ 0x00000000 }	},	/* round to 0	*/
    { { 0x00400000 },	-2000,	{ 0x00000000 }	},	/* underflow	*/
    
    /* underflow	*/
    { { .fl = 1. },	-151,	{ 0 }	},
    { { .fl = -1. },	-151,	{ 0x80000000 }	},
    
    /* overflow	*/
    { { .fl = 1. },	128,	{ 0x7f800000 }	},
    { { .fl = -1. },	128,	{ 0xff800000 }	},
    { { .fl = 1. },	32767-127,	{ 0x7f800000 }	},
    { { .fl = -1. },	32767-127,	{ 0xff800000 }	},
    
    /* Infinity	*/
    { { 0x7f800000 },	0,	{ 0x7f800000 } },
    { { 0x7f800000 },	1,	{ 0x7f800000 } },
    { { 0x7f800000 },	-1,	{ 0x7f800000 } },
    { { 0x7f800000 },	32767,	{ 0x7f800000 } },
    { { 0x7f800000 },	-32768,	{ 0x7f800000 } },
    { { 0xff800000 },	0,	{ 0xff800000 } },
    { { 0xff800000 },	1,	{ 0xff800000 } },
    { { 0xff800000 },	-1,	{ 0xff800000 } },
    { { 0xff800000 },	32767,	{ 0xff800000 } },
    { { 0xff800000 },	-32768,	{ 0xff800000 } },

    /* Rounding	*/
    { { 0x00000001 },	-1,	{ 0x00000000 } },
    { { 0x00000003 },	-1,	{ 0x00000002 } },
    { { 0x00000005 },	-1,	{ 0x00000002 } },
    { { 0x00000007 },	-1,	{ 0x00000004 } },
    { { 0x00000009 },	-1,	{ 0x00000004 } },
    { { 0x0000000b },	-1,	{ 0x00000006 } },
    { { 0x0000000d },	-1,	{ 0x00000006 } },    
    { { 0x0000000f },	-1,	{ 0x00000008 } },
    { { 0x00000011 },	-1,	{ 0x00000008 } },
    
    { { 0x00000100 },	-9,	{ 0x00000000 } },
    { { 0x00000101 },	-9,	{ 0x00000001 } },
    { { 0x00010001 },	-17,	{ 0x00000001 } },
    { { 0x00800001 },	-24,	{ 0x00000001 } },
    { { 0x01800001 },	-26,	{ 0x00000001 } },

    { { 0x00000101 },	-10,	{ 0x00000000 } },
};

void x_exit (int index)
{
#ifndef	__AVR__
    fprintf (stderr, "t[%d]: %e (%#lx)\n", index - 1, v.fl, v.lo);
#endif
    exit (index ? index : -1);
}

int main ()
{
    union lofl_u x, z;
    int y;
    int i;

    for (i = 0; i < (int) (sizeof(t) / sizeof(t[0])); i++) {
	x.lo = pgm_read_dword (& t[i].x);
	y    = pgm_read_word  (& t[i].y);
	z.lo = pgm_read_dword (& t[i].z);
	v.fl = ldexp (x.fl, y);
	/* Comparison is integer to verify zero sign.	*/
	if (v.lo != z.lo)
	    x_exit (i+1);
    }
    return 0;
}
