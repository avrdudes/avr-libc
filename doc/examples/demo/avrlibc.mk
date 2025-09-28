# In order to align demo.dox with demo.map, generate a small file
# that contains the .text size.

all: textsize.txt vectorssize.txt

AWK = awk

S = cat demo.map | grep '^\.text *0x' | $(AWK) '{ print $$3 }'
V = cat demo.map | grep '^[ \t]*\.vectors *0x0.*' | $(AWK) '{ print $$3 }'

textsize.txt: $(PRG).elf
	echo "$(shell $S) = $(shell echo $$((`$S`)))" > $@

vectorssize.txt: $(PRG).elf
	echo "$(shell $V) = $(shell echo $$((`$V`)))" > $@

EXTRA_CLEAN_FILES += textsize.txt  vectorssize.txt


# Showing the size of the program.  Some extra salt is needed to get
# a nice output (no trailing white lines), and to graceful degrade
# when avr-objdump -P mem-usage doesn't work for whatever reason.
# Therefore, we put the following rule in this file and not in Makefile.

all: $(PRG).size

SED = sed

%.size: %.elf
	$(OBJDUMP) -P mem-usage $< > $@ \
		|| echo "error: $(OBJDUMP) -P mem-usage $< failed" > $@
	$(SED) -i '$${/^$$/d}' $@
	$(SED) -i '$${/^$$/d}' $@
	$(SED) -i '$${/^$$/d}' $@

EXTRA_CLEAN_FILES += $(PRG).size
