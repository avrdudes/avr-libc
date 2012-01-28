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

#ifndef	__AVR__

/* Skip testing.	*/
int main ()	{ return 0; }

#else
# include <avr/pgmspace.h>
# define PUTS(s)

static char s[50];		/* buffer for result	*/

static int put (char c, FILE *fp)
{
    (void)fp;
    size_t n = strlen (s);
    if (n < sizeof (s) - 1)
	s[n] = c;
    return c;
}

static FILE outfile = FDEV_SETUP_STREAM (put, 0, _FDEV_SETUP_WRITE);

int main ()
{
    FILE *out;

    out = &outfile;

    fprintf_P (out, PSTR ("e1=%f %% e2=%f"), 0.5, -1.125);
    fflush (out);
    if (strcmp (s, "e1=0.500000 % e2=-1.125000")) {
	PUTS (s);
	return __LINE__;
    }

    memset (s, 0, sizeof (s));

    fprintf_P (out, PSTR ("e1=%f %%%% e2=%f"), -123.0, 9876.5);
    fflush (out);
    if (strcmp (s, "e1=-123.000000 %% e2=9876.500000")) {
	PUTS (s);
	return __LINE__;
    }

    return 0;
}
#endif	/* __AVR__ */
