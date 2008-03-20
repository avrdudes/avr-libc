/* Test of iscntrl() function.
   $Id$
 */
#include <ctype.h>
#include <stdlib.h>
#include <string.h>
#include <stdio.h>

#ifndef	__AVR__
# define PRINTFLN(fmt, ...)	\
    printf ("\nLine %d: " fmt "\n", __LINE__, ##__VA_ARGS__)
# define EXIT(code)	exit ((code) < 255 ? (code) : 100 + (code) % 100)
#else
# if defined(__AVR_ATmega128__)
  /* ATmega128 has enough RAM for sprintf(), print to 0x2000 in XRAM. */
#  define PRINTFLN(fmt, ...)	\
    sprintf ((char *)0x2000, "\nLine %d: " fmt "\n", __LINE__, ##__VA_ARGS__)
# else
   /* small AVR */
#  define PRINTFLN(args...)
# endif
# define EXIT	exit
#endif

int main ()
{
    int i;
    
    for (i = -1; i < 256; i++) {
	if ((i >= 0 && i < ' ') || i == 0x7f) {
	    if (!iscntrl (i)) {
		PRINTFLN ("iscntrl(%#x) --> false", i);
		EXIT (__LINE__);
	    }
	} else {
	    if (iscntrl (i)) {
		PRINTFLN ("iscntrl(%#x) --> true", i);
		EXIT (__LINE__);
	    }
	}
    }
    

/* Skip the host, as according to C standart it is not safety to use an
   argument beyound -1..255 value.  But Avr-libc's ctype functions permit
   this.	*/
#ifdef	__AVR__
    {
	unsigned int u;
	for (u = 0xffff; u > 0xff; u--)
	    if (iscntrl (u))
		EXIT (__LINE__);
    }
#endif

    return 0;
}
