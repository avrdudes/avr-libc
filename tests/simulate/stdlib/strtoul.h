/* Copyright (c) 2007  Dmitry Xmelkov
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

/* $Id$	*/

#include <errno.h>
#include <limits.h>
#include <stdlib.h>
#ifndef	__AVR__
# include <stdio.h>
#endif
#ifndef	EINVAL		/* Addition for errno.h in AVR-LibC-1.2.0	*/
# define EINVAL	22	/* Invalid argument	*/
#endif

static int
t_strtoul (const char *s, int base, unsigned long ret, int err, int len)
{
    char * endptr;
    
    errno = 0;
    endptr = (char *)s - 1;		/* invalid value	*/
    if (strtoul (s, & endptr, base) != ret
	|| errno != err
#ifdef	__AVR__
	|| endptr - s != len)
#else		/* Glibc 2.3.1 is not set endptr in the case of EINVAL	*/
	|| (errno != EINVAL && (endptr - s) != len) )
#endif
    {
#ifndef	__AVR__
	printf ("strtoul(\"%s\",,%d): %lu, errno: %d, len: %d\n",
	    s, base, strtoul(s, & endptr, base), errno, endptr - s);
#endif
	return 1;
    }
    return 0;
}
