/* The _FFS() macro is wrong in case of CPP conditional usage.
   Seems, it is a bug in CPP parser in case of few '?:' expersions.
   The CC parser is correct.
   
   $Id$
 */

#include <string.h>

#ifdef	__AVR__
# if	 _FFS (1) != 1
#  error
# endif
#endif

int main ()
{
    return 0;
}
