/* Test of isnan().
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

PROGMEM const union lofl_u t0[] = {	/* No NaNs	*/

    /* positive finite	*/
    { 0x00000000 },
    { 0x00000001 },
    { 0x00000100 },
    { 0x00010000 },
    { 0x007fffff },
    { 0x00800000 },
    { 0x3f800000 },
    { 0x7f7fffff },

    /* negative finite	*/
    { 0x80000000 },
    { 0x80000001 },
    { 0x80000100 },
    { 0x80010000 },
    { 0x807fffff },
    { 0x80800000 },
    { 0xbf800000 },
    { 0xff7fffff },

    /* Inf	*/
    { 0x7f800000 },
    { 0xff800000 },
};

PROGMEM const union lofl_u t1[] = {	/* NaNs	*/

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
    fprintf (stderr, "t[%d]\n", index - 1);
#endif
    exit (index ? index : -1);
}

int main ()
{
    union lofl_u x;
    int i;
    
    for (i = 0; i < (int) (sizeof(t0) / sizeof(t0[0])); i++) {
	x.lo = pgm_read_dword (& t0[i]);
	if (isnan(x.fl))
	    x_exit (i + 1);
    }
    for (i = 0; i < (int) (sizeof(t1) / sizeof(t1[0])); i++) {
	x.lo = pgm_read_dword (& t1[i]);
	if (!isnan(x.fl))
	    x_exit (i + 101);
    }
    return 0;
}
