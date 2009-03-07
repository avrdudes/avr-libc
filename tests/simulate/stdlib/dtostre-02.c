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

/* $Id */

#include <stdlib.h>
#include <string.h>
#include "progmem.h"
#include "dtostre.h"

PROGMEM static const struct dtostre_s t[] = {

    { { 0x3f800000 }, 0, 0,	"1e+00" },    
    { { 0x3f800000 }, 1, 0,	"1.0e+00" },
    { { 0x3f800000 }, 2, 0,	"1.00e+00" },
    { { 0x3f800000 }, 3, 0,	"1.000e+00" },
    { { 0x3f800000 }, 4, 0,	"1.0000e+00" },
    { { 0x3f800000 }, 5, 0,	"1.00000e+00" },
    { { 0x3f800000 }, 6, 0,	"1.000000e+00" },
    { { 0x3f800000 }, 7, 0,	"1.0000000e+00" },
    { { 0x3f800000 }, 8, 0,	"1.0000000e+00" },
    { { 0x3f800000 }, 255, 0,	"1.0000000e+00" },

    { { 0x3f800000 }, 0, DTOSTR_ALWAYS_SIGN,	" 1e+00" },    
    { { 0x3f800000 }, 0, DTOSTR_PLUS_SIGN,	"+1e+00" },    
    { { 0x3f800000 }, 0, DTOSTR_UPPERCASE,	"1E+00" },    
    { { 0x3f800000 }, 0,
	DTOSTR_ALWAYS_SIGN | DTOSTR_PLUS_SIGN | DTOSTR_UPPERCASE,
	"+1E+00" },

    { { 0xbf800000 }, 0, 0,	"-1e+00" },    
    { { 0xbf800000 }, 0, DTOSTR_ALWAYS_SIGN,	"-1e+00" },    
    { { 0xbf800000 }, 0, DTOSTR_PLUS_SIGN,	"-1e+00" },    
    { { 0xbf800000 }, 0, DTOSTR_UPPERCASE,	"-1E+00" },
    
    { { .fl = 1e-15 }, 0, 0,	"1e-15" },
    { { .fl = 1e-15 }, 1, 0,	"1.0e-15" },
    { { .fl = 1e-15 }, 2, 0,	"1.00e-15" },
    { { .fl = 1e-15 }, 3, 0,	"1.000e-15" },	/* avr-libc bug # 11820	*/
    { { .fl = 1e-15 }, 4, 0,	"1.0000e-15" },
    { { .fl = 1e-15 }, 5, 0,	"1.00000e-15" },
    { { .fl = 1e-15 }, 6, 0,	"1.000000e-15" },
    { { .fl = 1e-15 }, 7, 0,	"1.0000000e-15" },
    { { .fl = 1e-15 }, 8, 0,	"1.0000000e-15" },

    { { .fl = 1e-37 }, 0, 0,	"1e-37" },
    { { .fl = 1e-36 }, 0, 0,	"1e-36" },
    { { .fl = 1e-35 }, 0, 0,	"1e-35" },
    { { .fl = 1e-34 }, 0, 0,	"1e-34" },
    { { .fl = 1e-33 }, 0, 0,	"1e-33" },
    { { .fl = 1e-32 }, 0, 0,	"1e-32" },
    { { .fl = 1e-31 }, 0, 0,	"1e-31" },
    { { .fl = 1e-30 }, 0, 0,	"1e-30" },

    { { .fl = 1e-29 }, 0, 0,	"1e-29" },
    { { .fl = 1e-28 }, 0, 0,	"1e-28" },
    { { .fl = 1e-27 }, 0, 0,	"1e-27" },
    { { .fl = 1e-26 }, 0, 0,	"1e-26" },
    { { .fl = 1e-25 }, 0, 0,	"1e-25" },
    { { .fl = 1e-24 }, 0, 0,	"1e-24" },
    { { .fl = 1e-23 }, 0, 0,	"1e-23" },
    { { .fl = 1e-22 }, 0, 0,	"1e-22" },
    { { .fl = 1e-21 }, 0, 0,	"1e-21" },
    { { .fl = 1e-20 }, 0, 0,	"1e-20" },

    { { .fl = 1e-19 }, 0, 0,	"1e-19" },
    { { .fl = 1e-18 }, 0, 0,	"1e-18" },
    { { .fl = 1e-17 }, 0, 0,	"1e-17" },
    { { .fl = 1e-16 }, 0, 0,	"1e-16" },
    { { .fl = 1e-15 }, 0, 0,	"1e-15" },
    { { .fl = 1e-14 }, 0, 0,	"1e-14" },
    { { .fl = 1e-13 }, 0, 0,	"1e-13" },
    { { .fl = 1e-12 }, 0, 0,	"1e-12" },
    { { .fl = 1e-11 }, 0, 0,	"1e-11" },
    { { .fl = 1e-10 }, 0, 0,	"1e-10" },

    { { .fl = 1e-09 }, 0, 0,	"1e-09" },
    { { .fl = 1e-08 }, 0, 0,	"1e-08" },
    { { .fl = 1e-07 }, 0, 0,	"1e-07" },
    { { .fl = 1e-06 }, 0, 0,	"1e-06" },
    { { .fl = 1e-05 }, 0, 0,	"1e-05" },
    { { .fl = 1e-04 }, 0, 0,	"1e-04" },
    { { .fl = 1e-03 }, 0, 0,	"1e-03" },
    { { .fl = 1e-02 }, 0, 0,	"1e-02" },
    { { .fl = 1e-01 }, 0, 0,	"1e-01" },

    { { .fl = 1e+00 }, 0, 0,	"1e+00" },

    { { .fl = 1e+01 }, 0, 0,	"1e+01" },
    { { .fl = 1e+02 }, 0, 0,	"1e+02" },
    { { .fl = 1e+03 }, 0, 0,	"1e+03" },
    { { .fl = 1e+04 }, 0, 0,	"1e+04" },
    { { .fl = 1e+05 }, 0, 0,	"1e+05" },
    { { .fl = 1e+06 }, 0, 0,	"1e+06" },
    { { .fl = 1e+07 }, 0, 0,	"1e+07" },
    { { .fl = 1e+08 }, 0, 0,	"1e+08" },
    { { .fl = 1e+09 }, 0, 0,	"1e+09" },

    { { .fl = 1e+10 }, 0, 0,	"1e+10" },
    { { .fl = 1e+11 }, 0, 0,	"1e+11" },
    { { .fl = 1e+12 }, 0, 0,	"1e+12" },
    { { .fl = 1e+13 }, 0, 0,	"1e+13" },
    { { .fl = 1e+14 }, 0, 0,	"1e+14" },
    { { .fl = 1e+15 }, 0, 0,	"1e+15" },
    { { .fl = 1e+16 }, 0, 0,	"1e+16" },
    { { .fl = 1e+17 }, 0, 0,	"1e+17" },
    { { .fl = 1e+18 }, 0, 0,	"1e+18" },
    { { .fl = 1e+19 }, 0, 0,	"1e+19" },

    { { .fl = 1e+20 }, 0, 0,	"1e+20" },
    { { .fl = 1e+21 }, 0, 0,	"1e+21" },
    { { .fl = 1e+22 }, 0, 0,	"1e+22" },
    { { .fl = 1e+23 }, 0, 0,	"1e+23" },
    { { .fl = 1e+24 }, 0, 0,	"1e+24" },
    { { .fl = 1e+25 }, 0, 0,	"1e+25" },
    { { .fl = 1e+26 }, 0, 0,	"1e+26" },
    { { .fl = 1e+27 }, 0, 0,	"1e+27" },
    { { .fl = 1e+28 }, 0, 0,	"1e+28" },
    { { .fl = 1e+29 }, 0, 0,	"1e+29" },

    { { .fl = 1e+30 }, 0, 0,	"1e+30" },
    { { .fl = 1e+31 }, 0, 0,	"1e+31" },
    { { .fl = 1e+32 }, 0, 0,	"1e+32" },
    { { .fl = 1e+33 }, 0, 0,	"1e+33" },
    { { .fl = 1e+34 }, 0, 0,	"1e+34" },
    { { .fl = 1e+35 }, 0, 0,	"1e+35" },
    { { .fl = 1e+36 }, 0, 0,	"1e+36" },
    { { .fl = 1e+37 }, 0, 0,	"1e+37" },
    { { .fl = 1e+38 }, 0, 0,	"1e+38" },
};

int main ()
{
    int i;
    for (i= 0; (size_t)i != sizeof(t)/sizeof(t[0]); i++)
	run_dtostre (t+i, i+1);
    return 0;
}
