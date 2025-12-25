#include <avr/io.h>

#if defined(__AVR_XMEGA__) || defined(CCP_SPM_gc)

# ifndef CCP_SPM_gc
#  define CCP_SPM_gc	0x9D	/* SPM Instruction Protection  */
# endif

#include "asmdef.h"

;;; void ccp_write_spm (volatile uint8_t *__ioaddr, uint8_t __value)

ENTRY   ccp_write_spm
    ;; r24,25 - __ioaddr
    ;; r22    - __value
    X_movw  r26, r24            ; load io addr into X
    ldi     r24, CCP_SPM_gc     ; load SPM Instruction protection signature
    sts     CCP, r24
    st      X, r22              ; write __value to __ioaddr
    ret
ENDFUNC

#endif  /* __AVR_XMEGA__ || ATtiny102/104 */
