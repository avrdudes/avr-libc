/* Test of modf() function. NaNs
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

volatile union lofl_u vf = { 1 };
double vn = { 1 };

PROGMEM const struct {		/* Table of test cases.	*/
    union lofl_u x;	/* argument			*/
} t[] = {

    { { 0x7f800001 } },
    { { 0x7f800100 } },
    { { 0x7f810000 } },
    { { 0x7fffffff } },

    { { 0xff800001 } },
    { { 0xff800100 } },
    { { 0xff810000 } },
    { { 0xffffffff } },
};

void x_exit (int index)
{
#ifndef	__AVR__
    fprintf (stderr, "t[%d]:  %#lx\n", index - 1, vf.lo);
#endif
    exit (index ? index : -1);
}

int main ()
{
    union lofl_u x;
    int i;
    
    for (i = 0; i < (int) (sizeof(t) / sizeof(t[0])); i++) {
	x.lo = pgm_read_dword (& t[i].x);
	vn = 0;
	vf.fl = modf (x.fl, & vn);
	if (!isnan (vf.fl) || !isnan (vn)) {
	    x_exit (i+1);
	}
    }
    return 0;
}
