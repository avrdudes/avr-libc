/* $Id$	*/

#include <ctype.h>
#include <errno.h>
#include <limits.h>
#include <stdlib.h>
#ifndef	__AVR__
# include <stdio.h>
#endif
#ifndef	EINVAL		/* Addition for errno.h in avr-libc-1.2.0	*/
# define EINVAL	22	/* Invalid argument	*/
#endif

static int t_strtol (const char *s, int base, long ret, int err, int len)
{
    char * endptr;
    
    errno = 0;
    endptr = (char *)s - 1;		/* invalid value	*/
    if (strtol (s, & endptr, base) != ret
	|| errno != err
#ifdef	__AVR__
	|| endptr - s != len)
#else		/* Glibc 2.3.1 is not set endptr in the case of EINVAL	*/
	|| (errno != EINVAL && (endptr - s) != len) )
#endif
    {
#ifndef	__AVR__
	printf ("strtol(\"%s\",,%d): %ld, errno: %d, len: %d\n",
	    s, base, strtol(s, & endptr, base), errno, endptr - s);
#endif
	return 1;
    }
    return 0;
}
