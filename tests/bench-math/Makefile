.PHONY: help clean

help:
	@echo "Determine libm / float function benchmark values."
	@echo "The result is s Doxygen file then can be used as"
	@echo "doc/api/bench-libm.dox.  Sample usage:"
	@echo "$ JOBS=3 CC=avr-gcc-15 builddir=../../../../build/avr-libc TIMES=10 ./gen-bench.sh 2"
	@exit 0

AVRTEST_HOME=$(shell dirname `which avrtest`)

CC=avr-gcc
MCU=atmega128

# Defines CC, MCU, LIBS and AARGS_sinf etc.
-include margs.txt

PRG = bench-$(BASE)

atest := -I$(AVRTEST_HOME) $(AVRTEST_HOME)/exit-$(MCU).o

args  := -std=gnu99 -Os -mmcu=$(MCU) -fmax-errors=1 $(CFLAGS)
args2 = $(shell grep "ID=$*" cargs.txt) -DTIMES=$(TIMES) $(LIBS)

elf = $(PRG)-$*.elf

text-%.out: $(PRG).c cargs.txt
	@echo "== $* =="
	$(CC) $< -o $(elf) $(atest) $(args) $(args2)
	avrtest -q $(elf) -args $(AARGS_$*) | tee $@

clean:
	rm -f $(wildcard *.[iso] *.elf *.out)
