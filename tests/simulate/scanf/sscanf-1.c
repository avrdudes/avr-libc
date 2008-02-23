/* Test of scanf(): none conversion directives.
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
#endif

/* Next variables are useful to debug the AVR.	*/
int vrslt = 1;
struct {
    char b;
} v = { 1 };

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
    /* Empty format string.	*/
    CHECK (0, 1, "", "");
    CHECK (0, 1, " ", "");
    CHECK (0, 1, "1", "");
    CHECK (0, 1, "a\n", "");

    /* Format directive is white-space (i.e. isspace) symbol.	*/
    CHECK (0, 1, "", " ");
    CHECK (0, 1, "", "\t");
    CHECK (0, 1, "", "\n");
    CHECK (0, 1, "", "\r");
    CHECK (0, 1, "", "\f");
    CHECK (0, 1, "", "\v");
    CHECK (0, 1, "", " \t\n\v\f\r");

    /* Format directive is ordinary character, no input.	*/
    CHECK (-1, 1, "", "a");
    CHECK (-1, 1, "a", "aa");
    
    /* Format directive is ordinary character, input is match.	*/
    CHECK (0, 1, "a", "a");
    CHECK (0, 1, "\001", "\001");
    CHECK (0, 1, "\377", "\377");
    CHECK (0, 1, "The_quick_brown_fox", "The_quick_brown_fox");

    /* Format directive is ordinary character, input is't match.	*/
    CHECK (0, 1, "A", "a");
    CHECK (0, 1, " ", "a");
    CHECK (0, 1, "\001", "a");
    CHECK (0, 1, "\377", "a");

    CHECK (0, 1, "aA", "aa");
    CHECK (0, 1, "a ", "aa");
    CHECK (0, 1, "a\001", "AA");
    CHECK (0, 1, "a\377", "AA");
    
    CHECK (0, 1, ".", "aaaaaaaa");

    return 0;
}
