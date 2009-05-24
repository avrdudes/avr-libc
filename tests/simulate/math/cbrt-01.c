/* Copyright (c) 2009  Dmitry Xmelkov
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

/* Test of cbrt() function.
   $Id$	*/

#include <math.h>
#include <stdlib.h>
#include "progmem.h"

#ifndef	__AVR__
# include <stdio.h>
# define PRINTFLN(fmt, ...)	\
    printf ("\nLine %d: " fmt "\n", __LINE__, ##__VA_ARGS__)
# define EXIT(code)	exit ((code) < 255 ? (code) : 100 + (code) % 100)
#else
# define PRINTFLN(args...)
# define EXIT	exit
#endif

union float_u {
    float flt;
    unsigned long u32;
};

/* Result is placed into SRAM variable, allocated at the start of
   memory. This is convinient to debug: read a core dump.	*/
volatile union float_u v = {.u32 = 1};

PROGMEM const struct {
    union float_u x;
    union float_u z;
} t[] = {

    { { 0.0},	{ 0.0} },
    { {-0.0},	{-0.0} },

    /* Infinity	*/
    { {.u32 = 0x7f800000 }, {.u32 = 0x7f800000 } },
    { {.u32 = 0xff800000 }, {.u32 = 0xff800000 } },

    { { 1 },	{ 1 } },
    { {-1 },	{-1 } },
    { { 8 },	{ 2 } },
    { { 27 },	{ 3 } },
    { { 64 },	{ 4 } },
    { { 125 },	{ 5 } },
    { { 216 },	{ 6 } },
    { { 343 },	{ 7 } },
    { { 512 },	{ 8 } },
    { { 729 },	{ 9 } },
    { { 1000 },	{ 10 } },
    { {-1000 },	{-10 } },
    
    { { 0.125 }, { 0.5 } },
    { { 0.015625 }, { 0.25 } },
    { {-0.001953125 }, {-0.125 } },
};

int main ()
{
    int i;
    union float_u tx, tz;
    
    for (i = 0;  (size_t)i < sizeof(t) / sizeof(t[0]); i++) {
	tx.u32 = pgm_read_dword (& t[i].x);
	tz.u32 = pgm_read_dword (& t[i].z);
	v.flt = cbrt (tx.flt);
	if (v.u32 != tz.u32) {
	    PRINTFLN ("t1[%d]={0x%08lx,0x%08lx} --> 0x%08lx\n",
		      i, tx.u32, tz.u32, v.u32);
	    EXIT (i + 1);
	}
    }
    
    return 0;
}
