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

#include <stdlib.h>
#include <string.h>
#include "progmem.h"

#define PATTERN_SIZE	270
#include "ftostrf.h"

PROGMEM static const struct ftostrf_s t[] = {

    { { .fl = 1.2345678 }, 127, 7,
	"                                "	/* 32 */
	"                                "	/* 32 */
	"                                "	/* 32 */
	"                      1.2345678" },

    { { .fl = 1.2345678 }, -128, 7,
	"1.2345678                       "	/* 32 */
	"                                "	/* 32 */
	"                                "	/* 32 */
	"                                " },

    { { .fl = -1.2345678 }, 127, 7,
	"                                "	/* 32 */
	"                                "	/* 32 */
	"                                "	/* 32 */
	"                     -1.2345678" },

    { { .fl = -1.2345678 }, -128, 7,
	"-1.2345678                      "	/* 32 */
	"                                "	/* 32 */
	"                                "	/* 32 */
	"                                " },

    { { .fl = 12345678. }, 0, 255,
	"12345678."
	"00000000000000000000000000000000"	/* 32 */
	"00000000000000000000000000000000"	/* 32 */
	"00000000000000000000000000000000"	/* 32 */
	"00000000000000000000000000000000"	/* 32 */
	"00000000000000000000000000000000"	/* 32 */
	"00000000000000000000000000000000"	/* 32 */
	"00000000000000000000000000000000"	/* 32 */
	"0000000000000000000000000000000" },

    { { .fl = -12345678. }, 0, 255,
	"-12345678."
	"00000000000000000000000000000000"	/* 32 */
	"00000000000000000000000000000000"	/* 32 */
	"00000000000000000000000000000000"	/* 32 */
	"00000000000000000000000000000000"	/* 32 */
	"00000000000000000000000000000000"	/* 32 */
	"00000000000000000000000000000000"	/* 32 */
	"00000000000000000000000000000000"	/* 32 */
	"0000000000000000000000000000000" },

    { { .fl = .5 }, 0, 255,
	"0."
	"50000000000000000000000000000000"	/* 32 */
	"00000000000000000000000000000000"	/* 32 */
	"00000000000000000000000000000000"	/* 32 */
	"00000000000000000000000000000000"	/* 32 */
	"00000000000000000000000000000000"	/* 32 */
	"00000000000000000000000000000000"	/* 32 */
	"00000000000000000000000000000000"	/* 32 */
	"0000000000000000000000000000000" },
};

int main ()
{
    int i;
    for (i= 0; (size_t)i != sizeof(t)/sizeof(t[0]); i++)
	run_ftostrf (t+i, i+1);
    return 0;
}
