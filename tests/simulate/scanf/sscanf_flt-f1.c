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
    /* All possible conversion symbols.	*/
    CHECK (
	6,
	v.x[0] == 1.0 && v.x[1] == 2.0 && v.x[2] == 3.0
	&& v.x[3] == 4.0 && v.x[4] == 5.0 && v.x[5] == 6.0,
	"1 2 3 4 5 6", "%e %E %f %F %g %G",
	& v.x[0], & v.x[1], & v.x[2], & v.x[3], & v.x[4], & v.x[5]);

    /* Empty input.	*/
    CHECK (-1, (*(char *)v.x == FILL), "", "%e", v.x);
    CHECK (-1, (*(char *)v.x == FILL), "", " %e", v.x);
    CHECK (-1, (*(char *)v.x == FILL), " ", " %e", v.x);
    CHECK (-1, (*(char *)v.x == FILL), " ", "  %e", v.x);
    CHECK (-1, (*(char *)v.x == FILL), "\t\n\v\f\r", " %e", v.x);

    /* 0.0	*/
    CHECK (
	6,
	v.x[0] == 0.0 && v.x[1] == 0.0 && v.x[2] == 0.0
	&& v.x[3] == 0.0 && v.x[4] == 0.0 && v.x[5] == 0.0,
	"0 0. .0 0.0 +0 +0.0", "%e %e %e %e %e %e",
	& v.x[0], & v.x[1], & v.x[2], & v.x[3], & v.x[4], & v.x[5]);

    /* -0.0	*/
    CHECK (
	6,
	v.x[0] == -0.0 && v.x[1] == -0.0 && v.x[2] == -0.0
	&& v.x[3] == -0.0 && v.x[4] == -0.0 && v.x[5] == -0.0,
	"-0 -0. -.0 -0.0 -00 -0e+00", "%e %e %e %e %e %e",
	& v.x[0], & v.x[1], & v.x[2], & v.x[3], & v.x[4], & v.x[5]);

    /* End of number.	*/
    CHECK (
	12,
	v.x[0] == 123 && v.c[0] == ' '
	&& v.x[1] == 456 && v.c[1] == '\001'
	&& v.x[2] == 789 && v.c[2] == '\377'
	&& v.x[3] == 12. && v.c[3] == '/'
	&& v.x[4] == 345 && v.c[4] == ':'
	&& v.x[5] == 678 && v.c[5] == 'd',
	"123 456\001789\377012/345:678d+11",
	"%e%c %e%c %e%c %e%c %e%c %e%c",
	& v.x[0], & v.c[0], & v.x[1], & v.c[1], & v.x[2], & v.c[2],
	& v.x[3], & v.c[3], & v.x[4], & v.c[4], & v.x[5], & v.c[5]);

    CHECK (
	12,
	v.x[0] == 234 && v.c[0] == '.'
	&& v.x[1] == 567 && v.c[1] == '+'
	&& v.x[2] == 890 && v.c[2] == '-'
	&& v.x[3] == 123 && v.c[3] == 'f'
	&& v.x[4] == 456 && v.c[4] == '\177'
	&& v.x[5] == 0.5 && v.c[5] == '.',
	"234..567+890-123f+456\1770.5.",
	"%e%c %e%c %e%c %e%c %e%c %e%c",
	& v.x[0], & v.c[0], & v.x[1], & v.c[1], & v.x[2], & v.c[2],
	& v.x[3], & v.c[3], & v.x[4], & v.c[4], & v.x[5], & v.c[5]);

    return 0;
}
