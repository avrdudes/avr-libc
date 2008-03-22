/* Bug: isinf() produces too large code with GCC 4.3.0
   $Id$

   GCC 4.3.0 unrolls the isinf() function with call of __unordsf2().
   The testing method is to force 'region text is full' in case
   of libgcc's __unordsf2() function usage.	*/

#ifdef	__AVR__

#include <avr/io.h>

/* Sufficient MIN_SIZE value:
     200   avr-gcc 4.1.2, ATmega128
     700   avr-gcc 4.3.0, ATmega128, before fixing
     280   avr-gcc 4.3.0, ATmega128, after fixing of this bug
 */
#define MIN_SIZE 320

#define NWORDS	((FLASHEND - _VECTORS_SIZE - MIN_SIZE)/2)
void very_big_function (void)
{
    asm volatile (
	".rept	(%0)*256 + %1	\n\t"
	"nop			\n\t"
	".endr "
	:: "M" (NWORDS / 256),
	   "M" (NWORDS % 256)
    );
}

#endif

int isinf (double);

int main ()
{
    static volatile double x;
    return isinf (x);
}
