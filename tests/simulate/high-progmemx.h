/*
  Used per "-include high-progmemx.h" by run-avrtest.sh

  Will force .progmemx to a high address.

  This will fail with (very) old versions of Binutils, namely
  when the ld script doesn' have a .hightext section and ld
  places the orphan in such a way that it overlaps .data.
*/

#ifdef __AVR_HAVE_ELPM__

__asm (".pushsection .hightext,\"a\",@progbits\n"
       ".space 0xff00\n"
       ".popsection");

#endif
