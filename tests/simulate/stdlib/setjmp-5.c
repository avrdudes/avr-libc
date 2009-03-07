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

/* Test of setjmp()/longjmp() functions: SREG restoring.
   $Id$	*/

#ifdef	__AVR__

#include <setjmp.h>
#include <stdlib.h>
#include <avr/io.h>

jmp_buf env;

int main ()
{
    SREG = 0;
    if (setjmp (env)) {
	if (SREG & (1 << SREG_I)) exit (__LINE__);
    } else {
	if (SREG & (1 << SREG_I)) exit (__LINE__);
	SREG = 0xff;
	longjmp (env, 1);
    }
    
    SREG = 0xff;
    if (setjmp (env)) {
	if ((SREG & (1 << SREG_I)) == 0) exit (__LINE__);
    } else {
	if ((SREG & (1 << SREG_I)) == 0) exit (__LINE__);
	SREG = 0;
	longjmp (env, 1);
    }
    return 0;
}

#else
int main ()	{ return 0; }
#endif
