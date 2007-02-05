/* Test of ldexp function.  NaNs.
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
    union lofl_u x;
    int y;
} t[] = {

    { { 0x7f800001 }, 1 },
    { { 0x7f800100 }, 1 },
    { { 0x7f810000 }, 1 },
    { { 0x7fffffff }, 1 },
    { { 0xff800001 }, 1 },
    { { 0xff800100 }, 1 },
    { { 0xff810000 }, 1 },
    { { 0xffffffff }, 1 },
    
    { { 0x7fc00000 }, 0 },
    { { 0xffc00000 }, 0 },

    { { 0x7fc00000 },  32767 },
    { { 0x7fc00000 }, -32768 },
};

void x_exit (int index)
{
#ifndef	__AVR__
    fprintf (stderr, "t[%d]: %e (%#lx)\n", index - 1, v.fl, v.lo);
#endif
    exit (index ? index : -1);
}

int main ()
{
    union lofl_u x;
    int y;
    int i;

    for (i = 0; i < (int) (sizeof(t) / sizeof(t[0])); i++) {
	x.lo = pgm_read_dword (& t[i].x);
	y    = pgm_read_word  (& t[i].y);
	v.fl = ldexp (x.fl, y);
	if (!isnan(v.fl))
	    x_exit (i+1);
    }
    return 0;
}
