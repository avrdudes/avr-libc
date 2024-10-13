/* Copyright (c) 2002, 2004, 2010 Joerg Wunsch
   Copyright (c) 2010  Gerben van den Broeke
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
#include "sectionname.h"
#include "stdlib_private.h"

#ifdef MALLOC_TEST
char mymem[256];
#else
#include <avr/io.h>
#endif /* MALLOC_TEST */

/*
 * Exported interface:
 *
 * When extending the data segment, the allocator will not try to go
 * beyond the current stack limit, decreased by __malloc_margin bytes.
 * Thus, all possible stack frames of interrupt routines that could
 * interrupt the current function, plus all further nested function
 * calls must not require more stack space, or they'll risk to collide
 * with the data segment.
 */

/* May be changed by the user only before the first malloc() call.  */

size_t __malloc_margin = 32;
char *__malloc_heap_start = &__heap_start;
char *__malloc_heap_end = &__heap_end;

char *__brkval;
struct __freelist *__flp;

ATTRIBUTE_CLIB_SECTION
void *
malloc(size_t len)
{
	struct __freelist *fp1, *fp2, *sfp1, *sfp2;
	char *cp;
	size_t s, avail;

	/*
	 * Our minimum chunk size is the size of a pointer (plus the
	 * size of the "sz" field, but we don't need to account for
	 * this), otherwise we could not possibly fit a freelist entry
	 * into the chunk later.
	 */
	if (len < sizeof(struct __freelist) - sizeof(size_t))
		len = sizeof(struct __freelist) - sizeof(size_t);

	/*
	 * First, walk the free list and try finding a chunk that
	 * would match exactly.  If we found one, we are done.  While
	 * walking, note down the smallest chunk we found that would
	 * still fit the request -- we need it for step 2.
	 *
	 */
	for (s = 0, fp1 = __flp, fp2 = 0;
	     fp1;
	     fp2 = fp1, fp1 = fp1->nx) {
		if (fp1->sz < len)
			continue;
		if (fp1->sz == len) {
			/*
			 * Found it.  Disconnect the chunk from the
			 * freelist, and return it.
			 */
			if (fp2)
				fp2->nx = fp1->nx;
			else
				__flp = fp1->nx;
			return &(fp1->nx);
		}
		else {
			if (s == 0 || fp1->sz < s) {
				/* this is the smallest chunk found so far */
				s = fp1->sz;
				sfp1 = fp1;
				sfp2 = fp2;
			}
		}
	}
	/*
	 * Step 2: If we found a chunk on the freelist that would fit
	 * (but was too large), look it up again and use it, since it
	 * is our closest match now.  Since the freelist entry needs
	 * to be split into two entries then, watch out that the
	 * difference between the requested size and the size of the
	 * chunk found is large enough for another freelist entry; if
	 * not, just enlarge the request size to what we have found,
	 * and use the entire chunk.
	 */
	if (s) {
		if (s - len < sizeof(struct __freelist)) {
			/* Disconnect it from freelist and return it. */
			if (sfp2)
				sfp2->nx = sfp1->nx;
			else
				__flp = sfp1->nx;
			return &(sfp1->nx);
		}
		/*
		 * Split them up.  Note that we leave the first part
		 * as the new (smaller) freelist entry, and return the
		 * upper portion to the caller.  This saves us the
		 * work to fix up the freelist chain; we just need to
		 * fixup the size of the current entry, and note down
		 * the size of the new chunk before returning it to
		 * the caller.
		 */
		cp = (char *)sfp1;
		s -= len;
		cp += s;
		sfp2 = (struct __freelist *)cp;
		sfp2->sz = len;
		sfp1->sz = s - sizeof(size_t);
		return &(sfp2->nx);
	}
	/*
	 * Step 3: If the request could not be satisfied from a
	 * freelist entry, just prepare a new chunk.  This means we
	 * need to obtain more memory first.  The largest address just
	 * not allocated so far is remembered in the brkval variable.
	 * Under Unix, the "break value" was the end of the data
	 * segment as dynamically requested from the operating system.
	 * Since we don't have an operating system, just make sure
	 * that we don't collide with the stack.
	 */
	if (__brkval == 0)
		__brkval = __malloc_heap_start;
	cp = __malloc_heap_end;
	if (cp == 0)
		cp = STACK_POINTER() - __malloc_margin;
	if (cp <= __brkval)
	  /*
	   * Memory exhausted.
	   */
	  return 0;
	avail = cp - __brkval;
	/*
	 * Both tests below are needed to catch the case len >= 0xfffe.
	 */
	if (avail >= len && avail >= len + sizeof(size_t)) {
		fp1 = (struct __freelist *)__brkval;
		__brkval += len + sizeof(size_t);
		fp1->sz = len;
		return &(fp1->nx);
	}
	/*
	 * Step 4: There's no help, just fail. :-/
	 */
	return 0;
}


