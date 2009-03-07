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
# define strstr_P  strstr
#endif
#include <stdlib.h>
#include <string.h>
#include "progmem.h"

void Check (int line, const char *s1, const char *s2, int expect)
{
    char t1[200];
    char *p;

    if (strlen_P(s1) > sizeof(t1) - 1)
	exit (1);
    strcpy_P (t1, s1);
    p = strstr_P (t1, s2);
    if ((!p && expect == -1)  || (p == t1 + expect))
	return;
#if	!defined(__AVR__)
    printf ("\nLine %d: expect: %d, result: %d\n",
	    line, expect, (p ? p - t1 : -1));
    if (line > 255) line = 255;
#elif	defined(DEBUG)
    exit (p ? p - t1 : -1);
#endif
    exit (line);
}

#define CHECK(s1, s2, expect)	do {			\
    Check (__LINE__, PSTR(s1), PSTR(s2), expect);	\
} while (0)

int main ()
{
    /* Empty 'needle'.	*/
    CHECK ("", "", 0);
    CHECK ("12345", "", 0);

    /* bug #19135	*/
    CHECK ("ababac", "abac", 2);

    /* 'needle' of 1 byte long	*/
    CHECK ("", "a", -1);
    CHECK ("b", "a", -1);
    CHECK ("a", "a", 0);
    CHECK ("abcbef", "a", 0);
    CHECK (".a", "a", 1);
    CHECK (".a.", "a", 1);
    CHECK ("ABCDEFGH", "H", 7);
    
    /* 'needle' of 2 bytes long	*/
    CHECK ("", "12", -1);
    CHECK ("13", "12", -1);
    CHECK ("32", "12", -1);
    CHECK ("12", "12", 0);
    CHECK ("123", "12", 0);
    CHECK ("012", "12", 1);
    CHECK ("01200", "12", 1);
    
    /* partially mathing	*/
    CHECK ("a_ab_abc_abcd_abcde", "abcdef", -1);
    CHECK ("a_ab_abc_abcd_abcde_abcdef", "abcdef", 20);
    CHECK ("aababcabcdabcde", "abcdef", -1);
    CHECK ("aababcabcdabcdeabcdef", "abcdef", 15);
    
    /* repeated chars	*/
    CHECK ("abaabaaabaaaab", "aaaaab", -1);
    CHECK ("abaabaaabaaaabaaaaab", "aaaaab", 14);
    
    /* A first match is returned.	*/
    CHECK ("_foo_foo", "foo", 1);
    
    /* Case is importent.	*/
    CHECK ("A", "a", -1);

    return 0;
}
