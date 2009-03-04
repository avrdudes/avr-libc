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

/* $Id*/

#include <stdlib.h>

#include "../../libc/stdlib/stdlib_private.h"

/*
 * Test code from bug #25723, courtesy Lou Amadio.
 */
void testMalloc(void)
{
    size_t *array = malloc(4 * sizeof(size_t));
    free(array);
    array = NULL;

    array = realloc(array, sizeof(size_t));
    array = realloc(array, 2 * sizeof(size_t));
    array = realloc(array, 3 * sizeof(size_t));
    realloc(array, 4 * sizeof(size_t));
}

int
main(void)
{
  testMalloc();

  /*
   * In the original (buggy) case, __flp ended up pointing to an entry
   * of size 65534.  With the fix applied, the subsequent calls to
   * realloc() ought to have re-consumed the entire space freed
   * previously, so __flp must be NULL.
   */
  if (__flp != NULL)
    exit(1);

  return 0;
}
