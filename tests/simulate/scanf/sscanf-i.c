/* Test of scanf(): 'i' conversion directive.
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
    unsigned int i[8];
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

#define	PVEC(args...)	({ static int __x[] PROGMEM = {args}; __x; })

int main ()
{
    /* Simplest.	*/
    CHECK (1, (v.i[0] == 0), "0", "%i", v.i);
    CHECK (1, (v.i[0] == 0), "+0", "%i", v.i);
    CHECK (1, (v.i[0] == 0), "-0", "%i", v.i);
    CHECK (1, (v.i[0] == 1), "1", "%i", v.i);

    /* Decimal.	*/
    CHECK (
	5,
	!memcmp_P (v.i, PVEC(1234, 5678, -90, 0, 1234), 5 * sizeof(int)),
	"1234 5678 -90 0A 1234f",
	"%i %i %i %i%*s %i",
	v.i, v.i + 1, v.i + 2, v.i + 3, v.i + 4);

    /* Octal.	*/
    CHECK (
	4,
	!memcmp_P (v.i, PVEC(01234, 06700, 0, 01234), 4 * sizeof(int)),
	"01234 06700 08 012349",
	"%i %i %i%*s %i",
	v.i, v.i + 1, v.i + 2, v.i + 3);

    /* Hexidecimal.	*/
    CHECK (
	5,
	!memcmp_P (v.i, PVEC(0x1234,0x5678,0x9ABC,0xDEF0,0), 5 * sizeof(int)),
	"0x1234 0X5678 0x9ABc 0XDEF0 0x",
	"%i %i %i %i %i",
	v.i, v.i + 1, v.i + 2, v.i + 3, v.i + 4);

    return 0;
}
