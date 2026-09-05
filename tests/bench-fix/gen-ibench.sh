#!/bin/bash

# Recognized variables:
#
# CC=[avr-gcc]		Used to compile int.c.
# TIMES=[1]             How often to repeat for the same operation.
# builddir=             Use AVR-LibC from builddir instead of CC's.
#
# ./gen-ibench.sh A B ... will read files $BASE-A.txt $BASE-B.txt etc.
# and user their input to generate the output file.

out=out.dox
elf=x.elf
# BASE default
base=intop

. ./common.sh

fun_line ()
{
    echo "== Line: $*"
    ta=$1
    tb=$2
    tc=$3
    txt=$(echo $4 | tr '-' ' ')
    def="-DTA=$ta -DTB=$tb -DTC=$tc"
    def="$def -DMUL=$MUL -DEXT=$EXT -DDIV=$DIV -DTIMES=$TIMES"

    echo "$BASE: def=$def"

    copt="-mmcu=$MCU -Os -std=gnu99 -fwrapv -Wall -Werror -mrelax"

    # Get cyc_avr, cyc_max.
    aopt="-I$AVRTEST_HOME"
    exit_o="$AVRTEST_HOME/exit-$MCU.o"
    $CC int.c -fmax-errors=1 -o $elf $copt $def $aopt $exit_o $CRT $LIBS \
	|| exit 1
    avr-objdump -d $elf > $lst
    aout=$($avrtest $elf)
    #echo "aout=$aout"

    getval cyc_avr "$aout"
    getval cyc_max "$aout"

    # Get size
    sopt="-nostartfiles"
    lopt="-Wl,--defsym,main=0"

    $CC int.c -DSIZE_ONLY -o y$elf $aopt $def $copt $sopt $d1 $lopt $LIBS \
	|| exit 3
    avr-objdump -d y$elf > y$lst
    size=$(avr-size y$elf | grep y$elf | awk '{ print $1 }')
    echo "size: $size; cyc: ($cyc_avr) $cyc_max"

    echo -n "  <tr><td align='center'>$txt" >> $out
    echo -n " <td align='right'>$size"    >> $out
    echo -n " <td align='right'>$cyc_avr" >> $out
    echo    " <td align='right'>$cyc_max" >> $out
}

echo "CC=$CC"
echo "BASE=$BASE"
echo "out=$out"
echo "elf=$elf"
echo "avrtest=$avrtest"

#set -x

main $*

rm -f -- *.lst *.elf
