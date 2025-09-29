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
   POSSIBILITY OF SUCH DAMAGE. */

/* Tests for 'ftostrf'. */
#include <stdlib.h>
#include <string.h>
#include "progmem.h"
#include "ftostrf.h"

PROGMEM static const struct ftostrf_s t[] = {

/* Nonregular cases.	*/
    { { .fl = 1.0 }, 0, 0,	"1" },
    { { .fl = 0.0 }, 0, 0,	"0" },
    { { .fl = 1.1 }, 0, 1,	"1.1" },
    { { .fl = 1.2 }, 4, 1,	" 1.2" },
    { { .fl = 0.5 }, 0, 1,	"0.5" },
    { { .fl = 0.5 }, 0, 2,	"0.50" },
    { { .fl = 0.5 }, 0, 8,	"0.50000000" },
    { { .fl = 0.5 }, 0, 9,	"0.500000000" },
    { { .fl = 123.45 }, 0, 2,	"123.45" },
    { { .fl = 0.999999 }, 0, 6,	"0.999999"	},
    
    { { .fl = 1.234 }, -8, 3,	"1.234   "	},
    { { .fl = -1.234 }, -8, 3,	"-1.234  "	},

};

int main ()
{
    int i;
    for (i= 0; (size_t)i != sizeof(t)/sizeof(t[0]); i++)
	run_ftostrf (t+i, i+1);
    return 0;
}
