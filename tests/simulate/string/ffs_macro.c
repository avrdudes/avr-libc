/* Test of _FFS() macro.
   $Id$	*/

#include <stdlib.h>
#include <string.h>

#ifndef	__AVR__
# define _FFS(x)	ffs ((x) & 0xffff)
#endif

/* Check usage in CPP expressions.	*/
#ifdef	__AVR__

# if	_FFS (0) != 0		\
     || _FFS (1) != 1		\
     || _FFS (2) != 2		\
     || _FFS (4) != 3		\
     || _FFS (8) != 4		\
     || _FFS (16) != 5		\
     || _FFS (32) != 6		\
     || _FFS (64) != 7		\
     || _FFS (128) != 8		\
     || _FFS (256) != 9		\
     || _FFS (512) != 10	\
     || _FFS (1024) != 11	\
     || _FFS (2048) != 12	\
     || _FFS (4096) != 13	\
     || _FFS (8192) != 14	\
     || _FFS (16384) != 15	\
     || _FFS (32768) != 16
#  error
# endif

# if	_FFS (-1) != 1	\
     || _FFS (32769) != 1
#  error
# endif

# if	_FFS (65536) != 0	/* Only 16 bits are evaluated.	*/
#  error
# endif

#endif

int main ()
{
    if (_FFS (0) != 0) exit (__LINE__);
    if (_FFS (1) != 1) exit (__LINE__);
    if (_FFS (2) != 2) exit (__LINE__);
    if (_FFS (4) != 3) exit (__LINE__);
    if (_FFS (8) != 4) exit (__LINE__);
    if (_FFS (16) != 5) exit (__LINE__);
    if (_FFS (32) != 6) exit (__LINE__);
    if (_FFS (64) != 7) exit (__LINE__);
    if (_FFS (128) != 8) exit (__LINE__);
    if (_FFS (256) != 9) exit (__LINE__);
    if (_FFS (512) != 10) exit (__LINE__);
    if (_FFS (1024) != 11) exit (__LINE__);
    if (_FFS (2048) != 12) exit (__LINE__);
    if (_FFS (4096) != 13) exit (__LINE__);
    if (_FFS (8192) != 14) exit (__LINE__);
    if (_FFS (16384) != 15) exit (__LINE__);
    if (_FFS (32768) != 16) exit (__LINE__);

    if (_FFS (_FFS (_FFS (2))) != 2) exit (__LINE__);

    if (_FFS (0x8001) != 1) exit (__LINE__);
    if (_FFS (0xFFFF) != 1) exit (__LINE__);
    if (_FFS (0x0006) != 2) exit (__LINE__);
    if (_FFS (0x0180) != 8) exit (__LINE__);
    if (_FFS (0xC000) != 15) exit (__LINE__);

    /* Only 16 bits are evaluated.	*/
    if (_FFS (0x20000) != 0) exit (__LINE__);
    if (_FFS (0xFFFF0000) != 0) exit (__LINE__);

    return 0;
}
