/* Test of copysign(). Both realizations are tested: inline and library.
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
    union lofl_u x, y;		/* args		*/
    union lofl_u z;		/* result	*/
} t[] = {

    { { .fl= +0.0 }, { .fl= +0.0 }, { .fl= +0.0 } },
    { { .fl= -0.0 }, { .fl= +0.0 }, { .fl= +0.0 } },
    { { .fl= +0.0 }, { .fl= -0.0 }, { .fl= -0.0 } },
    { { .fl= -0.0 }, { .fl= -0.0 }, { .fl= -0.0 } },
    
    { { .fl= +1 },   { .fl= +10 },  { .fl= +1 } },
    { { .fl= -1 },   { .fl= +10 },  { .fl= +1 } },
    { { .fl= +1 },   { .fl= -10 },  { .fl= -1 } },
    { { .fl= -1 },   { .fl= -10 },  { .fl= -1 } },
    
    /* Inf	*/
    { { 0x7f800000 }, { 0xff800000 }, { 0xff800000 } },
    { { 0xff800000 }, { 0x7f800000 }, { 0x7f800000 } },
};

void x_exit (int index)
{
#ifndef	__AVR__
    fprintf (stderr, "t[%d]\n", index - 1);
#endif
    exit (index ? index : -1);
}

int main ()
{
    union lofl_u x, y, z;
    int i;
    double (* volatile vp) (double, double);
    
    /* inline     */
    for (i = 0; i < (int) (sizeof(t) / sizeof(t[0])); i++) {
	x.lo = pgm_read_dword (& t[i].x);
	y.lo = pgm_read_dword (& t[i].y);
	z.lo = pgm_read_dword (& t[i].z);
	v.fl = copysign (x.fl, y.fl);
	if (v.lo != z.lo)
	    x_exit (i + 1);
    }

    /* library function     */
    vp = copysign;
    for (i = 0; i < (int) (sizeof(t) / sizeof(t[0])); i++) {
	x.lo = pgm_read_dword (& t[i].x);
	y.lo = pgm_read_dword (& t[i].y);
	z.lo = pgm_read_dword (& t[i].z);
	v.fl = vp (x.fl, y.fl);
	if (v.lo != z.lo)
	    x_exit (i + 0x101);
    }
    
    return 0;
}
