/*-
 * Copyright (c) 1992, 1993
 *	The Regents of the University of California.  All rights reserved.
 * Copyright (c) 2025 Georg-Johann Lay (rewrite from scratch avoiding fprintf)
 *
 * Redistribution and use in source and binary forms, with or without
 * modification, are permitted provided that the following conditions
 * are met:
 * *  Redistributions of source code must retain the above copyright
 *    notice, this list of conditions and the following disclaimer.
 * *  Redistributions in binary form must reproduce the above copyright
 *    notice, this list of conditions and the following disclaimer in the
 *    documentation and/or other materials provided with the distribution.
 * *  Neither the name of the University nor the names of its contributors
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
static char sccsid[] = "@(#)assert.c	8.1 (Berkeley) 6/4/93";
#endif /* LIBC_SCCS and not lint */

#include <assert.h>
#include <stdio.h>
#include <stdlib.h>
#include <bits/best_as.h>
#include "sectionname.h"

/* Print a message with operands to stderr. */
ATTRIBUTE_CLIB_SECTION
static void
err_msg (const __BEST_AS char *fmt,
         const char *v1, const char *v2, const char *v3, unsigned v4)
{
    while (1)
    {
        char c = *fmt++;

        if (c == '\0')
            return;
        else if (c == '1')
            fputs (v1, stderr);
        else if (c == '2')
            fputs (v2, stderr);
        else if (c == '3')
            fputs (v3, stderr);
        else if (c == '4')
        {
            char s_num[6];
            fputs (utoa (v4, s_num, 10), stderr);
        }
        else
            fputc (c, stderr);
    }
}

ATTRIBUTE_CLIB_SECTION
void
__assert (const char *func, const char *file, int line, const char *failedexpr)
{
    static const __BEST_AS char s1[] = ("Assertion failed: (1),"
                                        " file 3, line 4.\n");
    static const __BEST_AS char s2[] = ("Assertion failed: (1), function 2,"
                                        " file 3, line 4.\n");

    err_msg (func ? s2 : s1, failedexpr, func, file, (unsigned) line);

    abort();
    /* NOTREACHED */
}
