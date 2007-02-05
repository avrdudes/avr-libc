/* Test of addition.  Rounding.
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

PROGMEM const struct {		/* Table of test cases:  x + y = z	*/
    union lofl_u x, y, z;
} t[] = {

    /* The remainder is exactly 0.5: look the smart rounding direction. */
    { { .fl = 0x0.8p0 }, { .fl = 0x0.0000008p0 }, { .fl = 0x0.800000p0 } },
    { { .fl = 0x0.8p0 }, { .fl = 0x0.0000010p0 }, { .fl = 0x0.800001p0 } },
    { { .fl = 0x0.8p0 }, { .fl = 0x0.0000018p0 }, { .fl = 0x0.800002p0 } },
    { { .fl = 0x0.8p0 }, { .fl = 0x0.0000020p0 }, { .fl = 0x0.800002p0 } },
    { { .fl = 0x0.8p0 }, { .fl = 0x0.0000028p0 }, { .fl = 0x0.800002p0 } },
    { { .fl = 0x0.8p0 }, { .fl = 0x0.0000030p0 }, { .fl = 0x0.800003p0 } },
    { { .fl = 0x0.8p0 }, { .fl = 0x0.0000038p0 }, { .fl = 0x0.800004p0 } },
    { { .fl = 0x0.8p0 }, { .fl = 0x0.0000040p0 }, { .fl = 0x0.800004p0 } },

    /* The remainder is exactly 0.5, subtraction.	*/
    { { .fl = 0x0.9p0 }, { .fl = -0x0.0000008p0 }, { .fl = 0x0.900000p0 } },
    { { .fl = 0x0.9p0 }, { .fl = -0x0.0000010p0 }, { .fl = 0x0.8fffffp0 } },
    { { .fl = 0x0.9p0 }, { .fl = -0x0.0000018p0 }, { .fl = 0x0.8ffffep0 } },
    { { .fl = 0x0.9p0 }, { .fl = -0x0.0000020p0 }, { .fl = 0x0.8ffffep0 } },
    { { .fl = 0x0.9p0 }, { .fl = -0x0.0000028p0 }, { .fl = 0x0.8ffffep0 } },
    { { .fl = 0x0.9p0 }, { .fl = -0x0.0000030p0 }, { .fl = 0x0.8ffffdp0 } },
    { { .fl = 0x0.9p0 }, { .fl = -0x0.0000038p0 }, { .fl = 0x0.8ffffcp0 } },
    { { .fl = 0x0.9p0 }, { .fl = -0x0.0000040p0 }, { .fl = 0x0.8ffffcp0 } },

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
	v.fl = x.fl + y.fl;
	/* Comparison is integer to verify the zero sign.	*/
	if (v.lo != z.lo)
	    x_exit (i+1);
    }
    return 0;
}
