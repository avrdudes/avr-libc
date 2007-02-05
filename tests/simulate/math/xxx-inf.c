/* Test of a set of functions: func(Inf) --> NaN
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

volatile union lofl_u v = { 1 };

double (*tfun[]) (double) = {	/* Table of tested functions.	*/
    asin,
    cos,
    sin,
    tan,
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
    int i;
    
    for (i = 0; i < (int) (sizeof(tfun) / sizeof(tfun[0])); i++) {
	x.lo = 0x7f800000;		/* +Inf	*/
	v.fl = (tfun[i]) (x.fl);
	if (!isnan (v.fl)) {
	    x_exit (i+1);
	}
	x.lo = 0xff800000;		/* -Inf	*/
	v.fl = (tfun[i]) (x.fl);
	if (!isnan (v.fl)) {
	    x_exit (i+1);
	}
    }
    return 0;
}
