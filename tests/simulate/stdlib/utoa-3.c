/* Copyright (c) 2012  Dmitry Xmelkov
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

/* Test of utoa() function with strtoul() usage.
   $Id$	*/

#include <stdlib.h>
#include <string.h>
#include "progmem.h"

#ifndef	__AVR__
# include <stdio.h>
# define PRINTFLN(line, fmt, ...)	\
    printf ("\n%s:%d: " fmt "\n", __FILE__, line, ##__VA_ARGS__);
# define EXIT(code)	exit ((code) < 255 ? (code) : 100 + (code) % 100)
#else
# define PRINTFLN(args...)
# define EXIT(code)	exit (code)
#endif

#ifndef	__AVR__
static char *utoa_recursive (unsigned val, char *s, unsigned radix)
{
    int c;

    if (val >= radix)
	s = utoa_recursive (val / radix, s, radix);
    c = val % radix;
    c += (c < 10 ? '0' : 'a' - 10);
    *s++ = c;
    return s;
}

static char *utoa (unsigned val, char *s, int radix)
{
    if (radix < 2 || radix > 36)
	s[0] = 0;
    else
	*utoa_recursive (val, s, radix) = 0;
    return s;
}
#endif

static void
Check (int line, unsigned val, int radix)
{
    char s[40], *p;
    unsigned long x;

    memset (s, 0xff, sizeof (s) - 1);
    s[sizeof (s) - 1] = 0;
    if (utoa (val, s, radix) != s) {
	PRINTFLN (line, "Incorrect result");
	EXIT (1000 + line);
    }

    x = strtoul (s, &p, radix);
    if (x != val) {
	PRINTFLN (line, "strtoul (utoa (%u,s,%d)) = %lu", val, radix, x);
	EXIT (line);
    }

    if (p != s + strlen (s)) {
	PRINTFLN (line, "Invalid character");
	EXIT (line);
    }
}

#define CHECK(val, base)	Check (__LINE__, val, base)


int main ()
{
    int i;
    int radix;

    for (radix = 2; radix <= 36; radix++) {
	int n;

	CHECK (0x5555, radix);
	CHECK (0xaaaa, radix);

	for (i = 0; i < 16; i++) {
	    CHECK (1 << i, radix);
	    CHECK (~0 << i, radix);
	}

	for (i = 0; i < 15; i++) {
	    CHECK (3 << i, radix);
	    CHECK (~3 << i, radix);
	}

	for (i = 0; i < 14; i++) {
	    CHECK (7 << i, radix);
	    CHECK (~7 << i, radix);
	}

	for (i = 0; i < 13; i++) {
	    CHECK (017 << i, radix);
	    CHECK (~017 << i, radix);
	}

	for (i = 0; i < 12; i++) {
	    CHECK (037 << i, radix);
	    CHECK (~037 << i, radix);
	}

	for (i = 0; i < 11; i++) {
	    CHECK (077 << i, radix);
	    CHECK (~077 << i, radix);
	}

	for (i = 0; i < 10; i++) {
	    CHECK (0177 << i, radix);
	    CHECK (~0177 << i, radix);
	}

	for (i = 0; i < 9; i++) {
	    CHECK (0377 << i, radix);
	    CHECK (~0377 << i, radix);
	}

	n = radix*radix;
	for (i = 5; i <= n; i++) {
	    CHECK (i, radix);
	    CHECK (-i, radix);
	}
    }

    return 0;
}
