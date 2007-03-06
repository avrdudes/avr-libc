/* $Id$	*/

#ifndef __AVR__
# define _GNU_SOURCE		/* to include strcasestr()	*/
# include <stdio.h>
# define PRINTFLN(line, fmt, ...)	\
    printf("\nLine %d: " fmt "\n", line, ##__VA_ARGS__)
# define EXIT(code)	exit ((code) < 255 ? (code) : 255)
# define strcasestr_P	strcasestr
#else
# define PRINTFLN(args...)
# define EXIT	exit
#endif

#include <stdlib.h>
#include <string.h>
#include "progmem.h"

void Check (int line, const char *s1, const char *s2, int expect)
{
    char t1[300];
    char *p;

    if (strlen_P(s1) > sizeof(t1) - 1)
	exit (1);
    strcpy_P (t1, s1);
    p = strcasestr_P (t1, s2);

    if (expect < 0) {
	if (p) {
	    PRINTFLN (line, "return nonzero");
	    EXIT (line);
	}
    } else {
	if (p != t1 + expect) {
	    PRINTFLN (line, "expect= %d  result= %d", expect, p - t1);
	    EXIT (1000 + line);
	}
    }
    if (strcmp_P (t1, s1)) {
	PRINTFLN (line, "string is changed");
	EXIT (2000 + line);
    }
}

#define CHECK(s1, s2, expect)	do {			\
    Check (__LINE__, PSTR(s1), PSTR(s2), expect);	\
} while (0)

int main ()
{
    /* Empty 'needle'.	*/
    CHECK ("", "", 0);
    CHECK ("12345", "", 0);

    /* bug #19135	*/
    CHECK ("ababac", "abac", 2);

    /* 'needle' of 1 byte long	*/
    CHECK ("", "a", -1);
    CHECK ("b", "a", -1);
    CHECK ("a", "a", 0);
    CHECK ("abcbef", "a", 0);
    CHECK (".a", "a", 1);
    CHECK (".a.", "a", 1);
    CHECK ("ABCDEFGH", "H", 7);
    
    /* 'needle' of 2 bytes long	*/
    CHECK ("", "12", -1);
    CHECK ("13", "12", -1);
    CHECK ("32", "12", -1);
    CHECK ("12", "12", 0);
    CHECK ("123", "12", 0);
    CHECK ("012", "12", 1);
    CHECK ("01200", "12", 1);
    
    /* partially mathing	*/
    CHECK ("a_ab_abc_abcd_abcde", "abcdef", -1);
    CHECK ("a_ab_abc_abcd_abcde_abcdef", "abcdef", 20);
    CHECK ("aababcabcdabcde", "abcdef", -1);
    CHECK ("aababcabcdabcdeabcdef", "abcdef", 15);
    
    /* repeated chars	*/
    CHECK ("abaabaaabaaaab", "aaaaab", -1);
    CHECK ("abaabaaabaaaabaaaaab", "aaaaab", 14);
    
    /* A first match is returned.	*/
    CHECK ("_foo_foo", "foo", 1);
    
    /* Case is ignored.	*/
    CHECK ("A", "a", 0);
    CHECK ("qwertyuiopasdfghjklzxcvbnm",
	   "QWERTYUIOPASDFGHJKLZXCVBNM",
	   0);
    CHECK (" QWERTYUIOPASDFGHJKLZXCVBNM",
	   "qwertyuiopasdfghjklzxcvbnm",
	   1);
    CHECK ("  The Quick Brown Fox ", "thE quicK browN foX", 2);

    /* Case is ignored for alphas only.	*/
    CHECK ("", "\040", -1);
    CHECK ("\100", "\140", -1);		/* first	*/
    CHECK ("\140", "\100", -1);
    CHECK ("\133", "\173", -1);
    CHECK ("\173", "\133", -1);
    CHECK (".\100", ".\140", -1);	/* second	*/
    CHECK (".\140", ".\100", -1);
    CHECK (".\133", ".\173", -1);
    CHECK (".\173", ".\133", -1);
    CHECK ("\100\140", "\140", 1);	/* second match	*/

    /* Very long s1	*/
    CHECK ("................................................................"
	   "................................................................"
	   "................................................................"
	   "...............................................................A",
	   "a", 255);
    CHECK ("................................................................"
	   "................................................................"
	   "................................................................"
	   "................................................................"
	   "a", "A", 256);
    CHECK ("................................................................"
	   "................................................................"
	   "................................................................"
	   "................................................................"
	   ".a", "A", 257);
    CHECK ("................................................................"
	   "................................................................"
	   "................................................................"
	   "................................................................"
	   ".a", "..A", 255);

    return 0;
}
