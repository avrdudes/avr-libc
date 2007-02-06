/* Multibytes members.
   $Id$
 */

#include <stdlib.h>
#include <string.h>
#include <stdio.h>

size_t size;	/* to pass size of members	*/

int cmp (const void *p1, const void *p2)
{
    return memcmp(p1, p2, size);
}

int main ()
{
    char arr[100];
    size_t nmemb;
    int i;
    
    /* Filling of arr: 0,1,2...	*/
    for (i= 0; (size_t)i < sizeof(arr); i++)
	arr[i] = i;

    for (size= 1;  size <= sizeof(arr);  size++) {
	for (nmemb= 1;  nmemb <= sizeof(arr) / size;  nmemb++) {
	    /* scanning all keys	*/
	    for (i= 0;  (size_t)i <= sizeof(arr) - size;  i++) {
		if ((i % size) == 0 && (i / size) < nmemb) {
		    if (bsearch (arr + i, arr, nmemb, size, cmp) != arr + i) {
#ifndef	__AVR__
			printf ("size= %d  nmemb= %d  i= %d\n",
				size, nmemb, i );
#endif
			exit (__LINE__);
		    }
		} else {
		    if (bsearch (arr + i, arr, nmemb, size, cmp))
			exit (__LINE__);
		}
	    }
	}
    }
    return 0;
}
