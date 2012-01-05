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

/* Test of scanf(): '[' conversion directive.
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
    char c[12];
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
    /* A few conversions.	*/
    CHECK (2, !memcmp_P(v.c, PSTR("AB\000CD\000"), 6),
	   "ABCD", "%[AB]%[CD]", v.c, v.c + 3);

    /* Suppress a writing.	*/
    CHECK (0, (v.c[0] == FILL), "A", "%*[A]", v.c);
    CHECK (2, !memcmp_P(v.c, PSTR("A\000C\000"), 4),
	   "ABC", "%[A]%*[B]%[C]", v.c, v.c + 2);

    /* Width field.	*/
    CHECK (1, !strcmp_P(v.c, PSTR("A")), "A", "%1[A]", v.c);
    CHECK (1, !strcmp_P(v.c, PSTR("A")), "ABCD", "%1[A-Z]", v.c);
    CHECK (1, !strcmp_P(v.c, PSTR("AB")), "ABCD", "%2[A-Z]", v.c);
    CHECK (2, !memcmp_P(v.c, PSTR("CD\000AB\000"), 6),
	   "ABCD", "%2[A-Z]%2[A-Z]", v.c + 3, v.c);
    CHECK (1, !strcmp_P(v.c, PSTR("the_quick_b")),
	   "the_quick_brown_fox", "%11[a-z_]", v.c);

    /* Suppress and width.	*/
    CHECK (0, (v.c[0] == FILL), "A", "%*1[A]", v.c);
    CHECK (0, (v.c[0] == FILL), "AA", "%*2[A]", v.c);

    /* Zero width.	*/
#ifdef	__AVR__
    CHECK (0, (v.c[0] == FILL && v.c[1] == FILL), "A", "%0[A]", v.c);
#else
    CHECK (1, !strcmp_P(v.c, PSTR("A")), "A", "%0[A]", v.c);	/* ??? */
#endif

    /* Left width digit is 0.	*/
    CHECK (1, !strcmp_P(v.c, PSTR("A")), "ABCD", "%01[A-Z]", v.c);
    CHECK (1, !strcmp_P(v.c, PSTR("AB")), "ABCD", "%02[A-Z]", v.c);

    /* Invalid symbol after '%'.	*/
    CHECK (0, (v.c[0] == FILL), "A", "% [A]", v.c);
    CHECK (0, (v.c[0] == FILL), "A", "%-[A]", v.c);
    CHECK (0, (v.c[0] == FILL), "A", "%+[A]", v.c);
    CHECK (0, (v.c[0] == FILL), "A", "%.[A]", v.c);
    CHECK (0, (v.c[0] == FILL), "A", "%#[A]", v.c);

    return 0;
}
