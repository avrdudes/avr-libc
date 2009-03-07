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

/* Test of signbit() function.
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
# if defined(__AVR_ATmega128__)
  /* ATmega128 has enough RAM for sprintf(), print to 0x2000 in XRAM. */
#  define PRINTFLN(fmt, ...)	\
    sprintf ((char *)0x2000, "\nLine %d: " fmt "\n", __LINE__, ##__VA_ARGS__)
# else
   /* small AVR */
#  define PRINTFLN(args...)
# endif
# define EXIT	exit
#endif

union lofl_u {
    long lo;
    float fl;
};

/* Result is placed into SRAM variable, allocated at the start of
   memory. This is convinient to debug: read a core dump.	*/
volatile int v = 1;

PROGMEM const struct {		/* Table of test cases.	*/
    union lofl_u x;		/* argument	*/
    int z;			/* result	*/
} t[] = {

    /* Zero	*/
    { { .fl= +0.0 },	0 },
    { { .fl= -0.0 },	1 },
    
    /* A few of normal values	*/
    { { 0x00800000 },	0 },
    { { 0x00800001 },	0 },
    { { 0x00ffffff },	0 },
    { { 0x3f800000 },	0 },
    { { 0x7f7fffff },	0 },
    { { 0x80800000 },	1 },
    { { 0x80800001 },	1 },
    { { 0x80ffffff },	1 },
    { { 0xdf800000 },	1 },
    { { 0xff7fffff },	1 },
    
    /* Subnormal	*/
    { { 0x00000001 }, 0 },
    { { 0x00000100 }, 0 },
    { { 0x00010000 }, 0 },
    { { 0x007fffff }, 0 },
    { { 0x80000001 }, 1 },
    { { 0x80000100 }, 1 },
    { { 0x80010000 }, 1 },
    { { 0x807fffff }, 1 },

    /* Inf	*/
    { { 0x7f800000 },	0 },
    { { 0xff800000 },	1 },    

    /* NaN	*/
    { { 0x7f800001 },	0 },
    { { 0x7fc00000 },	0 },
    { { 0x7fffffff },	0 },
    { { 0xff800001 },	1 },
    { { 0xffc00000 },	1 },
    { { 0xffffffff },	1 },
};

int main ()
{
    union lofl_u x;
    int z;
    int i;
    int (* volatile vp)(double);

    /* Default implementation.	*/    
    for (i = 0; i < (int) (sizeof(t) / sizeof(t[0])); i++) {
	x.lo = pgm_read_dword (& t[i].x);
	z = pgm_read_word (& t[i].z);
	v = signbit (x.fl);
	if (v != z) {
	    PRINTFLN ("i= %d  v= %d", i, v);
	    EXIT (i + 1);
	}
    }

#ifdef	__AVR__
    /* Force to use the library implementation.	*/
    vp = & signbit;
    for (i = 0; i < (int) (sizeof(t) / sizeof(t[0])); i++) {
	x.lo = pgm_read_dword (& t[i].x);
	z = pgm_read_word (& t[i].z);
	v = vp (x.fl);
	if (v != z) {
	    PRINTFLN ("i= %d  v= %d", i, v);
	    EXIT (i + 101);
	}
    }
#else
    (void)vp;
#endif

    return 0;
}
