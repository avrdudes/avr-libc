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

/* Test of sprintf(), float version, '%g(G)' specification.
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
    { "%g",	0,		"0"	},
    { "%g",	1,		"1"	},
    { "%.8g",	12345678,	"12345678"	},
    { "%.8g",	123456780,	"1.2345678e+08"	},
    { "%.8g",	0.00012345678,	"0.00012345678"	},
    { "%.8g",	0.000012345678,	"1.2345678e-05"	},

/* Flags separatly.	*/
    { "%g",	1.23456e-5,	"1.23456e-05"	},
    { "%G",	1.23456e-5,	"1.23456E-05"	},
    { "%g",	-1.23456e-5,	"-1.23456e-05"	},
    { "% g",	1.23456e-5,	" 1.23456e-05"	},
    { "%+g",	1.23456e-5,	"+1.23456e-05"	},
    { "%.4g",	1.23456e-5,	"1.235e-05"	},
    { "%15g",	1.23456e-5,	"    1.23456e-05"	},
    { "%-15g",	1.23456e-5,	"1.23456e-05    "	},
    { "%015g",	1.23456e-5,	"00001.23456e-05"	},

/* Flags together.	*/
    { "% G",	1.23456e-5,	" 1.23456E-05"	},
    { "% +g",	1.23456e-5,	"+1.23456e-05"	},
    { "% g", 	-1.23456e-5,	"-1.23456e-05"	},
    { "%+015g",	1.23456e-5,	"+0001.23456e-05"	},
    { "%-015g",	1.23456e-5,	"1.23456e-05    "	},

/* Precision, 'f'	*/
    { "%.8g",	1.2345678,	"1.2345678"	},
    { "%.7g",	1.2345678,	"1.234568"	},
    { "%.6g",	1.2345678,	"1.23457"	},
    { "%.5g",	1.2345678,	"1.2346"	},
    { "%.4g",	1.2345678,	"1.235"		},
    { "%.3g",	1.2345678,	"1.23"		},
    { "%.2g",	1.2345678,	"1.2"		},
    { "%.1g",	1.2345678,	"1"		},
    { "%.0g",	1.2345678,	"1"		},
    { "%.g",	1.2345678,	"1"		},
    { "%g",	1.2345678,	"1.23457"	},

/* Precision, 'g'	*/
    { "%.8g",	1.2345678e+12,	"1.2345678e+12"	},
    { "%.7g",	1.2345678e+12,	"1.234568e+12"	},
    { "%.6g",	1.2345678e+12,	"1.23457e+12"	},
    { "%.5g",	1.2345678e+12,	"1.2346e+12"	},
    { "%.4g",	1.2345678e+12,	"1.235e+12"	},
    { "%.3g",	1.2345678e+12,	"1.23e+12"	},
    { "%.2g",	1.2345678e+12,	"1.2e+12"	},
    { "%.1g",	1.2345678e+12,	"1e+12"		},
    { "%.0g",	1.2345678e+12,	"1e+12"		},
    { "%.g",	1.2345678e+12,	"1e+12"		},
    { "%g",	1.2345678e+12,	"1.23457e+12"	},

/* Width, 'f' without dec. point	*/
    { "%0g",	10,		"10"		},
    { "%2g",	10,		"10"		},
    { "%3g",	10,		" 10"		},
    { "%12g",	10,		"          10"	},
    { "%12g",	-10,		"         -10"	},

/* Width, 'f', only fractional part	*/
    { "%.3g",	0.123,		"0.123"		},
    { "%0.3g",	0.123,		"0.123"		},
    { "%5.3g",	0.123,		"0.123"		},
    { "%6.3g",	0.123,		" 0.123"	},
    { "%12.3g",	0.123,		"       0.123"	},
    { "%12.3g",	-0.123,		"      -0.123"	},

/* Width, 'f', integer and fractional parts	*/
    { "%.5g",	12.345,		"12.345"	},
    { "%0.5g",	12.345,		"12.345"	},
    { "%6.5g",	12.345,		"12.345"	},
    { "%7.5g",	12.345,		" 12.345"	},
    { "%12.5g",	12.345,		"      12.345"	},
    { "%12.5g",	-12.345,	"     -12.345"	},

/* Width, 'e' without dec. point	*/
    { "%0g",	1e+23,		"1e+23"		},
    { "%5g",	1e+23,		"1e+23"		},
    { "%6g",	1e+23,		" 1e+23"	},
    { "%12g",	1e+23,		"       1e+23"	},
    { "%12g",	-1e+23,		"      -1e+23"	},

/* Width, 'e' with dec. point	*/
    { "%0g",	1.2e+34,	"1.2e+34"	},
    { "%7g",	1.2e+34,	"1.2e+34"	},
    { "%8g",	1.2e+34,	" 1.2e+34"	},
    { "%12g",	1.2e+34,	"     1.2e+34"	},
    { "%12g",	-1.2e+34,	"    -1.2e+34"	},

/* In contrast to 'f' spec.	*/
    { "%.3g",	0.46,		"0.46"	},
    { "%.2g",	0.46,		"0.46"	},
    { "%.1g",	0.46,		"0.5"	},
    { "%.0g",	0.46,		"0.5"	},
    { "%3.0g",	0.46,		"0.5"	},
    { "%4.0g",	0.46,		" 0.5"	},
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
