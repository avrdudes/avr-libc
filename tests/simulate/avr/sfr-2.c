/* Test of _SFR's macroses.  Old style C program.
   $Id$	*/

/* XXX: Seems, the _SFR_MEM_ADDR() is worse.  In case of _SFR_ASM_COMPAT
   with __SFR_OFFSET == 0 it returns the same value, as _SFR_IO_ADDR().
   This happens with SREG and below, with higher the _SFR_MEM_ADDR() is
   OK.  Note, the _SFR_IO_ADDR() and _SFR_ADDR() are correct with all 3
   combinations of _SFR_ASM_COMPAT, __SFR_OFFSET.  Now the tests of
   _SFR_MEM_ADDR() are commented.	*/

#define	_SFR_ASM_COMPAT  1
#define	__SFR_OFFSET	 0
#include <avr/io.h>
#include <stdlib.h>

#define cli()	asm volatile ("cli")
#define sei()	asm volatile ("sei")
#define nop()	asm volatile ("nop")

/* Get a string like: VALUE(SREG) --> "0x3F"	*/
#define VALUE(port)	VALUE_2 (port)
#define VALUE_2(port)	#port

/* Note, this is old style where ports are pure numbers.	*/
#define inb(port)	({				\
    unsigned char __c;					\
    asm volatile ("in %0," VALUE (port) : "=r" (__c));	\
    __c;						\
})

