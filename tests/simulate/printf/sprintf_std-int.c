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

/* Test of sprintf(), a set of decimal numbers.
   Is sutable for all variants: MIN, STD and FLT.
   $Id$	*/

#ifndef __AVR__
# define PRINTFLN(line, fmt, ...)	\
    printf("\nLine %2d: " fmt "\n", line, ##__VA_ARGS__)
# define EXIT(code)	exit ((code) < 255 ? (code) : 255)
# define sprintf_P	sprintf
#else
# if defined(__AVR_ATmega128__)
  /* ATmega128 has enough RAM for sprintf(), print to 0x2000 in XRAM. */
#  define PRINTFLN(line, fmt, ...)	\
    sprintf ((char *)0x2000, "\nLine %d: " fmt "\n", line, ##__VA_ARGS__)
# else
   /* small AVR */
#  define PRINTFLN(args...)
# endif
# define EXIT	exit
#endif

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "progmem.h"

void Check (int line,
            const char *expstr,
	    int retval, const char *retstr)
{
    int code;

    if (retval != (int)strlen (retstr))
	code = 1000 + line;
    else if (strcmp_P (retstr, expstr))
	code = line;
    else
	return;
    PRINTFLN (line, "expect: %3d, \"%s\",\n%8s output: %3d, \"%s\"\n",
	      strlen(expstr), expstr, " ", retval, retstr);
#ifdef	DEBUG
    code = (int)retstr;
#endif
    EXIT (code);
}

/* 'vp' is used to avoid gcc warnings about format string.	*/
#define CHECK(expstr, fmt, ...)	do {				\
    char s[260];						\
    int i;							\
    int (* volatile vp)(char *, const char *, ...) = sprintf_P;	\
    memset (s, 0, sizeof(s));					\
    i = vp (s, PSTR(fmt), ##__VA_ARGS__);			\
    Check (__LINE__, PSTR(expstr), i, s);			\
} while (0)

#define CHECK_2(fmt, val)	do {	\
    char s[20];				\
    int i;				\
    i = sprintf_P (s, PSTR(fmt), val);	\
    if (i <= 0 || i > 12)		\
	EXIT (__LINE__);		\
    if (val != strtoul(s, 0, 0))	\
	EXIT (__LINE__ + 1000);		\
} while (0)

int main ()
{
    unsigned long b1, b2;

    CHECK ("012345678", "%d%d%d%d%d%d%d%d%d", 0,1,2,3,4,5,6,7,8);
    CHECK ("9 10 11", "%d %d %d", 9, 10, 11);
    CHECK ("99 100 101", "%d %d %d", 99, 100, 101);
    CHECK ("999 1000 1001", "%d %d %d", 999, 1000, 1001);
    CHECK ("9999 10000 10001", "%d %d %d", 9999, 10000, 10001);
    CHECK ("99999 100000 100001", "%ld %ld %ld", 99999L, 100000L, 100001L);
    CHECK ("999999 1000000 1000001", "%ld %ld %ld",
	   999999L, 1000000L, 1000001L);
    CHECK ("9999999 10000000 10000001", "%ld %ld %ld",
	   9999999L, 10000000L, 10000001L);
    CHECK ("99999999 100000000 100000001", "%ld %ld %ld",
           99999999L, 100000000L, 100000001L);
    CHECK ("999999999 1000000000 1000000001", "%ld %ld %ld",
	   999999999L, 1000000000L, 1000000001L);
    CHECK ("2000000000 3000000000 4000000000 4294967295", "%lu %lu %lu %lu",
	   2000000000ul, 3000000000ul, 4000000000ul, 0xffffffff);

    /* Check a set of numbers.	*/
    for (b1 = 1; b1; b1 <<= 1) {
	for (b2 = 1; b2; b2 <<= 1) {
	    unsigned long x;
	    x = b1 | b2;
	    CHECK_2 ("%ld", x);
	    CHECK_2 ("%lu", x);
	    CHECK_2 ("%#lo", x);
	    CHECK_2 ("%#lx", x);
	    CHECK_2 ("%#lX", x);
	    x -= 1;
	    CHECK_2 ("%ld", x);
	    CHECK_2 ("%lu", x);
	    CHECK_2 ("%#lo", x);
	    CHECK_2 ("%#lx", x);
	    CHECK_2 ("%#lX", x);
	    x = ~(b1 | b2);
	    CHECK_2 ("%ld", x);
	    CHECK_2 ("%lu", x);
	    CHECK_2 ("%#lo", x);
	    CHECK_2 ("%#lx", x);
	    CHECK_2 ("%#lX", x);
	    x += 1;
	    CHECK_2 ("%ld", x);
	    CHECK_2 ("%lu", x);
	    CHECK_2 ("%#lo", x);
	    CHECK_2 ("%#lx", x);
	    CHECK_2 ("%#lX", x);
	}
    }
    return 0;
}