ATTRIBUTE_CLIB_SECTION
void
free(void *p)
{
	struct __freelist *fp1, *fp2, *fpnew;
	char *cp1, *cpnew;

	/* ISO C says free(NULL) must be a no-op */
	if (p == 0)
		return;

	cpnew = p;
	cpnew -= sizeof(size_t);
	fpnew = (struct __freelist *)cpnew;
	fpnew->nx = 0;

	/* First, check if we can reduce __brkval. */
	if ((char *)p + fpnew->sz == __brkval) {
		__brkval = cpnew;
		/* If there is no freelist, we are done. */
		if (!__flp)
			return;
		/*
		 * Otherwise, walk the entire list to see if there is a
		 * new top-most chunk.
		 */
		for (fp1 = __flp, fp2 = 0;
	             fp1->nx != 0;
	             fp2 = fp1, fp1 = fp1->nx)
			/* advance to entry just before end of list */;
		cp1 = (char *)&(fp1->nx);
		if (cp1 + fp1->sz == __brkval) {
			if (fp2 == NULL)
				/* Freelist is empty now. */
				__flp = NULL;
			else
				fp2->nx = NULL;
			__brkval = cp1 - sizeof(size_t);
		}
		return;
	}
	/* __brkval can't be reduced */
	/* If there is no freelist yet, create a new one. */
	if (!__flp) {
		__flp = fpnew;
		return;
	}
	/*
	 * Now, find the position where our new entry belongs onto the
	 * freelist.  Try to aggregate the chunk with adjacent chunks
	 * if possible.
	 */
	for (fp1 = __flp, fp2 = 0;
	     fp1;
	     fp2 = fp1, fp1 = fp1->nx) {
		if (fp1 < fpnew)
			continue;
		cp1 = (char *)fp1;
		fpnew->nx = fp1;
		if ((char *)&(fpnew->nx) + fpnew->sz == cp1) {
			/* upper chunk adjacent, assimilate it */
			fpnew->sz += fp1->sz + sizeof(size_t);
			fpnew->nx = fp1->nx;
		}
		if (fp2 == 0) {
			/* new head of freelist */
			__flp = fpnew;
			return;
		}
		break;
	}
	/*
	 * Note that we get here either if we hit the "break" above,
	 * or if we fell off the end of the loop.  The latter means
	 * we've got a new topmost chunk.  Either way, try aggregating
	 * with the lower chunk if possible.
	 */
	fp2->nx = fpnew;
	cp1 = (char *)&(fp2->nx);
	if (cp1 + fp2->sz == cpnew) {
		/* lower junk adjacent, merge */
		fp2->sz += fpnew->sz + sizeof(size_t);
		fp2->nx = fpnew->nx;
	}
}

#ifdef MALLOC_TEST

#include <stdio.h>
#include <string.h>
#include <time.h>
#include <unistd.h>

void *handles[32];
size_t sizes[32];


void *
alloc(size_t s)
{
	void *p;

	if ((p = malloc(s)) == 0)
		return 0;
	memset(p, 0xd0, s);
	return p;
}

void
printfreelist(void)
{
	struct __freelist *fp1;
	int i;

	if (!__flp) {
		printf("no free list\n");
		return;
	}

	for (i = 0, fp1 = __flp; fp1; i++, fp1 = fp1->nx) {
		printf("entry %d @ %u: size %u, next ",
		       i, (char *)fp1 - mymem, fp1->sz);
		if (fp1->nx)
			printf("%u\n", (char *)fp1->nx - mymem);
		else
			printf("NULL\n");
	}
}

int
compare(const void *p1, const void *p2)
{
	return *((size_t *)p1) - *((size_t *)p2);
}

void
printalloc(void)
{
	int j, k;
	size_t i;
	size_t sum, sum2;
	void *sortedhandles[32];
	struct __freelist *fp;
	char *cp;

	for (i = j = k = sum = sum2 = 0;
	     i < sizeof handles / sizeof (void *);
	     i++)
		if (sizes[i]) {
			j++;
			sum += sizes[i];
			if (handles[i]) {
				k++;
				sum2 += sizes[i];
			}
		}
	printf("brkval: %d, %d request%s => sum %u bytes "
	       "(actually %d reqs => %u bytes)\n",
	       (char *)__brkval - mymem, j, j == 1? "": "s", sum, k, sum2);
	memcpy(sortedhandles, handles, sizeof sortedhandles);
	qsort(sortedhandles, 32, sizeof(void *), compare);
	for (i = j = 0; i < sizeof sortedhandles / sizeof (void *); i++)
		if ((cp = sortedhandles[i])) {
			cp -= sizeof(size_t);
			fp = (struct __freelist *)cp;
			printf("block %d @ %u: %u bytes\n",
			       j, (char *)&fp->nx - mymem, fp->sz);
			j++;
		}

}


int
main(void)
{
	int i, j, k, l, m, om, p, f;
	size_t s;

	srand(time(0) ^ getpid());

	for (k = 0; k < 100; k++) {
		memset(handles, 0, sizeof handles);
		memset(sizes, 0, sizeof sizes);

		j = rand() % 16 + 15;
		l = rand() % 80 + 7;

		for (i = s = 0; i < j && s < 256; i++) {
			sizes[i] = rand() % l + 1;
			s += sizes[i];
		}
		j = i;
		for (m = om = 1, p = 1, f = 0; m < 1000; m++) {
			for (i = s = 0; i < j; i++)
				if (handles[i])
					s++;
			if (s == (unsigned)j)
				break;

			if (m / om > 10) {
				p <<= 1;
				p |= 1;
			}

			for (i = 0; i < j; i++)
				if (rand() & p) {
					if (!handles[i] &&
					    (handles[i] = alloc(sizes[i])) == 0)
						f++;
				}
			for (i = 0; i < j; i++)
				if (rand() & 1) {
					free(handles[i]);
					handles[i] = 0;
				}
		}
		if (f)
			printf("%d alloc failure%s total\n",
			       f, f == 1? "": "s");
		printf("After alloc:\n");
		printalloc();
		printfreelist();
		for (i = 0; i < j; i++)
			free(handles[i]);
		printf("After cleanup:\n");
		printfreelist();
	}

	return 0;
}

#endif /* MALLOC_TEST */

