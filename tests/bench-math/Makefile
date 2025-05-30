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
args2 = $(shell grep "ID=$*" cargs.txt) -DTIMES=$(TIMES) $(CRT) $(LIBS)

p=-Wl,--defsym,
nosym = $(patsubst %, $(p)%=0, main errno __prologue_saves__ __epilogue_restores__)

elf = $(PRG)-$*.elf
self = $(PRG)-size-$*.elf
size = size-$*.out

text-%.out: $(PRG).c cargs.txt
	@echo "== $* =="
	echo | $(CC) -xc - -xnone -o $(self) $(args) -Wl,-u,$(SYMBL_$*) $(nosym) $(LIBS)
	avr-size $(self) | grep $(self) | awk '{ print "#define SIZE " $$1 }' \
		> $(size)
	$(CC) $< -o $(elf) $(atest) $(args) $(args2) -include $(size)
	avrtest -q $(elf) -args $(AARGS_$*) | tee $@

clean:
	rm -f -- $(wildcard *.[iso] *.elf *.out)
