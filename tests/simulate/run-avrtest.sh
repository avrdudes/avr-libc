#! /bin/bash

# Copyright (c) 2007, Dmitry Xmelkov
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

# Script for testing AVR-LibC functions, mainly, by simulating.
# AVRtest is needed. The script is tuned to run after 'make'
# without any options, at this place.  Use
#
#     MCUS="..." ./run-avrtest.sh ...
#
# in order to override the predefined list of MCUs.
# Notice that this requires an  exit-<mcu>.o module  for each of the MCUs.
# When it is not present, you can generate it with, say
#
#    (cd $AVRTEST_HOME; make exit-<mcu>.o)
#
# Use
#
#     EXTRA_CFLAGS="..." ./run-avrtest.sh ...
#
# in order to add additional CFLAGS.
# In order to replace the CFLAGS below entirely, use
#
#     CFLAGS="..." ./run-avrtest.sh ...
# Use
#
#     EXTRA_AFLAGS="..." ./run-avrtest.sh ...
#
# in order to pass additional flags to AVRtest.


##########################################################################
# This script is similar to runtest.sh but uses AVRtest for simulation.
#
#     https://github.com/sprintersb/atest
#
# There are ups and downs of using AVRtest instead of SimulAVR:
#
# + AVRtest is order of magnitude(s) faster than SimulAVR.
#
# + AVRtest can simulate for much more devices than SimulAVR supports.
#   But this comes at a cost:  AVRtest only simulates the core, no I/O and
#   no SFRs or interrupts.  But it can simulate code for
#   ATmega103, ATtiny3216, ATmega128, ATtiny40, ATtiny3216, AVR128DA32, ...
#
# - No SFRs are supported, i.e. simulation fails or hangs for:
#   EEPROM, SFRs, ISRs, ...
#
# + As no real hardware is simulated, we can supply more RAM than the device
#   actually has, same for the size of program memory (in the bounds imposed
#   by the core arch).  For example we pretend ATtiny40 has a program size
#   of 8 KiB.

# When you want to skip a test with AVRtest for whatever reason, add a
# magic comment like
#
#     /* SKIP_AVRTEST: "This is the reason" */

# When you want to run part of a code only with AVRtest, e.g. because
# SimulAVR is slow, then wrap the code in
#
#     #ifdef USE_AVRTEST

set -e

myname="$0"

: ${AVR_GCC:=avr-gcc}
: ${AVR_NM:=avr-nm}
: ${AVR_OBJCOPY:=avr-objcopy}
: ${avrtest:=avrtest}

if [ -z $AVRTEST_HOME ] ; then
    # AVRTEST_HOME is not set, try which
    ahome=$(which $avrtest)
    if [ $? -eq 0 ] ; then
	AVRTEST_HOME=$(dirname $ahome)
    fi
fi

if [ -z $AVRTEST_HOME ] ; then
    echo "avrtest simulator not found, set AVRTEST_HOME"
    exit 1
else
    echo "Using $avrtest from: ${AVRTEST_HOME}"
fi


: ${AVRDIR=../..}
: ${MCU_LIST="atmega128 attiny3216"}
: ${MCU_LIST_FULL="atmega128 attiny3216 atmega2560 atxmega128a3" }

HOST_PASS=			# Add pass at host computer
HOST_ONLY=			# Pass at host only, skip AVR mode
MAKE_ONLY=			# Compile/link only
FLAG_STOP=			# Stop at any error

Errx ()
{
    echo "$myname: $*"
    exit 1
}

Usage ()
{
    cat <<EOF
Usage: $1 [-a AVRDIR] [-g AVR_GCC] [-ictTsh] [FILE]...
Options:
  -a AVRDIR   Specify AVR-LibC builddir (default is $AVRDIR)
  -i          Test an installed AVR-LibC
  -c          Compile/link only
  -g AVRGCC   Specify avr-gcc program (default is $AVR_GCC)
  -t          Add pass at host computer
  -T          Pass at host only
  -s          Stop at any error, temporary files will save
  -h          Print this help
  -v          Verbose mode; echo shell commands being executed
If FILE is not specified, the full test list is used.
EOF
}

OPTS="a:icg:tTshv"

