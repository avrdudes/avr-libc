#ifndef __DOXYGEN__

#include <avr/io.h>

/* Only compile if the device has the NVMCTRL_CTRLB.FLMAP bit-field.
   We don't use avr-gcc's __AVR_HAVE_FLMAP__ so that the code below can be
   used with avr-gcc that's not configured against Binutils with PR31124.
   In that case, the user can provide her own linker description file like
   it comes with Binutils v2.42.  */
#ifdef NVMCTRL_FLMAP_gm

/* The purpose of this module is to initialize bit-field NVMCTRL_CTRLB.FLMAP
   according to symbol __flmap.  The initialization must happen early, prior
   to the call of any static constructors, which is accomplished by the code
   in section .init3 below.  */
#define FUNC_SEGNAME ".init3"
#include "asmdef.h"

/* Referenced by the compiler as needed.  This function must not be called
   because it is naked.  */
ENTRY   _U(__do_flmap_init)

/* Definitions in avr/io*.h are neglecting assembly, so...  */
#ifndef CCP_IOREG_gc
#define CCP_IOREG_gc    0xD8    /* IO Register Protection */
#endif

/* The following symbols are inputs to the default linker script for
   emulations avrxmega2, avrxmega2_flmap, avrxmega4, avrxmega4_flmap
   in Binutils since v2.42 (PR31124):
       __RODATA_FLASH_START__, __flmap, __flmap_lock, __flmap_lock_mask,
       __flmap_bpos, __flmap_init_start, __flmap_noinit_start.
   The following symbols are outputs:
       __flmap_value_with_lock, __flmap_init_label.

   In order to work as expected with Binutils without PR31124, default values
   are defined for __flmap_value_with_lock but *NOT* for __flmap_init_label.
   For rationale, see the comments at the end of this file.  */

;; Defaulting __flmap to the last 32k flash block.
;; This is also the hardware default for FLMAP.
.weak   __flmap
.set    __flmap, (FLASHEND + 1 - 0x8000) >> 15
;; Changing FLMAP in the program will invoke UB, hence allow the user
;; to set FLMAPLOCK by setting __flmap_lock to non-0.
.weak   __flmap_lock
.set    __flmap_lock, 0
;; Describe positions of FLMAP and mask for FLMAPLOCK in NVMCTRL_CTRLB.
;; Mask to lock / protect FLMAP in NVMCTRL_CTRLB provided __flmap_lock.
.global __flmap_lock_mask
.set    __flmap_lock_mask, NVMCTRL_FLMAPLOCK_bm
;; Bit position of the FLMAP bit field in NVMCTRL_CTRLB.
.global __flmap_bpos
.set    __flmap_bpos, NVMCTRL_FLMAP_gp

;; Conditional RJMP depending on emulation:
;; avrxmega[2|4]        ->  __flmap_noinit_start
;; avrxmega[2|4]_flmap  ->  __flmap_init_start
.global __flmap_init_start
.global __flmap_noinit_start
    rjmp __flmap_init_label     ; Resolves to one of __flmap_[no]init_start

__flmap_init_start = .
    lds r18, NVMCTRL_CTRLB
    cbr r18, NVMCTRL_FLMAP_gm
#if NVMCTRL_FLMAP_gm == 0x30
    ;; r18 |= (flmap << bpos) | (lock_mask & (flmap_lock ? 0xff : 0))
    ori r18, __flmap_value_with_lock
#else
#error init FLMAP
#endif
    ldi     r19, CCP_IOREG_gc   ; Load I/O reg change protection signature.
    out     CCP, r19
    sts     NVMCTRL_CTRLB, r18
__flmap_noinit_start = .

;; There may be the case that this code is used with a toolchain that
;; does not support Binutils PR31124.  This can happen when the code
;; is shipped with a device support pack.  In that case, linking the
;; code would raise undefined references to __flmap_init_label and
;; __flmap_value_with_lock.  Therefore, provide default values.
.weak   __flmap_value_with_lock
.set    __flmap_value_with_lock, NVMCTRL_FLMAP_gm
;; The linker scripts for emulations avrxmega2/4_flmap define symbol
;; __flmap_init_label as PROVIDE, hence a weak definition of __flmap_init_label
;; like below would bypass the instructions above by  RJMP __flmap_noinit_start.
;; There is an addendum PR31321 to PR31124 which removes the PROVIDE, but
;; that's not in v2.42 and only in v2.43 (or v2.42.1).
;; In the case when an undefined reference occurs, the fix is to
;;     -Wl,--defsym,__flmap_init_label=__flmap_noinit_start
;; The same can be achieved with (inline) assembly:
;      .weak  __flmap_init_label
;      .set   __flmap_init_label, __flmap_noinit_start
;; Alternatively, one can  -Wl,--defsym,__init_flmap=0  in order to satisfy
;; the symbol so that the code from above is not dragged.

ENDFUNC

#endif  /* Have NVMCTRL_CTRLB.FLMAP */

#endif  /* !__DOXYGEN__ */
