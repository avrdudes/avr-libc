/* Copyright (c) 2002, Reiner Patommel
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

/* ---------------------------------------------------------------------------------------
   atan.S

   Contributors:
     Created by Reiner Patommel
     Changed by Reiner Patommel 31 August 2002
     Changes: swapped arguments x and y for call of atan2 because of change to atan2

 -*- Mode: Asm -*-

 /*----------------------------------------------------------------------------------------
 *  A = atan(A)
 *---------------------------------------------------------------------------------------*/

 #include "gasava.inc"
 #include "fplib.inc"

 TEXT_SEG(fplib, atan)
 FUNCTION(atan)

 GLOBAL(atan)
    LDI     rB3, 0x3F
    LDI     rB2, 0x80
    CLR     rB1
    CLR     rB0             ; load 1.0
    XJMP    _U(atan2)       ; atan(A) = atan2(A, 1.0)
 ENDFUNC
 ; --------------------------------------------------------------------------------------

