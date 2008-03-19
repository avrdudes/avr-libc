/* $Id$ */

#ifndef __AVR__
# define PRINTFLN(line, fmt, ...)	\
    printf("\nLine %2d: " fmt "\n", line, ##__VA_ARGS__)
# define EXIT(code)	exit ((code) < 255 ? (code) : 255)
# define vsnprintf_P	vsnprintf
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

#include <stdarg.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "progmem.h"

#ifdef	L_progmem
# define vsnprintf	vsnprintf_P
# define PFMT(s)	PSTR(s)
#else
# define PFMT(s)	s
#endif

void Check (int line,
            int expval, const char *expstr,
	    char *buf, size_t size, const char *fmt, ...)
{
    va_list ap;
    int retval;
    int code;

    va_start (ap, fmt);
    retval = vsnprintf (buf, size, fmt, ap);
    va_end (ap);

    if (retval != expval)
	code = line;
    else if (size && strcmp_P (buf, expstr))
	code = 1000 + line;
    else
	return;
    PRINTFLN (line, "expect: %3d, \"%s\",\n%8s output: %3d, \"%s\"\n",
	      strlen(expstr), expstr, " ", retval, size ? buf : "");
#ifdef	DEBUG
    code = (int)retstr;
#endif
    EXIT (code);
}


#define FILLBUF	0x55	/* Before call of function to test
			   buf[] is filled with nonzero value.	*/
#define CHECK(expval, expstr, buf, size, fmt, ...)	\
    memset (buf, FILLBUF, sizeof(buf));			\
    Check (__LINE__, expval, PSTR(expstr),		\
	   buf, size, PFMT(fmt), ##__VA_ARGS__)

int main ()
{
    char s[260];
    int i;

    /* size == 0	*/
    CHECK (0, "", s+10, 0, "");

    /* bug #19280: snprintf(s,0,...) write to s[-1]	*/
    memset (s, FILLBUF, sizeof(s));
    Check (__LINE__, 3, PSTR(""), s+10, 0, PFMT("foo"));
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
