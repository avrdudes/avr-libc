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

/* Simplest cases.
   $Id$
 */
#include <stdlib.h>

int cmp (const void *p1, const void *p2)
{
    return *(unsigned char *)p1 - *(unsigned char *)p2;
}

int main ()
{
    static unsigned char arr[100];
    unsigned char key;

    if (bsearch (arr, arr, 0, 1, cmp) != 0)
	exit (__LINE__);
    
    /* If element size equal to 0, Glibc and original bsearch
       return comparison result of first element.
       New bsearch do the same.	*/
    if (bsearch (arr, arr, sizeof(arr), 0, cmp) != arr)
	exit (__LINE__);
    key = 1;
    if (bsearch (& key, arr, sizeof(arr), 0, cmp) != 0)
	exit (__LINE__);
    
    /* key has address from arr	*/
    if (bsearch (arr, arr, 1, 1, cmp) != arr)
	exit (__LINE__);

    /* key has another address	*/
    key = arr[0];
    if (bsearch (& key, arr, 1, 1, cmp) != arr)
	exit (__LINE__);

    /* key > arr[0]	*/
    key = 1;
    if (bsearch (& key, arr, 1, 1, cmp) != 0)
	exit (__LINE__);

    /* key < arr[0]	*/
    arr[0] = 2;
    if (bsearch (& key, arr, 1, 1, cmp) != 0)
	exit (__LINE__);

    return 0;
}
