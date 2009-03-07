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

/* Case of negative zero exponent: 'e-00'.
   $Id$
 */
#include <stdlib.h>
#include <string.h>
#include "progmem.h"
#include "dtostre.h"

PROGMEM static const struct dtostre_s t[] = {

    { { 0x3f7fffff }, 0, 0,	"1e-00" },
    { { 0x3f7fffff }, 1, 0,	"1.0e-00" },
    { { 0x3f7fffff }, 2, 0,	"1.00e-00" },
    { { 0x3f7fffff }, 3, 0,	"1.000e-00" },
    { { 0x3f7fffff }, 4, 0,	"1.0000e-00" },
    { { 0x3f7fffff }, 5, 0,	"1.00000e-00" },
    { { 0x3f7fffff }, 6, 0,	"9.999999e-01" },
    { { 0x3f7fffff }, 7, 0,	"9.9999994e-01" },

    { { 0xbf7fffff }, 0, 0,	"-1e-00" },
    
    { { .fl = 0.9500001 }, 0, 0,	"1e-00" },
    { { .fl = 0.9950001 }, 1, 0,	"1.0e-00" },
    { { .fl = 0.9995001 }, 2, 0,	"1.00e-00" },
    { { .fl = 0.9999501 }, 3, 0,	"1.000e-00" },
    { { .fl = 0.9999951 }, 4, 0,	"1.0000e-00" },
    { { .fl = 0.9999996 }, 5, 0,	"1.00000e-00" },
};

int main ()
{
    int i;
    for (i= 0; (size_t)i != sizeof(t)/sizeof(t[0]); i++)
	run_dtostre (t+i, i+1);
    return 0;
}
