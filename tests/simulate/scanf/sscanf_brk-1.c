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
    CHECK (-1, 1, "", "%[a]", v.c);
    CHECK (-1, 1, " ", " %[a]", v.c);
    CHECK (-1, 1, "\t\n\v\f\r", " %[a]", v.c);
    
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

    return 0;
}
