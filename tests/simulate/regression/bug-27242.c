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

#include "../../libc/stdlib/stdlib_private.h"


/* Test code from bug #27242 (and #25723) */
int main(void)
{
	char *p, *p1;

	p = malloc(16);
	if (!p)
		return 1;

	/* releasing 6 bytes creates a new free chunk */
	p1 = realloc(p, 10);
	if (p != p1)
		return 2;

	/*
	 * The patch for bug #25723 introduces a regression to realloc()
	 * when called to shrink a memory chunk. We simply verify if
	 * the new __brkval starts immediately after the last allocated
	 * chunk.
	 */
	p = p1 + 10;
	if (__brkval != p)
		return 3;

	/* use the last free chunk */
	p1 = malloc(4);
	if (!p1)
		return 4;

	/* should be empty */
	if (__flp)
		return 5;

	p = malloc(10);
	if (!p)
		return 6;

	/* force creation of a new minimal free chunk (sz = 3), which
           will be returned from heap then */
	p1 = realloc(p, 5);
	if (p != p1)
		return 7;

	p = p1 + 5;
	if (__brkval != p)
		return 8;

	/* merge with the free chunk (incr = 4 > sz = 3) */
	p = realloc(p1, 9);
	if (p != p1)
		return 9;

	/* chunk size should be 9 */
	p -= sizeof(size_t);
	if (*(size_t *)p != 9)
		return 10;

	/* should be empty */
	if (__flp)
		return 11;

	return 0;
}

