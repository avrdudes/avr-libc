/* $Id$ */
#ifndef __DOXYGEN__

#include <avr/io.h>

#if E2END && __AVR_XMEGA__ && defined(E2PAGESIZE) && (E2PAGESIZE)

#include <assert.h>
#include "sectionname.h"
#include <avr/eeprom.h>

#if defined (NVM)

#define NVMADDRL NVM_ADDR0
#define NVMADDRH NVM_ADDR1

#define NVMBUSY_WAIT()                                          \
  do {                                                          \
    while ((NVM.STATUS & NVM_NVMBUSY_bm) == NVM_NVMBUSY_bm)     \
      {}                                                        \
  } while (0)

#define NVM_WRITE_CMD(command)                  \
  do {                                          \
    NVM.CMD = command;                          \
    _PROTECTED_WRITE (NVM.CTRLA, NVM_CMDEX_bm); \
  } while (0)

#define NVM_PAGEERASEWRITE_CMD \
  NVM_CMD_ERASE_WRITE_EEPROM_PAGE_gc

#elif defined (NVMCTRL)

/* Handle XTINY devices from avrxmega3.  */

#define NVMADDRL NVMCTRL_ADDRL
#define NVMADDRH NVMCTRL_ADDRH

#define NVMBUSY_WAIT()                                                  \
  do {                                                                  \
    while ((NVMCTRL.STATUS & NVMCTRL_EEBUSY_bm) == NVMCTRL_EEBUSY_bm)   \
      {}                                                                \
  } while (0)

#define NVM_WRITE_CMD(command)                                  \
  do {                                                          \
    _PROTECTED_WRITE_SPM (NVMCTRL.CTRLA, ((uint8_t) command));  \
  } while (0)                                                   \

#define NVM_PAGEERASEWRITE_CMD \
  NVMCTRL_CMD_PAGEERASEWRITE_gc

#endif /* NVM{CTRL} */

extern void ccp_write_io (volatile uint8_t *__ioaddr, uint8_t __value);

ATTRIBUTE_CLIB_SECTION
static void
eeprom_write_page (const uint8_t *sram, uint16_t eeprom_addr, uint8_t nbytes)
{
  assert (eeprom_addr <= (uint16_t)(E2END - nbytes));

  /* Wait till nvm is ready.  */
  NVMBUSY_WAIT();

  for (uint8_t data_index = 0; data_index < nbytes; data_index++)
  {
    NVMBUSY_WAIT();

    /* Load byte into page buffer.  */
    *((uint8_t*)MAPPED_EEPROM_START + eeprom_addr + data_index) = sram[data_index];
  }

  #if defined (NVM) && !defined (NVMCTRL) /* except for tinyXA/B/C devices */
    /*
	FIXME: Load eeprom address. (all other xmega including xmegaE)
	As eeprom is memory mapped, loading address to ADDR register is not
	required. But xmega128A1 doesn't work if not loaded, it overwrites same
	page.
	e.g. eeprom_write_block (data, 26, 40);  */
    #if defined (NVM_ADDR2)
      NVM.ADDR2 = 0;
    #endif
    NVMADDRH = ((eeprom_addr >> 8) & 0xff);
    NVMADDRL = ((eeprom_addr & 0xff));
  #endif

  /* Issue EEPROM erase and write command.  */
  NVM_WRITE_CMD (NVM_PAGEERASEWRITE_CMD);
}


ATTRIBUTE_CLIB_SECTION
void eeprom_write_block (const void *sram, void *eeprom_addr, size_t length)
{
  #if defined (NVM_EEMAPEN_bm)
    /* enable memory map.  */
    NVM_CTRLB = NVM_CTRLB | NVM_EEMAPEN_bm;
  #endif

  while (length)
  {
    uint8_t byte_position = ((uint16_t)eeprom_addr & (E2PAGESIZE-1));
    uint8_t nbytes = E2PAGESIZE - byte_position;
    nbytes = nbytes > length ? length : nbytes;
    eeprom_write_page ((uint8_t*)sram, (uint16_t)eeprom_addr, nbytes);
    sram = (uint8_t*)sram + nbytes;
    eeprom_addr = (uint8_t*)eeprom_addr + nbytes;
    length -= nbytes;
  }

  #if defined (NVM_EEMAPEN_bm)
    /* disable memory map.  */
    NVM_CTRLB = NVM_CTRLB & ~NVM_EEMAPEN_bm;
  #endif
}

#endif  /* E2END && __AVR_XMEGA__ && E2PAGESIZE */
#endif  /* !__DOXYGEN__ */

