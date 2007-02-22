/* $Id$	*/

#include <stdlib.h>
#include <string.h>
#include "progmem.h"

#ifndef	__AVR__
# include <stdio.h>
# define strchr_P	strchr
#endif

void Check (int line, const char *s, int c, int expect)
{
    const char *p;
    p = strchr_P (s, c);
    if (expect == -1 && !p)
	return;
    if (s + expect == p)
	return;
#ifndef	__AVR__
    printf ("\nLine %d: expect: %d, result: %d\n",
	    line, expect, (p ? p-s : -1));
#endif
    exit (line);
}

#define CHECK(s, c, expect)	do {		\
    Check (__LINE__, PSTR(s), c, expect);	\
} while (0)

int main ()
{
    /* Not found	*/
    CHECK ("", 1, -1);
    CHECK ("", 255, -1);
    CHECK ("ABCDEF", 'a', -1);
    
    /* Found	*/
    CHECK ("\001", 1, 0);
    CHECK ("\377", 255, 0);
    CHECK ("987654321", '7', 2);

    /* '\0' is a part of string	*/
    CHECK ("12345", 0, 5);
    CHECK ("", 0, 0);

    /* First occurance	*/
    CHECK ("abcdabcd", 'b', 1);
    
    /* 'c' converted to a char	*/
    CHECK ("ABCDEF", 'A'+0x100, 0);
    CHECK ("ABCDE\377", ~0, 5);
    
    /* Very long string	*/
    CHECK ("................................................................"
	   "................................................................"
	   "................................................................"
	   "................................................................"
	   "*...............", '*', 256);

    return 0;
}
