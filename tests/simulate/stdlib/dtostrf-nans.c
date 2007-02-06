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
