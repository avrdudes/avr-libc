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

/* Base test.
   $Id$
 */
#include <stdlib.h>
#include <string.h>
#include "progmem.h"
#include "strtol.h"

PROGMEM static const struct t_s {
    char s[14];		/* string to convert	*/
    int base;
    long ret;		/* result must	*/
    int err;		/* errno must	*/
    unsigned char len;	/* endptr displacement must	*/
} t[] = {
    { "", 0,	    0, 0, 0 },
    { "-", 0,	    0, 0, 0 },
    { "+", 0,	    0, 0, 0 },
    { "    ", 0,    0, 0, 0 },

#ifdef	__AVR__		/* AVR: errno is't set in case of invalid base	*/
    { "", -1,	    0, 0, 0 },
    { "0", 1,	    0, 0, 0 },
    { "123", 37,    0, 0, 0 },
#else
    { "", -1,	    0, EINVAL, 0 },
    { "0", 1,	    0, EINVAL, 0 },
    { "123", 37,    0, EINVAL, 0 },
#endif
	
    { "0", 0,	    0, 0, 1 },
    { "0 ", 0,	    0, 0, 1 },
    { " 0", 0,	    0, 0, 2 },
    { "\t0", 0,	    0, 0, 2 },
    { " \t 0", 0,   0, 0, 4 },
    { "0x0", 0,	    0, 0, 3 },
    { "0000", 0,    0, 0, 4 },
    { "+0", 0,	    0, 0, 2 },
    { "-0", 0,	    0, 0, 2 },
	
    { "0x", 0,	    0, 0, 1 },
    { "0x", 16,	    0, 0, 1 },
    { "0X", 0,	    0, 0, 1 },
    { " 0x", 0,	    0, 0, 2 },
    { "0xx", 0,	    0, 0, 1 },
    { "-0x", 0,	    0, 0, 2 },
    { "-0x", 16,    0, 0, 2 },
    { "+0x", 0,	    0, 0, 2 },
	
    { "1", 0,	    1, 0, 1 },
    { "-1", 0,	    -1, 0, 2 },

    { "210", 3,	    2*9 + 1*3 + 0,		0, 3 },
    { "a98", 11,    10*11*11L + 9*11 + 8,	0, 3 },
    { "xyz", 36,    33*36*36L + 34*36 + 35,	0, 3 },
	
    { "12345", 8,    012345, 0, 5 },
    { "12345", 10,    12345, 0, 5 },
    { "12345", 16,    0x12345, 0, 5 },
};

int main ()
{
    struct t_s tt;
    int i;
    
    for (i = 0; i != (int)(sizeof(t)/sizeof(t[0])); i++) {
	memcpy_P (&tt, t+i, sizeof(tt));
	if (t_strtol (tt.s, tt.base, tt.ret, tt.err, tt.len))
	    exit (i+1);
    }
    return 0;
}
