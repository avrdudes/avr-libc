/* Test of _SFR's macroses.  Default usage without any definition.
   $Id$	*/

#include <avr/io.h>
#include <stdlib.h>

#define cli()	asm volatile ("cli")
#define sei()	asm volatile ("sei")
#define nop()	asm volatile ("nop")

int main ()
{
    int i;
    volatile unsigned char *p;
    unsigned char c;

#if	defined (__AVR_AT90S8515__)

    i = _SFR_ADDR (SREG);
    if (i != 0x5F) exit (__LINE__);
    i = _SFR_MEM_ADDR (SREG);
    if (i != 0x5F) exit (__LINE__);
    i = _SFR_IO_ADDR (SREG);
    if (i != 0x3F) exit (__LINE__);
    if (!_SFR_IO_REG_P (SREG)) exit (__LINE__);

    i = _SFR_ADDR (WDTCR);
    if (i != 0x41) exit (__LINE__);
    i = _SFR_MEM_ADDR (WDTCR);
    if (i != 0x41) exit (__LINE__);
    i = _SFR_IO_ADDR (WDTCR);
    if (i != 0x21) exit (__LINE__);
    if (!_SFR_IO_REG_P (WDTCR)) exit (__LINE__);

    i = _SFR_ADDR (EEARH);
    if (i != 0x3F) exit (__LINE__);
    i = _SFR_MEM_ADDR (EEARH);
    if (i != 0x3F) exit (__LINE__);
    i = _SFR_IO_ADDR (EEARH);
    if (i != 0x1F) exit (__LINE__);
    if (!_SFR_IO_REG_P (EEARH)) exit (__LINE__);

    i = _SFR_ADDR (ACSR);
    if (i != 0x28) exit (__LINE__);
    i = _SFR_MEM_ADDR (ACSR);
    if (i != 0x28) exit (__LINE__);
    i = _SFR_IO_ADDR (ACSR);
    if (i != 0x08) exit (__LINE__);
    if (!_SFR_IO_REG_P (ACSR)) exit (__LINE__);

#elif	defined (__AVR_ATmega8__)

    i = _SFR_ADDR (SREG);
    if (i != 0x5F) exit (__LINE__);
    i = _SFR_MEM_ADDR (SREG);
    if (i != 0x5F) exit (__LINE__);
    i = _SFR_IO_ADDR (SREG);
    if (i != 0x3F) exit (__LINE__);
    if (!_SFR_IO_REG_P (SREG)) exit (__LINE__);

    i = _SFR_ADDR (UCSRC);
    if (i != 0x40) exit (__LINE__);
    i = _SFR_MEM_ADDR (UCSRC);
    if (i != 0x40) exit (__LINE__);
    i = _SFR_IO_ADDR (UCSRC);
    if (i != 0x20) exit (__LINE__);
    if (!_SFR_IO_REG_P (UCSRC)) exit (__LINE__);

    i = _SFR_ADDR (EEARH);
    if (i != 0x3F) exit (__LINE__);
    i = _SFR_MEM_ADDR (EEARH);
    if (i != 0x3F) exit (__LINE__);
    i = _SFR_IO_ADDR (EEARH);
    if (i != 0x1F) exit (__LINE__);
    if (!_SFR_IO_REG_P (EEARH)) exit (__LINE__);

    i = _SFR_ADDR (TWBR);
    if (i != 0x20) exit (__LINE__);
    i = _SFR_MEM_ADDR (TWBR);
    if (i != 0x20) exit (__LINE__);
    i = _SFR_IO_ADDR (TWBR);
    if (i != 0x00) exit (__LINE__);
    if (!_SFR_IO_REG_P (TWBR)) exit (__LINE__);

#elif	defined (__AVR_ATmega128__)

    i = _SFR_ADDR (UCSR1C);
    if (i != 0x9D) exit (__LINE__);
    i = _SFR_MEM_ADDR (UCSR1C);
    if (i != 0x9D) exit (__LINE__);
    if (_SFR_IO_REG_P (UCSR1C)) exit (__LINE__);

    i = _SFR_ADDR (DDRF);
    if (i != 0x61) exit (__LINE__);
    i = _SFR_MEM_ADDR (DDRF);
    if (i != 0x61) exit (__LINE__);
    if (_SFR_IO_REG_P (DDRF)) exit (__LINE__);

    i = _SFR_ADDR (SREG);
    if (i != 0x5F) exit (__LINE__);
    i = _SFR_MEM_ADDR (SREG);
    if (i != 0x5F) exit (__LINE__);
    i = _SFR_IO_ADDR (SREG);
    if (i != 0x3F) exit (__LINE__);
    if (!_SFR_IO_REG_P (SREG)) exit (__LINE__);

    i = _SFR_ADDR (SFIOR);
    if (i != 0x40) exit (__LINE__);
    i = _SFR_MEM_ADDR (SFIOR);
    if (i != 0x40) exit (__LINE__);
    i = _SFR_IO_ADDR (SFIOR);
    if (i != 0x20) exit (__LINE__);
    if (!_SFR_IO_REG_P (SFIOR)) exit (__LINE__);

    i = _SFR_ADDR (EEARH);
    if (i != 0x3F) exit (__LINE__);
    i = _SFR_MEM_ADDR (EEARH);
    if (i != 0x3F) exit (__LINE__);
    i = _SFR_IO_ADDR (EEARH);
    if (i != 0x1F) exit (__LINE__);
    if (!_SFR_IO_REG_P (EEARH)) exit (__LINE__);

    i = _SFR_ADDR (PINF);
    if (i != 0x20) exit (__LINE__);
    i = _SFR_MEM_ADDR (PINF);
    if (i != 0x20) exit (__LINE__);
    i = _SFR_IO_ADDR (PINF);
    if (i != 0x00) exit (__LINE__);
    if (!_SFR_IO_REG_P (PINF)) exit (__LINE__);

#else
    (void)i;
#endif

    /* SREG: mem addr is 0x5F (avr2..avr5)	*/

    cli ();
    if (SREG & (1 << SREG_I)) exit (__LINE__);
    sei ();
    if (!(SREG & (1 << SREG_I))) exit (__LINE__);

    p = (void *)_SFR_ADDR (SREG);
    cli ();
    if (*p & (1 << SREG_I)) exit (__LINE__);
    sei ();
    if (!(*p & (1 << SREG_I))) exit (__LINE__);

    p = (void *)_SFR_MEM_ADDR (SREG);
    cli ();
    if (*p & (1 << SREG_I)) exit (__LINE__);
    sei ();
    if (!(*p & (1 << SREG_I))) exit (__LINE__);

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
