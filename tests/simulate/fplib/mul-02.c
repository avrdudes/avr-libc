/* Test of multiplication. Subnormals.
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

    /* subnormal * subnormal	*/
    { { 0x00000001 }, { 0x00000001 }, { 0 } },
    { { 0x00000100 }, { 0x00000100 }, { 0 } },
    { { 0x00010000 }, { 0x00010000 }, { 0 } },
    { { 0x007fffff }, { 0x007fffff }, { 0 } },
    
    /* subnormal * normal	*/
    { { 0x00000001 }, { .fl = .5 },		{ 0x00000000 }	},
    { { 0x00000001 }, { .fl = 1 },		{ 0x00000001 }	},
    { { 0x00000001 }, { .fl = 2 },		{ 0x00000002 }	},
    { { 0x00000001 }, { .fl = 4 },		{ 0x00000004 }	},
    { { 0x00000001 }, { .fl = 0x1p22 },		{ 0x00400000 }	},
    { { 0x00000001 }, { .fl = 0x1p23 },		{ 0x00800000 }	},
    { { 0x00000001 }, { .fl = 0x0.ffffffp127 },	{ .fl = 0x0.ffffffp-22 } },

    { { 0x00000002 }, { .fl = .25 },		{ 0x00000000 }	},
    { { 0x00000002 }, { .fl = .5 },		{ 0x00000001 }	},
    { { 0x00000002 }, { .fl = 1 },		{ 0x00000002 }	},
    { { 0x00000002 }, { .fl = 2 },		{ 0x00000004 }	},
    { { 0x00000002 }, { .fl = 0x1p21 },		{ 0x00400000 }	},
    { { 0x00000002 }, { .fl = 0x1p22 },		{ 0x00800000 }	},
    { { 0x00000002 }, { .fl = 0x0.ffffffp127 },	{ .fl = 0x0.ffffffp-21 } },
    
    { { 0x007fffff }, { .fl = 0x1p-24 },	{ 0x00000000 }	},
    { { 0x007fffff }, { .fl = 0x1p-23 },	{ 0x00000001 }	},
    { { 0x007fffff }, { .fl = 0x1p-22 },	{ 0x00000002 }	},
    { { 0x007fffff }, { .fl = 0x1p-1 },		{ 0x00400000 }	},
    { { 0x007fffff }, { .fl = 0x1p0 },		{ 0x007fffff }	},
    { { 0x007fffff }, { .fl = 0x1p1 },		{ 0x00fffffe }	},
    { { 0x007fffff }, { .fl = 0x0.ffffffp127 },	{ 0x3ffffffd }	},
    
    /* normal * subnormal	*/
    { { .fl = .5 },		{ 0x00000001 }, { 0x00000000 }	},
    { { .fl = 1 },		{ 0x00000001 }, { 0x00000001 }	},
    { { .fl = 2 },		{ 0x00000001 }, { 0x00000002 }	},
    { { .fl = 4 },		{ 0x00000001 }, { 0x00000004 }	},
    { { .fl = 0x1p22 },		{ 0x00000001 }, { 0x00400000 }	},
    { { .fl = 0x1p23 },		{ 0x00000001 }, { 0x00800000 }	},
    { { .fl = 0x0.ffffffp127 },	{ 0x00000001 }, { .fl = 0x0.ffffffp-22 } },
                                
    { { .fl = .25 },		{ 0x00000002 }, { 0x00000000 }	},
    { { .fl = .5 },		{ 0x00000002 }, { 0x00000001 }	},
    { { .fl = 1 },		{ 0x00000002 }, { 0x00000002 }	},
    { { .fl = 2 },		{ 0x00000002 }, { 0x00000004 }	},
    { { .fl = 0x1p21 },		{ 0x00000002 }, { 0x00400000 }	},
    { { .fl = 0x1p22 },		{ 0x00000002 }, { 0x00800000 }	},
    { { .fl = 0x0.ffffffp127 },	{ 0x00000002 }, { .fl = 0x0.ffffffp-21 } },
                                
    { { .fl = 0x1p-24 },	{ 0x007fffff }, { 0x00000000 }	},
    { { .fl = 0x1p-23 },	{ 0x007fffff }, { 0x00000001 }	},
    { { .fl = 0x1p-22 },	{ 0x007fffff }, { 0x00000002 }	},
    { { .fl = 0x1p-1 },		{ 0x007fffff }, { 0x00400000 }	},
    { { .fl = 0x1p0 },		{ 0x007fffff }, { 0x007fffff }	},
    { { .fl = 0x1p1 },		{ 0x007fffff }, { 0x00fffffe }	},
    { { .fl = 0x0.ffffffp127 },	{ 0x007fffff }, { 0x3ffffffd }	},

    /* normal * normal --> subnormal	*/
    { { .fl = 0x1p-75 }, { .fl = 0x1p-75 },	{ 0 }	},
    { { .fl = 0x1p-74 }, { .fl = 0x1p-75 },	{ 0x00000001 }	},
    { { .fl = 0x1p-74 }, { .fl = 0x1p-74 },	{ 0x00000002 }	},
    { { .fl = 0x1p-23 }, { 0x00800000 },	{ 0x00000001 }	},
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
