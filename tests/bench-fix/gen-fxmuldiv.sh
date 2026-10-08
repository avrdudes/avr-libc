#!/bin/bash

# Recognized variables:
#
# CC=[avr-gcc]		Used to compile muldiv.c.
# TIMES=[1]             Multiplicator for N_VALS from the input files.
# builddir=             Use AVR-LibC from builddir instead of CC's.
#
# ./gen-fxmuldiv.sh A B ... will read files $BASE-A.txt $BASE-B.txt etc.
# and user their input to generate the output file.

out=out.dox
elf=x.elf
# BASE default
base=mudi

. ./common.sh

fun_line ()
{
    echo "== Line: $*"
    suff=$1
    qform=$2
    typ=$(echo $3 | tr '-' ' ')
    def="-DFX=$suff -DMUL=$MUL -DDIV=$DIV -DTIMES=$TIMES"

    echo "$BASE: $suff def=$def"

    copt="-mmcu=$MCU -Os -std=gnu99 -Wall -Werror -mrelax"

    # Get cyc_avr, cyc_max, d_max.
    aopt="-I$AVRTEST_HOME"
    exit_o="$AVRTEST_HOME/exit-$MCU.o"
    $CC muldiv.c -fmax-errors=1 -o $elf $copt $def $aopt $exit_o $CRT $LIBS \
	|| exit 1
    avr-objdump -d $elf > $lst
    aout=$($avrtest $elf)
    #echo "aout=$aout"

    getval cyc_avr "$aout"
    getval cyc_max "$aout"
    getval d_max "$aout"

    # Get size
    sopt="-nostartfiles"
    lopt="-Wl,--defsym,main=0"

    $CC muldiv.c -DSIZE_ONLY -o y$elf $aopt $def $copt $sopt $d1 $lopt $LIBS \
	|| exit 3
    avr-objdump -d y$elf > y$lst
    size=$(avr-size y$elf | grep y$elf | awk '{ print $1 }')
    echo "size: $size; cyc: ($cyc_avr) $cyc_max; d_max: $d_max"

    echo -n "  <tr><td align='right'><code>$typ</code>" >> $out
    echo -n " <td align='right'>$qform"     >> $out
    echo -n " <td align='right'>\\c $suff"  >> $out
    echo -n " <td align='right'>$size"    >> $out
    echo -n " <td align='right'>$cyc_avr" >> $out
    echo -n " <td align='right'>$cyc_max" >> $out
    # Add 0.5 to the ULP value.
    echo    " <td>${d_max}.5" >> $out
}

echo "CC=$CC"
echo "BASE=$BASE"
echo "out=$out"
echo "elf=$elf"
echo "avrtest=$avrtest"

#set -x

main $*

rm -f -- *.lst *.elf
