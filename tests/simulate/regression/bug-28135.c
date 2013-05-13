/* Copyright (c) 2009 Aleksandar Kanchev
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

/* $Id$ */

#include <stdlib.h>
#include <avr/cpufunc.h>

#include "../../libc/stdlib/stdlib_private.h"


/* Test code from bug # */
int main(void)
{
	char *p, *p1;

	/* Step 1: test with just one free chunk */

	p = malloc(20);
	if (!p)
		return 1;

	/* releasing 10 bytes returns them from the heap */
	p1 = realloc(p, 10);
	if (p != p1)
		return 2;

	_MemoryBarrier();
	if (__flp)
		return 3;

	/* should extend the free chunk */
	p = malloc(15);
	if (!p)
		return 4;

	_MemoryBarrier();
	/* should be empty */
	if (__flp)
		return 5;

	/* should be the following chunk */
	p1 += 10 + sizeof(size_t);
	if (p != p1)
		return 6;

	/* should point right after the last chunk */
	p += 15;
	if (p != __brkval)
		return 7;

	/* Step 2: Test with 2 free chunks. */

	p = malloc(8);
	if (!p)
		return 8;

	p1 = malloc(9);
	if (!p1)
		return 9;

	free(p);

	p = malloc(20);
	if (!p)
		return 10;

	_MemoryBarrier();
	if (!__flp)
		return 11;

	p1 = realloc(p, 10);
	if (p1 != p)
		return 12;

	_MemoryBarrier();
	if (!__flp)
		return 13;

	if (__flp->nx)
		return 14;

	p = malloc(15);
	if (!p)
		return 15;

	_MemoryBarrier();
	if (!__flp)
		return 16;

	if (__flp->nx)
		return 17;

	p1 += 10 + sizeof(size_t);
	if (p != p1)
		return 18;

	p += 15;
	if (p != __brkval)
		return 19;

	return 0;
}

