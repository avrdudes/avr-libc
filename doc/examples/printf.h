#ifndef _PRINTF_H_
#define _PRINTF_H_

#include <progmem.h>
#include <io.h>

int printf (const char *fmt, ...);
int sprintf (char *buf, const char *fmt, ...);

extern void inline
init_send_byte ()
{
  outp (0x7f,DDRB);
}

/* call init_send_byte () first */
extern void send_byte (char);

extern inline void
send_str (char *s)
{
  while (*s)
    send_byte (*s++);
}

extern inline void
send_prgstr(prog_char * s)
{
  while (PRG_RDB (s))
    send_byte (PRG_RDB (s++));
}

#endif /* _PRINTF_H_ */
