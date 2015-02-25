/* Copyright (c) 2009  Dmitry Xmelkov
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
   POSSIBILITY OF SUCH DAMAGE.	*/

/* $Id$	*/

#ifndef	_EEDEF_H_
#define _EEDEF_H_  1

#ifndef	__DOXYGEN__

/* EEPROM address arg for a set of byte/word/dword functions and for
   the internal eeprom_read_blraw().	*/
#define addr_lo	r24
#define addr_hi	r25

/* Number of bytes arg for all block read/write functions, include
   internal.	*/
#define n_lo	r20
#define n_hi	r21

#if	__AVR_XMEGA__

# define NVM_BASE	NVM_ADDR0

#else

# if	!defined (EECR) && defined (DEECR)	/* AT86RF401	*/
#  define EECR	DEECR
#  define EEARL	DEEAR
#  define EEDR	DEEDR
# endif

# if	!defined (EERE) && defined (EER)	/* AT86RF401	*/
#  define EERE	EER
# endif

# if	!defined (EEWE) && defined (EEPE)	/* A part of Mega and Tiny */
#  define EEWE	EEPE
# endif
# if	!defined (EEWE) && defined (EEL)	/* AT86RF401	*/
#  define EEWE	EEL
# endif

# if	!defined (EEMWE) && defined (EEMPE)	/* A part of Mega and Tiny */
#  define EEMWE	EEMPE
# endif
# if	!defined (EEMWE) && defined (EEU)	/* AT86RF401	*/
#  define EEMWE	EEU
# endif

# if	!_SFR_IO_REG_P (EECR)	\
     || !_SFR_IO_REG_P (EEDR)	\
     || !_SFR_IO_REG_P (EEARL)	\
     || (defined (EEARH) && !_SFR_IO_REG_P (EEARH))
#  error
# endif

#endif	/* !__AVR_XMEGA__ */
#endif	/* !__DOXYGEN__ */
#endif	/* !_EEDEF_H_ */
