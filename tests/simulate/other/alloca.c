/* Copyright (c) 2007  Dmitry Xmelkov
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

#include <alloca.h>
#include <stdarg.h>
#include <stdlib.h>
#include <string.h>

#define elemof(v)	(sizeof(v) / sizeof((v)[0]))

/* A few of alloca() calls in the one function.	*/
void test_few_alloca (void)
{
    unsigned char *p[10];
    int i, n;

    /* Allocate and fill each block with sizes: 1 .. elemof(p)	*/
    for (n = 1; n < (int)elemof(p); n++) {
	p[n-1] = alloca (n);
	memset (p[n-1], n, n);
    }

    /* Check that there is no overlapping.	*/
    for (n = 1; n < (int)elemof(p); n++) {
	for (i = 0; i < n; i++)
	    if (p[n-1][i] != n)
		exit (__LINE__);
    }
}

/* Variable size array and alloca() together.	*/
void test_with_var_array (int n)
{
    unsigned char s[n];
    unsigned char *p;
    int i;

    /* Fill variable size array.	*/
    memset (s, 1, n);

    /* Allocate and fill the second array.	*/
    p = alloca (n);
    memset (p, 2, n);
    
    /* Refill the first array.	*/
    for (i = 0; i < n; i++) s[i] += 1;

    /* Check both.	*/
    if (memcmp (s, p, n))
	exit (__LINE__);
}

/* Increment the each element of buf[].
   The second argument is the number of elements.	*/
void inc_array (unsigned char *buf, ...)
{
    va_list ap;
    int n, i;
    
    va_start (ap, buf);
    n = va_arg (ap, int);
    va_end (ap);
    
    for (i = 0; i < n; i++) buf[i] += 1;
}

/* Check the compatibility with call of function, where arguments are
   allocated in the stack.	*/
void test_with_var_args (int n)
{
    unsigned char *p;
    int i;

    /* Allocate and fill.	*/
    p = alloca (n);
    memset (p, 1, n);

    /* Args are placed in stack.	*/
    inc_array (p, n);

    /* Check the result.	*/
    for (i = 0; i < n; i++) {
	if (p[i] != 2)
	    exit (__LINE__);
    }
}

int main ()
{
    test_few_alloca ();
    test_with_var_array (10);
    test_with_var_args (20);
    
    return 0;
}
