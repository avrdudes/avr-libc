/*  
    Copyright (C) 1998, 1999 by Denis Chertykov (denisc@overta.ru)

    You can redistribute it and/or modify
    it under the terms of the GNU General Public License as published by
    the Free Software Foundation; either version 2, or (at your option)
    any later version.

   This function send one byte to PC parallel port.
  Connect AVR with parallel port
        AVR                       Parallel Port
   Signal name   Pin             Pin  Signal name
   GND           20 ------------ 19   GND
   GND           20 ------------ 21   GND
   SCK            8 ------------  1   Strobe
   MOSI           6 ------------ 12   Out of paper
   MISO           7 ------------ 11   Busy
   Reset          9 ------------ 16   Init
   Connect parallel port pin 12 with parallel port pin 2 through diod
                                 Out of paper 12 ----|>|--- 2 Data 0
  This connection allow to use send_byte and program AVR flash 
  with Uros Platise `uisp' in dummy mode.

  Bugs: For me this work only if Parellel port in EPP mode.
        May be ECP mode also work ?
        
*/


/* #arch AT90S8515 */

#define PORTB   $18
#define DDRB    $17
#define PINB    $16

	seg removable flash.code.send_byte
public _send_byte:
	mov	r24,r25
	ldi	r25,0x55
	rcall	send_byte1
	mov	r25,r24

send_byte1:
	ldi	r19,8
send_bloop:
	mov	r21,r25
	andi	r21,1
	ldi	r21,0x20+0x40
	breq	send_bz
	ldi	r21,0x20
send_bz:
	in	r20,PORTB
	or	r20,r21
	out	PORTB,r20

send_bwait_z:
	in	r18, PINB
	andi	r18, 0x80
	breq	send_bwait_z

	andi	r20,0x9f
	out	PORTB,r20

nnm:	in	r18, PINB
	andi	r18, 0x80
	brne	nnm

	asr	r25
	dec	r19
	brne	send_bloop
	ret
