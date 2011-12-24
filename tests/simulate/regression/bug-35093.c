/* Copyright (c) 2011  Dmitry Xmelkov
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

/* bug #35093: strlcat_P fails for some destinations
   $Id$	*/

#ifndef __AVR__

/* Omit the test, as strlcat() is not a standart C function.	*/
int main ()	{ return 0; }

#else

#include <avr/io.h>
#include <avr/pgmspace.h>
#include <string.h>

int main ()
{
    /* To activiate this bug, it is needed 0xXXFF address of terminated
       zero byte.	*/
# if	RAMEND >= 511
    char s[260];
# else
    char s[8];		/* Too small SRAM: omit testing.	*/
# endif
    int i, n;

    /* strlcat_P()	*/
    for (n = 0; n < (int)sizeof (s) - 2; n++) {
	for (i = 0; i < n; i++)
	    s[i] = 'A';
	s[i] = 0;

	i = strlcat_P (s, PSTR (""), sizeof (s));
	if (i != n)
	    return __LINE__;

	i = strlcat_P (s, PSTR ("B"), sizeof (s));
	if (i != n + 1)
	    return __LINE__;
	for (i = 0; i < n; i++) {
	    if (s[i] != 'A')
		return __LINE__;
	}
	if (s[i++] != 'B')
	    return __LINE__;
	if (s[i])
	    return __LINE__;
    }

    /* strlcat()	*/
    for (n = 0; n < (int)sizeof (s) - 2; n++) {
	for (i = 0; i < n; i++)
	    s[i] = 'A';
	s[i] = 0;

	i = strlcat (s, "", sizeof (s));
	if (i != n)
	    return __LINE__;

	i = strlcat (s, "B", sizeof (s));
	if (i != n + 1)
	    return __LINE__;
	for (i = 0; i < n; i++) {
	    if (s[i] != 'A')
		return __LINE__;
	}
	if (s[i++] != 'B')
	    return __LINE__;
	if (s[i])
	    return __LINE__;
    }

    return 0;
}

#endif	/* __AVR__ */
