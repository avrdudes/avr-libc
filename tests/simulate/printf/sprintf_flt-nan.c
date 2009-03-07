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

/* Test of sprintf(), float version, nonfinite numbers.
   $Id$	*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "progmem.h"

PROGMEM static const struct sprfu_s {
    char fmt[8];
    union {
	long lo;
	float fl;
    } val;
    char pattern[21];
} t[] = {

    { "%e",	{ 0x7f800000 }, 	"inf"	},
    { "%e",	{ 0xff800000 },		"-inf"	},
    { "%f",	{ 0x7f800000 },		"inf"	},
    { "%G",	{ 0xff800000 },		"-INF"	},

    { "%e",	{ 0x7f800001 },		"nan"	},
    { "% e",	{ 0x7f800001 },		" nan"	},
    { "%+e",	{ 0x7f800001 },		"+nan"	},
    { "%E",	{ 0x7f800001 },		"NAN"	},
    { "%5e",	{ 0x7f800001 },		"  nan"	},
    { "%+5e",	{ 0x7f800001 },		" +nan"	},
    { "%05e",	{ 0x7f800001 },		"  nan"	},
    { "%-5e",	{ 0x7f800001 },		"nan  "	},

    { "%e",	{ 0xff800001 },		"nan"	},
    { "% e",	{ 0xff800001 },		" nan"	},
    { "%+e",	{ 0xff800001 },		"+nan"	},
    { "%E",	{ 0xff800001 },		"NAN"	},
    { "%5e",	{ 0xff800001 },		"  nan"	},
    { "%+5e",	{ 0xff800001 },		" +nan"	},
    { "%05e",	{ 0xff800001 },		"  nan"	},
    { "%-5e",	{ 0xff800001 },		"nan  "	},

    { "%e",	{ 0x7fffffff },		"nan"	},
    { "%e",	{ 0xffffffff },		"nan"	},
    { "%e",	{ 0x7fc00000 },		"nan"	},
    { "%e",	{ 0xffc00000 },		"nan"	},

    { "%f",	{ 0x7f800001 },		"nan"	},
    { "%5F",	{ 0x7f800001 },		"  NAN"	},
    { "%g",	{ 0x7f800001 },		"nan"	},
    { "%5G",	{ 0x7f800001 },		"  NAN"	},
};

#ifndef	__AVR__
# define strlen_P	strlen
#endif

void run_sprf (const struct sprfu_s *pt, int testno)
{
    static char s[300];
    int n;
    int code;

#ifdef	__AVR__
    n = sprintf_P (s, pt->fmt, pgm_read_dword (& pt->val));
#else
    n = sprintf (s, pt->fmt, pt->val.fl);
#endif
    if (n != (int)strlen_P (pt->pattern))
	code = testno + 1000;
    else if (strcmp_P (s, pt->pattern))
	code = testno;
    else
	return;
#if  !defined(__AVR__)
    printf ("\ntestno %3d: expect: %3d, \"%s\","
	    "\n            output: %3d, \"%s\"\n",
	    testno, strlen(pt->pattern), pt->pattern, n, s);
    exit (code < 256 ? testno : 255);
#elif	defined(DEBUG)
    exit ((int)s);
#endif
    exit (code);
}

int main ()
{
    int i;
    for (i = 0; (unsigned)i != sizeof(t)/sizeof(t[0]); i++)
	run_sprf (t+i, i+1);
    return 0;
}
