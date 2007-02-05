/* bug #1929, -Inf not detected
   $Id$
 */
#include <stdlib.h>
#include <math.h>

int main ()
{
    volatile float v = 0;
    v = -1/v;
    if (isinf (v)) return 0;
    exit (__LINE__);
}
