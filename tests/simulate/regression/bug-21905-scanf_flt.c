/* bug #21905: scanf: float conversion ignores the suppression symbol
   $Id$	*/

#include <stdio.h>
#include <string.h>

int main ()
{
    /* Use function pointer to avoid compiler warning.	*/
    int (* volatile pf) (const char *, const char *, ...) = sscanf;
    float x, y;
    int i;

    y = 0;
    i = pf ("1.2345 6.7", "%e %*e", &x, &y);
    if (i == 0) return __LINE__;	/* Are you use float version?	*/
    if ((i != 1) || y) return __LINE__;
    
    return 0;
}
