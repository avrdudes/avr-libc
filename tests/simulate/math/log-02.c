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

/* Test of log() function. Check some values and the monotone.
   $Id$
 */
#define	ULPMAX	6	/* Max possible error, "units at last place".	*/

#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include "progmem.h"

union lofl_u {
    long lo;
    float fl;
};

volatile union lofl_u v = { .lo = 1 };

PROGMEM const struct {		/* Table of test cases:  x, log(x)	*/
    union lofl_u x, z;
} t[] = {

    { { 0x00000001 }, { 0xc2ce8ed0 } },
    { { 0x00000002 }, { 0xc2cd2bec } },
    { { 0x00000003 }, { 0xc2cc5c53 } },

    { { 0x000000ff }, { 0xc2c379af } },
    { { 0x00000100 }, { 0xc2c377ae } },
    { { 0x00000101 }, { 0xc2c375af } },

    { { 0x0000ffff }, { 0xc2b8608f } },
    { { 0x00010000 }, { 0xc2b8608d } },
    { { 0x00010001 }, { 0xc2b8608b } },

    { { 0x007fffff }, { 0xc2aeac50 } },
    { { 0x00800000 }, { 0xc2aeac50 } },
    { { 0x00800001 }, { 0xc2aeac50 } },
    
    /* 0.5	*/
    { { 0x3effffff }, { 0xbf317219 } },
    { { 0x3f000000 }, { 0xbf317218 } },
    { { 0x3f000001 }, { 0xbf317216 } },
    
    /* 1.0	*/
    { { 0x3f7ffffe }, { 0xb4000001 } },
    { { 0x3f7fffff }, { 0xb3800000 } },
    { { 0x3f800000 }, { 0x00000000 } },
    { { 0x3f800001 }, { 0x33ffffff } },
    { { 0x3f800002 }, { 0x347ffffe } },

    /* fraction 0x0.98  --  switch between tables	*/
    { { 0x3f97fffe }, { 0x3e2ff976 } },
    { { 0x3f97ffff }, { 0x3e2ff97d } },
    { { 0x3f980000 }, { 0x3e2ff984 } },
    { { 0x3f980001 }, { 0x3e2ff98a } },

    /* fraction 0x0.E0  --  switch between tables	*/
    { { 0x3fdffffe }, { 0x3f0f42f9 } },
    { { 0x3fdfffff }, { 0x3f0f42fa } },
    { { 0x3fe00000 }, { 0x3f0f42fb } },
    { { 0x3fe00001 }, { 0x3f0f42fc } },

    /* 2.0	*/
    { { 0x3fffffff }, { 0x3f317217 } },
    { { 0x40000000 }, { 0x3f317218 } },
    { { 0x40000001 }, { 0x3f31721a } },
    
    { { 0x7f7ffffd }, { 0x42b17218 } },
    { { 0x7f7ffffe }, { 0x42b17218 } },
    { { 0x7f7fffff }, { 0x42b17218 } },
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
    union lofl_u x, z, v1;
    int i;
    
    v.fl = -INFINITY;
    for (i = 0; i < (int) (sizeof(t) / sizeof(t[0])); i++) {
	x.lo = pgm_read_dword (& t[i].x);
	z.lo = pgm_read_dword (& t[i].z);
	v1.fl = log (x.fl);
	if (   ((v1.lo ^ z.lo) & 0x80000000)	/* signbit(v1) != signbit(z) */
	    || labs (v1.lo - z.lo) > ULPMAX
	    || v1.fl < v.fl)
	{
	    v = v1;
	    x_exit (i+1);
	}
	v = v1;
    }
    return 0;
}
