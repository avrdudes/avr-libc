/* Test of setjmp()/longjmp() functions: frame pointer restoring.
   $Id$	*/

#include <setjmp.h>
#include <stdlib.h>
#include <string.h>

jmp_buf env;

/* foo_jmp() use stack.	longjmp must restore frame pointer from env.	*/
void foo_jmp (const char *p)
{
    char s[16];
    strcpy (s, p);
    s[0] += 1;
    longjmp (env, strtol (s, 0, 0));
}

/* foo() use stack. If frame pointer would be scratch, return value
   (or all program) would be another.	*/
int foo (char *p)
{
    volatile char s[16];
    strcpy ((char *)s, p);
    switch (setjmp (env)) {
	case 0:     break;
	case 2:     return strtol ((const char *)s, 0, 0);
	default:    exit (__LINE__);
    }
    foo_jmp ("1");
    exit (__LINE__);
}

int main ()
{
    if (foo ("1234") != 1234)
	exit (__LINE__);
    if (foo ("4321") != 4321)
	exit (__LINE__);
    return 0;
}
