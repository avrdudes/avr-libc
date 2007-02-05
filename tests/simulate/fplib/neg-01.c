/* Test of negation.
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

PROGMEM const struct {		/* Table of test cases:  x, -x	*/
    union lofl_u x, z;
} t[] = {

    /* 0.0	*/
    { { 0x00000000 }, { 0x80000000 } },
    { { 0x80000000 }, { 0x00000000 } },
    
    /* finite	*/
    { { 0x00000001 }, { 0x80000001 } },
    { { 0x007fffff }, { 0x807fffff } },
    { { 0x00800000 }, { 0x80800000 } },
    { { 0x7f7fffff }, { 0xff7fffff } },
    { { 0x80000001 }, { 0x00000001 } },
    { { 0x807fffff }, { 0x007fffff } },
    { { 0x80800000 }, { 0x00800000 } },
    { { 0xff7fffff }, { 0x7f7fffff } },
    
    /* infinite	*/
    { { 0x7f800000 }, { 0xff800000 } },
    { { 0xff800000 }, { 0x7f800000 } },
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
    union lofl_u x,z;
    int i;
    
    for (i = 0; i < (int) (sizeof(t) / sizeof(t[0])); i++) {
	x.lo = pgm_read_dword (& t[i].x);
	z.lo = pgm_read_dword (& t[i].z);
	v.fl = -x.fl;
	if (v.lo != z.lo)
	    x_exit (i+1);
#ifdef  __AVR__
	{
	    /* Forse to use fplib's function.	*/
	    extern float __negsf2 (float);
	    v.fl = __negsf2 (x.fl);
	    if (v.lo != z.lo)
		x_exit (i+1);
	}
#endif
    }
    return 0;
}
