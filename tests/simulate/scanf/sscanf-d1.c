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
    int i[5];
    char s[5];
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

int main ()
{
    /* Empty input.	*/
    CHECK (-1, (*(char *)v.i == FILL), "", "%d", v.i);
    CHECK (-1, (*(char *)v.i == FILL), "", " %d", v.i);
    CHECK (-1, (*(char *)v.i == FILL), " ", " %d", v.i);
    CHECK (-1, (*(char *)v.i == FILL), " ", "  %d", v.i);
    CHECK (-1, (*(char *)v.i == FILL), "\t\n\v\f\r", " %d", v.i);

    /* Normal conversion.	*/
    CHECK (1, (v.i[0] == 0), "0", "%d", v.i);
    CHECK (1, (v.i[0] == 0), "+0", "%d", v.i);
    CHECK (1, (v.i[0] == 0), "-0", "%d", v.i);
    CHECK (1, (v.i[0] == 1), "1", "%d", v.i);
    CHECK (1, (v.i[0] == 32767), "32767", "%d", v.i);
    CHECK (1, (v.i[0] == -1), "-1", "%d", v.i);
    CHECK (1, (v.i[0] == -32768), "-32768", "%d", v.i);
    CHECK (1, (v.i[0] == 12345), "+12345", "%d", v.i);
    CHECK (1, (v.i[0] == -6789), "-6789", "%d", v.i);

    /* '%u' conversion.	*/
    CHECK (
	3,
	!memcmp_P (
	    v.i,
	    ({ static int __x[3] PROGMEM = { 123, -456, 65535 }; __x; }),
	    3 * sizeof(int)),
	"123 -456 65535",
	"%u%u%u", v.i, v.i + 1, v.i + 2);

    /* Leading spaces.	*/
    CHECK (
	2,
	(v.i[0] == 12) && (v.i[1] == 123),
	" 12\t\n\v\f\r123",
	"%d%d", v.i, v.i + 1);

    /* End of number.	*/
    CHECK (2, v.i[0] == 0 && v.s[0] == 'x', "0x1", "%d%c", v.i, v.s);
    CHECK (
	10,
	!memcmp_P (
	    v.i,
	    ({ static int __x[5] PROGMEM = { 1, 2, 3, 4, 5 }; __x; }),
	    5 * sizeof(int))
	&& !memcmp_P (v.s, PSTR(" \n.\001\377"), 5),
	"1 2\n3.4\0015\3776",
	"%d%c%d%c%d%c%d%c%d%c",
	v.i + 0, v.s + 0,
	v.i + 1, v.s + 1,
	v.i + 2, v.s + 2,
	v.i + 3, v.s + 3,
	v.i + 4, v.s + 4);
    CHECK (
	3,
	v.i[0] == 6 && v.i[1] == -7 && v.i[2] == 8,
	"6-7+8",
	"%d%d%d",
	v.i, v.i + 1, v.i + 2);

    /* Non-decimal input.	*/
    CHECK (1, (v.i[0] == 10), "010", "%d", v.i);
    CHECK (1, (v.i[0] == 0), "0x10", "%d", v.i);
    CHECK (1, (v.i[0] == 10), "10e2", "%d", v.i);

    /* Suppress a writing.	*/
    CHECK (0, (*(char *)v.i == FILL), "123", "%*d", v.i);
    CHECK (2, (v.i[0] == 1) && (v.i[1] == 3),
	   "1 2 3", "%d%*d%d", v.i, v.i + 1);

    return 0;
}