# First option pass for -h only so that we get the defaults right when
# options like -a are specified.
while getopts $OPTS opt ; do
    case $opt in
	h)	Usage `basename $myname` ; exit 0 ;;
    esac
done

# Second option pass: When -h was not specified, do the work.
OPTIND=1
while getopts $OPTS opt ; do
    case $opt in
	a)	AVRDIR="$OPTARG" ;;
	i)	AVRDIR= ;;
	c)	MAKE_ONLY=1 ;;
	g)	AVR_GCC="$OPTARG" ;;
	t)	HOST_PASS=1 ;;
	T)	HOST_ONLY=1 ; HOST_PASS=1 ;;
	s)	FLAG_STOP=1 ;;
	h)	Usage `basename $myname` ; exit 0 ;;
	v)	set -x ;;
	*)	Errx "Invalid option(s). Try '-h' for more info."
    esac
done
shift $((OPTIND - 1))
test_list=${*:-"time/*.c regression/*.c stdlib/*.c string/*.c pmstring/*.c \
		stdfix/*.c \
		printf/*.c scanf/*.c fplib/*.c math/*.c other/*.c \
		util/*.c"}

CPPFLAGS="-Wundef -I."
# -Wno-array-bounds: Ditch wrong warnings due to avr-gcc PR105523.
# This works with more GCC versions than --param=min-pagesize=0.
CFLAGS=${CFLAGS-"-gdwarf-4 -W -Wall -pipe -Os -Wno-array-bounds ${EXTRA_CFLAGS}"}
HOST_CC=gcc
HOST_CFLAGS="-m32 -W -Wall -std=gnu99 -pipe -O2 -I."

Err_echo ()
{
    echo "*** $*"
    if [ $FLAG_STOP ] ; then
	Errx "Stop"
    fi
}

# Usage: Host_exe EXEFILE
Host_exe ()
{
    $1
    RETVAL=$?
    [ $RETVAL -eq 0 ]
}

# Compose extra avr-gcc options for extended memory layout.
# $1 = 0: Stack is below static storage
# $1 = 1: Stack is at the end of static storage
# $2 = RAM start
# $3 = RAM end
o_mem ()
{
    local ramVMA=0x800000
    local ramSTART=$(printf "0x%x" $(($2 + ${ramVMA})))
    local ramEND=$(printf "0x%x" $(($3 + ${ramVMA})))
    local ramLEN=$(printf "0x%x" $((1 + $3 - $2)))
    local stack
    if [ $1 -eq 0 ] ; then
	# Stack is located below static storage.
	stack=$(printf "0x%x" $((${ramSTART} - 1 - ${ramVMA})))
    else
	# Stack is located at the end of static storage.
	stack=$(printf "0x%x" $((${ramEND} - ${ramVMA})))
    fi

    local ramstart="-Tdata=${ramSTART} \
		    -Wl,--defsym,__DATA_REGION_ORIGIN__=${ramSTART}"
    local ramlen="-Wl,--defsym,__DATA_REGION_LENGTH__=${ramLEN}"
    local stack="-Wl,--defsym,__stack=${stack}"
    local heap="-Wl,--defsym,__heap_end=${ramEND}"

    echo "${ramstart} ${ramlen} ${stack} ${heap}"
}

