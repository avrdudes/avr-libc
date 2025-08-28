FIG2DEV                 = fig2dev
EXTRA_CLEAN_FILES       = *.hex *.bin *.srec

.PHONY: dox eps png pdf

dox: eps png pdf

eps: $(PRG).eps
png: $(PRG).png
pdf: $(PRG).pdf

%.eps: %.fig
	$(FIG2DEV) -L eps $< $@

%.pdf: %.fig
	$(FIG2DEV) -L pdf $< $@

%.png: %.fig
	$(FIG2DEV) -L png $< $@

# In order to align demo.dox with demo.map, generate a small file
# that contains the .text size.

all: textsize.txt

S = cat demo.map | grep '^\.text *0x' | awk '{ print $$3 }'

textsize.txt: $(PRG).elf
	echo "$(shell $S) = $(shell echo $$((`$S`)))" > $@

EXTRA_CLEAN_FILES += textsize.txt
