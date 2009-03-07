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
# include <ctype.h>
# include <stdio.h>
#endif
#include <stdlib.h>
#include <string.h>
#include "progmem.h"

#ifndef	__AVR__			/* strlwr() is't a standart function	*/
char * strlwr (char *s)
{
    char *p = s;
    while (*p) {
	*p = tolower(*p);
	p++;
    }
    return s;
}
#endif

void Check (int line, const char *s, const char *expect)
{
    char t[200];
    char *p;
    int code;

    if (strlen_P(s) > sizeof(t) - 1)
	exit (1);
    strcpy_P (t, s);
    p = strlwr (t);
    if (p != t)
	code = line + 1000;
    else if (strcmp_P (t, expect))
	code = line;
    else
	return;
#if	!defined(__AVR__)
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
    
    CHECK ("A", "a");
    CHECK ("Z", "z");
    CHECK ("@[", "@[");		/* '@'=='A'-1, '['=='Z'+1	*/
    CHECK ("`az{", "`az{");	/* '`'=='a'-1, '{'=='z'+1	*/

    CHECK ("QWERTYUIOPASDFGHJKLZXCVBNM", "qwertyuiopasdfghjklzxcvbnm");
    CHECK ("FoO", "foo");
    
    /* non-ASCII	*/
    CHECK ("\001A\177\200\201B\377", "\001a\177\200\201b\377");

    return 0;
}
