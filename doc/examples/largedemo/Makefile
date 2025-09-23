PRG            = largedemo
OBJ            = largedemo.o
MCU_TARGET     = atmega328p
#MCU_TARGET     = atmega16
#MCU_TARGET     = atmega8
#MCU_TARGET     = atmega48
#MCU_TARGET     = atmega88
#MCU_TARGET     = atmega168
#MCU_TARGET     = attiny2313
OPTIMIZE       = -Os

DEFS           = -DMCU_NAME='"$(MCU_TARGET)"'
LIBS           =

# AVRDUDE configuration
# override that from the environment if needed
ifndef AVRDUDE_PORT
  ifeq ($(OS),Windows_NT)
    AVRDUDE_PORT = COM3
  else
    UNAME_S := $(shell uname -s)
    ifeq ($(UNAME_S),Linux)
        AVRDUDE_PORT = /dev/ttyUSB0
    endif
    ifeq ($(UNAME_S),Darwin)
        AVRDUDE_PORT = /dev/cu.usbserial-10
    endif
    ifeq ($(UNAME_S),FreeBSD)
        AVRDUDE_PORT = /dev/cuaU0
    endif
  endif
endif
ifndef AVRDUDE_PROGRAMMER
  AVRDUDE_PROGRAMMER = arduino
endif
ifndef AVRDUDE_ADDITIONAL
  AVRDUDE_ADDITIONAL = -b 57600 # for Arduino Nano compat device
endif
ifndef AVRDUDE
  AVRDUDE = avrdude # search along $PATH
endif

# You should not have to change anything below here.

CC             = avr-gcc

# Override is only needed by avr-lib build system.

override CFLAGS  = -std=c99 -g -Wall $(OPTIMIZE) -mmcu=$(MCU_TARGET) $(DEFS)
override LDFLAGS = -Wl,-Map,$(PRG).map

OBJCOPY        = avr-objcopy
OBJDUMP        = avr-objdump

.PHONY: all lst text hex bin srec eeprom ehex ebin esrec program

all: $(PRG).elf lst text eeprom

$(PRG).elf: $(OBJ)
	$(CC) $(CFLAGS) $(LDFLAGS) -o $@ $^ $(LIBS)

clean:
	rm -f -- *.o $(PRG).elf *.png *.pdf *.bak
	rm -f -- *.lst *.map $(EXTRA_CLEAN_FILES)

lst:  $(PRG).lst

%.lst: %.elf
	$(OBJDUMP) -h -S $< > $@

# device programming

program: $(PRG).elf
	$(AVRDUDE) -c $(AVRDUDE_PROGRAMMER) \
	  -p $(MCU_TARGET) -P $(AVRDUDE_PORT) \
	  $(AVRDUDE_ADDITIONAL) \
	  -U $(PRG).elf

# Rules for building the .text rom images

text: hex bin srec

hex:  $(PRG).hex
bin:  $(PRG).bin
srec: $(PRG).srec

%.hex: %.elf
	$(OBJCOPY) -j .text -j .data -O ihex $< $@

%.srec: %.elf
	$(OBJCOPY) -j .text -j .data -O srec $< $@

%.bin: %.elf
	$(OBJCOPY) -j .text -j .data -O binary $< $@

# Rules for building the .eeprom rom images

eeprom: ehex ebin esrec

ehex:  $(PRG)_eeprom.hex
ebin:  $(PRG)_eeprom.bin
esrec: $(PRG)_eeprom.srec

%_eeprom.hex: %.elf
	$(OBJCOPY) -j .eeprom --change-section-lma .eeprom=0 -O ihex $< $@

%_eeprom.srec: %.elf
	$(OBJCOPY) -j .eeprom --change-section-lma .eeprom=0 -O srec $< $@

%_eeprom.bin: %.elf
	$(OBJCOPY) -j .eeprom --change-section-lma .eeprom=0 -O binary $< $@

EXTRA_CLEAN_FILES += *.hex *.bin *.srec
