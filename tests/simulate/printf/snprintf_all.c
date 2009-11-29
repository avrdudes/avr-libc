/* Copyright (c) 2008  Dmitry Xmelkov
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

/* $Id$ */

#ifndef __AVR__
# define PRINTFLN(line, fmt, ...)	\
    printf("\nLine %2d: " fmt "\n", line, ##__VA_ARGS__)
# define EXIT(code)	exit ((code) < 255 ? (code) : 255)
# define sprintf_P	sprintf
#else
# if defined(__AVR_ATmega128__)
  /* ATmega128 has enough RAM for sprintf(), print to 0x2000 in XRAM. */
#  define PRINTFLN(line, fmt, ...)	\
    sprintf ((char *)0x2000, "\nLine %d: " fmt "\n", line, ##__VA_ARGS__)
# else
   /* small AVR */
#  define PRINTFLN(args...)
# endif
# define EXIT	exit
#endif

#define	L_PRINTFLN(args...)	PRINTFLN (__LINE__, args)
#define L_EXIT()		EXIT (__LINE__)

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "progmem.h"

#ifdef	L_progmem
# ifdef	 __AVR__
#  define snprintf	snprintf_P
# endif
# define PFMT(s)	PSTR(s)
#else
# define PFMT(s)	s
#endif

void Check (int line,
            int expval, const char *expstr,
	    int retval, const char *retstr)
{
    int code;

    if (retval != expval)
	code = line;
    else if (strcmp_P (retstr, expstr))
	code = 1000 + line;
    else
	return;
    PRINTFLN (line, "expect: %3d, \"%s\",\n%8s output: %3d, \"%s\"\n",
	      strlen(expstr), expstr, " ", retval, retval > 0 ? retstr : "");
#ifdef	DEBUG
    code = (int)retstr;
#endif
    EXIT (code);
}

#define FILLBUF	0x55	/* Before call of function to test
			   buf[] is filled with nonzero value.	*/
/* 'vp' is used to avoid gcc warnings about format string.	*/
#define CHECK(expval, expstr, buf, size, fmt, ...)	do {	\
    int (* volatile vp)(char *, size_t, const char *, ...);	\
    vp = snprintf;						\
    memset (buf, FILLBUF, sizeof(buf));				\
    Check (__LINE__,						\
	   expval, PSTR(expstr),				\
	   vp (buf, size, PFMT(fmt), ##__VA_ARGS__),		\
	   buf);						\
} while (0)

int main ()
{
    int (* volatile vp)(char *, size_t, const char *, ...);
    char s[260];
    int i;

    /* size == 0	*/
    vp = snprintf;		/* to avoid compiler warning	*/
    i = vp (s+10, 0, PFMT(""));
    if (i) L_EXIT ();

    /* bug #19280: snprintf(s,0,...) write to s[-1]	*/
    memset (s, FILLBUF, sizeof(s));
    i = snprintf (s+10, 0, PFMT("foo"));
    if (i != 3) L_EXIT ();
    for (i = 0; i != (int)sizeof(s); i++) {
	if ((unsigned char)s[i] != FILLBUF)
	    L_EXIT ();
    }

    /* size == 1	*/
    s[0] = 1;
    CHECK (0, "", s, 1, "");
    CHECK (3, "", s, 1, "foo");

    /* size == 2	*/
    CHECK (0, "", s, 2, "");
    CHECK (1, ".", s, 2, ".");
    CHECK (2, "a", s, 2, "aa");
    CHECK (5, "1", s, 2, "%d", 12345);

    /* big size	*/
    CHECK (6, "-12345", s, sizeof(s), "%d", -12345);
    CHECK (5, "54321", s, ~0u >> 1, "%u", 54321);		/* 32767 */
    CHECK (4, "abcd", s, ~(~0u >> 1), "%x", 0xabcd);		/* 32768 */
    CHECK (3, "123", s, ~0u, "%o", 0123);			/* 65535 */


    return 0;
}
