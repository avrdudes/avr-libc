/* Copyright (c) 2002-2005  Michael Stumpf  <mistumpf@de.pepperl-fuchs.com>
   Copyright (c) 2006 Dmitry Xmelkov

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

#include <avr/pgmspace.h>
#include <ctype.h>
#include <errno.h>
#include <math.h>		/* INFINITY, NAN		*/
#include <stdlib.h>

/* double strtod (const char * nptr, char ** endptr);
 */

/* GCC before 4.2 does not use a library function to convert an unsigned
   long to float.  Instead it uses a signed long to float conversion
   function along with a large inline code to correct the result.	*/
#if	__GNUC__ <= 4  &&  __GNUC_MINOR__ < 2 
extern double __floatunsisf (unsigned long);	/* force library call	*/
#else
# define __floatunsisf(v)	(v)		/* is not needed	*/
#endif

PROGMEM static const float pwr_p10 [6] = {
    1e+1, 1e+2, 1e+4, 1e+8, 1e+16, 1e+32
};
PROGMEM static const float pwr_m10 [6] = {
    1e-1, 1e-2, 1e-4, 1e-8, 1e-16, 1e-32
};

/* PSTR() is not used to save 1 byte per string: '\0' at the tail.	*/
PROGMEM static const char pstr_inf[] = {'I','N','F'};
PROGMEM static const char pstr_inity[] = {'I','N','I','T','Y'};
PROGMEM static const char pstr_nan[] = {'N','A','N'};

double strtod (const char * nptr, char ** endptr)
{
    unsigned long acc;
    unsigned char c;
    int exp;
    double x;

    unsigned char flag;
#define FL_MINUS    0x01	/* number is negative	*/
#define FL_ANY	    0x02	/* any digit was readed	*/
#define FL_OVFL	    0x04	/* overflow was		*/
#define FL_DOT	    0x08	/* decimal '.' was	*/
#define FL_MEXP	    0x10	/* exponent 'e' is neg.	*/

    if (endptr)
	*endptr = (char *)nptr;

    do {
	c = *nptr++;
    } while (isspace (c));

    flag = 0;    
    if (c == '-') {
	flag = FL_MINUS;
	c = *nptr++;
    } else if (c == '+') {
	c = *nptr++;
    }
    
    if (!strncasecmp_P (nptr - 1, pstr_inf, 3)) {
	nptr += 2;
	if (!strncasecmp_P (nptr, pstr_inity, 5))
	    nptr += 5;
	if (endptr)
	    *endptr = (char *)nptr;
	return flag & FL_MINUS ? -INFINITY : +INFINITY;
    }
    
    /* NAN() construction is not realised.
       Length would be 3 characters only.	*/
    if (!strncasecmp_P (nptr - 1, pstr_nan, 3)) {
	if (endptr)
	    *endptr = (char *)nptr + 2;
	return NAN;
    }

    acc = 0;
    exp = 0;
    while (1) {
    
	c -= '0';
    
	if (c <= 9) {
	    flag |= FL_ANY;
	    if (!(flag & FL_OVFL)) {
		long tac;	/* temporary place for acc	*/

		/* 'acc = 10*acc + c'  with overflow control.
		   Multiplication: 10*x == ((x<<2) + x) << 1	*/
		tac = acc;
		asm (
		    /* tac <<= 2	*/
		    "clr     r0		\n"
	    "1:      lsl     %A2	\n\t"
		    "rol     %B2	\n\t"
		    "rol     %C2	\n\t"
		    "rol     %D2	\n\t"
		    "brcs    2f		\n\t"
		    "com     r0		\n\t"
		    "brmi    1b		\n\t"
		    /* tac += acc	*/
		    "add     %A2, %A0	\n\t"
		    "adc     %B2, %B0	\n\t"
		    "adc     %C2, %C0	\n\t"
		    "adc     %D2, %D0	\n\t"
		    "brcs    2f		\n\t"
		    /* tac <<= 1	*/
		    "lsl     %A2	\n\t"
		    "rol     %B2	\n\t"
		    "rol     %C2	\n\t"
		    "rol     %D2	\n\t"
		    "brcs    2f		\n\t"
		    /* tac += c		*/
		    "add     %A2, %1		\n\t"
		    "adc     %B2, __zero_reg__	\n\t"
		    "adc     %C2, __zero_reg__	\n\t"
		    "adc     %D2, __zero_reg__	\n\t"
		    "brcs    2f		\n\t"
		    /* acc = tac	*/
		    "mov     %A0, %A2	\n\t"
		    "mov     %B0, %B2	\n\t"
		    "mov     %C0, %C2	\n\t"
		    "mov     %D0, %D2	\n"
		    /* overflow flag	*/
	    "2:      sbc     %1, %1	"
		    : "=r" (acc), "=r" (c), "=r" (tac)
		    : "0" (acc), "1" (c), "2" (tac)
		    : "r0"
		);
		if (c) flag |= FL_OVFL;
	    }
	    if (flag & FL_DOT) {
		if (!(flag & FL_OVFL)) exp -= 1;
	    } else {
		if (flag & FL_OVFL) exp += 1;
	    }

	} else if (c == (('.'-'0') & 0xff)  &&  !(flag & FL_DOT)) {
	    flag |= FL_DOT;
	} else {
	    break;
	}
	c = *nptr++;
    }
    
    if (   c == (('e'-'0') & 0xff)
	|| c == (('E'-'0') & 0xff) )
    {
	int i;
	c = *nptr++;
	i = 2;
	if (c == '-') {
	    flag |= FL_MEXP;
	    c = *nptr++;
	} else if (c == '+') {
	    c = *nptr++;
	} else {
	    i = 1;
	}
	c -= '0';
	if (c > 9) {
	    nptr -= i;
	} else {
	    i = 0;
	    do {
		if (i < 3200)
		    i = 10*i + c;
		c = *nptr++ - '0';
	    } while (c <= 9);
	    if (flag & FL_MEXP)
		i = -i;
	    exp += i;
	}
    }
    
    if ((flag & FL_ANY) && endptr)
	*endptr = (char *)nptr - 1;
    
    x = __floatunsisf (acc);
    if ((flag & FL_MINUS) && (flag & FL_ANY))
	x = -x;
	
    if (x != 0) {
	int pwr;
	if (exp < 0) {
	    nptr = (void *)(pwr_m10 + 5);
	    exp = -exp;
	} else {
	    nptr = (void *)(pwr_p10 + 5);
	}
	for (pwr = 32; pwr; pwr >>= 1) {
	    for (; exp >= pwr; exp -= pwr) {
		union {
		    long lo;
		    float fl;
		} y;
		y.lo = pgm_read_dword ((float *)nptr);
		x *= y.fl;
	    }
	    nptr -= sizeof(float);
	}
	if (!isfinite(x) || x == 0)
	    errno = ERANGE;
    }

    return x;
}
