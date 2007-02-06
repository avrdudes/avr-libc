/* Simplest cases.
   $Id$
 */
#include <stdlib.h>

int cmp (const void *p1, const void *p2)
{
    return *(unsigned char *)p1 - *(unsigned char *)p2;
}

int main ()
{
    static unsigned char arr[100];
    unsigned char key;

    if (bsearch (arr, arr, 0, 1, cmp) != 0)
	exit (__LINE__);
    
    /* If element size equal to 0, Glibc and original bsearch
       return comparison result of first element.
       New bsearch do the same.	*/
    if (bsearch (arr, arr, sizeof(arr), 0, cmp) != arr)
	exit (__LINE__);
    key = 1;
    if (bsearch (& key, arr, sizeof(arr), 0, cmp) != 0)
	exit (__LINE__);
    
    /* key has address from arr	*/
    if (bsearch (arr, arr, 1, 1, cmp) != arr)
	exit (__LINE__);

    /* key has another address	*/
    key = arr[0];
    if (bsearch (& key, arr, 1, 1, cmp) != arr)
	exit (__LINE__);

    /* key > arr[0]	*/
    key = 1;
    if (bsearch (& key, arr, 1, 1, cmp) != 0)
	exit (__LINE__);

    /* key < arr[0]	*/
    arr[0] = 2;
    if (bsearch (& key, arr, 1, 1, cmp) != 0)
	exit (__LINE__);

    return 0;
}
