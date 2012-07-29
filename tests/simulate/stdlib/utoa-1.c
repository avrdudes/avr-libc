/* Copyright (c) 2012  Dmitry Xmelkov
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

/* Test of utoa() with all possible inline variants.
   $Id$	*/

#include <stdlib.h>
#include <string.h>
#include "progmem.h"

#ifndef	__AVR__
# include <stdio.h>
# define PRINTFLN(line, fmt, ...)	\
    printf ("\n%s:%d: " fmt "\n", __FILE__, line, ##__VA_ARGS__);
# define EXIT(code)	exit ((code) < 255 ? (code) : 100 + (code) % 100)
#else
# define PRINTFLN(args...)
# define EXIT(code)	exit (code)
#endif

#ifndef	__AVR__
static char *utoa_recursive (unsigned val, char *s, unsigned radix)
{
    int c;

    if (val >= radix)
	s = utoa_recursive (val / radix, s, radix);
    c = val % radix;
    c += (c < 10 ? '0' : 'a' - 10);
    *s++ = c;
    return s;
}

static char *utoa (unsigned val, char *s, int radix)
{
    if (radix < 2 || radix > 36)
	s[0] = 0;
    else
	*utoa_recursive (val, s, radix) = 0;
    return s;
}
#endif


int main ()
{
    char s[40];
    char *(* volatile fun)(unsigned, char *, int);
    volatile int rdx;

    /* Inline function, possible call of __ltoa_ncheck().	*/

    utoa (60000, s, 10);
    if (strcmp_P (s, PSTR ("60000")))
	EXIT (__LINE__);
    utoa (35, s, 2);
    if (strcmp_P (s, PSTR ("100011")))
	EXIT (__LINE__);
    utoa (35, s, 36);
    if (strcmp_P (s, PSTR ("z")))
	EXIT (__LINE__);

    if (utoa (2, s, 1) != s || s[0])
	EXIT (__LINE__);
    s[0] = '2';
    if (utoa (2, s, 37) != s || s[0])
	EXIT (__LINE__);
    s[0] = '2';
    if (utoa (2, s, 0x0108) != s || s[0])
	EXIT (__LINE__);

    /* Library function, call of utoa().	*/

    fun = utoa;
    fun (60000, s, 10);
    if (strcmp_P (s, PSTR ("60000")))
	EXIT (__LINE__);
    fun (35, s, 2);
    if (strcmp_P (s, PSTR ("100011")))
	EXIT (__LINE__);
    fun (35, s, 36);
    if (strcmp_P (s, PSTR ("z")))
	EXIT (__LINE__);

    if (fun (2, s, 1) != s || s[0])
	EXIT (__LINE__);
    s[0] = '2';
    if (fun (2, s, 37) != s || s[0])
	EXIT (__LINE__);
    s[0] = '2';
    if (fun (2, s, 0x0108) != s || s[0])
	EXIT (__LINE__);

    /* Unknown radix, call of __utoa().	*/

    rdx = 10;
    utoa (60000, s, rdx);
    if (strcmp_P (s, PSTR ("60000")))
	EXIT (__LINE__);
    rdx = 2;
    utoa (35, s, rdx);
    if (strcmp_P (s, PSTR ("100011")))
	EXIT (__LINE__);
    rdx = 36;
    utoa (35, s, rdx);
    if (strcmp_P (s, PSTR ("z")))
	EXIT (__LINE__);

    rdx = 1;
    if (utoa (2, s, rdx) != s || s[0])
	EXIT (__LINE__);
    rdx = 37;
    s[0] = '2';
    if (utoa (2, s, rdx) != s || s[0])
	EXIT (__LINE__);
    rdx = 0x0108;
    s[0] = '2';
    if (utoa (2, s, rdx) != s || s[0])
	EXIT (__LINE__);

    return 0;
}
