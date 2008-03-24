/* Test of setjmp()/longjmp() functions: return value.
   $Id$	*/

#include <stdlib.h>
#include <setjmp.h>

jmp_buf env;

int main ()
{
    int (* volatile v_setjmp) (jmp_buf);
    void (* volatile v_longjmp) (jmp_buf, int);

    /* Return 0 from setjmp().	*/
    if (setjmp (env))
	exit (__LINE__);

    /* Pass value throw longjmp().	*/
    switch (setjmp (env)) {
	case 0:
	    longjmp (env, 12345);
	    exit (__LINE__);
	case 12345:
	    break;
	default:
	    exit (__LINE__);
    }

    /* Replace 0 arg of longjmp().	*/
    switch (setjmp (env)) {
	case 0:
	    longjmp (env, 0);
	    exit (__LINE__);
	case 1:
	    break;
	default:
	    exit (__LINE__);
    }

    /* Check -1 value.	*/
    switch (setjmp (env)) {
	case 0:
	    longjmp (env, -1);
	    exit (__LINE__);
	case -1:
	    break;
	default:
	    exit (__LINE__);
    }

    /* Repeat above with volatile function pointers: exclude
       posible compiler optimization.	*/
    v_setjmp = setjmp;
    v_longjmp = longjmp;

    if (v_setjmp (env))
	exit (__LINE__);

    switch (v_setjmp (env)) {
	case 0:
	    v_longjmp (env, 12345);
	    exit (__LINE__);
	case 12345:
	    break;
	default:
	    exit (__LINE__);
    }

    switch (v_setjmp (env)) {
	case 0:
	    v_longjmp (env, 0);
	    exit (__LINE__);
	case 1:
	    break;
	default:
	    exit (__LINE__);
    }
    
    switch (v_setjmp (env)) {
	case 0:
	    v_longjmp (env, -1);
	    exit (__LINE__);
	case -1:
	    break;
	default:
	    exit (__LINE__);
    }

    return 0;
}
