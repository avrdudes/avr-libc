#include <avr/io.h>

#if __AVR_ARCH__ >= 100

# ifndef CCP_IOREG_gc
#  define CCP_IOREG_gc	0xD8	/* IO Register Protection	*/
# endif

#include "asmdef.h"

;;; void ccp_write_io (uint8_t *__ioaddr, uint8_t __value)

ENTRY ccp_write_io
    ;; r24,25 - __ioaddr
    ;; r22    - __value
    X_movw  r26, r24            ; load io addr into X
    ldi     r24, CCP_IOREG_gc   ; load IO reg change protection signature
    out     CCP, r24
    st      X, r22              ; write __value to __ioaddr
    ret
ENDFUNC

#endif  /* __AVR_XMEGA__ || __AVR_TINY__ */
