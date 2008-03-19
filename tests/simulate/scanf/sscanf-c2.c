/* Test of scanf(): 'c' conversion directive.
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
    char s[12];
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
    /* Zero width.	*/
#ifdef	__AVR__
    CHECK (0, (v.s[0] == FILL), "A", "%0c", v.s);
#else
    CHECK (1, (v.s[0] == 'A'), "A", "%0c", v.s);
#endif

    /* Left width digit is 0.	*/
    CHECK (1, (v.s[0] == 'A'), "A", "%01c", v.s);
    CHECK (1, !memcmp_P(v.s, PSTR("AB"), 2), "AB", "%02c", v.s);

    /* Invalid symbol after '%'.	*/
    CHECK (0, (v.s[0] == FILL), "A", "% c", v.s);
    CHECK (0, (v.s[0] == FILL), "A", "%-c", v.s);
    CHECK (0, (v.s[0] == FILL), "A", "%+c", v.s);
    CHECK (0, (v.s[0] == FILL), "A", "%.c", v.s);
    CHECK (0, (v.s[0] == FILL), "A", "%#c", v.s);

    /* The length modifier.	*/
    CHECK (1, (v.s[0] == 'A' && v.s[1] == FILL), "A", "%hc", v.s);
#ifdef	__AVR__
    CHECK (1, (v.s[0] == 'A' && v.s[1] == FILL), "A", "%lc", v.s);
#else
    CHECK (1, (v.s[0] == 'A' && v.s[1] == 0), "A", "%lc", v.s);
#endif

    return 0;
}
