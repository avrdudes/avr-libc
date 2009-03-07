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

/* Test of sprintf(), float version, '%e(E)' specification.
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

/* Flags separatly.	*/
    { "%e",	1.234567,	"1.234567e+00"	},
    { "%E",	1.234567,	"1.234567E+00"	},
    { "% e",	1.234567,	" 1.234567e+00"	},
    { "%+e",	1.234567,	"+1.234567e+00"	},
    { "%.3e",	1.234567,	"1.235e+00"	},
    { "%20e",	1.234567,	"        1.234567e+00"	},
    { "%-20e",	1.234567,	"1.234567e+00        "	},
    { "%020e",	1.234567,	"000000001.234567e+00"	},

/* Flags together.	*/
    { "% E",	1.234567,	" 1.234567E+00"	},
    { "% +e",	1.234567,	"+1.234567e+00"	},
    { "% e", 	-1.234567,	"-1.234567e+00"	},
    { "%+020e",	1.234567,	"+00000001.234567e+00"	},
    { "%-020e",	1.234567,	"1.234567e+00        "	},

/* Precision.	*/
    { "%.7e",	1.2345678,	"1.2345678e+00"	},
    { "%.6e",	1.2345678,	"1.234568e+00"	},
    { "%.5e",	1.2345678,	"1.23457e+00"	},
    { "%.4e",	1.2345678,	"1.2346e+00"	},
    { "%.3e",	1.2345678,	"1.235e+00"	},
    { "%.2e",	1.2345678,	"1.23e+00"	},
    { "%.1e",	1.2345678,	"1.2e+00"	},
    { "%.0e",	1.2345678,	"1e+00"		},
    { "%.e",	1.2345678,	"1e+00"		},

/* Width.	*/
    { "%1e",	1.2345678,	"1.234568e+00"	},
    { "%12e",	1.2345678,	"1.234568e+00"	},
    { "%13e",	1.2345678,	" 1.234568e+00"	},
    { "%13e",	-1.2345678,	"-1.234568e+00"	},
    { "%5.0e",	1.2345678,	"1e+00",	},
    { "%6.0e",	1.2345678,	" 1e+00",	},

/* Min and max values.	*/
    { "%.7e",	1.1754944e-38,	"1.1754944e-38"	},
    { "%.7e",	3.4028235e+38,	"3.4028235e+38"	},

/* Exponent "-00".	*/
    { "%.0e",	9.9999994e-01,	"1e-00"		},
    { "%.1e",	9.9999994e-01,	"1.0e-00"	},
    { "%.2e",	9.9999994e-01,	"1.00e-00"	},
    { "%.3e",	9.9999994e-01,	"1.000e-00"	},
    { "%.4e",	9.9999994e-01,	"1.0000e-00"	},
    { "%.5e",	9.9999994e-01,	"1.00000e-00"	},
    { "%.6e",	9.9999994e-01,	"9.999999e-01"	},
    { "%.7e",	9.9999994e-01,	"9.9999994e-01"	},
    { "%10.0e",	-9.9999994e-01,	"    -1e-00"	},
    { "%.0e",	0.9500001,	"1e-00"		},
    { "%.1e",	0.9950001,	"1.0e-00"	},
    { "%.2e",	0.9995001,	"1.00e-00"	},
    { "%.3e",	0.9999501,	"1.000e-00"	},
    { "%.4e",	0.9999951,	"1.0000e-00"	},
    { "%.5e",	0.9999996,	"1.00000e-00"	},
    { "%.6e",	0.9999996,	"9.999996e-01"	},

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
