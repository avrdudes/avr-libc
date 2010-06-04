/* Copyright (c) 2010  Joerg Wunsch
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

/* $Id$ */

/* Basic realloc() test: ensure the realloc'ed area's initial
   contents matches the previously malloc'ed one. */

#ifndef	__AVR__

/* There is no sense to check on host computer. */
int main ()
{
    return 0;
}

#else

#include <stdint.h>
#include <stdlib.h>

struct __freelist {
        size_t sz;
        struct __freelist *nx;
};

extern char *__brkval;          /* first location not yet allocated */
extern struct __freelist *__flp; /* freelist pointer (head of freelist) */
extern char *__malloc_heap_start;
extern char *__malloc_heap_end;

int main(void)
{
    /* allocate first chunk; expected to work */
    uint8_t *p = malloc(42);
    if (p == NULL) return __LINE__;

    /* allocate second chunk; also expected to work */
    void *q = malloc(23);
    if (q == NULL) return __LINE__;

    /* fill some data into first chunk */
    uint8_t i;
    for (i = 0; i < 42; i++)
        p[i] = i ^ 0x42;

    /* extend first chunk; expected to work but expected to go into a
       different location than the initial allocation */
    uint8_t *r = realloc(p, 142);
    if (r == NULL) return __LINE__;
    if (r == p) return __LINE__;

    /* verify contents */
    for (i = 0; i < 42; i++)
        if (r[i] != (i ^ 0x42)) return __LINE__;

    return 0;
}

#endif  /* !AVR */
