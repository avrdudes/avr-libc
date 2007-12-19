/* Test of exit() function.
   $Id$	*/

#include <stdlib.h>

int main ()
{
    /* To suppress any optimization, call a library function by using a
       volatile pointer.	*/
    void (* volatile vp) (int) = 0;
    vp = &exit;
    vp (0);
    return __LINE__;
}
