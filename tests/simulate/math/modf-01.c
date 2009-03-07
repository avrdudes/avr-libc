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

/* Test of modf() function.
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

volatile union lofl_u vf = { 1 };
double vn = { 1 };

PROGMEM const struct {		/* Table of test cases.	*/
    union lofl_u x;	/* argument			*/
    union lofl_u f;	/* fraction part: modf(x,*pn)	*/
    union lofl_u n;	/* integral part: *pn		*/
} t[] = {

    /* zero	*/
    { { 0x00000000 }, { 0x00000000 }, { .fl = 0 } },
    { { 0x80000000 }, { 0x80000000 }, { .fl = -0.0 } },

    /* subnormal	*/
    { { 0x00000001 }, { 0x00000001 }, { .fl = 0 } },
    { { 0x00000100 }, { 0x00000100 }, { .fl = 0 } },
    { { 0x00010000 }, { 0x00010000 }, { .fl = 0 } },
    { { 0x007fffff }, { 0x007fffff }, { .fl = 0 } },

    { { 0x80000001 }, { 0x80000001 }, { .fl = -0.0 } },
    { { 0x80000100 }, { 0x80000100 }, { .fl = -0.0 } },
    { { 0x80010000 }, { 0x80010000 }, { .fl = -0.0 } },
    { { 0x807fffff }, { 0x807fffff }, { .fl = -0.0 } },
    
    /* integral normal	*/
    { { .fl = 0x000001 }, { .fl = 0 }, { .fl = 0x000001 } },
    { { .fl = 0x000002 }, { .fl = 0 }, { .fl = 0x000002 } },
    { { .fl = 0x000004 }, { .fl = 0 }, { .fl = 0x000004 } },
    { { .fl = 0x000008 }, { .fl = 0 }, { .fl = 0x000008 } },
    { { .fl = 0x000010 }, { .fl = 0 }, { .fl = 0x000010 } },
    { { .fl = 0x000020 }, { .fl = 0 }, { .fl = 0x000020 } },
    { { .fl = 0x000040 }, { .fl = 0 }, { .fl = 0x000040 } },
    { { .fl = 0x000080 }, { .fl = 0 }, { .fl = 0x000080 } },
    { { .fl = 0x000100 }, { .fl = 0 }, { .fl = 0x000100 } },
    { { .fl = 0x000200 }, { .fl = 0 }, { .fl = 0x000200 } },
    { { .fl = 0x000400 }, { .fl = 0 }, { .fl = 0x000400 } },
    { { .fl = 0x000800 }, { .fl = 0 }, { .fl = 0x000800 } },
    { { .fl = 0x001000 }, { .fl = 0 }, { .fl = 0x001000 } },
    { { .fl = 0x002000 }, { .fl = 0 }, { .fl = 0x002000 } },
    { { .fl = 0x004000 }, { .fl = 0 }, { .fl = 0x004000 } },
    { { .fl = 0x008000 }, { .fl = 0 }, { .fl = 0x008000 } },
    { { .fl = 0x010000 }, { .fl = 0 }, { .fl = 0x010000 } },
    { { .fl = 0x020000 }, { .fl = 0 }, { .fl = 0x020000 } },
    { { .fl = 0x040000 }, { .fl = 0 }, { .fl = 0x040000 } },
    { { .fl = 0x080000 }, { .fl = 0 }, { .fl = 0x080000 } },
    { { .fl = 0x100000 }, { .fl = 0 }, { .fl = 0x100000 } },
    { { .fl = 0x200000 }, { .fl = 0 }, { .fl = 0x200000 } },
    { { .fl = 0x400000 }, { .fl = 0 }, { .fl = 0x400000 } },
    { { .fl = 0x7fffff }, { .fl = 0 }, { .fl = 0x7fffff } },

    { { .fl = -0x000001L }, { .fl = -0.0 }, { .fl = -0x000001L } },
    { { .fl = -0x000002L }, { .fl = -0.0 }, { .fl = -0x000002L } },
    { { .fl = -0x000080L }, { .fl = -0.0 }, { .fl = -0x000080L } },
    { { .fl = -0x000100L }, { .fl = -0.0 }, { .fl = -0x000100L } },
    { { .fl = -0x008000L }, { .fl = -0.0 }, { .fl = -0x008000L } },
    { { .fl = -0x010000L }, { .fl = -0.0 }, { .fl = -0x010000L } },
    { { .fl = -0x400000L }, { .fl = -0.0 }, { .fl = -0x400000L } },
    { { .fl = -0x7fffffL }, { .fl = -0.0 }, { .fl = -0x7fffffL } },
    
    /* normal too big	*/
    { { .fl = 0x800000 }, { .fl = 0 }, { .fl = 0x800000 } },
    { { .fl = 0x800001 }, { .fl = 0 }, { .fl = 0x800001 } },
    { { 0x7e000000 }, { .fl = 0 }, { 0x7e000000 } },
    { { 0x7f000000 }, { .fl = 0 }, { 0x7f000000 } },
    { { 0x7f7fffff }, { .fl = 0 }, { 0x7f7fffff } },

    { { .fl = -0x800000L }, { .fl = -0.0 }, { .fl = -0x800000L } },
    { { .fl = -0x800001L }, { .fl = -0.0 }, { .fl = -0x800001L } },
    { { 0xfe000000 }, { .fl = -0.0 }, { 0xfe000000 } },
    { { 0xff000000 }, { .fl = -0.0 }, { 0xff000000 } },
    { { 0xff7fffff }, { .fl = -0.0 }, { 0xff7fffff } },
    
    /* Inf	*/
    { { 0x7f800000 },	{ .fl = 0 },	{ 0x7f800000 } },
    { { 0xff800000 },	{ .fl = -0.0 },	{ 0xff800000 } },
    
    /* integral and fraction	*/
    { { .fl= 0x1.000002p+0 }, { .fl= 0x0.000002p+0 }, { .fl= 1 } },
    { { .fl= 0x1.000004p+0 }, { .fl= 0x0.000004p+0 }, { .fl= 1 } },
    { { .fl= 0x1.000008p+0 }, { .fl= 0x0.000008p+0 }, { .fl= 1 } },
    { { .fl= 0x1.000010p+0 }, { .fl= 0x0.000010p+0 }, { .fl= 1 } },
    { { .fl= 0x1.000020p+0 }, { .fl= 0x0.000020p+0 }, { .fl= 1 } },
    { { .fl= 0x1.000040p+0 }, { .fl= 0x0.000040p+0 }, { .fl= 1 } },
    { { .fl= 0x1.000080p+0 }, { .fl= 0x0.000080p+0 }, { .fl= 1 } },
    { { .fl= 0x1.000100p+0 }, { .fl= 0x0.000100p+0 }, { .fl= 1 } },
    { { .fl= 0x1.000200p+0 }, { .fl= 0x0.000200p+0 }, { .fl= 1 } },
    { { .fl= 0x1.000400p+0 }, { .fl= 0x0.000400p+0 }, { .fl= 1 } },
    { { .fl= 0x1.000800p+0 }, { .fl= 0x0.000800p+0 }, { .fl= 1 } },
    { { .fl= 0x1.001000p+0 }, { .fl= 0x0.001000p+0 }, { .fl= 1 } },
    { { .fl= 0x1.002000p+0 }, { .fl= 0x0.002000p+0 }, { .fl= 1 } },
    { { .fl= 0x1.004000p+0 }, { .fl= 0x0.004000p+0 }, { .fl= 1 } },
    { { .fl= 0x1.008000p+0 }, { .fl= 0x0.008000p+0 }, { .fl= 1 } },
    { { .fl= 0x1.010000p+0 }, { .fl= 0x0.010000p+0 }, { .fl= 1 } },
    { { .fl= 0x1.020000p+0 }, { .fl= 0x0.020000p+0 }, { .fl= 1 } },
    { { .fl= 0x1.040000p+0 }, { .fl= 0x0.040000p+0 }, { .fl= 1 } },
    { { .fl= 0x1.080000p+0 }, { .fl= 0x0.080000p+0 }, { .fl= 1 } },
    { { .fl= 0x1.100000p+0 }, { .fl= 0x0.100000p+0 }, { .fl= 1 } },
    { { .fl= 0x1.200000p+0 }, { .fl= 0x0.200000p+0 }, { .fl= 1 } },
    { { .fl= 0x1.400000p+0 }, { .fl= 0x0.400000p+0 }, { .fl= 1 } },
    { { .fl= 0x1.800000p+0 }, { .fl= 0x0.800000p+0 }, { .fl= 1 } },
    { { .fl= 0x1.fffffep+0 }, { .fl= 0x0.fffffep+0 }, { .fl= 1 } },

    { { .fl= 0x2.000004p+0 }, { .fl= 0x0.000004p+0 }, { .fl= 2 } },
    { { .fl= 0x2.000400p+0 }, { .fl= 0x0.000400p+0 }, { .fl= 2 } },
    { { .fl= 0x2.800000p+0 }, { .fl= 0x0.800000p+0 }, { .fl= 2 } },
    { { .fl= 0x2.fffffcp+0 }, { .fl= 0x0.fffffcp+0 }, { .fl= 2 } },
    { { .fl= 0x7fffff.8p+0 }, { .fl= 0x0.8p+0 }, { .fl= 0x7fffffp+0 } },

    { { .fl= -0x1.000002p+0 }, { .fl= -0x0.000002p+0 }, { .fl= -1 } },
    { { .fl= -0x1.800000p+0 }, { .fl= -0x0.800000p+0 }, { .fl= -1 } },
    { { .fl= -0x1.fffffep+0 }, { .fl= -0x0.fffffep+0 }, { .fl= -1 } },
    { { .fl= -0x2.000004p+0 }, { .fl= -0x0.000004p+0 }, { .fl= -2 } },
    { { .fl= -0x2.000400p+0 }, { .fl= -0x0.000400p+0 }, { .fl= -2 } },
    { { .fl= -0x2.800000p+0 }, { .fl= -0x0.800000p+0 }, { .fl= -2 } },
    { { .fl= -0x2.fffffcp+0 }, { .fl= -0x0.fffffcp+0 }, { .fl= -2 } },
    { { .fl= -0x7fffff.8p+0 }, { .fl= -0x0.8p+0 }, { .fl= -0x7fffffp+0 } },
};

void x_exit (int index)
{
#ifndef	__AVR__
    fprintf (stderr, "t[%d]:  %#lx\n", index - 1, vf.lo);
#endif
    exit (index ? index : -1);
}

int main ()
{
    union lofl_u x, zf, zn, vn1;
    int i;
    
    for (i = 0; i < (int) (sizeof(t) / sizeof(t[0])); i++) {
	x.lo = pgm_read_dword (& t[i].x);
	zf.lo = pgm_read_dword (& t[i].f);
	zn.lo = pgm_read_dword (& t[i].n);
	vf.fl = modf (x.fl, & vn);
	vn1.fl = vn;
	if ((vf.lo != zf.lo) || (vn1.lo != zn.lo))
	    x_exit (i+1);
    }
    return 0;
}
