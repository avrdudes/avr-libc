/* Test of __unordsf2() function (used by GCC 4.3.0), Infs.
   $Id$
 */
#include <stdio.h>
#include <stdlib.h>
#include "progmem.h"

#ifdef	__AVR__
extern int __unordsf2 (float, float);
# define UNORDSF2	__unordsf2
# define EXIT		exit
#else
# include <math.h>
# define UNORDSF2	isunordered
# define EXIT(x)	exit ((x) < 255 ? (x) : 255)
#endif

union lofl_u {
    long lo;
    float fl;
};

PROGMEM const struct {		/* Table of test cases.	*/
    union lofl_u x, y;
    unsigned char z;		/* result	*/
} t[] = {

    /* 0.0 and Inf, all signes	*/
    { { 0x00000000 }, { 0x7f800000 }, 0	},
    { { 0x80000000 }, { 0x7f800000 }, 0	},
    { { 0x00000000 }, { 0xff800000 }, 0	},
    { { 0x80000000 }, { 0xff800000 }, 0	},
    
    /* nonzero and +Inf	*/
    { { 0xff7fffff }, { 0x7f800000 }, 0	},
    { { 0x80800000 }, { 0x7f800000 }, 0	},
    { { 0x807fffff }, { 0x7f800000 }, 0	},
    { { 0x80000001 }, { 0x7f800000 }, 0	},
    { { 0x00000001 }, { 0x7f800000 }, 0	},
    { { 0x007fffff }, { 0x7f800000 }, 0	},
    { { 0x00800000 }, { 0x7f800000 }, 0	},
    { { 0x7f7fffff }, { 0x7f800000 }, 0	},

    /* nonzero and -Inf	*/
    { { 0xff7fffff }, { 0xff800000 }, 0	},
    { { 0x80800000 }, { 0xff800000 }, 0	},
    { { 0x807fffff }, { 0xff800000 }, 0	},
    { { 0x80000001 }, { 0xff800000 }, 0	},
    { { 0x00000001 }, { 0xff800000 }, 0	},
    { { 0x007fffff }, { 0xff800000 }, 0	},
    { { 0x00800000 }, { 0xff800000 }, 0	},
    { { 0x7f7fffff }, { 0xff800000 }, 0	},

    /* +Inf and nonzero	*/
    { { 0x7f800000 }, { 0xff7fffff }, 0	},
    { { 0x7f800000 }, { 0x80800000 }, 0	},
    { { 0x7f800000 }, { 0x807fffff }, 0	},
    { { 0x7f800000 }, { 0x80000001 }, 0	},
    { { 0x7f800000 }, { 0x00000001 }, 0	},
    { { 0x7f800000 }, { 0x007fffff }, 0	},
    { { 0x7f800000 }, { 0x00800000 }, 0	},
    { { 0x7f800000 }, { 0x7f7fffff }, 0	},

    /* -Inf and nonzero	*/
    { { 0xff800000 }, { 0xff7fffff }, 0	},
    { { 0xff800000 }, { 0x80800000 }, 0	},
    { { 0xff800000 }, { 0x807fffff }, 0	},
    { { 0xff800000 }, { 0x80000001 }, 0	},
    { { 0xff800000 }, { 0x00000001 }, 0	},
    { { 0xff800000 }, { 0x007fffff }, 0	},
    { { 0xff800000 }, { 0x00800000 }, 0	},
    { { 0xff800000 }, { 0x7f7fffff }, 0	},

    /* Inf and Inf, all signes	*/
    { { 0x7f800000 }, { 0x7f800000 }, 0	},
    { { 0xff800000 }, { 0xff800000 }, 0	},
    { { 0xff800000 }, { 0x7f800000 }, 0	},
    { { 0x7f800000 }, { 0xff800000 }, 0	},
};

volatile union lofl_u x, y;

int main ()
{
    int i;
    unsigned char z;
    
    for (i = 0; i < (int) (sizeof(t) / sizeof(t[0])); i++) {
	x.lo = pgm_read_dword (& t[i].x);
	y.lo = pgm_read_dword (& t[i].y);
	z = UNORDSF2 (x.fl, y.fl) ? 1 : 0;
	if (z != pgm_read_byte (& t[i].z))
	    EXIT (i + 1);
    }
    return 0;
}
