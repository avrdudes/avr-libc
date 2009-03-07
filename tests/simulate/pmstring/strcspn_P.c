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
# define strcspn_P  strcspn
#endif
#include <stdlib.h>
#include <string.h>
#include "progmem.h"

void Check (int line, const char *s1, const char *s2, size_t expect)
{
    char t1[300];
    size_t n;

    if (strlen_P(s1) > sizeof(t1) - 1)
	exit (1);
    strcpy_P (t1, s1);
    n = strcspn_P (t1, s2);
    if (n == expect)
	return;
#if   !defined(__AVR__)
    printf ("\nLine %d: expect: %d, result: %d\n",
	    line, expect, n);
    if (line > 255) line = 255;
#elif	defined(DEBUG)
    exit (n ? n : ~0);
#endif
    exit (line);
}

#define CHECK(s1, s2, expect)	do {			\
    Check (__LINE__, PSTR(s1), PSTR(s2), expect);	\
} while (0)

int main ()
{
    /* Empty string.	*/
    CHECK ("", "", 0);
    CHECK ("", "A", 0);
    CHECK ("", "abcdef", 0);
    CHECK ("A", "", 1);
    CHECK ("0123456789", "", 10);

    /* accept[] length is 1.	*/
    CHECK ("B", "A", 1);
    CHECK ("abcdefghij", "A", 10);
    CHECK ("A", "A", 0);
    CHECK ("AAAAAAAA", "A", 0);

    /* accept[] length is 2.	*/
    CHECK ("c", "ab", 1);
    CHECK ("cd", "ab", 2);
    CHECK ("cde", "ab", 3);
    CHECK ("a", "ab", 0);
    CHECK (".a", "ab", 1);
    CHECK ("..a", "ab", 2);
    CHECK ("...a", "ab", 3);
    CHECK ("b", "ab", 0);
    CHECK (".b", "ab", 1);
    CHECK ("..b", "ab", 2);
    CHECK ("...b", "ab", 3);
    CHECK ("0101010101", "23", 10);
    CHECK ("0123456789AB", ".A", 10);
    
    /* accept[] length > 2	*/
    CHECK ("the quick brown fox", "QWERTYUIOPASDFGHJKLZXCVBNM", 19);
    CHECK ("the quick brown fox ...", ".QWERTYUIOPASDFGHJKLZXCVBNM", 20);
    CHECK ("the quick brown fox .?", "QWERTYUIOPASDFGHJKLZXCVBNM?", 21);
    
    /* non ASCII chars	*/
    CHECK ("\001", "\001", 0);
    CHECK ("\377", "\377", 0);
    CHECK ("\002\376", "\001\377", 2);

    /* Result approx. 256	*/
    CHECK ("................................................................"
	   "................................................................"
	   "................................................................"
	   "...............................................................",
	   "*", 255);
    CHECK ("................................................................"
	   "................................................................"
	   "................................................................"
	   "................................................................",
	   "*", 256);
    CHECK ("................................................................"
	   "................................................................"
	   "................................................................"
	   "................................................................"
	   ".*", "*", 257);

    return 0;
}
