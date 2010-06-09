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

/* Test of sprintf(), 'x' specification.
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
    /* '%x' specification	*/
    CHECK ("0", "%x", 0);
    CHECK ("1234 5678 9abc def0",
	   "%x %x %x %x", 0x1234, 0x5678, 0x9abc, 0xdef0);
    CHECK ("1 7fff 8000 8001 ffff",
           "%x %x %x %x %x", 1, 0x7fff, 0x8000, 0x8001, 0xffff);

    CHECK ("0 1 ffff", "%0x %0x %0x", 0, 1, 0xffff);
    CHECK ("0 1 ffff", "% x % x % x", 0, 1, 0xffff);
    CHECK ("0 1 ffff", "%+x %+x %+x", 0, 1, 0xffff);
    CHECK ("0 1 ffff", "%-x %-x %-x", 0, 1, 0xffff);
    CHECK ("0 0x1 0xffff", "%#x %#x %#x", 0, 1, 0xffff);

#ifdef	__AVR__
    CHECK ("0", "%.0x", 0);
#endif
    CHECK ("1 ffff", "%.0x %.0x", 1, 0xffff);
    CHECK ("0 1 ffff", "%.1x %.1x %.1x", 0, 1, 0xffff);
    CHECK ("00 01 ff ffff", "%.2x %.2x %.2x %.2x", 0, 1, 255, 0xffff);
    CHECK ("000 001 012 123 1234",
	   "%.3x %.3x %.3x %.3x %.3x", 0, 1, 0x12, 0x123, 0x1234);

    CHECK ("0.1.ffff", "%1x.%1x.%1x", 0, 1, 0xffff);
    CHECK (" 1.12.123", "%2x.%2x.%2x", 1, 0x12, 0x123);
    CHECK ("  1. 12.123.1234",
	   "%3x.%3x.%3x.%3x", 1, 0x12, 0x123, 0x1234);
    CHECK ("   0. 0x1.0x12.0x123.0x1234",
	   "%#4x.%#4x.%#4x.%#4x.%#4x", 0, 1, 0x12, 0x123, 0x1234);
    CHECK ("  14.ffff", "% 4x.% 4x", 0x14, 0xffff);
    CHECK ("  16.ffff", "%+4x.%+4x", 0x16, 0xffff);
    CHECK ("17  .ffff", "%-4x.%-4x", 0x17, 0xffff);

    CHECK ("0000.0001.0012.0123.1234",
	   "%04x.%04x.%04x.%04x.%04x",
	   0, 1, 0x12, 0x123, 0x1234);

    CHECK ("    0001", "%08.4x", 1);		/* 0 - ignored	*/
    CHECK ("       1", "%08.0x", 1);
    CHECK ("       1", "%08.x", 1);

    CHECK ("     000.     001.     012.     123.    1234",
	   "%8.3x.%8.3x.%8.3x.%8.3x.%8.3x", 0, 1, 0x12, 0x123, 0x1234);
    CHECK ("    0012.    0013.    0014",
	   "%08.4x.% 8.4x.%+8.4x", 0x12, 0x13, 0x14);
    CHECK ("000     .001     .012     .123     .1234    ",
	   "%-8.3x.%-8.3x.%-8.3x.%-8.3x.%-8.3x", 0, 1, 0x12, 0x123, 0x1234);

    CHECK ("    0000.  0x0001.  0x0012.  0x0123.  0x1234",
           "%#8.4x.%#8.4x.%#8.4x.%#8.4x.%#8.4x",
	   0, 1, 0x12, 0x123, 0x1234);

#if !defined(__AVR_AT90S8515__) /* this does not fit */
    CHECK ("                                                                "
	   "                                                                "
	   "                                                                "
	   "                                                              1",
	   "%255x", 1);
    CHECK ("1                                                               "
	   "                                                                "
	   "                                                                "
	   "                                                               ",
	   "%-255x", 1);
    CHECK ("0000000000000000000000000000000000000000000000000000000000000000"
	   "0000000000000000000000000000000000000000000000000000000000000000"
	   "0000000000000000000000000000000000000000000000000000000000000000"
	   "000000000000000000000000000000000000000000000000000000000000002",
	   "%.255x", 2);

    /* long arg	*/
    CHECK ("0 1 12345678 9abcdef0 7fffffff 80000000 80000001 ffffffff",
	   "%lx %lx %lx %lx %lx %lx %lx %lx",
	   0L, 1L, 0x12345678L, 0x9abcdef0L,
	   0x7fffffffL, 0x80000000L, 0x80000001L, 0xffffffffL);

    /* short arg	*/
    CHECK ("0 2 fffe", "%hx %hx %hx", 0, 2, 0xfffe);
#endif
    return 0;
}
