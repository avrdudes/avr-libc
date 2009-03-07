/* Copyright (c) 2008  Dmitry Xmelkov
   All rights reserved.

   Redistribution and use in source and binary forms, with or without
   modification, are permitted provided that the following conditions are met:

   * Redistributions of source code must retain the above copyright
     notice, this list of conditions and the following disclaimer.
   * Redistributions in binary form must reproduce the above copyright
     notice, this list of conditions and the following disclaimer in
     the documentation and/or other materials provided with the
     distribution.
   * Neither the name of the copyright holders nor the names of
     contributors may be used to endorse or promote products derived
     from this software without specific prior written permission.

   THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS "AS IS"
   AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE
   IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE
   ARE DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT OWNER OR CONTRIBUTORS BE
   LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR
   CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF
   SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS
   INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN
   CONTRACT, STRICT LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE)
   ARISING IN ANY WAY OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE
   POSSIBILITY OF SUCH DAMAGE.
 */

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
    float x,y;
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

    /* %e	*/
    memset (&v, ~0, sizeof(v));
    fp = uopen (PSTR ("1.0\0002e3"), 7);
    vrslt = fscanf (fp, "%e%c%e", & v.x, v.s, & v.y);
    ASSERT (vrslt == 3);
    ASSERT (v.x == 1.0 && !v.s[0] && v.y == 2e3);

    return 0;
}
