/* bug #21955: pgm_read_xxxx() does not use enhanced LPM instruction
   $Id$

   Idea is to force 'region text is full': pgm_read_word() takes 5 words
   in case of classic LPM, and takes 2 words with enhanced LPM.	*/

#ifndef	__AVR__

/* There are not sense to check host computer.	*/
int main ()
{
    return 0;
}

#else

#include <avr/io.h>
#include <avr/pgmspace.h>

/* avr-gcc 4.1.2, Avr-libc 1.6.1, main() contains only 1 line with
   pgm_read_word, bytes:
      MIN_SIZE == 90  --> Fault
      MIN_SIZE == 100 --> OK
   So, for 50 lines it would:
      100 + 8*49 =  492  for enhanced
      100 + 14*49 = 786  for enhanced
   No use __AVR_HAVE_LPMX__ for preprocessing.	*/
#if  (__AVR_ARCH__ == 2) || (__AVR_ARCH__ == 3)
# define MIN_SIZE 940
#else
# define MIN_SIZE 640
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


int main ()
{
    volatile int rslt;
    int addr = 0;

    /* 10*4 words with enhanced LPM
       10*7 words with classic LPM	*/
    addr = pgm_read_word (addr) & 0x7FF;
    addr = pgm_read_word (addr) & 0x7FF;
    addr = pgm_read_word (addr) & 0x7FF;
    addr = pgm_read_word (addr) & 0x7FF;
    addr = pgm_read_word (addr) & 0x7FF;
    addr = pgm_read_word (addr) & 0x7FF;
    addr = pgm_read_word (addr) & 0x7FF;
    addr = pgm_read_word (addr) & 0x7FF;
    addr = pgm_read_word (addr) & 0x7FF;
    addr = pgm_read_word (addr) & 0x7FF;		/* 10 */

    /* 10*4 words with enhanced LPM
       10*7 words with classic LPM	*/
    addr = pgm_read_word (addr) & 0x7FF;
    addr = pgm_read_word (addr) & 0x7FF;
    addr = pgm_read_word (addr) & 0x7FF;
    addr = pgm_read_word (addr) & 0x7FF;
    addr = pgm_read_word (addr) & 0x7FF;
    addr = pgm_read_word (addr) & 0x7FF;
    addr = pgm_read_word (addr) & 0x7FF;
    addr = pgm_read_word (addr) & 0x7FF;
    addr = pgm_read_word (addr) & 0x7FF;
    addr = pgm_read_word (addr) & 0x7FF;		/* 20 */

    /* 10*4 words with enhanced LPM
       10*7 words with classic LPM	*/
    addr = pgm_read_word (addr) & 0x7FF;
    addr = pgm_read_word (addr) & 0x7FF;
    addr = pgm_read_word (addr) & 0x7FF;
    addr = pgm_read_word (addr) & 0x7FF;
    addr = pgm_read_word (addr) & 0x7FF;
    addr = pgm_read_word (addr) & 0x7FF;
    addr = pgm_read_word (addr) & 0x7FF;
    addr = pgm_read_word (addr) & 0x7FF;
    addr = pgm_read_word (addr) & 0x7FF;
    addr = pgm_read_word (addr) & 0x7FF;		/* 30 */

    /* 10*4 words with enhanced LPM
       10*7 words with classic LPM	*/
    addr = pgm_read_word (addr) & 0x7FF;
    addr = pgm_read_word (addr) & 0x7FF;
    addr = pgm_read_word (addr) & 0x7FF;
    addr = pgm_read_word (addr) & 0x7FF;
    addr = pgm_read_word (addr) & 0x7FF;
    addr = pgm_read_word (addr) & 0x7FF;
    addr = pgm_read_word (addr) & 0x7FF;
    addr = pgm_read_word (addr) & 0x7FF;
    addr = pgm_read_word (addr) & 0x7FF;
    addr = pgm_read_word (addr) & 0x7FF;		/* 40 */

    /* 10*4 words with enhanced LPM
       10*7 words with classic LPM	*/
    addr = pgm_read_word (addr) & 0x7FF;
    addr = pgm_read_word (addr) & 0x7FF;
    addr = pgm_read_word (addr) & 0x7FF;
    addr = pgm_read_word (addr) & 0x7FF;
    addr = pgm_read_word (addr) & 0x7FF;
    addr = pgm_read_word (addr) & 0x7FF;
    addr = pgm_read_word (addr) & 0x7FF;
    addr = pgm_read_word (addr) & 0x7FF;
    addr = pgm_read_word (addr) & 0x7FF;
    addr = pgm_read_word (addr) & 0x7FF;		/* 50 */

    rslt = (int)addr;
    return 0;
}

#endif	/* __AVR__ */
