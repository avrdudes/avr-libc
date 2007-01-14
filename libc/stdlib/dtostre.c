/* Copyright (c) 2005, Dmitry Xmelkov
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
  POSSIBILITY OF SUCH DAMAGE. */

/* $Id$ */

#include <stdlib.h>
#include "ftoa_engine.h"

char *
dtostre (double val, char *sbeg, unsigned char prec, unsigned char flags)
{
    char *d;		/* dst	*/
    char *s;		/* src	*/
    signed char exp;
    unsigned char vtype;

    if (prec > 7) prec = 7;
    
    exp = __ftoa_engine (val, sbeg, prec, 0);
    d = s = sbeg;
    vtype = *s++;

    if ((vtype & FTOA_MINUS) && !(vtype & FTOA_NAN))	/* like 'Glibc'	*/
	*d++ = '-';
    else if (flags & DTOSTR_PLUS_SIGN)
	*d++ = '+';
    else if (flags & DTOSTR_ALWAYS_SIGN)
	*d++ = ' ';

    if (vtype & FTOA_NAN) {
	if (flags & DTOSTR_UPPERCASE) {
	    *d++ = 'N';  *d++ = 'A';  *d++ = 'N';
	} else {
	    *d++ = 'n';  *d++ = 'a';  *d++ = 'n';
	}
	goto ret;
    }
    
    if (vtype & FTOA_INF) {
	if (flags & DTOSTR_UPPERCASE) {
	    *d++ = 'I';  *d++ = 'N';  *d++ = 'F';
	} else {
	    *d++ = 'i';  *d++ = 'n';  *d++ = 'f';
	}
	goto ret;
    }
    
    /* mantissa	*/
    if ( (*d++ = *s++) != '1')
	vtype &= ~FTOA_CARRY;		/* for possible exponent "-00"	*/
    if (prec) {
	unsigned char c1, c2;
	c1 = '.';
	do {
	    c2 = *s++;
	    *d++ = c1;
	    c1 = c2;
	} while (--prec);
	*d++ = c1;
    }

    /* exponent	*/
    *d++ = (flags & DTOSTR_UPPERCASE) ? 'E' : 'e';
    if (exp < 0) {
	*d++ = '-';
	exp = -exp;
    } else if (exp == 0 && (vtype & FTOA_CARRY) != 0) {
	*d++ = '-';
    } else {
	*d++ = '+';
    }
    for (prec = '0';  exp >= 10;  exp -= 10)
	prec += 1;
    *d++ = prec;
    *d++ = '0' + exp;
    
  ret:
    *d = 0;
    return sbeg;
}
			/*** end of file ***/
