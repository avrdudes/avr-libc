/* Test of scanf(): 'd' conversion directive.
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
    int i[4];
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
    /* Not a number: EOF	*/
    CHECK (-1, *(char *)v.i == FILL, "", "%d", v.i);
    CHECK (-1, *(char *)v.i == FILL, " ", "%d", v.i);

#ifdef	__AVR__
    CHECK (-1, *(char *)v.i == FILL, "+", "%d", v.i);
    CHECK (-1, *(char *)v.i == FILL, "-", "%d", v.i);
#else							/* ???	*/
    CHECK (0, *(char *)v.i == FILL, "+", "%d", v.i);
    CHECK (0, *(char *)v.i == FILL, "-", "%d", v.i);
#endif

    /* Not a number: invalid symbol.	*/
    CHECK (0, *(char *)v.i == FILL, "A", "%d", v.i);
    CHECK (0, *(char *)v.i == FILL, ".9", "%d", v.i);

    /* Width field.	*/
    CHECK (1, (v.i[0] == 9), "9", "%1d", v.i);
    CHECK (1, (v.i[0] == 9), "98", "%1d", v.i);
    CHECK (1, (v.i[0] == 98), "9876", "%2d", v.i);
    CHECK (2, (v.i[0] == 76) && (v.i[1] == 98),
	   "9876", "%2d%2d", v.i + 1, v.i);
    CHECK (1, (v.i[0] == 1234), "000000000012345", "%14d", v.i);

    /* Width field and spaces.	*/
    CHECK (1, (v.i[0] == 12), " 12345", "%2d", v.i);
    CHECK (1, (v.i[0] == 12), " \t\n\v\f\r12345", "%2d", v.i);

    /* Width field and a sign.	*/
    CHECK (1, (v.i[0] == 12), "+12345", "%3d", v.i);
    CHECK (1, (v.i[0] == -12), "-12345", "%3d", v.i);

    /* Width, space and sign.	*/
    CHECK (1, (v.i[0] == -12), "  -12345", "%3d", v.i);

    /* Suppress and width.	*/
    CHECK (0, (*(char *)v.i == FILL), "9", "%*1d", v.i);
    CHECK (0, (*(char *)v.i == FILL), "9876", "%*2d", v.i);

    return 0;
}
