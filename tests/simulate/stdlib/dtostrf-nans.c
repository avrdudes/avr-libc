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

/* 'NaN' and 'Inf'.
   $Id$
 */
#include <stdlib.h>
#include <string.h>
#include "progmem.h"
#include "dtostrf.h"

PROGMEM static const struct dtostrf_s t[] = {

    { { 0x7f800000 }, 0, 0,	"INF"		},
    { { 0x7f800000 }, 10, 0,	"       INF"	},
    { { 0x7f800000 }, -10, 0,	"INF       "	},

    { { 0x7f800000 }, 0, 1,	"INF"		},
    { { 0x7f800000 }, 0, 255,	"INF"		},
    { { 0x7f800000 }, 4, 2,	" INF"		},

    { { 0xff800000 }, 0, 0,	"-INF"		},
    { { 0xff800000 }, 10, 0,	"      -INF"	},
    { { 0xff800000 }, -10, 0,	"-INF      "	},

    { { 0x7f800001 }, 0, 0,	"NAN"		},
    { { 0x7f800001 }, 10, 0,	"       NAN"	},
    { { 0x7f800001 }, -10, 0,	"NAN       "	},

    { { 0xff800001 }, 0, 0,	"NAN"		},    /* no '-NaN' */
    { { 0xff800001 }, 10, 0,	"       NAN"	},
    { { 0xff800001 }, -10, 0,	"NAN       "	},

    { { 0x7fffffff }, 0, 0,	"NAN" },
    { { 0xffffffff }, 0, 0,	"NAN" },
    { { 0x7fc00000 }, 0, 0,	"NAN" },
    { { 0xffc00000 }, 0, 0,	"NAN" },

    { { 0x7fc00000 }, 0, 1,	"NAN" },
    { { 0x7fc00000 }, 0, 255,	"NAN" },
    { { 0x7fc00000 }, 4, 2,	" NAN" },
};

int main ()
{
    int i;
    for (i= 0; (size_t)i != sizeof(t)/sizeof(t[0]); i++)
	run_dtostrf (t+i, i+1);
    return 0;
}
