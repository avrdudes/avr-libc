/* $Id$ */

#ifndef __AVR__
# define _GNU_SOURCE	/* to include strchrnul()	*/
# include <stdio.h>
# define PRINTFLN(line, fmt, ...)	\
    printf("\nLine %d: " fmt "\n", line, ##__VA_ARGS__)
# define EXIT(code)	exit ((code) < 255 ? (code) : 255)
# define memcmp_P	memcmp
#else
# define PRINTFLN(args...)
# define EXIT	exit
#endif

#include <stdlib.h>
#include <string.h>
#include "progmem.h"

void Check (int line, const char *s, int c, int expect)
{
    char t[300], *p;
    
    if (strlen_P(s) > sizeof(t) - 1)
	exit (1);
    strcpy_P (t, s);
    p = strchrnul (t, c);
    
    if (p != t + expect) {
	PRINTFLN (line, "expect: %d, result: %d", expect, p - t);
	EXIT (line);
    }
    if (strcmp_P (t, s)) {
	PRINTFLN (line, "string was changed");
	EXIT (1000 + line);
    }
}

#define CHECK(s, c, expect)	do {		\
    Check (__LINE__, PSTR(s), c, expect);	\
} while (0)

int main ()
{
    /* Not found	*/
    CHECK ("", 1, 0);
    CHECK ("", 255, 0);
    CHECK ("ABCDEF", 'a', 6);
    
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
	   "...............................................................*"
	   "...............", '*', 255);
    CHECK ("................................................................"
	   "................................................................"
	   "................................................................"
	   "................................................................"
	   "*..............", '*', 256);
    CHECK ("................................................................"
	   "................................................................"
	   "................................................................"
	   "................................................................"
	   ".*.............", '*', 257);

    return 0;
}
