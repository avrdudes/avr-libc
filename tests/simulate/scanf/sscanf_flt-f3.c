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
    union {
	long lo;
	float fl;
    } x[8];
} v = { {{1.0}} };

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
    /* The smallest.	*/
    CHECK (
	2,
	v.x[0].lo == 0x00000001 && v.x[1].lo == 0x00000002,
	"0.0000000000000000000000000000000000000000000014 "
	"0.0000000000000000000000000000000000000000000028",
	"%e %e",
	& v.x[0].fl, & v.x[1].fl);

    CHECK (
	8,
	v.x[0].lo == 0x00000001 && v.x[1].lo == 0x00000001
	&& v.x[2].lo == 0x00000001 && v.x[3].lo == 0x00000001
	&& v.x[4].lo == 0x00000001 && v.x[5].lo == 0x00000001
	&& v.x[6].lo == 0x00000001 && v.x[7].lo == 0x00000001,
	"1.4012985e-45 "
	"1.401298e-45 "
	"1.40130e-45 "
	"1.4013e-45 "
	"1.401e-45 "
	"1.40e-45 "
	"1.4e-45 "
	"1e-45",
	"%e %e %e %e %e %e %e %e",
	& v.x[0].fl, & v.x[1].fl, 
	& v.x[2].fl, & v.x[3].fl, 
	& v.x[4].fl, & v.x[5].fl, 
	& v.x[6].fl, & v.x[7].fl);

    /* The biggest.	*/
    CHECK (
	1,
	v.x[0].lo == 0x7f7fffff,
	"340282350000000000000000000000000000000",
	"%e",
	& v.x[0].fl);

    /* Note: it is impossible to obtain 0x7f7fffff with AVR
       due to round errors.	*/
    CHECK (
	2,
	v.x[0].lo == 0x7f7ffffc || v.x[1].lo == 0x7f7ffffb,
	"3.4028229e+38 3.4028228e+38",
	"%e %e",
	& v.x[0].fl, & v.x[1].fl);

    /* Underflow.	*/
    CHECK (
	4,
	v.x[0].fl == -0.0 && v.x[1].fl == 0.0
	&& v.x[2].fl == 0 && v.x[3].fl == -0.0,
	"-0.7e-45 1e-99 "
	"0.0000000000000000000000000000000000000000000007 "	/* 0.7e-45 */
	"-0.000000000000000000000000000000000000000000000000000000000099999 ",
	"%e %e %e %e",
	& v.x[0].fl, & v.x[1].fl, & v.x[2].fl, & v.x[3].fl);

    /* Overflow.	*/
    CHECK (
	4,
	v.x[0].fl == INFINITY && v.x[1].fl == -INFINITY
	&& v.x[2].fl == -INFINITY && v.x[3].fl == INFINITY,
	"3.4028236e+38 -1e99 "
	"-340282360000000000000000000000000000000 "
	"10000000000000000000000000000000000000000000000000000000000000000",
	"%e %e %e %e",
	& v.x[0].fl, & v.x[1].fl, & v.x[2].fl, & v.x[3].fl);

    return 0;
}
