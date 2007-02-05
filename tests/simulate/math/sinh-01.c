/* Test of sinh() function.
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
    union lofl_u x;		/* argument	*/
    union lofl_u z;		/* sinh(x)	*/
} t[] = {

    /* Zero	*/
    { { .fl=  0.0 },	{ .fl=  0.0 } },
    { { .fl= -0.0 },	{ .fl= -0.0 } },

    /* Inf	*/
    { { 0x7f800000 },	{ 0x7f800000 } },
    { { 0xff800000 },	{ 0xff800000 } },

    /* Subnormal	*/
    { { 0x00000001 },	{ 0x00000001 } },
    { { 0x00000100 },	{ 0x00000100 } },
    { { 0x00010000 },	{ 0x00010000 } },
    { { 0x007fffff },	{ 0x007fffff } },
    { { 0x80000001 },	{ 0x80000001 } },
    { { 0x80000100 },	{ 0x80000100 } },
    { { 0x80010000 },	{ 0x80010000 } },
    { { 0x807fffff },	{ 0x807fffff } },
    
    /* Arg too big	*/
    { { .fl= 89.415989 },	{ 0x7f800000 } },
    { { .fl= 100 },		{ 0x7f800000 } },
    { { .fl= 1000 },		{ 0x7f800000 } },
    { { 0x7f7fffff },		{ 0x7f800000 } },

    /* Arg too negative	*/
    { { .fl= -89.415989 },	{ 0xff800000 } },
    { { .fl= -100 },		{ 0xff800000 } },
    { { .fl= -12345 },		{ 0xff800000 } },
    { { 0xff7fffff },		{ 0xff800000 } },

    /* Near 0.0	*/
    { { 0x00800000 },	{ 0x00800000 } },
    { { 0x01000000 },	{ 0x01000000 } },
    { { 0x38000000 },	{ 0x38000000 } },
    { { 0x39000000 },	{ 0x39000000 } },
    { { 0x39800000 },	{ 0x39800000 } },

    { { 0x80800000 },	{ 0x80800000 } },
    { { 0x81000000 },	{ 0x81000000 } },
    { { 0xb8000000 },	{ 0xb8000000 } },
    { { 0xb9000000 },	{ 0xb9000000 } },
    { { 0xb9800000 },	{ 0xb9800000 } },
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
    union lofl_u x, z;
    int i;
    
    for (i = 0; i < (int) (sizeof(t) / sizeof(t[0])); i++) {
	x.lo = pgm_read_dword (& t[i].x);
	z.lo = pgm_read_dword (& t[i].z);
	v.fl = sinh (x.fl);
	/* Comparison is integer to verify the zero sign.	*/
	if (v.lo != z.lo)
	    x_exit (i+1);
    }
    return 0;
}
