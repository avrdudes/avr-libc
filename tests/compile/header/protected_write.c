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
#if defined(__AVR_XMEGA__) || defined(CCP_SPM_gc)
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
#if defined(__AVR_XMEGA__) || defined(CCP_SPM_gc)
    ccp_write_spm (&SFR, 0xff);
#endif
}

void func2 (volatile int8_t *addr, uint8_t val)
{
#if __AVR_ARCH__ >= 100
    ccp_write_io (addr, val);
#endif
#if defined(__AVR_XMEGA__) || defined(CCP_SPM_gc)
    ccp_write_spm (addr, val);
#endif
}

void *p1, *p2;
void func3 (void)
{
#if __AVR_ARCH__ >= 100
    p1 = (void*) ccp_write_io;
#endif
#if defined(__AVR_XMEGA__) || defined(CCP_SPM_gc)
    p2 = (void*) ccp_write_spm;
#endif
}
