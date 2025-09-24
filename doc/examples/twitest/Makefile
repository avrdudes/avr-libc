CC= avr-gcc
#MCU=atmega8
#MCU=atmega16
#MCU=atmega32
#MCU=atmega163
#MCU=atmega323
MCU=atmega128

CFLAGS = -mmcu=$(MCU) -std=c99 -Os -Wall -Wextra

.SUFFIXES: .s .bin .elf .hex .srec

.c.s:
	$(CC) $(CFLAGS) -S $<

.S.o:
	$(CC) $(ASFLAGS) -c $<

.o.elf:
	$(CC) $(CFLAGS) -o $@ $<

.elf.bin:
	avr-objcopy -O binary $< $@

.elf.hex:
	avr-objcopy -O ihex $< $@

.elf.srec:
	avr-objcopy -O srec $< $@

all:	twitest.bin

OBJS=twitest.o
twitest.elf: $(OBJS)
	$(CC) -o twitest.elf $(CFLAGS) $(LDFLAGS) $(OBJS) $(LIBS)

clean:
	rm -f *~ *.elf *.bin *.hex *.srec *.s *.o *.pdf *core
