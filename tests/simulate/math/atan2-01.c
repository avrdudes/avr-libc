/* Test of atan2() function.
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

#define	Pi	0x40490fdb
#define	Pi_2	0x3fc90fdb
#define Pi_4	0x3f490fdb
#define	MPi	0xc0490fdb
#define	MPi_2	0xbfc90fdb
#define MPi_4	0xbf490fdb

#define	DEG_45	0x3f490fdb
#define	DEG_135	0x4016cbe4

/* ATTENTION: first arg is named 'y'	*/
PROGMEM const struct {		/* Table of test cases	*/
    union lofl_u y, x;		/* args		*/
    union lofl_u z;		/* atan2(y,x)	*/
} t[] = {

    { { .fl=  0.0 }, { .fl=  0.0 }, { 0x00000000 } },
#ifdef	__AVR__
    { { .fl= -0.0 }, { .fl=  0.0 }, { 0 } },
    { { .fl=  0.0 }, { .fl= -0.0 }, { 0 } },
    { { .fl= -0.0 }, { .fl= -0.0 }, { 0 } },
#else
    { { .fl= -0.0 }, { .fl=  0.0 }, { 0x80000000 } },
    { { .fl=  0.0 }, { .fl= -0.0 }, { Pi  } },
    { { .fl= -0.0 }, { .fl= -0.0 }, { MPi } },
#endif

    { { .fl=  1 }, { .fl=  1 }, { 0x3f490fdb } },
    { { .fl=  1 }, { .fl= -1 }, { 0x4016cbe4 } },
    { { .fl= -1 }, { .fl= -1 }, { 0xc016cbe4 } },
    { { .fl= -1 }, { .fl=  1 }, { 0xbf490fdb } },
    
    /* atan2(y,+Inf)	*/
    { { 0x00000001 }, { 0x7f800000 }, { 0 } },
    { { 0x3f800000 }, { 0x7f800000 }, { 0 } },
    { { 0x7f7fffff }, { 0x7f800000 }, { 0 } },
    { { 0x80000001 }, { 0x7f800000 }, { .fl= -0.0 } },
    { { 0xbf800000 }, { 0x7f800000 }, { .fl= -0.0 } },
    { { 0xff7fffff }, { 0x7f800000 }, { .fl= -0.0 } },
    
    /* atan2(y,-Inf)	*/
    { { 0x00000000 }, { 0xff800000 }, { Pi } },
    { { 0x00000001 }, { 0xff800000 }, { Pi } },
    { { 0x3f800000 }, { 0xff800000 }, { Pi } },
    { { 0x7f7fffff }, { 0xff800000 }, { Pi } },
    { { 0x80000001 }, { 0xff800000 }, { MPi } },
    { { 0xbf800000 }, { 0xff800000 }, { MPi } },
    { { 0xff7fffff }, { 0xff800000 }, { MPi } },

    /* atan2(+Inf,x)	*/
    { { 0x7f800000 }, { 0x00000000 }, { Pi_2 } },
    { { 0x7f800000 }, { 0x00000001 }, { Pi_2 } },
    { { 0x7f800000 }, { 0x3f800000 }, { Pi_2 } },
    { { 0x7f800000 }, { 0x7f7fffff }, { Pi_2 } },
    { { 0x7f800000 }, { 0x80000000 }, { Pi_2 } },
    { { 0x7f800000 }, { 0x80000001 }, { Pi_2 } },
    { { 0x7f800000 }, { 0xbf800000 }, { Pi_2 } },
    { { 0x7f800000 }, { 0xff7fffff }, { Pi_2 } },

    /* atan2(-Inf,x)	*/
    { { 0xff800000 }, { 0x00000000 }, { MPi_2 } },
    { { 0xff800000 }, { 0x00000001 }, { MPi_2 } },
    { { 0xff800000 }, { 0x3f800000 }, { MPi_2 } },
    { { 0xff800000 }, { 0x7f7fffff }, { MPi_2 } },
    { { 0xff800000 }, { 0x80000000 }, { MPi_2 } },
    { { 0xff800000 }, { 0x80000001 }, { MPi_2 } },
    { { 0xff800000 }, { 0xbf800000 }, { MPi_2 } },
    { { 0xff800000 }, { 0xff7fffff }, { MPi_2 } },

    /* Both args are Inf	*/
    { { 0x7f800000 }, { 0x7f800000 }, { DEG_45 } },
    { { 0x7f800000 }, { 0xff800000 }, { DEG_135 } },
    { { 0xff800000 }, { 0x7f800000 }, { DEG_45  | 0x80000000 } },
    { { 0xff800000 }, { 0xff800000 }, { DEG_135 | 0x80000000 } },
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
	v.fl = atan2 (y.fl, x.fl);
	/* Comparison is integer to verify the zero sign.	*/
	if (v.lo != z.lo)
	    x_exit (i+1);
    }
    return 0;
}
