/* Copyright (c) 2007  Dmitry Xmelkov
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

/* Test of strtod() function. Base cases.
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
    float val;
    int eno;
} t[] = {

    /* Empty string	*/
    { "", 0,	0, 0 },
    { " ", 0,	0, 0 },
    { "\t\n\r\f\v", 0, 0, 0 },

    /* 0.0	*/
    { "0", 1,		0.0, 0 },
    { "0.0", 3,		0.0, 0 },
    { "+0", 2,		0.0, 0 },
    { "+0.0", 4,	0.0, 0 },
    
    /* -0.0	*/
    { "-0", 2,		-0.0, 0 },
    { "-0.0", 4,	-0.0, 0 },
    
    /* Leading spaces	*/
    { " \t\n\r\f\v1", 7,	1, 0 },
    
    /* Non-zero character at the end of number	*/
    { "123 ", 3, 123, 0 },
    { "123/", 3, 123, 0 },
    { "123:", 3, 123, 0 },
    { "123\x01", 3, 123, 0 },
    { "123\xff", 3, 123, 0 },
    { "123-", 3, 123, 0 },
    { "123+", 3, 123, 0 },
    { "123..", 4, 123, 0 },

    /* No valid digits	*/
    { ".", 0,	0, 0 },
    { "+", 0,	0, 0 },
    { "-", 0,	0, 0 },
    { "e", 0,	0, 0 },
    { "E", 0,	0, 0 },
    { "+-123", 0, 0, 0 },
    { "-+123", 0, 0, 0 },
    { ".-123", 0, 0, 0 },
    { ".+123", 0, 0, 0 },
    { "e12",   0, 0, 0 },
    { "- 1",   0, 0, 0 },
    { "IN",    0, 0, 0 },
    { "NA",    0, 0, 0 },
    
    /* Infinity	*/
    { "INF", 3,		INFINITY, 0 },
    { " inf", 4,	INFINITY, 0 },
    { "+Inf", 4,	INFINITY, 0 },

    { "-INF", 4,	-INFINITY, 0 },
    { "\t-inF", 5,	-INFINITY, 0 },
    
    { "INFINITY", 8,	INFINITY, 0 },
    { "-InFiNiTy", 9,	-INFINITY, 0 },

    { "INFINIT", 3,	INFINITY, 0 },
    { "infinitys", 8,	INFINITY, 0 },
    
    /* NaN	*/
    { "NAN", 3,		NAN, 0 },
    { " nan", 4,	NAN, 0 },
    { "-NaN", 4,	NAN, 0 },
    { "NANQ", 3,	NAN, 0 },
    
    /* Overflow	*/
    { "1e309", 5,	INFINITY, ERANGE },
    { "-1e309", 6,	-INFINITY, ERANGE },

    { "1e32767", 7,		INFINITY, ERANGE },
    { "1e32768", 7,		INFINITY, ERANGE },
    { "1e32769", 7,		INFINITY, ERANGE },
    { "1e9999999999", 12,	INFINITY, ERANGE },
    
    /* Underflow	*/
    { "1e-350", 6,	0.0, ERANGE },
#ifdef	__AVR__
    { "-1e-350", 7,	-0.0, ERANGE },
#else
    { "-1e-350", 7,	0.0, ERANGE },		/* ???	*/
#endif
    { "1e-32767", 8,		0.0, ERANGE },
    { "1e-32768", 8,		0.0, ERANGE },
    { "1e-32769", 8,		0.0, ERANGE },
    { "1e-9999999999", 13,	0.0, ERANGE },
    
    /* Nonregular cases	*/
    { "1234.5", 6,	1234.5, 0 },
    { "-9.876e12", 9,	-9.876e12, 0 },
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
	mst.fl = pgm_read_float (& t[i].val);
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
