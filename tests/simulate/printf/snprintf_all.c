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
# define snprintf	snprintf_P
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
