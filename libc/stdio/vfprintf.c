/* Copyright (c) 2002, Alexander Popov (sasho@vip.bg)
   Copyright (c) 2002, Joerg Wunsch
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

/* From: Id: printf_p_new.c,v 1.1.1.9 2002/10/15 20:10:28 joerg_wunsch Exp */
/* $Id$ */

#include <avr/pgmspace.h>
#include <inttypes.h>
#include <stdarg.h>
#include <stdio.h>

#include "stdio_private.h"

#define BUFLEN 12

/*
 * This file can be compiled into more than one flavour.  The default
 * is to offer the usual modifiers and integer formatting support
 * (level 2).  Level 1 maintains a minimal version that just offers
 * integer formatting, but no modifier support whatsoever.  Level 3 is
 * intented for floating point support.
 */

#ifndef PRINTF_LEVEL
#  define PRINTF_LEVEL 2
#endif

#if PRINTF_LEVEL == 1 || PRINTF_LEVEL == 2
/* OK */
#elif PRINTF_LEVEL == 3
#  error "Not yet implemented."
#else
#  error "Not a known printf level."
#endif

int
vfprintf(FILE *stream, const char *fmt, va_list ap) {
	union {
		char c;
		uint8_t u8;
		int8_t i8;
		long l;
		unsigned long ul;
		char *pc;
	} a;
	char	c;	/* holds a char from the format string */
	uint8_t	base;
	char	b[BUFLEN]; /*
			    * Contains character representation of the
			    * number and its prefix, written from back
			    * to front.
			    */
	char	*pb;	/* used as pointer to an element in b */
#if PRINTF_LEVEL > 1
	int8_t	width;
	uint8_t	prec;
#endif

#if PRINTF_LEVEL < 2
	uint8_t flags;
#else
	uint16_t flags;
#endif

#define FLHASPERCENT	0x01	/* first % found */
#define FLNEGATIVE	0x02	/* arg is negative int */
#define FLLONG		0x04	/* arg is long int */

#if PRINTF_LEVEL > 1
#define FLPREC		0x08	/* .prec given */
#define FLSIGNPLUS	0x10	/* always print '+' sign */
#define FLSIGN		0x20	/* always print sign */
#define FLALT		0x40	/* # alternate specification given */
#define FLLPAD		0x80	/* left-align result */
#define FLZFILL		0x100	/* zero-fill up to width */
#endif /* PRINTF_LEVEL > 1 */

	flags = 0;
	stream->len = 0;

	if ((stream->flags & __SWR) == 0)
		return EOF;

	while ((c = ((stream->flags & __SPGM)? PRG_RDB(fmt++): *fmt++))) {
		if (flags & FLHASPERCENT) {
			if (c >= '0' && c <= '9') {
#if PRINTF_LEVEL > 1
				if (c == '0' && prec == 0 && width == 0) {
					flags |= FLZFILL;
				} else {
					/* digit */
					prec *= 10;
					prec += c - '0';
					if (!(flags & FLPREC) && prec < 128) 
						width = prec;
				}
#endif
			} else {
#if PRINTF_LEVEL > 1
				if ((flags & FLPREC) && prec == 0)
					prec = 1;
#endif /* PRINTF_LEVEL > 1 */
				switch (c) {
				case '+':
#if PRINTF_LEVEL > 1
					flags |= FLSIGNPLUS;
					/* FALLTHROUGH */
#endif /* PRINTF_LEVEL > 1 */
				case ' ':
#if PRINTF_LEVEL > 1
					flags |= FLSIGN;
#endif /* PRINTF_LEVEL > 1 */
					break;
				case '-':
#if PRINTF_LEVEL > 1
					flags |= FLLPAD;
#endif /* PRINTF_LEVEL > 1 */
					break;
				case '#':
#if PRINTF_LEVEL > 1
					flags |= FLALT;
#endif /* PRINTF_LEVEL > 1 */
					break;
				case '.':
#if PRINTF_LEVEL > 1
					flags |= FLPREC;
					flags &= ~FLZFILL;
					prec = 0;
#endif /* PRINTF_LEVEL > 1 */
					break;
				case 'l':
					flags |= FLLONG;
					break;
				case 'e':
				case 'f':
				case 'g':
					a.c = '?';
#if PRINTF_LEVEL > 1
					width--;
#endif /* PRINTF_LEVEL > 1 */
					c = 'c';
					goto nextitem;
				case 'c':
					/* char is promoted to int via va_arg */
					a.c = (char)va_arg(ap, int);
#if PRINTF_LEVEL > 1
					width--;
#endif
					goto nextitem;
				case 's':
					a.pc = va_arg(ap, char *);
					for (base = 0; a.pc[base]; base++)
						; /* calc length of string */
#if PRINTF_LEVEL > 1
					if ((flags & FLPREC) && prec < base)
						base = prec;
					width -= base;
#endif
					goto nextitem;
				case 'd':
				case 'i':
					a.l = flags & FLLONG ?
						va_arg(ap, long):
						va_arg(ap, int);
					if (a.l < 0) {
						flags |= FLNEGATIVE;
						a.l = -a.l;
					}
#if PRINTF_LEVEL > 1
					flags &= ~FLALT;
#endif
					goto processnum;
				case 'o': /* octal number */
					base = 8;
					goto getulong;
				case 'p':
#if PRINTF_LEVEL > 1
					flags |= FLALT;
#endif
					c = 'x';
					/* FALLTHROUGH */
				case 'x':
				case 'X':
					base = 16;
					/* FALLTHROUGH */
				case 'u':
				  getulong:
					a.ul = flags & FLLONG?
						va_arg(ap, unsigned long):
						va_arg(ap, unsigned int);
#if PRINTF_LEVEL > 1
					flags &= ~(FLSIGNPLUS | FLSIGN);
#endif
				  processnum:
					pb = b;
					do {
						*pb = a.ul % base;
						*pb = *pb > 9?
							*pb + c - 'X' + 'A' - 10:
							*pb + '0';
						*pb++;
						a.ul /= base;
					} while (a.ul);
#if PRINTF_LEVEL > 1
					if (flags & FLZFILL) {
						a.i8 = width;
						if (flags & FLALT)
							a.i8 -= base == 16? 2: 1;
						if (flags & FLSIGN)
							a.i8--;
						if (a.i8 > 0) {
							prec = a.i8;
							flags |= FLPREC;
						}
					}
					if (flags & FLPREC) {
						/*
						 * Don't overflow buffer.
						 * Keep space for possible
						 * 0x, trailing '\0', and
						 * optional sign.
						 */
						if (prec > BUFLEN - 4)
							prec = BUFLEN - 4;
						a.u8 = (int8_t)(pb - b);
						while (prec-- > a.u8)
							*pb++ = '0';
					}
#endif
					if (flags & FLNEGATIVE)
						*pb++ = '-';
#if PRINTF_LEVEL > 1
					else if (flags & FLSIGNPLUS)
						*pb++ = '+';
					else if (flags & FLSIGN)
						*pb++ = ' ';
					if (flags & FLALT) {
						if (base == 16)
							*pb++ = c;
						*pb++ = '0';
					}
					width -= (uint8_t)(pb - b);
#endif
				  nextitem:
#if PRINTF_LEVEL > 1
					if (!(flags & FLLPAD))
						while (width-- > 0)
							putc(' ', stream);
#endif
					if (c == 'c')
						putc(a.c, stream);
					else if (c == 's')
						while (base--)
							putc(*a.pc++, stream);
					else 
						while (pb != b)
							putc(*--pb, stream);
#if PRINTF_LEVEL > 1
					if (flags & FLLPAD)
						while (width-- > 0)
							putc(' ', stream);
#endif
					goto clearflags;

				default:
					putc(c, stream);
				  clearflags:
					flags = 0;
					break;
				}
			}
		} else
			if (c == '%') {
				flags = FLHASPERCENT;
#if PRINTF_LEVEL > 1
				prec = width = 0;
#endif
				base = 10;
			} else
				putc(c, stream);
	}

	return stream->len;
}
