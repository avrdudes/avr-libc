/* Copyright (c) 2012 Joerg Wunsch
   All rights reserved.

   Redistribution and use in source and binary forms, with or without
   modification, are permitted provided that the following conditions are met:

   * Redistributions of source code must retain the above copyright
     notice, this list of conditions and the following disclaimer.

   * Redistributions in binary form must reproduce the above copyright
     notice, this list of conditions and the following disclaimer in
     the documentation and/or other materials provided with the
     distribution.

   * Neither the name of the copyright holders nor the names of
     contributors may be used to endorse or promote products derived
     from this software without specific prior written permission.

  THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS "AS IS"
  AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE
  IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE
  ARE DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT OWNER OR CONTRIBUTORS BE
  LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR
  CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF
  SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS
  INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN
  CONTRACT, STRICT LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE)
  ARISING IN ANY WAY OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE
  POSSIBILITY OF SUCH DAMAGE. */

/* $Id$ */

/*
 * This file is included by <avr/io.h> whenever compiling for an Xmega
 * device.  It abstracts certain features common to the Xmega device
 * families.
 */

#ifndef _AVR_XMEGA_H
#define _AVR_XMEGA_H

#ifdef __DOXYGEN__
/**
 \def _PROTECTED_WRITE
 \ingroup avr_io

 Write value \c value to IO register \c reg that is protected through
 the Xmega configuration change protection (CCP) mechanism.  This
 implements the timed sequence that is required for CCP.

 Example to modify the CPU clock:
 \code
 #include <avr/io.h>

 _PROTECTED_WRITE(CLK_PSCTRL, CLK_PSADIV0_bm);
 _PROTECTED_WRITE(CLK_CTRL, CLK_SCLKSEL0_bm);
 \endcode
 */
#define _PROTECTED_WRITE(reg, value)

/**
 \def _PROTECTED_WRITE_SPM
 \ingroup avr_io

 Write value \c value to register \c reg that is protected through
 the Xmega configuration change protection (CCP) key for self
 programming (SPM).  This implements the timed sequence that is
 required for CCP.

 Example to modify the CPU clock:
 \code
 #include <avr/io.h>

 _PROTECTED_WRITE_SPM(NVMCTRL_CTRLA, NVMCTRL_CMD_PAGEERASEWRITE_gc);
 \endcode
 */
#define _PROTECTED_WRITE_SPM(reg, value)

#else  /* !__DOXYGEN__ */

#define _PROTECTED_WRITE(reg, value)				\
  __asm__ __volatile__("out %[ccp], %[ccp_ioreg]" "\n\t"	\
		       "sts %[ioreg], %[val]"			\
		       :					\
		       : [ccp] "I" (_SFR_IO_ADDR(CCP)),		\
			 [ccp_ioreg] "d" ((uint8_t)CCP_IOREG_gc),	\
			 [ioreg] "n" (_SFR_MEM_ADDR(reg)),	\
			 [val] "r" ((uint8_t)value))

#define _PROTECTED_WRITE_SPM(reg, value) \
  __asm__ __volatile__("out %[ccp], %[ccp_spm_mask]" "\n\t" \
                       "sts %[ioreg], %[val]"               \
                       :                                    \
                       : [ccp]          "I" (_SFR_IO_ADDR(CCP)), \
                         [ccp_spm_mask] "d" ((uint8_t)CCP_SPM_gc), \
                         [ioreg]        "n" (_SFR_MEM_ADDR(reg)), \
                         [val]          "r" ((uint8_t)value))
#endif /* DOXYGEN */

#ifdef __DOXYGEN__
/**
 \ingroup avr_io

 Initialize bit-fields \c NVMCTRL_CTRLB.FLMAP and
 \c NVMCTRL_CTRLB.FLMAPLOCK according to the value of symbols
 \c __flmap and \c __flmap_lock.
 The function itself does not execute any code, it just arranges the
 start-up code so that these bit-fields are initialized accordingly.

 This can be used on AVR-Dx and AVR-Ex devices like \c AVR64* and \c AVR128*
 when read-only data in \c .rodata is located in program memory (flash).

 Locating \c .rodata in flash requires three parts:
 -# A linker description file that \b locates \c .rodata in flash. This requires
  Binutils v2.42 or a linker description file according to Binutils
  <a href="https://sourceware.org/PR31124">PR31124</a>.
 -# A start-up code that \b initializes the hardware according to the actual
  location of \c .rodata. This is accomplished by \c init_flmap().
  The (hardware) default is to use the last 32 KiB block for \c .rodata,
  which means that \c init_flmap() is only required when a
  different location is used (but \c init_flmap() works in any case).
 -# The user has to \b specify the location of \c .rodata when a non-default
  placement is desired.  For example, you can <tt>-Wl,\--defsym,__flmap=1</tt>
  or <tt>-Wl,\--defsym,__RODATA_FLASH_START__=32k</tt> to specify the second
  32 KiB block.  \c __RODATA_FLASH_START__  takes precedence over \c __flmap.
  \n
  Defining symbol \c __flmap_lock to a non-zero value will have the effect
  that bit \c NVMCTRL_CTRLB.FLMAPLOCK will be set, which will protect
  \c NVMCTRL_CTRLB.FLMAP from future changes.

  For convenience,
  <a href="https://gcc.gnu.org/gcc-14/changes.html#avr">avr-gcc v14</a>
  supports a new command-line option \c -mrodata-in-ram to return to the old
  layout with \c .rodata in RAM.
  \c init_flmap() will work as expected in that case, too,
  i.e. \c NVMCTRL_CTRLB will be unaltered.

 Example
 \code
 #include <avr/io.h>

 init_flmap();
 \endcode

 When you prefer a command-line option over a call-like symbol reference,
 you can achieve the same effect by means of linking with
 <tt>avr-gcc ... -Wl,-u,__init_flmap</tt>
 */
void init_flmap (void);
#else /* __DOXYGEN__ */

#ifndef __ASSEMBLER__

#ifndef __ATTR_ALWAYS_INLINE__
#define __ATTR_ALWAYS_INLINE__ __inline__ __attribute__((__always_inline__))
#endif

static __ATTR_ALWAYS_INLINE__
void init_flmap (void)
{
  __asm ("__do_init_flmap");
}
#endif /* ASSEMBLER */
#endif /* __DOXYGEN__ */

#endif /* _AVR_XMEGA_H */
