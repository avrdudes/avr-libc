/* $Id$ */
#ifndef __DOXYGEN__

#include <avr/io.h>

#if E2END && __AVR_XMEGA__ && defined(E2PAGESIZE) && (E2PAGESIZE)

#include <assert.h>
#include "sectionname.h"
#include <avr/eeprom.h>

extern void ccp_write_io (volatile uint8_t *__ioaddr, uint8_t __value);

ATTRIBUTE_CLIB_SECTION
static void
eeprom_write_page (const uint8_t *sram, uint16_t eeprom_addr,
					uint8_t byte_position, uint8_t nbytes)
{
  assert (eeprom_addr <= (uint16_t)(E2END - nbytes));

  uint8_t i = byte_position;
  uint8_t data_index = 0;

  /* Wait till nvm is ready.  */
  do {
  } while ((NVM.STATUS & NVM_NVMBUSY_bm) == NVM_NVMBUSY_bm);

  while (data_index < nbytes)
  {
    do {
    } while ((NVM.STATUS & NVM_NVMBUSY_bm) == NVM_NVMBUSY_bm);


    #if defined (NVM_EEMAPEN_bm)
    /* enable memory map.  */
    NVM_CTRLB = NVM_CTRLB | NVM_EEMAPEN_bm;
    #endif

    /* Load byte into page buffer.  */
    *((uint8_t*)MAPPED_EEPROM_START + i) = sram[data_index];

    data_index++;
    i++;

    #if defined (NVM_EEMAPEN_bm)
    /* disable memory map.  */
    NVM_CTRLB = NVM_CTRLB & ~NVM_EEMAPEN_bm;
    #endif
  }

  /* Load eeprom address.  */
  #if defined (NVM_ADDR2)
    NVM.ADDR2 = 0;
  #endif
  NVM.ADDR1 = ((eeprom_addr >> 8) & 0xff);
  NVM.ADDR0 = ((eeprom_addr & 0xff));
  /* Issue EEPROM erase and write command.  */
  NVM.CMD = NVM_CMD_ERASE_WRITE_EEPROM_PAGE_gc;
  ccp_write_io (&NVM.CTRLA, NVM_CMDEX_bm);
}

/* void eeprom_write_block (const void *sram, void *eeprom_addr, size_t length)
 */
ATTRIBUTE_CLIB_SECTION
void eeprom_write_block (const void *sram, void *eeprom_addr, size_t length)
{
  while (length)
  {
    uint8_t byte_position = ((uint16_t)eeprom_addr & (E2PAGESIZE-1));
    uint8_t nbytes = E2PAGESIZE - byte_position;
    nbytes = nbytes > length ? length : nbytes;
    eeprom_write_page ((uint8_t*)sram, (uint16_t)eeprom_addr,
                       byte_position, nbytes);
    sram = (uint8_t*)sram + nbytes;
    eeprom_addr = (uint8_t*)eeprom_addr + nbytes;
    length -= nbytes;
  }
}

#endif  /* E2END && __AVR_XMEGA__ && E2PAGESIZE */
#endif  /* !__DOXYGEN__ */

