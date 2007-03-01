/* $Id$	*/

#ifndef __AVR__
# include <stdio.h>
#endif
#include <stdlib.h>
#include <string.h>
#include "progmem.h"

void Check (int line, const char *s, int c, int expect)
{
    char t[300], *p;
    strcpy_P (t, s);
    p = strrchr (t, c);
    if (expect == -1 && !p)
	return;
    if (t + expect == p)
	return;
#ifndef	__AVR__
    printf ("\nLine %d: expect: %d, result: %d\n",
	    line, expect, (p ? p-t : -1));
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

    /* Last occurance	*/
    CHECK ("00", '0', 1);
    CHECK ("abcdabcd", 'b', 5);
    CHECK ("***********", '*', 10);
    
    /* 'c' converted to a char	*/
    CHECK ("ABCDEF", 'A'+0x100, 0);
    CHECK ("ABCDE\377", ~0, 5);
    CHECK ("+", ~0xff, 1);
    
    /* Very long string	*/
    CHECK ("................................................................"
	   "................................................................"
	   "................................................................"
	   "................................................................"
	   "*...............", '*', 256);

    return 0;
}
