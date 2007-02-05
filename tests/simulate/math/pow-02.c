/* Test of pow() function.
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

PROGMEM const struct {		/* Table of test cases	*/
    union lofl_u x, y;		/* args		*/
    union lofl_u z;		/* pow(x,y)	*/
} t[] = {

    /* pow (0,0)	*/
    { { .fl=  0.0 }, { .fl=  0.0 }, { .fl= 1 } },
    { { .fl= -0.0 }, { .fl=  0.0 }, { .fl= 1 } },
    { { .fl=  0.0 }, { .fl= -0.0 }, { .fl= 1 } },
    { { .fl= -0.0 }, { .fl= -0.0 }, { .fl= 1 } },
    
    /* pow (0, positive)	*/
    { { .fl=  0.0 }, { 0x00000001 }, { .fl= 0.0 } },
    { { .fl=  0.0 }, { 0x007fffff }, { .fl= 0.0 } },
    { { .fl=  0.0 }, { 0x00800000 }, { .fl= 0.0 } },
    { { .fl=  0.0 }, { 0x7f7fffff }, { .fl= 0.0 } },

    /* pow (0, negative)	*/
    { { .fl=  0.0 }, { 0x80000001 }, { 0x7f800000 } },
    { { .fl=  0.0 }, { 0x807fffff }, { 0x7f800000 } },
    { { .fl=  0.0 }, { 0x80800000 }, { 0x7f800000 } },
    { { .fl=  0.0 }, { 0xff7fffff }, { 0x7f800000 } },
    
    /* pow (-0, +even)	*/
    { { .fl= -0.0 }, { .fl=  1 }, { .fl= -0.0 } },
    
    /* pow (-0, +odd)	*/
    { { .fl= -0.0 }, { .fl=  2 }, { .fl= 0.0 } },

    /* pow (-0, +nonintegral)	*/
    { { .fl= -0.0 }, { 0x00000001 }, { .fl= 0.0 } },
    { { .fl= -0.0 }, { 0x007fffff }, { .fl= 0.0 } },
    { { .fl= -0.0 }, { 0x00800000 }, { .fl= 0.0 } },
    { { .fl= -0.0 }, { 0x7f7fffff }, { .fl= 0.0 } },
    
    /* pow (-0, +Inf)	*/
    { { .fl= -0.0 }, { 0x7f800000 }, { .fl= 0.0 } },
    
    /* pow (-0, -even)	*/
    { { .fl= -0.0 }, { .fl= -1 }, { 0xff800000 } },

    /* pow (-0, -odd)	*/
    { { .fl= -0.0 }, { .fl= -2 }, { 0x7f800000 } },
    
    /* pow (-0, -nonintegral)	*/
    { { .fl= -0.0 }, { 0x80000001 }, { 0x7f800000 } },
    { { .fl= -0.0 }, { 0x807fffff }, { 0x7f800000 } },
    { { .fl= -0.0 }, { 0x80800000 }, { 0x7f800000 } },
    { { .fl= -0.0 }, { 0xff7fffff }, { 0x7f800000 } },
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
    union lofl_u x,y,z;
    int i;
    
    for (i = 0; i < (int) (sizeof(t) / sizeof(t[0])); i++) {
	y.lo = pgm_read_dword (& t[i].y);
	x.lo = pgm_read_dword (& t[i].x);
	z.lo = pgm_read_dword (& t[i].z);
	v.fl = pow (x.fl, y.fl);
	/* Comparison is integer to verify the zero sign.	*/
	if (v.lo != z.lo)
	    x_exit (i+1);
    }
    return 0;
}
