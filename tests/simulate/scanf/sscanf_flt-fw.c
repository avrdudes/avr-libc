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

/* Test of scanf(): float conversion, width field.
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
    float x[8];
    char s[8];
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
	char fmt_s[50];							\
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
    /* 1 character.	*/
#ifdef	__AVR__
    /* ???: Glibc gets 2 characters and places 1.0 into v.x	*/
    CHECK (1, v.x[0] == 0, "01", "%1e", v.x);
#endif
    CHECK (1, v.x[0] == 1, "1", "%1e", v.x);
    CHECK (
	2,
	v.x[0] == 2 && v.x[1] == 9,
	"298", "%1f%1g", v.x, v.x + 1);

    /* Space before number.	*/
    CHECK (1, v.x[0] == 12, " 1234.5", "%2e", v.x);

    /* All possible symbols of float number.	*/
    CHECK (
	16,
	!memcmp_P (
	    v.x,
	    ({	static const float __x[8] PROGMEM = {
		    12, -45, 0.5, 10, .25, 1e1, 2e2, .125
		};  __x; }),
	    8 * sizeof(float))
	&& !memcmp_P (v.s, PSTR("36759093"), 8),
	"+123 -456 0.57 10.5 .259 1e10 2e+29 125.e-33",
	"%3e%c %3e%c %3e%c %3e%c %3e%c %3e%c %4e%c %7e%c",
	v.x + 0, v.s + 0, v.x + 1, v.s + 1,
	v.x + 2, v.s + 2, v.x + 3, v.s + 3,
	v.x + 4, v.s + 4, v.x + 5, v.s + 5,
	v.x + 6, v.s + 6, v.x + 7, v.s + 7);

    /* Suppress and width.	*/
    CHECK (0, (*(char *)v.x == FILL), "9", "%*1e", v.x);
    CHECK (1, v.x[0] == 76, "9876", "%*2e%2e", v.x);

    return 0;
}
