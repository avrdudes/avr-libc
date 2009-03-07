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

/* Test of float comparison, finite values.
   $Id$
 */
#include <stdio.h>
#include <stdlib.h>
#include "progmem.h"

union lofl_u {
    long lo;
    float fl;
};

PROGMEM const struct {		/* Table of test cases.	*/
    union lofl_u x, y;
    unsigned char ne;	/* x != y */
    unsigned char lt;	/* x < y  */
    unsigned char le;	/* x <= y */
    unsigned char eq;	/* x == y */
    unsigned char ge;	/* x >= y */
    unsigned char gt;	/* x > y  */
} t[] = {

    /* 0.0 and 0.0	*/
    { { 0x00000000 }, { 0x00000000 }, 0, 0, 1, 1, 1, 0	},
    { { 0x00000000 }, { 0x80000000 }, 0, 0, 1, 1, 1, 0	},
    { { 0x80000000 }, { 0x00000000 }, 0, 0, 1, 1, 1, 0	},
    { { 0x80000000 }, { 0x80000000 }, 0, 0, 1, 1, 1, 0	},
    
    /* 0.0 and nonzero	*/
    { { 0x00000000 }, { 0x00000001 }, 1, 1, 1, 0, 0, 0	},
    { { 0x00000000 }, { 0x007fffff }, 1, 1, 1, 0, 0, 0	},
    { { 0x00000000 }, { 0x00800000 }, 1, 1, 1, 0, 0, 0	},
    { { 0x00000000 }, { 0x7f7fffff }, 1, 1, 1, 0, 0, 0	},
    { { 0x00000000 }, { 0x80000001 }, 1, 0, 0, 0, 1, 1	},
    { { 0x00000000 }, { 0x807fffff }, 1, 0, 0, 0, 1, 1	},
    { { 0x00000000 }, { 0x80800000 }, 1, 0, 0, 0, 1, 1	},
    { { 0x00000000 }, { 0xff7fffff }, 1, 0, 0, 0, 1, 1	},

    /* -0.0 and nonzero	*/
    { { 0x80000000 }, { 0x00000001 }, 1, 1, 1, 0, 0, 0	},
    { { 0x80000000 }, { 0x007fffff }, 1, 1, 1, 0, 0, 0	},
    { { 0x80000000 }, { 0x00800000 }, 1, 1, 1, 0, 0, 0	},
    { { 0x80000000 }, { 0x7f7fffff }, 1, 1, 1, 0, 0, 0	},
    { { 0x80000000 }, { 0x80000001 }, 1, 0, 0, 0, 1, 1	},
    { { 0x80000000 }, { 0x807fffff }, 1, 0, 0, 0, 1, 1	},
    { { 0x80000000 }, { 0x80800000 }, 1, 0, 0, 0, 1, 1	},
    { { 0x80000000 }, { 0xff7fffff }, 1, 0, 0, 0, 1, 1	},
    
    /* nonzero and 0.0	*/
    { { 0x00000001 }, { 0x00000000 }, 1, 0, 0, 0, 1, 1	},
    { { 0x007fffff }, { 0x00000000 }, 1, 0, 0, 0, 1, 1	},
    { { 0x00800000 }, { 0x00000000 }, 1, 0, 0, 0, 1, 1	},
    { { 0x7f7fffff }, { 0x00000000 }, 1, 0, 0, 0, 1, 1	},
    { { 0x80000001 }, { 0x00000000 }, 1, 1, 1, 0, 0, 0	},
    { { 0x807fffff }, { 0x00000000 }, 1, 1, 1, 0, 0, 0	},
    { { 0x80800000 }, { 0x00000000 }, 1, 1, 1, 0, 0, 0	},
    { { 0xff7fffff }, { 0x00000000 }, 1, 1, 1, 0, 0, 0	},

    /* nonzero and -0.0	*/
    { { 0x00000001 }, { 0x80000000 }, 1, 0, 0, 0, 1, 1	},
    { { 0x007fffff }, { 0x80000000 }, 1, 0, 0, 0, 1, 1	},
    { { 0x00800000 }, { 0x80000000 }, 1, 0, 0, 0, 1, 1	},
    { { 0x7f7fffff }, { 0x80000000 }, 1, 0, 0, 0, 1, 1	},
    { { 0x80000001 }, { 0x80000000 }, 1, 1, 1, 0, 0, 0	},
    { { 0x807fffff }, { 0x80000000 }, 1, 1, 1, 0, 0, 0	},
    { { 0x80800000 }, { 0x80000000 }, 1, 1, 1, 0, 0, 0	},
    { { 0xff7fffff }, { 0x80000000 }, 1, 1, 1, 0, 0, 0	},

    /* equal	*/
    { { 0x00000001 }, { 0x00000001 }, 0, 0, 1, 1, 1, 0	},
    { { 0x007fffff }, { 0x007fffff }, 0, 0, 1, 1, 1, 0	},
    { { 0x00800000 }, { 0x00800000 }, 0, 0, 1, 1, 1, 0	},
    { { 0x7f7fffff }, { 0x7f7fffff }, 0, 0, 1, 1, 1, 0	},
    { { 0x80000001 }, { 0x80000001 }, 0, 0, 1, 1, 1, 0	},
    { { 0x807fffff }, { 0x807fffff }, 0, 0, 1, 1, 1, 0	},
    { { 0x80800000 }, { 0x80800000 }, 0, 0, 1, 1, 1, 0	},
    { { 0xff7fffff }, { 0xff7fffff }, 0, 0, 1, 1, 1, 0	},
    
    /* different signs	*/
    { { 0x00000001 }, { 0x80000001 }, 1, 0, 0, 0, 1, 1	},
    { { 0x00000100 }, { 0x80000100 }, 1, 0, 0, 0, 1, 1	},
    { { 0x00010000 }, { 0x80010000 }, 1, 0, 0, 0, 1, 1	},
    { { 0x00800000 }, { 0x80800000 }, 1, 0, 0, 0, 1, 1	},
    { { 0x7f000000 }, { 0xff000000 }, 1, 0, 0, 0, 1, 1	},
    { { 0x7f7fffff }, { 0xff7fffff }, 1, 0, 0, 0, 1, 1	},
    { { 0x80000001 }, { 0x00000001 }, 1, 1, 1, 0, 0, 0	},
    { { 0x80000100 }, { 0x00000100 }, 1, 1, 1, 0, 0, 0	},
    { { 0x80010000 }, { 0x00010000 }, 1, 1, 1, 0, 0, 0	},
    { { 0x80800000 }, { 0x00800000 }, 1, 1, 1, 0, 0, 0	},
    { { 0xff000000 }, { 0x7f000000 }, 1, 1, 1, 0, 0, 0	},
    { { 0xff7fffff }, { 0x7f7fffff }, 1, 1, 1, 0, 0, 0	},
    
    /* slitely diffirent values	*/
    { { 0x00000003 }, { 0x00000001 }, 1, 0, 0, 0, 1, 1	},
    { { 0x00000300 }, { 0x00000100 }, 1, 0, 0, 0, 1, 1	},
    { { 0x00030000 }, { 0x00010000 }, 1, 0, 0, 0, 1, 1	},
    { { 0x00c00000 }, { 0x00800000 }, 1, 0, 0, 0, 1, 1	},
    { { 0x03000000 }, { 0x01000000 }, 1, 0, 0, 0, 1, 1	},
    { { 0x60000000 }, { 0x20000000 }, 1, 0, 0, 0, 1, 1	},
    { { 0x00000001 }, { 0x00000003 }, 1, 1, 1, 0, 0, 0	},
    { { 0x00000100 }, { 0x00000300 }, 1, 1, 1, 0, 0, 0	},
    { { 0x00010000 }, { 0x00030000 }, 1, 1, 1, 0, 0, 0	},
    { { 0x00800000 }, { 0x00c00000 }, 1, 1, 1, 0, 0, 0	},
    { { 0x01000000 }, { 0x03000000 }, 1, 1, 1, 0, 0, 0	},
    { { 0x20000000 }, { 0x60000000 }, 1, 1, 1, 0, 0, 0	},

    /* x < y	*/
    { { 0xff7fffff }, { 0xff7ffffe }, 1, 1, 1, 0, 0, 0	},
    { { 0xff7fffff }, { 0x80800000 }, 1, 1, 1, 0, 0, 0	},
    { { 0xff7fffff }, { 0x807fffff }, 1, 1, 1, 0, 0, 0	},
    { { 0xff7fffff }, { 0x80000001 }, 1, 1, 1, 0, 0, 0	},
    { { 0xff7fffff }, { 0x00000001 }, 1, 1, 1, 0, 0, 0	},
    { { 0xff7fffff }, { 0x007fffff }, 1, 1, 1, 0, 0, 0	},
    { { 0xff7fffff }, { 0x00800000 }, 1, 1, 1, 0, 0, 0	},
    { { 0xff7fffff }, { 0x7f7fffff }, 1, 1, 1, 0, 0, 0	},
    { { 0x80800000 }, { 0x807fffff }, 1, 1, 1, 0, 0, 0	},
    { { 0x80800000 }, { 0x80000001 }, 1, 1, 1, 0, 0, 0	},
    { { 0x80800000 }, { 0x00000001 }, 1, 1, 1, 0, 0, 0	},
    { { 0x80800000 }, { 0x007fffff }, 1, 1, 1, 0, 0, 0	},
    { { 0x80800000 }, { 0x00800000 }, 1, 1, 1, 0, 0, 0	},
    { { 0x80800000 }, { 0x7f7fffff }, 1, 1, 1, 0, 0, 0	},
    { { 0x807fffff }, { 0x807ffffe }, 1, 1, 1, 0, 0, 0	},
    { { 0x807fffff }, { 0x80000001 }, 1, 1, 1, 0, 0, 0	},
    { { 0x807fffff }, { 0x00000001 }, 1, 1, 1, 0, 0, 0	},
    { { 0x807fffff }, { 0x007fffff }, 1, 1, 1, 0, 0, 0	},
    { { 0x807fffff }, { 0x00800000 }, 1, 1, 1, 0, 0, 0	},
    { { 0x807fffff }, { 0x7f7fffff }, 1, 1, 1, 0, 0, 0	},
    { { 0x80000001 }, { 0x00000001 }, 1, 1, 1, 0, 0, 0	},
    { { 0x80000001 }, { 0x007fffff }, 1, 1, 1, 0, 0, 0	},
    { { 0x80000001 }, { 0x00800000 }, 1, 1, 1, 0, 0, 0	},
    { { 0x80000001 }, { 0x7f7fffff }, 1, 1, 1, 0, 0, 0	},
    { { 0x00000001 }, { 0x00000002 }, 1, 1, 1, 0, 0, 0	},
    { { 0x00000001 }, { 0x007fffff }, 1, 1, 1, 0, 0, 0	},
    { { 0x00000001 }, { 0x00800000 }, 1, 1, 1, 0, 0, 0	},
    { { 0x00000001 }, { 0x7f7fffff }, 1, 1, 1, 0, 0, 0	},
    { { 0x007fffff }, { 0x00800000 }, 1, 1, 1, 0, 0, 0	},
    { { 0x007fffff }, { 0x7f7fffff }, 1, 1, 1, 0, 0, 0	},
    { { 0x00800000 }, { 0x00800001 }, 1, 1, 1, 0, 0, 0	},
    { { 0x00800000 }, { 0x7f7fffff }, 1, 1, 1, 0, 0, 0	},
    { { 0x7f7ffffe }, { 0x7f7fffff }, 1, 1, 1, 0, 0, 0	},

    /* x > y	*/
    { { 0xff7ffffe }, { 0xff7fffff }, 1, 0, 0, 0, 1, 1	},
    { { 0x80800000 }, { 0xff7fffff }, 1, 0, 0, 0, 1, 1	},
    { { 0x807fffff }, { 0xff7fffff }, 1, 0, 0, 0, 1, 1	},
    { { 0x80000001 }, { 0xff7fffff }, 1, 0, 0, 0, 1, 1	},
    { { 0x00000001 }, { 0xff7fffff }, 1, 0, 0, 0, 1, 1	},
    { { 0x007fffff }, { 0xff7fffff }, 1, 0, 0, 0, 1, 1	},
    { { 0x00800000 }, { 0xff7fffff }, 1, 0, 0, 0, 1, 1	},
    { { 0x7f7fffff }, { 0xff7fffff }, 1, 0, 0, 0, 1, 1	},
    { { 0x807fffff }, { 0x80800000 }, 1, 0, 0, 0, 1, 1	},
    { { 0x80000001 }, { 0x80800000 }, 1, 0, 0, 0, 1, 1	},
    { { 0x00000001 }, { 0x80800000 }, 1, 0, 0, 0, 1, 1	},
    { { 0x007fffff }, { 0x80800000 }, 1, 0, 0, 0, 1, 1	},
    { { 0x00800000 }, { 0x80800000 }, 1, 0, 0, 0, 1, 1	},
    { { 0x7f7fffff }, { 0x80800000 }, 1, 0, 0, 0, 1, 1	},
    { { 0x807ffffe }, { 0x807fffff }, 1, 0, 0, 0, 1, 1	},
    { { 0x80000001 }, { 0x807fffff }, 1, 0, 0, 0, 1, 1	},
    { { 0x00000001 }, { 0x807fffff }, 1, 0, 0, 0, 1, 1	},
    { { 0x007fffff }, { 0x807fffff }, 1, 0, 0, 0, 1, 1	},
    { { 0x00800000 }, { 0x807fffff }, 1, 0, 0, 0, 1, 1	},
    { { 0x7f7fffff }, { 0x807fffff }, 1, 0, 0, 0, 1, 1	},
    { { 0x00000001 }, { 0x80000001 }, 1, 0, 0, 0, 1, 1	},
    { { 0x007fffff }, { 0x80000001 }, 1, 0, 0, 0, 1, 1	},
    { { 0x00800000 }, { 0x80000001 }, 1, 0, 0, 0, 1, 1	},
    { { 0x7f7fffff }, { 0x80000001 }, 1, 0, 0, 0, 1, 1	},
    { { 0x00000002 }, { 0x00000001 }, 1, 0, 0, 0, 1, 1	},
    { { 0x007fffff }, { 0x00000001 }, 1, 0, 0, 0, 1, 1	},
    { { 0x00800000 }, { 0x00000001 }, 1, 0, 0, 0, 1, 1	},
    { { 0x7f7fffff }, { 0x00000001 }, 1, 0, 0, 0, 1, 1	},
    { { 0x00800000 }, { 0x007fffff }, 1, 0, 0, 0, 1, 1	},
    { { 0x7f7fffff }, { 0x007fffff }, 1, 0, 0, 0, 1, 1	},
    { { 0x00800001 }, { 0x00800000 }, 1, 0, 0, 0, 1, 1	},
    { { 0x7f7fffff }, { 0x00800000 }, 1, 0, 0, 0, 1, 1	},
    { { 0x7f7fffff }, { 0x7f7ffffe }, 1, 0, 0, 0, 1, 1	},
    
    /* others	*/
    { { 0x000000ff }, { 0x00000100 }, 1, 1, 1, 0, 0, 0	},
    { { 0x0000ffff }, { 0x00010000 }, 1, 1, 1, 0, 0, 0	},
    { { 0x000000ff }, { 0x000000fe }, 1, 0, 0, 0, 1, 1	},
    { { 0x0000ffff }, { 0x0000fffe }, 1, 0, 0, 0, 1, 1	},
};

