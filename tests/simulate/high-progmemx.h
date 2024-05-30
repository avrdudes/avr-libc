/*
  Used per "-include high-progmemx.h" by run-avrtest.sh

  Will force .progmemx to a high address.
*/

#ifdef __AVR_HAVE_ELPM__

__asm (".pushsection .hightext,\"a\",@progbits\n"
       ".space 0xff00\n"
       ".popsection");

#endif
