/* Test of __unordsf2() function (used by GCC 4.3.0), NaNs.
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

    /* NaNs and 1.0	*/
    { { 0x7f800001 }, { 0x3f800000 }, 1	},
    { { 0x7f800100 }, { 0x3f800000 }, 1	},
    { { 0x7f810000 }, { 0x3f800000 }, 1	},
    { { 0x7fffffff }, { 0x3f800000 }, 1	},
    { { 0xff800001 }, { 0x3f800000 }, 1	},
    { { 0xff800100 }, { 0x3f800000 }, 1	},
    { { 0xff810000 }, { 0x3f800000 }, 1	},
    { { 0xffffffff }, { 0x3f800000 }, 1	},
    
    /* 1.0 and NaNs	*/
    { { 0x3f800000 }, { 0x7f800001 }, 1	},
    { { 0x3f800000 }, { 0x7f800100 }, 1	},
    { { 0x3f800000 }, { 0x7f810000 }, 1	},
    { { 0x3f800000 }, { 0x7fffffff }, 1	},
    { { 0x3f800000 }, { 0xff800001 }, 1	},
    { { 0x3f800000 }, { 0xff800100 }, 1	},
    { { 0x3f800000 }, { 0xff810000 }, 1	},
    { { 0x3f800000 }, { 0xffffffff }, 1	},

    /* NaN and normal/Inf	*/
    { { 0x7fc00000 }, { 0xff800000 }, 1	},    
    { { 0x7fc00000 }, { 0xff7fffff }, 1	},    
    { { 0x7fc00000 }, { 0x80800000 }, 1	},    
    { { 0x7fc00000 }, { 0x807fffff }, 1	},    
    { { 0x7fc00000 }, { 0x80000001 }, 1	},    
    { { 0x7fc00000 }, { 0x80000000 }, 1	},    
    { { 0x7fc00000 }, { 0x00000000 }, 1	},    
    { { 0x7fc00000 }, { 0x00000001 }, 1	},    
    { { 0x7fc00000 }, { 0x007fffff }, 1	},    
    { { 0x7fc00000 }, { 0x00800000 }, 1	},    
    { { 0x7fc00000 }, { 0x7f7fffff }, 1	},    
    { { 0x7fc00000 }, { 0x7f800000 }, 1	},    

    /* normal/Inf and NaN	*/
    { { 0xff800000 }, { 0x7fc00000 }, 1	},    
    { { 0xff7fffff }, { 0x7fc00000 }, 1	},    
    { { 0x80800000 }, { 0x7fc00000 }, 1	},    
    { { 0x807fffff }, { 0x7fc00000 }, 1	},    
    { { 0x80000001 }, { 0x7fc00000 }, 1	},    
    { { 0x80000000 }, { 0x7fc00000 }, 1	},    
    { { 0x00000000 }, { 0x7fc00000 }, 1	},    
    { { 0x00000001 }, { 0x7fc00000 }, 1	},    
    { { 0x007fffff }, { 0x7fc00000 }, 1	},    
    { { 0x00800000 }, { 0x7fc00000 }, 1	},    
    { { 0x7f7fffff }, { 0x7fc00000 }, 1	},    
    { { 0x7f800000 }, { 0x7fc00000 }, 1	},    

    /* NaN and NaN	*/
    { { 0x7f800001 }, { 0x7f800001 }, 1	},
    { { 0xffffffff }, { 0xffffffff }, 1	},
    { { 0x7fc00000 }, { 0xffc00000 }, 1	},
    { { 0xffc00000 }, { 0x7fc00000 }, 1	},
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
