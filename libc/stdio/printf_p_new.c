// $Id$

/******************************************************************
 *
 * printf_p Copyright (c) 2002 Alexander Popov (sasho@vip.bg)
 *
 * This is a simplified version of printf for AVR-GCC, working with
 * format string in program memory. All the output is through the
 * printf_char function. These features are implemented :
 *		* flags : '-','+','#'	
 *		* width, precision
 *		* length modifier : 'l'
 *		* types : 'c','s','d','u','x','X','o'
 *
 * There is no floating point support. The total size of a number
 * (including zero padding and prefix) is 12 characters. This has 
 * been chosen from the size of maximum unsigned long represented
 * in octal form plus the '0' prefix. It can be extended by
 * increasing the size of b[]. 
 *
 *****************************************************************/

#include <avr/pgmspace.h>
#include <inttypes.h>

#ifdef __STDC__
#include <stdarg.h>
#else
#include <varargs.h>
#endif

extern void printf_char(char c);

void _printf_p (char const *fmt0, ...) {
	va_list ap;
	char const *fmt;
	union {
		char c;
		uint8_t u8;
		long l;
		unsigned long ul;
		char *pc;
	} a;
	char	c; // holds a char from the format string
	int8_t width;
	uint8_t base, prec;
	char b[12]; // contains character representation of the number and its prefix
	char *pb; // used as pointer to an element in b

	uint8_t flags;

#define FLHASPERCENT 0x01
#define FLPREC			0x02
#define FLSIGNCHAR   0x04
#define FLLONG   		0x08
#define FLNEGATIVE   0x10
#define FLALT			0x20
#define FLLPAD			0x40

	va_start(ap, fmt0);
	fmt = fmt0;

	flags=0;

	while ((c=PRG_RDB(fmt++))) {
		if(flags&FLHASPERCENT) {
			if(c>='0' && c<='9') { // digit
				prec*=10;
				prec+=c-'0';
				if(!(flags&FLPREC)) 
					width=prec;
			} else {
				if((flags&FLPREC) && prec==0)
					prec=1;
				switch (c) {
					case '+':
						flags|=FLSIGNCHAR;
						break;
					case '-':
						flags|=FLLPAD;
						break;
					case '#'	:
						flags|=FLALT;
						break;
					case '.':
						flags|=FLPREC;
						prec=0;
						break;
					case 'l':
						flags|=FLLONG;
						break;
					case 'c':
						a.c=(char)va_arg(ap, int); // char is promoted to int via va_arg
						width--;
						goto nextitem;
					case 's':
						a.pc=va_arg(ap, char *);
						for(base=0;a.pc[base];base++); // calc length of string
						if((flags&FLPREC) && prec<base)
							base=prec;
						width-=base;
						goto nextitem;
					case 'd':
						a.l=flags&FLLONG ? va_arg(ap, long) : va_arg(ap, int);
						if(a.l<0) {
							flags|=FLNEGATIVE;
							a.l=-a.l;
						}
						goto processnum;
					case 'o' : // octal number
						base=8;
						goto getulong;	
					case 'x' : case 'X' :
						base=16; // fall through	
					case 'u':
getulong:
						a.ul=flags&FLLONG ? va_arg(ap, unsigned long) : va_arg(ap, unsigned int);
processnum:
						pb=b; 	
						do {
							*pb=a.ul%base;
							*pb=*pb>9 ? *pb+c-'X'+'A'-10 : *pb+'0';
							*pb++;
							a.ul/=base;
						} while(a.ul);
						if(flags&FLPREC) {
							a.u8=(uint8_t)(pb-b);
							while(prec-->a.u8)
								*pb++='0';
						}
						if(flags&FLNEGATIVE)
							*pb++='-';
						else if(flags&FLSIGNCHAR)
							*pb++='+';
						if(flags&FLALT) {
							if(base==16)
								*pb++=c;
							if(base!=10)
								*pb++='0';
						}
						width-=(uint8_t)(pb-b);
nextitem:
						if(!(flags&FLLPAD))
							while(width-->0)
								printf_char(' ');
						if(c=='c')
							printf_char(a.c);
						else if(c=='s')
							while(base--)
								printf_char(*a.pc++);
						else 
							while(pb!=b)
								printf_char(*--pb);
						if(flags&FLLPAD)
							while(width-->0)
								printf_char(' ');
						goto clearflags;

					default :
						printf_char(c);
clearflags:
						flags=0;
						break;
				}
			}
		} else
			if(c=='%') {
				flags=FLHASPERCENT;
				prec=width=0;
				base=10;
			} else
				printf_char(c);
	}
	va_end(ap);
}

