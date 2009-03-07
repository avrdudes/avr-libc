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
	long long val;
	unsigned char pattern;
    } t[] = {
	{ 0LL, 0 },
	{ 1LL, 1 },
	{ 0xffffffffffffffffLL, 1 },
	{ 0x0000000000000002LL, 2 },
	{ 0x8000000000000002LL, 2 },
	{ 0x7ffffffffffffff2LL, 2 },
	{ 0xfffffffffffffff2LL, 2 },
	{ 0x0000000000000040LL, 7 },
	{ 0xffffffffffffff40LL, 7 },
	{ 0x0000000000000080LL, 8 },
	{ 0xffffffffffffff80LL, 8 },

	{ 0x0000000000000100LL, 9 },
	{ 0xffffffffffffff00LL, 9 },
	{ 0x0000000000008000LL, 16 },
	{ 0xffffffffffff8000LL, 16 },
	
	{ 0x0000000000010000LL, 17 },
	{ 0xffffffffffff0000LL, 17 },
	{ 0x0000000000800000LL, 24 },
	{ 0xffffffffff800000LL, 24 },
	
	{ 0x0000000001000000LL, 25 },
	{ 0xffffffffff000000LL, 25 },
	{ 0x0000000080000000LL, 32 },
	{ 0xffffffff80000000LL, 32 },
	
	{ 0x0000000100000000LL, 33 },
	{ 0xffffffff00000000LL, 33 },
	{ 0x0000008000000000LL, 40 },
	{ 0xffffff8000000000LL, 40 },
	
	{ 0x0000010000000000LL, 41 },
	{ 0xffffff0000000000LL, 41 },
	{ 0x0000800000000000LL, 48 },
	{ 0xffff800000000000LL, 48 },
	
	{ 0x0001000000000000LL, 49 },
	{ 0xffff000000000000LL, 49 },
	{ 0x0080000000000000LL, 56 },
	{ 0xff80000000000000LL, 56 },

	{ 0x0100000000000000LL, 57 },
	{ 0xff00000000000000LL, 57 },
	{ 0x8000000000000000LL, 64 },
    };
    int i;
    
    for (i = 0; i != (int)(sizeof(t)/sizeof(t[0])); i++) {
	if (ffsll (t[i].val) != t[i].pattern)
	    exit (1 + i);
    }
    return 0;
}
