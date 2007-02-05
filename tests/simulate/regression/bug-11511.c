/* bug #11511: NaN not generated correctly by division library
   $Id$
 */
#include <stdlib.h>
#include <math.h>

int main ()
{
    volatile float a = 0, b = 0;
    float c = a/b;
    if (isnan (c)) return 0;
    exit (__LINE__);
}
