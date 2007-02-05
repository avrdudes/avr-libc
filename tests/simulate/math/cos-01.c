/* Test of cos() function.
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
    union lofl_u z;		/* cos(x)	*/
} t[] = {

    /* Zero	*/
    { { .fl= +0.0 },	{ .fl= 1.0 }	},
    { { .fl= -0.0 },	{ .fl= 1.0 }	},
    
    /* Subnormal	*/
    { { 0x00000001 },	{ .fl= 1.0 }	},
    { { 0x00000100 },	{ .fl= 1.0 }	},
    { { 0x00010000 },	{ .fl= 1.0 }	},
    { { 0x007fffff },	{ .fl= 1.0 }	},
    { { 0x80000001 },	{ .fl= 1.0 }	},
    { { 0x80000100 },	{ .fl= 1.0 }	},
    { { 0x80010000 },	{ .fl= 1.0 }	},
    { { 0x807fffff },	{ .fl= 1.0 }	},
    
    /* Arg. too small	*/
    { { 0x00800000 },	{ .fl= 1.0 }	},
    { { 0x01000000 },	{ .fl= 1.0 }	},
    { { 0x107fffff },	{ .fl= 1.0 }	},
    { { 0x80800000 },	{ .fl= 1.0 }	},
    { { 0x81000000 },	{ .fl= 1.0 }	},
    { { 0x907fffff },	{ .fl= 1.0 }	},

    /* Some values	*/
    { { .fl=  3.1415927 },  { .fl= -1.0 } },
    { { .fl=  6.2831853 },  { .fl=  1.0 } },
    { { .fl= -3.1415927 },  { .fl= -1.0 } },
    { { .fl= -6.2831853 },  { .fl=  1.0 } },
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
	v.fl = cos (x.fl);
	/* Comparison is integer to verify the zero sign.	*/
	if (v.lo != z.lo)
	    x_exit (i+1);
    }
    return 0;
}
