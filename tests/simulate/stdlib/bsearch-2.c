/* Tests of branch logic. Number of probing is checked.
   $Id$
 */
#include <stdlib.h>

/* Calculate max number of compare function calls, depends of nmemb	*/
int max_calls (size_t nmemb)
{
    int n = 0;		/* result		*/
    size_t exp = 1;	/* margin: 1,2,4,8...	*/
    do {
	if (exp > nmemb) break;
	n += 1;
    } while (exp *= 2);
    return (n ? n : 1);
}

int cmp_calls;

int cmp (const void *p1, const void *p2)
{
    cmp_calls += 1;
    return *(unsigned char *)p1 - *(unsigned char *)p2;
}

int main ()
{
    unsigned char arr[33], key;
    size_t nmemb;
    int i;
    
    /* max_calls verify	*/
    if (   max_calls(1) != 1
	|| max_calls(2) != 2
	|| max_calls(3) != 2
	|| max_calls(7) != 3
	|| max_calls(8) != 4 ) exit (__LINE__);
    
    /* Filling of arr: 1,3,5...	*/
    for (i= 0; i < (int)sizeof(arr); i++)
	arr[i] = 1 + 2*i;

    for (nmemb= 1; nmemb <= sizeof(arr); nmemb++) {
    
	/* Non-existance keys:  arr[i] < key < arr[i+1]	*/
	for (i= 0; (size_t)i <= nmemb; i++) {
	    key = 2*i;
	    cmp_calls = 0;
	    if (bsearch (& key, arr, nmemb, 1, cmp) != 0)
		exit (__LINE__);
	    if (cmp_calls > max_calls(nmemb))
		exit (__LINE__);
	}
	
	/* All existance keys.	*/
	for (i= 0; (size_t)i < nmemb; i++) {
	    key = arr[i];
	    cmp_calls = 0;
	    if (bsearch (& key, arr, nmemb, 1, cmp) != arr + i)
		exit (__LINE__);
	    if (cmp_calls > max_calls(nmemb))
		exit (__LINE__);
	}

    }
    return 0;
}
