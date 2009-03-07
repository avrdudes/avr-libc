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

/* $Id$	*/

#ifndef __AVR__
# define _GNU_SOURCE		/* to include strcasestr()	*/
# define PRINTFLN(line, fmt, ...)	\
    printf("\nLine %d: " fmt "\n", line, ##__VA_ARGS__)
# define EXIT(code)	exit ((code) < 255 ? (code) : 255)
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

#include <ctype.h>
#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "progmem.h"

void Check (int line, const char *s1, const char *s2, int expect)
{
    char t1[300];
    char t2[100];
    char *p;

    if ((strlen_P(s1) > sizeof(t1) - 1) || (strlen_P(s2) > sizeof(t2) - 1))
	exit (1);
    strcpy_P (t1, s1);
    strcpy_P (t2, s2);
    p = strcasestr (t1, t2);

    if (expect < 0) {
	if (p) {
	    PRINTFLN (line, "return nonzero");
	    EXIT (line);
	}
    } else {
	if (p != t1 + expect) {
	    PRINTFLN (line, "expect= %d  result= %d", expect, p - t1);
	    EXIT (1000 + line);
	}
    }
    if (strcmp_P (t1, s1) || strcmp_P (t2, s2)) {
	PRINTFLN (line, "string(s) is changed");
	EXIT (2000 + line);
    }
}

#define CHECK(s1, s2, expect)	do {			\
    Check (__LINE__, PSTR(s1), PSTR(s2), expect);	\
} while (0)

int main ()
{
    int c1, c2;
    char s1[4];
    char s2[4];

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
    
    /* Case is ignored.	*/
    CHECK ("A", "a", 0);
    CHECK ("qwertyuiopasdfghjklzxcvbnm",
	   "QWERTYUIOPASDFGHJKLZXCVBNM",
	   0);
    CHECK (" QWERTYUIOPASDFGHJKLZXCVBNM",
	   "qwertyuiopasdfghjklzxcvbnm",
	   1);
    CHECK ("  The Quick Brown Fox ", "thE quicK browN foX", 2);

    /* Case is ignored for alphas only.	*/
    CHECK ("", "\040", -1);
    CHECK ("\100", "\140", -1);		/* first	*/
    CHECK ("\140", "\100", -1);
    CHECK ("\133", "\173", -1);
    CHECK ("\173", "\133", -1);
    CHECK (".\100", ".\140", -1);	/* second	*/
    CHECK (".\140", ".\100", -1);
    CHECK (".\133", ".\173", -1);
    CHECK (".\173", ".\133", -1);
    CHECK ("\100\140", "\140", 1);	/* second match	*/
    
    /* Very long s1	*/
    CHECK ("................................................................"
	   "................................................................"
	   "................................................................"
	   "...............................................................A",
	   "a", 255);
    CHECK ("................................................................"
	   "................................................................"
	   "................................................................"
	   "................................................................"
	   "a", "A", 256);
    CHECK ("................................................................"
	   "................................................................"
	   "................................................................"
	   "................................................................"
	   ".a", "A", 257);
    CHECK ("................................................................"
	   "................................................................"
	   "................................................................"
	   "................................................................"
	   ".a", "..A", 255);

    /* Let us check a set of possible combinations of 2 symbols.	*/
    for (c1 = 1; c1 < 256; c1++) {
	for (c2 = 1; c2 < 256; c2++) {
	    if (c1 == c2
		|| (isalpha(c1) && isalpha(c2) && ((c1 ^ c2) == ('A' ^ 'a'))))
	    {

		/* first char: ("c","c")	*/
		s1[0] = c1;  s1[1] = 0;
		s2[0] = c2;  s2[1] = 0;
		if (strcasestr (s1, s2) != s1)
		    EXIT (__LINE__);

		/* second char: (".c", ".c")	*/
		s1[0] = '.';  s1[1] = c1;  s1[2] = 0;
		s2[0] = '.';  s2[1] = c2;  s2[2] = 0;
		if (strcasestr (s1, s2) != s1)
		    EXIT (__LINE__);

		/* substring is shifted: ("..c", ".c")	*/
		s1[0] = '.';  s1[1] = '.';  s1[2] = c1;  s1[3] = 0;
		s2[0] = '.';  s2[1] = c2;  s2[2] = 0;
		if (strcasestr (s1, s2) != s1 + (c2 != '.'))
		    EXIT (__LINE__);

	    } else {

		/* first char: ("c","c")	*/
		s1[0] = c1;  s1[1] = 0;
		s2[0] = c2;  s2[1] = 0;
		if (strcasestr (s1, s2) != 0)
#ifdef	DEBUG
		    EXIT (c1 | c2<<8);
#else
		    EXIT (__LINE__);
#endif

		/* second char: (".c", ".c")	*/
		s1[0] = '.';  s1[1] = c1;  s1[2] = 0;
		s2[0] = '.';  s2[1] = c2;  s2[2] = 0;
		if (strcasestr (s1, s2) != 0)
		    EXIT (__LINE__);
	    }
	}
    }

    return 0;
}
