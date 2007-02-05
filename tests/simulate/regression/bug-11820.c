/* bug #11820: wrong output with precision = 3
   $Id$
 */
#include <stdlib.h>
#include <string.h>

int main ()
{
#ifdef	__AVR__		/* dtostre() is not a standart C function.	*/
    char s[20];
    dtostre (1e-15, s, 3, 0);
    if (strcmp (s, "1.000e-15")) exit (__LINE__);
#endif
    return 0;
}
