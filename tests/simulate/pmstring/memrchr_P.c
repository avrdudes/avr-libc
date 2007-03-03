/* $Id$	*/

#ifndef __AVR__
# define _GNU_SOURCE	/* to include memrchr()	*/
# include <stdio.h>
# define PRINTFLN(line, fmt, ...)	\
    printf("\nLine %d: " fmt "\n", line, ##__VA_ARGS__)
# define EXIT(code)	exit ((code) < 255 ? (code) : 255)
# define memrchr_P	memrchr
#else
# define PRINTFLN(args...)
# define EXIT	exit
#endif

#include <stdlib.h>
#include <string.h>
#include "progmem.h"

void Check (int line, const char *s, int c, size_t len, int expect)
{
    const char *p;
    
    p = memrchr_P (s, c, len);

    if (expect < 0) {
	if (p) {
	    PRINTFLN (line, "non zero pointer is returned");
	    EXIT (line);
	}
    } else {
	if (p != s + expect) {
	    PRINTFLN (line, "expect= %d  result= %d", expect, p - s);
	    EXIT (line + 1000);
	}
    }
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

    /* Last occurance	*/
    CHECK ("abcdabcd", 'b', 8, 5);
    CHECK ("........", '.', 8, 7);
    
    /* 'c' converted to a char	*/
    CHECK ("ABCDEF", 'A'+0x100, 6, 0);
    CHECK ("ABCDE\377", ~0, 6, 5);
    
    /* Very long string	*/
    CHECK ("................................................................"
	   "................................................................"
	   "................................................................"
	   "...............................................................*"
	   "................................................................",
	   '*', 320, 255);
    CHECK ("................................................................"
	   "................................................................"
	   "................................................................"
	   "................................................................"
	   "*...............................................................",
	   '*', 320, 256);
    CHECK ("................................................................"
	   "................................................................"
	   "................................................................"
	   "................................................................"
	   ".*..............................................................",
	   '*', 320, 257);

    return 0;
}
