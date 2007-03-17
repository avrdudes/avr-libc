/* bug #19281: isblank('\v') return TRUE: mismatch to C99
   $Id$	*/

#include <ctype.h>

int main ()
{
    if (isblank('\v')) return __LINE__;
    return 0;
}
