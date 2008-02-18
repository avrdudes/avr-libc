/* bug #21906: scanf: float conversion, wrong width count in case of sign 
   or exponent
   $Id$	*/

#include <stdio.h>

int main ()
{
    float x = 0;

    sscanf ("+1.2599", "%5e", &x);
    if (x != 1.25) return __LINE__;
    
    sscanf ("2.5e+11", "%6e", &x);
    if (x != 25.0) return __LINE__;

    return 0;
}
