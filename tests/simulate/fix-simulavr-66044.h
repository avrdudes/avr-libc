/* Work around issue #954, which is due to a bug 66044 in SimulAVR.
   Clear XL by hand prior to calling the very EEPROM read func. */
#ifdef __AVR_ATtiny2313__
__asm (".pushsection .text\n"
       ".global __wrap_eeprom_read_block\n"
       ".global __wrap_eeprom_read_blraw\n"
       "__wrap_eeprom_read_block: clr r27 $ rjmp __real_eeprom_read_block\n"
       "__wrap_eeprom_read_blraw: clr r27 $ rjmp __real_eeprom_read_blraw\n"
       ".popsection\n");
#endif
