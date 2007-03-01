/* $Id$	*/

#ifndef __AVR__
# include <stdio.h>
# define strspn_P  strspn
#endif
#include <stdlib.h>
#include <string.h>
#include "progmem.h"

void Check (int line, const char *s1, const char *s2, size_t expect)
{
    char t1[300];
    size_t n;

    if (strlen_P(s1) > sizeof(t1) - 1)
	exit (1);
    strcpy_P (t1, s1);
    n = strspn_P (t1, s2);
    if (n == expect)
	return;
#if   !defined(__AVR__)
    printf ("\nLine %d: expect: %d, result: %d\n",
	    line, expect, n);
    if (line > 255) line = 255;
#elif	defined(DEBUG)
    exit (n ? n : ~0);
#endif
    exit (line);
}

#define CHECK(s1, s2, expect)	do {			\
    Check (__LINE__, PSTR(s1), PSTR(s2), expect);	\
} while (0)

int main ()
{
    /* Empty string.	*/
    CHECK ("", "", 0);
    CHECK ("A", "", 0);
    CHECK ("", "A", 0);

    /* accept[] length is 1.	*/
    CHECK ("B", "A", 0);
    CHECK ("A", "A", 1);
    CHECK ("AAAAAAAA", "A", 8);

    /* accept[] length is 2.	*/
    CHECK ("c", "ab", 0);
    CHECK ("cd", "ab", 0);
    CHECK ("a", "ab", 1);
    CHECK ("a.", "ab", 1);
    CHECK ("ba", "ab", 2);
    CHECK ("ab.", "ab", 2);
    CHECK ("0101010101", "10", 10);
    CHECK ("0123456789AB", "+0", 1);
    
    /* accept[] length > 2	*/
    CHECK ("the quick brown fox", " qwertyuiopasdfghjklzxcvbnm", 19);
    CHECK ("the quick brown fox ...", " qwertyuiopasdfghjklzxcvbnm", 20);
    
    /* non ASCII chars	*/
    CHECK ("\001", "\001", 1);
    CHECK ("\377", "\377", 1);
    CHECK ("\002\376", "\001\377", 0);

    /* Result approx. 256	*/
    CHECK ("................................................................"
	   "................................................................"
	   "................................................................"
	   "...............................................................",
	   ".", 255);
    CHECK ("................................................................"
	   "................................................................"
	   "................................................................"
	   "................................................................",
	   "*.", 256);
    CHECK ("................................................................"
	   "................................................................"
	   "................................................................"
	   "................................................................"
	   ".+", "*.", 257);

    return 0;
}
