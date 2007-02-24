/* $Id$	*/

#ifndef __AVR__
# include <stdio.h>
#endif
#include <stdlib.h>
#include <string.h>
#include "progmem.h"

void Check (int line, const char *s1, const char *s2, int expect)
{
    char t1[200];
    char t2[200];
    int i;
    if (   strlen_P(s1) > sizeof(t1) - 1
	|| strlen_P(s2) > sizeof(t2) - 1)
      exit (1);
    strcpy_P (t1, s1);
    strcpy_P (t2, s2);
    i = strcmp (t1, t2);
    if (i == expect)
	return;
#if	!defined(__AVR__)
    printf ("\nLine %d: expect: %d, result: %d\n",
	    line, expect, i);
    if (line > 255) line = 255;
#elif	defined(DEBUG)
    exit (i);
#endif
    exit (line);
}

#define CHECK(s1, s2, expect)	do {			\
    Check (__LINE__, PSTR(s1), PSTR(s2), expect);	\
} while (0)

int main ()
{
    /* One or both strings are empty.	*/
    CHECK ("", "", 0);
    CHECK ("", "\001", -1);
    CHECK ("", "\377", -255);
    CHECK ("\001", "", 1);
    CHECK ("\377", "", 255);

    /* Agrs are equal.	*/
    CHECK ("\001", "\001", 0);
    CHECK ("1234\377", "1234\377", 0);
    CHECK ("ABC", "ABC", 0);
    CHECK ("foo", "foo", 0);

    /* Args are not equal.	*/
    CHECK ("ABCDEF", "ABCDE", 'F');
    CHECK ("abcde", "abcdef", -'f');
    CHECK ("12345", "12245", 1);

    /* Case is important.	*/
    CHECK ("xyz", "xYz", 'y'-'Y');
    CHECK ("QUICK", "qUICK", 'Q'-'q');

    /* Chars are unsigned	*/
    CHECK ("\200", "\177", 1);
    CHECK ("\177", "\200", -1);
    CHECK ("\001", "\377", -254);
    CHECK ("\377", "\001", 254);

    return 0;
}
