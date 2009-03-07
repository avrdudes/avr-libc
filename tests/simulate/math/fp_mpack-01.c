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

/* Test of __fp_mpack() function. This is an internal function of Avr-libc.
   $Id$
 */
#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include "progmem.h"

#ifndef	__AVR__
# define PRINTFLN(fmt, ...)	\
    printf ("\nLine %d: " fmt "\n", __LINE__, ##__VA_ARGS__)
# define EXIT(code)	exit ((code) < 255 ? (code) : 100 + (code) % 100)
#else
# define PRINTFLN(args...)
# define EXIT	exit
#endif

/* Result is placed into SRAM variable, allocated at the start of
   memory. This is convinient to debug: read a core dump.	*/
volatile unsigned long v = 1;

PROGMEM const struct {		/* Table of test cases.	*/
    unsigned long x;		/* argument		*/
    unsigned long z;			/* __fp_mpack(x)	*/
} t[] = {

    /* zero	*/
    { 0x00000000, 0x00000000 },
    
    /* subnormal, where shift to right is needed	*/
    { 0x00000001, 0x00000000 },
    { 0x00000002, 0x00000001 },
    { 0x00000080, 0x00000040 },
    { 0x00000100, 0x00000080 },
    { 0x00008000, 0x00004000 },
    { 0x00010000, 0x00008000 },
    { 0x007fffff, 0x003fffff },
    { 0x00800000, 0x00400000 },
    { 0x00ff0000, 0x007f8000 },
    { 0x00fffffe, 0x007fffff },
    { 0x00ffffff, 0x007fffff },

    /* "common" subnormal	*/
    { 0x01000000, 0x00000000 },
    { 0x01000001, 0x00000001 },
    { 0x01000100, 0x00000100 },
    { 0x01010000, 0x00010000 },
    { 0x01234567, 0x00234567 },
    { 0x017fffff, 0x007fffff },

    /* normal, exp == 1	*/
    { 0x01800000, 0x00800000 },
    { 0x01800001, 0x00800001 },
    { 0x01800100, 0x00800100 },
    { 0x01810000, 0x00810000 },
    { 0x01ffffff, 0x00ffffff },

    /* normal, exp > 1	*/
    { 0x02800000, 0x01000000 },
    { 0x02800001, 0x01000001 },
    { 0x02800100, 0x01000100 },
    { 0x02810000, 0x01010000 },
    { 0xfeffffff, 0x7f7fffff },

    /* Inf	*/
    { 0xff000000, 0x7f800000 },
    
    /* NaN	*/
    { 0xff000001, 0x7f800001 },
    { 0xff000100, 0x7f800100 },
    { 0xff400000, 0x7fc00000 },
    { 0xff7fffff, 0x7fffffff },
};

#ifdef	__AVR__
extern unsigned long __fp_mpack (unsigned long);
unsigned long fp_mpack (unsigned long x)
{
    asm volatile ("clt");
    return __fp_mpack (x);
}
#else
unsigned long fp_mpack (unsigned long x)
{
    int exp = x >> 24;
    unsigned long mnt = x & 0xffffff;
    
    if (exp == 0) {
	return mnt >> 1;
    } else if (exp == 1 && mnt < 0x800000) {
	return mnt;
    } else if (exp < 255) {
	return (exp << 23) | (mnt & 0x7fffff);
    } else {
	return 0x7f800000 | mnt;
    }
}
#endif

int main ()
{
    int i;
    
    for (i = 0; i < (int) (sizeof(t) / sizeof(t[0])); i++) {
	unsigned long tx = pgm_read_dword (& t[i].x);
	unsigned long tz = pgm_read_dword (& t[i].z);
	v = fp_mpack (tx);
	if (v != tz) {
	    PRINTFLN ("t[%d]= {0x%08lx,0x%08lx} --> 0x%08lx\n", i, tx, tz, v);
	    EXIT (i + 1);
	}
    }

    return 0;
}
