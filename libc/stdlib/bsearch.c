/*
 * Copyright (c) 1990, 1993
 *	The Regents of the University of California.  All rights reserved.
 * Copyright (c) 2025  Georg-Johann Lay
 *
 * Redistribution and use in source and binary forms, with or without
 * modification, are permitted provided that the following conditions
 * are met:
 * 1. Redistributions of source code must retain the above copyright
 *    notice, this list of conditions and the following disclaimer.
 * 2. Redistributions in binary form must reproduce the above copyright
 *    notice, this list of conditions and the following disclaimer in the
 *    documentation and/or other materials provided with the distribution.
 * 3. Neither the name of the University nor the names of its contributors
 *    may be used to endorse or promote products derived from this software
 *    without specific prior written permission.
 *
 * THIS SOFTWARE IS PROVIDED BY THE REGENTS AND CONTRIBUTORS ``AS IS'' AND
 * ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE
 * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE
 * ARE DISCLAIMED.  IN NO EVENT SHALL THE REGENTS OR CONTRIBUTORS BE LIABLE
 * FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL
 * DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS
 * OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)
 * HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT
 * LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY
 * OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF
 * SUCH DAMAGE. */

#if defined(LIBC_SCCS) && !defined(lint)
static char sccsid[] = "@(#)bsearch.c	8.1 (Berkeley) 6/4/93";
#endif /* LIBC_SCCS and not lint */

#include <stddef.h>
#include <stdlib.h>
#include "sectionname.h"

/* Perform a binary search.
   The code below is a bit sneaky.  After a comparison fails, we divide the
   work in half by moving either left or right. If N is odd, moving left simply
   involves halving N: e.g., when N is 5 we look at item 2, so we change N
   to 2 so that we will look at items 0 & 1.  If N is even, the same applies.
   - If N is odd, moving right again involes halving N, this time moving the
     base up one item past p: e.g., when N is 5 we change base to item 3 and
     make N 2 so that we will look at items 3 and 4.
   - If N is even, however, we have to shrink it by one before halving: e.g.,
     when N is 4, we still looked at item 2, so we have to make N 3, then
     halve, obtaining 1, so that we will only look at item 3.
*/
ATTRIBUTE_CLIB_SECTION
void *
bsearch (const void *key, const void *base, size_t n,
         size_t size, __compar_fn_t compar)
{
#ifdef __AVR_HAVE_MUL__
    // The MUL timings of the two implementations are not very conclusive,
    // with a small edge for doing the multiplication in the loop.

    for (; n != 0; n >>= 1)
    {
        const char *p = (const char*) base + (n >> 1) * size;
        const int cmp = compar (key, p);

        if (cmp == 0)
            return (void*) p;
        else if (cmp > 0)
        {
            // key > p: use the chunk right of p.
            base = p + size;
            n--;
        }
        // else: use the chunk left of p.
    }
#else
    // Without MUL, we are clearly better off performing the
    // multiplication before the loop.

    for (size_t off = n * size; n != 0; n >>= 1)
    {
        // Calculate off = (n >> 1) * size, but without MUL.
        if (n & 1)
            off -= size;
        off >>= 1;

        const char *p = (const char*) base + off;
        const int cmp = compar (key, p);

        if (cmp == 0)
            return (void*) p;
        else if (cmp > 0)
        {
            // key > p: use the chunk right of p.
            base = p + size;
            n--;
            // Additional adjust to off is required when n was even.
            if (n & 1)
                off -= size;
        }
        // else: use the chunk left of p.
    }
#endif

    return NULL;
}
