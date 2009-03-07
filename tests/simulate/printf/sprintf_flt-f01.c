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

/* Test of sprintf(), float version, '%f(F)' specification.
   $Id$	*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "progmem.h"

PROGMEM static const struct sprf_s {
    char fmt[8];
    float val;
    char pattern[21];
} t[] = {

/* Nonregular cases.	*/
    { "%f",	0,	"0.000000"	},
    { "%7.3f",	9.9999,	" 10.000"	},

/* Flags separatly.	*/
    { "%f",	1.234567,	"1.234567"	},
    { "%F",	1.234567,	"1.234567"	},
    { "%f",	-1.234567,	"-1.234567"	},
    { "% f",	1.234567,	" 1.234567"	},
    { "%+f",	1.234567,	"+1.234567"	},
    { "%.3f",	1.234567,	"1.235"		},
    { "%12f",	1.234567,	"    1.234567"	},
    { "%-12f",	1.234567,	"1.234567    "	},
    { "%012f",	1.234567,	"00001.234567"	},

/* Flags together.	*/
    { "% F",	1.234567,	" 1.234567"	},
    { "% +f",	1.234567,	"+1.234567"	},
    { "% f", 	-1.234567,	"-1.234567"	},
    { "%+012f",	1.234567,	"+0001.234567"	},
    { "%-012f",	1.234567,	"1.234567    "	},

/* Precision.	*/
    { "%.7f",	1.2345678,	"1.2345678"	},
    { "%.6f",	1.2345678,	"1.234568"	},
    { "%.5f",	1.2345678,	"1.23457"	},
    { "%.4f",	1.2345678,	"1.2346"	},
    { "%.3f",	1.2345678,	"1.235"		},
    { "%.2f",	1.2345678,	"1.23"		},
    { "%.1f",	1.2345678,	"1.2"		},
    { "%.0f",	1.2345678,	"1"		},
    { "%.f",	1.2345678,	"1"		},

/* Width, without dec. point	*/
    { "%.0f",	10,		"10"		},
    { "%0.0f",	10,		"10"		},
    { "%1.0f",	10,		"10"		},
    { "%2.0f",	10,		"10"		},
    { "%3.0f",	10,		" 10"		},
    { "%12.0f",	10,		"          10"	},
    { "%12.0f",	-10,		"         -10"	},

/* Width, only fractional part.	*/
    { "%.3f",	0.123,		"0.123"		},
    { "%0.3f",	0.123,		"0.123"		},
    { "%1.3f",	0.123,		"0.123"		},
    { "%5.3f",	0.123,		"0.123"		},
    { "%6.3f",	0.123,		" 0.123"	},
    { "%12.3f",	0.123,		"       0.123"	},
    { "%12.3f",	-0.123,		"      -0.123"	},

/* Width, integer and fractional are present.	*/
    { "%.3f",	1.234,		"1.234"		},
    { "%0.3f",	1.234,		"1.234"		},
    { "%1.3f",	1.234,		"1.234"		},
    { "%5.3f",	1.234,		"1.234"		},
    { "%6.3f",	1.234,		" 1.234"	},
    { "%12.3f",	1.234,		"       1.234"	},
    { "%12.3f",	-1.234,		"      -1.234"	},

/* Double rounding elimination (ftoa_engine give at least 1 digit).	*/
    { "%.3f",	0.46,		"0.460"	},
    { "%.2f",	0.46,		"0.46"	},
    { "%.1f",	0.46,		"0.5"	},
    { "%.0f",	0.46,		"0"	},	/* just that very case */
    { "%1.0f",	0.46,		"0"	},
    { "%2.0f",	0.46,		" 0"	},

/* Rounding cases.	*/
    { "%.3f",	0.51,		"0.510"	},
    { "%.2f",	0.51,		"0.51"	},
    { "%.1f",	0.51,		"0.5"	},
    { "%.0f",	0.51,		"1"	},
    { "%1.0f",	0.51,		"1"	},
    { "%2.0f",	0.51,		" 1"	},

    { "%.3f",	0.58,		"0.580"	},
    { "%.2f",	0.58,		"0.58"	},
    { "%.1f",	0.58,		"0.6"	},
    { "%.0f",	0.58,		"1"	},
    { "%1.0f",	0.58,		"1"	},
    { "%2.0f",	0.58,		" 1"	},
    
    { "%.4f",	0.4999,		"0.4999"},
    { "%.3f",	0.4999,		"0.500"	},
    { "%.2f",	0.4999,		"0.50"	},
    { "%.1f",	0.4999,		"0.5"	},
    { "%.0f",	0.4999,		"0"	},

    { "%.2f",	0.049,		"0.05"	},
    { "%.1f",	0.049,		"0.0"	},
    { "%.0f",	0.049,		"0"	},

    { "%.10f",	0.00000000049,	"0.0000000005"	},
    { "%.9f",	0.00000000049,	"0.000000000"	},
    { "%.8f",	0.00000000049,	"0.00000000"	},
    
    { "%.10f",	0.00000000051,	"0.0000000005"	},
    { "%.9f",	0.00000000051,	"0.000000001"	},
    { "%.8f",	0.00000000051,	"0.00000000"	},
};

#ifndef	__AVR__
# define strlen_P	strlen
#endif

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
