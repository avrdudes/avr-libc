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

/* Test of setjmp()/longjmp() functions: frame pointer restoring.
   $Id$	*/

#include <setjmp.h>
#include <stdlib.h>
#include <string.h>

jmp_buf env;

/* foo_jmp() use stack.	longjmp must restore frame pointer from env.	*/
void foo_jmp (const char *p)
{
    char s[16];
    strcpy (s, p);
    s[0] += 1;
    longjmp (env, strtol (s, 0, 0));
}

/* foo() use stack. If frame pointer would be scratch, return value
   (or all program) would be another.	*/
int foo (char *p)
{
    volatile char s[16];
    strcpy ((char *)s, p);
    switch (setjmp (env)) {
	case 0:     break;
	case 2:     return strtol ((const char *)s, 0, 0);
	default:    exit (__LINE__);
    }
    foo_jmp ("1");
    exit (__LINE__);
}

int main ()
{
    if (foo ("1234") != 1234)
	exit (__LINE__);
    if (foo ("4321") != 4321)
	exit (__LINE__);
    return 0;
}
