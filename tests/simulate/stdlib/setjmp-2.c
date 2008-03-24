/* Test of setjmp()/longjmp(): preservation call-saved registers.
   $Id$	*/

#include <stdlib.h>
#include <setjmp.h>

jmp_buf env;

/* foo2() uses (and destroys) call-saved registers. Complex return
   value is used to force allocate all variables.	*/
int foo2 (void)
{
    int v1, v2, v3, v4, v5, v6, v7, v8;
    
    srand (1);
    v1 = rand ();
    v2 = rand ();
    v3 = rand ();
    v4 = rand ();
    v5 = rand ();
    v6 = rand ();
    v7 = rand ();
    v8 = rand ();
    
    v1 *= rand ();
    v1 += v2 * rand ();
    v1 += v3 * rand ();
    v1 += v4 * rand ();
    v1 += v5 * rand ();
    v1 += v6 * rand ();
    v1 += v7 * rand ();
    v1 += v8 * rand ();
    
    while (!v1) v1 = rand ();
    
    longjmp (env, v1);
}

/* Recalculate result above.	*/
int calc (int initial)
{
    int v1, v2, v3, v4, v5, v6, v7, v8;
    
    srand (initial);
    v1 = rand ();
    v2 = rand ();
    v3 = rand ();
    v4 = rand ();
    v5 = rand ();
    v6 = rand ();
    v7 = rand ();
    v8 = rand ();
    
    v1 *= rand ();
    v1 += v2 * rand ();
    v1 += v3 * rand ();
    v1 += v4 * rand ();
    v1 += v5 * rand ();
    v1 += v6 * rand ();
    v1 += v7 * rand ();
    v1 += v8 * rand ();
    
    while (!v1) v1 = rand ();

    return v1;
}

/* foo1() does not use call-save registers.
   The setjmp() must do this.	*/
void foo1 (void)
{
    int x;

    if ( (x = setjmp (env)) != 0) {
	if (x != calc (1))
	    exit (__LINE__);
	return;
    }
    foo2 ();
    exit (__LINE__);
}

/* main() allocates many variables in call-saved registers.
 */
int main ()
{
    int v1, v2, v3, v4, v5, v6, v7, v8;

    srand (2);
    v1 = rand ();
    v2 = rand ();
    v3 = rand ();
    v4 = rand ();
    v5 = rand ();
    v6 = rand ();
    v7 = rand ();
    v8 = rand ();

    foo1 ();
    
    srand (2);
    if (   v1 != rand()
	|| v2 != rand()
	|| v3 != rand()
	|| v4 != rand()
	|| v5 != rand()
	|| v6 != rand()
	|| v7 != rand()
	|| v8 != rand())
    {
	exit (__LINE__);
    }
    
    return 0;
}
