# Copyright (c) 2002, Reinhard Jessich  <reinhard.jessich@telering.at>
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

## Process this file with automake to generate Makefile.in

noinst_LIBRARIES = lib.a

lib_a_c_sources = \
	abs.c		\
	bsearch.c	\
	errno.c		\
	labs.c		\
	malloc.c	\
	qsort.c		\
	rand.c		\
	strtol.c	\
	strtoul.c

lib_a_asm_sources = \
	abort.S  \
	atoi.S   \
	atol.S   \
	div.S    \
	exit.S   \
	ldiv.S   \
	setjmp.S

# this objects are all generated from ctype.S
libc_ctype_asm_objs = \
	isascii.o toascii.o isalnum.o cty_isfalse.o \
	isalpha.o isdigit.o isxdigit.o iscntrl.o    \
	isprint.o isspace.o isblank.o ispunct.o     \
	tolower.o toupper.o

lib_a_SOURCES = $(lib_a_c_sources) $(lib_a_asm_sources)

lib_a_c_objs = $(lib_a_c_sources:%.c=%.o)

lib_a_asm_objs = $(lib_a_asm_sources:%.S=%.o)

lib_a_LIBADD = $(libc_ctype_asm_objs)

# must be added to the package, but automake doesn't know them as source
# files until now
EXTRA_DIST = ctype.S abort.c atoi.c atol.c

# content of AVRLIB_CFLAGS and AVRLIB_ASFLAGS is determined by configure
# according to the multilib subdir (see acinclude.m4 in top directory)

$(libc_ctype_asm_objs): %.o: ctype.S
	$(COMPILE) $(AVRLIB_ASFLAGS) -c -DL$(basename $@) $< -o $@

$(lib_a_c_objs): %.o: %.c
	$(COMPILE) $(AVRLIB_CFLAGS) -c $< -o $@

$(lib_a_asm_objs): %.o: %.S
	$(COMPILE) $(AVRLIB_ASFLAGS) -c $< -o $@
