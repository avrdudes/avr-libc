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

/* Rounding.
   $Id$
*/
#include <stdlib.h>
#include <string.h>
#include "progmem.h"
#include "dtostre.h"

PROGMEM static const struct dtostre_s t[] = {

    { { .fl = 4.4444442 }, 7, 0,	"4.4444442e+00" },
    { { .fl = 4.4444442 }, 6, 0,	"4.444444e+00" },
    { { .fl = 4.4444442 }, 5, 0,	"4.44444e+00" },
    { { .fl = 4.4444442 }, 4, 0,	"4.4444e+00" },
    { { .fl = 4.4444442 }, 3, 0,	"4.444e+00" },
    { { .fl = 4.4444442 }, 2, 0,	"4.44e+00" },
    { { .fl = 4.4444442 }, 1, 0,	"4.4e+00" },
    { { .fl = 4.4444442 }, 0, 0,	"4e+00" },

    { { .fl = 6.6666665 }, 7, 0,	"6.6666665e+00" },
    { { .fl = 6.6666665 }, 6, 0,	"6.666667e+00" },
    { { .fl = 6.6666665 }, 5, 0,	"6.66667e+00" },
    { { .fl = 6.6666665 }, 4, 0,	"6.6667e+00" },
    { { .fl = 6.6666665 }, 3, 0,	"6.667e+00" },
    { { .fl = 6.6666665 }, 2, 0,	"6.67e+00" },
    { { .fl = 6.6666665 }, 1, 0,	"6.7e+00" },
    { { .fl = 6.6666665 }, 0, 0,	"7e+00" },
    
    { { .fl = 9.999999 }, 6, 0,		"9.999999e+00" },
    { { .fl = 9.999999 }, 5, 0,		"1.00000e+01" },
    { { .fl = 9.999999 }, 4, 0,		"1.0000e+01" },
    { { .fl = 9.999999 }, 3, 0,		"1.000e+01" },
    { { .fl = 9.999999 }, 2, 0,		"1.00e+01" },
    { { .fl = 9.999999 }, 1, 0,		"1.0e+01" },
    { { .fl = 9.999999 }, 0, 0,		"1e+01" },
    
    { { .fl = 1.2341233 }, 7, 0,	"1.2341233e+00" },
    { { .fl = 1.2341233 }, 6, 0,	"1.234123e+00" },
    { { .fl = 1.2341233 }, 5, 0,	"1.23412e+00" },
    { { .fl = 1.2341233 }, 4, 0,	"1.2341e+00" },
    { { .fl = 1.2341233 }, 3, 0,	"1.234e+00" },
    { { .fl = 1.2341233 }, 2, 0,	"1.23e+00" },
    { { .fl = 1.2341233 }, 1, 0,	"1.2e+00" },
    { { .fl = 1.2341233 }, 0, 0,	"1e+00" },

    { { .fl = 5.6789565 }, 7, 0,	"5.6789565e+00" },
    { { .fl = 5.6789565 }, 6, 0,	"5.678957e+00" },
    { { .fl = 5.6789565 }, 5, 0,	"5.67896e+00" },
    { { .fl = 5.6789565 }, 4, 0,	"5.6790e+00" },
    { { .fl = 5.6789565 }, 3, 0,	"5.679e+00" },
    { { .fl = 5.6789565 }, 2, 0,	"5.68e+00" },
    { { .fl = 5.6789565 }, 1, 0,	"5.7e+00" },
    { { .fl = 5.6789565 }, 0, 0,	"6e+00" },

};

int main ()
{
    int i;
    for (i= 0; (size_t)i != sizeof(t)/sizeof(t[0]); i++)
	run_dtostre (t+i, i+1);
    return 0;
}
