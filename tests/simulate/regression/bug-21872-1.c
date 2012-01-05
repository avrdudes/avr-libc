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

/* bug #21872: __floatunsisf/undisf incorrectly named
   $Id$

   Idea is to force 'region text is full' in case of libgcc's conversion
   function usage.	*/

#ifdef	__AVR__

#include <avr/io.h>

/* avr-gcc 4.2.2 + Avr-libc 1.6.1, before correction:
      MIN_SIZE == 1000 --> Fault
      MIN_SIZE == 1100 --> OK
   avr-gcc 4.2.2 + Avr-libc 1.6.1, after correction:
      MIN_SIZE == 220 --> Fault
      MIN_SIZE == 230 --> OK
   avr-gcc 4.1.2 + Avr-libc 1.6.1, after correction:
      MIN_SIZE == 650 --> Fault
      MIN_SIZE == 660 --> OK	*/
#if	(__GNUC__ == 4 && __GNUC_MINOR__ >= 2) || (__GNUC__ > 4)
# define MIN_SIZE 400
#else
# define MIN_SIZE 850
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

#endif

/* ???: GCC 4.6.2 produces this warning about volatile (!) variable.	*/
#if	(__GNUC__ > 4 || (__GNUC__ == 4 && __GNUC_MINOR__ >= 6))
# pragma GCC diagnostic ignored "-Wunused-but-set-variable"
#endif

int main ()
{
    volatile unsigned long vsi = 0;
    volatile float vsf;
    vsf = vsi;		/* call of conversion function	*/
    return 0;
}
