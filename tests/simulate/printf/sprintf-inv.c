/* Test of sprintf(), invalid format.
   $Id$	*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "progmem.h"

#ifndef __AVR__
# define sprintf_P	sprintf
#endif

void Check (int line,
	    int explen,
            const char *expstr,
	    int retval, const char *retstr)
{
    int code;

    if (retval != explen)
	code = 1000 + line;
    else if (strcmp_P (retstr, expstr))
	code = line;
    else
	return;
#if	!defined(__AVR__)
    if (code) {
	printf ("\nLine %3d: expect: %3d, \"%s\","
		"\n          output: %3d, \"%s\"\n",
		line, explen, expstr, retval, retstr);
	code = (line < 256 ? line : 255);	/* common OS restriction */
    }
#elif	defined(DEBUG)
    exit ((int)retstr);
#endif
    exit (code);
}

/* 'vp' is used to avoid gcc warnings about format string.	*/
#define CHECK(explen, expstr, fmt, ...)	do {			\
    char s[260];						\
    int i;							\
    int (* volatile vp)(char *, const char *, ...) = sprintf_P;	\
    memset (s, 0, sizeof(s));					\
    i = vp (s, PSTR(fmt), ##__VA_ARGS__);			\
    Check (__LINE__, explen, PSTR(expstr), i, s);		\
} while (0)

int main ()
{
    /* Format last symbol is absent	*/
    CHECK (-1, "", "%");
    CHECK (-1, ".", ".%0");
    CHECK (-1, "12345 ", "%d %+l", 12345);

    /* 'hh' length modifier is possible, but it is ignored in avr-libc	*/
    CHECK (3, "123", "%hhd", 123);
    
    /* Length modifier and conversion mismatch: ignored	*/
    CHECK (1, "a", "%hhc", 'a');
    CHECK (1, "b", "%hc", 'b');
    CHECK (3, "foo", "%hhs", "foo");
    CHECK (3, "foo", "%hs", "foo");
    
    /* If the `space' and `+' flags both appear, the `space' flag
       is ignored.	*/
    CHECK (7, "+10.+11", "% +d.%+ d", 10, 11);
    
#ifdef	__AVR__
    /* Unknown format: glibc output is "%b", return value 2.	*/
    CHECK (-1, "", "%b");

    /* Two precision dots.	*/
    CHECK (-1, "", "%8..4d", 1);
    
    /* Long long arg	*/
    CHECK (-1, "", "%lld", 1LL);

    /* wint_t, wchar_t: ignore	*/
    CHECK (1, "c", "%lc", 'c');
    CHECK (3, "foo", "%ls", "foo");
    
    /* The asterisk `*' in width or precision.	*/
    CHECK (-1, "", "%*d", 10, 12345);
    CHECK (-1, "", "%10.*d", 6, 12345);
    CHECK (-1, "", "%*.*d", 10, 6, 12345);
#endif

    return 0;
}
