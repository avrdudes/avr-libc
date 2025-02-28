#!/usr/bin/env bash

## Compare a libc just built in $2 with an installed one in $1.
## This can be used to verify that a refactoring is a no-op on the
## binary level.
## The script compares libc.a and libm.a from all the multilib variants
## supported by the $CC compiler.  It also compares the crt<mcu>.o and
## lib<mcu>.a files for all supported MCUs.
##
## Usage:  compare-libc.sh  <libc-install-dir>  <libc-build-dir>  [mcus]

Me=$(basename "$0")

Errx ()
{
    echo "$Me: Error: $*" 1>&2
    echo "Usage: $Me <libc-install-dir> <libc-build-dir>" 1>&2
    exit 1
}

# Installation directory (what you specified with --prefix).
INST="$1"
shift

# $builddir of AVR-LibC
LIBC="$1"
shift

if [ ! -d "${INST}" ]; then
    Errx "\$1 is not a directory: ${INST}"
    exit 1
fi

if [ ! -d "${INST}/avr/lib/ldscripts" ]; then
    Errx "\$1 does not look like an avr-gcc install dir: ${INST}"
    exit 1
fi

CC=${CC-"${INST}/bin/avr-gcc"}

if [ ! -d "${LIBC}" ]; then
    Errx "\$2 is not a directory: ${LIBC}"
    exit 1
fi

if [ ! -d "${LIBC}/avr/devices" ]; then
    Errx "\$2 does not look like an AVR-LibC build dir: ${LIBC}"
    exit 1
fi

Filter ()
{
    # grep: Filter out the (differing) file names.
    # sed: Different includes lead to different local \@ in .macro.
    # sed -r: GNU sed use regexp like [0-9]+
    grep -v 'avr/' \
	| sed -r -e 's:\.Lnoinc\.[0-9]++:.Lnoinc.XX+:g'
}

do_cmp_mcu ()
{
    mcu=$1
    L=$($CC -mmcu=${mcu} --print-multi-directory) || exit 1
    # Same replacements as performed by mlib-gen.py::to_ident():
    # avr5/long-double32  ->  avr5_long_double32
    ID=$(echo "$L" | sed -e 's:^\.$:avr2:' -e 's:/:_:g' -e 's:-:_:g')

    L1=$INST/avr/lib/$L
    L2=$LIBC/avr/lib/$ID
    D2=$LIBC/avr/devices/${mcu}

    (avr-objdump -dr $L1/crt${mcu}.o | Filter > x0.lst) || exit 1
    (avr-objdump -dr $D2/crt${mcu}.o | Filter > x1.lst) || exit 1
    diff x0.lst x1.lst

    (avr-objdump -dr $L1/lib${mcu}.a | Filter > x0.lst) || exit 1
    (avr-objdump -dr $D2/lib${mcu}.a | Filter > x1.lst) || exit 1
    diff x0.lst x1.lst
}

do_cmp_lib ()
{
    L=$($CC $* --print-multi-directory) || exit 1
    # Same replacements as performed by mlib-gen.py::to_ident().
    ID=$(echo "$L" | sed -e 's:^\.$:avr2:' -e 's:/:_:g' -e 's:-:_:g')

    L1=$INST/avr/lib/$L
    L2=$LIBC/avr/lib/$ID

    pat=john
    # Different includes lead to different local \@ in .macro.
    # -r: GNU sed use regexp like [0-9]+
    prune="sed -r -e s:\.Lnoinc\.[0-9]++:.Lnoinc.XX+:g"

    (avr-objdump -dr $L1/libc.a | Filter > x0.lst) || exit 1
    (avr-objdump -dr $L2/libc.a | Filter > x1.lst) || exit 1
    diff x0.lst x1.lst || exit 1

    (avr-objdump -dr $L1/libm.a | Filter > x0.lst) || exit 1
    (avr-objdump -dr $L2/libm.a | Filter > x1.lst) || exit 1
    diff x0.lst x1.lst || exit 1
}

############################################################
# Diff all multilib variants of libc.a and libm.a
# pml is lines like
#    avr4/double64;@mmcu=avr4@mdouble=64
# Extract avr-gcc options for the multilib variant from that.
for pml in $($CC --print-multi-lib); do
    # Get the part after the ";".
    atopt=$(cut -s -d ';' -f 2 <<< "${pml}")
    if [ -z $atopt ]; then
       atopt="@mmcu=avr2"
    fi

    # Transform that into proper avr-gcc options.
    opt=$(sed -e 's:@: -:g' <<< "${atopt}")
    echo $opt
    do_cmp_lib "$opt"
done

############################################################
# Diff all crt<mcu>.o and lib<mcu>.a  for all <mcu>s.
# When no MCUs are specified on the command line, take the
# ones from supported-mcus.txt.

supported_mcus=$(cat "${LIBC}/supported-mcus.txt")

for m in ${*-${supported_mcus}}; do
    echo $m
    do_cmp_mcu $m
done
