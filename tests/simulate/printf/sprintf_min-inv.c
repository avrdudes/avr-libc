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

/* Test of sprintf_min(), invalid format.
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
	    int explen,
            const char *expstr,
	    int retval, const char *retstr)
{
    int code;

    if (retval != explen)
	code = 1000 + line;
    else if (strcmp_P (retstr, expstr))
	code = line;
    else
	return;
    PRINTFLN (line, "expect: %3d, \"%s\",\n%8s output: %3d, \"%s\"\n",
	      explen, expstr, " ", retval, retstr);
#ifdef	DEBUG
    code = (int)retstr;
#endif
    EXIT (code);
}

/* 'vp' is used to avoid gcc warnings about format string.	*/
#define CHECK(explen, expstr, fmt, ...)	do {			\
    char s[260];						\
    int i;							\
    int (* volatile vp)(char *, const char *, ...) = sprintf_P;	\
    memset (s, 0, sizeof(s));					\
    i = vp (s, PSTR(fmt), ##__VA_ARGS__);			\
    Check (__LINE__, explen, PSTR(expstr), i, s);		\
} while (0)

int main ()
{
    /* Format last symbol is absent	*/
#ifdef	__AVR__		/* Glibc return -1, if '%' has not a format spec. */
    CHECK (0, "", "%");
    CHECK (1, ".", ".%");
    CHECK (1, ".", ".%0");
    CHECK (6, "12345 ", "%d %+l", 12345);
#endif

    /* 'hh' length modifier is possible, but it is ignored in avr-libc	*/
    CHECK (3, "123", "%hhd", 123);
    
    /* Length modifier and conversion mismatch: ignored	*/
    CHECK (1, "a", "%hhc", 'a');
    CHECK (1, "b", "%hc", 'b');
    CHECK (3, "foo", "%hhs", "foo");
    CHECK (3, "foo", "%hs", "foo");
    
    /* If the `space' and `+' flags both appear, the `space' flag
       is ignored.	*/
#ifdef	__AVR__
    CHECK (5, "10.11", "% +d.%+ d", 10, 11);	/* PRINTF_MIN: both ignored */
#else
    CHECK (7, "+10.+11", "% +d.%+ d", 10, 11);
#endif
    
#ifdef	__AVR__
    /* Unknown format: glibc output is "%b", return value 2.	*/
    CHECK (0, "", "%b");

    /* Two precision dots.	*/
    // CHECK (-1, "", "%8..4d", 1);
    CHECK (1, "1", "%8..4d", 1);	/* PRINTF_MIN: not checked	*/
    
    /* Long long arg	*/
    CHECK (0, "", "%lld", 1LL);

    /* wint_t, wchar_t: ignore	*/
    CHECK (1, "c", "%lc", 'c');
    CHECK (3, "foo", "%ls", "foo");
    
    /* The asterisk `*' in width or precision.	*/
    CHECK (0, "", "%*d", 10, 12345);
    CHECK (0, "", "%10.*d", 6, 12345);
    CHECK (0, "", "%*.*d", 10, 6, 12345);
    
    /* Float numbers: are skipped	*/
    CHECK (1, "?", "%e", 0.0);
    CHECK (23, "? e ? f ? g ? E ? F ? G",
	 "%e %c %e %c %e %c %e %c %e %c %e %c",
	 1.0, 'e', 2.0, 'f', 3.0, 'g', 4.0, 'E', 5.0, 'F', 6.0, 'G');
    CHECK (14, "? 10 ? 11 ? 12",
	   "%+0e %d %-10f %d % 10.5g %d",
	   10.0, 10, 11.0, 11, 12.0, 12);
#endif

    return 0;
}
