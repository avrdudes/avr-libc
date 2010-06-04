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

/* Allocate a bunch of things, and free them again.  At the end,
   the freelist is supposed to consist of a single entry. */

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

#if defined(__AVR_ATmega128__)
static const int sizes[8] =
{
    5, 8, 2, 122, 256, 1, 32, 25 /* 451 + 1 [padding] + 2 * 8 [ptrs] = 468 */
};
#define TARGETVAL 468
#elif defined(__AVR_AT90S8515__)
static const int sizes[8] =
{
    5, 8, 2, 22, 256, 1, 12, 25 /* 331 + 1 [padding] + 2 * 8 [ptrs] = 348 */
};
#define TARGETVAL 348
#else
#  error "Unknown MCU type"
#endif


int main(void)
{
    void *ptrs[8];
    uint8_t i;

    for (i = 0; i < 8; i++)
    {
        void *p = malloc(sizes[i]);
        /* first test: all allocations are supposed to fit */
        if (p == NULL) return __LINE__;
        ptrs[i] = p;
    }
    /* second test: the amount of memory allocated to the heap must
       match the expected TARGETVAL */
    if (__brkval - __malloc_heap_start != TARGETVAL) return __LINE__;

    for (i = 0; i < 8; i++)
    {
        free(ptrs[i]);
    }

    /* after freeing everything, the freelist must contain one
       chunk of the full TARGETVAL size (minus the size for one
       pointer), and the "nx" pointer must be NULL */
    if (__flp->nx != NULL) return __LINE__;
    if (__flp->sz != TARGETVAL - 2) return __LINE__;

    return 0;
}

#endif  /* !AVR */
