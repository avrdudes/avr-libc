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

/* With printf.
   $Id$
 */
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "strtol.h"

int main ()
{
    char s[16];
    long x;
    
    for (x = 0; x <= 100; x++) {
	sprintf(s, "%ld", x);
	if (t_strtol(s, 0, x, 0, strlen(s)))
	    exit(__LINE__);
	sprintf(s, "%lx", x);
	if (t_strtol(s, 16, x, 0, strlen(s)))
	    exit(__LINE__);
	sprintf(s, "%lo", x);
	if (t_strtol(s, 8, x, 0, strlen(s)))
	    exit(__LINE__);
    }
    
    for (x = 0; x >= -100; x--) {
	sprintf(s, "%ld", x);
	if (t_strtol(s, 0, x, 0, strlen(s)))
	    exit(__LINE__);
	sprintf(s, "-%lx", -x);
	if (t_strtol(s, 16, x, 0, strlen(s)))
	    exit(__LINE__);
	sprintf(s, "-%lo", -x);
	if (t_strtol(s, 8, x, 0, strlen(s)))
	    exit(__LINE__);
    }
    
    for (x = LONG_MAX; x >= LONG_MAX - 100; x--) {
	sprintf(s, "%ld", x);
	if (t_strtol(s, 0, x, 0, strlen(s)))
	    exit(__LINE__);
	sprintf(s, "%lx", x);
	if (t_strtol(s, 16, x, 0, strlen(s)))
	    exit(__LINE__);
	sprintf(s, "%lo", x);
	if (t_strtol(s, 8, x, 0, strlen(s)))
	    exit(__LINE__);
    }
    
    for (x = LONG_MIN; x <= LONG_MIN + 100; x++) {
	sprintf(s, "%ld", x);
	if (t_strtol(s, 0, x, 0, strlen(s)))
	    exit(__LINE__);
	sprintf(s, "-%lx", -x);
	if (t_strtol(s, 16, x, 0, strlen(s)))
	    exit(__LINE__);
	sprintf(s, "-%lo", -x);
	if (t_strtol(s, 8, x, 0, strlen(s)))
	    exit(__LINE__);
    }
    
    for (x = 1; x <= 300; x++) {
	sprintf(s, "8%07lx", x);
	if (t_strtol(s, 16, 0x7fffffff, ERANGE, strlen(s)))
	    exit(__LINE__);
	sprintf(s, "-8%07lx", x);
	if (t_strtol(s, 16, 0x80000000, ERANGE, strlen(s)))
	    exit(__LINE__);
    }

    return 0;
}
