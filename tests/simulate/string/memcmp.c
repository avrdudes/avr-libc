/* Copyright (c) 2007  Dmitry Xmelkov
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

/* $Id$	*/

#ifndef __AVR__
# include <stdio.h>
#endif
#include <stdlib.h>
#include <string.h>
#include "progmem.h"

void Check (int line, const char *s1, const char *s2, size_t len, int expect)
{
    char t1[200];
    char t2[200];
    int i;
    if (len > sizeof(t1) || len > sizeof(t2))
	exit (1);
    memcpy_P (t1, s1, len ? len : 1);
    memcpy_P (t2, s2, len ? len : 1);
    i = memcmp (t1, t2, len);
    if (i == expect)
	return;
#if	!defined(__AVR__)
    /* Glibc memcmp() returns: -1/0/+1.	*/
    if (   (i < 0 && expect < 0)
	|| (i > 0 && expect > 0)
	|| (i == 0 && expect == 0) )
      return;
    printf ("\nLine %d: expect: %d, result: %d\n",
	    line, expect, i);
    if (line > 255) line = 255;
#elif	defined(DEBUG)
    exit (i);
#endif
    exit (line);
}

#define CHECK(s1, s2, len, expect)	do {		\
    Check (__LINE__, PSTR(s1), PSTR(s2), len, expect);	\
} while (0)

int main ()
{
    /* len == 0	*/
    CHECK ("", "", 0, 0);
    CHECK ("A", "A", 0, 0);
    CHECK ("B", "C", 0, 0);

    /* len == 1	*/
    CHECK ("\000", "\001", 1, -1);
    CHECK ("\000", "\377", 1, -255);
    CHECK ("\001", "\000", 1, 1);
    CHECK ("\377", "\000", 1, 255);

    /* Agrs are equal.	*/
    CHECK ("\001", "\001", 1, 0);
    CHECK ("\001", "\001", 2, 0);
    CHECK ("1234\377", "1234\377", 1, 0);
    CHECK ("1234\377+", "1234\377-", 5, 0);

    /* Args are not equal.	*/
    CHECK ("ABCDEF", "ABCDE\000", 6, 'F');
    CHECK ("abcde\000", "abcdef", 6, -'f');
    CHECK ("12345", "12245", 5, 1);

    /* Case is important.	*/
    CHECK ("xyz", "xYz", 3, 'y'-'Y');
    CHECK ("QUICK", "qUICK", 5, 'Q'-'q');

    /* Chars are unsigned	*/
    CHECK ("\200", "\177", 1, 1);
    CHECK ("\177", "\200", 1, -1);
    CHECK ("\001", "\377", 1, -254);
    CHECK ("\377", "\001", 1, 254);

    /* '\0' is possible in the middle of array	*/
    CHECK ("\000ABC\000D", "\000ABC\000C", 5, 0);
    CHECK ("\000ABC\000D", "\000ABC\000C", 6, 1);

    return 0;
}
