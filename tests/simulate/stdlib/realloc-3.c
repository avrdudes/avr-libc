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
#include <stdint.h>
#include <string.h>

#ifdef __AVR__
#include <avr/pgmspace.h>
#include "../../libc/stdlib/stdlib_private.h"
#else
#include "progmem.h"
#endif

/*
 * Basic realloc() test:
 *
 * Simulates a serial receiver that semi-randomly "receives"
 * characters from some builtin text strings, and queues them in
 * variable-length records, forming a FIFO.  As the data arrive one
 * byte at a time, realloc() is used to extend the current record to
 * make the data fit.  Another semi-random part pulls data from the
 * FIFO head (again, one char at a time), and deletes the records
 * once they are completely processed.
 * After N (=2000) cycles, no more data are added to the FIFO, and
 * the remaining data are drained.
 * Finally, the number of characters "received" and "sent" is
 * compared, and must match, and the free list pointer is monitored
 * to ensure it only contains a single large block of all dynamic
 * memory that has been freed after use.
 */

struct list1
{
  struct list1 *next;
  bool done;
  size_t payloadlen;
  char payload[0];
};

struct list1 *l1head, *l1tail;

#if defined(__AVR_AT90S8515__)
#  define N 500
#else
#  define N 2000
#endif

bool l1append(char c)
{
  struct list1 *ele = malloc(sizeof(struct list1) + 1);
  if (ele == NULL)
    return false;
  ele->payloadlen = 1;
  ele->payload[0] = c;
  ele->next = NULL;
  ele->done = false;
  if (l1tail == NULL)
    {
      l1head = l1tail = ele;
      return true;
    }
  l1tail->next = ele;
  l1tail = ele;

  return true;
}

bool l1extend(char c)
{
  if (l1tail == NULL)
    exit(42);
  struct list1 *ele = l1tail;
  struct list1 *p;

  p = realloc(ele, sizeof(struct list1) + ele->payloadlen + 1);
  if (p == NULL)
    return false;

  p->payload[p->payloadlen] = c;
  p->payloadlen++;
  if (p != ele)
    {
      if (ele == l1head)
	{
	  l1head = p;
	}
      else
	{
	  struct list1 *walk = l1head;
	  while (walk != NULL && walk->next != ele)
	    walk = walk->next;
	  if (walk == NULL)
	    exit(43);
	  walk->next = p;
	}
      l1tail = p;
    }

  return true;
}

void l1delete(void)
{
  if (l1head == NULL)
    exit(44);
  struct list1 *p = l1head->next;
  free(l1head);
  l1head = p;
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

#define S(i,s) static const char string##i[] PROGMEM = s

S(0, "The ");
S(1, "quick ");
S(2, "brown ");
S(3, "fox ");
S(4, "jumps ");
S(5, "over ");
S(6, "the lazy ");
S(7, "dog.  ");

static const char *strings[8] = {
  string0, string1, string2, string3, string4, string5, string6, string7
};

static uint8_t s_idx;
static const char *cur_c;

/*
 * Simulates e.g. a serial receiver.  "Receives" characters from some
 * flash strings.
 */
char getdata(void)
{
  char c;

  if (cur_c == NULL)
    {
      cur_c = strings[0];
      c = pgm_read_byte(cur_c);
      cur_c++;
      return c;
    }
  c = pgm_read_byte(cur_c);
  cur_c++;
  if (c == '\0')
    {
      if (++s_idx == 8)
	s_idx = 0;
      cur_c = strings[s_idx];
    }
  return c;
}

static char *txp;

/*
 * Simulates e.g. a serial transmitter -- but transmits to /dev/null
 * for simplicity. ;)  It always transmits data from the payload
 * portion of the current list head.
 */
bool putdata(void)
{
  if (l1head == NULL)
    return false;
  if (txp == NULL)
    {
      if (!l1head->done)
	return false;
      txp = l1head->payload;
    }
  char devnull = *txp++;	/* /dev/null = devnull; */
  if (devnull == '\0')
    {
      /* end of current record */
      txp = NULL;
      l1delete();
    }
  return true;
}

uint16_t stats[2];

#define RAND_START_VALUE 42
int
main(void)
{
  uint16_t i;
  long r;
  bool rx_in_progress = false;

  __malloc_margin = 50;

  srandom(RAND_START_VALUE);
  for (i = 0; i < N; i++)
    {
      r = random();
      if (r & 0x01)
	{
	  char c = getdata();
	  if (!rx_in_progress)
	    {
	      /* allocate new tail */
	      if (l1append(c))
		stats[0]++;
	    }
	  else
	    {
	      if (l1extend(c))
		stats[0]++;
	    }
	  if (c == '\0')
	    {
	      /* end of record, allocate new one next time */
	      rx_in_progress = false;
	      l1tail->done = true;
	    }
	  else
	    {
	      /* extend current record next time */
	      rx_in_progress = true;
	    }
	}
      else if (r & 0x02)
	{
	  if (putdata())
	    stats[1]++;
	}
    }
  if (rx_in_progress)
    {
      /* terminate current record */
      if (l1extend('\0'))
	stats[0]++;
      l1tail->done = true;
    }
  srandom(RAND_START_VALUE);	/* repeat random sequence */
  while (l1head != NULL)
    {
      if (putdata())
	stats[1]++;
    }
  if (stats[0] != stats[1])
    exit(1);
#ifdef __AVR__
  if (__flp->nx != NULL)
    exit(2);
#endif
  return 0;
}
