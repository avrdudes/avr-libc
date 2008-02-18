/* Test of scanf(): '[' conversion directive.
   $Id$	*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "progmem.h"

#ifdef	__AVR__
# define ASSERT(expr)			\
    do {				\
	if (!(expr)) exit(__LINE__);	\
    } while (0)
# define EXIT(v)	exit (v)
# define PRINTF(f...)
#else
# include <assert.h>
# define ASSERT(expr)	assert (expr)
# define EXIT(v)	exit ((v) < 256 ? (v) : 255)
# define PRINTF(f...)	printf (f)
# define sscanf_P	sscanf
# define memcmp_P	memcmp
#endif

/* Next variables are useful to debug the AVR.	*/
int vrslt = 1;
struct {
    char c[12];
} v = { {1} };

void Check (int line, int expval, int rslt)
{
    vrslt = rslt;
    if (rslt != expval) {
	PRINTF ("\nLine %d:  expect= %d, rslt= %d\n", line, expval, rslt);
	EXIT (line);
    }
}

/* The sscanf() is called 4 times: SRAM and FLASH format, 2 values
   to fill before run.	*/
#define CHECK(expval, ass_expr, str, fmt, ...)				\
    do {								\
	PROGMEM static char fmt_p[] = fmt;				\
	char str_s[220];						\
	char fmt_s[40];							\
	char FILL;							\
	int i;								\
	int (* volatile vp)(const char *, const char *, ...);		\
									\
	ASSERT (sizeof(str_s) >= sizeof(str));				\
	ASSERT (sizeof(fmt_s) >= sizeof(fmt_p));			\
	strcpy_P (str_s, PSTR(str));					\
	strcpy_P (fmt_s, fmt_p);					\
									\
	for (FILL = 0; FILL < 4; FILL++) {				\
	    memset (&v, FILL, sizeof(v));				\
	    vp = (FILL & 1) ? sscanf_P : sscanf;			\
	    i = vp (str_s, (FILL & 1) ? fmt_p : fmt_s, ##__VA_ARGS__);	\
	    Check (__LINE__, expval, i);				\
    	    ASSERT (ass_expr);						\
	}								\
    } while (0)

int main ()
{
    /* Empty input.	*/
//    CHECK (-1, 1, "", "%s", v.c);
//    CHECK (-1, 1, " ", " %s", v.c);
//    CHECK (-1, 1, "\t\n\v\f\r", " %s", v.c);
    
    /* Normal conversion.	*/
    CHECK (1, !strcmp_P(v.c, PSTR("A")), "A", "%[A]", v.c);
    CHECK (1, !strcmp_P(v.c, PSTR("[")), "[", "%[[]", v.c);
    CHECK (1, !strcmp_P(v.c, PSTR("\001")), "\001", "%[\001]", v.c);
    CHECK (1, !strcmp_P(v.c, PSTR("\377")), "\377", "%[\377]", v.c);
    CHECK (1, !strcmp_P(v.c, PSTR("ABCD")), "ABCD", "%[ABCD]", v.c);

    /* The special symbol as normal.	*/
    CHECK (1, !strcmp_P(v.c, PSTR("]")), "]", "%[]]", v.c);
    CHECK (1, !strcmp_P(v.c, PSTR("]]")), "]]}", "%[]]", v.c);
    CHECK (1, !strcmp_P(v.c, PSTR("^")), "^", "%[ ^]", v.c);
    CHECK (1, !strcmp_P(v.c, PSTR("-")), "-", "%[-]", v.c);
    CHECK (1, !strcmp_P(v.c, PSTR("-a")), "-a", "%[a-]", v.c);
    CHECK (1, !strcmp_P(v.c, PSTR("-^]")), "-^]", "%[]^-]", v.c);

    /* End of string.	*/
    CHECK (1, !strcmp_P(v.c, PSTR("A")), "A A", "%[A]", v.c);
    CHECK (1, !strcmp_P(v.c, PSTR("A")), "AB", "%[A]", v.c);
    CHECK (1, !strcmp_P(v.c, PSTR("A")), "Aa", "%[A]", v.c);

    /* Leading spaces.	*/
    CHECK (0, v.c[0] == FILL, " A", "%[A]", v.c);

    /* Spaces in string.	*/
    CHECK (1, !strcmp_P(v.c, PSTR(" A")), " A", "%[A ]", v.c);
    CHECK (1, !strcmp_P(v.c, PSTR("Z A")), "Z A", "%[A Z]", v.c);

    /* A few conversions.	*/
    CHECK (2, !memcmp_P(v.c, PSTR("AB\000CD\000"), 6),
	   "ABCD", "%[AB]%[CD]", v.c, v.c + 3);

    /* Suppress a writing.	*/
    CHECK (0, (v.c[0] == FILL), "A", "%*[A]", v.c);
    CHECK (2, !memcmp_P(v.c, PSTR("A\000C\000"), 4),
	   "ABC", "%[A]%*[B]%[C]", v.c, v.c + 2);

#if 0
#if 0
    /* Width field.	*/
    CHECK (1, !strcmp_P(v.c, PSTR("A")), "A", "%1s", v.c);
    CHECK (1, !strcmp_P(v.c, PSTR("A")), "ABCD", "%1s", v.c);
    CHECK (1, !strcmp_P(v.c, PSTR("AB")), "ABCD", "%2s", v.c);
//    CHECK (2, !memcmp_P(v.c, PSTR("CD\000AB\000"), 6),
//	   "ABCD", "%2s%2s", v.c + 3, v.c);
    CHECK (1, !strcmp_P(v.c, PSTR("The_quick_b")),
	   "The_quick_brown_fox", "%11s", v.c);

    /* Suppress and width.	*/
    CHECK (0, (v.c[0] == FILL), "A", "%*1s", v.c);
    CHECK (0, (v.c[0] == FILL), "AA", "%*2s", v.c);

    /* Zero width.	*/
#ifdef	__AVR__
    CHECK (1, (v.c[0] == 0 && v.c[1] == FILL), "A", "%0s", v.c);
#else
    CHECK (1, !strcmp_P(v.c, PSTR("A")), "A", "%0s", v.c);	/* ??? */
#endif

    /* Left width digit is 0.	*/
    CHECK (1, !strcmp_P(v.c, PSTR("A")), "ABCD", "%01s", v.c);
    CHECK (1, !strcmp_P(v.c, PSTR("AB")), "ABCD", "%02s", v.c);

    /* Invalid symbol after '%'.	*/
    CHECK (0, (v.c[0] == FILL), "A", "% s", v.c);
    CHECK (0, (v.c[0] == FILL), "A", "%-s", v.c);
    CHECK (0, (v.c[0] == FILL), "A", "%+s", v.c);
    CHECK (0, (v.c[0] == FILL), "A", "%.s", v.c);
    CHECK (0, (v.c[0] == FILL), "A", "%#s", v.c);
#endif

    /* The length modifier.	*/
    CHECK (1, !strcmp_P(v.c, PSTR("A")), "A", "%hs", v.c);
#ifdef	__AVR__
//    CHECK (1, (v.c[0] == 'A' && v.c[1] == FILL), "A", "%lc", v.c);
#else
//    CHECK (1, (v.c[0] == 'A' && v.c[1] == 0), "A", "%lc", v.c);
#endif
#endif

    return 0;
}
