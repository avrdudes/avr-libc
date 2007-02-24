/* bug #19135: strstr(): `needle' is not always founded.
   $Id$	*/

#include <string.h>

int main ()
{
    char haystack[] = "ababac";
    char *p = strstr (haystack, "abac");
    if (p != haystack + 2)
	return __LINE__;
    return 0;
}
