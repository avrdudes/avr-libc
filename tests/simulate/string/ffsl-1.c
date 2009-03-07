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

/* $Id$	*/

#ifndef	__AVR__
# define _GNU_SOURCE
#endif
#include <stdlib.h>
#include <string.h>

int main ()
{
    static struct t_s {
	long val;
	unsigned char pattern;
    } t[] = {
	{ 0, 0 },
	{ 1, 1 },
	{ 0xffffffff, 1 },
	{ 0x00000002, 2 },
	{ 0x80000002, 2 },
	{ 0xfffffff2, 2 },
	{ 0x00000040, 7 },
	{ 0xffffff40, 7 },
	{ 0x00000080, 8 },
	{ 0xffffff80, 8 },

	{ 0x00000100, 9 },
	{ 0xffffff00, 9 },
	{ 0x00008000, 16 },
	{ 0xffff8000, 16 },
	
	{ 0x00010000, 17 },
	{ 0xffff0000, 17 },
	{ 0x00800000, 24 },
	{ 0xff800000, 24 },
	
	{ 0x01000000, 25 },
	{ 0xff000000, 25 },
	{ 0x80000000, 32 },
    };
    int i;
    
    for (i = 0; i != (int)(sizeof(t)/sizeof(t[0])); i++) {
	if (ffsl (t[i].val) != t[i].pattern)
	    exit (1 + i);
    }
    return 0;
}
