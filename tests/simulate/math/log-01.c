/* Test of log() function.
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

PROGMEM const struct {		/* Table of test cases:  x, log(x)	*/
    union lofl_u x, z;
} t[] = {

    /* log(0)	*/
    { { 0x00000000 }, { 0xff800000 } },
    { { 0x80000000 }, { 0xff800000 } },		/* -0.0 is legal arg.	*/
    
    /* log(+Inf)	*/
    { { 0x7f800000 }, { 0x7f800000 } },

    { { .fl = 1 / 2.7182818 },	{ .fl = -1 }	},
    { { .fl = 1 },		{ .fl = 0 }	},
//    { { .fl = 2.7182819 },	{ .fl = 1 }	},
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
	v.fl = log (x.fl);
	/* Comparison is integer to verify the zero sign.	*/
	if (v.lo != z.lo)
	    x_exit (i+1);
    }
    return 0;
}
