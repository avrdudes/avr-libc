/*
 * Copyright (c) 1998 Todd C. Miller <Todd.Miller@courtesan.com>
 * Copyright (c) 2009 Dmitry Xmelkov
 * All rights reserved.
 *
 * Redistribution and use in source and binary forms, with or without
 * modification, are permitted provided that the following conditions
 * are met:
 * 1. Redistributions of source code must retain the above copyright
 *    notice, this list of conditions and the following disclaimer.
 * 2. Redistributions in binary form must reproduce the above copyright
 *    notice, this list of conditions and the following disclaimer in the
 *    documentation and/or other materials provided with the distribution.
 * 3. The name of the author may not be used to endorse or promote products
 *    derived from this software without specific prior written permission.
 *
 * THIS SOFTWARE IS PROVIDED ``AS IS'' AND ANY EXPRESS OR IMPLIED WARRANTIES,
 * INCLUDING, BUT NOT LIMITED TO, THE IMPLIED WARRANTIES OF MERCHANTABILITY
 * AND FITNESS FOR A PARTICULAR PURPOSE ARE DISCLAIMED.  IN NO EVENT SHALL
 * THE AUTHOR BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL,
 * EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT LIMITED TO,
 * PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, DATA, OR PROFITS;
 * OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY,
 * WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR
 * OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF THIS SOFTWARE, EVEN IF
 * ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
 */

/* Test of strlcpy(). The program includes the strlcpy() function copy
   for testing themselves.
   $Id$
 */

#include <stdlib.h>
#include <string.h>
#include "progmem.h"

#ifndef __AVR__
# include <stdio.h>
# define PRINTFLN(line, fmt, ...)	\
    printf("\nLine %d: " fmt "\n", line, ##__VA_ARGS__)
# define EXIT(code)	exit ((code) < 255 ? (code) : 255)
#else
# define PRINTFLN(line, fmt, ...)
# define EXIT	exit
#endif

#ifndef	__AVR__
/*
 * Copy src to string dst of size siz.  At most siz-1 characters
 * will be copied.  Always NUL terminates (unless siz == 0).
 * Returns strlen(src); if retval >= siz, truncation occurred.
 */
size_t strlcpy (char *dst, const char *src, size_t siz)
{
        register char *d = dst;
        register const char *s = src;
        register size_t n = siz;

        /* Copy as many bytes as will fit */
        if (n != 0 && --n != 0) {
                do {
                        if ((*d++ = *s++) == 0)
                                break;
                } while (--n != 0);
        }

        /* Not enough room in dst, add NUL and traverse rest of src */
        if (n == 0) {
                if (siz != 0)
                        *d = '\0';                /* NUL-terminate dst */
                while (*s++)
                        ;
        }

        return(s - src - 1);        /* count does not include NUL */
}
#endif	/* !__AVR__ */


void
Check (int line, const char *src, size_t size, const char *result)
{
    char dst[(size < strlen_P (src) ? size : strlen_P (src)) + 1];
    char tmpsrc[strlen_P (src) + 1];
    size_t n;

    strcpy_P (tmpsrc, src);

    /* fill dst[]	*/
    for (n = 0; n < sizeof (dst); n++)
	dst[n] = line + n;


    n = strlcpy (dst, tmpsrc, size);
    if (n != strlen_P (src)) {
	PRINTFLN (line, "wrong return value: %zu", n);
	EXIT (line);
    }

    if (!size && ((dst[0] - line) & 0xFF)) {
	PRINTFLN (line, "dst is changed with 0 size");
	EXIT (1000 + line);
    }
    if (size && strcmp_P (dst, result) != 0) {
	PRINTFLN (line, "wrong result: %s", dst);
	EXIT (2000 + line);
    }
}


#define CHECK(src, size, result)				\
    do {							\
	Check (__LINE__, PSTR (src), size, PSTR (result));	\
    } while (0)


int main ()
{
    CHECK ("", 0, "");
    CHECK ("", 1, "");
    CHECK ("", 65535, "");

    CHECK ("A", 0, "");
    CHECK ("A", 1, "");
    CHECK ("A", 2, "A");
    CHECK ("A", 65535, "A");

    CHECK ("ab", 0, "");
    CHECK ("ab", 1, "");
    CHECK ("ab", 2, "a");
    CHECK ("ab", 3, "ab");
    CHECK ("ab", 4, "ab");

    CHECK ("The quick brown fox", 50, "The quick brown fox");
    CHECK ("The quick brown fox", 8, "The qui");

    CHECK ("................................................................"
	   "................................................................"
	   "................................................................"
	   "...............................................................",
	   2, ".");	/* 255	*/
    CHECK ("................................................................"
	   "................................................................"
	   "................................................................"
	   "................................................................",
	   2, ".");	/* 256	*/
    CHECK ("................................................................"
	   "................................................................"
	   "................................................................"
	   ".................................................................",
	   2, ".");	/* 257	*/

#if	!defined (RAMEND) || RAMEND > 0x400
    /* strlen(src) == 255	*/
    CHECK ("................................................................"
	   "................................................................"
	   "................................................................"
	   "..............................................................1",
	   258,
	   "................................................................"
	   "................................................................"
	   "................................................................"
	   "..............................................................1");

    /* strlen(src) == 256	*/
    CHECK ("................................................................"
	   "................................................................"
	   "................................................................"
	   "...............................................................2",
	   258,
	   "................................................................"
	   "................................................................"
	   "................................................................"
	   "...............................................................2");

    /* strlen(src) == 257	*/
    CHECK ("................................................................"
	   "................................................................"
	   "................................................................"
	   "................................................................3",
	   258,
	   "................................................................"
	   "................................................................"
	   "................................................................"
	   "................................................................3");

    /* strlen(src) == 258	*/
    CHECK ("................................................................"
	   "................................................................"
	   "................................................................"
	   ".................................................................4",
	   258,
	   "................................................................"
	   "................................................................"
	   "................................................................"
	   ".................................................................");
#endif

    return 0;
}
