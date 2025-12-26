PRG            = demo
OBJ            = demo.o

MCU_TARGET     = atmega328p

OPTIMIZE = -Os

WARN = -Wall -Wextra -Werror=missing-prototypes -Werror=strict-prototypes

DEFS =
LIBS =

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

CC      = avr-gcc

CFLAGS  = -g $(WARN) $(OPTIMIZE) -mmcu=$(MCU_TARGET) $(DEFS)
LDFLAGS = -Wl,-Map,$(PRG).map -mrelax

OBJCOPY = avr-objcopy
OBJDUMP = avr-objdump

all: $(PRG).elf lst text eeprom

$(PRG).elf: $(OBJ)
	$(CC) $(CFLAGS) $(LDFLAGS) -o $@ $^ $(LIBS)

# dependency:
demo.o: demo.c

clean:
	rm -f -- *.o $(PRG).elf
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

.PHONY: all clean lst program

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

.PHONY: text hex bin srec

# Rules for building the .eeprom rom images

eeprom: ehex ebin esrec

ehex:  $(PRG)_eeprom.hex
ebin:  $(PRG)_eeprom.bin
esrec: $(PRG)_eeprom.srec

%_eeprom.hex: %.elf
	$(OBJCOPY) -j .eeprom --change-section-lma .eeprom=0 -O ihex $< $@ \
	|| { echo empty $@ not generated; exit 0; }

%_eeprom.srec: %.elf
	$(OBJCOPY) -j .eeprom --change-section-lma .eeprom=0 -O srec $< $@ \
	|| { echo empty $@ not generated; exit 0; }

%_eeprom.bin: %.elf
	$(OBJCOPY) -j .eeprom --change-section-lma .eeprom=0 -O binary $< $@ \
	|| { echo empty $@ not generated; exit 0; }

EXTRA_CLEAN_FILES += *.hex *.bin *.srec

.PHONY: eeprom ehex ebin esrec
# The line above is used as an \until marker in demo.dox.

# Everything below here is used by AVR-LibC's build system and can be ignored
# by the casual user.

-include avrlibc.mk
