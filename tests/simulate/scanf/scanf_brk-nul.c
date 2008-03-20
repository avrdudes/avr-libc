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
# if defined(__AVR_ATmega128__)
  /* ATmega128 has enough RAM for sprintf(), print to 0x2000 in XRAM. */
#  define PRINTF(f...)	sprintf((char *)0x2000, f)
# else
  /* small AVR */
#  define PRINTF(f...)
# endif
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
    char s[8];
    char t[8];
} v = { {1}, {1} };

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

    /* %[	*/
    memset (&v, ~0, sizeof(v));
    fp = uopen (PSTR ("A\000BC"), 4);
    i = fscanf (fp, "%[A-Z]%s", v.s, v.t);
    ASSERT (i == 2);
    ASSERT (!memcmp_P (v.s, PSTR("A"), 2));
    ASSERT (!memcmp_P (v.t, PSTR("\000BC"), 4));

    /* %[^	*/
    memset (&v, ~0, sizeof(v));
    fp = uopen (PSTR ("D\000EF"), 4);
    vrslt = fscanf (fp, "%[^F]%s", v.s, v.t);
    ASSERT (vrslt == 2);
    ASSERT (!memcmp_P (v.s, PSTR("D\000E"), 4));
    ASSERT (!memcmp_P (v.t, PSTR("F"), 2));

    return 0;
}
