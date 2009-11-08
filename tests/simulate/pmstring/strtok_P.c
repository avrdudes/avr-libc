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

/* Test of strtok_P().
   $Id$	*/

#include <stdlib.h>
#include <string.h>
#include "progmem.h"

#ifndef	__AVR__
# include <stdio.h>
# define PRINTFLN(line, fmt, ...)	\
    printf ("\n%s:%d: " fmt "\n", __FILE__, line, ##__VA_ARGS__);
# define EXIT(code)	exit ((code) < 255 ? (code) : 100 + (code) % 100)
# define strtok_P(s,d)	strtok (s, d)
#else
# define PRINTFLN(args...)
# define EXIT(code)	exit (code)
#endif

static void
Check (int line, const char *s, const char *delim, int rslt, const char *token)
{
    static char ts[260];
    char *p;

    if (s) {
	if (strlen_P (s) >= sizeof (ts)) {
	    PRINTFLN (line, "Too small buffer");
	    EXIT (1000 + line);
	}
	strcpy_P (ts, s);
    }

    p = strtok_P (s ? ts : 0, delim);

    if (!p) {
	if (rslt >= 0) {
	    PRINTFLN (line, "Return 0, must: s+%d", rslt);
	    EXIT (2000 + line);
	}
    } else {
	if (rslt < 0) {
	    PRINTFLN (line, "Return nonzero pointer: s+%d", p - ts);
	    EXIT (3000 + line);
	}
	if ((p - ts) != rslt) {
	    PRINTFLN (line, "Return s+%d, must: s+%d",
		      p - ts, rslt);
	    EXIT (4000 + line);
	}
	if (strcmp_P (p, token)) {
	    PRINTFLN (line, "Return token \"%s\", must: \"%s\"", p, token);
	    EXIT (5000 + line);
	}
    }
}

/* Args:
     s     - string to parse (is saved in static buffer)
     delim - delimeter list
     rslt  - expected return value: (rslt >= 0 ? s+rslt : NULL)
     token - expected pointed string (if rslt >= 0)
 */
#define CHECK(s, delim, rslt, token)	\
    Check (__LINE__, PSTR (s), PSTR (delim), rslt, PSTR (token))

#define CHECK0(delim, rslt, token)	\
    Check (__LINE__, 0, PSTR (delim), rslt, PSTR (token))

int main ()
{
    /* Empty string.	*/

    CHECK ("", "", -1, "");

    CHECK ("", ".", -1, "");

    CHECK ("", "123", -1, "");

    /* Empty delimeter list.	*/

    CHECK ("A", "", 0, "A");
    CHECK0 ("", -1, "");

    CHECK ("12", "", 0, "12");
    CHECK0 ("", -1, "");

    CHECK ("dcba", "", 0, "dcba");
    CHECK0 ("", -1, "");

    /* No delimeter symbols are founded.	*/

    CHECK ("\t", " ", 0, "\t");
    CHECK0 (" ", -1, "");

    CHECK ("THE QUICK BROWN FOX", "thequickbrownfox", 0, "THE QUICK BROWN FOX");
    CHECK0 ("thequickbrownfox", -1, "");

    /* Delimeter list is 1 byte long.	*/

    CHECK ("1", ".", 0, "1");
    CHECK0 (".", -1, "");

    CHECK ("A,BC,DEF", ",", 0, "A");
    CHECK0 (",", 2, "BC");
    CHECK0 (",", 5, "DEF");
    CHECK0 (",", -1, "");

    /* Delimeter list is 2 bytes long.	*/

    CHECK ("AB", "ab", 0, "AB");
    CHECK0 ("ab", -1, "");

    CHECK ("123+45-6", "+-", 0, "123");
    CHECK0 ("+-", 4, "45");
    CHECK0 ("+-", 7, "6");
    CHECK0 ("+-", -1, "");

    /* Variable delimeter list.	*/

    CHECK ("A:B*C:D", ":", 0, "A");
    CHECK0 ("*", 2, "B");
    CHECK0 (":", 4, "C");
    CHECK0 ("", 6, "D");
    CHECK0 (":*", -1, "");

    /* Empty field.	*/

    CHECK (".", ".", -1, "");

    CHECK ("The quick", "kciuq ehT", -1, "");

    CHECK ("1,", ",", 0, "1");
    CHECK0 (",", -1, "");

    CHECK ("_2", "_", 1, "2");
    CHECK0 ("_", -1, "");

    CHECK ("A::B", ":", 0, "A");
    CHECK0 (":", 3, "B");
    CHECK0 (":", -1, "");

    CHECK ("  a\n\rb  ", "\r\n ", 2, "a");
    CHECK0 ("\r\n ", 5, "b");
    CHECK0 ("\r\n ", -1, "");

    /* String is approx. 256 bytes long.	*/

    CHECK ("................................................................"
	   "................................................................"
	   "................................................................"
	   "...............................................................5",
	   ".", 255, "5");

    CHECK ("................................................................"
	   "................................................................"
	   "................................................................"
	   "................................................................6",
	   ".", 256, "6");

    return 0;
}
