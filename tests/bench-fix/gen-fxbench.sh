#!/bin/bash

# Recognized variables:
#
# CC=[avr-gcc]		Used to compile bench.c.
# JOBS=[1]              Number of parallel Jobs for make.
# TIMES=[1]             Multiplicator for N_VALS from the input files.
# builddir=             Use AVR-LibC from builddir instead of CC's.
#
# ./gen-fxbench.sh A B ... will read files $BASE-A.txt $BASE-B.txt etc.
# and user their input to generate the output file.

out=out.dox
elf=x.elf
# BASE default
base=fxlib

. ./common.sh

fun_line ()
{
    echo "== Line: $*"
    fun=$1
    suff=$2
    rett=$3
    lo="$4"
    hi="$5"
    suf2=""
    [[ "$suff" =~ .*_.* ]] && suf2=_$(cut -d_ -f2 <<< "$suff")
    [[ "$suff" =~ .*_.* ]] && suff=$(cut -d_ -f1 <<< "$suff")
    signed=1 && [[ "$suff" =~ u.* ]] && signed=0
    def="-DFunc=$1 -DSuffix=$suff -DTIMES=$TIMES -DSIGNED=$signed -DRET=$rett -DSuf2=$suf2"

    echo "Func: $fun$suff $lo ... $hi def=$def"

    copt="-mmcu=$MCU -Os -std=gnu99 -Wall -Werror"

    # Get cyc_avr, cyc_max, d_max.
    aopt="-I$AVRTEST_HOME"
    exit_o="$AVRTEST_HOME/exit-$MCU.o"
    $CC bench.c -fmax-errors=1 -o $elf $copt $def $aopt $exit_o $CRT $LIBS \
	|| exit 1
    avr-objdump -d $elf > $lst
    aout=$($avrtest $elf -args $lo $hi)
    #echo "aout=$aout"

    getval cyc_avr "$aout"
    getval cyc_max "$aout"
    getval d_max "$aout"

    # Get size
    sym="$fun$suff$suf2"
    [ $sym = sqrthr  ] && sym="__$sym"
    [ $sym = sqrtuhr ] && sym="__$sym"
    sopt="-nostartfiles"
    lopt="-Wl,-u,$sym -Wl,--defsym,main=0"

    echo "" | $CC -xc - -xnone -o y$elf $copt $sopt $d1 $lopt $LIBS \
	|| exit 3
    avr-objdump -d y$elf > y$lst
    size=$(avr-size y$elf | grep y$elf | awk '{ print $1 }')
    echo "size: $size; cyc: ($cyc_avr) $cyc_max; d_max: $d_max"

    echo -n "  <tr><td>\\c #$fun$suff$suf2 <td align='right'>$size" >> $out
    echo -n " <td>$lo <td>$hi" >> $out
    echo -n " <td align='right'>$cyc_avr" >> $out
    echo -n " <td align='right'>$cyc_max" >> $out
    echo    " <td>$d_max" >> $out
}

echo "CC=$CC"
echo "BASE=$BASE"
echo "out=$out"
echo "elf=$elf"
echo "avrtest=$avrtest"

#set -x

main $*

rm -f -- *.lst *.elf
