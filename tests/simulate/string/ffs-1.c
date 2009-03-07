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

/* Test of ffs() function.
   $Id$	*/

#include <stdlib.h>
#include <string.h>

int main ()
{
    static struct t_s {
	int val;
	unsigned char pattern;
    } t[] = {
	{ 0, 0 },
	{ 1, 1 },
	{ 0xffff, 1 },
	{ 0x0002, 2 },
	{ 0x8002, 2 },
	{ 0xfff2, 2 },
	{ 0x0040, 7 },
	{ 0x0140, 7 },
	{ 0x0080, 8 },
	{ 0xff80, 8 },
	{ 0x0100, 9 },
	{ 0xff00, 9 },
	{ 0x8000, 16 },
    };
    volatile int vx;
    int i;
    
    /* Possibly, this is an inline substitution.	*/
    for (i = 0; i != (int)(sizeof(t)/sizeof(t[0])); i++) {
	if (ffs(t[i].val) != t[i].pattern)
	    exit (1 + i);
    }
    
    /* Force a function call (against inline substitution).	*/
    for (i = 0; i != (int)(sizeof(t)/sizeof(t[0])); i++) {
	int (* volatile vffs)(int) = ffs;
	if (vffs(t[i].val) != t[i].pattern)
	    exit (101 + i);
    }
    
    /* Side effects?	*/
    vx = 7;
    if (ffs(++vx) != 4 || vx != 8)
	exit (__LINE__);
    vx = 16;
    if (ffs(vx++) != 5 || vx != 17)
	exit (__LINE__);

    vx = 127;
    if (ffs(ffs(++vx)) != 4 || vx != 128)
	exit (__LINE__);

    /* Implicit check	*/
    vx = 1;
    if (__builtin_constant_p(++vx) || __builtin_constant_p(vx = -1))
	exit (__LINE__);
    if (vx != 1)    
	exit (__LINE__);

    return 0;
}
