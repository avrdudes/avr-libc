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

/* bug #35366: Bad behaviour for fprintf_P function
   Seems, there is no bug.
   $Id$	*/

#include <stdarg.h>
#include <stdio.h>
#include <string.h>

#ifdef	__AVR__
# include <avr/pgmspace.h>
# define PUTS(s)
#else
# define PUTS(s)	puts (s)
#endif

void foo (char *s, size_t n, const char *fmt, ...)
{
    va_list ap;
    va_start (ap, fmt);
    vsnprintf (s, n, fmt, ap);
    va_end (ap);
}

int main ()
{
    char s[50] = "";

    foo (s, sizeof (s), "e1=%f %% e2=%f", 1.25, -6.5);
    if (strcmp (s, "e1=1.250000 % e2=-6.500000")) {
	PUTS (s);
	return __LINE__;
    }

    foo (s, sizeof (s), "e1=%f %%%% e2=%f", -321.0, 0.125);
    if (strcmp (s, "e1=-321.000000 %% e2=0.125000")) {
	PUTS (s);
	return __LINE__;
    }

    return 0;
}
