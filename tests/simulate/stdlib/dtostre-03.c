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

    { { .fl = 1.2e-38 }, 1, 0,	"1.2e-38" },
    { { .fl = 9.9e-38 }, 1, 0,	"9.9e-38" },
    { { .fl = 1.1e-37 }, 1, 0,	"1.1e-37" },
    { { .fl = 9.9e-37 }, 1, 0,	"9.9e-37" },
    { { .fl = 1.1e-36 }, 1, 0,	"1.1e-36" },
    { { .fl = 9.9e-36 }, 1, 0,	"9.9e-36" },
    { { .fl = 1.1e-35 }, 1, 0,	"1.1e-35" },
    { { .fl = 9.9e-35 }, 1, 0,	"9.9e-35" },
    { { .fl = 1.1e-34 }, 1, 0,	"1.1e-34" },
    { { .fl = 9.9e-34 }, 1, 0,	"9.9e-34" },
    { { .fl = 1.1e-33 }, 1, 0,	"1.1e-33" },
    { { .fl = 9.9e-33 }, 1, 0,	"9.9e-33" },
    { { .fl = 1.1e-32 }, 1, 0,	"1.1e-32" },
    { { .fl = 9.9e-32 }, 1, 0,	"9.9e-32" },
    { { .fl = 1.1e-31 }, 1, 0,	"1.1e-31" },
    { { .fl = 9.9e-31 }, 1, 0,	"9.9e-31" },
    { { .fl = 1.1e-30 }, 1, 0,	"1.1e-30" },
    { { .fl = 9.9e-30 }, 1, 0,	"9.9e-30" },

    { { .fl = 1.1e-29 }, 1, 0,	"1.1e-29" },
    { { .fl = 9.9e-29 }, 1, 0,	"9.9e-29" },
    { { .fl = 1.1e-28 }, 1, 0,	"1.1e-28" },
    { { .fl = 9.9e-28 }, 1, 0,	"9.9e-28" },
    { { .fl = 1.1e-27 }, 1, 0,	"1.1e-27" },
    { { .fl = 9.9e-27 }, 1, 0,	"9.9e-27" },
    { { .fl = 1.1e-26 }, 1, 0,	"1.1e-26" },
    { { .fl = 9.9e-26 }, 1, 0,	"9.9e-26" },
    { { .fl = 1.1e-25 }, 1, 0,	"1.1e-25" },
    { { .fl = 9.9e-25 }, 1, 0,	"9.9e-25" },
    { { .fl = 1.1e-24 }, 1, 0,	"1.1e-24" },
    { { .fl = 9.9e-24 }, 1, 0,	"9.9e-24" },
    { { .fl = 1.1e-23 }, 1, 0,	"1.1e-23" },
    { { .fl = 9.9e-23 }, 1, 0,	"9.9e-23" },
    { { .fl = 1.1e-22 }, 1, 0,	"1.1e-22" },
    { { .fl = 9.9e-22 }, 1, 0,	"9.9e-22" },
    { { .fl = 1.1e-21 }, 1, 0,	"1.1e-21" },
    { { .fl = 9.9e-21 }, 1, 0,	"9.9e-21" },
    { { .fl = 1.1e-20 }, 1, 0,	"1.1e-20" },
    { { .fl = 9.9e-20 }, 1, 0,	"9.9e-20" },

    { { .fl = 1.1e-19 }, 1, 0,	"1.1e-19" },
    { { .fl = 9.9e-19 }, 1, 0,	"9.9e-19" },
    { { .fl = 1.1e-18 }, 1, 0,	"1.1e-18" },
    { { .fl = 9.9e-18 }, 1, 0,	"9.9e-18" },
    { { .fl = 1.1e-17 }, 1, 0,	"1.1e-17" },
    { { .fl = 9.9e-17 }, 1, 0,	"9.9e-17" },
    { { .fl = 1.1e-16 }, 1, 0,	"1.1e-16" },
    { { .fl = 9.9e-16 }, 1, 0,	"9.9e-16" },
    { { .fl = 1.1e-15 }, 1, 0,	"1.1e-15" },
    { { .fl = 9.9e-15 }, 1, 0,	"9.9e-15" },
    { { .fl = 1.1e-14 }, 1, 0,	"1.1e-14" },
    { { .fl = 9.9e-14 }, 1, 0,	"9.9e-14" },
    { { .fl = 1.1e-13 }, 1, 0,	"1.1e-13" },
    { { .fl = 9.9e-13 }, 1, 0,	"9.9e-13" },
    { { .fl = 1.1e-12 }, 1, 0,	"1.1e-12" },
    { { .fl = 9.9e-12 }, 1, 0,	"9.9e-12" },
    { { .fl = 1.1e-11 }, 1, 0,	"1.1e-11" },
    { { .fl = 9.9e-11 }, 1, 0,	"9.9e-11" },
    { { .fl = 1.1e-10 }, 1, 0,	"1.1e-10" },
    { { .fl = 9.9e-10 }, 1, 0,	"9.9e-10" },

    { { .fl = 1.1e-09 }, 1, 0,	"1.1e-09" },
    { { .fl = 9.9e-09 }, 1, 0,	"9.9e-09" },
    { { .fl = 1.1e-08 }, 1, 0,	"1.1e-08" },
    { { .fl = 9.9e-08 }, 1, 0,	"9.9e-08" },
    { { .fl = 1.1e-07 }, 1, 0,	"1.1e-07" },
    { { .fl = 9.9e-07 }, 1, 0,	"9.9e-07" },
    { { .fl = 1.1e-06 }, 1, 0,	"1.1e-06" },
    { { .fl = 9.9e-06 }, 1, 0,	"9.9e-06" },
    { { .fl = 1.1e-05 }, 1, 0,	"1.1e-05" },
    { { .fl = 9.9e-05 }, 1, 0,	"9.9e-05" },
    { { .fl = 1.1e-04 }, 1, 0,	"1.1e-04" },
    { { .fl = 9.9e-04 }, 1, 0,	"9.9e-04" },
    { { .fl = 1.1e-03 }, 1, 0,	"1.1e-03" },
    { { .fl = 9.9e-03 }, 1, 0,	"9.9e-03" },
    { { .fl = 1.1e-02 }, 1, 0,	"1.1e-02" },
    { { .fl = 9.9e-02 }, 1, 0,	"9.9e-02" },
    { { .fl = 1.1e-01 }, 1, 0,	"1.1e-01" },
    { { .fl = 9.9e-01 }, 1, 0,	"9.9e-01" },
    
    { { .fl = 1.1e+00 }, 1, 0,	"1.1e+00" },
    { { .fl = 9.9e+00 }, 1, 0,	"9.9e+00" },

};

int main ()
{
    int i;
    for (i= 0; (size_t)i != sizeof(t)/sizeof(t[0]); i++)
	run_dtostre (t+i, i+1);
    return 0;
}
