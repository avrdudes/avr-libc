/* Copyright (c) 2010, Joerg Wunsch
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

/* avr/cpufunc.h - Special CPU functions */

#ifndef _AVR_CPUFUNC_H_
#define _AVR_CPUFUNC_H_ 1

#include <stdint.h>

/** \file */
/** \defgroup avr_cpufunc <avr/cpufunc.h>: Special AVR CPU functions
    \code #include <avr/cpufunc.h> \endcode

    This header file contains macros that access special functions of
    the AVR CPU which do not fit into any of the other header files.

*/


/**
   \ingroup avr_cpufunc
   \def _NOP

   Execute a <i>no operation</i> (NOP) CPU instruction.  This
   should not be used to implement delays, better use the functions
   from <util/delay_basic.h> or <util/delay.h> for this.  For
   debugging purposes, a NOP can be useful to have an instruction that
   is guaranteed to be not optimized away by the compiler, so it can
   always become a breakpoint in the debugger.
*/
#define _NOP() __asm__ __volatile__("nop")


/**
   \ingroup avr_cpufunc
   \def _MemoryBarrier

   Implement a read/write <i>memory barrier</i>.  A memory
   barrier instructs the compiler to not cache any memory data in
   registers beyond the barrier.  This can sometimes be more effective
   than blocking certain optimizations by declaring some object with a
   \c volatile qualifier.

   See \ref optim_code_reorder for things to be taken into account
   with respect to compiler optimizations.
*/
#define _MemoryBarrier() __asm__ __volatile__("" ::: "memory")

#include <avr/io.h>
#include <bits/attribs.h>

#ifdef __cplusplus
extern "C" {
#endif

/**
   \ingroup avr_cpufunc

   Write \a __value to IO Register Protected (CCP) 8-bit IO register
   at \a __ioaddr. See also \c _PROTECTED_WRITE().  */
extern void ccp_write_io (volatile void *__ioaddr, uint8_t __value);

#if __AVR_ARCH__ >= 100
extern __ATTR_ALWAYS_INLINE__ __ATTR_GNU_INLINE__
void ccp_write_io (volatile void *__ioaddr, uint8_t __value)
{
  const uintptr_t __addr = (uintptr_t) __ioaddr;

#ifdef __AVR_TINY__
  if (__builtin_constant_p (__addr))
    __asm__ __volatile__ ("out %i0, %1" "\n\t"
			  "out %i2, %3"
			  :
			  : "n" (& CCP),
			    "d" ((uint8_t) 0xd8),
			    "n" (__addr),
			    "r" ((uint8_t) __value));
  else
    __asm__ __volatile__ ("out %i0, %1" "\n\t"
			  "st %a2, %3"
			  :
			  : "n" (& CCP),
			    "d" ((uint8_t) 0xd8),
			    "e" (__addr),
			    "r" ((uint8_t) __value));
#elif defined(__AVR_XMEGA__)
  if (__builtin_constant_p (__addr))
    __asm__ __volatile__ ("out %i0, %1" "\n\t"
			  "sts %2, %3"
			  :
			  : "n" (& CCP),
			    "d" ((uint8_t) CCP_IOREG_gc),
			    "n" (__addr),
			    "r" ((uint8_t) __value));
  else
    __asm__ __volatile__ ("out %i0, %1" "\n\t"
			  "st %a2, %3"
			  :
			  : "n" (& CCP),
			    "d" ((uint8_t) CCP_IOREG_gc),
			    "e" (__addr),
			    "r" ((uint8_t) __value));
#endif
}
#endif /* ARCH >= 100 */

/**
   \ingroup avr_cpufunc

   Write \a __value to SPM Instruction Protected (CCP) 8-bit IO register
   at \a __ioaddr. See also \c _PROTECTED_WRITE_SPM().  */
extern void ccp_write_spm (volatile void *__ioaddr, uint8_t __value);

#if defined(__AVR_XMEGA__) || defined(CCP_SPM_gc)
extern __ATTR_ALWAYS_INLINE__ __ATTR_GNU_INLINE__
void ccp_write_spm (volatile void *__ioaddr, uint8_t __value)
{
  const uintptr_t __addr = (uintptr_t) __ioaddr;

  if (__builtin_constant_p (__addr))
    __asm__ __volatile__ ("out %i0, %1" "\n\t"
#ifdef __AVR_TINY__
			  "out %i2, %3"
#else
			  "sts %2, %3"
#endif
			  :
			  : "n" (& CCP),
			    "d" ((uint8_t) CCP_SPM_gc),
			    "n" (__addr),
			    "r" ((uint8_t) __value));
  else
    __asm__ __volatile__ ("out %i0, %1" "\n\t"
			  "st %a2, %3"
			  :
			  : "n" (& CCP),
			    "d" ((uint8_t) CCP_SPM_gc),
			    "e" (__addr),
			    "r" ((uint8_t) __value));
}
#endif /* AVR_XMEGA || ATtiny102/104 */

#ifdef __cplusplus
}
#endif

#endif /* _AVR_CPUFUNC_H_ */
