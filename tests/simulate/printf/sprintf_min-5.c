/* Test of sprintf_min(), specification: x.
   $Id$	*/

#ifndef __AVR__
# define PRINTFLN(line, fmt, ...)	\
    printf("\nLine %2d: " fmt "\n", line, ##__VA_ARGS__)
# define EXIT(code)	exit ((code) < 255 ? (code) : 255)
# define sprintf_P	sprintf
#else
# define PRINTFLN(args...)
# define EXIT	exit
#endif

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "progmem.h"

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
    PRINTFLN (line, "expect: %3d, \"%s\",\n%8s output: %3d, \"%s\"\n",
	      strlen(expstr), expstr, " ", retval, retstr);
#ifdef	DEBUG
    code = (int)retstr;
#endif
    EXIT (code);
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
    /* '%X'	*/
    CHECK ("0 1234 5678 9ABC DEF0",
           "%X %X %X %X %X", 0, 0x1234, 0x5678, 0x9abc, 0xdef0);
    CHECK ("0XFEDC 0XBA98 0X7654 0X3210",
	   "%#X %#X %#X %#X", 0xfedc, 0xba98, 0x7654, 0x3210);

    /* '%p'	*/
#ifdef	__AVR__		/* Glibc result: (nil)	*/
    CHECK ("0", "%p", 0);
#endif
    CHECK ("0x1 0xabcd 0xef02", "%p %p %p", 1, 0xabcd, 0xef02);

    return 0;
}
