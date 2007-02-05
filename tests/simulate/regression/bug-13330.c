/* bug #13330: NaN is recognized not always
   $Id$
 */
#include <float.h>
#include <stdlib.h>
#include <math.h>

int main ()
{
    volatile double vx = -DBL_MAX;
    vx = vx + vx;
    if (isnan (vx))
	exit (__LINE__);
    return 0;
}
