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

/* Test of sprintf(), float version, very long strings.
   $Id$	*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "progmem.h"

PROGMEM static const struct sprf_s {
    char fmt[8];
    float val;
    char pattern[260];
} t[] = {

    { "%255e",		1.234567,
	"                                "	/* 32 */
	"                                "	/* 32 */
	"                                "	/* 32 */
	"                                "	/* 32 */
	"                                "	/* 32 */
	"                                "	/* 32 */
	"                                "	/* 32 */
	"                   1.234567e+00"	},
    { "%255.7e",	1.2345678,
	"                                "	/* 32 */
	"                                "	/* 32 */
	"                                "	/* 32 */
	"                                "	/* 32 */
	"                                "	/* 32 */
	"                                "	/* 32 */
	"                                "	/* 32 */
	"                  1.2345678e+00"	},
    { "%+255e",		1.234567,
	"                                "	/* 32 */
	"                                "	/* 32 */
	"                                "	/* 32 */
	"                                "	/* 32 */
	"                                "	/* 32 */
	"                                "	/* 32 */
	"                                "	/* 32 */
	"                  +1.234567e+00"	},
    { "%0255e",		1.234567,
	"00000000000000000000000000000000"	/* 32 */
	"00000000000000000000000000000000"	/* 32 */
	"00000000000000000000000000000000"	/* 32 */
	"00000000000000000000000000000000"	/* 32 */
	"00000000000000000000000000000000"	/* 32 */
	"00000000000000000000000000000000"	/* 32 */
	"00000000000000000000000000000000"	/* 32 */
	"00000000000000000001.234567e+00"	},
    { "%+0255e",	1.234567,
	"+0000000000000000000000000000000"	/* 32 */
	"00000000000000000000000000000000"	/* 32 */
	"00000000000000000000000000000000"	/* 32 */
	"00000000000000000000000000000000"	/* 32 */
	"00000000000000000000000000000000"	/* 32 */
	"00000000000000000000000000000000"	/* 32 */
	"00000000000000000000000000000000"	/* 32 */
	"00000000000000000001.234567e+00"	},
    { "%+0255e",	-1.234567,
	"-0000000000000000000000000000000"	/* 32 */
	"00000000000000000000000000000000"	/* 32 */
	"00000000000000000000000000000000"	/* 32 */
	"00000000000000000000000000000000"	/* 32 */
	"00000000000000000000000000000000"	/* 32 */
	"00000000000000000000000000000000"	/* 32 */
	"00000000000000000000000000000000"	/* 32 */
	"00000000000000000001.234567e+00"	},
    { "%-255e",		1.234567,
	"1.234567e+00                    "
	"                                "	/* 32 */
	"                                "	/* 32 */
	"                                "	/* 32 */
	"                                "	/* 32 */
	"                                "	/* 32 */
	"                                "	/* 32 */
	"                               "	},

    { "%255.0f",	1.25,
	"                                "	/* 32 */
	"                                "	/* 32 */
	"                                "	/* 32 */
	"                                "	/* 32 */
	"                                "	/* 32 */
	"                                "	/* 32 */
	"                                "	/* 32 */
	"                              1"	},
    { "%.255f",		1.25,
	"1.250000000000000000000000000000"
	"00000000000000000000000000000000"	/* 32 */
	"00000000000000000000000000000000"	/* 32 */
	"00000000000000000000000000000000"	/* 32 */
	"00000000000000000000000000000000"	/* 32 */
	"00000000000000000000000000000000"	/* 32 */
	"00000000000000000000000000000000"	/* 32 */
	"000000000000000000000000000000000"	},
    { "%0255f",		1.25,
	"00000000000000000000000000000000"	/* 32 */
	"00000000000000000000000000000000"	/* 32 */
	"00000000000000000000000000000000"	/* 32 */
	"00000000000000000000000000000000"	/* 32 */
	"00000000000000000000000000000000"	/* 32 */
	"00000000000000000000000000000000"	/* 32 */
	"00000000000000000000000000000000"	/* 32 */
	"000000000000000000000001.250000"	},
    { "%-255f",		1.25,
	"1.250000                        "
	"                                "	/* 32 */
	"                                "	/* 32 */
	"                                "	/* 32 */
	"                                "	/* 32 */
	"                                "	/* 32 */
	"                                "	/* 32 */
	"                               "	},

    /* the smallest nonzero	*/
    { "%.45f",		0x1p-149f,
	"0.000000000000000000000000000000000000000000001"	},
    { "%.50f",		0x1p-149f,
	"0.00000000000000000000000000000000000000000000140130"	},

};

void run_sprf (const struct sprf_s *pt, int testno)
{
    static char s[300];
    int n;
    int code;

#ifdef	__AVR__
    n = sprintf_P (s, pt->fmt, pgm_read_dword (& pt->val));
#else
    n = sprintf (s, pt->fmt, pt->val);
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
