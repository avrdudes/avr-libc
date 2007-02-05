/* Test of division.  Rounding.
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

    { { .fl = 1 }, { .fl = 3 }, { .fl = 0.33333333 } },	/* 0x3eaaaaab */
    { { .fl = 2 }, { .fl = 3 }, { .fl = 0.66666667 } }, /* 0x3f2aaaab */
    { { .fl = -1 }, { .fl = 3 }, { .fl = -0.33333333 } },
    { { .fl = -2 }, { .fl = 3 }, { .fl = -0.66666667 } },
    { { .fl = 1 }, { .fl = -3 }, { .fl = -0.33333333 } },
    { { .fl = 2 }, { .fl = -3 }, { .fl = -0.66666667 } },
    { { .fl = -1 }, { .fl = -3 }, { .fl = 0.33333333 } },
    { { .fl = -2 }, { .fl = -3 }, { .fl = 0.66666667 } },
    
    { { .fl = 2 }, { .fl = 0x0.fffffep1 }, { .fl = 0x0.800001p1 } },
    { { .fl = 2 }, { .fl = 0x0.ffffffp1 }, { .fl = 0x0.800001p1 } },
    { { .fl = 2 }, { .fl = 0x0.800000p2 }, { .fl = 0x0.800000p1 } },
    { { .fl = 2 }, { .fl = 0x0.800001p2 }, { .fl = 0x0.fffffep0 } },

    /* The remander is exactly 0.5: rounding direction is smart.	*/
    { { 0x007ffffe }, { .fl = 2 }, { 0x003fffff } },
    { { 0x007fffff }, { .fl = 2 }, { 0x00400000 } },
    { { 0x00800000 }, { .fl = 2 }, { 0x00400000 } },
    { { 0x00800001 }, { .fl = 2 }, { 0x00400000 } },
    { { 0x00800002 }, { .fl = 2 }, { 0x00400001 } },
    { { 0x00800003 }, { .fl = 2 }, { 0x00400002 } },
    { { 0x00800004 }, { .fl = 2 }, { 0x00400002 } },
    { { 0x00800005 }, { .fl = 2 }, { 0x00400002 } },
    { { 0x00800006 }, { .fl = 2 }, { 0x00400003 } },
    { { 0x00800007 }, { .fl = 2 }, { 0x00400004 } },

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
