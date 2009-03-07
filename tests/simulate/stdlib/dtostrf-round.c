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

/* Test of extra rounding.
   $Id$
 */
#include <stdlib.h>
#include <string.h>
#include "progmem.h"
#include "dtostrf.h"

PROGMEM static const struct dtostrf_s t[] = {

    { { .fl = .46 }, 0, 3,	"0.460"	},
    { { .fl = .46 }, 0, 2,	"0.46"	},
    { { .fl = .46 }, 0, 1,	"0.5"	},
    { { .fl = .46 }, 0, 0,	"0"	}, /* just that very case */
    { { .fl = .46 }, 1, 0,	"0"	},
    { { .fl = .46 }, 2, 0,	" 0"	},

    { { .fl = .51 }, 0, 3,	"0.510"	},
    { { .fl = .51 }, 0, 2,	"0.51"	},
    { { .fl = .51 }, 0, 1,	"0.5"	},
    { { .fl = .51 }, 0, 0,	"1"	},
    { { .fl = .51 }, 1, 0,	"1"	},
    { { .fl = .51 }, 2, 0,	" 1"	},

    { { .fl = .58 }, 0, 3,	"0.580"	},
    { { .fl = .58 }, 0, 2,	"0.58"	},
    { { .fl = .58 }, 0, 1,	"0.6"	},
    { { .fl = .58 }, 0, 0,	"1"	},
    { { .fl = .58 }, 1, 0,	"1"	},
    { { .fl = .58 }, 2, 0,	" 1"	},
    
    { { .fl = 0.4999 }, 0, 4,	"0.4999"},
    { { .fl = 0.4999 }, 0, 3,	"0.500"	},
    { { .fl = 0.4999 }, 0, 2,	"0.50"	},
    { { .fl = 0.4999 }, 0, 1,	"0.5"	},
    { { .fl = 0.4999 }, 0, 0,	"0"	},

    { { .fl = 0.049 }, 0, 2,	"0.05"	},
    { { .fl = 0.049 }, 0, 1,	"0.0"	},
    { { .fl = 0.049 }, 0, 0,	"0"	},

    { { .fl = 0.0000000000049 }, 0, 12,	"0.000000000005"},
    { { .fl = 0.0000000000049 }, 0, 11,	"0.00000000000"	},
    { { .fl = 0.0000000000049 }, 0, 10,	"0.0000000000"	},
    
    { { .fl = 0.0000000000051 }, 0, 12,	"0.000000000005"},
    { { .fl = 0.0000000000051 }, 0, 11,	"0.00000000001"	},
    { { .fl = 0.0000000000051 }, 0, 10,	"0.0000000000"	},
    
};

int main ()
{
    int i;
    for (i= 0; (size_t)i != sizeof(t)/sizeof(t[0]); i++)
	run_dtostrf (t+i, i+1);
    return 0;
}
