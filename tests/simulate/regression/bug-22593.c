/* Copyright (c) 2008  Dmitry Xmelkov
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

/* bug #22593: vfscanf improperly scans string parameters with a width
   option by 1 character
   $Id$	*/

/* Seems, this is duplication of bug #19079: sscanf %s eats 1 char too much
 */

#include <stdio.h>
#include <string.h>

#ifndef	__AVR__
# define sscanf_P	sscanf
# define PSTR(s)	(s)
#else
# include <avr/pgmspace.h>
#endif

int main ()
{
    char s1[5], s2[5];
    int result;
    
    s1[0] = 0;
    s2[0] = 0;

    result = sscanf_P (",ABCD,EFGH,", PSTR (",%4s,%4s,"), s1, s2);
    if (result != 2)
	return __LINE__;
    if (strcmp (s1, "ABCD") || strcmp (s2, "EFGH"))
	return __LINE__;

    s1[0] = 0;
    s2[0] = 0;
    result = sscanf_P (",ABCD,EFGH,", PSTR (",%3s,%3s,"), s1, s2);
    if (result != 1)
	return __LINE__;
    if (strcmp (s1, "ABC"))
	return __LINE__;

    return 0;
}
