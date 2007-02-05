/* Test of fmod() function. NaNs.
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
    union lofl_u x, y;		/* args.	*/
} t[] = {

    /* fmod (finite, 0) --> NaN	*/
    { { 0x00000001 }, { 0x00000000 } },
    { { 0x007fffff }, { 0x00000000 } },
    { { 0x00800000 }, { 0x00000000 } },
    { { 0x7f7fffff }, { 0x00000000 } },
    { { 0x3f800000 }, { 0x80000000 } },
    { { 0xbf800000 }, { 0x00000000 } },
    { { 0xbf800000 }, { 0x80000000 } },
    
    /* fmod (Inf, 0) --> NaN	*/
    { { 0x7f800000 }, { 0x00000000 } },
    { { 0x7f800000 }, { 0x80000000 } },
    { { 0xff800000 }, { 0x00000000 } },
    { { 0xff800000 }, { 0x80000000 } },
    
    /* fmod (Inf, Inf) --> NaN	*/
    { { 0x7f800000 }, { 0x7f800000 } },
    { { 0x7f800000 }, { 0xff800000 } },
    { { 0xff800000 }, { 0x7f800000 } },
    { { 0xff800000 }, { 0xff800000 } },

    /* fmod (NaN, 1) --> NaN	*/
    { { 0x7f800001 }, { 0x3f800000 } },
    { { 0x7f800100 }, { 0x3f800000 } },
    { { 0x7f810000 }, { 0x3f800000 } },
    { { 0x7fc00000 }, { 0x3f800000 } },
    { { 0x7fffffff }, { 0x3f800000 } },
    { { 0xff800001 }, { 0x3f800000 } },
    { { 0xff800100 }, { 0x3f800000 } },
    { { 0xff810000 }, { 0x3f800000 } },
    { { 0xffc00000 }, { 0x3f800000 } },
    { { 0xffffffff }, { 0x3f800000 } },

    /* fmod (1, NaN) --> NaN	*/
    { { 0x3f800000 }, { 0x7f800001 } },
    { { 0x3f800000 }, { 0x7f800100 } },
    { { 0x3f800000 }, { 0x7f810000 } },
    { { 0x3f800000 }, { 0x7fc00000 } },
    { { 0x3f800000 }, { 0x7fffffff } },
    { { 0x3f800000 }, { 0xff800001 } },
    { { 0x3f800000 }, { 0xff800100 } },
    { { 0x3f800000 }, { 0xff810000 } },
    { { 0x3f800000 }, { 0xffc00000 } },
    { { 0x3f800000 }, { 0xffffffff } },
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
    union lofl_u x, y;
    int i;
    
    for (i = 0; i < (int) (sizeof(t) / sizeof(t[0])); i++) {
	x.lo = pgm_read_dword (& t[i].x);
	y.lo = pgm_read_dword (& t[i].y);
	v.fl = fmod (x.fl, y.fl);
	if (!isnan(v.fl))
	    x_exit (i+1);
    }
    return 0;
}
