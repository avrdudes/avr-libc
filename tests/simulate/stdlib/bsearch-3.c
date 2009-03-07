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

/* Multibytes members.
   $Id$
 */

#include <stdlib.h>
#include <string.h>
#include <stdio.h>

size_t size;	/* to pass size of members	*/

int cmp (const void *p1, const void *p2)
{
    return memcmp(p1, p2, size);
}

int main ()
{
    char arr[100];
    size_t nmemb;
    int i;
    
    /* Filling of arr: 0,1,2...	*/
    for (i= 0; (size_t)i < sizeof(arr); i++)
	arr[i] = i;

    for (size= 1;  size <= sizeof(arr);  size++) {
	for (nmemb= 1;  nmemb <= sizeof(arr) / size;  nmemb++) {
	    /* scanning all keys	*/
	    for (i= 0;  (size_t)i <= sizeof(arr) - size;  i++) {
		if ((i % size) == 0 && (i / size) < nmemb) {
		    if (bsearch (arr + i, arr, nmemb, size, cmp) != arr + i) {
#ifndef	__AVR__
			printf ("size= %d  nmemb= %d  i= %d\n",
				size, nmemb, i );
#endif
			exit (__LINE__);
		    }
		} else {
		    if (bsearch (arr + i, arr, nmemb, size, cmp))
			exit (__LINE__);
		}
	    }
	}
    }
    return 0;
}
