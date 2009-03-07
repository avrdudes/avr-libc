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

/* Test for subnormal numbers.
   $Id$
 */
#include <stdlib.h>
#include <string.h>
#include "progmem.h"
#include "dtostre.h"

PROGMEM static const struct dtostre_s t[] = {

    { { 0x007fffff }, 7, 0,	"1.1754942e-38" },

    { { 0x00000001 }, 0, 0,	"1e-45" },
    { { 0x00000001 }, 1, 0,	"1.4e-45" },
    { { 0x00000001 }, 2, 0,	"1.40e-45" },
    { { 0x00000001 }, 3, 0,	"1.401e-45" },
    { { 0x00000001 }, 4, 0,	"1.4013e-45" },
    { { 0x00000001 }, 5, 0,	"1.40130e-45" },
/*    { { 0x00000001 }, 6, 0,	"1.401298e-45" },	*/
/*    { { 0x00000001 }, 7, 0,	"1.4012985e-45" },	*/

    { { 0x00000002 }, 0, 0,	"3e-45" },
    { { 0x00000002 }, 1, 0,	"2.8e-45" },
    { { 0x00000002 }, 2, 0,	"2.80e-45" },
    { { 0x00000002 }, 3, 0,	"2.803e-45" },
    { { 0x00000002 }, 4, 0,	"2.8026e-45" },
    { { 0x00000002 }, 5, 0,	"2.80260e-45" },
/*    { { 0x00000002 }, 6, 0,	"2.802597e-45" },	*/
/*    { { 0x00000002 }, 7, 0,	"2.8025969e-45" },	*/
};

int main ()
{
    int i;
    for (i= 0; (size_t)i != sizeof(t)/sizeof(t[0]); i++)
	run_dtostre (t+i, i+1);
    return 0;
}