# $1 = MCU as understood by avr-gcc.
# o_gcc: Extra options for avr-gcc
# o_sim: Extra options for avrtext
set_extra_options ()
{
    # As AVRtest is just simulating cores, not exact hardware, we can
    # add more RAM at will.

    o_gcc= # Extra options for gcc
    o_sim= # Extra options for AVRtest.  Default mmcu=avr51
    # To test the pgm_read_far functions.
    local o_pgmx="-include high-progmemx.h"
    case $1 in
	atmega8)
	    o_sim="-mmcu=avr4"
	    o_gcc="$(o_mem 0 0x2000 0xffff)"
	    ;;
	atmega128 | atmega103)
	    o_gcc="$(o_mem 0 0x2000 0xffff) $o_pgmx"
	    ;;
	atmega2560)
	    o_sim="-mmcu=avr6"
	    o_gcc="$(o_mem 0 0x2000 0xffff) $o_pgmx"
	    ;;
	attiny3216)
	    o_sim="-mmcu=avrxmega3"
	    o_gcc="$(o_mem 0 0x2000 0x7fff)"
	    ;;
	atxmega128a3)
	    o_sim="-mmcu=avrxmega6"
	    o_gcc="$(o_mem 0 0x2000 0xffff) $o_pgmx"
	    ;;
	atxmega128a1)
	    o_sim="-mmcu=avrxmega7"
	    o_gcc="$(o_mem 0 0x2000 0xffff) $o_pgmx"
	    ;;
	avr128da32)
	    o_sim="-mmcu=avrxmega4"
	    o_gcc="$(o_mem 0 0x1000 0x7fff) $o_pgmx"
	    ;;
	at90s8515)
	    o_sim="-mmcu=avr2"
	    o_gcc="$(o_mem 0 0x2000 0xffff)"
	    ;;
	attiny40)
	    o_sim="-mmcu=avrtiny -s 8k"
	    o_gcc="$(o_mem 1 0x40 0x3fff) \
		   -Wl,--pmem-wrap-around=8k \
		   -Wl,--defsym=__TEXT_REGION_LENGTH__=8K"
	    ;;
	*)
	    echo "Define extra options for $1"
	    exit 1
	;;
    esac
    o_gcc="$o_gcc ${AVRTEST_HOME}/exit-$1.o -I${AVRTEST_HOME} -DUSE_AVRTEST"
}


# $1 = ELF file
# $2 = mcu as understood by avr-gcc
# Extra options for AVRtest are passed in o_sim.
Simulate_avrtest ()
{
    # The following exit stati will be returned with -q:
    # -  0  Everything went fine.
    # -  1  Target program called abort()
    # -  x  Target program called exit (x)
    # - 10  Program timeout as set by -m MAXCOUNT.
    # - 11  Something is wrong with the program file:  Does not fit into
    #       memory, not an AVR executable, ELF headers broken, ...
    # - 12  The program goes haywire:  Stack overflow, illegal instruction
    #       or PC.
    # - 13  Problem with symbol information like an odd function address.
    # - 14  Problem with using file I/O with the host's file system: Bad file
    #       handle or file name, illegal argument.  This does *not* encompass
    #       when fopen cannot open the file; this will just return a 0-handle.
    # - 20  Out of memory.
    # - 21  Wrong avrtest usage: Unknown options, etc.
    # - 22  Program file could not be found / read.
    # - 23  IEEE single emulation failed (e.g. on big-endian host)
    # - 24  IEEE double emulation failed (e.g. on big-endian host)
    # - 42  Fatal error in avrtest.

    # -no-stdin keeps AVRtest from hanging in rare situations of bogus
    # code that tries to read from stdin, but there is no input.

    # AVRtest has 3 flavours: avrtest, avrtest-xmega and avrtest-tiny.
    local suff=
    case "$o_sim" in
	*avrxmega* ) suff="-xmega" ;;
	*avrtiny*  ) suff="-tiny"  ;;
    esac

    msg=$(${AVRTEST_HOME}/${avrtest}${suff} \
	      -q -no-stdin $1 $o_sim -m 60000000000 ${EXTRA_AFLAGS} 2>&1)
    RETVAL=$?
    #echo "MSG = $msg"
    #echo " - $AVRTEST_HOME/$avrtest$suff -q $1 $o_sim -m 60000000000"
    [ $RETVAL -eq 0 ]
}


# $1 = relative file name of file to be simulated.
# AVRtest does not support SFR magic like EEPROM etc.
Skip_with_avrtest ()
{
    local reason=
    skip_why=
    case $1 in
	*eeprom*) skip_why="EEPROM"  ;;
	*sfr*)    skip_why="SFRs"    ;;
    esac

    grep -i eeprom    $1 > /dev/null && skip_why="EEPROM"
    grep -i sfr_      $1 > /dev/null && skip_why="SFRs"
    reason=$(grep SKIP_AVRTEST $1) > /dev/null \
	&& skip_why=$(echo "$reason" | awk -F\" '{ print $2 }' )

    [ -n "$skip_why" ]
}

