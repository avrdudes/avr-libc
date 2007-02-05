/* Test of sqrt() function.
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
    union lofl_u z;		/* sqrt(x)	*/
} t[] = {

    /* zero	*/
    { { 0x00000000 }, { 0x00000000 } },
    { { 0x80000000 }, { 0x80000000 } },		/* sqrt(-0.0) --> -0.0	*/
    
    /* +Inf	*/
    { { 0x7f800000 }, { 0x7f800000 } },
    
    /* some known values	*/
    { { .fl= 0.25 },	{ .fl= 0.5 }	},
    { { .fl= 1 },	{ .fl= 1 }	},
    { { .fl= 4 },	{ .fl= 2 }	},
    { { .fl= 9 },	{ .fl= 3 }	},
    { { .fl= 25 },	{ .fl= 5 }	},
    { { .fl= 49 },	{ .fl= 7 }	},
    { { .fl= 100 },	{ .fl= 10 }	},
    { { .fl= 121 },	{ .fl= 11 }	},
    { { .fl= 169 },	{ .fl= 13 }	},
    { { .fl= 10000 },	{ .fl= 100 }	},
    { { .fl= 1000000 },	{ .fl= 1000 }	},
    
    /* subnormals	*/
    { { 0x00000001 },	{ 0x1a3504f3 }	},
    { { 0x00000002 },	{ 0x1a800000 }	},
    { { 0x00000003 },	{ 0x1a9cc471 }	},
    { { 0x00000080 },	{ 0x1c000000 }	},
    { { 0x00000100 },	{ 0x1c3504f3 }	},
    { { 0x00008000 },	{ 0x1e000000 }	},
    { { 0x00010000 },	{ 0x1e3504f3 }	},
    { { 0x00400000 },	{ 0x1fb504f3 }	},
    { { 0x007fffff },	{ 0x1fffffff }	},
    
    /* margin values	*/
    { { 0x00800000 },	{ 0x20000000 }	},
    { { 0x00800001 },	{ 0x20000000 }	},
    { { 0x01000000 },	{ 0x203504f3 }	},
    { { 0x01000001 },	{ 0x203504f4 }	},
    { { 0x7f000000 },	{ 0x5f3504f3 }	},
    { { 0x7f000001 },	{ 0x5f3504f4 }	},
    { { 0x7f7ffffe },	{ 0x5f7fffff }	},
    { { 0x7f7fffff },	{ 0x5f7fffff }	},
    
    /* rounding	*/
    { { .fl= 0x0.800001p+1 }, { .fl= 0x0.800000p+1 } },
    { { .fl= 0x0.800002p+1 }, { .fl= 0x0.800001p+1 } },
    { { .fl= 0x0.800003p+1 }, { .fl= 0x0.800001p+1 } },
    { { .fl= 0x0.800004p+1 }, { .fl= 0x0.800002p+1 } },
    { { .fl= 0x0.800005p+1 }, { .fl= 0x0.800002p+1 } },
    { { .fl= 0x0.800006p+1 }, { .fl= 0x0.800003p+1 } },
    { { .fl= 0x0.800007p+1 }, { .fl= 0x0.800003p+1 } },
    { { .fl= 0x0.800008p+1 }, { .fl= 0x0.800004p+1 } },
    { { .fl= 0x0.800009p+1 }, { .fl= 0x0.800004p+1 } },
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
	v.fl = sqrt (x.fl);
	/* Comparison is integer to verify the zero sign.	*/
	if (v.lo != z.lo)
	    x_exit (i+1);
    }
    return 0;
}
