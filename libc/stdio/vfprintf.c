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
	int8_t	width;
	uint8_t	base, prec;
	char	b[BUFLEN]; /*
			    * Contains character representation of the
			    * number and its prefix, written from back
			    * to front.
			    */
	char	*pb;	/* used as pointer to an element in b */

	uint16_t flags;

#define FLHASPERCENT	0x01	/* first % found */
#define FLNEGATIVE	0x02	/* arg is negative int */
#define FLLONG		0x04	/* arg is long int */
#define FLPREC		0x08	/* .prec given */
#define FLSIGNPLUS	0x10	/* always print '+' sign */
#define FLSIGN		0x20	/* always print sign */
#define FLALT		0x40	/* # alternate specification given */
#define FLLPAD		0x80	/* left-align result */
#define FLZFILL		0x100	/* zero-fill up to width */

	flags = 0;
	stream->len = 0;

	if ((stream->flags & __SWR) == 0)
		return EOF;

	while ((c = ((stream->flags & __SPGM)? PRG_RDB(fmt++): *fmt++))) {
		if (flags & FLHASPERCENT) {
			if (c >= '0' && c <= '9') {
				if (c == '0' && prec == 0 && width == 0) {
					flags |= FLZFILL;
				} else {
					/* digit */
					prec *= 10;
					prec += c - '0';
					if (!(flags & FLPREC) && prec < 128) 
						width = prec;
				}
			} else {
				if ((flags & FLPREC) && prec == 0)
					prec = 1;
				switch (c) {
				case '+':
					flags |= FLSIGNPLUS;
					/* FALLTHROUGH */
				case ' ':
					flags |= FLSIGN;
					break;
				case '-':
					flags |= FLLPAD;
					break;
				case '#':
					flags |= FLALT;
					break;
				case '.':
					flags |= FLPREC;
					flags &= ~FLZFILL;
					prec = 0;
					break;
				case 'l':
					flags |= FLLONG;
					break;
				case 'e':
				case 'f':
				case 'g':
					a.c = '?';
					width--;
					c = 'c';
					goto nextitem;
				case 'c':
					/* char is promoted to int via va_arg */
					a.c = (char)va_arg(ap, int);
					width--;
					goto nextitem;
				case 's':
					a.pc = va_arg(ap, char *);
					for (base = 0; a.pc[base]; base++)
						; /* calc length of string */
					if ((flags & FLPREC) && prec < base)
						base = prec;
					width -= base;
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
					flags &= ~FLALT;
					goto processnum;
				case 'o': /* octal number */
					base = 8;
					goto getulong; 
				case 'x':
				case 'X':
					base = 16;
					/* FALLTHROUGH */
				case 'u':
				  getulong:
					a.ul = flags & FLLONG?
						va_arg(ap, unsigned long):
						va_arg(ap, unsigned int);
					flags &= ~(FLSIGNPLUS | FLSIGN);
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
					if (flags & FLNEGATIVE)
						*pb++ = '-';
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
				  nextitem:
					if (!(flags & FLLPAD))
						while (width-- > 0)
							putc(' ', stream);
					if (c == 'c')
						putc(a.c, stream);
					else if (c == 's')
						while (base--)
							putc(*a.pc++, stream);
					else 
						while (pb != b)
							putc(*--pb, stream);
					if (flags & FLLPAD)
						while (width-- > 0)
							putc(' ', stream);
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
				prec = width = 0;
				base = 10;
			} else
				putc(c, stream);
	}

	return stream->len;
}
