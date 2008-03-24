/* Test of setjmp()/longjmp() functions: jmp_buf bounds.
   $Id$	*/

#include <stdlib.h>
#include <setjmp.h>

struct {
    char beg[16];
    jmp_buf env;
    char end[16];
} buf;

volatile int one = 1;		/* to suppress optimization	*/

void foo (void)
{
    longjmp (buf.env, one);
}

int main ()
{
    volatile unsigned char fill = 0;
    void * volatile p;		/* Avr-gcc >= 4.1.2 outputs incorrect
				    warning without 'volatile'.	*/

    do {
	/* filling	*/
	for (p = &buf; p != (void *)&buf + sizeof (buf); p++)
	    *(char *)p = fill;

	/* buf.env usage	*/
	switch (setjmp (buf.env)) {
	    case 1:
		break;
	    case 0:
		foo ();
	    default:
		exit (__LINE__);
	}
	
	/* checking	*/
	for (p = &buf; p != (void *)&buf + sizeof (buf); p++) {
	    if (*(unsigned char *)p != fill
		&& (p < (void *)&buf.env
		    || p >= (void *)&buf.env + sizeof(buf.env)))
	    {
		exit (__LINE__);
	    }
	}
    } while (++fill);
    
    return 0;
}
