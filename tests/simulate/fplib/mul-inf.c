/* Test of multiplication.  Infs (without NaNs).
   '0.0 * Inf' is not included into this file.
   $Id$
 */
#include <stdio.h>
#include <stdlib.h>
#include "progmem.h"

union lofl_u {
    long lo;
    float fl;
};

volatile union lofl_u v = { .lo = 1 };

PROGMEM const struct {		/* Table of test cases:  x * y = z	*/
    union lofl_u x, y, z;
} t[] = {

    /* +Inf * finite	*/
    { { 0x7f800000 }, { 0x00000001 }, { 0x7f800000 } },
    { { 0x7f800000 }, { 0x007fffff }, { 0x7f800000 } },
    { { 0x7f800000 }, { 0x00800000 }, { 0x7f800000 } },
    { { 0x7f800000 }, { 0x3f800000 }, { 0x7f800000 } },
    { { 0x7f800000 }, { 0x7f7fffff }, { 0x7f800000 } },
    { { 0x7f800000 }, { 0x80000001 }, { 0xff800000 } },
    { { 0x7f800000 }, { 0x807fffff }, { 0xff800000 } },
    { { 0x7f800000 }, { 0x80800000 }, { 0xff800000 } },
    { { 0x7f800000 }, { 0xbf800000 }, { 0xff800000 } },
    { { 0x7f800000 }, { 0xff7fffff }, { 0xff800000 } },

    /* -Inf * finite	*/
    { { 0xff800000 }, { 0x00000001 }, { 0xff800000 } },
    { { 0xff800000 }, { 0x007fffff }, { 0xff800000 } },
    { { 0xff800000 }, { 0x00800000 }, { 0xff800000 } },
    { { 0xff800000 }, { 0x3f800000 }, { 0xff800000 } },
    { { 0xff800000 }, { 0x7f7fffff }, { 0xff800000 } },
    { { 0xff800000 }, { 0x80000001 }, { 0x7f800000 } },
    { { 0xff800000 }, { 0x807fffff }, { 0x7f800000 } },
    { { 0xff800000 }, { 0x80800000 }, { 0x7f800000 } },
    { { 0xff800000 }, { 0xbf800000 }, { 0x7f800000 } },
    { { 0xff800000 }, { 0xff7fffff }, { 0x7f800000 } },

    /* finite * +Inf	*/
    { { 0x00000001 }, { 0x7f800000 }, { 0x7f800000 } },
    { { 0x007fffff }, { 0x7f800000 }, { 0x7f800000 } },
    { { 0x00800000 }, { 0x7f800000 }, { 0x7f800000 } },
    { { 0x3f800000 }, { 0x7f800000 }, { 0x7f800000 } },
    { { 0x7f7fffff }, { 0x7f800000 }, { 0x7f800000 } },
    { { 0x80000001 }, { 0x7f800000 }, { 0xff800000 } },
    { { 0x807fffff }, { 0x7f800000 }, { 0xff800000 } },
    { { 0x80800000 }, { 0x7f800000 }, { 0xff800000 } },
    { { 0xbf800000 }, { 0x7f800000 }, { 0xff800000 } },
    { { 0xff7fffff }, { 0x7f800000 }, { 0xff800000 } },

    /* finite * -Inf	*/
    { { 0x00000001 }, { 0xff800000 }, { 0xff800000 } },
    { { 0x007fffff }, { 0xff800000 }, { 0xff800000 } },
    { { 0x00800000 }, { 0xff800000 }, { 0xff800000 } },
    { { 0x3f800000 }, { 0xff800000 }, { 0xff800000 } },
    { { 0x7f7fffff }, { 0xff800000 }, { 0xff800000 } },
    { { 0x80000001 }, { 0xff800000 }, { 0x7f800000 } },
    { { 0x807fffff }, { 0xff800000 }, { 0x7f800000 } },
    { { 0x80800000 }, { 0xff800000 }, { 0x7f800000 } },
    { { 0xbf800000 }, { 0xff800000 }, { 0x7f800000 } },
    { { 0xff7fffff }, { 0xff800000 }, { 0x7f800000 } },
    
    /* Inf * Inf	*/
    { { 0x7f800000 }, { 0x7f800000 }, { 0x7f800000 } },
    { { 0xff800000 }, { 0x7f800000 }, { 0xff800000 } },
    { { 0x7f800000 }, { 0xff800000 }, { 0xff800000 } },
    { { 0xff800000 }, { 0xff800000 }, { 0x7f800000 } },

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
	x.lo = pgm_read_dword (& t[i].x);
	y.lo = pgm_read_dword (& t[i].y);
	z.lo = pgm_read_dword (& t[i].z);
	v.fl = x.fl * y.fl;
	/* Comparison is integer to verify the zero sign.	*/
	if (v.lo != z.lo)
	    x_exit (i+1);
    }
    return 0;
}
