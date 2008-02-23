/* Test of scanf(): 'h' type modifier.
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
    short i[10];
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
    CHECK (-1, (*(char *)v.i == FILL), "", "%hd", v.i);
    CHECK (-1, (*(char *)v.i == FILL), "", " %hd", v.i);
    CHECK (-1, (*(char *)v.i == FILL), " ", " %hd", v.i);
    CHECK (-1, (*(char *)v.i == FILL), " ", "  %hd", v.i);
    CHECK (-1, (*(char *)v.i == FILL), "\t\n\v\f\r", " %hd", v.i);

    /* All possible conversions.	*/
    CHECK (
	8,
	v.i[0] == 10 && v.i[1] == 20 && v.i[2] == 030 && v.i[3] == 040
	&& v.i[4] == 0x50 && v.i[5] == 0x60 && v.i[6] == 0x70 && v.i[7] == 22
	&& v.i[8] == 80,
	"10 20 030 40 50 60 70 80",
	"%hd %hu %hi %ho %hx %hX %hp %hn %hd",
	v.i + 0, v.i + 1, v.i + 2, v.i + 3,
	v.i + 4, v.i + 5, v.i + 6, v.i + 7,
	v.i + 8);

    /* Width field.	*/
    CHECK (
	1,
	v.i[0] == 12 && *(unsigned char *)(v.i + 1) == FILL,
	"123", "%2hd", v.i);
    CHECK (
	1,
	v.i[0] == 98 && *(unsigned char *)(v.i + 1) == FILL,
	"00000000009876", "%12hd", v.i);

    /* Suppress a writing.	*/
    CHECK (0, (*(unsigned char *)v.i == FILL), "123", "%*hd", v.i);
    CHECK (2, (v.i[0] == 1) && (v.i[1] == 3) && (*(char *)(v.i + 2) == FILL),
	   "1 2 3", "%hd%*hd%hd", v.i, v.i + 1);

    return 0;
}
