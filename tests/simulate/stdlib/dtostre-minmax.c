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

/* $Id$ */

#include <stdlib.h>
#include <string.h>
#include "progmem.h"
#include "dtostre.h"

PROGMEM static const struct dtostre_s t[] = {

    { { 0x00800000 }, 0, 0,	"1e-38" },
    { { 0x00800000 }, 1, 0,	"1.2e-38" },
    { { 0x00800000 }, 2, 0,	"1.18e-38" },
    { { 0x00800000 }, 3, 0,	"1.175e-38" },
    { { 0x00800000 }, 4, 0,	"1.1755e-38" },
    { { 0x00800000 }, 5, 0,	"1.17549e-38" },
    { { 0x00800000 }, 6, 0,	"1.175494e-38" },
    { { 0x00800000 }, 7, 0,	"1.1754944e-38" },

    { { 0x00800001 }, 7, 0,	"1.1754945e-38" },
    { { 0x00800002 }, 7, 0,	"1.1754946e-38" },
    { { 0x00800003 }, 7, 0,	"1.1754948e-38" },
    { { 0x00800004 }, 7, 0,	"1.1754949e-38" },
    
    { { 0x7f7fffff }, 0, 0,	"3e+38" },
    { { 0x7f7fffff }, 1, 0,	"3.4e+38" },
    { { 0x7f7fffff }, 2, 0,	"3.40e+38" },
    { { 0x7f7fffff }, 3, 0,	"3.403e+38" },
    { { 0x7f7fffff }, 4, 0,	"3.4028e+38" },
    { { 0x7f7fffff }, 5, 0,	"3.40282e+38" },
    { { 0x7f7fffff }, 6, 0,	"3.402823e+38" },
    { { 0x7f7fffff }, 7, 0,	"3.4028235e+38" },

    { { 0x7f7ffffe }, 7, 0,	"3.4028233e+38" },
    { { 0x7f7ffffd }, 7, 0,	"3.4028231e+38" },
    { { 0x7f7ffffc }, 7, 0,	"3.4028229e+38" },
    { { 0x7f7ffffb }, 7, 0,	"3.4028227e+38" },
};

int main ()
{
    int i;
    for (i= 0; (size_t)i != sizeof(t)/sizeof(t[0]); i++)
	run_dtostre (t+i, i+1);
    return 0;
}
