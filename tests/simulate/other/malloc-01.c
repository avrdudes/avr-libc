/* Copyright (c) 2009 Joerg Wunsch
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
#include <stdbool.h>
#include <string.h>
#include <stdint.h>

#ifdef __AVR__
#include "../../libc/stdlib/stdlib_private.h"
#endif

/*
 * Basic malloc() test:
 *
 * Two lists are maintained simultaneously, both featuring a different
 * payload size to trigger memory fragmentation issues.  A single
 * linked list is regularly appended to, and deleted from in a
 * semi-random manner.  In parallel, a double linked list is
 * maintained in ascending order of its payload values, gets new nodes
 * inserted, and nodes removed from close to the end.  After a number
 * of runs (500), the random sequence is replayed, and the remaining
 * list entries are removed, again, in the same semi-random order they
 * have been created with.  All successful append/insert and remove
 * operations are accounted.  At the end, the number of all
 * append/insert operations and delete operations must match for each
 * of the lists, and malloc's internal free list is monitored for only
 * consisting of a single large block (representing all the dynamic
 * memory that has been freed up again).
 */

#define N 500

struct list1
{
  struct list1 *next;
  uint16_t payload;
};

struct list2
{
  struct list2 *next, *prev;
  int32_t payload;
};

struct list1 *l1head, *l1tail;
struct list2 *l2head, *l2tail;

bool l1append(uint16_t payload)
{
  struct list1 *ele = malloc(sizeof(struct list1));
  if (ele == NULL)
    return false;
  ele->payload = payload;
  ele->next = NULL;
  if (l1tail == NULL)
    {
      l1head = l1tail = ele;
      return true;
    }
  l1tail->next = ele;
  l1tail = ele;

  return true;
}

struct list1 *l1find(uint16_t payload)
{
  if (l1head == NULL)
    return NULL;
  struct list1 *ele = l1head;
  while (ele != NULL && ele->payload != payload)
    ele = ele->next;
  return ele;
}

void l1delete(struct list1 *ele)
{
  struct list1 *e = l1head;
  struct list1 *f = NULL;

  if (ele == NULL)
    return;

  while (e != NULL && e != ele)
    {
      f = e;
      e = e->next;
    }
  if (e == NULL)
    exit(33);
  if (f == NULL)
    {
      /* First element matched, new head. */
      l1head = e->next;
      if (l1tail == ele)
	/* No member left. */
	l1tail = NULL;
    }
  else
    {
      f->next = ele->next;
      if (l1tail == ele)
	/* New tail. */
	l1tail = f;
    }
  free(ele);
}

bool l2insert(int32_t payload)
{
  struct list2 *ele = malloc(sizeof(struct list2));
  if (ele == NULL)
    return false;
  ele->payload = payload;
  ele->next = ele->prev = NULL;

  if (l2head == NULL && l2tail == NULL)
    {
      l2head = l2tail = ele;
      return true;
    }

  struct list2 *p = l2head;
  while (p != NULL && p->payload < ele->payload)
    p = p->next;

  if (p == NULL)
    {
      /* new tail */
      l2tail->next = ele;
      ele->prev = l2tail;
      l2tail = ele;

      return true;
    }

  /* insert here */
  ele->prev = p->prev;
  ele->next = p;

  if (p->prev != NULL)
    p->prev->next = ele;
  else
    /* new head */
    l2head = ele;
  p->prev = ele;

  return true;
}

void l2delete(struct list2 *ele)
{
  struct list2 *p = l2head;

  if (ele == NULL)
    return;

  while (p != NULL && p != ele)
    p = p->next;

  if (p == NULL)
    exit(34);

  if (p->prev != NULL)
    p->prev->next = p->next;
  else
    l2head = p->next;

  if (p->next != NULL)
    p->next->prev = p->prev;
  else
    l2tail = p->prev;

  free(ele);
}

struct list2 *l2find_3rd_last(void)
{
  uint8_t i;
  struct list2 *ele;

  if (l2tail == NULL)
    return NULL;

  for (i = 0, ele = l2tail; i < 3; ele = ele->prev)
    {
      if (ele->prev == NULL)
	break;
    }

  return ele;
}

#ifdef	__AVR__
void fill_mem(void) __attribute__((section(".init3"),naked));
void fill_mem(void)
{
  extern uint8_t __bss_end;
  uint8_t *p = &__bss_end;
  do
    *p++ = 0xa5;
  while (p < (uint8_t *)RAMEND);
}
#else
size_t __malloc_margin;
#endif

uint16_t stats[4];

#define RAND_START_VALUE 4242
int
main(void)
{
  uint16_t i;
  int32_t r;
  uint8_t x;
  int32_t v;

  __malloc_margin = 32;

  srandom(RAND_START_VALUE);
  for (i = 0; i < N; i++)
    {
      r = random();
      x = r & 0x0f;
      v = ((int32_t)x << 28) | ((int32_t)x << 24) |
      ((int32_t)x << 20) | ((int32_t)x << 16) |
      ((int32_t)x << 12) | ((int32_t)x << 8) |
      ((int32_t)x << 4) | (int32_t)x;
      if (r & 0x10)
	{
	  if (l1append(v))
	    stats[0]++;
	}
      else if (r & 0x20)
	{
	  struct list1 *p = l1find(v);
	  if (p != NULL)
	    {
	      stats[1]++;
	      l1delete(p);
	    }
	}
      if (r & 0x40)
	{
	  if (l2insert(v))
	    stats[2]++;
	}
      else if (r & 0x80)
	{
	  struct list2 *p = l2find_3rd_last();
	  if (p != NULL)
	    {
	      stats[3]++;
	      l2delete(p);
	    }
	}
    }
  srandom(RAND_START_VALUE);	/* repeat random sequence */
  while (l1head != NULL || l2head != NULL)
    {
      r = random();
      x = r & 0x0f;
      v = ((int32_t)x << 28) | ((int32_t)x << 24) |
      ((int32_t)x << 20) | ((int32_t)x << 16) |
      ((int32_t)x << 12) | ((int32_t)x << 8) |
      ((int32_t)x << 4) | (int32_t)x;
      if (r & 0x10)
	{
	  struct list1 *p = l1find(v);
	  if (p != NULL)
	    {
	      stats[1]++;
	      l1delete(p);
	    }
	}
      else if (r & 0x40)
	{
	  struct list2 *p = l2find_3rd_last();
	  if (p != NULL)
	    {
	      stats[3]++;
	      l2delete(p);
	    }
	}
    }
  if (stats[0] != stats[1] || stats[2] != stats[3])
    exit(1);
#ifdef __AVR__
  if (__flp != NULL)
    exit(2);
#endif
  return 0;
}
