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

#include <math.h>
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
    float x[7];
    char c[7];
} v = { {1.0}, {1} };

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

int all_nans (const float v[], int n)
{
    int i;
    for (i = 0; i < n; i++) {
	if (!isnan (v[i]))
	    return 0;
    }
    return 1;
}

int main ()
{
    /* No valid digits.	*/
    CHECK (0, 1, ". ", "%e", & v.x[0]);
    CHECK (0, 1, "+ ", "%e", & v.x[0]);
    CHECK (0, 1, "- ", "%e", & v.x[0]);
    CHECK (0, 1, "E ", "%e", & v.x[0]);
    CHECK (0, 1, "+-123", "%e", & v.x[0]);
    CHECK (0, 1, "-+123", "%e", & v.x[0]);
    CHECK (0, 1, ".-123", "%e", & v.x[0]);
    CHECK (0, 1, ".+123", "%e", & v.x[0]);
    CHECK (0, 1, "e12", "%e", & v.x[0]);
    CHECK (0, 1, "- 1", "%e", & v.x[0]);
    CHECK (0, 1, "IN ", "%e", & v.x[0]);
    CHECK (0, 1, "NA ", "%e", & v.x[0]);
    CHECK (0, 1, "infinit ", "%e", & v.x[0]);

    /* NaN	*/
    CHECK (
	6,
	all_nans (v.x, 6),
	"nan NAN NaN -nan +NAN -nAn",
	"%E %e %F %f %G %g",
	& v.x[0], & v.x[1], & v.x[2], & v.x[3], & v.x[4], & v.x[5]);

    /* Character after NaN.	*/
    CHECK (
	10,
	all_nans (v.x, 6) && !memcmp_P (v.c, PSTR (".+eQ"), 4),
	"nan. nan+ nane NANQ nannan",
	"%e%c %e%c %e%c %e%c %e %e",
	& v.x[0], & v.c[0], & v.x[1], & v.c[1],	& v.x[2], & v.c[2],
	& v.x[3], & v.c[3], & v.x[4], & v.x[5]);
	
    /* Inf	*/
    CHECK (
	6,
	!memcmp_P (
	    v.x,
	    ({	static const float __x[] PROGMEM = {
		    INFINITY, INFINITY, INFINITY,
		    INFINITY, -INFINITY, -INFINITY
		};
		__x;
	    }),
	    6 * sizeof(float)),
	"INF inf +Inf INFINITY -infinity -InFiNiTy",
	"%e %E %f %F %g %G",
	& v.x[0], & v.x[1], & v.x[2], & v.x[3], & v.x[4], & v.x[5]);

#if !defined(__AVR_AT90S8515__) /* this does not fit */
    /* Character after Inf.	*/
    CHECK (
	9,
	!memcmp_P (
	    v.x,
	    ({	static const float __x[] PROGMEM = {
		    INFINITY, INFINITY, INFINITY,
		    INFINITY, INFINITY, -INFINITY
		};
		__x;
	    }),
	    6 * sizeof(float))
	&& !memcmp_P (v.c, PSTR (" s\b"), 3),
	"inf infinityinfinitys INF\b inf-inf",
	"%e%c %e%e%c %e%c %e%e",
	& v.x[0], & v.c[0],
	& v.x[1],
	& v.x[2], & v.c[1],
	& v.x[3], & v.c[2],
	& v.x[4],
	& v.x[5]);
#endif

    return 0;
}
