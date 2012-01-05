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

/* Binary conversion.
   $Id$
 */
#include <stdlib.h>
#include <string.h>
#include "progmem.h"
#include "strtoul.h"

int main ()
{
    PROGMEM static const struct t_s {
	char s[35];		/* string to convert	*/
	int base;
	unsigned long ret;	/* result must	*/
	int err;		/* errno must	*/
	unsigned char len;	/* endptr displacement must	*/
    } t[] = {
	
	{ "0", 2,	0, 0, 1 },
	{ "1", 2,	1, 0, 1 },
	{ "-1", 2,	-1, 0, 2 },
	{ "10101010", 2,	0xaa, 0, 8 },

	{ "1111111111111111111111111111110", 2,	   0x7ffffffe, 0, 31 },
	{ "1111111111111111111111111111111", 2,    0x7fffffff, 0, 31 },
	{ "10000000000000000000000000000000", 2,   0x80000000, 0, 32 },
	{ "10000000000000000000000000000001", 2,   0x80000001, 0, 32 },
	{ "11111111111111111111111111111111", 2,   0xffffffff, 0, 32 },
	{ "100000000000000000000000000000000", 2,  0xffffffff, ERANGE, 33 },
	{ "100000000000000000000000000000001", 2,  0xffffffff, ERANGE, 33 },

	{ "-1111111111111111111111111111111", 2,   0x80000001, 0, 32 },
	{ "-10000000000000000000000000000000", 2,  0x80000000, 0, 33 },
	{ "-10000000000000000000000000000001", 2,  0x7fffffff, 0, 33 },
	{ "-10000000000000000000000000000010", 2,  0x7ffffffe, 0, 33 },
	{ "-11111111111111111111111111111111", 2,  0x00000001, 0, 33 },
	{ "-100000000000000000000000000000000", 2, 0xffffffff, ERANGE, 34 },
	{ "-100000000000000000000000000000001", 2, 0xffffffff, ERANGE, 34 },
	
    };
    struct t_s tt;
    int i;
    
    for (i = 0; i != (int)(sizeof(t)/sizeof(t[0])); i++) {
	struct t_s *p;
	memcpy_P (&tt, t + i, sizeof(tt));
	p = &tt;
	if (t_strtoul (p->s, p->base, p->ret, p->err, p->len))
	    exit (i+1);
    }
    return 0;
}
