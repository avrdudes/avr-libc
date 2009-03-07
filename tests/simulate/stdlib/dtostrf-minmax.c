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

/* Min and max float values.
   $Id$
 */
#include <stdlib.h>
#include <string.h>
#include "progmem.h"

#define PATTERN_SIZE	50
#include "dtostrf.h"

PROGMEM static const struct dtostrf_s t[] = {

    { { 0x00800000 }, 0, 45,
	"0.000000000000000000000000000000000000011754944"	},
    { { 0x00800000 }, 0, 44,
	"0.00000000000000000000000000000000000001175494"	},
    { { 0x00800000 }, 0, 43,
	"0.0000000000000000000000000000000000000117549"	},
    { { 0x00800000 }, 0, 42,
	"0.000000000000000000000000000000000000011755"	},
    { { 0x00800000 }, 0, 41,
	"0.00000000000000000000000000000000000001175"	},
    { { 0x00800000 }, 0, 40,
	"0.0000000000000000000000000000000000000118"	},
    { { 0x00800000 }, 0, 39,
	"0.000000000000000000000000000000000000012"	},
    { { 0x00800000 }, 0, 38,
	"0.00000000000000000000000000000000000001"	},
    { { 0x00800000 }, 0, 37,
	"0.0000000000000000000000000000000000000"	},
    { { 0x00800000 }, 0, 36,
	"0.000000000000000000000000000000000000"	},

    { { 0x80800000 }, 0, 45,
	"-0.000000000000000000000000000000000000011754944"	},
    { { 0x00800000 }, 49, 45,
	"  0.000000000000000000000000000000000000011754944"	},
    { { 0x80800000 }, 49, 45,
	" -0.000000000000000000000000000000000000011754944"	},

#ifdef	__AVR__		/* Reason: Glibc calculate all digits.	*/
    { { 0x7f7fffff }, 0, 0,
	"340282350000000000000000000000000000000" },
    { { 0xff7fffff }, 0, 0,
	"-340282350000000000000000000000000000000" },
#endif

};

int main ()
{
    int i;
    for (i= 0; (size_t)i != sizeof(t)/sizeof(t[0]); i++)
	run_dtostrf (t+i, i+1);
    return 0;
}
