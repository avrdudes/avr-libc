/* Test of scanf(): 'x' conversion directive.
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
    char s[8];
} v = { {1}, {1} };

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
    /* Empty input.	*/
    CHECK (-1, (*(char *)v.i == FILL), "", "%x", v.i);
    CHECK (-1, (*(char *)v.i == FILL), "", " %x", v.i);
    CHECK (-1, (*(char *)v.i == FILL), " ", " %x", v.i);
    CHECK (-1, (*(char *)v.i == FILL), " ", "  %x", v.i);
    CHECK (-1, (*(char *)v.i == FILL), "\t\n\v\f\r", " %x", v.i);

    /* Normal conversion.	*/
    CHECK (1, (v.i[0] == 0), "0", "%x", v.i);
    CHECK (1, (v.i[0] == 0), "+0", "%x", v.i);
    CHECK (1, (v.i[0] == 0), "-0", "%x", v.i);
    CHECK (1, (v.i[0] == 1), "1", "%x", v.i);
    CHECK (1, (v.i[0] == 0x1234), "1234", "%x", v.i);
    CHECK (1, (v.i[0] == 0x5678), "5678", "%x", v.i);
    CHECK (1, (v.i[0] == 0x9ABC), "9ABC", "%x", v.i);
    CHECK (1, (v.i[0] == 0xDEF0), "DEF0", "%x", v.i);
    CHECK (1, (v.i[0] == 0xFFFF), "FFFF", "%x", v.i);
    CHECK (1, (v.i[0] == (unsigned)(-1)), "-1", "%x", v.i);
    CHECK (1, (v.i[0] == 1), "-FFFFFFFF", "%x", v.i);

    /* Low/upper characters.	*/
    CHECK (
	8,
	!memcmp_P (
	    v.i,
	    PVEC(0xABCD, 0xEF, 0xABCD, 0xEF, 0xABCD, 0xEF, 0xABCD, 0xEF),
	    8 * sizeof(int)),
	"abcd ef abcd ef ABCD EF AbCd eF",
	"%x %x %X %X %X %X %x %X",
	v.i + 0, v.i + 1,
	v.i + 2, v.i + 3,
	v.i + 4, v.i + 5,
	v.i + 6, v.i + 7);

    /* '%p' conversion.	*/
    CHECK (
	3,
	!memcmp_P (v.i, PVEC(0xABCD, -0x12EF, 0x10), 3 * sizeof(int)),
	"ABCD -12EF 0x10",
	"%p%p%p", v.i, v.i + 1, v.i + 2);

    /* Leading spaces.	*/
    CHECK (1, (v.i[0] == 0x12), " 12", "%x", v.i);
    CHECK (1, (v.i[0] == 0x123), "\t\n\v\f\r123", "%x", v.i);

    /* Leading '0'.	*/
    CHECK (1, (v.i[0] == 04567), "04567", "%o", v.i);
    CHECK (1, (v.i[0] == 07654), "00000000007654", "%o", v.i);

    /* Hex prefix.	*/
    CHECK (
	6, !memcmp_P (v.i, PVEC(1,2,3,4,0xA987,-0x100), 6 * sizeof(int)),
	"0x1 0X2 0x3 0X4 0xA987 -0x100",
	"%x%x%X%X%x%x",
	v.i + 0, v.i + 1,
	v.i + 2, v.i + 3,
	v.i + 4, v.i + 5);

    return 0;
}
