/* Test of acos() function.
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
    union lofl_u z;		/* acos(x)	*/
} t[] = {

    /* Zero	*/
    { { .fl= +0.0 },	{ 0x3fc90fdb }	},	/* Pi/2	*/
    { { .fl= -0.0 },	{ 0x3fc90fdb }	},

    /* Subnormal	*/
    { { 0x00000001 },	{ 0x3fc90fdb }	},
    { { 0x00000100 },	{ 0x3fc90fdb }	},
    { { 0x00010000 },	{ 0x3fc90fdb }	},
    { { 0x007fffff },	{ 0x3fc90fdb }	},
    { { 0x80000001 },	{ 0x3fc90fdb }	},
    { { 0x80000100 },	{ 0x3fc90fdb }	},
    { { 0x80010000 },	{ 0x3fc90fdb }	},
    { { 0x807fffff },	{ 0x3fc90fdb }	},
    
    /* Some values	*/
    { { .fl=  1.0 },	{ .fl = 0.0  } },
    { { .fl= -1.0 },	{ 0x40490fdb } },	/* Pi	*/
};

void x_exit (int index)
{
#ifndef	__AVR__
    fprintf (stderr, "t[%d]:  %#lx\n", index - 1, v.lo);
#endif
    exit (index ? index : -1);
}

static inline unsigned long distance (long a, long b)
{
    unsigned long a1, b1;
    a1 = (a < 0) ? (unsigned long)~a : a + 0x80000000;
    b1 = (b < 0) ? (unsigned long)~b : b + 0x80000000;
    return (a1 > b1) ? a1 - b1 : b1 - a1;
}

int main ()
{
    union lofl_u x, z;
    int i;
    
    for (i = 0; i < (int) (sizeof(t) / sizeof(t[0])); i++) {
	x.lo = pgm_read_dword (& t[i].x);
	z.lo = pgm_read_dword (& t[i].z);
	v.fl = acos (x.fl);
	if (v.lo < 0 || distance(v.lo, z.lo) > 1)
	    x_exit (i+1);
    }
    return 0;
}
