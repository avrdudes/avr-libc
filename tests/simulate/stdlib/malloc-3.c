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

/* Test heap restrictions implied by __malloc_margin. */

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
#define HEAP_START 0x200
#elif defined(__AVR_AT90S8515__)
#define HEAP_START 0x100
#else
#  error "Unknown MCU type"
#endif


int main(void)
{
    volatile void *dummy;

    __malloc_heap_start = (void *)HEAP_START;
    unsigned int bottom_of_stack = (unsigned int)&dummy;
    size_t s = bottom_of_stack - HEAP_START;

    /* try allocating everything from heap start through bottom
       of stack; expected to fail */
    void *p = malloc(s);
    if (p != NULL) return __LINE__;

    /* reduce by __malloc_margin's default value; still expected to
       fail*/
    s -= 32;
    p = malloc(s);
    if (p != NULL) return __LINE__;

    /* reduce by some more bytes (size of malloc()'s stack frame);
       expected to work */
    s -= 10;                    /* AVR-GCC 4.3.4: 8 bytes needed */
    p = malloc(s);
    if (p == NULL) return __LINE__;

    return 0;
}

#endif  /* !AVR */
