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

/* bug #27235: malloc: Several things go wrong

   Part 1: empty gaps result out of reallocing towards a shorter
   amount, and mallocing on top of that. */

#ifndef	__AVR__

/* There is no sense to check on host computer. */
int main ()
{
    return 0;
}

#else

#include <stdlib.h>

struct __freelist {
        size_t sz;
        struct __freelist *nx;
};

extern char *__brkval;          /* first location not yet allocated */
extern struct __freelist *__flp; /* freelist pointer (head of freelist) */

int main(void)
{
    void *a, *b;

    a = malloc(34);
    a = realloc(a, 10);
    b = malloc(34);

    /* a and b are now expected to be adjacent, and the free list
       must be zero */

    if ((unsigned int)b - (unsigned int)a != 10 + 2) return __LINE__;
    if (__flp != NULL) return __LINE__;

    return 0;
}

#endif  /* !AVR */
