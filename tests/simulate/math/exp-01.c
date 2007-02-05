/* Test of exp() function.
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
    union lofl_u z;		/* exp(x)	*/
} t[] = {

    /* Zero	*/
    { { .fl=  0.0 },	{ .fl= 1 } },
    { { .fl= -0.0 },	{ .fl= 1 } },
    
    /* Inf	*/
    { { 0x7f800000 },	{ 0x7f800000 } },
    { { 0xff800000 },	{ 0x00000000 } },

    /* Subnormal	*/
    { { 0x00000001 },	{ .fl= 1 } },
    { { 0x00000100 },	{ .fl= 1 } },
    { { 0x00010000 },	{ .fl= 1 } },
    { { 0x007fffff },	{ .fl= 1 } },
    { { 0x80000001 },	{ .fl= 1 } },
    { { 0x80000100 },	{ .fl= 1 } },
    { { 0x80010000 },	{ .fl= 1 } },
    { { 0x807fffff },	{ .fl= 1 } },

    /* Arg too small	*/
    { { 0xc3000000 },	{ .fl= 0 } },
    { { 0xc3800000 },	{ .fl= 0 } },
    { { 0xc3ffffff },	{ .fl= 0 } },
    { { 0xc4000000 },	{ .fl= 0 } },
    { { 0xff7fffff },	{ .fl= 0 } },

    /* Some values	*/
    { { .fl=  1.0 },	{ 0x402df854 } },
    { { .fl= -1.0 },	{ 0x3ebc5ab2 } },
    
    /* Near 0.0	*/
    { { .fl= 0x0.000002p0 }, { .fl= 0x1.000002p0 } },
    { { .fl= 0x0.000004p0 }, { .fl= 0x1.000004p0 } },
    { { .fl= 0x0.000006p0 }, { .fl= 0x1.000006p0 } },
    { { .fl= 0x0.000010p0 }, { .fl= 0x1.000010p0 } },
    { { .fl= 0x0.000100p0 }, { .fl= 0x1.000100p0 } },
    { { .fl= 0x0.000800p0 }, { .fl= 0x1.000800p0 } },

    { { .fl= -0x0.000001p0 }, { .fl= 0x0.ffffffp0 } },
    { { .fl= -0x0.000002p0 }, { .fl= 0x0.fffffep0 } },
    { { .fl= -0x0.000003p0 }, { .fl= 0x0.fffffdp0 } },
    { { .fl= -0x0.000010p0 }, { .fl= 0x0.fffff0p0 } },
    { { .fl= -0x0.000100p0 }, { .fl= 0x0.ffff00p0 } },
    { { .fl= -0x0.001000p0 }, { .fl= 0x0.fff000p0 } },
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
	v.fl = exp (x.fl);
	/* Comparison is integer to verify the zero sign.	*/
	if (v.lo != z.lo)
	    x_exit (i+1);
    }
    return 0;
}
