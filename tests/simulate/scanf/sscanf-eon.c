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

/* Test of scanf(): end of number (integral).
   $Id$	*/

#include <ctype.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "progmem.h"

#ifdef	__AVR__
# define ASSERT(expr)			\
    do {				\
	if (!(expr)) exit(__LINE__);	\
    } while (0)
# define EXIT(v)	exit (v)
# if defined(__AVR_ATmega128__)
  /* ATmega128 has enough RAM for sprintf(), print to 0x2000 in XRAM. */
#  define PRINTF(f...)	sprintf((char *)0x2000, f)
# else
  /* small AVR */
#  define PRINTF(f...)
# endif
#else
# include <assert.h>
# define ASSERT(expr)	assert (expr)
# define EXIT(v)	exit ((v) < 256 ? (v) : 255)
# define PRINTF(f...)	printf (f)
# define sscanf_P	sscanf
# define memcmp_P	memcmp
#endif

/* Next variables are useful to debug the AVR.	*/
int vrslt = 1;
struct {
    int i[3];
    unsigned char s[3];
} v = { {1}, {1} };

int main ()
{
    char s[16];
    unsigned char c;
    int n;

    /* Decimal.	*/
    for (c = 255; c; c--) {
	if (isdigit (c))
	    continue;
	strcpy_P (s, PSTR("0.1.29."));
	s[1] = s[3] = s[6] = c;
	memset (&v, ~0, sizeof(v));
	n = sscanf (s, "%d%c%d%c%d%c",
		    v.i, v.s, v.i + 1, v.s + 1, v.i + 2, v.s + 2);
	ASSERT (n == 6);
	ASSERT (v.s[0] == c && v.s[1] == c && v.s[2] == c);
	ASSERT (v.i[0] == 0 && v.i[1] == 1 && v.i[2] == 29);
    }

    /* Octal.	*/
    for (c = 255; c; c--) {
	if (isdigit (c) && (c != '8') && (c != '9'))
	    continue;
	strcpy_P (s, PSTR("0.1.27."));
	s[1] = s[3] = s[6] = c;
	memset (&v, ~0, sizeof(v));
	n = sscanf (s, "%o%c%o%c%o%c",
		    v.i, v.s, v.i + 1, v.s + 1, v.i + 2, v.s + 2);
	ASSERT (n == 6);
	ASSERT (v.s[0] == c && v.s[1] == c && v.s[2] == c);
	ASSERT (v.i[0] == 0 && v.i[1] == 1 && v.i[2] == 027);
    }

    /* Hexidecimal.	*/
    for (c = 255; c; c--) {
	if (isxdigit (c))
	    continue;
	strcpy_P (s, PSTR("F.1.20."));
	s[1] = s[3] = s[6] = c;
	memset (&v, ~0, sizeof(v));
	n = sscanf (s, "%x%c%x%c%x%c",
		    v.i, v.s, v.i + 1, v.s + 1, v.i + 2, v.s + 2);
	ASSERT (n == 6);
	ASSERT (v.s[0] == c && v.s[1] == c && v.s[2] == c);
	ASSERT (v.i[0] == 0xF && v.i[1] == 1 && v.i[2] == 0x20);
    }

    return 0;
}
