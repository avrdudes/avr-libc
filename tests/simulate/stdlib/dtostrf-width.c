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

/* Argument 'width' test.
   $Id$
 */
#include <stdlib.h>
#include <string.h>
#include "progmem.h"

#define PATTERN_SIZE	20
#include "dtostrf.h"

PROGMEM static const struct dtostrf_s t[] = {

    { { .fl = .123 }, 0, 3,	"0.123" },
    { { .fl = .123 }, 1, 3,	"0.123" },
    { { .fl = .123 }, 5, 3,	"0.123" },
    { { .fl = .123 }, 6, 3,	" 0.123" },
    { { .fl = .123 }, 10, 3,	"     0.123" },
    { { .fl = -.123 }, 10, 3,	"    -0.123" },
    
    { { .fl = 123.45 }, 0, 2,	"123.45" },
    { { .fl = 123.45 }, 1, 2,	"123.45" },
    { { .fl = 123.45 }, 6, 2,	"123.45" },
    { { .fl = 123.45 }, 7, 2,	" 123.45" },
    { { .fl = 123.45 }, 10, 2,	"    123.45" },
    { { .fl = -123.45 }, 10, 2,	"   -123.45" },

    { { .fl = 10. }, 0, 0,	"10" },
    { { .fl = 10. }, 1, 0,	"10" },
    { { .fl = 10. }, 2, 0,	"10" },
    { { .fl = 10. }, 3, 0,	" 10" },
    { { .fl = 10. }, 10, 0,	"        10" },
    { { .fl = -10. }, 10, 0,	"       -10" },

    { { .fl = .123 }, -1, 3,	"0.123" },
    { { .fl = 123.45 }, -1, 2,	"123.45" },
    { { .fl = 10. }, -1, 0,	"10" },

    { { .fl = .123 }, -10, 3,	"0.123     " },
    { { .fl = -.123 }, -10, 3,	"-0.123    " },
    { { .fl = 123.45 }, -10, 2,	"123.45    " },
    { { .fl = -123.45 }, -10, 2,"-123.45   " },
    { { .fl = 10. }, -10, 0,	"10        " },
    { { .fl = -10. }, -10, 0,	"-10       " },
};

int main ()
{
    int i;
    for (i= 0; (size_t)i != sizeof(t)/sizeof(t[0]); i++)
	run_dtostrf (t+i, i+1);
    return 0;
}
