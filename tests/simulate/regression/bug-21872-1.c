/* bug #21872: __floatunsisf/undisf incorrectly named
   $Id$

   Idea is to force 'region text is full' in case of libgcc's conversion
   function usage.	*/

#ifdef	__AVR__

#include <avr/io.h>

/* avr-gcc 4.2.2 + Avr-libc 1.6.1, before correction:
      MIN_SIZE == 1000 --> Fault
      MIN_SIZE == 1100 --> OK
   avr-gcc 4.2.2 + Avr-libc 1.6.1, after correction:
      MIN_SIZE == 220 --> Fault
      MIN_SIZE == 230 --> OK
   avr-gcc 4.1.2 + Avr-libc 1.6.1, after correction:
      MIN_SIZE == 650 --> Fault
      MIN_SIZE == 660 --> OK	*/
#if	__GNUC__ >= 4 && __GNUC_MINOR__ >= 2
# define MIN_SIZE 400
#else
# define MIN_SIZE 850
#endif

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

int main ()
{
    volatile unsigned long vsi = 0;
    volatile float vsf;
    vsf = vsi;		/* call of conversion function	*/
    return 0;
}
