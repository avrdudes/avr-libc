/* Test of setjmp()/longjmp() functions: SREG restoring.
   $Id$	*/

#ifdef	__AVR__

#include <setjmp.h>
#include <stdlib.h>
#include <avr/io.h>

jmp_buf env;

int main ()
{
    SREG = 0;
    if (setjmp (env)) {
	if (SREG & (1 << SREG_I)) exit (__LINE__);
    } else {
	if (SREG & (1 << SREG_I)) exit (__LINE__);
	SREG = 0xff;
	longjmp (env, 1);
    }
    
    SREG = 0xff;
    if (setjmp (env)) {
	if ((SREG & (1 << SREG_I)) == 0) exit (__LINE__);
    } else {
	if ((SREG & (1 << SREG_I)) == 0) exit (__LINE__);
	SREG = 0;
	longjmp (env, 1);
    }
    return 0;
}

#else
int main ()	{ return 0; }
#endif
