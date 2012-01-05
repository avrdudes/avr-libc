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

/* Test of scanf(): 'l' type modifier.
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
    long i[10];
} v = { {1} };

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

int main ()
{
    long n;

    /* Empty input.	*/
    CHECK (-1, (*(char *)v.i == FILL), "", "%ld", v.i);
    CHECK (-1, (*(char *)v.i == FILL), "", " %ld", v.i);
    CHECK (-1, (*(char *)v.i == FILL), " ", " %ld", v.i);
    CHECK (-1, (*(char *)v.i == FILL), " ", "  %ld", v.i);
    CHECK (-1, (*(char *)v.i == FILL), "\t\n\v\f\r", " %ld", v.i);

    /* Normal conversion.	*/
    CHECK (1, (v.i[0] == 1234567890) && (*(char *)(v.i + 1) == FILL),
	   "1234567890", "%ld", v.i);
    CHECK (1, ((unsigned long)(v.i[0]) == 4111222333)
	      && (*(char *)(v.i + 1) == FILL),
	   "4111222333", "%lu", v.i);
    CHECK (1, (v.i[0] == 012345670123) && (*(char *)(v.i + 1) == FILL),
	   "012345670123", "%li", v.i);
    CHECK (1, ((unsigned long)(v.i[0]) == 021076543210)
	      && (*(char *)(v.i + 1) == FILL),
	   "21076543210", "%lo", v.i);
    CHECK (1, (v.i[0] == 0x12345678) && (*(char *)(v.i + 1) == FILL),
	   "12345678", "%lx", v.i);
    CHECK (1, (v.i[0] == 0x09ABCDEF) && (*(char *)(v.i + 1) == FILL),
	   "0x09ABCDEF", "%lX", v.i);
    CHECK (1, (v.i[0] == 0x01234567) && (*(char *)(v.i + 1) == FILL),
	   "1234567", "%lp", v.i);
    n = ~0L;
    CHECK (0, (n == 1) && (*(char *)(v.i) == FILL),
	   " ", " %ln", &n);

#if !defined(__AVR_AT90S8515__) /* this does not fit */
    /* All possible conversions.	*/
    CHECK (
	8,
	v.i[0] == 10 && v.i[1] == 20 && v.i[2] == 030 && v.i[3] == 040
	&& v.i[4] == 0x50 && v.i[5] == 0x60 && v.i[6] == 0x70 && v.i[7] == 22
	&& v.i[8] == 80,
	"10 20 030 40 50 60 70 80",
	"%ld %lu %li %lo %lx %lX %lp %ln %ld",
	v.i + 0, v.i + 1, v.i + 2, v.i + 3,
	v.i + 4, v.i + 5, v.i + 6, v.i + 7,
	v.i + 8);
#endif

    /* Width field.	*/
    CHECK (
	1,
	v.i[0] == 12 && *(unsigned char *)(v.i + 1) == FILL,
	"123", "%2ld", v.i);
    CHECK (
	1,
	v.i[0] == 98 && *(unsigned char *)(v.i + 1) == FILL,
	"00000000009876", "%12ld", v.i);

    /* Suppress a writing.	*/
    CHECK (0, (*(unsigned char *)v.i == FILL), "123", "%*ld", v.i);
    CHECK (2, (v.i[0] == 1) && (v.i[1] == 3) && (*(char *)(v.i + 2) == FILL),
	   "1 2 3", "%ld%*ld%ld", v.i, v.i + 1);

    return 0;
}
