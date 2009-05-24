/* Copyright (c) 2007,2009  Dmitry Xmelkov
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

/* Test of a set of functions: func(NaN) --> NaN
   $Id$
 */
#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include "progmem.h"

/* Table of tested functions.	*/
double (*tfun[]) (double) = {
    acos,
    asin,
    atan,
    cbrt,
    ceil,
    cos,
    cosh,
    exp,
    floor,
    log,
    log10,
    sin,
    sinh,
    sqrt,
    tan,
    tanh,
    trunc,
    round
};

union lofl_u {
    long lo;
    float fl;
};

volatile union lofl_u v = { 1 };

/* Table of test cases: NaNs	*/
PROGMEM const union lofl_u tnan[] = {
    { 0x7f800001 },
    { 0x7f800100 },
    { 0x7f810000 },
    { 0x7fc00000 },
    { 0x7fffffff },
    { 0xff800001 },
    { 0xff800100 },
    { 0xff810000 },
    { 0xffc00000 },
    { 0xffffffff },
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
    union lofl_u x;
    int f, n;
    
    for (f = 0; f < (int) (sizeof(tfun)/sizeof(tfun[0])); f++) {
	for (n = 0; n < (int) (sizeof(tnan)/sizeof(tnan[0])); n++) {
	    x.lo = pgm_read_dword (& tnan[n]);
	    v.fl = (tfun[f]) (x.fl);
	    if (!isnan (v.fl)) {
		x_exit (f+1);
	    }
	}
    }
    return 0;
}
