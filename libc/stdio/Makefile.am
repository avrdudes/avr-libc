# Copyright (c) 2002, Joerg Wunsch
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

noinst_LIBRARIES = lib.a libprintf_min.a libprintf_flt.a

lib_a_c_sources =	\
	clearerr.c	\
	fclose.c	\
	fdevopen.c	\
	feof.c		\
	ferror.c	\
	fgetc.c		\
	fgets.c		\
	fprintf.c	\
	fprintf_p.c	\
	fputc.c		\
	fputs.c		\
	fputs_p.c	\
	fread.c		\
	fwrite.c	\
	getchar.c	\
	gets.c		\
	printf.c	\
	printf_p.c	\
	putchar.c	\
	puts.c		\
	puts_p.c	\
	snprintf.c	\
	snprintf_p.c	\
	sprintf.c	\
	sprintf_p.c	\
	ungetc.c

lib_a_asm_sources =	\
	getc.S		\
	putc.S

lib_a_SOURCES = $(lib_a_c_sources) $(lib_a_asm_sources)

lib_a_c_objs = $(lib_a_c_sources:%.c=%.o)

lib_a_asm_objs = $(lib_a_c_sources:%.S=%.o)

lib_a_LIBADD = vfprintf_std.o

libprintf_min_a_SOURCES=

libprintf_min_a_LIBADD = vfprintf_min.o

libprintf_flt_a_SOURCES=

libprintf_flt_a_LIBADD = vfprintf_flt.o

# must be added to the package, but automake doesn't know them as source
# files until now
EXTRA_DIST = vfprintf.c stdio_private.h

# content of AVRLIB_CFLAGS and AVRLIB_ASFLAGS is determined by configure
# according to the multilib subdir (see acinclude.m4 in top directory)

$(lib_a_c_objs): %.o: %.c
	$(COMPILE) $(AVRLIB_CFLAGS) -c $< -o $@

$(lib_a_asm_objs): %.o: %.S
	$(COMPILE) $(AVRLIB_ASFLAGS) -c $< -o $@

# vfprintf is compiled best with -O1 -mno-tablejump, this gives the
# smallest code.
PRINTF_CFLAGS = $(AVRLIB_CFLAGS) -O1 -mno-tablejump

vfprintf_min.o: vfprintf.c
	$(COMPILE) $(PRINTF_CFLAGS) -DPRINTF_LEVEL=PRINTF_MIN \
	-c $(srcdir)/vfprintf.c -o $@

vfprintf_std.o: vfprintf.c
	$(COMPILE) $(PRINTF_CFLAGS) -DPRINTF_LEVEL=PRINTF_STD \
	-c $(srcdir)/vfprintf.c -o $@

vfprintf_flt.o: vfprintf.c
	$(COMPILE) $(PRINTF_CFLAGS) -DPRINTF_LEVEL=PRINTF_FLT \
	-c $(srcdir)/vfprintf.c -o $@

