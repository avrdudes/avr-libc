/* Test of a set of functions: func(NaN) --> NaN
   $Id$
 */
#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include "progmem.h"

/* Table of tested functions.	*/
double (*tfun[]) (double) = {
    acos,
    asin,
    atan,
    ceil,
    cos,
    cosh,
    exp,
    floor,
    log,
    log10,
    sin,
    sinh,
    sqrt,
    tan,
    tanh,
    trunc,
};

union lofl_u {
    long lo;
    float fl;
};

volatile union lofl_u v = { 1 };

/* Table of test cases: NaNs	*/
PROGMEM const union lofl_u tnan[] = {
    { 0x7f800001 },
    { 0x7f800100 },
    { 0x7f810000 },
    { 0x7fc00000 },
    { 0x7fffffff },
    { 0xff800001 },
    { 0xff800100 },
    { 0xff810000 },
    { 0xffc00000 },
    { 0xffffffff },
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
    union lofl_u x;
    int f, n;
    
    for (f = 0; f < (int) (sizeof(tfun)/sizeof(tfun[0])); f++) {
	for (n = 0; n < (int) (sizeof(tnan)/sizeof(tnan[0])); n++) {
	    x.lo = pgm_read_dword (& tnan[n]);
	    v.fl = (tfun[f]) (x.fl);
	    if (!isnan (v.fl)) {
		x_exit (f+1);
	    }
	}
    }
    return 0;
}
