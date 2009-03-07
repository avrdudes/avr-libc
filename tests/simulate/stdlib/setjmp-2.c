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

/* Test of setjmp()/longjmp(): preservation call-saved registers.
   $Id$	*/

#include <stdlib.h>
#include <setjmp.h>

jmp_buf env;

/* foo2() uses (and destroys) call-saved registers. Complex return
   value is used to force allocate all variables.	*/
int foo2 (void)
{
    int v1, v2, v3, v4, v5, v6, v7, v8;
    
    srand (1);
    v1 = rand ();
    v2 = rand ();
    v3 = rand ();
    v4 = rand ();
    v5 = rand ();
    v6 = rand ();
    v7 = rand ();
    v8 = rand ();
    
    v1 *= rand ();
    v1 += v2 * rand ();
    v1 += v3 * rand ();
    v1 += v4 * rand ();
    v1 += v5 * rand ();
    v1 += v6 * rand ();
    v1 += v7 * rand ();
    v1 += v8 * rand ();
    
    while (!v1) v1 = rand ();
    
    longjmp (env, v1);
}

/* Recalculate result above.	*/
int calc (int initial)
{
    int v1, v2, v3, v4, v5, v6, v7, v8;
    
    srand (initial);
    v1 = rand ();
    v2 = rand ();
    v3 = rand ();
    v4 = rand ();
    v5 = rand ();
    v6 = rand ();
    v7 = rand ();
    v8 = rand ();
    
    v1 *= rand ();
    v1 += v2 * rand ();
    v1 += v3 * rand ();
    v1 += v4 * rand ();
    v1 += v5 * rand ();
    v1 += v6 * rand ();
    v1 += v7 * rand ();
    v1 += v8 * rand ();
    
    while (!v1) v1 = rand ();

    return v1;
}

/* foo1() does not use call-save registers.
   The setjmp() must do this.	*/
void foo1 (void)
{
    int x;

    if ( (x = setjmp (env)) != 0) {
	if (x != calc (1))
	    exit (__LINE__);
	return;
    }
    foo2 ();
    exit (__LINE__);
}

/* main() allocates many variables in call-saved registers.
 */
int main ()
{
    int v1, v2, v3, v4, v5, v6, v7, v8;

    srand (2);
    v1 = rand ();
    v2 = rand ();
    v3 = rand ();
    v4 = rand ();
    v5 = rand ();
    v6 = rand ();
    v7 = rand ();
    v8 = rand ();

    foo1 ();
    
    srand (2);
    if (   v1 != rand()
	|| v2 != rand()
	|| v3 != rand()
	|| v4 != rand()
	|| v5 != rand()
	|| v6 != rand()
	|| v7 != rand()
	|| v8 != rand())
    {
	exit (__LINE__);
    }
    
    return 0;
}
