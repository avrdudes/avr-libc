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

/* bug #21955: pgm_read_xxxx() does not use enhanced LPM instruction
   $Id$

   Idea is to force 'region text is full': pgm_read_word() takes 5 words
   in case of classic LPM, and takes 2 words with enhanced LPM.	*/

#ifndef	__AVR__

/* There are not sense to check host computer.	*/
int main ()
{
    return 0;
}

#else

#include <avr/io.h>
#include <avr/pgmspace.h>

/* avr-gcc 4.1.2, Avr-libc 1.6.1, main() contains only 1 line with
   pgm_read_word, bytes:
      MIN_SIZE == 90  --> Fault
      MIN_SIZE == 100 --> OK
   So, for 50 lines it would:
      100 + 8*49 =  492  for enhanced
      100 + 14*49 = 786  for enhanced
   No use __AVR_HAVE_LPMX__ for preprocessing.	*/
#if  (__AVR_ARCH__ == 2) || (__AVR_ARCH__ == 3)
# define MIN_SIZE 940
#else
# define MIN_SIZE 640
#endif

#define NWORDS	((FLASHEND - _VECTORS_SIZE - MIN_SIZE)/2)
void very_big_function (void)
{
    asm volatile (
	".rept	(%0)*256 + %1	\n\t"
	"nop			\n\t"
	".endr "
	:: "M" (NWORDS / 256),
	   "M" (NWORDS % 256)
    );
}


/* ???: GCC 4.6.2 produces this warning about volatile (!) variable.	*/
#if	(__GNUC__ > 4 || (__GNUC__ == 4 && __GNUC_MINOR__ >= 6))
# pragma GCC diagnostic ignored "-Wunused-but-set-variable"
#endif


int main ()
{
    volatile int rslt;
    int addr = 0;

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

    rslt = (int)addr;
    return 0;
}

#endif	/* __AVR__ */
