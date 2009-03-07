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

/* Test of multiplication. Subnormals.
   $Id$
 */
#include <stdio.h>
#include <stdlib.h>
#include "progmem.h"

union lofl_u {
    long lo;
    float fl;
};

volatile union lofl_u v = { .lo = 1 };

PROGMEM const struct {		/* Table of test cases:  x * y = z	*/
    union lofl_u x, y, z;
} t[] = {

    /* subnormal * subnormal	*/
    { { 0x00000001 }, { 0x00000001 }, { 0 } },
    { { 0x00000100 }, { 0x00000100 }, { 0 } },
    { { 0x00010000 }, { 0x00010000 }, { 0 } },
    { { 0x007fffff }, { 0x007fffff }, { 0 } },
    
    /* subnormal * normal	*/
    { { 0x00000001 }, { .fl = .5 },		{ 0x00000000 }	},
    { { 0x00000001 }, { .fl = 1 },		{ 0x00000001 }	},
    { { 0x00000001 }, { .fl = 2 },		{ 0x00000002 }	},
    { { 0x00000001 }, { .fl = 4 },		{ 0x00000004 }	},
    { { 0x00000001 }, { .fl = 0x1p22 },		{ 0x00400000 }	},
    { { 0x00000001 }, { .fl = 0x1p23 },		{ 0x00800000 }	},
    { { 0x00000001 }, { .fl = 0x0.ffffffp127 },	{ .fl = 0x0.ffffffp-22 } },

    { { 0x00000002 }, { .fl = .25 },		{ 0x00000000 }	},
    { { 0x00000002 }, { .fl = .5 },		{ 0x00000001 }	},
    { { 0x00000002 }, { .fl = 1 },		{ 0x00000002 }	},
    { { 0x00000002 }, { .fl = 2 },		{ 0x00000004 }	},
    { { 0x00000002 }, { .fl = 0x1p21 },		{ 0x00400000 }	},
    { { 0x00000002 }, { .fl = 0x1p22 },		{ 0x00800000 }	},
    { { 0x00000002 }, { .fl = 0x0.ffffffp127 },	{ .fl = 0x0.ffffffp-21 } },
    
    { { 0x007fffff }, { .fl = 0x1p-24 },	{ 0x00000000 }	},
    { { 0x007fffff }, { .fl = 0x1p-23 },	{ 0x00000001 }	},
    { { 0x007fffff }, { .fl = 0x1p-22 },	{ 0x00000002 }	},
    { { 0x007fffff }, { .fl = 0x1p-1 },		{ 0x00400000 }	},
    { { 0x007fffff }, { .fl = 0x1p0 },		{ 0x007fffff }	},
    { { 0x007fffff }, { .fl = 0x1p1 },		{ 0x00fffffe }	},
    { { 0x007fffff }, { .fl = 0x0.ffffffp127 },	{ 0x3ffffffd }	},
    
    /* normal * subnormal	*/
    { { .fl = .5 },		{ 0x00000001 }, { 0x00000000 }	},
    { { .fl = 1 },		{ 0x00000001 }, { 0x00000001 }	},
    { { .fl = 2 },		{ 0x00000001 }, { 0x00000002 }	},
    { { .fl = 4 },		{ 0x00000001 }, { 0x00000004 }	},
    { { .fl = 0x1p22 },		{ 0x00000001 }, { 0x00400000 }	},
    { { .fl = 0x1p23 },		{ 0x00000001 }, { 0x00800000 }	},
    { { .fl = 0x0.ffffffp127 },	{ 0x00000001 }, { .fl = 0x0.ffffffp-22 } },
                                
    { { .fl = .25 },		{ 0x00000002 }, { 0x00000000 }	},
    { { .fl = .5 },		{ 0x00000002 }, { 0x00000001 }	},
    { { .fl = 1 },		{ 0x00000002 }, { 0x00000002 }	},
    { { .fl = 2 },		{ 0x00000002 }, { 0x00000004 }	},
    { { .fl = 0x1p21 },		{ 0x00000002 }, { 0x00400000 }	},
    { { .fl = 0x1p22 },		{ 0x00000002 }, { 0x00800000 }	},
    { { .fl = 0x0.ffffffp127 },	{ 0x00000002 }, { .fl = 0x0.ffffffp-21 } },
                                
    { { .fl = 0x1p-24 },	{ 0x007fffff }, { 0x00000000 }	},
    { { .fl = 0x1p-23 },	{ 0x007fffff }, { 0x00000001 }	},
    { { .fl = 0x1p-22 },	{ 0x007fffff }, { 0x00000002 }	},
    { { .fl = 0x1p-1 },		{ 0x007fffff }, { 0x00400000 }	},
    { { .fl = 0x1p0 },		{ 0x007fffff }, { 0x007fffff }	},
    { { .fl = 0x1p1 },		{ 0x007fffff }, { 0x00fffffe }	},
    { { .fl = 0x0.ffffffp127 },	{ 0x007fffff }, { 0x3ffffffd }	},

    /* normal * normal --> subnormal	*/
    { { .fl = 0x1p-75 }, { .fl = 0x1p-75 },	{ 0 }	},
    { { .fl = 0x1p-74 }, { .fl = 0x1p-75 },	{ 0x00000001 }	},
    { { .fl = 0x1p-74 }, { .fl = 0x1p-74 },	{ 0x00000002 }	},
    { { .fl = 0x1p-23 }, { 0x00800000 },	{ 0x00000001 }	},
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
	v.fl = x.fl * y.fl;
	/* Comparison is integer to verify the zero sign.	*/
	if (v.lo != z.lo)
	    x_exit (i+1);
    }
    return 0;
}
