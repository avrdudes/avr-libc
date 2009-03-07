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
# define _GNU_SOURCE	/* to include memrchr()	*/
# define PRINTFLN(line, fmt, ...)	\
    printf("\nLine %d: " fmt "\n", line, ##__VA_ARGS__)
# define EXIT(code)	exit ((code) < 255 ? (code) : 255)
# define memrchr_P	memrchr
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

#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "progmem.h"

void Check (int line, const char *s, int c, size_t len, int expect)
{
    const char *p;
    
    p = memrchr_P (s, c, len);

    if (expect < 0) {
	if (p) {
	    PRINTFLN (line, "non zero pointer is returned");
	    EXIT (line);
	}
    } else {
	if (p != s + expect) {
	    PRINTFLN (line, "expect= %d  result= %d", expect, p - s);
	    EXIT (line + 1000);
	}
    }
}

#define CHECK(s, c, len, expect)	do {	\
    Check (__LINE__, PSTR(s), c, len, expect);	\
} while (0)

int main ()
{
    /* Not found	*/
    CHECK ("", 0, 0, -1);
    CHECK ("", 255, 0, -1);
    CHECK ("ABCDEF", 'a', 6, -1);
    
    /* Found	*/
    CHECK ("\000", 0, 1, 0);
    CHECK ("\001", 1, 1, 0);
    CHECK ("\377", 255, 1, 0);
    CHECK ("987654321", '7', 9, 2);

    /* '\0' has't a special sense	*/
    CHECK ("12345", 0, 6, 5);
    CHECK (".\000.", 0, 3, 1);
    CHECK ("\000a\000b", 'b', 4, 3);

    /* Last occurance	*/
    CHECK ("abcdabcd", 'b', 8, 5);
    CHECK ("........", '.', 8, 7);
    
    /* 'c' converted to a char	*/
    CHECK ("ABCDEF", 'A'+0x100, 6, 0);
    CHECK ("ABCDE\377", ~0, 6, 5);
    
    /* Very long string	*/
    CHECK ("................................................................"
	   "................................................................"
	   "................................................................"
	   "...............................................................*"
	   "................................................................",
	   '*', 320, 255);
    CHECK ("................................................................"
	   "................................................................"
	   "................................................................"
	   "................................................................"
	   "*...............................................................",
	   '*', 320, 256);
    CHECK ("................................................................"
	   "................................................................"
	   "................................................................"
	   "................................................................"
	   ".*..............................................................",
	   '*', 320, 257);

    return 0;
}
