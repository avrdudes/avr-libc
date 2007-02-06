/* Tests for 'dtostrf'.
   $Id$
*/
#include <stdlib.h>
#include <string.h>
#include "progmem.h"
#include "dtostrf.h"

PROGMEM static const struct dtostrf_s t[] = {

/* Nonregular cases.	*/
    { { .fl = 1.0 }, 0, 0,	"1" },
    { { .fl = 0.0 }, 0, 0,	"0" },
    { { .fl = 1.1 }, 0, 1,	"1.1" },
    { { .fl = 1.2 }, 4, 1,	" 1.2" },
    { { .fl = 0.5 }, 0, 1,	"0.5" },
    { { .fl = 0.5 }, 0, 2,	"0.50" },
    { { .fl = 0.5 }, 0, 8,	"0.50000000" },
    { { .fl = 0.5 }, 0, 9,	"0.500000000" },
    { { .fl = 123.45 }, 0, 2,	"123.45" },
    { { .fl = 0.999999 }, 0, 6,	"0.999999"	},
    
    { { .fl = 1.234 }, -8, 3,	"1.234   "	},
    { { .fl = -1.234 }, -8, 3,	"-1.234  "	},

};

int main ()
{
    int i;
    for (i= 0; (size_t)i != sizeof(t)/sizeof(t[0]); i++)
	run_dtostrf (t+i, i+1);
    return 0;
}
