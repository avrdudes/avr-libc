/* $Id$	*/

#ifndef __AVR__
# include <stdio.h>
# define memcmp_P  memcmp
#endif
#include <stdlib.h>
#include <string.h>
#include "progmem.h"

void Check (int line, const char *s1, const char *s2, size_t len, int expect)
{
    char t1[200];
    int i;
    if (len > sizeof(t1))
	exit (1);
    memcpy_P (t1, s1, len ? len : 1);
    i = memcmp_P (t1, s2, len);
    if (i == expect)
	return;
#if	!defined(__AVR__)
    /* Glibc memcmp() returns: -1/0/+1.	*/
    if (   (i < 0 && expect < 0)
	|| (i > 0 && expect > 0)
	|| (i == 0 && expect == 0) )
      return;
    printf ("\nLine %d: expect: %d, result: %d\n",
	    line, expect, i);
    if (line > 255) line = 255;
#elif	defined(DEBUG)
    exit (i);
#endif
    exit (line);
}

#define CHECK(s1, s2, len, expect)	do {		\
    Check (__LINE__, PSTR(s1), PSTR(s2), len, expect);	\
} while (0)

int main ()
{
    /* len == 0	*/
    CHECK ("", "", 0, 0);
    CHECK ("A", "A", 0, 0);
    CHECK ("B", "C", 0, 0);

    /* len == 1	*/
    CHECK ("\000", "\001", 1, -1);
    CHECK ("\000", "\377", 1, -255);
    CHECK ("\001", "\000", 1, 1);
    CHECK ("\377", "\000", 1, 255);

    /* Agrs are equal.	*/
    CHECK ("\001", "\001", 1, 0);
    CHECK ("\001", "\001", 2, 0);
    CHECK ("1234\377", "1234\377", 1, 0);
    CHECK ("1234\377+", "1234\377-", 5, 0);

    /* Args are not equal.	*/
    CHECK ("ABCDEF", "ABCDE\000", 6, 'F');
    CHECK ("abcde\000", "abcdef", 6, -'f');
    CHECK ("12345", "12245", 5, 1);

    /* Case is important.	*/
    CHECK ("xyz", "xYz", 3, 'y'-'Y');
    CHECK ("QUICK", "qUICK", 5, 'Q'-'q');

    /* Chars are unsigned	*/
    CHECK ("\200", "\177", 1, 1);
    CHECK ("\177", "\200", 1, -1);
    CHECK ("\001", "\377", 1, -254);
    CHECK ("\377", "\001", 1, 254);

    /* '\0' is possible in the middle of array	*/
    CHECK ("\000ABC\000D", "\000ABC\000C", 5, 0);
    CHECK ("\000ABC\000D", "\000ABC\000C", 6, 1);

    return 0;
}
