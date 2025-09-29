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
   POSSIBILITY OF SUCH DAMAGE. */

/* Header+source file to test the ftostrf() function. */

#ifndef	PATTERN_SIZE
# define PATTERN_SIZE	15
#endif

struct ftostrf_s {
    union {
	long lo;
	float fl;
    };
    signed char width;
    unsigned char prec;
    char pattern[PATTERN_SIZE];
};

#ifndef	__AVR__

# include <stdio.h>
# include <string.h>

/* This function is intended for run of test cases on the host computer.
 */
char * ftostrf (double val, signed char width, unsigned char prec, char *s)
{
    char fmt[16];	/* "%-110.100F"	*/
    
    sprintf (fmt, "%%%d.%dF", width, prec);
    sprintf (s, fmt, val);
    return s;
}
#endif	/* !__AVR__ */

#define	PZLEN	5	/* protected zone length	*/

void run_ftostrf (const struct ftostrf_s *pt, int testno)
{
    union {
	long lo;
	float fl;
    } val;
    signed char width;
    unsigned char prec;
    static char s[2*PZLEN + sizeof(pt->pattern)];
    char c, *ps;
    char const *pp;
    
    memset (s, testno, sizeof(s));

#ifdef	__AVR__
    val.lo = pgm_read_dword (& pt->lo);
    width  = pgm_read_byte (& pt->width);
    prec   = pgm_read_byte (& pt->prec);
#else
    val.lo = pt->lo;
    width  = pt->width;
    prec   = pt->prec;
#endif
    ps = ftostrf (val.fl, width, prec, s + PZLEN);

    if (ps != s + PZLEN)
	exit (testno + 0x1000);
    for (ps = s; ps != s + PZLEN; ps++) {
	if ((unsigned char)*ps != (testno & 0377))
	    exit (testno + 0x2000);
    }

    pp = pt->pattern;
#ifdef	__AVR__
    do {
	c = pgm_read_byte(pp++);
	if (*ps++ != c) {
	    exit (testno + 0x3000);
	}
    } while (c);
#else
    do {
	c = *pp++;
	if (*ps++ != c) {
	    printf ("*** testno= %d:  must= %s  was= %s\n",
		testno, pt->pattern, s + PZLEN);
	    exit (testno + 0x3000);
	}
    } while (c);
#endif

    for (; ps != s + sizeof(s); ps++) {
	if ((unsigned char)*ps != (testno & 0377))
	    exit (testno + 0x4000);
    }
}
