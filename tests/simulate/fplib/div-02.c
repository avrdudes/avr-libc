/* Test of division.  Subnormals.
   $Id$
 */
#include <stdio.h>
#include <stdlib.h>
#include "progmem.h"

union lofl_u {
    long lo;
    float fl;
};

volatile union lofl_u v = { .lo = 1 };

PROGMEM const struct {		/* Table of test cases:  x / y = z	*/
    union lofl_u x, y, z;
} t[] = {

    { { 0x00000001 }, { 0x00000001 }, { .fl = 1 } },
    { { 0x00000002 }, { 0x00000001 }, { .fl = 2 } },
    { { 0x00000003 }, { 0x00000001 }, { .fl = 3 } },
    { { 0x00000004 }, { 0x00000001 }, { .fl = 4 } },
    { { 0x007fffff }, { 0x00000001 }, { .fl = 0x0.7fffffp+24 } },
    { { 0x00800000 }, { 0x00000001 }, { .fl = 0x0.800000p+24 } },
    { { 0x00800001 }, { 0x00000001 }, { .fl = 0x0.800001p+24 } },
    { { 0x00800002 }, { 0x00000001 }, { .fl = 0x0.800002p+24 } },
    { { 0x00ffffff }, { 0x00000001 }, { .fl = 0x0.ffffffp+24 } },
    { { 0x01000000 }, { 0x00000001 }, { .fl = 0x0.800000p+25 } },
    { { 0x34fffffe }, { 0x00000001 }, { 0x7f7ffffe } },
    { { 0x34ffffff }, { 0x00000001 }, { 0x7f7fffff } },
    { { 0x35000000 }, { 0x00000001 }, { 0x7f800000 } },
    { { 0x35000001 }, { 0x00000001 }, { 0x7f800000 } },
    { { 0x7f7fffff }, { 0x00000001 }, { 0x7f800000 } },

    { { 0x00000001 }, { 0x00000001 }, { .fl = 1 } },
    { { 0x00000001 }, { 0x00000002 }, { .fl = 0.5 } },
    { { 0x00000001 }, { 0x00000003 }, { .fl = 0.33333333 } },
    { { 0x00000001 }, { 0x00000004 }, { .fl = 0.25 } },
    { { 0x00000001 }, { 0x00100000 }, { .fl = 0x1p-20 } },
    { { 0x00000001 }, { 0x00800000 }, { .fl = 0x1p-23 } },
    { { 0x00000001 }, { .fl = 1.0  }, { .fl = 0x1p-149 } },
    { { 0x00000001 }, { .fl = 2.0  }, { .fl = 0 } },
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
	x.lo = pgm_read_dword (& t[i].x);
	y.lo = pgm_read_dword (& t[i].y);
	z.lo = pgm_read_dword (& t[i].z);
	v.fl = x.fl / y.fl;
	/* Comparison is integer to verify the zero sign.	*/
	if (v.lo != z.lo)
	    x_exit (i+1);
    }
    return 0;
}
