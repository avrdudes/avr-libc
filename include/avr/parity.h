/* Copyright (c) 2002, Marek Michalkiewicz
   All rights reserved.

   Redistribution and use in source and binary forms, with or without
   modification, are permitted provided that the following conditions are met:

   * Redistributions of source code must retain the above copyright
     notice, this list of conditions and the following disclaimer.
   * Redistributions in binary form must reproduce the above copyright
     notice, this list of conditions and the following disclaimer in
     the documentation and/or other materials provided with the
     distribution.

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

/* avr/parity.h - optimized code to calculate parity bit of a byte */

#ifndef _AVR_PARITY_H_
#define _AVR_PARITY_H_

#define parity_even_bit(val) ({				\
	unsigned char __t;				\
	__asm__ (					\
		"mov __tmp_reg__,%0" "\n\t"		\
		"swap %0" "\n\t"			\
		"eor %0,__tmp_reg__" "\n\t"		\
		"mov __tmp_reg__,%0" "\n\t"		\
		"lsr %0" "\n\t"				\
		"lsr %0" "\n\t"				\
		"eor %0,__tmp_reg__" 			\
		: "=r" (__t)				\
		: "0" ((unsigned char)(val))		\
		: "r0"					\
	);						\
	(((__t + 1) >> 1) & 1);				\
 })

#endif /* _AVR_PARITY_H_ */
