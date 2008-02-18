/* Test of scanf(): float conversion.
   $Id$	*/

#include <math.h>
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
    float x[7];
    char c[7];
} v = { {1.0}, {1} };

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
	char str_s[sizeof(str)];					\
	char fmt_s[sizeof(fmt_p)];					\
	char FILL;							\
	int i;								\
	int (* volatile vp)(const char *, const char *, ...);		\
									\
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
    /* No valid digits.	*/
    CHECK (0, 1, ". ", "%e", & v.x[0]);
    CHECK (0, 1, "+ ", "%e", & v.x[0]);
    CHECK (0, 1, "- ", "%e", & v.x[0]);
    CHECK (0, 1, "E ", "%e", & v.x[0]);
    CHECK (0, 1, "+-123", "%e", & v.x[0]);
    CHECK (0, 1, "-+123", "%e", & v.x[0]);
    CHECK (0, 1, ".-123", "%e", & v.x[0]);
    CHECK (0, 1, ".+123", "%e", & v.x[0]);
    CHECK (0, 1, "e12", "%e", & v.x[0]);
    CHECK (0, 1, "- 1", "%e", & v.x[0]);
    CHECK (0, 1, "IN ", "%e", & v.x[0]);
    CHECK (0, 1, "NA ", "%e", & v.x[0]);
    CHECK (0, 1, "infinit ", "%e", & v.x[0]);

    /* NaN	*/
    CHECK (
	6,
	isnan(v.x[0]) && isnan(v.x[1]) && isnan(v.x[2])
	&& isnan(v.x[3]) && isnan(v.x[4]) && isnan(v.x[5]),
	"nan NAN NaN -nan +NAN -nAn",
	"%E %e %F %f %G %g",
	& v.x[0], & v.x[1], & v.x[2], & v.x[3], & v.x[4], & v.x[5]);

    /* Character after NaN.	*/
    CHECK (
	10,
	isnan(v.x[0]) && v.c[0] == '.'
	&& isnan(v.x[1]) && v.c[1] == '+'
	&& isnan(v.x[2]) && v.c[2] == 'e'
	&& isnan(v.x[3]) && v.c[3] == 'Q'
	&& isnan(v.x[4])
	&& isnan(v.x[5]),
	"nan. nan+ nane NANQ nannan",
	"%e%c %e%c %e%c %e%c %e %e",
	& v.x[0], & v.c[0], & v.x[1], & v.c[1],	& v.x[2], & v.c[2],
	& v.x[3], & v.c[3], & v.x[4], & v.x[5]);
	
    /* Inf	*/
    CHECK (
	6,
	v.x[0] == INFINITY && v.x[1] == INFINITY
	&& v.x[2] == INFINITY && v.x[3] == INFINITY
	&& v.x[4] == -INFINITY && v.x[5] == -INFINITY,
	"INF inf +Inf INFINITY -infinity -InFiNiTy",
	"%e %E %f %F %g %G",
	& v.x[0], & v.x[1], & v.x[2], & v.x[3], & v.x[4], & v.x[5]);

    /* Character after Inf.	*/
    CHECK (
	9,
	v.x[0] == INFINITY && v.c[0] == ' '
	&& v.x[1] == INFINITY
	&& v.x[2] == INFINITY && v.c[2] == 's'
	&& v.x[3] == INFINITY && v.c[3] == '\b'
	&& v.x[4] == INFINITY && v.x[5] == -INFINITY,
	"inf infinityinfinitys INF\b inf-inf",
	"%e%c %e%e%c %e%c %e%e",
	& v.x[0], & v.c[0],
	& v.x[1],
	& v.x[2], & v.c[2],
	& v.x[3], & v.c[3],
	& v.x[4], & v.x[5]);

    return 0;
}
