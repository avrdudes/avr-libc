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

/* Test of copysign(). Both realizations are tested: inline and library.
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
    union lofl_u x, y;		/* args		*/
    union lofl_u z;		/* result	*/
} t[] = {

    { { .fl= +0.0 }, { .fl= +0.0 }, { .fl= +0.0 } },
    { { .fl= -0.0 }, { .fl= +0.0 }, { .fl= +0.0 } },
    { { .fl= +0.0 }, { .fl= -0.0 }, { .fl= -0.0 } },
    { { .fl= -0.0 }, { .fl= -0.0 }, { .fl= -0.0 } },
    
    { { .fl= +1 },   { .fl= +10 },  { .fl= +1 } },
    { { .fl= -1 },   { .fl= +10 },  { .fl= +1 } },
    { { .fl= +1 },   { .fl= -10 },  { .fl= -1 } },
    { { .fl= -1 },   { .fl= -10 },  { .fl= -1 } },
    
    /* Inf	*/
    { { 0x7f800000 }, { 0xff800000 }, { 0xff800000 } },
    { { 0xff800000 }, { 0x7f800000 }, { 0x7f800000 } },
};

void x_exit (int index)
{
#ifndef	__AVR__
    fprintf (stderr, "t[%d]\n", index - 1);
#endif
    exit (index ? index : -1);
}

int main ()
{
    union lofl_u x, y, z;
    int i;
    double (* volatile vp) (double, double);
    
    /* inline     */
    for (i = 0; i < (int) (sizeof(t) / sizeof(t[0])); i++) {
	x.lo = pgm_read_dword (& t[i].x);
	y.lo = pgm_read_dword (& t[i].y);
	z.lo = pgm_read_dword (& t[i].z);
	v.fl = copysign (x.fl, y.fl);
	if (v.lo != z.lo)
	    x_exit (i + 1);
    }

    /* library function     */
    vp = copysign;
    for (i = 0; i < (int) (sizeof(t) / sizeof(t[0])); i++) {
	x.lo = pgm_read_dword (& t[i].x);
	y.lo = pgm_read_dword (& t[i].y);
	z.lo = pgm_read_dword (& t[i].z);
	v.fl = vp (x.fl, y.fl);
	if (v.lo != z.lo)
	    x_exit (i + 0x101);
    }
    
    return 0;
}
