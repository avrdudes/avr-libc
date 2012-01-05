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

/* Test of scanf(): 'o' conversion directive.
   $Id$	*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "progmem.h"

#ifdef	__AVR__
# define ASSERT(expr)			\
    do {				\
	if (!(expr)) exit(__LINE__);	\
    } while (0)
# define EXIT(v)	exit (v)
# if defined(__AVR_ATmega128__)
  /* ATmega128 has enough RAM for sprintf(), print to 0x2000 in XRAM. */
#  define PRINTF(f...)	sprintf((char *)0x2000, f)
# else
  /* small AVR */
#  define PRINTF(f...)
# endif
#else
# include <assert.h>
# define ASSERT(expr)	assert (expr)
# define EXIT(v)	exit ((v) < 256 ? (v) : 255)
# define PRINTF(f...)	printf (f)
# define sscanf_P	sscanf
# define memcmp_P	memcmp
#endif

/* Next variables are useful to debug the AVR.	*/
int vrslt = 1;
struct {
    unsigned int i[10];
    char s[10];
} v = { {1}, {1} };

void Check (int line, int expval, int rslt)
{
    vrslt = rslt;
    if (rslt != expval) {
	PRINTF ("\nLine %d:  expect= %d, rslt= %d\n", line, expval, rslt);
	EXIT (line);
    }
}

/* The sscanf() is called 4 times: SRAM and FLASH format, 2 values
   to fill before run.	*/
#define CHECK(expval, ass_expr, str, fmt, ...)				\
    do {								\
	PROGMEM static const char fmt_p[] = fmt;			\
	char str_s[220];						\
	char fmt_s[40];							\
	char FILL;							\
	int i;								\
	int (* volatile vp)(const char *, const char *, ...);		\
									\
	ASSERT (sizeof(str_s) >= sizeof(str));				\
	ASSERT (sizeof(fmt_s) >= sizeof(fmt_p));			\
	strcpy_P (str_s, PSTR(str));					\
	strcpy_P (fmt_s, fmt_p);					\
									\
	for (FILL = 0; FILL < 4; FILL++) {				\
	    memset (&v, FILL, sizeof(v));				\
	    vp = (FILL & 1) ? sscanf_P : sscanf;			\
	    i = vp (str_s, (FILL & 1) ? fmt_p : fmt_s, ##__VA_ARGS__);	\
	    Check (__LINE__, expval, i);				\
    	    ASSERT (ass_expr);						\
	}								\
    } while (0)

#define	PVEC(args...)	({ static const int __x[] PROGMEM = {args}; __x; })

int main ()
{
    /* Empty input.	*/
    CHECK (-1, (*(char *)v.i == FILL), "", "%o", v.i);
    CHECK (-1, (*(char *)v.i == FILL), "", " %o", v.i);
    CHECK (-1, (*(char *)v.i == FILL), " ", " %o", v.i);
    CHECK (-1, (*(char *)v.i == FILL), " ", "  %o", v.i);
    CHECK (-1, (*(char *)v.i == FILL), "\t\n\v\f\r", " %o", v.i);

    /* Normal conversion.	*/
    CHECK (1, (v.i[0] == 0), "0", "%o", v.i);
    CHECK (
	10,
	!memcmp_P (
	    v.i,
	    PVEC (0, 0, 1, 0123456, 077777, 0100000, 0177777, -1,
		  012345, -07654),
	    10 * sizeof(int)),
	"+0 -0 1 123456 77777 100000 177777 -1 +12345 -7654",
	"%o %o %o %o %o %o %o %o %o %o",
	v.i + 0, v.i + 1,
	v.i + 2, v.i + 3,
	v.i + 4, v.i + 5,
	v.i + 6, v.i + 7,
	v.i + 8, v.i + 9);

    /* Leading spaces.	*/
    CHECK (1, (v.i[0] == 012), " 12", "%o", v.i);
    CHECK (1, (v.i[0] == 0123), "\t\n\v\f\r123", "%o", v.i);

    /* Leading '0'.	*/
    CHECK (1, (v.i[0] == 04567), "04567", "%o", v.i);
    CHECK (1, (v.i[0] == 07654), "00000000007654", "%o", v.i);

    /* End of number.	*/
    CHECK (2, v.i[0] == 0 && v.s[0] == 'x', "0x1", "%o%c", v.i, v.s);
    CHECK (
	14,
	!memcmp_P (v.i, PVEC (1,2,3,4,5,6,7), 7 * sizeof(int))
	&& !memcmp_P (v.s, PSTR(" \n.89\001\377"), 7),
	"1 2\n3.48596\0017\3776",
	"%o%c%o%c%o%c%o%c%o%c%o%c%o%c",
	v.i + 0, v.s + 0,
	v.i + 1, v.s + 1,
	v.i + 2, v.s + 2,
	v.i + 3, v.s + 3,
	v.i + 4, v.s + 4,
	v.i + 5, v.s + 5,
	v.i + 6, v.s + 6);
    CHECK (
	3,
	!memcmp_P (v.i, PVEC (1, -2, 3), 3 * sizeof(int)),
	"1-2+3", "%o%o%o", v.i, v.i + 1, v.i + 2);

    return 0;
}
