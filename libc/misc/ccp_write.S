#ifndef __DOXYGEN__

#include <avr/io.h>

#if __AVR_XMEGA__

# ifndef CCP_IOREG_gc
#  define CCP_IOREG_gc	0xD8	/* IO Register Protection	*/
# endif

#include "asmdef.h"

/*  void ccp_write_io (uint8_t *__ioaddr, uint8_t __value)
 */
ENTRY	ccp_write_io
	; r24,25 - __ioaddr
	; r22    - __value
	X_movw	r26, r24			; load io addr into X
	ldi		r18, CCP_IOREG_gc	; load IO reg change protection signature
	sts		CCP, r18
	st		x, r22				; write __value to __ioaddr
	ret
ENDFUNC

#endif  /* __AVR_XMEGA__ && CCP_IOREG_gc */ 
#endif  /* !__DOXYGEN__ */

