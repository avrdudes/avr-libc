/* Test of cos() function.  Nonpleasurable args.
   $Id$
 */
#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include "progmem.h"

#ifndef	__AVR__
# define PRINTFLN(fmt, ...)	\
    printf ("\nLine %d: " fmt "\n", __LINE__, ##__VA_ARGS__)
# define EXIT(code)	exit ((code) < 255 ? (code) : 100 + (code) % 100)
#else
# define PRINTFLN(args...)
# define EXIT	exit
#endif

union float_u {
    float flt;
    unsigned long u32;
};

/* Result is placed into SRAM variable, allocated at the start of
   memory. This is convinient to debug: read a core dump.	*/
volatile float vz = 1;
volatile unsigned long ve = 1;

PROGMEM const struct {		/* Table of test cases.	*/
    union float_u x;		/* argument	*/
    float z;			/* cos(x)	*/
    unsigned long maxerr;	/* max error in units of the last place	*/
} t[] = {

    /* Pi/2	*/
    { { .u32 = 0x3fc90fd9 },  1.94707189e-7,  4276 },
    { { .u32 = 0x3fc90fda },  7.54978995e-8,  8553 },
    { { .u32 = 0x3fc90fdb }, -4.37113900e-8, 17106 },
    { { .u32 = 0x3fc90fdc }, -1.62920680e-7,  4276 },
};

int main ()
{
    union float_u tx, tz;	/* from table		*/
    union float_u r;		/* calculation result	*/
    int i;
    
    for (i = 0; i < (int) (sizeof(t) / sizeof(t[0])); i++) {
	unsigned long delta;
	tx.u32 = pgm_read_dword (& t[i].x);
	tz.u32 = pgm_read_dword (& t[i].z);
	r.flt = cos (tx.flt);
	delta = r.u32 - tz.u32;
	if (delta > tz.u32 - r.u32)
	    delta = tz.u32 - r.u32;
#if 0
# ifdef  __AVR__
#  error
# endif
	/* To check the table.	*/
	printf ("t[%d]: e= %lu\n", i, delta);
#else
	if (delta > pgm_read_dword (& t[i].maxerr)) {
	    vz = r.flt;
	    ve = delta;
	    PRINTFLN ("t[%d]:\n"
		      "   tz= %.8g (0x%08lx)\n"
		      "   r = %.8g (0x%08lx), e= %lu",
		      i, tz.flt, tz.u32, r.flt, r.u32, delta);
	    EXIT (i + 1);
	}
#endif
    }
    return 0;
}
