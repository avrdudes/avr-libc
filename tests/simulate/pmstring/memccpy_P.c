/* Copyright (c) 2009  Dmitry Xmelkov
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

/* Test of memccpy_P().
   $Id$	*/

#include <stdlib.h>
#include <string.h>
#include "progmem.h"

#ifndef	__AVR__
# include <stdio.h>
# define PRINTFLN(line, fmt, ...)	\
    printf ("\n%s:%d: " fmt "\n", __FILE__, line, ##__VA_ARGS__);
# define EXIT(code)	exit ((code) < 255 ? (code) : 100 + (code) % 100)
# define memccpy_P	memccpy
# define memcmp_P	memcmp
#else
# define PRINTFLN(args...)
# define EXIT(code)	exit (code)
#endif

/* The expected return value must be (dst + expret) in case of expret >= 0,
   or NULL in case of expret == -1.
 */
static void
Check (int line,
       const void *src , int val, size_t len,		/* memccpy_P() args */
       int expret,					/* expecter return */
       const void *expdst, size_t explen)		/* expected result */
{
    char tdst[len];
    char *p;

    p = memccpy_P (tdst, src, val, len);

    if (expret == -1) {
	if (p) {
	    PRINTFLN (line, "nonzero result, must NULL");
	    EXIT (1000 + line);
	}
    } else {
	if (!p) {
	    PRINTFLN (line, "result is NULL, must dst+%d", expret);
	    EXIT (2000 + line);
	}
	if (p != tdst + expret) {
	    PRINTFLN (line, "result: dst+%d, must: dst+%d", p - tdst, expret);
	    EXIT (3000 + line);
	}
    }
    if (explen) {
	if (memcmp_P (tdst, expdst, explen)) {
	    PRINTFLN (line, "result string is wrong");
	    EXIT (4000 + line);
	}
    }
}

#define CHECK(src, val, len, expret, expdst, explen)	\
    Check (__LINE__, PSTR (src), val, len, expret, PSTR (expdst), explen)

int main ()
{
    /* Empty input.	*/
    CHECK ("", 0, 0,	-1, "", 0);
    CHECK ("", 255, 0,	-1, "", 0);

    /* 1 byte src.	*/
    CHECK ("A", 'A', 1,   1, "A", 1);
    CHECK ("A", 'a', 1,  -1, "A", 1);
    CHECK ("A", 0, 1,    -1, "A", 1);
    CHECK ("A", 255, 1,  -1, "A", 1);

    CHECK ("\000", 0, 1,    1, "\000", 1);
    CHECK ("\000", 1, 1,   -1, "\000", 1);
    CHECK ("\000", 255, 1, -1, "\000", 1);

    CHECK ("\377", 255, 1,   1, "\377", 1);
    CHECK ("\377", 0, 1,    -1, "\377", 1);
    CHECK ("\377", 'B', 1,  -1, "\377", 1);

    /* 2 bytes src, first byte is match.	*/
    CHECK ("CD", 'C', 2,    1, "C", 1);
    CHECK ("\000E", 0, 2,   1, "\000", 1);
    CHECK ("\377F", 255, 2, 1, "\377", 1);

    /* 2 bytes src, second byte is match.	*/
    CHECK ("GH", 'H', 2,        2, "GH", 2);
    CHECK ("\000\377", 255, 2,  2, "\000\377", 2);
    CHECK ("\377\000", 0, 2,    2, "\377\000", 2);

    /* 2 bytes src, no matches.	*/
    CHECK ("IJ", 'K', 2,      -1, "IJ", 2);
    CHECK ("\000\001", 2, 2,  -1, "\000\001", 2);

    /* Long string.	*/
    CHECK ("The quick brown fox", 'k', 19,  9, "The quick", 9);
    CHECK ("The quick brown fox", 'j', 19, -1, "The quick brown fox", 19);

    /* src is 255 bytes long.	*/
    CHECK ("................................................................"
	   "................................................................"
	   "................................................................"
	   "..............................................................5",
	   '5', 255, 255,
	   "................................................................"
	   "................................................................"
	   "................................................................"
	   "..............................................................5",
	   255);

    /* src is 256 bytes long.	*/
    CHECK ("................................................................"
	   "................................................................"
	   "................................................................"
	   "...............................................................6",
	   '6', 256, 256,
	   "................................................................"
	   "................................................................"
	   "................................................................"
	   "...............................................................6",
	   256);

    /* src is 255 bytes long.	*/
    CHECK ("................................................................"
	   "................................................................"
	   "................................................................"
	   "................................................................7",
	   '7', 257, 257,
	   "................................................................"
	   "................................................................"
	   "................................................................"
	   "................................................................7",
	   257);
}
