/* Bytes receiver for send_byte.s from /usr/local/avr/lib/libc/send_byte.s
   This program receive bytes from the ATMEL AVR chip connected to PC
   parallel port.
   For the connection scheme look to send_byte.s

   Bugs: Hard coded parallel port 0x378. (Can be easy changed)
   
   Copyright (C) 1998, 1999 by Denis Chertykov (denisc@overta.ru)

   You can redistribute it and/or modify
   it under the terms of the GNU General Public License as published by
   the Free Software Foundation; either version 2, or (at your option)
   any later version.
*/



#include <stdio.h>
#include <sys/io.h>
#include <unistd.h>
#include <linux/lp.h>
#include <signal.h>
#include <sys/time.h>


#define RECV_PORT_BASE 0x378

#define RD_PORT (inb (RECV_PORT_BASE+1))
#define SET_CLK (outb (LP_PINITP, RECV_PORT_BASE+2))
#define CLR_CLK (outb (LP_PSTROBE | LP_PINITP, RECV_PORT_BASE+2))
#define RESET_AVR {int k=20000;outb (LP_PSTROBE,RECV_PORT_BASE+2);while(--k) inb(RECV_PORT_BASE+1);outb (LP_PINITP,RECV_PORT_BASE+2);}

int
get_bit ()
{
  int i,n=200;
  
  while (!(RD_PORT & 0x20));
  i = !!(RD_PORT & 0x80);
  SET_CLK;
  CLR_CLK;
  return i;
}

int
get_byte1()
{
  int i=0;
  i = get_bit ();
  i += get_bit () << 1;
  i += get_bit () << 2;
  i += get_bit () << 3;
  i += get_bit () << 4;
  i += get_bit () << 5;
  i += get_bit () << 6;
  i += get_bit () << 7;
  return i;
}

int
get_byte()
{
  int n = get_byte1 ();
  if (n != 0x55)
    {
      fprintf (stderr, "sync error\n");
      while (get_byte1()!=0x55)
	get_bit();
    }
  return get_byte1();
}

int
main(int argc, char **argv)
{
  if (ioperm (RECV_PORT_BASE, 8, 1) == 0)
    {
      RESET_AVR;
      outb (0xff,RECV_PORT_BASE);
      if (!(RD_PORT & 0x20))
	CLR_CLK;
      while (1)
	{
	  if (argc >= 2)
	    printf ("%02x ", get_byte());
	  else
	    putchar (get_byte ());
	  fflush (stdout);
	}
    }
  else
    perror ("ioperm");
  return 0;					
}
