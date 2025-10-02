#include <avr/io.h>

#ifdef __AVR_TINY__
/* On AVRrc, all SFRs are accessible with IN/OUT. */
#define SFR (*(volatile uint8_t*) 0x33)
#else
#define SFR (*(volatile uint8_t*) 0xbf)
#endif

int main (void)
{
#if __AVR_ARCH__ >= 100
    _PROTECTED_WRITE (SFR, 0xff);
#endif
#ifdef __AVR_XMEGA__
    _PROTECTED_WRITE_SPM (SFR, 0xff);
#endif

    return 0;
}

#include <avr/cpufunc.h>

void func (void)
{
#if __AVR_ARCH__ >= 100
    ccp_write_io (&SFR, 0xff);
#endif
#ifdef __AVR_XMEGA__
    ccp_write_spm (&SFR, 0xff);
#endif
}
