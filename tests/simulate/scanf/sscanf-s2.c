/* Test of scanf(): 's' conversion directive.
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
# if defined(__AVR_ATmega128__)
  /* ATmega128 has enough RAM for sprintf(), print to 0x2000 in XRAM. */
#  define PRINTF(f...)	sprintf((char *)0x2000, f)
# else
  /* small AVR */
#  define PRINTF(f...)
# endif
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
    char c;
    char s[8];
} v[6] = { {1, {1}} };

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
    /* Width field.	*/
    CHECK (1, !strcmp_P(v[0].s, PSTR("A")), "A", "%1s", v[0].s);
    CHECK (1, !strcmp_P(v[0].s, PSTR("A")), "ABCD", "%1s", v[0].s);
    CHECK (1, !strcmp_P(v[0].s, PSTR("AB")), "ABCD", "%2s", v[0].s);
    CHECK (2, !memcmp_P(v[0].s, PSTR("CD\000AB\000"), 6),
	   "ABCD", "%2s%2s", v[0].s + 3, v[0].s);
    CHECK (1, !strcmp_P(v[0].s, PSTR("The_quick_b")),
	   "The_quick_brown_fox", "%11s", v[0].s);

    /* Suppress and width.	*/
    CHECK (0, (v[0].s[0] == FILL), "A", "%*1s", v[0].s);
    CHECK (0, (v[0].s[0] == FILL), "AA", "%*2s", v[0].s);

    /* Split long string.	*/
    CHECK (
	6,
	!strcmp_P (v[0].s, PSTR("ABCDE"))
	&& !strcmp_P (v[1].s, PSTR("FGHIJ"))
	&& !strcmp_P (v[2].s, PSTR("KLMNO"))
	&& !strcmp_P (v[3].s, PSTR("PQRST"))
	&& !strcmp_P (v[4].s, PSTR("UVWXY"))
	&& !strcmp_P (v[5].s, PSTR("Z")),
	"ABCDEFGHIJKLMNOPQRSTUVWXYZ",
	"%5s%5s %5s  %5s\t%5s\n%5s",
	v[0].s, v[1].s, v[2].s, v[3].s, v[4].s, v[5].s);

    /* Zero width.	*/
#ifdef	__AVR__
    CHECK (0, (v[0].s[0] == FILL), "A", "%0s", v[0].s);
#else
    CHECK (1, !strcmp_P(v[0].s, PSTR("A")), "A", "%0s", v[0].s);  /* ??? */
#endif

    /* Left width digit is 0.	*/
    CHECK (
	2,
	!strcmp_P(v[0].s, PSTR("A")) && !strcmp_P(v[1].s, PSTR("BC")),
	"ABCD",
	"%01s %02s", v[0].s, v[1].s);

    /* Invalid symbol after '%'.	*/
    CHECK (0, (v[0].s[0] == FILL), "A", "% s", v[0].s);
    CHECK (0, (v[0].s[0] == FILL), "A", "%-s", v[0].s);
    CHECK (0, (v[0].s[0] == FILL), "A", "%+s", v[0].s);
    CHECK (0, (v[0].s[0] == FILL), "A", "%.s", v[0].s);
    CHECK (0, (v[0].s[0] == FILL), "A", "%#s", v[0].s);

    /* The length modifier.	*/
    CHECK (1, !strcmp_P(v[0].s, PSTR("A")), "A", "%hs", v[0].s);
    CHECK (1, !strcmp_P(v[0].s, PSTR("A")), "A", "%ls", v[0].s);

    return 0;
}
