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

/* Test of ultoa() with patterns.
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
Check (int line, unsigned long val, const char *rslt, int radix)
{
    char s[40];

#ifndef	__AVR__
    if (radix >= 2 && radix <= 36) {
	unsigned long x = strtoul (rslt, 0, radix);
	if (x != val) {
	    PRINTFLN (line, "strtoul(\"%s\",,%d)= %lu,  val= %lu",
		      rslt, radix, x, val);
	    EXIT (2000 + line);
	}
    }
#endif

    memset (s, 0xff, sizeof (s) - 1);
    s[sizeof (s) - 1] = 0;
    if (ultoa (val, s, radix) != s) {
	PRINTFLN (line, "Incorrect result");
	EXIT (1000 + line);
    }

    if (strcmp_P (s, rslt)) {
	PRINTFLN (line, "ultoa(%lu,,%d) puts: %s, must: %s",
		  val, radix, s, rslt);
	EXIT (line);
    }
}

#define CHECK(val, rslt, base)	\
    Check (__LINE__, val, PSTR (rslt), base)


int main ()
{
    int i;

    /* Invalid radix.	*/
    CHECK (0, "", 0);
    CHECK (0, "", 1);
    CHECK (0, "", 37);
    CHECK (10, "", 0x0102);
    CHECK (256, "", 0x8008);

    /* Radix-independent results.	*/
    for (i = 2; i <= 36; i++) {
	unsigned long x;

	CHECK (0, "0", i);
	CHECK (1, "1", i);

	CHECK (i, "10", i);
	CHECK (i + 1, "11", i);

	x = i * i;
	CHECK (x, "100", i);
	CHECK (x + 1, "101", i);
	CHECK (x + i, "110", i);
	CHECK (x + i + 1, "111", i);

	x *= i;
	CHECK (x, "1000", i);
	x *= i;
	CHECK (x, "10000", i);
	x *= i;
	CHECK (x, "100000", i);
    }

    CHECK (0xfe, "11111110", 2);
    CHECK (0xfe, "254", 10);
    CHECK (0xfe, "211", 11);
    CHECK (0xfe, "72", 36);

    CHECK (0xff, "11111111", 2);
    CHECK (0xff, "255", 10);
    CHECK (0xff, "212", 11);
    CHECK (0xff, "73", 36);

    CHECK (0x100, "100000000", 2);
    CHECK (0x100, "256", 10);
    CHECK (0x100, "213", 11);
    CHECK (0x100, "74", 36);

    CHECK (0x101, "100000001", 2);
    CHECK (0x101, "257", 10);
    CHECK (0x101, "214", 11);
    CHECK (0x101, "75", 36);

    CHECK (0xfffe, "1111111111111110", 2);
    CHECK (0xfffe, "65534", 10);
    CHECK (0xfffe, "45267", 11);
    CHECK (0xfffe, "1eke", 36);

    CHECK (0xffff, "1111111111111111", 2);
    CHECK (0xffff, "65535", 10);
    CHECK (0xffff, "45268", 11);
    CHECK (0xffff, "1ekf", 36);

    CHECK (0x10000, "10000000000000000", 2);
    CHECK (0x10000, "65536", 10);
    CHECK (0x10000, "45269", 11);
    CHECK (0x10000, "1ekg", 36);

    CHECK (0x10001, "10000000000000001", 2);
    CHECK (0x10001, "65537", 10);
    CHECK (0x10001, "4526a", 11);
    CHECK (0x10001, "1ekh", 36);

    CHECK (0xfffffe, "111111111111111111111110", 2);
    CHECK (0xfffffe, "16777214", 10);
    CHECK (0xfffffe, "9519a73", 11);
    CHECK (0xfffffe, "9zldq", 36);

    CHECK (0xffffff, "111111111111111111111111", 2);
    CHECK (0xffffff, "16777215", 10);
    CHECK (0xffffff, "9519a74", 11);
    CHECK (0xffffff, "9zldr", 36);

    CHECK (0x1000000, "1000000000000000000000000", 2);
    CHECK (0x1000000, "16777216", 10);
    CHECK (0x1000000, "9519a75", 11);
    CHECK (0x1000000, "9zlds", 36);

    CHECK (0x1000001, "1000000000000000000000001", 2);
    CHECK (0x1000001, "16777217", 10);
    CHECK (0x1000001, "9519a76", 11);
    CHECK (0x1000001, "9zldt", 36);

    CHECK (0xfffffffe, "11111111111111111111111111111110", 2);
    CHECK (0xfffffffe, "37777777776", 8);
    CHECK (0xfffffffe, "4294967294", 10);
    CHECK (0xfffffffe, "1904440552", 11);
    CHECK (0xfffffffe, "fffffffe", 16);
    CHECK (0xfffffffe, "1z141z2", 36);

    CHECK (0xffffffff, "11111111111111111111111111111111", 2);
    CHECK (0xffffffff, "37777777777", 8);
    CHECK (0xffffffff, "4294967295", 10);
    CHECK (0xffffffff, "1904440553", 11);
    CHECK (0xffffffff, "ffffffff", 16);
    CHECK (0xffffffff, "1z141z3", 36);

    CHECK (10, "a", 11);
    CHECK (35, "z", 36);

    CHECK (01234567, "1234567", 8);
    CHECK (07654321, "7654321", 8);
    CHECK (123456789, "123456789", 10);
    CHECK (987654321, "987654321", 10);
    CHECK (0x89ABCDEF, "89abcdef", 16);
    CHECK (0xFEDCBA98, "fedcba98", 16);

    return 0;
}
