/* Copyright (c) 2008  Dmitry Xmelkov
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
   POSSIBILITY OF SUCH DAMAGE.
 */

/* Test of _SFR's macroses.  Old style ASM program, where the ports are
   values, suitable to use with LDS/STS instruction.
   $Id$	*/

/* XXX: Seems, the _SFR_MEM_ADDR() is worse.  In this case it works only
   with ports, which have the address higher then SREG.  There is no
   method to obtain the address suitable for LDS/STS instruction.  Now
   this test cases are commented.  Second, the _SFR_ADDR() is not defined.
   This is mismatch to C behavior (_SFR_ASM_COMPAT, __SFR_OFFSET = 0).	*/

#define __SFR_OFFSET	0
#include <avr/io.h>

#if	defined (__AVR_AT90S8515__)

# if	 SREG != 0x3F			\
     /*||  _SFR_ADDR (SREG) != 0x5F*/	\
     /*||  _SFR_MEM_ADDR (SREG) != 0x5F*/	\
     ||	 _SFR_IO_ADDR (SREG) != 0x3F	\
     ||	 !_SFR_IO_REG_P (SREG)
#  error
# endif

# if	 WDTCR != 0x21			\
     /*||  _SFR_ADDR (WDTCR) != 0x41*/	\
     /*||  _SFR_MEM_ADDR (WDTCR) != 0x41*/	\
     ||  _SFR_IO_ADDR (WDTCR) != 0x21	\
     ||	 !_SFR_IO_REG_P (WDTCR)
#  error
# endif

# if	 EEARH != 0x1F			\
     /*||  _SFR_ADDR (EEARH) != 0x3F*/	\
     /*||  _SFR_MEM_ADDR (EEARH) != 0x3F*/	\
     ||  _SFR_IO_ADDR (EEARH) != 0x1F	\
     ||  !_SFR_IO_REG_P (EEARH)
#  error
# endif

# if	 ACSR != 0x08			\
     /*||  _SFR_ADDR (ACSR) != 0x28*/	\
     /*||  _SFR_MEM_ADDR (ACSR) != 0x28*/	\
     ||  _SFR_IO_ADDR (ACSR) != 0x08	\
     ||  !_SFR_IO_REG_P (ACSR)
#  error
# endif

#elif	defined (__AVR_ATmega8__)

# if	 SREG != 0x3F			\
     /*||  _SFR_ADDR (SREG) != 0x5F*/	\
     /*||  _SFR_MEM_ADDR (SREG) != 0x5F*/	\
     ||  _SFR_IO_ADDR (SREG) != 0x3F	\
     ||  !_SFR_IO_REG_P (SREG)
#  error
# endif

# if	 UCSRC != 0x20			\
     /*||  _SFR_ADDR (UCSRC) != 0x40*/	\
     /*||  _SFR_MEM_ADDR (UCSRC) != 0x40*/	\
     ||  _SFR_IO_ADDR (UCSRC) != 0x20	\
     ||  !_SFR_IO_REG_P (UCSRC)
#  error
# endif

# if	 EEARH != 0x1F			\
     /*||  _SFR_ADDR (EEARH) != 0x3F*/	\
     /*||  _SFR_MEM_ADDR (EEARH) != 0x3F*/	\
     ||  _SFR_IO_ADDR (EEARH) != 0x1F	\
     ||  !_SFR_IO_REG_P (EEARH)
#  error
# endif

# if	 TWBR != 0x00			\
     /*||  _SFR_ADDR (TWBR) != 0x20*/	\
     /*||  _SFR_MEM_ADDR (TWBR) != 0x20*/	\
     ||  _SFR_IO_ADDR (TWBR) != 0x00	\
     ||  !_SFR_IO_REG_P (TWBR)
#  error
# endif

#elif	defined (__AVR_ATmega128__)

# if	 UCSR1C != 0x9D			\
     /*||  _SFR_ADDR (UCSR1C) != 0x9D*/	\
     ||  _SFR_MEM_ADDR (UCSR1C) != 0x9D	\
     ||  _SFR_IO_REG_P (UCSR1C)
#  error
# endif

# if	 DDRF != 0x61			\
     /*||  _SFR_ADDR (DDRF) != 0x61*/	\
     ||  _SFR_MEM_ADDR (DDRF) != 0x61	\
     ||  _SFR_IO_REG_P (DDRF)
#  error
# endif

# if	 SREG != 0x3F			\
     /*||  _SFR_ADDR (SREG) != 0x5F*/	\
     /*||  _SFR_MEM_ADDR (SREG) != 0x5F*/	\
     ||  _SFR_IO_ADDR (SREG) != 0x3F	\
     ||  !_SFR_IO_REG_P (SREG)
#  error
# endif

# if	 SFIOR != 0x20			\
     /*||  _SFR_ADDR (SFIOR) != 0x40*/	\
     /*||  _SFR_MEM_ADDR (SFIOR) != 0x40*/	\
     ||  _SFR_IO_ADDR (SFIOR) != 0x20	\
     ||  !_SFR_IO_REG_P (SFIOR)
#  error
# endif

# if	 EEARH != 0x1F			\
     /*||  _SFR_ADDR (EEARH) != 0x3F*/	\
     /*||  _SFR_MEM_ADDR (EEARH) != 0x3F*/	\
     ||  _SFR_IO_ADDR (EEARH) != 0x1F	\
     ||  !_SFR_IO_REG_P (EEARH)
#  error
# endif

# if	 PINF != 0x00			\
     /*||  _SFR_ADDR (PINF) != 0x20*/	\
     /*||  _SFR_MEM_ADDR (PINF) != 0x20*/	\
     ||  _SFR_IO_ADDR (PINF) != 0x00	\
     ||  !_SFR_IO_REG_P (PINF)
#  error
# endif

#endif


.macro	EXIT	result
	ldi	r24, lo8 (\result)
	ldi	r25, hi8 (\result)
	rjmp	exit
.endm

	.text
	.global	main
main:
	sei
	in	r16, SREG
	sbrc	r16, SREG_I
	rjmp	0f
	EXIT	__LINE__

0:	cli
	in	r16, SREG
	sbrs	r16, SREG_I
	rjmp	0f
	EXIT	__LINE__

0:	sei
;;;	lds	r16, _SFR_ADDR (SREG)
;;;	sbrc	r16, SREG_I
	rjmp	0f
	EXIT	__LINE__

0:	cli
;;;	lds	r16, _SFR_ADDR (SREG)
;;;	sbrs	r16, SREG_I
	rjmp	0f
	EXIT	__LINE__

0:	sei
;;;	lds	r16, _SFR_MEM_ADDR (SREG)
;;;	sbrc	r16, SREG_I
	rjmp	0f
	EXIT	__LINE__

0:	cli
;;;	lds	r16, _SFR_MEM_ADDR (SREG)
;;;	sbrs	r16, SREG_I
	rjmp	0f
	EXIT	__LINE__

0:	sei
	in	r16, _SFR_IO_ADDR (SREG)
	sbrc	r16, SREG_I
	rjmp	0f
	EXIT	__LINE__

0:	cli
	in	r16, _SFR_IO_ADDR (SREG)
	sbrs	r16, SREG_I
	rjmp	0f
	EXIT	__LINE__

0:	EXIT	0
	.end
