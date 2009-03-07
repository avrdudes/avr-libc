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

#ifndef	__AVR__		/* strrev() is't a standart function	*/
char * strrev (char *s)
{
    char *p1, *p2;
    
    for (p2 = s; *p2; ) p2++;
    p1 = s;
    while (p1 < p2) {
	char c1 = *p1;
	char c2 = *--p2;
	*p1++ = c2;
	*p2 = c1;
    }
    return s;
}
#endif

void Check (int line, const char *s, const char *expect)
{
    char t[300];
    char *p;
    int code = 0;
    int i;

    for (i = 2; i; i--) {
	if (strlen_P(s) > sizeof(t) - 1)
	    exit (1);
        strcpy_P (t, s);
	p = strrev (t);
        if (p != t) {
	    code = line + 1000;
	    break;
	}
        if (strcmp_P (t, expect)) {
	    code = line;
	    break;
	}
	p = (char *)s;		/* change strings	*/
	s = expect;
	expect = p;
    }
    if (!code)
	return;
#if   !defined(__AVR__)
    printf ("\nLine %d: expect: \"%s\""
	    "\n         result: \"%s\"\n",
	    line, expect, t);
    if (code > 255) code = 255;
#elif	defined(DEBUG)
    exit ((int)t);
#endif
    exit (code);
}

#define CHECK(s, expect)	do {		\
    Check (__LINE__, PSTR(s), PSTR(expect));	\
} while (0)

int main ()
{
    /* Empty string.	*/
    CHECK ("", "");
    
    /* 1 char long	*/
    CHECK ("a", "a");
    CHECK ("\001", "\001");
    CHECK ("\377", "\377");
    
    /* 2 chars long	*/
    CHECK ("01", "10");
    CHECK ("**", "**");
    
    /* 3 and more chars long	*/
    CHECK ("abc", "cba");
    CHECK ("qwer", "rewq");
    CHECK ("12345", "54321");
    CHECK ("[];'./", "/.';][");
    CHECK ("\001\177\200\201\377", "\377\201\200\177\001");
    CHECK ("The quick brown fox jumps over the lazy dog.",
	   ".god yzal eht revo spmuj xof nworb kciuq ehT");

    /* Very long string.	*/
    CHECK ("1..............................................................2"
	   "3..............................................................4"
	   "5..............................................................6"
	   "7..............................................................",
	   "..............................................................7"
	   "6..............................................................5"
	   "4..............................................................3"
	   "2..............................................................1");

    CHECK ("1..............................................................2"
	   "3..............................................................4"
	   "5..............................................................6"
	   "7..............................................................8",
	   "8..............................................................7"
	   "6..............................................................5"
	   "4..............................................................3"
	   "2..............................................................1");

    CHECK ("1..............................................................2"
	   "3..............................................................4"
	   "5..............................................................6"
	   "7..............................................................89",
	   "98..............................................................7"
	   "6..............................................................5"
	   "4..............................................................3"
	   "2..............................................................1");
    
    return 0;
}
