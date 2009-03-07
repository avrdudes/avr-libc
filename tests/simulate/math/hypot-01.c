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

/* Test of hypot() function.
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

PROGMEM const struct {		/* Table of test cases	*/
    union lofl_u x, y;		/* args		*/
    union lofl_u z;		/* result	*/
} t[] = {

    /* NaN and NaN --> NaN	*/
    { { 0x7f800001 }, { 0x7f800100 }, { 0x7fc00000 } },
    { { 0x7f810001 }, { 0x7fc00000 }, { 0x7fc00000 } },
    { { 0x7fffffff }, { 0xff800001 }, { 0x7fc00000 } },
    { { 0xff800100 }, { 0x7f800100 }, { 0x7fc00000 } },

    /* NaN and finite --> NaN	*/
    { { 0x7f800001 }, { 0x3f800000 }, { 0x7fc00000 } },
    { { 0x3f800000 }, { 0x7f800001 }, { 0x7fc00000 } },

    /* Inf & NaN --> Inf	*/
    { { 0x7f800000 }, { 0x7f800001 }, { 0x7f800000 } },
    { { 0x7f800000 }, { 0x7f800100 }, { 0x7f800000 } },
    { { 0x7f800000 }, { 0x7f810000 }, { 0x7f800000 } },
    { { 0x7f800000 }, { 0x7fc00000 }, { 0x7f800000 } },
    { { 0x7f800000 }, { 0x7fffffff }, { 0x7f800000 } },
    { { 0x7f800000 }, { 0xffffffff }, { 0x7f800000 } },
    
    { { 0xff800000 }, { 0x7fc00000 }, { 0x7f800000 } },
    { { 0x7fc00000 }, { 0x7f800000 }, { 0x7f800000 } },
    { { 0x7fc00000 }, { 0xff800000 }, { 0x7f800000 } },
    
    /* 0 and 0	*/
    { { 0x00000000 }, { 0x00000000 }, { 0x00000000 } },
    { { 0x80000000 }, { 0x00000000 }, { 0x00000000 } },
    { { 0x00000000 }, { 0x80000000 }, { 0x00000000 } },
    { { 0x80000000 }, { 0x80000000 }, { 0x00000000 } },

    /* hypot(0,*)	*/
    { { 0 }, { 0x00000001 }, { 0x00000001 } },
    { { 0 }, { 0x007fffff }, { 0x007fffff } },
    { { 0 }, { 0x00800000 }, { 0x00800000 } },
    { { 0 }, { 0x3f800000 }, { 0x3f800000 } },
    { { 0 }, { 0x7f7fffff }, { 0x7f7fffff } },
    { { 0 }, { 0x7f800000 }, { 0x7f800000 } },	/* Inf	*/

    /* hypot(*,0)	*/
    { { 0x00000001 }, { 0 }, { 0x00000001 } },
    { { 0x007fffff }, { 0 }, { 0x007fffff } },
    { { 0x00800000 }, { 0 }, { 0x00800000 } },
    { { 0x3f800000 }, { 0 }, { 0x3f800000 } },
    { { 0x7f7fffff }, { 0 }, { 0x7f7fffff } },
    { { 0x7f800000 }, { 0 }, { 0x7f800000 } },	/* Inf	*/
    
    /* overflow	*/
    { { 0x7f7fffff }, { 0x7f7fffff }, { 0x7f800000 } },
    { { 0xff7fffff }, { 0xff7fffff }, { 0x7f800000 } },
/*  { { .fl= 2.4061596e+38 }, { .fl= 2.4061596e+38 }, { 0x7f800000 } }, */
    { { .fl= 2.4061598e+38 }, { .fl= 2.4061598e+38 }, { 0x7f800000 } },
    
    { { .fl=  3 }, { .fl=  4 }, { .fl= 5 } },
    { { .fl= -3 }, { .fl=  4 }, { .fl= 5 } },
    { { .fl=  3 }, { .fl= -4 }, { .fl= 5 } },
    { { .fl= -3 }, { .fl= -4 }, { .fl= 5 } },

    /* very small args	*/    
    { { 0x00000001 }, { 0x00000001 }, { 0x00000001 } },		/* 1.4	*/
    { { 0x00000001 }, { 0x00000002 }, { 0x00000002 } },		/* 2.2	*/
    { { 0x00000002 }, { 0x00000001 }, { 0x00000002 } },		/* 2.2	*/
    { { 0x00000002 }, { 0x00000002 }, { 0x00000003 } },		/* 2.8	*/
    
    /* very big args	*/
    { { .fl= 2.4061596e+38 }, { .fl= 2.4061595e+38 }, { 0x7f7fffff } },
    { { .fl= 2.4061595e+38 }, { .fl= 2.4061596e+38 }, { 0x7f7fffff } },
    
    /* x >> y	*/
    { { .fl= 1 }, { .fl= 0x0.8p-9 },  { 0x3f800004 } },
    { { .fl= 1 }, { .fl= 0x0.8p-10 }, { 0x3f800001 } },
    { { .fl= 1 }, { .fl= 0x0.8p-11 }, { 0x3f800000 } },
    { { .fl= 1 }, { .fl= 0x0.8p-12 }, { 0x3f800000 } },
    { { .fl= 1 }, { .fl= 0x0.8p-13 }, { 0x3f800000 } },
    
    { { .fl= 0x0.800001p0 }, { .fl= 0x0.ffffffp-10 }, { 0x3f000011 } },
    { { .fl= 0x0.800001p0 }, { .fl= 0x0.ffffffp-11 }, { 0x3f000005 } },
    { { .fl= 0x0.800001p0 }, { .fl= 0x0.ffffffp-12 }, { 0x3f000002 } },
    { { .fl= 0x0.800001p0 }, { .fl= 0x0.ffffffp-13 }, { 0x3f000001 } },
    { { .fl= 0x0.800001p0 }, { .fl= 0x0.ffffffp-14 }, { 0x3f000001 } },
    { { .fl= 0x0.800001p0 }, { .fl= 0x0.ffffffp-15 }, { 0x3f000001 } },

    /* x << y	*/
    { { .fl= 0x0.8p-9 },  { .fl= 1 }, { 0x3f800004 } },
    { { .fl= 0x0.8p-10 }, { .fl= 1 }, { 0x3f800001 } },
    { { .fl= 0x0.8p-11 }, { .fl= 1 }, { 0x3f800000 } },
    { { .fl= 0x0.8p-12 }, { .fl= 1 }, { 0x3f800000 } },
    { { .fl= 0x0.8p-13 }, { .fl= 1 }, { 0x3f800000 } },
    
    { { .fl= 0x0.ffffffp-10 }, { .fl= 0x0.800001p0 }, { 0x3f000011 } },
    { { .fl= 0x0.ffffffp-11 }, { .fl= 0x0.800001p0 }, { 0x3f000005 } },
    { { .fl= 0x0.ffffffp-12 }, { .fl= 0x0.800001p0 }, { 0x3f000002 } },
    { { .fl= 0x0.ffffffp-13 }, { .fl= 0x0.800001p0 }, { 0x3f000001 } },
    { { .fl= 0x0.ffffffp-14 }, { .fl= 0x0.800001p0 }, { 0x3f000001 } },
    { { .fl= 0x0.ffffffp-15 }, { .fl= 0x0.800001p0 }, { 0x3f000001 } },

    /* a set of scales	*/    
    { { 0x00000003 }, { 0x00000004 }, { 0x00000005 } },
    { { .fl= 0x0.3p-140 }, { .fl= 0x0.4p-140 }, { .fl= 0x0.5p-140 } },
    { { .fl= 0x0.3p-120 }, { .fl= 0x0.4p-120 }, { .fl= 0x0.5p-120 } },
    { { .fl= 0x0.3p-100 }, { .fl= 0x0.4p-100 }, { .fl= 0x0.5p-100 } },
    { { .fl= 0x0.3p-80 },  { .fl= 0x0.4p-80 },  { .fl= 0x0.5p-80 }  },
    { { .fl= 0x0.3p-60 },  { .fl= 0x0.4p-60 },  { .fl= 0x0.5p-60 }  },
    { { .fl= 0x0.3p-40 },  { .fl= 0x0.4p-40 },  { .fl= 0x0.5p-40 }  },
    { { .fl= 0x0.3p-20 },  { .fl= 0x0.4p-20 },  { .fl= 0x0.5p-20 }  },
    { { .fl= 0x0.3p+0 },   { .fl= 0x0.4p+0 },   { .fl= 0x0.5p+0 }   },
    { { .fl= 0x0.3p+20 },  { .fl= 0x0.4p+20 },  { .fl= 0x0.5p+20 }  },
    { { .fl= 0x0.3p+40 },  { .fl= 0x0.4p+40 },  { .fl= 0x0.5p+40 }  },
    { { .fl= 0x0.3p+60 },  { .fl= 0x0.4p+60 },  { .fl= 0x0.5p+60 }  },
    { { .fl= 0x0.3p+80 },  { .fl= 0x0.4p+80 },  { .fl= 0x0.5p+80 }  },
    { { .fl= 0x0.3p+100 }, { .fl= 0x0.4p+100 }, { .fl= 0x0.5p+100 } },
    { { .fl= 0x0.3p+120 }, { .fl= 0x0.4p+120 }, { .fl= 0x0.5p+120 } },
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
	y.lo = pgm_read_dword (& t[i].y);
	x.lo = pgm_read_dword (& t[i].x);
	z.lo = pgm_read_dword (& t[i].z);
	v.fl = hypot (x.fl, y.fl);
	
	if (   v.lo == z.lo
	    || (isnan(v.fl) && isnan(z.fl))	)
	  continue;
	x_exit (i+1);
    }
    return 0;
}
