/* missed-optimization: jmp_buf includes unused bytes.
   $Id$	*/

#include <setjmp.h>
#include <stdlib.h>
#include <string.h>

jmp_buf env;

int main ()
{
    char isused[sizeof(env)];
    volatile unsigned char fill;
    void *p;
    int i;

    memset (isused, 0, sizeof(isused));
    fill = 0;
    do {
	memset (&env, fill, sizeof(env));

	setjmp (env);
	rand ();	/* to avoid optimization	*/

	for (i = 0, p = &env; i < (int)sizeof(env); i++, p++) {
	    if (*(unsigned char *)p != fill)
		isused[i] = 1;
	}
    } while (++fill);

#ifdef	__AVR__
    if (memchr (isused, 0, sizeof(isused)))
	exit (__LINE__);
#endif

    return 0;
}
