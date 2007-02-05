/* Test of modf() function. NULL pointer.
   $Id$
 */
#include <math.h>
#include <stdlib.h>

int main ()
{
    double z;

    {
#ifdef	__AVR__
	/* Address of R1 is 0x0001	*/
	unsigned char r1;
	z = modf (257.5, 0);		/* 257 == 0x0101	*/
	asm ("mov %0,r1 \n\t clr r1" : "=r"(r1));
	if (r1)
	    exit (__LINE__);
#else
	/* Skip NULL pointer testing.	*/
	double v;
	z = modf (257.5, & v);
#endif
    }
    if (z != 0.5)
	exit (__LINE__);

    return 0;
}