unsigned char cmpno = 255;		/* to debug	*/

void x_exit (int index, unsigned char no)
{
#ifndef	__AVR__
    fprintf (stderr, "t[%d]: no= %d\n", index - 1, no);
#endif
    cmpno = no;
    exit (index ? index : -1);
}

volatile union lofl_u x, y;

int main ()
{
    int i;
    
    for (i = 0; i < (int) (sizeof(t) / sizeof(t[0])); i++) {
	x.lo = pgm_read_dword (& t[i].x);
	y.lo = pgm_read_dword (& t[i].y);
	if ((x.fl != y.fl) != pgm_read_byte (& t[i].ne))
	    x_exit (i+1, 1);
	if ((x.fl < y.fl)  != pgm_read_byte (& t[i].lt))
	    x_exit (i+1, 2);
	if ((x.fl <= y.fl) != pgm_read_byte (& t[i].le))
	    x_exit (i+1, 3);
	if ((x.fl == y.fl) != pgm_read_byte (& t[i].eq))
	    x_exit (i+1, 4);
	if ((x.fl >= y.fl) != pgm_read_byte (& t[i].ge))
	    x_exit (i+1, 5);
	if ((x.fl > y.fl)  != pgm_read_byte (& t[i].gt))
	    x_exit (i+1, 6);
    }
    return 0;
}
