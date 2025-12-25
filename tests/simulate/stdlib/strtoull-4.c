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

/* Binary conversion. */
#include <stdlib.h>
#include <string.h>
#include <limits.h>
#include "progmem.h"
#include "strtoull.h"

int main (void)
{
    PROGMEM static const struct t_s
    {
	char s[25];		/* string to convert	*/
	int base;
	unsigned long long ret;	/* result must	*/
	int err;		/* errno must	*/
	unsigned char len;	/* endptr displacement must	*/
    } t[] = {

	{   "0x8000000000000000", 0,   0x8000000000000000ull, 0, 18 },
	{   "0xffffffffffffffff", 0,   ULLONG_MAX, 0, 18 },
	{  "0x10000000000000000", 0,   ULLONG_MAX, ERANGE, 19 },
	{  "0x10000000000000001", 0,   ULLONG_MAX, ERANGE, 19 },
	{  "0x10000000000000010", 0,   ULLONG_MAX, ERANGE, 19 },

	{  "-0x8000000000000001", 0,   LLONG_MAX, 0, 19 },
	{  "-0x8000000000000000", 0,   0x8000000000000000ull, 0, 19 },
	{  "-0xfffffffffffffffe", 0,   2, 0, 19 },
	{  "-0xffffffffffffffff", 0,   1, 0, 19 },
	{ "-0x10000000000000000", 0,   ULLONG_MAX, ERANGE, 20 },
	{ "-0x10000000000000001", 0,   ULLONG_MAX, ERANGE, 20 },
	{ "-0x10000000000000010", 0,   ULLONG_MAX, ERANGE, 20 },

	{  "18446744073709551614", 0,  ULLONG_MAX-1, 0, 20 },
	{  "18446744073709551615", 0,  ULLONG_MAX, 0, 20 },
	{  "18446744073709551616", 0,  ULLONG_MAX, ERANGE, 20 },
	{  "18446744073709551617", 0,  ULLONG_MAX, ERANGE, 20 },
	{  "18446744073709551618", 0,  ULLONG_MAX, ERANGE, 20 },
	{  "18446744073709551619", 0,  ULLONG_MAX, ERANGE, 20 },
	{  "19000000000000000000", 0,  ULLONG_MAX, ERANGE, 20 },
	{  "17999999999999999999", 0,  17999999999999999999ull, 0, 20 },

	{ "-18446744073709551614", 0,  2, 0, 21 },
	{ "-18446744073709551615", 0,  1, 0, 21 },
	{ "-18446744073709551616", 0,  ULLONG_MAX, ERANGE, 21 },
    };
    struct t_s tt;

    for (int i = 0; i != ARRAY_SIZE (t); i++)
    {
	struct t_s *p;
	memcpy_P (&tt, t + i, sizeof(tt));
	p = &tt;
	if (t_strtoull (p->s, p->base, p->ret, p->err, p->len))
	    exit (i + 1);
    }
    return 0;
}
