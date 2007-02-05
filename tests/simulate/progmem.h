#ifdef	__AVR__

# include <avr/pgmspace.h>
# define pgm_read_qword(addr)			\
    (  (0xffffffff & pgm_read_dword(addr))	\
     | ((long long)pgm_read_dword((void *)(addr) + 4) << 32) )

#else

# define PROGMEM
# define pgm_read_byte(addr)	(*(unsigned char *)(addr))
# define pgm_read_word(addr)	(*(unsigned int *)(addr))
# define pgm_read_dword(addr)	(*(unsigned long *)(addr))
# define pgm_read_qword(addr)	(*(unsigned long long *)(addr))
# define strcpy_P(dst,src)	strcpy(dst,src)

#endif
