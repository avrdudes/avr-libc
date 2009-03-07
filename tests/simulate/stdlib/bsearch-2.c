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

/* Tests of branch logic. Number of probing is checked.
   $Id$
 */
#include <stdlib.h>

/* Calculate max number of compare function calls, depends of nmemb	*/
int max_calls (size_t nmemb)
{
    int n = 0;		/* result		*/
    size_t exp = 1;	/* margin: 1,2,4,8...	*/
    do {
	if (exp > nmemb) break;
	n += 1;
    } while (exp *= 2);
    return (n ? n : 1);
}

int cmp_calls;

int cmp (const void *p1, const void *p2)
{
    cmp_calls += 1;
    return *(unsigned char *)p1 - *(unsigned char *)p2;
}

int main ()
{
    unsigned char arr[33], key;
    size_t nmemb;
    int i;
    
    /* max_calls verify	*/
    if (   max_calls(1) != 1
	|| max_calls(2) != 2
	|| max_calls(3) != 2
	|| max_calls(7) != 3
	|| max_calls(8) != 4 ) exit (__LINE__);
    
    /* Filling of arr: 1,3,5...	*/
    for (i= 0; i < (int)sizeof(arr); i++)
	arr[i] = 1 + 2*i;

    for (nmemb= 1; nmemb <= sizeof(arr); nmemb++) {
    
	/* Non-existance keys:  arr[i] < key < arr[i+1]	*/
	for (i= 0; (size_t)i <= nmemb; i++) {
	    key = 2*i;
	    cmp_calls = 0;
	    if (bsearch (& key, arr, nmemb, 1, cmp) != 0)
		exit (__LINE__);
	    if (cmp_calls > max_calls(nmemb))
		exit (__LINE__);
	}
	
	/* All existance keys.	*/
	for (i= 0; (size_t)i < nmemb; i++) {
	    key = arr[i];
	    cmp_calls = 0;
	    if (bsearch (& key, arr, nmemb, 1, cmp) != arr + i)
		exit (__LINE__);
	    if (cmp_calls > max_calls(nmemb))
		exit (__LINE__);
	}

    }
    return 0;
}
