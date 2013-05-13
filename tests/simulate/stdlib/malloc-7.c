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

/* Freelist test #3: aggregation test. */

#ifndef	__AVR__

/* There is no sense to check on host computer. */
int main ()
{
    return 0;
}

#else

#include <stdint.h>
#include <stdlib.h>
#include <avr/cpufunc.h>

#include "../../libc/stdlib/stdlib_private.h"

int main(void)
{
    void *ptrs[6];
    uint8_t i;

    for (i = 0; i < 6; i++)
    {
        void *p = malloc(10);
        if (p == NULL) return __LINE__;
        ptrs[i] = p;
    }

    free(ptrs[5]);
    _MemoryBarrier();
    /* Freelist must be still empty, and __brkval reduced. */
    if (__flp != NULL) return __LINE__;
    if ((char *)(ptrs[5]) - 2 != __brkval) return __LINE__;

    free(ptrs[4]);
    _MemoryBarrier();
    /* Still no entry, and __brkval further down. */
    if (__flp != NULL) return __LINE__;
    if ((char *)(ptrs[4]) - 2 != __brkval) return __LINE__;

    struct __freelist *ofp = __flp;

    free(ptrs[1]);
    _MemoryBarrier();
    /* One entry added. */
    if ((char *)(ptrs[1]) - 2 != (void *)__flp) return __LINE__;
    if (__flp->sz != 10) return __LINE__;
    if (__flp->nx != (void *)ofp) return __LINE__;

    free(ptrs[3]);
    _MemoryBarrier();
    /* __brkval lowered again. */
    if (__flp->nx != NULL) return __LINE__;
    if ((char *)(ptrs[3]) - 2 != __brkval) return __LINE__;

    free(ptrs[2]);
    _MemoryBarrier();
    /* ...and again. */
    if (__flp->nx != NULL) return __LINE__;
    if ((char *)(ptrs[1]) - 2 != __brkval) return __LINE__;

    return 0;
}

#endif  /* !AVR */
