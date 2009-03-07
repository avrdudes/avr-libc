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

/* Test of setjmp()/longjmp() functions: jmp_buf bounds.
   $Id$	*/

#include <stdlib.h>
#include <setjmp.h>

struct {
    char beg[16];
    jmp_buf env;
    char end[16];
} buf;

volatile int one = 1;		/* to suppress optimization	*/

void foo (void)
{
    longjmp (buf.env, one);
}

int main ()
{
    volatile unsigned char fill = 0;
    void * volatile p;		/* Avr-gcc >= 4.1.2 outputs incorrect
				    warning without 'volatile'.	*/

    do {
	/* filling	*/
	for (p = &buf; p != (void *)&buf + sizeof (buf); p++)
	    *(char *)p = fill;

	/* buf.env usage	*/
	switch (setjmp (buf.env)) {
	    case 1:
		break;
	    case 0:
		foo ();
	    default:
		exit (__LINE__);
	}
	
	/* checking	*/
	for (p = &buf; p != (void *)&buf + sizeof (buf); p++) {
	    if (*(unsigned char *)p != fill
		&& (p < (void *)&buf.env
		    || p >= (void *)&buf.env + sizeof(buf.env)))
	    {
		exit (__LINE__);
	    }
	}
    } while (++fill);
    
    return 0;
}
