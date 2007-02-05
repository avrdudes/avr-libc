/* Test of tanh() function. ULP control.
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
    union lofl_u z;		/* tanh(x)	*/
    unsigned int maxulp;	/* max possible error in ULP	*/
} t[] = {

    { { .fl= 0 },	{ .fl= 0 },	0 },
    { { 0x3a000000 },	{ 0x39ffffff },		1 },
    { { 0x3b000000 },	{ 0x3affffeb },		1 },
    { { 0x3e0ffffe },	{ 0x3e0f0ee6 },		4 },
    { { 0x3e0fffff },	{ 0x3e0f0ee7 },		4 },
    { { 0x3e100000 },	{ 0x3e0f0ee8 },		3 },	/* .140625	*/
    { { 0x3e100001 },	{ 0x3e0f0ee9 },		3 },
    { { .fl= 0.25 },	{ .fl= .24491866 },	1 },
    { { .fl= 0.5 },	{ .fl= .46211716 },	1 },
    { { .fl= 1 },	{ .fl= .76159416 },	1 },
    { { .fl= 2 },	{ .fl= .96402758 },	1 },
    { { .fl= 5 },	{ .fl= .99990920 },	1 },
    { { .fl= 10 },	{ .fl= 1.0 },	0 },
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
    unsigned int maxulp;
    unsigned long v1, z1, r;
    int i;
    
    for (i = 0; i < (int) (sizeof(t) / sizeof(t[0])); i++) {
	x.lo = pgm_read_dword (& t[i].x);
	z.lo = pgm_read_dword (& t[i].z);
	maxulp = pgm_read_word (& t[i].maxulp);
	v.fl = tanh (x.fl);
	
	v1 = (v.lo < 0) ? (unsigned long)~(v.lo) : v.lo + 0x80000000;
	z1 = (z.lo < 0) ? (unsigned long)~(z.lo) : z.lo + 0x80000000;
	r = (v1 >= z1) ? v1 - z1 : z1 - v1;
	
	if (r > maxulp) x_exit (i+1);
    }
    return 0;
}
