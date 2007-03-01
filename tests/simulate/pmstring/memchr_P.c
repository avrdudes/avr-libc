/* $Id$	*/

#ifndef	__AVR__
# include <stdio.h>
# define memchr_P  memchr
#endif
#include <stdlib.h>
#include <string.h>
#include "progmem.h"

void Check (int line, const char *s, int c, size_t len, int expect)
{
    const char *p;
    
    p = memchr_P (s, c, len);
    if ((expect == -1 && !p) || (s + expect == p))
	return;
#ifndef	__AVR__
    printf ("\nLine %d: expect: %d, result: %d\n",
	    line, expect, (p ? p-s : -1));
    if (line > 255) line = 255;			/* common OS restriction */
#endif
    exit (line);
}

#define CHECK(s, c, len, expect)	do {	\
    Check (__LINE__, PSTR(s), c, len, expect);	\
} while (0)

int main ()
{
    /* Not found	*/
    CHECK ("", 0, 0, -1);
    CHECK ("", 255, 0, -1);
    CHECK ("ABCDEF", 'a', 6, -1);
    
    /* Found	*/
    CHECK ("\000", 0, 1, 0);
    CHECK ("\001", 1, 1, 0);
    CHECK ("\377", 255, 1, 0);
    CHECK ("987654321", '7', 9, 2);

    /* '\0' has't a special sense	*/
    CHECK ("12345", 0, 6, 5);
    CHECK (".\000.", 0, 3, 1);
    CHECK ("\000a\000b", 'b', 4, 3);

    /* First occurance	*/
    CHECK ("abcdabcd", 'b', 8, 1);
    CHECK ("........", '.', 8, 0);
    
    /* 'c' converted to a char	*/
    CHECK ("ABCDEF", 'A'+0x100, 6, 0);
    CHECK ("ABCDE\377", ~0, 6, 5);
    
    /* Very long string	*/
    CHECK ("................................................................"
	   "................................................................"
	   "................................................................"
	   "................................................................"
	   "*...............................................................",
	   '*', 320, 256);

    return 0;
}
