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

/* Tailing zeroes removing.	*/

    { "%.7g",	0.000010000002,	"1e-05"		},
    { "%.8g",	0.000010000002,	"1.0000002e-05"	},
    { "%.8g",	0.00001000002,	"1.000002e-05"	},
    { "%.8g",	0.0000100002,	"1.00002e-05"	},
    { "%.8g",	0.000010002,	"1.0002e-05"	},
    { "%.8g",	0.00001002,	"1.002e-05"	},
    { "%.8g",	0.0000102,	"1.02e-05"	},
    { "%.8g",	0.000012,	"1.2e-05"	},

    { "%.7g",	0.00010000002,	"0.0001"	},
    { "%.8g",	0.00010000002,	"0.00010000002"	},
    { "%.8g",	0.0001000002,	"0.0001000002"	},
    { "%.8g",	0.000100002,	"0.000100002"	},
    { "%.8g",	0.00010002,	"0.00010002"	},
    { "%.8g",	0.0001002,	"0.0001002"	},
    { "%.8g",	0.000102,	"0.000102"	},
    { "%.8g",	0.00012,	"0.00012"	},

    { "%.7g",	0.10000002,	"0.1"		},
    { "%.8g",	0.10000002,	"0.10000002"	},
    { "%.8g",	0.1000002,	"0.1000002"	},
    { "%.8g",	0.100002,	"0.100002"	},
    { "%.8g",	0.10002,	"0.10002"	},
    { "%.8g",	0.1002,		"0.1002"	},
    { "%.8g",	0.102,		"0.102"		},
    { "%.8g",	0.12,		"0.12"		},

    { "%.7g",	1.0000002,	"1"		},
    { "%.8g",	1.0000002,	"1.0000002"	},
    { "%.8g",	1.000002,	"1.000002"	},
    { "%.8g",	1.00002,	"1.00002"	},
    { "%.8g",	1.0002,		"1.0002"	},
    { "%.8g",	1.002,		"1.002"		},
    { "%.8g",	1.02,		"1.02"		},
    { "%.8g",	1.2,		"1.2"		},

    { "%.7g",	10.000002,	"10"		},
    { "%.8g",	10.000002,	"10.000002"	},
    { "%.8g",	10.00002,	"10.00002"	},
    { "%.8g",	10.0002,	"10.0002"	},
    { "%.8g",	10.002,		"10.002"	},
    { "%.8g",	10.02,		"10.02"		},
    { "%.8g",	10.2,		"10.2"		},
    { "%.8g",	12.,		"12"		},

    { "%.7g",	1000000.2,	"1000000"	},
    { "%.8g",	1000000.2,	"1000000.2"	},
    { "%.8g",	1000002.0,	"1000002"	},
    { "%.8g",	1000020.0,	"1000020"	},
    { "%.8g",	1200000.0,	"1200000"	},

    { "%.7g",	100000020.0,	"1e+08"		},
    { "%.8g",	100000020.0,	"1.0000002e+08"	},
    { "%.8g",	100000200.0,	"1.000002e+08"	},
    { "%.8g",	100002000.0,	"1.00002e+08"	},
    { "%.8g",	100020000.0,	"1.0002e+08"	},
    { "%.8g",	100200000.0,	"1.002e+08"	},
    { "%.8g",	102000000.0,	"1.02e+08"	},
    { "%.8g",	120000000.0,	"1.2e+08"	},

