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
#include "strtoll.h"

int main (void)
{
    PROGMEM static const struct t_s
    {
	char s[25];		/* string to convert	*/
	int base;
	long long ret;		/* result must	*/
	int err;		/* errno must	*/
	unsigned char len;	/* endptr displacement must	*/
    } t[] = {

	{  "0x7fffffffffffffff", 0, LLONG_MAX, 0, 18 },
	{  "0x8000000000000000", 0, LLONG_MAX, ERANGE, 18 },
	{  "0x8000000000000001", 0, LLONG_MAX, ERANGE, 18 },
	{  "0x8000000000000010", 0, LLONG_MAX, ERANGE, 18 },
	{ "0x80000000000000000", 0, LLONG_MAX, ERANGE, 19 },
	{  "0x8000000000000000 ",0, LLONG_MAX, ERANGE, 18 },
	{ "0x80000000000000000 ",0, LLONG_MAX, ERANGE, 19 },

	{  "-0X7fffffffFFFFFFFF", 0, LLONG_MIN + 1, 0, 19 },
	{  "-0x8000000000000000", 0, LLONG_MIN, 0, 19 },
	{  "-0x8000000000000001", 0, LLONG_MIN, ERANGE, 19 },
	{  "-0x8000000000000010", 0, LLONG_MIN, ERANGE, 19 },
	{ "-0x80000000000000000", 0, LLONG_MIN, ERANGE, 20 },
	{ "-0x80000000000000001", 0, LLONG_MIN, ERANGE, 20 },

	{  "9223372036854775807", 0, LLONG_MAX, 0, 19 },
	{  "9223372036854775808", 0, LLONG_MAX, ERANGE, 19 },
	{  "9223372036854775809", 0, LLONG_MAX, ERANGE, 19 },
	{  "9223372036854775810", 0, LLONG_MAX, ERANGE, 19 },
	{  "9223373000000000000", 0, LLONG_MAX, ERANGE, 19 },
	{ "10000000000000000000", 0, LLONG_MAX, ERANGE, 20 },

	{  "-9223372036854775807", 0, LLONG_MIN + 1, 0, 20 },
	{  "-9223372036854775808", 0, LLONG_MIN, 0, 20 },
	{  "-9223372036854775809", 0, LLONG_MIN, ERANGE, 20 },
	{  "-9223372036854775810", 0, LLONG_MIN, ERANGE, 20 },
	{  "-9223373000000000000", 0, LLONG_MIN, ERANGE, 20 },
	{ "-10000000000000000000", 0, LLONG_MIN, ERANGE, 21 },
    };
    struct t_s tt;

    for (int i = 0; i != ARRAY_SIZE (t); i++)
    {
	struct t_s *p;
	memcpy_P (&tt, t + i, sizeof(tt));
	p = &tt;
	if (t_strtoll (p->s, p->base, p->ret, p->err, p->len))
	    exit (i + 1);
    }
    return 0;
}
