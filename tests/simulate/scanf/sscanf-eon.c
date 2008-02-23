/* Test of scanf(): end of number (integral).
   $Id$	*/

#include <ctype.h>
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
    int i[3];
    unsigned char s[3];
} v = { {1}, {1} };

int main ()
{
    char s[16];
    unsigned char c;
    int n;

    /* Decimal.	*/
    for (c = 255; c; c--) {
	if (isdigit (c))
	    continue;
	strcpy_P (s, PSTR("0.1.29."));
	s[1] = s[3] = s[6] = c;
	memset (&v, ~0, sizeof(v));
	n = sscanf (s, "%d%c%d%c%d%c",
		    v.i, v.s, v.i + 1, v.s + 1, v.i + 2, v.s + 2);
	ASSERT (n == 6);
	ASSERT (v.s[0] == c && v.s[1] == c && v.s[2] == c);
	ASSERT (v.i[0] == 0 && v.i[1] == 1 && v.i[2] == 29);
    }

    /* Octal.	*/
    for (c = 255; c; c--) {
	if (isdigit (c) && (c != '8') && (c != '9'))
	    continue;
	strcpy_P (s, PSTR("0.1.27."));
	s[1] = s[3] = s[6] = c;
	memset (&v, ~0, sizeof(v));
	n = sscanf (s, "%o%c%o%c%o%c",
		    v.i, v.s, v.i + 1, v.s + 1, v.i + 2, v.s + 2);
	ASSERT (n == 6);
	ASSERT (v.s[0] == c && v.s[1] == c && v.s[2] == c);
	ASSERT (v.i[0] == 0 && v.i[1] == 1 && v.i[2] == 027);
    }

    /* Hexidecimal.	*/
    for (c = 255; c; c--) {
	if (isxdigit (c))
	    continue;
	strcpy_P (s, PSTR("F.1.20."));
	s[1] = s[3] = s[6] = c;
	memset (&v, ~0, sizeof(v));
	n = sscanf (s, "%x%c%x%c%x%c",
		    v.i, v.s, v.i + 1, v.s + 1, v.i + 2, v.s + 2);
	ASSERT (n == 6);
	ASSERT (v.s[0] == c && v.s[1] == c && v.s[2] == c);
	ASSERT (v.i[0] == 0xF && v.i[1] == 1 && v.i[2] == 0x20);
    }

    return 0;
}