int main ()
{
    int i;
    volatile unsigned char *p;
    unsigned char c;

#if	defined (__AVR_AT90S8515__)

# if	 SREG != 0x3F  ||  !_SFR_IO_REG_P (SREG)
#  error
# endif
    i = _SFR_ADDR (SREG);
    if (i != 0x5F) exit (__LINE__);
///    i = _SFR_MEM_ADDR (SREG);
///    if (i != 0x5F) exit (__LINE__);
    i = _SFR_IO_ADDR (SREG);
    if (i != 0x3F) exit (__LINE__);
    if (!_SFR_IO_REG_P (SREG)) exit (__LINE__);

# if	WDTCR != 0x21  ||  !_SFR_IO_REG_P (WDTCR)
#  error
# endif
    i = _SFR_ADDR (WDTCR);
    if (i != 0x41) exit (__LINE__);
///    i = _SFR_MEM_ADDR (WDTCR);
///    if (i != 0x41) exit (__LINE__);
    i = _SFR_IO_ADDR (WDTCR);
    if (i != 0x21) exit (__LINE__);
    if (!_SFR_IO_REG_P (WDTCR)) exit (__LINE__);

# if	EEARH != 0x1F  ||  !_SFR_IO_REG_P (EEARH)
#  error
# endif
    i = _SFR_ADDR (EEARH);
    if (i != 0x3F) exit (__LINE__);
///    i = _SFR_MEM_ADDR (EEARH);
///    if (i != 0x3F) exit (__LINE__);
    i = _SFR_IO_ADDR (EEARH);
    if (i != 0x1F) exit (__LINE__);
    if (!_SFR_IO_REG_P (EEARH)) exit (__LINE__);

# if	ACSR != 0x08  ||  !_SFR_IO_REG_P (ACSR)
#  error
# endif
    i = _SFR_ADDR (ACSR);
    if (i != 0x28) exit (__LINE__);
///    i = _SFR_MEM_ADDR (ACSR);
///    if (i != 0x28) exit (__LINE__);
    i = _SFR_IO_ADDR (ACSR);
    if (i != 0x08) exit (__LINE__);
    if (!_SFR_IO_REG_P (ACSR)) exit (__LINE__);

#elif	defined (__AVR_ATmega8__)

# if	 SREG != 0x3F  ||  !_SFR_IO_REG_P (SREG)
#  error
# endif
    i = _SFR_ADDR (SREG);
    if (i != 0x5F) exit (__LINE__);
///    i = _SFR_MEM_ADDR (SREG);
///    if (i != 0x5F) exit (__LINE__);
    i = _SFR_IO_ADDR (SREG);
    if (i != 0x3F) exit (__LINE__);
    if (!_SFR_IO_REG_P (SREG)) exit (__LINE__);

# if	UCSRC != 0x20  ||  !_SFR_IO_REG_P (UCSRC)
#  error
# endif
    i = _SFR_ADDR (UCSRC);
    if (i != 0x40) exit (__LINE__);
///    i = _SFR_MEM_ADDR (UCSRC);
///    if (i != 0x40) exit (__LINE__);
    i = _SFR_IO_ADDR (UCSRC);
    if (i != 0x20) exit (__LINE__);
    if (!_SFR_IO_REG_P (UCSRC)) exit (__LINE__);

# if	EEARH != 0x1F  ||  !_SFR_IO_REG_P (EEARH)
#  error
# endif
    i = _SFR_ADDR (EEARH);
    if (i != 0x3F) exit (__LINE__);
///    i = _SFR_MEM_ADDR (EEARH);
///    if (i != 0x3F) exit (__LINE__);
    i = _SFR_IO_ADDR (EEARH);
    if (i != 0x1F) exit (__LINE__);
    if (!_SFR_IO_REG_P (EEARH)) exit (__LINE__);

# if	TWBR != 0x00  ||  !_SFR_IO_REG_P (TWBR)
#  error
# endif
    i = _SFR_ADDR (TWBR);
    if (i != 0x20) exit (__LINE__);
///    i = _SFR_MEM_ADDR (TWBR);
///    if (i != 0x20) exit (__LINE__);
    i = _SFR_IO_ADDR (TWBR);
    if (i != 0x00) exit (__LINE__);
    if (!_SFR_IO_REG_P (TWBR)) exit (__LINE__);

#elif	defined (__AVR_ATmega128__)

# if	 UCSR1C != 0x9D  ||  _SFR_IO_REG_P (UCSR1C)
#  error
# endif
    i = _SFR_ADDR (UCSR1C);
    if (i != 0x9D) exit (__LINE__);
    i = _SFR_MEM_ADDR (UCSR1C);
    if (i != 0x9D) exit (__LINE__);
    if (_SFR_IO_REG_P (UCSR1C)) exit (__LINE__);

# if	DDRF != 0x61  ||  _SFR_IO_REG_P (DDRF)
#  error
# endif
    i = _SFR_ADDR (DDRF);
    if (i != 0x61) exit (__LINE__);
    i = _SFR_MEM_ADDR (DDRF);
    if (i != 0x61) exit (__LINE__);
    if (_SFR_IO_REG_P (DDRF)) exit (__LINE__);

# if	 SREG != 0x3F  ||  !_SFR_IO_REG_P (SREG)
#  error
# endif
    i = _SFR_ADDR (SREG);
    if (i != 0x5F) exit (__LINE__);
///    i = _SFR_MEM_ADDR (SREG);
///    if (i != 0x5F) exit (__LINE__);
    i = _SFR_IO_ADDR (SREG);
    if (i != 0x3F) exit (__LINE__);
    if (!_SFR_IO_REG_P (SREG)) exit (__LINE__);

# if	SFIOR != 0x20  ||  !_SFR_IO_REG_P (SFIOR)
#  error
# endif
    i = _SFR_ADDR (SFIOR);
    if (i != 0x40) exit (__LINE__);
///    i = _SFR_MEM_ADDR (SFIOR);
///    if (i != 0x40) exit (__LINE__);
    i = _SFR_IO_ADDR (SFIOR);
    if (i != 0x20) exit (__LINE__);
    if (!_SFR_IO_REG_P (SFIOR)) exit (__LINE__);

# if	EEARH != 0x1F  ||  !_SFR_IO_REG_P (EEARH)
#  error
# endif
    i = _SFR_ADDR (EEARH);
    if (i != 0x3F) exit (__LINE__);
///    i = _SFR_MEM_ADDR (EEARH);
///    if (i != 0x3F) exit (__LINE__);
    i = _SFR_IO_ADDR (EEARH);
    if (i != 0x1F) exit (__LINE__);
    if (!_SFR_IO_REG_P (EEARH)) exit (__LINE__);

# if	PINF != 0x00  ||  !_SFR_IO_REG_P (PINF)
#  error
# endif
    i = _SFR_ADDR (PINF);
    if (i != 0x20) exit (__LINE__);
///    i = _SFR_MEM_ADDR (PINF);
///    if (i != 0x20) exit (__LINE__);
    i = _SFR_IO_ADDR (PINF);
    if (i != 0x00) exit (__LINE__);
    if (!_SFR_IO_REG_P (PINF)) exit (__LINE__);

#else
    (void)i;
#endif

    /* SREG: mem addr is 0x5F (avr2..avr5)	*/

    cli ();
    if (inb (SREG) & (1 << SREG_I)) exit (__LINE__);
    sei ();
    if (!(inb (SREG) & (1 << SREG_I))) exit (__LINE__);

    p = (void *)_SFR_ADDR (SREG);
    cli ();
    if (*p & (1 << SREG_I)) exit (__LINE__);
    sei ();
    if (!(*p & (1 << SREG_I))) exit (__LINE__);

///    p = (void *)_SFR_MEM_ADDR (SREG);
///    cli ();
///    if (*p & (1 << SREG_I)) exit (__LINE__);
///    sei ();
///    if (!(*p & (1 << SREG_I))) exit (__LINE__);

    cli ();
    asm volatile ("in %0,%1" : "=r" (c) : "I" (_SFR_IO_ADDR (SREG)));
    if (c & (1 << SREG_I)) exit (__LINE__);
    sei ();
    asm volatile ("in %0,%1" : "=r" (c) : "I" (_SFR_IO_ADDR (SREG)));
    if (!(c & (1 << SREG_I))) exit (__LINE__);

/* TODO: it is needed to update simulavr: do not ask PINx value, if DDRx
   is set.	*/
#if 0
    /* PORTB: mem addr is small	*/
    DDRB = 0xFF;

    PORTB = 1;
    nop ();
    if ((PINB & 3) != 1) exit (__LINE__);
    PORTB = 2;
    nop ();
    if ((PINB & 3) != 2) exit (__LINE__);
#endif

    return 0;
}
