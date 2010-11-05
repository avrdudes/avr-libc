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
  POSSIBILITY OF SUCH DAMAGE.
*/

/* $Id$ */

/** \file */

/** \ingroup avr_pgmspace
    \fn char *strtok_rP (char *string, PGM_P delim, char **last)
    \brief Parses string into tokens.

    The strtok_rP() function parses \p string into tokens. The first call to
    strtok_rP() should have string as its first argument. Subsequent calls
    should have the first argument set to NULL. If a token ends with a
    delimiter, this delimiting character is overwritten with a '\\0' and a
    pointer to the next character is saved for the next call to strtok_rP().
    The delimiter string \p delim may be different for each call. \p last is
    a user allocated char* pointer. It must be the same while parsing the
    same string. strtok_rP() is a reentrant version of strtok_P().

    The strtok_rP() function is similar to strtok_r() except that \p delim
    is pointer to a string in program space.

    \returns The strtok_rP() function returns a pointer to the next token or
    NULL when no more tokens are found. */

#if !defined(__AVR_TINY__)

#if !defined(__DOXYGEN__)

#include "asmdef.h"

/*  char *strtok_r (char *s, const char *delim, char **last)
    {
	char *p = *last;
	const char *q;
	char c, d;

	if (!s) {
	    if (!p) return s;		// end of string
	    s = p;			// continue parsing
	}

	p = s;
	for (;;) {			// skip delimeters
	    s = p;			// space optimization (vs. s = p-1)
	    if (!(c = *p++)) {
		s = 0;
		p = 0;
		goto ret;
	    }
	    q = delim;
	    do {
		if (!(d = *q++))
		    goto find_end;
	    } while (d != c);
	}

      find_end:
	do {
	    q = delim;
	    do {
		d = *q++;
		if (c == d) {
		    *--p = 0;
		    p++;
		    goto ret;
		}
	    } while (d);
	} while ((c = *p++) != 0);
	p = 0;				// stop parsing
      ret:
	*last = p;
	return s;
    }
 */

#define str_hi	r25
#define str_lo	r24
#define dlm_lo	r22
#define lst_lo	r20

ENTRY strtok_rP

/* Two variants below are different in registers to load chars. In case
   of enhanced core it is convinient to use <R0,R1> pair as zero word.
   In classic case it is optimal to load delimeter char (flash) to R0.
 */

/* --------------------------------------------------------------------	*/
#if	__AVR_HAVE_LPMX__

# define dlm_ch r18		/* delimeter character	*/
# define str_ch r0		/* string character	*/

	X_movw	ZL, lst_lo
	ld	XL, Z+			; X = *last
	ld	XH, Z
  ; check str
	sbiw	str_lo, 0
	brne	1f
	sbiw	XL, 0
	breq	.Lret			; end of string
	X_movw	str_lo, XL		; continue parsing

  ; skip delimeters
1:	X_movw	XL, str_lo		; p = str
2:	X_movw	str_lo, XL
	ld	str_ch, X+
	tst	str_ch
	brne	3f
	X_movw	str_lo, str_ch		; <r0,r1>
	rjmp	.Lclr
3:	X_movw	ZL, dlm_lo
4:	lpm	dlm_ch, Z+
	tst	dlm_ch
	breq	5f			; goto find
	cp	dlm_ch, str_ch
	brne	4b
	rjmp	2b			; skip 1 byte

  ; find new token end
5:	X_movw	ZL, dlm_lo
6:	lpm	dlm_ch, Z+
	cp	dlm_ch, str_ch		; str_ch != 0
	brne	7f
	st	-X, __zero_reg__
	adiw	XL, 1
	rjmp	.Lret
7:	tst	dlm_ch
	brne	6b
  ; next str byte
	ld	str_ch, X+
	tst	str_ch
	brne	5b

  ; stop parsing
.Lclr:	X_movw	XL, str_ch		; <r0,r1>
  ; save last pointer
.Lret:	X_movw	ZL, lst_lo		; *last = X
	st	Z+, XL
	st	Z, XH
	ret

/* --------------------------------------------------------------------	*/
#else	/* !__AVR_HAVE_LPMX__ */

# define dlm_ch r0		/* delimeter character	*/
# define str_ch r18		/* string character	*/

	X_movw	ZL, lst_lo
	ld	XL, Z+			; X = *last
	ld	XH, Z
  ; check str
	sbiw	str_lo, 0
	brne	1f
	sbiw	XL, 0
	breq	.Lret			; end of string
	X_movw	str_lo, XL		; continue parsing

  ; skip delimeters
1:	X_movw	XL, str_lo		; p = str
2:	X_movw	str_lo, XL
	ld	str_ch, X+
	tst	str_ch
	brne	3f
	clr	str_lo			; return value
	clr	str_hi
	rjmp	.Lclr
3:	X_movw	ZL, dlm_lo
4:	lpm				; lpm r0,Z
	adiw	ZL, 1
	tst	dlm_ch
	breq	5f			; goto find
	cp	dlm_ch, str_ch
	brne	4b
	rjmp	2b			; skip 1 byte

  ; find new token end
5:	X_movw	ZL, dlm_lo
6:	lpm				; lpm r0,Z
	adiw	ZL, 1
	cp	dlm_ch, str_ch		; str_ch != 0
	brne	7f
	st	-X, __zero_reg__
	adiw	XL, 1
	rjmp	.Lret
7:	tst	dlm_ch
	brne	6b
  ; next str byte
	ld	str_ch, X+
	tst	str_ch
	brne	5b

  ; stop parsing
.Lclr:	clr	XL
	clr	XH
  ; save last pointer
.Lret:	X_movw	ZL, lst_lo		; *last = X
	st	Z+, XL
	st	Z, XH
	ret

/* --------------------------------------------------------------------	*/
#endif	/* !__AVR_HAVE_LPMX__ */

ENDFUNC

#endif /* not __DOXYGEN__ */

#endif /* !defined(__AVR_TINY__) */
