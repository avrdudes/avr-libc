/* bug #19134: strcasecmp(): result sign is not changed by swaping args.
   $Id$	*/

#include <string.h>

int main ()
{
    char s1[] = "a";
    char s2[] = "[";

    if (   (strcasecmp (s1, s2) > 0 && strcasecmp (s2, s1) > 0)
	|| (strcasecmp (s1, s2) < 0 && strcasecmp (s2, s1) < 0) )
      return __LINE__;
    return 0;
}
