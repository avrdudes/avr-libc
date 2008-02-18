/* Test of scanf(): NUL symbol (input file).
   $Id$	*/

#define _GNU_SOURCE
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
# define ssize_t	int
#else
# include <assert.h>
# define ASSERT(expr)	assert (expr)
# define EXIT(v)	exit ((v) < 256 ? (v) : 255)
# define PRINTF(f...)	printf (f)
# define sscanf_P	sscanf
# define memcmp_P	memcmp
# define _FDEV_EOF	(-1)
#endif

/* Next variables are useful to debug the AVR.	*/
int vrslt = 1;
struct {
    int i;
    int j;
    char s[8];
    char t[8];
} v = { 1, 1, {1}, {1} };

const char *getpnt, *getend;

int ugetc (FILE *fp)
{
    (void)fp;
    if (getpnt == getend)
	return _FDEV_EOF;
    return pgm_read_byte (getpnt++);
}

ssize_t uread (void *cookie, char *buf, size_t size)
{
    size_t n;

    for (n = 0; n < size; n++) {
	int i = ugetc (cookie);
	if (i < 0) break;
	*buf++ = i;
    }
    return n;
}

int uclose (void *cookie)
{
    (void)cookie;
    return 0;
}

static FILE * uopen (const char *buf, int size)
{
    static FILE *fp;

    if (fp) fclose (fp);

#ifdef	__AVR__
    fp = fdevopen (0, ugetc);
#else
    {
        cookie_io_functions_t iofuns;
	memset (& iofuns, 0, sizeof(iofuns));
        iofuns.read = uread;
	iofuns.close = uclose;
        fp = fopencookie (NULL, "rb", iofuns);
    }
#endif
    ASSERT (fp);

    getpnt = buf;
    getend = buf + size;
    return fp;
}

int main ()
{
    FILE *fp;
    int i;

    /* %c	*/
    memset (&v, ~0, sizeof(v));
    fp = uopen (PSTR ("A\000B"), 3);
    vrslt = fscanf (fp, "%c%c%c", v.s, v.s + 1, v.s + 2);
    ASSERT (vrslt == 3);
    ASSERT (!memcmp_P (v.s, PSTR("A\000B"), 3));

    /* '\0' is not a space.	*/
    memset (&v, ~0, sizeof(v));
    fp = uopen (PSTR ("\t \000"), 3);
    i = fscanf (fp, " %c", v.s);
    ASSERT (i == 1);
    ASSERT (!v.s[0]);

    /* %d	*/
    memset (&v, ~0, sizeof(v));
    fp = uopen (PSTR ("123\000456"), 7);
    i = fscanf (fp, "%d%c%d", & v.i, v.s, & v.j);
    ASSERT (i == 3);
    ASSERT (v.i == 123 && !v.s[0] && v.j == 456);

    /* %s	*/
    memset (&v, ~0, sizeof(v));
    fp = uopen (PSTR ("A\000BC"), 4);
    i = fscanf (fp, "%s%s", v.s, v.t);
    ASSERT (i == 1);
    ASSERT (!memcmp_P (v.s, PSTR("A\000BC"), 4));

    return 0;
}
