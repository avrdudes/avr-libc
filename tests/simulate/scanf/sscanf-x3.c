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
    /* Width field.	*/
    CHECK (1, (v.i[0] == 9), "9", "%1x", v.i);
    CHECK (1, (v.i[0] == 9), "98", "%1x", v.i);
    CHECK (1, (v.i[0] == 0xFE), "FEDC", "%2x", v.i);
    CHECK (2, (v.i[0] == 0x34) && (v.i[1] == 0x12),
	   "1234", "%2x%2x", v.i + 1, v.i);
    CHECK (1, (v.i[0] == 0x1234), "000000000012345", "%14x", v.i);
    CHECK (1, (v.i[0] == 0x1234), "0x0000000012345", "%14x", v.i);
    CHECK (1, (v.i[0] == 0), "01", "%1x", v.i);

    /* Width field and spaces.	*/
    CHECK (1, (v.i[0] == 0x12), " 12345", "%2x", v.i);
    CHECK (1, (v.i[0] == 0x12), " \t\n\v\f\r12345", "%2x", v.i);

    /* Width field and a sign.	*/
    CHECK (1, (v.i[0] == 0x12), "+12345", "%3x", v.i);
    CHECK (1, ((int)v.i[0] == -0x12), "-12345", "%3x", v.i);

    /* Width, space and sign.	*/
    CHECK (1, ((int)v.i[0] == -0x12), "  -12345", "%3x", v.i);

    /* Suppress and width.	*/
    CHECK (0, (*(char *)v.i == FILL), "9", "%*1x", v.i);
    CHECK (0, (*(char *)v.i == FILL), "9876", "%*2x", v.i);

    return 0;
}
