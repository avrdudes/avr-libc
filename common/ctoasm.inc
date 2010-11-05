/* Copyright (c) 1999, Michael Stumpf
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

/*
    CtoASM.inc

    Specify the parameter passing from C functions

    Michael Stumpf, (c) 9. August 1999
*/

#ifndef __CTOASM_INC
#define __CTOASM_INC

#define rP0      r25   /* first incoming parameter (MSB) */
#define rP1      r24   /* 2nd incoming parameter         */
#define rP2      r23   /* 3rd incoming parameter         */
#define rP3      r22   /* 4th incoming parameter         */
#define rP4      r21   /* */
#define rP5      r20   /* */
#define rP6      r19   /* */
#define rP7      r18   /* */

#define rByte    r24   /* a function returning a byte passes this as if it was
                          an integer in R25:R24, but R25 is unused */

/* Temporary registers, usable without saving,
   maybe clobbered after an external function call */
#if !defined(__tmp_reg__)
    #if defined(__AVR_TINY__)
        #define __tmp_reg__ r16
    #else
        #define __tmp_reg__ r0
    #endif
#endif

/* The zero constant register MUST be cleared on return. */
#if !defined(__zero_reg__)
    #if defined(__AVR_TINY__)
        #define __zero_reg__ r17
    #else
        #define __zero_reg__ r1
    #endif
#endif



#define rTI0     r31  /* 1st temporary with immidiate */
#define rTI1     r30  /* 2nd temporary with immidiate */
#define rTI2     r27  /* 3rd temporary with immidiate */
#define rTI3     r26  /* 4th temporary with immidiate */

/* registers wich have to be saved */
#define rSI0     r17   /* first saved (pushed) register with immidiate */
#define rSI1     r16   /* 2nd push register  */
#define rSI2     r29   /* 3rd saved (pushed) register */
#define rSI3     r28   /* 4th saved (pushed) register  */

#define rS0      r15   /* 3rd pushed register  */
#define rS1      r14   /* 4th pushed register  */
#define rS2      r13   /* */
#define rS3      r12   /* */
#define rS4      r11   /* */
#define rS5      r10   /* */
#define rS6      r9    /* */
#define rS7      r8    /* */
#define rS8      r7    /* */
#define rS9      r6    /* */
#define rS10     r5    /* */
#define rS11     r4    /* */
#define rS12     r3    /* */
#define rS13     r2    /* */

#endif /* __CTOASM_INC */