/* Tailing zeroes removing with sign presence.	*/

    { "%.7g",	-0.000010000002,"-1e-05"	},
    { "%.8g",	-0.000010000002,"-1.0000002e-05"},
    { "%.8g",	-0.00001000002,	"-1.000002e-05"	},
    { "%.8g",	-0.0000100002,	"-1.00002e-05"	},
    { "%.8g",	-0.000010002,	"-1.0002e-05"	},
    { "%.8g",	-0.00001002,	"-1.002e-05"	},
    { "%.8g",	-0.0000102,	"-1.02e-05"	},
    { "%.8g",	-0.000012,	"-1.2e-05"	},

    { "%.7g",	-0.10000002,	"-0.1"		},
    { "%.8g",	-0.10000002,	"-0.10000002"	},
    { "%.8g",	-0.1000002,	"-0.1000002"	},
    { "%.8g",	-0.100002,	"-0.100002"	},
    { "%.8g",	-0.10002,	"-0.10002"	},
    { "%.8g",	-0.1002,	"-0.1002"	},
    { "%.8g",	-0.102,		"-0.102"	},
    { "%.8g",	-0.12,		"-0.12"		},

    { "%.7g",	-1.0000002,	"-1"		},
    { "%.8g",	-1.0000002,	"-1.0000002"	},
    { "%.8g",	-1.000002,	"-1.000002"	},
    { "%.8g",	-1.00002,	"-1.00002"	},
    { "%.8g",	-1.0002,	"-1.0002"	},
    { "%.8g",	-1.002,		"-1.002"	},
    { "%.8g",	-1.02,		"-1.02"		},
    { "%.8g",	-1.2,		"-1.2"		},

    { "%.7g",	-10.000002,	"-10"		},
    { "%.8g",	-10.000002,	"-10.000002"	},
    { "%.8g",	-10.00002,	"-10.00002"	},
    { "%.8g",	-10.0002,	"-10.0002"	},
    { "%.8g",	-10.002,	"-10.002"	},
    { "%.8g",	-10.02,		"-10.02"	},
    { "%.8g",	-10.2,		"-10.2"		},
    { "%.8g",	-12.,		"-12"		},

    { "%.7g",	-1000000.2,	"-1000000"	},
    { "%.8g",	-1000000.2,	"-1000000.2"	},
    { "%.8g",	-1000002.0,	"-1000002"	},
    { "%.8g",	-1000020.0,	"-1000020"	},
    { "%.8g",	-1200000.0,	"-1200000"	},

    { "%.7g",	-100000020.0,	"-1e+08"	},
    { "%.8g",	-100000020.0,	"-1.0000002e+08"},
    { "%.8g",	-100000200.0,	"-1.000002e+08"	},
    { "%.8g",	-100002000.0,	"-1.00002e+08"	},
    { "%.8g",	-100020000.0,	"-1.0002e+08"	},
    { "%.8g",	-100200000.0,	"-1.002e+08"	},
    { "%.8g",	-102000000.0,	"-1.02e+08"	},
    { "%.8g",	-120000000.0,	"-1.2e+08"	},

/* Decimal point removing.	*/
    { "%.8g",	2.0000001e-5,	"2.0000001e-05"	},
    { "%.7g",	2.0000001e-5,	"2e-05"		},
    { "%.1g",	2.0000001e-5,	"2e-05"		},
    { "%.7g",	2.0,		"2"		},
    { "%.1g",	2.0,		"2"		},
    { "%.7g",	23.0,		"23"		},
    { "%.2g",	23.0,		"23"		},
    { "%.7g",	234.0,		"234"		},
    { "%.3g",	234.0,		"234"		},
    { "%.7g",	2345.0,		"2345"		},
    { "%.4g",	2345.0,		"2345"		},
    { "%.7g",	23456.0,	"23456"		},
    { "%.5g",	23456.0,	"23456"		},
    { "%.7g",	234567.0,	"234567"	},
    { "%.6g",	234567.0,	"234567"	},
    { "%.7g",	2345678.0,	"2345678"	},
    { "%.1g",	20.0,		"2e+01"		},
    { "%.2g",	200.0,		"2e+02"		},
    { "%.3g",	2000.0,		"2e+03"		},
    { "%.4g",	20000.0,	"2e+04"		},
    { "%.5g",	200000.0,	"2e+05"		},
    { "%.6g",	2000000.0,	"2e+06"		},
    { "%.7g",	20000000.0,	"2e+07"		},
    { "%.8g",	200000000.0,	"2e+08"		},

/* Decimale point removing with sign presence.	*/
    { "%.8g",	-2.0000001e-5,	"-2.0000001e-05"},
    { "%.7g",	-2.0000001e-5,	"-2e-05"	},
    { "%.1g",	-2.0000001e-5,	"-2e-05"	},
    { "%.7g",	-2.0,		"-2"		},
    { "%.1g",	-2.0,		"-2"		},
    { "%.7g",	-234567.0,	"-234567"	},
    { "%.6g",	-234567.0,	"-234567"	},
    { "%.1g",	-20.0,		"-2e+01"	},
    { "%.8g",	-200000000.0,	"-2e+08"	},
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
