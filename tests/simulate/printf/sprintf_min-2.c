/* Test of sprintf_min(), specifications: d,i,u.
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
    /* '%d' specification	*/
    CHECK ("0", "%d", 0);
    CHECK ("12345", "%d", 12345);
    CHECK ("-32768 -32767 -1 0 1 32767",
           "%d %d %d %d %d %d",
	   (int)-32768, -32767, -1, 0, 1, 32767);

    CHECK ("0 1 -1", "%0d %0d %0d", 0, 1, -1);
    CHECK ("0 1 -1", "%-d %-d %-d", 0, 1, -1);
    CHECK ("0 1 -1", "%#d %#d %#d", 0, 1, -1);
#ifdef	__AVR__		/* PRINTF_MIN	*/
    CHECK ("0 1 -1", "%+d %+d %+d", 0, 1, -1);
    CHECK ("0 1 -1", "% d % d % d", 0, 1, -1);
    
    CHECK ("0.1.-1.1234.-123.12345.-1234",
	   "%04d.%04d.%04d.%04d.%04d.%04d.%04d",
	   0, 1, -1, 1234, -123, 12345, -1234);

    CHECK ("1", "%08.4d", 1);
    CHECK ("1", "%08.0d", 1);
    CHECK ("1", "%08.d", 1);

    CHECK ("0", "%.0d", 0);
#endif
    CHECK ("1 -1", "%.0d %.0d", 1, -1);
    CHECK ("0 1 -1", "%.1d %.1d %.1d", 0, 1, -1);
#ifdef	__AVR__		/* PRINTF_MIN	*/
    CHECK ("0 1 -1", "%.2d %.2d %.2d", 0, 1, -1);
    CHECK ("0 1 12 123 1234 12345",
	   "%.4d %.4d %.4d %.4d %.4d %.4d",
	   0, 1, 12, 123, 1234, 12345);

    CHECK ("0.1.-1", "%1d.%1d.%1d", 0, 1, -1);
    CHECK ("1.12.123", "%2d.%2d.%2d", 1, 12, 123);
    CHECK ("-1.-12.-123.-1234", "%4d.%4d.%4d.%4d", -1, -12, -123, -1234);
    CHECK ("12.-13", "%#4d.%#4d", 12, -13);
    CHECK ("14.-15", "% 4d.% 4d", 14, -15);
    CHECK ("16.-17", "%+4d.%+4d", 16, -17);
    CHECK ("18.-19", "%-4d.%-4d", 18, -19);

    CHECK ("1.-1.1234.-1234",
	   "%8.4d.%8.4d.%8.4d.%8.4d", 1, -1, 1234, -1234);
    CHECK ("12.13.14.15",
	   "%08.4d.%#8.4d.% 8.4d.%+8.4d", 12, 13, 14, 15);
    CHECK ("1.123.1234.12345",
	   "%-8.4d.%-8.4d.%-8.4d.%-8.4d", 1, 123, 1234, 12345);
    CHECK ("-1.-123.-1234.-12345",
	   "%-8.4d.%-8.4d.%-8.4d.%-8.4d", -1, -123, -1234, -12345);

    CHECK ("1", "%255d", 1);
    CHECK ("1", "%-255d", 1);
    CHECK ("2", "%.255d", 2);
#endif

    /* long arg	*/
    CHECK ("0 1 -1 2147483647 -2147483647 -2147483648",
	   "%ld %ld %ld %ld %ld %ld",
	   0L, 1L, -1L, 2147483647L, -2147483647L, 0x80000000L);

    /* short arg	*/
    CHECK ("0 2 -2", "%hd %hd %hd", 0, 2, -2);

    /* '%i' specification	*/
    CHECK ("-9", "%i", -9);

    /* '%u' specification	*/
    CHECK ("0 1 32767 32768 32769 65535",
           "%u %u %u %u %u %u",
	   0, 1, 0x7fff, 0x8000, 0x8001, 0xffff);

    return 0;
}
