/* Copyright (c) 2002  Michael Stumpf  <Michael.Stumpf@t-online.de>

   This file is free software; you can redistribute it and/or modify it under
   the terms of the GNU General Public License as published by the Free
   Software Foundation; either version 2, or (at your option) any later
   version.

   In addition to the permissions in the GNU General Public License, the
   author gives you unlimited permission to link the compiled version of this
   file into combinations with other programs, and to distribute those
   combinations without any restriction coming from the use of this file.
   (The General Public License restrictions do apply in other respects; for
   example, they cover modification of the file, and distribution when not
   linked into a combine executable.)

   This file is distributed in the hope that it will be useful, but WITHOUT
   ANY WARRANTY; without even the implied warranty of MERCHANTABILITY or
   FITNESS FOR A PARTICULAR PURPOSE.  See the GNU General Public License for
   more details. */

#include "fplib-as.inc"

          TEXT_SEG(irexp)
          FUNC(irexp)

GLOBAL(irexp)
        BST     rA3,7
        RCALL   _UG(fp_split1)	;
        TST     rA3
        BREQ    _frexp_200
        SUBI    rA3, 0x7E	; 0.5 -> 0.5 * 2^0
				; 1.0 -> 0.5 * 2^1
	sbc	rB0, rB0	; sign expand rA3
	mov	rA2, rA3
	mov     rA3, rB0
        RET

 _irexp_200:
	mov	rA2, rA3
	mov	rA3, rT1c
	ret

          ENDFUNC


