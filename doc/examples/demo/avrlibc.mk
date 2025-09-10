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
