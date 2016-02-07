/* Copyright (c) 2013  Embecosm
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

#include <stdlib.h>

#ifndef __DOXYGEN__
static struct atexit_s
{
  void (*fun) (void);
  struct atexit_s *next;
} *atexit_p;
#endif

int
atexit (void (*fun) (void))
{
  struct atexit_s *new_as = (struct atexit_s *) malloc (sizeof *new_as);
  if (!new_as)
    return 1;
  new_as->fun = fun;
  new_as->next = atexit_p;
  atexit_p = new_as;
  return 0;
}

#ifndef __DOXYGEN__
/* Don't inline this code as naked to arrange for the very unlikely case
   that it needs a frame.   This won't work as naked function.  */

static void __attribute__((__noinline__))
atexit_finido (void)
{
  while (atexit_p)
    {
      void (*fun) (void) = atexit_p->fun;
      atexit_p = atexit_p->next;
      (*fun) ();
    }
}

/* Run functions registered by atexit in .fini8 so that they are
   sequenced before static destructors which run in .fini6.  */

static void __attribute__((__naked__, __used__, __section__(".fini8")))
atexit_fini (void)
{
  atexit_finido ();
}
#endif	/* !__DOXYGEN__ */
