/* Test of log() function. NaNs.
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

PROGMEM const struct {		/* Table of test cases:  log(x) --> NaN	*/
    union lofl_u x;
} t[] = {

    /* x is NaN	*/
    { { 0x7f800001 } },
    { { 0x7f800100 } },
    { { 0x7f810000 } },
    { { 0x7fc00000 } },
    { { 0x7fffffff } },
    { { 0xff800001 } },
    { { 0xff800100 } },
    { { 0xff810000 } },
    { { 0xffc00000 } },
    { { 0xffffffff } },
    
    /* x < 0	*/
    { { 0x80000001 } },
    { { 0x80000100 } },
    { { 0x80010000 } },
    { { 0x807fffff } },
    { { 0x80800000 } },
    { { 0xbf800000 } },
    { { 0xff7fffff } },

    /* x = -Inf	*/
    { { 0xff800000 } },
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
    
    for (i = 0; i < (int) (sizeof(t) / sizeof(t[0])); i++) {
	x.lo = pgm_read_dword (& t[i].x);
	v.fl = log (x.fl);
	if (!isnan(v.fl))
	    x_exit (i+1);
    }
    return 0;
}
