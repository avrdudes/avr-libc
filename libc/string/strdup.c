/* Copyright (c) 2008, Atmel Corporation
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

/* $Id$ */

#include <stdlib.h>
#include <string.h>
#include "sectionname.h"

/** \file */
/** \ingroup avr_string
    \fn char *strdup(const char *s1)
    \brief Duplicate a string.

    The strdup() function allocates memory and copies into it the string
    addressed by s1, including the terminating null character.

    \warning The strdup() function calls malloc() to allocate the memory
    for the duplicated string! The user is responsible for freeing the
    memory by calling free(). 
    
    \returns The strdup() function returns a pointer to the resulting string
    dest. If malloc() cannot allocate enough storage for the string, strdup() 
    will return NULL.

    \warning Be sure to check the return value of the strdup() function to
    make sure that the function has succeeded in allocating the memory!
*/

ATTRIBUTE_CLIB_SECTION
char *
strdup(const char *s1)
{
    char *s2 = malloc(strlen(s1)+1);
    if (s2 != NULL)
    {
        strcpy(s2, s1);
    }
    return(s2);
}
