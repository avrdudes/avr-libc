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

/* Test of 'd(i,u)' specification.
   $Id$	*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "progmem.h"

#ifndef __AVR__
# define sprintf_P	sprintf
#endif

void Check (int line,
            const char *expstr,
	    int retval, const char *retstr)
{
    int code;

    if (retval != (int)strlen (retstr))
	code = 1000 + line;
    else if (strcmp_P (retstr, expstr))
	code = line;
    else
	return;
#if	!defined(__AVR__)
    if (code) {
	printf ("\nLine %3d: expect: %3d, \"%s\","
		"\n          output: %3d, \"%s\"\n",
		line, strlen (expstr), expstr, retval, retstr);
	code = (line < 256 ? line : 255);	/* common OS restriction */
    }
#elif	defined(DEBUG)
    exit ((int)retstr);
#endif
    exit (code);
}

/* 'vp' is used to avoid gcc warnings about format string.	*/
#define CHECK(expstr, fmt, ...)	do {				\
    char s[260];						\
    int i;							\
    int (* volatile vp)(char *, const char *, ...) = sprintf_P;	\
    memset (s, 0, sizeof(s));					\
    i = vp (s, PSTR(fmt), ##__VA_ARGS__);			\
    Check (__LINE__, PSTR(expstr), i, s);			\
} while (0)

int main ()
{
    /* '%d' specification	*/
    CHECK ("0", "%d", 0);
    CHECK ("12345", "%d", 12345);
    CHECK ("-32768 -32767 -1 0 1 32767",
           "%d %d %d %d %d %d",
	   (int)-32768, -32767, -1, 0, 1, 32767);

    CHECK ("0 1 -1", "%0d %0d %0d", 0, 1, -1);
    CHECK ("+0 +1 -1", "%+d %+d %+d", 0, 1, -1);
    CHECK ("0 1 -1", "%-d %-d %-d", 0, 1, -1);
    CHECK ("0 1 -1", "%#d %#d %#d", 0, 1, -1);
    CHECK (" 0  1 -1", "% d % d % d", 0, 1, -1);
    
    CHECK ("0000.0001.-001.1234.-123.12345.-1234",
	   "%04d.%04d.%04d.%04d.%04d.%04d.%04d",
	   0, 1, -1, 1234, -123, 12345, -1234);

    CHECK ("    0001", "%08.4d", 1);		/* 0 - ignored	*/
    CHECK ("       1", "%08.0d", 1);
    CHECK ("       1", "%08.d", 1);

#ifdef	__AVR__
    CHECK ("0", "%.0d", 0);
#endif
    CHECK ("1 -1", "%.0d %.0d", 1, -1);
    CHECK ("0 1 -1", "%.1d %.1d %.1d", 0, 1, -1);
    CHECK ("00 01 -01", "%.2d %.2d %.2d", 0, 1, -1);
    CHECK ("0000 0001 0012 0123 1234 12345",
	   "%.4d %.4d %.4d %.4d %.4d %.4d",
	   0, 1, 12, 123, 1234, 12345);

    CHECK ("0.1.-1", "%1d.%1d.%1d", 0, 1, -1);
    CHECK (" 1.12.123", "%2d.%2d.%2d", 1, 12, 123);
    CHECK ("  -1. -12.-123.-1234", "%4d.%4d.%4d.%4d", -1, -12, -123, -1234);
    CHECK ("  12. -13", "%#4d.%#4d", 12, -13);
    CHECK ("  14. -15", "% 4d.% 4d", 14, -15);
    CHECK (" +16. -17", "%+4d.%+4d", 16, -17);
    CHECK ("18  .-19 ", "%-4d.%-4d", 18, -19);

    CHECK ("    0001.   -0001.    1234.   -1234",
	   "%8.4d.%8.4d.%8.4d.%8.4d", 1, -1, 1234, -1234);
    CHECK ("    0012.    0013.    0014.   +0015",
	   "%08.4d.%#8.4d.% 8.4d.%+8.4d", 12, 13, 14, 15);
    CHECK ("0001    .0123    .1234    .12345   ",
	   "%-8.4d.%-8.4d.%-8.4d.%-8.4d", 1, 123, 1234, 12345);
    CHECK ("-0001   .-0123   .-1234   .-12345  ",
	   "%-8.4d.%-8.4d.%-8.4d.%-8.4d", -1, -123, -1234, -12345);
#if !defined(__AVR_AT90S8515__) /* this does not fit */

    CHECK ("                                                                "
	   "                                                                "
	   "                                                                "
	   "                                                              1",
	   "%255d", 1);
    CHECK ("1                                                               "
	   "                                                                "
	   "                                                                "
	   "                                                               ",
	   "%-255d", 1);
    CHECK ("0000000000000000000000000000000000000000000000000000000000000000"
	   "0000000000000000000000000000000000000000000000000000000000000000"
	   "0000000000000000000000000000000000000000000000000000000000000000"
	   "000000000000000000000000000000000000000000000000000000000000002",
	   "%.255d", 2);

    /* long arg	*/
    CHECK ("0 1 -1 2147483647 -2147483647 -2147483648",
	   "%ld %ld %ld %ld %ld %ld",
	   0L, 1L, -1L, 2147483647L, -2147483647L, 0x80000000L);

    /* short arg	*/
    CHECK ("0 2 -2", "%hd %hd %hd", 0, 2, -2);

    /* '%i' specification	*/
    CHECK ("-9", "%i", -9);
#endif

    /* '%u' specification	*/
    CHECK ("0 1 32767 32768 32769 65535",
           "%u %u %u %u %u %u",
	   0, 1, 0x7fff, 0x8000, 0x8001, 0xffff);

    return 0;
}
