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

/* First and last value for each ftoa_engine's table entry.
   $Id$
*/
#include <stdlib.h>
#include <string.h>
#include "progmem.h"
#include "dtostre.h"

PROGMEM static const struct dtostre_s t[] = {

    { { 0x03ffffff }, 7, 0,	"1.5046327e-36" },

    { { 0x04000000 }, 7, 0,	"1.5046328e-36" },
    { { 0x07ffffff }, 7, 0,	"3.8518597e-34" },

    { { 0x08000000 }, 7, 0,	"3.8518599e-34" },
    { { 0x0bffffff }, 7, 0,	"9.8607607e-32" },

    { { 0x0c000000 }, 7, 0,	"9.8607613e-32" },
    { { 0x0fffffff }, 7, 0,	"2.5243547e-29" },

    { { 0x10000000 }, 7, 0,	"2.5243549e-29" },
    { { 0x13ffffff }, 7, 0,	"6.4623482e-27" },

    { { 0x14000000 }, 7, 0,	"6.4623485e-27" },
    { { 0x17ffffff }, 7, 0,	"1.6543611e-24" },

    { { 0x18000000 }, 7, 0,	"1.6543612e-24" },
    { { 0x1bffffff }, 7, 0,	"4.2351645e-22" },

    { { 0x1c000000 }, 7, 0,	"4.2351647e-22" },
    { { 0x1fffffff }, 7, 0,	"1.0842021e-19" },

    { { 0x20000000 }, 7, 0,	"1.0842022e-19" },
    { { 0x23ffffff }, 7, 0,	"2.7755574e-17" },

    { { 0x24000000 }, 7, 0,	"2.7755576e-17" },
    { { 0x27ffffff }, 7, 0,	"7.1054269e-15" },

    { { 0x28000000 }, 7, 0,	"7.1054274e-15" },
    { { 0x2bffffff }, 7, 0,	"1.8189893e-12" },

    { { 0x2c000000 }, 7, 0,	"1.8189894e-12" },
    { { 0x2fffffff }, 7, 0,	"4.6566126e-10" },

    { { 0x30000000 }, 7, 0,	"4.6566129e-10" },
    { { 0x33ffffff }, 7, 0,	"1.1920928e-07" },

    { { 0x34000000 }, 7, 0,	"1.1920929e-07" },
    { { 0x37ffffff }, 7, 0,	"3.0517576e-05" },

    { { 0x38000000 }, 7, 0,	"3.0517578e-05" },
    { { 0x3bffffff }, 7, 0,	"7.8124995e-03" },

    { { 0x3c000000 }, 7, 0,	"7.8125000e-03" },
    { { 0x3fffffff }, 7, 0,	"1.9999999e+00" },

    { { 0x40000000 }, 7, 0,	"2.0000000e+00" },
    { { 0x43ffffff }, 7, 0,	"5.1199997e+02" },

    { { 0x44000000 }, 7, 0,	"5.1200000e+02" },
    { { 0x47ffffff }, 7, 0,	"1.3107199e+05" },

    { { 0x48000000 }, 7, 0,	"1.3107200e+05" },
    { { 0x4bffffff }, 7, 0,	"3.3554430e+07" },

    { { 0x4c000000 }, 7, 0,	"3.3554432e+07" },
    { { 0x4fffffff }, 7, 0,	"8.5899341e+09" },

    { { 0x50000000 }, 7, 0,	"8.5899346e+09" },
    { { 0x53ffffff }, 7, 0,	"2.1990231e+12" },

    { { 0x54000000 }, 7, 0,	"2.1990233e+12" },
    { { 0x57ffffff }, 7, 0,	"5.6294992e+14" },

    { { 0x58000000 }, 7, 0,	"5.6294995e+14" },
    { { 0x5bffffff }, 7, 0,	"1.4411518e+17" },

    { { 0x5c000000 }, 7, 0,	"1.4411519e+17" },
    { { 0x5fffffff }, 7, 0,	"3.6893486e+19" },

    { { 0x60000000 }, 7, 0,	"3.6893488e+19" },
    { { 0x63ffffff }, 7, 0,	"9.4447324e+21" },

    { { 0x64000000 }, 7, 0,	"9.4447330e+21" },
    { { 0x67ffffff }, 7, 0,	"2.4178515e+24" },

    { { 0x68000000 }, 7, 0,	"2.4178516e+24" },
    { { 0x6bffffff }, 7, 0,	"6.1896998e+26" },

    { { 0x6c000000 }, 7, 0,	"6.1897002e+26" },
    { { 0x6fffffff }, 7, 0,	"1.5845632e+29" },

    { { 0x70000000 }, 7, 0,	"1.5845633e+29" },
    { { 0x73ffffff }, 7, 0,	"4.0564817e+31" },

    { { 0x74000000 }, 7, 0,	"4.0564819e+31" },
    { { 0x77ffffff }, 7, 0,	"1.0384593e+34" },

    { { 0x78000000 }, 7, 0,	"1.0384594e+34" },
    { { 0x7bffffff }, 7, 0,	"2.6584558e+36" },

    { { 0x7c000000 }, 7, 0,	"2.6584560e+36" },

};

int main ()
{
    int i;
    for (i= 0; (size_t)i != sizeof(t)/sizeof(t[0]); i++)
	run_dtostre (t+i, i+1);
    return 0;
}
