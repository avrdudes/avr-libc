/*
  $ CFLAGS_EXTRA="-include high-progmemx.h" ./run-avrtest.sh ...

  will force .progmemx to a high address.
*/

#ifdef __AVR_HAVE_ELPM__

__asm (".pushsection .hightext,\"a\",@progbits\n"
       ".space 0xff00\n"
       ".popsection");

#endif
