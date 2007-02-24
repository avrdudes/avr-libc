/* $Id$	*/

#ifndef __AVR__
# include <stdio.h>
# define strcasecmp_P  strcasecmp
#endif
#include <stdlib.h>
#include <string.h>
#include "progmem.h"

void Check (int line, const char *s1, const char *s2, int expect)
{
    char t1[200];
    int i;
    if (strlen_P(s1) > sizeof(t1) - 1)
	exit (1);
    strcpy_P (t1, s1);
    i = strcasecmp_P (t1, s2);
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

    /* bug #19134	*/
    CHECK ("a", "[", 'a' - '[');
    CHECK ("[", "a", '[' - 'a');

    /* Agrs are equal.	*/
    CHECK ("\001", "\001", 0);
    CHECK ("1234\377", "1234\377", 0);
    CHECK ("ABC", "abc", 0);
    CHECK ("FoO", "fOO", 0);

    /* Args are not equal.	*/
    CHECK ("@", "`", '@' - '`');	/* '@'=='A'-1, '`'=='a'-1	*/
    CHECK ("{", "[", '{' - '[');	/* '{'=='z'+1, '['=='A'+1	*/

    /* Alpha is always converted to lower	*/
    CHECK ("1", "A", '1'-'a');
    CHECK ("Z", "2", 'z'-'2');

    /* Chars are unsigned	*/
    CHECK ("\200", "\177", 1);
    CHECK ("\177", "\200", -1);
    CHECK ("\001", "\377", -254);
    CHECK ("\377", "\001", 254);

    return 0;
}
