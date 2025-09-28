#!/usr/bin/env bash

# Copyright (c) 2025  Georg-Johann Lay
# All rights reserved.
#
# Redistribution and use in source and binary forms, with or without
# modification, are permitted provided that the following conditions are met:
#
# * Redistributions of source code must retain the above copyright
#   notice, this list of conditions and the following disclaimer.
# * Redistributions in binary form must reproduce the above copyright
#   notice, this list of conditions and the following disclaimer in
#   the documentation and/or other materials provided with the
#   distribution.
# * Neither the name of the copyright holders nor the names of
#   contributors may be used to endorse or promote products derived
#   from this software without specific prior written permission.
#
# THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS "AS IS"
# AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE
# IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE
# ARE DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT OWNER OR CONTRIBUTORS BE
# LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR
# CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF
# SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS
# INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN
# CONTRACT, STRICT LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE)
# ARISING IN ANY WAY OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE
# POSSIBILITY OF SUCH DAMAGE.

me="$0"

set -e

### Error Handling ###################################################

trap "exit 1" TERM
export TOP_PID=$$

Err ()
{
    echo "$me: error: $*" 1>&2
    kill -s TERM $TOP_PID
}

### Options ##########################################################

: ${AVR_GCC:=avr-gcc}
: ${AVRDIR=../..}

Usage ()
{
    cat <<EOF
Usage: $1 [-a AVRDIR] [-g AVR_GCC] [-hisv] [FILE]...
Options:
  -a AVRDIR   Specify AVR-LibC builddir (default is $AVRDIR)
  -g AVRGCC   Specify avr-gcc program (default is $AVR_GCC)
  -h          Print this help
  -i          Test an installed AVR-LibC
  -s          Stop at any error
  -v          Verbose mode
  -v -v       Very verbose mode
If FILE is not specified, then the full \$test_list is used.
- Set MCUS in order to restrict the tests to only some devices:
  \$ MCUS="atmega16 atmega8* !atmega8*a" $me ...
- Set ARGS in order to set the options for the compiler:
  \$ ARGS="-Og,-O3" $me...
- Set WARN to override diagnostics, which is: -Wall -Werror:
  \$ WARN=" " $me...
EOF
}

OPTS="a:ig:shv"
VERB=0

# First option pass for -h only so that we get the defaults right when
# options like -a are specified.
while getopts $OPTS opt ; do
    case $opt in
	h)	Usage `basename $me`
		exit 0
		;;
    esac
done

# Second option pass: When -h was not specified, do the work.
OPTIND=1
while getopts $OPTS opt ; do
    case $opt in
	a)	AVRDIR="$OPTARG" ;;
	i)	INSTALLED=1 ;;
	g)	AVR_GCC="$OPTARG" ;;
	s)	FLAG_STOP=1 ;;
	h)	Usage $(basename $me) ; exit 0 ;;
	v)	VERB=$(( 1 + $VERB )) ;;
	*)	Err "unknown option(s). Try '-h' for more info."
    esac
done
shift $((OPTIND - 1))

[ $VERB -ge 2 ] && set -x

test_list=${*:-"header/*.c"}

if [ x$INSTALLED = x1 ]; then
    CPPFLAGS="-I${AVRDIR}/include"
else
    CPPFLAGS="-I${AVRDIR}/include -I../../include"
fi
[ $VERB -ge 1 ] && echo "CPPFLAGS=$CPPFLAGS"

### Get MCUs #########################################################

AllMcus ()
{
    local all="supported-mcus.txt"

    if [ -f "${AVRDIR}/$all" ]; then
	cat "${AVRDIR}/$all"
    else
	[ x$INSTALLED = x ] && echo "${AVRDIR}/$all not found, using $all" 1>&2
	cat "./$all"
    fi
}

rex='^[a-z0-9 ]+$'
Filter=../../devtools/filter-mcus.py

if [ -z "${MCUS}" ]; then
    # No MCUS given: Use supported-mcus.txt.
    given_mcus="$(AllMcus)"
elif [[ ${MCUS} =~ $rex ]]; then
    # Plain MCUS with no wildcards: Use MCUS as is.
    given_mcus="${MCUS}"
else
    # MCUS has special chars like * or . or !
    # Use filter.py to filter MCUS.  In order to resolve *'s etc we need
    # a list of available MCUs.
    given_mcus=$(${Filter} "$(AllMcus)" "${MCUS}")
fi

MCUS=

echo "Filtering out MCUs not supported by ${AVR_GCC}..."

Compile ()
{
    LANG=C ${AVR_GCC} $* -o /dev/null > msg.txt 2>&1
    return $?
}

for mcu in ${given_mcus}; do
    if Compile simple.c -mmcu=${mcu}; then
	MCUS="${MCUS} ${mcu}"
    else
	echo "Unsupported: $mcu"
    fi
done

n_mcus=$(wc -w <<< "${MCUS}")
echo "Using ${n_mcus} MCUs:${MCUS}"

### Run the Tests ####################################################

n_files=0
n_fails=0
n_passes=0

# Iterate over sources.
for src in ${test_list}; do
    echo "Compiling ${src}..."
    n_files=$(( 1 + $n_files ))

    # List of default argument(s) when no "ARGS:" is found in the C source.
    args="-O0, -Os"

    # When "ARGS:" is found in the source, then use these as args.
    # The sed gets rid of C comments.  The xargs performs a trim.
    if grep '\bARGS:' "$src" > args.txt; then
	args=$(cat "args.txt" \
		   | sed -e 's:/[\*/]::g' -e 's:\*/::g' \
		   | cut -d ":" -f 2- \
		   | xargs )
    fi
    # FIXME: When cut doesn't find a delimiter, then it prints the
    #        entire string.  Hence append a "," for the cut to come.
    args="${ARGS:-$args},"
    warn=${WARN:--Wall -Werror}

    # Iterate over MCUs.
    for mcu in ${MCUS}; do

	# Iterate over ARGS.
	i=0
	while true; do
	    i=$(( i + 1 ))
	    arg="$(echo ${args} | cut -d "," -f $i | xargs)"
	    [ $VERB -ge 2 ] && echo "arg.$i=$arg"
	    [ "x$arg" = "x" ] && break

	    if Compile "${src}" -mmcu=$mcu "$arg" ${CPPFLAGS} $warn; then
		n_passes=$(( 1 + $n_passes ))
		[ $VERB -ge 1 ] && echo "PASS: $src -mmcu=$mcu $arg"
	    else
		n_fails=$(( 1 + $n_fails ))
		echo "FAIL: $src -mmcu=$mcu $arg"
		[ $VERB -ge 1 ] && cat msg.txt
		[ x$FLAG_STOP = x1 ] && exit 1
	    fi
	done
    done
done


### Finally ##########################################################

echo "Done"
echo "Summary: $n_files files, $n_mcus MCUs, $n_passes PASSes, $n_fails FAILs"

if [ $n_fails -eq 0 ]; then
    echo "Success"
else
    exit 1
fi
