/* Copyright (c) 2007  Dmitry Xmelkov
   Copyright (c) 2025  Georg-Johann Lay
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
   POSSIBILITY OF SUCH DAMAGE. */

/* Overflow. */
#include <stdlib.h>
#include <string.h>
#include "progmem.h"
#include "strtoull.h"

int main (void)
{
    PROGMEM static const struct t_s
    {
	char s[14];		/* string to convert	*/
	int base;
	unsigned long long ret;	/* result must	*/
	int err;		/* errno must	*/
	unsigned char len;	/* endptr displacement must	*/
    } t[] = {

	{ "2147483647", 0,	0x7fffffff, 0, 10 },
	{ "0x7fffffff", 0,	0x7fffffff, 0, 10 },
	{ "017777777777", 0,	0x7fffffff, 0, 12 },
	{ "2147483648", 0,	0x80000000, 0, 10 },
	{ "0x80000000", 0,	0x80000000, 0, 10 },
	{ "020000000000", 0,	0x80000000, 0, 12 },

	{ "4294967295", 0,	0xffffffff, 0, 10 },
	{ "4294967296", 0,	4294967296ull, 0, 10 },
	{ "4294967297", 0,	4294967297ull, 0, 10 },
	{ "4294967298", 0,	4294967298ull, 0, 10 },
	{ "4294967299", 0,	4294967299ull, 0, 10 },
	{ "4294967300", 0,	4294967300ull, 0, 10 },
	{ "4294967301", 0,	4294967301ull, 0, 10 },
	{ "4294967302", 0,	4294967302ull, 0, 10 },
	{ "4294967303", 0,	4294967303ull, 0, 10 },
	{ "4294967304", 0,	4294967304ull, 0, 10 },
	{ "4294967305", 0,	4294967305ull, 0, 10 },
	{ "4294967306", 0,	4294967306ull, 0, 10 },
	{ "9999999999999", 0,	9999999999999ull, 0, 13 },

	{ "037777777777", 0,	0xffffffff, 0, 12 },
	{ "040000000000", 0,	0x100000000ull, 0, 12 },
	{ "040000000001", 0,	0x100000000ull + 1, 0, 12 },
	{ "040000000006", 0,	0x100000000ull + 6, 0, 12 },
	{ "040000000007", 0,	0x100000000ull + 7, 0, 12 },
	{ "040000000010", 0,	0x100000000ull + 8, 0, 12 },
	{ "0777777777777", 0,	0xfffffffffull, 0, 13 },

	{ "0xffffffff", 0,	0xffffffff, 0, 10},
	{ "0x100000000", 0,	0x100000000ull, 0, 11 },
	{ "0x100000001", 0,	0x100000001ull, 0, 11 },
	{ "0x10000000e", 0,	0x10000000eull, 0, 11 },
	{ "0x10000000f", 0,	0x10000000full, 0, 11 },
	{ "0x100000010", 0,	0x100000010ull, 0, 11 },
	{ "0xfffffffffff", 0,	0xfffffffffffull, 0, 13 },

	{ "-2147483647", 0,	-2147483647ull, 0, 11 },
	{ "-0x7fffffff", 0,	-0x7fffffffull, 0, 11 },
	{ "-017777777777", 0,	-0x7fffffffull, 0, 13 },
	{ "-2147483648", 0,	-0x80000000ull, 0, 11 },
	{ "-0x80000000", 0,	-0x80000000ull, 0, 11 },
	{ "-020000000000", 0,	-0x80000000ull, 0, 13 },
	{ "-2147483649", 0,	-2147483649ull, 0, 11 },
	{ "-0x80000001", 0,	-0x80000001ull, 0, 11 },
	{ "-020000000001", 0,	-0x80000001ull, 0, 13 },

	{ "-4294967295", 0,	-4294967295ull, 0, 11 },
	{ "-4294967296", 0,	-4294967296ull, 0, 11 },
	{ "-4294967297", 0,	-4294967297ull, 0, 11 },
    };

    for (int i = 0; i != ARRAY_SIZE (t); i++)
    {
	struct t_s tt, *p;
	memcpy_P (&tt, t + i, sizeof(tt));
	p = &tt;
	if (t_strtoull (p->s, p->base, p->ret, p->err, p->len))
	    exit (i + 1);
    }
    return 0;
}
