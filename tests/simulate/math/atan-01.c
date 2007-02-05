/* Test of atan() function.
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
    union lofl_u z;		/* atan(x)	*/
} t[] = {

    /* Zero	*/
    { { .fl= +0.0 },	{ .fl= +0.0 }	},
    { { .fl= -0.0 },	{ .fl= -0.0 }	},

    /* Subnormal	*/
    { { 0x00000001 },	{ 0x00000001 }	},
    { { 0x00000100 },	{ 0x00000100 }	},
    { { 0x00010000 },	{ 0x00010000 }	},
    { { 0x007fffff },	{ 0x007fffff }	},
    { { 0x80000001 },	{ 0x80000001 }	},
    { { 0x80000100 },	{ 0x80000100 }	},
    { { 0x80010000 },	{ 0x80010000 }	},
    { { 0x807fffff },	{ 0x807fffff }	},
    
    /* Inf	*/
    { { 0x7f800000 },	{ 0x3fc90fdb } },	/* +Pi/2	*/
    { { 0xff800000 },	{ 0xbfc90fdb } },	/* -Pi/2	*/
    
    /* Some values	*/
    { { .fl=  0x0.ffffffp0 },	{ 0x3f490fda } },	/* Pi/4	*/
    { { .fl=  1.0 },		{ 0x3f490fdb } },	/* Pi/4	*/
    { { .fl=  0x1.000002p0 },	{ 0x3f490fdc } },	/* Pi/4	*/

    { { .fl= -0x0.ffffffp0 },	{ 0xbf490fda } },	/* -Pi/4 */
    { { .fl= -1.0 },		{ 0xbf490fdb } },	/* -Pi/4 */
    { { .fl= -0x1.000002p0 },	{ 0xbf490fdc } },	/* -Pi/4 */
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
	v.fl = atan (x.fl);
	/* Comparison is integer to verify the zero sign.	*/
	if (v.lo != z.lo)
	    x_exit (i+1);
    }
    return 0;
}
