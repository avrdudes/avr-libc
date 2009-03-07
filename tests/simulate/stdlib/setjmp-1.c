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

/* Test of setjmp()/longjmp() functions: return value.
   $Id$	*/

#include <stdlib.h>
#include <setjmp.h>

jmp_buf env;

int main ()
{
    int (* volatile v_setjmp) (jmp_buf);
    void (* volatile v_longjmp) (jmp_buf, int);

    /* Return 0 from setjmp().	*/
    if (setjmp (env))
	exit (__LINE__);

    /* Pass value throw longjmp().	*/
    switch (setjmp (env)) {
	case 0:
	    longjmp (env, 12345);
	    exit (__LINE__);
	case 12345:
	    break;
	default:
	    exit (__LINE__);
    }

    /* Replace 0 arg of longjmp().	*/
    switch (setjmp (env)) {
	case 0:
	    longjmp (env, 0);
	    exit (__LINE__);
	case 1:
	    break;
	default:
	    exit (__LINE__);
    }

    /* Check -1 value.	*/
    switch (setjmp (env)) {
	case 0:
	    longjmp (env, -1);
	    exit (__LINE__);
	case -1:
	    break;
	default:
	    exit (__LINE__);
    }

    /* Repeat above with volatile function pointers: exclude
       posible compiler optimization.	*/
    v_setjmp = setjmp;
    v_longjmp = longjmp;

    if (v_setjmp (env))
	exit (__LINE__);

    switch (v_setjmp (env)) {
	case 0:
	    v_longjmp (env, 12345);
	    exit (__LINE__);
	case 12345:
	    break;
	default:
	    exit (__LINE__);
    }

    switch (v_setjmp (env)) {
	case 0:
	    v_longjmp (env, 0);
	    exit (__LINE__);
	case 1:
	    break;
	default:
	    exit (__LINE__);
    }
    
    switch (v_setjmp (env)) {
	case 0:
	    v_longjmp (env, -1);
	    exit (__LINE__);
	case -1:
	    break;
	default:
	    exit (__LINE__);
    }

    return 0;
}
