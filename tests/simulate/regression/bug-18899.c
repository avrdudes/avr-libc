/* bug #18899: atoi and atol do not handle vertical tab properly
   $Id$
 */
#include <stdlib.h>

int main ()
{
    if (atoi ("\v12345") != 12345) exit (__LINE__);
    if (atol ("\v123456") != 123456) exit (__LINE__);
    return 0;
}
