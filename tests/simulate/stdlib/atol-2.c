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

/* This is a copy of 'atol-1.c', but without <stdlib.h>.
   The purpose is to check a native atol() function, as today (2007-02-06)
   the <stdlib.h> header substitutes an inlined version with strtol() usage.

   $Id$
 */

#include <stdio.h>
#include <string.h>
#include "progmem.h"

long atol (const char *);
void exit (int);

PROGMEM const struct {
    char s[12];
    long val;
} t[] = {

    /* Empty string	*/
    { "", 0 },
    { " ", 0 },
    { "\t\n\v\f\r", 0 },

    /* Common values	*/
    { "0", 0 },
    { "+0", 0 },
    { "-0", 0 },
    { "1", 1 },
    { "+1", 1 },
    { "-1", -1 },
    { "32767", 32767 },
    { "32768", 32768 },
    { "-32767", -32767 },
    { "-32768", -32768 },
    { "-987654321", -987654321 },
    { "+1234567890", 1234567890 },
    { "2147483647", 2147483647 },
    { "-2147483647", -2147483647 },
    { "-2147483648", 0x80000000 },
    
    /* Nonzero end character	*/
    { "12\001", 12 },
    { "123\377", 123 },
    { "1234/", 1234 },		/* '0'-1 == '/'	*/
    { "12345:", 12345 },	/* '9'+1 == ':'	*/
    { "321 4", 321 },
    
    /* Empty symbols at begin	*/
    { " -4", -4 },
    { "\t+5", 5 },
    { "\t\n\v\f\r-321", -321 },		/* bug #18899	*/
    
    /* No digits	*/
    { "\001123", 0 },
    { "\377-123", 0 },
    { "\010123", 0 },		/* '\t'-1 == 010	*/
    { "\016+123", 0 },		/* '\r'+1 == 016	*/
    
    /* atol() accepts 10-base only	*/
    { "010", 10 },
    { "0x10", 0 },
    { "0X10", 0 },
};

volatile long vlt = 1;		/* for debug conveniency	*/

void t_exit (int idx)
{
#ifdef	__AVR__
    exit (idx + 1);
#else
    printf ("result=%ld against t[%d]={\"%s\", %ld}\n",
	    vlt, idx, t[idx].s, t[idx].val);
    exit (1);
#endif
}

int main ()
{
    int i;
    char s[sizeof(t[0].s)];

    for (i = 0; i < (int)(sizeof(t) / sizeof(t[0])); i++) {
	strcpy_P (s, t[i].s);
	vlt = atol (s);
	if (vlt != (long)pgm_read_dword (& t[i].val))
	    t_exit (i);
    }
    return 0;
}
