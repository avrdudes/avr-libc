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

#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "progmem.h"

#ifndef __AVR__
# define PRINTFLN(line, fmt, ...)	\
    printf("\nLine %d: " fmt "\n", line, ##__VA_ARGS__)
# define EXIT(code)	exit ((code) < 255 ? (code) : 255)
# define memcmp_P	memcmp
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

void Check (int line, const char *s1, const char *s2, int clr, int pnt)
{
    char t1[300];
    char t2[100];
    char *sp;
    char *rp;

    if ((strlen_P(s1) > sizeof(t1) - 1) || (strlen_P(s2) > sizeof(t2) - 1))
	exit (1);
    strcpy_P (t1, s1);
    strcpy_P (t2, s2);
    sp = t1;
    rp = strsep (&sp, t2);

    if (rp != t1) {
	PRINTFLN (line, "false return value");
	EXIT (5000 + line);
    }
    if (clr < 0) {
	if (strcmp_P (t1, s1)) {
	    PRINTFLN (line, "string is changed");
	    EXIT (line);
	}
    } else {
	if (strlen (t1) != (size_t)clr) {
	    PRINTFLN (line, "strlen: expect= %d  result= %d",
			 clr, strlen (t1));
	    EXIT (1000 + line);
	}
	if (memcmp_P (t1, s1, clr)
	    || t1[clr]
	    || strcmp_P (t1 + clr + 1, s1 + clr + 1))
	{
	    PRINTFLN (line, "string mismatch");
	    EXIT (2000 + line);
	}
    }
    if (pnt < 0) {
	if (sp) {
	    PRINTFLN (line, "sp is not a NULL");
	    EXIT (3000 + line);
	}
    } else {
	if (sp != t1 + pnt) {
	    PRINTFLN (line, "sp: expect= %d  result= %d",
			 pnt, sp - t1);
	    EXIT (4000 + line);
	}
    }
}

/* Args:
     s - string to parse
     delim - delimeter list
     clr   - if (clr >= 0) s[cln] must be cleared
     pnt   - if (pnt >= 0) s[pnt] must be pointed, else NULL
 */
#define CHECK(s, delim, clr, pnt)	do {		\
    Check (__LINE__, PSTR(s), PSTR(delim), clr, pnt);	\
} while (0)

int main ()
{
    char *p;
    
    /* NULL at first call	*/
    p = 0;
    if (strsep (&p, "") || p) exit (__LINE__);
    if (strsep (&p, "abc") || p) exit (__LINE__);

    /* Empty string	*/
    CHECK ("", "", -1, -1);
    CHECK ("", "abc", -1, -1);
    
    /* Empty delimeter list	*/
    CHECK ("a", "", -1, -1);
    CHECK ("12345678", "", -1, -1);
    
    /* No delimeter symbols are founded	*/
    CHECK ("\tabc", " ", -1, -1);
    CHECK ("THE QUICK BROWN FOX", "thequickbrownfox", -1, -1);
    
    /* delim is 1 byte long	*/
    CHECK (".", ".", 0, 1);
    CHECK ("abc", "a", 0, 1);
    CHECK ("abc", "b", 1, 2);
    CHECK ("abc", "c", 2, 3);

    /* delim is 2 bytes long	*/
    CHECK ("0", "01", 0, 1);
    CHECK ("1", "01", 0, 1);
    CHECK ("A.", "AB", 0, 1);
    CHECK ("B.", "AB", 0, 1);
    CHECK ("CAD", "AB", 1, 2);
    CHECK ("CDB", "AB", 2, 3);
    
    /* delim length > 2 bytes	*/
    CHECK ("the quick", "0123456789 ", 3, 4);

    /* Very long string	*/
    CHECK ("................................................................"
	   "................................................................"
	   "................................................................"
	   "...............................................................*",
	   "*", 255, 256);
    CHECK ("................................................................"
	   "................................................................"
	   "................................................................"
	   "................................................................"
	   "*", "*", 256, 257);

    /* Non ASCII bytes	*/
    CHECK ("\001\002\377", "\001", 0, 1);
    CHECK ("\001\002\377", "\377", 2, 3);
}
