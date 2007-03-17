/* bug #19280: snprintf(s,0,fmt,...) write to foreign memory: s[-1]
   $Id$	*/

#include <stdio.h>

int main ()
{
    volatile char s[5];

    s[0] = 1;
    snprintf ((char *)s + 1, 0, "foo");
    if (s[0] != 1) return __LINE__;
    return 0;
}
