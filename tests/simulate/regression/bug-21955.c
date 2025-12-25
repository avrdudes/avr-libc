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
   POSSIBILITY OF SUCH DAMAGE. */

/* bug #21955: pgm_read_xxxx() does not use enhanced LPM instruction */

#ifndef	__AVR__

/* There are not sense to check host computer.	*/
int main ()
{
    return 0;
}

#else

#include <avr/io.h>
#include <avr/pgmspace.h>

extern int theSize[];

int use_pgm_read_word (unsigned addr)
{
    __asm volatile (".Lsize = ."
                    : "+r" (addr) :: "memory");

    /* 10*4 words with enhanced LPM
       10*7 words with classic LPM	*/
    addr = pgm_read_word (addr) & 0x7FF;
    addr = pgm_read_word (addr) & 0x7FF;
    addr = pgm_read_word (addr) & 0x7FF;
    addr = pgm_read_word (addr) & 0x7FF;
    addr = pgm_read_word (addr) & 0x7FF;
    addr = pgm_read_word (addr) & 0x7FF;
    addr = pgm_read_word (addr) & 0x7FF;
    addr = pgm_read_word (addr) & 0x7FF;
    addr = pgm_read_word (addr) & 0x7FF;
    addr = pgm_read_word (addr) & 0x7FF;		/* 10 */

    /* 10*4 words with enhanced LPM
       10*7 words with classic LPM	*/
    addr = pgm_read_word (addr) & 0x7FF;
    addr = pgm_read_word (addr) & 0x7FF;
    addr = pgm_read_word (addr) & 0x7FF;
    addr = pgm_read_word (addr) & 0x7FF;
    addr = pgm_read_word (addr) & 0x7FF;
    addr = pgm_read_word (addr) & 0x7FF;
    addr = pgm_read_word (addr) & 0x7FF;
    addr = pgm_read_word (addr) & 0x7FF;
    addr = pgm_read_word (addr) & 0x7FF;
    addr = pgm_read_word (addr) & 0x7FF;		/* 20 */

    /* 10*4 words with enhanced LPM
       10*7 words with classic LPM	*/
    addr = pgm_read_word (addr) & 0x7FF;
    addr = pgm_read_word (addr) & 0x7FF;
    addr = pgm_read_word (addr) & 0x7FF;
    addr = pgm_read_word (addr) & 0x7FF;
    addr = pgm_read_word (addr) & 0x7FF;
    addr = pgm_read_word (addr) & 0x7FF;
    addr = pgm_read_word (addr) & 0x7FF;
    addr = pgm_read_word (addr) & 0x7FF;
    addr = pgm_read_word (addr) & 0x7FF;
    addr = pgm_read_word (addr) & 0x7FF;		/* 30 */

    /* 10*4 words with enhanced LPM
       10*7 words with classic LPM	*/
    addr = pgm_read_word (addr) & 0x7FF;
    addr = pgm_read_word (addr) & 0x7FF;
    addr = pgm_read_word (addr) & 0x7FF;
    addr = pgm_read_word (addr) & 0x7FF;
    addr = pgm_read_word (addr) & 0x7FF;
    addr = pgm_read_word (addr) & 0x7FF;
    addr = pgm_read_word (addr) & 0x7FF;
    addr = pgm_read_word (addr) & 0x7FF;
    addr = pgm_read_word (addr) & 0x7FF;
    addr = pgm_read_word (addr) & 0x7FF;		/* 40 */

    /* 10*4 words with enhanced LPM
       10*7 words with classic LPM	*/
    addr = pgm_read_word (addr) & 0x7FF;
    addr = pgm_read_word (addr) & 0x7FF;
    addr = pgm_read_word (addr) & 0x7FF;
    addr = pgm_read_word (addr) & 0x7FF;
    addr = pgm_read_word (addr) & 0x7FF;
    addr = pgm_read_word (addr) & 0x7FF;
    addr = pgm_read_word (addr) & 0x7FF;
    addr = pgm_read_word (addr) & 0x7FF;
    addr = pgm_read_word (addr) & 0x7FF;
    addr = pgm_read_word (addr) & 0x7FF;		/* 50 */

    __asm volatile (".global theSize\n\t"
                    "theSize = . - .Lsize"
                    : "+r" (addr) :: "memory");
    return addr;
}

int main (void)
{
#ifdef __AVR_HAVE_LPMX__
    unsigned max_insns = 5;
#else
    unsigned max_insns = 8;
#endif

    if ((unsigned) theSize > 10 + 2 * 50 * max_insns)
        __builtin_exit (__LINE__);

    return 0;
}

#endif	/* __AVR__ */
