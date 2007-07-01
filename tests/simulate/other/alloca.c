/* $Id$ */

#include <alloca.h>
#include <stdarg.h>
#include <stdlib.h>
#include <string.h>

#define elemof(v)	(sizeof(v) / sizeof((v)[0]))

/* A few of alloca() calls in the one function.	*/
void test_few_alloca (void)
{
    unsigned char *p[10];
    int i, n;

    /* Allocate and fill each block with sizes: 1 .. elemof(p)	*/
    for (n = 1; n < (int)elemof(p); n++) {
	p[n-1] = alloca (n);
	memset (p[n-1], n, n);
    }

    /* Check that there is no overlapping.	*/
    for (n = 1; n < (int)elemof(p); n++) {
	for (i = 0; i < n; i++)
	    if (p[n-1][i] != n)
		exit (__LINE__);
    }
}

/* Variable size array and alloca() together.	*/
void test_with_var_array (int n)
{
    unsigned char s[n];
    unsigned char *p;
    int i;

    /* Fill variable size array.	*/
    memset (s, 1, n);

    /* Allocate and fill the second array.	*/
    p = alloca (n);
    memset (p, 2, n);
    
    /* Refill the first array.	*/
    for (i = 0; i < n; i++) s[i] += 1;

    /* Check both.	*/
    if (memcmp (s, p, n))
	exit (__LINE__);
}

/* Increment the each element of buf[].
   The second argument is the number of elements.	*/
void inc_array (unsigned char *buf, ...)
{
    va_list ap;
    int n, i;
    
    va_start (ap, buf);
    n = va_arg (ap, int);
    va_end (ap);
    
    for (i = 0; i < n; i++) buf[i] += 1;
}

/* Check the compatibility with call of function, where arguments are
   allocated in the stack.	*/
void test_with_var_args (int n)
{
    unsigned char *p;
    int i;

    /* Allocate and fill.	*/
    p = alloca (n);
    memset (p, 1, n);

    /* Args are placed in stack.	*/
    inc_array (p, n);

    /* Check the result.	*/
    for (i = 0; i < n; i++) {
	if (p[i] != 2)
	    exit (__LINE__);
    }
}

int main ()
{
    test_few_alloca ();
    test_with_var_array (10);
    test_with_var_args (20);
    
    return 0;
}
