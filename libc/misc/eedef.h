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

#if defined(NVMCTRL_CTRLA)
#  undef NVM_BASE
#  define NVM_BASE       NVMCTRL_CTRLA

#  define NVM_ADDR0      NVMCTRL_ADDR0
#  define NVM_ADDR1      NVMCTRL_ADDR1
#  define NVM_DATA0      NVMCTRL_DATA0
#  define NVM_DATA1      NVMCTRL_DATA1
#  define NVM_NVMBUSY_bp NVMCTRL_EEBUSY_bp
#  define NVM_STATUS     NVMCTRL_STATUS
#  define NVM_CTRLA      NVMCTRL_CTRLA
#  define NVM_CTRLB      NVMCTRL_CTRLB
#  ifndef CCP_SPM_gc
#    define CCP_SPM_gc   (0x9D)
#  endif
#  ifndef NVMCTRL_CMD_PAGEERASEWRITE_gc
#    if NVMCTRL_CMD_gm == 0x7F
#      if defined (__AVR_AVR16EA28__) || defined (__AVR_AVR16EA32__) || defined (__AVR_AVR16EA48__) || \
          defined (__AVR_AVR16EB14__) || defined (__AVR_AVR16EB20__) || defined (__AVR_AVR16EB28__) || \
          defined (__AVR_AVR16EB32__) || defined (__AVR_AVR32EA28__) || defined (__AVR_AVR32EA32__) || \
          defined (__AVR_AVR32EA48__) || defined (__AVR_AVR64EA28__) || defined (__AVR_AVR64EA32__) || \
          defined (__AVR_AVR64EA48__)
         /* AVR-Ex family
          * value of NVMCTRL_CMD_enum.NVMCTRL_CMD_EEPERW_gc */
#        define NVMCTRL_CMD_PAGEERASEWRITE_gc (0x15<<0)
#      elif defined (__AVR_AVR32DA28__) || defined (__AVR_AVR32DA32__) || defined (__AVR_AVR32DA48__) || \
            defined (__AVR_AVR64DA28__) || defined (__AVR_AVR64DA32__) || defined (__AVR_AVR64DA48__) || \
            defined (__AVR_AVR64DA64__) || defined (__AVR_AVR128DA28__) || defined (__AVR_AVR128DA32__) || \
            defined (__AVR_AVR128DA48__) || defined (__AVR_AVR128DA64__) || defined (__AVR_AVR32DB28__) || \
            defined (__AVR_AVR32DB32__) || defined (__AVR_AVR32DB48__) || defined (__AVR_AVR64DB28__) || \
            defined (__AVR_AVR64DB32__) || defined (__AVR_AVR64DB48__) || defined (__AVR_AVR64DB64__) || \
            defined (__AVR_AVR128DB28__) || defined (__AVR_AVR128DB32__) || defined (__AVR_AVR128DB48__) || \
            defined (__AVR_AVR128DB64__) || defined (__AVR_AVR16DD14__) || defined (__AVR_AVR16DD20__) || \
            defined (__AVR_AVR16DD28__) || defined (__AVR_AVR16DD32__) || defined (__AVR_AVR32DD14__) || \
            defined (__AVR_AVR32DD20__) || defined (__AVR_AVR32DD32__) || defined (__AVR_AVR32DD28__) || \
            defined (__AVR_AVR64DD14__) || defined (__AVR_AVR64DD20__) || defined (__AVR_AVR64DD28__) || \
            defined (__AVR_AVR64DD32__)
         /* AVR-Dx family
          * value of NVMCTRL_CMD_enum.NVMCTRL_CMD_EEERWR_gc */
#        define NVMCTRL_CMD_PAGEERASEWRITE_gc (0x13<<0)
#      else
         /* To add support for a new device, define NVMCTRL CMD_PAGEERASEWRITE_gc with the value
          * of "Erase and Write EEPROM Page" comand code for - Persistent Memory Controller (NVMCTRL).*/
#        error "Not supported devices"
#      endif
#    else
       /* the rest of the AVR devices with NVMCTRL_CTRLA (0x07)
        * value of NVMCTRL_CMD_enum.NVMCTRL_CMD_PAGEERASEWRITE_gc */
#      define NVMCTRL_CMD_PAGEERASEWRITE_gc 3
#    endif
#  endif /* NVMCTRL_CMD_PAGEERASEWRITE_gc */
#endif /* defined(NVMCTRL_CTRLA) */
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
