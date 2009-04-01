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

/** \file */
/** \ingroup avr_string
    \fn char *strtok(char *s, const char *delim)
    \brief Parses the string s into tokens.

    strtok parses the string s into tokens. The first call to strtok
    should have s as its first argument. Subsequent calls should have
    the first argument set to NULL. If a token ends with a delimiter, this
    delimiting character is overwritten with a '\\0' and a pointer to the next
    character is saved for the next call to strtok. The delimiter string
    delim may be different for each call.
    
    \returns The strtok() function returns a pointer to the next token or
    NULL when no more tokens are found. 
    
    \note strtok() is NOT reentrant. For a reentrant version of this function
    see \c strtok_r().
*/

#include <string.h>
#include "sectionname.h"

static char *p;

ATTRIBUTE_CLIB_SECTION
char *
strtok(char *s, const char *delim)
{
    return strtok_r(s, delim, &p);
} 
