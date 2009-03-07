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

/* Test of sqrt() function.
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
    union lofl_u z;		/* sqrt(x)	*/
} t[] = {

    /* zero	*/
    { { 0x00000000 }, { 0x00000000 } },
    { { 0x80000000 }, { 0x80000000 } },		/* sqrt(-0.0) --> -0.0	*/
    
    /* +Inf	*/
    { { 0x7f800000 }, { 0x7f800000 } },
    
    /* some known values	*/
    { { .fl= 0.25 },	{ .fl= 0.5 }	},
    { { .fl= 1 },	{ .fl= 1 }	},
    { { .fl= 4 },	{ .fl= 2 }	},
    { { .fl= 9 },	{ .fl= 3 }	},
    { { .fl= 25 },	{ .fl= 5 }	},
    { { .fl= 49 },	{ .fl= 7 }	},
    { { .fl= 100 },	{ .fl= 10 }	},
    { { .fl= 121 },	{ .fl= 11 }	},
    { { .fl= 169 },	{ .fl= 13 }	},
    { { .fl= 10000 },	{ .fl= 100 }	},
    { { .fl= 1000000 },	{ .fl= 1000 }	},
    
    /* subnormals	*/
    { { 0x00000001 },	{ 0x1a3504f3 }	},
    { { 0x00000002 },	{ 0x1a800000 }	},
    { { 0x00000003 },	{ 0x1a9cc471 }	},
    { { 0x00000080 },	{ 0x1c000000 }	},
    { { 0x00000100 },	{ 0x1c3504f3 }	},
    { { 0x00008000 },	{ 0x1e000000 }	},
    { { 0x00010000 },	{ 0x1e3504f3 }	},
    { { 0x00400000 },	{ 0x1fb504f3 }	},
    { { 0x007fffff },	{ 0x1fffffff }	},
    
    /* margin values	*/
    { { 0x00800000 },	{ 0x20000000 }	},
    { { 0x00800001 },	{ 0x20000000 }	},
    { { 0x01000000 },	{ 0x203504f3 }	},
    { { 0x01000001 },	{ 0x203504f4 }	},
    { { 0x7f000000 },	{ 0x5f3504f3 }	},
    { { 0x7f000001 },	{ 0x5f3504f4 }	},
    { { 0x7f7ffffe },	{ 0x5f7fffff }	},
    { { 0x7f7fffff },	{ 0x5f7fffff }	},
    
    /* rounding	*/
    { { .fl= 0x0.800001p+1 }, { .fl= 0x0.800000p+1 } },
    { { .fl= 0x0.800002p+1 }, { .fl= 0x0.800001p+1 } },
    { { .fl= 0x0.800003p+1 }, { .fl= 0x0.800001p+1 } },
    { { .fl= 0x0.800004p+1 }, { .fl= 0x0.800002p+1 } },
    { { .fl= 0x0.800005p+1 }, { .fl= 0x0.800002p+1 } },
    { { .fl= 0x0.800006p+1 }, { .fl= 0x0.800003p+1 } },
    { { .fl= 0x0.800007p+1 }, { .fl= 0x0.800003p+1 } },
    { { .fl= 0x0.800008p+1 }, { .fl= 0x0.800004p+1 } },
    { { .fl= 0x0.800009p+1 }, { .fl= 0x0.800004p+1 } },
    
    /* slightly less 1.0 	*/
    { { .fl= 0x0.fffffcp+0 }, { .fl= 0x0.fffffep+0 } },
    { { .fl= 0x0.fffffdp+0 }, { .fl= 0x0.fffffep+0 } },
    { { .fl= 0x0.fffffep+0 }, { .fl= 0x0.ffffffp+0 } },
    { { .fl= 0x0.ffffffp+0 }, { .fl= 0x0.ffffffp+0 } },

    /* approx. 2.0	*/
    { { .fl= 0x0.fffff8p+1 }, { .fl= 0x0.b504f0p+1 } },
    { { .fl= 0x0.fffff9p+1 }, { .fl= 0x0.b504f1p+1 } },
    { { .fl= 0x0.fffffap+1 }, { .fl= 0x0.b504f1p+1 } },
    { { .fl= 0x0.fffffbp+1 }, { .fl= 0x0.b504f1p+1 } },
    { { .fl= 0x0.fffffcp+1 }, { .fl= 0x0.b504f2p+1 } },
    { { .fl= 0x0.fffffdp+1 }, { .fl= 0x0.b504f2p+1 } },
    { { .fl= 0x0.fffffep+1 }, { .fl= 0x0.b504f2p+1 } },
    { { .fl= 0x0.ffffffp+1 }, { .fl= 0x0.b504f3p+1 } },
    { { .fl= 0x0.800000p+2 }, { .fl= 0x0.b504f3p+1 } },
    { { .fl= 0x0.800001p+2 }, { .fl= 0x0.b504f4p+1 } },
    { { .fl= 0x0.800002p+2 }, { .fl= 0x0.b504f5p+1 } },
    { { .fl= 0x0.800003p+2 }, { .fl= 0x0.b504f5p+1 } },
    { { .fl= 0x0.800004p+2 }, { .fl= 0x0.b504f6p+1 } },
    { { .fl= 0x0.800005p+2 }, { .fl= 0x0.b504f7p+1 } },
    { { .fl= 0x0.800006p+2 }, { .fl= 0x0.b504f7p+1 } },
    { { .fl= 0x0.800007p+2 }, { .fl= 0x0.b504f8p+1 } },
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
	v.fl = sqrt (x.fl);
	/* Comparison is integer to verify the zero sign.	*/
	if (v.lo != z.lo)
	    x_exit (i+1);
    }
    return 0;
}