# Usage: Compile SRCFILE MCU ELFILE PRVERS
Compile ()
{
    local crt=
    local libs=
    local flags=

    if [ -z "$AVRDIR" ] ; then
	  libs="-lm"
    else
      local multilibdir=`$AVR_GCC -mmcu=$2 -print-multi-directory`
      # Use the same replacements like in mlib-gen.py::to_ident() and
      # configure.ac's CHECK_AVR_DEVICE.  This flattens out the multilib path.
      # For example, "avr25/tiny-stack" becomes "avr25_tiny_stack",
      # and "." becomes "avr2".
      multilibdir=$(echo "$multilibdir"     \
                    | sed -e 's:^\.$:avr2:' \
                    | sed -e 's:/:_:g'      \
                    | sed -e 's:-:_:g')
      crt=crt$2.o
      flags="-I../../include -I $AVRDIR/include -nostdlib"
      crt=`find $AVRDIR/avr/devices -name $crt -print | head -1`
      if [ -z "$crt" ]; then
	  crt=`find $AVRDIR/avr/devices/$2 -name 'crt*.o' -print | head -1`
      fi
      libs="$AVRDIR/avr/lib/$multilibdir/libc.a	\
            $AVRDIR/avr/lib/$multilibdir/libm.a \
            $AVRDIR/avr/devices/$2/lib$2.a -lgcc"
    fi

    case $4 in
      PR_MIN)
	flags="$flags -Wl,-u,vfprintf"
	if [ -z "$AVRDIR" ] ; then
	    libs="-lprintf_min $libs"
	else
	    libs="$AVRDIR/avr/lib/$multilibdir/libprintf_min.a $libs"
	fi
	;;
      PR_FLT)
	flags="$flags -Wl,-u,vfprintf"
	if [ -z "$AVRDIR" ] ; then
	    libs="-lprintf_flt $libs"
	else
	    libs="$AVRDIR/avr/lib/$multilibdir/libprintf_flt.a $libs"
	fi
	;;
      SC_MIN)
	flags="$flags -Wl,-u,vfscanf"
	if [ -z "$AVRDIR" ] ; then
	    libs="-lscanf_min $libs"
	else
	    libs="$AVRDIR/avr/lib/$multilibdir/libscanf_min.a $libs"
	fi
	;;
      SC_FLT)
	flags="$flags -Wl,-u,vfscanf"
	if [ -z "$AVRDIR" ] ; then
	    libs="-lscanf_flt $libs"
	else
	    libs="$AVRDIR/avr/lib/$multilibdir/libscanf_flt.a $libs"
	fi
	;;
    esac

    libs="-Wl,--start-group $libs -Wl,--end-group"

    # The GCC 4.1 (and older) does not define __ASSEMBLER__ with
    # '-std=gnu99' option for *.S sources.
    case `basename $1` in
	*.c)	flags="$flags -std=gnu99" ;;
    esac

    $AVR_GCC $CPPFLAGS $CFLAGS $flags -mmcu=$2 $crt $1 $o_gcc $libs -o $3
}


n_files=0	# number of operated files
n_emake=0	# number of compile/link errors
n_ehost=0	# number of 'run-at-host' errors
n_esimul=0	# number of simulation errors
n_skips=0	# number of skipped tests (AVRtest can't EEPROM, SFRs or ISRs)

