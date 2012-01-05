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

/* Test of scanf(): float conversion.
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
    float x[10];
} v = { {1.0} };

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
    PROGMEM static const float ones[10] = {1, 1, 1, 1, 1, 1, 1, 1, 1, 1};

    /* All symbols.	*/
    CHECK (
	4,
	v.x[0] == 12345678 && v.x[1] == 0.25
	&& v.x[2] == 90 && v.x[3] == -0.5,
	"12345678 .25e0 +9e+01 -0.5E-00",
	"%e %e %e %e",
	& v.x[0], & v.x[1], & v.x[2], & v.x[3]);

    /* 1.0	*/
    CHECK (
	10,
	!memcmp_P (v.x, ones, 10 * sizeof(float)),
	"1. 1.0 01 001. 0001.0 00001.00 1.e0 1.00000e000000 1e+00 1e-0",
	"%e %e %e %e %e %e %e %e %e %e",
	& v.x[0], & v.x[1], & v.x[2], & v.x[3],	& v.x[4],
	& v.x[5], & v.x[6], & v.x[7], & v.x[8], & v.x[9]);

    /* Negative exponents.	*/
    CHECK (
	10,
	!memcmp_P (v.x, ones, 10 * sizeof(float)),
	"10e-1 "
	"100e-2 "
	"1000e-3 "
	"10000e-4 "
	"100000e-5 "
	"1000000e-6 "
	"10000000e-7 "
	"100000000e-8 "
	"1000000000e-9 "
	"10000000000e-10 ",
	"%e %e %e %e %e %e %e %e %e %e",
	& v.x[0], & v.x[1], & v.x[2], & v.x[3],	& v.x[4],
	& v.x[5], & v.x[6], & v.x[7], & v.x[8], & v.x[9]);

    CHECK (
	10,
	!memcmp_P (v.x, ones, 10 * sizeof(float)),
	"100000000000e-11 "
	"1000000000000e-12 "
	"10000000000000e-13 "
	"100000000000000e-14 "
	"1000000000000000e-15 "
	"10000000000000000e-16 "
	"100000000000000000e-17 "
	"1000000000000000000e-18 "
	"10000000000000000000e-19 "
	"100000000000000000000e-20 ",
	"%e %e %e %e %e %e %e %e %e %e",
	& v.x[0], & v.x[1], & v.x[2], & v.x[3],	& v.x[4],
	& v.x[5], & v.x[6], & v.x[7], & v.x[8], & v.x[9]);

    /* Positive exponents.	*/
    CHECK (
	10,
	!memcmp_P (v.x, ones, 10 * sizeof(float)),
	".1e1 "
	".01e2 "
	".001e3 "
	".0001e4 "
	".00001e5 "
	".000001e6 "
	".0000001e7 "
	".00000001e8 "
	".000000001e9 "
	".0000000001e10 ",
	"%e %e %e %e %e %e %e %e %e %e",
	& v.x[0], & v.x[1], & v.x[2], & v.x[3],	& v.x[4],
	& v.x[5], & v.x[6], & v.x[7], & v.x[8], & v.x[9]);

    CHECK (
	10,
	!memcmp_P (v.x, ones, 10 * sizeof(float)),
	".00000000001e11 "
	".000000000001e12 "
	".0000000000001e13 "
	".00000000000001e14 "
	".000000000000001e15 "
	".0000000000000001e16 "
	".00000000000000001e17 "
	".000000000000000001e18 "
	".0000000000000000001e19 "
	".00000000000000000001e20 ",
	"%e %e %e %e %e %e %e %e %e %e",
	& v.x[0], & v.x[1], & v.x[2], & v.x[3],	& v.x[4],
	& v.x[5], & v.x[6], & v.x[7], & v.x[8], & v.x[9]);

    return 0;
}
