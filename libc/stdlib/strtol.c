/*-
 * Copyright (c) 1990, 1993
 *	The Regents of the University of California.  All rights reserved.
 * Copyright (c) 2005, Dmitry Xmelkov
 *
 * Redistribution and use in source and binary forms, with or without
 * modification, are permitted provided that the following conditions
 * are met:
 * 1. Redistributions of source code must retain the above copyright
 *    notice, this list of conditions and the following disclaimer.
 * 2. Redistributions in binary form must reproduce the above copyright
 *    notice, this list of conditions and the following disclaimer in the
 *    documentation and/or other materials provided with the distribution.
 * 3. Neither the name of the University nor the names of its contributors
 *    may be used to endorse or promote products derived from this software
 *    without specific prior written permission.
 *
 * THIS SOFTWARE IS PROVIDED BY THE REGENTS AND CONTRIBUTORS ``AS IS'' AND
 * ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE
 * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE
 * ARE DISCLAIMED.  IN NO EVENT SHALL THE REGENTS OR CONTRIBUTORS BE LIABLE
 * FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL
 * DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS
 * OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)
 * HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT
 * LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY
 * OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF
 * SUCH DAMAGE.
 *
 * $Id$
 */

#include <limits.h>
#include <ctype.h>
#include <errno.h>
#include <stdlib.h>
#include "sectionname.h"

/*
 * Convert a string to a long integer.
 *
 * Ignores `locale' stuff.  Assumes that the upper and lower case
 * alphabets and digits are each contiguous.
 */
ATTRIBUTE_CLIB_SECTION
long
strtol(const char *nptr, char **endptr, register int base)
{
	register unsigned long acc;
	register unsigned char c;
	register unsigned long cutoff;
	register signed char any;
	unsigned char flag = 0;
#define FL_NEG	0x01		/* number is negative */
#define FL_0X	0x02		/* number has a 0x prefix */

	if (endptr)
		*endptr = (char *)nptr;
	if (base != 0 && (base < 2 || base > 36))
		return 0;

	/*
	 * Skip white space and pick up leading +/- sign if any.
	 * If base is 0, allow 0x for hex and 0 for octal, else
	 * assume decimal; if base is already 16, allow 0x.
	 */
	do {
		c = *nptr++;
	} while (isspace(c));
	if (c == '-') {
		flag = FL_NEG;
		c = *nptr++;
	} else if (c == '+')
		c = *nptr++;
	if ((base == 0 || base == 16) &&
	    c == '0' && (*nptr == 'x' || *nptr == 'X')) {
		c = nptr[1];
		nptr += 2;
		base = 16;
		flag |= FL_0X;
	}
	if (base == 0)
		base = c == '0' ? 8 : 10;

	/*
	 * Compute the cutoff value between legal numbers and illegal
	 * numbers.  That is the largest legal value, divided by the
	 * base.  An input number that is greater than this value, if
	 * followed by a legal input character, is too big.  One that
	 * is equal to this value may be valid or not; the decision
	 * about this is done as outlined below.
	 *
	 * Overflow detections works as follows:
	 *
	 * As:
	 *    acc_old <= cutoff
	 * then:
	 *    acc_old * base <= 0x80000000        (unsigned)
	 * then:
	 *    acc_old * base + c <= 0x80000000 + c
	 * or:
	 *    acc_new <= 0x80000000 + 35
	 *
	 * i.e. carry from MSB (by calculating acc_new) is impossible
	 * and we can check result directly:
	 *
	 *    if (acc_new > 0x80000000) then overflow
	 *
	 * Set any if any `digits' consumed; make it negative to indicate
	 * overflow.
	 */
#if  LONG_MIN != -LONG_MAX - 1
#  error "This implementation of strtol() does not work on this platform."
#endif
	switch (base) {
	    case 10:
		cutoff = ((unsigned long)LONG_MAX + 1) / 10;
		break;
	    case 16:
		cutoff = ((unsigned long)LONG_MAX + 1) / 16;
		break;
	    case 8:
		cutoff = ((unsigned long)LONG_MAX + 1) / 8;
		break;
	    case 2:
		cutoff = ((unsigned long)LONG_MAX + 1) / 2;
		break;
	    default:
		cutoff = ((unsigned long)LONG_MAX + 1) / base;
	}

	for (acc = 0, any = 0;; c = *nptr++) {
		if (c >= '0' && c <= '9')
			c -= '0';
		else if (c >= 'A' && c <= 'Z')
			c -= 'A' - 10;
		else if (c >= 'a' && c <= 'z')
			c -= 'a' - 10;
		else
			break;
		if (c >= base)
			break;
		if (any < 0)
			continue;
		if (acc > cutoff) {
			any = -1;
			continue;
		}
		acc = acc * base + c;
		if (acc > (unsigned long)LONG_MAX + 1)
			any = -1;
		else
			any = 1;
	}
	if (endptr) {
		if (any)
		    *endptr = (char *)nptr - 1;
		else if (flag & FL_0X)
		    *endptr = (char *)nptr - 2;
	}
	if (any < 0) {
		acc = (flag & FL_NEG) ? LONG_MIN : LONG_MAX;
		errno = ERANGE;
	} else if (flag & FL_NEG) {
		acc = -acc;
	} else if ((signed long)acc < 0) {
		acc = LONG_MAX;
		errno = ERANGE;
	}
	return (acc);
}
