/* Test of abort() function. Now it is a normal function and
   the user can to replace it.
   $Id$	*/

#include <stdlib.h>

volatile int v;		/* to suppress any optimization	*/

__attribute__((noreturn)) void abort (void)
{
    exit (v);
}

int main ()
{
    v = 0;
    abort ();
    return __LINE__;
}
