/* Copyright (c) 2008  Dmitry Xmelkov
   All rights reserved.

   Redistribution and use in source and binary forms, with or without
   modification, are permitted provided that the following conditions are met:

   * Redistributions of source code must retain the above copyright
     notice, this list of conditions and the following disclaimer.
   * Redistributions in binary form must reproduce the above copyright
     notice, this list of conditions and the following disclaimer in
     the documentation and/or other materials provided with the
     distribution.
   * Neither the name of the copyright holders nor the names of
     contributors may be used to endorse or promote products derived
     from this software without specific prior written permission.

   THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS "AS IS"
   AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE
   IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE
   ARE DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT OWNER OR CONTRIBUTORS BE
   LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR
   CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF
   SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS
   INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN
   CONTRACT, STRICT LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE)
   ARISING IN ANY WAY OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE
   POSSIBILITY OF SUCH DAMAGE.
 */

/* Test of strtod() function. big/small values.
   $Id$
 */
#include <errno.h>
#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "progmem.h"

union lofl_u {
    long lo;
    float fl;
};

volatile union lofl_u v = { .lo = 1 };

PROGMEM const struct {		/* Table of test cases.	*/
    char s[20];
    unsigned char len;
    union lofl_u val;
    int eno;
} t[] = {

    { "1.4012985e-45", 13,	{ 0x00000001 }, 0 },
    { "1.401298e-45", 12,	{ 0x00000001 }, 0 },
    { "1.40130e-45", 11,	{ 0x00000001 }, 0 },
    { "1.4013e-45", 10,		{ 0x00000001 }, 0 },
    { "1.401e-45", 9,		{ 0x00000001 }, 0 },
    { "1.40e-45", 8,		{ 0x00000001 }, 0 },
    { "1.4e-45", 7,		{ 0x00000001 }, 0 },
    { "1e-45", 5,		{ 0x00000001 }, 0 },

    { "3e-45", 5,		{ 0x00000002 }, 0 },

#ifndef	__AVR__    	/* strtod() is't absolutely accurate today	*/
    { "3.4028235e+38", 13,	{ 0x7f7fffff }, 0 },
#endif
    { "3.4028229e+38", 13,	{ 0x7f7ffffc }, 0 },

    /* Near acc overflow.	*/
    { "4294967200", 10,	{ .fl = 4294967200 }, 0 },
    { "4294967270", 10,	{ .fl = 4294967300 }, 0 },
    { "4294967279", 10,	{ .fl = 4294967300 }, 0 },
    { "4294967280", 10,	{ .fl = 4294967300 }, 0 },
    { "4294967289", 10,	{ .fl = 4294967300 }, 0 },
    { "4294967290", 10,	{ .fl = 4294967300 }, 0 },
    { "4294967295", 10, { .fl = 4294967300 }, 0 },	/* 0xffffffff	*/
    { "4294967296", 10, { .fl = 4294967300 }, 0 },
    { "4294967400", 10,	{ .fl = 4294967400 }, 0 },
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
    char s [sizeof(t[0].s)];
    char *p;
    union lofl_u mst;
    unsigned char len;
    int eno;
    int i;
    
    for (i = 0; i < (int) (sizeof(t) / sizeof(t[0])); i++) {
	strcpy_P (s, t[i].s);
	len = pgm_read_byte (& t[i].len);
	mst.lo = pgm_read_dword (& t[i].val);
	eno = pgm_read_word (& t[i].eno);
	
	errno = 0;
	p = 0;
	v.fl = strtod (s, &p);
	
	if (!p || (p - s) != len || errno != eno)
	    x_exit (i+1);
	if (isnan(mst.fl) && isnan(v.fl))
	    continue;
	if (v.lo != mst.lo)
	    x_exit (i+1);
    }
    return 0;
}
