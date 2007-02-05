/* Test of fmax() function.
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

    /* fmax (0,0)	*/
    { { .fl=  0.0 }, { .fl=  0.0 }, { .fl=  0.0 } },
    { { .fl=  0.0 }, { .fl= -0.0 }, { .fl=  0.0 } },
    { { .fl= -0.0 }, { .fl= -0.0 }, { .fl= -0.0 } },
#ifdef	__AVR__
    { { .fl= -0.0 }, { .fl=  0.0 }, { .fl=  0.0 } },	/* Glibc: --> -0.0 */
#endif

    /* fmax (NaN, finite)	*/
    { { 0x7f800001 }, { 0x7f7fffff }, { 0x7f7fffff } },
    { { 0x7f800100 }, { 0xff7fffff }, { 0xff7fffff } },
    { { 0x7f810000 }, { 0x00000001 }, { 0x00000001 } },
    { { 0x7fc00000 }, { 0x80000001 }, { 0x80000001 } },
    { { 0x7ffffffe }, { 0x00000000 }, { 0x00000000 } },
    { { 0x7fffffff }, { 0x80000000 }, { 0x80000000 } },

    { { 0xff800001 }, { 0x7f7fffff }, { 0x7f7fffff } },
    { { 0xff800100 }, { 0xff7fffff }, { 0xff7fffff } },
    { { 0xff810000 }, { 0x00000001 }, { 0x00000001 } },
    { { 0xffc00000 }, { 0x80000001 }, { 0x80000001 } },
    { { 0xfffffffe }, { 0x00000000 }, { 0x00000000 } },
    { { 0xffffffff }, { 0x80000000 }, { 0x80000000 } },

    /* fmax (finite, NaN)	*/
    { { 0x7f7fffff }, { 0x7f800001 }, { 0x7f7fffff } },
    { { 0xff7fffff }, { 0x7f800100 }, { 0xff7fffff } },
    { { 0x00000001 }, { 0x7f810000 }, { 0x00000001 } },
    { { 0x80000001 }, { 0x7fc00000 }, { 0x80000001 } },
    { { 0x00000000 }, { 0x7ffffffe }, { 0x00000000 } },
    { { 0x80000000 }, { 0x7fffffff }, { 0x80000000 } },

    { { 0x7f7fffff }, { 0xff800001 }, { 0x7f7fffff } },
    { { 0xff7fffff }, { 0xff800100 }, { 0xff7fffff } },
    { { 0x00000001 }, { 0xff810000 }, { 0x00000001 } },
    { { 0x80000001 }, { 0xffc00000 }, { 0x80000001 } },
    { { 0x00000000 }, { 0xfffffffe }, { 0x00000000 } },
    { { 0x80000000 }, { 0xffffffff }, { 0x80000000 } },
    
    /* fmax (NaN, Inf)	*/
    { { 0x7f800001 }, { 0x7f800000 }, { 0x7f800000 } },
    { { 0x7f800001 }, { 0xff800000 }, { 0xff800000 } },
    { { 0xff800001 }, { 0x7f800000 }, { 0x7f800000 } },
    { { 0xff800001 }, { 0xff800000 }, { 0xff800000 } },
    { { 0x7fffffff }, { 0x7f800000 }, { 0x7f800000 } },
    { { 0x7fffffff }, { 0xff800000 }, { 0xff800000 } },
    { { 0xffffffff }, { 0x7f800000 }, { 0x7f800000 } },
    { { 0xffffffff }, { 0xff800000 }, { 0xff800000 } },

    /* fmax (Inf, NaN)	*/
    { { 0x7f800000 }, { 0x7f800001 }, { 0x7f800000 } },
    { { 0xff800000 }, { 0x7f800001 }, { 0xff800000 } },
    { { 0x7f800000 }, { 0xff800001 }, { 0x7f800000 } },
    { { 0xff800000 }, { 0xff800001 }, { 0xff800000 } },
    { { 0x7f800000 }, { 0x7fffffff }, { 0x7f800000 } },
    { { 0xff800000 }, { 0x7fffffff }, { 0xff800000 } },
    { { 0x7f800000 }, { 0xffffffff }, { 0x7f800000 } },
    { { 0xff800000 }, { 0xffffffff }, { 0xff800000 } },

    /* fmax (NaN, NaN)	*/
    { { 0x7f800001 }, { 0x7fffffff }, { 0x7fffffff } },
    { { 0xffffffff }, { 0xff800001 }, { 0xff800001 } },
    
    /* fmax (Inf, Inf)	*/
    { { 0x7f800000 }, { 0x7f800000 }, { 0x7f800000 } },
    { { 0xff800000 }, { 0x7f800000 }, { 0x7f800000 } },
    { { 0x7f800000 }, { 0xff800000 }, { 0x7f800000 } },
    { { 0xff800000 }, { 0xff800000 }, { 0xff800000 } },

    /* fmax (+Inf, finite)	*/
    { { 0x7f800000 }, { 0x7f7fffff }, { 0x7f800000 } },
    { { 0x7f800000 }, { 0xff7fffff }, { 0x7f800000 } },
    
    /* fmax (-Inf, finite)	*/
    { { 0xff800000 }, { 0x7f7fffff }, { 0x7f7fffff } },
    { { 0xff800000 }, { 0xff7fffff }, { 0xff7fffff } },

    /* fmax (finite, +Inf)	*/
    { { 0x7f7fffff }, { 0x7f800000 }, { 0x7f800000 } },
    { { 0xff7fffff }, { 0x7f800000 }, { 0x7f800000 } },
    
    /* fmax (finite, -Inf)	*/
    { { 0x7f7fffff }, { 0xff800000 }, { 0x7f7fffff } },
    { { 0xff7fffff }, { 0xff800000 }, { 0xff7fffff } },
    
    /* x == y	*/
    { { 0x12345678 }, { 0x12345678 }, { 0x12345678 } },
    
    /* x < y	*/
    { { 0xff7fffff }, { 0xff7ffffe }, { 0xff7ffffe } },
    { { 0x80000002 }, { 0x00000001 }, { 0x00000001 } },
    { { 0x7f7ffffe }, { 0x7f7fffff }, { 0x7f7fffff } },
    
    /* x > y	*/
    { { 0xff7ffffe }, { 0xff7fffff }, { 0xff7ffffe } },
    { { 0x00000000 }, { 0x80000001 }, { 0x00000000 } },
    { { 0x7f7fffff }, { 0x7f7ffffe }, { 0x7f7fffff } },
    
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
	v.fl = fmax (x.fl, y.fl);
	
	if (   v.lo == z.lo
	    || (isnan(v.fl) && isnan(z.fl))	)
	  continue;
	x_exit (i+1);
    }
    return 0;
}
