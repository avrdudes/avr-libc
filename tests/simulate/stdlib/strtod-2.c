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

/* Test of strtod() function. "+1.0"
   $Id$
 */
#include <errno.h>
#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "progmem.h"

union lofl_u {
    long lo;
    float fl;
};

volatile union lofl_u v = { .lo = 1 };

PROGMEM const struct {		/* Table of test cases.	*/
    char s[20];
    unsigned char len;
    float val;
    int eno;
} t[] = {

    { "1", 1,		1, 0 },
    { "1.", 2,		1, 0 },
    { "1.0", 3,		1, 0 },
    { "1.00", 4,	1, 0 },

    { "01", 2,		1, 0 },
    { "001.", 4,	1, 0 },
    { "0001.0", 6,	1, 0 },
    { "00001.00", 8,	1, 0 },

    { "1e0", 3,		1, 0 },
    { "1e00", 4,	1, 0 },
    { "1e+0", 4,	1, 0 },
    { "1e+00", 5,	1, 0 },
    { "1e-0", 4,	1, 0 },
    { "1e-00", 5,	1, 0 },

    { "1.e0", 4,	1, 0 },
    { "1.0e0", 5,	1, 0 },
    { "1.00e0", 6,	1, 0 },
    { "001.0e0", 7,	1, 0 },

    { "10e-1", 5,		1, 0 },
    { "100e-2", 6,		1, 0 },
    { "1000e-3", 7,		1, 0 },
    { "10000e-4", 8,		1, 0 },
    { "100000e-5", 9,		1, 0 },
    { "1000000e-6", 10,		1, 0 },
    { "10000000e-7", 11,	1, 0 },
    { "100000000e-8", 12,	1, 0 },
    { "1000000000e-9", 13,	1, 0 },
    { "10000000000e-10", 15,	1, 0 },
    { "100000000000e-11", 16,	1, 0 },
    { "1000000000000e-12", 17,	1, 0 },
    { "10000000000000e-13", 18,	1, 0 },
    { "100000000000000e-14", 19, 1, 0 },
    
    { ".1e+1", 5,		1, 0 },
    { ".1e1", 4,		1, 0 },
    { ".01e2", 5,		1, 0 },
    { ".001e3", 6,		1, 0 },
    { ".0001e4", 7,		1, 0 },
    { ".00001e5", 8,		1, 0 },
    { ".000001e6", 9,		1, 0 },
    { ".0000001e7", 10,		1, 0 },
    { ".00000001e8", 11,	1, 0 },
    { ".000000001e9", 12,	1, 0 },
    { ".0000000001e10", 14,	1, 0 },
    { ".00000000001e11", 15,	1, 0 },
    { ".000000000001e12", 16,	1, 0 },
    { ".0000000000001e13", 17,	1, 0 },
    { ".00000000000001e14", 18,	1, 0 },
    { ".000000000000001e15", 19, 1, 0 },

    { "100000001e-8", 12,	1, 0 },
    { "100000004e-8", 12,	1, 0 },
/*  { "1000000033e-9", 13,	1, 0 },	--> 0x3f800001	today	*/
    { "1000000032e-9", 13,	1, 0 },
    { "10000000329e-10", 15,	1, 0 },
    { "100000003299e-11", 16,	1, 0 },
    { "1000000032999e-12", 17,	1, 0 },
    { "10000000329999e-13", 18,	1, 0 },
    { "100000003299999e-14", 19, 1, 0 },
    
    { "99999998e-8", 11,	1, 0 },
    { "999999971e-9", 12,	1, 0 },
    { "9999999702e-10", 14,	1, 0 },
    { "99999997020e-11", 15,	1, 0 },
    { "999999970200e-12", 16,	1, 0 },
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
    char s [sizeof(t[0].s)];
    char *p;
    union lofl_u mst;
    unsigned char len;
    int eno;
    int i;
    
    for (i = 0; i < (int) (sizeof(t) / sizeof(t[0])); i++) {
	strcpy_P (s, t[i].s);
	len = pgm_read_byte (& t[i].len);
	mst.fl = pgm_read_float (& t[i].val);
	eno = pgm_read_word (& t[i].eno);
	
	errno = 0;
	p = 0;
	v.fl = strtod (s, &p);
	
	if (!p || (p - s) != len || errno != eno)
	    x_exit (i+1);
	if (isnan(mst.fl) && isnan(v.fl))
	    continue;
	if (v.lo != mst.lo)
	    x_exit (i+1);
    }
    return 0;
}
