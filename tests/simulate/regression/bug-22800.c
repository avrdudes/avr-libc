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

/* bug #22800: sprintf() expands a 128char string parameter incorrectly
   $Id$
   
   This bug is marked as INVALID.  It is take place with avr-libc 1.4 only,
   which is not supported now.  Avr-libc 1.6 is correct.
 */

#include <stdio.h>
#include <string.h>

#ifndef	__AVR__
# define strcmp_P	strcmp
# define PSTR(s)	(s)
#else
# include <avr/pgmspace.h>
#endif


char buffer[210], string[200];
char tmp[] = "123";

int main ()
{
    int i;

    /* This is the bug report code.	*/
    for (i = 0; i < 129; i++)
	string[i] = 'B';
    sprintf (buffer, "%s%s", string, tmp);
    
    if (strcmp_P (buffer, PSTR ("BBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBB"  /* 32*B */
				"BBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBB"  /* 32*B */
				"BBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBB"  /* 32*B */
				"BBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBB"  /* 32*B */
				"B123")))
    {
	return __LINE__;
    }

#if	!defined(__AVR__) || (RAMEND >= 0x45F)
    /* Check the size > 255.	*/
    {
	char s[260];
	char t[sizeof(s)];

	memset (s, 'A', sizeof(s));
	s[sizeof(s) - 1] = 0;
	memset (t, 'B', sizeof(t));
	sprintf (t, "%s", s);
	
	if (strcmp (s, t)) return __LINE__;
    }
#endif
    
    return 0;
}
