/* Test of fma().
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

PROGMEM const struct {		/* Table of test cases: res=fma(x,y,z)	*/
    union lofl_u x, y, z, res;
} t[] = {

    /* 0.0 (and -0.0)	*/
    { { 0x00000000 }, { 0x00000000 }, { 0x00000000 }, { 0x00000000 } },
    { { 0x80000000 }, { 0x00000000 }, { 0x00000000 }, { 0x00000000 } },
    { { 0x00000000 }, { 0x80000000 }, { 0x00000000 }, { 0x00000000 } },
    { { 0x80000000 }, { 0x80000000 }, { 0x00000000 }, { 0x00000000 } },
    { { 0x00000000 }, { 0x00000000 }, { 0x80000000 }, { 0x00000000 } },
    { { 0x80000000 }, { 0x00000000 }, { 0x80000000 }, { 0x80000000 } },
    { { 0x00000000 }, { 0x80000000 }, { 0x80000000 }, { 0x80000000 } },
    { { 0x80000000 }, { 0x80000000 }, { 0x80000000 }, { 0x00000000 } },
    
    { { .fl =  1 }, { .fl =  2 }, { .fl =  3 }, { .fl =  5 } },
    { { .fl = -1 }, { .fl =  2 }, { .fl =  3 }, { .fl =  1 } },
    { { .fl =  1 }, { .fl = -2 }, { .fl =  3 }, { .fl =  1 } },
    { { .fl = -1 }, { .fl = -2 }, { .fl =  3 }, { .fl =  5 } },
    { { .fl =  1 }, { .fl =  2 }, { .fl = -3 }, { .fl = -1 } },
    { { .fl = -1 }, { .fl =  2 }, { .fl = -3 }, { .fl = -5 } },
    { { .fl =  1 }, { .fl = -2 }, { .fl = -3 }, { .fl = -5 } },
    { { .fl = -1 }, { .fl = -2 }, { .fl = -3 }, { .fl = -1 } },
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
    union lofl_u x, y, z, res;
    int i;
    
    for (i = 0; i < (int) (sizeof(t) / sizeof(t[0])); i++) {
	x.lo = pgm_read_dword (& t[i].x);
	y.lo = pgm_read_dword (& t[i].y);
	z.lo = pgm_read_dword (& t[i].z);
	res.lo = pgm_read_dword (& t[i].res);
	v.fl = fma (x.fl, y.fl, z.fl);
	if (v.lo != res.lo)
	    x_exit (i+1);
    }
    return 0;
}