for test_file in $test_list ; do
    case `basename $test_file` in

	*.c | *.cpp)
	    n_files=$(($n_files + 1))

	    rootname=`basename $test_file .c`

	    if [ $HOST_PASS ] ; then
		exe_file=./$rootname.exe
		echo -n "At_host:  $test_file ... "
		if ! ${HOST_CC} ${HOST_CFLAGS} -o $exe_file $test_file -lm
		then
		    Err_echo "compile failed"
		    n_emake=$(($n_emake + 1))
		elif [ -z $MAKE_ONLY ] && ! Host_exe $exe_file ; then
		    Err_echo "execute failed: $RETVAL"
		    n_ehost=$(($n_ehost + 1))
		else
		    echo "OK"
		fi
		rm -f $exe_file
	    fi

	    if [ -z $HOST_ONLY ] ; then
		case $rootname in
		    *printf_min*)	prlist="PR_MIN" ;;
		    *printf_std*)	prlist="PR_STD" ;;
		    *printf_flt*)	prlist="PR_FLT" ;;
		    *printf_all*)	prlist="PR_STD PR_FLT PR_MIN" ;;
		    *printf*)		prlist="PR_STD PR_FLT" ;;
		    *scanf_min*)	prlist="SC_MIN" ;;
		    *scanf_std*)	prlist="SC_STD" ;;
		    *scanf_flt*)	prlist="SC_FLT" ;;
		    *scanf_brk*)	prlist="SC_STD SC_FLT" ;;
		    *scanf*)		prlist="SC_STD SC_FLT SC_MIN" ;;
		    *)			prlist="PR_STD" ;;
		esac

		case `dirname $test_file` in
		    avr)  mcu_list="$MCU_LIST_FULL" ;;
		    *)    mcu_list="$MCU_LIST" ;;
		esac

	        elf_file=$rootname.elf
		for prvers in $prlist ; do
		    for mcu in ${MCUS-$mcu_list} ; do
			set_extra_options $mcu
			echo -n "Simulate avrtest: $test_file "
			case $prvers in
			    PR_MIN)	echo -n "/printf_min " ;;
			    PR_FLT)	echo -n "/printf_flt " ;;
			    SC_MIN)	echo -n "/scanf_min " ;;
			    SC_FLT)	echo -n "/scanf_flt " ;;
			esac
			echo -n "$mcu ... "
			if Skip_with_avrtest $test_file
			then
			    echo "SKIP (why: $skip_why)"
			    n_skips=$(($n_skips + 1))
			    break
		        elif ! Compile $test_file $mcu $elf_file $prvers
			then
			    Err_echo "compile failed"
			    n_emake=$(($n_emake + 1))
			    break
			elif [ -z $MAKE_ONLY ] \
				 && ! Simulate_avrtest $elf_file $mcu
			then
			    case $RETVAL in
				23)
				    echo "SKIP (no IEEE single emulation)"
				    n_skips=$(($n_skips + 1))
				    break
				    ;;
				24)
				    echo "SKIP (no IEEE double emulation)"
				    n_skips=$(($n_skips + 1))
				    break
				    ;;
				*)
				    Err_echo "simulate avrtest failed: $RETVAL"
				    n_esimul=$(($n_esimul + 1))
				    ;;
			    esac
			else
			    echo "OK"
			fi
		    done
	        done
		rm -f $elf_file
	    fi
	    ;;

	*.S)
	    n_files=$(($n_files + 1))

	    rootname=`basename $test_file .S`

	    if [ -z $HOST_ONLY ] ; then
		case `dirname $test_file` in
		    avr)  mcu_list="$MCU_LIST_FULL" ;;
		    *)    mcu_list="$MCU_LIST" ;;
		esac

	        elf_file=$rootname.elf
		for mcu in ${MCUS-$mcu_list} ; do
		    set_extra_options $mcu
		    echo -n "Simulate: $test_file "
		    echo -n "$mcu ... "
		    if Skip_with_avrtest $test_file
		    then
			Err_echo "skipped ($skip_why)"
			n_skips=$(($n_skips + 1))
			break
		    elif ! Compile $test_file $mcu $elf_file
		    then
			Err_echo "compile failed"
			n_emake=$(($n_emake + 1))
			break
		    elif [ -z $MAKE_ONLY ] && ! Simulate $elf_file $mcu
		    then
			Err_echo "simulate failed: $RETVAL"
			n_esimul=$(($n_esimul + 1))
		    else
			echo "OK"
		    fi
		done
		rm -f $elf_file
	    fi
	    ;;

	*)
	    Errx "Unknown file type: $test_file"
    esac
done

echo "-------"
echo "Done.  Number of operated files: $n_files"

[ $n_skips  -gt 0 ]  && echo "*** Simulations skipped: $n_skips"

if [ $(expr $n_emake + $n_ehost + $n_esimul) -gt 0 ] ; then
    [ $n_emake -gt 0 ]   && echo "*** Compile/link errors: $n_emake"
    [ $n_ehost -gt 0 ]   && echo "*** At host errors:      $n_ehost"
    [ $n_esimul -gt 0 ]  && echo "*** Simulate errors:     $n_esimul"
    exit 1
else
    echo "Success."
fi

# eof
