/* Test of ceil() function.
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
    union lofl_u z;		/* ceil(x)	*/
} t[] = {

    /* Zero	*/
    { { .fl= +0.0 },	{ .fl= +0.0 }	},
    { { .fl= -0.0 },	{ .fl= -0.0 }	},

    /* Normal	*/
    { { .fl= 0.1 },		{ .fl= 1.0 }	},
    { { .fl= 1.9 },		{ .fl= 2.0 }	},
    { { .fl= 1000000.5 },	{ .fl= 1000001.0 } },
    { { .fl= -0.1 },		{ .fl= -0.0 }	},
    { { .fl= -1.9 },		{ .fl= -1.0 }	},
    { { .fl= -1000000.5 },	{ .fl= -1000000.0 } },

    /* Inf	*/
    { { 0x7f800000 },	{ 0x7f800000 } },
    { { 0xff800000 },	{ 0xff800000 } },
    
    /* Subnormal	*/
    { { 0x00000001 }, { .fl= 1.0 } },
    { { 0x00000100 }, { .fl= 1.0 } },
    { { 0x00010000 }, { .fl= 1.0 } },
    { { 0x007fffff }, { .fl= 1.0 } },
    { { 0x80000001 }, { .fl= -0.0 } },
    { { 0x80000100 }, { .fl= -0.0 } },
    { { 0x80010000 }, { .fl= -0.0 } },
    { { 0x807fffff }, { .fl= -0.0 } },
    
    /* Margin values	*/
    { { 0x3f7fffff }, { .fl= 1.0 } },
    { { 0x3f800000 }, { .fl= 1.0 } },
    { { 0x3f800001 }, { .fl= 2.0 } },
    { { 0x3fffffff }, { .fl= 2.0 } },
    { { 0x40000000 }, { .fl= 2.0 } },
    { { 0x40000001 }, { .fl= 3.0 } },
    { { 0x403fffff }, { .fl= 3.0 } },
    { { .fl= 0x0.ffffffp+23 }, { .fl= 0x1.000000p+23 } },
    { { .fl= 0x1.000000p+23 }, { .fl= 0x1.000000p+23 } },
    { { 0x7f7fffff }, { 0x7f7fffff } },

    { { 0xbf7fffff }, { .fl= -0.0 } },
    { { 0xbf800000 }, { .fl= -1.0 } },
    { { 0xbf800001 }, { .fl= -1.0 } },
    { { 0xbfffffff }, { .fl= -1.0 } },
    { { 0xc0000000 }, { .fl= -2.0 } },
    { { 0xc0000001 }, { .fl= -2.0 } },
    { { 0xc03fffff }, { .fl= -2.0 } },
    { { .fl= -0x0.ffffffp+23 }, { .fl= -0x0.fffffep+23 } },
    { { .fl= -0x1.000000p+23 }, { .fl= -0x1.000000p+23 } },
    { { 0xff7fffff }, { 0xff7fffff } },
    
    /* All possible shifts	*/
    { { .fl= -0x0.ffffffp+00 }, { .fl= -0.0 } },
    { { .fl= -0x0.ffffffp+01 }, { .fl= -0x1p+00 } },
    { { .fl= -0x0.ffffffp+02 }, { .fl= -0x3p+00 } },
    { { .fl= -0x0.ffffffp+03 }, { .fl= -0x7p+00 } },
    { { .fl= -0x0.ffffffp+04 }, { .fl= -0xfp+00 } },
    { { .fl= -0x0.ffffffp+05 }, { .fl= -0x1fp+00 } },
    { { .fl= -0x0.ffffffp+06 }, { .fl= -0x3fp+00 } },
    { { .fl= -0x0.ffffffp+07 }, { .fl= -0x7fp+00 } },
    { { .fl= -0x0.ffffffp+08 }, { .fl= -0xffp+00 } },
    { { .fl= -0x0.ffffffp+09 }, { .fl= -0x1ffp+00 } },
    { { .fl= -0x0.ffffffp+10 }, { .fl= -0x3ffp+00 } },
    { { .fl= -0x0.ffffffp+11 }, { .fl= -0x7ffp+00 } },
    { { .fl= -0x0.ffffffp+12 }, { .fl= -0xfffp+00 } },
    { { .fl= -0x0.ffffffp+13 }, { .fl= -0x1fffp+00 } },
    { { .fl= -0x0.ffffffp+14 }, { .fl= -0x3fffp+00 } },
    { { .fl= -0x0.ffffffp+15 }, { .fl= -0x7fffp+00 } },
    { { .fl= -0x0.ffffffp+16 }, { .fl= -0xffffp+00 } },
    { { .fl= -0x0.ffffffp+17 }, { .fl= -0x1ffffp+00 } },
    { { .fl= -0x0.ffffffp+18 }, { .fl= -0x3ffffp+00 } },
    { { .fl= -0x0.ffffffp+19 }, { .fl= -0x7ffffp+00 } },
    { { .fl= -0x0.ffffffp+20 }, { .fl= -0xfffffp+00 } },
    { { .fl= -0x0.ffffffp+21 }, { .fl= -0x1fffffp+00 } },
    { { .fl= -0x0.ffffffp+22 }, { .fl= -0x3fffffp+00 } },
    { { .fl= -0x0.ffffffp+23 }, { .fl= -0x7fffffp+00 } },
    { { .fl= -0x0.ffffffp+24 }, { .fl= -0xffffffp+00 } },
    { { .fl= -0x0.ffffffp+25 }, { .fl= -0xffffffp+01 } },
    { { .fl= -0x0.ffffffp+26 }, { .fl= -0xffffffp+02 } },
    { { .fl= -0x0.ffffffp+27 }, { .fl= -0xffffffp+03 } },
    { { .fl= -0x0.ffffffp+28 }, { .fl= -0xffffffp+04 } },
    { { .fl= -0x0.ffffffp+29 }, { .fl= -0xffffffp+05 } },

    /* All possible shifts with mantissa increment	*/
    { { .fl= 0x0.ffffffp+00 }, { .fl= 0x1p+00 } },
    { { .fl= 0x0.ffffffp+01 }, { .fl= 0x1p+01 } },
    { { .fl= 0x0.ffffffp+02 }, { .fl= 0x1p+02 } },
    { { .fl= 0x0.ffffffp+03 }, { .fl= 0x1p+03 } },
    { { .fl= 0x0.ffffffp+04 }, { .fl= 0x1p+04 } },
    { { .fl= 0x0.ffffffp+05 }, { .fl= 0x1p+05 } },
    { { .fl= 0x0.ffffffp+06 }, { .fl= 0x1p+06 } },
    { { .fl= 0x0.ffffffp+07 }, { .fl= 0x1p+07 } },
    { { .fl= 0x0.ffffffp+08 }, { .fl= 0x1p+08 } },
    { { .fl= 0x0.ffffffp+09 }, { .fl= 0x1p+09 } },
    { { .fl= 0x0.ffffffp+10 }, { .fl= 0x1p+10 } },
    { { .fl= 0x0.ffffffp+11 }, { .fl= 0x1p+11 } },
    { { .fl= 0x0.ffffffp+12 }, { .fl= 0x1p+12 } },
    { { .fl= 0x0.ffffffp+13 }, { .fl= 0x1p+13 } },
    { { .fl= 0x0.ffffffp+14 }, { .fl= 0x1p+14 } },
    { { .fl= 0x0.ffffffp+15 }, { .fl= 0x1p+15 } },
    { { .fl= 0x0.ffffffp+16 }, { .fl= 0x1p+16 } },
    { { .fl= 0x0.ffffffp+17 }, { .fl= 0x1p+17 } },
    { { .fl= 0x0.ffffffp+18 }, { .fl= 0x1p+18 } },
    { { .fl= 0x0.ffffffp+19 }, { .fl= 0x1p+19 } },
    { { .fl= 0x0.ffffffp+20 }, { .fl= 0x1p+20 } },
    { { .fl= 0x0.ffffffp+21 }, { .fl= 0x1p+21 } },
    { { .fl= 0x0.ffffffp+22 }, { .fl= 0x1p+22 } },
    { { .fl= 0x0.ffffffp+23 }, { .fl= 0x1p+23 } },
    { { .fl= 0x0.ffffffp+24 }, { .fl= 0x1.fffffep+23 } },
    { { .fl= 0x0.ffffffp+25 }, { .fl= 0x1.fffffep+24 } },
    { { .fl= 0x0.ffffffp+26 }, { .fl= 0x1.fffffep+25 } },
    { { .fl= 0x0.ffffffp+27 }, { .fl= 0x1.fffffep+26 } },
    { { .fl= 0x0.ffffffp+28 }, { .fl= 0x1.fffffep+27 } },
    { { .fl= 0x0.ffffffp+29 }, { .fl= 0x1.fffffep+28 } },
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
	v.fl = ceil (x.fl);
	/* Comparison is integer to verify the zero sign.	*/
	if (v.lo != z.lo)
	    x_exit (i+1);
    }
    return 0;
}
