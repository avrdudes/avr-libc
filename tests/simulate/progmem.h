/* $Id$	*/

#ifdef	__AVR__

# include <avr/pgmspace.h>

# define pgm_read_qword(addr)	({			\
    union {						\
	unsigned long __dw[2];				\
	unsigned long long __qw[1];			\
    } __u;						\
    __u.__dw[0] = pgm_read_dword (addr);		\
    __u.__dw[1] = pgm_read_dword ((void *)addr + 4);	\
    __u.__qw[0];					\
  })

#else

# define PROGMEM
# define PSTR(s)		(s)
# define pgm_read_byte(addr)	(*(unsigned char *)(addr))
# define pgm_read_word(addr)	(*(unsigned int *)(addr))
# define pgm_read_dword(addr)	(*(unsigned long *)(addr))
# define pgm_read_qword(addr)	(*(unsigned long long *)(addr))
# define strlen_P		strlen
# define strcmp_P		strcmp
# define strcpy_P		strcpy
# define memcpy_P		memcpy

#endif
