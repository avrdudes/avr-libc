#include <avr/io.h>

#define SFR (*(volatile uint8_t*) 0xbf)

int main (void)
{
#ifdef __AVR_XMEGA__
    _PROTECTED_WRITE (SFR, 0xff);
    _PROTECTED_WRITE_SPM (SFR, 0xff);
#endif

    return 0;
}

#include <avr/cpufunc.h>

#ifdef __AVR_XMEGA__
void func (void)
{
    ccp_write_io (&SFR, 0xff);
    ccp_write_spm (&SFR, 0xff);
}
#endif
