/* Test of multiplication. Overflow.
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

PROGMEM const struct {		/* Table of test cases:  x * y = z	*/
    union lofl_u x, y, z;
} t[] = {

    { { .fl = 0x0.ffffffp64 }, { .fl = 0x0.ffffffp64 }, { 0x7f7ffffe }	},
    { { .fl = 0x0.800000p65 }, { .fl = 0x0.ffffffp64 }, { 0x7f7fffff }	},
    { { .fl = 0x0.800000p65 }, { .fl = 0x0.800000p65 }, { 0x7f800000 }	},
    { { .fl = 0x0.800001p65 }, { .fl = 0x0.800000p65 }, { 0x7f800000 }	},
    { { .fl = 0x0.800000p65 }, { .fl = 0x0.800001p65 }, { 0x7f800000 }	},
    { { .fl = 0x0.800001p65 }, { .fl = 0x0.800001p65 }, { 0x7f800000 }	},

    { { 0x7f7fffff }, { 0x7f7fffff }, { 0x7f800000 }	},
    { { 0x7f7fffff }, { 0xff7fffff }, { 0xff800000 }	},
    { { 0xff7fffff }, { 0x7f7fffff }, { 0xff800000 }	},
    { { 0xff7fffff }, { 0xff7fffff }, { 0x7f800000 }	},
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
	v.fl = x.fl * y.fl;
	/* Comparison is integer to verify the zero sign.	*/
	if (v.lo != z.lo)
	    x_exit (i+1);
    }
    return 0;
}
