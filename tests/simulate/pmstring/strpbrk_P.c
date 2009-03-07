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
# define strpbrk_P  strpbrk
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
    p = strpbrk_P (t1, s2);
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
    /* Empty string.	*/
    CHECK ("", "", -1);
    CHECK ("A", "", -1);
    CHECK ("", "A", -1);

    /* accept[] length is 1.	*/
    CHECK ("A", "A", 0);
    CHECK (".B.", "B", 1);
    CHECK ("........C", "C", 8);
    CHECK ("a", "A", -1);
    CHECK ("AA", "a", -1);

    /* accept[] length is 2.	*/
    CHECK ("a.", "ab", 0);
    CHECK (".a", "ab", 1);
    CHECK ("b.", "ab", 0);
    CHECK (".b", "ab", 1);
    CHECK ("c", "ab", -1);
    CHECK ("0123456789", "56", 5);
    CHECK ("0123456789", "-+", -1);
    
    /* Long strings.	*/
    CHECK ("qwertyuiopasdfghjklzxcvbnm", "MNBVCXZLKJHGFDSAPOIUYTREWQ", -1);
    CHECK ("qwertyuiopasdfghjklzxcvbnm", "MNBVCXZLKJHGFDSAPOIUYTREWQm", 25);

    /* non ASCII chars	*/
    CHECK ("\001", "\001", 0);
    CHECK ("\377", "\377", 0);
    CHECK ("\002\376", "\001\377", -1);

    return 0;
}
