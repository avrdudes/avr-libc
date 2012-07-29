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

/* Test of ultoa() function with strtoul() usage.
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
static char *ultoa_recursive (unsigned long val, char *s, unsigned radix)
{
    int c;

    if (val >= radix)
	s = ultoa_recursive (val / radix, s, radix);
    c = val % radix;
    c += (c < 10 ? '0' : 'a' - 10);
    *s++ = c;
    return s;
}

static char *ultoa (unsigned long val, char *s, int radix)
{
    if (radix < 2 || radix > 36)
	s[0] = 0;
    else
	*ultoa_recursive (val, s, radix) = 0;
    return s;
}
#endif

static void
Check (int line, unsigned long val, int radix)
{
    char s[40], *p;
    unsigned long x;

    memset (s, 0xff, sizeof (s) - 1);
    s[sizeof (s) - 1] = 0;
    if (ultoa (val, s, radix) != s) {
	PRINTFLN (line, "Incorrect result");
	EXIT (1000 + line);
    }

    x = strtoul (s, &p, radix);
    if (x != val) {
	PRINTFLN (line, "strtoul (ultoa (%lu,s,%d)) = %lu", val, radix, x);
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

	CHECK (0x55555555, radix);
	CHECK (0xaaaaaaaa, radix);

	for (i = 0; i < 32; i++) {
	    CHECK (1uL << i, radix);
	    CHECK (~0uL << i, radix);
	}

	for (i = 0; i < 31; i++) {
	    CHECK (3uL << i, radix);
	    CHECK (~3uL << i, radix);
	}

	for (i = 0; i < 30; i++) {
	    CHECK (7uL << i, radix);
	    CHECK (~7uL << i, radix);
	}

	for (i = 0; i < 29; i++) {
	    CHECK (017uL << i, radix);
	    CHECK (~017uL << i, radix);
	}

	for (i = 0; i < 28; i++) {
	    CHECK (037uL << i, radix);
	    CHECK (~037uL << i, radix);
	}

	for (i = 0; i < 27; i++) {
	    CHECK (077uL << i, radix);
	    CHECK (~077uL << i, radix);
	}

	for (i = 0; i < 26; i++) {
	    CHECK (0177uL << i, radix);
	    CHECK (~0177uL << i, radix);
	}

	for (i = 0; i < 25; i++) {
	    CHECK (0377uL << i, radix);
	    CHECK (~0377uL << i, radix);
	}

	n = radix*radix;
	for (i = 5; i <= n; i++) {
	    CHECK (i, radix);
	    CHECK (-i, radix);
	}
    }

    return 0;
}
