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

/* Test of sprintf(), specifications: none, c, s(S).
   $Id$	*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "progmem.h"

#ifndef __AVR__
# define sprintf_P	sprintf
#endif

void Check (int line,
            const char *expstr,
	    int retval, const char *retstr)
{
    int code;

    if (retval != (int)strlen (retstr))
	code = 1000 + line;
    else if (strcmp_P (retstr, expstr))
	code = line;
    else
	return;
#if	!defined(__AVR__)
    if (code) {
	printf ("\nLine %d: expect: %3d, \"%s\","
		"\n         output: %3d, \"%s\"\n",
		line, strlen (expstr), expstr, retval, retstr);
	code = (line < 256 ? line : 255);	/* common OS restriction */
    }
#elif	defined(DEBUG)
    exit ((int)retstr);
#endif
    exit (code);
}

/* 'vp' is used to avoid gcc warnings about format string.	*/
#define CHECK(expstr, fmt, ...)	do {				\
    char s[260];						\
    int i;							\
    int (* volatile vp)(char *, const char *, ...) = sprintf_P;	\
    memset (s, 0, sizeof(s));					\
    i = vp (s, PSTR(fmt), ##__VA_ARGS__);			\
    Check (__LINE__, PSTR(expstr), i, s);			\
} while (0)

int main ()
{
    CHECK ("", "");

    /* Without format specifications	*/
    CHECK (" ", " ");
    CHECK ("\001", "\001");
    CHECK ("\a\b\t\n\v\f\r ! 09 AZ az \177\200\201 \377",
	   "\a\b\t\n\v\f\r ! 09 AZ az \177\200\201 \377");
    CHECK ("%", "%%");
    CHECK ("%% ", "%%%% ");

    /* '%c' specification	*/
    CHECK ("a", "%c", 'a');
    CHECK ("\001\177\200\201\377", "%c%c%c%c%c", 001,0177,0200,0201,0377);
    CHECK ("A B C D E", "%0c %+c %-c % c %#c", 'A','B','C','D','E');
    CHECK ("A B C D", "%.c %.0c %.1c %.99c", 'A','B','C','D');
    CHECK ("A. B.    C.         D", "%1c.%2c.%5c.%10.2c", 'A','B','C','D','E');
    CHECK ("A.B .C         ", "%-1c.%-2c.%-10c", 'A','B','C');
    CHECK ("                                                                "
	   "                                                                "
	   "                                                                "
	   "                                                              F",
	   "%255c", 'F');
    CHECK ("G                                                               "
	   "                                                                "
	   "                                                                "
	   "                                                               ",
	   "%-255c", 'G');
	   

    /* '%s' specification	*/
    CHECK ("", "%s", "");
    CHECK ("A", "%s", "A");
    CHECK ("123456789\001\177\200\201\377", "%s",
           "123456789\001\177\200\201\377");
    CHECK ("A B C D E", "%0s %+s %-s % s %#s", "A","B","C","D","E");
    CHECK ("A. B.    C.         D", "%1s.%2s.%5s.%10.2s", "A","B","C","D");
    CHECK (".a.0123456789", "%.0s.%.1s.%.10s", "ABCDEF","abcdef","0123456789");

#ifdef	__AVR__
    /* '%S' specification	*/
    CHECK ("", "%S", PSTR(""));
    CHECK ("A", "%S", PSTR("A"));
    CHECK ("123456789\001\177\200\201\377", "%S",
           PSTR("123456789\001\177\200\201\377"));
    CHECK ("A B C D E", "%0S %+S %-S % S %#S",
	   PSTR("A"), PSTR("B"), PSTR("C"), PSTR("D"), PSTR("E"));
    CHECK ("A. B.    C.         D", "%1S.%2S.%5S.%10.2S",
	   PSTR("A"), PSTR("B"), PSTR("C"), PSTR("D"));
    CHECK (".a.0123456789", "%.0S.%.1S.%.10S",
	   PSTR("ABCDEF"), PSTR("abcdef"), PSTR("0123456789"));
#endif

    return 0;
}
