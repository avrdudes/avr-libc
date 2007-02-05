/* Test of float comparison, Inf.
   $Id$
 */
#include <stdio.h>
#include <stdlib.h>
#include "progmem.h"

union lofl_u {
    long lo;
    float fl;
};

PROGMEM const struct {		/* Table of test cases.	*/
    union lofl_u x, y;
    unsigned char ne;	/* x != y */
    unsigned char lt;	/* x < y  */
    unsigned char le;	/* x <= y */
    unsigned char eq;	/* x == y */
    unsigned char ge;	/* x >= y */
    unsigned char gt;	/* x > y  */
} t[] = {

    /* 0.0 and Inf, all signes	*/
    { { 0x00000000 }, { 0x7f800000 }, 1, 1, 1, 0, 0, 0	},
    { { 0x80000000 }, { 0x7f800000 }, 1, 1, 1, 0, 0, 0	},
    { { 0x00000000 }, { 0xff800000 }, 1, 0, 0, 0, 1, 1	},
    { { 0x80000000 }, { 0xff800000 }, 1, 0, 0, 0, 1, 1	},
    
    /* nonzero and +Inf	*/
    { { 0xff7fffff }, { 0x7f800000 }, 1, 1, 1, 0, 0, 0	},
    { { 0x80800000 }, { 0x7f800000 }, 1, 1, 1, 0, 0, 0	},
    { { 0x807fffff }, { 0x7f800000 }, 1, 1, 1, 0, 0, 0	},
    { { 0x80000001 }, { 0x7f800000 }, 1, 1, 1, 0, 0, 0	},
    { { 0x00000001 }, { 0x7f800000 }, 1, 1, 1, 0, 0, 0	},
    { { 0x007fffff }, { 0x7f800000 }, 1, 1, 1, 0, 0, 0	},
    { { 0x00800000 }, { 0x7f800000 }, 1, 1, 1, 0, 0, 0	},
    { { 0x7f7fffff }, { 0x7f800000 }, 1, 1, 1, 0, 0, 0	},

    /* nonzero and -Inf	*/
    { { 0xff7fffff }, { 0xff800000 }, 1, 0, 0, 0, 1, 1	},
    { { 0x80800000 }, { 0xff800000 }, 1, 0, 0, 0, 1, 1	},
    { { 0x807fffff }, { 0xff800000 }, 1, 0, 0, 0, 1, 1	},
    { { 0x80000001 }, { 0xff800000 }, 1, 0, 0, 0, 1, 1	},
    { { 0x00000001 }, { 0xff800000 }, 1, 0, 0, 0, 1, 1	},
    { { 0x007fffff }, { 0xff800000 }, 1, 0, 0, 0, 1, 1	},
    { { 0x00800000 }, { 0xff800000 }, 1, 0, 0, 0, 1, 1	},
    { { 0x7f7fffff }, { 0xff800000 }, 1, 0, 0, 0, 1, 1	},

    /* +Inf and nonzero	*/
    { { 0x7f800000 }, { 0xff7fffff }, 1, 0, 0, 0, 1, 1	},
    { { 0x7f800000 }, { 0x80800000 }, 1, 0, 0, 0, 1, 1	},
    { { 0x7f800000 }, { 0x807fffff }, 1, 0, 0, 0, 1, 1	},
    { { 0x7f800000 }, { 0x80000001 }, 1, 0, 0, 0, 1, 1	},
    { { 0x7f800000 }, { 0x00000001 }, 1, 0, 0, 0, 1, 1	},
    { { 0x7f800000 }, { 0x007fffff }, 1, 0, 0, 0, 1, 1	},
    { { 0x7f800000 }, { 0x00800000 }, 1, 0, 0, 0, 1, 1	},
    { { 0x7f800000 }, { 0x7f7fffff }, 1, 0, 0, 0, 1, 1	},

    /* -Inf and nonzero	*/
    { { 0xff800000 }, { 0xff7fffff }, 1, 1, 1, 0, 0, 0	},
    { { 0xff800000 }, { 0x80800000 }, 1, 1, 1, 0, 0, 0	},
    { { 0xff800000 }, { 0x807fffff }, 1, 1, 1, 0, 0, 0	},
    { { 0xff800000 }, { 0x80000001 }, 1, 1, 1, 0, 0, 0	},
    { { 0xff800000 }, { 0x00000001 }, 1, 1, 1, 0, 0, 0	},
    { { 0xff800000 }, { 0x007fffff }, 1, 1, 1, 0, 0, 0	},
    { { 0xff800000 }, { 0x00800000 }, 1, 1, 1, 0, 0, 0	},
    { { 0xff800000 }, { 0x7f7fffff }, 1, 1, 1, 0, 0, 0	},

    /* Inf and Inf, all signes	*/
    { { 0x7f800000 }, { 0x7f800000 }, 0, 0, 1, 1, 1, 0	},
    { { 0xff800000 }, { 0xff800000 }, 0, 0, 1, 1, 1, 0	},
    { { 0xff800000 }, { 0x7f800000 }, 1, 1, 1, 0, 0, 0	},
    { { 0x7f800000 }, { 0xff800000 }, 1, 0, 0, 0, 1, 1	},
};

unsigned char cmpno = 255;		/* to debug	*/

void x_exit (int index, unsigned char no)
{
#ifndef	__AVR__
    fprintf (stderr, "t[%d]: no= %d\n", index - 1, no);
#endif
    cmpno = no;
    exit (index ? index : -1);
}

volatile union lofl_u x, y;

int main ()
{
    int i;
    
    for (i = 0; i < (int) (sizeof(t) / sizeof(t[0])); i++) {
	x.lo = pgm_read_dword (& t[i].x);
	y.lo = pgm_read_dword (& t[i].y);
	if ((x.fl != y.fl) != pgm_read_byte (& t[i].ne))
	    x_exit (i+1, 1);
	if ((x.fl < y.fl)  != pgm_read_byte (& t[i].lt))
	    x_exit (i+1, 2);
	if ((x.fl <= y.fl) != pgm_read_byte (& t[i].le))
	    x_exit (i+1, 3);
	if ((x.fl == y.fl) != pgm_read_byte (& t[i].eq))
	    x_exit (i+1, 4);
	if ((x.fl >= y.fl) != pgm_read_byte (& t[i].ge))
	    x_exit (i+1, 5);
	if ((x.fl > y.fl)  != pgm_read_byte (& t[i].gt))
	    x_exit (i+1, 6);
    }
    return 0;
}
