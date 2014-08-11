/* This file is part of avr-libc.

   Automatically created by devtools/ioreg.pl
   DO NOT EDIT!

   Redistribution and use in source and binary forms, with or without
   modification, are permitted provided that the following conditions are met:

   * Redistributions of source code must retain the above copyright
     notice, this list of conditions and the following disclaimer.

   * Redistributions in binary form must reproduce the above copyright
     notice, this list of conditions and the following disclaimer in
     the documentation and/or other materials provided with the
     distribution.

   * Neither the name of the copyright holders nor the names of
     contributors may be used to endorse or promote products derived
     from this software without specific prior written permission.

  THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS "AS IS"
  AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE
  IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE
  ARE DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT OWNER OR CONTRIBUTORS BE
  LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR
  CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF
  SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS
  INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN
  CONTRACT, STRICT LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE)
  ARISING IN ANY WAY OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE
  POSSIBILITY OF SUCH DAMAGE. */

/* $Id$ */

#include <avr/version.h>

#define DW_TAG_array_type               0x01
#define DW_TAG_compile_unit             0x11
#define DW_TAG_typedef                  0x16
#define DW_TAG_subrange_type            0x21
#define DW_TAG_base_type                0x24
#define DW_TAG_variable                 0x34

#define DW_FORM_addr                    0x01
#define DW_FORM_block1                  0x0a
#define DW_FORM_block2                  0x03
#define DW_FORM_block4                  0x04
#define DW_FORM_data1                   0x0b
#define DW_FORM_data2                   0x05
#define DW_FORM_data4                   0x06
#define DW_FORM_data8                   0x07
#define DW_FORM_string                  0x08
#define DW_FORM_flag                    0x0c
#define DW_FORM_strp                    0x0e
#define DW_FORM_ref1                    0x11
#define DW_FORM_ref2                    0x12
#define DW_FORM_ref4                    0x13
#define DW_FORM_ref8                    0x14

#define DW_AT_location                  0x02
#define DW_AT_name                      0x03
#define DW_AT_byte_size                 0x0b
#define DW_AT_stmt_list                 0x10
#define DW_AT_language                  0x13
#define DW_AT_producer                  0x25
#define DW_AT_upper_bound               0x2f
#define DW_AT_decl_file                 0x3a
#define DW_AT_decl_line                 0x3b
#define DW_AT_encoding                  0x3e
#define DW_AT_external                  0x3f
#define DW_AT_type                      0x49

#define DW_LANG_C89                     0x0001

#define DW_CHILDREN_no                  0x00
#define DW_CHILDREN_yes                 0x01

#define DW_ATE_unsigned                 0x7
#define DW_ATE_unsigned_char            0x8

#define DW_OP_addr                      0x03
.eject
	.section	.debug_abbrev, "", @progbits
.Ldebug_abbrev0:
	.section	.debug_info, "", @progbits
	.section	.debug_line, "", @progbits
.Ldebug_line0:
	.section	.debug_str, "", @progbits

	.section	.debug_info, "", @progbits
	;; compilation unit header
.Lssinfo:
	.long	.Leinfo - .Lsinfo
.Lsinfo:
	.word	2		; DWARF-2
	.long	.Ldebug_abbrev0
	.byte	4		; sizeof(address)


	;; DIE #1: compilation unit
	.section	.debug_info
	.uleb128	1	; ref to abbrev 1
	.section	.debug_abbrev
	.uleb128	1
	.uleb128	DW_TAG_compile_unit
	.byte		DW_CHILDREN_yes

	.uleb128	DW_AT_producer
	.uleb128	DW_FORM_strp
	.section	.debug_str
.Lproducer:
	.ascii		"avr-libc "
	.asciz		__AVR_LIBC_VERSION_STRING__
	.section	.debug_info
	.long		.Lproducer

	.section	.debug_abbrev
	.uleb128	DW_AT_stmt_list
	.uleb128	DW_FORM_data4
	.section	.debug_info
	.long		.Ldebug_line0

	.section	.debug_abbrev
	.uleb128	0
	.uleb128	0

	;; DIE #2: base type uint8_t
	.section	.debug_info
.Luint8_t:
	.uleb128	2	; ref to abbrev 2
	.section	.debug_abbrev
	.uleb128	2
	.uleb128	DW_TAG_base_type
	.byte		DW_CHILDREN_no

	.uleb128	DW_AT_name
	.uleb128	DW_FORM_strp
	.section	.debug_str
.Luint8_t_name:
	.string		"uint8_t"
	.section	.debug_info
	.long		.Luint8_t_name

	.section	.debug_abbrev
	.uleb128	DW_AT_byte_size
	.uleb128	DW_FORM_data1
	.section	.debug_info
	.byte		1

	.section	.debug_abbrev
	.uleb128	DW_AT_encoding
	.uleb128	DW_FORM_data1
	.section	.debug_info
	.byte		DW_ATE_unsigned_char

	.section	.debug_abbrev
	.uleb128	0
	.uleb128	0

	;; DIE #3: base type uint16_t
	.section	.debug_info
.Luint16_t:
	.uleb128	3	; ref to abbrev 3
	.section	.debug_abbrev
	.uleb128	3
	.uleb128	DW_TAG_base_type
	.byte		DW_CHILDREN_no

	.uleb128	DW_AT_name
	.uleb128	DW_FORM_strp
	.section	.debug_str
.Luint16_t_name:
	.string		"uint16_t"
	.section	.debug_info
	.long		.Luint16_t_name

	.section	.debug_abbrev
	.uleb128	DW_AT_byte_size
	.uleb128	DW_FORM_data1
	.section	.debug_info
	.byte		2

	.section	.debug_abbrev
	.uleb128	DW_AT_encoding
	.uleb128	DW_FORM_data1
	.section	.debug_info
	.byte		DW_ATE_unsigned

	.section	.debug_abbrev
	.uleb128	0
	.uleb128	0

;- - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
	;; DIE #4: EEPROM array base type: uint8_t
	.section	.debug_info
.Leeprom_t:
	.uleb128	4	; ref to abbrev 4
	.section	.debug_abbrev
	.uleb128	4
	.uleb128	DW_TAG_array_type
	.byte		DW_CHILDREN_yes

	.uleb128	DW_AT_type
	.uleb128	DW_FORM_ref4
	.section	.debug_info
	.long		.Luint8_t - .Lssinfo

	.section	.debug_abbrev
	.uleb128	0
	.uleb128	0

	;; DIE #5: EEPROM array subtype (index type/bounds): uint16_t
	.section	.debug_info
	.uleb128	5	; ref to abbrev 5
	.section	.debug_abbrev
	.uleb128	5
	.uleb128	DW_TAG_subrange_type
	.byte		DW_CHILDREN_no

	.uleb128	DW_AT_type
	.uleb128	DW_FORM_ref4
	.section	.debug_info
	.long		.Luint16_t - .Lssinfo
	.section	.debug_abbrev
	.uleb128	DW_AT_upper_bound
	.uleb128	DW_FORM_data2
	.section	.debug_info
	.word		0x0400 - 1
	.section	.debug_abbrev
	.uleb128	0
	.uleb128	0

	.section	.debug_info
	.byte		0	; end of DIE #4 children

	;; DIE #6: EEPROM array variable (name)
	.section	.debug_info
	.uleb128	6	; ref to abbrev 6
	.section	.debug_abbrev
	.uleb128	6
	.uleb128	DW_TAG_variable
	.byte		DW_CHILDREN_no

	.uleb128	DW_AT_name
	.uleb128	DW_FORM_strp
	.section	.debug_str
.Lname6:
	.string		"__eeprom"
	.section	.debug_info
	.long		.Lname6

	.section	.debug_abbrev
	.uleb128	DW_AT_decl_file
	.uleb128	DW_FORM_data1
	.section	.debug_info
	.byte		0	; no source file information

	.section	.debug_abbrev
	.uleb128	DW_AT_decl_line
	.uleb128	DW_FORM_data1
	.section	.debug_info
	.byte		0	; no source line information

	.section	.debug_abbrev
	.uleb128	DW_AT_type
	.uleb128	DW_FORM_ref4
	.section	.debug_info
	.long		.Leeprom_t - .Lssinfo

	.section	.debug_abbrev
	.uleb128	DW_AT_external
	.uleb128	DW_FORM_flag
	.section	.debug_info
	.byte		1

	.section	.debug_abbrev
	.uleb128	DW_AT_location
	.uleb128	DW_FORM_block1
	.section	.debug_info
	.byte		5	; length of block
	.byte		DW_OP_addr
	.long		0x810000 + 0x00000

	.section	.debug_abbrev
	.uleb128	0
	.uleb128	0

;- - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
	;; DIE #7: variable GPIO_GPIOR0
	.section	.debug_info
	.uleb128	7	; ref to abbrev 7
	.section	.debug_abbrev
	.uleb128	7
	.uleb128	DW_TAG_variable
	.byte		DW_CHILDREN_no

	.uleb128	DW_AT_name
	.uleb128	DW_FORM_strp
	.section	.debug_str
.Lname7:
	.string		"GPIO_GPIOR0"
	.section	.debug_info
	.long		.Lname7

	.section	.debug_abbrev
	.uleb128	DW_AT_decl_file
	.uleb128	DW_FORM_data1
	.section	.debug_info
	.byte		0	; no source file information

	.section	.debug_abbrev
	.uleb128	DW_AT_decl_line
	.uleb128	DW_FORM_data1
	.section	.debug_info
	.byte		0	; no source line information

	.section	.debug_abbrev
	.uleb128	DW_AT_type
	.uleb128	DW_FORM_ref4
	.section	.debug_info
	.long		.Luint8_t - .Lssinfo

	.section	.debug_abbrev
	.uleb128	DW_AT_external
	.uleb128	DW_FORM_flag
	.section	.debug_info
	.byte		1

	.section	.debug_abbrev
	.uleb128	DW_AT_location
	.uleb128	DW_FORM_block1
	.section	.debug_info
	.byte		5	; length of block
	.byte		DW_OP_addr
	.long		0x800000 + 0x0000 + 0x00

	.section	.debug_abbrev
	.uleb128	0
	.uleb128	0

;- - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
	;; DIE #8: variable GPIO_GPIOR1
	.section	.debug_info
	.uleb128	8	; ref to abbrev 8
	.section	.debug_abbrev
	.uleb128	8
	.uleb128	DW_TAG_variable
	.byte		DW_CHILDREN_no

	.uleb128	DW_AT_name
	.uleb128	DW_FORM_strp
	.section	.debug_str
.Lname8:
	.string		"GPIO_GPIOR1"
	.section	.debug_info
	.long		.Lname8

	.section	.debug_abbrev
	.uleb128	DW_AT_decl_file
	.uleb128	DW_FORM_data1
	.section	.debug_info
	.byte		0	; no source file information

	.section	.debug_abbrev
	.uleb128	DW_AT_decl_line
	.uleb128	DW_FORM_data1
	.section	.debug_info
	.byte		0	; no source line information

	.section	.debug_abbrev
	.uleb128	DW_AT_type
	.uleb128	DW_FORM_ref4
	.section	.debug_info
	.long		.Luint8_t - .Lssinfo

	.section	.debug_abbrev
	.uleb128	DW_AT_external
	.uleb128	DW_FORM_flag
	.section	.debug_info
	.byte		1

	.section	.debug_abbrev
	.uleb128	DW_AT_location
	.uleb128	DW_FORM_block1
	.section	.debug_info
	.byte		5	; length of block
	.byte		DW_OP_addr
	.long		0x800000 + 0x0000 + 0x01

	.section	.debug_abbrev
	.uleb128	0
	.uleb128	0

;- - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
	;; DIE #9: variable GPIO_GPIOR2
	.section	.debug_info
	.uleb128	9	; ref to abbrev 9
	.section	.debug_abbrev
	.uleb128	9
	.uleb128	DW_TAG_variable
	.byte		DW_CHILDREN_no

	.uleb128	DW_AT_name
	.uleb128	DW_FORM_strp
	.section	.debug_str
.Lname9:
	.string		"GPIO_GPIOR2"
	.section	.debug_info
	.long		.Lname9

	.section	.debug_abbrev
	.uleb128	DW_AT_decl_file
	.uleb128	DW_FORM_data1
	.section	.debug_info
	.byte		0	; no source file information

	.section	.debug_abbrev
	.uleb128	DW_AT_decl_line
	.uleb128	DW_FORM_data1
	.section	.debug_info
	.byte		0	; no source line information

	.section	.debug_abbrev
	.uleb128	DW_AT_type
	.uleb128	DW_FORM_ref4
	.section	.debug_info
	.long		.Luint8_t - .Lssinfo

	.section	.debug_abbrev
	.uleb128	DW_AT_external
	.uleb128	DW_FORM_flag
	.section	.debug_info
	.byte		1

	.section	.debug_abbrev
	.uleb128	DW_AT_location
	.uleb128	DW_FORM_block1
	.section	.debug_info
	.byte		5	; length of block
	.byte		DW_OP_addr
	.long		0x800000 + 0x0000 + 0x02

	.section	.debug_abbrev
	.uleb128	0
	.uleb128	0

;- - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
	;; DIE #10: variable GPIO_GPIOR3
	.section	.debug_info
	.uleb128	10	; ref to abbrev 10
	.section	.debug_abbrev
	.uleb128	10
	.uleb128	DW_TAG_variable
	.byte		DW_CHILDREN_no

	.uleb128	DW_AT_name
	.uleb128	DW_FORM_strp
	.section	.debug_str
.Lname10:
	.string		"GPIO_GPIOR3"
	.section	.debug_info
	.long		.Lname10

	.section	.debug_abbrev
	.uleb128	DW_AT_decl_file
	.uleb128	DW_FORM_data1
	.section	.debug_info
	.byte		0	; no source file information

	.section	.debug_abbrev
	.uleb128	DW_AT_decl_line
	.uleb128	DW_FORM_data1
	.section	.debug_info
	.byte		0	; no source line information

	.section	.debug_abbrev
	.uleb128	DW_AT_type
	.uleb128	DW_FORM_ref4
	.section	.debug_info
	.long		.Luint8_t - .Lssinfo

	.section	.debug_abbrev
	.uleb128	DW_AT_external
	.uleb128	DW_FORM_flag
	.section	.debug_info
	.byte		1

	.section	.debug_abbrev
	.uleb128	DW_AT_location
	.uleb128	DW_FORM_block1
	.section	.debug_info
	.byte		5	; length of block
	.byte		DW_OP_addr
	.long		0x800000 + 0x0000 + 0x03

	.section	.debug_abbrev
	.uleb128	0
	.uleb128	0

;- - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
	;; DIE #11: variable VPORT0_DIR
	.section	.debug_info
	.uleb128	11	; ref to abbrev 11
	.section	.debug_abbrev
	.uleb128	11
	.uleb128	DW_TAG_variable
	.byte		DW_CHILDREN_no

	.uleb128	DW_AT_name
	.uleb128	DW_FORM_strp
	.section	.debug_str
.Lname11:
	.string		"VPORT0_DIR"
	.section	.debug_info
	.long		.Lname11

	.section	.debug_abbrev
	.uleb128	DW_AT_decl_file
	.uleb128	DW_FORM_data1
	.section	.debug_info
	.byte		0	; no source file information

	.section	.debug_abbrev
	.uleb128	DW_AT_decl_line
	.uleb128	DW_FORM_data1
	.section	.debug_info
	.byte		0	; no source line information

	.section	.debug_abbrev
	.uleb128	DW_AT_type
	.uleb128	DW_FORM_ref4
	.section	.debug_info
	.long		.Luint8_t - .Lssinfo

	.section	.debug_abbrev
	.uleb128	DW_AT_external
	.uleb128	DW_FORM_flag
	.section	.debug_info
	.byte		1

	.section	.debug_abbrev
	.uleb128	DW_AT_location
	.uleb128	DW_FORM_block1
	.section	.debug_info
	.byte		5	; length of block
	.byte		DW_OP_addr
	.long		0x800000 + 0x0010 + 0x00

	.section	.debug_abbrev
	.uleb128	0
	.uleb128	0

;- - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
	;; DIE #12: variable VPORT0_OUT
	.section	.debug_info
	.uleb128	12	; ref to abbrev 12
	.section	.debug_abbrev
	.uleb128	12
	.uleb128	DW_TAG_variable
	.byte		DW_CHILDREN_no

	.uleb128	DW_AT_name
	.uleb128	DW_FORM_strp
	.section	.debug_str
.Lname12:
	.string		"VPORT0_OUT"
	.section	.debug_info
	.long		.Lname12

	.section	.debug_abbrev
	.uleb128	DW_AT_decl_file
	.uleb128	DW_FORM_data1
	.section	.debug_info
	.byte		0	; no source file information

	.section	.debug_abbrev
	.uleb128	DW_AT_decl_line
	.uleb128	DW_FORM_data1
	.section	.debug_info
	.byte		0	; no source line information

	.section	.debug_abbrev
	.uleb128	DW_AT_type
	.uleb128	DW_FORM_ref4
	.section	.debug_info
	.long		.Luint8_t - .Lssinfo

	.section	.debug_abbrev
	.uleb128	DW_AT_external
	.uleb128	DW_FORM_flag
	.section	.debug_info
	.byte		1

	.section	.debug_abbrev
	.uleb128	DW_AT_location
	.uleb128	DW_FORM_block1
	.section	.debug_info
	.byte		5	; length of block
	.byte		DW_OP_addr
	.long		0x800000 + 0x0010 + 0x01

	.section	.debug_abbrev
	.uleb128	0
	.uleb128	0

;- - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
	;; DIE #13: variable VPORT0_IN
	.section	.debug_info
	.uleb128	13	; ref to abbrev 13
	.section	.debug_abbrev
	.uleb128	13
	.uleb128	DW_TAG_variable
	.byte		DW_CHILDREN_no

	.uleb128	DW_AT_name
	.uleb128	DW_FORM_strp
	.section	.debug_str
.Lname13:
	.string		"VPORT0_IN"
	.section	.debug_info
	.long		.Lname13

	.section	.debug_abbrev
	.uleb128	DW_AT_decl_file
	.uleb128	DW_FORM_data1
	.section	.debug_info
	.byte		0	; no source file information

	.section	.debug_abbrev
	.uleb128	DW_AT_decl_line
	.uleb128	DW_FORM_data1
	.section	.debug_info
	.byte		0	; no source line information

	.section	.debug_abbrev
	.uleb128	DW_AT_type
	.uleb128	DW_FORM_ref4
	.section	.debug_info
	.long		.Luint8_t - .Lssinfo

	.section	.debug_abbrev
	.uleb128	DW_AT_external
	.uleb128	DW_FORM_flag
	.section	.debug_info
	.byte		1

	.section	.debug_abbrev
	.uleb128	DW_AT_location
	.uleb128	DW_FORM_block1
	.section	.debug_info
	.byte		5	; length of block
	.byte		DW_OP_addr
	.long		0x800000 + 0x0010 + 0x02

	.section	.debug_abbrev
	.uleb128	0
	.uleb128	0

;- - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
	;; DIE #14: variable VPORT0_INTFLAGS
	.section	.debug_info
	.uleb128	14	; ref to abbrev 14
	.section	.debug_abbrev
	.uleb128	14
	.uleb128	DW_TAG_variable
	.byte		DW_CHILDREN_no

	.uleb128	DW_AT_name
	.uleb128	DW_FORM_strp
	.section	.debug_str
.Lname14:
	.string		"VPORT0_INTFLAGS"
	.section	.debug_info
	.long		.Lname14

	.section	.debug_abbrev
	.uleb128	DW_AT_decl_file
	.uleb128	DW_FORM_data1
	.section	.debug_info
	.byte		0	; no source file information

	.section	.debug_abbrev
	.uleb128	DW_AT_decl_line
	.uleb128	DW_FORM_data1
	.section	.debug_info
	.byte		0	; no source line information

	.section	.debug_abbrev
	.uleb128	DW_AT_type
	.uleb128	DW_FORM_ref4
	.section	.debug_info
	.long		.Luint8_t - .Lssinfo

	.section	.debug_abbrev
	.uleb128	DW_AT_external
	.uleb128	DW_FORM_flag
	.section	.debug_info
	.byte		1

	.section	.debug_abbrev
	.uleb128	DW_AT_location
	.uleb128	DW_FORM_block1
	.section	.debug_info
	.byte		5	; length of block
	.byte		DW_OP_addr
	.long		0x800000 + 0x0010 + 0x03

	.section	.debug_abbrev
	.uleb128	0
	.uleb128	0

;- - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
	;; DIE #15: variable VPORT1_DIR
	.section	.debug_info
	.uleb128	15	; ref to abbrev 15
	.section	.debug_abbrev
	.uleb128	15
	.uleb128	DW_TAG_variable
	.byte		DW_CHILDREN_no

	.uleb128	DW_AT_name
	.uleb128	DW_FORM_strp
	.section	.debug_str
.Lname15:
	.string		"VPORT1_DIR"
	.section	.debug_info
	.long		.Lname15

	.section	.debug_abbrev
	.uleb128	DW_AT_decl_file
	.uleb128	DW_FORM_data1
	.section	.debug_info
	.byte		0	; no source file information

	.section	.debug_abbrev
	.uleb128	DW_AT_decl_line
	.uleb128	DW_FORM_data1
	.section	.debug_info
	.byte		0	; no source line information

	.section	.debug_abbrev
	.uleb128	DW_AT_type
	.uleb128	DW_FORM_ref4
	.section	.debug_info
	.long		.Luint8_t - .Lssinfo

	.section	.debug_abbrev
	.uleb128	DW_AT_external
	.uleb128	DW_FORM_flag
	.section	.debug_info
	.byte		1

	.section	.debug_abbrev
	.uleb128	DW_AT_location
	.uleb128	DW_FORM_block1
	.section	.debug_info
	.byte		5	; length of block
	.byte		DW_OP_addr
	.long		0x800000 + 0x0014 + 0x00

	.section	.debug_abbrev
	.uleb128	0
	.uleb128	0

;- - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
	;; DIE #16: variable VPORT1_OUT
	.section	.debug_info
	.uleb128	16	; ref to abbrev 16
	.section	.debug_abbrev
	.uleb128	16
	.uleb128	DW_TAG_variable
	.byte		DW_CHILDREN_no

	.uleb128	DW_AT_name
	.uleb128	DW_FORM_strp
	.section	.debug_str
.Lname16:
	.string		"VPORT1_OUT"
	.section	.debug_info
	.long		.Lname16

	.section	.debug_abbrev
	.uleb128	DW_AT_decl_file
	.uleb128	DW_FORM_data1
	.section	.debug_info
	.byte		0	; no source file information

	.section	.debug_abbrev
	.uleb128	DW_AT_decl_line
	.uleb128	DW_FORM_data1
	.section	.debug_info
	.byte		0	; no source line information

	.section	.debug_abbrev
	.uleb128	DW_AT_type
	.uleb128	DW_FORM_ref4
	.section	.debug_info
	.long		.Luint8_t - .Lssinfo

	.section	.debug_abbrev
	.uleb128	DW_AT_external
	.uleb128	DW_FORM_flag
	.section	.debug_info
	.byte		1

	.section	.debug_abbrev
	.uleb128	DW_AT_location
	.uleb128	DW_FORM_block1
	.section	.debug_info
	.byte		5	; length of block
	.byte		DW_OP_addr
	.long		0x800000 + 0x0014 + 0x01

	.section	.debug_abbrev
	.uleb128	0
	.uleb128	0

;- - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
	;; DIE #17: variable VPORT1_IN
	.section	.debug_info
	.uleb128	17	; ref to abbrev 17
	.section	.debug_abbrev
	.uleb128	17
	.uleb128	DW_TAG_variable
	.byte		DW_CHILDREN_no

	.uleb128	DW_AT_name
	.uleb128	DW_FORM_strp
	.section	.debug_str
.Lname17:
	.string		"VPORT1_IN"
	.section	.debug_info
	.long		.Lname17

	.section	.debug_abbrev
	.uleb128	DW_AT_decl_file
	.uleb128	DW_FORM_data1
	.section	.debug_info
	.byte		0	; no source file information

	.section	.debug_abbrev
	.uleb128	DW_AT_decl_line
	.uleb128	DW_FORM_data1
	.section	.debug_info
	.byte		0	; no source line information

	.section	.debug_abbrev
	.uleb128	DW_AT_type
	.uleb128	DW_FORM_ref4
	.section	.debug_info
	.long		.Luint8_t - .Lssinfo

	.section	.debug_abbrev
	.uleb128	DW_AT_external
	.uleb128	DW_FORM_flag
	.section	.debug_info
	.byte		1

	.section	.debug_abbrev
	.uleb128	DW_AT_location
	.uleb128	DW_FORM_block1
	.section	.debug_info
	.byte		5	; length of block
	.byte		DW_OP_addr
	.long		0x800000 + 0x0014 + 0x02

	.section	.debug_abbrev
	.uleb128	0
	.uleb128	0

;- - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
	;; DIE #18: variable VPORT1_INTFLAGS
	.section	.debug_info
	.uleb128	18	; ref to abbrev 18
	.section	.debug_abbrev
	.uleb128	18
	.uleb128	DW_TAG_variable
	.byte		DW_CHILDREN_no

	.uleb128	DW_AT_name
	.uleb128	DW_FORM_strp
	.section	.debug_str
.Lname18:
	.string		"VPORT1_INTFLAGS"
	.section	.debug_info
	.long		.Lname18

	.section	.debug_abbrev
	.uleb128	DW_AT_decl_file
	.uleb128	DW_FORM_data1
	.section	.debug_info
	.byte		0	; no source file information

	.section	.debug_abbrev
	.uleb128	DW_AT_decl_line
	.uleb128	DW_FORM_data1
	.section	.debug_info
	.byte		0	; no source line information

	.section	.debug_abbrev
	.uleb128	DW_AT_type
	.uleb128	DW_FORM_ref4
	.section	.debug_info
	.long		.Luint8_t - .Lssinfo

	.section	.debug_abbrev
	.uleb128	DW_AT_external
	.uleb128	DW_FORM_flag
	.section	.debug_info
	.byte		1

	.section	.debug_abbrev
	.uleb128	DW_AT_location
	.uleb128	DW_FORM_block1
	.section	.debug_info
	.byte		5	; length of block
	.byte		DW_OP_addr
	.long		0x800000 + 0x0014 + 0x03

	.section	.debug_abbrev
	.uleb128	0
	.uleb128	0

;- - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
	;; DIE #19: variable VPORT2_DIR
	.section	.debug_info
	.uleb128	19	; ref to abbrev 19
	.section	.debug_abbrev
	.uleb128	19
	.uleb128	DW_TAG_variable
	.byte		DW_CHILDREN_no

	.uleb128	DW_AT_name
	.uleb128	DW_FORM_strp
	.section	.debug_str
.Lname19:
	.string		"VPORT2_DIR"
	.section	.debug_info
	.long		.Lname19

	.section	.debug_abbrev
	.uleb128	DW_AT_decl_file
	.uleb128	DW_FORM_data1
	.section	.debug_info
	.byte		0	; no source file information

	.section	.debug_abbrev
	.uleb128	DW_AT_decl_line
	.uleb128	DW_FORM_data1
	.section	.debug_info
	.byte		0	; no source line information

	.section	.debug_abbrev
	.uleb128	DW_AT_type
	.uleb128	DW_FORM_ref4
	.section	.debug_info
	.long		.Luint8_t - .Lssinfo

	.section	.debug_abbrev
	.uleb128	DW_AT_external
	.uleb128	DW_FORM_flag
	.section	.debug_info
	.byte		1

	.section	.debug_abbrev
	.uleb128	DW_AT_location
	.uleb128	DW_FORM_block1
	.section	.debug_info
	.byte		5	; length of block
	.byte		DW_OP_addr
	.long		0x800000 + 0x0018 + 0x00

	.section	.debug_abbrev
	.uleb128	0
	.uleb128	0

;- - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
	;; DIE #20: variable VPORT2_OUT
	.section	.debug_info
	.uleb128	20	; ref to abbrev 20
	.section	.debug_abbrev
	.uleb128	20
	.uleb128	DW_TAG_variable
	.byte		DW_CHILDREN_no

	.uleb128	DW_AT_name
	.uleb128	DW_FORM_strp
	.section	.debug_str
.Lname20:
	.string		"VPORT2_OUT"
	.section	.debug_info
	.long		.Lname20

	.section	.debug_abbrev
	.uleb128	DW_AT_decl_file
	.uleb128	DW_FORM_data1
	.section	.debug_info
	.byte		0	; no source file information

	.section	.debug_abbrev
	.uleb128	DW_AT_decl_line
	.uleb128	DW_FORM_data1
	.section	.debug_info
	.byte		0	; no source line information

	.section	.debug_abbrev
	.uleb128	DW_AT_type
	.uleb128	DW_FORM_ref4
	.section	.debug_info
	.long		.Luint8_t - .Lssinfo

	.section	.debug_abbrev
	.uleb128	DW_AT_external
	.uleb128	DW_FORM_flag
	.section	.debug_info
	.byte		1

	.section	.debug_abbrev
	.uleb128	DW_AT_location
	.uleb128	DW_FORM_block1
	.section	.debug_info
	.byte		5	; length of block
	.byte		DW_OP_addr
	.long		0x800000 + 0x0018 + 0x01

	.section	.debug_abbrev
	.uleb128	0
	.uleb128	0

;- - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
	;; DIE #21: variable VPORT2_IN
	.section	.debug_info
	.uleb128	21	; ref to abbrev 21
	.section	.debug_abbrev
	.uleb128	21
	.uleb128	DW_TAG_variable
	.byte		DW_CHILDREN_no

	.uleb128	DW_AT_name
	.uleb128	DW_FORM_strp
	.section	.debug_str
.Lname21:
	.string		"VPORT2_IN"
	.section	.debug_info
	.long		.Lname21

	.section	.debug_abbrev
	.uleb128	DW_AT_decl_file
	.uleb128	DW_FORM_data1
	.section	.debug_info
	.byte		0	; no source file information

	.section	.debug_abbrev
	.uleb128	DW_AT_decl_line
	.uleb128	DW_FORM_data1
	.section	.debug_info
	.byte		0	; no source line information

	.section	.debug_abbrev
	.uleb128	DW_AT_type
	.uleb128	DW_FORM_ref4
	.section	.debug_info
	.long		.Luint8_t - .Lssinfo

	.section	.debug_abbrev
	.uleb128	DW_AT_external
	.uleb128	DW_FORM_flag
	.section	.debug_info
	.byte		1

	.section	.debug_abbrev
	.uleb128	DW_AT_location
	.uleb128	DW_FORM_block1
	.section	.debug_info
	.byte		5	; length of block
	.byte		DW_OP_addr
	.long		0x800000 + 0x0018 + 0x02

	.section	.debug_abbrev
	.uleb128	0
	.uleb128	0

;- - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
	;; DIE #22: variable VPORT2_INTFLAGS
	.section	.debug_info
	.uleb128	22	; ref to abbrev 22
	.section	.debug_abbrev
	.uleb128	22
	.uleb128	DW_TAG_variable
	.byte		DW_CHILDREN_no

	.uleb128	DW_AT_name
	.uleb128	DW_FORM_strp
	.section	.debug_str
.Lname22:
	.string		"VPORT2_INTFLAGS"
	.section	.debug_info
	.long		.Lname22

	.section	.debug_abbrev
	.uleb128	DW_AT_decl_file
	.uleb128	DW_FORM_data1
	.section	.debug_info
	.byte		0	; no source file information

	.section	.debug_abbrev
	.uleb128	DW_AT_decl_line
	.uleb128	DW_FORM_data1
	.section	.debug_info
	.byte		0	; no source line information

	.section	.debug_abbrev
	.uleb128	DW_AT_type
	.uleb128	DW_FORM_ref4
	.section	.debug_info
	.long		.Luint8_t - .Lssinfo

	.section	.debug_abbrev
	.uleb128	DW_AT_external
	.uleb128	DW_FORM_flag
	.section	.debug_info
	.byte		1

	.section	.debug_abbrev
	.uleb128	DW_AT_location
	.uleb128	DW_FORM_block1
	.section	.debug_info
	.byte		5	; length of block
	.byte		DW_OP_addr
	.long		0x800000 + 0x0018 + 0x03

	.section	.debug_abbrev
	.uleb128	0
	.uleb128	0

;- - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
	;; DIE #23: variable VPORT3_DIR
	.section	.debug_info
	.uleb128	23	; ref to abbrev 23
	.section	.debug_abbrev
	.uleb128	23
	.uleb128	DW_TAG_variable
	.byte		DW_CHILDREN_no

	.uleb128	DW_AT_name
	.uleb128	DW_FORM_strp
	.section	.debug_str
.Lname23:
	.string		"VPORT3_DIR"
	.section	.debug_info
	.long		.Lname23

	.section	.debug_abbrev
	.uleb128	DW_AT_decl_file
	.uleb128	DW_FORM_data1
	.section	.debug_info
	.byte		0	; no source file information

	.section	.debug_abbrev
	.uleb128	DW_AT_decl_line
	.uleb128	DW_FORM_data1
	.section	.debug_info
	.byte		0	; no source line information

	.section	.debug_abbrev
	.uleb128	DW_AT_type
	.uleb128	DW_FORM_ref4
	.section	.debug_info
	.long		.Luint8_t - .Lssinfo

	.section	.debug_abbrev
	.uleb128	DW_AT_external
	.uleb128	DW_FORM_flag
	.section	.debug_info
	.byte		1

	.section	.debug_abbrev
	.uleb128	DW_AT_location
	.uleb128	DW_FORM_block1
	.section	.debug_info
	.byte		5	; length of block
	.byte		DW_OP_addr
	.long		0x800000 + 0x001C + 0x00

	.section	.debug_abbrev
	.uleb128	0
	.uleb128	0

;- - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
	;; DIE #24: variable VPORT3_OUT
	.section	.debug_info
	.uleb128	24	; ref to abbrev 24
	.section	.debug_abbrev
	.uleb128	24
	.uleb128	DW_TAG_variable
	.byte		DW_CHILDREN_no

	.uleb128	DW_AT_name
	.uleb128	DW_FORM_strp
	.section	.debug_str
.Lname24:
	.string		"VPORT3_OUT"
	.section	.debug_info
	.long		.Lname24

	.section	.debug_abbrev
	.uleb128	DW_AT_decl_file
	.uleb128	DW_FORM_data1
	.section	.debug_info
	.byte		0	; no source file information

	.section	.debug_abbrev
	.uleb128	DW_AT_decl_line
	.uleb128	DW_FORM_data1
	.section	.debug_info
	.byte		0	; no source line information

	.section	.debug_abbrev
	.uleb128	DW_AT_type
	.uleb128	DW_FORM_ref4
	.section	.debug_info
	.long		.Luint8_t - .Lssinfo

	.section	.debug_abbrev
	.uleb128	DW_AT_external
	.uleb128	DW_FORM_flag
	.section	.debug_info
	.byte		1

	.section	.debug_abbrev
	.uleb128	DW_AT_location
	.uleb128	DW_FORM_block1
	.section	.debug_info
	.byte		5	; length of block
	.byte		DW_OP_addr
	.long		0x800000 + 0x001C + 0x01

	.section	.debug_abbrev
	.uleb128	0
	.uleb128	0

;- - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
	;; DIE #25: variable VPORT3_IN
	.section	.debug_info
	.uleb128	25	; ref to abbrev 25
	.section	.debug_abbrev
	.uleb128	25
	.uleb128	DW_TAG_variable
	.byte		DW_CHILDREN_no

	.uleb128	DW_AT_name
	.uleb128	DW_FORM_strp
	.section	.debug_str
.Lname25:
	.string		"VPORT3_IN"
	.section	.debug_info
	.long		.Lname25

	.section	.debug_abbrev
	.uleb128	DW_AT_decl_file
	.uleb128	DW_FORM_data1
	.section	.debug_info
	.byte		0	; no source file information

	.section	.debug_abbrev
	.uleb128	DW_AT_decl_line
	.uleb128	DW_FORM_data1
	.section	.debug_info
	.byte		0	; no source line information

	.section	.debug_abbrev
	.uleb128	DW_AT_type
	.uleb128	DW_FORM_ref4
	.section	.debug_info
	.long		.Luint8_t - .Lssinfo

	.section	.debug_abbrev
	.uleb128	DW_AT_external
	.uleb128	DW_FORM_flag
	.section	.debug_info
	.byte		1

	.section	.debug_abbrev
	.uleb128	DW_AT_location
	.uleb128	DW_FORM_block1
	.section	.debug_info
	.byte		5	; length of block
	.byte		DW_OP_addr
	.long		0x800000 + 0x001C + 0x02

	.section	.debug_abbrev
	.uleb128	0
	.uleb128	0

;- - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
	;; DIE #26: variable VPORT3_INTFLAGS
	.section	.debug_info
	.uleb128	26	; ref to abbrev 26
	.section	.debug_abbrev
	.uleb128	26
	.uleb128	DW_TAG_variable
	.byte		DW_CHILDREN_no

	.uleb128	DW_AT_name
	.uleb128	DW_FORM_strp
	.section	.debug_str
.Lname26:
	.string		"VPORT3_INTFLAGS"
	.section	.debug_info
	.long		.Lname26

	.section	.debug_abbrev
	.uleb128	DW_AT_decl_file
	.uleb128	DW_FORM_data1
	.section	.debug_info
	.byte		0	; no source file information

	.section	.debug_abbrev
	.uleb128	DW_AT_decl_line
	.uleb128	DW_FORM_data1
	.section	.debug_info
	.byte		0	; no source line information

	.section	.debug_abbrev
	.uleb128	DW_AT_type
	.uleb128	DW_FORM_ref4
	.section	.debug_info
	.long		.Luint8_t - .Lssinfo

	.section	.debug_abbrev
	.uleb128	DW_AT_external
	.uleb128	DW_FORM_flag
	.section	.debug_info
	.byte		1

	.section	.debug_abbrev
	.uleb128	DW_AT_location
	.uleb128	DW_FORM_block1
	.section	.debug_info
	.byte		5	; length of block
	.byte		DW_OP_addr
	.long		0x800000 + 0x001C + 0x03

	.section	.debug_abbrev
	.uleb128	0
	.uleb128	0

;- - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
	;; DIE #27: variable OCD_OCDR0
	.section	.debug_info
	.uleb128	27	; ref to abbrev 27
	.section	.debug_abbrev
	.uleb128	27
	.uleb128	DW_TAG_variable
	.byte		DW_CHILDREN_no

	.uleb128	DW_AT_name
	.uleb128	DW_FORM_strp
	.section	.debug_str
.Lname27:
	.string		"OCD_OCDR0"
	.section	.debug_info
	.long		.Lname27

	.section	.debug_abbrev
	.uleb128	DW_AT_decl_file
	.uleb128	DW_FORM_data1
	.section	.debug_info
	.byte		0	; no source file information

	.section	.debug_abbrev
	.uleb128	DW_AT_decl_line
	.uleb128	DW_FORM_data1
	.section	.debug_info
	.byte		0	; no source line information

	.section	.debug_abbrev
	.uleb128	DW_AT_type
	.uleb128	DW_FORM_ref4
	.section	.debug_info
	.long		.Luint8_t - .Lssinfo

	.section	.debug_abbrev
	.uleb128	DW_AT_external
	.uleb128	DW_FORM_flag
	.section	.debug_info
	.byte		1

	.section	.debug_abbrev
	.uleb128	DW_AT_location
	.uleb128	DW_FORM_block1
	.section	.debug_info
	.byte		5	; length of block
	.byte		DW_OP_addr
	.long		0x800000 + 0x002E + 0x00

	.section	.debug_abbrev
	.uleb128	0
	.uleb128	0

;- - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
	;; DIE #28: variable OCD_OCDR1
	.section	.debug_info
	.uleb128	28	; ref to abbrev 28
	.section	.debug_abbrev
	.uleb128	28
	.uleb128	DW_TAG_variable
	.byte		DW_CHILDREN_no

	.uleb128	DW_AT_name
	.uleb128	DW_FORM_strp
	.section	.debug_str
.Lname28:
	.string		"OCD_OCDR1"
	.section	.debug_info
	.long		.Lname28

	.section	.debug_abbrev
	.uleb128	DW_AT_decl_file
	.uleb128	DW_FORM_data1
	.section	.debug_info
	.byte		0	; no source file information

	.section	.debug_abbrev
	.uleb128	DW_AT_decl_line
	.uleb128	DW_FORM_data1
	.section	.debug_info
	.byte		0	; no source line information

	.section	.debug_abbrev
	.uleb128	DW_AT_type
	.uleb128	DW_FORM_ref4
	.section	.debug_info
	.long		.Luint8_t - .Lssinfo

	.section	.debug_abbrev
	.uleb128	DW_AT_external
	.uleb128	DW_FORM_flag
	.section	.debug_info
	.byte		1

	.section	.debug_abbrev
	.uleb128	DW_AT_location
	.uleb128	DW_FORM_block1
	.section	.debug_info
	.byte		5	; length of block
	.byte		DW_OP_addr
	.long		0x800000 + 0x002E + 0x01

	.section	.debug_abbrev
	.uleb128	0
	.uleb128	0

;- - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
	;; DIE #29: variable CPU_CCP
	.section	.debug_info
	.uleb128	29	; ref to abbrev 29
	.section	.debug_abbrev
	.uleb128	29
	.uleb128	DW_TAG_variable
	.byte		DW_CHILDREN_no

	.uleb128	DW_AT_name
	.uleb128	DW_FORM_strp
	.section	.debug_str
.Lname29:
	.string		"CPU_CCP"
	.section	.debug_info
	.long		.Lname29

	.section	.debug_abbrev
	.uleb128	DW_AT_decl_file
	.uleb128	DW_FORM_data1
	.section	.debug_info
	.byte		0	; no source file information

	.section	.debug_abbrev
	.uleb128	DW_AT_decl_line
	.uleb128	DW_FORM_data1
	.section	.debug_info
	.byte		0	; no source line information

	.section	.debug_abbrev
	.uleb128	DW_AT_type
	.uleb128	DW_FORM_ref4
	.section	.debug_info
	.long		.Luint8_t - .Lssinfo

	.section	.debug_abbrev
	.uleb128	DW_AT_external
	.uleb128	DW_FORM_flag
	.section	.debug_info
	.byte		1

	.section	.debug_abbrev
	.uleb128	DW_AT_location
	.uleb128	DW_FORM_block1
	.section	.debug_info
	.byte		5	; length of block
	.byte		DW_OP_addr
	.long		0x800000 + 0x0030 + 0x04

	.section	.debug_abbrev
	.uleb128	0
	.uleb128	0

;- - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
	;; DIE #30: variable CPU_RAMPD
	.section	.debug_info
	.uleb128	30	; ref to abbrev 30
	.section	.debug_abbrev
	.uleb128	30
	.uleb128	DW_TAG_variable
	.byte		DW_CHILDREN_no

	.uleb128	DW_AT_name
	.uleb128	DW_FORM_strp
	.section	.debug_str
.Lname30:
	.string		"CPU_RAMPD"
	.section	.debug_info
	.long		.Lname30

	.section	.debug_abbrev
	.uleb128	DW_AT_decl_file
	.uleb128	DW_FORM_data1
	.section	.debug_info
	.byte		0	; no source file information

	.section	.debug_abbrev
	.uleb128	DW_AT_decl_line
	.uleb128	DW_FORM_data1
	.section	.debug_info
	.byte		0	; no source line information

	.section	.debug_abbrev
	.uleb128	DW_AT_type
	.uleb128	DW_FORM_ref4
	.section	.debug_info
	.long		.Luint8_t - .Lssinfo

	.section	.debug_abbrev
	.uleb128	DW_AT_external
	.uleb128	DW_FORM_flag
	.section	.debug_info
	.byte		1

	.section	.debug_abbrev
	.uleb128	DW_AT_location
	.uleb128	DW_FORM_block1
	.section	.debug_info
	.byte		5	; length of block
	.byte		DW_OP_addr
	.long		0x800000 + 0x0030 + 0x08

	.section	.debug_abbrev
	.uleb128	0
	.uleb128	0

;- - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
	;; DIE #31: variable CPU_RAMPX
	.section	.debug_info
	.uleb128	31	; ref to abbrev 31
	.section	.debug_abbrev
	.uleb128	31
	.uleb128	DW_TAG_variable
	.byte		DW_CHILDREN_no

	.uleb128	DW_AT_name
	.uleb128	DW_FORM_strp
	.section	.debug_str
.Lname31:
	.string		"CPU_RAMPX"
	.section	.debug_info
	.long		.Lname31

	.section	.debug_abbrev
	.uleb128	DW_AT_decl_file
	.uleb128	DW_FORM_data1
	.section	.debug_info
	.byte		0	; no source file information

	.section	.debug_abbrev
	.uleb128	DW_AT_decl_line
	.uleb128	DW_FORM_data1
	.section	.debug_info
	.byte		0	; no source line information

	.section	.debug_abbrev
	.uleb128	DW_AT_type
	.uleb128	DW_FORM_ref4
	.section	.debug_info
	.long		.Luint8_t - .Lssinfo

	.section	.debug_abbrev
	.uleb128	DW_AT_external
	.uleb128	DW_FORM_flag
	.section	.debug_info
	.byte		1

	.section	.debug_abbrev
	.uleb128	DW_AT_location
	.uleb128	DW_FORM_block1
	.section	.debug_info
	.byte		5	; length of block
	.byte		DW_OP_addr
	.long		0x800000 + 0x0030 + 0x09

	.section	.debug_abbrev
	.uleb128	0
	.uleb128	0

;- - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
	;; DIE #32: variable CPU_RAMPY
	.section	.debug_info
	.uleb128	32	; ref to abbrev 32
	.section	.debug_abbrev
	.uleb128	32
	.uleb128	DW_TAG_variable
	.byte		DW_CHILDREN_no

	.uleb128	DW_AT_name
	.uleb128	DW_FORM_strp
	.section	.debug_str
.Lname32:
	.string		"CPU_RAMPY"
	.section	.debug_info
	.long		.Lname32

	.section	.debug_abbrev
	.uleb128	DW_AT_decl_file
	.uleb128	DW_FORM_data1
	.section	.debug_info
	.byte		0	; no source file information

	.section	.debug_abbrev
	.uleb128	DW_AT_decl_line
	.uleb128	DW_FORM_data1
	.section	.debug_info
	.byte		0	; no source line information

	.section	.debug_abbrev
	.uleb128	DW_AT_type
	.uleb128	DW_FORM_ref4
	.section	.debug_info
	.long		.Luint8_t - .Lssinfo

	.section	.debug_abbrev
	.uleb128	DW_AT_external
	.uleb128	DW_FORM_flag
	.section	.debug_info
	.byte		1

	.section	.debug_abbrev
	.uleb128	DW_AT_location
	.uleb128	DW_FORM_block1
	.section	.debug_info
	.byte		5	; length of block
	.byte		DW_OP_addr
	.long		0x800000 + 0x0030 + 0x0A

	.section	.debug_abbrev
	.uleb128	0
	.uleb128	0

;- - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
	;; DIE #33: variable CPU_RAMPZ
	.section	.debug_info
	.uleb128	33	; ref to abbrev 33
	.section	.debug_abbrev
	.uleb128	33
	.uleb128	DW_TAG_variable
	.byte		DW_CHILDREN_no

	.uleb128	DW_AT_name
	.uleb128	DW_FORM_strp
	.section	.debug_str
.Lname33:
	.string		"CPU_RAMPZ"
	.section	.debug_info
	.long		.Lname33

	.section	.debug_abbrev
	.uleb128	DW_AT_decl_file
	.uleb128	DW_FORM_data1
	.section	.debug_info
	.byte		0	; no source file information

	.section	.debug_abbrev
	.uleb128	DW_AT_decl_line
	.uleb128	DW_FORM_data1
	.section	.debug_info
	.byte		0	; no source line information

	.section	.debug_abbrev
	.uleb128	DW_AT_type
	.uleb128	DW_FORM_ref4
	.section	.debug_info
	.long		.Luint8_t - .Lssinfo

	.section	.debug_abbrev
	.uleb128	DW_AT_external
	.uleb128	DW_FORM_flag
	.section	.debug_info
	.byte		1

	.section	.debug_abbrev
	.uleb128	DW_AT_location
	.uleb128	DW_FORM_block1
	.section	.debug_info
	.byte		5	; length of block
	.byte		DW_OP_addr
	.long		0x800000 + 0x0030 + 0x0B

	.section	.debug_abbrev
	.uleb128	0
	.uleb128	0

;- - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
	;; DIE #34: variable CPU_EIND
	.section	.debug_info
	.uleb128	34	; ref to abbrev 34
	.section	.debug_abbrev
	.uleb128	34
	.uleb128	DW_TAG_variable
	.byte		DW_CHILDREN_no

	.uleb128	DW_AT_name
	.uleb128	DW_FORM_strp
	.section	.debug_str
.Lname34:
	.string		"CPU_EIND"
	.section	.debug_info
	.long		.Lname34

	.section	.debug_abbrev
	.uleb128	DW_AT_decl_file
	.uleb128	DW_FORM_data1
	.section	.debug_info
	.byte		0	; no source file information

	.section	.debug_abbrev
	.uleb128	DW_AT_decl_line
	.uleb128	DW_FORM_data1
	.section	.debug_info
	.byte		0	; no source line information

	.section	.debug_abbrev
	.uleb128	DW_AT_type
	.uleb128	DW_FORM_ref4
	.section	.debug_info
	.long		.Luint8_t - .Lssinfo

	.section	.debug_abbrev
	.uleb128	DW_AT_external
	.uleb128	DW_FORM_flag
	.section	.debug_info
	.byte		1

	.section	.debug_abbrev
	.uleb128	DW_AT_location
	.uleb128	DW_FORM_block1
	.section	.debug_info
	.byte		5	; length of block
	.byte		DW_OP_addr
	.long		0x800000 + 0x0030 + 0x0C

	.section	.debug_abbrev
	.uleb128	0
	.uleb128	0

;- - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
	;; DIE #35: variable CPU_SPL
	.section	.debug_info
	.uleb128	35	; ref to abbrev 35
	.section	.debug_abbrev
	.uleb128	35
	.uleb128	DW_TAG_variable
	.byte		DW_CHILDREN_no

	.uleb128	DW_AT_name
	.uleb128	DW_FORM_strp
	.section	.debug_str
.Lname35:
	.string		"CPU_SPL"
	.section	.debug_info
	.long		.Lname35

	.section	.debug_abbrev
	.uleb128	DW_AT_decl_file
	.uleb128	DW_FORM_data1
	.section	.debug_info
	.byte		0	; no source file information

	.section	.debug_abbrev
	.uleb128	DW_AT_decl_line
	.uleb128	DW_FORM_data1
	.section	.debug_info
	.byte		0	; no source line information

	.section	.debug_abbrev
	.uleb128	DW_AT_type
	.uleb128	DW_FORM_ref4
	.section	.debug_info
	.long		.Luint8_t - .Lssinfo

	.section	.debug_abbrev
	.uleb128	DW_AT_external
	.uleb128	DW_FORM_flag
	.section	.debug_info
	.byte		1

	.section	.debug_abbrev
	.uleb128	DW_AT_location
	.uleb128	DW_FORM_block1
	.section	.debug_info
	.byte		5	; length of block
	.byte		DW_OP_addr
	.long		0x800000 + 0x0030 + 0x0D

	.section	.debug_abbrev
	.uleb128	0
	.uleb128	0

;- - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
	;; DIE #36: variable CPU_SPH
	.section	.debug_info
	.uleb128	36	; ref to abbrev 36
	.section	.debug_abbrev
	.uleb128	36
	.uleb128	DW_TAG_variable
	.byte		DW_CHILDREN_no

	.uleb128	DW_AT_name
	.uleb128	DW_FORM_strp
	.section	.debug_str
.Lname36:
	.string		"CPU_SPH"
	.section	.debug_info
	.long		.Lname36

	.section	.debug_abbrev
	.uleb128	DW_AT_decl_file
	.uleb128	DW_FORM_data1
	.section	.debug_info
	.byte		0	; no source file information

	.section	.debug_abbrev
	.uleb128	DW_AT_decl_line
	.uleb128	DW_FORM_data1
	.section	.debug_info
	.byte		0	; no source line information

	.section	.debug_abbrev
	.uleb128	DW_AT_type
	.uleb128	DW_FORM_ref4
	.section	.debug_info
	.long		.Luint8_t - .Lssinfo

	.section	.debug_abbrev
	.uleb128	DW_AT_external
	.uleb128	DW_FORM_flag
	.section	.debug_info
	.byte		1

	.section	.debug_abbrev
	.uleb128	DW_AT_location
	.uleb128	DW_FORM_block1
	.section	.debug_info
	.byte		5	; length of block
	.byte		DW_OP_addr
	.long		0x800000 + 0x0030 + 0x0E

	.section	.debug_abbrev
	.uleb128	0
	.uleb128	0

;- - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
	;; DIE #37: variable CPU_SREG
	.section	.debug_info
	.uleb128	37	; ref to abbrev 37
	.section	.debug_abbrev
	.uleb128	37
	.uleb128	DW_TAG_variable
	.byte		DW_CHILDREN_no

	.uleb128	DW_AT_name
	.uleb128	DW_FORM_strp
	.section	.debug_str
.Lname37:
	.string		"CPU_SREG"
	.section	.debug_info
	.long		.Lname37

	.section	.debug_abbrev
	.uleb128	DW_AT_decl_file
	.uleb128	DW_FORM_data1
	.section	.debug_info
	.byte		0	; no source file information

	.section	.debug_abbrev
	.uleb128	DW_AT_decl_line
	.uleb128	DW_FORM_data1
	.section	.debug_info
	.byte		0	; no source line information

	.section	.debug_abbrev
	.uleb128	DW_AT_type
	.uleb128	DW_FORM_ref4
	.section	.debug_info
	.long		.Luint8_t - .Lssinfo

	.section	.debug_abbrev
	.uleb128	DW_AT_external
	.uleb128	DW_FORM_flag
	.section	.debug_info
	.byte		1

	.section	.debug_abbrev
	.uleb128	DW_AT_location
	.uleb128	DW_FORM_block1
	.section	.debug_info
	.byte		5	; length of block
	.byte		DW_OP_addr
	.long		0x800000 + 0x0030 + 0x0F

	.section	.debug_abbrev
	.uleb128	0
	.uleb128	0

;- - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
	;; DIE #38: variable CLK_CTRL
	.section	.debug_info
	.uleb128	38	; ref to abbrev 38
	.section	.debug_abbrev
	.uleb128	38
	.uleb128	DW_TAG_variable
	.byte		DW_CHILDREN_no

	.uleb128	DW_AT_name
	.uleb128	DW_FORM_strp
	.section	.debug_str
.Lname38:
	.string		"CLK_CTRL"
	.section	.debug_info
	.long		.Lname38

	.section	.debug_abbrev
	.uleb128	DW_AT_decl_file
	.uleb128	DW_FORM_data1
	.section	.debug_info
	.byte		0	; no source file information

	.section	.debug_abbrev
	.uleb128	DW_AT_decl_line
	.uleb128	DW_FORM_data1
	.section	.debug_info
	.byte		0	; no source line information

	.section	.debug_abbrev
	.uleb128	DW_AT_type
	.uleb128	DW_FORM_ref4
	.section	.debug_info
	.long		.Luint8_t - .Lssinfo

	.section	.debug_abbrev
	.uleb128	DW_AT_external
	.uleb128	DW_FORM_flag
	.section	.debug_info
	.byte		1

	.section	.debug_abbrev
	.uleb128	DW_AT_location
	.uleb128	DW_FORM_block1
	.section	.debug_info
	.byte		5	; length of block
	.byte		DW_OP_addr
	.long		0x800000 + 0x0040 + 0x00

	.section	.debug_abbrev
	.uleb128	0
	.uleb128	0

;- - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
	;; DIE #39: variable CLK_PSCTRL
	.section	.debug_info
	.uleb128	39	; ref to abbrev 39
	.section	.debug_abbrev
	.uleb128	39
	.uleb128	DW_TAG_variable
	.byte		DW_CHILDREN_no

	.uleb128	DW_AT_name
	.uleb128	DW_FORM_strp
	.section	.debug_str
.Lname39:
	.string		"CLK_PSCTRL"
	.section	.debug_info
	.long		.Lname39

	.section	.debug_abbrev
	.uleb128	DW_AT_decl_file
	.uleb128	DW_FORM_data1
	.section	.debug_info
	.byte		0	; no source file information

	.section	.debug_abbrev
	.uleb128	DW_AT_decl_line
	.uleb128	DW_FORM_data1
	.section	.debug_info
	.byte		0	; no source line information

	.section	.debug_abbrev
	.uleb128	DW_AT_type
	.uleb128	DW_FORM_ref4
	.section	.debug_info
	.long		.Luint8_t - .Lssinfo

	.section	.debug_abbrev
	.uleb128	DW_AT_external
	.uleb128	DW_FORM_flag
	.section	.debug_info
	.byte		1

	.section	.debug_abbrev
	.uleb128	DW_AT_location
	.uleb128	DW_FORM_block1
	.section	.debug_info
	.byte		5	; length of block
	.byte		DW_OP_addr
	.long		0x800000 + 0x0040 + 0x01

	.section	.debug_abbrev
	.uleb128	0
	.uleb128	0

;- - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
	;; DIE #40: variable CLK_LOCK
	.section	.debug_info
	.uleb128	40	; ref to abbrev 40
	.section	.debug_abbrev
	.uleb128	40
	.uleb128	DW_TAG_variable
	.byte		DW_CHILDREN_no

	.uleb128	DW_AT_name
	.uleb128	DW_FORM_strp
	.section	.debug_str
.Lname40:
	.string		"CLK_LOCK"
	.section	.debug_info
	.long		.Lname40

	.section	.debug_abbrev
	.uleb128	DW_AT_decl_file
	.uleb128	DW_FORM_data1
	.section	.debug_info
	.byte		0	; no source file information

	.section	.debug_abbrev
	.uleb128	DW_AT_decl_line
	.uleb128	DW_FORM_data1
	.section	.debug_info
	.byte		0	; no source line information

	.section	.debug_abbrev
	.uleb128	DW_AT_type
	.uleb128	DW_FORM_ref4
	.section	.debug_info
	.long		.Luint8_t - .Lssinfo

	.section	.debug_abbrev
	.uleb128	DW_AT_external
	.uleb128	DW_FORM_flag
	.section	.debug_info
	.byte		1

	.section	.debug_abbrev
	.uleb128	DW_AT_location
	.uleb128	DW_FORM_block1
	.section	.debug_info
	.byte		5	; length of block
	.byte		DW_OP_addr
	.long		0x800000 + 0x0040 + 0x02

	.section	.debug_abbrev
	.uleb128	0
	.uleb128	0

;- - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
	;; DIE #41: variable CLK_RTCCTRL
	.section	.debug_info
	.uleb128	41	; ref to abbrev 41
	.section	.debug_abbrev
	.uleb128	41
	.uleb128	DW_TAG_variable
	.byte		DW_CHILDREN_no

	.uleb128	DW_AT_name
	.uleb128	DW_FORM_strp
	.section	.debug_str
.Lname41:
	.string		"CLK_RTCCTRL"
	.section	.debug_info
	.long		.Lname41

	.section	.debug_abbrev
	.uleb128	DW_AT_decl_file
	.uleb128	DW_FORM_data1
	.section	.debug_info
	.byte		0	; no source file information

	.section	.debug_abbrev
	.uleb128	DW_AT_decl_line
	.uleb128	DW_FORM_data1
	.section	.debug_info
	.byte		0	; no source line information

	.section	.debug_abbrev
	.uleb128	DW_AT_type
	.uleb128	DW_FORM_ref4
	.section	.debug_info
	.long		.Luint8_t - .Lssinfo

	.section	.debug_abbrev
	.uleb128	DW_AT_external
	.uleb128	DW_FORM_flag
	.section	.debug_info
	.byte		1

	.section	.debug_abbrev
	.uleb128	DW_AT_location
	.uleb128	DW_FORM_block1
	.section	.debug_info
	.byte		5	; length of block
	.byte		DW_OP_addr
	.long		0x800000 + 0x0040 + 0x03

	.section	.debug_abbrev
	.uleb128	0
	.uleb128	0

;- - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
	;; DIE #42: variable CLK_USBCTRL
	.section	.debug_info
	.uleb128	42	; ref to abbrev 42
	.section	.debug_abbrev
	.uleb128	42
	.uleb128	DW_TAG_variable
	.byte		DW_CHILDREN_no

	.uleb128	DW_AT_name
	.uleb128	DW_FORM_strp
	.section	.debug_str
.Lname42:
	.string		"CLK_USBCTRL"
	.section	.debug_info
	.long		.Lname42

	.section	.debug_abbrev
	.uleb128	DW_AT_decl_file
	.uleb128	DW_FORM_data1
	.section	.debug_info
	.byte		0	; no source file information

	.section	.debug_abbrev
	.uleb128	DW_AT_decl_line
	.uleb128	DW_FORM_data1
	.section	.debug_info
	.byte		0	; no source line information

	.section	.debug_abbrev
	.uleb128	DW_AT_type
	.uleb128	DW_FORM_ref4
	.section	.debug_info
	.long		.Luint8_t - .Lssinfo

	.section	.debug_abbrev
	.uleb128	DW_AT_external
	.uleb128	DW_FORM_flag
	.section	.debug_info
	.byte		1

	.section	.debug_abbrev
	.uleb128	DW_AT_location
	.uleb128	DW_FORM_block1
	.section	.debug_info
	.byte		5	; length of block
	.byte		DW_OP_addr
	.long		0x800000 + 0x0040 + 0x04

	.section	.debug_abbrev
	.uleb128	0
	.uleb128	0

;- - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
	;; DIE #43: variable PR_PRGEN
	.section	.debug_info
	.uleb128	43	; ref to abbrev 43
	.section	.debug_abbrev
	.uleb128	43
	.uleb128	DW_TAG_variable
	.byte		DW_CHILDREN_no

	.uleb128	DW_AT_name
	.uleb128	DW_FORM_strp
	.section	.debug_str
.Lname43:
	.string		"PR_PRGEN"
	.section	.debug_info
	.long		.Lname43

	.section	.debug_abbrev
	.uleb128	DW_AT_decl_file
	.uleb128	DW_FORM_data1
	.section	.debug_info
	.byte		0	; no source file information

	.section	.debug_abbrev
	.uleb128	DW_AT_decl_line
	.uleb128	DW_FORM_data1
	.section	.debug_info
	.byte		0	; no source line information

	.section	.debug_abbrev
	.uleb128	DW_AT_type
	.uleb128	DW_FORM_ref4
	.section	.debug_info
	.long		.Luint8_t - .Lssinfo

	.section	.debug_abbrev
	.uleb128	DW_AT_external
	.uleb128	DW_FORM_flag
	.section	.debug_info
	.byte		1

	.section	.debug_abbrev
	.uleb128	DW_AT_location
	.uleb128	DW_FORM_block1
	.section	.debug_info
	.byte		5	; length of block
	.byte		DW_OP_addr
	.long		0x800000 + 0x0070 + 0x00

	.section	.debug_abbrev
	.uleb128	0
	.uleb128	0

;- - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
	;; DIE #44: variable PR_PRPA
	.section	.debug_info
	.uleb128	44	; ref to abbrev 44
	.section	.debug_abbrev
	.uleb128	44
	.uleb128	DW_TAG_variable
	.byte		DW_CHILDREN_no

	.uleb128	DW_AT_name
	.uleb128	DW_FORM_strp
	.section	.debug_str
.Lname44:
	.string		"PR_PRPA"
	.section	.debug_info
	.long		.Lname44

	.section	.debug_abbrev
	.uleb128	DW_AT_decl_file
	.uleb128	DW_FORM_data1
	.section	.debug_info
	.byte		0	; no source file information

	.section	.debug_abbrev
	.uleb128	DW_AT_decl_line
	.uleb128	DW_FORM_data1
	.section	.debug_info
	.byte		0	; no source line information

	.section	.debug_abbrev
	.uleb128	DW_AT_type
	.uleb128	DW_FORM_ref4
	.section	.debug_info
	.long		.Luint8_t - .Lssinfo

	.section	.debug_abbrev
	.uleb128	DW_AT_external
	.uleb128	DW_FORM_flag
	.section	.debug_info
	.byte		1

	.section	.debug_abbrev
	.uleb128	DW_AT_location
	.uleb128	DW_FORM_block1
	.section	.debug_info
	.byte		5	; length of block
	.byte		DW_OP_addr
	.long		0x800000 + 0x0070 + 0x01

	.section	.debug_abbrev
	.uleb128	0
	.uleb128	0

;- - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
	;; DIE #45: variable PR_PRPC
	.section	.debug_info
	.uleb128	45	; ref to abbrev 45
	.section	.debug_abbrev
	.uleb128	45
	.uleb128	DW_TAG_variable
	.byte		DW_CHILDREN_no

	.uleb128	DW_AT_name
	.uleb128	DW_FORM_strp
	.section	.debug_str
.Lname45:
	.string		"PR_PRPC"
	.section	.debug_info
	.long		.Lname45

	.section	.debug_abbrev
	.uleb128	DW_AT_decl_file
	.uleb128	DW_FORM_data1
	.section	.debug_info
	.byte		0	; no source file information

	.section	.debug_abbrev
	.uleb128	DW_AT_decl_line
	.uleb128	DW_FORM_data1
	.section	.debug_info
	.byte		0	; no source line information

	.section	.debug_abbrev
	.uleb128	DW_AT_type
	.uleb128	DW_FORM_ref4
	.section	.debug_info
	.long		.Luint8_t - .Lssinfo

	.section	.debug_abbrev
	.uleb128	DW_AT_external
	.uleb128	DW_FORM_flag
	.section	.debug_info
	.byte		1

	.section	.debug_abbrev
	.uleb128	DW_AT_location
	.uleb128	DW_FORM_block1
	.section	.debug_info
	.byte		5	; length of block
	.byte		DW_OP_addr
	.long		0x800000 + 0x0070 + 0x03

	.section	.debug_abbrev
	.uleb128	0
	.uleb128	0

;- - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
	;; DIE #46: variable PR_PRPD
	.section	.debug_info
	.uleb128	46	; ref to abbrev 46
	.section	.debug_abbrev
	.uleb128	46
	.uleb128	DW_TAG_variable
	.byte		DW_CHILDREN_no

	.uleb128	DW_AT_name
	.uleb128	DW_FORM_strp
	.section	.debug_str
.Lname46:
	.string		"PR_PRPD"
	.section	.debug_info
	.long		.Lname46

	.section	.debug_abbrev
	.uleb128	DW_AT_decl_file
	.uleb128	DW_FORM_data1
	.section	.debug_info
	.byte		0	; no source file information

	.section	.debug_abbrev
	.uleb128	DW_AT_decl_line
	.uleb128	DW_FORM_data1
	.section	.debug_info
	.byte		0	; no source line information

	.section	.debug_abbrev
	.uleb128	DW_AT_type
	.uleb128	DW_FORM_ref4
	.section	.debug_info
	.long		.Luint8_t - .Lssinfo

	.section	.debug_abbrev
	.uleb128	DW_AT_external
	.uleb128	DW_FORM_flag
	.section	.debug_info
	.byte		1

	.section	.debug_abbrev
	.uleb128	DW_AT_location
	.uleb128	DW_FORM_block1
	.section	.debug_info
	.byte		5	; length of block
	.byte		DW_OP_addr
	.long		0x800000 + 0x0070 + 0x04

	.section	.debug_abbrev
	.uleb128	0
	.uleb128	0

;- - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
	;; DIE #47: variable PR_PRPE
	.section	.debug_info
	.uleb128	47	; ref to abbrev 47
	.section	.debug_abbrev
	.uleb128	47
	.uleb128	DW_TAG_variable
	.byte		DW_CHILDREN_no

	.uleb128	DW_AT_name
	.uleb128	DW_FORM_strp
	.section	.debug_str
.Lname47:
	.string		"PR_PRPE"
	.section	.debug_info
	.long		.Lname47

	.section	.debug_abbrev
	.uleb128	DW_AT_decl_file
	.uleb128	DW_FORM_data1
	.section	.debug_info
	.byte		0	; no source file information

	.section	.debug_abbrev
	.uleb128	DW_AT_decl_line
	.uleb128	DW_FORM_data1
	.section	.debug_info
	.byte		0	; no source line information

	.section	.debug_abbrev
	.uleb128	DW_AT_type
	.uleb128	DW_FORM_ref4
	.section	.debug_info
	.long		.Luint8_t - .Lssinfo

	.section	.debug_abbrev
	.uleb128	DW_AT_external
	.uleb128	DW_FORM_flag
	.section	.debug_info
	.byte		1

	.section	.debug_abbrev
	.uleb128	DW_AT_location
	.uleb128	DW_FORM_block1
	.section	.debug_info
	.byte		5	; length of block
	.byte		DW_OP_addr
	.long		0x800000 + 0x0070 + 0x05

	.section	.debug_abbrev
	.uleb128	0
	.uleb128	0

;- - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
	;; DIE #48: variable PR_PRPF
	.section	.debug_info
	.uleb128	48	; ref to abbrev 48
	.section	.debug_abbrev
	.uleb128	48
	.uleb128	DW_TAG_variable
	.byte		DW_CHILDREN_no

	.uleb128	DW_AT_name
	.uleb128	DW_FORM_strp
	.section	.debug_str
.Lname48:
	.string		"PR_PRPF"
	.section	.debug_info
	.long		.Lname48

	.section	.debug_abbrev
	.uleb128	DW_AT_decl_file
	.uleb128	DW_FORM_data1
	.section	.debug_info
	.byte		0	; no source file information

	.section	.debug_abbrev
	.uleb128	DW_AT_decl_line
	.uleb128	DW_FORM_data1
	.section	.debug_info
	.byte		0	; no source line information

	.section	.debug_abbrev
	.uleb128	DW_AT_type
	.uleb128	DW_FORM_ref4
	.section	.debug_info
	.long		.Luint8_t - .Lssinfo

	.section	.debug_abbrev
	.uleb128	DW_AT_external
	.uleb128	DW_FORM_flag
	.section	.debug_info
	.byte		1

	.section	.debug_abbrev
	.uleb128	DW_AT_location
	.uleb128	DW_FORM_block1
	.section	.debug_info
	.byte		5	; length of block
	.byte		DW_OP_addr
	.long		0x800000 + 0x0070 + 0x06

	.section	.debug_abbrev
	.uleb128	0
	.uleb128	0

;- - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
	;; DIE #49: variable SLEEP_CTRL
	.section	.debug_info
	.uleb128	49	; ref to abbrev 49
	.section	.debug_abbrev
	.uleb128	49
	.uleb128	DW_TAG_variable
	.byte		DW_CHILDREN_no

	.uleb128	DW_AT_name
	.uleb128	DW_FORM_strp
	.section	.debug_str
.Lname49:
	.string		"SLEEP_CTRL"
	.section	.debug_info
	.long		.Lname49

	.section	.debug_abbrev
	.uleb128	DW_AT_decl_file
	.uleb128	DW_FORM_data1
	.section	.debug_info
	.byte		0	; no source file information

	.section	.debug_abbrev
	.uleb128	DW_AT_decl_line
	.uleb128	DW_FORM_data1
	.section	.debug_info
	.byte		0	; no source line information

	.section	.debug_abbrev
	.uleb128	DW_AT_type
	.uleb128	DW_FORM_ref4
	.section	.debug_info
	.long		.Luint8_t - .Lssinfo

	.section	.debug_abbrev
	.uleb128	DW_AT_external
	.uleb128	DW_FORM_flag
	.section	.debug_info
	.byte		1

	.section	.debug_abbrev
	.uleb128	DW_AT_location
	.uleb128	DW_FORM_block1
	.section	.debug_info
	.byte		5	; length of block
	.byte		DW_OP_addr
	.long		0x800000 + 0x0048 + 0x00

	.section	.debug_abbrev
	.uleb128	0
	.uleb128	0

;- - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
	;; DIE #50: variable OSC_CTRL
	.section	.debug_info
	.uleb128	50	; ref to abbrev 50
	.section	.debug_abbrev
	.uleb128	50
	.uleb128	DW_TAG_variable
	.byte		DW_CHILDREN_no

	.uleb128	DW_AT_name
	.uleb128	DW_FORM_strp
	.section	.debug_str
.Lname50:
	.string		"OSC_CTRL"
	.section	.debug_info
	.long		.Lname50

	.section	.debug_abbrev
	.uleb128	DW_AT_decl_file
	.uleb128	DW_FORM_data1
	.section	.debug_info
	.byte		0	; no source file information

	.section	.debug_abbrev
	.uleb128	DW_AT_decl_line
	.uleb128	DW_FORM_data1
	.section	.debug_info
	.byte		0	; no source line information

	.section	.debug_abbrev
	.uleb128	DW_AT_type
	.uleb128	DW_FORM_ref4
	.section	.debug_info
	.long		.Luint8_t - .Lssinfo

	.section	.debug_abbrev
	.uleb128	DW_AT_external
	.uleb128	DW_FORM_flag
	.section	.debug_info
	.byte		1

	.section	.debug_abbrev
	.uleb128	DW_AT_location
	.uleb128	DW_FORM_block1
	.section	.debug_info
	.byte		5	; length of block
	.byte		DW_OP_addr
	.long		0x800000 + 0x0050 + 0x00

	.section	.debug_abbrev
	.uleb128	0
	.uleb128	0

;- - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
	;; DIE #51: variable OSC_STATUS
	.section	.debug_info
	.uleb128	51	; ref to abbrev 51
	.section	.debug_abbrev
	.uleb128	51
	.uleb128	DW_TAG_variable
	.byte		DW_CHILDREN_no

	.uleb128	DW_AT_name
	.uleb128	DW_FORM_strp
	.section	.debug_str
.Lname51:
	.string		"OSC_STATUS"
	.section	.debug_info
	.long		.Lname51

	.section	.debug_abbrev
	.uleb128	DW_AT_decl_file
	.uleb128	DW_FORM_data1
	.section	.debug_info
	.byte		0	; no source file information

	.section	.debug_abbrev
	.uleb128	DW_AT_decl_line
	.uleb128	DW_FORM_data1
	.section	.debug_info
	.byte		0	; no source line information

	.section	.debug_abbrev
	.uleb128	DW_AT_type
	.uleb128	DW_FORM_ref4
	.section	.debug_info
	.long		.Luint8_t - .Lssinfo

	.section	.debug_abbrev
	.uleb128	DW_AT_external
	.uleb128	DW_FORM_flag
	.section	.debug_info
	.byte		1

	.section	.debug_abbrev
	.uleb128	DW_AT_location
	.uleb128	DW_FORM_block1
	.section	.debug_info
	.byte		5	; length of block
	.byte		DW_OP_addr
	.long		0x800000 + 0x0050 + 0x01

	.section	.debug_abbrev
	.uleb128	0
	.uleb128	0

;- - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
	;; DIE #52: variable OSC_XOSCCTRL
	.section	.debug_info
	.uleb128	52	; ref to abbrev 52
	.section	.debug_abbrev
	.uleb128	52
	.uleb128	DW_TAG_variable
	.byte		DW_CHILDREN_no

	.uleb128	DW_AT_name
	.uleb128	DW_FORM_strp
	.section	.debug_str
.Lname52:
	.string		"OSC_XOSCCTRL"
	.section	.debug_info
	.long		.Lname52

	.section	.debug_abbrev
	.uleb128	DW_AT_decl_file
	.uleb128	DW_FORM_data1
	.section	.debug_info
	.byte		0	; no source file information

	.section	.debug_abbrev
	.uleb128	DW_AT_decl_line
	.uleb128	DW_FORM_data1
	.section	.debug_info
	.byte		0	; no source line information

	.section	.debug_abbrev
	.uleb128	DW_AT_type
	.uleb128	DW_FORM_ref4
	.section	.debug_info
	.long		.Luint8_t - .Lssinfo

	.section	.debug_abbrev
	.uleb128	DW_AT_external
	.uleb128	DW_FORM_flag
	.section	.debug_info
	.byte		1

	.section	.debug_abbrev
	.uleb128	DW_AT_location
	.uleb128	DW_FORM_block1
	.section	.debug_info
	.byte		5	; length of block
	.byte		DW_OP_addr
	.long		0x800000 + 0x0050 + 0x02

	.section	.debug_abbrev
	.uleb128	0
	.uleb128	0

;- - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
	;; DIE #53: variable OSC_XOSCFAIL
	.section	.debug_info
	.uleb128	53	; ref to abbrev 53
	.section	.debug_abbrev
	.uleb128	53
	.uleb128	DW_TAG_variable
	.byte		DW_CHILDREN_no

	.uleb128	DW_AT_name
	.uleb128	DW_FORM_strp
	.section	.debug_str
.Lname53:
	.string		"OSC_XOSCFAIL"
	.section	.debug_info
	.long		.Lname53

	.section	.debug_abbrev
	.uleb128	DW_AT_decl_file
	.uleb128	DW_FORM_data1
	.section	.debug_info
	.byte		0	; no source file information

	.section	.debug_abbrev
	.uleb128	DW_AT_decl_line
	.uleb128	DW_FORM_data1
	.section	.debug_info
	.byte		0	; no source line information

	.section	.debug_abbrev
	.uleb128	DW_AT_type
	.uleb128	DW_FORM_ref4
	.section	.debug_info
	.long		.Luint8_t - .Lssinfo

	.section	.debug_abbrev
	.uleb128	DW_AT_external
	.uleb128	DW_FORM_flag
	.section	.debug_info
	.byte		1

	.section	.debug_abbrev
	.uleb128	DW_AT_location
	.uleb128	DW_FORM_block1
	.section	.debug_info
	.byte		5	; length of block
	.byte		DW_OP_addr
	.long		0x800000 + 0x0050 + 0x03

	.section	.debug_abbrev
	.uleb128	0
	.uleb128	0

;- - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
	;; DIE #54: variable OSC_RC32KCAL
	.section	.debug_info
	.uleb128	54	; ref to abbrev 54
	.section	.debug_abbrev
	.uleb128	54
	.uleb128	DW_TAG_variable
	.byte		DW_CHILDREN_no

	.uleb128	DW_AT_name
	.uleb128	DW_FORM_strp
	.section	.debug_str
.Lname54:
	.string		"OSC_RC32KCAL"
	.section	.debug_info
	.long		.Lname54

	.section	.debug_abbrev
	.uleb128	DW_AT_decl_file
	.uleb128	DW_FORM_data1
	.section	.debug_info
	.byte		0	; no source file information

	.section	.debug_abbrev
	.uleb128	DW_AT_decl_line
	.uleb128	DW_FORM_data1
	.section	.debug_info
	.byte		0	; no source line information

	.section	.debug_abbrev
	.uleb128	DW_AT_type
	.uleb128	DW_FORM_ref4
	.section	.debug_info
	.long		.Luint8_t - .Lssinfo

	.section	.debug_abbrev
	.uleb128	DW_AT_external
	.uleb128	DW_FORM_flag
	.section	.debug_info
	.byte		1

	.section	.debug_abbrev
	.uleb128	DW_AT_location
	.uleb128	DW_FORM_block1
	.section	.debug_info
	.byte		5	; length of block
	.byte		DW_OP_addr
	.long		0x800000 + 0x0050 + 0x04

	.section	.debug_abbrev
	.uleb128	0
	.uleb128	0

;- - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
	;; DIE #55: variable OSC_PLLCTRL
	.section	.debug_info
	.uleb128	55	; ref to abbrev 55
	.section	.debug_abbrev
	.uleb128	55
	.uleb128	DW_TAG_variable
	.byte		DW_CHILDREN_no

	.uleb128	DW_AT_name
	.uleb128	DW_FORM_strp
	.section	.debug_str
.Lname55:
	.string		"OSC_PLLCTRL"
	.section	.debug_info
	.long		.Lname55

	.section	.debug_abbrev
	.uleb128	DW_AT_decl_file
	.uleb128	DW_FORM_data1
	.section	.debug_info
	.byte		0	; no source file information

	.section	.debug_abbrev
	.uleb128	DW_AT_decl_line
	.uleb128	DW_FORM_data1
	.section	.debug_info
	.byte		0	; no source line information

	.section	.debug_abbrev
	.uleb128	DW_AT_type
	.uleb128	DW_FORM_ref4
	.section	.debug_info
	.long		.Luint8_t - .Lssinfo

	.section	.debug_abbrev
	.uleb128	DW_AT_external
	.uleb128	DW_FORM_flag
	.section	.debug_info
	.byte		1

	.section	.debug_abbrev
	.uleb128	DW_AT_location
	.uleb128	DW_FORM_block1
	.section	.debug_info
	.byte		5	; length of block
	.byte		DW_OP_addr
	.long		0x800000 + 0x0050 + 0x05

	.section	.debug_abbrev
	.uleb128	0
	.uleb128	0

;- - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
	;; DIE #56: variable OSC_DFLLCTRL
	.section	.debug_info
	.uleb128	56	; ref to abbrev 56
	.section	.debug_abbrev
	.uleb128	56
	.uleb128	DW_TAG_variable
	.byte		DW_CHILDREN_no

	.uleb128	DW_AT_name
	.uleb128	DW_FORM_strp
	.section	.debug_str
.Lname56:
	.string		"OSC_DFLLCTRL"
	.section	.debug_info
	.long		.Lname56

	.section	.debug_abbrev
	.uleb128	DW_AT_decl_file
	.uleb128	DW_FORM_data1
	.section	.debug_info
	.byte		0	; no source file information

	.section	.debug_abbrev
	.uleb128	DW_AT_decl_line
	.uleb128	DW_FORM_data1
	.section	.debug_info
	.byte		0	; no source line information

	.section	.debug_abbrev
	.uleb128	DW_AT_type
	.uleb128	DW_FORM_ref4
	.section	.debug_info
	.long		.Luint8_t - .Lssinfo

	.section	.debug_abbrev
	.uleb128	DW_AT_external
	.uleb128	DW_FORM_flag
	.section	.debug_info
	.byte		1

	.section	.debug_abbrev
	.uleb128	DW_AT_location
	.uleb128	DW_FORM_block1
	.section	.debug_info
	.byte		5	; length of block
	.byte		DW_OP_addr
	.long		0x800000 + 0x0050 + 0x06

	.section	.debug_abbrev
	.uleb128	0
	.uleb128	0

;- - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
	;; DIE #57: variable DFLLRC32M_CTRL
	.section	.debug_info
	.uleb128	57	; ref to abbrev 57
	.section	.debug_abbrev
	.uleb128	57
	.uleb128	DW_TAG_variable
	.byte		DW_CHILDREN_no

	.uleb128	DW_AT_name
	.uleb128	DW_FORM_strp
	.section	.debug_str
.Lname57:
	.string		"DFLLRC32M_CTRL"
	.section	.debug_info
	.long		.Lname57

	.section	.debug_abbrev
	.uleb128	DW_AT_decl_file
	.uleb128	DW_FORM_data1
	.section	.debug_info
	.byte		0	; no source file information

	.section	.debug_abbrev
	.uleb128	DW_AT_decl_line
	.uleb128	DW_FORM_data1
	.section	.debug_info
	.byte		0	; no source line information

	.section	.debug_abbrev
	.uleb128	DW_AT_type
	.uleb128	DW_FORM_ref4
	.section	.debug_info
	.long		.Luint8_t - .Lssinfo

	.section	.debug_abbrev
	.uleb128	DW_AT_external
	.uleb128	DW_FORM_flag
	.section	.debug_info
	.byte		1

	.section	.debug_abbrev
	.uleb128	DW_AT_location
	.uleb128	DW_FORM_block1
	.section	.debug_info
	.byte		5	; length of block
	.byte		DW_OP_addr
	.long		0x800000 + 0x0060 + 0x00

	.section	.debug_abbrev
	.uleb128	0
	.uleb128	0

;- - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
	;; DIE #58: variable DFLLRC32M_CALA
	.section	.debug_info
	.uleb128	58	; ref to abbrev 58
	.section	.debug_abbrev
	.uleb128	58
	.uleb128	DW_TAG_variable
	.byte		DW_CHILDREN_no

	.uleb128	DW_AT_name
	.uleb128	DW_FORM_strp
	.section	.debug_str
.Lname58:
	.string		"DFLLRC32M_CALA"
	.section	.debug_info
	.long		.Lname58

	.section	.debug_abbrev
	.uleb128	DW_AT_decl_file
	.uleb128	DW_FORM_data1
	.section	.debug_info
	.byte		0	; no source file information

	.section	.debug_abbrev
	.uleb128	DW_AT_decl_line
	.uleb128	DW_FORM_data1
	.section	.debug_info
	.byte		0	; no source line information

	.section	.debug_abbrev
	.uleb128	DW_AT_type
	.uleb128	DW_FORM_ref4
	.section	.debug_info
	.long		.Luint8_t - .Lssinfo

	.section	.debug_abbrev
	.uleb128	DW_AT_external
	.uleb128	DW_FORM_flag
	.section	.debug_info
	.byte		1

	.section	.debug_abbrev
	.uleb128	DW_AT_location
	.uleb128	DW_FORM_block1
	.section	.debug_info
	.byte		5	; length of block
	.byte		DW_OP_addr
	.long		0x800000 + 0x0060 + 0x02

	.section	.debug_abbrev
	.uleb128	0
	.uleb128	0

;- - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
	;; DIE #59: variable DFLLRC32M_CALB
	.section	.debug_info
	.uleb128	59	; ref to abbrev 59
	.section	.debug_abbrev
	.uleb128	59
	.uleb128	DW_TAG_variable
	.byte		DW_CHILDREN_no

	.uleb128	DW_AT_name
	.uleb128	DW_FORM_strp
	.section	.debug_str
.Lname59:
	.string		"DFLLRC32M_CALB"
	.section	.debug_info
	.long		.Lname59

	.section	.debug_abbrev
	.uleb128	DW_AT_decl_file
	.uleb128	DW_FORM_data1
	.section	.debug_info
	.byte		0	; no source file information

	.section	.debug_abbrev
	.uleb128	DW_AT_decl_line
	.uleb128	DW_FORM_data1
	.section	.debug_info
	.byte		0	; no source line information

	.section	.debug_abbrev
	.uleb128	DW_AT_type
	.uleb128	DW_FORM_ref4
	.section	.debug_info
	.long		.Luint8_t - .Lssinfo

	.section	.debug_abbrev
	.uleb128	DW_AT_external
	.uleb128	DW_FORM_flag
	.section	.debug_info
	.byte		1

	.section	.debug_abbrev
	.uleb128	DW_AT_location
	.uleb128	DW_FORM_block1
	.section	.debug_info
	.byte		5	; length of block
	.byte		DW_OP_addr
	.long		0x800000 + 0x0060 + 0x03

	.section	.debug_abbrev
	.uleb128	0
	.uleb128	0

;- - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
	;; DIE #60: variable DFLLRC32M_COMP0
	.section	.debug_info
	.uleb128	60	; ref to abbrev 60
	.section	.debug_abbrev
	.uleb128	60
	.uleb128	DW_TAG_variable
	.byte		DW_CHILDREN_no

	.uleb128	DW_AT_name
	.uleb128	DW_FORM_strp
	.section	.debug_str
.Lname60:
	.string		"DFLLRC32M_COMP0"
	.section	.debug_info
	.long		.Lname60

	.section	.debug_abbrev
	.uleb128	DW_AT_decl_file
	.uleb128	DW_FORM_data1
	.section	.debug_info
	.byte		0	; no source file information

	.section	.debug_abbrev
	.uleb128	DW_AT_decl_line
	.uleb128	DW_FORM_data1
	.section	.debug_info
	.byte		0	; no source line information

	.section	.debug_abbrev
	.uleb128	DW_AT_type
	.uleb128	DW_FORM_ref4
	.section	.debug_info
	.long		.Luint8_t - .Lssinfo

	.section	.debug_abbrev
	.uleb128	DW_AT_external
	.uleb128	DW_FORM_flag
	.section	.debug_info
	.byte		1

	.section	.debug_abbrev
	.uleb128	DW_AT_location
	.uleb128	DW_FORM_block1
	.section	.debug_info
	.byte		5	; length of block
	.byte		DW_OP_addr
	.long		0x800000 + 0x0060 + 0x04

	.section	.debug_abbrev
	.uleb128	0
	.uleb128	0

;- - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
	;; DIE #61: variable DFLLRC32M_COMP1
	.section	.debug_info
	.uleb128	61	; ref to abbrev 61
	.section	.debug_abbrev
	.uleb128	61
	.uleb128	DW_TAG_variable
	.byte		DW_CHILDREN_no

	.uleb128	DW_AT_name
	.uleb128	DW_FORM_strp
	.section	.debug_str
.Lname61:
	.string		"DFLLRC32M_COMP1"
	.section	.debug_info
	.long		.Lname61

	.section	.debug_abbrev
	.uleb128	DW_AT_decl_file
	.uleb128	DW_FORM_data1
	.section	.debug_info
	.byte		0	; no source file information

	.section	.debug_abbrev
	.uleb128	DW_AT_decl_line
	.uleb128	DW_FORM_data1
	.section	.debug_info
	.byte		0	; no source line information

	.section	.debug_abbrev
	.uleb128	DW_AT_type
	.uleb128	DW_FORM_ref4
	.section	.debug_info
	.long		.Luint8_t - .Lssinfo

	.section	.debug_abbrev
	.uleb128	DW_AT_external
	.uleb128	DW_FORM_flag
	.section	.debug_info
	.byte		1

	.section	.debug_abbrev
	.uleb128	DW_AT_location
	.uleb128	DW_FORM_block1
	.section	.debug_info
	.byte		5	; length of block
	.byte		DW_OP_addr
	.long		0x800000 + 0x0060 + 0x05

	.section	.debug_abbrev
	.uleb128	0
	.uleb128	0

;- - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
	;; DIE #62: variable DFLLRC32M_COMP2
	.section	.debug_info
	.uleb128	62	; ref to abbrev 62
	.section	.debug_abbrev
	.uleb128	62
	.uleb128	DW_TAG_variable
	.byte		DW_CHILDREN_no

	.uleb128	DW_AT_name
	.uleb128	DW_FORM_strp
	.section	.debug_str
.Lname62:
	.string		"DFLLRC32M_COMP2"
	.section	.debug_info
	.long		.Lname62

	.section	.debug_abbrev
	.uleb128	DW_AT_decl_file
	.uleb128	DW_FORM_data1
	.section	.debug_info
	.byte		0	; no source file information

	.section	.debug_abbrev
	.uleb128	DW_AT_decl_line
	.uleb128	DW_FORM_data1
	.section	.debug_info
	.byte		0	; no source line information

	.section	.debug_abbrev
	.uleb128	DW_AT_type
	.uleb128	DW_FORM_ref4
	.section	.debug_info
	.long		.Luint8_t - .Lssinfo

	.section	.debug_abbrev
	.uleb128	DW_AT_external
	.uleb128	DW_FORM_flag
	.section	.debug_info
	.byte		1

	.section	.debug_abbrev
	.uleb128	DW_AT_location
	.uleb128	DW_FORM_block1
	.section	.debug_info
	.byte		5	; length of block
	.byte		DW_OP_addr
	.long		0x800000 + 0x0060 + 0x06

	.section	.debug_abbrev
	.uleb128	0
	.uleb128	0

;- - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
	;; DIE #63: variable DFLLRC2M_CTRL
	.section	.debug_info
	.uleb128	63	; ref to abbrev 63
	.section	.debug_abbrev
	.uleb128	63
	.uleb128	DW_TAG_variable
	.byte		DW_CHILDREN_no

	.uleb128	DW_AT_name
	.uleb128	DW_FORM_strp
	.section	.debug_str
.Lname63:
	.string		"DFLLRC2M_CTRL"
	.section	.debug_info
	.long		.Lname63

	.section	.debug_abbrev
	.uleb128	DW_AT_decl_file
	.uleb128	DW_FORM_data1
	.section	.debug_info
	.byte		0	; no source file information

	.section	.debug_abbrev
	.uleb128	DW_AT_decl_line
	.uleb128	DW_FORM_data1
	.section	.debug_info
	.byte		0	; no source line information

	.section	.debug_abbrev
	.uleb128	DW_AT_type
	.uleb128	DW_FORM_ref4
	.section	.debug_info
	.long		.Luint8_t - .Lssinfo

	.section	.debug_abbrev
	.uleb128	DW_AT_external
	.uleb128	DW_FORM_flag
	.section	.debug_info
	.byte		1

	.section	.debug_abbrev
	.uleb128	DW_AT_location
	.uleb128	DW_FORM_block1
	.section	.debug_info
	.byte		5	; length of block
	.byte		DW_OP_addr
	.long		0x800000 + 0x0068 + 0x00

	.section	.debug_abbrev
	.uleb128	0
	.uleb128	0

;- - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
	;; DIE #64: variable DFLLRC2M_CALA
	.section	.debug_info
	.uleb128	64	; ref to abbrev 64
	.section	.debug_abbrev
	.uleb128	64
	.uleb128	DW_TAG_variable
	.byte		DW_CHILDREN_no

	.uleb128	DW_AT_name
	.uleb128	DW_FORM_strp
	.section	.debug_str
.Lname64:
	.string		"DFLLRC2M_CALA"
	.section	.debug_info
	.long		.Lname64

	.section	.debug_abbrev
	.uleb128	DW_AT_decl_file
	.uleb128	DW_FORM_data1
	.section	.debug_info
	.byte		0	; no source file information

	.section	.debug_abbrev
	.uleb128	DW_AT_decl_line
	.uleb128	DW_FORM_data1
	.section	.debug_info
	.byte		0	; no source line information

	.section	.debug_abbrev
	.uleb128	DW_AT_type
	.uleb128	DW_FORM_ref4
	.section	.debug_info
	.long		.Luint8_t - .Lssinfo

	.section	.debug_abbrev
	.uleb128	DW_AT_external
	.uleb128	DW_FORM_flag
	.section	.debug_info
	.byte		1

	.section	.debug_abbrev
	.uleb128	DW_AT_location
	.uleb128	DW_FORM_block1
	.section	.debug_info
	.byte		5	; length of block
	.byte		DW_OP_addr
	.long		0x800000 + 0x0068 + 0x02

	.section	.debug_abbrev
	.uleb128	0
	.uleb128	0

;- - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
	;; DIE #65: variable DFLLRC2M_CALB
	.section	.debug_info
	.uleb128	65	; ref to abbrev 65
	.section	.debug_abbrev
	.uleb128	65
	.uleb128	DW_TAG_variable
	.byte		DW_CHILDREN_no

	.uleb128	DW_AT_name
	.uleb128	DW_FORM_strp
	.section	.debug_str
.Lname65:
	.string		"DFLLRC2M_CALB"
	.section	.debug_info
	.long		.Lname65

	.section	.debug_abbrev
	.uleb128	DW_AT_decl_file
	.uleb128	DW_FORM_data1
	.section	.debug_info
	.byte		0	; no source file information

	.section	.debug_abbrev
	.uleb128	DW_AT_decl_line
	.uleb128	DW_FORM_data1
	.section	.debug_info
	.byte		0	; no source line information

	.section	.debug_abbrev
	.uleb128	DW_AT_type
	.uleb128	DW_FORM_ref4
	.section	.debug_info
	.long		.Luint8_t - .Lssinfo

	.section	.debug_abbrev
	.uleb128	DW_AT_external
	.uleb128	DW_FORM_flag
	.section	.debug_info
	.byte		1

	.section	.debug_abbrev
	.uleb128	DW_AT_location
	.uleb128	DW_FORM_block1
	.section	.debug_info
	.byte		5	; length of block
	.byte		DW_OP_addr
	.long		0x800000 + 0x0068 + 0x03

	.section	.debug_abbrev
	.uleb128	0
	.uleb128	0

;- - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
	;; DIE #66: variable DFLLRC2M_COMP0
	.section	.debug_info
	.uleb128	66	; ref to abbrev 66
	.section	.debug_abbrev
	.uleb128	66
	.uleb128	DW_TAG_variable
	.byte		DW_CHILDREN_no

	.uleb128	DW_AT_name
	.uleb128	DW_FORM_strp
	.section	.debug_str
.Lname66:
	.string		"DFLLRC2M_COMP0"
	.section	.debug_info
	.long		.Lname66

	.section	.debug_abbrev
	.uleb128	DW_AT_decl_file
	.uleb128	DW_FORM_data1
	.section	.debug_info
	.byte		0	; no source file information

	.section	.debug_abbrev
	.uleb128	DW_AT_decl_line
	.uleb128	DW_FORM_data1
	.section	.debug_info
	.byte		0	; no source line information

	.section	.debug_abbrev
	.uleb128	DW_AT_type
	.uleb128	DW_FORM_ref4
	.section	.debug_info
	.long		.Luint8_t - .Lssinfo

	.section	.debug_abbrev
	.uleb128	DW_AT_external
	.uleb128	DW_FORM_flag
	.section	.debug_info
	.byte		1

	.section	.debug_abbrev
	.uleb128	DW_AT_location
	.uleb128	DW_FORM_block1
	.section	.debug_info
	.byte		5	; length of block
	.byte		DW_OP_addr
	.long		0x800000 + 0x0068 + 0x04

	.section	.debug_abbrev
	.uleb128	0
	.uleb128	0

;- - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
	;; DIE #67: variable DFLLRC2M_COMP1
	.section	.debug_info
	.uleb128	67	; ref to abbrev 67
	.section	.debug_abbrev
	.uleb128	67
	.uleb128	DW_TAG_variable
	.byte		DW_CHILDREN_no

	.uleb128	DW_AT_name
	.uleb128	DW_FORM_strp
	.section	.debug_str
.Lname67:
	.string		"DFLLRC2M_COMP1"
	.section	.debug_info
	.long		.Lname67

	.section	.debug_abbrev
	.uleb128	DW_AT_decl_file
	.uleb128	DW_FORM_data1
	.section	.debug_info
	.byte		0	; no source file information

	.section	.debug_abbrev
	.uleb128	DW_AT_decl_line
	.uleb128	DW_FORM_data1
	.section	.debug_info
	.byte		0	; no source line information

	.section	.debug_abbrev
	.uleb128	DW_AT_type
	.uleb128	DW_FORM_ref4
	.section	.debug_info
	.long		.Luint8_t - .Lssinfo

	.section	.debug_abbrev
	.uleb128	DW_AT_external
	.uleb128	DW_FORM_flag
	.section	.debug_info
	.byte		1

	.section	.debug_abbrev
	.uleb128	DW_AT_location
	.uleb128	DW_FORM_block1
	.section	.debug_info
	.byte		5	; length of block
	.byte		DW_OP_addr
	.long		0x800000 + 0x0068 + 0x05

	.section	.debug_abbrev
	.uleb128	0
	.uleb128	0

;- - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
	;; DIE #68: variable DFLLRC2M_COMP2
	.section	.debug_info
	.uleb128	68	; ref to abbrev 68
	.section	.debug_abbrev
	.uleb128	68
	.uleb128	DW_TAG_variable
	.byte		DW_CHILDREN_no

	.uleb128	DW_AT_name
	.uleb128	DW_FORM_strp
	.section	.debug_str
.Lname68:
	.string		"DFLLRC2M_COMP2"
	.section	.debug_info
	.long		.Lname68

	.section	.debug_abbrev
	.uleb128	DW_AT_decl_file
	.uleb128	DW_FORM_data1
	.section	.debug_info
	.byte		0	; no source file information

	.section	.debug_abbrev
	.uleb128	DW_AT_decl_line
	.uleb128	DW_FORM_data1
	.section	.debug_info
	.byte		0	; no source line information

	.section	.debug_abbrev
	.uleb128	DW_AT_type
	.uleb128	DW_FORM_ref4
	.section	.debug_info
	.long		.Luint8_t - .Lssinfo

	.section	.debug_abbrev
	.uleb128	DW_AT_external
	.uleb128	DW_FORM_flag
	.section	.debug_info
	.byte		1

	.section	.debug_abbrev
	.uleb128	DW_AT_location
	.uleb128	DW_FORM_block1
	.section	.debug_info
	.byte		5	; length of block
	.byte		DW_OP_addr
	.long		0x800000 + 0x0068 + 0x06

	.section	.debug_abbrev
	.uleb128	0
	.uleb128	0

;- - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
	;; DIE #69: variable RST_STATUS
	.section	.debug_info
	.uleb128	69	; ref to abbrev 69
	.section	.debug_abbrev
	.uleb128	69
	.uleb128	DW_TAG_variable
	.byte		DW_CHILDREN_no

	.uleb128	DW_AT_name
	.uleb128	DW_FORM_strp
	.section	.debug_str
.Lname69:
	.string		"RST_STATUS"
	.section	.debug_info
	.long		.Lname69

	.section	.debug_abbrev
	.uleb128	DW_AT_decl_file
	.uleb128	DW_FORM_data1
	.section	.debug_info
	.byte		0	; no source file information

	.section	.debug_abbrev
	.uleb128	DW_AT_decl_line
	.uleb128	DW_FORM_data1
	.section	.debug_info
	.byte		0	; no source line information

	.section	.debug_abbrev
	.uleb128	DW_AT_type
	.uleb128	DW_FORM_ref4
	.section	.debug_info
	.long		.Luint8_t - .Lssinfo

	.section	.debug_abbrev
	.uleb128	DW_AT_external
	.uleb128	DW_FORM_flag
	.section	.debug_info
	.byte		1

	.section	.debug_abbrev
	.uleb128	DW_AT_location
	.uleb128	DW_FORM_block1
	.section	.debug_info
	.byte		5	; length of block
	.byte		DW_OP_addr
	.long		0x800000 + 0x0078 + 0x00

	.section	.debug_abbrev
	.uleb128	0
	.uleb128	0

;- - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
	;; DIE #70: variable RST_CTRL
	.section	.debug_info
	.uleb128	70	; ref to abbrev 70
	.section	.debug_abbrev
	.uleb128	70
	.uleb128	DW_TAG_variable
	.byte		DW_CHILDREN_no

	.uleb128	DW_AT_name
	.uleb128	DW_FORM_strp
	.section	.debug_str
.Lname70:
	.string		"RST_CTRL"
	.section	.debug_info
	.long		.Lname70

	.section	.debug_abbrev
	.uleb128	DW_AT_decl_file
	.uleb128	DW_FORM_data1
	.section	.debug_info
	.byte		0	; no source file information

	.section	.debug_abbrev
	.uleb128	DW_AT_decl_line
	.uleb128	DW_FORM_data1
	.section	.debug_info
	.byte		0	; no source line information

	.section	.debug_abbrev
	.uleb128	DW_AT_type
	.uleb128	DW_FORM_ref4
	.section	.debug_info
	.long		.Luint8_t - .Lssinfo

	.section	.debug_abbrev
	.uleb128	DW_AT_external
	.uleb128	DW_FORM_flag
	.section	.debug_info
	.byte		1

	.section	.debug_abbrev
	.uleb128	DW_AT_location
	.uleb128	DW_FORM_block1
	.section	.debug_info
	.byte		5	; length of block
	.byte		DW_OP_addr
	.long		0x800000 + 0x0078 + 0x01

	.section	.debug_abbrev
	.uleb128	0
	.uleb128	0

;- - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
	;; DIE #71: variable WDT_CTRL
	.section	.debug_info
	.uleb128	71	; ref to abbrev 71
	.section	.debug_abbrev
	.uleb128	71
	.uleb128	DW_TAG_variable
	.byte		DW_CHILDREN_no

	.uleb128	DW_AT_name
	.uleb128	DW_FORM_strp
	.section	.debug_str
.Lname71:
	.string		"WDT_CTRL"
	.section	.debug_info
	.long		.Lname71

	.section	.debug_abbrev
	.uleb128	DW_AT_decl_file
	.uleb128	DW_FORM_data1
	.section	.debug_info
	.byte		0	; no source file information

	.section	.debug_abbrev
	.uleb128	DW_AT_decl_line
	.uleb128	DW_FORM_data1
	.section	.debug_info
	.byte		0	; no source line information

	.section	.debug_abbrev
	.uleb128	DW_AT_type
	.uleb128	DW_FORM_ref4
	.section	.debug_info
	.long		.Luint8_t - .Lssinfo

	.section	.debug_abbrev
	.uleb128	DW_AT_external
	.uleb128	DW_FORM_flag
	.section	.debug_info
	.byte		1

	.section	.debug_abbrev
	.uleb128	DW_AT_location
	.uleb128	DW_FORM_block1
	.section	.debug_info
	.byte		5	; length of block
	.byte		DW_OP_addr
	.long		0x800000 + 0x0080 + 0x00

	.section	.debug_abbrev
	.uleb128	0
	.uleb128	0

;- - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
	;; DIE #72: variable WDT_WINCTRL
	.section	.debug_info
	.uleb128	72	; ref to abbrev 72
	.section	.debug_abbrev
	.uleb128	72
	.uleb128	DW_TAG_variable
	.byte		DW_CHILDREN_no

	.uleb128	DW_AT_name
	.uleb128	DW_FORM_strp
	.section	.debug_str
.Lname72:
	.string		"WDT_WINCTRL"
	.section	.debug_info
	.long		.Lname72

	.section	.debug_abbrev
	.uleb128	DW_AT_decl_file
	.uleb128	DW_FORM_data1
	.section	.debug_info
	.byte		0	; no source file information

	.section	.debug_abbrev
	.uleb128	DW_AT_decl_line
	.uleb128	DW_FORM_data1
	.section	.debug_info
	.byte		0	; no source line information

	.section	.debug_abbrev
	.uleb128	DW_AT_type
	.uleb128	DW_FORM_ref4
	.section	.debug_info
	.long		.Luint8_t - .Lssinfo

	.section	.debug_abbrev
	.uleb128	DW_AT_external
	.uleb128	DW_FORM_flag
	.section	.debug_info
	.byte		1

	.section	.debug_abbrev
	.uleb128	DW_AT_location
	.uleb128	DW_FORM_block1
	.section	.debug_info
	.byte		5	; length of block
	.byte		DW_OP_addr
	.long		0x800000 + 0x0080 + 0x01

	.section	.debug_abbrev
	.uleb128	0
	.uleb128	0

;- - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
	;; DIE #73: variable WDT_STATUS
	.section	.debug_info
	.uleb128	73	; ref to abbrev 73
	.section	.debug_abbrev
	.uleb128	73
	.uleb128	DW_TAG_variable
	.byte		DW_CHILDREN_no

	.uleb128	DW_AT_name
	.uleb128	DW_FORM_strp
	.section	.debug_str
.Lname73:
	.string		"WDT_STATUS"
	.section	.debug_info
	.long		.Lname73

	.section	.debug_abbrev
	.uleb128	DW_AT_decl_file
	.uleb128	DW_FORM_data1
	.section	.debug_info
	.byte		0	; no source file information

	.section	.debug_abbrev
	.uleb128	DW_AT_decl_line
	.uleb128	DW_FORM_data1
	.section	.debug_info
	.byte		0	; no source line information

	.section	.debug_abbrev
	.uleb128	DW_AT_type
	.uleb128	DW_FORM_ref4
	.section	.debug_info
	.long		.Luint8_t - .Lssinfo

	.section	.debug_abbrev
	.uleb128	DW_AT_external
	.uleb128	DW_FORM_flag
	.section	.debug_info
	.byte		1

	.section	.debug_abbrev
	.uleb128	DW_AT_location
	.uleb128	DW_FORM_block1
	.section	.debug_info
	.byte		5	; length of block
	.byte		DW_OP_addr
	.long		0x800000 + 0x0080 + 0x02

	.section	.debug_abbrev
	.uleb128	0
	.uleb128	0

;- - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
	;; DIE #74: variable MCU_DEVID0
	.section	.debug_info
	.uleb128	74	; ref to abbrev 74
	.section	.debug_abbrev
	.uleb128	74
	.uleb128	DW_TAG_variable
	.byte		DW_CHILDREN_no

	.uleb128	DW_AT_name
	.uleb128	DW_FORM_strp
	.section	.debug_str
.Lname74:
	.string		"MCU_DEVID0"
	.section	.debug_info
	.long		.Lname74

	.section	.debug_abbrev
	.uleb128	DW_AT_decl_file
	.uleb128	DW_FORM_data1
	.section	.debug_info
	.byte		0	; no source file information

	.section	.debug_abbrev
	.uleb128	DW_AT_decl_line
	.uleb128	DW_FORM_data1
	.section	.debug_info
	.byte		0	; no source line information

	.section	.debug_abbrev
	.uleb128	DW_AT_type
	.uleb128	DW_FORM_ref4
	.section	.debug_info
	.long		.Luint8_t - .Lssinfo

	.section	.debug_abbrev
	.uleb128	DW_AT_external
	.uleb128	DW_FORM_flag
	.section	.debug_info
	.byte		1

	.section	.debug_abbrev
	.uleb128	DW_AT_location
	.uleb128	DW_FORM_block1
	.section	.debug_info
	.byte		5	; length of block
	.byte		DW_OP_addr
	.long		0x800000 + 0x0090 + 0x00

	.section	.debug_abbrev
	.uleb128	0
	.uleb128	0

;- - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
	;; DIE #75: variable MCU_DEVID1
	.section	.debug_info
	.uleb128	75	; ref to abbrev 75
	.section	.debug_abbrev
	.uleb128	75
	.uleb128	DW_TAG_variable
	.byte		DW_CHILDREN_no

	.uleb128	DW_AT_name
	.uleb128	DW_FORM_strp
	.section	.debug_str
.Lname75:
	.string		"MCU_DEVID1"
	.section	.debug_info
	.long		.Lname75

	.section	.debug_abbrev
	.uleb128	DW_AT_decl_file
	.uleb128	DW_FORM_data1
	.section	.debug_info
	.byte		0	; no source file information

	.section	.debug_abbrev
	.uleb128	DW_AT_decl_line
	.uleb128	DW_FORM_data1
	.section	.debug_info
	.byte		0	; no source line information

	.section	.debug_abbrev
	.uleb128	DW_AT_type
	.uleb128	DW_FORM_ref4
	.section	.debug_info
	.long		.Luint8_t - .Lssinfo

	.section	.debug_abbrev
	.uleb128	DW_AT_external
	.uleb128	DW_FORM_flag
	.section	.debug_info
	.byte		1

	.section	.debug_abbrev
	.uleb128	DW_AT_location
	.uleb128	DW_FORM_block1
	.section	.debug_info
	.byte		5	; length of block
	.byte		DW_OP_addr
	.long		0x800000 + 0x0090 + 0x01

	.section	.debug_abbrev
	.uleb128	0
	.uleb128	0

;- - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
	;; DIE #76: variable MCU_DEVID2
	.section	.debug_info
	.uleb128	76	; ref to abbrev 76
	.section	.debug_abbrev
	.uleb128	76
	.uleb128	DW_TAG_variable
	.byte		DW_CHILDREN_no

	.uleb128	DW_AT_name
	.uleb128	DW_FORM_strp
	.section	.debug_str
.Lname76:
	.string		"MCU_DEVID2"
	.section	.debug_info
	.long		.Lname76

	.section	.debug_abbrev
	.uleb128	DW_AT_decl_file
	.uleb128	DW_FORM_data1
	.section	.debug_info
	.byte		0	; no source file information

	.section	.debug_abbrev
	.uleb128	DW_AT_decl_line
	.uleb128	DW_FORM_data1
	.section	.debug_info
	.byte		0	; no source line information

	.section	.debug_abbrev
	.uleb128	DW_AT_type
	.uleb128	DW_FORM_ref4
	.section	.debug_info
	.long		.Luint8_t - .Lssinfo

	.section	.debug_abbrev
	.uleb128	DW_AT_external
	.uleb128	DW_FORM_flag
	.section	.debug_info
	.byte		1

	.section	.debug_abbrev
	.uleb128	DW_AT_location
	.uleb128	DW_FORM_block1
	.section	.debug_info
	.byte		5	; length of block
	.byte		DW_OP_addr
	.long		0x800000 + 0x0090 + 0x02

	.section	.debug_abbrev
	.uleb128	0
	.uleb128	0

;- - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
	;; DIE #77: variable MCU_REVID
	.section	.debug_info
	.uleb128	77	; ref to abbrev 77
	.section	.debug_abbrev
	.uleb128	77
	.uleb128	DW_TAG_variable
	.byte		DW_CHILDREN_no

	.uleb128	DW_AT_name
	.uleb128	DW_FORM_strp
	.section	.debug_str
.Lname77:
	.string		"MCU_REVID"
	.section	.debug_info
	.long		.Lname77

	.section	.debug_abbrev
	.uleb128	DW_AT_decl_file
	.uleb128	DW_FORM_data1
	.section	.debug_info
	.byte		0	; no source file information

	.section	.debug_abbrev
	.uleb128	DW_AT_decl_line
	.uleb128	DW_FORM_data1
	.section	.debug_info
	.byte		0	; no source line information

	.section	.debug_abbrev
	.uleb128	DW_AT_type
	.uleb128	DW_FORM_ref4
	.section	.debug_info
	.long		.Luint8_t - .Lssinfo

	.section	.debug_abbrev
	.uleb128	DW_AT_external
	.uleb128	DW_FORM_flag
	.section	.debug_info
	.byte		1

	.section	.debug_abbrev
	.uleb128	DW_AT_location
	.uleb128	DW_FORM_block1
	.section	.debug_info
	.byte		5	; length of block
	.byte		DW_OP_addr
	.long		0x800000 + 0x0090 + 0x03

	.section	.debug_abbrev
	.uleb128	0
	.uleb128	0

;- - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
	;; DIE #78: variable MCU_ANAINIT
	.section	.debug_info
	.uleb128	78	; ref to abbrev 78
	.section	.debug_abbrev
	.uleb128	78
	.uleb128	DW_TAG_variable
	.byte		DW_CHILDREN_no

	.uleb128	DW_AT_name
	.uleb128	DW_FORM_strp
	.section	.debug_str
.Lname78:
	.string		"MCU_ANAINIT"
	.section	.debug_info
	.long		.Lname78

	.section	.debug_abbrev
	.uleb128	DW_AT_decl_file
	.uleb128	DW_FORM_data1
	.section	.debug_info
	.byte		0	; no source file information

	.section	.debug_abbrev
	.uleb128	DW_AT_decl_line
	.uleb128	DW_FORM_data1
	.section	.debug_info
	.byte		0	; no source line information

	.section	.debug_abbrev
	.uleb128	DW_AT_type
	.uleb128	DW_FORM_ref4
	.section	.debug_info
	.long		.Luint8_t - .Lssinfo

	.section	.debug_abbrev
	.uleb128	DW_AT_external
	.uleb128	DW_FORM_flag
	.section	.debug_info
	.byte		1

	.section	.debug_abbrev
	.uleb128	DW_AT_location
	.uleb128	DW_FORM_block1
	.section	.debug_info
	.byte		5	; length of block
	.byte		DW_OP_addr
	.long		0x800000 + 0x0090 + 0x07

	.section	.debug_abbrev
	.uleb128	0
	.uleb128	0

;- - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
	;; DIE #79: variable MCU_EVSYSLOCK
	.section	.debug_info
	.uleb128	79	; ref to abbrev 79
	.section	.debug_abbrev
	.uleb128	79
	.uleb128	DW_TAG_variable
	.byte		DW_CHILDREN_no

	.uleb128	DW_AT_name
	.uleb128	DW_FORM_strp
	.section	.debug_str
.Lname79:
	.string		"MCU_EVSYSLOCK"
	.section	.debug_info
	.long		.Lname79

	.section	.debug_abbrev
	.uleb128	DW_AT_decl_file
	.uleb128	DW_FORM_data1
	.section	.debug_info
	.byte		0	; no source file information

	.section	.debug_abbrev
	.uleb128	DW_AT_decl_line
	.uleb128	DW_FORM_data1
	.section	.debug_info
	.byte		0	; no source line information

	.section	.debug_abbrev
	.uleb128	DW_AT_type
	.uleb128	DW_FORM_ref4
	.section	.debug_info
	.long		.Luint8_t - .Lssinfo

	.section	.debug_abbrev
	.uleb128	DW_AT_external
	.uleb128	DW_FORM_flag
	.section	.debug_info
	.byte		1

	.section	.debug_abbrev
	.uleb128	DW_AT_location
	.uleb128	DW_FORM_block1
	.section	.debug_info
	.byte		5	; length of block
	.byte		DW_OP_addr
	.long		0x800000 + 0x0090 + 0x08

	.section	.debug_abbrev
	.uleb128	0
	.uleb128	0

;- - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
	;; DIE #80: variable MCU_AWEXLOCK
	.section	.debug_info
	.uleb128	80	; ref to abbrev 80
	.section	.debug_abbrev
	.uleb128	80
	.uleb128	DW_TAG_variable
	.byte		DW_CHILDREN_no

	.uleb128	DW_AT_name
	.uleb128	DW_FORM_strp
	.section	.debug_str
.Lname80:
	.string		"MCU_AWEXLOCK"
	.section	.debug_info
	.long		.Lname80

	.section	.debug_abbrev
	.uleb128	DW_AT_decl_file
	.uleb128	DW_FORM_data1
	.section	.debug_info
	.byte		0	; no source file information

	.section	.debug_abbrev
	.uleb128	DW_AT_decl_line
	.uleb128	DW_FORM_data1
	.section	.debug_info
	.byte		0	; no source line information

	.section	.debug_abbrev
	.uleb128	DW_AT_type
	.uleb128	DW_FORM_ref4
	.section	.debug_info
	.long		.Luint8_t - .Lssinfo

	.section	.debug_abbrev
	.uleb128	DW_AT_external
	.uleb128	DW_FORM_flag
	.section	.debug_info
	.byte		1

	.section	.debug_abbrev
	.uleb128	DW_AT_location
	.uleb128	DW_FORM_block1
	.section	.debug_info
	.byte		5	; length of block
	.byte		DW_OP_addr
	.long		0x800000 + 0x0090 + 0x09

	.section	.debug_abbrev
	.uleb128	0
	.uleb128	0

;- - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
	;; DIE #81: variable PMIC_STATUS
	.section	.debug_info
	.uleb128	81	; ref to abbrev 81
	.section	.debug_abbrev
	.uleb128	81
	.uleb128	DW_TAG_variable
	.byte		DW_CHILDREN_no

	.uleb128	DW_AT_name
	.uleb128	DW_FORM_strp
	.section	.debug_str
.Lname81:
	.string		"PMIC_STATUS"
	.section	.debug_info
	.long		.Lname81

	.section	.debug_abbrev
	.uleb128	DW_AT_decl_file
	.uleb128	DW_FORM_data1
	.section	.debug_info
	.byte		0	; no source file information

	.section	.debug_abbrev
	.uleb128	DW_AT_decl_line
	.uleb128	DW_FORM_data1
	.section	.debug_info
	.byte		0	; no source line information

	.section	.debug_abbrev
	.uleb128	DW_AT_type
	.uleb128	DW_FORM_ref4
	.section	.debug_info
	.long		.Luint8_t - .Lssinfo

	.section	.debug_abbrev
	.uleb128	DW_AT_external
	.uleb128	DW_FORM_flag
	.section	.debug_info
	.byte		1

	.section	.debug_abbrev
	.uleb128	DW_AT_location
	.uleb128	DW_FORM_block1
	.section	.debug_info
	.byte		5	; length of block
	.byte		DW_OP_addr
	.long		0x800000 + 0x00A0 + 0x00

	.section	.debug_abbrev
	.uleb128	0
	.uleb128	0

;- - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
	;; DIE #82: variable PMIC_INTPRI
	.section	.debug_info
	.uleb128	82	; ref to abbrev 82
	.section	.debug_abbrev
	.uleb128	82
	.uleb128	DW_TAG_variable
	.byte		DW_CHILDREN_no

	.uleb128	DW_AT_name
	.uleb128	DW_FORM_strp
	.section	.debug_str
.Lname82:
	.string		"PMIC_INTPRI"
	.section	.debug_info
	.long		.Lname82

	.section	.debug_abbrev
	.uleb128	DW_AT_decl_file
	.uleb128	DW_FORM_data1
	.section	.debug_info
	.byte		0	; no source file information

	.section	.debug_abbrev
	.uleb128	DW_AT_decl_line
	.uleb128	DW_FORM_data1
	.section	.debug_info
	.byte		0	; no source line information

	.section	.debug_abbrev
	.uleb128	DW_AT_type
	.uleb128	DW_FORM_ref4
	.section	.debug_info
	.long		.Luint8_t - .Lssinfo

	.section	.debug_abbrev
	.uleb128	DW_AT_external
	.uleb128	DW_FORM_flag
	.section	.debug_info
	.byte		1

	.section	.debug_abbrev
	.uleb128	DW_AT_location
	.uleb128	DW_FORM_block1
	.section	.debug_info
	.byte		5	; length of block
	.byte		DW_OP_addr
	.long		0x800000 + 0x00A0 + 0x01

	.section	.debug_abbrev
	.uleb128	0
	.uleb128	0

;- - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
	;; DIE #83: variable PMIC_CTRL
	.section	.debug_info
	.uleb128	83	; ref to abbrev 83
	.section	.debug_abbrev
	.uleb128	83
	.uleb128	DW_TAG_variable
	.byte		DW_CHILDREN_no

	.uleb128	DW_AT_name
	.uleb128	DW_FORM_strp
	.section	.debug_str
.Lname83:
	.string		"PMIC_CTRL"
	.section	.debug_info
	.long		.Lname83

	.section	.debug_abbrev
	.uleb128	DW_AT_decl_file
	.uleb128	DW_FORM_data1
	.section	.debug_info
	.byte		0	; no source file information

	.section	.debug_abbrev
	.uleb128	DW_AT_decl_line
	.uleb128	DW_FORM_data1
	.section	.debug_info
	.byte		0	; no source line information

	.section	.debug_abbrev
	.uleb128	DW_AT_type
	.uleb128	DW_FORM_ref4
	.section	.debug_info
	.long		.Luint8_t - .Lssinfo

	.section	.debug_abbrev
	.uleb128	DW_AT_external
	.uleb128	DW_FORM_flag
	.section	.debug_info
	.byte		1

	.section	.debug_abbrev
	.uleb128	DW_AT_location
	.uleb128	DW_FORM_block1
	.section	.debug_info
	.byte		5	; length of block
	.byte		DW_OP_addr
	.long		0x800000 + 0x00A0 + 0x02

	.section	.debug_abbrev
	.uleb128	0
	.uleb128	0

;- - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
	;; DIE #84: variable PORTCFG_MPCMASK
	.section	.debug_info
	.uleb128	84	; ref to abbrev 84
	.section	.debug_abbrev
	.uleb128	84
	.uleb128	DW_TAG_variable
	.byte		DW_CHILDREN_no

	.uleb128	DW_AT_name
	.uleb128	DW_FORM_strp
	.section	.debug_str
.Lname84:
	.string		"PORTCFG_MPCMASK"
	.section	.debug_info
	.long		.Lname84

	.section	.debug_abbrev
	.uleb128	DW_AT_decl_file
	.uleb128	DW_FORM_data1
	.section	.debug_info
	.byte		0	; no source file information

	.section	.debug_abbrev
	.uleb128	DW_AT_decl_line
	.uleb128	DW_FORM_data1
	.section	.debug_info
	.byte		0	; no source line information

	.section	.debug_abbrev
	.uleb128	DW_AT_type
	.uleb128	DW_FORM_ref4
	.section	.debug_info
	.long		.Luint8_t - .Lssinfo

	.section	.debug_abbrev
	.uleb128	DW_AT_external
	.uleb128	DW_FORM_flag
	.section	.debug_info
	.byte		1

	.section	.debug_abbrev
	.uleb128	DW_AT_location
	.uleb128	DW_FORM_block1
	.section	.debug_info
	.byte		5	; length of block
	.byte		DW_OP_addr
	.long		0x800000 + 0x00B0 + 0x00

	.section	.debug_abbrev
	.uleb128	0
	.uleb128	0

;- - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
	;; DIE #85: variable PORTCFG_VPCTRLA
	.section	.debug_info
	.uleb128	85	; ref to abbrev 85
	.section	.debug_abbrev
	.uleb128	85
	.uleb128	DW_TAG_variable
	.byte		DW_CHILDREN_no

	.uleb128	DW_AT_name
	.uleb128	DW_FORM_strp
	.section	.debug_str
.Lname85:
	.string		"PORTCFG_VPCTRLA"
	.section	.debug_info
	.long		.Lname85

	.section	.debug_abbrev
	.uleb128	DW_AT_decl_file
	.uleb128	DW_FORM_data1
	.section	.debug_info
	.byte		0	; no source file information

	.section	.debug_abbrev
	.uleb128	DW_AT_decl_line
	.uleb128	DW_FORM_data1
	.section	.debug_info
	.byte		0	; no source line information

	.section	.debug_abbrev
	.uleb128	DW_AT_type
	.uleb128	DW_FORM_ref4
	.section	.debug_info
	.long		.Luint8_t - .Lssinfo

	.section	.debug_abbrev
	.uleb128	DW_AT_external
	.uleb128	DW_FORM_flag
	.section	.debug_info
	.byte		1

	.section	.debug_abbrev
	.uleb128	DW_AT_location
	.uleb128	DW_FORM_block1
	.section	.debug_info
	.byte		5	; length of block
	.byte		DW_OP_addr
	.long		0x800000 + 0x00B0 + 0x02

	.section	.debug_abbrev
	.uleb128	0
	.uleb128	0

;- - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
	;; DIE #86: variable PORTCFG_VPCTRLB
	.section	.debug_info
	.uleb128	86	; ref to abbrev 86
	.section	.debug_abbrev
	.uleb128	86
	.uleb128	DW_TAG_variable
	.byte		DW_CHILDREN_no

	.uleb128	DW_AT_name
	.uleb128	DW_FORM_strp
	.section	.debug_str
.Lname86:
	.string		"PORTCFG_VPCTRLB"
	.section	.debug_info
	.long		.Lname86

	.section	.debug_abbrev
	.uleb128	DW_AT_decl_file
	.uleb128	DW_FORM_data1
	.section	.debug_info
	.byte		0	; no source file information

	.section	.debug_abbrev
	.uleb128	DW_AT_decl_line
	.uleb128	DW_FORM_data1
	.section	.debug_info
	.byte		0	; no source line information

	.section	.debug_abbrev
	.uleb128	DW_AT_type
	.uleb128	DW_FORM_ref4
	.section	.debug_info
	.long		.Luint8_t - .Lssinfo

	.section	.debug_abbrev
	.uleb128	DW_AT_external
	.uleb128	DW_FORM_flag
	.section	.debug_info
	.byte		1

	.section	.debug_abbrev
	.uleb128	DW_AT_location
	.uleb128	DW_FORM_block1
	.section	.debug_info
	.byte		5	; length of block
	.byte		DW_OP_addr
	.long		0x800000 + 0x00B0 + 0x03

	.section	.debug_abbrev
	.uleb128	0
	.uleb128	0

;- - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
	;; DIE #87: variable PORTCFG_CLKEVOUT
	.section	.debug_info
	.uleb128	87	; ref to abbrev 87
	.section	.debug_abbrev
	.uleb128	87
	.uleb128	DW_TAG_variable
	.byte		DW_CHILDREN_no

	.uleb128	DW_AT_name
	.uleb128	DW_FORM_strp
	.section	.debug_str
.Lname87:
	.string		"PORTCFG_CLKEVOUT"
	.section	.debug_info
	.long		.Lname87

	.section	.debug_abbrev
	.uleb128	DW_AT_decl_file
	.uleb128	DW_FORM_data1
	.section	.debug_info
	.byte		0	; no source file information

	.section	.debug_abbrev
	.uleb128	DW_AT_decl_line
	.uleb128	DW_FORM_data1
	.section	.debug_info
	.byte		0	; no source line information

	.section	.debug_abbrev
	.uleb128	DW_AT_type
	.uleb128	DW_FORM_ref4
	.section	.debug_info
	.long		.Luint8_t - .Lssinfo

	.section	.debug_abbrev
	.uleb128	DW_AT_external
	.uleb128	DW_FORM_flag
	.section	.debug_info
	.byte		1

	.section	.debug_abbrev
	.uleb128	DW_AT_location
	.uleb128	DW_FORM_block1
	.section	.debug_info
	.byte		5	; length of block
	.byte		DW_OP_addr
	.long		0x800000 + 0x00B0 + 0x04

	.section	.debug_abbrev
	.uleb128	0
	.uleb128	0

;- - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
	;; DIE #88: variable PORTCFG_EVOUTSEL
	.section	.debug_info
	.uleb128	88	; ref to abbrev 88
	.section	.debug_abbrev
	.uleb128	88
	.uleb128	DW_TAG_variable
	.byte		DW_CHILDREN_no

	.uleb128	DW_AT_name
	.uleb128	DW_FORM_strp
	.section	.debug_str
.Lname88:
	.string		"PORTCFG_EVOUTSEL"
	.section	.debug_info
	.long		.Lname88

	.section	.debug_abbrev
	.uleb128	DW_AT_decl_file
	.uleb128	DW_FORM_data1
	.section	.debug_info
	.byte		0	; no source file information

	.section	.debug_abbrev
	.uleb128	DW_AT_decl_line
	.uleb128	DW_FORM_data1
	.section	.debug_info
	.byte		0	; no source line information

	.section	.debug_abbrev
	.uleb128	DW_AT_type
	.uleb128	DW_FORM_ref4
	.section	.debug_info
	.long		.Luint8_t - .Lssinfo

	.section	.debug_abbrev
	.uleb128	DW_AT_external
	.uleb128	DW_FORM_flag
	.section	.debug_info
	.byte		1

	.section	.debug_abbrev
	.uleb128	DW_AT_location
	.uleb128	DW_FORM_block1
	.section	.debug_info
	.byte		5	; length of block
	.byte		DW_OP_addr
	.long		0x800000 + 0x00B0 + 0x06

	.section	.debug_abbrev
	.uleb128	0
	.uleb128	0

;- - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
	;; DIE #89: variable CRC_CTRL
	.section	.debug_info
	.uleb128	89	; ref to abbrev 89
	.section	.debug_abbrev
	.uleb128	89
	.uleb128	DW_TAG_variable
	.byte		DW_CHILDREN_no

	.uleb128	DW_AT_name
	.uleb128	DW_FORM_strp
	.section	.debug_str
.Lname89:
	.string		"CRC_CTRL"
	.section	.debug_info
	.long		.Lname89

	.section	.debug_abbrev
	.uleb128	DW_AT_decl_file
	.uleb128	DW_FORM_data1
	.section	.debug_info
	.byte		0	; no source file information

	.section	.debug_abbrev
	.uleb128	DW_AT_decl_line
	.uleb128	DW_FORM_data1
	.section	.debug_info
	.byte		0	; no source line information

	.section	.debug_abbrev
	.uleb128	DW_AT_type
	.uleb128	DW_FORM_ref4
	.section	.debug_info
	.long		.Luint8_t - .Lssinfo

	.section	.debug_abbrev
	.uleb128	DW_AT_external
	.uleb128	DW_FORM_flag
	.section	.debug_info
	.byte		1

	.section	.debug_abbrev
	.uleb128	DW_AT_location
	.uleb128	DW_FORM_block1
	.section	.debug_info
	.byte		5	; length of block
	.byte		DW_OP_addr
	.long		0x800000 + 0x0D0 + 0x00

	.section	.debug_abbrev
	.uleb128	0
	.uleb128	0

;- - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
	;; DIE #90: variable CRC_STATUS
	.section	.debug_info
	.uleb128	90	; ref to abbrev 90
	.section	.debug_abbrev
	.uleb128	90
	.uleb128	DW_TAG_variable
	.byte		DW_CHILDREN_no

	.uleb128	DW_AT_name
	.uleb128	DW_FORM_strp
	.section	.debug_str
.Lname90:
	.string		"CRC_STATUS"
	.section	.debug_info
	.long		.Lname90

	.section	.debug_abbrev
	.uleb128	DW_AT_decl_file
	.uleb128	DW_FORM_data1
	.section	.debug_info
	.byte		0	; no source file information

	.section	.debug_abbrev
	.uleb128	DW_AT_decl_line
	.uleb128	DW_FORM_data1
	.section	.debug_info
	.byte		0	; no source line information

	.section	.debug_abbrev
	.uleb128	DW_AT_type
	.uleb128	DW_FORM_ref4
	.section	.debug_info
	.long		.Luint8_t - .Lssinfo

	.section	.debug_abbrev
	.uleb128	DW_AT_external
	.uleb128	DW_FORM_flag
	.section	.debug_info
	.byte		1

	.section	.debug_abbrev
	.uleb128	DW_AT_location
	.uleb128	DW_FORM_block1
	.section	.debug_info
	.byte		5	; length of block
	.byte		DW_OP_addr
	.long		0x800000 + 0x0D0 + 0x01

	.section	.debug_abbrev
	.uleb128	0
	.uleb128	0

;- - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
	;; DIE #91: variable CRC_DATAIN
	.section	.debug_info
	.uleb128	91	; ref to abbrev 91
	.section	.debug_abbrev
	.uleb128	91
	.uleb128	DW_TAG_variable
	.byte		DW_CHILDREN_no

	.uleb128	DW_AT_name
	.uleb128	DW_FORM_strp
	.section	.debug_str
.Lname91:
	.string		"CRC_DATAIN"
	.section	.debug_info
	.long		.Lname91

	.section	.debug_abbrev
	.uleb128	DW_AT_decl_file
	.uleb128	DW_FORM_data1
	.section	.debug_info
	.byte		0	; no source file information

	.section	.debug_abbrev
	.uleb128	DW_AT_decl_line
	.uleb128	DW_FORM_data1
	.section	.debug_info
	.byte		0	; no source line information

	.section	.debug_abbrev
	.uleb128	DW_AT_type
	.uleb128	DW_FORM_ref4
	.section	.debug_info
	.long		.Luint8_t - .Lssinfo

	.section	.debug_abbrev
	.uleb128	DW_AT_external
	.uleb128	DW_FORM_flag
	.section	.debug_info
	.byte		1

	.section	.debug_abbrev
	.uleb128	DW_AT_location
	.uleb128	DW_FORM_block1
	.section	.debug_info
	.byte		5	; length of block
	.byte		DW_OP_addr
	.long		0x800000 + 0x0D0 + 0x03

	.section	.debug_abbrev
	.uleb128	0
	.uleb128	0

;- - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
	;; DIE #92: variable CRC_CHECKSUM0
	.section	.debug_info
	.uleb128	92	; ref to abbrev 92
	.section	.debug_abbrev
	.uleb128	92
	.uleb128	DW_TAG_variable
	.byte		DW_CHILDREN_no

	.uleb128	DW_AT_name
	.uleb128	DW_FORM_strp
	.section	.debug_str
.Lname92:
	.string		"CRC_CHECKSUM0"
	.section	.debug_info
	.long		.Lname92

	.section	.debug_abbrev
	.uleb128	DW_AT_decl_file
	.uleb128	DW_FORM_data1
	.section	.debug_info
	.byte		0	; no source file information

	.section	.debug_abbrev
	.uleb128	DW_AT_decl_line
	.uleb128	DW_FORM_data1
	.section	.debug_info
	.byte		0	; no source line information

	.section	.debug_abbrev
	.uleb128	DW_AT_type
	.uleb128	DW_FORM_ref4
	.section	.debug_info
	.long		.Luint8_t - .Lssinfo

	.section	.debug_abbrev
	.uleb128	DW_AT_external
	.uleb128	DW_FORM_flag
	.section	.debug_info
	.byte		1

	.section	.debug_abbrev
	.uleb128	DW_AT_location
	.uleb128	DW_FORM_block1
	.section	.debug_info
	.byte		5	; length of block
	.byte		DW_OP_addr
	.long		0x800000 + 0x0D0 + 0x04

	.section	.debug_abbrev
	.uleb128	0
	.uleb128	0

;- - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
	;; DIE #93: variable CRC_CHECKSUM1
	.section	.debug_info
	.uleb128	93	; ref to abbrev 93
	.section	.debug_abbrev
	.uleb128	93
	.uleb128	DW_TAG_variable
	.byte		DW_CHILDREN_no

	.uleb128	DW_AT_name
	.uleb128	DW_FORM_strp
	.section	.debug_str
.Lname93:
	.string		"CRC_CHECKSUM1"
	.section	.debug_info
	.long		.Lname93

	.section	.debug_abbrev
	.uleb128	DW_AT_decl_file
	.uleb128	DW_FORM_data1
	.section	.debug_info
	.byte		0	; no source file information

	.section	.debug_abbrev
	.uleb128	DW_AT_decl_line
	.uleb128	DW_FORM_data1
	.section	.debug_info
	.byte		0	; no source line information

	.section	.debug_abbrev
	.uleb128	DW_AT_type
	.uleb128	DW_FORM_ref4
	.section	.debug_info
	.long		.Luint8_t - .Lssinfo

	.section	.debug_abbrev
	.uleb128	DW_AT_external
	.uleb128	DW_FORM_flag
	.section	.debug_info
	.byte		1

	.section	.debug_abbrev
	.uleb128	DW_AT_location
	.uleb128	DW_FORM_block1
	.section	.debug_info
	.byte		5	; length of block
	.byte		DW_OP_addr
	.long		0x800000 + 0x0D0 + 0x05

	.section	.debug_abbrev
	.uleb128	0
	.uleb128	0

;- - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
	;; DIE #94: variable CRC_CHECKSUM2
	.section	.debug_info
	.uleb128	94	; ref to abbrev 94
	.section	.debug_abbrev
	.uleb128	94
	.uleb128	DW_TAG_variable
	.byte		DW_CHILDREN_no

	.uleb128	DW_AT_name
	.uleb128	DW_FORM_strp
	.section	.debug_str
.Lname94:
	.string		"CRC_CHECKSUM2"
	.section	.debug_info
	.long		.Lname94

	.section	.debug_abbrev
	.uleb128	DW_AT_decl_file
	.uleb128	DW_FORM_data1
	.section	.debug_info
	.byte		0	; no source file information

	.section	.debug_abbrev
	.uleb128	DW_AT_decl_line
	.uleb128	DW_FORM_data1
	.section	.debug_info
	.byte		0	; no source line information

	.section	.debug_abbrev
	.uleb128	DW_AT_type
	.uleb128	DW_FORM_ref4
	.section	.debug_info
	.long		.Luint8_t - .Lssinfo

	.section	.debug_abbrev
	.uleb128	DW_AT_external
	.uleb128	DW_FORM_flag
	.section	.debug_info
	.byte		1

	.section	.debug_abbrev
	.uleb128	DW_AT_location
	.uleb128	DW_FORM_block1
	.section	.debug_info
	.byte		5	; length of block
	.byte		DW_OP_addr
	.long		0x800000 + 0x0D0 + 0x06

	.section	.debug_abbrev
	.uleb128	0
	.uleb128	0

;- - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
	;; DIE #95: variable CRC_CHECKSUM3
	.section	.debug_info
	.uleb128	95	; ref to abbrev 95
	.section	.debug_abbrev
	.uleb128	95
	.uleb128	DW_TAG_variable
	.byte		DW_CHILDREN_no

	.uleb128	DW_AT_name
	.uleb128	DW_FORM_strp
	.section	.debug_str
.Lname95:
	.string		"CRC_CHECKSUM3"
	.section	.debug_info
	.long		.Lname95

	.section	.debug_abbrev
	.uleb128	DW_AT_decl_file
	.uleb128	DW_FORM_data1
	.section	.debug_info
	.byte		0	; no source file information

	.section	.debug_abbrev
	.uleb128	DW_AT_decl_line
	.uleb128	DW_FORM_data1
	.section	.debug_info
	.byte		0	; no source line information

	.section	.debug_abbrev
	.uleb128	DW_AT_type
	.uleb128	DW_FORM_ref4
	.section	.debug_info
	.long		.Luint8_t - .Lssinfo

	.section	.debug_abbrev
	.uleb128	DW_AT_external
	.uleb128	DW_FORM_flag
	.section	.debug_info
	.byte		1

	.section	.debug_abbrev
	.uleb128	DW_AT_location
	.uleb128	DW_FORM_block1
	.section	.debug_info
	.byte		5	; length of block
	.byte		DW_OP_addr
	.long		0x800000 + 0x0D0 + 0x07

	.section	.debug_abbrev
	.uleb128	0
	.uleb128	0

;- - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
	;; DIE #96: variable EVSYS_CH0MUX
	.section	.debug_info
	.uleb128	96	; ref to abbrev 96
	.section	.debug_abbrev
	.uleb128	96
	.uleb128	DW_TAG_variable
	.byte		DW_CHILDREN_no

	.uleb128	DW_AT_name
	.uleb128	DW_FORM_strp
	.section	.debug_str
.Lname96:
	.string		"EVSYS_CH0MUX"
	.section	.debug_info
	.long		.Lname96

	.section	.debug_abbrev
	.uleb128	DW_AT_decl_file
	.uleb128	DW_FORM_data1
	.section	.debug_info
	.byte		0	; no source file information

	.section	.debug_abbrev
	.uleb128	DW_AT_decl_line
	.uleb128	DW_FORM_data1
	.section	.debug_info
	.byte		0	; no source line information

	.section	.debug_abbrev
	.uleb128	DW_AT_type
	.uleb128	DW_FORM_ref4
	.section	.debug_info
	.long		.Luint8_t - .Lssinfo

	.section	.debug_abbrev
	.uleb128	DW_AT_external
	.uleb128	DW_FORM_flag
	.section	.debug_info
	.byte		1

	.section	.debug_abbrev
	.uleb128	DW_AT_location
	.uleb128	DW_FORM_block1
	.section	.debug_info
	.byte		5	; length of block
	.byte		DW_OP_addr
	.long		0x800000 + 0x0180 + 0x00

	.section	.debug_abbrev
	.uleb128	0
	.uleb128	0

;- - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
	;; DIE #97: variable EVSYS_CH1MUX
	.section	.debug_info
	.uleb128	97	; ref to abbrev 97
	.section	.debug_abbrev
	.uleb128	97
	.uleb128	DW_TAG_variable
	.byte		DW_CHILDREN_no

	.uleb128	DW_AT_name
	.uleb128	DW_FORM_strp
	.section	.debug_str
.Lname97:
	.string		"EVSYS_CH1MUX"
	.section	.debug_info
	.long		.Lname97

	.section	.debug_abbrev
	.uleb128	DW_AT_decl_file
	.uleb128	DW_FORM_data1
	.section	.debug_info
	.byte		0	; no source file information

	.section	.debug_abbrev
	.uleb128	DW_AT_decl_line
	.uleb128	DW_FORM_data1
	.section	.debug_info
	.byte		0	; no source line information

	.section	.debug_abbrev
	.uleb128	DW_AT_type
	.uleb128	DW_FORM_ref4
	.section	.debug_info
	.long		.Luint8_t - .Lssinfo

	.section	.debug_abbrev
	.uleb128	DW_AT_external
	.uleb128	DW_FORM_flag
	.section	.debug_info
	.byte		1

	.section	.debug_abbrev
	.uleb128	DW_AT_location
	.uleb128	DW_FORM_block1
	.section	.debug_info
	.byte		5	; length of block
	.byte		DW_OP_addr
	.long		0x800000 + 0x0180 + 0x01

	.section	.debug_abbrev
	.uleb128	0
	.uleb128	0

;- - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
	;; DIE #98: variable EVSYS_CH2MUX
	.section	.debug_info
	.uleb128	98	; ref to abbrev 98
	.section	.debug_abbrev
	.uleb128	98
	.uleb128	DW_TAG_variable
	.byte		DW_CHILDREN_no

	.uleb128	DW_AT_name
	.uleb128	DW_FORM_strp
	.section	.debug_str
.Lname98:
	.string		"EVSYS_CH2MUX"
	.section	.debug_info
	.long		.Lname98

	.section	.debug_abbrev
	.uleb128	DW_AT_decl_file
	.uleb128	DW_FORM_data1
	.section	.debug_info
	.byte		0	; no source file information

	.section	.debug_abbrev
	.uleb128	DW_AT_decl_line
	.uleb128	DW_FORM_data1
	.section	.debug_info
	.byte		0	; no source line information

	.section	.debug_abbrev
	.uleb128	DW_AT_type
	.uleb128	DW_FORM_ref4
	.section	.debug_info
	.long		.Luint8_t - .Lssinfo

	.section	.debug_abbrev
	.uleb128	DW_AT_external
	.uleb128	DW_FORM_flag
	.section	.debug_info
	.byte		1

	.section	.debug_abbrev
	.uleb128	DW_AT_location
	.uleb128	DW_FORM_block1
	.section	.debug_info
	.byte		5	; length of block
	.byte		DW_OP_addr
	.long		0x800000 + 0x0180 + 0x02

	.section	.debug_abbrev
	.uleb128	0
	.uleb128	0

;- - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
	;; DIE #99: variable EVSYS_CH3MUX
	.section	.debug_info
	.uleb128	99	; ref to abbrev 99
	.section	.debug_abbrev
	.uleb128	99
	.uleb128	DW_TAG_variable
	.byte		DW_CHILDREN_no

	.uleb128	DW_AT_name
	.uleb128	DW_FORM_strp
	.section	.debug_str
.Lname99:
	.string		"EVSYS_CH3MUX"
	.section	.debug_info
	.long		.Lname99

	.section	.debug_abbrev
	.uleb128	DW_AT_decl_file
	.uleb128	DW_FORM_data1
	.section	.debug_info
	.byte		0	; no source file information

	.section	.debug_abbrev
	.uleb128	DW_AT_decl_line
	.uleb128	DW_FORM_data1
	.section	.debug_info
	.byte		0	; no source line information

	.section	.debug_abbrev
	.uleb128	DW_AT_type
	.uleb128	DW_FORM_ref4
	.section	.debug_info
	.long		.Luint8_t - .Lssinfo

	.section	.debug_abbrev
	.uleb128	DW_AT_external
	.uleb128	DW_FORM_flag
	.section	.debug_info
	.byte		1

	.section	.debug_abbrev
	.uleb128	DW_AT_location
	.uleb128	DW_FORM_block1
	.section	.debug_info
	.byte		5	; length of block
	.byte		DW_OP_addr
	.long		0x800000 + 0x0180 + 0x03

	.section	.debug_abbrev
	.uleb128	0
	.uleb128	0

;- - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
	;; DIE #100: variable EVSYS_CH0CTRL
	.section	.debug_info
	.uleb128	100	; ref to abbrev 100
	.section	.debug_abbrev
	.uleb128	100
	.uleb128	DW_TAG_variable
	.byte		DW_CHILDREN_no

	.uleb128	DW_AT_name
	.uleb128	DW_FORM_strp
	.section	.debug_str
.Lname100:
	.string		"EVSYS_CH0CTRL"
	.section	.debug_info
	.long		.Lname100

	.section	.debug_abbrev
	.uleb128	DW_AT_decl_file
	.uleb128	DW_FORM_data1
	.section	.debug_info
	.byte		0	; no source file information

	.section	.debug_abbrev
	.uleb128	DW_AT_decl_line
	.uleb128	DW_FORM_data1
	.section	.debug_info
	.byte		0	; no source line information

	.section	.debug_abbrev
	.uleb128	DW_AT_type
	.uleb128	DW_FORM_ref4
	.section	.debug_info
	.long		.Luint8_t - .Lssinfo

	.section	.debug_abbrev
	.uleb128	DW_AT_external
	.uleb128	DW_FORM_flag
	.section	.debug_info
	.byte		1

	.section	.debug_abbrev
	.uleb128	DW_AT_location
	.uleb128	DW_FORM_block1
	.section	.debug_info
	.byte		5	; length of block
	.byte		DW_OP_addr
	.long		0x800000 + 0x0180 + 0x08

	.section	.debug_abbrev
	.uleb128	0
	.uleb128	0

;- - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
	;; DIE #101: variable EVSYS_CH1CTRL
	.section	.debug_info
	.uleb128	101	; ref to abbrev 101
	.section	.debug_abbrev
	.uleb128	101
	.uleb128	DW_TAG_variable
	.byte		DW_CHILDREN_no

	.uleb128	DW_AT_name
	.uleb128	DW_FORM_strp
	.section	.debug_str
.Lname101:
	.string		"EVSYS_CH1CTRL"
	.section	.debug_info
	.long		.Lname101

	.section	.debug_abbrev
	.uleb128	DW_AT_decl_file
	.uleb128	DW_FORM_data1
	.section	.debug_info
	.byte		0	; no source file information

	.section	.debug_abbrev
	.uleb128	DW_AT_decl_line
	.uleb128	DW_FORM_data1
	.section	.debug_info
	.byte		0	; no source line information

	.section	.debug_abbrev
	.uleb128	DW_AT_type
	.uleb128	DW_FORM_ref4
	.section	.debug_info
	.long		.Luint8_t - .Lssinfo

	.section	.debug_abbrev
	.uleb128	DW_AT_external
	.uleb128	DW_FORM_flag
	.section	.debug_info
	.byte		1

	.section	.debug_abbrev
	.uleb128	DW_AT_location
	.uleb128	DW_FORM_block1
	.section	.debug_info
	.byte		5	; length of block
	.byte		DW_OP_addr
	.long		0x800000 + 0x0180 + 0x09

	.section	.debug_abbrev
	.uleb128	0
	.uleb128	0

;- - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
	;; DIE #102: variable EVSYS_CH2CTRL
	.section	.debug_info
	.uleb128	102	; ref to abbrev 102
	.section	.debug_abbrev
	.uleb128	102
	.uleb128	DW_TAG_variable
	.byte		DW_CHILDREN_no

	.uleb128	DW_AT_name
	.uleb128	DW_FORM_strp
	.section	.debug_str
.Lname102:
	.string		"EVSYS_CH2CTRL"
	.section	.debug_info
	.long		.Lname102

	.section	.debug_abbrev
	.uleb128	DW_AT_decl_file
	.uleb128	DW_FORM_data1
	.section	.debug_info
	.byte		0	; no source file information

	.section	.debug_abbrev
	.uleb128	DW_AT_decl_line
	.uleb128	DW_FORM_data1
	.section	.debug_info
	.byte		0	; no source line information

	.section	.debug_abbrev
	.uleb128	DW_AT_type
	.uleb128	DW_FORM_ref4
	.section	.debug_info
	.long		.Luint8_t - .Lssinfo

	.section	.debug_abbrev
	.uleb128	DW_AT_external
	.uleb128	DW_FORM_flag
	.section	.debug_info
	.byte		1

	.section	.debug_abbrev
	.uleb128	DW_AT_location
	.uleb128	DW_FORM_block1
	.section	.debug_info
	.byte		5	; length of block
	.byte		DW_OP_addr
	.long		0x800000 + 0x0180 + 0x0A

	.section	.debug_abbrev
	.uleb128	0
	.uleb128	0

;- - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
	;; DIE #103: variable EVSYS_CH3CTRL
	.section	.debug_info
	.uleb128	103	; ref to abbrev 103
	.section	.debug_abbrev
	.uleb128	103
	.uleb128	DW_TAG_variable
	.byte		DW_CHILDREN_no

	.uleb128	DW_AT_name
	.uleb128	DW_FORM_strp
	.section	.debug_str
.Lname103:
	.string		"EVSYS_CH3CTRL"
	.section	.debug_info
	.long		.Lname103

	.section	.debug_abbrev
	.uleb128	DW_AT_decl_file
	.uleb128	DW_FORM_data1
	.section	.debug_info
	.byte		0	; no source file information

	.section	.debug_abbrev
	.uleb128	DW_AT_decl_line
	.uleb128	DW_FORM_data1
	.section	.debug_info
	.byte		0	; no source line information

	.section	.debug_abbrev
	.uleb128	DW_AT_type
	.uleb128	DW_FORM_ref4
	.section	.debug_info
	.long		.Luint8_t - .Lssinfo

	.section	.debug_abbrev
	.uleb128	DW_AT_external
	.uleb128	DW_FORM_flag
	.section	.debug_info
	.byte		1

	.section	.debug_abbrev
	.uleb128	DW_AT_location
	.uleb128	DW_FORM_block1
	.section	.debug_info
	.byte		5	; length of block
	.byte		DW_OP_addr
	.long		0x800000 + 0x0180 + 0x0B

	.section	.debug_abbrev
	.uleb128	0
	.uleb128	0

;- - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
	;; DIE #104: variable EVSYS_STROBE
	.section	.debug_info
	.uleb128	104	; ref to abbrev 104
	.section	.debug_abbrev
	.uleb128	104
	.uleb128	DW_TAG_variable
	.byte		DW_CHILDREN_no

	.uleb128	DW_AT_name
	.uleb128	DW_FORM_strp
	.section	.debug_str
.Lname104:
	.string		"EVSYS_STROBE"
	.section	.debug_info
	.long		.Lname104

	.section	.debug_abbrev
	.uleb128	DW_AT_decl_file
	.uleb128	DW_FORM_data1
	.section	.debug_info
	.byte		0	; no source file information

	.section	.debug_abbrev
	.uleb128	DW_AT_decl_line
	.uleb128	DW_FORM_data1
	.section	.debug_info
	.byte		0	; no source line information

	.section	.debug_abbrev
	.uleb128	DW_AT_type
	.uleb128	DW_FORM_ref4
	.section	.debug_info
	.long		.Luint8_t - .Lssinfo

	.section	.debug_abbrev
	.uleb128	DW_AT_external
	.uleb128	DW_FORM_flag
	.section	.debug_info
	.byte		1

	.section	.debug_abbrev
	.uleb128	DW_AT_location
	.uleb128	DW_FORM_block1
	.section	.debug_info
	.byte		5	; length of block
	.byte		DW_OP_addr
	.long		0x800000 + 0x0180 + 0x10

	.section	.debug_abbrev
	.uleb128	0
	.uleb128	0

;- - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
	;; DIE #105: variable EVSYS_DATA
	.section	.debug_info
	.uleb128	105	; ref to abbrev 105
	.section	.debug_abbrev
	.uleb128	105
	.uleb128	DW_TAG_variable
	.byte		DW_CHILDREN_no

	.uleb128	DW_AT_name
	.uleb128	DW_FORM_strp
	.section	.debug_str
.Lname105:
	.string		"EVSYS_DATA"
	.section	.debug_info
	.long		.Lname105

	.section	.debug_abbrev
	.uleb128	DW_AT_decl_file
	.uleb128	DW_FORM_data1
	.section	.debug_info
	.byte		0	; no source file information

	.section	.debug_abbrev
	.uleb128	DW_AT_decl_line
	.uleb128	DW_FORM_data1
	.section	.debug_info
	.byte		0	; no source line information

	.section	.debug_abbrev
	.uleb128	DW_AT_type
	.uleb128	DW_FORM_ref4
	.section	.debug_info
	.long		.Luint8_t - .Lssinfo

	.section	.debug_abbrev
	.uleb128	DW_AT_external
	.uleb128	DW_FORM_flag
	.section	.debug_info
	.byte		1

	.section	.debug_abbrev
	.uleb128	DW_AT_location
	.uleb128	DW_FORM_block1
	.section	.debug_info
	.byte		5	; length of block
	.byte		DW_OP_addr
	.long		0x800000 + 0x0180 + 0x11

	.section	.debug_abbrev
	.uleb128	0
	.uleb128	0

;- - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
	;; DIE #106: variable NVM_ADDR0
	.section	.debug_info
	.uleb128	106	; ref to abbrev 106
	.section	.debug_abbrev
	.uleb128	106
	.uleb128	DW_TAG_variable
	.byte		DW_CHILDREN_no

	.uleb128	DW_AT_name
	.uleb128	DW_FORM_strp
	.section	.debug_str
.Lname106:
	.string		"NVM_ADDR0"
	.section	.debug_info
	.long		.Lname106

	.section	.debug_abbrev
	.uleb128	DW_AT_decl_file
	.uleb128	DW_FORM_data1
	.section	.debug_info
	.byte		0	; no source file information

	.section	.debug_abbrev
	.uleb128	DW_AT_decl_line
	.uleb128	DW_FORM_data1
	.section	.debug_info
	.byte		0	; no source line information

	.section	.debug_abbrev
	.uleb128	DW_AT_type
	.uleb128	DW_FORM_ref4
	.section	.debug_info
	.long		.Luint8_t - .Lssinfo

	.section	.debug_abbrev
	.uleb128	DW_AT_external
	.uleb128	DW_FORM_flag
	.section	.debug_info
	.byte		1

	.section	.debug_abbrev
	.uleb128	DW_AT_location
	.uleb128	DW_FORM_block1
	.section	.debug_info
	.byte		5	; length of block
	.byte		DW_OP_addr
	.long		0x800000 + 0x01C0 + 0x00

	.section	.debug_abbrev
	.uleb128	0
	.uleb128	0

;- - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
	;; DIE #107: variable NVM_ADDR1
	.section	.debug_info
	.uleb128	107	; ref to abbrev 107
	.section	.debug_abbrev
	.uleb128	107
	.uleb128	DW_TAG_variable
	.byte		DW_CHILDREN_no

	.uleb128	DW_AT_name
	.uleb128	DW_FORM_strp
	.section	.debug_str
.Lname107:
	.string		"NVM_ADDR1"
	.section	.debug_info
	.long		.Lname107

	.section	.debug_abbrev
	.uleb128	DW_AT_decl_file
	.uleb128	DW_FORM_data1
	.section	.debug_info
	.byte		0	; no source file information

	.section	.debug_abbrev
	.uleb128	DW_AT_decl_line
	.uleb128	DW_FORM_data1
	.section	.debug_info
	.byte		0	; no source line information

	.section	.debug_abbrev
	.uleb128	DW_AT_type
	.uleb128	DW_FORM_ref4
	.section	.debug_info
	.long		.Luint8_t - .Lssinfo

	.section	.debug_abbrev
	.uleb128	DW_AT_external
	.uleb128	DW_FORM_flag
	.section	.debug_info
	.byte		1

	.section	.debug_abbrev
	.uleb128	DW_AT_location
	.uleb128	DW_FORM_block1
	.section	.debug_info
	.byte		5	; length of block
	.byte		DW_OP_addr
	.long		0x800000 + 0x01C0 + 0x01

	.section	.debug_abbrev
	.uleb128	0
	.uleb128	0

;- - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
	;; DIE #108: variable NVM_ADDR2
	.section	.debug_info
	.uleb128	108	; ref to abbrev 108
	.section	.debug_abbrev
	.uleb128	108
	.uleb128	DW_TAG_variable
	.byte		DW_CHILDREN_no

	.uleb128	DW_AT_name
	.uleb128	DW_FORM_strp
	.section	.debug_str
.Lname108:
	.string		"NVM_ADDR2"
	.section	.debug_info
	.long		.Lname108

	.section	.debug_abbrev
	.uleb128	DW_AT_decl_file
	.uleb128	DW_FORM_data1
	.section	.debug_info
	.byte		0	; no source file information

	.section	.debug_abbrev
	.uleb128	DW_AT_decl_line
	.uleb128	DW_FORM_data1
	.section	.debug_info
	.byte		0	; no source line information

	.section	.debug_abbrev
	.uleb128	DW_AT_type
	.uleb128	DW_FORM_ref4
	.section	.debug_info
	.long		.Luint8_t - .Lssinfo

	.section	.debug_abbrev
	.uleb128	DW_AT_external
	.uleb128	DW_FORM_flag
	.section	.debug_info
	.byte		1

	.section	.debug_abbrev
	.uleb128	DW_AT_location
	.uleb128	DW_FORM_block1
	.section	.debug_info
	.byte		5	; length of block
	.byte		DW_OP_addr
	.long		0x800000 + 0x01C0 + 0x02

	.section	.debug_abbrev
	.uleb128	0
	.uleb128	0

;- - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
	;; DIE #109: variable NVM_DATA0
	.section	.debug_info
	.uleb128	109	; ref to abbrev 109
	.section	.debug_abbrev
	.uleb128	109
	.uleb128	DW_TAG_variable
	.byte		DW_CHILDREN_no

	.uleb128	DW_AT_name
	.uleb128	DW_FORM_strp
	.section	.debug_str
.Lname109:
	.string		"NVM_DATA0"
	.section	.debug_info
	.long		.Lname109

	.section	.debug_abbrev
	.uleb128	DW_AT_decl_file
	.uleb128	DW_FORM_data1
	.section	.debug_info
	.byte		0	; no source file information

	.section	.debug_abbrev
	.uleb128	DW_AT_decl_line
	.uleb128	DW_FORM_data1
	.section	.debug_info
	.byte		0	; no source line information

	.section	.debug_abbrev
	.uleb128	DW_AT_type
	.uleb128	DW_FORM_ref4
	.section	.debug_info
	.long		.Luint8_t - .Lssinfo

	.section	.debug_abbrev
	.uleb128	DW_AT_external
	.uleb128	DW_FORM_flag
	.section	.debug_info
	.byte		1

	.section	.debug_abbrev
	.uleb128	DW_AT_location
	.uleb128	DW_FORM_block1
	.section	.debug_info
	.byte		5	; length of block
	.byte		DW_OP_addr
	.long		0x800000 + 0x01C0 + 0x04

	.section	.debug_abbrev
	.uleb128	0
	.uleb128	0

;- - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
	;; DIE #110: variable NVM_DATA1
	.section	.debug_info
	.uleb128	110	; ref to abbrev 110
	.section	.debug_abbrev
	.uleb128	110
	.uleb128	DW_TAG_variable
	.byte		DW_CHILDREN_no

	.uleb128	DW_AT_name
	.uleb128	DW_FORM_strp
	.section	.debug_str
.Lname110:
	.string		"NVM_DATA1"
	.section	.debug_info
	.long		.Lname110

	.section	.debug_abbrev
	.uleb128	DW_AT_decl_file
	.uleb128	DW_FORM_data1
	.section	.debug_info
	.byte		0	; no source file information

	.section	.debug_abbrev
	.uleb128	DW_AT_decl_line
	.uleb128	DW_FORM_data1
	.section	.debug_info
	.byte		0	; no source line information

	.section	.debug_abbrev
	.uleb128	DW_AT_type
	.uleb128	DW_FORM_ref4
	.section	.debug_info
	.long		.Luint8_t - .Lssinfo

	.section	.debug_abbrev
	.uleb128	DW_AT_external
	.uleb128	DW_FORM_flag
	.section	.debug_info
	.byte		1

	.section	.debug_abbrev
	.uleb128	DW_AT_location
	.uleb128	DW_FORM_block1
	.section	.debug_info
	.byte		5	; length of block
	.byte		DW_OP_addr
	.long		0x800000 + 0x01C0 + 0x05

	.section	.debug_abbrev
	.uleb128	0
	.uleb128	0

;- - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
	;; DIE #111: variable NVM_DATA2
	.section	.debug_info
	.uleb128	111	; ref to abbrev 111
	.section	.debug_abbrev
	.uleb128	111
	.uleb128	DW_TAG_variable
	.byte		DW_CHILDREN_no

	.uleb128	DW_AT_name
	.uleb128	DW_FORM_strp
	.section	.debug_str
.Lname111:
	.string		"NVM_DATA2"
	.section	.debug_info
	.long		.Lname111

	.section	.debug_abbrev
	.uleb128	DW_AT_decl_file
	.uleb128	DW_FORM_data1
	.section	.debug_info
	.byte		0	; no source file information

	.section	.debug_abbrev
	.uleb128	DW_AT_decl_line
	.uleb128	DW_FORM_data1
	.section	.debug_info
	.byte		0	; no source line information

	.section	.debug_abbrev
	.uleb128	DW_AT_type
	.uleb128	DW_FORM_ref4
	.section	.debug_info
	.long		.Luint8_t - .Lssinfo

	.section	.debug_abbrev
	.uleb128	DW_AT_external
	.uleb128	DW_FORM_flag
	.section	.debug_info
	.byte		1

	.section	.debug_abbrev
	.uleb128	DW_AT_location
	.uleb128	DW_FORM_block1
	.section	.debug_info
	.byte		5	; length of block
	.byte		DW_OP_addr
	.long		0x800000 + 0x01C0 + 0x06

	.section	.debug_abbrev
	.uleb128	0
	.uleb128	0

;- - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
	;; DIE #112: variable NVM_CMD
	.section	.debug_info
	.uleb128	112	; ref to abbrev 112
	.section	.debug_abbrev
	.uleb128	112
	.uleb128	DW_TAG_variable
	.byte		DW_CHILDREN_no

	.uleb128	DW_AT_name
	.uleb128	DW_FORM_strp
	.section	.debug_str
.Lname112:
	.string		"NVM_CMD"
	.section	.debug_info
	.long		.Lname112

	.section	.debug_abbrev
	.uleb128	DW_AT_decl_file
	.uleb128	DW_FORM_data1
	.section	.debug_info
	.byte		0	; no source file information

	.section	.debug_abbrev
	.uleb128	DW_AT_decl_line
	.uleb128	DW_FORM_data1
	.section	.debug_info
	.byte		0	; no source line information

	.section	.debug_abbrev
	.uleb128	DW_AT_type
	.uleb128	DW_FORM_ref4
	.section	.debug_info
	.long		.Luint8_t - .Lssinfo

	.section	.debug_abbrev
	.uleb128	DW_AT_external
	.uleb128	DW_FORM_flag
	.section	.debug_info
	.byte		1

	.section	.debug_abbrev
	.uleb128	DW_AT_location
	.uleb128	DW_FORM_block1
	.section	.debug_info
	.byte		5	; length of block
	.byte		DW_OP_addr
	.long		0x800000 + 0x01C0 + 0x0A

	.section	.debug_abbrev
	.uleb128	0
	.uleb128	0

;- - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
	;; DIE #113: variable NVM_CTRLA
	.section	.debug_info
	.uleb128	113	; ref to abbrev 113
	.section	.debug_abbrev
	.uleb128	113
	.uleb128	DW_TAG_variable
	.byte		DW_CHILDREN_no

	.uleb128	DW_AT_name
	.uleb128	DW_FORM_strp
	.section	.debug_str
.Lname113:
	.string		"NVM_CTRLA"
	.section	.debug_info
	.long		.Lname113

	.section	.debug_abbrev
	.uleb128	DW_AT_decl_file
	.uleb128	DW_FORM_data1
	.section	.debug_info
	.byte		0	; no source file information

	.section	.debug_abbrev
	.uleb128	DW_AT_decl_line
	.uleb128	DW_FORM_data1
	.section	.debug_info
	.byte		0	; no source line information

	.section	.debug_abbrev
	.uleb128	DW_AT_type
	.uleb128	DW_FORM_ref4
	.section	.debug_info
	.long		.Luint8_t - .Lssinfo

	.section	.debug_abbrev
	.uleb128	DW_AT_external
	.uleb128	DW_FORM_flag
	.section	.debug_info
	.byte		1

	.section	.debug_abbrev
	.uleb128	DW_AT_location
	.uleb128	DW_FORM_block1
	.section	.debug_info
	.byte		5	; length of block
	.byte		DW_OP_addr
	.long		0x800000 + 0x01C0 + 0x0B

	.section	.debug_abbrev
	.uleb128	0
	.uleb128	0

;- - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
	;; DIE #114: variable NVM_CTRLB
	.section	.debug_info
	.uleb128	114	; ref to abbrev 114
	.section	.debug_abbrev
	.uleb128	114
	.uleb128	DW_TAG_variable
	.byte		DW_CHILDREN_no

	.uleb128	DW_AT_name
	.uleb128	DW_FORM_strp
	.section	.debug_str
.Lname114:
	.string		"NVM_CTRLB"
	.section	.debug_info
	.long		.Lname114

	.section	.debug_abbrev
	.uleb128	DW_AT_decl_file
	.uleb128	DW_FORM_data1
	.section	.debug_info
	.byte		0	; no source file information

	.section	.debug_abbrev
	.uleb128	DW_AT_decl_line
	.uleb128	DW_FORM_data1
	.section	.debug_info
	.byte		0	; no source line information

	.section	.debug_abbrev
	.uleb128	DW_AT_type
	.uleb128	DW_FORM_ref4
	.section	.debug_info
	.long		.Luint8_t - .Lssinfo

	.section	.debug_abbrev
	.uleb128	DW_AT_external
	.uleb128	DW_FORM_flag
	.section	.debug_info
	.byte		1

	.section	.debug_abbrev
	.uleb128	DW_AT_location
	.uleb128	DW_FORM_block1
	.section	.debug_info
	.byte		5	; length of block
	.byte		DW_OP_addr
	.long		0x800000 + 0x01C0 + 0x0C

	.section	.debug_abbrev
	.uleb128	0
	.uleb128	0

;- - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
	;; DIE #115: variable NVM_INTCTRL
	.section	.debug_info
	.uleb128	115	; ref to abbrev 115
	.section	.debug_abbrev
	.uleb128	115
	.uleb128	DW_TAG_variable
	.byte		DW_CHILDREN_no

	.uleb128	DW_AT_name
	.uleb128	DW_FORM_strp
	.section	.debug_str
.Lname115:
	.string		"NVM_INTCTRL"
	.section	.debug_info
	.long		.Lname115

	.section	.debug_abbrev
	.uleb128	DW_AT_decl_file
	.uleb128	DW_FORM_data1
	.section	.debug_info
	.byte		0	; no source file information

	.section	.debug_abbrev
	.uleb128	DW_AT_decl_line
	.uleb128	DW_FORM_data1
	.section	.debug_info
	.byte		0	; no source line information

	.section	.debug_abbrev
	.uleb128	DW_AT_type
	.uleb128	DW_FORM_ref4
	.section	.debug_info
	.long		.Luint8_t - .Lssinfo

	.section	.debug_abbrev
	.uleb128	DW_AT_external
	.uleb128	DW_FORM_flag
	.section	.debug_info
	.byte		1

	.section	.debug_abbrev
	.uleb128	DW_AT_location
	.uleb128	DW_FORM_block1
	.section	.debug_info
	.byte		5	; length of block
	.byte		DW_OP_addr
	.long		0x800000 + 0x01C0 + 0x0D

	.section	.debug_abbrev
	.uleb128	0
	.uleb128	0

;- - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
	;; DIE #116: variable NVM_STATUS
	.section	.debug_info
	.uleb128	116	; ref to abbrev 116
	.section	.debug_abbrev
	.uleb128	116
	.uleb128	DW_TAG_variable
	.byte		DW_CHILDREN_no

	.uleb128	DW_AT_name
	.uleb128	DW_FORM_strp
	.section	.debug_str
.Lname116:
	.string		"NVM_STATUS"
	.section	.debug_info
	.long		.Lname116

	.section	.debug_abbrev
	.uleb128	DW_AT_decl_file
	.uleb128	DW_FORM_data1
	.section	.debug_info
	.byte		0	; no source file information

	.section	.debug_abbrev
	.uleb128	DW_AT_decl_line
	.uleb128	DW_FORM_data1
	.section	.debug_info
	.byte		0	; no source line information

	.section	.debug_abbrev
	.uleb128	DW_AT_type
	.uleb128	DW_FORM_ref4
	.section	.debug_info
	.long		.Luint8_t - .Lssinfo

	.section	.debug_abbrev
	.uleb128	DW_AT_external
	.uleb128	DW_FORM_flag
	.section	.debug_info
	.byte		1

	.section	.debug_abbrev
	.uleb128	DW_AT_location
	.uleb128	DW_FORM_block1
	.section	.debug_info
	.byte		5	; length of block
	.byte		DW_OP_addr
	.long		0x800000 + 0x01C0 + 0x0F

	.section	.debug_abbrev
	.uleb128	0
	.uleb128	0

;- - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
	;; DIE #117: variable NVM_LOCKBITS
	.section	.debug_info
	.uleb128	117	; ref to abbrev 117
	.section	.debug_abbrev
	.uleb128	117
	.uleb128	DW_TAG_variable
	.byte		DW_CHILDREN_no

	.uleb128	DW_AT_name
	.uleb128	DW_FORM_strp
	.section	.debug_str
.Lname117:
	.string		"NVM_LOCKBITS"
	.section	.debug_info
	.long		.Lname117

	.section	.debug_abbrev
	.uleb128	DW_AT_decl_file
	.uleb128	DW_FORM_data1
	.section	.debug_info
	.byte		0	; no source file information

	.section	.debug_abbrev
	.uleb128	DW_AT_decl_line
	.uleb128	DW_FORM_data1
	.section	.debug_info
	.byte		0	; no source line information

	.section	.debug_abbrev
	.uleb128	DW_AT_type
	.uleb128	DW_FORM_ref4
	.section	.debug_info
	.long		.Luint8_t - .Lssinfo

	.section	.debug_abbrev
	.uleb128	DW_AT_external
	.uleb128	DW_FORM_flag
	.section	.debug_info
	.byte		1

	.section	.debug_abbrev
	.uleb128	DW_AT_location
	.uleb128	DW_FORM_block1
	.section	.debug_info
	.byte		5	; length of block
	.byte		DW_OP_addr
	.long		0x800000 + 0x01C0 + 0x10

	.section	.debug_abbrev
	.uleb128	0
	.uleb128	0

;- - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
	;; DIE #118: variable ADCA_CTRLA
	.section	.debug_info
	.uleb128	118	; ref to abbrev 118
	.section	.debug_abbrev
	.uleb128	118
	.uleb128	DW_TAG_variable
	.byte		DW_CHILDREN_no

	.uleb128	DW_AT_name
	.uleb128	DW_FORM_strp
	.section	.debug_str
.Lname118:
	.string		"ADCA_CTRLA"
	.section	.debug_info
	.long		.Lname118

	.section	.debug_abbrev
	.uleb128	DW_AT_decl_file
	.uleb128	DW_FORM_data1
	.section	.debug_info
	.byte		0	; no source file information

	.section	.debug_abbrev
	.uleb128	DW_AT_decl_line
	.uleb128	DW_FORM_data1
	.section	.debug_info
	.byte		0	; no source line information

	.section	.debug_abbrev
	.uleb128	DW_AT_type
	.uleb128	DW_FORM_ref4
	.section	.debug_info
	.long		.Luint8_t - .Lssinfo

	.section	.debug_abbrev
	.uleb128	DW_AT_external
	.uleb128	DW_FORM_flag
	.section	.debug_info
	.byte		1

	.section	.debug_abbrev
	.uleb128	DW_AT_location
	.uleb128	DW_FORM_block1
	.section	.debug_info
	.byte		5	; length of block
	.byte		DW_OP_addr
	.long		0x800000 + 0x0200 + 0x00

	.section	.debug_abbrev
	.uleb128	0
	.uleb128	0

;- - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
	;; DIE #119: variable ADCA_CTRLB
	.section	.debug_info
	.uleb128	119	; ref to abbrev 119
	.section	.debug_abbrev
	.uleb128	119
	.uleb128	DW_TAG_variable
	.byte		DW_CHILDREN_no

	.uleb128	DW_AT_name
	.uleb128	DW_FORM_strp
	.section	.debug_str
.Lname119:
	.string		"ADCA_CTRLB"
	.section	.debug_info
	.long		.Lname119

	.section	.debug_abbrev
	.uleb128	DW_AT_decl_file
	.uleb128	DW_FORM_data1
	.section	.debug_info
	.byte		0	; no source file information

	.section	.debug_abbrev
	.uleb128	DW_AT_decl_line
	.uleb128	DW_FORM_data1
	.section	.debug_info
	.byte		0	; no source line information

	.section	.debug_abbrev
	.uleb128	DW_AT_type
	.uleb128	DW_FORM_ref4
	.section	.debug_info
	.long		.Luint8_t - .Lssinfo

	.section	.debug_abbrev
	.uleb128	DW_AT_external
	.uleb128	DW_FORM_flag
	.section	.debug_info
	.byte		1

	.section	.debug_abbrev
	.uleb128	DW_AT_location
	.uleb128	DW_FORM_block1
	.section	.debug_info
	.byte		5	; length of block
	.byte		DW_OP_addr
	.long		0x800000 + 0x0200 + 0x01

	.section	.debug_abbrev
	.uleb128	0
	.uleb128	0

;- - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
	;; DIE #120: variable ADCA_REFCTRL
	.section	.debug_info
	.uleb128	120	; ref to abbrev 120
	.section	.debug_abbrev
	.uleb128	120
	.uleb128	DW_TAG_variable
	.byte		DW_CHILDREN_no

	.uleb128	DW_AT_name
	.uleb128	DW_FORM_strp
	.section	.debug_str
.Lname120:
	.string		"ADCA_REFCTRL"
	.section	.debug_info
	.long		.Lname120

	.section	.debug_abbrev
	.uleb128	DW_AT_decl_file
	.uleb128	DW_FORM_data1
	.section	.debug_info
	.byte		0	; no source file information

	.section	.debug_abbrev
	.uleb128	DW_AT_decl_line
	.uleb128	DW_FORM_data1
	.section	.debug_info
	.byte		0	; no source line information

	.section	.debug_abbrev
	.uleb128	DW_AT_type
	.uleb128	DW_FORM_ref4
	.section	.debug_info
	.long		.Luint8_t - .Lssinfo

	.section	.debug_abbrev
	.uleb128	DW_AT_external
	.uleb128	DW_FORM_flag
	.section	.debug_info
	.byte		1

	.section	.debug_abbrev
	.uleb128	DW_AT_location
	.uleb128	DW_FORM_block1
	.section	.debug_info
	.byte		5	; length of block
	.byte		DW_OP_addr
	.long		0x800000 + 0x0200 + 0x02

	.section	.debug_abbrev
	.uleb128	0
	.uleb128	0

;- - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
	;; DIE #121: variable ADCA_EVCTRL
	.section	.debug_info
	.uleb128	121	; ref to abbrev 121
	.section	.debug_abbrev
	.uleb128	121
	.uleb128	DW_TAG_variable
	.byte		DW_CHILDREN_no

	.uleb128	DW_AT_name
	.uleb128	DW_FORM_strp
	.section	.debug_str
.Lname121:
	.string		"ADCA_EVCTRL"
	.section	.debug_info
	.long		.Lname121

	.section	.debug_abbrev
	.uleb128	DW_AT_decl_file
	.uleb128	DW_FORM_data1
	.section	.debug_info
	.byte		0	; no source file information

	.section	.debug_abbrev
	.uleb128	DW_AT_decl_line
	.uleb128	DW_FORM_data1
	.section	.debug_info
	.byte		0	; no source line information

	.section	.debug_abbrev
	.uleb128	DW_AT_type
	.uleb128	DW_FORM_ref4
	.section	.debug_info
	.long		.Luint8_t - .Lssinfo

	.section	.debug_abbrev
	.uleb128	DW_AT_external
	.uleb128	DW_FORM_flag
	.section	.debug_info
	.byte		1

	.section	.debug_abbrev
	.uleb128	DW_AT_location
	.uleb128	DW_FORM_block1
	.section	.debug_info
	.byte		5	; length of block
	.byte		DW_OP_addr
	.long		0x800000 + 0x0200 + 0x03

	.section	.debug_abbrev
	.uleb128	0
	.uleb128	0

;- - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
	;; DIE #122: variable ADCA_PRESCALER
	.section	.debug_info
	.uleb128	122	; ref to abbrev 122
	.section	.debug_abbrev
	.uleb128	122
	.uleb128	DW_TAG_variable
	.byte		DW_CHILDREN_no

	.uleb128	DW_AT_name
	.uleb128	DW_FORM_strp
	.section	.debug_str
.Lname122:
	.string		"ADCA_PRESCALER"
	.section	.debug_info
	.long		.Lname122

	.section	.debug_abbrev
	.uleb128	DW_AT_decl_file
	.uleb128	DW_FORM_data1
	.section	.debug_info
	.byte		0	; no source file information

	.section	.debug_abbrev
	.uleb128	DW_AT_decl_line
	.uleb128	DW_FORM_data1
	.section	.debug_info
	.byte		0	; no source line information

	.section	.debug_abbrev
	.uleb128	DW_AT_type
	.uleb128	DW_FORM_ref4
	.section	.debug_info
	.long		.Luint8_t - .Lssinfo

	.section	.debug_abbrev
	.uleb128	DW_AT_external
	.uleb128	DW_FORM_flag
	.section	.debug_info
	.byte		1

	.section	.debug_abbrev
	.uleb128	DW_AT_location
	.uleb128	DW_FORM_block1
	.section	.debug_info
	.byte		5	; length of block
	.byte		DW_OP_addr
	.long		0x800000 + 0x0200 + 0x04

	.section	.debug_abbrev
	.uleb128	0
	.uleb128	0

;- - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
	;; DIE #123: variable ADCA_INTFLAGS
	.section	.debug_info
	.uleb128	123	; ref to abbrev 123
	.section	.debug_abbrev
	.uleb128	123
	.uleb128	DW_TAG_variable
	.byte		DW_CHILDREN_no

	.uleb128	DW_AT_name
	.uleb128	DW_FORM_strp
	.section	.debug_str
.Lname123:
	.string		"ADCA_INTFLAGS"
	.section	.debug_info
	.long		.Lname123

	.section	.debug_abbrev
	.uleb128	DW_AT_decl_file
	.uleb128	DW_FORM_data1
	.section	.debug_info
	.byte		0	; no source file information

	.section	.debug_abbrev
	.uleb128	DW_AT_decl_line
	.uleb128	DW_FORM_data1
	.section	.debug_info
	.byte		0	; no source line information

	.section	.debug_abbrev
	.uleb128	DW_AT_type
	.uleb128	DW_FORM_ref4
	.section	.debug_info
	.long		.Luint8_t - .Lssinfo

	.section	.debug_abbrev
	.uleb128	DW_AT_external
	.uleb128	DW_FORM_flag
	.section	.debug_info
	.byte		1

	.section	.debug_abbrev
	.uleb128	DW_AT_location
	.uleb128	DW_FORM_block1
	.section	.debug_info
	.byte		5	; length of block
	.byte		DW_OP_addr
	.long		0x800000 + 0x0200 + 0x06

	.section	.debug_abbrev
	.uleb128	0
	.uleb128	0

;- - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
	;; DIE #124: variable ADCA_TEMP
	.section	.debug_info
	.uleb128	124	; ref to abbrev 124
	.section	.debug_abbrev
	.uleb128	124
	.uleb128	DW_TAG_variable
	.byte		DW_CHILDREN_no

	.uleb128	DW_AT_name
	.uleb128	DW_FORM_strp
	.section	.debug_str
.Lname124:
	.string		"ADCA_TEMP"
	.section	.debug_info
	.long		.Lname124

	.section	.debug_abbrev
	.uleb128	DW_AT_decl_file
	.uleb128	DW_FORM_data1
	.section	.debug_info
	.byte		0	; no source file information

	.section	.debug_abbrev
	.uleb128	DW_AT_decl_line
	.uleb128	DW_FORM_data1
	.section	.debug_info
	.byte		0	; no source line information

	.section	.debug_abbrev
	.uleb128	DW_AT_type
	.uleb128	DW_FORM_ref4
	.section	.debug_info
	.long		.Luint8_t - .Lssinfo

	.section	.debug_abbrev
	.uleb128	DW_AT_external
	.uleb128	DW_FORM_flag
	.section	.debug_info
	.byte		1

	.section	.debug_abbrev
	.uleb128	DW_AT_location
	.uleb128	DW_FORM_block1
	.section	.debug_info
	.byte		5	; length of block
	.byte		DW_OP_addr
	.long		0x800000 + 0x0200 + 0x07

	.section	.debug_abbrev
	.uleb128	0
	.uleb128	0

;- - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
	;; DIE #125: variable ADCA_CAL
	.section	.debug_info
	.uleb128	125	; ref to abbrev 125
	.section	.debug_abbrev
	.uleb128	125
	.uleb128	DW_TAG_variable
	.byte		DW_CHILDREN_no

	.uleb128	DW_AT_name
	.uleb128	DW_FORM_strp
	.section	.debug_str
.Lname125:
	.string		"ADCA_CAL"
	.section	.debug_info
	.long		.Lname125

	.section	.debug_abbrev
	.uleb128	DW_AT_decl_file
	.uleb128	DW_FORM_data1
	.section	.debug_info
	.byte		0	; no source file information

	.section	.debug_abbrev
	.uleb128	DW_AT_decl_line
	.uleb128	DW_FORM_data1
	.section	.debug_info
	.byte		0	; no source line information

	.section	.debug_abbrev
	.uleb128	DW_AT_type
	.uleb128	DW_FORM_ref4
	.section	.debug_info
	.long		.Luint16_t - .Lssinfo

	.section	.debug_abbrev
	.uleb128	DW_AT_external
	.uleb128	DW_FORM_flag
	.section	.debug_info
	.byte		1

	.section	.debug_abbrev
	.uleb128	DW_AT_location
	.uleb128	DW_FORM_block1
	.section	.debug_info
	.byte		5	; length of block
	.byte		DW_OP_addr
	.long		0x800000 + 0x0200 + 0x0C

	.section	.debug_abbrev
	.uleb128	0
	.uleb128	0

;- - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
	;; DIE #126: variable ADCA_CH0RES
	.section	.debug_info
	.uleb128	126	; ref to abbrev 126
	.section	.debug_abbrev
	.uleb128	126
	.uleb128	DW_TAG_variable
	.byte		DW_CHILDREN_no

	.uleb128	DW_AT_name
	.uleb128	DW_FORM_strp
	.section	.debug_str
.Lname126:
	.string		"ADCA_CH0RES"
	.section	.debug_info
	.long		.Lname126

	.section	.debug_abbrev
	.uleb128	DW_AT_decl_file
	.uleb128	DW_FORM_data1
	.section	.debug_info
	.byte		0	; no source file information

	.section	.debug_abbrev
	.uleb128	DW_AT_decl_line
	.uleb128	DW_FORM_data1
	.section	.debug_info
	.byte		0	; no source line information

	.section	.debug_abbrev
	.uleb128	DW_AT_type
	.uleb128	DW_FORM_ref4
	.section	.debug_info
	.long		.Luint16_t - .Lssinfo

	.section	.debug_abbrev
	.uleb128	DW_AT_external
	.uleb128	DW_FORM_flag
	.section	.debug_info
	.byte		1

	.section	.debug_abbrev
	.uleb128	DW_AT_location
	.uleb128	DW_FORM_block1
	.section	.debug_info
	.byte		5	; length of block
	.byte		DW_OP_addr
	.long		0x800000 + 0x0200 + 0x10

	.section	.debug_abbrev
	.uleb128	0
	.uleb128	0

;- - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
	;; DIE #127: variable ADCA_CMP
	.section	.debug_info
	.uleb128	127	; ref to abbrev 127
	.section	.debug_abbrev
	.uleb128	127
	.uleb128	DW_TAG_variable
	.byte		DW_CHILDREN_no

	.uleb128	DW_AT_name
	.uleb128	DW_FORM_strp
	.section	.debug_str
.Lname127:
	.string		"ADCA_CMP"
	.section	.debug_info
	.long		.Lname127

	.section	.debug_abbrev
	.uleb128	DW_AT_decl_file
	.uleb128	DW_FORM_data1
	.section	.debug_info
	.byte		0	; no source file information

	.section	.debug_abbrev
	.uleb128	DW_AT_decl_line
	.uleb128	DW_FORM_data1
	.section	.debug_info
	.byte		0	; no source line information

	.section	.debug_abbrev
	.uleb128	DW_AT_type
	.uleb128	DW_FORM_ref4
	.section	.debug_info
	.long		.Luint16_t - .Lssinfo

	.section	.debug_abbrev
	.uleb128	DW_AT_external
	.uleb128	DW_FORM_flag
	.section	.debug_info
	.byte		1

	.section	.debug_abbrev
	.uleb128	DW_AT_location
	.uleb128	DW_FORM_block1
	.section	.debug_info
	.byte		5	; length of block
	.byte		DW_OP_addr
	.long		0x800000 + 0x0200 + 0x18

	.section	.debug_abbrev
	.uleb128	0
	.uleb128	0

;- - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
	;; DIE #128: variable ACA_AC0CTRL
	.section	.debug_info
	.uleb128	128	; ref to abbrev 128
	.section	.debug_abbrev
	.uleb128	128
	.uleb128	DW_TAG_variable
	.byte		DW_CHILDREN_no

	.uleb128	DW_AT_name
	.uleb128	DW_FORM_strp
	.section	.debug_str
.Lname128:
	.string		"ACA_AC0CTRL"
	.section	.debug_info
	.long		.Lname128

	.section	.debug_abbrev
	.uleb128	DW_AT_decl_file
	.uleb128	DW_FORM_data1
	.section	.debug_info
	.byte		0	; no source file information

	.section	.debug_abbrev
	.uleb128	DW_AT_decl_line
	.uleb128	DW_FORM_data1
	.section	.debug_info
	.byte		0	; no source line information

	.section	.debug_abbrev
	.uleb128	DW_AT_type
	.uleb128	DW_FORM_ref4
	.section	.debug_info
	.long		.Luint8_t - .Lssinfo

	.section	.debug_abbrev
	.uleb128	DW_AT_external
	.uleb128	DW_FORM_flag
	.section	.debug_info
	.byte		1

	.section	.debug_abbrev
	.uleb128	DW_AT_location
	.uleb128	DW_FORM_block1
	.section	.debug_info
	.byte		5	; length of block
	.byte		DW_OP_addr
	.long		0x800000 + 0x0380 + 0x00

	.section	.debug_abbrev
	.uleb128	0
	.uleb128	0

;- - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
	;; DIE #129: variable ACA_AC1CTRL
	.section	.debug_info
	.uleb128	129	; ref to abbrev 129
	.section	.debug_abbrev
	.uleb128	129
	.uleb128	DW_TAG_variable
	.byte		DW_CHILDREN_no

	.uleb128	DW_AT_name
	.uleb128	DW_FORM_strp
	.section	.debug_str
.Lname129:
	.string		"ACA_AC1CTRL"
	.section	.debug_info
	.long		.Lname129

	.section	.debug_abbrev
	.uleb128	DW_AT_decl_file
	.uleb128	DW_FORM_data1
	.section	.debug_info
	.byte		0	; no source file information

	.section	.debug_abbrev
	.uleb128	DW_AT_decl_line
	.uleb128	DW_FORM_data1
	.section	.debug_info
	.byte		0	; no source line information

	.section	.debug_abbrev
	.uleb128	DW_AT_type
	.uleb128	DW_FORM_ref4
	.section	.debug_info
	.long		.Luint8_t - .Lssinfo

	.section	.debug_abbrev
	.uleb128	DW_AT_external
	.uleb128	DW_FORM_flag
	.section	.debug_info
	.byte		1

	.section	.debug_abbrev
	.uleb128	DW_AT_location
	.uleb128	DW_FORM_block1
	.section	.debug_info
	.byte		5	; length of block
	.byte		DW_OP_addr
	.long		0x800000 + 0x0380 + 0x01

	.section	.debug_abbrev
	.uleb128	0
	.uleb128	0

;- - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
	;; DIE #130: variable ACA_AC0MUXCTRL
	.section	.debug_info
	.uleb128	130	; ref to abbrev 130
	.section	.debug_abbrev
	.uleb128	130
	.uleb128	DW_TAG_variable
	.byte		DW_CHILDREN_no

	.uleb128	DW_AT_name
	.uleb128	DW_FORM_strp
	.section	.debug_str
.Lname130:
	.string		"ACA_AC0MUXCTRL"
	.section	.debug_info
	.long		.Lname130

	.section	.debug_abbrev
	.uleb128	DW_AT_decl_file
	.uleb128	DW_FORM_data1
	.section	.debug_info
	.byte		0	; no source file information

	.section	.debug_abbrev
	.uleb128	DW_AT_decl_line
	.uleb128	DW_FORM_data1
	.section	.debug_info
	.byte		0	; no source line information

	.section	.debug_abbrev
	.uleb128	DW_AT_type
	.uleb128	DW_FORM_ref4
	.section	.debug_info
	.long		.Luint8_t - .Lssinfo

	.section	.debug_abbrev
	.uleb128	DW_AT_external
	.uleb128	DW_FORM_flag
	.section	.debug_info
	.byte		1

	.section	.debug_abbrev
	.uleb128	DW_AT_location
	.uleb128	DW_FORM_block1
	.section	.debug_info
	.byte		5	; length of block
	.byte		DW_OP_addr
	.long		0x800000 + 0x0380 + 0x02

	.section	.debug_abbrev
	.uleb128	0
	.uleb128	0

;- - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
	;; DIE #131: variable ACA_AC1MUXCTRL
	.section	.debug_info
	.uleb128	131	; ref to abbrev 131
	.section	.debug_abbrev
	.uleb128	131
	.uleb128	DW_TAG_variable
	.byte		DW_CHILDREN_no

	.uleb128	DW_AT_name
	.uleb128	DW_FORM_strp
	.section	.debug_str
.Lname131:
	.string		"ACA_AC1MUXCTRL"
	.section	.debug_info
	.long		.Lname131

	.section	.debug_abbrev
	.uleb128	DW_AT_decl_file
	.uleb128	DW_FORM_data1
	.section	.debug_info
	.byte		0	; no source file information

	.section	.debug_abbrev
	.uleb128	DW_AT_decl_line
	.uleb128	DW_FORM_data1
	.section	.debug_info
	.byte		0	; no source line information

	.section	.debug_abbrev
	.uleb128	DW_AT_type
	.uleb128	DW_FORM_ref4
	.section	.debug_info
	.long		.Luint8_t - .Lssinfo

	.section	.debug_abbrev
	.uleb128	DW_AT_external
	.uleb128	DW_FORM_flag
	.section	.debug_info
	.byte		1

	.section	.debug_abbrev
	.uleb128	DW_AT_location
	.uleb128	DW_FORM_block1
	.section	.debug_info
	.byte		5	; length of block
	.byte		DW_OP_addr
	.long		0x800000 + 0x0380 + 0x03

	.section	.debug_abbrev
	.uleb128	0
	.uleb128	0

;- - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
	;; DIE #132: variable ACA_CTRLA
	.section	.debug_info
	.uleb128	132	; ref to abbrev 132
	.section	.debug_abbrev
	.uleb128	132
	.uleb128	DW_TAG_variable
	.byte		DW_CHILDREN_no

	.uleb128	DW_AT_name
	.uleb128	DW_FORM_strp
	.section	.debug_str
.Lname132:
	.string		"ACA_CTRLA"
	.section	.debug_info
	.long		.Lname132

	.section	.debug_abbrev
	.uleb128	DW_AT_decl_file
	.uleb128	DW_FORM_data1
	.section	.debug_info
	.byte		0	; no source file information

	.section	.debug_abbrev
	.uleb128	DW_AT_decl_line
	.uleb128	DW_FORM_data1
	.section	.debug_info
	.byte		0	; no source line information

	.section	.debug_abbrev
	.uleb128	DW_AT_type
	.uleb128	DW_FORM_ref4
	.section	.debug_info
	.long		.Luint8_t - .Lssinfo

	.section	.debug_abbrev
	.uleb128	DW_AT_external
	.uleb128	DW_FORM_flag
	.section	.debug_info
	.byte		1

	.section	.debug_abbrev
	.uleb128	DW_AT_location
	.uleb128	DW_FORM_block1
	.section	.debug_info
	.byte		5	; length of block
	.byte		DW_OP_addr
	.long		0x800000 + 0x0380 + 0x04

	.section	.debug_abbrev
	.uleb128	0
	.uleb128	0

;- - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
	;; DIE #133: variable ACA_CTRLB
	.section	.debug_info
	.uleb128	133	; ref to abbrev 133
	.section	.debug_abbrev
	.uleb128	133
	.uleb128	DW_TAG_variable
	.byte		DW_CHILDREN_no

	.uleb128	DW_AT_name
	.uleb128	DW_FORM_strp
	.section	.debug_str
.Lname133:
	.string		"ACA_CTRLB"
	.section	.debug_info
	.long		.Lname133

	.section	.debug_abbrev
	.uleb128	DW_AT_decl_file
	.uleb128	DW_FORM_data1
	.section	.debug_info
	.byte		0	; no source file information

	.section	.debug_abbrev
	.uleb128	DW_AT_decl_line
	.uleb128	DW_FORM_data1
	.section	.debug_info
	.byte		0	; no source line information

	.section	.debug_abbrev
	.uleb128	DW_AT_type
	.uleb128	DW_FORM_ref4
	.section	.debug_info
	.long		.Luint8_t - .Lssinfo

	.section	.debug_abbrev
	.uleb128	DW_AT_external
	.uleb128	DW_FORM_flag
	.section	.debug_info
	.byte		1

	.section	.debug_abbrev
	.uleb128	DW_AT_location
	.uleb128	DW_FORM_block1
	.section	.debug_info
	.byte		5	; length of block
	.byte		DW_OP_addr
	.long		0x800000 + 0x0380 + 0x05

	.section	.debug_abbrev
	.uleb128	0
	.uleb128	0

;- - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
	;; DIE #134: variable ACA_WINCTRL
	.section	.debug_info
	.uleb128	134	; ref to abbrev 134
	.section	.debug_abbrev
	.uleb128	134
	.uleb128	DW_TAG_variable
	.byte		DW_CHILDREN_no

	.uleb128	DW_AT_name
	.uleb128	DW_FORM_strp
	.section	.debug_str
.Lname134:
	.string		"ACA_WINCTRL"
	.section	.debug_info
	.long		.Lname134

	.section	.debug_abbrev
	.uleb128	DW_AT_decl_file
	.uleb128	DW_FORM_data1
	.section	.debug_info
	.byte		0	; no source file information

	.section	.debug_abbrev
	.uleb128	DW_AT_decl_line
	.uleb128	DW_FORM_data1
	.section	.debug_info
	.byte		0	; no source line information

	.section	.debug_abbrev
	.uleb128	DW_AT_type
	.uleb128	DW_FORM_ref4
	.section	.debug_info
	.long		.Luint8_t - .Lssinfo

	.section	.debug_abbrev
	.uleb128	DW_AT_external
	.uleb128	DW_FORM_flag
	.section	.debug_info
	.byte		1

	.section	.debug_abbrev
	.uleb128	DW_AT_location
	.uleb128	DW_FORM_block1
	.section	.debug_info
	.byte		5	; length of block
	.byte		DW_OP_addr
	.long		0x800000 + 0x0380 + 0x06

	.section	.debug_abbrev
	.uleb128	0
	.uleb128	0

;- - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
	;; DIE #135: variable ACA_STATUS
	.section	.debug_info
	.uleb128	135	; ref to abbrev 135
	.section	.debug_abbrev
	.uleb128	135
	.uleb128	DW_TAG_variable
	.byte		DW_CHILDREN_no

	.uleb128	DW_AT_name
	.uleb128	DW_FORM_strp
	.section	.debug_str
.Lname135:
	.string		"ACA_STATUS"
	.section	.debug_info
	.long		.Lname135

	.section	.debug_abbrev
	.uleb128	DW_AT_decl_file
	.uleb128	DW_FORM_data1
	.section	.debug_info
	.byte		0	; no source file information

	.section	.debug_abbrev
	.uleb128	DW_AT_decl_line
	.uleb128	DW_FORM_data1
	.section	.debug_info
	.byte		0	; no source line information

	.section	.debug_abbrev
	.uleb128	DW_AT_type
	.uleb128	DW_FORM_ref4
	.section	.debug_info
	.long		.Luint8_t - .Lssinfo

	.section	.debug_abbrev
	.uleb128	DW_AT_external
	.uleb128	DW_FORM_flag
	.section	.debug_info
	.byte		1

	.section	.debug_abbrev
	.uleb128	DW_AT_location
	.uleb128	DW_FORM_block1
	.section	.debug_info
	.byte		5	; length of block
	.byte		DW_OP_addr
	.long		0x800000 + 0x0380 + 0x07

	.section	.debug_abbrev
	.uleb128	0
	.uleb128	0

;- - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
	;; DIE #136: variable RTC_CTRL
	.section	.debug_info
	.uleb128	136	; ref to abbrev 136
	.section	.debug_abbrev
	.uleb128	136
	.uleb128	DW_TAG_variable
	.byte		DW_CHILDREN_no

	.uleb128	DW_AT_name
	.uleb128	DW_FORM_strp
	.section	.debug_str
.Lname136:
	.string		"RTC_CTRL"
	.section	.debug_info
	.long		.Lname136

	.section	.debug_abbrev
	.uleb128	DW_AT_decl_file
	.uleb128	DW_FORM_data1
	.section	.debug_info
	.byte		0	; no source file information

	.section	.debug_abbrev
	.uleb128	DW_AT_decl_line
	.uleb128	DW_FORM_data1
	.section	.debug_info
	.byte		0	; no source line information

	.section	.debug_abbrev
	.uleb128	DW_AT_type
	.uleb128	DW_FORM_ref4
	.section	.debug_info
	.long		.Luint8_t - .Lssinfo

	.section	.debug_abbrev
	.uleb128	DW_AT_external
	.uleb128	DW_FORM_flag
	.section	.debug_info
	.byte		1

	.section	.debug_abbrev
	.uleb128	DW_AT_location
	.uleb128	DW_FORM_block1
	.section	.debug_info
	.byte		5	; length of block
	.byte		DW_OP_addr
	.long		0x800000 + 0x0400 + 0x00

	.section	.debug_abbrev
	.uleb128	0
	.uleb128	0

;- - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
	;; DIE #137: variable RTC_STATUS
	.section	.debug_info
	.uleb128	137	; ref to abbrev 137
	.section	.debug_abbrev
	.uleb128	137
	.uleb128	DW_TAG_variable
	.byte		DW_CHILDREN_no

	.uleb128	DW_AT_name
	.uleb128	DW_FORM_strp
	.section	.debug_str
.Lname137:
	.string		"RTC_STATUS"
	.section	.debug_info
	.long		.Lname137

	.section	.debug_abbrev
	.uleb128	DW_AT_decl_file
	.uleb128	DW_FORM_data1
	.section	.debug_info
	.byte		0	; no source file information

	.section	.debug_abbrev
	.uleb128	DW_AT_decl_line
	.uleb128	DW_FORM_data1
	.section	.debug_info
	.byte		0	; no source line information

	.section	.debug_abbrev
	.uleb128	DW_AT_type
	.uleb128	DW_FORM_ref4
	.section	.debug_info
	.long		.Luint8_t - .Lssinfo

	.section	.debug_abbrev
	.uleb128	DW_AT_external
	.uleb128	DW_FORM_flag
	.section	.debug_info
	.byte		1

	.section	.debug_abbrev
	.uleb128	DW_AT_location
	.uleb128	DW_FORM_block1
	.section	.debug_info
	.byte		5	; length of block
	.byte		DW_OP_addr
	.long		0x800000 + 0x0400 + 0x01

	.section	.debug_abbrev
	.uleb128	0
	.uleb128	0

;- - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
	;; DIE #138: variable RTC_INTCTRL
	.section	.debug_info
	.uleb128	138	; ref to abbrev 138
	.section	.debug_abbrev
	.uleb128	138
	.uleb128	DW_TAG_variable
	.byte		DW_CHILDREN_no

	.uleb128	DW_AT_name
	.uleb128	DW_FORM_strp
	.section	.debug_str
.Lname138:
	.string		"RTC_INTCTRL"
	.section	.debug_info
	.long		.Lname138

	.section	.debug_abbrev
	.uleb128	DW_AT_decl_file
	.uleb128	DW_FORM_data1
	.section	.debug_info
	.byte		0	; no source file information

	.section	.debug_abbrev
	.uleb128	DW_AT_decl_line
	.uleb128	DW_FORM_data1
	.section	.debug_info
	.byte		0	; no source line information

	.section	.debug_abbrev
	.uleb128	DW_AT_type
	.uleb128	DW_FORM_ref4
	.section	.debug_info
	.long		.Luint8_t - .Lssinfo

	.section	.debug_abbrev
	.uleb128	DW_AT_external
	.uleb128	DW_FORM_flag
	.section	.debug_info
	.byte		1

	.section	.debug_abbrev
	.uleb128	DW_AT_location
	.uleb128	DW_FORM_block1
	.section	.debug_info
	.byte		5	; length of block
	.byte		DW_OP_addr
	.long		0x800000 + 0x0400 + 0x02

	.section	.debug_abbrev
	.uleb128	0
	.uleb128	0

;- - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
	;; DIE #139: variable RTC_INTFLAGS
	.section	.debug_info
	.uleb128	139	; ref to abbrev 139
	.section	.debug_abbrev
	.uleb128	139
	.uleb128	DW_TAG_variable
	.byte		DW_CHILDREN_no

	.uleb128	DW_AT_name
	.uleb128	DW_FORM_strp
	.section	.debug_str
.Lname139:
	.string		"RTC_INTFLAGS"
	.section	.debug_info
	.long		.Lname139

	.section	.debug_abbrev
	.uleb128	DW_AT_decl_file
	.uleb128	DW_FORM_data1
	.section	.debug_info
	.byte		0	; no source file information

	.section	.debug_abbrev
	.uleb128	DW_AT_decl_line
	.uleb128	DW_FORM_data1
	.section	.debug_info
	.byte		0	; no source line information

	.section	.debug_abbrev
	.uleb128	DW_AT_type
	.uleb128	DW_FORM_ref4
	.section	.debug_info
	.long		.Luint8_t - .Lssinfo

	.section	.debug_abbrev
	.uleb128	DW_AT_external
	.uleb128	DW_FORM_flag
	.section	.debug_info
	.byte		1

	.section	.debug_abbrev
	.uleb128	DW_AT_location
	.uleb128	DW_FORM_block1
	.section	.debug_info
	.byte		5	; length of block
	.byte		DW_OP_addr
	.long		0x800000 + 0x0400 + 0x03

	.section	.debug_abbrev
	.uleb128	0
	.uleb128	0

;- - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
	;; DIE #140: variable RTC_TEMP
	.section	.debug_info
	.uleb128	140	; ref to abbrev 140
	.section	.debug_abbrev
	.uleb128	140
	.uleb128	DW_TAG_variable
	.byte		DW_CHILDREN_no

	.uleb128	DW_AT_name
	.uleb128	DW_FORM_strp
	.section	.debug_str
.Lname140:
	.string		"RTC_TEMP"
	.section	.debug_info
	.long		.Lname140

	.section	.debug_abbrev
	.uleb128	DW_AT_decl_file
	.uleb128	DW_FORM_data1
	.section	.debug_info
	.byte		0	; no source file information

	.section	.debug_abbrev
	.uleb128	DW_AT_decl_line
	.uleb128	DW_FORM_data1
	.section	.debug_info
	.byte		0	; no source line information

	.section	.debug_abbrev
	.uleb128	DW_AT_type
	.uleb128	DW_FORM_ref4
	.section	.debug_info
	.long		.Luint8_t - .Lssinfo

	.section	.debug_abbrev
	.uleb128	DW_AT_external
	.uleb128	DW_FORM_flag
	.section	.debug_info
	.byte		1

	.section	.debug_abbrev
	.uleb128	DW_AT_location
	.uleb128	DW_FORM_block1
	.section	.debug_info
	.byte		5	; length of block
	.byte		DW_OP_addr
	.long		0x800000 + 0x0400 + 0x04

	.section	.debug_abbrev
	.uleb128	0
	.uleb128	0

;- - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
	;; DIE #141: variable RTC_CNT
	.section	.debug_info
	.uleb128	141	; ref to abbrev 141
	.section	.debug_abbrev
	.uleb128	141
	.uleb128	DW_TAG_variable
	.byte		DW_CHILDREN_no

	.uleb128	DW_AT_name
	.uleb128	DW_FORM_strp
	.section	.debug_str
.Lname141:
	.string		"RTC_CNT"
	.section	.debug_info
	.long		.Lname141

	.section	.debug_abbrev
	.uleb128	DW_AT_decl_file
	.uleb128	DW_FORM_data1
	.section	.debug_info
	.byte		0	; no source file information

	.section	.debug_abbrev
	.uleb128	DW_AT_decl_line
	.uleb128	DW_FORM_data1
	.section	.debug_info
	.byte		0	; no source line information

	.section	.debug_abbrev
	.uleb128	DW_AT_type
	.uleb128	DW_FORM_ref4
	.section	.debug_info
	.long		.Luint16_t - .Lssinfo

	.section	.debug_abbrev
	.uleb128	DW_AT_external
	.uleb128	DW_FORM_flag
	.section	.debug_info
	.byte		1

	.section	.debug_abbrev
	.uleb128	DW_AT_location
	.uleb128	DW_FORM_block1
	.section	.debug_info
	.byte		5	; length of block
	.byte		DW_OP_addr
	.long		0x800000 + 0x0400 + 0x08

	.section	.debug_abbrev
	.uleb128	0
	.uleb128	0

;- - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
	;; DIE #142: variable RTC_PER
	.section	.debug_info
	.uleb128	142	; ref to abbrev 142
	.section	.debug_abbrev
	.uleb128	142
	.uleb128	DW_TAG_variable
	.byte		DW_CHILDREN_no

	.uleb128	DW_AT_name
	.uleb128	DW_FORM_strp
	.section	.debug_str
.Lname142:
	.string		"RTC_PER"
	.section	.debug_info
	.long		.Lname142

	.section	.debug_abbrev
	.uleb128	DW_AT_decl_file
	.uleb128	DW_FORM_data1
	.section	.debug_info
	.byte		0	; no source file information

	.section	.debug_abbrev
	.uleb128	DW_AT_decl_line
	.uleb128	DW_FORM_data1
	.section	.debug_info
	.byte		0	; no source line information

	.section	.debug_abbrev
	.uleb128	DW_AT_type
	.uleb128	DW_FORM_ref4
	.section	.debug_info
	.long		.Luint16_t - .Lssinfo

	.section	.debug_abbrev
	.uleb128	DW_AT_external
	.uleb128	DW_FORM_flag
	.section	.debug_info
	.byte		1

	.section	.debug_abbrev
	.uleb128	DW_AT_location
	.uleb128	DW_FORM_block1
	.section	.debug_info
	.byte		5	; length of block
	.byte		DW_OP_addr
	.long		0x800000 + 0x0400 + 0x0A

	.section	.debug_abbrev
	.uleb128	0
	.uleb128	0

;- - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
	;; DIE #143: variable RTC_COMP
	.section	.debug_info
	.uleb128	143	; ref to abbrev 143
	.section	.debug_abbrev
	.uleb128	143
	.uleb128	DW_TAG_variable
	.byte		DW_CHILDREN_no

	.uleb128	DW_AT_name
	.uleb128	DW_FORM_strp
	.section	.debug_str
.Lname143:
	.string		"RTC_COMP"
	.section	.debug_info
	.long		.Lname143

	.section	.debug_abbrev
	.uleb128	DW_AT_decl_file
	.uleb128	DW_FORM_data1
	.section	.debug_info
	.byte		0	; no source file information

	.section	.debug_abbrev
	.uleb128	DW_AT_decl_line
	.uleb128	DW_FORM_data1
	.section	.debug_info
	.byte		0	; no source line information

	.section	.debug_abbrev
	.uleb128	DW_AT_type
	.uleb128	DW_FORM_ref4
	.section	.debug_info
	.long		.Luint16_t - .Lssinfo

	.section	.debug_abbrev
	.uleb128	DW_AT_external
	.uleb128	DW_FORM_flag
	.section	.debug_info
	.byte		1

	.section	.debug_abbrev
	.uleb128	DW_AT_location
	.uleb128	DW_FORM_block1
	.section	.debug_info
	.byte		5	; length of block
	.byte		DW_OP_addr
	.long		0x800000 + 0x0400 + 0x0C

	.section	.debug_abbrev
	.uleb128	0
	.uleb128	0

;- - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
	;; DIE #144: variable TWIC_CTRL
	.section	.debug_info
	.uleb128	144	; ref to abbrev 144
	.section	.debug_abbrev
	.uleb128	144
	.uleb128	DW_TAG_variable
	.byte		DW_CHILDREN_no

	.uleb128	DW_AT_name
	.uleb128	DW_FORM_strp
	.section	.debug_str
.Lname144:
	.string		"TWIC_CTRL"
	.section	.debug_info
	.long		.Lname144

	.section	.debug_abbrev
	.uleb128	DW_AT_decl_file
	.uleb128	DW_FORM_data1
	.section	.debug_info
	.byte		0	; no source file information

	.section	.debug_abbrev
	.uleb128	DW_AT_decl_line
	.uleb128	DW_FORM_data1
	.section	.debug_info
	.byte		0	; no source line information

	.section	.debug_abbrev
	.uleb128	DW_AT_type
	.uleb128	DW_FORM_ref4
	.section	.debug_info
	.long		.Luint8_t - .Lssinfo

	.section	.debug_abbrev
	.uleb128	DW_AT_external
	.uleb128	DW_FORM_flag
	.section	.debug_info
	.byte		1

	.section	.debug_abbrev
	.uleb128	DW_AT_location
	.uleb128	DW_FORM_block1
	.section	.debug_info
	.byte		5	; length of block
	.byte		DW_OP_addr
	.long		0x800000 + 0x480 + 0x00

	.section	.debug_abbrev
	.uleb128	0
	.uleb128	0

;- - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
	;; DIE #145: variable TWIE_CTRL
	.section	.debug_info
	.uleb128	145	; ref to abbrev 145
	.section	.debug_abbrev
	.uleb128	145
	.uleb128	DW_TAG_variable
	.byte		DW_CHILDREN_no

	.uleb128	DW_AT_name
	.uleb128	DW_FORM_strp
	.section	.debug_str
.Lname145:
	.string		"TWIE_CTRL"
	.section	.debug_info
	.long		.Lname145

	.section	.debug_abbrev
	.uleb128	DW_AT_decl_file
	.uleb128	DW_FORM_data1
	.section	.debug_info
	.byte		0	; no source file information

	.section	.debug_abbrev
	.uleb128	DW_AT_decl_line
	.uleb128	DW_FORM_data1
	.section	.debug_info
	.byte		0	; no source line information

	.section	.debug_abbrev
	.uleb128	DW_AT_type
	.uleb128	DW_FORM_ref4
	.section	.debug_info
	.long		.Luint8_t - .Lssinfo

	.section	.debug_abbrev
	.uleb128	DW_AT_external
	.uleb128	DW_FORM_flag
	.section	.debug_info
	.byte		1

	.section	.debug_abbrev
	.uleb128	DW_AT_location
	.uleb128	DW_FORM_block1
	.section	.debug_info
	.byte		5	; length of block
	.byte		DW_OP_addr
	.long		0x800000 + 0x4A0 + 0x00

	.section	.debug_abbrev
	.uleb128	0
	.uleb128	0

;- - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
	;; DIE #146: variable USB_CTRLA
	.section	.debug_info
	.uleb128	146	; ref to abbrev 146
	.section	.debug_abbrev
	.uleb128	146
	.uleb128	DW_TAG_variable
	.byte		DW_CHILDREN_no

	.uleb128	DW_AT_name
	.uleb128	DW_FORM_strp
	.section	.debug_str
.Lname146:
	.string		"USB_CTRLA"
	.section	.debug_info
	.long		.Lname146

	.section	.debug_abbrev
	.uleb128	DW_AT_decl_file
	.uleb128	DW_FORM_data1
	.section	.debug_info
	.byte		0	; no source file information

	.section	.debug_abbrev
	.uleb128	DW_AT_decl_line
	.uleb128	DW_FORM_data1
	.section	.debug_info
	.byte		0	; no source line information

	.section	.debug_abbrev
	.uleb128	DW_AT_type
	.uleb128	DW_FORM_ref4
	.section	.debug_info
	.long		.Luint8_t - .Lssinfo

	.section	.debug_abbrev
	.uleb128	DW_AT_external
	.uleb128	DW_FORM_flag
	.section	.debug_info
	.byte		1

	.section	.debug_abbrev
	.uleb128	DW_AT_location
	.uleb128	DW_FORM_block1
	.section	.debug_info
	.byte		5	; length of block
	.byte		DW_OP_addr
	.long		0x800000 + 0x4C0 + 0x00

	.section	.debug_abbrev
	.uleb128	0
	.uleb128	0

;- - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
	;; DIE #147: variable USB_CTRLB
	.section	.debug_info
	.uleb128	147	; ref to abbrev 147
	.section	.debug_abbrev
	.uleb128	147
	.uleb128	DW_TAG_variable
	.byte		DW_CHILDREN_no

	.uleb128	DW_AT_name
	.uleb128	DW_FORM_strp
	.section	.debug_str
.Lname147:
	.string		"USB_CTRLB"
	.section	.debug_info
	.long		.Lname147

	.section	.debug_abbrev
	.uleb128	DW_AT_decl_file
	.uleb128	DW_FORM_data1
	.section	.debug_info
	.byte		0	; no source file information

	.section	.debug_abbrev
	.uleb128	DW_AT_decl_line
	.uleb128	DW_FORM_data1
	.section	.debug_info
	.byte		0	; no source line information

	.section	.debug_abbrev
	.uleb128	DW_AT_type
	.uleb128	DW_FORM_ref4
	.section	.debug_info
	.long		.Luint8_t - .Lssinfo

	.section	.debug_abbrev
	.uleb128	DW_AT_external
	.uleb128	DW_FORM_flag
	.section	.debug_info
	.byte		1

	.section	.debug_abbrev
	.uleb128	DW_AT_location
	.uleb128	DW_FORM_block1
	.section	.debug_info
	.byte		5	; length of block
	.byte		DW_OP_addr
	.long		0x800000 + 0x4C0 + 0x01

	.section	.debug_abbrev
	.uleb128	0
	.uleb128	0

;- - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
	;; DIE #148: variable USB_STATUS
	.section	.debug_info
	.uleb128	148	; ref to abbrev 148
	.section	.debug_abbrev
	.uleb128	148
	.uleb128	DW_TAG_variable
	.byte		DW_CHILDREN_no

	.uleb128	DW_AT_name
	.uleb128	DW_FORM_strp
	.section	.debug_str
.Lname148:
	.string		"USB_STATUS"
	.section	.debug_info
	.long		.Lname148

	.section	.debug_abbrev
	.uleb128	DW_AT_decl_file
	.uleb128	DW_FORM_data1
	.section	.debug_info
	.byte		0	; no source file information

	.section	.debug_abbrev
	.uleb128	DW_AT_decl_line
	.uleb128	DW_FORM_data1
	.section	.debug_info
	.byte		0	; no source line information

	.section	.debug_abbrev
	.uleb128	DW_AT_type
	.uleb128	DW_FORM_ref4
	.section	.debug_info
	.long		.Luint8_t - .Lssinfo

	.section	.debug_abbrev
	.uleb128	DW_AT_external
	.uleb128	DW_FORM_flag
	.section	.debug_info
	.byte		1

	.section	.debug_abbrev
	.uleb128	DW_AT_location
	.uleb128	DW_FORM_block1
	.section	.debug_info
	.byte		5	; length of block
	.byte		DW_OP_addr
	.long		0x800000 + 0x4C0 + 0x02

	.section	.debug_abbrev
	.uleb128	0
	.uleb128	0

;- - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
	;; DIE #149: variable USB_ADDR
	.section	.debug_info
	.uleb128	149	; ref to abbrev 149
	.section	.debug_abbrev
	.uleb128	149
	.uleb128	DW_TAG_variable
	.byte		DW_CHILDREN_no

	.uleb128	DW_AT_name
	.uleb128	DW_FORM_strp
	.section	.debug_str
.Lname149:
	.string		"USB_ADDR"
	.section	.debug_info
	.long		.Lname149

	.section	.debug_abbrev
	.uleb128	DW_AT_decl_file
	.uleb128	DW_FORM_data1
	.section	.debug_info
	.byte		0	; no source file information

	.section	.debug_abbrev
	.uleb128	DW_AT_decl_line
	.uleb128	DW_FORM_data1
	.section	.debug_info
	.byte		0	; no source line information

	.section	.debug_abbrev
	.uleb128	DW_AT_type
	.uleb128	DW_FORM_ref4
	.section	.debug_info
	.long		.Luint8_t - .Lssinfo

	.section	.debug_abbrev
	.uleb128	DW_AT_external
	.uleb128	DW_FORM_flag
	.section	.debug_info
	.byte		1

	.section	.debug_abbrev
	.uleb128	DW_AT_location
	.uleb128	DW_FORM_block1
	.section	.debug_info
	.byte		5	; length of block
	.byte		DW_OP_addr
	.long		0x800000 + 0x4C0 + 0x03

	.section	.debug_abbrev
	.uleb128	0
	.uleb128	0

;- - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
	;; DIE #150: variable USB_FIFOWP
	.section	.debug_info
	.uleb128	150	; ref to abbrev 150
	.section	.debug_abbrev
	.uleb128	150
	.uleb128	DW_TAG_variable
	.byte		DW_CHILDREN_no

	.uleb128	DW_AT_name
	.uleb128	DW_FORM_strp
	.section	.debug_str
.Lname150:
	.string		"USB_FIFOWP"
	.section	.debug_info
	.long		.Lname150

	.section	.debug_abbrev
	.uleb128	DW_AT_decl_file
	.uleb128	DW_FORM_data1
	.section	.debug_info
	.byte		0	; no source file information

	.section	.debug_abbrev
	.uleb128	DW_AT_decl_line
	.uleb128	DW_FORM_data1
	.section	.debug_info
	.byte		0	; no source line information

	.section	.debug_abbrev
	.uleb128	DW_AT_type
	.uleb128	DW_FORM_ref4
	.section	.debug_info
	.long		.Luint8_t - .Lssinfo

	.section	.debug_abbrev
	.uleb128	DW_AT_external
	.uleb128	DW_FORM_flag
	.section	.debug_info
	.byte		1

	.section	.debug_abbrev
	.uleb128	DW_AT_location
	.uleb128	DW_FORM_block1
	.section	.debug_info
	.byte		5	; length of block
	.byte		DW_OP_addr
	.long		0x800000 + 0x4C0 + 0x04

	.section	.debug_abbrev
	.uleb128	0
	.uleb128	0

;- - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
	;; DIE #151: variable USB_FIFORP
	.section	.debug_info
	.uleb128	151	; ref to abbrev 151
	.section	.debug_abbrev
	.uleb128	151
	.uleb128	DW_TAG_variable
	.byte		DW_CHILDREN_no

	.uleb128	DW_AT_name
	.uleb128	DW_FORM_strp
	.section	.debug_str
.Lname151:
	.string		"USB_FIFORP"
	.section	.debug_info
	.long		.Lname151

	.section	.debug_abbrev
	.uleb128	DW_AT_decl_file
	.uleb128	DW_FORM_data1
	.section	.debug_info
	.byte		0	; no source file information

	.section	.debug_abbrev
	.uleb128	DW_AT_decl_line
	.uleb128	DW_FORM_data1
	.section	.debug_info
	.byte		0	; no source line information

	.section	.debug_abbrev
	.uleb128	DW_AT_type
	.uleb128	DW_FORM_ref4
	.section	.debug_info
	.long		.Luint8_t - .Lssinfo

	.section	.debug_abbrev
	.uleb128	DW_AT_external
	.uleb128	DW_FORM_flag
	.section	.debug_info
	.byte		1

	.section	.debug_abbrev
	.uleb128	DW_AT_location
	.uleb128	DW_FORM_block1
	.section	.debug_info
	.byte		5	; length of block
	.byte		DW_OP_addr
	.long		0x800000 + 0x4C0 + 0x05

	.section	.debug_abbrev
	.uleb128	0
	.uleb128	0

;- - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
	;; DIE #152: variable USB_EPPTR
	.section	.debug_info
	.uleb128	152	; ref to abbrev 152
	.section	.debug_abbrev
	.uleb128	152
	.uleb128	DW_TAG_variable
	.byte		DW_CHILDREN_no

	.uleb128	DW_AT_name
	.uleb128	DW_FORM_strp
	.section	.debug_str
.Lname152:
	.string		"USB_EPPTR"
	.section	.debug_info
	.long		.Lname152

	.section	.debug_abbrev
	.uleb128	DW_AT_decl_file
	.uleb128	DW_FORM_data1
	.section	.debug_info
	.byte		0	; no source file information

	.section	.debug_abbrev
	.uleb128	DW_AT_decl_line
	.uleb128	DW_FORM_data1
	.section	.debug_info
	.byte		0	; no source line information

	.section	.debug_abbrev
	.uleb128	DW_AT_type
	.uleb128	DW_FORM_ref4
	.section	.debug_info
	.long		.Luint16_t - .Lssinfo

	.section	.debug_abbrev
	.uleb128	DW_AT_external
	.uleb128	DW_FORM_flag
	.section	.debug_info
	.byte		1

	.section	.debug_abbrev
	.uleb128	DW_AT_location
	.uleb128	DW_FORM_block1
	.section	.debug_info
	.byte		5	; length of block
	.byte		DW_OP_addr
	.long		0x800000 + 0x4C0 + 0x06

	.section	.debug_abbrev
	.uleb128	0
	.uleb128	0

;- - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
	;; DIE #153: variable USB_INTCTRLA
	.section	.debug_info
	.uleb128	153	; ref to abbrev 153
	.section	.debug_abbrev
	.uleb128	153
	.uleb128	DW_TAG_variable
	.byte		DW_CHILDREN_no

	.uleb128	DW_AT_name
	.uleb128	DW_FORM_strp
	.section	.debug_str
.Lname153:
	.string		"USB_INTCTRLA"
	.section	.debug_info
	.long		.Lname153

	.section	.debug_abbrev
	.uleb128	DW_AT_decl_file
	.uleb128	DW_FORM_data1
	.section	.debug_info
	.byte		0	; no source file information

	.section	.debug_abbrev
	.uleb128	DW_AT_decl_line
	.uleb128	DW_FORM_data1
	.section	.debug_info
	.byte		0	; no source line information

	.section	.debug_abbrev
	.uleb128	DW_AT_type
	.uleb128	DW_FORM_ref4
	.section	.debug_info
	.long		.Luint8_t - .Lssinfo

	.section	.debug_abbrev
	.uleb128	DW_AT_external
	.uleb128	DW_FORM_flag
	.section	.debug_info
	.byte		1

	.section	.debug_abbrev
	.uleb128	DW_AT_location
	.uleb128	DW_FORM_block1
	.section	.debug_info
	.byte		5	; length of block
	.byte		DW_OP_addr
	.long		0x800000 + 0x4C0 + 0x08

	.section	.debug_abbrev
	.uleb128	0
	.uleb128	0

;- - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
	;; DIE #154: variable USB_INTCTRLB
	.section	.debug_info
	.uleb128	154	; ref to abbrev 154
	.section	.debug_abbrev
	.uleb128	154
	.uleb128	DW_TAG_variable
	.byte		DW_CHILDREN_no

	.uleb128	DW_AT_name
	.uleb128	DW_FORM_strp
	.section	.debug_str
.Lname154:
	.string		"USB_INTCTRLB"
	.section	.debug_info
	.long		.Lname154

	.section	.debug_abbrev
	.uleb128	DW_AT_decl_file
	.uleb128	DW_FORM_data1
	.section	.debug_info
	.byte		0	; no source file information

	.section	.debug_abbrev
	.uleb128	DW_AT_decl_line
	.uleb128	DW_FORM_data1
	.section	.debug_info
	.byte		0	; no source line information

	.section	.debug_abbrev
	.uleb128	DW_AT_type
	.uleb128	DW_FORM_ref4
	.section	.debug_info
	.long		.Luint8_t - .Lssinfo

	.section	.debug_abbrev
	.uleb128	DW_AT_external
	.uleb128	DW_FORM_flag
	.section	.debug_info
	.byte		1

	.section	.debug_abbrev
	.uleb128	DW_AT_location
	.uleb128	DW_FORM_block1
	.section	.debug_info
	.byte		5	; length of block
	.byte		DW_OP_addr
	.long		0x800000 + 0x4C0 + 0x09

	.section	.debug_abbrev
	.uleb128	0
	.uleb128	0

;- - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
	;; DIE #155: variable USB_INTFLAGSACLR
	.section	.debug_info
	.uleb128	155	; ref to abbrev 155
	.section	.debug_abbrev
	.uleb128	155
	.uleb128	DW_TAG_variable
	.byte		DW_CHILDREN_no

	.uleb128	DW_AT_name
	.uleb128	DW_FORM_strp
	.section	.debug_str
.Lname155:
	.string		"USB_INTFLAGSACLR"
	.section	.debug_info
	.long		.Lname155

	.section	.debug_abbrev
	.uleb128	DW_AT_decl_file
	.uleb128	DW_FORM_data1
	.section	.debug_info
	.byte		0	; no source file information

	.section	.debug_abbrev
	.uleb128	DW_AT_decl_line
	.uleb128	DW_FORM_data1
	.section	.debug_info
	.byte		0	; no source line information

	.section	.debug_abbrev
	.uleb128	DW_AT_type
	.uleb128	DW_FORM_ref4
	.section	.debug_info
	.long		.Luint8_t - .Lssinfo

	.section	.debug_abbrev
	.uleb128	DW_AT_external
	.uleb128	DW_FORM_flag
	.section	.debug_info
	.byte		1

	.section	.debug_abbrev
	.uleb128	DW_AT_location
	.uleb128	DW_FORM_block1
	.section	.debug_info
	.byte		5	; length of block
	.byte		DW_OP_addr
	.long		0x800000 + 0x4C0 + 0x0A

	.section	.debug_abbrev
	.uleb128	0
	.uleb128	0

;- - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
	;; DIE #156: variable USB_INTFLAGSASET
	.section	.debug_info
	.uleb128	156	; ref to abbrev 156
	.section	.debug_abbrev
	.uleb128	156
	.uleb128	DW_TAG_variable
	.byte		DW_CHILDREN_no

	.uleb128	DW_AT_name
	.uleb128	DW_FORM_strp
	.section	.debug_str
.Lname156:
	.string		"USB_INTFLAGSASET"
	.section	.debug_info
	.long		.Lname156

	.section	.debug_abbrev
	.uleb128	DW_AT_decl_file
	.uleb128	DW_FORM_data1
	.section	.debug_info
	.byte		0	; no source file information

	.section	.debug_abbrev
	.uleb128	DW_AT_decl_line
	.uleb128	DW_FORM_data1
	.section	.debug_info
	.byte		0	; no source line information

	.section	.debug_abbrev
	.uleb128	DW_AT_type
	.uleb128	DW_FORM_ref4
	.section	.debug_info
	.long		.Luint8_t - .Lssinfo

	.section	.debug_abbrev
	.uleb128	DW_AT_external
	.uleb128	DW_FORM_flag
	.section	.debug_info
	.byte		1

	.section	.debug_abbrev
	.uleb128	DW_AT_location
	.uleb128	DW_FORM_block1
	.section	.debug_info
	.byte		5	; length of block
	.byte		DW_OP_addr
	.long		0x800000 + 0x4C0 + 0x0B

	.section	.debug_abbrev
	.uleb128	0
	.uleb128	0

;- - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
	;; DIE #157: variable USB_INTFLAGSBCLR
	.section	.debug_info
	.uleb128	157	; ref to abbrev 157
	.section	.debug_abbrev
	.uleb128	157
	.uleb128	DW_TAG_variable
	.byte		DW_CHILDREN_no

	.uleb128	DW_AT_name
	.uleb128	DW_FORM_strp
	.section	.debug_str
.Lname157:
	.string		"USB_INTFLAGSBCLR"
	.section	.debug_info
	.long		.Lname157

	.section	.debug_abbrev
	.uleb128	DW_AT_decl_file
	.uleb128	DW_FORM_data1
	.section	.debug_info
	.byte		0	; no source file information

	.section	.debug_abbrev
	.uleb128	DW_AT_decl_line
	.uleb128	DW_FORM_data1
	.section	.debug_info
	.byte		0	; no source line information

	.section	.debug_abbrev
	.uleb128	DW_AT_type
	.uleb128	DW_FORM_ref4
	.section	.debug_info
	.long		.Luint8_t - .Lssinfo

	.section	.debug_abbrev
	.uleb128	DW_AT_external
	.uleb128	DW_FORM_flag
	.section	.debug_info
	.byte		1

	.section	.debug_abbrev
	.uleb128	DW_AT_location
	.uleb128	DW_FORM_block1
	.section	.debug_info
	.byte		5	; length of block
	.byte		DW_OP_addr
	.long		0x800000 + 0x4C0 + 0x0C

	.section	.debug_abbrev
	.uleb128	0
	.uleb128	0

;- - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
	;; DIE #158: variable USB_INTFLAGSBSET
	.section	.debug_info
	.uleb128	158	; ref to abbrev 158
	.section	.debug_abbrev
	.uleb128	158
	.uleb128	DW_TAG_variable
	.byte		DW_CHILDREN_no

	.uleb128	DW_AT_name
	.uleb128	DW_FORM_strp
	.section	.debug_str
.Lname158:
	.string		"USB_INTFLAGSBSET"
	.section	.debug_info
	.long		.Lname158

	.section	.debug_abbrev
	.uleb128	DW_AT_decl_file
	.uleb128	DW_FORM_data1
	.section	.debug_info
	.byte		0	; no source file information

	.section	.debug_abbrev
	.uleb128	DW_AT_decl_line
	.uleb128	DW_FORM_data1
	.section	.debug_info
	.byte		0	; no source line information

	.section	.debug_abbrev
	.uleb128	DW_AT_type
	.uleb128	DW_FORM_ref4
	.section	.debug_info
	.long		.Luint8_t - .Lssinfo

	.section	.debug_abbrev
	.uleb128	DW_AT_external
	.uleb128	DW_FORM_flag
	.section	.debug_info
	.byte		1

	.section	.debug_abbrev
	.uleb128	DW_AT_location
	.uleb128	DW_FORM_block1
	.section	.debug_info
	.byte		5	; length of block
	.byte		DW_OP_addr
	.long		0x800000 + 0x4C0 + 0x0D

	.section	.debug_abbrev
	.uleb128	0
	.uleb128	0

;- - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
	;; DIE #159: variable USB_CAL0
	.section	.debug_info
	.uleb128	159	; ref to abbrev 159
	.section	.debug_abbrev
	.uleb128	159
	.uleb128	DW_TAG_variable
	.byte		DW_CHILDREN_no

	.uleb128	DW_AT_name
	.uleb128	DW_FORM_strp
	.section	.debug_str
.Lname159:
	.string		"USB_CAL0"
	.section	.debug_info
	.long		.Lname159

	.section	.debug_abbrev
	.uleb128	DW_AT_decl_file
	.uleb128	DW_FORM_data1
	.section	.debug_info
	.byte		0	; no source file information

	.section	.debug_abbrev
	.uleb128	DW_AT_decl_line
	.uleb128	DW_FORM_data1
	.section	.debug_info
	.byte		0	; no source line information

	.section	.debug_abbrev
	.uleb128	DW_AT_type
	.uleb128	DW_FORM_ref4
	.section	.debug_info
	.long		.Luint8_t - .Lssinfo

	.section	.debug_abbrev
	.uleb128	DW_AT_external
	.uleb128	DW_FORM_flag
	.section	.debug_info
	.byte		1

	.section	.debug_abbrev
	.uleb128	DW_AT_location
	.uleb128	DW_FORM_block1
	.section	.debug_info
	.byte		5	; length of block
	.byte		DW_OP_addr
	.long		0x800000 + 0x4C0 + 0x3A

	.section	.debug_abbrev
	.uleb128	0
	.uleb128	0

;- - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
	;; DIE #160: variable USB_CAL1
	.section	.debug_info
	.uleb128	160	; ref to abbrev 160
	.section	.debug_abbrev
	.uleb128	160
	.uleb128	DW_TAG_variable
	.byte		DW_CHILDREN_no

	.uleb128	DW_AT_name
	.uleb128	DW_FORM_strp
	.section	.debug_str
.Lname160:
	.string		"USB_CAL1"
	.section	.debug_info
	.long		.Lname160

	.section	.debug_abbrev
	.uleb128	DW_AT_decl_file
	.uleb128	DW_FORM_data1
	.section	.debug_info
	.byte		0	; no source file information

	.section	.debug_abbrev
	.uleb128	DW_AT_decl_line
	.uleb128	DW_FORM_data1
	.section	.debug_info
	.byte		0	; no source line information

	.section	.debug_abbrev
	.uleb128	DW_AT_type
	.uleb128	DW_FORM_ref4
	.section	.debug_info
	.long		.Luint8_t - .Lssinfo

	.section	.debug_abbrev
	.uleb128	DW_AT_external
	.uleb128	DW_FORM_flag
	.section	.debug_info
	.byte		1

	.section	.debug_abbrev
	.uleb128	DW_AT_location
	.uleb128	DW_FORM_block1
	.section	.debug_info
	.byte		5	; length of block
	.byte		DW_OP_addr
	.long		0x800000 + 0x4C0 + 0x3B

	.section	.debug_abbrev
	.uleb128	0
	.uleb128	0

;- - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
	;; DIE #161: variable PORTA_DIR
	.section	.debug_info
	.uleb128	161	; ref to abbrev 161
	.section	.debug_abbrev
	.uleb128	161
	.uleb128	DW_TAG_variable
	.byte		DW_CHILDREN_no

	.uleb128	DW_AT_name
	.uleb128	DW_FORM_strp
	.section	.debug_str
.Lname161:
	.string		"PORTA_DIR"
	.section	.debug_info
	.long		.Lname161

	.section	.debug_abbrev
	.uleb128	DW_AT_decl_file
	.uleb128	DW_FORM_data1
	.section	.debug_info
	.byte		0	; no source file information

	.section	.debug_abbrev
	.uleb128	DW_AT_decl_line
	.uleb128	DW_FORM_data1
	.section	.debug_info
	.byte		0	; no source line information

	.section	.debug_abbrev
	.uleb128	DW_AT_type
	.uleb128	DW_FORM_ref4
	.section	.debug_info
	.long		.Luint8_t - .Lssinfo

	.section	.debug_abbrev
	.uleb128	DW_AT_external
	.uleb128	DW_FORM_flag
	.section	.debug_info
	.byte		1

	.section	.debug_abbrev
	.uleb128	DW_AT_location
	.uleb128	DW_FORM_block1
	.section	.debug_info
	.byte		5	; length of block
	.byte		DW_OP_addr
	.long		0x800000 + 0x0600 + 0x00

	.section	.debug_abbrev
	.uleb128	0
	.uleb128	0

;- - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
	;; DIE #162: variable PORTA_DIRSET
	.section	.debug_info
	.uleb128	162	; ref to abbrev 162
	.section	.debug_abbrev
	.uleb128	162
	.uleb128	DW_TAG_variable
	.byte		DW_CHILDREN_no

	.uleb128	DW_AT_name
	.uleb128	DW_FORM_strp
	.section	.debug_str
.Lname162:
	.string		"PORTA_DIRSET"
	.section	.debug_info
	.long		.Lname162

	.section	.debug_abbrev
	.uleb128	DW_AT_decl_file
	.uleb128	DW_FORM_data1
	.section	.debug_info
	.byte		0	; no source file information

	.section	.debug_abbrev
	.uleb128	DW_AT_decl_line
	.uleb128	DW_FORM_data1
	.section	.debug_info
	.byte		0	; no source line information

	.section	.debug_abbrev
	.uleb128	DW_AT_type
	.uleb128	DW_FORM_ref4
	.section	.debug_info
	.long		.Luint8_t - .Lssinfo

	.section	.debug_abbrev
	.uleb128	DW_AT_external
	.uleb128	DW_FORM_flag
	.section	.debug_info
	.byte		1

	.section	.debug_abbrev
	.uleb128	DW_AT_location
	.uleb128	DW_FORM_block1
	.section	.debug_info
	.byte		5	; length of block
	.byte		DW_OP_addr
	.long		0x800000 + 0x0600 + 0x01

	.section	.debug_abbrev
	.uleb128	0
	.uleb128	0

;- - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
	;; DIE #163: variable PORTA_DIRCLR
	.section	.debug_info
	.uleb128	163	; ref to abbrev 163
	.section	.debug_abbrev
	.uleb128	163
	.uleb128	DW_TAG_variable
	.byte		DW_CHILDREN_no

	.uleb128	DW_AT_name
	.uleb128	DW_FORM_strp
	.section	.debug_str
.Lname163:
	.string		"PORTA_DIRCLR"
	.section	.debug_info
	.long		.Lname163

	.section	.debug_abbrev
	.uleb128	DW_AT_decl_file
	.uleb128	DW_FORM_data1
	.section	.debug_info
	.byte		0	; no source file information

	.section	.debug_abbrev
	.uleb128	DW_AT_decl_line
	.uleb128	DW_FORM_data1
	.section	.debug_info
	.byte		0	; no source line information

	.section	.debug_abbrev
	.uleb128	DW_AT_type
	.uleb128	DW_FORM_ref4
	.section	.debug_info
	.long		.Luint8_t - .Lssinfo

	.section	.debug_abbrev
	.uleb128	DW_AT_external
	.uleb128	DW_FORM_flag
	.section	.debug_info
	.byte		1

	.section	.debug_abbrev
	.uleb128	DW_AT_location
	.uleb128	DW_FORM_block1
	.section	.debug_info
	.byte		5	; length of block
	.byte		DW_OP_addr
	.long		0x800000 + 0x0600 + 0x02

	.section	.debug_abbrev
	.uleb128	0
	.uleb128	0

;- - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
	;; DIE #164: variable PORTA_DIRTGL
	.section	.debug_info
	.uleb128	164	; ref to abbrev 164
	.section	.debug_abbrev
	.uleb128	164
	.uleb128	DW_TAG_variable
	.byte		DW_CHILDREN_no

	.uleb128	DW_AT_name
	.uleb128	DW_FORM_strp
	.section	.debug_str
.Lname164:
	.string		"PORTA_DIRTGL"
	.section	.debug_info
	.long		.Lname164

	.section	.debug_abbrev
	.uleb128	DW_AT_decl_file
	.uleb128	DW_FORM_data1
	.section	.debug_info
	.byte		0	; no source file information

	.section	.debug_abbrev
	.uleb128	DW_AT_decl_line
	.uleb128	DW_FORM_data1
	.section	.debug_info
	.byte		0	; no source line information

	.section	.debug_abbrev
	.uleb128	DW_AT_type
	.uleb128	DW_FORM_ref4
	.section	.debug_info
	.long		.Luint8_t - .Lssinfo

	.section	.debug_abbrev
	.uleb128	DW_AT_external
	.uleb128	DW_FORM_flag
	.section	.debug_info
	.byte		1

	.section	.debug_abbrev
	.uleb128	DW_AT_location
	.uleb128	DW_FORM_block1
	.section	.debug_info
	.byte		5	; length of block
	.byte		DW_OP_addr
	.long		0x800000 + 0x0600 + 0x03

	.section	.debug_abbrev
	.uleb128	0
	.uleb128	0

;- - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
	;; DIE #165: variable PORTA_OUT
	.section	.debug_info
	.uleb128	165	; ref to abbrev 165
	.section	.debug_abbrev
	.uleb128	165
	.uleb128	DW_TAG_variable
	.byte		DW_CHILDREN_no

	.uleb128	DW_AT_name
	.uleb128	DW_FORM_strp
	.section	.debug_str
.Lname165:
	.string		"PORTA_OUT"
	.section	.debug_info
	.long		.Lname165

	.section	.debug_abbrev
	.uleb128	DW_AT_decl_file
	.uleb128	DW_FORM_data1
	.section	.debug_info
	.byte		0	; no source file information

	.section	.debug_abbrev
	.uleb128	DW_AT_decl_line
	.uleb128	DW_FORM_data1
	.section	.debug_info
	.byte		0	; no source line information

	.section	.debug_abbrev
	.uleb128	DW_AT_type
	.uleb128	DW_FORM_ref4
	.section	.debug_info
	.long		.Luint8_t - .Lssinfo

	.section	.debug_abbrev
	.uleb128	DW_AT_external
	.uleb128	DW_FORM_flag
	.section	.debug_info
	.byte		1

	.section	.debug_abbrev
	.uleb128	DW_AT_location
	.uleb128	DW_FORM_block1
	.section	.debug_info
	.byte		5	; length of block
	.byte		DW_OP_addr
	.long		0x800000 + 0x0600 + 0x04

	.section	.debug_abbrev
	.uleb128	0
	.uleb128	0

;- - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
	;; DIE #166: variable PORTA_OUTSET
	.section	.debug_info
	.uleb128	166	; ref to abbrev 166
	.section	.debug_abbrev
	.uleb128	166
	.uleb128	DW_TAG_variable
	.byte		DW_CHILDREN_no

	.uleb128	DW_AT_name
	.uleb128	DW_FORM_strp
	.section	.debug_str
.Lname166:
	.string		"PORTA_OUTSET"
	.section	.debug_info
	.long		.Lname166

	.section	.debug_abbrev
	.uleb128	DW_AT_decl_file
	.uleb128	DW_FORM_data1
	.section	.debug_info
	.byte		0	; no source file information

	.section	.debug_abbrev
	.uleb128	DW_AT_decl_line
	.uleb128	DW_FORM_data1
	.section	.debug_info
	.byte		0	; no source line information

	.section	.debug_abbrev
	.uleb128	DW_AT_type
	.uleb128	DW_FORM_ref4
	.section	.debug_info
	.long		.Luint8_t - .Lssinfo

	.section	.debug_abbrev
	.uleb128	DW_AT_external
	.uleb128	DW_FORM_flag
	.section	.debug_info
	.byte		1

	.section	.debug_abbrev
	.uleb128	DW_AT_location
	.uleb128	DW_FORM_block1
	.section	.debug_info
	.byte		5	; length of block
	.byte		DW_OP_addr
	.long		0x800000 + 0x0600 + 0x05

	.section	.debug_abbrev
	.uleb128	0
	.uleb128	0

;- - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
	;; DIE #167: variable PORTA_OUTCLR
	.section	.debug_info
	.uleb128	167	; ref to abbrev 167
	.section	.debug_abbrev
	.uleb128	167
	.uleb128	DW_TAG_variable
	.byte		DW_CHILDREN_no

	.uleb128	DW_AT_name
	.uleb128	DW_FORM_strp
	.section	.debug_str
.Lname167:
	.string		"PORTA_OUTCLR"
	.section	.debug_info
	.long		.Lname167

	.section	.debug_abbrev
	.uleb128	DW_AT_decl_file
	.uleb128	DW_FORM_data1
	.section	.debug_info
	.byte		0	; no source file information

	.section	.debug_abbrev
	.uleb128	DW_AT_decl_line
	.uleb128	DW_FORM_data1
	.section	.debug_info
	.byte		0	; no source line information

	.section	.debug_abbrev
	.uleb128	DW_AT_type
	.uleb128	DW_FORM_ref4
	.section	.debug_info
	.long		.Luint8_t - .Lssinfo

	.section	.debug_abbrev
	.uleb128	DW_AT_external
	.uleb128	DW_FORM_flag
	.section	.debug_info
	.byte		1

	.section	.debug_abbrev
	.uleb128	DW_AT_location
	.uleb128	DW_FORM_block1
	.section	.debug_info
	.byte		5	; length of block
	.byte		DW_OP_addr
	.long		0x800000 + 0x0600 + 0x06

	.section	.debug_abbrev
	.uleb128	0
	.uleb128	0

;- - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
	;; DIE #168: variable PORTA_OUTTGL
	.section	.debug_info
	.uleb128	168	; ref to abbrev 168
	.section	.debug_abbrev
	.uleb128	168
	.uleb128	DW_TAG_variable
	.byte		DW_CHILDREN_no

	.uleb128	DW_AT_name
	.uleb128	DW_FORM_strp
	.section	.debug_str
.Lname168:
	.string		"PORTA_OUTTGL"
	.section	.debug_info
	.long		.Lname168

	.section	.debug_abbrev
	.uleb128	DW_AT_decl_file
	.uleb128	DW_FORM_data1
	.section	.debug_info
	.byte		0	; no source file information

	.section	.debug_abbrev
	.uleb128	DW_AT_decl_line
	.uleb128	DW_FORM_data1
	.section	.debug_info
	.byte		0	; no source line information

	.section	.debug_abbrev
	.uleb128	DW_AT_type
	.uleb128	DW_FORM_ref4
	.section	.debug_info
	.long		.Luint8_t - .Lssinfo

	.section	.debug_abbrev
	.uleb128	DW_AT_external
	.uleb128	DW_FORM_flag
	.section	.debug_info
	.byte		1

	.section	.debug_abbrev
	.uleb128	DW_AT_location
	.uleb128	DW_FORM_block1
	.section	.debug_info
	.byte		5	; length of block
	.byte		DW_OP_addr
	.long		0x800000 + 0x0600 + 0x07

	.section	.debug_abbrev
	.uleb128	0
	.uleb128	0

;- - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
	;; DIE #169: variable PORTA_IN
	.section	.debug_info
	.uleb128	169	; ref to abbrev 169
	.section	.debug_abbrev
	.uleb128	169
	.uleb128	DW_TAG_variable
	.byte		DW_CHILDREN_no

	.uleb128	DW_AT_name
	.uleb128	DW_FORM_strp
	.section	.debug_str
.Lname169:
	.string		"PORTA_IN"
	.section	.debug_info
	.long		.Lname169

	.section	.debug_abbrev
	.uleb128	DW_AT_decl_file
	.uleb128	DW_FORM_data1
	.section	.debug_info
	.byte		0	; no source file information

	.section	.debug_abbrev
	.uleb128	DW_AT_decl_line
	.uleb128	DW_FORM_data1
	.section	.debug_info
	.byte		0	; no source line information

	.section	.debug_abbrev
	.uleb128	DW_AT_type
	.uleb128	DW_FORM_ref4
	.section	.debug_info
	.long		.Luint8_t - .Lssinfo

	.section	.debug_abbrev
	.uleb128	DW_AT_external
	.uleb128	DW_FORM_flag
	.section	.debug_info
	.byte		1

	.section	.debug_abbrev
	.uleb128	DW_AT_location
	.uleb128	DW_FORM_block1
	.section	.debug_info
	.byte		5	; length of block
	.byte		DW_OP_addr
	.long		0x800000 + 0x0600 + 0x08

	.section	.debug_abbrev
	.uleb128	0
	.uleb128	0

;- - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
	;; DIE #170: variable PORTA_INTCTRL
	.section	.debug_info
	.uleb128	170	; ref to abbrev 170
	.section	.debug_abbrev
	.uleb128	170
	.uleb128	DW_TAG_variable
	.byte		DW_CHILDREN_no

	.uleb128	DW_AT_name
	.uleb128	DW_FORM_strp
	.section	.debug_str
.Lname170:
	.string		"PORTA_INTCTRL"
	.section	.debug_info
	.long		.Lname170

	.section	.debug_abbrev
	.uleb128	DW_AT_decl_file
	.uleb128	DW_FORM_data1
	.section	.debug_info
	.byte		0	; no source file information

	.section	.debug_abbrev
	.uleb128	DW_AT_decl_line
	.uleb128	DW_FORM_data1
	.section	.debug_info
	.byte		0	; no source line information

	.section	.debug_abbrev
	.uleb128	DW_AT_type
	.uleb128	DW_FORM_ref4
	.section	.debug_info
	.long		.Luint8_t - .Lssinfo

	.section	.debug_abbrev
	.uleb128	DW_AT_external
	.uleb128	DW_FORM_flag
	.section	.debug_info
	.byte		1

	.section	.debug_abbrev
	.uleb128	DW_AT_location
	.uleb128	DW_FORM_block1
	.section	.debug_info
	.byte		5	; length of block
	.byte		DW_OP_addr
	.long		0x800000 + 0x0600 + 0x09

	.section	.debug_abbrev
	.uleb128	0
	.uleb128	0

;- - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
	;; DIE #171: variable PORTA_INT0MASK
	.section	.debug_info
	.uleb128	171	; ref to abbrev 171
	.section	.debug_abbrev
	.uleb128	171
	.uleb128	DW_TAG_variable
	.byte		DW_CHILDREN_no

	.uleb128	DW_AT_name
	.uleb128	DW_FORM_strp
	.section	.debug_str
.Lname171:
	.string		"PORTA_INT0MASK"
	.section	.debug_info
	.long		.Lname171

	.section	.debug_abbrev
	.uleb128	DW_AT_decl_file
	.uleb128	DW_FORM_data1
	.section	.debug_info
	.byte		0	; no source file information

	.section	.debug_abbrev
	.uleb128	DW_AT_decl_line
	.uleb128	DW_FORM_data1
	.section	.debug_info
	.byte		0	; no source line information

	.section	.debug_abbrev
	.uleb128	DW_AT_type
	.uleb128	DW_FORM_ref4
	.section	.debug_info
	.long		.Luint8_t - .Lssinfo

	.section	.debug_abbrev
	.uleb128	DW_AT_external
	.uleb128	DW_FORM_flag
	.section	.debug_info
	.byte		1

	.section	.debug_abbrev
	.uleb128	DW_AT_location
	.uleb128	DW_FORM_block1
	.section	.debug_info
	.byte		5	; length of block
	.byte		DW_OP_addr
	.long		0x800000 + 0x0600 + 0x0A

	.section	.debug_abbrev
	.uleb128	0
	.uleb128	0

;- - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
	;; DIE #172: variable PORTA_INT1MASK
	.section	.debug_info
	.uleb128	172	; ref to abbrev 172
	.section	.debug_abbrev
	.uleb128	172
	.uleb128	DW_TAG_variable
	.byte		DW_CHILDREN_no

	.uleb128	DW_AT_name
	.uleb128	DW_FORM_strp
	.section	.debug_str
.Lname172:
	.string		"PORTA_INT1MASK"
	.section	.debug_info
	.long		.Lname172

	.section	.debug_abbrev
	.uleb128	DW_AT_decl_file
	.uleb128	DW_FORM_data1
	.section	.debug_info
	.byte		0	; no source file information

	.section	.debug_abbrev
	.uleb128	DW_AT_decl_line
	.uleb128	DW_FORM_data1
	.section	.debug_info
	.byte		0	; no source line information

	.section	.debug_abbrev
	.uleb128	DW_AT_type
	.uleb128	DW_FORM_ref4
	.section	.debug_info
	.long		.Luint8_t - .Lssinfo

	.section	.debug_abbrev
	.uleb128	DW_AT_external
	.uleb128	DW_FORM_flag
	.section	.debug_info
	.byte		1

	.section	.debug_abbrev
	.uleb128	DW_AT_location
	.uleb128	DW_FORM_block1
	.section	.debug_info
	.byte		5	; length of block
	.byte		DW_OP_addr
	.long		0x800000 + 0x0600 + 0x0B

	.section	.debug_abbrev
	.uleb128	0
	.uleb128	0

;- - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
	;; DIE #173: variable PORTA_INTFLAGS
	.section	.debug_info
	.uleb128	173	; ref to abbrev 173
	.section	.debug_abbrev
	.uleb128	173
	.uleb128	DW_TAG_variable
	.byte		DW_CHILDREN_no

	.uleb128	DW_AT_name
	.uleb128	DW_FORM_strp
	.section	.debug_str
.Lname173:
	.string		"PORTA_INTFLAGS"
	.section	.debug_info
	.long		.Lname173

	.section	.debug_abbrev
	.uleb128	DW_AT_decl_file
	.uleb128	DW_FORM_data1
	.section	.debug_info
	.byte		0	; no source file information

	.section	.debug_abbrev
	.uleb128	DW_AT_decl_line
	.uleb128	DW_FORM_data1
	.section	.debug_info
	.byte		0	; no source line information

	.section	.debug_abbrev
	.uleb128	DW_AT_type
	.uleb128	DW_FORM_ref4
	.section	.debug_info
	.long		.Luint8_t - .Lssinfo

	.section	.debug_abbrev
	.uleb128	DW_AT_external
	.uleb128	DW_FORM_flag
	.section	.debug_info
	.byte		1

	.section	.debug_abbrev
	.uleb128	DW_AT_location
	.uleb128	DW_FORM_block1
	.section	.debug_info
	.byte		5	; length of block
	.byte		DW_OP_addr
	.long		0x800000 + 0x0600 + 0x0C

	.section	.debug_abbrev
	.uleb128	0
	.uleb128	0

;- - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
	;; DIE #174: variable PORTA_REMAP
	.section	.debug_info
	.uleb128	174	; ref to abbrev 174
	.section	.debug_abbrev
	.uleb128	174
	.uleb128	DW_TAG_variable
	.byte		DW_CHILDREN_no

	.uleb128	DW_AT_name
	.uleb128	DW_FORM_strp
	.section	.debug_str
.Lname174:
	.string		"PORTA_REMAP"
	.section	.debug_info
	.long		.Lname174

	.section	.debug_abbrev
	.uleb128	DW_AT_decl_file
	.uleb128	DW_FORM_data1
	.section	.debug_info
	.byte		0	; no source file information

	.section	.debug_abbrev
	.uleb128	DW_AT_decl_line
	.uleb128	DW_FORM_data1
	.section	.debug_info
	.byte		0	; no source line information

	.section	.debug_abbrev
	.uleb128	DW_AT_type
	.uleb128	DW_FORM_ref4
	.section	.debug_info
	.long		.Luint8_t - .Lssinfo

	.section	.debug_abbrev
	.uleb128	DW_AT_external
	.uleb128	DW_FORM_flag
	.section	.debug_info
	.byte		1

	.section	.debug_abbrev
	.uleb128	DW_AT_location
	.uleb128	DW_FORM_block1
	.section	.debug_info
	.byte		5	; length of block
	.byte		DW_OP_addr
	.long		0x800000 + 0x0600 + 0x0E

	.section	.debug_abbrev
	.uleb128	0
	.uleb128	0

;- - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
	;; DIE #175: variable PORTA_PIN0CTRL
	.section	.debug_info
	.uleb128	175	; ref to abbrev 175
	.section	.debug_abbrev
	.uleb128	175
	.uleb128	DW_TAG_variable
	.byte		DW_CHILDREN_no

	.uleb128	DW_AT_name
	.uleb128	DW_FORM_strp
	.section	.debug_str
.Lname175:
	.string		"PORTA_PIN0CTRL"
	.section	.debug_info
	.long		.Lname175

	.section	.debug_abbrev
	.uleb128	DW_AT_decl_file
	.uleb128	DW_FORM_data1
	.section	.debug_info
	.byte		0	; no source file information

	.section	.debug_abbrev
	.uleb128	DW_AT_decl_line
	.uleb128	DW_FORM_data1
	.section	.debug_info
	.byte		0	; no source line information

	.section	.debug_abbrev
	.uleb128	DW_AT_type
	.uleb128	DW_FORM_ref4
	.section	.debug_info
	.long		.Luint8_t - .Lssinfo

	.section	.debug_abbrev
	.uleb128	DW_AT_external
	.uleb128	DW_FORM_flag
	.section	.debug_info
	.byte		1

	.section	.debug_abbrev
	.uleb128	DW_AT_location
	.uleb128	DW_FORM_block1
	.section	.debug_info
	.byte		5	; length of block
	.byte		DW_OP_addr
	.long		0x800000 + 0x0600 + 0x10

	.section	.debug_abbrev
	.uleb128	0
	.uleb128	0

;- - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
	;; DIE #176: variable PORTA_PIN1CTRL
	.section	.debug_info
	.uleb128	176	; ref to abbrev 176
	.section	.debug_abbrev
	.uleb128	176
	.uleb128	DW_TAG_variable
	.byte		DW_CHILDREN_no

	.uleb128	DW_AT_name
	.uleb128	DW_FORM_strp
	.section	.debug_str
.Lname176:
	.string		"PORTA_PIN1CTRL"
	.section	.debug_info
	.long		.Lname176

	.section	.debug_abbrev
	.uleb128	DW_AT_decl_file
	.uleb128	DW_FORM_data1
	.section	.debug_info
	.byte		0	; no source file information

	.section	.debug_abbrev
	.uleb128	DW_AT_decl_line
	.uleb128	DW_FORM_data1
	.section	.debug_info
	.byte		0	; no source line information

	.section	.debug_abbrev
	.uleb128	DW_AT_type
	.uleb128	DW_FORM_ref4
	.section	.debug_info
	.long		.Luint8_t - .Lssinfo

	.section	.debug_abbrev
	.uleb128	DW_AT_external
	.uleb128	DW_FORM_flag
	.section	.debug_info
	.byte		1

	.section	.debug_abbrev
	.uleb128	DW_AT_location
	.uleb128	DW_FORM_block1
	.section	.debug_info
	.byte		5	; length of block
	.byte		DW_OP_addr
	.long		0x800000 + 0x0600 + 0x11

	.section	.debug_abbrev
	.uleb128	0
	.uleb128	0

;- - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
	;; DIE #177: variable PORTA_PIN2CTRL
	.section	.debug_info
	.uleb128	177	; ref to abbrev 177
	.section	.debug_abbrev
	.uleb128	177
	.uleb128	DW_TAG_variable
	.byte		DW_CHILDREN_no

	.uleb128	DW_AT_name
	.uleb128	DW_FORM_strp
	.section	.debug_str
.Lname177:
	.string		"PORTA_PIN2CTRL"
	.section	.debug_info
	.long		.Lname177

	.section	.debug_abbrev
	.uleb128	DW_AT_decl_file
	.uleb128	DW_FORM_data1
	.section	.debug_info
	.byte		0	; no source file information

	.section	.debug_abbrev
	.uleb128	DW_AT_decl_line
	.uleb128	DW_FORM_data1
	.section	.debug_info
	.byte		0	; no source line information

	.section	.debug_abbrev
	.uleb128	DW_AT_type
	.uleb128	DW_FORM_ref4
	.section	.debug_info
	.long		.Luint8_t - .Lssinfo

	.section	.debug_abbrev
	.uleb128	DW_AT_external
	.uleb128	DW_FORM_flag
	.section	.debug_info
	.byte		1

	.section	.debug_abbrev
	.uleb128	DW_AT_location
	.uleb128	DW_FORM_block1
	.section	.debug_info
	.byte		5	; length of block
	.byte		DW_OP_addr
	.long		0x800000 + 0x0600 + 0x12

	.section	.debug_abbrev
	.uleb128	0
	.uleb128	0

;- - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
	;; DIE #178: variable PORTA_PIN3CTRL
	.section	.debug_info
	.uleb128	178	; ref to abbrev 178
	.section	.debug_abbrev
	.uleb128	178
	.uleb128	DW_TAG_variable
	.byte		DW_CHILDREN_no

	.uleb128	DW_AT_name
	.uleb128	DW_FORM_strp
	.section	.debug_str
.Lname178:
	.string		"PORTA_PIN3CTRL"
	.section	.debug_info
	.long		.Lname178

	.section	.debug_abbrev
	.uleb128	DW_AT_decl_file
	.uleb128	DW_FORM_data1
	.section	.debug_info
	.byte		0	; no source file information

	.section	.debug_abbrev
	.uleb128	DW_AT_decl_line
	.uleb128	DW_FORM_data1
	.section	.debug_info
	.byte		0	; no source line information

	.section	.debug_abbrev
	.uleb128	DW_AT_type
	.uleb128	DW_FORM_ref4
	.section	.debug_info
	.long		.Luint8_t - .Lssinfo

	.section	.debug_abbrev
	.uleb128	DW_AT_external
	.uleb128	DW_FORM_flag
	.section	.debug_info
	.byte		1

	.section	.debug_abbrev
	.uleb128	DW_AT_location
	.uleb128	DW_FORM_block1
	.section	.debug_info
	.byte		5	; length of block
	.byte		DW_OP_addr
	.long		0x800000 + 0x0600 + 0x13

	.section	.debug_abbrev
	.uleb128	0
	.uleb128	0

;- - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
	;; DIE #179: variable PORTA_PIN4CTRL
	.section	.debug_info
	.uleb128	179	; ref to abbrev 179
	.section	.debug_abbrev
	.uleb128	179
	.uleb128	DW_TAG_variable
	.byte		DW_CHILDREN_no

	.uleb128	DW_AT_name
	.uleb128	DW_FORM_strp
	.section	.debug_str
.Lname179:
	.string		"PORTA_PIN4CTRL"
	.section	.debug_info
	.long		.Lname179

	.section	.debug_abbrev
	.uleb128	DW_AT_decl_file
	.uleb128	DW_FORM_data1
	.section	.debug_info
	.byte		0	; no source file information

	.section	.debug_abbrev
	.uleb128	DW_AT_decl_line
	.uleb128	DW_FORM_data1
	.section	.debug_info
	.byte		0	; no source line information

	.section	.debug_abbrev
	.uleb128	DW_AT_type
	.uleb128	DW_FORM_ref4
	.section	.debug_info
	.long		.Luint8_t - .Lssinfo

	.section	.debug_abbrev
	.uleb128	DW_AT_external
	.uleb128	DW_FORM_flag
	.section	.debug_info
	.byte		1

	.section	.debug_abbrev
	.uleb128	DW_AT_location
	.uleb128	DW_FORM_block1
	.section	.debug_info
	.byte		5	; length of block
	.byte		DW_OP_addr
	.long		0x800000 + 0x0600 + 0x14

	.section	.debug_abbrev
	.uleb128	0
	.uleb128	0

;- - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
	;; DIE #180: variable PORTA_PIN5CTRL
	.section	.debug_info
	.uleb128	180	; ref to abbrev 180
	.section	.debug_abbrev
	.uleb128	180
	.uleb128	DW_TAG_variable
	.byte		DW_CHILDREN_no

	.uleb128	DW_AT_name
	.uleb128	DW_FORM_strp
	.section	.debug_str
.Lname180:
	.string		"PORTA_PIN5CTRL"
	.section	.debug_info
	.long		.Lname180

	.section	.debug_abbrev
	.uleb128	DW_AT_decl_file
	.uleb128	DW_FORM_data1
	.section	.debug_info
	.byte		0	; no source file information

	.section	.debug_abbrev
	.uleb128	DW_AT_decl_line
	.uleb128	DW_FORM_data1
	.section	.debug_info
	.byte		0	; no source line information

	.section	.debug_abbrev
	.uleb128	DW_AT_type
	.uleb128	DW_FORM_ref4
	.section	.debug_info
	.long		.Luint8_t - .Lssinfo

	.section	.debug_abbrev
	.uleb128	DW_AT_external
	.uleb128	DW_FORM_flag
	.section	.debug_info
	.byte		1

	.section	.debug_abbrev
	.uleb128	DW_AT_location
	.uleb128	DW_FORM_block1
	.section	.debug_info
	.byte		5	; length of block
	.byte		DW_OP_addr
	.long		0x800000 + 0x0600 + 0x15

	.section	.debug_abbrev
	.uleb128	0
	.uleb128	0

;- - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
	;; DIE #181: variable PORTA_PIN6CTRL
	.section	.debug_info
	.uleb128	181	; ref to abbrev 181
	.section	.debug_abbrev
	.uleb128	181
	.uleb128	DW_TAG_variable
	.byte		DW_CHILDREN_no

	.uleb128	DW_AT_name
	.uleb128	DW_FORM_strp
	.section	.debug_str
.Lname181:
	.string		"PORTA_PIN6CTRL"
	.section	.debug_info
	.long		.Lname181

	.section	.debug_abbrev
	.uleb128	DW_AT_decl_file
	.uleb128	DW_FORM_data1
	.section	.debug_info
	.byte		0	; no source file information

	.section	.debug_abbrev
	.uleb128	DW_AT_decl_line
	.uleb128	DW_FORM_data1
	.section	.debug_info
	.byte		0	; no source line information

	.section	.debug_abbrev
	.uleb128	DW_AT_type
	.uleb128	DW_FORM_ref4
	.section	.debug_info
	.long		.Luint8_t - .Lssinfo

	.section	.debug_abbrev
	.uleb128	DW_AT_external
	.uleb128	DW_FORM_flag
	.section	.debug_info
	.byte		1

	.section	.debug_abbrev
	.uleb128	DW_AT_location
	.uleb128	DW_FORM_block1
	.section	.debug_info
	.byte		5	; length of block
	.byte		DW_OP_addr
	.long		0x800000 + 0x0600 + 0x16

	.section	.debug_abbrev
	.uleb128	0
	.uleb128	0

;- - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
	;; DIE #182: variable PORTA_PIN7CTRL
	.section	.debug_info
	.uleb128	182	; ref to abbrev 182
	.section	.debug_abbrev
	.uleb128	182
	.uleb128	DW_TAG_variable
	.byte		DW_CHILDREN_no

	.uleb128	DW_AT_name
	.uleb128	DW_FORM_strp
	.section	.debug_str
.Lname182:
	.string		"PORTA_PIN7CTRL"
	.section	.debug_info
	.long		.Lname182

	.section	.debug_abbrev
	.uleb128	DW_AT_decl_file
	.uleb128	DW_FORM_data1
	.section	.debug_info
	.byte		0	; no source file information

	.section	.debug_abbrev
	.uleb128	DW_AT_decl_line
	.uleb128	DW_FORM_data1
	.section	.debug_info
	.byte		0	; no source line information

	.section	.debug_abbrev
	.uleb128	DW_AT_type
	.uleb128	DW_FORM_ref4
	.section	.debug_info
	.long		.Luint8_t - .Lssinfo

	.section	.debug_abbrev
	.uleb128	DW_AT_external
	.uleb128	DW_FORM_flag
	.section	.debug_info
	.byte		1

	.section	.debug_abbrev
	.uleb128	DW_AT_location
	.uleb128	DW_FORM_block1
	.section	.debug_info
	.byte		5	; length of block
	.byte		DW_OP_addr
	.long		0x800000 + 0x0600 + 0x17

	.section	.debug_abbrev
	.uleb128	0
	.uleb128	0

;- - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
	;; DIE #183: variable PORTB_DIR
	.section	.debug_info
	.uleb128	183	; ref to abbrev 183
	.section	.debug_abbrev
	.uleb128	183
	.uleb128	DW_TAG_variable
	.byte		DW_CHILDREN_no

	.uleb128	DW_AT_name
	.uleb128	DW_FORM_strp
	.section	.debug_str
.Lname183:
	.string		"PORTB_DIR"
	.section	.debug_info
	.long		.Lname183

	.section	.debug_abbrev
	.uleb128	DW_AT_decl_file
	.uleb128	DW_FORM_data1
	.section	.debug_info
	.byte		0	; no source file information

	.section	.debug_abbrev
	.uleb128	DW_AT_decl_line
	.uleb128	DW_FORM_data1
	.section	.debug_info
	.byte		0	; no source line information

	.section	.debug_abbrev
	.uleb128	DW_AT_type
	.uleb128	DW_FORM_ref4
	.section	.debug_info
	.long		.Luint8_t - .Lssinfo

	.section	.debug_abbrev
	.uleb128	DW_AT_external
	.uleb128	DW_FORM_flag
	.section	.debug_info
	.byte		1

	.section	.debug_abbrev
	.uleb128	DW_AT_location
	.uleb128	DW_FORM_block1
	.section	.debug_info
	.byte		5	; length of block
	.byte		DW_OP_addr
	.long		0x800000 + 0x0620 + 0x00

	.section	.debug_abbrev
	.uleb128	0
	.uleb128	0

;- - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
	;; DIE #184: variable PORTB_DIRSET
	.section	.debug_info
	.uleb128	184	; ref to abbrev 184
	.section	.debug_abbrev
	.uleb128	184
	.uleb128	DW_TAG_variable
	.byte		DW_CHILDREN_no

	.uleb128	DW_AT_name
	.uleb128	DW_FORM_strp
	.section	.debug_str
.Lname184:
	.string		"PORTB_DIRSET"
	.section	.debug_info
	.long		.Lname184

	.section	.debug_abbrev
	.uleb128	DW_AT_decl_file
	.uleb128	DW_FORM_data1
	.section	.debug_info
	.byte		0	; no source file information

	.section	.debug_abbrev
	.uleb128	DW_AT_decl_line
	.uleb128	DW_FORM_data1
	.section	.debug_info
	.byte		0	; no source line information

	.section	.debug_abbrev
	.uleb128	DW_AT_type
	.uleb128	DW_FORM_ref4
	.section	.debug_info
	.long		.Luint8_t - .Lssinfo

	.section	.debug_abbrev
	.uleb128	DW_AT_external
	.uleb128	DW_FORM_flag
	.section	.debug_info
	.byte		1

	.section	.debug_abbrev
	.uleb128	DW_AT_location
	.uleb128	DW_FORM_block1
	.section	.debug_info
	.byte		5	; length of block
	.byte		DW_OP_addr
	.long		0x800000 + 0x0620 + 0x01

	.section	.debug_abbrev
	.uleb128	0
	.uleb128	0

;- - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
	;; DIE #185: variable PORTB_DIRCLR
	.section	.debug_info
	.uleb128	185	; ref to abbrev 185
	.section	.debug_abbrev
	.uleb128	185
	.uleb128	DW_TAG_variable
	.byte		DW_CHILDREN_no

	.uleb128	DW_AT_name
	.uleb128	DW_FORM_strp
	.section	.debug_str
.Lname185:
	.string		"PORTB_DIRCLR"
	.section	.debug_info
	.long		.Lname185

	.section	.debug_abbrev
	.uleb128	DW_AT_decl_file
	.uleb128	DW_FORM_data1
	.section	.debug_info
	.byte		0	; no source file information

	.section	.debug_abbrev
	.uleb128	DW_AT_decl_line
	.uleb128	DW_FORM_data1
	.section	.debug_info
	.byte		0	; no source line information

	.section	.debug_abbrev
	.uleb128	DW_AT_type
	.uleb128	DW_FORM_ref4
	.section	.debug_info
	.long		.Luint8_t - .Lssinfo

	.section	.debug_abbrev
	.uleb128	DW_AT_external
	.uleb128	DW_FORM_flag
	.section	.debug_info
	.byte		1

	.section	.debug_abbrev
	.uleb128	DW_AT_location
	.uleb128	DW_FORM_block1
	.section	.debug_info
	.byte		5	; length of block
	.byte		DW_OP_addr
	.long		0x800000 + 0x0620 + 0x02

	.section	.debug_abbrev
	.uleb128	0
	.uleb128	0

;- - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
	;; DIE #186: variable PORTB_DIRTGL
	.section	.debug_info
	.uleb128	186	; ref to abbrev 186
	.section	.debug_abbrev
	.uleb128	186
	.uleb128	DW_TAG_variable
	.byte		DW_CHILDREN_no

	.uleb128	DW_AT_name
	.uleb128	DW_FORM_strp
	.section	.debug_str
.Lname186:
	.string		"PORTB_DIRTGL"
	.section	.debug_info
	.long		.Lname186

	.section	.debug_abbrev
	.uleb128	DW_AT_decl_file
	.uleb128	DW_FORM_data1
	.section	.debug_info
	.byte		0	; no source file information

	.section	.debug_abbrev
	.uleb128	DW_AT_decl_line
	.uleb128	DW_FORM_data1
	.section	.debug_info
	.byte		0	; no source line information

	.section	.debug_abbrev
	.uleb128	DW_AT_type
	.uleb128	DW_FORM_ref4
	.section	.debug_info
	.long		.Luint8_t - .Lssinfo

	.section	.debug_abbrev
	.uleb128	DW_AT_external
	.uleb128	DW_FORM_flag
	.section	.debug_info
	.byte		1

	.section	.debug_abbrev
	.uleb128	DW_AT_location
	.uleb128	DW_FORM_block1
	.section	.debug_info
	.byte		5	; length of block
	.byte		DW_OP_addr
	.long		0x800000 + 0x0620 + 0x03

	.section	.debug_abbrev
	.uleb128	0
	.uleb128	0

;- - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
	;; DIE #187: variable PORTB_OUT
	.section	.debug_info
	.uleb128	187	; ref to abbrev 187
	.section	.debug_abbrev
	.uleb128	187
	.uleb128	DW_TAG_variable
	.byte		DW_CHILDREN_no

	.uleb128	DW_AT_name
	.uleb128	DW_FORM_strp
	.section	.debug_str
.Lname187:
	.string		"PORTB_OUT"
	.section	.debug_info
	.long		.Lname187

	.section	.debug_abbrev
	.uleb128	DW_AT_decl_file
	.uleb128	DW_FORM_data1
	.section	.debug_info
	.byte		0	; no source file information

	.section	.debug_abbrev
	.uleb128	DW_AT_decl_line
	.uleb128	DW_FORM_data1
	.section	.debug_info
	.byte		0	; no source line information

	.section	.debug_abbrev
	.uleb128	DW_AT_type
	.uleb128	DW_FORM_ref4
	.section	.debug_info
	.long		.Luint8_t - .Lssinfo

	.section	.debug_abbrev
	.uleb128	DW_AT_external
	.uleb128	DW_FORM_flag
	.section	.debug_info
	.byte		1

	.section	.debug_abbrev
	.uleb128	DW_AT_location
	.uleb128	DW_FORM_block1
	.section	.debug_info
	.byte		5	; length of block
	.byte		DW_OP_addr
	.long		0x800000 + 0x0620 + 0x04

	.section	.debug_abbrev
	.uleb128	0
	.uleb128	0

;- - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
	;; DIE #188: variable PORTB_OUTSET
	.section	.debug_info
	.uleb128	188	; ref to abbrev 188
	.section	.debug_abbrev
	.uleb128	188
	.uleb128	DW_TAG_variable
	.byte		DW_CHILDREN_no

	.uleb128	DW_AT_name
	.uleb128	DW_FORM_strp
	.section	.debug_str
.Lname188:
	.string		"PORTB_OUTSET"
	.section	.debug_info
	.long		.Lname188

	.section	.debug_abbrev
	.uleb128	DW_AT_decl_file
	.uleb128	DW_FORM_data1
	.section	.debug_info
	.byte		0	; no source file information

	.section	.debug_abbrev
	.uleb128	DW_AT_decl_line
	.uleb128	DW_FORM_data1
	.section	.debug_info
	.byte		0	; no source line information

	.section	.debug_abbrev
	.uleb128	DW_AT_type
	.uleb128	DW_FORM_ref4
	.section	.debug_info
	.long		.Luint8_t - .Lssinfo

	.section	.debug_abbrev
	.uleb128	DW_AT_external
	.uleb128	DW_FORM_flag
	.section	.debug_info
	.byte		1

	.section	.debug_abbrev
	.uleb128	DW_AT_location
	.uleb128	DW_FORM_block1
	.section	.debug_info
	.byte		5	; length of block
	.byte		DW_OP_addr
	.long		0x800000 + 0x0620 + 0x05

	.section	.debug_abbrev
	.uleb128	0
	.uleb128	0

;- - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
	;; DIE #189: variable PORTB_OUTCLR
	.section	.debug_info
	.uleb128	189	; ref to abbrev 189
	.section	.debug_abbrev
	.uleb128	189
	.uleb128	DW_TAG_variable
	.byte		DW_CHILDREN_no

	.uleb128	DW_AT_name
	.uleb128	DW_FORM_strp
	.section	.debug_str
.Lname189:
	.string		"PORTB_OUTCLR"
	.section	.debug_info
	.long		.Lname189

	.section	.debug_abbrev
	.uleb128	DW_AT_decl_file
	.uleb128	DW_FORM_data1
	.section	.debug_info
	.byte		0	; no source file information

	.section	.debug_abbrev
	.uleb128	DW_AT_decl_line
	.uleb128	DW_FORM_data1
	.section	.debug_info
	.byte		0	; no source line information

	.section	.debug_abbrev
	.uleb128	DW_AT_type
	.uleb128	DW_FORM_ref4
	.section	.debug_info
	.long		.Luint8_t - .Lssinfo

	.section	.debug_abbrev
	.uleb128	DW_AT_external
	.uleb128	DW_FORM_flag
	.section	.debug_info
	.byte		1

	.section	.debug_abbrev
	.uleb128	DW_AT_location
	.uleb128	DW_FORM_block1
	.section	.debug_info
	.byte		5	; length of block
	.byte		DW_OP_addr
	.long		0x800000 + 0x0620 + 0x06

	.section	.debug_abbrev
	.uleb128	0
	.uleb128	0

;- - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
	;; DIE #190: variable PORTB_OUTTGL
	.section	.debug_info
	.uleb128	190	; ref to abbrev 190
	.section	.debug_abbrev
	.uleb128	190
	.uleb128	DW_TAG_variable
	.byte		DW_CHILDREN_no

	.uleb128	DW_AT_name
	.uleb128	DW_FORM_strp
	.section	.debug_str
.Lname190:
	.string		"PORTB_OUTTGL"
	.section	.debug_info
	.long		.Lname190

	.section	.debug_abbrev
	.uleb128	DW_AT_decl_file
	.uleb128	DW_FORM_data1
	.section	.debug_info
	.byte		0	; no source file information

	.section	.debug_abbrev
	.uleb128	DW_AT_decl_line
	.uleb128	DW_FORM_data1
	.section	.debug_info
	.byte		0	; no source line information

	.section	.debug_abbrev
	.uleb128	DW_AT_type
	.uleb128	DW_FORM_ref4
	.section	.debug_info
	.long		.Luint8_t - .Lssinfo

	.section	.debug_abbrev
	.uleb128	DW_AT_external
	.uleb128	DW_FORM_flag
	.section	.debug_info
	.byte		1

	.section	.debug_abbrev
	.uleb128	DW_AT_location
	.uleb128	DW_FORM_block1
	.section	.debug_info
	.byte		5	; length of block
	.byte		DW_OP_addr
	.long		0x800000 + 0x0620 + 0x07

	.section	.debug_abbrev
	.uleb128	0
	.uleb128	0

;- - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
	;; DIE #191: variable PORTB_IN
	.section	.debug_info
	.uleb128	191	; ref to abbrev 191
	.section	.debug_abbrev
	.uleb128	191
	.uleb128	DW_TAG_variable
	.byte		DW_CHILDREN_no

	.uleb128	DW_AT_name
	.uleb128	DW_FORM_strp
	.section	.debug_str
.Lname191:
	.string		"PORTB_IN"
	.section	.debug_info
	.long		.Lname191

	.section	.debug_abbrev
	.uleb128	DW_AT_decl_file
	.uleb128	DW_FORM_data1
	.section	.debug_info
	.byte		0	; no source file information

	.section	.debug_abbrev
	.uleb128	DW_AT_decl_line
	.uleb128	DW_FORM_data1
	.section	.debug_info
	.byte		0	; no source line information

	.section	.debug_abbrev
	.uleb128	DW_AT_type
	.uleb128	DW_FORM_ref4
	.section	.debug_info
	.long		.Luint8_t - .Lssinfo

	.section	.debug_abbrev
	.uleb128	DW_AT_external
	.uleb128	DW_FORM_flag
	.section	.debug_info
	.byte		1

	.section	.debug_abbrev
	.uleb128	DW_AT_location
	.uleb128	DW_FORM_block1
	.section	.debug_info
	.byte		5	; length of block
	.byte		DW_OP_addr
	.long		0x800000 + 0x0620 + 0x08

	.section	.debug_abbrev
	.uleb128	0
	.uleb128	0

;- - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
	;; DIE #192: variable PORTB_INTCTRL
	.section	.debug_info
	.uleb128	192	; ref to abbrev 192
	.section	.debug_abbrev
	.uleb128	192
	.uleb128	DW_TAG_variable
	.byte		DW_CHILDREN_no

	.uleb128	DW_AT_name
	.uleb128	DW_FORM_strp
	.section	.debug_str
.Lname192:
	.string		"PORTB_INTCTRL"
	.section	.debug_info
	.long		.Lname192

	.section	.debug_abbrev
	.uleb128	DW_AT_decl_file
	.uleb128	DW_FORM_data1
	.section	.debug_info
	.byte		0	; no source file information

	.section	.debug_abbrev
	.uleb128	DW_AT_decl_line
	.uleb128	DW_FORM_data1
	.section	.debug_info
	.byte		0	; no source line information

	.section	.debug_abbrev
	.uleb128	DW_AT_type
	.uleb128	DW_FORM_ref4
	.section	.debug_info
	.long		.Luint8_t - .Lssinfo

	.section	.debug_abbrev
	.uleb128	DW_AT_external
	.uleb128	DW_FORM_flag
	.section	.debug_info
	.byte		1

	.section	.debug_abbrev
	.uleb128	DW_AT_location
	.uleb128	DW_FORM_block1
	.section	.debug_info
	.byte		5	; length of block
	.byte		DW_OP_addr
	.long		0x800000 + 0x0620 + 0x09

	.section	.debug_abbrev
	.uleb128	0
	.uleb128	0

;- - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
	;; DIE #193: variable PORTB_INT0MASK
	.section	.debug_info
	.uleb128	193	; ref to abbrev 193
	.section	.debug_abbrev
	.uleb128	193
	.uleb128	DW_TAG_variable
	.byte		DW_CHILDREN_no

	.uleb128	DW_AT_name
	.uleb128	DW_FORM_strp
	.section	.debug_str
.Lname193:
	.string		"PORTB_INT0MASK"
	.section	.debug_info
	.long		.Lname193

	.section	.debug_abbrev
	.uleb128	DW_AT_decl_file
	.uleb128	DW_FORM_data1
	.section	.debug_info
	.byte		0	; no source file information

	.section	.debug_abbrev
	.uleb128	DW_AT_decl_line
	.uleb128	DW_FORM_data1
	.section	.debug_info
	.byte		0	; no source line information

	.section	.debug_abbrev
	.uleb128	DW_AT_type
	.uleb128	DW_FORM_ref4
	.section	.debug_info
	.long		.Luint8_t - .Lssinfo

	.section	.debug_abbrev
	.uleb128	DW_AT_external
	.uleb128	DW_FORM_flag
	.section	.debug_info
	.byte		1

	.section	.debug_abbrev
	.uleb128	DW_AT_location
	.uleb128	DW_FORM_block1
	.section	.debug_info
	.byte		5	; length of block
	.byte		DW_OP_addr
	.long		0x800000 + 0x0620 + 0x0A

	.section	.debug_abbrev
	.uleb128	0
	.uleb128	0

;- - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
	;; DIE #194: variable PORTB_INT1MASK
	.section	.debug_info
	.uleb128	194	; ref to abbrev 194
	.section	.debug_abbrev
	.uleb128	194
	.uleb128	DW_TAG_variable
	.byte		DW_CHILDREN_no

	.uleb128	DW_AT_name
	.uleb128	DW_FORM_strp
	.section	.debug_str
.Lname194:
	.string		"PORTB_INT1MASK"
	.section	.debug_info
	.long		.Lname194

	.section	.debug_abbrev
	.uleb128	DW_AT_decl_file
	.uleb128	DW_FORM_data1
	.section	.debug_info
	.byte		0	; no source file information

	.section	.debug_abbrev
	.uleb128	DW_AT_decl_line
	.uleb128	DW_FORM_data1
	.section	.debug_info
	.byte		0	; no source line information

	.section	.debug_abbrev
	.uleb128	DW_AT_type
	.uleb128	DW_FORM_ref4
	.section	.debug_info
	.long		.Luint8_t - .Lssinfo

	.section	.debug_abbrev
	.uleb128	DW_AT_external
	.uleb128	DW_FORM_flag
	.section	.debug_info
	.byte		1

	.section	.debug_abbrev
	.uleb128	DW_AT_location
	.uleb128	DW_FORM_block1
	.section	.debug_info
	.byte		5	; length of block
	.byte		DW_OP_addr
	.long		0x800000 + 0x0620 + 0x0B

	.section	.debug_abbrev
	.uleb128	0
	.uleb128	0

;- - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
	;; DIE #195: variable PORTB_INTFLAGS
	.section	.debug_info
	.uleb128	195	; ref to abbrev 195
	.section	.debug_abbrev
	.uleb128	195
	.uleb128	DW_TAG_variable
	.byte		DW_CHILDREN_no

	.uleb128	DW_AT_name
	.uleb128	DW_FORM_strp
	.section	.debug_str
.Lname195:
	.string		"PORTB_INTFLAGS"
	.section	.debug_info
	.long		.Lname195

	.section	.debug_abbrev
	.uleb128	DW_AT_decl_file
	.uleb128	DW_FORM_data1
	.section	.debug_info
	.byte		0	; no source file information

	.section	.debug_abbrev
	.uleb128	DW_AT_decl_line
	.uleb128	DW_FORM_data1
	.section	.debug_info
	.byte		0	; no source line information

	.section	.debug_abbrev
	.uleb128	DW_AT_type
	.uleb128	DW_FORM_ref4
	.section	.debug_info
	.long		.Luint8_t - .Lssinfo

	.section	.debug_abbrev
	.uleb128	DW_AT_external
	.uleb128	DW_FORM_flag
	.section	.debug_info
	.byte		1

	.section	.debug_abbrev
	.uleb128	DW_AT_location
	.uleb128	DW_FORM_block1
	.section	.debug_info
	.byte		5	; length of block
	.byte		DW_OP_addr
	.long		0x800000 + 0x0620 + 0x0C

	.section	.debug_abbrev
	.uleb128	0
	.uleb128	0

;- - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
	;; DIE #196: variable PORTB_REMAP
	.section	.debug_info
	.uleb128	196	; ref to abbrev 196
	.section	.debug_abbrev
	.uleb128	196
	.uleb128	DW_TAG_variable
	.byte		DW_CHILDREN_no

	.uleb128	DW_AT_name
	.uleb128	DW_FORM_strp
	.section	.debug_str
.Lname196:
	.string		"PORTB_REMAP"
	.section	.debug_info
	.long		.Lname196

	.section	.debug_abbrev
	.uleb128	DW_AT_decl_file
	.uleb128	DW_FORM_data1
	.section	.debug_info
	.byte		0	; no source file information

	.section	.debug_abbrev
	.uleb128	DW_AT_decl_line
	.uleb128	DW_FORM_data1
	.section	.debug_info
	.byte		0	; no source line information

	.section	.debug_abbrev
	.uleb128	DW_AT_type
	.uleb128	DW_FORM_ref4
	.section	.debug_info
	.long		.Luint8_t - .Lssinfo

	.section	.debug_abbrev
	.uleb128	DW_AT_external
	.uleb128	DW_FORM_flag
	.section	.debug_info
	.byte		1

	.section	.debug_abbrev
	.uleb128	DW_AT_location
	.uleb128	DW_FORM_block1
	.section	.debug_info
	.byte		5	; length of block
	.byte		DW_OP_addr
	.long		0x800000 + 0x0620 + 0x0E

	.section	.debug_abbrev
	.uleb128	0
	.uleb128	0

;- - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
	;; DIE #197: variable PORTB_PIN0CTRL
	.section	.debug_info
	.uleb128	197	; ref to abbrev 197
	.section	.debug_abbrev
	.uleb128	197
	.uleb128	DW_TAG_variable
	.byte		DW_CHILDREN_no

	.uleb128	DW_AT_name
	.uleb128	DW_FORM_strp
	.section	.debug_str
.Lname197:
	.string		"PORTB_PIN0CTRL"
	.section	.debug_info
	.long		.Lname197

	.section	.debug_abbrev
	.uleb128	DW_AT_decl_file
	.uleb128	DW_FORM_data1
	.section	.debug_info
	.byte		0	; no source file information

	.section	.debug_abbrev
	.uleb128	DW_AT_decl_line
	.uleb128	DW_FORM_data1
	.section	.debug_info
	.byte		0	; no source line information

	.section	.debug_abbrev
	.uleb128	DW_AT_type
	.uleb128	DW_FORM_ref4
	.section	.debug_info
	.long		.Luint8_t - .Lssinfo

	.section	.debug_abbrev
	.uleb128	DW_AT_external
	.uleb128	DW_FORM_flag
	.section	.debug_info
	.byte		1

	.section	.debug_abbrev
	.uleb128	DW_AT_location
	.uleb128	DW_FORM_block1
	.section	.debug_info
	.byte		5	; length of block
	.byte		DW_OP_addr
	.long		0x800000 + 0x0620 + 0x10

	.section	.debug_abbrev
	.uleb128	0
	.uleb128	0

;- - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
	;; DIE #198: variable PORTB_PIN1CTRL
	.section	.debug_info
	.uleb128	198	; ref to abbrev 198
	.section	.debug_abbrev
	.uleb128	198
	.uleb128	DW_TAG_variable
	.byte		DW_CHILDREN_no

	.uleb128	DW_AT_name
	.uleb128	DW_FORM_strp
	.section	.debug_str
.Lname198:
	.string		"PORTB_PIN1CTRL"
	.section	.debug_info
	.long		.Lname198

	.section	.debug_abbrev
	.uleb128	DW_AT_decl_file
	.uleb128	DW_FORM_data1
	.section	.debug_info
	.byte		0	; no source file information

	.section	.debug_abbrev
	.uleb128	DW_AT_decl_line
	.uleb128	DW_FORM_data1
	.section	.debug_info
	.byte		0	; no source line information

	.section	.debug_abbrev
	.uleb128	DW_AT_type
	.uleb128	DW_FORM_ref4
	.section	.debug_info
	.long		.Luint8_t - .Lssinfo

	.section	.debug_abbrev
	.uleb128	DW_AT_external
	.uleb128	DW_FORM_flag
	.section	.debug_info
	.byte		1

	.section	.debug_abbrev
	.uleb128	DW_AT_location
	.uleb128	DW_FORM_block1
	.section	.debug_info
	.byte		5	; length of block
	.byte		DW_OP_addr
	.long		0x800000 + 0x0620 + 0x11

	.section	.debug_abbrev
	.uleb128	0
	.uleb128	0

;- - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
	;; DIE #199: variable PORTB_PIN2CTRL
	.section	.debug_info
	.uleb128	199	; ref to abbrev 199
	.section	.debug_abbrev
	.uleb128	199
	.uleb128	DW_TAG_variable
	.byte		DW_CHILDREN_no

	.uleb128	DW_AT_name
	.uleb128	DW_FORM_strp
	.section	.debug_str
.Lname199:
	.string		"PORTB_PIN2CTRL"
	.section	.debug_info
	.long		.Lname199

	.section	.debug_abbrev
	.uleb128	DW_AT_decl_file
	.uleb128	DW_FORM_data1
	.section	.debug_info
	.byte		0	; no source file information

	.section	.debug_abbrev
	.uleb128	DW_AT_decl_line
	.uleb128	DW_FORM_data1
	.section	.debug_info
	.byte		0	; no source line information

	.section	.debug_abbrev
	.uleb128	DW_AT_type
	.uleb128	DW_FORM_ref4
	.section	.debug_info
	.long		.Luint8_t - .Lssinfo

	.section	.debug_abbrev
	.uleb128	DW_AT_external
	.uleb128	DW_FORM_flag
	.section	.debug_info
	.byte		1

	.section	.debug_abbrev
	.uleb128	DW_AT_location
	.uleb128	DW_FORM_block1
	.section	.debug_info
	.byte		5	; length of block
	.byte		DW_OP_addr
	.long		0x800000 + 0x0620 + 0x12

	.section	.debug_abbrev
	.uleb128	0
	.uleb128	0

;- - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
	;; DIE #200: variable PORTB_PIN3CTRL
	.section	.debug_info
	.uleb128	200	; ref to abbrev 200
	.section	.debug_abbrev
	.uleb128	200
	.uleb128	DW_TAG_variable
	.byte		DW_CHILDREN_no

	.uleb128	DW_AT_name
	.uleb128	DW_FORM_strp
	.section	.debug_str
.Lname200:
	.string		"PORTB_PIN3CTRL"
	.section	.debug_info
	.long		.Lname200

	.section	.debug_abbrev
	.uleb128	DW_AT_decl_file
	.uleb128	DW_FORM_data1
	.section	.debug_info
	.byte		0	; no source file information

	.section	.debug_abbrev
	.uleb128	DW_AT_decl_line
	.uleb128	DW_FORM_data1
	.section	.debug_info
	.byte		0	; no source line information

	.section	.debug_abbrev
	.uleb128	DW_AT_type
	.uleb128	DW_FORM_ref4
	.section	.debug_info
	.long		.Luint8_t - .Lssinfo

	.section	.debug_abbrev
	.uleb128	DW_AT_external
	.uleb128	DW_FORM_flag
	.section	.debug_info
	.byte		1

	.section	.debug_abbrev
	.uleb128	DW_AT_location
	.uleb128	DW_FORM_block1
	.section	.debug_info
	.byte		5	; length of block
	.byte		DW_OP_addr
	.long		0x800000 + 0x0620 + 0x13

	.section	.debug_abbrev
	.uleb128	0
	.uleb128	0

;- - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
	;; DIE #201: variable PORTB_PIN4CTRL
	.section	.debug_info
	.uleb128	201	; ref to abbrev 201
	.section	.debug_abbrev
	.uleb128	201
	.uleb128	DW_TAG_variable
	.byte		DW_CHILDREN_no

	.uleb128	DW_AT_name
	.uleb128	DW_FORM_strp
	.section	.debug_str
.Lname201:
	.string		"PORTB_PIN4CTRL"
	.section	.debug_info
	.long		.Lname201

	.section	.debug_abbrev
	.uleb128	DW_AT_decl_file
	.uleb128	DW_FORM_data1
	.section	.debug_info
	.byte		0	; no source file information

	.section	.debug_abbrev
	.uleb128	DW_AT_decl_line
	.uleb128	DW_FORM_data1
	.section	.debug_info
	.byte		0	; no source line information

	.section	.debug_abbrev
	.uleb128	DW_AT_type
	.uleb128	DW_FORM_ref4
	.section	.debug_info
	.long		.Luint8_t - .Lssinfo

	.section	.debug_abbrev
	.uleb128	DW_AT_external
	.uleb128	DW_FORM_flag
	.section	.debug_info
	.byte		1

	.section	.debug_abbrev
	.uleb128	DW_AT_location
	.uleb128	DW_FORM_block1
	.section	.debug_info
	.byte		5	; length of block
	.byte		DW_OP_addr
	.long		0x800000 + 0x0620 + 0x14

	.section	.debug_abbrev
	.uleb128	0
	.uleb128	0

;- - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
	;; DIE #202: variable PORTB_PIN5CTRL
	.section	.debug_info
	.uleb128	202	; ref to abbrev 202
	.section	.debug_abbrev
	.uleb128	202
	.uleb128	DW_TAG_variable
	.byte		DW_CHILDREN_no

	.uleb128	DW_AT_name
	.uleb128	DW_FORM_strp
	.section	.debug_str
.Lname202:
	.string		"PORTB_PIN5CTRL"
	.section	.debug_info
	.long		.Lname202

	.section	.debug_abbrev
	.uleb128	DW_AT_decl_file
	.uleb128	DW_FORM_data1
	.section	.debug_info
	.byte		0	; no source file information

	.section	.debug_abbrev
	.uleb128	DW_AT_decl_line
	.uleb128	DW_FORM_data1
	.section	.debug_info
	.byte		0	; no source line information

	.section	.debug_abbrev
	.uleb128	DW_AT_type
	.uleb128	DW_FORM_ref4
	.section	.debug_info
	.long		.Luint8_t - .Lssinfo

	.section	.debug_abbrev
	.uleb128	DW_AT_external
	.uleb128	DW_FORM_flag
	.section	.debug_info
	.byte		1

	.section	.debug_abbrev
	.uleb128	DW_AT_location
	.uleb128	DW_FORM_block1
	.section	.debug_info
	.byte		5	; length of block
	.byte		DW_OP_addr
	.long		0x800000 + 0x0620 + 0x15

	.section	.debug_abbrev
	.uleb128	0
	.uleb128	0

;- - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
	;; DIE #203: variable PORTB_PIN6CTRL
	.section	.debug_info
	.uleb128	203	; ref to abbrev 203
	.section	.debug_abbrev
	.uleb128	203
	.uleb128	DW_TAG_variable
	.byte		DW_CHILDREN_no

	.uleb128	DW_AT_name
	.uleb128	DW_FORM_strp
	.section	.debug_str
.Lname203:
	.string		"PORTB_PIN6CTRL"
	.section	.debug_info
	.long		.Lname203

	.section	.debug_abbrev
	.uleb128	DW_AT_decl_file
	.uleb128	DW_FORM_data1
	.section	.debug_info
	.byte		0	; no source file information

	.section	.debug_abbrev
	.uleb128	DW_AT_decl_line
	.uleb128	DW_FORM_data1
	.section	.debug_info
	.byte		0	; no source line information

	.section	.debug_abbrev
	.uleb128	DW_AT_type
	.uleb128	DW_FORM_ref4
	.section	.debug_info
	.long		.Luint8_t - .Lssinfo

	.section	.debug_abbrev
	.uleb128	DW_AT_external
	.uleb128	DW_FORM_flag
	.section	.debug_info
	.byte		1

	.section	.debug_abbrev
	.uleb128	DW_AT_location
	.uleb128	DW_FORM_block1
	.section	.debug_info
	.byte		5	; length of block
	.byte		DW_OP_addr
	.long		0x800000 + 0x0620 + 0x16

	.section	.debug_abbrev
	.uleb128	0
	.uleb128	0

;- - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
	;; DIE #204: variable PORTB_PIN7CTRL
	.section	.debug_info
	.uleb128	204	; ref to abbrev 204
	.section	.debug_abbrev
	.uleb128	204
	.uleb128	DW_TAG_variable
	.byte		DW_CHILDREN_no

	.uleb128	DW_AT_name
	.uleb128	DW_FORM_strp
	.section	.debug_str
.Lname204:
	.string		"PORTB_PIN7CTRL"
	.section	.debug_info
	.long		.Lname204

	.section	.debug_abbrev
	.uleb128	DW_AT_decl_file
	.uleb128	DW_FORM_data1
	.section	.debug_info
	.byte		0	; no source file information

	.section	.debug_abbrev
	.uleb128	DW_AT_decl_line
	.uleb128	DW_FORM_data1
	.section	.debug_info
	.byte		0	; no source line information

	.section	.debug_abbrev
	.uleb128	DW_AT_type
	.uleb128	DW_FORM_ref4
	.section	.debug_info
	.long		.Luint8_t - .Lssinfo

	.section	.debug_abbrev
	.uleb128	DW_AT_external
	.uleb128	DW_FORM_flag
	.section	.debug_info
	.byte		1

	.section	.debug_abbrev
	.uleb128	DW_AT_location
	.uleb128	DW_FORM_block1
	.section	.debug_info
	.byte		5	; length of block
	.byte		DW_OP_addr
	.long		0x800000 + 0x0620 + 0x17

	.section	.debug_abbrev
	.uleb128	0
	.uleb128	0

;- - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
	;; DIE #205: variable PORTC_DIR
	.section	.debug_info
	.uleb128	205	; ref to abbrev 205
	.section	.debug_abbrev
	.uleb128	205
	.uleb128	DW_TAG_variable
	.byte		DW_CHILDREN_no

	.uleb128	DW_AT_name
	.uleb128	DW_FORM_strp
	.section	.debug_str
.Lname205:
	.string		"PORTC_DIR"
	.section	.debug_info
	.long		.Lname205

	.section	.debug_abbrev
	.uleb128	DW_AT_decl_file
	.uleb128	DW_FORM_data1
	.section	.debug_info
	.byte		0	; no source file information

	.section	.debug_abbrev
	.uleb128	DW_AT_decl_line
	.uleb128	DW_FORM_data1
	.section	.debug_info
	.byte		0	; no source line information

	.section	.debug_abbrev
	.uleb128	DW_AT_type
	.uleb128	DW_FORM_ref4
	.section	.debug_info
	.long		.Luint8_t - .Lssinfo

	.section	.debug_abbrev
	.uleb128	DW_AT_external
	.uleb128	DW_FORM_flag
	.section	.debug_info
	.byte		1

	.section	.debug_abbrev
	.uleb128	DW_AT_location
	.uleb128	DW_FORM_block1
	.section	.debug_info
	.byte		5	; length of block
	.byte		DW_OP_addr
	.long		0x800000 + 0x0640 + 0x00

	.section	.debug_abbrev
	.uleb128	0
	.uleb128	0

;- - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
	;; DIE #206: variable PORTC_DIRSET
	.section	.debug_info
	.uleb128	206	; ref to abbrev 206
	.section	.debug_abbrev
	.uleb128	206
	.uleb128	DW_TAG_variable
	.byte		DW_CHILDREN_no

	.uleb128	DW_AT_name
	.uleb128	DW_FORM_strp
	.section	.debug_str
.Lname206:
	.string		"PORTC_DIRSET"
	.section	.debug_info
	.long		.Lname206

	.section	.debug_abbrev
	.uleb128	DW_AT_decl_file
	.uleb128	DW_FORM_data1
	.section	.debug_info
	.byte		0	; no source file information

	.section	.debug_abbrev
	.uleb128	DW_AT_decl_line
	.uleb128	DW_FORM_data1
	.section	.debug_info
	.byte		0	; no source line information

	.section	.debug_abbrev
	.uleb128	DW_AT_type
	.uleb128	DW_FORM_ref4
	.section	.debug_info
	.long		.Luint8_t - .Lssinfo

	.section	.debug_abbrev
	.uleb128	DW_AT_external
	.uleb128	DW_FORM_flag
	.section	.debug_info
	.byte		1

	.section	.debug_abbrev
	.uleb128	DW_AT_location
	.uleb128	DW_FORM_block1
	.section	.debug_info
	.byte		5	; length of block
	.byte		DW_OP_addr
	.long		0x800000 + 0x0640 + 0x01

	.section	.debug_abbrev
	.uleb128	0
	.uleb128	0

;- - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
	;; DIE #207: variable PORTC_DIRCLR
	.section	.debug_info
	.uleb128	207	; ref to abbrev 207
	.section	.debug_abbrev
	.uleb128	207
	.uleb128	DW_TAG_variable
	.byte		DW_CHILDREN_no

	.uleb128	DW_AT_name
	.uleb128	DW_FORM_strp
	.section	.debug_str
.Lname207:
	.string		"PORTC_DIRCLR"
	.section	.debug_info
	.long		.Lname207

	.section	.debug_abbrev
	.uleb128	DW_AT_decl_file
	.uleb128	DW_FORM_data1
	.section	.debug_info
	.byte		0	; no source file information

	.section	.debug_abbrev
	.uleb128	DW_AT_decl_line
	.uleb128	DW_FORM_data1
	.section	.debug_info
	.byte		0	; no source line information

	.section	.debug_abbrev
	.uleb128	DW_AT_type
	.uleb128	DW_FORM_ref4
	.section	.debug_info
	.long		.Luint8_t - .Lssinfo

	.section	.debug_abbrev
	.uleb128	DW_AT_external
	.uleb128	DW_FORM_flag
	.section	.debug_info
	.byte		1

	.section	.debug_abbrev
	.uleb128	DW_AT_location
	.uleb128	DW_FORM_block1
	.section	.debug_info
	.byte		5	; length of block
	.byte		DW_OP_addr
	.long		0x800000 + 0x0640 + 0x02

	.section	.debug_abbrev
	.uleb128	0
	.uleb128	0

;- - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
	;; DIE #208: variable PORTC_DIRTGL
	.section	.debug_info
	.uleb128	208	; ref to abbrev 208
	.section	.debug_abbrev
	.uleb128	208
	.uleb128	DW_TAG_variable
	.byte		DW_CHILDREN_no

	.uleb128	DW_AT_name
	.uleb128	DW_FORM_strp
	.section	.debug_str
.Lname208:
	.string		"PORTC_DIRTGL"
	.section	.debug_info
	.long		.Lname208

	.section	.debug_abbrev
	.uleb128	DW_AT_decl_file
	.uleb128	DW_FORM_data1
	.section	.debug_info
	.byte		0	; no source file information

	.section	.debug_abbrev
	.uleb128	DW_AT_decl_line
	.uleb128	DW_FORM_data1
	.section	.debug_info
	.byte		0	; no source line information

	.section	.debug_abbrev
	.uleb128	DW_AT_type
	.uleb128	DW_FORM_ref4
	.section	.debug_info
	.long		.Luint8_t - .Lssinfo

	.section	.debug_abbrev
	.uleb128	DW_AT_external
	.uleb128	DW_FORM_flag
	.section	.debug_info
	.byte		1

	.section	.debug_abbrev
	.uleb128	DW_AT_location
	.uleb128	DW_FORM_block1
	.section	.debug_info
	.byte		5	; length of block
	.byte		DW_OP_addr
	.long		0x800000 + 0x0640 + 0x03

	.section	.debug_abbrev
	.uleb128	0
	.uleb128	0

;- - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
	;; DIE #209: variable PORTC_OUT
	.section	.debug_info
	.uleb128	209	; ref to abbrev 209
	.section	.debug_abbrev
	.uleb128	209
	.uleb128	DW_TAG_variable
	.byte		DW_CHILDREN_no

	.uleb128	DW_AT_name
	.uleb128	DW_FORM_strp
	.section	.debug_str
.Lname209:
	.string		"PORTC_OUT"
	.section	.debug_info
	.long		.Lname209

	.section	.debug_abbrev
	.uleb128	DW_AT_decl_file
	.uleb128	DW_FORM_data1
	.section	.debug_info
	.byte		0	; no source file information

	.section	.debug_abbrev
	.uleb128	DW_AT_decl_line
	.uleb128	DW_FORM_data1
	.section	.debug_info
	.byte		0	; no source line information

	.section	.debug_abbrev
	.uleb128	DW_AT_type
	.uleb128	DW_FORM_ref4
	.section	.debug_info
	.long		.Luint8_t - .Lssinfo

	.section	.debug_abbrev
	.uleb128	DW_AT_external
	.uleb128	DW_FORM_flag
	.section	.debug_info
	.byte		1

	.section	.debug_abbrev
	.uleb128	DW_AT_location
	.uleb128	DW_FORM_block1
	.section	.debug_info
	.byte		5	; length of block
	.byte		DW_OP_addr
	.long		0x800000 + 0x0640 + 0x04

	.section	.debug_abbrev
	.uleb128	0
	.uleb128	0

;- - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
	;; DIE #210: variable PORTC_OUTSET
	.section	.debug_info
	.uleb128	210	; ref to abbrev 210
	.section	.debug_abbrev
	.uleb128	210
	.uleb128	DW_TAG_variable
	.byte		DW_CHILDREN_no

	.uleb128	DW_AT_name
	.uleb128	DW_FORM_strp
	.section	.debug_str
.Lname210:
	.string		"PORTC_OUTSET"
	.section	.debug_info
	.long		.Lname210

	.section	.debug_abbrev
	.uleb128	DW_AT_decl_file
	.uleb128	DW_FORM_data1
	.section	.debug_info
	.byte		0	; no source file information

	.section	.debug_abbrev
	.uleb128	DW_AT_decl_line
	.uleb128	DW_FORM_data1
	.section	.debug_info
	.byte		0	; no source line information

	.section	.debug_abbrev
	.uleb128	DW_AT_type
	.uleb128	DW_FORM_ref4
	.section	.debug_info
	.long		.Luint8_t - .Lssinfo

	.section	.debug_abbrev
	.uleb128	DW_AT_external
	.uleb128	DW_FORM_flag
	.section	.debug_info
	.byte		1

	.section	.debug_abbrev
	.uleb128	DW_AT_location
	.uleb128	DW_FORM_block1
	.section	.debug_info
	.byte		5	; length of block
	.byte		DW_OP_addr
	.long		0x800000 + 0x0640 + 0x05

	.section	.debug_abbrev
	.uleb128	0
	.uleb128	0

;- - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
	;; DIE #211: variable PORTC_OUTCLR
	.section	.debug_info
	.uleb128	211	; ref to abbrev 211
	.section	.debug_abbrev
	.uleb128	211
	.uleb128	DW_TAG_variable
	.byte		DW_CHILDREN_no

	.uleb128	DW_AT_name
	.uleb128	DW_FORM_strp
	.section	.debug_str
.Lname211:
	.string		"PORTC_OUTCLR"
	.section	.debug_info
	.long		.Lname211

	.section	.debug_abbrev
	.uleb128	DW_AT_decl_file
	.uleb128	DW_FORM_data1
	.section	.debug_info
	.byte		0	; no source file information

	.section	.debug_abbrev
	.uleb128	DW_AT_decl_line
	.uleb128	DW_FORM_data1
	.section	.debug_info
	.byte		0	; no source line information

	.section	.debug_abbrev
	.uleb128	DW_AT_type
	.uleb128	DW_FORM_ref4
	.section	.debug_info
	.long		.Luint8_t - .Lssinfo

	.section	.debug_abbrev
	.uleb128	DW_AT_external
	.uleb128	DW_FORM_flag
	.section	.debug_info
	.byte		1

	.section	.debug_abbrev
	.uleb128	DW_AT_location
	.uleb128	DW_FORM_block1
	.section	.debug_info
	.byte		5	; length of block
	.byte		DW_OP_addr
	.long		0x800000 + 0x0640 + 0x06

	.section	.debug_abbrev
	.uleb128	0
	.uleb128	0

;- - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
	;; DIE #212: variable PORTC_OUTTGL
	.section	.debug_info
	.uleb128	212	; ref to abbrev 212
	.section	.debug_abbrev
	.uleb128	212
	.uleb128	DW_TAG_variable
	.byte		DW_CHILDREN_no

	.uleb128	DW_AT_name
	.uleb128	DW_FORM_strp
	.section	.debug_str
.Lname212:
	.string		"PORTC_OUTTGL"
	.section	.debug_info
	.long		.Lname212

	.section	.debug_abbrev
	.uleb128	DW_AT_decl_file
	.uleb128	DW_FORM_data1
	.section	.debug_info
	.byte		0	; no source file information

	.section	.debug_abbrev
	.uleb128	DW_AT_decl_line
	.uleb128	DW_FORM_data1
	.section	.debug_info
	.byte		0	; no source line information

	.section	.debug_abbrev
	.uleb128	DW_AT_type
	.uleb128	DW_FORM_ref4
	.section	.debug_info
	.long		.Luint8_t - .Lssinfo

	.section	.debug_abbrev
	.uleb128	DW_AT_external
	.uleb128	DW_FORM_flag
	.section	.debug_info
	.byte		1

	.section	.debug_abbrev
	.uleb128	DW_AT_location
	.uleb128	DW_FORM_block1
	.section	.debug_info
	.byte		5	; length of block
	.byte		DW_OP_addr
	.long		0x800000 + 0x0640 + 0x07

	.section	.debug_abbrev
	.uleb128	0
	.uleb128	0

;- - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
	;; DIE #213: variable PORTC_IN
	.section	.debug_info
	.uleb128	213	; ref to abbrev 213
	.section	.debug_abbrev
	.uleb128	213
	.uleb128	DW_TAG_variable
	.byte		DW_CHILDREN_no

	.uleb128	DW_AT_name
	.uleb128	DW_FORM_strp
	.section	.debug_str
.Lname213:
	.string		"PORTC_IN"
	.section	.debug_info
	.long		.Lname213

	.section	.debug_abbrev
	.uleb128	DW_AT_decl_file
	.uleb128	DW_FORM_data1
	.section	.debug_info
	.byte		0	; no source file information

	.section	.debug_abbrev
	.uleb128	DW_AT_decl_line
	.uleb128	DW_FORM_data1
	.section	.debug_info
	.byte		0	; no source line information

	.section	.debug_abbrev
	.uleb128	DW_AT_type
	.uleb128	DW_FORM_ref4
	.section	.debug_info
	.long		.Luint8_t - .Lssinfo

	.section	.debug_abbrev
	.uleb128	DW_AT_external
	.uleb128	DW_FORM_flag
	.section	.debug_info
	.byte		1

	.section	.debug_abbrev
	.uleb128	DW_AT_location
	.uleb128	DW_FORM_block1
	.section	.debug_info
	.byte		5	; length of block
	.byte		DW_OP_addr
	.long		0x800000 + 0x0640 + 0x08

	.section	.debug_abbrev
	.uleb128	0
	.uleb128	0

;- - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
	;; DIE #214: variable PORTC_INTCTRL
	.section	.debug_info
	.uleb128	214	; ref to abbrev 214
	.section	.debug_abbrev
	.uleb128	214
	.uleb128	DW_TAG_variable
	.byte		DW_CHILDREN_no

	.uleb128	DW_AT_name
	.uleb128	DW_FORM_strp
	.section	.debug_str
.Lname214:
	.string		"PORTC_INTCTRL"
	.section	.debug_info
	.long		.Lname214

	.section	.debug_abbrev
	.uleb128	DW_AT_decl_file
	.uleb128	DW_FORM_data1
	.section	.debug_info
	.byte		0	; no source file information

	.section	.debug_abbrev
	.uleb128	DW_AT_decl_line
	.uleb128	DW_FORM_data1
	.section	.debug_info
	.byte		0	; no source line information

	.section	.debug_abbrev
	.uleb128	DW_AT_type
	.uleb128	DW_FORM_ref4
	.section	.debug_info
	.long		.Luint8_t - .Lssinfo

	.section	.debug_abbrev
	.uleb128	DW_AT_external
	.uleb128	DW_FORM_flag
	.section	.debug_info
	.byte		1

	.section	.debug_abbrev
	.uleb128	DW_AT_location
	.uleb128	DW_FORM_block1
	.section	.debug_info
	.byte		5	; length of block
	.byte		DW_OP_addr
	.long		0x800000 + 0x0640 + 0x09

	.section	.debug_abbrev
	.uleb128	0
	.uleb128	0

;- - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
	;; DIE #215: variable PORTC_INT0MASK
	.section	.debug_info
	.uleb128	215	; ref to abbrev 215
	.section	.debug_abbrev
	.uleb128	215
	.uleb128	DW_TAG_variable
	.byte		DW_CHILDREN_no

	.uleb128	DW_AT_name
	.uleb128	DW_FORM_strp
	.section	.debug_str
.Lname215:
	.string		"PORTC_INT0MASK"
	.section	.debug_info
	.long		.Lname215

	.section	.debug_abbrev
	.uleb128	DW_AT_decl_file
	.uleb128	DW_FORM_data1
	.section	.debug_info
	.byte		0	; no source file information

	.section	.debug_abbrev
	.uleb128	DW_AT_decl_line
	.uleb128	DW_FORM_data1
	.section	.debug_info
	.byte		0	; no source line information

	.section	.debug_abbrev
	.uleb128	DW_AT_type
	.uleb128	DW_FORM_ref4
	.section	.debug_info
	.long		.Luint8_t - .Lssinfo

	.section	.debug_abbrev
	.uleb128	DW_AT_external
	.uleb128	DW_FORM_flag
	.section	.debug_info
	.byte		1

	.section	.debug_abbrev
	.uleb128	DW_AT_location
	.uleb128	DW_FORM_block1
	.section	.debug_info
	.byte		5	; length of block
	.byte		DW_OP_addr
	.long		0x800000 + 0x0640 + 0x0A

	.section	.debug_abbrev
	.uleb128	0
	.uleb128	0

;- - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
	;; DIE #216: variable PORTC_INT1MASK
	.section	.debug_info
	.uleb128	216	; ref to abbrev 216
	.section	.debug_abbrev
	.uleb128	216
	.uleb128	DW_TAG_variable
	.byte		DW_CHILDREN_no

	.uleb128	DW_AT_name
	.uleb128	DW_FORM_strp
	.section	.debug_str
.Lname216:
	.string		"PORTC_INT1MASK"
	.section	.debug_info
	.long		.Lname216

	.section	.debug_abbrev
	.uleb128	DW_AT_decl_file
	.uleb128	DW_FORM_data1
	.section	.debug_info
	.byte		0	; no source file information

	.section	.debug_abbrev
	.uleb128	DW_AT_decl_line
	.uleb128	DW_FORM_data1
	.section	.debug_info
	.byte		0	; no source line information

	.section	.debug_abbrev
	.uleb128	DW_AT_type
	.uleb128	DW_FORM_ref4
	.section	.debug_info
	.long		.Luint8_t - .Lssinfo

	.section	.debug_abbrev
	.uleb128	DW_AT_external
	.uleb128	DW_FORM_flag
	.section	.debug_info
	.byte		1

	.section	.debug_abbrev
	.uleb128	DW_AT_location
	.uleb128	DW_FORM_block1
	.section	.debug_info
	.byte		5	; length of block
	.byte		DW_OP_addr
	.long		0x800000 + 0x0640 + 0x0B

	.section	.debug_abbrev
	.uleb128	0
	.uleb128	0

;- - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
	;; DIE #217: variable PORTC_INTFLAGS
	.section	.debug_info
	.uleb128	217	; ref to abbrev 217
	.section	.debug_abbrev
	.uleb128	217
	.uleb128	DW_TAG_variable
	.byte		DW_CHILDREN_no

	.uleb128	DW_AT_name
	.uleb128	DW_FORM_strp
	.section	.debug_str
.Lname217:
	.string		"PORTC_INTFLAGS"
	.section	.debug_info
	.long		.Lname217

	.section	.debug_abbrev
	.uleb128	DW_AT_decl_file
	.uleb128	DW_FORM_data1
	.section	.debug_info
	.byte		0	; no source file information

	.section	.debug_abbrev
	.uleb128	DW_AT_decl_line
	.uleb128	DW_FORM_data1
	.section	.debug_info
	.byte		0	; no source line information

	.section	.debug_abbrev
	.uleb128	DW_AT_type
	.uleb128	DW_FORM_ref4
	.section	.debug_info
	.long		.Luint8_t - .Lssinfo

	.section	.debug_abbrev
	.uleb128	DW_AT_external
	.uleb128	DW_FORM_flag
	.section	.debug_info
	.byte		1

	.section	.debug_abbrev
	.uleb128	DW_AT_location
	.uleb128	DW_FORM_block1
	.section	.debug_info
	.byte		5	; length of block
	.byte		DW_OP_addr
	.long		0x800000 + 0x0640 + 0x0C

	.section	.debug_abbrev
	.uleb128	0
	.uleb128	0

;- - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
	;; DIE #218: variable PORTC_REMAP
	.section	.debug_info
	.uleb128	218	; ref to abbrev 218
	.section	.debug_abbrev
	.uleb128	218
	.uleb128	DW_TAG_variable
	.byte		DW_CHILDREN_no

	.uleb128	DW_AT_name
	.uleb128	DW_FORM_strp
	.section	.debug_str
.Lname218:
	.string		"PORTC_REMAP"
	.section	.debug_info
	.long		.Lname218

	.section	.debug_abbrev
	.uleb128	DW_AT_decl_file
	.uleb128	DW_FORM_data1
	.section	.debug_info
	.byte		0	; no source file information

	.section	.debug_abbrev
	.uleb128	DW_AT_decl_line
	.uleb128	DW_FORM_data1
	.section	.debug_info
	.byte		0	; no source line information

	.section	.debug_abbrev
	.uleb128	DW_AT_type
	.uleb128	DW_FORM_ref4
	.section	.debug_info
	.long		.Luint8_t - .Lssinfo

	.section	.debug_abbrev
	.uleb128	DW_AT_external
	.uleb128	DW_FORM_flag
	.section	.debug_info
	.byte		1

	.section	.debug_abbrev
	.uleb128	DW_AT_location
	.uleb128	DW_FORM_block1
	.section	.debug_info
	.byte		5	; length of block
	.byte		DW_OP_addr
	.long		0x800000 + 0x0640 + 0x0E

	.section	.debug_abbrev
	.uleb128	0
	.uleb128	0

;- - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
	;; DIE #219: variable PORTC_PIN0CTRL
	.section	.debug_info
	.uleb128	219	; ref to abbrev 219
	.section	.debug_abbrev
	.uleb128	219
	.uleb128	DW_TAG_variable
	.byte		DW_CHILDREN_no

	.uleb128	DW_AT_name
	.uleb128	DW_FORM_strp
	.section	.debug_str
.Lname219:
	.string		"PORTC_PIN0CTRL"
	.section	.debug_info
	.long		.Lname219

	.section	.debug_abbrev
	.uleb128	DW_AT_decl_file
	.uleb128	DW_FORM_data1
	.section	.debug_info
	.byte		0	; no source file information

	.section	.debug_abbrev
	.uleb128	DW_AT_decl_line
	.uleb128	DW_FORM_data1
	.section	.debug_info
	.byte		0	; no source line information

	.section	.debug_abbrev
	.uleb128	DW_AT_type
	.uleb128	DW_FORM_ref4
	.section	.debug_info
	.long		.Luint8_t - .Lssinfo

	.section	.debug_abbrev
	.uleb128	DW_AT_external
	.uleb128	DW_FORM_flag
	.section	.debug_info
	.byte		1

	.section	.debug_abbrev
	.uleb128	DW_AT_location
	.uleb128	DW_FORM_block1
	.section	.debug_info
	.byte		5	; length of block
	.byte		DW_OP_addr
	.long		0x800000 + 0x0640 + 0x10

	.section	.debug_abbrev
	.uleb128	0
	.uleb128	0

;- - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
	;; DIE #220: variable PORTC_PIN1CTRL
	.section	.debug_info
	.uleb128	220	; ref to abbrev 220
	.section	.debug_abbrev
	.uleb128	220
	.uleb128	DW_TAG_variable
	.byte		DW_CHILDREN_no

	.uleb128	DW_AT_name
	.uleb128	DW_FORM_strp
	.section	.debug_str
.Lname220:
	.string		"PORTC_PIN1CTRL"
	.section	.debug_info
	.long		.Lname220

	.section	.debug_abbrev
	.uleb128	DW_AT_decl_file
	.uleb128	DW_FORM_data1
	.section	.debug_info
	.byte		0	; no source file information

	.section	.debug_abbrev
	.uleb128	DW_AT_decl_line
	.uleb128	DW_FORM_data1
	.section	.debug_info
	.byte		0	; no source line information

	.section	.debug_abbrev
	.uleb128	DW_AT_type
	.uleb128	DW_FORM_ref4
	.section	.debug_info
	.long		.Luint8_t - .Lssinfo

	.section	.debug_abbrev
	.uleb128	DW_AT_external
	.uleb128	DW_FORM_flag
	.section	.debug_info
	.byte		1

	.section	.debug_abbrev
	.uleb128	DW_AT_location
	.uleb128	DW_FORM_block1
	.section	.debug_info
	.byte		5	; length of block
	.byte		DW_OP_addr
	.long		0x800000 + 0x0640 + 0x11

	.section	.debug_abbrev
	.uleb128	0
	.uleb128	0

;- - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
	;; DIE #221: variable PORTC_PIN2CTRL
	.section	.debug_info
	.uleb128	221	; ref to abbrev 221
	.section	.debug_abbrev
	.uleb128	221
	.uleb128	DW_TAG_variable
	.byte		DW_CHILDREN_no

	.uleb128	DW_AT_name
	.uleb128	DW_FORM_strp
	.section	.debug_str
.Lname221:
	.string		"PORTC_PIN2CTRL"
	.section	.debug_info
	.long		.Lname221

	.section	.debug_abbrev
	.uleb128	DW_AT_decl_file
	.uleb128	DW_FORM_data1
	.section	.debug_info
	.byte		0	; no source file information

	.section	.debug_abbrev
	.uleb128	DW_AT_decl_line
	.uleb128	DW_FORM_data1
	.section	.debug_info
	.byte		0	; no source line information

	.section	.debug_abbrev
	.uleb128	DW_AT_type
	.uleb128	DW_FORM_ref4
	.section	.debug_info
	.long		.Luint8_t - .Lssinfo

	.section	.debug_abbrev
	.uleb128	DW_AT_external
	.uleb128	DW_FORM_flag
	.section	.debug_info
	.byte		1

	.section	.debug_abbrev
	.uleb128	DW_AT_location
	.uleb128	DW_FORM_block1
	.section	.debug_info
	.byte		5	; length of block
	.byte		DW_OP_addr
	.long		0x800000 + 0x0640 + 0x12

	.section	.debug_abbrev
	.uleb128	0
	.uleb128	0

;- - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
	;; DIE #222: variable PORTC_PIN3CTRL
	.section	.debug_info
	.uleb128	222	; ref to abbrev 222
	.section	.debug_abbrev
	.uleb128	222
	.uleb128	DW_TAG_variable
	.byte		DW_CHILDREN_no

	.uleb128	DW_AT_name
	.uleb128	DW_FORM_strp
	.section	.debug_str
.Lname222:
	.string		"PORTC_PIN3CTRL"
	.section	.debug_info
	.long		.Lname222

	.section	.debug_abbrev
	.uleb128	DW_AT_decl_file
	.uleb128	DW_FORM_data1
	.section	.debug_info
	.byte		0	; no source file information

	.section	.debug_abbrev
	.uleb128	DW_AT_decl_line
	.uleb128	DW_FORM_data1
	.section	.debug_info
	.byte		0	; no source line information

	.section	.debug_abbrev
	.uleb128	DW_AT_type
	.uleb128	DW_FORM_ref4
	.section	.debug_info
	.long		.Luint8_t - .Lssinfo

	.section	.debug_abbrev
	.uleb128	DW_AT_external
	.uleb128	DW_FORM_flag
	.section	.debug_info
	.byte		1

	.section	.debug_abbrev
	.uleb128	DW_AT_location
	.uleb128	DW_FORM_block1
	.section	.debug_info
	.byte		5	; length of block
	.byte		DW_OP_addr
	.long		0x800000 + 0x0640 + 0x13

	.section	.debug_abbrev
	.uleb128	0
	.uleb128	0

;- - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
	;; DIE #223: variable PORTC_PIN4CTRL
	.section	.debug_info
	.uleb128	223	; ref to abbrev 223
	.section	.debug_abbrev
	.uleb128	223
	.uleb128	DW_TAG_variable
	.byte		DW_CHILDREN_no

	.uleb128	DW_AT_name
	.uleb128	DW_FORM_strp
	.section	.debug_str
.Lname223:
	.string		"PORTC_PIN4CTRL"
	.section	.debug_info
	.long		.Lname223

	.section	.debug_abbrev
	.uleb128	DW_AT_decl_file
	.uleb128	DW_FORM_data1
	.section	.debug_info
	.byte		0	; no source file information

	.section	.debug_abbrev
	.uleb128	DW_AT_decl_line
	.uleb128	DW_FORM_data1
	.section	.debug_info
	.byte		0	; no source line information

	.section	.debug_abbrev
	.uleb128	DW_AT_type
	.uleb128	DW_FORM_ref4
	.section	.debug_info
	.long		.Luint8_t - .Lssinfo

	.section	.debug_abbrev
	.uleb128	DW_AT_external
	.uleb128	DW_FORM_flag
	.section	.debug_info
	.byte		1

	.section	.debug_abbrev
	.uleb128	DW_AT_location
	.uleb128	DW_FORM_block1
	.section	.debug_info
	.byte		5	; length of block
	.byte		DW_OP_addr
	.long		0x800000 + 0x0640 + 0x14

	.section	.debug_abbrev
	.uleb128	0
	.uleb128	0

;- - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
	;; DIE #224: variable PORTC_PIN5CTRL
	.section	.debug_info
	.uleb128	224	; ref to abbrev 224
	.section	.debug_abbrev
	.uleb128	224
	.uleb128	DW_TAG_variable
	.byte		DW_CHILDREN_no

	.uleb128	DW_AT_name
	.uleb128	DW_FORM_strp
	.section	.debug_str
.Lname224:
	.string		"PORTC_PIN5CTRL"
	.section	.debug_info
	.long		.Lname224

	.section	.debug_abbrev
	.uleb128	DW_AT_decl_file
	.uleb128	DW_FORM_data1
	.section	.debug_info
	.byte		0	; no source file information

	.section	.debug_abbrev
	.uleb128	DW_AT_decl_line
	.uleb128	DW_FORM_data1
	.section	.debug_info
	.byte		0	; no source line information

	.section	.debug_abbrev
	.uleb128	DW_AT_type
	.uleb128	DW_FORM_ref4
	.section	.debug_info
	.long		.Luint8_t - .Lssinfo

	.section	.debug_abbrev
	.uleb128	DW_AT_external
	.uleb128	DW_FORM_flag
	.section	.debug_info
	.byte		1

	.section	.debug_abbrev
	.uleb128	DW_AT_location
	.uleb128	DW_FORM_block1
	.section	.debug_info
	.byte		5	; length of block
	.byte		DW_OP_addr
	.long		0x800000 + 0x0640 + 0x15

	.section	.debug_abbrev
	.uleb128	0
	.uleb128	0

;- - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
	;; DIE #225: variable PORTC_PIN6CTRL
	.section	.debug_info
	.uleb128	225	; ref to abbrev 225
	.section	.debug_abbrev
	.uleb128	225
	.uleb128	DW_TAG_variable
	.byte		DW_CHILDREN_no

	.uleb128	DW_AT_name
	.uleb128	DW_FORM_strp
	.section	.debug_str
.Lname225:
	.string		"PORTC_PIN6CTRL"
	.section	.debug_info
	.long		.Lname225

	.section	.debug_abbrev
	.uleb128	DW_AT_decl_file
	.uleb128	DW_FORM_data1
	.section	.debug_info
	.byte		0	; no source file information

	.section	.debug_abbrev
	.uleb128	DW_AT_decl_line
	.uleb128	DW_FORM_data1
	.section	.debug_info
	.byte		0	; no source line information

	.section	.debug_abbrev
	.uleb128	DW_AT_type
	.uleb128	DW_FORM_ref4
	.section	.debug_info
	.long		.Luint8_t - .Lssinfo

	.section	.debug_abbrev
	.uleb128	DW_AT_external
	.uleb128	DW_FORM_flag
	.section	.debug_info
	.byte		1

	.section	.debug_abbrev
	.uleb128	DW_AT_location
	.uleb128	DW_FORM_block1
	.section	.debug_info
	.byte		5	; length of block
	.byte		DW_OP_addr
	.long		0x800000 + 0x0640 + 0x16

	.section	.debug_abbrev
	.uleb128	0
	.uleb128	0

;- - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
	;; DIE #226: variable PORTC_PIN7CTRL
	.section	.debug_info
	.uleb128	226	; ref to abbrev 226
	.section	.debug_abbrev
	.uleb128	226
	.uleb128	DW_TAG_variable
	.byte		DW_CHILDREN_no

	.uleb128	DW_AT_name
	.uleb128	DW_FORM_strp
	.section	.debug_str
.Lname226:
	.string		"PORTC_PIN7CTRL"
	.section	.debug_info
	.long		.Lname226

	.section	.debug_abbrev
	.uleb128	DW_AT_decl_file
	.uleb128	DW_FORM_data1
	.section	.debug_info
	.byte		0	; no source file information

	.section	.debug_abbrev
	.uleb128	DW_AT_decl_line
	.uleb128	DW_FORM_data1
	.section	.debug_info
	.byte		0	; no source line information

	.section	.debug_abbrev
	.uleb128	DW_AT_type
	.uleb128	DW_FORM_ref4
	.section	.debug_info
	.long		.Luint8_t - .Lssinfo

	.section	.debug_abbrev
	.uleb128	DW_AT_external
	.uleb128	DW_FORM_flag
	.section	.debug_info
	.byte		1

	.section	.debug_abbrev
	.uleb128	DW_AT_location
	.uleb128	DW_FORM_block1
	.section	.debug_info
	.byte		5	; length of block
	.byte		DW_OP_addr
	.long		0x800000 + 0x0640 + 0x17

	.section	.debug_abbrev
	.uleb128	0
	.uleb128	0

;- - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
	;; DIE #227: variable PORTD_DIR
	.section	.debug_info
	.uleb128	227	; ref to abbrev 227
	.section	.debug_abbrev
	.uleb128	227
	.uleb128	DW_TAG_variable
	.byte		DW_CHILDREN_no

	.uleb128	DW_AT_name
	.uleb128	DW_FORM_strp
	.section	.debug_str
.Lname227:
	.string		"PORTD_DIR"
	.section	.debug_info
	.long		.Lname227

	.section	.debug_abbrev
	.uleb128	DW_AT_decl_file
	.uleb128	DW_FORM_data1
	.section	.debug_info
	.byte		0	; no source file information

	.section	.debug_abbrev
	.uleb128	DW_AT_decl_line
	.uleb128	DW_FORM_data1
	.section	.debug_info
	.byte		0	; no source line information

	.section	.debug_abbrev
	.uleb128	DW_AT_type
	.uleb128	DW_FORM_ref4
	.section	.debug_info
	.long		.Luint8_t - .Lssinfo

	.section	.debug_abbrev
	.uleb128	DW_AT_external
	.uleb128	DW_FORM_flag
	.section	.debug_info
	.byte		1

	.section	.debug_abbrev
	.uleb128	DW_AT_location
	.uleb128	DW_FORM_block1
	.section	.debug_info
	.byte		5	; length of block
	.byte		DW_OP_addr
	.long		0x800000 + 0x0660 + 0x00

	.section	.debug_abbrev
	.uleb128	0
	.uleb128	0

;- - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
	;; DIE #228: variable PORTD_DIRSET
	.section	.debug_info
	.uleb128	228	; ref to abbrev 228
	.section	.debug_abbrev
	.uleb128	228
	.uleb128	DW_TAG_variable
	.byte		DW_CHILDREN_no

	.uleb128	DW_AT_name
	.uleb128	DW_FORM_strp
	.section	.debug_str
.Lname228:
	.string		"PORTD_DIRSET"
	.section	.debug_info
	.long		.Lname228

	.section	.debug_abbrev
	.uleb128	DW_AT_decl_file
	.uleb128	DW_FORM_data1
	.section	.debug_info
	.byte		0	; no source file information

	.section	.debug_abbrev
	.uleb128	DW_AT_decl_line
	.uleb128	DW_FORM_data1
	.section	.debug_info
	.byte		0	; no source line information

	.section	.debug_abbrev
	.uleb128	DW_AT_type
	.uleb128	DW_FORM_ref4
	.section	.debug_info
	.long		.Luint8_t - .Lssinfo

	.section	.debug_abbrev
	.uleb128	DW_AT_external
	.uleb128	DW_FORM_flag
	.section	.debug_info
	.byte		1

	.section	.debug_abbrev
	.uleb128	DW_AT_location
	.uleb128	DW_FORM_block1
	.section	.debug_info
	.byte		5	; length of block
	.byte		DW_OP_addr
	.long		0x800000 + 0x0660 + 0x01

	.section	.debug_abbrev
	.uleb128	0
	.uleb128	0

;- - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
	;; DIE #229: variable PORTD_DIRCLR
	.section	.debug_info
	.uleb128	229	; ref to abbrev 229
	.section	.debug_abbrev
	.uleb128	229
	.uleb128	DW_TAG_variable
	.byte		DW_CHILDREN_no

	.uleb128	DW_AT_name
	.uleb128	DW_FORM_strp
	.section	.debug_str
.Lname229:
	.string		"PORTD_DIRCLR"
	.section	.debug_info
	.long		.Lname229

	.section	.debug_abbrev
	.uleb128	DW_AT_decl_file
	.uleb128	DW_FORM_data1
	.section	.debug_info
	.byte		0	; no source file information

	.section	.debug_abbrev
	.uleb128	DW_AT_decl_line
	.uleb128	DW_FORM_data1
	.section	.debug_info
	.byte		0	; no source line information

	.section	.debug_abbrev
	.uleb128	DW_AT_type
	.uleb128	DW_FORM_ref4
	.section	.debug_info
	.long		.Luint8_t - .Lssinfo

	.section	.debug_abbrev
	.uleb128	DW_AT_external
	.uleb128	DW_FORM_flag
	.section	.debug_info
	.byte		1

	.section	.debug_abbrev
	.uleb128	DW_AT_location
	.uleb128	DW_FORM_block1
	.section	.debug_info
	.byte		5	; length of block
	.byte		DW_OP_addr
	.long		0x800000 + 0x0660 + 0x02

	.section	.debug_abbrev
	.uleb128	0
	.uleb128	0

;- - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
	;; DIE #230: variable PORTD_DIRTGL
	.section	.debug_info
	.uleb128	230	; ref to abbrev 230
	.section	.debug_abbrev
	.uleb128	230
	.uleb128	DW_TAG_variable
	.byte		DW_CHILDREN_no

	.uleb128	DW_AT_name
	.uleb128	DW_FORM_strp
	.section	.debug_str
.Lname230:
	.string		"PORTD_DIRTGL"
	.section	.debug_info
	.long		.Lname230

	.section	.debug_abbrev
	.uleb128	DW_AT_decl_file
	.uleb128	DW_FORM_data1
	.section	.debug_info
	.byte		0	; no source file information

	.section	.debug_abbrev
	.uleb128	DW_AT_decl_line
	.uleb128	DW_FORM_data1
	.section	.debug_info
	.byte		0	; no source line information

	.section	.debug_abbrev
	.uleb128	DW_AT_type
	.uleb128	DW_FORM_ref4
	.section	.debug_info
	.long		.Luint8_t - .Lssinfo

	.section	.debug_abbrev
	.uleb128	DW_AT_external
	.uleb128	DW_FORM_flag
	.section	.debug_info
	.byte		1

	.section	.debug_abbrev
	.uleb128	DW_AT_location
	.uleb128	DW_FORM_block1
	.section	.debug_info
	.byte		5	; length of block
	.byte		DW_OP_addr
	.long		0x800000 + 0x0660 + 0x03

	.section	.debug_abbrev
	.uleb128	0
	.uleb128	0

;- - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
	;; DIE #231: variable PORTD_OUT
	.section	.debug_info
	.uleb128	231	; ref to abbrev 231
	.section	.debug_abbrev
	.uleb128	231
	.uleb128	DW_TAG_variable
	.byte		DW_CHILDREN_no

	.uleb128	DW_AT_name
	.uleb128	DW_FORM_strp
	.section	.debug_str
.Lname231:
	.string		"PORTD_OUT"
	.section	.debug_info
	.long		.Lname231

	.section	.debug_abbrev
	.uleb128	DW_AT_decl_file
	.uleb128	DW_FORM_data1
	.section	.debug_info
	.byte		0	; no source file information

	.section	.debug_abbrev
	.uleb128	DW_AT_decl_line
	.uleb128	DW_FORM_data1
	.section	.debug_info
	.byte		0	; no source line information

	.section	.debug_abbrev
	.uleb128	DW_AT_type
	.uleb128	DW_FORM_ref4
	.section	.debug_info
	.long		.Luint8_t - .Lssinfo

	.section	.debug_abbrev
	.uleb128	DW_AT_external
	.uleb128	DW_FORM_flag
	.section	.debug_info
	.byte		1

	.section	.debug_abbrev
	.uleb128	DW_AT_location
	.uleb128	DW_FORM_block1
	.section	.debug_info
	.byte		5	; length of block
	.byte		DW_OP_addr
	.long		0x800000 + 0x0660 + 0x04

	.section	.debug_abbrev
	.uleb128	0
	.uleb128	0

;- - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
	;; DIE #232: variable PORTD_OUTSET
	.section	.debug_info
	.uleb128	232	; ref to abbrev 232
	.section	.debug_abbrev
	.uleb128	232
	.uleb128	DW_TAG_variable
	.byte		DW_CHILDREN_no

	.uleb128	DW_AT_name
	.uleb128	DW_FORM_strp
	.section	.debug_str
.Lname232:
	.string		"PORTD_OUTSET"
	.section	.debug_info
	.long		.Lname232

	.section	.debug_abbrev
	.uleb128	DW_AT_decl_file
	.uleb128	DW_FORM_data1
	.section	.debug_info
	.byte		0	; no source file information

	.section	.debug_abbrev
	.uleb128	DW_AT_decl_line
	.uleb128	DW_FORM_data1
	.section	.debug_info
	.byte		0	; no source line information

	.section	.debug_abbrev
	.uleb128	DW_AT_type
	.uleb128	DW_FORM_ref4
	.section	.debug_info
	.long		.Luint8_t - .Lssinfo

	.section	.debug_abbrev
	.uleb128	DW_AT_external
	.uleb128	DW_FORM_flag
	.section	.debug_info
	.byte		1

	.section	.debug_abbrev
	.uleb128	DW_AT_location
	.uleb128	DW_FORM_block1
	.section	.debug_info
	.byte		5	; length of block
	.byte		DW_OP_addr
	.long		0x800000 + 0x0660 + 0x05

	.section	.debug_abbrev
	.uleb128	0
	.uleb128	0

;- - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
	;; DIE #233: variable PORTD_OUTCLR
	.section	.debug_info
	.uleb128	233	; ref to abbrev 233
	.section	.debug_abbrev
	.uleb128	233
	.uleb128	DW_TAG_variable
	.byte		DW_CHILDREN_no

	.uleb128	DW_AT_name
	.uleb128	DW_FORM_strp
	.section	.debug_str
.Lname233:
	.string		"PORTD_OUTCLR"
	.section	.debug_info
	.long		.Lname233

	.section	.debug_abbrev
	.uleb128	DW_AT_decl_file
	.uleb128	DW_FORM_data1
	.section	.debug_info
	.byte		0	; no source file information

	.section	.debug_abbrev
	.uleb128	DW_AT_decl_line
	.uleb128	DW_FORM_data1
	.section	.debug_info
	.byte		0	; no source line information

	.section	.debug_abbrev
	.uleb128	DW_AT_type
	.uleb128	DW_FORM_ref4
	.section	.debug_info
	.long		.Luint8_t - .Lssinfo

	.section	.debug_abbrev
	.uleb128	DW_AT_external
	.uleb128	DW_FORM_flag
	.section	.debug_info
	.byte		1

	.section	.debug_abbrev
	.uleb128	DW_AT_location
	.uleb128	DW_FORM_block1
	.section	.debug_info
	.byte		5	; length of block
	.byte		DW_OP_addr
	.long		0x800000 + 0x0660 + 0x06

	.section	.debug_abbrev
	.uleb128	0
	.uleb128	0

;- - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
	;; DIE #234: variable PORTD_OUTTGL
	.section	.debug_info
	.uleb128	234	; ref to abbrev 234
	.section	.debug_abbrev
	.uleb128	234
	.uleb128	DW_TAG_variable
	.byte		DW_CHILDREN_no

	.uleb128	DW_AT_name
	.uleb128	DW_FORM_strp
	.section	.debug_str
.Lname234:
	.string		"PORTD_OUTTGL"
	.section	.debug_info
	.long		.Lname234

	.section	.debug_abbrev
	.uleb128	DW_AT_decl_file
	.uleb128	DW_FORM_data1
	.section	.debug_info
	.byte		0	; no source file information

	.section	.debug_abbrev
	.uleb128	DW_AT_decl_line
	.uleb128	DW_FORM_data1
	.section	.debug_info
	.byte		0	; no source line information

	.section	.debug_abbrev
	.uleb128	DW_AT_type
	.uleb128	DW_FORM_ref4
	.section	.debug_info
	.long		.Luint8_t - .Lssinfo

	.section	.debug_abbrev
	.uleb128	DW_AT_external
	.uleb128	DW_FORM_flag
	.section	.debug_info
	.byte		1

	.section	.debug_abbrev
	.uleb128	DW_AT_location
	.uleb128	DW_FORM_block1
	.section	.debug_info
	.byte		5	; length of block
	.byte		DW_OP_addr
	.long		0x800000 + 0x0660 + 0x07

	.section	.debug_abbrev
	.uleb128	0
	.uleb128	0

;- - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
	;; DIE #235: variable PORTD_IN
	.section	.debug_info
	.uleb128	235	; ref to abbrev 235
	.section	.debug_abbrev
	.uleb128	235
	.uleb128	DW_TAG_variable
	.byte		DW_CHILDREN_no

	.uleb128	DW_AT_name
	.uleb128	DW_FORM_strp
	.section	.debug_str
.Lname235:
	.string		"PORTD_IN"
	.section	.debug_info
	.long		.Lname235

	.section	.debug_abbrev
	.uleb128	DW_AT_decl_file
	.uleb128	DW_FORM_data1
	.section	.debug_info
	.byte		0	; no source file information

	.section	.debug_abbrev
	.uleb128	DW_AT_decl_line
	.uleb128	DW_FORM_data1
	.section	.debug_info
	.byte		0	; no source line information

	.section	.debug_abbrev
	.uleb128	DW_AT_type
	.uleb128	DW_FORM_ref4
	.section	.debug_info
	.long		.Luint8_t - .Lssinfo

	.section	.debug_abbrev
	.uleb128	DW_AT_external
	.uleb128	DW_FORM_flag
	.section	.debug_info
	.byte		1

	.section	.debug_abbrev
	.uleb128	DW_AT_location
	.uleb128	DW_FORM_block1
	.section	.debug_info
	.byte		5	; length of block
	.byte		DW_OP_addr
	.long		0x800000 + 0x0660 + 0x08

	.section	.debug_abbrev
	.uleb128	0
	.uleb128	0

;- - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
	;; DIE #236: variable PORTD_INTCTRL
	.section	.debug_info
	.uleb128	236	; ref to abbrev 236
	.section	.debug_abbrev
	.uleb128	236
	.uleb128	DW_TAG_variable
	.byte		DW_CHILDREN_no

	.uleb128	DW_AT_name
	.uleb128	DW_FORM_strp
	.section	.debug_str
.Lname236:
	.string		"PORTD_INTCTRL"
	.section	.debug_info
	.long		.Lname236

	.section	.debug_abbrev
	.uleb128	DW_AT_decl_file
	.uleb128	DW_FORM_data1
	.section	.debug_info
	.byte		0	; no source file information

	.section	.debug_abbrev
	.uleb128	DW_AT_decl_line
	.uleb128	DW_FORM_data1
	.section	.debug_info
	.byte		0	; no source line information

	.section	.debug_abbrev
	.uleb128	DW_AT_type
	.uleb128	DW_FORM_ref4
	.section	.debug_info
	.long		.Luint8_t - .Lssinfo

	.section	.debug_abbrev
	.uleb128	DW_AT_external
	.uleb128	DW_FORM_flag
	.section	.debug_info
	.byte		1

	.section	.debug_abbrev
	.uleb128	DW_AT_location
	.uleb128	DW_FORM_block1
	.section	.debug_info
	.byte		5	; length of block
	.byte		DW_OP_addr
	.long		0x800000 + 0x0660 + 0x09

	.section	.debug_abbrev
	.uleb128	0
	.uleb128	0

;- - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
	;; DIE #237: variable PORTD_INT0MASK
	.section	.debug_info
	.uleb128	237	; ref to abbrev 237
	.section	.debug_abbrev
	.uleb128	237
	.uleb128	DW_TAG_variable
	.byte		DW_CHILDREN_no

	.uleb128	DW_AT_name
	.uleb128	DW_FORM_strp
	.section	.debug_str
.Lname237:
	.string		"PORTD_INT0MASK"
	.section	.debug_info
	.long		.Lname237

	.section	.debug_abbrev
	.uleb128	DW_AT_decl_file
	.uleb128	DW_FORM_data1
	.section	.debug_info
	.byte		0	; no source file information

	.section	.debug_abbrev
	.uleb128	DW_AT_decl_line
	.uleb128	DW_FORM_data1
	.section	.debug_info
	.byte		0	; no source line information

	.section	.debug_abbrev
	.uleb128	DW_AT_type
	.uleb128	DW_FORM_ref4
	.section	.debug_info
	.long		.Luint8_t - .Lssinfo

	.section	.debug_abbrev
	.uleb128	DW_AT_external
	.uleb128	DW_FORM_flag
	.section	.debug_info
	.byte		1

	.section	.debug_abbrev
	.uleb128	DW_AT_location
	.uleb128	DW_FORM_block1
	.section	.debug_info
	.byte		5	; length of block
	.byte		DW_OP_addr
	.long		0x800000 + 0x0660 + 0x0A

	.section	.debug_abbrev
	.uleb128	0
	.uleb128	0

;- - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
	;; DIE #238: variable PORTD_INT1MASK
	.section	.debug_info
	.uleb128	238	; ref to abbrev 238
	.section	.debug_abbrev
	.uleb128	238
	.uleb128	DW_TAG_variable
	.byte		DW_CHILDREN_no

	.uleb128	DW_AT_name
	.uleb128	DW_FORM_strp
	.section	.debug_str
.Lname238:
	.string		"PORTD_INT1MASK"
	.section	.debug_info
	.long		.Lname238

	.section	.debug_abbrev
	.uleb128	DW_AT_decl_file
	.uleb128	DW_FORM_data1
	.section	.debug_info
	.byte		0	; no source file information

	.section	.debug_abbrev
	.uleb128	DW_AT_decl_line
	.uleb128	DW_FORM_data1
	.section	.debug_info
	.byte		0	; no source line information

	.section	.debug_abbrev
	.uleb128	DW_AT_type
	.uleb128	DW_FORM_ref4
	.section	.debug_info
	.long		.Luint8_t - .Lssinfo

	.section	.debug_abbrev
	.uleb128	DW_AT_external
	.uleb128	DW_FORM_flag
	.section	.debug_info
	.byte		1

	.section	.debug_abbrev
	.uleb128	DW_AT_location
	.uleb128	DW_FORM_block1
	.section	.debug_info
	.byte		5	; length of block
	.byte		DW_OP_addr
	.long		0x800000 + 0x0660 + 0x0B

	.section	.debug_abbrev
	.uleb128	0
	.uleb128	0

;- - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
	;; DIE #239: variable PORTD_INTFLAGS
	.section	.debug_info
	.uleb128	239	; ref to abbrev 239
	.section	.debug_abbrev
	.uleb128	239
	.uleb128	DW_TAG_variable
	.byte		DW_CHILDREN_no

	.uleb128	DW_AT_name
	.uleb128	DW_FORM_strp
	.section	.debug_str
.Lname239:
	.string		"PORTD_INTFLAGS"
	.section	.debug_info
	.long		.Lname239

	.section	.debug_abbrev
	.uleb128	DW_AT_decl_file
	.uleb128	DW_FORM_data1
	.section	.debug_info
	.byte		0	; no source file information

	.section	.debug_abbrev
	.uleb128	DW_AT_decl_line
	.uleb128	DW_FORM_data1
	.section	.debug_info
	.byte		0	; no source line information

	.section	.debug_abbrev
	.uleb128	DW_AT_type
	.uleb128	DW_FORM_ref4
	.section	.debug_info
	.long		.Luint8_t - .Lssinfo

	.section	.debug_abbrev
	.uleb128	DW_AT_external
	.uleb128	DW_FORM_flag
	.section	.debug_info
	.byte		1

	.section	.debug_abbrev
	.uleb128	DW_AT_location
	.uleb128	DW_FORM_block1
	.section	.debug_info
	.byte		5	; length of block
	.byte		DW_OP_addr
	.long		0x800000 + 0x0660 + 0x0C

	.section	.debug_abbrev
	.uleb128	0
	.uleb128	0

;- - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
	;; DIE #240: variable PORTD_REMAP
	.section	.debug_info
	.uleb128	240	; ref to abbrev 240
	.section	.debug_abbrev
	.uleb128	240
	.uleb128	DW_TAG_variable
	.byte		DW_CHILDREN_no

	.uleb128	DW_AT_name
	.uleb128	DW_FORM_strp
	.section	.debug_str
.Lname240:
	.string		"PORTD_REMAP"
	.section	.debug_info
	.long		.Lname240

	.section	.debug_abbrev
	.uleb128	DW_AT_decl_file
	.uleb128	DW_FORM_data1
	.section	.debug_info
	.byte		0	; no source file information

	.section	.debug_abbrev
	.uleb128	DW_AT_decl_line
	.uleb128	DW_FORM_data1
	.section	.debug_info
	.byte		0	; no source line information

	.section	.debug_abbrev
	.uleb128	DW_AT_type
	.uleb128	DW_FORM_ref4
	.section	.debug_info
	.long		.Luint8_t - .Lssinfo

	.section	.debug_abbrev
	.uleb128	DW_AT_external
	.uleb128	DW_FORM_flag
	.section	.debug_info
	.byte		1

	.section	.debug_abbrev
	.uleb128	DW_AT_location
	.uleb128	DW_FORM_block1
	.section	.debug_info
	.byte		5	; length of block
	.byte		DW_OP_addr
	.long		0x800000 + 0x0660 + 0x0E

	.section	.debug_abbrev
	.uleb128	0
	.uleb128	0

;- - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
	;; DIE #241: variable PORTD_PIN0CTRL
	.section	.debug_info
	.uleb128	241	; ref to abbrev 241
	.section	.debug_abbrev
	.uleb128	241
	.uleb128	DW_TAG_variable
	.byte		DW_CHILDREN_no

	.uleb128	DW_AT_name
	.uleb128	DW_FORM_strp
	.section	.debug_str
.Lname241:
	.string		"PORTD_PIN0CTRL"
	.section	.debug_info
	.long		.Lname241

	.section	.debug_abbrev
	.uleb128	DW_AT_decl_file
	.uleb128	DW_FORM_data1
	.section	.debug_info
	.byte		0	; no source file information

	.section	.debug_abbrev
	.uleb128	DW_AT_decl_line
	.uleb128	DW_FORM_data1
	.section	.debug_info
	.byte		0	; no source line information

	.section	.debug_abbrev
	.uleb128	DW_AT_type
	.uleb128	DW_FORM_ref4
	.section	.debug_info
	.long		.Luint8_t - .Lssinfo

	.section	.debug_abbrev
	.uleb128	DW_AT_external
	.uleb128	DW_FORM_flag
	.section	.debug_info
	.byte		1

	.section	.debug_abbrev
	.uleb128	DW_AT_location
	.uleb128	DW_FORM_block1
	.section	.debug_info
	.byte		5	; length of block
	.byte		DW_OP_addr
	.long		0x800000 + 0x0660 + 0x10

	.section	.debug_abbrev
	.uleb128	0
	.uleb128	0

;- - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
	;; DIE #242: variable PORTD_PIN1CTRL
	.section	.debug_info
	.uleb128	242	; ref to abbrev 242
	.section	.debug_abbrev
	.uleb128	242
	.uleb128	DW_TAG_variable
	.byte		DW_CHILDREN_no

	.uleb128	DW_AT_name
	.uleb128	DW_FORM_strp
	.section	.debug_str
.Lname242:
	.string		"PORTD_PIN1CTRL"
	.section	.debug_info
	.long		.Lname242

	.section	.debug_abbrev
	.uleb128	DW_AT_decl_file
	.uleb128	DW_FORM_data1
	.section	.debug_info
	.byte		0	; no source file information

	.section	.debug_abbrev
	.uleb128	DW_AT_decl_line
	.uleb128	DW_FORM_data1
	.section	.debug_info
	.byte		0	; no source line information

	.section	.debug_abbrev
	.uleb128	DW_AT_type
	.uleb128	DW_FORM_ref4
	.section	.debug_info
	.long		.Luint8_t - .Lssinfo

	.section	.debug_abbrev
	.uleb128	DW_AT_external
	.uleb128	DW_FORM_flag
	.section	.debug_info
	.byte		1

	.section	.debug_abbrev
	.uleb128	DW_AT_location
	.uleb128	DW_FORM_block1
	.section	.debug_info
	.byte		5	; length of block
	.byte		DW_OP_addr
	.long		0x800000 + 0x0660 + 0x11

	.section	.debug_abbrev
	.uleb128	0
	.uleb128	0

;- - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
	;; DIE #243: variable PORTD_PIN2CTRL
	.section	.debug_info
	.uleb128	243	; ref to abbrev 243
	.section	.debug_abbrev
	.uleb128	243
	.uleb128	DW_TAG_variable
	.byte		DW_CHILDREN_no

	.uleb128	DW_AT_name
	.uleb128	DW_FORM_strp
	.section	.debug_str
.Lname243:
	.string		"PORTD_PIN2CTRL"
	.section	.debug_info
	.long		.Lname243

	.section	.debug_abbrev
	.uleb128	DW_AT_decl_file
	.uleb128	DW_FORM_data1
	.section	.debug_info
	.byte		0	; no source file information

	.section	.debug_abbrev
	.uleb128	DW_AT_decl_line
	.uleb128	DW_FORM_data1
	.section	.debug_info
	.byte		0	; no source line information

	.section	.debug_abbrev
	.uleb128	DW_AT_type
	.uleb128	DW_FORM_ref4
	.section	.debug_info
	.long		.Luint8_t - .Lssinfo

	.section	.debug_abbrev
	.uleb128	DW_AT_external
	.uleb128	DW_FORM_flag
	.section	.debug_info
	.byte		1

	.section	.debug_abbrev
	.uleb128	DW_AT_location
	.uleb128	DW_FORM_block1
	.section	.debug_info
	.byte		5	; length of block
	.byte		DW_OP_addr
	.long		0x800000 + 0x0660 + 0x12

	.section	.debug_abbrev
	.uleb128	0
	.uleb128	0

;- - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
	;; DIE #244: variable PORTD_PIN3CTRL
	.section	.debug_info
	.uleb128	244	; ref to abbrev 244
	.section	.debug_abbrev
	.uleb128	244
	.uleb128	DW_TAG_variable
	.byte		DW_CHILDREN_no

	.uleb128	DW_AT_name
	.uleb128	DW_FORM_strp
	.section	.debug_str
.Lname244:
	.string		"PORTD_PIN3CTRL"
	.section	.debug_info
	.long		.Lname244

	.section	.debug_abbrev
	.uleb128	DW_AT_decl_file
	.uleb128	DW_FORM_data1
	.section	.debug_info
	.byte		0	; no source file information

	.section	.debug_abbrev
	.uleb128	DW_AT_decl_line
	.uleb128	DW_FORM_data1
	.section	.debug_info
	.byte		0	; no source line information

	.section	.debug_abbrev
	.uleb128	DW_AT_type
	.uleb128	DW_FORM_ref4
	.section	.debug_info
	.long		.Luint8_t - .Lssinfo

	.section	.debug_abbrev
	.uleb128	DW_AT_external
	.uleb128	DW_FORM_flag
	.section	.debug_info
	.byte		1

	.section	.debug_abbrev
	.uleb128	DW_AT_location
	.uleb128	DW_FORM_block1
	.section	.debug_info
	.byte		5	; length of block
	.byte		DW_OP_addr
	.long		0x800000 + 0x0660 + 0x13

	.section	.debug_abbrev
	.uleb128	0
	.uleb128	0

;- - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
	;; DIE #245: variable PORTD_PIN4CTRL
	.section	.debug_info
	.uleb128	245	; ref to abbrev 245
	.section	.debug_abbrev
	.uleb128	245
	.uleb128	DW_TAG_variable
	.byte		DW_CHILDREN_no

	.uleb128	DW_AT_name
	.uleb128	DW_FORM_strp
	.section	.debug_str
.Lname245:
	.string		"PORTD_PIN4CTRL"
	.section	.debug_info
	.long		.Lname245

	.section	.debug_abbrev
	.uleb128	DW_AT_decl_file
	.uleb128	DW_FORM_data1
	.section	.debug_info
	.byte		0	; no source file information

	.section	.debug_abbrev
	.uleb128	DW_AT_decl_line
	.uleb128	DW_FORM_data1
	.section	.debug_info
	.byte		0	; no source line information

	.section	.debug_abbrev
	.uleb128	DW_AT_type
	.uleb128	DW_FORM_ref4
	.section	.debug_info
	.long		.Luint8_t - .Lssinfo

	.section	.debug_abbrev
	.uleb128	DW_AT_external
	.uleb128	DW_FORM_flag
	.section	.debug_info
	.byte		1

	.section	.debug_abbrev
	.uleb128	DW_AT_location
	.uleb128	DW_FORM_block1
	.section	.debug_info
	.byte		5	; length of block
	.byte		DW_OP_addr
	.long		0x800000 + 0x0660 + 0x14

	.section	.debug_abbrev
	.uleb128	0
	.uleb128	0

;- - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
	;; DIE #246: variable PORTD_PIN5CTRL
	.section	.debug_info
	.uleb128	246	; ref to abbrev 246
	.section	.debug_abbrev
	.uleb128	246
	.uleb128	DW_TAG_variable
	.byte		DW_CHILDREN_no

	.uleb128	DW_AT_name
	.uleb128	DW_FORM_strp
	.section	.debug_str
.Lname246:
	.string		"PORTD_PIN5CTRL"
	.section	.debug_info
	.long		.Lname246

	.section	.debug_abbrev
	.uleb128	DW_AT_decl_file
	.uleb128	DW_FORM_data1
	.section	.debug_info
	.byte		0	; no source file information

	.section	.debug_abbrev
	.uleb128	DW_AT_decl_line
	.uleb128	DW_FORM_data1
	.section	.debug_info
	.byte		0	; no source line information

	.section	.debug_abbrev
	.uleb128	DW_AT_type
	.uleb128	DW_FORM_ref4
	.section	.debug_info
	.long		.Luint8_t - .Lssinfo

	.section	.debug_abbrev
	.uleb128	DW_AT_external
	.uleb128	DW_FORM_flag
	.section	.debug_info
	.byte		1

	.section	.debug_abbrev
	.uleb128	DW_AT_location
	.uleb128	DW_FORM_block1
	.section	.debug_info
	.byte		5	; length of block
	.byte		DW_OP_addr
	.long		0x800000 + 0x0660 + 0x15

	.section	.debug_abbrev
	.uleb128	0
	.uleb128	0

;- - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
	;; DIE #247: variable PORTD_PIN6CTRL
	.section	.debug_info
	.uleb128	247	; ref to abbrev 247
	.section	.debug_abbrev
	.uleb128	247
	.uleb128	DW_TAG_variable
	.byte		DW_CHILDREN_no

	.uleb128	DW_AT_name
	.uleb128	DW_FORM_strp
	.section	.debug_str
.Lname247:
	.string		"PORTD_PIN6CTRL"
	.section	.debug_info
	.long		.Lname247

	.section	.debug_abbrev
	.uleb128	DW_AT_decl_file
	.uleb128	DW_FORM_data1
	.section	.debug_info
	.byte		0	; no source file information

	.section	.debug_abbrev
	.uleb128	DW_AT_decl_line
	.uleb128	DW_FORM_data1
	.section	.debug_info
	.byte		0	; no source line information

	.section	.debug_abbrev
	.uleb128	DW_AT_type
	.uleb128	DW_FORM_ref4
	.section	.debug_info
	.long		.Luint8_t - .Lssinfo

	.section	.debug_abbrev
	.uleb128	DW_AT_external
	.uleb128	DW_FORM_flag
	.section	.debug_info
	.byte		1

	.section	.debug_abbrev
	.uleb128	DW_AT_location
	.uleb128	DW_FORM_block1
	.section	.debug_info
	.byte		5	; length of block
	.byte		DW_OP_addr
	.long		0x800000 + 0x0660 + 0x16

	.section	.debug_abbrev
	.uleb128	0
	.uleb128	0

;- - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
	;; DIE #248: variable PORTD_PIN7CTRL
	.section	.debug_info
	.uleb128	248	; ref to abbrev 248
	.section	.debug_abbrev
	.uleb128	248
	.uleb128	DW_TAG_variable
	.byte		DW_CHILDREN_no

	.uleb128	DW_AT_name
	.uleb128	DW_FORM_strp
	.section	.debug_str
.Lname248:
	.string		"PORTD_PIN7CTRL"
	.section	.debug_info
	.long		.Lname248

	.section	.debug_abbrev
	.uleb128	DW_AT_decl_file
	.uleb128	DW_FORM_data1
	.section	.debug_info
	.byte		0	; no source file information

	.section	.debug_abbrev
	.uleb128	DW_AT_decl_line
	.uleb128	DW_FORM_data1
	.section	.debug_info
	.byte		0	; no source line information

	.section	.debug_abbrev
	.uleb128	DW_AT_type
	.uleb128	DW_FORM_ref4
	.section	.debug_info
	.long		.Luint8_t - .Lssinfo

	.section	.debug_abbrev
	.uleb128	DW_AT_external
	.uleb128	DW_FORM_flag
	.section	.debug_info
	.byte		1

	.section	.debug_abbrev
	.uleb128	DW_AT_location
	.uleb128	DW_FORM_block1
	.section	.debug_info
	.byte		5	; length of block
	.byte		DW_OP_addr
	.long		0x800000 + 0x0660 + 0x17

	.section	.debug_abbrev
	.uleb128	0
	.uleb128	0

;- - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
	;; DIE #249: variable PORTE_DIR
	.section	.debug_info
	.uleb128	249	; ref to abbrev 249
	.section	.debug_abbrev
	.uleb128	249
	.uleb128	DW_TAG_variable
	.byte		DW_CHILDREN_no

	.uleb128	DW_AT_name
	.uleb128	DW_FORM_strp
	.section	.debug_str
.Lname249:
	.string		"PORTE_DIR"
	.section	.debug_info
	.long		.Lname249

	.section	.debug_abbrev
	.uleb128	DW_AT_decl_file
	.uleb128	DW_FORM_data1
	.section	.debug_info
	.byte		0	; no source file information

	.section	.debug_abbrev
	.uleb128	DW_AT_decl_line
	.uleb128	DW_FORM_data1
	.section	.debug_info
	.byte		0	; no source line information

	.section	.debug_abbrev
	.uleb128	DW_AT_type
	.uleb128	DW_FORM_ref4
	.section	.debug_info
	.long		.Luint8_t - .Lssinfo

	.section	.debug_abbrev
	.uleb128	DW_AT_external
	.uleb128	DW_FORM_flag
	.section	.debug_info
	.byte		1

	.section	.debug_abbrev
	.uleb128	DW_AT_location
	.uleb128	DW_FORM_block1
	.section	.debug_info
	.byte		5	; length of block
	.byte		DW_OP_addr
	.long		0x800000 + 0x0680 + 0x00

	.section	.debug_abbrev
	.uleb128	0
	.uleb128	0

;- - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
	;; DIE #250: variable PORTE_DIRSET
	.section	.debug_info
	.uleb128	250	; ref to abbrev 250
	.section	.debug_abbrev
	.uleb128	250
	.uleb128	DW_TAG_variable
	.byte		DW_CHILDREN_no

	.uleb128	DW_AT_name
	.uleb128	DW_FORM_strp
	.section	.debug_str
.Lname250:
	.string		"PORTE_DIRSET"
	.section	.debug_info
	.long		.Lname250

	.section	.debug_abbrev
	.uleb128	DW_AT_decl_file
	.uleb128	DW_FORM_data1
	.section	.debug_info
	.byte		0	; no source file information

	.section	.debug_abbrev
	.uleb128	DW_AT_decl_line
	.uleb128	DW_FORM_data1
	.section	.debug_info
	.byte		0	; no source line information

	.section	.debug_abbrev
	.uleb128	DW_AT_type
	.uleb128	DW_FORM_ref4
	.section	.debug_info
	.long		.Luint8_t - .Lssinfo

	.section	.debug_abbrev
	.uleb128	DW_AT_external
	.uleb128	DW_FORM_flag
	.section	.debug_info
	.byte		1

	.section	.debug_abbrev
	.uleb128	DW_AT_location
	.uleb128	DW_FORM_block1
	.section	.debug_info
	.byte		5	; length of block
	.byte		DW_OP_addr
	.long		0x800000 + 0x0680 + 0x01

	.section	.debug_abbrev
	.uleb128	0
	.uleb128	0

;- - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
	;; DIE #251: variable PORTE_DIRCLR
	.section	.debug_info
	.uleb128	251	; ref to abbrev 251
	.section	.debug_abbrev
	.uleb128	251
	.uleb128	DW_TAG_variable
	.byte		DW_CHILDREN_no

	.uleb128	DW_AT_name
	.uleb128	DW_FORM_strp
	.section	.debug_str
.Lname251:
	.string		"PORTE_DIRCLR"
	.section	.debug_info
	.long		.Lname251

	.section	.debug_abbrev
	.uleb128	DW_AT_decl_file
	.uleb128	DW_FORM_data1
	.section	.debug_info
	.byte		0	; no source file information

	.section	.debug_abbrev
	.uleb128	DW_AT_decl_line
	.uleb128	DW_FORM_data1
	.section	.debug_info
	.byte		0	; no source line information

	.section	.debug_abbrev
	.uleb128	DW_AT_type
	.uleb128	DW_FORM_ref4
	.section	.debug_info
	.long		.Luint8_t - .Lssinfo

	.section	.debug_abbrev
	.uleb128	DW_AT_external
	.uleb128	DW_FORM_flag
	.section	.debug_info
	.byte		1

	.section	.debug_abbrev
	.uleb128	DW_AT_location
	.uleb128	DW_FORM_block1
	.section	.debug_info
	.byte		5	; length of block
	.byte		DW_OP_addr
	.long		0x800000 + 0x0680 + 0x02

	.section	.debug_abbrev
	.uleb128	0
	.uleb128	0

;- - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
	;; DIE #252: variable PORTE_DIRTGL
	.section	.debug_info
	.uleb128	252	; ref to abbrev 252
	.section	.debug_abbrev
	.uleb128	252
	.uleb128	DW_TAG_variable
	.byte		DW_CHILDREN_no

	.uleb128	DW_AT_name
	.uleb128	DW_FORM_strp
	.section	.debug_str
.Lname252:
	.string		"PORTE_DIRTGL"
	.section	.debug_info
	.long		.Lname252

	.section	.debug_abbrev
	.uleb128	DW_AT_decl_file
	.uleb128	DW_FORM_data1
	.section	.debug_info
	.byte		0	; no source file information

	.section	.debug_abbrev
	.uleb128	DW_AT_decl_line
	.uleb128	DW_FORM_data1
	.section	.debug_info
	.byte		0	; no source line information

	.section	.debug_abbrev
	.uleb128	DW_AT_type
	.uleb128	DW_FORM_ref4
	.section	.debug_info
	.long		.Luint8_t - .Lssinfo

	.section	.debug_abbrev
	.uleb128	DW_AT_external
	.uleb128	DW_FORM_flag
	.section	.debug_info
	.byte		1

	.section	.debug_abbrev
	.uleb128	DW_AT_location
	.uleb128	DW_FORM_block1
	.section	.debug_info
	.byte		5	; length of block
	.byte		DW_OP_addr
	.long		0x800000 + 0x0680 + 0x03

	.section	.debug_abbrev
	.uleb128	0
	.uleb128	0

;- - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
	;; DIE #253: variable PORTE_OUT
	.section	.debug_info
	.uleb128	253	; ref to abbrev 253
	.section	.debug_abbrev
	.uleb128	253
	.uleb128	DW_TAG_variable
	.byte		DW_CHILDREN_no

	.uleb128	DW_AT_name
	.uleb128	DW_FORM_strp
	.section	.debug_str
.Lname253:
	.string		"PORTE_OUT"
	.section	.debug_info
	.long		.Lname253

	.section	.debug_abbrev
	.uleb128	DW_AT_decl_file
	.uleb128	DW_FORM_data1
	.section	.debug_info
	.byte		0	; no source file information

	.section	.debug_abbrev
	.uleb128	DW_AT_decl_line
	.uleb128	DW_FORM_data1
	.section	.debug_info
	.byte		0	; no source line information

	.section	.debug_abbrev
	.uleb128	DW_AT_type
	.uleb128	DW_FORM_ref4
	.section	.debug_info
	.long		.Luint8_t - .Lssinfo

	.section	.debug_abbrev
	.uleb128	DW_AT_external
	.uleb128	DW_FORM_flag
	.section	.debug_info
	.byte		1

	.section	.debug_abbrev
	.uleb128	DW_AT_location
	.uleb128	DW_FORM_block1
	.section	.debug_info
	.byte		5	; length of block
	.byte		DW_OP_addr
	.long		0x800000 + 0x0680 + 0x04

	.section	.debug_abbrev
	.uleb128	0
	.uleb128	0

;- - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
	;; DIE #254: variable PORTE_OUTSET
	.section	.debug_info
	.uleb128	254	; ref to abbrev 254
	.section	.debug_abbrev
	.uleb128	254
	.uleb128	DW_TAG_variable
	.byte		DW_CHILDREN_no

	.uleb128	DW_AT_name
	.uleb128	DW_FORM_strp
	.section	.debug_str
.Lname254:
	.string		"PORTE_OUTSET"
	.section	.debug_info
	.long		.Lname254

	.section	.debug_abbrev
	.uleb128	DW_AT_decl_file
	.uleb128	DW_FORM_data1
	.section	.debug_info
	.byte		0	; no source file information

	.section	.debug_abbrev
	.uleb128	DW_AT_decl_line
	.uleb128	DW_FORM_data1
	.section	.debug_info
	.byte		0	; no source line information

	.section	.debug_abbrev
	.uleb128	DW_AT_type
	.uleb128	DW_FORM_ref4
	.section	.debug_info
	.long		.Luint8_t - .Lssinfo

	.section	.debug_abbrev
	.uleb128	DW_AT_external
	.uleb128	DW_FORM_flag
	.section	.debug_info
	.byte		1

	.section	.debug_abbrev
	.uleb128	DW_AT_location
	.uleb128	DW_FORM_block1
	.section	.debug_info
	.byte		5	; length of block
	.byte		DW_OP_addr
	.long		0x800000 + 0x0680 + 0x05

	.section	.debug_abbrev
	.uleb128	0
	.uleb128	0

;- - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
	;; DIE #255: variable PORTE_OUTCLR
	.section	.debug_info
	.uleb128	255	; ref to abbrev 255
	.section	.debug_abbrev
	.uleb128	255
	.uleb128	DW_TAG_variable
	.byte		DW_CHILDREN_no

	.uleb128	DW_AT_name
	.uleb128	DW_FORM_strp
	.section	.debug_str
.Lname255:
	.string		"PORTE_OUTCLR"
	.section	.debug_info
	.long		.Lname255

	.section	.debug_abbrev
	.uleb128	DW_AT_decl_file
	.uleb128	DW_FORM_data1
	.section	.debug_info
	.byte		0	; no source file information

	.section	.debug_abbrev
	.uleb128	DW_AT_decl_line
	.uleb128	DW_FORM_data1
	.section	.debug_info
	.byte		0	; no source line information

	.section	.debug_abbrev
	.uleb128	DW_AT_type
	.uleb128	DW_FORM_ref4
	.section	.debug_info
	.long		.Luint8_t - .Lssinfo

	.section	.debug_abbrev
	.uleb128	DW_AT_external
	.uleb128	DW_FORM_flag
	.section	.debug_info
	.byte		1

	.section	.debug_abbrev
	.uleb128	DW_AT_location
	.uleb128	DW_FORM_block1
	.section	.debug_info
	.byte		5	; length of block
	.byte		DW_OP_addr
	.long		0x800000 + 0x0680 + 0x06

	.section	.debug_abbrev
	.uleb128	0
	.uleb128	0

;- - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
	;; DIE #256: variable PORTE_OUTTGL
	.section	.debug_info
	.uleb128	256	; ref to abbrev 256
	.section	.debug_abbrev
	.uleb128	256
	.uleb128	DW_TAG_variable
	.byte		DW_CHILDREN_no

	.uleb128	DW_AT_name
	.uleb128	DW_FORM_strp
	.section	.debug_str
.Lname256:
	.string		"PORTE_OUTTGL"
	.section	.debug_info
	.long		.Lname256

	.section	.debug_abbrev
	.uleb128	DW_AT_decl_file
	.uleb128	DW_FORM_data1
	.section	.debug_info
	.byte		0	; no source file information

	.section	.debug_abbrev
	.uleb128	DW_AT_decl_line
	.uleb128	DW_FORM_data1
	.section	.debug_info
	.byte		0	; no source line information

	.section	.debug_abbrev
	.uleb128	DW_AT_type
	.uleb128	DW_FORM_ref4
	.section	.debug_info
	.long		.Luint8_t - .Lssinfo

	.section	.debug_abbrev
	.uleb128	DW_AT_external
	.uleb128	DW_FORM_flag
	.section	.debug_info
	.byte		1

	.section	.debug_abbrev
	.uleb128	DW_AT_location
	.uleb128	DW_FORM_block1
	.section	.debug_info
	.byte		5	; length of block
	.byte		DW_OP_addr
	.long		0x800000 + 0x0680 + 0x07

	.section	.debug_abbrev
	.uleb128	0
	.uleb128	0

;- - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
	;; DIE #257: variable PORTE_IN
	.section	.debug_info
	.uleb128	257	; ref to abbrev 257
	.section	.debug_abbrev
	.uleb128	257
	.uleb128	DW_TAG_variable
	.byte		DW_CHILDREN_no

	.uleb128	DW_AT_name
	.uleb128	DW_FORM_strp
	.section	.debug_str
.Lname257:
	.string		"PORTE_IN"
	.section	.debug_info
	.long		.Lname257

	.section	.debug_abbrev
	.uleb128	DW_AT_decl_file
	.uleb128	DW_FORM_data1
	.section	.debug_info
	.byte		0	; no source file information

	.section	.debug_abbrev
	.uleb128	DW_AT_decl_line
	.uleb128	DW_FORM_data1
	.section	.debug_info
	.byte		0	; no source line information

	.section	.debug_abbrev
	.uleb128	DW_AT_type
	.uleb128	DW_FORM_ref4
	.section	.debug_info
	.long		.Luint8_t - .Lssinfo

	.section	.debug_abbrev
	.uleb128	DW_AT_external
	.uleb128	DW_FORM_flag
	.section	.debug_info
	.byte		1

	.section	.debug_abbrev
	.uleb128	DW_AT_location
	.uleb128	DW_FORM_block1
	.section	.debug_info
	.byte		5	; length of block
	.byte		DW_OP_addr
	.long		0x800000 + 0x0680 + 0x08

	.section	.debug_abbrev
	.uleb128	0
	.uleb128	0

;- - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
	;; DIE #258: variable PORTE_INTCTRL
	.section	.debug_info
	.uleb128	258	; ref to abbrev 258
	.section	.debug_abbrev
	.uleb128	258
	.uleb128	DW_TAG_variable
	.byte		DW_CHILDREN_no

	.uleb128	DW_AT_name
	.uleb128	DW_FORM_strp
	.section	.debug_str
.Lname258:
	.string		"PORTE_INTCTRL"
	.section	.debug_info
	.long		.Lname258

	.section	.debug_abbrev
	.uleb128	DW_AT_decl_file
	.uleb128	DW_FORM_data1
	.section	.debug_info
	.byte		0	; no source file information

	.section	.debug_abbrev
	.uleb128	DW_AT_decl_line
	.uleb128	DW_FORM_data1
	.section	.debug_info
	.byte		0	; no source line information

	.section	.debug_abbrev
	.uleb128	DW_AT_type
	.uleb128	DW_FORM_ref4
	.section	.debug_info
	.long		.Luint8_t - .Lssinfo

	.section	.debug_abbrev
	.uleb128	DW_AT_external
	.uleb128	DW_FORM_flag
	.section	.debug_info
	.byte		1

	.section	.debug_abbrev
	.uleb128	DW_AT_location
	.uleb128	DW_FORM_block1
	.section	.debug_info
	.byte		5	; length of block
	.byte		DW_OP_addr
	.long		0x800000 + 0x0680 + 0x09

	.section	.debug_abbrev
	.uleb128	0
	.uleb128	0

;- - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
	;; DIE #259: variable PORTE_INT0MASK
	.section	.debug_info
	.uleb128	259	; ref to abbrev 259
	.section	.debug_abbrev
	.uleb128	259
	.uleb128	DW_TAG_variable
	.byte		DW_CHILDREN_no

	.uleb128	DW_AT_name
	.uleb128	DW_FORM_strp
	.section	.debug_str
.Lname259:
	.string		"PORTE_INT0MASK"
	.section	.debug_info
	.long		.Lname259

	.section	.debug_abbrev
	.uleb128	DW_AT_decl_file
	.uleb128	DW_FORM_data1
	.section	.debug_info
	.byte		0	; no source file information

	.section	.debug_abbrev
	.uleb128	DW_AT_decl_line
	.uleb128	DW_FORM_data1
	.section	.debug_info
	.byte		0	; no source line information

	.section	.debug_abbrev
	.uleb128	DW_AT_type
	.uleb128	DW_FORM_ref4
	.section	.debug_info
	.long		.Luint8_t - .Lssinfo

	.section	.debug_abbrev
	.uleb128	DW_AT_external
	.uleb128	DW_FORM_flag
	.section	.debug_info
	.byte		1

	.section	.debug_abbrev
	.uleb128	DW_AT_location
	.uleb128	DW_FORM_block1
	.section	.debug_info
	.byte		5	; length of block
	.byte		DW_OP_addr
	.long		0x800000 + 0x0680 + 0x0A

	.section	.debug_abbrev
	.uleb128	0
	.uleb128	0

;- - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
	;; DIE #260: variable PORTE_INT1MASK
	.section	.debug_info
	.uleb128	260	; ref to abbrev 260
	.section	.debug_abbrev
	.uleb128	260
	.uleb128	DW_TAG_variable
	.byte		DW_CHILDREN_no

	.uleb128	DW_AT_name
	.uleb128	DW_FORM_strp
	.section	.debug_str
.Lname260:
	.string		"PORTE_INT1MASK"
	.section	.debug_info
	.long		.Lname260

	.section	.debug_abbrev
	.uleb128	DW_AT_decl_file
	.uleb128	DW_FORM_data1
	.section	.debug_info
	.byte		0	; no source file information

	.section	.debug_abbrev
	.uleb128	DW_AT_decl_line
	.uleb128	DW_FORM_data1
	.section	.debug_info
	.byte		0	; no source line information

	.section	.debug_abbrev
	.uleb128	DW_AT_type
	.uleb128	DW_FORM_ref4
	.section	.debug_info
	.long		.Luint8_t - .Lssinfo

	.section	.debug_abbrev
	.uleb128	DW_AT_external
	.uleb128	DW_FORM_flag
	.section	.debug_info
	.byte		1

	.section	.debug_abbrev
	.uleb128	DW_AT_location
	.uleb128	DW_FORM_block1
	.section	.debug_info
	.byte		5	; length of block
	.byte		DW_OP_addr
	.long		0x800000 + 0x0680 + 0x0B

	.section	.debug_abbrev
	.uleb128	0
	.uleb128	0

;- - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
	;; DIE #261: variable PORTE_INTFLAGS
	.section	.debug_info
	.uleb128	261	; ref to abbrev 261
	.section	.debug_abbrev
	.uleb128	261
	.uleb128	DW_TAG_variable
	.byte		DW_CHILDREN_no

	.uleb128	DW_AT_name
	.uleb128	DW_FORM_strp
	.section	.debug_str
.Lname261:
	.string		"PORTE_INTFLAGS"
	.section	.debug_info
	.long		.Lname261

	.section	.debug_abbrev
	.uleb128	DW_AT_decl_file
	.uleb128	DW_FORM_data1
	.section	.debug_info
	.byte		0	; no source file information

	.section	.debug_abbrev
	.uleb128	DW_AT_decl_line
	.uleb128	DW_FORM_data1
	.section	.debug_info
	.byte		0	; no source line information

	.section	.debug_abbrev
	.uleb128	DW_AT_type
	.uleb128	DW_FORM_ref4
	.section	.debug_info
	.long		.Luint8_t - .Lssinfo

	.section	.debug_abbrev
	.uleb128	DW_AT_external
	.uleb128	DW_FORM_flag
	.section	.debug_info
	.byte		1

	.section	.debug_abbrev
	.uleb128	DW_AT_location
	.uleb128	DW_FORM_block1
	.section	.debug_info
	.byte		5	; length of block
	.byte		DW_OP_addr
	.long		0x800000 + 0x0680 + 0x0C

	.section	.debug_abbrev
	.uleb128	0
	.uleb128	0

;- - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
	;; DIE #262: variable PORTE_REMAP
	.section	.debug_info
	.uleb128	262	; ref to abbrev 262
	.section	.debug_abbrev
	.uleb128	262
	.uleb128	DW_TAG_variable
	.byte		DW_CHILDREN_no

	.uleb128	DW_AT_name
	.uleb128	DW_FORM_strp
	.section	.debug_str
.Lname262:
	.string		"PORTE_REMAP"
	.section	.debug_info
	.long		.Lname262

	.section	.debug_abbrev
	.uleb128	DW_AT_decl_file
	.uleb128	DW_FORM_data1
	.section	.debug_info
	.byte		0	; no source file information

	.section	.debug_abbrev
	.uleb128	DW_AT_decl_line
	.uleb128	DW_FORM_data1
	.section	.debug_info
	.byte		0	; no source line information

	.section	.debug_abbrev
	.uleb128	DW_AT_type
	.uleb128	DW_FORM_ref4
	.section	.debug_info
	.long		.Luint8_t - .Lssinfo

	.section	.debug_abbrev
	.uleb128	DW_AT_external
	.uleb128	DW_FORM_flag
	.section	.debug_info
	.byte		1

	.section	.debug_abbrev
	.uleb128	DW_AT_location
	.uleb128	DW_FORM_block1
	.section	.debug_info
	.byte		5	; length of block
	.byte		DW_OP_addr
	.long		0x800000 + 0x0680 + 0x0E

	.section	.debug_abbrev
	.uleb128	0
	.uleb128	0

;- - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
	;; DIE #263: variable PORTE_PIN0CTRL
	.section	.debug_info
	.uleb128	263	; ref to abbrev 263
	.section	.debug_abbrev
	.uleb128	263
	.uleb128	DW_TAG_variable
	.byte		DW_CHILDREN_no

	.uleb128	DW_AT_name
	.uleb128	DW_FORM_strp
	.section	.debug_str
.Lname263:
	.string		"PORTE_PIN0CTRL"
	.section	.debug_info
	.long		.Lname263

	.section	.debug_abbrev
	.uleb128	DW_AT_decl_file
	.uleb128	DW_FORM_data1
	.section	.debug_info
	.byte		0	; no source file information

	.section	.debug_abbrev
	.uleb128	DW_AT_decl_line
	.uleb128	DW_FORM_data1
	.section	.debug_info
	.byte		0	; no source line information

	.section	.debug_abbrev
	.uleb128	DW_AT_type
	.uleb128	DW_FORM_ref4
	.section	.debug_info
	.long		.Luint8_t - .Lssinfo

	.section	.debug_abbrev
	.uleb128	DW_AT_external
	.uleb128	DW_FORM_flag
	.section	.debug_info
	.byte		1

	.section	.debug_abbrev
	.uleb128	DW_AT_location
	.uleb128	DW_FORM_block1
	.section	.debug_info
	.byte		5	; length of block
	.byte		DW_OP_addr
	.long		0x800000 + 0x0680 + 0x10

	.section	.debug_abbrev
	.uleb128	0
	.uleb128	0

;- - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
	;; DIE #264: variable PORTE_PIN1CTRL
	.section	.debug_info
	.uleb128	264	; ref to abbrev 264
	.section	.debug_abbrev
	.uleb128	264
	.uleb128	DW_TAG_variable
	.byte		DW_CHILDREN_no

	.uleb128	DW_AT_name
	.uleb128	DW_FORM_strp
	.section	.debug_str
.Lname264:
	.string		"PORTE_PIN1CTRL"
	.section	.debug_info
	.long		.Lname264

	.section	.debug_abbrev
	.uleb128	DW_AT_decl_file
	.uleb128	DW_FORM_data1
	.section	.debug_info
	.byte		0	; no source file information

	.section	.debug_abbrev
	.uleb128	DW_AT_decl_line
	.uleb128	DW_FORM_data1
	.section	.debug_info
	.byte		0	; no source line information

	.section	.debug_abbrev
	.uleb128	DW_AT_type
	.uleb128	DW_FORM_ref4
	.section	.debug_info
	.long		.Luint8_t - .Lssinfo

	.section	.debug_abbrev
	.uleb128	DW_AT_external
	.uleb128	DW_FORM_flag
	.section	.debug_info
	.byte		1

	.section	.debug_abbrev
	.uleb128	DW_AT_location
	.uleb128	DW_FORM_block1
	.section	.debug_info
	.byte		5	; length of block
	.byte		DW_OP_addr
	.long		0x800000 + 0x0680 + 0x11

	.section	.debug_abbrev
	.uleb128	0
	.uleb128	0

;- - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
	;; DIE #265: variable PORTE_PIN2CTRL
	.section	.debug_info
	.uleb128	265	; ref to abbrev 265
	.section	.debug_abbrev
	.uleb128	265
	.uleb128	DW_TAG_variable
	.byte		DW_CHILDREN_no

	.uleb128	DW_AT_name
	.uleb128	DW_FORM_strp
	.section	.debug_str
.Lname265:
	.string		"PORTE_PIN2CTRL"
	.section	.debug_info
	.long		.Lname265

	.section	.debug_abbrev
	.uleb128	DW_AT_decl_file
	.uleb128	DW_FORM_data1
	.section	.debug_info
	.byte		0	; no source file information

	.section	.debug_abbrev
	.uleb128	DW_AT_decl_line
	.uleb128	DW_FORM_data1
	.section	.debug_info
	.byte		0	; no source line information

	.section	.debug_abbrev
	.uleb128	DW_AT_type
	.uleb128	DW_FORM_ref4
	.section	.debug_info
	.long		.Luint8_t - .Lssinfo

	.section	.debug_abbrev
	.uleb128	DW_AT_external
	.uleb128	DW_FORM_flag
	.section	.debug_info
	.byte		1

	.section	.debug_abbrev
	.uleb128	DW_AT_location
	.uleb128	DW_FORM_block1
	.section	.debug_info
	.byte		5	; length of block
	.byte		DW_OP_addr
	.long		0x800000 + 0x0680 + 0x12

	.section	.debug_abbrev
	.uleb128	0
	.uleb128	0

;- - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
	;; DIE #266: variable PORTE_PIN3CTRL
	.section	.debug_info
	.uleb128	266	; ref to abbrev 266
	.section	.debug_abbrev
	.uleb128	266
	.uleb128	DW_TAG_variable
	.byte		DW_CHILDREN_no

	.uleb128	DW_AT_name
	.uleb128	DW_FORM_strp
	.section	.debug_str
.Lname266:
	.string		"PORTE_PIN3CTRL"
	.section	.debug_info
	.long		.Lname266

	.section	.debug_abbrev
	.uleb128	DW_AT_decl_file
	.uleb128	DW_FORM_data1
	.section	.debug_info
	.byte		0	; no source file information

	.section	.debug_abbrev
	.uleb128	DW_AT_decl_line
	.uleb128	DW_FORM_data1
	.section	.debug_info
	.byte		0	; no source line information

	.section	.debug_abbrev
	.uleb128	DW_AT_type
	.uleb128	DW_FORM_ref4
	.section	.debug_info
	.long		.Luint8_t - .Lssinfo

	.section	.debug_abbrev
	.uleb128	DW_AT_external
	.uleb128	DW_FORM_flag
	.section	.debug_info
	.byte		1

	.section	.debug_abbrev
	.uleb128	DW_AT_location
	.uleb128	DW_FORM_block1
	.section	.debug_info
	.byte		5	; length of block
	.byte		DW_OP_addr
	.long		0x800000 + 0x0680 + 0x13

	.section	.debug_abbrev
	.uleb128	0
	.uleb128	0

;- - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
	;; DIE #267: variable PORTE_PIN4CTRL
	.section	.debug_info
	.uleb128	267	; ref to abbrev 267
	.section	.debug_abbrev
	.uleb128	267
	.uleb128	DW_TAG_variable
	.byte		DW_CHILDREN_no

	.uleb128	DW_AT_name
	.uleb128	DW_FORM_strp
	.section	.debug_str
.Lname267:
	.string		"PORTE_PIN4CTRL"
	.section	.debug_info
	.long		.Lname267

	.section	.debug_abbrev
	.uleb128	DW_AT_decl_file
	.uleb128	DW_FORM_data1
	.section	.debug_info
	.byte		0	; no source file information

	.section	.debug_abbrev
	.uleb128	DW_AT_decl_line
	.uleb128	DW_FORM_data1
	.section	.debug_info
	.byte		0	; no source line information

	.section	.debug_abbrev
	.uleb128	DW_AT_type
	.uleb128	DW_FORM_ref4
	.section	.debug_info
	.long		.Luint8_t - .Lssinfo

	.section	.debug_abbrev
	.uleb128	DW_AT_external
	.uleb128	DW_FORM_flag
	.section	.debug_info
	.byte		1

	.section	.debug_abbrev
	.uleb128	DW_AT_location
	.uleb128	DW_FORM_block1
	.section	.debug_info
	.byte		5	; length of block
	.byte		DW_OP_addr
	.long		0x800000 + 0x0680 + 0x14

	.section	.debug_abbrev
	.uleb128	0
	.uleb128	0

;- - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
	;; DIE #268: variable PORTE_PIN5CTRL
	.section	.debug_info
	.uleb128	268	; ref to abbrev 268
	.section	.debug_abbrev
	.uleb128	268
	.uleb128	DW_TAG_variable
	.byte		DW_CHILDREN_no

	.uleb128	DW_AT_name
	.uleb128	DW_FORM_strp
	.section	.debug_str
.Lname268:
	.string		"PORTE_PIN5CTRL"
	.section	.debug_info
	.long		.Lname268

	.section	.debug_abbrev
	.uleb128	DW_AT_decl_file
	.uleb128	DW_FORM_data1
	.section	.debug_info
	.byte		0	; no source file information

	.section	.debug_abbrev
	.uleb128	DW_AT_decl_line
	.uleb128	DW_FORM_data1
	.section	.debug_info
	.byte		0	; no source line information

	.section	.debug_abbrev
	.uleb128	DW_AT_type
	.uleb128	DW_FORM_ref4
	.section	.debug_info
	.long		.Luint8_t - .Lssinfo

	.section	.debug_abbrev
	.uleb128	DW_AT_external
	.uleb128	DW_FORM_flag
	.section	.debug_info
	.byte		1

	.section	.debug_abbrev
	.uleb128	DW_AT_location
	.uleb128	DW_FORM_block1
	.section	.debug_info
	.byte		5	; length of block
	.byte		DW_OP_addr
	.long		0x800000 + 0x0680 + 0x15

	.section	.debug_abbrev
	.uleb128	0
	.uleb128	0

;- - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
	;; DIE #269: variable PORTE_PIN6CTRL
	.section	.debug_info
	.uleb128	269	; ref to abbrev 269
	.section	.debug_abbrev
	.uleb128	269
	.uleb128	DW_TAG_variable
	.byte		DW_CHILDREN_no

	.uleb128	DW_AT_name
	.uleb128	DW_FORM_strp
	.section	.debug_str
.Lname269:
	.string		"PORTE_PIN6CTRL"
	.section	.debug_info
	.long		.Lname269

	.section	.debug_abbrev
	.uleb128	DW_AT_decl_file
	.uleb128	DW_FORM_data1
	.section	.debug_info
	.byte		0	; no source file information

	.section	.debug_abbrev
	.uleb128	DW_AT_decl_line
	.uleb128	DW_FORM_data1
	.section	.debug_info
	.byte		0	; no source line information

	.section	.debug_abbrev
	.uleb128	DW_AT_type
	.uleb128	DW_FORM_ref4
	.section	.debug_info
	.long		.Luint8_t - .Lssinfo

	.section	.debug_abbrev
	.uleb128	DW_AT_external
	.uleb128	DW_FORM_flag
	.section	.debug_info
	.byte		1

	.section	.debug_abbrev
	.uleb128	DW_AT_location
	.uleb128	DW_FORM_block1
	.section	.debug_info
	.byte		5	; length of block
	.byte		DW_OP_addr
	.long		0x800000 + 0x0680 + 0x16

	.section	.debug_abbrev
	.uleb128	0
	.uleb128	0

;- - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
	;; DIE #270: variable PORTE_PIN7CTRL
	.section	.debug_info
	.uleb128	270	; ref to abbrev 270
	.section	.debug_abbrev
	.uleb128	270
	.uleb128	DW_TAG_variable
	.byte		DW_CHILDREN_no

	.uleb128	DW_AT_name
	.uleb128	DW_FORM_strp
	.section	.debug_str
.Lname270:
	.string		"PORTE_PIN7CTRL"
	.section	.debug_info
	.long		.Lname270

	.section	.debug_abbrev
	.uleb128	DW_AT_decl_file
	.uleb128	DW_FORM_data1
	.section	.debug_info
	.byte		0	; no source file information

	.section	.debug_abbrev
	.uleb128	DW_AT_decl_line
	.uleb128	DW_FORM_data1
	.section	.debug_info
	.byte		0	; no source line information

	.section	.debug_abbrev
	.uleb128	DW_AT_type
	.uleb128	DW_FORM_ref4
	.section	.debug_info
	.long		.Luint8_t - .Lssinfo

	.section	.debug_abbrev
	.uleb128	DW_AT_external
	.uleb128	DW_FORM_flag
	.section	.debug_info
	.byte		1

	.section	.debug_abbrev
	.uleb128	DW_AT_location
	.uleb128	DW_FORM_block1
	.section	.debug_info
	.byte		5	; length of block
	.byte		DW_OP_addr
	.long		0x800000 + 0x0680 + 0x17

	.section	.debug_abbrev
	.uleb128	0
	.uleb128	0

;- - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
	;; DIE #271: variable PORTR_DIR
	.section	.debug_info
	.uleb128	271	; ref to abbrev 271
	.section	.debug_abbrev
	.uleb128	271
	.uleb128	DW_TAG_variable
	.byte		DW_CHILDREN_no

	.uleb128	DW_AT_name
	.uleb128	DW_FORM_strp
	.section	.debug_str
.Lname271:
	.string		"PORTR_DIR"
	.section	.debug_info
	.long		.Lname271

	.section	.debug_abbrev
	.uleb128	DW_AT_decl_file
	.uleb128	DW_FORM_data1
	.section	.debug_info
	.byte		0	; no source file information

	.section	.debug_abbrev
	.uleb128	DW_AT_decl_line
	.uleb128	DW_FORM_data1
	.section	.debug_info
	.byte		0	; no source line information

	.section	.debug_abbrev
	.uleb128	DW_AT_type
	.uleb128	DW_FORM_ref4
	.section	.debug_info
	.long		.Luint8_t - .Lssinfo

	.section	.debug_abbrev
	.uleb128	DW_AT_external
	.uleb128	DW_FORM_flag
	.section	.debug_info
	.byte		1

	.section	.debug_abbrev
	.uleb128	DW_AT_location
	.uleb128	DW_FORM_block1
	.section	.debug_info
	.byte		5	; length of block
	.byte		DW_OP_addr
	.long		0x800000 + 0x07E0 + 0x00

	.section	.debug_abbrev
	.uleb128	0
	.uleb128	0

;- - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
	;; DIE #272: variable PORTR_DIRSET
	.section	.debug_info
	.uleb128	272	; ref to abbrev 272
	.section	.debug_abbrev
	.uleb128	272
	.uleb128	DW_TAG_variable
	.byte		DW_CHILDREN_no

	.uleb128	DW_AT_name
	.uleb128	DW_FORM_strp
	.section	.debug_str
.Lname272:
	.string		"PORTR_DIRSET"
	.section	.debug_info
	.long		.Lname272

	.section	.debug_abbrev
	.uleb128	DW_AT_decl_file
	.uleb128	DW_FORM_data1
	.section	.debug_info
	.byte		0	; no source file information

	.section	.debug_abbrev
	.uleb128	DW_AT_decl_line
	.uleb128	DW_FORM_data1
	.section	.debug_info
	.byte		0	; no source line information

	.section	.debug_abbrev
	.uleb128	DW_AT_type
	.uleb128	DW_FORM_ref4
	.section	.debug_info
	.long		.Luint8_t - .Lssinfo

	.section	.debug_abbrev
	.uleb128	DW_AT_external
	.uleb128	DW_FORM_flag
	.section	.debug_info
	.byte		1

	.section	.debug_abbrev
	.uleb128	DW_AT_location
	.uleb128	DW_FORM_block1
	.section	.debug_info
	.byte		5	; length of block
	.byte		DW_OP_addr
	.long		0x800000 + 0x07E0 + 0x01

	.section	.debug_abbrev
	.uleb128	0
	.uleb128	0

;- - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
	;; DIE #273: variable PORTR_DIRCLR
	.section	.debug_info
	.uleb128	273	; ref to abbrev 273
	.section	.debug_abbrev
	.uleb128	273
	.uleb128	DW_TAG_variable
	.byte		DW_CHILDREN_no

	.uleb128	DW_AT_name
	.uleb128	DW_FORM_strp
	.section	.debug_str
.Lname273:
	.string		"PORTR_DIRCLR"
	.section	.debug_info
	.long		.Lname273

	.section	.debug_abbrev
	.uleb128	DW_AT_decl_file
	.uleb128	DW_FORM_data1
	.section	.debug_info
	.byte		0	; no source file information

	.section	.debug_abbrev
	.uleb128	DW_AT_decl_line
	.uleb128	DW_FORM_data1
	.section	.debug_info
	.byte		0	; no source line information

	.section	.debug_abbrev
	.uleb128	DW_AT_type
	.uleb128	DW_FORM_ref4
	.section	.debug_info
	.long		.Luint8_t - .Lssinfo

	.section	.debug_abbrev
	.uleb128	DW_AT_external
	.uleb128	DW_FORM_flag
	.section	.debug_info
	.byte		1

	.section	.debug_abbrev
	.uleb128	DW_AT_location
	.uleb128	DW_FORM_block1
	.section	.debug_info
	.byte		5	; length of block
	.byte		DW_OP_addr
	.long		0x800000 + 0x07E0 + 0x02

	.section	.debug_abbrev
	.uleb128	0
	.uleb128	0

;- - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
	;; DIE #274: variable PORTR_DIRTGL
	.section	.debug_info
	.uleb128	274	; ref to abbrev 274
	.section	.debug_abbrev
	.uleb128	274
	.uleb128	DW_TAG_variable
	.byte		DW_CHILDREN_no

	.uleb128	DW_AT_name
	.uleb128	DW_FORM_strp
	.section	.debug_str
.Lname274:
	.string		"PORTR_DIRTGL"
	.section	.debug_info
	.long		.Lname274

	.section	.debug_abbrev
	.uleb128	DW_AT_decl_file
	.uleb128	DW_FORM_data1
	.section	.debug_info
	.byte		0	; no source file information

	.section	.debug_abbrev
	.uleb128	DW_AT_decl_line
	.uleb128	DW_FORM_data1
	.section	.debug_info
	.byte		0	; no source line information

	.section	.debug_abbrev
	.uleb128	DW_AT_type
	.uleb128	DW_FORM_ref4
	.section	.debug_info
	.long		.Luint8_t - .Lssinfo

	.section	.debug_abbrev
	.uleb128	DW_AT_external
	.uleb128	DW_FORM_flag
	.section	.debug_info
	.byte		1

	.section	.debug_abbrev
	.uleb128	DW_AT_location
	.uleb128	DW_FORM_block1
	.section	.debug_info
	.byte		5	; length of block
	.byte		DW_OP_addr
	.long		0x800000 + 0x07E0 + 0x03

	.section	.debug_abbrev
	.uleb128	0
	.uleb128	0

;- - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
	;; DIE #275: variable PORTR_OUT
	.section	.debug_info
	.uleb128	275	; ref to abbrev 275
	.section	.debug_abbrev
	.uleb128	275
	.uleb128	DW_TAG_variable
	.byte		DW_CHILDREN_no

	.uleb128	DW_AT_name
	.uleb128	DW_FORM_strp
	.section	.debug_str
.Lname275:
	.string		"PORTR_OUT"
	.section	.debug_info
	.long		.Lname275

	.section	.debug_abbrev
	.uleb128	DW_AT_decl_file
	.uleb128	DW_FORM_data1
	.section	.debug_info
	.byte		0	; no source file information

	.section	.debug_abbrev
	.uleb128	DW_AT_decl_line
	.uleb128	DW_FORM_data1
	.section	.debug_info
	.byte		0	; no source line information

	.section	.debug_abbrev
	.uleb128	DW_AT_type
	.uleb128	DW_FORM_ref4
	.section	.debug_info
	.long		.Luint8_t - .Lssinfo

	.section	.debug_abbrev
	.uleb128	DW_AT_external
	.uleb128	DW_FORM_flag
	.section	.debug_info
	.byte		1

	.section	.debug_abbrev
	.uleb128	DW_AT_location
	.uleb128	DW_FORM_block1
	.section	.debug_info
	.byte		5	; length of block
	.byte		DW_OP_addr
	.long		0x800000 + 0x07E0 + 0x04

	.section	.debug_abbrev
	.uleb128	0
	.uleb128	0

;- - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
	;; DIE #276: variable PORTR_OUTSET
	.section	.debug_info
	.uleb128	276	; ref to abbrev 276
	.section	.debug_abbrev
	.uleb128	276
	.uleb128	DW_TAG_variable
	.byte		DW_CHILDREN_no

	.uleb128	DW_AT_name
	.uleb128	DW_FORM_strp
	.section	.debug_str
.Lname276:
	.string		"PORTR_OUTSET"
	.section	.debug_info
	.long		.Lname276

	.section	.debug_abbrev
	.uleb128	DW_AT_decl_file
	.uleb128	DW_FORM_data1
	.section	.debug_info
	.byte		0	; no source file information

	.section	.debug_abbrev
	.uleb128	DW_AT_decl_line
	.uleb128	DW_FORM_data1
	.section	.debug_info
	.byte		0	; no source line information

	.section	.debug_abbrev
	.uleb128	DW_AT_type
	.uleb128	DW_FORM_ref4
	.section	.debug_info
	.long		.Luint8_t - .Lssinfo

	.section	.debug_abbrev
	.uleb128	DW_AT_external
	.uleb128	DW_FORM_flag
	.section	.debug_info
	.byte		1

	.section	.debug_abbrev
	.uleb128	DW_AT_location
	.uleb128	DW_FORM_block1
	.section	.debug_info
	.byte		5	; length of block
	.byte		DW_OP_addr
	.long		0x800000 + 0x07E0 + 0x05

	.section	.debug_abbrev
	.uleb128	0
	.uleb128	0

;- - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
	;; DIE #277: variable PORTR_OUTCLR
	.section	.debug_info
	.uleb128	277	; ref to abbrev 277
	.section	.debug_abbrev
	.uleb128	277
	.uleb128	DW_TAG_variable
	.byte		DW_CHILDREN_no

	.uleb128	DW_AT_name
	.uleb128	DW_FORM_strp
	.section	.debug_str
.Lname277:
	.string		"PORTR_OUTCLR"
	.section	.debug_info
	.long		.Lname277

	.section	.debug_abbrev
	.uleb128	DW_AT_decl_file
	.uleb128	DW_FORM_data1
	.section	.debug_info
	.byte		0	; no source file information

	.section	.debug_abbrev
	.uleb128	DW_AT_decl_line
	.uleb128	DW_FORM_data1
	.section	.debug_info
	.byte		0	; no source line information

	.section	.debug_abbrev
	.uleb128	DW_AT_type
	.uleb128	DW_FORM_ref4
	.section	.debug_info
	.long		.Luint8_t - .Lssinfo

	.section	.debug_abbrev
	.uleb128	DW_AT_external
	.uleb128	DW_FORM_flag
	.section	.debug_info
	.byte		1

	.section	.debug_abbrev
	.uleb128	DW_AT_location
	.uleb128	DW_FORM_block1
	.section	.debug_info
	.byte		5	; length of block
	.byte		DW_OP_addr
	.long		0x800000 + 0x07E0 + 0x06

	.section	.debug_abbrev
	.uleb128	0
	.uleb128	0

;- - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
	;; DIE #278: variable PORTR_OUTTGL
	.section	.debug_info
	.uleb128	278	; ref to abbrev 278
	.section	.debug_abbrev
	.uleb128	278
	.uleb128	DW_TAG_variable
	.byte		DW_CHILDREN_no

	.uleb128	DW_AT_name
	.uleb128	DW_FORM_strp
	.section	.debug_str
.Lname278:
	.string		"PORTR_OUTTGL"
	.section	.debug_info
	.long		.Lname278

	.section	.debug_abbrev
	.uleb128	DW_AT_decl_file
	.uleb128	DW_FORM_data1
	.section	.debug_info
	.byte		0	; no source file information

	.section	.debug_abbrev
	.uleb128	DW_AT_decl_line
	.uleb128	DW_FORM_data1
	.section	.debug_info
	.byte		0	; no source line information

	.section	.debug_abbrev
	.uleb128	DW_AT_type
	.uleb128	DW_FORM_ref4
	.section	.debug_info
	.long		.Luint8_t - .Lssinfo

	.section	.debug_abbrev
	.uleb128	DW_AT_external
	.uleb128	DW_FORM_flag
	.section	.debug_info
	.byte		1

	.section	.debug_abbrev
	.uleb128	DW_AT_location
	.uleb128	DW_FORM_block1
	.section	.debug_info
	.byte		5	; length of block
	.byte		DW_OP_addr
	.long		0x800000 + 0x07E0 + 0x07

	.section	.debug_abbrev
	.uleb128	0
	.uleb128	0

;- - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
	;; DIE #279: variable PORTR_IN
	.section	.debug_info
	.uleb128	279	; ref to abbrev 279
	.section	.debug_abbrev
	.uleb128	279
	.uleb128	DW_TAG_variable
	.byte		DW_CHILDREN_no

	.uleb128	DW_AT_name
	.uleb128	DW_FORM_strp
	.section	.debug_str
.Lname279:
	.string		"PORTR_IN"
	.section	.debug_info
	.long		.Lname279

	.section	.debug_abbrev
	.uleb128	DW_AT_decl_file
	.uleb128	DW_FORM_data1
	.section	.debug_info
	.byte		0	; no source file information

	.section	.debug_abbrev
	.uleb128	DW_AT_decl_line
	.uleb128	DW_FORM_data1
	.section	.debug_info
	.byte		0	; no source line information

	.section	.debug_abbrev
	.uleb128	DW_AT_type
	.uleb128	DW_FORM_ref4
	.section	.debug_info
	.long		.Luint8_t - .Lssinfo

	.section	.debug_abbrev
	.uleb128	DW_AT_external
	.uleb128	DW_FORM_flag
	.section	.debug_info
	.byte		1

	.section	.debug_abbrev
	.uleb128	DW_AT_location
	.uleb128	DW_FORM_block1
	.section	.debug_info
	.byte		5	; length of block
	.byte		DW_OP_addr
	.long		0x800000 + 0x07E0 + 0x08

	.section	.debug_abbrev
	.uleb128	0
	.uleb128	0

;- - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
	;; DIE #280: variable PORTR_INTCTRL
	.section	.debug_info
	.uleb128	280	; ref to abbrev 280
	.section	.debug_abbrev
	.uleb128	280
	.uleb128	DW_TAG_variable
	.byte		DW_CHILDREN_no

	.uleb128	DW_AT_name
	.uleb128	DW_FORM_strp
	.section	.debug_str
.Lname280:
	.string		"PORTR_INTCTRL"
	.section	.debug_info
	.long		.Lname280

	.section	.debug_abbrev
	.uleb128	DW_AT_decl_file
	.uleb128	DW_FORM_data1
	.section	.debug_info
	.byte		0	; no source file information

	.section	.debug_abbrev
	.uleb128	DW_AT_decl_line
	.uleb128	DW_FORM_data1
	.section	.debug_info
	.byte		0	; no source line information

	.section	.debug_abbrev
	.uleb128	DW_AT_type
	.uleb128	DW_FORM_ref4
	.section	.debug_info
	.long		.Luint8_t - .Lssinfo

	.section	.debug_abbrev
	.uleb128	DW_AT_external
	.uleb128	DW_FORM_flag
	.section	.debug_info
	.byte		1

	.section	.debug_abbrev
	.uleb128	DW_AT_location
	.uleb128	DW_FORM_block1
	.section	.debug_info
	.byte		5	; length of block
	.byte		DW_OP_addr
	.long		0x800000 + 0x07E0 + 0x09

	.section	.debug_abbrev
	.uleb128	0
	.uleb128	0

;- - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
	;; DIE #281: variable PORTR_INT0MASK
	.section	.debug_info
	.uleb128	281	; ref to abbrev 281
	.section	.debug_abbrev
	.uleb128	281
	.uleb128	DW_TAG_variable
	.byte		DW_CHILDREN_no

	.uleb128	DW_AT_name
	.uleb128	DW_FORM_strp
	.section	.debug_str
.Lname281:
	.string		"PORTR_INT0MASK"
	.section	.debug_info
	.long		.Lname281

	.section	.debug_abbrev
	.uleb128	DW_AT_decl_file
	.uleb128	DW_FORM_data1
	.section	.debug_info
	.byte		0	; no source file information

	.section	.debug_abbrev
	.uleb128	DW_AT_decl_line
	.uleb128	DW_FORM_data1
	.section	.debug_info
	.byte		0	; no source line information

	.section	.debug_abbrev
	.uleb128	DW_AT_type
	.uleb128	DW_FORM_ref4
	.section	.debug_info
	.long		.Luint8_t - .Lssinfo

	.section	.debug_abbrev
	.uleb128	DW_AT_external
	.uleb128	DW_FORM_flag
	.section	.debug_info
	.byte		1

	.section	.debug_abbrev
	.uleb128	DW_AT_location
	.uleb128	DW_FORM_block1
	.section	.debug_info
	.byte		5	; length of block
	.byte		DW_OP_addr
	.long		0x800000 + 0x07E0 + 0x0A

	.section	.debug_abbrev
	.uleb128	0
	.uleb128	0

;- - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
	;; DIE #282: variable PORTR_INT1MASK
	.section	.debug_info
	.uleb128	282	; ref to abbrev 282
	.section	.debug_abbrev
	.uleb128	282
	.uleb128	DW_TAG_variable
	.byte		DW_CHILDREN_no

	.uleb128	DW_AT_name
	.uleb128	DW_FORM_strp
	.section	.debug_str
.Lname282:
	.string		"PORTR_INT1MASK"
	.section	.debug_info
	.long		.Lname282

	.section	.debug_abbrev
	.uleb128	DW_AT_decl_file
	.uleb128	DW_FORM_data1
	.section	.debug_info
	.byte		0	; no source file information

	.section	.debug_abbrev
	.uleb128	DW_AT_decl_line
	.uleb128	DW_FORM_data1
	.section	.debug_info
	.byte		0	; no source line information

	.section	.debug_abbrev
	.uleb128	DW_AT_type
	.uleb128	DW_FORM_ref4
	.section	.debug_info
	.long		.Luint8_t - .Lssinfo

	.section	.debug_abbrev
	.uleb128	DW_AT_external
	.uleb128	DW_FORM_flag
	.section	.debug_info
	.byte		1

	.section	.debug_abbrev
	.uleb128	DW_AT_location
	.uleb128	DW_FORM_block1
	.section	.debug_info
	.byte		5	; length of block
	.byte		DW_OP_addr
	.long		0x800000 + 0x07E0 + 0x0B

	.section	.debug_abbrev
	.uleb128	0
	.uleb128	0

;- - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
	;; DIE #283: variable PORTR_INTFLAGS
	.section	.debug_info
	.uleb128	283	; ref to abbrev 283
	.section	.debug_abbrev
	.uleb128	283
	.uleb128	DW_TAG_variable
	.byte		DW_CHILDREN_no

	.uleb128	DW_AT_name
	.uleb128	DW_FORM_strp
	.section	.debug_str
.Lname283:
	.string		"PORTR_INTFLAGS"
	.section	.debug_info
	.long		.Lname283

	.section	.debug_abbrev
	.uleb128	DW_AT_decl_file
	.uleb128	DW_FORM_data1
	.section	.debug_info
	.byte		0	; no source file information

	.section	.debug_abbrev
	.uleb128	DW_AT_decl_line
	.uleb128	DW_FORM_data1
	.section	.debug_info
	.byte		0	; no source line information

	.section	.debug_abbrev
	.uleb128	DW_AT_type
	.uleb128	DW_FORM_ref4
	.section	.debug_info
	.long		.Luint8_t - .Lssinfo

	.section	.debug_abbrev
	.uleb128	DW_AT_external
	.uleb128	DW_FORM_flag
	.section	.debug_info
	.byte		1

	.section	.debug_abbrev
	.uleb128	DW_AT_location
	.uleb128	DW_FORM_block1
	.section	.debug_info
	.byte		5	; length of block
	.byte		DW_OP_addr
	.long		0x800000 + 0x07E0 + 0x0C

	.section	.debug_abbrev
	.uleb128	0
	.uleb128	0

;- - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
	;; DIE #284: variable PORTR_REMAP
	.section	.debug_info
	.uleb128	284	; ref to abbrev 284
	.section	.debug_abbrev
	.uleb128	284
	.uleb128	DW_TAG_variable
	.byte		DW_CHILDREN_no

	.uleb128	DW_AT_name
	.uleb128	DW_FORM_strp
	.section	.debug_str
.Lname284:
	.string		"PORTR_REMAP"
	.section	.debug_info
	.long		.Lname284

	.section	.debug_abbrev
	.uleb128	DW_AT_decl_file
	.uleb128	DW_FORM_data1
	.section	.debug_info
	.byte		0	; no source file information

	.section	.debug_abbrev
	.uleb128	DW_AT_decl_line
	.uleb128	DW_FORM_data1
	.section	.debug_info
	.byte		0	; no source line information

	.section	.debug_abbrev
	.uleb128	DW_AT_type
	.uleb128	DW_FORM_ref4
	.section	.debug_info
	.long		.Luint8_t - .Lssinfo

	.section	.debug_abbrev
	.uleb128	DW_AT_external
	.uleb128	DW_FORM_flag
	.section	.debug_info
	.byte		1

	.section	.debug_abbrev
	.uleb128	DW_AT_location
	.uleb128	DW_FORM_block1
	.section	.debug_info
	.byte		5	; length of block
	.byte		DW_OP_addr
	.long		0x800000 + 0x07E0 + 0x0E

	.section	.debug_abbrev
	.uleb128	0
	.uleb128	0

;- - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
	;; DIE #285: variable PORTR_PIN0CTRL
	.section	.debug_info
	.uleb128	285	; ref to abbrev 285
	.section	.debug_abbrev
	.uleb128	285
	.uleb128	DW_TAG_variable
	.byte		DW_CHILDREN_no

	.uleb128	DW_AT_name
	.uleb128	DW_FORM_strp
	.section	.debug_str
.Lname285:
	.string		"PORTR_PIN0CTRL"
	.section	.debug_info
	.long		.Lname285

	.section	.debug_abbrev
	.uleb128	DW_AT_decl_file
	.uleb128	DW_FORM_data1
	.section	.debug_info
	.byte		0	; no source file information

	.section	.debug_abbrev
	.uleb128	DW_AT_decl_line
	.uleb128	DW_FORM_data1
	.section	.debug_info
	.byte		0	; no source line information

	.section	.debug_abbrev
	.uleb128	DW_AT_type
	.uleb128	DW_FORM_ref4
	.section	.debug_info
	.long		.Luint8_t - .Lssinfo

	.section	.debug_abbrev
	.uleb128	DW_AT_external
	.uleb128	DW_FORM_flag
	.section	.debug_info
	.byte		1

	.section	.debug_abbrev
	.uleb128	DW_AT_location
	.uleb128	DW_FORM_block1
	.section	.debug_info
	.byte		5	; length of block
	.byte		DW_OP_addr
	.long		0x800000 + 0x07E0 + 0x10

	.section	.debug_abbrev
	.uleb128	0
	.uleb128	0

;- - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
	;; DIE #286: variable PORTR_PIN1CTRL
	.section	.debug_info
	.uleb128	286	; ref to abbrev 286
	.section	.debug_abbrev
	.uleb128	286
	.uleb128	DW_TAG_variable
	.byte		DW_CHILDREN_no

	.uleb128	DW_AT_name
	.uleb128	DW_FORM_strp
	.section	.debug_str
.Lname286:
	.string		"PORTR_PIN1CTRL"
	.section	.debug_info
	.long		.Lname286

	.section	.debug_abbrev
	.uleb128	DW_AT_decl_file
	.uleb128	DW_FORM_data1
	.section	.debug_info
	.byte		0	; no source file information

	.section	.debug_abbrev
	.uleb128	DW_AT_decl_line
	.uleb128	DW_FORM_data1
	.section	.debug_info
	.byte		0	; no source line information

	.section	.debug_abbrev
	.uleb128	DW_AT_type
	.uleb128	DW_FORM_ref4
	.section	.debug_info
	.long		.Luint8_t - .Lssinfo

	.section	.debug_abbrev
	.uleb128	DW_AT_external
	.uleb128	DW_FORM_flag
	.section	.debug_info
	.byte		1

	.section	.debug_abbrev
	.uleb128	DW_AT_location
	.uleb128	DW_FORM_block1
	.section	.debug_info
	.byte		5	; length of block
	.byte		DW_OP_addr
	.long		0x800000 + 0x07E0 + 0x11

	.section	.debug_abbrev
	.uleb128	0
	.uleb128	0

;- - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
	;; DIE #287: variable PORTR_PIN2CTRL
	.section	.debug_info
	.uleb128	287	; ref to abbrev 287
	.section	.debug_abbrev
	.uleb128	287
	.uleb128	DW_TAG_variable
	.byte		DW_CHILDREN_no

	.uleb128	DW_AT_name
	.uleb128	DW_FORM_strp
	.section	.debug_str
.Lname287:
	.string		"PORTR_PIN2CTRL"
	.section	.debug_info
	.long		.Lname287

	.section	.debug_abbrev
	.uleb128	DW_AT_decl_file
	.uleb128	DW_FORM_data1
	.section	.debug_info
	.byte		0	; no source file information

	.section	.debug_abbrev
	.uleb128	DW_AT_decl_line
	.uleb128	DW_FORM_data1
	.section	.debug_info
	.byte		0	; no source line information

	.section	.debug_abbrev
	.uleb128	DW_AT_type
	.uleb128	DW_FORM_ref4
	.section	.debug_info
	.long		.Luint8_t - .Lssinfo

	.section	.debug_abbrev
	.uleb128	DW_AT_external
	.uleb128	DW_FORM_flag
	.section	.debug_info
	.byte		1

	.section	.debug_abbrev
	.uleb128	DW_AT_location
	.uleb128	DW_FORM_block1
	.section	.debug_info
	.byte		5	; length of block
	.byte		DW_OP_addr
	.long		0x800000 + 0x07E0 + 0x12

	.section	.debug_abbrev
	.uleb128	0
	.uleb128	0

;- - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
	;; DIE #288: variable PORTR_PIN3CTRL
	.section	.debug_info
	.uleb128	288	; ref to abbrev 288
	.section	.debug_abbrev
	.uleb128	288
	.uleb128	DW_TAG_variable
	.byte		DW_CHILDREN_no

	.uleb128	DW_AT_name
	.uleb128	DW_FORM_strp
	.section	.debug_str
.Lname288:
	.string		"PORTR_PIN3CTRL"
	.section	.debug_info
	.long		.Lname288

	.section	.debug_abbrev
	.uleb128	DW_AT_decl_file
	.uleb128	DW_FORM_data1
	.section	.debug_info
	.byte		0	; no source file information

	.section	.debug_abbrev
	.uleb128	DW_AT_decl_line
	.uleb128	DW_FORM_data1
	.section	.debug_info
	.byte		0	; no source line information

	.section	.debug_abbrev
	.uleb128	DW_AT_type
	.uleb128	DW_FORM_ref4
	.section	.debug_info
	.long		.Luint8_t - .Lssinfo

	.section	.debug_abbrev
	.uleb128	DW_AT_external
	.uleb128	DW_FORM_flag
	.section	.debug_info
	.byte		1

	.section	.debug_abbrev
	.uleb128	DW_AT_location
	.uleb128	DW_FORM_block1
	.section	.debug_info
	.byte		5	; length of block
	.byte		DW_OP_addr
	.long		0x800000 + 0x07E0 + 0x13

	.section	.debug_abbrev
	.uleb128	0
	.uleb128	0

;- - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
	;; DIE #289: variable PORTR_PIN4CTRL
	.section	.debug_info
	.uleb128	289	; ref to abbrev 289
	.section	.debug_abbrev
	.uleb128	289
	.uleb128	DW_TAG_variable
	.byte		DW_CHILDREN_no

	.uleb128	DW_AT_name
	.uleb128	DW_FORM_strp
	.section	.debug_str
.Lname289:
	.string		"PORTR_PIN4CTRL"
	.section	.debug_info
	.long		.Lname289

	.section	.debug_abbrev
	.uleb128	DW_AT_decl_file
	.uleb128	DW_FORM_data1
	.section	.debug_info
	.byte		0	; no source file information

	.section	.debug_abbrev
	.uleb128	DW_AT_decl_line
	.uleb128	DW_FORM_data1
	.section	.debug_info
	.byte		0	; no source line information

	.section	.debug_abbrev
	.uleb128	DW_AT_type
	.uleb128	DW_FORM_ref4
	.section	.debug_info
	.long		.Luint8_t - .Lssinfo

	.section	.debug_abbrev
	.uleb128	DW_AT_external
	.uleb128	DW_FORM_flag
	.section	.debug_info
	.byte		1

	.section	.debug_abbrev
	.uleb128	DW_AT_location
	.uleb128	DW_FORM_block1
	.section	.debug_info
	.byte		5	; length of block
	.byte		DW_OP_addr
	.long		0x800000 + 0x07E0 + 0x14

	.section	.debug_abbrev
	.uleb128	0
	.uleb128	0

;- - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
	;; DIE #290: variable PORTR_PIN5CTRL
	.section	.debug_info
	.uleb128	290	; ref to abbrev 290
	.section	.debug_abbrev
	.uleb128	290
	.uleb128	DW_TAG_variable
	.byte		DW_CHILDREN_no

	.uleb128	DW_AT_name
	.uleb128	DW_FORM_strp
	.section	.debug_str
.Lname290:
	.string		"PORTR_PIN5CTRL"
	.section	.debug_info
	.long		.Lname290

	.section	.debug_abbrev
	.uleb128	DW_AT_decl_file
	.uleb128	DW_FORM_data1
	.section	.debug_info
	.byte		0	; no source file information

	.section	.debug_abbrev
	.uleb128	DW_AT_decl_line
	.uleb128	DW_FORM_data1
	.section	.debug_info
	.byte		0	; no source line information

	.section	.debug_abbrev
	.uleb128	DW_AT_type
	.uleb128	DW_FORM_ref4
	.section	.debug_info
	.long		.Luint8_t - .Lssinfo

	.section	.debug_abbrev
	.uleb128	DW_AT_external
	.uleb128	DW_FORM_flag
	.section	.debug_info
	.byte		1

	.section	.debug_abbrev
	.uleb128	DW_AT_location
	.uleb128	DW_FORM_block1
	.section	.debug_info
	.byte		5	; length of block
	.byte		DW_OP_addr
	.long		0x800000 + 0x07E0 + 0x15

	.section	.debug_abbrev
	.uleb128	0
	.uleb128	0

;- - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
	;; DIE #291: variable PORTR_PIN6CTRL
	.section	.debug_info
	.uleb128	291	; ref to abbrev 291
	.section	.debug_abbrev
	.uleb128	291
	.uleb128	DW_TAG_variable
	.byte		DW_CHILDREN_no

	.uleb128	DW_AT_name
	.uleb128	DW_FORM_strp
	.section	.debug_str
.Lname291:
	.string		"PORTR_PIN6CTRL"
	.section	.debug_info
	.long		.Lname291

	.section	.debug_abbrev
	.uleb128	DW_AT_decl_file
	.uleb128	DW_FORM_data1
	.section	.debug_info
	.byte		0	; no source file information

	.section	.debug_abbrev
	.uleb128	DW_AT_decl_line
	.uleb128	DW_FORM_data1
	.section	.debug_info
	.byte		0	; no source line information

	.section	.debug_abbrev
	.uleb128	DW_AT_type
	.uleb128	DW_FORM_ref4
	.section	.debug_info
	.long		.Luint8_t - .Lssinfo

	.section	.debug_abbrev
	.uleb128	DW_AT_external
	.uleb128	DW_FORM_flag
	.section	.debug_info
	.byte		1

	.section	.debug_abbrev
	.uleb128	DW_AT_location
	.uleb128	DW_FORM_block1
	.section	.debug_info
	.byte		5	; length of block
	.byte		DW_OP_addr
	.long		0x800000 + 0x07E0 + 0x16

	.section	.debug_abbrev
	.uleb128	0
	.uleb128	0

;- - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
	;; DIE #292: variable PORTR_PIN7CTRL
	.section	.debug_info
	.uleb128	292	; ref to abbrev 292
	.section	.debug_abbrev
	.uleb128	292
	.uleb128	DW_TAG_variable
	.byte		DW_CHILDREN_no

	.uleb128	DW_AT_name
	.uleb128	DW_FORM_strp
	.section	.debug_str
.Lname292:
	.string		"PORTR_PIN7CTRL"
	.section	.debug_info
	.long		.Lname292

	.section	.debug_abbrev
	.uleb128	DW_AT_decl_file
	.uleb128	DW_FORM_data1
	.section	.debug_info
	.byte		0	; no source file information

	.section	.debug_abbrev
	.uleb128	DW_AT_decl_line
	.uleb128	DW_FORM_data1
	.section	.debug_info
	.byte		0	; no source line information

	.section	.debug_abbrev
	.uleb128	DW_AT_type
	.uleb128	DW_FORM_ref4
	.section	.debug_info
	.long		.Luint8_t - .Lssinfo

	.section	.debug_abbrev
	.uleb128	DW_AT_external
	.uleb128	DW_FORM_flag
	.section	.debug_info
	.byte		1

	.section	.debug_abbrev
	.uleb128	DW_AT_location
	.uleb128	DW_FORM_block1
	.section	.debug_info
	.byte		5	; length of block
	.byte		DW_OP_addr
	.long		0x800000 + 0x07E0 + 0x17

	.section	.debug_abbrev
	.uleb128	0
	.uleb128	0

;- - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
	;; DIE #293: variable TCC0_CTRLA
	.section	.debug_info
	.uleb128	293	; ref to abbrev 293
	.section	.debug_abbrev
	.uleb128	293
	.uleb128	DW_TAG_variable
	.byte		DW_CHILDREN_no

	.uleb128	DW_AT_name
	.uleb128	DW_FORM_strp
	.section	.debug_str
.Lname293:
	.string		"TCC0_CTRLA"
	.section	.debug_info
	.long		.Lname293

	.section	.debug_abbrev
	.uleb128	DW_AT_decl_file
	.uleb128	DW_FORM_data1
	.section	.debug_info
	.byte		0	; no source file information

	.section	.debug_abbrev
	.uleb128	DW_AT_decl_line
	.uleb128	DW_FORM_data1
	.section	.debug_info
	.byte		0	; no source line information

	.section	.debug_abbrev
	.uleb128	DW_AT_type
	.uleb128	DW_FORM_ref4
	.section	.debug_info
	.long		.Luint8_t - .Lssinfo

	.section	.debug_abbrev
	.uleb128	DW_AT_external
	.uleb128	DW_FORM_flag
	.section	.debug_info
	.byte		1

	.section	.debug_abbrev
	.uleb128	DW_AT_location
	.uleb128	DW_FORM_block1
	.section	.debug_info
	.byte		5	; length of block
	.byte		DW_OP_addr
	.long		0x800000 + 0x800 + 0x00

	.section	.debug_abbrev
	.uleb128	0
	.uleb128	0

;- - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
	;; DIE #294: variable TCC0_CTRLB
	.section	.debug_info
	.uleb128	294	; ref to abbrev 294
	.section	.debug_abbrev
	.uleb128	294
	.uleb128	DW_TAG_variable
	.byte		DW_CHILDREN_no

	.uleb128	DW_AT_name
	.uleb128	DW_FORM_strp
	.section	.debug_str
.Lname294:
	.string		"TCC0_CTRLB"
	.section	.debug_info
	.long		.Lname294

	.section	.debug_abbrev
	.uleb128	DW_AT_decl_file
	.uleb128	DW_FORM_data1
	.section	.debug_info
	.byte		0	; no source file information

	.section	.debug_abbrev
	.uleb128	DW_AT_decl_line
	.uleb128	DW_FORM_data1
	.section	.debug_info
	.byte		0	; no source line information

	.section	.debug_abbrev
	.uleb128	DW_AT_type
	.uleb128	DW_FORM_ref4
	.section	.debug_info
	.long		.Luint8_t - .Lssinfo

	.section	.debug_abbrev
	.uleb128	DW_AT_external
	.uleb128	DW_FORM_flag
	.section	.debug_info
	.byte		1

	.section	.debug_abbrev
	.uleb128	DW_AT_location
	.uleb128	DW_FORM_block1
	.section	.debug_info
	.byte		5	; length of block
	.byte		DW_OP_addr
	.long		0x800000 + 0x800 + 0x01

	.section	.debug_abbrev
	.uleb128	0
	.uleb128	0

;- - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
	;; DIE #295: variable TCC0_CTRLC
	.section	.debug_info
	.uleb128	295	; ref to abbrev 295
	.section	.debug_abbrev
	.uleb128	295
	.uleb128	DW_TAG_variable
	.byte		DW_CHILDREN_no

	.uleb128	DW_AT_name
	.uleb128	DW_FORM_strp
	.section	.debug_str
.Lname295:
	.string		"TCC0_CTRLC"
	.section	.debug_info
	.long		.Lname295

	.section	.debug_abbrev
	.uleb128	DW_AT_decl_file
	.uleb128	DW_FORM_data1
	.section	.debug_info
	.byte		0	; no source file information

	.section	.debug_abbrev
	.uleb128	DW_AT_decl_line
	.uleb128	DW_FORM_data1
	.section	.debug_info
	.byte		0	; no source line information

	.section	.debug_abbrev
	.uleb128	DW_AT_type
	.uleb128	DW_FORM_ref4
	.section	.debug_info
	.long		.Luint8_t - .Lssinfo

	.section	.debug_abbrev
	.uleb128	DW_AT_external
	.uleb128	DW_FORM_flag
	.section	.debug_info
	.byte		1

	.section	.debug_abbrev
	.uleb128	DW_AT_location
	.uleb128	DW_FORM_block1
	.section	.debug_info
	.byte		5	; length of block
	.byte		DW_OP_addr
	.long		0x800000 + 0x800 + 0x02

	.section	.debug_abbrev
	.uleb128	0
	.uleb128	0

;- - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
	;; DIE #296: variable TCC0_CTRLD
	.section	.debug_info
	.uleb128	296	; ref to abbrev 296
	.section	.debug_abbrev
	.uleb128	296
	.uleb128	DW_TAG_variable
	.byte		DW_CHILDREN_no

	.uleb128	DW_AT_name
	.uleb128	DW_FORM_strp
	.section	.debug_str
.Lname296:
	.string		"TCC0_CTRLD"
	.section	.debug_info
	.long		.Lname296

	.section	.debug_abbrev
	.uleb128	DW_AT_decl_file
	.uleb128	DW_FORM_data1
	.section	.debug_info
	.byte		0	; no source file information

	.section	.debug_abbrev
	.uleb128	DW_AT_decl_line
	.uleb128	DW_FORM_data1
	.section	.debug_info
	.byte		0	; no source line information

	.section	.debug_abbrev
	.uleb128	DW_AT_type
	.uleb128	DW_FORM_ref4
	.section	.debug_info
	.long		.Luint8_t - .Lssinfo

	.section	.debug_abbrev
	.uleb128	DW_AT_external
	.uleb128	DW_FORM_flag
	.section	.debug_info
	.byte		1

	.section	.debug_abbrev
	.uleb128	DW_AT_location
	.uleb128	DW_FORM_block1
	.section	.debug_info
	.byte		5	; length of block
	.byte		DW_OP_addr
	.long		0x800000 + 0x800 + 0x03

	.section	.debug_abbrev
	.uleb128	0
	.uleb128	0

;- - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
	;; DIE #297: variable TCC0_CTRLE
	.section	.debug_info
	.uleb128	297	; ref to abbrev 297
	.section	.debug_abbrev
	.uleb128	297
	.uleb128	DW_TAG_variable
	.byte		DW_CHILDREN_no

	.uleb128	DW_AT_name
	.uleb128	DW_FORM_strp
	.section	.debug_str
.Lname297:
	.string		"TCC0_CTRLE"
	.section	.debug_info
	.long		.Lname297

	.section	.debug_abbrev
	.uleb128	DW_AT_decl_file
	.uleb128	DW_FORM_data1
	.section	.debug_info
	.byte		0	; no source file information

	.section	.debug_abbrev
	.uleb128	DW_AT_decl_line
	.uleb128	DW_FORM_data1
	.section	.debug_info
	.byte		0	; no source line information

	.section	.debug_abbrev
	.uleb128	DW_AT_type
	.uleb128	DW_FORM_ref4
	.section	.debug_info
	.long		.Luint8_t - .Lssinfo

	.section	.debug_abbrev
	.uleb128	DW_AT_external
	.uleb128	DW_FORM_flag
	.section	.debug_info
	.byte		1

	.section	.debug_abbrev
	.uleb128	DW_AT_location
	.uleb128	DW_FORM_block1
	.section	.debug_info
	.byte		5	; length of block
	.byte		DW_OP_addr
	.long		0x800000 + 0x800 + 0x04

	.section	.debug_abbrev
	.uleb128	0
	.uleb128	0

;- - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
	;; DIE #298: variable TCC0_INTCTRLA
	.section	.debug_info
	.uleb128	298	; ref to abbrev 298
	.section	.debug_abbrev
	.uleb128	298
	.uleb128	DW_TAG_variable
	.byte		DW_CHILDREN_no

	.uleb128	DW_AT_name
	.uleb128	DW_FORM_strp
	.section	.debug_str
.Lname298:
	.string		"TCC0_INTCTRLA"
	.section	.debug_info
	.long		.Lname298

	.section	.debug_abbrev
	.uleb128	DW_AT_decl_file
	.uleb128	DW_FORM_data1
	.section	.debug_info
	.byte		0	; no source file information

	.section	.debug_abbrev
	.uleb128	DW_AT_decl_line
	.uleb128	DW_FORM_data1
	.section	.debug_info
	.byte		0	; no source line information

	.section	.debug_abbrev
	.uleb128	DW_AT_type
	.uleb128	DW_FORM_ref4
	.section	.debug_info
	.long		.Luint8_t - .Lssinfo

	.section	.debug_abbrev
	.uleb128	DW_AT_external
	.uleb128	DW_FORM_flag
	.section	.debug_info
	.byte		1

	.section	.debug_abbrev
	.uleb128	DW_AT_location
	.uleb128	DW_FORM_block1
	.section	.debug_info
	.byte		5	; length of block
	.byte		DW_OP_addr
	.long		0x800000 + 0x800 + 0x06

	.section	.debug_abbrev
	.uleb128	0
	.uleb128	0

;- - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
	;; DIE #299: variable TCC0_INTCTRLB
	.section	.debug_info
	.uleb128	299	; ref to abbrev 299
	.section	.debug_abbrev
	.uleb128	299
	.uleb128	DW_TAG_variable
	.byte		DW_CHILDREN_no

	.uleb128	DW_AT_name
	.uleb128	DW_FORM_strp
	.section	.debug_str
.Lname299:
	.string		"TCC0_INTCTRLB"
	.section	.debug_info
	.long		.Lname299

	.section	.debug_abbrev
	.uleb128	DW_AT_decl_file
	.uleb128	DW_FORM_data1
	.section	.debug_info
	.byte		0	; no source file information

	.section	.debug_abbrev
	.uleb128	DW_AT_decl_line
	.uleb128	DW_FORM_data1
	.section	.debug_info
	.byte		0	; no source line information

	.section	.debug_abbrev
	.uleb128	DW_AT_type
	.uleb128	DW_FORM_ref4
	.section	.debug_info
	.long		.Luint8_t - .Lssinfo

	.section	.debug_abbrev
	.uleb128	DW_AT_external
	.uleb128	DW_FORM_flag
	.section	.debug_info
	.byte		1

	.section	.debug_abbrev
	.uleb128	DW_AT_location
	.uleb128	DW_FORM_block1
	.section	.debug_info
	.byte		5	; length of block
	.byte		DW_OP_addr
	.long		0x800000 + 0x800 + 0x07

	.section	.debug_abbrev
	.uleb128	0
	.uleb128	0

;- - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
	;; DIE #300: variable TCC0_CTRLFCLR
	.section	.debug_info
	.uleb128	300	; ref to abbrev 300
	.section	.debug_abbrev
	.uleb128	300
	.uleb128	DW_TAG_variable
	.byte		DW_CHILDREN_no

	.uleb128	DW_AT_name
	.uleb128	DW_FORM_strp
	.section	.debug_str
.Lname300:
	.string		"TCC0_CTRLFCLR"
	.section	.debug_info
	.long		.Lname300

	.section	.debug_abbrev
	.uleb128	DW_AT_decl_file
	.uleb128	DW_FORM_data1
	.section	.debug_info
	.byte		0	; no source file information

	.section	.debug_abbrev
	.uleb128	DW_AT_decl_line
	.uleb128	DW_FORM_data1
	.section	.debug_info
	.byte		0	; no source line information

	.section	.debug_abbrev
	.uleb128	DW_AT_type
	.uleb128	DW_FORM_ref4
	.section	.debug_info
	.long		.Luint8_t - .Lssinfo

	.section	.debug_abbrev
	.uleb128	DW_AT_external
	.uleb128	DW_FORM_flag
	.section	.debug_info
	.byte		1

	.section	.debug_abbrev
	.uleb128	DW_AT_location
	.uleb128	DW_FORM_block1
	.section	.debug_info
	.byte		5	; length of block
	.byte		DW_OP_addr
	.long		0x800000 + 0x800 + 0x08

	.section	.debug_abbrev
	.uleb128	0
	.uleb128	0

;- - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
	;; DIE #301: variable TCC0_CTRLFSET
	.section	.debug_info
	.uleb128	301	; ref to abbrev 301
	.section	.debug_abbrev
	.uleb128	301
	.uleb128	DW_TAG_variable
	.byte		DW_CHILDREN_no

	.uleb128	DW_AT_name
	.uleb128	DW_FORM_strp
	.section	.debug_str
.Lname301:
	.string		"TCC0_CTRLFSET"
	.section	.debug_info
	.long		.Lname301

	.section	.debug_abbrev
	.uleb128	DW_AT_decl_file
	.uleb128	DW_FORM_data1
	.section	.debug_info
	.byte		0	; no source file information

	.section	.debug_abbrev
	.uleb128	DW_AT_decl_line
	.uleb128	DW_FORM_data1
	.section	.debug_info
	.byte		0	; no source line information

	.section	.debug_abbrev
	.uleb128	DW_AT_type
	.uleb128	DW_FORM_ref4
	.section	.debug_info
	.long		.Luint8_t - .Lssinfo

	.section	.debug_abbrev
	.uleb128	DW_AT_external
	.uleb128	DW_FORM_flag
	.section	.debug_info
	.byte		1

	.section	.debug_abbrev
	.uleb128	DW_AT_location
	.uleb128	DW_FORM_block1
	.section	.debug_info
	.byte		5	; length of block
	.byte		DW_OP_addr
	.long		0x800000 + 0x800 + 0x09

	.section	.debug_abbrev
	.uleb128	0
	.uleb128	0

;- - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
	;; DIE #302: variable TCC0_CTRLGCLR
	.section	.debug_info
	.uleb128	302	; ref to abbrev 302
	.section	.debug_abbrev
	.uleb128	302
	.uleb128	DW_TAG_variable
	.byte		DW_CHILDREN_no

	.uleb128	DW_AT_name
	.uleb128	DW_FORM_strp
	.section	.debug_str
.Lname302:
	.string		"TCC0_CTRLGCLR"
	.section	.debug_info
	.long		.Lname302

	.section	.debug_abbrev
	.uleb128	DW_AT_decl_file
	.uleb128	DW_FORM_data1
	.section	.debug_info
	.byte		0	; no source file information

	.section	.debug_abbrev
	.uleb128	DW_AT_decl_line
	.uleb128	DW_FORM_data1
	.section	.debug_info
	.byte		0	; no source line information

	.section	.debug_abbrev
	.uleb128	DW_AT_type
	.uleb128	DW_FORM_ref4
	.section	.debug_info
	.long		.Luint8_t - .Lssinfo

	.section	.debug_abbrev
	.uleb128	DW_AT_external
	.uleb128	DW_FORM_flag
	.section	.debug_info
	.byte		1

	.section	.debug_abbrev
	.uleb128	DW_AT_location
	.uleb128	DW_FORM_block1
	.section	.debug_info
	.byte		5	; length of block
	.byte		DW_OP_addr
	.long		0x800000 + 0x800 + 0x0A

	.section	.debug_abbrev
	.uleb128	0
	.uleb128	0

;- - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
	;; DIE #303: variable TCC0_CTRLGSET
	.section	.debug_info
	.uleb128	303	; ref to abbrev 303
	.section	.debug_abbrev
	.uleb128	303
	.uleb128	DW_TAG_variable
	.byte		DW_CHILDREN_no

	.uleb128	DW_AT_name
	.uleb128	DW_FORM_strp
	.section	.debug_str
.Lname303:
	.string		"TCC0_CTRLGSET"
	.section	.debug_info
	.long		.Lname303

	.section	.debug_abbrev
	.uleb128	DW_AT_decl_file
	.uleb128	DW_FORM_data1
	.section	.debug_info
	.byte		0	; no source file information

	.section	.debug_abbrev
	.uleb128	DW_AT_decl_line
	.uleb128	DW_FORM_data1
	.section	.debug_info
	.byte		0	; no source line information

	.section	.debug_abbrev
	.uleb128	DW_AT_type
	.uleb128	DW_FORM_ref4
	.section	.debug_info
	.long		.Luint8_t - .Lssinfo

	.section	.debug_abbrev
	.uleb128	DW_AT_external
	.uleb128	DW_FORM_flag
	.section	.debug_info
	.byte		1

	.section	.debug_abbrev
	.uleb128	DW_AT_location
	.uleb128	DW_FORM_block1
	.section	.debug_info
	.byte		5	; length of block
	.byte		DW_OP_addr
	.long		0x800000 + 0x800 + 0x0B

	.section	.debug_abbrev
	.uleb128	0
	.uleb128	0

;- - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
	;; DIE #304: variable TCC0_INTFLAGS
	.section	.debug_info
	.uleb128	304	; ref to abbrev 304
	.section	.debug_abbrev
	.uleb128	304
	.uleb128	DW_TAG_variable
	.byte		DW_CHILDREN_no

	.uleb128	DW_AT_name
	.uleb128	DW_FORM_strp
	.section	.debug_str
.Lname304:
	.string		"TCC0_INTFLAGS"
	.section	.debug_info
	.long		.Lname304

	.section	.debug_abbrev
	.uleb128	DW_AT_decl_file
	.uleb128	DW_FORM_data1
	.section	.debug_info
	.byte		0	; no source file information

	.section	.debug_abbrev
	.uleb128	DW_AT_decl_line
	.uleb128	DW_FORM_data1
	.section	.debug_info
	.byte		0	; no source line information

	.section	.debug_abbrev
	.uleb128	DW_AT_type
	.uleb128	DW_FORM_ref4
	.section	.debug_info
	.long		.Luint8_t - .Lssinfo

	.section	.debug_abbrev
	.uleb128	DW_AT_external
	.uleb128	DW_FORM_flag
	.section	.debug_info
	.byte		1

	.section	.debug_abbrev
	.uleb128	DW_AT_location
	.uleb128	DW_FORM_block1
	.section	.debug_info
	.byte		5	; length of block
	.byte		DW_OP_addr
	.long		0x800000 + 0x800 + 0x0C

	.section	.debug_abbrev
	.uleb128	0
	.uleb128	0

;- - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
	;; DIE #305: variable TCC0_TEMP
	.section	.debug_info
	.uleb128	305	; ref to abbrev 305
	.section	.debug_abbrev
	.uleb128	305
	.uleb128	DW_TAG_variable
	.byte		DW_CHILDREN_no

	.uleb128	DW_AT_name
	.uleb128	DW_FORM_strp
	.section	.debug_str
.Lname305:
	.string		"TCC0_TEMP"
	.section	.debug_info
	.long		.Lname305

	.section	.debug_abbrev
	.uleb128	DW_AT_decl_file
	.uleb128	DW_FORM_data1
	.section	.debug_info
	.byte		0	; no source file information

	.section	.debug_abbrev
	.uleb128	DW_AT_decl_line
	.uleb128	DW_FORM_data1
	.section	.debug_info
	.byte		0	; no source line information

	.section	.debug_abbrev
	.uleb128	DW_AT_type
	.uleb128	DW_FORM_ref4
	.section	.debug_info
	.long		.Luint8_t - .Lssinfo

	.section	.debug_abbrev
	.uleb128	DW_AT_external
	.uleb128	DW_FORM_flag
	.section	.debug_info
	.byte		1

	.section	.debug_abbrev
	.uleb128	DW_AT_location
	.uleb128	DW_FORM_block1
	.section	.debug_info
	.byte		5	; length of block
	.byte		DW_OP_addr
	.long		0x800000 + 0x800 + 0x0F

	.section	.debug_abbrev
	.uleb128	0
	.uleb128	0

;- - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
	;; DIE #306: variable TCC0_CNT
	.section	.debug_info
	.uleb128	306	; ref to abbrev 306
	.section	.debug_abbrev
	.uleb128	306
	.uleb128	DW_TAG_variable
	.byte		DW_CHILDREN_no

	.uleb128	DW_AT_name
	.uleb128	DW_FORM_strp
	.section	.debug_str
.Lname306:
	.string		"TCC0_CNT"
	.section	.debug_info
	.long		.Lname306

	.section	.debug_abbrev
	.uleb128	DW_AT_decl_file
	.uleb128	DW_FORM_data1
	.section	.debug_info
	.byte		0	; no source file information

	.section	.debug_abbrev
	.uleb128	DW_AT_decl_line
	.uleb128	DW_FORM_data1
	.section	.debug_info
	.byte		0	; no source line information

	.section	.debug_abbrev
	.uleb128	DW_AT_type
	.uleb128	DW_FORM_ref4
	.section	.debug_info
	.long		.Luint16_t - .Lssinfo

	.section	.debug_abbrev
	.uleb128	DW_AT_external
	.uleb128	DW_FORM_flag
	.section	.debug_info
	.byte		1

	.section	.debug_abbrev
	.uleb128	DW_AT_location
	.uleb128	DW_FORM_block1
	.section	.debug_info
	.byte		5	; length of block
	.byte		DW_OP_addr
	.long		0x800000 + 0x800 + 0x20

	.section	.debug_abbrev
	.uleb128	0
	.uleb128	0

;- - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
	;; DIE #307: variable TCC0_PER
	.section	.debug_info
	.uleb128	307	; ref to abbrev 307
	.section	.debug_abbrev
	.uleb128	307
	.uleb128	DW_TAG_variable
	.byte		DW_CHILDREN_no

	.uleb128	DW_AT_name
	.uleb128	DW_FORM_strp
	.section	.debug_str
.Lname307:
	.string		"TCC0_PER"
	.section	.debug_info
	.long		.Lname307

	.section	.debug_abbrev
	.uleb128	DW_AT_decl_file
	.uleb128	DW_FORM_data1
	.section	.debug_info
	.byte		0	; no source file information

	.section	.debug_abbrev
	.uleb128	DW_AT_decl_line
	.uleb128	DW_FORM_data1
	.section	.debug_info
	.byte		0	; no source line information

	.section	.debug_abbrev
	.uleb128	DW_AT_type
	.uleb128	DW_FORM_ref4
	.section	.debug_info
	.long		.Luint16_t - .Lssinfo

	.section	.debug_abbrev
	.uleb128	DW_AT_external
	.uleb128	DW_FORM_flag
	.section	.debug_info
	.byte		1

	.section	.debug_abbrev
	.uleb128	DW_AT_location
	.uleb128	DW_FORM_block1
	.section	.debug_info
	.byte		5	; length of block
	.byte		DW_OP_addr
	.long		0x800000 + 0x800 + 0x26

	.section	.debug_abbrev
	.uleb128	0
	.uleb128	0

;- - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
	;; DIE #308: variable TCC0_CCA
	.section	.debug_info
	.uleb128	308	; ref to abbrev 308
	.section	.debug_abbrev
	.uleb128	308
	.uleb128	DW_TAG_variable
	.byte		DW_CHILDREN_no

	.uleb128	DW_AT_name
	.uleb128	DW_FORM_strp
	.section	.debug_str
.Lname308:
	.string		"TCC0_CCA"
	.section	.debug_info
	.long		.Lname308

	.section	.debug_abbrev
	.uleb128	DW_AT_decl_file
	.uleb128	DW_FORM_data1
	.section	.debug_info
	.byte		0	; no source file information

	.section	.debug_abbrev
	.uleb128	DW_AT_decl_line
	.uleb128	DW_FORM_data1
	.section	.debug_info
	.byte		0	; no source line information

	.section	.debug_abbrev
	.uleb128	DW_AT_type
	.uleb128	DW_FORM_ref4
	.section	.debug_info
	.long		.Luint16_t - .Lssinfo

	.section	.debug_abbrev
	.uleb128	DW_AT_external
	.uleb128	DW_FORM_flag
	.section	.debug_info
	.byte		1

	.section	.debug_abbrev
	.uleb128	DW_AT_location
	.uleb128	DW_FORM_block1
	.section	.debug_info
	.byte		5	; length of block
	.byte		DW_OP_addr
	.long		0x800000 + 0x800 + 0x28

	.section	.debug_abbrev
	.uleb128	0
	.uleb128	0

;- - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
	;; DIE #309: variable TCC0_CCB
	.section	.debug_info
	.uleb128	309	; ref to abbrev 309
	.section	.debug_abbrev
	.uleb128	309
	.uleb128	DW_TAG_variable
	.byte		DW_CHILDREN_no

	.uleb128	DW_AT_name
	.uleb128	DW_FORM_strp
	.section	.debug_str
.Lname309:
	.string		"TCC0_CCB"
	.section	.debug_info
	.long		.Lname309

	.section	.debug_abbrev
	.uleb128	DW_AT_decl_file
	.uleb128	DW_FORM_data1
	.section	.debug_info
	.byte		0	; no source file information

	.section	.debug_abbrev
	.uleb128	DW_AT_decl_line
	.uleb128	DW_FORM_data1
	.section	.debug_info
	.byte		0	; no source line information

	.section	.debug_abbrev
	.uleb128	DW_AT_type
	.uleb128	DW_FORM_ref4
	.section	.debug_info
	.long		.Luint16_t - .Lssinfo

	.section	.debug_abbrev
	.uleb128	DW_AT_external
	.uleb128	DW_FORM_flag
	.section	.debug_info
	.byte		1

	.section	.debug_abbrev
	.uleb128	DW_AT_location
	.uleb128	DW_FORM_block1
	.section	.debug_info
	.byte		5	; length of block
	.byte		DW_OP_addr
	.long		0x800000 + 0x800 + 0x2A

	.section	.debug_abbrev
	.uleb128	0
	.uleb128	0

;- - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
	;; DIE #310: variable TCC0_CCC
	.section	.debug_info
	.uleb128	310	; ref to abbrev 310
	.section	.debug_abbrev
	.uleb128	310
	.uleb128	DW_TAG_variable
	.byte		DW_CHILDREN_no

	.uleb128	DW_AT_name
	.uleb128	DW_FORM_strp
	.section	.debug_str
.Lname310:
	.string		"TCC0_CCC"
	.section	.debug_info
	.long		.Lname310

	.section	.debug_abbrev
	.uleb128	DW_AT_decl_file
	.uleb128	DW_FORM_data1
	.section	.debug_info
	.byte		0	; no source file information

	.section	.debug_abbrev
	.uleb128	DW_AT_decl_line
	.uleb128	DW_FORM_data1
	.section	.debug_info
	.byte		0	; no source line information

	.section	.debug_abbrev
	.uleb128	DW_AT_type
	.uleb128	DW_FORM_ref4
	.section	.debug_info
	.long		.Luint16_t - .Lssinfo

	.section	.debug_abbrev
	.uleb128	DW_AT_external
	.uleb128	DW_FORM_flag
	.section	.debug_info
	.byte		1

	.section	.debug_abbrev
	.uleb128	DW_AT_location
	.uleb128	DW_FORM_block1
	.section	.debug_info
	.byte		5	; length of block
	.byte		DW_OP_addr
	.long		0x800000 + 0x800 + 0x2C

	.section	.debug_abbrev
	.uleb128	0
	.uleb128	0

;- - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
	;; DIE #311: variable TCC0_CCD
	.section	.debug_info
	.uleb128	311	; ref to abbrev 311
	.section	.debug_abbrev
	.uleb128	311
	.uleb128	DW_TAG_variable
	.byte		DW_CHILDREN_no

	.uleb128	DW_AT_name
	.uleb128	DW_FORM_strp
	.section	.debug_str
.Lname311:
	.string		"TCC0_CCD"
	.section	.debug_info
	.long		.Lname311

	.section	.debug_abbrev
	.uleb128	DW_AT_decl_file
	.uleb128	DW_FORM_data1
	.section	.debug_info
	.byte		0	; no source file information

	.section	.debug_abbrev
	.uleb128	DW_AT_decl_line
	.uleb128	DW_FORM_data1
	.section	.debug_info
	.byte		0	; no source line information

	.section	.debug_abbrev
	.uleb128	DW_AT_type
	.uleb128	DW_FORM_ref4
	.section	.debug_info
	.long		.Luint16_t - .Lssinfo

	.section	.debug_abbrev
	.uleb128	DW_AT_external
	.uleb128	DW_FORM_flag
	.section	.debug_info
	.byte		1

	.section	.debug_abbrev
	.uleb128	DW_AT_location
	.uleb128	DW_FORM_block1
	.section	.debug_info
	.byte		5	; length of block
	.byte		DW_OP_addr
	.long		0x800000 + 0x800 + 0x2E

	.section	.debug_abbrev
	.uleb128	0
	.uleb128	0

;- - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
	;; DIE #312: variable TCC0_PERBUF
	.section	.debug_info
	.uleb128	312	; ref to abbrev 312
	.section	.debug_abbrev
	.uleb128	312
	.uleb128	DW_TAG_variable
	.byte		DW_CHILDREN_no

	.uleb128	DW_AT_name
	.uleb128	DW_FORM_strp
	.section	.debug_str
.Lname312:
	.string		"TCC0_PERBUF"
	.section	.debug_info
	.long		.Lname312

	.section	.debug_abbrev
	.uleb128	DW_AT_decl_file
	.uleb128	DW_FORM_data1
	.section	.debug_info
	.byte		0	; no source file information

	.section	.debug_abbrev
	.uleb128	DW_AT_decl_line
	.uleb128	DW_FORM_data1
	.section	.debug_info
	.byte		0	; no source line information

	.section	.debug_abbrev
	.uleb128	DW_AT_type
	.uleb128	DW_FORM_ref4
	.section	.debug_info
	.long		.Luint16_t - .Lssinfo

	.section	.debug_abbrev
	.uleb128	DW_AT_external
	.uleb128	DW_FORM_flag
	.section	.debug_info
	.byte		1

	.section	.debug_abbrev
	.uleb128	DW_AT_location
	.uleb128	DW_FORM_block1
	.section	.debug_info
	.byte		5	; length of block
	.byte		DW_OP_addr
	.long		0x800000 + 0x800 + 0x36

	.section	.debug_abbrev
	.uleb128	0
	.uleb128	0

;- - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
	;; DIE #313: variable TCC0_CCABUF
	.section	.debug_info
	.uleb128	313	; ref to abbrev 313
	.section	.debug_abbrev
	.uleb128	313
	.uleb128	DW_TAG_variable
	.byte		DW_CHILDREN_no

	.uleb128	DW_AT_name
	.uleb128	DW_FORM_strp
	.section	.debug_str
.Lname313:
	.string		"TCC0_CCABUF"
	.section	.debug_info
	.long		.Lname313

	.section	.debug_abbrev
	.uleb128	DW_AT_decl_file
	.uleb128	DW_FORM_data1
	.section	.debug_info
	.byte		0	; no source file information

	.section	.debug_abbrev
	.uleb128	DW_AT_decl_line
	.uleb128	DW_FORM_data1
	.section	.debug_info
	.byte		0	; no source line information

	.section	.debug_abbrev
	.uleb128	DW_AT_type
	.uleb128	DW_FORM_ref4
	.section	.debug_info
	.long		.Luint16_t - .Lssinfo

	.section	.debug_abbrev
	.uleb128	DW_AT_external
	.uleb128	DW_FORM_flag
	.section	.debug_info
	.byte		1

	.section	.debug_abbrev
	.uleb128	DW_AT_location
	.uleb128	DW_FORM_block1
	.section	.debug_info
	.byte		5	; length of block
	.byte		DW_OP_addr
	.long		0x800000 + 0x800 + 0x38

	.section	.debug_abbrev
	.uleb128	0
	.uleb128	0

;- - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
	;; DIE #314: variable TCC0_CCBBUF
	.section	.debug_info
	.uleb128	314	; ref to abbrev 314
	.section	.debug_abbrev
	.uleb128	314
	.uleb128	DW_TAG_variable
	.byte		DW_CHILDREN_no

	.uleb128	DW_AT_name
	.uleb128	DW_FORM_strp
	.section	.debug_str
.Lname314:
	.string		"TCC0_CCBBUF"
	.section	.debug_info
	.long		.Lname314

	.section	.debug_abbrev
	.uleb128	DW_AT_decl_file
	.uleb128	DW_FORM_data1
	.section	.debug_info
	.byte		0	; no source file information

	.section	.debug_abbrev
	.uleb128	DW_AT_decl_line
	.uleb128	DW_FORM_data1
	.section	.debug_info
	.byte		0	; no source line information

	.section	.debug_abbrev
	.uleb128	DW_AT_type
	.uleb128	DW_FORM_ref4
	.section	.debug_info
	.long		.Luint16_t - .Lssinfo

	.section	.debug_abbrev
	.uleb128	DW_AT_external
	.uleb128	DW_FORM_flag
	.section	.debug_info
	.byte		1

	.section	.debug_abbrev
	.uleb128	DW_AT_location
	.uleb128	DW_FORM_block1
	.section	.debug_info
	.byte		5	; length of block
	.byte		DW_OP_addr
	.long		0x800000 + 0x800 + 0x3A

	.section	.debug_abbrev
	.uleb128	0
	.uleb128	0

;- - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
	;; DIE #315: variable TCC0_CCCBUF
	.section	.debug_info
	.uleb128	315	; ref to abbrev 315
	.section	.debug_abbrev
	.uleb128	315
	.uleb128	DW_TAG_variable
	.byte		DW_CHILDREN_no

	.uleb128	DW_AT_name
	.uleb128	DW_FORM_strp
	.section	.debug_str
.Lname315:
	.string		"TCC0_CCCBUF"
	.section	.debug_info
	.long		.Lname315

	.section	.debug_abbrev
	.uleb128	DW_AT_decl_file
	.uleb128	DW_FORM_data1
	.section	.debug_info
	.byte		0	; no source file information

	.section	.debug_abbrev
	.uleb128	DW_AT_decl_line
	.uleb128	DW_FORM_data1
	.section	.debug_info
	.byte		0	; no source line information

	.section	.debug_abbrev
	.uleb128	DW_AT_type
	.uleb128	DW_FORM_ref4
	.section	.debug_info
	.long		.Luint16_t - .Lssinfo

	.section	.debug_abbrev
	.uleb128	DW_AT_external
	.uleb128	DW_FORM_flag
	.section	.debug_info
	.byte		1

	.section	.debug_abbrev
	.uleb128	DW_AT_location
	.uleb128	DW_FORM_block1
	.section	.debug_info
	.byte		5	; length of block
	.byte		DW_OP_addr
	.long		0x800000 + 0x800 + 0x3C

	.section	.debug_abbrev
	.uleb128	0
	.uleb128	0

;- - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
	;; DIE #316: variable TCC0_CCDBUF
	.section	.debug_info
	.uleb128	316	; ref to abbrev 316
	.section	.debug_abbrev
	.uleb128	316
	.uleb128	DW_TAG_variable
	.byte		DW_CHILDREN_no

	.uleb128	DW_AT_name
	.uleb128	DW_FORM_strp
	.section	.debug_str
.Lname316:
	.string		"TCC0_CCDBUF"
	.section	.debug_info
	.long		.Lname316

	.section	.debug_abbrev
	.uleb128	DW_AT_decl_file
	.uleb128	DW_FORM_data1
	.section	.debug_info
	.byte		0	; no source file information

	.section	.debug_abbrev
	.uleb128	DW_AT_decl_line
	.uleb128	DW_FORM_data1
	.section	.debug_info
	.byte		0	; no source line information

	.section	.debug_abbrev
	.uleb128	DW_AT_type
	.uleb128	DW_FORM_ref4
	.section	.debug_info
	.long		.Luint16_t - .Lssinfo

	.section	.debug_abbrev
	.uleb128	DW_AT_external
	.uleb128	DW_FORM_flag
	.section	.debug_info
	.byte		1

	.section	.debug_abbrev
	.uleb128	DW_AT_location
	.uleb128	DW_FORM_block1
	.section	.debug_info
	.byte		5	; length of block
	.byte		DW_OP_addr
	.long		0x800000 + 0x800 + 0x3E

	.section	.debug_abbrev
	.uleb128	0
	.uleb128	0

;- - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
	;; DIE #317: variable TCC1_CTRLA
	.section	.debug_info
	.uleb128	317	; ref to abbrev 317
	.section	.debug_abbrev
	.uleb128	317
	.uleb128	DW_TAG_variable
	.byte		DW_CHILDREN_no

	.uleb128	DW_AT_name
	.uleb128	DW_FORM_strp
	.section	.debug_str
.Lname317:
	.string		"TCC1_CTRLA"
	.section	.debug_info
	.long		.Lname317

	.section	.debug_abbrev
	.uleb128	DW_AT_decl_file
	.uleb128	DW_FORM_data1
	.section	.debug_info
	.byte		0	; no source file information

	.section	.debug_abbrev
	.uleb128	DW_AT_decl_line
	.uleb128	DW_FORM_data1
	.section	.debug_info
	.byte		0	; no source line information

	.section	.debug_abbrev
	.uleb128	DW_AT_type
	.uleb128	DW_FORM_ref4
	.section	.debug_info
	.long		.Luint8_t - .Lssinfo

	.section	.debug_abbrev
	.uleb128	DW_AT_external
	.uleb128	DW_FORM_flag
	.section	.debug_info
	.byte		1

	.section	.debug_abbrev
	.uleb128	DW_AT_location
	.uleb128	DW_FORM_block1
	.section	.debug_info
	.byte		5	; length of block
	.byte		DW_OP_addr
	.long		0x800000 + 0x840 + 0x00

	.section	.debug_abbrev
	.uleb128	0
	.uleb128	0

;- - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
	;; DIE #318: variable TCC1_CTRLB
	.section	.debug_info
	.uleb128	318	; ref to abbrev 318
	.section	.debug_abbrev
	.uleb128	318
	.uleb128	DW_TAG_variable
	.byte		DW_CHILDREN_no

	.uleb128	DW_AT_name
	.uleb128	DW_FORM_strp
	.section	.debug_str
.Lname318:
	.string		"TCC1_CTRLB"
	.section	.debug_info
	.long		.Lname318

	.section	.debug_abbrev
	.uleb128	DW_AT_decl_file
	.uleb128	DW_FORM_data1
	.section	.debug_info
	.byte		0	; no source file information

	.section	.debug_abbrev
	.uleb128	DW_AT_decl_line
	.uleb128	DW_FORM_data1
	.section	.debug_info
	.byte		0	; no source line information

	.section	.debug_abbrev
	.uleb128	DW_AT_type
	.uleb128	DW_FORM_ref4
	.section	.debug_info
	.long		.Luint8_t - .Lssinfo

	.section	.debug_abbrev
	.uleb128	DW_AT_external
	.uleb128	DW_FORM_flag
	.section	.debug_info
	.byte		1

	.section	.debug_abbrev
	.uleb128	DW_AT_location
	.uleb128	DW_FORM_block1
	.section	.debug_info
	.byte		5	; length of block
	.byte		DW_OP_addr
	.long		0x800000 + 0x840 + 0x01

	.section	.debug_abbrev
	.uleb128	0
	.uleb128	0

;- - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
	;; DIE #319: variable TCC1_CTRLC
	.section	.debug_info
	.uleb128	319	; ref to abbrev 319
	.section	.debug_abbrev
	.uleb128	319
	.uleb128	DW_TAG_variable
	.byte		DW_CHILDREN_no

	.uleb128	DW_AT_name
	.uleb128	DW_FORM_strp
	.section	.debug_str
.Lname319:
	.string		"TCC1_CTRLC"
	.section	.debug_info
	.long		.Lname319

	.section	.debug_abbrev
	.uleb128	DW_AT_decl_file
	.uleb128	DW_FORM_data1
	.section	.debug_info
	.byte		0	; no source file information

	.section	.debug_abbrev
	.uleb128	DW_AT_decl_line
	.uleb128	DW_FORM_data1
	.section	.debug_info
	.byte		0	; no source line information

	.section	.debug_abbrev
	.uleb128	DW_AT_type
	.uleb128	DW_FORM_ref4
	.section	.debug_info
	.long		.Luint8_t - .Lssinfo

	.section	.debug_abbrev
	.uleb128	DW_AT_external
	.uleb128	DW_FORM_flag
	.section	.debug_info
	.byte		1

	.section	.debug_abbrev
	.uleb128	DW_AT_location
	.uleb128	DW_FORM_block1
	.section	.debug_info
	.byte		5	; length of block
	.byte		DW_OP_addr
	.long		0x800000 + 0x840 + 0x02

	.section	.debug_abbrev
	.uleb128	0
	.uleb128	0

;- - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
	;; DIE #320: variable TCC1_CTRLD
	.section	.debug_info
	.uleb128	320	; ref to abbrev 320
	.section	.debug_abbrev
	.uleb128	320
	.uleb128	DW_TAG_variable
	.byte		DW_CHILDREN_no

	.uleb128	DW_AT_name
	.uleb128	DW_FORM_strp
	.section	.debug_str
.Lname320:
	.string		"TCC1_CTRLD"
	.section	.debug_info
	.long		.Lname320

	.section	.debug_abbrev
	.uleb128	DW_AT_decl_file
	.uleb128	DW_FORM_data1
	.section	.debug_info
	.byte		0	; no source file information

	.section	.debug_abbrev
	.uleb128	DW_AT_decl_line
	.uleb128	DW_FORM_data1
	.section	.debug_info
	.byte		0	; no source line information

	.section	.debug_abbrev
	.uleb128	DW_AT_type
	.uleb128	DW_FORM_ref4
	.section	.debug_info
	.long		.Luint8_t - .Lssinfo

	.section	.debug_abbrev
	.uleb128	DW_AT_external
	.uleb128	DW_FORM_flag
	.section	.debug_info
	.byte		1

	.section	.debug_abbrev
	.uleb128	DW_AT_location
	.uleb128	DW_FORM_block1
	.section	.debug_info
	.byte		5	; length of block
	.byte		DW_OP_addr
	.long		0x800000 + 0x840 + 0x03

	.section	.debug_abbrev
	.uleb128	0
	.uleb128	0

;- - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
	;; DIE #321: variable TCC1_CTRLE
	.section	.debug_info
	.uleb128	321	; ref to abbrev 321
	.section	.debug_abbrev
	.uleb128	321
	.uleb128	DW_TAG_variable
	.byte		DW_CHILDREN_no

	.uleb128	DW_AT_name
	.uleb128	DW_FORM_strp
	.section	.debug_str
.Lname321:
	.string		"TCC1_CTRLE"
	.section	.debug_info
	.long		.Lname321

	.section	.debug_abbrev
	.uleb128	DW_AT_decl_file
	.uleb128	DW_FORM_data1
	.section	.debug_info
	.byte		0	; no source file information

	.section	.debug_abbrev
	.uleb128	DW_AT_decl_line
	.uleb128	DW_FORM_data1
	.section	.debug_info
	.byte		0	; no source line information

	.section	.debug_abbrev
	.uleb128	DW_AT_type
	.uleb128	DW_FORM_ref4
	.section	.debug_info
	.long		.Luint8_t - .Lssinfo

	.section	.debug_abbrev
	.uleb128	DW_AT_external
	.uleb128	DW_FORM_flag
	.section	.debug_info
	.byte		1

	.section	.debug_abbrev
	.uleb128	DW_AT_location
	.uleb128	DW_FORM_block1
	.section	.debug_info
	.byte		5	; length of block
	.byte		DW_OP_addr
	.long		0x800000 + 0x840 + 0x04

	.section	.debug_abbrev
	.uleb128	0
	.uleb128	0

;- - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
	;; DIE #322: variable TCC1_INTCTRLA
	.section	.debug_info
	.uleb128	322	; ref to abbrev 322
	.section	.debug_abbrev
	.uleb128	322
	.uleb128	DW_TAG_variable
	.byte		DW_CHILDREN_no

	.uleb128	DW_AT_name
	.uleb128	DW_FORM_strp
	.section	.debug_str
.Lname322:
	.string		"TCC1_INTCTRLA"
	.section	.debug_info
	.long		.Lname322

	.section	.debug_abbrev
	.uleb128	DW_AT_decl_file
	.uleb128	DW_FORM_data1
	.section	.debug_info
	.byte		0	; no source file information

	.section	.debug_abbrev
	.uleb128	DW_AT_decl_line
	.uleb128	DW_FORM_data1
	.section	.debug_info
	.byte		0	; no source line information

	.section	.debug_abbrev
	.uleb128	DW_AT_type
	.uleb128	DW_FORM_ref4
	.section	.debug_info
	.long		.Luint8_t - .Lssinfo

	.section	.debug_abbrev
	.uleb128	DW_AT_external
	.uleb128	DW_FORM_flag
	.section	.debug_info
	.byte		1

	.section	.debug_abbrev
	.uleb128	DW_AT_location
	.uleb128	DW_FORM_block1
	.section	.debug_info
	.byte		5	; length of block
	.byte		DW_OP_addr
	.long		0x800000 + 0x840 + 0x06

	.section	.debug_abbrev
	.uleb128	0
	.uleb128	0

;- - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
	;; DIE #323: variable TCC1_INTCTRLB
	.section	.debug_info
	.uleb128	323	; ref to abbrev 323
	.section	.debug_abbrev
	.uleb128	323
	.uleb128	DW_TAG_variable
	.byte		DW_CHILDREN_no

	.uleb128	DW_AT_name
	.uleb128	DW_FORM_strp
	.section	.debug_str
.Lname323:
	.string		"TCC1_INTCTRLB"
	.section	.debug_info
	.long		.Lname323

	.section	.debug_abbrev
	.uleb128	DW_AT_decl_file
	.uleb128	DW_FORM_data1
	.section	.debug_info
	.byte		0	; no source file information

	.section	.debug_abbrev
	.uleb128	DW_AT_decl_line
	.uleb128	DW_FORM_data1
	.section	.debug_info
	.byte		0	; no source line information

	.section	.debug_abbrev
	.uleb128	DW_AT_type
	.uleb128	DW_FORM_ref4
	.section	.debug_info
	.long		.Luint8_t - .Lssinfo

	.section	.debug_abbrev
	.uleb128	DW_AT_external
	.uleb128	DW_FORM_flag
	.section	.debug_info
	.byte		1

	.section	.debug_abbrev
	.uleb128	DW_AT_location
	.uleb128	DW_FORM_block1
	.section	.debug_info
	.byte		5	; length of block
	.byte		DW_OP_addr
	.long		0x800000 + 0x840 + 0x07

	.section	.debug_abbrev
	.uleb128	0
	.uleb128	0

;- - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
	;; DIE #324: variable TCC1_CTRLFCLR
	.section	.debug_info
	.uleb128	324	; ref to abbrev 324
	.section	.debug_abbrev
	.uleb128	324
	.uleb128	DW_TAG_variable
	.byte		DW_CHILDREN_no

	.uleb128	DW_AT_name
	.uleb128	DW_FORM_strp
	.section	.debug_str
.Lname324:
	.string		"TCC1_CTRLFCLR"
	.section	.debug_info
	.long		.Lname324

	.section	.debug_abbrev
	.uleb128	DW_AT_decl_file
	.uleb128	DW_FORM_data1
	.section	.debug_info
	.byte		0	; no source file information

	.section	.debug_abbrev
	.uleb128	DW_AT_decl_line
	.uleb128	DW_FORM_data1
	.section	.debug_info
	.byte		0	; no source line information

	.section	.debug_abbrev
	.uleb128	DW_AT_type
	.uleb128	DW_FORM_ref4
	.section	.debug_info
	.long		.Luint8_t - .Lssinfo

	.section	.debug_abbrev
	.uleb128	DW_AT_external
	.uleb128	DW_FORM_flag
	.section	.debug_info
	.byte		1

	.section	.debug_abbrev
	.uleb128	DW_AT_location
	.uleb128	DW_FORM_block1
	.section	.debug_info
	.byte		5	; length of block
	.byte		DW_OP_addr
	.long		0x800000 + 0x840 + 0x08

	.section	.debug_abbrev
	.uleb128	0
	.uleb128	0

;- - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
	;; DIE #325: variable TCC1_CTRLFSET
	.section	.debug_info
	.uleb128	325	; ref to abbrev 325
	.section	.debug_abbrev
	.uleb128	325
	.uleb128	DW_TAG_variable
	.byte		DW_CHILDREN_no

	.uleb128	DW_AT_name
	.uleb128	DW_FORM_strp
	.section	.debug_str
.Lname325:
	.string		"TCC1_CTRLFSET"
	.section	.debug_info
	.long		.Lname325

	.section	.debug_abbrev
	.uleb128	DW_AT_decl_file
	.uleb128	DW_FORM_data1
	.section	.debug_info
	.byte		0	; no source file information

	.section	.debug_abbrev
	.uleb128	DW_AT_decl_line
	.uleb128	DW_FORM_data1
	.section	.debug_info
	.byte		0	; no source line information

	.section	.debug_abbrev
	.uleb128	DW_AT_type
	.uleb128	DW_FORM_ref4
	.section	.debug_info
	.long		.Luint8_t - .Lssinfo

	.section	.debug_abbrev
	.uleb128	DW_AT_external
	.uleb128	DW_FORM_flag
	.section	.debug_info
	.byte		1

	.section	.debug_abbrev
	.uleb128	DW_AT_location
	.uleb128	DW_FORM_block1
	.section	.debug_info
	.byte		5	; length of block
	.byte		DW_OP_addr
	.long		0x800000 + 0x840 + 0x09

	.section	.debug_abbrev
	.uleb128	0
	.uleb128	0

;- - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
	;; DIE #326: variable TCC1_CTRLGCLR
	.section	.debug_info
	.uleb128	326	; ref to abbrev 326
	.section	.debug_abbrev
	.uleb128	326
	.uleb128	DW_TAG_variable
	.byte		DW_CHILDREN_no

	.uleb128	DW_AT_name
	.uleb128	DW_FORM_strp
	.section	.debug_str
.Lname326:
	.string		"TCC1_CTRLGCLR"
	.section	.debug_info
	.long		.Lname326

	.section	.debug_abbrev
	.uleb128	DW_AT_decl_file
	.uleb128	DW_FORM_data1
	.section	.debug_info
	.byte		0	; no source file information

	.section	.debug_abbrev
	.uleb128	DW_AT_decl_line
	.uleb128	DW_FORM_data1
	.section	.debug_info
	.byte		0	; no source line information

	.section	.debug_abbrev
	.uleb128	DW_AT_type
	.uleb128	DW_FORM_ref4
	.section	.debug_info
	.long		.Luint8_t - .Lssinfo

	.section	.debug_abbrev
	.uleb128	DW_AT_external
	.uleb128	DW_FORM_flag
	.section	.debug_info
	.byte		1

	.section	.debug_abbrev
	.uleb128	DW_AT_location
	.uleb128	DW_FORM_block1
	.section	.debug_info
	.byte		5	; length of block
	.byte		DW_OP_addr
	.long		0x800000 + 0x840 + 0x0A

	.section	.debug_abbrev
	.uleb128	0
	.uleb128	0

;- - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
	;; DIE #327: variable TCC1_CTRLGSET
	.section	.debug_info
	.uleb128	327	; ref to abbrev 327
	.section	.debug_abbrev
	.uleb128	327
	.uleb128	DW_TAG_variable
	.byte		DW_CHILDREN_no

	.uleb128	DW_AT_name
	.uleb128	DW_FORM_strp
	.section	.debug_str
.Lname327:
	.string		"TCC1_CTRLGSET"
	.section	.debug_info
	.long		.Lname327

	.section	.debug_abbrev
	.uleb128	DW_AT_decl_file
	.uleb128	DW_FORM_data1
	.section	.debug_info
	.byte		0	; no source file information

	.section	.debug_abbrev
	.uleb128	DW_AT_decl_line
	.uleb128	DW_FORM_data1
	.section	.debug_info
	.byte		0	; no source line information

	.section	.debug_abbrev
	.uleb128	DW_AT_type
	.uleb128	DW_FORM_ref4
	.section	.debug_info
	.long		.Luint8_t - .Lssinfo

	.section	.debug_abbrev
	.uleb128	DW_AT_external
	.uleb128	DW_FORM_flag
	.section	.debug_info
	.byte		1

	.section	.debug_abbrev
	.uleb128	DW_AT_location
	.uleb128	DW_FORM_block1
	.section	.debug_info
	.byte		5	; length of block
	.byte		DW_OP_addr
	.long		0x800000 + 0x840 + 0x0B

	.section	.debug_abbrev
	.uleb128	0
	.uleb128	0

;- - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
	;; DIE #328: variable TCC1_INTFLAGS
	.section	.debug_info
	.uleb128	328	; ref to abbrev 328
	.section	.debug_abbrev
	.uleb128	328
	.uleb128	DW_TAG_variable
	.byte		DW_CHILDREN_no

	.uleb128	DW_AT_name
	.uleb128	DW_FORM_strp
	.section	.debug_str
.Lname328:
	.string		"TCC1_INTFLAGS"
	.section	.debug_info
	.long		.Lname328

	.section	.debug_abbrev
	.uleb128	DW_AT_decl_file
	.uleb128	DW_FORM_data1
	.section	.debug_info
	.byte		0	; no source file information

	.section	.debug_abbrev
	.uleb128	DW_AT_decl_line
	.uleb128	DW_FORM_data1
	.section	.debug_info
	.byte		0	; no source line information

	.section	.debug_abbrev
	.uleb128	DW_AT_type
	.uleb128	DW_FORM_ref4
	.section	.debug_info
	.long		.Luint8_t - .Lssinfo

	.section	.debug_abbrev
	.uleb128	DW_AT_external
	.uleb128	DW_FORM_flag
	.section	.debug_info
	.byte		1

	.section	.debug_abbrev
	.uleb128	DW_AT_location
	.uleb128	DW_FORM_block1
	.section	.debug_info
	.byte		5	; length of block
	.byte		DW_OP_addr
	.long		0x800000 + 0x840 + 0x0C

	.section	.debug_abbrev
	.uleb128	0
	.uleb128	0

;- - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
	;; DIE #329: variable TCC1_TEMP
	.section	.debug_info
	.uleb128	329	; ref to abbrev 329
	.section	.debug_abbrev
	.uleb128	329
	.uleb128	DW_TAG_variable
	.byte		DW_CHILDREN_no

	.uleb128	DW_AT_name
	.uleb128	DW_FORM_strp
	.section	.debug_str
.Lname329:
	.string		"TCC1_TEMP"
	.section	.debug_info
	.long		.Lname329

	.section	.debug_abbrev
	.uleb128	DW_AT_decl_file
	.uleb128	DW_FORM_data1
	.section	.debug_info
	.byte		0	; no source file information

	.section	.debug_abbrev
	.uleb128	DW_AT_decl_line
	.uleb128	DW_FORM_data1
	.section	.debug_info
	.byte		0	; no source line information

	.section	.debug_abbrev
	.uleb128	DW_AT_type
	.uleb128	DW_FORM_ref4
	.section	.debug_info
	.long		.Luint8_t - .Lssinfo

	.section	.debug_abbrev
	.uleb128	DW_AT_external
	.uleb128	DW_FORM_flag
	.section	.debug_info
	.byte		1

	.section	.debug_abbrev
	.uleb128	DW_AT_location
	.uleb128	DW_FORM_block1
	.section	.debug_info
	.byte		5	; length of block
	.byte		DW_OP_addr
	.long		0x800000 + 0x840 + 0x0F

	.section	.debug_abbrev
	.uleb128	0
	.uleb128	0

;- - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
	;; DIE #330: variable TCC1_CNT
	.section	.debug_info
	.uleb128	330	; ref to abbrev 330
	.section	.debug_abbrev
	.uleb128	330
	.uleb128	DW_TAG_variable
	.byte		DW_CHILDREN_no

	.uleb128	DW_AT_name
	.uleb128	DW_FORM_strp
	.section	.debug_str
.Lname330:
	.string		"TCC1_CNT"
	.section	.debug_info
	.long		.Lname330

	.section	.debug_abbrev
	.uleb128	DW_AT_decl_file
	.uleb128	DW_FORM_data1
	.section	.debug_info
	.byte		0	; no source file information

	.section	.debug_abbrev
	.uleb128	DW_AT_decl_line
	.uleb128	DW_FORM_data1
	.section	.debug_info
	.byte		0	; no source line information

	.section	.debug_abbrev
	.uleb128	DW_AT_type
	.uleb128	DW_FORM_ref4
	.section	.debug_info
	.long		.Luint16_t - .Lssinfo

	.section	.debug_abbrev
	.uleb128	DW_AT_external
	.uleb128	DW_FORM_flag
	.section	.debug_info
	.byte		1

	.section	.debug_abbrev
	.uleb128	DW_AT_location
	.uleb128	DW_FORM_block1
	.section	.debug_info
	.byte		5	; length of block
	.byte		DW_OP_addr
	.long		0x800000 + 0x840 + 0x20

	.section	.debug_abbrev
	.uleb128	0
	.uleb128	0

;- - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
	;; DIE #331: variable TCC1_PER
	.section	.debug_info
	.uleb128	331	; ref to abbrev 331
	.section	.debug_abbrev
	.uleb128	331
	.uleb128	DW_TAG_variable
	.byte		DW_CHILDREN_no

	.uleb128	DW_AT_name
	.uleb128	DW_FORM_strp
	.section	.debug_str
.Lname331:
	.string		"TCC1_PER"
	.section	.debug_info
	.long		.Lname331

	.section	.debug_abbrev
	.uleb128	DW_AT_decl_file
	.uleb128	DW_FORM_data1
	.section	.debug_info
	.byte		0	; no source file information

	.section	.debug_abbrev
	.uleb128	DW_AT_decl_line
	.uleb128	DW_FORM_data1
	.section	.debug_info
	.byte		0	; no source line information

	.section	.debug_abbrev
	.uleb128	DW_AT_type
	.uleb128	DW_FORM_ref4
	.section	.debug_info
	.long		.Luint16_t - .Lssinfo

	.section	.debug_abbrev
	.uleb128	DW_AT_external
	.uleb128	DW_FORM_flag
	.section	.debug_info
	.byte		1

	.section	.debug_abbrev
	.uleb128	DW_AT_location
	.uleb128	DW_FORM_block1
	.section	.debug_info
	.byte		5	; length of block
	.byte		DW_OP_addr
	.long		0x800000 + 0x840 + 0x26

	.section	.debug_abbrev
	.uleb128	0
	.uleb128	0

;- - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
	;; DIE #332: variable TCC1_CCA
	.section	.debug_info
	.uleb128	332	; ref to abbrev 332
	.section	.debug_abbrev
	.uleb128	332
	.uleb128	DW_TAG_variable
	.byte		DW_CHILDREN_no

	.uleb128	DW_AT_name
	.uleb128	DW_FORM_strp
	.section	.debug_str
.Lname332:
	.string		"TCC1_CCA"
	.section	.debug_info
	.long		.Lname332

	.section	.debug_abbrev
	.uleb128	DW_AT_decl_file
	.uleb128	DW_FORM_data1
	.section	.debug_info
	.byte		0	; no source file information

	.section	.debug_abbrev
	.uleb128	DW_AT_decl_line
	.uleb128	DW_FORM_data1
	.section	.debug_info
	.byte		0	; no source line information

	.section	.debug_abbrev
	.uleb128	DW_AT_type
	.uleb128	DW_FORM_ref4
	.section	.debug_info
	.long		.Luint16_t - .Lssinfo

	.section	.debug_abbrev
	.uleb128	DW_AT_external
	.uleb128	DW_FORM_flag
	.section	.debug_info
	.byte		1

	.section	.debug_abbrev
	.uleb128	DW_AT_location
	.uleb128	DW_FORM_block1
	.section	.debug_info
	.byte		5	; length of block
	.byte		DW_OP_addr
	.long		0x800000 + 0x840 + 0x28

	.section	.debug_abbrev
	.uleb128	0
	.uleb128	0

;- - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
	;; DIE #333: variable TCC1_CCB
	.section	.debug_info
	.uleb128	333	; ref to abbrev 333
	.section	.debug_abbrev
	.uleb128	333
	.uleb128	DW_TAG_variable
	.byte		DW_CHILDREN_no

	.uleb128	DW_AT_name
	.uleb128	DW_FORM_strp
	.section	.debug_str
.Lname333:
	.string		"TCC1_CCB"
	.section	.debug_info
	.long		.Lname333

	.section	.debug_abbrev
	.uleb128	DW_AT_decl_file
	.uleb128	DW_FORM_data1
	.section	.debug_info
	.byte		0	; no source file information

	.section	.debug_abbrev
	.uleb128	DW_AT_decl_line
	.uleb128	DW_FORM_data1
	.section	.debug_info
	.byte		0	; no source line information

	.section	.debug_abbrev
	.uleb128	DW_AT_type
	.uleb128	DW_FORM_ref4
	.section	.debug_info
	.long		.Luint16_t - .Lssinfo

	.section	.debug_abbrev
	.uleb128	DW_AT_external
	.uleb128	DW_FORM_flag
	.section	.debug_info
	.byte		1

	.section	.debug_abbrev
	.uleb128	DW_AT_location
	.uleb128	DW_FORM_block1
	.section	.debug_info
	.byte		5	; length of block
	.byte		DW_OP_addr
	.long		0x800000 + 0x840 + 0x2A

	.section	.debug_abbrev
	.uleb128	0
	.uleb128	0

;- - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
	;; DIE #334: variable TCC1_PERBUF
	.section	.debug_info
	.uleb128	334	; ref to abbrev 334
	.section	.debug_abbrev
	.uleb128	334
	.uleb128	DW_TAG_variable
	.byte		DW_CHILDREN_no

	.uleb128	DW_AT_name
	.uleb128	DW_FORM_strp
	.section	.debug_str
.Lname334:
	.string		"TCC1_PERBUF"
	.section	.debug_info
	.long		.Lname334

	.section	.debug_abbrev
	.uleb128	DW_AT_decl_file
	.uleb128	DW_FORM_data1
	.section	.debug_info
	.byte		0	; no source file information

	.section	.debug_abbrev
	.uleb128	DW_AT_decl_line
	.uleb128	DW_FORM_data1
	.section	.debug_info
	.byte		0	; no source line information

	.section	.debug_abbrev
	.uleb128	DW_AT_type
	.uleb128	DW_FORM_ref4
	.section	.debug_info
	.long		.Luint16_t - .Lssinfo

	.section	.debug_abbrev
	.uleb128	DW_AT_external
	.uleb128	DW_FORM_flag
	.section	.debug_info
	.byte		1

	.section	.debug_abbrev
	.uleb128	DW_AT_location
	.uleb128	DW_FORM_block1
	.section	.debug_info
	.byte		5	; length of block
	.byte		DW_OP_addr
	.long		0x800000 + 0x840 + 0x36

	.section	.debug_abbrev
	.uleb128	0
	.uleb128	0

;- - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
	;; DIE #335: variable TCC1_CCABUF
	.section	.debug_info
	.uleb128	335	; ref to abbrev 335
	.section	.debug_abbrev
	.uleb128	335
	.uleb128	DW_TAG_variable
	.byte		DW_CHILDREN_no

	.uleb128	DW_AT_name
	.uleb128	DW_FORM_strp
	.section	.debug_str
.Lname335:
	.string		"TCC1_CCABUF"
	.section	.debug_info
	.long		.Lname335

	.section	.debug_abbrev
	.uleb128	DW_AT_decl_file
	.uleb128	DW_FORM_data1
	.section	.debug_info
	.byte		0	; no source file information

	.section	.debug_abbrev
	.uleb128	DW_AT_decl_line
	.uleb128	DW_FORM_data1
	.section	.debug_info
	.byte		0	; no source line information

	.section	.debug_abbrev
	.uleb128	DW_AT_type
	.uleb128	DW_FORM_ref4
	.section	.debug_info
	.long		.Luint16_t - .Lssinfo

	.section	.debug_abbrev
	.uleb128	DW_AT_external
	.uleb128	DW_FORM_flag
	.section	.debug_info
	.byte		1

	.section	.debug_abbrev
	.uleb128	DW_AT_location
	.uleb128	DW_FORM_block1
	.section	.debug_info
	.byte		5	; length of block
	.byte		DW_OP_addr
	.long		0x800000 + 0x840 + 0x38

	.section	.debug_abbrev
	.uleb128	0
	.uleb128	0

;- - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
	;; DIE #336: variable TCC1_CCBBUF
	.section	.debug_info
	.uleb128	336	; ref to abbrev 336
	.section	.debug_abbrev
	.uleb128	336
	.uleb128	DW_TAG_variable
	.byte		DW_CHILDREN_no

	.uleb128	DW_AT_name
	.uleb128	DW_FORM_strp
	.section	.debug_str
.Lname336:
	.string		"TCC1_CCBBUF"
	.section	.debug_info
	.long		.Lname336

	.section	.debug_abbrev
	.uleb128	DW_AT_decl_file
	.uleb128	DW_FORM_data1
	.section	.debug_info
	.byte		0	; no source file information

	.section	.debug_abbrev
	.uleb128	DW_AT_decl_line
	.uleb128	DW_FORM_data1
	.section	.debug_info
	.byte		0	; no source line information

	.section	.debug_abbrev
	.uleb128	DW_AT_type
	.uleb128	DW_FORM_ref4
	.section	.debug_info
	.long		.Luint16_t - .Lssinfo

	.section	.debug_abbrev
	.uleb128	DW_AT_external
	.uleb128	DW_FORM_flag
	.section	.debug_info
	.byte		1

	.section	.debug_abbrev
	.uleb128	DW_AT_location
	.uleb128	DW_FORM_block1
	.section	.debug_info
	.byte		5	; length of block
	.byte		DW_OP_addr
	.long		0x800000 + 0x840 + 0x3A

	.section	.debug_abbrev
	.uleb128	0
	.uleb128	0

;- - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
	;; DIE #337: variable TCD0_CTRLA
	.section	.debug_info
	.uleb128	337	; ref to abbrev 337
	.section	.debug_abbrev
	.uleb128	337
	.uleb128	DW_TAG_variable
	.byte		DW_CHILDREN_no

	.uleb128	DW_AT_name
	.uleb128	DW_FORM_strp
	.section	.debug_str
.Lname337:
	.string		"TCD0_CTRLA"
	.section	.debug_info
	.long		.Lname337

	.section	.debug_abbrev
	.uleb128	DW_AT_decl_file
	.uleb128	DW_FORM_data1
	.section	.debug_info
	.byte		0	; no source file information

	.section	.debug_abbrev
	.uleb128	DW_AT_decl_line
	.uleb128	DW_FORM_data1
	.section	.debug_info
	.byte		0	; no source line information

	.section	.debug_abbrev
	.uleb128	DW_AT_type
	.uleb128	DW_FORM_ref4
	.section	.debug_info
	.long		.Luint8_t - .Lssinfo

	.section	.debug_abbrev
	.uleb128	DW_AT_external
	.uleb128	DW_FORM_flag
	.section	.debug_info
	.byte		1

	.section	.debug_abbrev
	.uleb128	DW_AT_location
	.uleb128	DW_FORM_block1
	.section	.debug_info
	.byte		5	; length of block
	.byte		DW_OP_addr
	.long		0x800000 + 0x900 + 0x00

	.section	.debug_abbrev
	.uleb128	0
	.uleb128	0

;- - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
	;; DIE #338: variable TCD0_CTRLB
	.section	.debug_info
	.uleb128	338	; ref to abbrev 338
	.section	.debug_abbrev
	.uleb128	338
	.uleb128	DW_TAG_variable
	.byte		DW_CHILDREN_no

	.uleb128	DW_AT_name
	.uleb128	DW_FORM_strp
	.section	.debug_str
.Lname338:
	.string		"TCD0_CTRLB"
	.section	.debug_info
	.long		.Lname338

	.section	.debug_abbrev
	.uleb128	DW_AT_decl_file
	.uleb128	DW_FORM_data1
	.section	.debug_info
	.byte		0	; no source file information

	.section	.debug_abbrev
	.uleb128	DW_AT_decl_line
	.uleb128	DW_FORM_data1
	.section	.debug_info
	.byte		0	; no source line information

	.section	.debug_abbrev
	.uleb128	DW_AT_type
	.uleb128	DW_FORM_ref4
	.section	.debug_info
	.long		.Luint8_t - .Lssinfo

	.section	.debug_abbrev
	.uleb128	DW_AT_external
	.uleb128	DW_FORM_flag
	.section	.debug_info
	.byte		1

	.section	.debug_abbrev
	.uleb128	DW_AT_location
	.uleb128	DW_FORM_block1
	.section	.debug_info
	.byte		5	; length of block
	.byte		DW_OP_addr
	.long		0x800000 + 0x900 + 0x01

	.section	.debug_abbrev
	.uleb128	0
	.uleb128	0

;- - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
	;; DIE #339: variable TCD0_CTRLC
	.section	.debug_info
	.uleb128	339	; ref to abbrev 339
	.section	.debug_abbrev
	.uleb128	339
	.uleb128	DW_TAG_variable
	.byte		DW_CHILDREN_no

	.uleb128	DW_AT_name
	.uleb128	DW_FORM_strp
	.section	.debug_str
.Lname339:
	.string		"TCD0_CTRLC"
	.section	.debug_info
	.long		.Lname339

	.section	.debug_abbrev
	.uleb128	DW_AT_decl_file
	.uleb128	DW_FORM_data1
	.section	.debug_info
	.byte		0	; no source file information

	.section	.debug_abbrev
	.uleb128	DW_AT_decl_line
	.uleb128	DW_FORM_data1
	.section	.debug_info
	.byte		0	; no source line information

	.section	.debug_abbrev
	.uleb128	DW_AT_type
	.uleb128	DW_FORM_ref4
	.section	.debug_info
	.long		.Luint8_t - .Lssinfo

	.section	.debug_abbrev
	.uleb128	DW_AT_external
	.uleb128	DW_FORM_flag
	.section	.debug_info
	.byte		1

	.section	.debug_abbrev
	.uleb128	DW_AT_location
	.uleb128	DW_FORM_block1
	.section	.debug_info
	.byte		5	; length of block
	.byte		DW_OP_addr
	.long		0x800000 + 0x900 + 0x02

	.section	.debug_abbrev
	.uleb128	0
	.uleb128	0

;- - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
	;; DIE #340: variable TCD0_CTRLD
	.section	.debug_info
	.uleb128	340	; ref to abbrev 340
	.section	.debug_abbrev
	.uleb128	340
	.uleb128	DW_TAG_variable
	.byte		DW_CHILDREN_no

	.uleb128	DW_AT_name
	.uleb128	DW_FORM_strp
	.section	.debug_str
.Lname340:
	.string		"TCD0_CTRLD"
	.section	.debug_info
	.long		.Lname340

	.section	.debug_abbrev
	.uleb128	DW_AT_decl_file
	.uleb128	DW_FORM_data1
	.section	.debug_info
	.byte		0	; no source file information

	.section	.debug_abbrev
	.uleb128	DW_AT_decl_line
	.uleb128	DW_FORM_data1
	.section	.debug_info
	.byte		0	; no source line information

	.section	.debug_abbrev
	.uleb128	DW_AT_type
	.uleb128	DW_FORM_ref4
	.section	.debug_info
	.long		.Luint8_t - .Lssinfo

	.section	.debug_abbrev
	.uleb128	DW_AT_external
	.uleb128	DW_FORM_flag
	.section	.debug_info
	.byte		1

	.section	.debug_abbrev
	.uleb128	DW_AT_location
	.uleb128	DW_FORM_block1
	.section	.debug_info
	.byte		5	; length of block
	.byte		DW_OP_addr
	.long		0x800000 + 0x900 + 0x03

	.section	.debug_abbrev
	.uleb128	0
	.uleb128	0

;- - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
	;; DIE #341: variable TCD0_CTRLE
	.section	.debug_info
	.uleb128	341	; ref to abbrev 341
	.section	.debug_abbrev
	.uleb128	341
	.uleb128	DW_TAG_variable
	.byte		DW_CHILDREN_no

	.uleb128	DW_AT_name
	.uleb128	DW_FORM_strp
	.section	.debug_str
.Lname341:
	.string		"TCD0_CTRLE"
	.section	.debug_info
	.long		.Lname341

	.section	.debug_abbrev
	.uleb128	DW_AT_decl_file
	.uleb128	DW_FORM_data1
	.section	.debug_info
	.byte		0	; no source file information

	.section	.debug_abbrev
	.uleb128	DW_AT_decl_line
	.uleb128	DW_FORM_data1
	.section	.debug_info
	.byte		0	; no source line information

	.section	.debug_abbrev
	.uleb128	DW_AT_type
	.uleb128	DW_FORM_ref4
	.section	.debug_info
	.long		.Luint8_t - .Lssinfo

	.section	.debug_abbrev
	.uleb128	DW_AT_external
	.uleb128	DW_FORM_flag
	.section	.debug_info
	.byte		1

	.section	.debug_abbrev
	.uleb128	DW_AT_location
	.uleb128	DW_FORM_block1
	.section	.debug_info
	.byte		5	; length of block
	.byte		DW_OP_addr
	.long		0x800000 + 0x900 + 0x04

	.section	.debug_abbrev
	.uleb128	0
	.uleb128	0

;- - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
	;; DIE #342: variable TCD0_INTCTRLA
	.section	.debug_info
	.uleb128	342	; ref to abbrev 342
	.section	.debug_abbrev
	.uleb128	342
	.uleb128	DW_TAG_variable
	.byte		DW_CHILDREN_no

	.uleb128	DW_AT_name
	.uleb128	DW_FORM_strp
	.section	.debug_str
.Lname342:
	.string		"TCD0_INTCTRLA"
	.section	.debug_info
	.long		.Lname342

	.section	.debug_abbrev
	.uleb128	DW_AT_decl_file
	.uleb128	DW_FORM_data1
	.section	.debug_info
	.byte		0	; no source file information

	.section	.debug_abbrev
	.uleb128	DW_AT_decl_line
	.uleb128	DW_FORM_data1
	.section	.debug_info
	.byte		0	; no source line information

	.section	.debug_abbrev
	.uleb128	DW_AT_type
	.uleb128	DW_FORM_ref4
	.section	.debug_info
	.long		.Luint8_t - .Lssinfo

	.section	.debug_abbrev
	.uleb128	DW_AT_external
	.uleb128	DW_FORM_flag
	.section	.debug_info
	.byte		1

	.section	.debug_abbrev
	.uleb128	DW_AT_location
	.uleb128	DW_FORM_block1
	.section	.debug_info
	.byte		5	; length of block
	.byte		DW_OP_addr
	.long		0x800000 + 0x900 + 0x06

	.section	.debug_abbrev
	.uleb128	0
	.uleb128	0

;- - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
	;; DIE #343: variable TCD0_INTCTRLB
	.section	.debug_info
	.uleb128	343	; ref to abbrev 343
	.section	.debug_abbrev
	.uleb128	343
	.uleb128	DW_TAG_variable
	.byte		DW_CHILDREN_no

	.uleb128	DW_AT_name
	.uleb128	DW_FORM_strp
	.section	.debug_str
.Lname343:
	.string		"TCD0_INTCTRLB"
	.section	.debug_info
	.long		.Lname343

	.section	.debug_abbrev
	.uleb128	DW_AT_decl_file
	.uleb128	DW_FORM_data1
	.section	.debug_info
	.byte		0	; no source file information

	.section	.debug_abbrev
	.uleb128	DW_AT_decl_line
	.uleb128	DW_FORM_data1
	.section	.debug_info
	.byte		0	; no source line information

	.section	.debug_abbrev
	.uleb128	DW_AT_type
	.uleb128	DW_FORM_ref4
	.section	.debug_info
	.long		.Luint8_t - .Lssinfo

	.section	.debug_abbrev
	.uleb128	DW_AT_external
	.uleb128	DW_FORM_flag
	.section	.debug_info
	.byte		1

	.section	.debug_abbrev
	.uleb128	DW_AT_location
	.uleb128	DW_FORM_block1
	.section	.debug_info
	.byte		5	; length of block
	.byte		DW_OP_addr
	.long		0x800000 + 0x900 + 0x07

	.section	.debug_abbrev
	.uleb128	0
	.uleb128	0

;- - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
	;; DIE #344: variable TCD0_CTRLFCLR
	.section	.debug_info
	.uleb128	344	; ref to abbrev 344
	.section	.debug_abbrev
	.uleb128	344
	.uleb128	DW_TAG_variable
	.byte		DW_CHILDREN_no

	.uleb128	DW_AT_name
	.uleb128	DW_FORM_strp
	.section	.debug_str
.Lname344:
	.string		"TCD0_CTRLFCLR"
	.section	.debug_info
	.long		.Lname344

	.section	.debug_abbrev
	.uleb128	DW_AT_decl_file
	.uleb128	DW_FORM_data1
	.section	.debug_info
	.byte		0	; no source file information

	.section	.debug_abbrev
	.uleb128	DW_AT_decl_line
	.uleb128	DW_FORM_data1
	.section	.debug_info
	.byte		0	; no source line information

	.section	.debug_abbrev
	.uleb128	DW_AT_type
	.uleb128	DW_FORM_ref4
	.section	.debug_info
	.long		.Luint8_t - .Lssinfo

	.section	.debug_abbrev
	.uleb128	DW_AT_external
	.uleb128	DW_FORM_flag
	.section	.debug_info
	.byte		1

	.section	.debug_abbrev
	.uleb128	DW_AT_location
	.uleb128	DW_FORM_block1
	.section	.debug_info
	.byte		5	; length of block
	.byte		DW_OP_addr
	.long		0x800000 + 0x900 + 0x08

	.section	.debug_abbrev
	.uleb128	0
	.uleb128	0

;- - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
	;; DIE #345: variable TCD0_CTRLFSET
	.section	.debug_info
	.uleb128	345	; ref to abbrev 345
	.section	.debug_abbrev
	.uleb128	345
	.uleb128	DW_TAG_variable
	.byte		DW_CHILDREN_no

	.uleb128	DW_AT_name
	.uleb128	DW_FORM_strp
	.section	.debug_str
.Lname345:
	.string		"TCD0_CTRLFSET"
	.section	.debug_info
	.long		.Lname345

	.section	.debug_abbrev
	.uleb128	DW_AT_decl_file
	.uleb128	DW_FORM_data1
	.section	.debug_info
	.byte		0	; no source file information

	.section	.debug_abbrev
	.uleb128	DW_AT_decl_line
	.uleb128	DW_FORM_data1
	.section	.debug_info
	.byte		0	; no source line information

	.section	.debug_abbrev
	.uleb128	DW_AT_type
	.uleb128	DW_FORM_ref4
	.section	.debug_info
	.long		.Luint8_t - .Lssinfo

	.section	.debug_abbrev
	.uleb128	DW_AT_external
	.uleb128	DW_FORM_flag
	.section	.debug_info
	.byte		1

	.section	.debug_abbrev
	.uleb128	DW_AT_location
	.uleb128	DW_FORM_block1
	.section	.debug_info
	.byte		5	; length of block
	.byte		DW_OP_addr
	.long		0x800000 + 0x900 + 0x09

	.section	.debug_abbrev
	.uleb128	0
	.uleb128	0

;- - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
	;; DIE #346: variable TCD0_CTRLGCLR
	.section	.debug_info
	.uleb128	346	; ref to abbrev 346
	.section	.debug_abbrev
	.uleb128	346
	.uleb128	DW_TAG_variable
	.byte		DW_CHILDREN_no

	.uleb128	DW_AT_name
	.uleb128	DW_FORM_strp
	.section	.debug_str
.Lname346:
	.string		"TCD0_CTRLGCLR"
	.section	.debug_info
	.long		.Lname346

	.section	.debug_abbrev
	.uleb128	DW_AT_decl_file
	.uleb128	DW_FORM_data1
	.section	.debug_info
	.byte		0	; no source file information

	.section	.debug_abbrev
	.uleb128	DW_AT_decl_line
	.uleb128	DW_FORM_data1
	.section	.debug_info
	.byte		0	; no source line information

	.section	.debug_abbrev
	.uleb128	DW_AT_type
	.uleb128	DW_FORM_ref4
	.section	.debug_info
	.long		.Luint8_t - .Lssinfo

	.section	.debug_abbrev
	.uleb128	DW_AT_external
	.uleb128	DW_FORM_flag
	.section	.debug_info
	.byte		1

	.section	.debug_abbrev
	.uleb128	DW_AT_location
	.uleb128	DW_FORM_block1
	.section	.debug_info
	.byte		5	; length of block
	.byte		DW_OP_addr
	.long		0x800000 + 0x900 + 0x0A

	.section	.debug_abbrev
	.uleb128	0
	.uleb128	0

;- - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
	;; DIE #347: variable TCD0_CTRLGSET
	.section	.debug_info
	.uleb128	347	; ref to abbrev 347
	.section	.debug_abbrev
	.uleb128	347
	.uleb128	DW_TAG_variable
	.byte		DW_CHILDREN_no

	.uleb128	DW_AT_name
	.uleb128	DW_FORM_strp
	.section	.debug_str
.Lname347:
	.string		"TCD0_CTRLGSET"
	.section	.debug_info
	.long		.Lname347

	.section	.debug_abbrev
	.uleb128	DW_AT_decl_file
	.uleb128	DW_FORM_data1
	.section	.debug_info
	.byte		0	; no source file information

	.section	.debug_abbrev
	.uleb128	DW_AT_decl_line
	.uleb128	DW_FORM_data1
	.section	.debug_info
	.byte		0	; no source line information

	.section	.debug_abbrev
	.uleb128	DW_AT_type
	.uleb128	DW_FORM_ref4
	.section	.debug_info
	.long		.Luint8_t - .Lssinfo

	.section	.debug_abbrev
	.uleb128	DW_AT_external
	.uleb128	DW_FORM_flag
	.section	.debug_info
	.byte		1

	.section	.debug_abbrev
	.uleb128	DW_AT_location
	.uleb128	DW_FORM_block1
	.section	.debug_info
	.byte		5	; length of block
	.byte		DW_OP_addr
	.long		0x800000 + 0x900 + 0x0B

	.section	.debug_abbrev
	.uleb128	0
	.uleb128	0

;- - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
	;; DIE #348: variable TCD0_INTFLAGS
	.section	.debug_info
	.uleb128	348	; ref to abbrev 348
	.section	.debug_abbrev
	.uleb128	348
	.uleb128	DW_TAG_variable
	.byte		DW_CHILDREN_no

	.uleb128	DW_AT_name
	.uleb128	DW_FORM_strp
	.section	.debug_str
.Lname348:
	.string		"TCD0_INTFLAGS"
	.section	.debug_info
	.long		.Lname348

	.section	.debug_abbrev
	.uleb128	DW_AT_decl_file
	.uleb128	DW_FORM_data1
	.section	.debug_info
	.byte		0	; no source file information

	.section	.debug_abbrev
	.uleb128	DW_AT_decl_line
	.uleb128	DW_FORM_data1
	.section	.debug_info
	.byte		0	; no source line information

	.section	.debug_abbrev
	.uleb128	DW_AT_type
	.uleb128	DW_FORM_ref4
	.section	.debug_info
	.long		.Luint8_t - .Lssinfo

	.section	.debug_abbrev
	.uleb128	DW_AT_external
	.uleb128	DW_FORM_flag
	.section	.debug_info
	.byte		1

	.section	.debug_abbrev
	.uleb128	DW_AT_location
	.uleb128	DW_FORM_block1
	.section	.debug_info
	.byte		5	; length of block
	.byte		DW_OP_addr
	.long		0x800000 + 0x900 + 0x0C

	.section	.debug_abbrev
	.uleb128	0
	.uleb128	0

;- - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
	;; DIE #349: variable TCD0_TEMP
	.section	.debug_info
	.uleb128	349	; ref to abbrev 349
	.section	.debug_abbrev
	.uleb128	349
	.uleb128	DW_TAG_variable
	.byte		DW_CHILDREN_no

	.uleb128	DW_AT_name
	.uleb128	DW_FORM_strp
	.section	.debug_str
.Lname349:
	.string		"TCD0_TEMP"
	.section	.debug_info
	.long		.Lname349

	.section	.debug_abbrev
	.uleb128	DW_AT_decl_file
	.uleb128	DW_FORM_data1
	.section	.debug_info
	.byte		0	; no source file information

	.section	.debug_abbrev
	.uleb128	DW_AT_decl_line
	.uleb128	DW_FORM_data1
	.section	.debug_info
	.byte		0	; no source line information

	.section	.debug_abbrev
	.uleb128	DW_AT_type
	.uleb128	DW_FORM_ref4
	.section	.debug_info
	.long		.Luint8_t - .Lssinfo

	.section	.debug_abbrev
	.uleb128	DW_AT_external
	.uleb128	DW_FORM_flag
	.section	.debug_info
	.byte		1

	.section	.debug_abbrev
	.uleb128	DW_AT_location
	.uleb128	DW_FORM_block1
	.section	.debug_info
	.byte		5	; length of block
	.byte		DW_OP_addr
	.long		0x800000 + 0x900 + 0x0F

	.section	.debug_abbrev
	.uleb128	0
	.uleb128	0

;- - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
	;; DIE #350: variable TCD0_CNT
	.section	.debug_info
	.uleb128	350	; ref to abbrev 350
	.section	.debug_abbrev
	.uleb128	350
	.uleb128	DW_TAG_variable
	.byte		DW_CHILDREN_no

	.uleb128	DW_AT_name
	.uleb128	DW_FORM_strp
	.section	.debug_str
.Lname350:
	.string		"TCD0_CNT"
	.section	.debug_info
	.long		.Lname350

	.section	.debug_abbrev
	.uleb128	DW_AT_decl_file
	.uleb128	DW_FORM_data1
	.section	.debug_info
	.byte		0	; no source file information

	.section	.debug_abbrev
	.uleb128	DW_AT_decl_line
	.uleb128	DW_FORM_data1
	.section	.debug_info
	.byte		0	; no source line information

	.section	.debug_abbrev
	.uleb128	DW_AT_type
	.uleb128	DW_FORM_ref4
	.section	.debug_info
	.long		.Luint16_t - .Lssinfo

	.section	.debug_abbrev
	.uleb128	DW_AT_external
	.uleb128	DW_FORM_flag
	.section	.debug_info
	.byte		1

	.section	.debug_abbrev
	.uleb128	DW_AT_location
	.uleb128	DW_FORM_block1
	.section	.debug_info
	.byte		5	; length of block
	.byte		DW_OP_addr
	.long		0x800000 + 0x900 + 0x20

	.section	.debug_abbrev
	.uleb128	0
	.uleb128	0

;- - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
	;; DIE #351: variable TCD0_PER
	.section	.debug_info
	.uleb128	351	; ref to abbrev 351
	.section	.debug_abbrev
	.uleb128	351
	.uleb128	DW_TAG_variable
	.byte		DW_CHILDREN_no

	.uleb128	DW_AT_name
	.uleb128	DW_FORM_strp
	.section	.debug_str
.Lname351:
	.string		"TCD0_PER"
	.section	.debug_info
	.long		.Lname351

	.section	.debug_abbrev
	.uleb128	DW_AT_decl_file
	.uleb128	DW_FORM_data1
	.section	.debug_info
	.byte		0	; no source file information

	.section	.debug_abbrev
	.uleb128	DW_AT_decl_line
	.uleb128	DW_FORM_data1
	.section	.debug_info
	.byte		0	; no source line information

	.section	.debug_abbrev
	.uleb128	DW_AT_type
	.uleb128	DW_FORM_ref4
	.section	.debug_info
	.long		.Luint16_t - .Lssinfo

	.section	.debug_abbrev
	.uleb128	DW_AT_external
	.uleb128	DW_FORM_flag
	.section	.debug_info
	.byte		1

	.section	.debug_abbrev
	.uleb128	DW_AT_location
	.uleb128	DW_FORM_block1
	.section	.debug_info
	.byte		5	; length of block
	.byte		DW_OP_addr
	.long		0x800000 + 0x900 + 0x26

	.section	.debug_abbrev
	.uleb128	0
	.uleb128	0

;- - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
	;; DIE #352: variable TCD0_CCA
	.section	.debug_info
	.uleb128	352	; ref to abbrev 352
	.section	.debug_abbrev
	.uleb128	352
	.uleb128	DW_TAG_variable
	.byte		DW_CHILDREN_no

	.uleb128	DW_AT_name
	.uleb128	DW_FORM_strp
	.section	.debug_str
.Lname352:
	.string		"TCD0_CCA"
	.section	.debug_info
	.long		.Lname352

	.section	.debug_abbrev
	.uleb128	DW_AT_decl_file
	.uleb128	DW_FORM_data1
	.section	.debug_info
	.byte		0	; no source file information

	.section	.debug_abbrev
	.uleb128	DW_AT_decl_line
	.uleb128	DW_FORM_data1
	.section	.debug_info
	.byte		0	; no source line information

	.section	.debug_abbrev
	.uleb128	DW_AT_type
	.uleb128	DW_FORM_ref4
	.section	.debug_info
	.long		.Luint16_t - .Lssinfo

	.section	.debug_abbrev
	.uleb128	DW_AT_external
	.uleb128	DW_FORM_flag
	.section	.debug_info
	.byte		1

	.section	.debug_abbrev
	.uleb128	DW_AT_location
	.uleb128	DW_FORM_block1
	.section	.debug_info
	.byte		5	; length of block
	.byte		DW_OP_addr
	.long		0x800000 + 0x900 + 0x28

	.section	.debug_abbrev
	.uleb128	0
	.uleb128	0

;- - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
	;; DIE #353: variable TCD0_CCB
	.section	.debug_info
	.uleb128	353	; ref to abbrev 353
	.section	.debug_abbrev
	.uleb128	353
	.uleb128	DW_TAG_variable
	.byte		DW_CHILDREN_no

	.uleb128	DW_AT_name
	.uleb128	DW_FORM_strp
	.section	.debug_str
.Lname353:
	.string		"TCD0_CCB"
	.section	.debug_info
	.long		.Lname353

	.section	.debug_abbrev
	.uleb128	DW_AT_decl_file
	.uleb128	DW_FORM_data1
	.section	.debug_info
	.byte		0	; no source file information

	.section	.debug_abbrev
	.uleb128	DW_AT_decl_line
	.uleb128	DW_FORM_data1
	.section	.debug_info
	.byte		0	; no source line information

	.section	.debug_abbrev
	.uleb128	DW_AT_type
	.uleb128	DW_FORM_ref4
	.section	.debug_info
	.long		.Luint16_t - .Lssinfo

	.section	.debug_abbrev
	.uleb128	DW_AT_external
	.uleb128	DW_FORM_flag
	.section	.debug_info
	.byte		1

	.section	.debug_abbrev
	.uleb128	DW_AT_location
	.uleb128	DW_FORM_block1
	.section	.debug_info
	.byte		5	; length of block
	.byte		DW_OP_addr
	.long		0x800000 + 0x900 + 0x2A

	.section	.debug_abbrev
	.uleb128	0
	.uleb128	0

;- - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
	;; DIE #354: variable TCD0_CCC
	.section	.debug_info
	.uleb128	354	; ref to abbrev 354
	.section	.debug_abbrev
	.uleb128	354
	.uleb128	DW_TAG_variable
	.byte		DW_CHILDREN_no

	.uleb128	DW_AT_name
	.uleb128	DW_FORM_strp
	.section	.debug_str
.Lname354:
	.string		"TCD0_CCC"
	.section	.debug_info
	.long		.Lname354

	.section	.debug_abbrev
	.uleb128	DW_AT_decl_file
	.uleb128	DW_FORM_data1
	.section	.debug_info
	.byte		0	; no source file information

	.section	.debug_abbrev
	.uleb128	DW_AT_decl_line
	.uleb128	DW_FORM_data1
	.section	.debug_info
	.byte		0	; no source line information

	.section	.debug_abbrev
	.uleb128	DW_AT_type
	.uleb128	DW_FORM_ref4
	.section	.debug_info
	.long		.Luint16_t - .Lssinfo

	.section	.debug_abbrev
	.uleb128	DW_AT_external
	.uleb128	DW_FORM_flag
	.section	.debug_info
	.byte		1

	.section	.debug_abbrev
	.uleb128	DW_AT_location
	.uleb128	DW_FORM_block1
	.section	.debug_info
	.byte		5	; length of block
	.byte		DW_OP_addr
	.long		0x800000 + 0x900 + 0x2C

	.section	.debug_abbrev
	.uleb128	0
	.uleb128	0

;- - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
	;; DIE #355: variable TCD0_CCD
	.section	.debug_info
	.uleb128	355	; ref to abbrev 355
	.section	.debug_abbrev
	.uleb128	355
	.uleb128	DW_TAG_variable
	.byte		DW_CHILDREN_no

	.uleb128	DW_AT_name
	.uleb128	DW_FORM_strp
	.section	.debug_str
.Lname355:
	.string		"TCD0_CCD"
	.section	.debug_info
	.long		.Lname355

	.section	.debug_abbrev
	.uleb128	DW_AT_decl_file
	.uleb128	DW_FORM_data1
	.section	.debug_info
	.byte		0	; no source file information

	.section	.debug_abbrev
	.uleb128	DW_AT_decl_line
	.uleb128	DW_FORM_data1
	.section	.debug_info
	.byte		0	; no source line information

	.section	.debug_abbrev
	.uleb128	DW_AT_type
	.uleb128	DW_FORM_ref4
	.section	.debug_info
	.long		.Luint16_t - .Lssinfo

	.section	.debug_abbrev
	.uleb128	DW_AT_external
	.uleb128	DW_FORM_flag
	.section	.debug_info
	.byte		1

	.section	.debug_abbrev
	.uleb128	DW_AT_location
	.uleb128	DW_FORM_block1
	.section	.debug_info
	.byte		5	; length of block
	.byte		DW_OP_addr
	.long		0x800000 + 0x900 + 0x2E

	.section	.debug_abbrev
	.uleb128	0
	.uleb128	0

;- - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
	;; DIE #356: variable TCD0_PERBUF
	.section	.debug_info
	.uleb128	356	; ref to abbrev 356
	.section	.debug_abbrev
	.uleb128	356
	.uleb128	DW_TAG_variable
	.byte		DW_CHILDREN_no

	.uleb128	DW_AT_name
	.uleb128	DW_FORM_strp
	.section	.debug_str
.Lname356:
	.string		"TCD0_PERBUF"
	.section	.debug_info
	.long		.Lname356

	.section	.debug_abbrev
	.uleb128	DW_AT_decl_file
	.uleb128	DW_FORM_data1
	.section	.debug_info
	.byte		0	; no source file information

	.section	.debug_abbrev
	.uleb128	DW_AT_decl_line
	.uleb128	DW_FORM_data1
	.section	.debug_info
	.byte		0	; no source line information

	.section	.debug_abbrev
	.uleb128	DW_AT_type
	.uleb128	DW_FORM_ref4
	.section	.debug_info
	.long		.Luint16_t - .Lssinfo

	.section	.debug_abbrev
	.uleb128	DW_AT_external
	.uleb128	DW_FORM_flag
	.section	.debug_info
	.byte		1

	.section	.debug_abbrev
	.uleb128	DW_AT_location
	.uleb128	DW_FORM_block1
	.section	.debug_info
	.byte		5	; length of block
	.byte		DW_OP_addr
	.long		0x800000 + 0x900 + 0x36

	.section	.debug_abbrev
	.uleb128	0
	.uleb128	0

;- - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
	;; DIE #357: variable TCD0_CCABUF
	.section	.debug_info
	.uleb128	357	; ref to abbrev 357
	.section	.debug_abbrev
	.uleb128	357
	.uleb128	DW_TAG_variable
	.byte		DW_CHILDREN_no

	.uleb128	DW_AT_name
	.uleb128	DW_FORM_strp
	.section	.debug_str
.Lname357:
	.string		"TCD0_CCABUF"
	.section	.debug_info
	.long		.Lname357

	.section	.debug_abbrev
	.uleb128	DW_AT_decl_file
	.uleb128	DW_FORM_data1
	.section	.debug_info
	.byte		0	; no source file information

	.section	.debug_abbrev
	.uleb128	DW_AT_decl_line
	.uleb128	DW_FORM_data1
	.section	.debug_info
	.byte		0	; no source line information

	.section	.debug_abbrev
	.uleb128	DW_AT_type
	.uleb128	DW_FORM_ref4
	.section	.debug_info
	.long		.Luint16_t - .Lssinfo

	.section	.debug_abbrev
	.uleb128	DW_AT_external
	.uleb128	DW_FORM_flag
	.section	.debug_info
	.byte		1

	.section	.debug_abbrev
	.uleb128	DW_AT_location
	.uleb128	DW_FORM_block1
	.section	.debug_info
	.byte		5	; length of block
	.byte		DW_OP_addr
	.long		0x800000 + 0x900 + 0x38

	.section	.debug_abbrev
	.uleb128	0
	.uleb128	0

;- - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
	;; DIE #358: variable TCD0_CCBBUF
	.section	.debug_info
	.uleb128	358	; ref to abbrev 358
	.section	.debug_abbrev
	.uleb128	358
	.uleb128	DW_TAG_variable
	.byte		DW_CHILDREN_no

	.uleb128	DW_AT_name
	.uleb128	DW_FORM_strp
	.section	.debug_str
.Lname358:
	.string		"TCD0_CCBBUF"
	.section	.debug_info
	.long		.Lname358

	.section	.debug_abbrev
	.uleb128	DW_AT_decl_file
	.uleb128	DW_FORM_data1
	.section	.debug_info
	.byte		0	; no source file information

	.section	.debug_abbrev
	.uleb128	DW_AT_decl_line
	.uleb128	DW_FORM_data1
	.section	.debug_info
	.byte		0	; no source line information

	.section	.debug_abbrev
	.uleb128	DW_AT_type
	.uleb128	DW_FORM_ref4
	.section	.debug_info
	.long		.Luint16_t - .Lssinfo

	.section	.debug_abbrev
	.uleb128	DW_AT_external
	.uleb128	DW_FORM_flag
	.section	.debug_info
	.byte		1

	.section	.debug_abbrev
	.uleb128	DW_AT_location
	.uleb128	DW_FORM_block1
	.section	.debug_info
	.byte		5	; length of block
	.byte		DW_OP_addr
	.long		0x800000 + 0x900 + 0x3A

	.section	.debug_abbrev
	.uleb128	0
	.uleb128	0

;- - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
	;; DIE #359: variable TCD0_CCCBUF
	.section	.debug_info
	.uleb128	359	; ref to abbrev 359
	.section	.debug_abbrev
	.uleb128	359
	.uleb128	DW_TAG_variable
	.byte		DW_CHILDREN_no

	.uleb128	DW_AT_name
	.uleb128	DW_FORM_strp
	.section	.debug_str
.Lname359:
	.string		"TCD0_CCCBUF"
	.section	.debug_info
	.long		.Lname359

	.section	.debug_abbrev
	.uleb128	DW_AT_decl_file
	.uleb128	DW_FORM_data1
	.section	.debug_info
	.byte		0	; no source file information

	.section	.debug_abbrev
	.uleb128	DW_AT_decl_line
	.uleb128	DW_FORM_data1
	.section	.debug_info
	.byte		0	; no source line information

	.section	.debug_abbrev
	.uleb128	DW_AT_type
	.uleb128	DW_FORM_ref4
	.section	.debug_info
	.long		.Luint16_t - .Lssinfo

	.section	.debug_abbrev
	.uleb128	DW_AT_external
	.uleb128	DW_FORM_flag
	.section	.debug_info
	.byte		1

	.section	.debug_abbrev
	.uleb128	DW_AT_location
	.uleb128	DW_FORM_block1
	.section	.debug_info
	.byte		5	; length of block
	.byte		DW_OP_addr
	.long		0x800000 + 0x900 + 0x3C

	.section	.debug_abbrev
	.uleb128	0
	.uleb128	0

;- - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
	;; DIE #360: variable TCD0_CCDBUF
	.section	.debug_info
	.uleb128	360	; ref to abbrev 360
	.section	.debug_abbrev
	.uleb128	360
	.uleb128	DW_TAG_variable
	.byte		DW_CHILDREN_no

	.uleb128	DW_AT_name
	.uleb128	DW_FORM_strp
	.section	.debug_str
.Lname360:
	.string		"TCD0_CCDBUF"
	.section	.debug_info
	.long		.Lname360

	.section	.debug_abbrev
	.uleb128	DW_AT_decl_file
	.uleb128	DW_FORM_data1
	.section	.debug_info
	.byte		0	; no source file information

	.section	.debug_abbrev
	.uleb128	DW_AT_decl_line
	.uleb128	DW_FORM_data1
	.section	.debug_info
	.byte		0	; no source line information

	.section	.debug_abbrev
	.uleb128	DW_AT_type
	.uleb128	DW_FORM_ref4
	.section	.debug_info
	.long		.Luint16_t - .Lssinfo

	.section	.debug_abbrev
	.uleb128	DW_AT_external
	.uleb128	DW_FORM_flag
	.section	.debug_info
	.byte		1

	.section	.debug_abbrev
	.uleb128	DW_AT_location
	.uleb128	DW_FORM_block1
	.section	.debug_info
	.byte		5	; length of block
	.byte		DW_OP_addr
	.long		0x800000 + 0x900 + 0x3E

	.section	.debug_abbrev
	.uleb128	0
	.uleb128	0

;- - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
	;; DIE #361: variable TCE0_CTRLA
	.section	.debug_info
	.uleb128	361	; ref to abbrev 361
	.section	.debug_abbrev
	.uleb128	361
	.uleb128	DW_TAG_variable
	.byte		DW_CHILDREN_no

	.uleb128	DW_AT_name
	.uleb128	DW_FORM_strp
	.section	.debug_str
.Lname361:
	.string		"TCE0_CTRLA"
	.section	.debug_info
	.long		.Lname361

	.section	.debug_abbrev
	.uleb128	DW_AT_decl_file
	.uleb128	DW_FORM_data1
	.section	.debug_info
	.byte		0	; no source file information

	.section	.debug_abbrev
	.uleb128	DW_AT_decl_line
	.uleb128	DW_FORM_data1
	.section	.debug_info
	.byte		0	; no source line information

	.section	.debug_abbrev
	.uleb128	DW_AT_type
	.uleb128	DW_FORM_ref4
	.section	.debug_info
	.long		.Luint8_t - .Lssinfo

	.section	.debug_abbrev
	.uleb128	DW_AT_external
	.uleb128	DW_FORM_flag
	.section	.debug_info
	.byte		1

	.section	.debug_abbrev
	.uleb128	DW_AT_location
	.uleb128	DW_FORM_block1
	.section	.debug_info
	.byte		5	; length of block
	.byte		DW_OP_addr
	.long		0x800000 + 0xA00 + 0x00

	.section	.debug_abbrev
	.uleb128	0
	.uleb128	0

;- - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
	;; DIE #362: variable TCE0_CTRLB
	.section	.debug_info
	.uleb128	362	; ref to abbrev 362
	.section	.debug_abbrev
	.uleb128	362
	.uleb128	DW_TAG_variable
	.byte		DW_CHILDREN_no

	.uleb128	DW_AT_name
	.uleb128	DW_FORM_strp
	.section	.debug_str
.Lname362:
	.string		"TCE0_CTRLB"
	.section	.debug_info
	.long		.Lname362

	.section	.debug_abbrev
	.uleb128	DW_AT_decl_file
	.uleb128	DW_FORM_data1
	.section	.debug_info
	.byte		0	; no source file information

	.section	.debug_abbrev
	.uleb128	DW_AT_decl_line
	.uleb128	DW_FORM_data1
	.section	.debug_info
	.byte		0	; no source line information

	.section	.debug_abbrev
	.uleb128	DW_AT_type
	.uleb128	DW_FORM_ref4
	.section	.debug_info
	.long		.Luint8_t - .Lssinfo

	.section	.debug_abbrev
	.uleb128	DW_AT_external
	.uleb128	DW_FORM_flag
	.section	.debug_info
	.byte		1

	.section	.debug_abbrev
	.uleb128	DW_AT_location
	.uleb128	DW_FORM_block1
	.section	.debug_info
	.byte		5	; length of block
	.byte		DW_OP_addr
	.long		0x800000 + 0xA00 + 0x01

	.section	.debug_abbrev
	.uleb128	0
	.uleb128	0

;- - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
	;; DIE #363: variable TCE0_CTRLC
	.section	.debug_info
	.uleb128	363	; ref to abbrev 363
	.section	.debug_abbrev
	.uleb128	363
	.uleb128	DW_TAG_variable
	.byte		DW_CHILDREN_no

	.uleb128	DW_AT_name
	.uleb128	DW_FORM_strp
	.section	.debug_str
.Lname363:
	.string		"TCE0_CTRLC"
	.section	.debug_info
	.long		.Lname363

	.section	.debug_abbrev
	.uleb128	DW_AT_decl_file
	.uleb128	DW_FORM_data1
	.section	.debug_info
	.byte		0	; no source file information

	.section	.debug_abbrev
	.uleb128	DW_AT_decl_line
	.uleb128	DW_FORM_data1
	.section	.debug_info
	.byte		0	; no source line information

	.section	.debug_abbrev
	.uleb128	DW_AT_type
	.uleb128	DW_FORM_ref4
	.section	.debug_info
	.long		.Luint8_t - .Lssinfo

	.section	.debug_abbrev
	.uleb128	DW_AT_external
	.uleb128	DW_FORM_flag
	.section	.debug_info
	.byte		1

	.section	.debug_abbrev
	.uleb128	DW_AT_location
	.uleb128	DW_FORM_block1
	.section	.debug_info
	.byte		5	; length of block
	.byte		DW_OP_addr
	.long		0x800000 + 0xA00 + 0x02

	.section	.debug_abbrev
	.uleb128	0
	.uleb128	0

;- - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
	;; DIE #364: variable TCE0_CTRLD
	.section	.debug_info
	.uleb128	364	; ref to abbrev 364
	.section	.debug_abbrev
	.uleb128	364
	.uleb128	DW_TAG_variable
	.byte		DW_CHILDREN_no

	.uleb128	DW_AT_name
	.uleb128	DW_FORM_strp
	.section	.debug_str
.Lname364:
	.string		"TCE0_CTRLD"
	.section	.debug_info
	.long		.Lname364

	.section	.debug_abbrev
	.uleb128	DW_AT_decl_file
	.uleb128	DW_FORM_data1
	.section	.debug_info
	.byte		0	; no source file information

	.section	.debug_abbrev
	.uleb128	DW_AT_decl_line
	.uleb128	DW_FORM_data1
	.section	.debug_info
	.byte		0	; no source line information

	.section	.debug_abbrev
	.uleb128	DW_AT_type
	.uleb128	DW_FORM_ref4
	.section	.debug_info
	.long		.Luint8_t - .Lssinfo

	.section	.debug_abbrev
	.uleb128	DW_AT_external
	.uleb128	DW_FORM_flag
	.section	.debug_info
	.byte		1

	.section	.debug_abbrev
	.uleb128	DW_AT_location
	.uleb128	DW_FORM_block1
	.section	.debug_info
	.byte		5	; length of block
	.byte		DW_OP_addr
	.long		0x800000 + 0xA00 + 0x03

	.section	.debug_abbrev
	.uleb128	0
	.uleb128	0

;- - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
	;; DIE #365: variable TCE0_CTRLE
	.section	.debug_info
	.uleb128	365	; ref to abbrev 365
	.section	.debug_abbrev
	.uleb128	365
	.uleb128	DW_TAG_variable
	.byte		DW_CHILDREN_no

	.uleb128	DW_AT_name
	.uleb128	DW_FORM_strp
	.section	.debug_str
.Lname365:
	.string		"TCE0_CTRLE"
	.section	.debug_info
	.long		.Lname365

	.section	.debug_abbrev
	.uleb128	DW_AT_decl_file
	.uleb128	DW_FORM_data1
	.section	.debug_info
	.byte		0	; no source file information

	.section	.debug_abbrev
	.uleb128	DW_AT_decl_line
	.uleb128	DW_FORM_data1
	.section	.debug_info
	.byte		0	; no source line information

	.section	.debug_abbrev
	.uleb128	DW_AT_type
	.uleb128	DW_FORM_ref4
	.section	.debug_info
	.long		.Luint8_t - .Lssinfo

	.section	.debug_abbrev
	.uleb128	DW_AT_external
	.uleb128	DW_FORM_flag
	.section	.debug_info
	.byte		1

	.section	.debug_abbrev
	.uleb128	DW_AT_location
	.uleb128	DW_FORM_block1
	.section	.debug_info
	.byte		5	; length of block
	.byte		DW_OP_addr
	.long		0x800000 + 0xA00 + 0x04

	.section	.debug_abbrev
	.uleb128	0
	.uleb128	0

;- - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
	;; DIE #366: variable TCE0_INTCTRLA
	.section	.debug_info
	.uleb128	366	; ref to abbrev 366
	.section	.debug_abbrev
	.uleb128	366
	.uleb128	DW_TAG_variable
	.byte		DW_CHILDREN_no

	.uleb128	DW_AT_name
	.uleb128	DW_FORM_strp
	.section	.debug_str
.Lname366:
	.string		"TCE0_INTCTRLA"
	.section	.debug_info
	.long		.Lname366

	.section	.debug_abbrev
	.uleb128	DW_AT_decl_file
	.uleb128	DW_FORM_data1
	.section	.debug_info
	.byte		0	; no source file information

	.section	.debug_abbrev
	.uleb128	DW_AT_decl_line
	.uleb128	DW_FORM_data1
	.section	.debug_info
	.byte		0	; no source line information

	.section	.debug_abbrev
	.uleb128	DW_AT_type
	.uleb128	DW_FORM_ref4
	.section	.debug_info
	.long		.Luint8_t - .Lssinfo

	.section	.debug_abbrev
	.uleb128	DW_AT_external
	.uleb128	DW_FORM_flag
	.section	.debug_info
	.byte		1

	.section	.debug_abbrev
	.uleb128	DW_AT_location
	.uleb128	DW_FORM_block1
	.section	.debug_info
	.byte		5	; length of block
	.byte		DW_OP_addr
	.long		0x800000 + 0xA00 + 0x06

	.section	.debug_abbrev
	.uleb128	0
	.uleb128	0

;- - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
	;; DIE #367: variable TCE0_INTCTRLB
	.section	.debug_info
	.uleb128	367	; ref to abbrev 367
	.section	.debug_abbrev
	.uleb128	367
	.uleb128	DW_TAG_variable
	.byte		DW_CHILDREN_no

	.uleb128	DW_AT_name
	.uleb128	DW_FORM_strp
	.section	.debug_str
.Lname367:
	.string		"TCE0_INTCTRLB"
	.section	.debug_info
	.long		.Lname367

	.section	.debug_abbrev
	.uleb128	DW_AT_decl_file
	.uleb128	DW_FORM_data1
	.section	.debug_info
	.byte		0	; no source file information

	.section	.debug_abbrev
	.uleb128	DW_AT_decl_line
	.uleb128	DW_FORM_data1
	.section	.debug_info
	.byte		0	; no source line information

	.section	.debug_abbrev
	.uleb128	DW_AT_type
	.uleb128	DW_FORM_ref4
	.section	.debug_info
	.long		.Luint8_t - .Lssinfo

	.section	.debug_abbrev
	.uleb128	DW_AT_external
	.uleb128	DW_FORM_flag
	.section	.debug_info
	.byte		1

	.section	.debug_abbrev
	.uleb128	DW_AT_location
	.uleb128	DW_FORM_block1
	.section	.debug_info
	.byte		5	; length of block
	.byte		DW_OP_addr
	.long		0x800000 + 0xA00 + 0x07

	.section	.debug_abbrev
	.uleb128	0
	.uleb128	0

;- - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
	;; DIE #368: variable TCE0_CTRLFCLR
	.section	.debug_info
	.uleb128	368	; ref to abbrev 368
	.section	.debug_abbrev
	.uleb128	368
	.uleb128	DW_TAG_variable
	.byte		DW_CHILDREN_no

	.uleb128	DW_AT_name
	.uleb128	DW_FORM_strp
	.section	.debug_str
.Lname368:
	.string		"TCE0_CTRLFCLR"
	.section	.debug_info
	.long		.Lname368

	.section	.debug_abbrev
	.uleb128	DW_AT_decl_file
	.uleb128	DW_FORM_data1
	.section	.debug_info
	.byte		0	; no source file information

	.section	.debug_abbrev
	.uleb128	DW_AT_decl_line
	.uleb128	DW_FORM_data1
	.section	.debug_info
	.byte		0	; no source line information

	.section	.debug_abbrev
	.uleb128	DW_AT_type
	.uleb128	DW_FORM_ref4
	.section	.debug_info
	.long		.Luint8_t - .Lssinfo

	.section	.debug_abbrev
	.uleb128	DW_AT_external
	.uleb128	DW_FORM_flag
	.section	.debug_info
	.byte		1

	.section	.debug_abbrev
	.uleb128	DW_AT_location
	.uleb128	DW_FORM_block1
	.section	.debug_info
	.byte		5	; length of block
	.byte		DW_OP_addr
	.long		0x800000 + 0xA00 + 0x08

	.section	.debug_abbrev
	.uleb128	0
	.uleb128	0

;- - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
	;; DIE #369: variable TCE0_CTRLFSET
	.section	.debug_info
	.uleb128	369	; ref to abbrev 369
	.section	.debug_abbrev
	.uleb128	369
	.uleb128	DW_TAG_variable
	.byte		DW_CHILDREN_no

	.uleb128	DW_AT_name
	.uleb128	DW_FORM_strp
	.section	.debug_str
.Lname369:
	.string		"TCE0_CTRLFSET"
	.section	.debug_info
	.long		.Lname369

	.section	.debug_abbrev
	.uleb128	DW_AT_decl_file
	.uleb128	DW_FORM_data1
	.section	.debug_info
	.byte		0	; no source file information

	.section	.debug_abbrev
	.uleb128	DW_AT_decl_line
	.uleb128	DW_FORM_data1
	.section	.debug_info
	.byte		0	; no source line information

	.section	.debug_abbrev
	.uleb128	DW_AT_type
	.uleb128	DW_FORM_ref4
	.section	.debug_info
	.long		.Luint8_t - .Lssinfo

	.section	.debug_abbrev
	.uleb128	DW_AT_external
	.uleb128	DW_FORM_flag
	.section	.debug_info
	.byte		1

	.section	.debug_abbrev
	.uleb128	DW_AT_location
	.uleb128	DW_FORM_block1
	.section	.debug_info
	.byte		5	; length of block
	.byte		DW_OP_addr
	.long		0x800000 + 0xA00 + 0x09

	.section	.debug_abbrev
	.uleb128	0
	.uleb128	0

;- - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
	;; DIE #370: variable TCE0_CTRLGCLR
	.section	.debug_info
	.uleb128	370	; ref to abbrev 370
	.section	.debug_abbrev
	.uleb128	370
	.uleb128	DW_TAG_variable
	.byte		DW_CHILDREN_no

	.uleb128	DW_AT_name
	.uleb128	DW_FORM_strp
	.section	.debug_str
.Lname370:
	.string		"TCE0_CTRLGCLR"
	.section	.debug_info
	.long		.Lname370

	.section	.debug_abbrev
	.uleb128	DW_AT_decl_file
	.uleb128	DW_FORM_data1
	.section	.debug_info
	.byte		0	; no source file information

	.section	.debug_abbrev
	.uleb128	DW_AT_decl_line
	.uleb128	DW_FORM_data1
	.section	.debug_info
	.byte		0	; no source line information

	.section	.debug_abbrev
	.uleb128	DW_AT_type
	.uleb128	DW_FORM_ref4
	.section	.debug_info
	.long		.Luint8_t - .Lssinfo

	.section	.debug_abbrev
	.uleb128	DW_AT_external
	.uleb128	DW_FORM_flag
	.section	.debug_info
	.byte		1

	.section	.debug_abbrev
	.uleb128	DW_AT_location
	.uleb128	DW_FORM_block1
	.section	.debug_info
	.byte		5	; length of block
	.byte		DW_OP_addr
	.long		0x800000 + 0xA00 + 0x0A

	.section	.debug_abbrev
	.uleb128	0
	.uleb128	0

;- - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
	;; DIE #371: variable TCE0_CTRLGSET
	.section	.debug_info
	.uleb128	371	; ref to abbrev 371
	.section	.debug_abbrev
	.uleb128	371
	.uleb128	DW_TAG_variable
	.byte		DW_CHILDREN_no

	.uleb128	DW_AT_name
	.uleb128	DW_FORM_strp
	.section	.debug_str
.Lname371:
	.string		"TCE0_CTRLGSET"
	.section	.debug_info
	.long		.Lname371

	.section	.debug_abbrev
	.uleb128	DW_AT_decl_file
	.uleb128	DW_FORM_data1
	.section	.debug_info
	.byte		0	; no source file information

	.section	.debug_abbrev
	.uleb128	DW_AT_decl_line
	.uleb128	DW_FORM_data1
	.section	.debug_info
	.byte		0	; no source line information

	.section	.debug_abbrev
	.uleb128	DW_AT_type
	.uleb128	DW_FORM_ref4
	.section	.debug_info
	.long		.Luint8_t - .Lssinfo

	.section	.debug_abbrev
	.uleb128	DW_AT_external
	.uleb128	DW_FORM_flag
	.section	.debug_info
	.byte		1

	.section	.debug_abbrev
	.uleb128	DW_AT_location
	.uleb128	DW_FORM_block1
	.section	.debug_info
	.byte		5	; length of block
	.byte		DW_OP_addr
	.long		0x800000 + 0xA00 + 0x0B

	.section	.debug_abbrev
	.uleb128	0
	.uleb128	0

;- - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
	;; DIE #372: variable TCE0_INTFLAGS
	.section	.debug_info
	.uleb128	372	; ref to abbrev 372
	.section	.debug_abbrev
	.uleb128	372
	.uleb128	DW_TAG_variable
	.byte		DW_CHILDREN_no

	.uleb128	DW_AT_name
	.uleb128	DW_FORM_strp
	.section	.debug_str
.Lname372:
	.string		"TCE0_INTFLAGS"
	.section	.debug_info
	.long		.Lname372

	.section	.debug_abbrev
	.uleb128	DW_AT_decl_file
	.uleb128	DW_FORM_data1
	.section	.debug_info
	.byte		0	; no source file information

	.section	.debug_abbrev
	.uleb128	DW_AT_decl_line
	.uleb128	DW_FORM_data1
	.section	.debug_info
	.byte		0	; no source line information

	.section	.debug_abbrev
	.uleb128	DW_AT_type
	.uleb128	DW_FORM_ref4
	.section	.debug_info
	.long		.Luint8_t - .Lssinfo

	.section	.debug_abbrev
	.uleb128	DW_AT_external
	.uleb128	DW_FORM_flag
	.section	.debug_info
	.byte		1

	.section	.debug_abbrev
	.uleb128	DW_AT_location
	.uleb128	DW_FORM_block1
	.section	.debug_info
	.byte		5	; length of block
	.byte		DW_OP_addr
	.long		0x800000 + 0xA00 + 0x0C

	.section	.debug_abbrev
	.uleb128	0
	.uleb128	0

;- - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
	;; DIE #373: variable TCE0_TEMP
	.section	.debug_info
	.uleb128	373	; ref to abbrev 373
	.section	.debug_abbrev
	.uleb128	373
	.uleb128	DW_TAG_variable
	.byte		DW_CHILDREN_no

	.uleb128	DW_AT_name
	.uleb128	DW_FORM_strp
	.section	.debug_str
.Lname373:
	.string		"TCE0_TEMP"
	.section	.debug_info
	.long		.Lname373

	.section	.debug_abbrev
	.uleb128	DW_AT_decl_file
	.uleb128	DW_FORM_data1
	.section	.debug_info
	.byte		0	; no source file information

	.section	.debug_abbrev
	.uleb128	DW_AT_decl_line
	.uleb128	DW_FORM_data1
	.section	.debug_info
	.byte		0	; no source line information

	.section	.debug_abbrev
	.uleb128	DW_AT_type
	.uleb128	DW_FORM_ref4
	.section	.debug_info
	.long		.Luint8_t - .Lssinfo

	.section	.debug_abbrev
	.uleb128	DW_AT_external
	.uleb128	DW_FORM_flag
	.section	.debug_info
	.byte		1

	.section	.debug_abbrev
	.uleb128	DW_AT_location
	.uleb128	DW_FORM_block1
	.section	.debug_info
	.byte		5	; length of block
	.byte		DW_OP_addr
	.long		0x800000 + 0xA00 + 0x0F

	.section	.debug_abbrev
	.uleb128	0
	.uleb128	0

;- - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
	;; DIE #374: variable TCE0_CNT
	.section	.debug_info
	.uleb128	374	; ref to abbrev 374
	.section	.debug_abbrev
	.uleb128	374
	.uleb128	DW_TAG_variable
	.byte		DW_CHILDREN_no

	.uleb128	DW_AT_name
	.uleb128	DW_FORM_strp
	.section	.debug_str
.Lname374:
	.string		"TCE0_CNT"
	.section	.debug_info
	.long		.Lname374

	.section	.debug_abbrev
	.uleb128	DW_AT_decl_file
	.uleb128	DW_FORM_data1
	.section	.debug_info
	.byte		0	; no source file information

	.section	.debug_abbrev
	.uleb128	DW_AT_decl_line
	.uleb128	DW_FORM_data1
	.section	.debug_info
	.byte		0	; no source line information

	.section	.debug_abbrev
	.uleb128	DW_AT_type
	.uleb128	DW_FORM_ref4
	.section	.debug_info
	.long		.Luint16_t - .Lssinfo

	.section	.debug_abbrev
	.uleb128	DW_AT_external
	.uleb128	DW_FORM_flag
	.section	.debug_info
	.byte		1

	.section	.debug_abbrev
	.uleb128	DW_AT_location
	.uleb128	DW_FORM_block1
	.section	.debug_info
	.byte		5	; length of block
	.byte		DW_OP_addr
	.long		0x800000 + 0xA00 + 0x20

	.section	.debug_abbrev
	.uleb128	0
	.uleb128	0

;- - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
	;; DIE #375: variable TCE0_PER
	.section	.debug_info
	.uleb128	375	; ref to abbrev 375
	.section	.debug_abbrev
	.uleb128	375
	.uleb128	DW_TAG_variable
	.byte		DW_CHILDREN_no

	.uleb128	DW_AT_name
	.uleb128	DW_FORM_strp
	.section	.debug_str
.Lname375:
	.string		"TCE0_PER"
	.section	.debug_info
	.long		.Lname375

	.section	.debug_abbrev
	.uleb128	DW_AT_decl_file
	.uleb128	DW_FORM_data1
	.section	.debug_info
	.byte		0	; no source file information

	.section	.debug_abbrev
	.uleb128	DW_AT_decl_line
	.uleb128	DW_FORM_data1
	.section	.debug_info
	.byte		0	; no source line information

	.section	.debug_abbrev
	.uleb128	DW_AT_type
	.uleb128	DW_FORM_ref4
	.section	.debug_info
	.long		.Luint16_t - .Lssinfo

	.section	.debug_abbrev
	.uleb128	DW_AT_external
	.uleb128	DW_FORM_flag
	.section	.debug_info
	.byte		1

	.section	.debug_abbrev
	.uleb128	DW_AT_location
	.uleb128	DW_FORM_block1
	.section	.debug_info
	.byte		5	; length of block
	.byte		DW_OP_addr
	.long		0x800000 + 0xA00 + 0x26

	.section	.debug_abbrev
	.uleb128	0
	.uleb128	0

;- - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
	;; DIE #376: variable TCE0_CCA
	.section	.debug_info
	.uleb128	376	; ref to abbrev 376
	.section	.debug_abbrev
	.uleb128	376
	.uleb128	DW_TAG_variable
	.byte		DW_CHILDREN_no

	.uleb128	DW_AT_name
	.uleb128	DW_FORM_strp
	.section	.debug_str
.Lname376:
	.string		"TCE0_CCA"
	.section	.debug_info
	.long		.Lname376

	.section	.debug_abbrev
	.uleb128	DW_AT_decl_file
	.uleb128	DW_FORM_data1
	.section	.debug_info
	.byte		0	; no source file information

	.section	.debug_abbrev
	.uleb128	DW_AT_decl_line
	.uleb128	DW_FORM_data1
	.section	.debug_info
	.byte		0	; no source line information

	.section	.debug_abbrev
	.uleb128	DW_AT_type
	.uleb128	DW_FORM_ref4
	.section	.debug_info
	.long		.Luint16_t - .Lssinfo

	.section	.debug_abbrev
	.uleb128	DW_AT_external
	.uleb128	DW_FORM_flag
	.section	.debug_info
	.byte		1

	.section	.debug_abbrev
	.uleb128	DW_AT_location
	.uleb128	DW_FORM_block1
	.section	.debug_info
	.byte		5	; length of block
	.byte		DW_OP_addr
	.long		0x800000 + 0xA00 + 0x28

	.section	.debug_abbrev
	.uleb128	0
	.uleb128	0

;- - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
	;; DIE #377: variable TCE0_CCB
	.section	.debug_info
	.uleb128	377	; ref to abbrev 377
	.section	.debug_abbrev
	.uleb128	377
	.uleb128	DW_TAG_variable
	.byte		DW_CHILDREN_no

	.uleb128	DW_AT_name
	.uleb128	DW_FORM_strp
	.section	.debug_str
.Lname377:
	.string		"TCE0_CCB"
	.section	.debug_info
	.long		.Lname377

	.section	.debug_abbrev
	.uleb128	DW_AT_decl_file
	.uleb128	DW_FORM_data1
	.section	.debug_info
	.byte		0	; no source file information

	.section	.debug_abbrev
	.uleb128	DW_AT_decl_line
	.uleb128	DW_FORM_data1
	.section	.debug_info
	.byte		0	; no source line information

	.section	.debug_abbrev
	.uleb128	DW_AT_type
	.uleb128	DW_FORM_ref4
	.section	.debug_info
	.long		.Luint16_t - .Lssinfo

	.section	.debug_abbrev
	.uleb128	DW_AT_external
	.uleb128	DW_FORM_flag
	.section	.debug_info
	.byte		1

	.section	.debug_abbrev
	.uleb128	DW_AT_location
	.uleb128	DW_FORM_block1
	.section	.debug_info
	.byte		5	; length of block
	.byte		DW_OP_addr
	.long		0x800000 + 0xA00 + 0x2A

	.section	.debug_abbrev
	.uleb128	0
	.uleb128	0

;- - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
	;; DIE #378: variable TCE0_CCC
	.section	.debug_info
	.uleb128	378	; ref to abbrev 378
	.section	.debug_abbrev
	.uleb128	378
	.uleb128	DW_TAG_variable
	.byte		DW_CHILDREN_no

	.uleb128	DW_AT_name
	.uleb128	DW_FORM_strp
	.section	.debug_str
.Lname378:
	.string		"TCE0_CCC"
	.section	.debug_info
	.long		.Lname378

	.section	.debug_abbrev
	.uleb128	DW_AT_decl_file
	.uleb128	DW_FORM_data1
	.section	.debug_info
	.byte		0	; no source file information

	.section	.debug_abbrev
	.uleb128	DW_AT_decl_line
	.uleb128	DW_FORM_data1
	.section	.debug_info
	.byte		0	; no source line information

	.section	.debug_abbrev
	.uleb128	DW_AT_type
	.uleb128	DW_FORM_ref4
	.section	.debug_info
	.long		.Luint16_t - .Lssinfo

	.section	.debug_abbrev
	.uleb128	DW_AT_external
	.uleb128	DW_FORM_flag
	.section	.debug_info
	.byte		1

	.section	.debug_abbrev
	.uleb128	DW_AT_location
	.uleb128	DW_FORM_block1
	.section	.debug_info
	.byte		5	; length of block
	.byte		DW_OP_addr
	.long		0x800000 + 0xA00 + 0x2C

	.section	.debug_abbrev
	.uleb128	0
	.uleb128	0

;- - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
	;; DIE #379: variable TCE0_CCD
	.section	.debug_info
	.uleb128	379	; ref to abbrev 379
	.section	.debug_abbrev
	.uleb128	379
	.uleb128	DW_TAG_variable
	.byte		DW_CHILDREN_no

	.uleb128	DW_AT_name
	.uleb128	DW_FORM_strp
	.section	.debug_str
.Lname379:
	.string		"TCE0_CCD"
	.section	.debug_info
	.long		.Lname379

	.section	.debug_abbrev
	.uleb128	DW_AT_decl_file
	.uleb128	DW_FORM_data1
	.section	.debug_info
	.byte		0	; no source file information

	.section	.debug_abbrev
	.uleb128	DW_AT_decl_line
	.uleb128	DW_FORM_data1
	.section	.debug_info
	.byte		0	; no source line information

	.section	.debug_abbrev
	.uleb128	DW_AT_type
	.uleb128	DW_FORM_ref4
	.section	.debug_info
	.long		.Luint16_t - .Lssinfo

	.section	.debug_abbrev
	.uleb128	DW_AT_external
	.uleb128	DW_FORM_flag
	.section	.debug_info
	.byte		1

	.section	.debug_abbrev
	.uleb128	DW_AT_location
	.uleb128	DW_FORM_block1
	.section	.debug_info
	.byte		5	; length of block
	.byte		DW_OP_addr
	.long		0x800000 + 0xA00 + 0x2E

	.section	.debug_abbrev
	.uleb128	0
	.uleb128	0

;- - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
	;; DIE #380: variable TCE0_PERBUF
	.section	.debug_info
	.uleb128	380	; ref to abbrev 380
	.section	.debug_abbrev
	.uleb128	380
	.uleb128	DW_TAG_variable
	.byte		DW_CHILDREN_no

	.uleb128	DW_AT_name
	.uleb128	DW_FORM_strp
	.section	.debug_str
.Lname380:
	.string		"TCE0_PERBUF"
	.section	.debug_info
	.long		.Lname380

	.section	.debug_abbrev
	.uleb128	DW_AT_decl_file
	.uleb128	DW_FORM_data1
	.section	.debug_info
	.byte		0	; no source file information

	.section	.debug_abbrev
	.uleb128	DW_AT_decl_line
	.uleb128	DW_FORM_data1
	.section	.debug_info
	.byte		0	; no source line information

	.section	.debug_abbrev
	.uleb128	DW_AT_type
	.uleb128	DW_FORM_ref4
	.section	.debug_info
	.long		.Luint16_t - .Lssinfo

	.section	.debug_abbrev
	.uleb128	DW_AT_external
	.uleb128	DW_FORM_flag
	.section	.debug_info
	.byte		1

	.section	.debug_abbrev
	.uleb128	DW_AT_location
	.uleb128	DW_FORM_block1
	.section	.debug_info
	.byte		5	; length of block
	.byte		DW_OP_addr
	.long		0x800000 + 0xA00 + 0x36

	.section	.debug_abbrev
	.uleb128	0
	.uleb128	0

;- - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
	;; DIE #381: variable TCE0_CCABUF
	.section	.debug_info
	.uleb128	381	; ref to abbrev 381
	.section	.debug_abbrev
	.uleb128	381
	.uleb128	DW_TAG_variable
	.byte		DW_CHILDREN_no

	.uleb128	DW_AT_name
	.uleb128	DW_FORM_strp
	.section	.debug_str
.Lname381:
	.string		"TCE0_CCABUF"
	.section	.debug_info
	.long		.Lname381

	.section	.debug_abbrev
	.uleb128	DW_AT_decl_file
	.uleb128	DW_FORM_data1
	.section	.debug_info
	.byte		0	; no source file information

	.section	.debug_abbrev
	.uleb128	DW_AT_decl_line
	.uleb128	DW_FORM_data1
	.section	.debug_info
	.byte		0	; no source line information

	.section	.debug_abbrev
	.uleb128	DW_AT_type
	.uleb128	DW_FORM_ref4
	.section	.debug_info
	.long		.Luint16_t - .Lssinfo

	.section	.debug_abbrev
	.uleb128	DW_AT_external
	.uleb128	DW_FORM_flag
	.section	.debug_info
	.byte		1

	.section	.debug_abbrev
	.uleb128	DW_AT_location
	.uleb128	DW_FORM_block1
	.section	.debug_info
	.byte		5	; length of block
	.byte		DW_OP_addr
	.long		0x800000 + 0xA00 + 0x38

	.section	.debug_abbrev
	.uleb128	0
	.uleb128	0

;- - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
	;; DIE #382: variable TCE0_CCBBUF
	.section	.debug_info
	.uleb128	382	; ref to abbrev 382
	.section	.debug_abbrev
	.uleb128	382
	.uleb128	DW_TAG_variable
	.byte		DW_CHILDREN_no

	.uleb128	DW_AT_name
	.uleb128	DW_FORM_strp
	.section	.debug_str
.Lname382:
	.string		"TCE0_CCBBUF"
	.section	.debug_info
	.long		.Lname382

	.section	.debug_abbrev
	.uleb128	DW_AT_decl_file
	.uleb128	DW_FORM_data1
	.section	.debug_info
	.byte		0	; no source file information

	.section	.debug_abbrev
	.uleb128	DW_AT_decl_line
	.uleb128	DW_FORM_data1
	.section	.debug_info
	.byte		0	; no source line information

	.section	.debug_abbrev
	.uleb128	DW_AT_type
	.uleb128	DW_FORM_ref4
	.section	.debug_info
	.long		.Luint16_t - .Lssinfo

	.section	.debug_abbrev
	.uleb128	DW_AT_external
	.uleb128	DW_FORM_flag
	.section	.debug_info
	.byte		1

	.section	.debug_abbrev
	.uleb128	DW_AT_location
	.uleb128	DW_FORM_block1
	.section	.debug_info
	.byte		5	; length of block
	.byte		DW_OP_addr
	.long		0x800000 + 0xA00 + 0x3A

	.section	.debug_abbrev
	.uleb128	0
	.uleb128	0

;- - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
	;; DIE #383: variable TCE0_CCCBUF
	.section	.debug_info
	.uleb128	383	; ref to abbrev 383
	.section	.debug_abbrev
	.uleb128	383
	.uleb128	DW_TAG_variable
	.byte		DW_CHILDREN_no

	.uleb128	DW_AT_name
	.uleb128	DW_FORM_strp
	.section	.debug_str
.Lname383:
	.string		"TCE0_CCCBUF"
	.section	.debug_info
	.long		.Lname383

	.section	.debug_abbrev
	.uleb128	DW_AT_decl_file
	.uleb128	DW_FORM_data1
	.section	.debug_info
	.byte		0	; no source file information

	.section	.debug_abbrev
	.uleb128	DW_AT_decl_line
	.uleb128	DW_FORM_data1
	.section	.debug_info
	.byte		0	; no source line information

	.section	.debug_abbrev
	.uleb128	DW_AT_type
	.uleb128	DW_FORM_ref4
	.section	.debug_info
	.long		.Luint16_t - .Lssinfo

	.section	.debug_abbrev
	.uleb128	DW_AT_external
	.uleb128	DW_FORM_flag
	.section	.debug_info
	.byte		1

	.section	.debug_abbrev
	.uleb128	DW_AT_location
	.uleb128	DW_FORM_block1
	.section	.debug_info
	.byte		5	; length of block
	.byte		DW_OP_addr
	.long		0x800000 + 0xA00 + 0x3C

	.section	.debug_abbrev
	.uleb128	0
	.uleb128	0

;- - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
	;; DIE #384: variable TCE0_CCDBUF
	.section	.debug_info
	.uleb128	384	; ref to abbrev 384
	.section	.debug_abbrev
	.uleb128	384
	.uleb128	DW_TAG_variable
	.byte		DW_CHILDREN_no

	.uleb128	DW_AT_name
	.uleb128	DW_FORM_strp
	.section	.debug_str
.Lname384:
	.string		"TCE0_CCDBUF"
	.section	.debug_info
	.long		.Lname384

	.section	.debug_abbrev
	.uleb128	DW_AT_decl_file
	.uleb128	DW_FORM_data1
	.section	.debug_info
	.byte		0	; no source file information

	.section	.debug_abbrev
	.uleb128	DW_AT_decl_line
	.uleb128	DW_FORM_data1
	.section	.debug_info
	.byte		0	; no source line information

	.section	.debug_abbrev
	.uleb128	DW_AT_type
	.uleb128	DW_FORM_ref4
	.section	.debug_info
	.long		.Luint16_t - .Lssinfo

	.section	.debug_abbrev
	.uleb128	DW_AT_external
	.uleb128	DW_FORM_flag
	.section	.debug_info
	.byte		1

	.section	.debug_abbrev
	.uleb128	DW_AT_location
	.uleb128	DW_FORM_block1
	.section	.debug_info
	.byte		5	; length of block
	.byte		DW_OP_addr
	.long		0x800000 + 0xA00 + 0x3E

	.section	.debug_abbrev
	.uleb128	0
	.uleb128	0

;- - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
	;; DIE #385: variable TCC2_CTRLA
	.section	.debug_info
	.uleb128	385	; ref to abbrev 385
	.section	.debug_abbrev
	.uleb128	385
	.uleb128	DW_TAG_variable
	.byte		DW_CHILDREN_no

	.uleb128	DW_AT_name
	.uleb128	DW_FORM_strp
	.section	.debug_str
.Lname385:
	.string		"TCC2_CTRLA"
	.section	.debug_info
	.long		.Lname385

	.section	.debug_abbrev
	.uleb128	DW_AT_decl_file
	.uleb128	DW_FORM_data1
	.section	.debug_info
	.byte		0	; no source file information

	.section	.debug_abbrev
	.uleb128	DW_AT_decl_line
	.uleb128	DW_FORM_data1
	.section	.debug_info
	.byte		0	; no source line information

	.section	.debug_abbrev
	.uleb128	DW_AT_type
	.uleb128	DW_FORM_ref4
	.section	.debug_info
	.long		.Luint8_t - .Lssinfo

	.section	.debug_abbrev
	.uleb128	DW_AT_external
	.uleb128	DW_FORM_flag
	.section	.debug_info
	.byte		1

	.section	.debug_abbrev
	.uleb128	DW_AT_location
	.uleb128	DW_FORM_block1
	.section	.debug_info
	.byte		5	; length of block
	.byte		DW_OP_addr
	.long		0x800000 + 0x800 + 0x00

	.section	.debug_abbrev
	.uleb128	0
	.uleb128	0

;- - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
	;; DIE #386: variable TCC2_CTRLB
	.section	.debug_info
	.uleb128	386	; ref to abbrev 386
	.section	.debug_abbrev
	.uleb128	386
	.uleb128	DW_TAG_variable
	.byte		DW_CHILDREN_no

	.uleb128	DW_AT_name
	.uleb128	DW_FORM_strp
	.section	.debug_str
.Lname386:
	.string		"TCC2_CTRLB"
	.section	.debug_info
	.long		.Lname386

	.section	.debug_abbrev
	.uleb128	DW_AT_decl_file
	.uleb128	DW_FORM_data1
	.section	.debug_info
	.byte		0	; no source file information

	.section	.debug_abbrev
	.uleb128	DW_AT_decl_line
	.uleb128	DW_FORM_data1
	.section	.debug_info
	.byte		0	; no source line information

	.section	.debug_abbrev
	.uleb128	DW_AT_type
	.uleb128	DW_FORM_ref4
	.section	.debug_info
	.long		.Luint8_t - .Lssinfo

	.section	.debug_abbrev
	.uleb128	DW_AT_external
	.uleb128	DW_FORM_flag
	.section	.debug_info
	.byte		1

	.section	.debug_abbrev
	.uleb128	DW_AT_location
	.uleb128	DW_FORM_block1
	.section	.debug_info
	.byte		5	; length of block
	.byte		DW_OP_addr
	.long		0x800000 + 0x800 + 0x01

	.section	.debug_abbrev
	.uleb128	0
	.uleb128	0

;- - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
	;; DIE #387: variable TCC2_CTRLC
	.section	.debug_info
	.uleb128	387	; ref to abbrev 387
	.section	.debug_abbrev
	.uleb128	387
	.uleb128	DW_TAG_variable
	.byte		DW_CHILDREN_no

	.uleb128	DW_AT_name
	.uleb128	DW_FORM_strp
	.section	.debug_str
.Lname387:
	.string		"TCC2_CTRLC"
	.section	.debug_info
	.long		.Lname387

	.section	.debug_abbrev
	.uleb128	DW_AT_decl_file
	.uleb128	DW_FORM_data1
	.section	.debug_info
	.byte		0	; no source file information

	.section	.debug_abbrev
	.uleb128	DW_AT_decl_line
	.uleb128	DW_FORM_data1
	.section	.debug_info
	.byte		0	; no source line information

	.section	.debug_abbrev
	.uleb128	DW_AT_type
	.uleb128	DW_FORM_ref4
	.section	.debug_info
	.long		.Luint8_t - .Lssinfo

	.section	.debug_abbrev
	.uleb128	DW_AT_external
	.uleb128	DW_FORM_flag
	.section	.debug_info
	.byte		1

	.section	.debug_abbrev
	.uleb128	DW_AT_location
	.uleb128	DW_FORM_block1
	.section	.debug_info
	.byte		5	; length of block
	.byte		DW_OP_addr
	.long		0x800000 + 0x800 + 0x02

	.section	.debug_abbrev
	.uleb128	0
	.uleb128	0

;- - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
	;; DIE #388: variable TCC2_CTRLE
	.section	.debug_info
	.uleb128	388	; ref to abbrev 388
	.section	.debug_abbrev
	.uleb128	388
	.uleb128	DW_TAG_variable
	.byte		DW_CHILDREN_no

	.uleb128	DW_AT_name
	.uleb128	DW_FORM_strp
	.section	.debug_str
.Lname388:
	.string		"TCC2_CTRLE"
	.section	.debug_info
	.long		.Lname388

	.section	.debug_abbrev
	.uleb128	DW_AT_decl_file
	.uleb128	DW_FORM_data1
	.section	.debug_info
	.byte		0	; no source file information

	.section	.debug_abbrev
	.uleb128	DW_AT_decl_line
	.uleb128	DW_FORM_data1
	.section	.debug_info
	.byte		0	; no source line information

	.section	.debug_abbrev
	.uleb128	DW_AT_type
	.uleb128	DW_FORM_ref4
	.section	.debug_info
	.long		.Luint8_t - .Lssinfo

	.section	.debug_abbrev
	.uleb128	DW_AT_external
	.uleb128	DW_FORM_flag
	.section	.debug_info
	.byte		1

	.section	.debug_abbrev
	.uleb128	DW_AT_location
	.uleb128	DW_FORM_block1
	.section	.debug_info
	.byte		5	; length of block
	.byte		DW_OP_addr
	.long		0x800000 + 0x800 + 0x04

	.section	.debug_abbrev
	.uleb128	0
	.uleb128	0

;- - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
	;; DIE #389: variable TCC2_INTCTRLA
	.section	.debug_info
	.uleb128	389	; ref to abbrev 389
	.section	.debug_abbrev
	.uleb128	389
	.uleb128	DW_TAG_variable
	.byte		DW_CHILDREN_no

	.uleb128	DW_AT_name
	.uleb128	DW_FORM_strp
	.section	.debug_str
.Lname389:
	.string		"TCC2_INTCTRLA"
	.section	.debug_info
	.long		.Lname389

	.section	.debug_abbrev
	.uleb128	DW_AT_decl_file
	.uleb128	DW_FORM_data1
	.section	.debug_info
	.byte		0	; no source file information

	.section	.debug_abbrev
	.uleb128	DW_AT_decl_line
	.uleb128	DW_FORM_data1
	.section	.debug_info
	.byte		0	; no source line information

	.section	.debug_abbrev
	.uleb128	DW_AT_type
	.uleb128	DW_FORM_ref4
	.section	.debug_info
	.long		.Luint8_t - .Lssinfo

	.section	.debug_abbrev
	.uleb128	DW_AT_external
	.uleb128	DW_FORM_flag
	.section	.debug_info
	.byte		1

	.section	.debug_abbrev
	.uleb128	DW_AT_location
	.uleb128	DW_FORM_block1
	.section	.debug_info
	.byte		5	; length of block
	.byte		DW_OP_addr
	.long		0x800000 + 0x800 + 0x06

	.section	.debug_abbrev
	.uleb128	0
	.uleb128	0

;- - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
	;; DIE #390: variable TCC2_INTCTRLB
	.section	.debug_info
	.uleb128	390	; ref to abbrev 390
	.section	.debug_abbrev
	.uleb128	390
	.uleb128	DW_TAG_variable
	.byte		DW_CHILDREN_no

	.uleb128	DW_AT_name
	.uleb128	DW_FORM_strp
	.section	.debug_str
.Lname390:
	.string		"TCC2_INTCTRLB"
	.section	.debug_info
	.long		.Lname390

	.section	.debug_abbrev
	.uleb128	DW_AT_decl_file
	.uleb128	DW_FORM_data1
	.section	.debug_info
	.byte		0	; no source file information

	.section	.debug_abbrev
	.uleb128	DW_AT_decl_line
	.uleb128	DW_FORM_data1
	.section	.debug_info
	.byte		0	; no source line information

	.section	.debug_abbrev
	.uleb128	DW_AT_type
	.uleb128	DW_FORM_ref4
	.section	.debug_info
	.long		.Luint8_t - .Lssinfo

	.section	.debug_abbrev
	.uleb128	DW_AT_external
	.uleb128	DW_FORM_flag
	.section	.debug_info
	.byte		1

	.section	.debug_abbrev
	.uleb128	DW_AT_location
	.uleb128	DW_FORM_block1
	.section	.debug_info
	.byte		5	; length of block
	.byte		DW_OP_addr
	.long		0x800000 + 0x800 + 0x07

	.section	.debug_abbrev
	.uleb128	0
	.uleb128	0

;- - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
	;; DIE #391: variable TCC2_CTRLF
	.section	.debug_info
	.uleb128	391	; ref to abbrev 391
	.section	.debug_abbrev
	.uleb128	391
	.uleb128	DW_TAG_variable
	.byte		DW_CHILDREN_no

	.uleb128	DW_AT_name
	.uleb128	DW_FORM_strp
	.section	.debug_str
.Lname391:
	.string		"TCC2_CTRLF"
	.section	.debug_info
	.long		.Lname391

	.section	.debug_abbrev
	.uleb128	DW_AT_decl_file
	.uleb128	DW_FORM_data1
	.section	.debug_info
	.byte		0	; no source file information

	.section	.debug_abbrev
	.uleb128	DW_AT_decl_line
	.uleb128	DW_FORM_data1
	.section	.debug_info
	.byte		0	; no source line information

	.section	.debug_abbrev
	.uleb128	DW_AT_type
	.uleb128	DW_FORM_ref4
	.section	.debug_info
	.long		.Luint8_t - .Lssinfo

	.section	.debug_abbrev
	.uleb128	DW_AT_external
	.uleb128	DW_FORM_flag
	.section	.debug_info
	.byte		1

	.section	.debug_abbrev
	.uleb128	DW_AT_location
	.uleb128	DW_FORM_block1
	.section	.debug_info
	.byte		5	; length of block
	.byte		DW_OP_addr
	.long		0x800000 + 0x800 + 0x09

	.section	.debug_abbrev
	.uleb128	0
	.uleb128	0

;- - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
	;; DIE #392: variable TCC2_INTFLAGS
	.section	.debug_info
	.uleb128	392	; ref to abbrev 392
	.section	.debug_abbrev
	.uleb128	392
	.uleb128	DW_TAG_variable
	.byte		DW_CHILDREN_no

	.uleb128	DW_AT_name
	.uleb128	DW_FORM_strp
	.section	.debug_str
.Lname392:
	.string		"TCC2_INTFLAGS"
	.section	.debug_info
	.long		.Lname392

	.section	.debug_abbrev
	.uleb128	DW_AT_decl_file
	.uleb128	DW_FORM_data1
	.section	.debug_info
	.byte		0	; no source file information

	.section	.debug_abbrev
	.uleb128	DW_AT_decl_line
	.uleb128	DW_FORM_data1
	.section	.debug_info
	.byte		0	; no source line information

	.section	.debug_abbrev
	.uleb128	DW_AT_type
	.uleb128	DW_FORM_ref4
	.section	.debug_info
	.long		.Luint8_t - .Lssinfo

	.section	.debug_abbrev
	.uleb128	DW_AT_external
	.uleb128	DW_FORM_flag
	.section	.debug_info
	.byte		1

	.section	.debug_abbrev
	.uleb128	DW_AT_location
	.uleb128	DW_FORM_block1
	.section	.debug_info
	.byte		5	; length of block
	.byte		DW_OP_addr
	.long		0x800000 + 0x800 + 0x0C

	.section	.debug_abbrev
	.uleb128	0
	.uleb128	0

;- - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
	;; DIE #393: variable TCC2_LCNT
	.section	.debug_info
	.uleb128	393	; ref to abbrev 393
	.section	.debug_abbrev
	.uleb128	393
	.uleb128	DW_TAG_variable
	.byte		DW_CHILDREN_no

	.uleb128	DW_AT_name
	.uleb128	DW_FORM_strp
	.section	.debug_str
.Lname393:
	.string		"TCC2_LCNT"
	.section	.debug_info
	.long		.Lname393

	.section	.debug_abbrev
	.uleb128	DW_AT_decl_file
	.uleb128	DW_FORM_data1
	.section	.debug_info
	.byte		0	; no source file information

	.section	.debug_abbrev
	.uleb128	DW_AT_decl_line
	.uleb128	DW_FORM_data1
	.section	.debug_info
	.byte		0	; no source line information

	.section	.debug_abbrev
	.uleb128	DW_AT_type
	.uleb128	DW_FORM_ref4
	.section	.debug_info
	.long		.Luint8_t - .Lssinfo

	.section	.debug_abbrev
	.uleb128	DW_AT_external
	.uleb128	DW_FORM_flag
	.section	.debug_info
	.byte		1

	.section	.debug_abbrev
	.uleb128	DW_AT_location
	.uleb128	DW_FORM_block1
	.section	.debug_info
	.byte		5	; length of block
	.byte		DW_OP_addr
	.long		0x800000 + 0x800 + 0x20

	.section	.debug_abbrev
	.uleb128	0
	.uleb128	0

;- - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
	;; DIE #394: variable TCC2_HCNT
	.section	.debug_info
	.uleb128	394	; ref to abbrev 394
	.section	.debug_abbrev
	.uleb128	394
	.uleb128	DW_TAG_variable
	.byte		DW_CHILDREN_no

	.uleb128	DW_AT_name
	.uleb128	DW_FORM_strp
	.section	.debug_str
.Lname394:
	.string		"TCC2_HCNT"
	.section	.debug_info
	.long		.Lname394

	.section	.debug_abbrev
	.uleb128	DW_AT_decl_file
	.uleb128	DW_FORM_data1
	.section	.debug_info
	.byte		0	; no source file information

	.section	.debug_abbrev
	.uleb128	DW_AT_decl_line
	.uleb128	DW_FORM_data1
	.section	.debug_info
	.byte		0	; no source line information

	.section	.debug_abbrev
	.uleb128	DW_AT_type
	.uleb128	DW_FORM_ref4
	.section	.debug_info
	.long		.Luint8_t - .Lssinfo

	.section	.debug_abbrev
	.uleb128	DW_AT_external
	.uleb128	DW_FORM_flag
	.section	.debug_info
	.byte		1

	.section	.debug_abbrev
	.uleb128	DW_AT_location
	.uleb128	DW_FORM_block1
	.section	.debug_info
	.byte		5	; length of block
	.byte		DW_OP_addr
	.long		0x800000 + 0x800 + 0x21

	.section	.debug_abbrev
	.uleb128	0
	.uleb128	0

;- - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
	;; DIE #395: variable TCC2_LPER
	.section	.debug_info
	.uleb128	395	; ref to abbrev 395
	.section	.debug_abbrev
	.uleb128	395
	.uleb128	DW_TAG_variable
	.byte		DW_CHILDREN_no

	.uleb128	DW_AT_name
	.uleb128	DW_FORM_strp
	.section	.debug_str
.Lname395:
	.string		"TCC2_LPER"
	.section	.debug_info
	.long		.Lname395

	.section	.debug_abbrev
	.uleb128	DW_AT_decl_file
	.uleb128	DW_FORM_data1
	.section	.debug_info
	.byte		0	; no source file information

	.section	.debug_abbrev
	.uleb128	DW_AT_decl_line
	.uleb128	DW_FORM_data1
	.section	.debug_info
	.byte		0	; no source line information

	.section	.debug_abbrev
	.uleb128	DW_AT_type
	.uleb128	DW_FORM_ref4
	.section	.debug_info
	.long		.Luint8_t - .Lssinfo

	.section	.debug_abbrev
	.uleb128	DW_AT_external
	.uleb128	DW_FORM_flag
	.section	.debug_info
	.byte		1

	.section	.debug_abbrev
	.uleb128	DW_AT_location
	.uleb128	DW_FORM_block1
	.section	.debug_info
	.byte		5	; length of block
	.byte		DW_OP_addr
	.long		0x800000 + 0x800 + 0x26

	.section	.debug_abbrev
	.uleb128	0
	.uleb128	0

;- - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
	;; DIE #396: variable TCC2_HPER
	.section	.debug_info
	.uleb128	396	; ref to abbrev 396
	.section	.debug_abbrev
	.uleb128	396
	.uleb128	DW_TAG_variable
	.byte		DW_CHILDREN_no

	.uleb128	DW_AT_name
	.uleb128	DW_FORM_strp
	.section	.debug_str
.Lname396:
	.string		"TCC2_HPER"
	.section	.debug_info
	.long		.Lname396

	.section	.debug_abbrev
	.uleb128	DW_AT_decl_file
	.uleb128	DW_FORM_data1
	.section	.debug_info
	.byte		0	; no source file information

	.section	.debug_abbrev
	.uleb128	DW_AT_decl_line
	.uleb128	DW_FORM_data1
	.section	.debug_info
	.byte		0	; no source line information

	.section	.debug_abbrev
	.uleb128	DW_AT_type
	.uleb128	DW_FORM_ref4
	.section	.debug_info
	.long		.Luint8_t - .Lssinfo

	.section	.debug_abbrev
	.uleb128	DW_AT_external
	.uleb128	DW_FORM_flag
	.section	.debug_info
	.byte		1

	.section	.debug_abbrev
	.uleb128	DW_AT_location
	.uleb128	DW_FORM_block1
	.section	.debug_info
	.byte		5	; length of block
	.byte		DW_OP_addr
	.long		0x800000 + 0x800 + 0x27

	.section	.debug_abbrev
	.uleb128	0
	.uleb128	0

;- - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
	;; DIE #397: variable TCC2_LCMPA
	.section	.debug_info
	.uleb128	397	; ref to abbrev 397
	.section	.debug_abbrev
	.uleb128	397
	.uleb128	DW_TAG_variable
	.byte		DW_CHILDREN_no

	.uleb128	DW_AT_name
	.uleb128	DW_FORM_strp
	.section	.debug_str
.Lname397:
	.string		"TCC2_LCMPA"
	.section	.debug_info
	.long		.Lname397

	.section	.debug_abbrev
	.uleb128	DW_AT_decl_file
	.uleb128	DW_FORM_data1
	.section	.debug_info
	.byte		0	; no source file information

	.section	.debug_abbrev
	.uleb128	DW_AT_decl_line
	.uleb128	DW_FORM_data1
	.section	.debug_info
	.byte		0	; no source line information

	.section	.debug_abbrev
	.uleb128	DW_AT_type
	.uleb128	DW_FORM_ref4
	.section	.debug_info
	.long		.Luint8_t - .Lssinfo

	.section	.debug_abbrev
	.uleb128	DW_AT_external
	.uleb128	DW_FORM_flag
	.section	.debug_info
	.byte		1

	.section	.debug_abbrev
	.uleb128	DW_AT_location
	.uleb128	DW_FORM_block1
	.section	.debug_info
	.byte		5	; length of block
	.byte		DW_OP_addr
	.long		0x800000 + 0x800 + 0x28

	.section	.debug_abbrev
	.uleb128	0
	.uleb128	0

;- - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
	;; DIE #398: variable TCC2_HCMPA
	.section	.debug_info
	.uleb128	398	; ref to abbrev 398
	.section	.debug_abbrev
	.uleb128	398
	.uleb128	DW_TAG_variable
	.byte		DW_CHILDREN_no

	.uleb128	DW_AT_name
	.uleb128	DW_FORM_strp
	.section	.debug_str
.Lname398:
	.string		"TCC2_HCMPA"
	.section	.debug_info
	.long		.Lname398

	.section	.debug_abbrev
	.uleb128	DW_AT_decl_file
	.uleb128	DW_FORM_data1
	.section	.debug_info
	.byte		0	; no source file information

	.section	.debug_abbrev
	.uleb128	DW_AT_decl_line
	.uleb128	DW_FORM_data1
	.section	.debug_info
	.byte		0	; no source line information

	.section	.debug_abbrev
	.uleb128	DW_AT_type
	.uleb128	DW_FORM_ref4
	.section	.debug_info
	.long		.Luint8_t - .Lssinfo

	.section	.debug_abbrev
	.uleb128	DW_AT_external
	.uleb128	DW_FORM_flag
	.section	.debug_info
	.byte		1

	.section	.debug_abbrev
	.uleb128	DW_AT_location
	.uleb128	DW_FORM_block1
	.section	.debug_info
	.byte		5	; length of block
	.byte		DW_OP_addr
	.long		0x800000 + 0x800 + 0x29

	.section	.debug_abbrev
	.uleb128	0
	.uleb128	0

;- - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
	;; DIE #399: variable TCC2_LCMPB
	.section	.debug_info
	.uleb128	399	; ref to abbrev 399
	.section	.debug_abbrev
	.uleb128	399
	.uleb128	DW_TAG_variable
	.byte		DW_CHILDREN_no

	.uleb128	DW_AT_name
	.uleb128	DW_FORM_strp
	.section	.debug_str
.Lname399:
	.string		"TCC2_LCMPB"
	.section	.debug_info
	.long		.Lname399

	.section	.debug_abbrev
	.uleb128	DW_AT_decl_file
	.uleb128	DW_FORM_data1
	.section	.debug_info
	.byte		0	; no source file information

	.section	.debug_abbrev
	.uleb128	DW_AT_decl_line
	.uleb128	DW_FORM_data1
	.section	.debug_info
	.byte		0	; no source line information

	.section	.debug_abbrev
	.uleb128	DW_AT_type
	.uleb128	DW_FORM_ref4
	.section	.debug_info
	.long		.Luint8_t - .Lssinfo

	.section	.debug_abbrev
	.uleb128	DW_AT_external
	.uleb128	DW_FORM_flag
	.section	.debug_info
	.byte		1

	.section	.debug_abbrev
	.uleb128	DW_AT_location
	.uleb128	DW_FORM_block1
	.section	.debug_info
	.byte		5	; length of block
	.byte		DW_OP_addr
	.long		0x800000 + 0x800 + 0x2A

	.section	.debug_abbrev
	.uleb128	0
	.uleb128	0

;- - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
	;; DIE #400: variable TCC2_HCMPB
	.section	.debug_info
	.uleb128	400	; ref to abbrev 400
	.section	.debug_abbrev
	.uleb128	400
	.uleb128	DW_TAG_variable
	.byte		DW_CHILDREN_no

	.uleb128	DW_AT_name
	.uleb128	DW_FORM_strp
	.section	.debug_str
.Lname400:
	.string		"TCC2_HCMPB"
	.section	.debug_info
	.long		.Lname400

	.section	.debug_abbrev
	.uleb128	DW_AT_decl_file
	.uleb128	DW_FORM_data1
	.section	.debug_info
	.byte		0	; no source file information

	.section	.debug_abbrev
	.uleb128	DW_AT_decl_line
	.uleb128	DW_FORM_data1
	.section	.debug_info
	.byte		0	; no source line information

	.section	.debug_abbrev
	.uleb128	DW_AT_type
	.uleb128	DW_FORM_ref4
	.section	.debug_info
	.long		.Luint8_t - .Lssinfo

	.section	.debug_abbrev
	.uleb128	DW_AT_external
	.uleb128	DW_FORM_flag
	.section	.debug_info
	.byte		1

	.section	.debug_abbrev
	.uleb128	DW_AT_location
	.uleb128	DW_FORM_block1
	.section	.debug_info
	.byte		5	; length of block
	.byte		DW_OP_addr
	.long		0x800000 + 0x800 + 0x2B

	.section	.debug_abbrev
	.uleb128	0
	.uleb128	0

;- - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
	;; DIE #401: variable TCC2_LCMPC
	.section	.debug_info
	.uleb128	401	; ref to abbrev 401
	.section	.debug_abbrev
	.uleb128	401
	.uleb128	DW_TAG_variable
	.byte		DW_CHILDREN_no

	.uleb128	DW_AT_name
	.uleb128	DW_FORM_strp
	.section	.debug_str
.Lname401:
	.string		"TCC2_LCMPC"
	.section	.debug_info
	.long		.Lname401

	.section	.debug_abbrev
	.uleb128	DW_AT_decl_file
	.uleb128	DW_FORM_data1
	.section	.debug_info
	.byte		0	; no source file information

	.section	.debug_abbrev
	.uleb128	DW_AT_decl_line
	.uleb128	DW_FORM_data1
	.section	.debug_info
	.byte		0	; no source line information

	.section	.debug_abbrev
	.uleb128	DW_AT_type
	.uleb128	DW_FORM_ref4
	.section	.debug_info
	.long		.Luint8_t - .Lssinfo

	.section	.debug_abbrev
	.uleb128	DW_AT_external
	.uleb128	DW_FORM_flag
	.section	.debug_info
	.byte		1

	.section	.debug_abbrev
	.uleb128	DW_AT_location
	.uleb128	DW_FORM_block1
	.section	.debug_info
	.byte		5	; length of block
	.byte		DW_OP_addr
	.long		0x800000 + 0x800 + 0x2C

	.section	.debug_abbrev
	.uleb128	0
	.uleb128	0

;- - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
	;; DIE #402: variable TCC2_HCMPC
	.section	.debug_info
	.uleb128	402	; ref to abbrev 402
	.section	.debug_abbrev
	.uleb128	402
	.uleb128	DW_TAG_variable
	.byte		DW_CHILDREN_no

	.uleb128	DW_AT_name
	.uleb128	DW_FORM_strp
	.section	.debug_str
.Lname402:
	.string		"TCC2_HCMPC"
	.section	.debug_info
	.long		.Lname402

	.section	.debug_abbrev
	.uleb128	DW_AT_decl_file
	.uleb128	DW_FORM_data1
	.section	.debug_info
	.byte		0	; no source file information

	.section	.debug_abbrev
	.uleb128	DW_AT_decl_line
	.uleb128	DW_FORM_data1
	.section	.debug_info
	.byte		0	; no source line information

	.section	.debug_abbrev
	.uleb128	DW_AT_type
	.uleb128	DW_FORM_ref4
	.section	.debug_info
	.long		.Luint8_t - .Lssinfo

	.section	.debug_abbrev
	.uleb128	DW_AT_external
	.uleb128	DW_FORM_flag
	.section	.debug_info
	.byte		1

	.section	.debug_abbrev
	.uleb128	DW_AT_location
	.uleb128	DW_FORM_block1
	.section	.debug_info
	.byte		5	; length of block
	.byte		DW_OP_addr
	.long		0x800000 + 0x800 + 0x2D

	.section	.debug_abbrev
	.uleb128	0
	.uleb128	0

;- - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
	;; DIE #403: variable TCC2_LCMPD
	.section	.debug_info
	.uleb128	403	; ref to abbrev 403
	.section	.debug_abbrev
	.uleb128	403
	.uleb128	DW_TAG_variable
	.byte		DW_CHILDREN_no

	.uleb128	DW_AT_name
	.uleb128	DW_FORM_strp
	.section	.debug_str
.Lname403:
	.string		"TCC2_LCMPD"
	.section	.debug_info
	.long		.Lname403

	.section	.debug_abbrev
	.uleb128	DW_AT_decl_file
	.uleb128	DW_FORM_data1
	.section	.debug_info
	.byte		0	; no source file information

	.section	.debug_abbrev
	.uleb128	DW_AT_decl_line
	.uleb128	DW_FORM_data1
	.section	.debug_info
	.byte		0	; no source line information

	.section	.debug_abbrev
	.uleb128	DW_AT_type
	.uleb128	DW_FORM_ref4
	.section	.debug_info
	.long		.Luint8_t - .Lssinfo

	.section	.debug_abbrev
	.uleb128	DW_AT_external
	.uleb128	DW_FORM_flag
	.section	.debug_info
	.byte		1

	.section	.debug_abbrev
	.uleb128	DW_AT_location
	.uleb128	DW_FORM_block1
	.section	.debug_info
	.byte		5	; length of block
	.byte		DW_OP_addr
	.long		0x800000 + 0x800 + 0x2E

	.section	.debug_abbrev
	.uleb128	0
	.uleb128	0

;- - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
	;; DIE #404: variable TCC2_HCMPD
	.section	.debug_info
	.uleb128	404	; ref to abbrev 404
	.section	.debug_abbrev
	.uleb128	404
	.uleb128	DW_TAG_variable
	.byte		DW_CHILDREN_no

	.uleb128	DW_AT_name
	.uleb128	DW_FORM_strp
	.section	.debug_str
.Lname404:
	.string		"TCC2_HCMPD"
	.section	.debug_info
	.long		.Lname404

	.section	.debug_abbrev
	.uleb128	DW_AT_decl_file
	.uleb128	DW_FORM_data1
	.section	.debug_info
	.byte		0	; no source file information

	.section	.debug_abbrev
	.uleb128	DW_AT_decl_line
	.uleb128	DW_FORM_data1
	.section	.debug_info
	.byte		0	; no source line information

	.section	.debug_abbrev
	.uleb128	DW_AT_type
	.uleb128	DW_FORM_ref4
	.section	.debug_info
	.long		.Luint8_t - .Lssinfo

	.section	.debug_abbrev
	.uleb128	DW_AT_external
	.uleb128	DW_FORM_flag
	.section	.debug_info
	.byte		1

	.section	.debug_abbrev
	.uleb128	DW_AT_location
	.uleb128	DW_FORM_block1
	.section	.debug_info
	.byte		5	; length of block
	.byte		DW_OP_addr
	.long		0x800000 + 0x800 + 0x2F

	.section	.debug_abbrev
	.uleb128	0
	.uleb128	0

;- - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
	;; DIE #405: variable TCD2_CTRLA
	.section	.debug_info
	.uleb128	405	; ref to abbrev 405
	.section	.debug_abbrev
	.uleb128	405
	.uleb128	DW_TAG_variable
	.byte		DW_CHILDREN_no

	.uleb128	DW_AT_name
	.uleb128	DW_FORM_strp
	.section	.debug_str
.Lname405:
	.string		"TCD2_CTRLA"
	.section	.debug_info
	.long		.Lname405

	.section	.debug_abbrev
	.uleb128	DW_AT_decl_file
	.uleb128	DW_FORM_data1
	.section	.debug_info
	.byte		0	; no source file information

	.section	.debug_abbrev
	.uleb128	DW_AT_decl_line
	.uleb128	DW_FORM_data1
	.section	.debug_info
	.byte		0	; no source line information

	.section	.debug_abbrev
	.uleb128	DW_AT_type
	.uleb128	DW_FORM_ref4
	.section	.debug_info
	.long		.Luint8_t - .Lssinfo

	.section	.debug_abbrev
	.uleb128	DW_AT_external
	.uleb128	DW_FORM_flag
	.section	.debug_info
	.byte		1

	.section	.debug_abbrev
	.uleb128	DW_AT_location
	.uleb128	DW_FORM_block1
	.section	.debug_info
	.byte		5	; length of block
	.byte		DW_OP_addr
	.long		0x800000 + 0x900 + 0x00

	.section	.debug_abbrev
	.uleb128	0
	.uleb128	0

;- - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
	;; DIE #406: variable TCD2_CTRLB
	.section	.debug_info
	.uleb128	406	; ref to abbrev 406
	.section	.debug_abbrev
	.uleb128	406
	.uleb128	DW_TAG_variable
	.byte		DW_CHILDREN_no

	.uleb128	DW_AT_name
	.uleb128	DW_FORM_strp
	.section	.debug_str
.Lname406:
	.string		"TCD2_CTRLB"
	.section	.debug_info
	.long		.Lname406

	.section	.debug_abbrev
	.uleb128	DW_AT_decl_file
	.uleb128	DW_FORM_data1
	.section	.debug_info
	.byte		0	; no source file information

	.section	.debug_abbrev
	.uleb128	DW_AT_decl_line
	.uleb128	DW_FORM_data1
	.section	.debug_info
	.byte		0	; no source line information

	.section	.debug_abbrev
	.uleb128	DW_AT_type
	.uleb128	DW_FORM_ref4
	.section	.debug_info
	.long		.Luint8_t - .Lssinfo

	.section	.debug_abbrev
	.uleb128	DW_AT_external
	.uleb128	DW_FORM_flag
	.section	.debug_info
	.byte		1

	.section	.debug_abbrev
	.uleb128	DW_AT_location
	.uleb128	DW_FORM_block1
	.section	.debug_info
	.byte		5	; length of block
	.byte		DW_OP_addr
	.long		0x800000 + 0x900 + 0x01

	.section	.debug_abbrev
	.uleb128	0
	.uleb128	0

;- - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
	;; DIE #407: variable TCD2_CTRLC
	.section	.debug_info
	.uleb128	407	; ref to abbrev 407
	.section	.debug_abbrev
	.uleb128	407
	.uleb128	DW_TAG_variable
	.byte		DW_CHILDREN_no

	.uleb128	DW_AT_name
	.uleb128	DW_FORM_strp
	.section	.debug_str
.Lname407:
	.string		"TCD2_CTRLC"
	.section	.debug_info
	.long		.Lname407

	.section	.debug_abbrev
	.uleb128	DW_AT_decl_file
	.uleb128	DW_FORM_data1
	.section	.debug_info
	.byte		0	; no source file information

	.section	.debug_abbrev
	.uleb128	DW_AT_decl_line
	.uleb128	DW_FORM_data1
	.section	.debug_info
	.byte		0	; no source line information

	.section	.debug_abbrev
	.uleb128	DW_AT_type
	.uleb128	DW_FORM_ref4
	.section	.debug_info
	.long		.Luint8_t - .Lssinfo

	.section	.debug_abbrev
	.uleb128	DW_AT_external
	.uleb128	DW_FORM_flag
	.section	.debug_info
	.byte		1

	.section	.debug_abbrev
	.uleb128	DW_AT_location
	.uleb128	DW_FORM_block1
	.section	.debug_info
	.byte		5	; length of block
	.byte		DW_OP_addr
	.long		0x800000 + 0x900 + 0x02

	.section	.debug_abbrev
	.uleb128	0
	.uleb128	0

;- - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
	;; DIE #408: variable TCD2_CTRLE
	.section	.debug_info
	.uleb128	408	; ref to abbrev 408
	.section	.debug_abbrev
	.uleb128	408
	.uleb128	DW_TAG_variable
	.byte		DW_CHILDREN_no

	.uleb128	DW_AT_name
	.uleb128	DW_FORM_strp
	.section	.debug_str
.Lname408:
	.string		"TCD2_CTRLE"
	.section	.debug_info
	.long		.Lname408

	.section	.debug_abbrev
	.uleb128	DW_AT_decl_file
	.uleb128	DW_FORM_data1
	.section	.debug_info
	.byte		0	; no source file information

	.section	.debug_abbrev
	.uleb128	DW_AT_decl_line
	.uleb128	DW_FORM_data1
	.section	.debug_info
	.byte		0	; no source line information

	.section	.debug_abbrev
	.uleb128	DW_AT_type
	.uleb128	DW_FORM_ref4
	.section	.debug_info
	.long		.Luint8_t - .Lssinfo

	.section	.debug_abbrev
	.uleb128	DW_AT_external
	.uleb128	DW_FORM_flag
	.section	.debug_info
	.byte		1

	.section	.debug_abbrev
	.uleb128	DW_AT_location
	.uleb128	DW_FORM_block1
	.section	.debug_info
	.byte		5	; length of block
	.byte		DW_OP_addr
	.long		0x800000 + 0x900 + 0x04

	.section	.debug_abbrev
	.uleb128	0
	.uleb128	0

;- - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
	;; DIE #409: variable TCD2_INTCTRLA
	.section	.debug_info
	.uleb128	409	; ref to abbrev 409
	.section	.debug_abbrev
	.uleb128	409
	.uleb128	DW_TAG_variable
	.byte		DW_CHILDREN_no

	.uleb128	DW_AT_name
	.uleb128	DW_FORM_strp
	.section	.debug_str
.Lname409:
	.string		"TCD2_INTCTRLA"
	.section	.debug_info
	.long		.Lname409

	.section	.debug_abbrev
	.uleb128	DW_AT_decl_file
	.uleb128	DW_FORM_data1
	.section	.debug_info
	.byte		0	; no source file information

	.section	.debug_abbrev
	.uleb128	DW_AT_decl_line
	.uleb128	DW_FORM_data1
	.section	.debug_info
	.byte		0	; no source line information

	.section	.debug_abbrev
	.uleb128	DW_AT_type
	.uleb128	DW_FORM_ref4
	.section	.debug_info
	.long		.Luint8_t - .Lssinfo

	.section	.debug_abbrev
	.uleb128	DW_AT_external
	.uleb128	DW_FORM_flag
	.section	.debug_info
	.byte		1

	.section	.debug_abbrev
	.uleb128	DW_AT_location
	.uleb128	DW_FORM_block1
	.section	.debug_info
	.byte		5	; length of block
	.byte		DW_OP_addr
	.long		0x800000 + 0x900 + 0x06

	.section	.debug_abbrev
	.uleb128	0
	.uleb128	0

;- - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
	;; DIE #410: variable TCD2_INTCTRLB
	.section	.debug_info
	.uleb128	410	; ref to abbrev 410
	.section	.debug_abbrev
	.uleb128	410
	.uleb128	DW_TAG_variable
	.byte		DW_CHILDREN_no

	.uleb128	DW_AT_name
	.uleb128	DW_FORM_strp
	.section	.debug_str
.Lname410:
	.string		"TCD2_INTCTRLB"
	.section	.debug_info
	.long		.Lname410

	.section	.debug_abbrev
	.uleb128	DW_AT_decl_file
	.uleb128	DW_FORM_data1
	.section	.debug_info
	.byte		0	; no source file information

	.section	.debug_abbrev
	.uleb128	DW_AT_decl_line
	.uleb128	DW_FORM_data1
	.section	.debug_info
	.byte		0	; no source line information

	.section	.debug_abbrev
	.uleb128	DW_AT_type
	.uleb128	DW_FORM_ref4
	.section	.debug_info
	.long		.Luint8_t - .Lssinfo

	.section	.debug_abbrev
	.uleb128	DW_AT_external
	.uleb128	DW_FORM_flag
	.section	.debug_info
	.byte		1

	.section	.debug_abbrev
	.uleb128	DW_AT_location
	.uleb128	DW_FORM_block1
	.section	.debug_info
	.byte		5	; length of block
	.byte		DW_OP_addr
	.long		0x800000 + 0x900 + 0x07

	.section	.debug_abbrev
	.uleb128	0
	.uleb128	0

;- - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
	;; DIE #411: variable TCD2_CTRLF
	.section	.debug_info
	.uleb128	411	; ref to abbrev 411
	.section	.debug_abbrev
	.uleb128	411
	.uleb128	DW_TAG_variable
	.byte		DW_CHILDREN_no

	.uleb128	DW_AT_name
	.uleb128	DW_FORM_strp
	.section	.debug_str
.Lname411:
	.string		"TCD2_CTRLF"
	.section	.debug_info
	.long		.Lname411

	.section	.debug_abbrev
	.uleb128	DW_AT_decl_file
	.uleb128	DW_FORM_data1
	.section	.debug_info
	.byte		0	; no source file information

	.section	.debug_abbrev
	.uleb128	DW_AT_decl_line
	.uleb128	DW_FORM_data1
	.section	.debug_info
	.byte		0	; no source line information

	.section	.debug_abbrev
	.uleb128	DW_AT_type
	.uleb128	DW_FORM_ref4
	.section	.debug_info
	.long		.Luint8_t - .Lssinfo

	.section	.debug_abbrev
	.uleb128	DW_AT_external
	.uleb128	DW_FORM_flag
	.section	.debug_info
	.byte		1

	.section	.debug_abbrev
	.uleb128	DW_AT_location
	.uleb128	DW_FORM_block1
	.section	.debug_info
	.byte		5	; length of block
	.byte		DW_OP_addr
	.long		0x800000 + 0x900 + 0x09

	.section	.debug_abbrev
	.uleb128	0
	.uleb128	0

;- - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
	;; DIE #412: variable TCD2_INTFLAGS
	.section	.debug_info
	.uleb128	412	; ref to abbrev 412
	.section	.debug_abbrev
	.uleb128	412
	.uleb128	DW_TAG_variable
	.byte		DW_CHILDREN_no

	.uleb128	DW_AT_name
	.uleb128	DW_FORM_strp
	.section	.debug_str
.Lname412:
	.string		"TCD2_INTFLAGS"
	.section	.debug_info
	.long		.Lname412

	.section	.debug_abbrev
	.uleb128	DW_AT_decl_file
	.uleb128	DW_FORM_data1
	.section	.debug_info
	.byte		0	; no source file information

	.section	.debug_abbrev
	.uleb128	DW_AT_decl_line
	.uleb128	DW_FORM_data1
	.section	.debug_info
	.byte		0	; no source line information

	.section	.debug_abbrev
	.uleb128	DW_AT_type
	.uleb128	DW_FORM_ref4
	.section	.debug_info
	.long		.Luint8_t - .Lssinfo

	.section	.debug_abbrev
	.uleb128	DW_AT_external
	.uleb128	DW_FORM_flag
	.section	.debug_info
	.byte		1

	.section	.debug_abbrev
	.uleb128	DW_AT_location
	.uleb128	DW_FORM_block1
	.section	.debug_info
	.byte		5	; length of block
	.byte		DW_OP_addr
	.long		0x800000 + 0x900 + 0x0C

	.section	.debug_abbrev
	.uleb128	0
	.uleb128	0

;- - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
	;; DIE #413: variable TCD2_LCNT
	.section	.debug_info
	.uleb128	413	; ref to abbrev 413
	.section	.debug_abbrev
	.uleb128	413
	.uleb128	DW_TAG_variable
	.byte		DW_CHILDREN_no

	.uleb128	DW_AT_name
	.uleb128	DW_FORM_strp
	.section	.debug_str
.Lname413:
	.string		"TCD2_LCNT"
	.section	.debug_info
	.long		.Lname413

	.section	.debug_abbrev
	.uleb128	DW_AT_decl_file
	.uleb128	DW_FORM_data1
	.section	.debug_info
	.byte		0	; no source file information

	.section	.debug_abbrev
	.uleb128	DW_AT_decl_line
	.uleb128	DW_FORM_data1
	.section	.debug_info
	.byte		0	; no source line information

	.section	.debug_abbrev
	.uleb128	DW_AT_type
	.uleb128	DW_FORM_ref4
	.section	.debug_info
	.long		.Luint8_t - .Lssinfo

	.section	.debug_abbrev
	.uleb128	DW_AT_external
	.uleb128	DW_FORM_flag
	.section	.debug_info
	.byte		1

	.section	.debug_abbrev
	.uleb128	DW_AT_location
	.uleb128	DW_FORM_block1
	.section	.debug_info
	.byte		5	; length of block
	.byte		DW_OP_addr
	.long		0x800000 + 0x900 + 0x20

	.section	.debug_abbrev
	.uleb128	0
	.uleb128	0

;- - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
	;; DIE #414: variable TCD2_HCNT
	.section	.debug_info
	.uleb128	414	; ref to abbrev 414
	.section	.debug_abbrev
	.uleb128	414
	.uleb128	DW_TAG_variable
	.byte		DW_CHILDREN_no

	.uleb128	DW_AT_name
	.uleb128	DW_FORM_strp
	.section	.debug_str
.Lname414:
	.string		"TCD2_HCNT"
	.section	.debug_info
	.long		.Lname414

	.section	.debug_abbrev
	.uleb128	DW_AT_decl_file
	.uleb128	DW_FORM_data1
	.section	.debug_info
	.byte		0	; no source file information

	.section	.debug_abbrev
	.uleb128	DW_AT_decl_line
	.uleb128	DW_FORM_data1
	.section	.debug_info
	.byte		0	; no source line information

	.section	.debug_abbrev
	.uleb128	DW_AT_type
	.uleb128	DW_FORM_ref4
	.section	.debug_info
	.long		.Luint8_t - .Lssinfo

	.section	.debug_abbrev
	.uleb128	DW_AT_external
	.uleb128	DW_FORM_flag
	.section	.debug_info
	.byte		1

	.section	.debug_abbrev
	.uleb128	DW_AT_location
	.uleb128	DW_FORM_block1
	.section	.debug_info
	.byte		5	; length of block
	.byte		DW_OP_addr
	.long		0x800000 + 0x900 + 0x21

	.section	.debug_abbrev
	.uleb128	0
	.uleb128	0

;- - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
	;; DIE #415: variable TCD2_LPER
	.section	.debug_info
	.uleb128	415	; ref to abbrev 415
	.section	.debug_abbrev
	.uleb128	415
	.uleb128	DW_TAG_variable
	.byte		DW_CHILDREN_no

	.uleb128	DW_AT_name
	.uleb128	DW_FORM_strp
	.section	.debug_str
.Lname415:
	.string		"TCD2_LPER"
	.section	.debug_info
	.long		.Lname415

	.section	.debug_abbrev
	.uleb128	DW_AT_decl_file
	.uleb128	DW_FORM_data1
	.section	.debug_info
	.byte		0	; no source file information

	.section	.debug_abbrev
	.uleb128	DW_AT_decl_line
	.uleb128	DW_FORM_data1
	.section	.debug_info
	.byte		0	; no source line information

	.section	.debug_abbrev
	.uleb128	DW_AT_type
	.uleb128	DW_FORM_ref4
	.section	.debug_info
	.long		.Luint8_t - .Lssinfo

	.section	.debug_abbrev
	.uleb128	DW_AT_external
	.uleb128	DW_FORM_flag
	.section	.debug_info
	.byte		1

	.section	.debug_abbrev
	.uleb128	DW_AT_location
	.uleb128	DW_FORM_block1
	.section	.debug_info
	.byte		5	; length of block
	.byte		DW_OP_addr
	.long		0x800000 + 0x900 + 0x26

	.section	.debug_abbrev
	.uleb128	0
	.uleb128	0

;- - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
	;; DIE #416: variable TCD2_HPER
	.section	.debug_info
	.uleb128	416	; ref to abbrev 416
	.section	.debug_abbrev
	.uleb128	416
	.uleb128	DW_TAG_variable
	.byte		DW_CHILDREN_no

	.uleb128	DW_AT_name
	.uleb128	DW_FORM_strp
	.section	.debug_str
.Lname416:
	.string		"TCD2_HPER"
	.section	.debug_info
	.long		.Lname416

	.section	.debug_abbrev
	.uleb128	DW_AT_decl_file
	.uleb128	DW_FORM_data1
	.section	.debug_info
	.byte		0	; no source file information

	.section	.debug_abbrev
	.uleb128	DW_AT_decl_line
	.uleb128	DW_FORM_data1
	.section	.debug_info
	.byte		0	; no source line information

	.section	.debug_abbrev
	.uleb128	DW_AT_type
	.uleb128	DW_FORM_ref4
	.section	.debug_info
	.long		.Luint8_t - .Lssinfo

	.section	.debug_abbrev
	.uleb128	DW_AT_external
	.uleb128	DW_FORM_flag
	.section	.debug_info
	.byte		1

	.section	.debug_abbrev
	.uleb128	DW_AT_location
	.uleb128	DW_FORM_block1
	.section	.debug_info
	.byte		5	; length of block
	.byte		DW_OP_addr
	.long		0x800000 + 0x900 + 0x27

	.section	.debug_abbrev
	.uleb128	0
	.uleb128	0

;- - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
	;; DIE #417: variable TCD2_LCMPA
	.section	.debug_info
	.uleb128	417	; ref to abbrev 417
	.section	.debug_abbrev
	.uleb128	417
	.uleb128	DW_TAG_variable
	.byte		DW_CHILDREN_no

	.uleb128	DW_AT_name
	.uleb128	DW_FORM_strp
	.section	.debug_str
.Lname417:
	.string		"TCD2_LCMPA"
	.section	.debug_info
	.long		.Lname417

	.section	.debug_abbrev
	.uleb128	DW_AT_decl_file
	.uleb128	DW_FORM_data1
	.section	.debug_info
	.byte		0	; no source file information

	.section	.debug_abbrev
	.uleb128	DW_AT_decl_line
	.uleb128	DW_FORM_data1
	.section	.debug_info
	.byte		0	; no source line information

	.section	.debug_abbrev
	.uleb128	DW_AT_type
	.uleb128	DW_FORM_ref4
	.section	.debug_info
	.long		.Luint8_t - .Lssinfo

	.section	.debug_abbrev
	.uleb128	DW_AT_external
	.uleb128	DW_FORM_flag
	.section	.debug_info
	.byte		1

	.section	.debug_abbrev
	.uleb128	DW_AT_location
	.uleb128	DW_FORM_block1
	.section	.debug_info
	.byte		5	; length of block
	.byte		DW_OP_addr
	.long		0x800000 + 0x900 + 0x28

	.section	.debug_abbrev
	.uleb128	0
	.uleb128	0

;- - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
	;; DIE #418: variable TCD2_HCMPA
	.section	.debug_info
	.uleb128	418	; ref to abbrev 418
	.section	.debug_abbrev
	.uleb128	418
	.uleb128	DW_TAG_variable
	.byte		DW_CHILDREN_no

	.uleb128	DW_AT_name
	.uleb128	DW_FORM_strp
	.section	.debug_str
.Lname418:
	.string		"TCD2_HCMPA"
	.section	.debug_info
	.long		.Lname418

	.section	.debug_abbrev
	.uleb128	DW_AT_decl_file
	.uleb128	DW_FORM_data1
	.section	.debug_info
	.byte		0	; no source file information

	.section	.debug_abbrev
	.uleb128	DW_AT_decl_line
	.uleb128	DW_FORM_data1
	.section	.debug_info
	.byte		0	; no source line information

	.section	.debug_abbrev
	.uleb128	DW_AT_type
	.uleb128	DW_FORM_ref4
	.section	.debug_info
	.long		.Luint8_t - .Lssinfo

	.section	.debug_abbrev
	.uleb128	DW_AT_external
	.uleb128	DW_FORM_flag
	.section	.debug_info
	.byte		1

	.section	.debug_abbrev
	.uleb128	DW_AT_location
	.uleb128	DW_FORM_block1
	.section	.debug_info
	.byte		5	; length of block
	.byte		DW_OP_addr
	.long		0x800000 + 0x900 + 0x29

	.section	.debug_abbrev
	.uleb128	0
	.uleb128	0

;- - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
	;; DIE #419: variable TCD2_LCMPB
	.section	.debug_info
	.uleb128	419	; ref to abbrev 419
	.section	.debug_abbrev
	.uleb128	419
	.uleb128	DW_TAG_variable
	.byte		DW_CHILDREN_no

	.uleb128	DW_AT_name
	.uleb128	DW_FORM_strp
	.section	.debug_str
.Lname419:
	.string		"TCD2_LCMPB"
	.section	.debug_info
	.long		.Lname419

	.section	.debug_abbrev
	.uleb128	DW_AT_decl_file
	.uleb128	DW_FORM_data1
	.section	.debug_info
	.byte		0	; no source file information

	.section	.debug_abbrev
	.uleb128	DW_AT_decl_line
	.uleb128	DW_FORM_data1
	.section	.debug_info
	.byte		0	; no source line information

	.section	.debug_abbrev
	.uleb128	DW_AT_type
	.uleb128	DW_FORM_ref4
	.section	.debug_info
	.long		.Luint8_t - .Lssinfo

	.section	.debug_abbrev
	.uleb128	DW_AT_external
	.uleb128	DW_FORM_flag
	.section	.debug_info
	.byte		1

	.section	.debug_abbrev
	.uleb128	DW_AT_location
	.uleb128	DW_FORM_block1
	.section	.debug_info
	.byte		5	; length of block
	.byte		DW_OP_addr
	.long		0x800000 + 0x900 + 0x2A

	.section	.debug_abbrev
	.uleb128	0
	.uleb128	0

;- - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
	;; DIE #420: variable TCD2_HCMPB
	.section	.debug_info
	.uleb128	420	; ref to abbrev 420
	.section	.debug_abbrev
	.uleb128	420
	.uleb128	DW_TAG_variable
	.byte		DW_CHILDREN_no

	.uleb128	DW_AT_name
	.uleb128	DW_FORM_strp
	.section	.debug_str
.Lname420:
	.string		"TCD2_HCMPB"
	.section	.debug_info
	.long		.Lname420

	.section	.debug_abbrev
	.uleb128	DW_AT_decl_file
	.uleb128	DW_FORM_data1
	.section	.debug_info
	.byte		0	; no source file information

	.section	.debug_abbrev
	.uleb128	DW_AT_decl_line
	.uleb128	DW_FORM_data1
	.section	.debug_info
	.byte		0	; no source line information

	.section	.debug_abbrev
	.uleb128	DW_AT_type
	.uleb128	DW_FORM_ref4
	.section	.debug_info
	.long		.Luint8_t - .Lssinfo

	.section	.debug_abbrev
	.uleb128	DW_AT_external
	.uleb128	DW_FORM_flag
	.section	.debug_info
	.byte		1

	.section	.debug_abbrev
	.uleb128	DW_AT_location
	.uleb128	DW_FORM_block1
	.section	.debug_info
	.byte		5	; length of block
	.byte		DW_OP_addr
	.long		0x800000 + 0x900 + 0x2B

	.section	.debug_abbrev
	.uleb128	0
	.uleb128	0

;- - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
	;; DIE #421: variable TCD2_LCMPC
	.section	.debug_info
	.uleb128	421	; ref to abbrev 421
	.section	.debug_abbrev
	.uleb128	421
	.uleb128	DW_TAG_variable
	.byte		DW_CHILDREN_no

	.uleb128	DW_AT_name
	.uleb128	DW_FORM_strp
	.section	.debug_str
.Lname421:
	.string		"TCD2_LCMPC"
	.section	.debug_info
	.long		.Lname421

	.section	.debug_abbrev
	.uleb128	DW_AT_decl_file
	.uleb128	DW_FORM_data1
	.section	.debug_info
	.byte		0	; no source file information

	.section	.debug_abbrev
	.uleb128	DW_AT_decl_line
	.uleb128	DW_FORM_data1
	.section	.debug_info
	.byte		0	; no source line information

	.section	.debug_abbrev
	.uleb128	DW_AT_type
	.uleb128	DW_FORM_ref4
	.section	.debug_info
	.long		.Luint8_t - .Lssinfo

	.section	.debug_abbrev
	.uleb128	DW_AT_external
	.uleb128	DW_FORM_flag
	.section	.debug_info
	.byte		1

	.section	.debug_abbrev
	.uleb128	DW_AT_location
	.uleb128	DW_FORM_block1
	.section	.debug_info
	.byte		5	; length of block
	.byte		DW_OP_addr
	.long		0x800000 + 0x900 + 0x2C

	.section	.debug_abbrev
	.uleb128	0
	.uleb128	0

;- - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
	;; DIE #422: variable TCD2_HCMPC
	.section	.debug_info
	.uleb128	422	; ref to abbrev 422
	.section	.debug_abbrev
	.uleb128	422
	.uleb128	DW_TAG_variable
	.byte		DW_CHILDREN_no

	.uleb128	DW_AT_name
	.uleb128	DW_FORM_strp
	.section	.debug_str
.Lname422:
	.string		"TCD2_HCMPC"
	.section	.debug_info
	.long		.Lname422

	.section	.debug_abbrev
	.uleb128	DW_AT_decl_file
	.uleb128	DW_FORM_data1
	.section	.debug_info
	.byte		0	; no source file information

	.section	.debug_abbrev
	.uleb128	DW_AT_decl_line
	.uleb128	DW_FORM_data1
	.section	.debug_info
	.byte		0	; no source line information

	.section	.debug_abbrev
	.uleb128	DW_AT_type
	.uleb128	DW_FORM_ref4
	.section	.debug_info
	.long		.Luint8_t - .Lssinfo

	.section	.debug_abbrev
	.uleb128	DW_AT_external
	.uleb128	DW_FORM_flag
	.section	.debug_info
	.byte		1

	.section	.debug_abbrev
	.uleb128	DW_AT_location
	.uleb128	DW_FORM_block1
	.section	.debug_info
	.byte		5	; length of block
	.byte		DW_OP_addr
	.long		0x800000 + 0x900 + 0x2D

	.section	.debug_abbrev
	.uleb128	0
	.uleb128	0

;- - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
	;; DIE #423: variable TCD2_LCMPD
	.section	.debug_info
	.uleb128	423	; ref to abbrev 423
	.section	.debug_abbrev
	.uleb128	423
	.uleb128	DW_TAG_variable
	.byte		DW_CHILDREN_no

	.uleb128	DW_AT_name
	.uleb128	DW_FORM_strp
	.section	.debug_str
.Lname423:
	.string		"TCD2_LCMPD"
	.section	.debug_info
	.long		.Lname423

	.section	.debug_abbrev
	.uleb128	DW_AT_decl_file
	.uleb128	DW_FORM_data1
	.section	.debug_info
	.byte		0	; no source file information

	.section	.debug_abbrev
	.uleb128	DW_AT_decl_line
	.uleb128	DW_FORM_data1
	.section	.debug_info
	.byte		0	; no source line information

	.section	.debug_abbrev
	.uleb128	DW_AT_type
	.uleb128	DW_FORM_ref4
	.section	.debug_info
	.long		.Luint8_t - .Lssinfo

	.section	.debug_abbrev
	.uleb128	DW_AT_external
	.uleb128	DW_FORM_flag
	.section	.debug_info
	.byte		1

	.section	.debug_abbrev
	.uleb128	DW_AT_location
	.uleb128	DW_FORM_block1
	.section	.debug_info
	.byte		5	; length of block
	.byte		DW_OP_addr
	.long		0x800000 + 0x900 + 0x2E

	.section	.debug_abbrev
	.uleb128	0
	.uleb128	0

;- - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
	;; DIE #424: variable TCD2_HCMPD
	.section	.debug_info
	.uleb128	424	; ref to abbrev 424
	.section	.debug_abbrev
	.uleb128	424
	.uleb128	DW_TAG_variable
	.byte		DW_CHILDREN_no

	.uleb128	DW_AT_name
	.uleb128	DW_FORM_strp
	.section	.debug_str
.Lname424:
	.string		"TCD2_HCMPD"
	.section	.debug_info
	.long		.Lname424

	.section	.debug_abbrev
	.uleb128	DW_AT_decl_file
	.uleb128	DW_FORM_data1
	.section	.debug_info
	.byte		0	; no source file information

	.section	.debug_abbrev
	.uleb128	DW_AT_decl_line
	.uleb128	DW_FORM_data1
	.section	.debug_info
	.byte		0	; no source line information

	.section	.debug_abbrev
	.uleb128	DW_AT_type
	.uleb128	DW_FORM_ref4
	.section	.debug_info
	.long		.Luint8_t - .Lssinfo

	.section	.debug_abbrev
	.uleb128	DW_AT_external
	.uleb128	DW_FORM_flag
	.section	.debug_info
	.byte		1

	.section	.debug_abbrev
	.uleb128	DW_AT_location
	.uleb128	DW_FORM_block1
	.section	.debug_info
	.byte		5	; length of block
	.byte		DW_OP_addr
	.long		0x800000 + 0x900 + 0x2F

	.section	.debug_abbrev
	.uleb128	0
	.uleb128	0

;- - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
	;; DIE #425: variable AWEXC_CTRL
	.section	.debug_info
	.uleb128	425	; ref to abbrev 425
	.section	.debug_abbrev
	.uleb128	425
	.uleb128	DW_TAG_variable
	.byte		DW_CHILDREN_no

	.uleb128	DW_AT_name
	.uleb128	DW_FORM_strp
	.section	.debug_str
.Lname425:
	.string		"AWEXC_CTRL"
	.section	.debug_info
	.long		.Lname425

	.section	.debug_abbrev
	.uleb128	DW_AT_decl_file
	.uleb128	DW_FORM_data1
	.section	.debug_info
	.byte		0	; no source file information

	.section	.debug_abbrev
	.uleb128	DW_AT_decl_line
	.uleb128	DW_FORM_data1
	.section	.debug_info
	.byte		0	; no source line information

	.section	.debug_abbrev
	.uleb128	DW_AT_type
	.uleb128	DW_FORM_ref4
	.section	.debug_info
	.long		.Luint8_t - .Lssinfo

	.section	.debug_abbrev
	.uleb128	DW_AT_external
	.uleb128	DW_FORM_flag
	.section	.debug_info
	.byte		1

	.section	.debug_abbrev
	.uleb128	DW_AT_location
	.uleb128	DW_FORM_block1
	.section	.debug_info
	.byte		5	; length of block
	.byte		DW_OP_addr
	.long		0x800000 + 0x880 + 0x00

	.section	.debug_abbrev
	.uleb128	0
	.uleb128	0

;- - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
	;; DIE #426: variable AWEXC_FDEMASK
	.section	.debug_info
	.uleb128	426	; ref to abbrev 426
	.section	.debug_abbrev
	.uleb128	426
	.uleb128	DW_TAG_variable
	.byte		DW_CHILDREN_no

	.uleb128	DW_AT_name
	.uleb128	DW_FORM_strp
	.section	.debug_str
.Lname426:
	.string		"AWEXC_FDEMASK"
	.section	.debug_info
	.long		.Lname426

	.section	.debug_abbrev
	.uleb128	DW_AT_decl_file
	.uleb128	DW_FORM_data1
	.section	.debug_info
	.byte		0	; no source file information

	.section	.debug_abbrev
	.uleb128	DW_AT_decl_line
	.uleb128	DW_FORM_data1
	.section	.debug_info
	.byte		0	; no source line information

	.section	.debug_abbrev
	.uleb128	DW_AT_type
	.uleb128	DW_FORM_ref4
	.section	.debug_info
	.long		.Luint8_t - .Lssinfo

	.section	.debug_abbrev
	.uleb128	DW_AT_external
	.uleb128	DW_FORM_flag
	.section	.debug_info
	.byte		1

	.section	.debug_abbrev
	.uleb128	DW_AT_location
	.uleb128	DW_FORM_block1
	.section	.debug_info
	.byte		5	; length of block
	.byte		DW_OP_addr
	.long		0x800000 + 0x880 + 0x02

	.section	.debug_abbrev
	.uleb128	0
	.uleb128	0

;- - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
	;; DIE #427: variable AWEXC_FDCTRL
	.section	.debug_info
	.uleb128	427	; ref to abbrev 427
	.section	.debug_abbrev
	.uleb128	427
	.uleb128	DW_TAG_variable
	.byte		DW_CHILDREN_no

	.uleb128	DW_AT_name
	.uleb128	DW_FORM_strp
	.section	.debug_str
.Lname427:
	.string		"AWEXC_FDCTRL"
	.section	.debug_info
	.long		.Lname427

	.section	.debug_abbrev
	.uleb128	DW_AT_decl_file
	.uleb128	DW_FORM_data1
	.section	.debug_info
	.byte		0	; no source file information

	.section	.debug_abbrev
	.uleb128	DW_AT_decl_line
	.uleb128	DW_FORM_data1
	.section	.debug_info
	.byte		0	; no source line information

	.section	.debug_abbrev
	.uleb128	DW_AT_type
	.uleb128	DW_FORM_ref4
	.section	.debug_info
	.long		.Luint8_t - .Lssinfo

	.section	.debug_abbrev
	.uleb128	DW_AT_external
	.uleb128	DW_FORM_flag
	.section	.debug_info
	.byte		1

	.section	.debug_abbrev
	.uleb128	DW_AT_location
	.uleb128	DW_FORM_block1
	.section	.debug_info
	.byte		5	; length of block
	.byte		DW_OP_addr
	.long		0x800000 + 0x880 + 0x03

	.section	.debug_abbrev
	.uleb128	0
	.uleb128	0

;- - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
	;; DIE #428: variable AWEXC_STATUS
	.section	.debug_info
	.uleb128	428	; ref to abbrev 428
	.section	.debug_abbrev
	.uleb128	428
	.uleb128	DW_TAG_variable
	.byte		DW_CHILDREN_no

	.uleb128	DW_AT_name
	.uleb128	DW_FORM_strp
	.section	.debug_str
.Lname428:
	.string		"AWEXC_STATUS"
	.section	.debug_info
	.long		.Lname428

	.section	.debug_abbrev
	.uleb128	DW_AT_decl_file
	.uleb128	DW_FORM_data1
	.section	.debug_info
	.byte		0	; no source file information

	.section	.debug_abbrev
	.uleb128	DW_AT_decl_line
	.uleb128	DW_FORM_data1
	.section	.debug_info
	.byte		0	; no source line information

	.section	.debug_abbrev
	.uleb128	DW_AT_type
	.uleb128	DW_FORM_ref4
	.section	.debug_info
	.long		.Luint8_t - .Lssinfo

	.section	.debug_abbrev
	.uleb128	DW_AT_external
	.uleb128	DW_FORM_flag
	.section	.debug_info
	.byte		1

	.section	.debug_abbrev
	.uleb128	DW_AT_location
	.uleb128	DW_FORM_block1
	.section	.debug_info
	.byte		5	; length of block
	.byte		DW_OP_addr
	.long		0x800000 + 0x880 + 0x04

	.section	.debug_abbrev
	.uleb128	0
	.uleb128	0

;- - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
	;; DIE #429: variable AWEXC_STATUSSET
	.section	.debug_info
	.uleb128	429	; ref to abbrev 429
	.section	.debug_abbrev
	.uleb128	429
	.uleb128	DW_TAG_variable
	.byte		DW_CHILDREN_no

	.uleb128	DW_AT_name
	.uleb128	DW_FORM_strp
	.section	.debug_str
.Lname429:
	.string		"AWEXC_STATUSSET"
	.section	.debug_info
	.long		.Lname429

	.section	.debug_abbrev
	.uleb128	DW_AT_decl_file
	.uleb128	DW_FORM_data1
	.section	.debug_info
	.byte		0	; no source file information

	.section	.debug_abbrev
	.uleb128	DW_AT_decl_line
	.uleb128	DW_FORM_data1
	.section	.debug_info
	.byte		0	; no source line information

	.section	.debug_abbrev
	.uleb128	DW_AT_type
	.uleb128	DW_FORM_ref4
	.section	.debug_info
	.long		.Luint8_t - .Lssinfo

	.section	.debug_abbrev
	.uleb128	DW_AT_external
	.uleb128	DW_FORM_flag
	.section	.debug_info
	.byte		1

	.section	.debug_abbrev
	.uleb128	DW_AT_location
	.uleb128	DW_FORM_block1
	.section	.debug_info
	.byte		5	; length of block
	.byte		DW_OP_addr
	.long		0x800000 + 0x880 + 0x05

	.section	.debug_abbrev
	.uleb128	0
	.uleb128	0

;- - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
	;; DIE #430: variable AWEXC_DTBOTH
	.section	.debug_info
	.uleb128	430	; ref to abbrev 430
	.section	.debug_abbrev
	.uleb128	430
	.uleb128	DW_TAG_variable
	.byte		DW_CHILDREN_no

	.uleb128	DW_AT_name
	.uleb128	DW_FORM_strp
	.section	.debug_str
.Lname430:
	.string		"AWEXC_DTBOTH"
	.section	.debug_info
	.long		.Lname430

	.section	.debug_abbrev
	.uleb128	DW_AT_decl_file
	.uleb128	DW_FORM_data1
	.section	.debug_info
	.byte		0	; no source file information

	.section	.debug_abbrev
	.uleb128	DW_AT_decl_line
	.uleb128	DW_FORM_data1
	.section	.debug_info
	.byte		0	; no source line information

	.section	.debug_abbrev
	.uleb128	DW_AT_type
	.uleb128	DW_FORM_ref4
	.section	.debug_info
	.long		.Luint8_t - .Lssinfo

	.section	.debug_abbrev
	.uleb128	DW_AT_external
	.uleb128	DW_FORM_flag
	.section	.debug_info
	.byte		1

	.section	.debug_abbrev
	.uleb128	DW_AT_location
	.uleb128	DW_FORM_block1
	.section	.debug_info
	.byte		5	; length of block
	.byte		DW_OP_addr
	.long		0x800000 + 0x880 + 0x06

	.section	.debug_abbrev
	.uleb128	0
	.uleb128	0

;- - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
	;; DIE #431: variable AWEXC_DTBOTHBUF
	.section	.debug_info
	.uleb128	431	; ref to abbrev 431
	.section	.debug_abbrev
	.uleb128	431
	.uleb128	DW_TAG_variable
	.byte		DW_CHILDREN_no

	.uleb128	DW_AT_name
	.uleb128	DW_FORM_strp
	.section	.debug_str
.Lname431:
	.string		"AWEXC_DTBOTHBUF"
	.section	.debug_info
	.long		.Lname431

	.section	.debug_abbrev
	.uleb128	DW_AT_decl_file
	.uleb128	DW_FORM_data1
	.section	.debug_info
	.byte		0	; no source file information

	.section	.debug_abbrev
	.uleb128	DW_AT_decl_line
	.uleb128	DW_FORM_data1
	.section	.debug_info
	.byte		0	; no source line information

	.section	.debug_abbrev
	.uleb128	DW_AT_type
	.uleb128	DW_FORM_ref4
	.section	.debug_info
	.long		.Luint8_t - .Lssinfo

	.section	.debug_abbrev
	.uleb128	DW_AT_external
	.uleb128	DW_FORM_flag
	.section	.debug_info
	.byte		1

	.section	.debug_abbrev
	.uleb128	DW_AT_location
	.uleb128	DW_FORM_block1
	.section	.debug_info
	.byte		5	; length of block
	.byte		DW_OP_addr
	.long		0x800000 + 0x880 + 0x07

	.section	.debug_abbrev
	.uleb128	0
	.uleb128	0

;- - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
	;; DIE #432: variable AWEXC_DTLS
	.section	.debug_info
	.uleb128	432	; ref to abbrev 432
	.section	.debug_abbrev
	.uleb128	432
	.uleb128	DW_TAG_variable
	.byte		DW_CHILDREN_no

	.uleb128	DW_AT_name
	.uleb128	DW_FORM_strp
	.section	.debug_str
.Lname432:
	.string		"AWEXC_DTLS"
	.section	.debug_info
	.long		.Lname432

	.section	.debug_abbrev
	.uleb128	DW_AT_decl_file
	.uleb128	DW_FORM_data1
	.section	.debug_info
	.byte		0	; no source file information

	.section	.debug_abbrev
	.uleb128	DW_AT_decl_line
	.uleb128	DW_FORM_data1
	.section	.debug_info
	.byte		0	; no source line information

	.section	.debug_abbrev
	.uleb128	DW_AT_type
	.uleb128	DW_FORM_ref4
	.section	.debug_info
	.long		.Luint8_t - .Lssinfo

	.section	.debug_abbrev
	.uleb128	DW_AT_external
	.uleb128	DW_FORM_flag
	.section	.debug_info
	.byte		1

	.section	.debug_abbrev
	.uleb128	DW_AT_location
	.uleb128	DW_FORM_block1
	.section	.debug_info
	.byte		5	; length of block
	.byte		DW_OP_addr
	.long		0x800000 + 0x880 + 0x08

	.section	.debug_abbrev
	.uleb128	0
	.uleb128	0

;- - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
	;; DIE #433: variable AWEXC_DTHS
	.section	.debug_info
	.uleb128	433	; ref to abbrev 433
	.section	.debug_abbrev
	.uleb128	433
	.uleb128	DW_TAG_variable
	.byte		DW_CHILDREN_no

	.uleb128	DW_AT_name
	.uleb128	DW_FORM_strp
	.section	.debug_str
.Lname433:
	.string		"AWEXC_DTHS"
	.section	.debug_info
	.long		.Lname433

	.section	.debug_abbrev
	.uleb128	DW_AT_decl_file
	.uleb128	DW_FORM_data1
	.section	.debug_info
	.byte		0	; no source file information

	.section	.debug_abbrev
	.uleb128	DW_AT_decl_line
	.uleb128	DW_FORM_data1
	.section	.debug_info
	.byte		0	; no source line information

	.section	.debug_abbrev
	.uleb128	DW_AT_type
	.uleb128	DW_FORM_ref4
	.section	.debug_info
	.long		.Luint8_t - .Lssinfo

	.section	.debug_abbrev
	.uleb128	DW_AT_external
	.uleb128	DW_FORM_flag
	.section	.debug_info
	.byte		1

	.section	.debug_abbrev
	.uleb128	DW_AT_location
	.uleb128	DW_FORM_block1
	.section	.debug_info
	.byte		5	; length of block
	.byte		DW_OP_addr
	.long		0x800000 + 0x880 + 0x09

	.section	.debug_abbrev
	.uleb128	0
	.uleb128	0

;- - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
	;; DIE #434: variable AWEXC_DTLSBUF
	.section	.debug_info
	.uleb128	434	; ref to abbrev 434
	.section	.debug_abbrev
	.uleb128	434
	.uleb128	DW_TAG_variable
	.byte		DW_CHILDREN_no

	.uleb128	DW_AT_name
	.uleb128	DW_FORM_strp
	.section	.debug_str
.Lname434:
	.string		"AWEXC_DTLSBUF"
	.section	.debug_info
	.long		.Lname434

	.section	.debug_abbrev
	.uleb128	DW_AT_decl_file
	.uleb128	DW_FORM_data1
	.section	.debug_info
	.byte		0	; no source file information

	.section	.debug_abbrev
	.uleb128	DW_AT_decl_line
	.uleb128	DW_FORM_data1
	.section	.debug_info
	.byte		0	; no source line information

	.section	.debug_abbrev
	.uleb128	DW_AT_type
	.uleb128	DW_FORM_ref4
	.section	.debug_info
	.long		.Luint8_t - .Lssinfo

	.section	.debug_abbrev
	.uleb128	DW_AT_external
	.uleb128	DW_FORM_flag
	.section	.debug_info
	.byte		1

	.section	.debug_abbrev
	.uleb128	DW_AT_location
	.uleb128	DW_FORM_block1
	.section	.debug_info
	.byte		5	; length of block
	.byte		DW_OP_addr
	.long		0x800000 + 0x880 + 0x0A

	.section	.debug_abbrev
	.uleb128	0
	.uleb128	0

;- - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
	;; DIE #435: variable AWEXC_DTHSBUF
	.section	.debug_info
	.uleb128	435	; ref to abbrev 435
	.section	.debug_abbrev
	.uleb128	435
	.uleb128	DW_TAG_variable
	.byte		DW_CHILDREN_no

	.uleb128	DW_AT_name
	.uleb128	DW_FORM_strp
	.section	.debug_str
.Lname435:
	.string		"AWEXC_DTHSBUF"
	.section	.debug_info
	.long		.Lname435

	.section	.debug_abbrev
	.uleb128	DW_AT_decl_file
	.uleb128	DW_FORM_data1
	.section	.debug_info
	.byte		0	; no source file information

	.section	.debug_abbrev
	.uleb128	DW_AT_decl_line
	.uleb128	DW_FORM_data1
	.section	.debug_info
	.byte		0	; no source line information

	.section	.debug_abbrev
	.uleb128	DW_AT_type
	.uleb128	DW_FORM_ref4
	.section	.debug_info
	.long		.Luint8_t - .Lssinfo

	.section	.debug_abbrev
	.uleb128	DW_AT_external
	.uleb128	DW_FORM_flag
	.section	.debug_info
	.byte		1

	.section	.debug_abbrev
	.uleb128	DW_AT_location
	.uleb128	DW_FORM_block1
	.section	.debug_info
	.byte		5	; length of block
	.byte		DW_OP_addr
	.long		0x800000 + 0x880 + 0x0B

	.section	.debug_abbrev
	.uleb128	0
	.uleb128	0

;- - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
	;; DIE #436: variable AWEXC_OUTOVEN
	.section	.debug_info
	.uleb128	436	; ref to abbrev 436
	.section	.debug_abbrev
	.uleb128	436
	.uleb128	DW_TAG_variable
	.byte		DW_CHILDREN_no

	.uleb128	DW_AT_name
	.uleb128	DW_FORM_strp
	.section	.debug_str
.Lname436:
	.string		"AWEXC_OUTOVEN"
	.section	.debug_info
	.long		.Lname436

	.section	.debug_abbrev
	.uleb128	DW_AT_decl_file
	.uleb128	DW_FORM_data1
	.section	.debug_info
	.byte		0	; no source file information

	.section	.debug_abbrev
	.uleb128	DW_AT_decl_line
	.uleb128	DW_FORM_data1
	.section	.debug_info
	.byte		0	; no source line information

	.section	.debug_abbrev
	.uleb128	DW_AT_type
	.uleb128	DW_FORM_ref4
	.section	.debug_info
	.long		.Luint8_t - .Lssinfo

	.section	.debug_abbrev
	.uleb128	DW_AT_external
	.uleb128	DW_FORM_flag
	.section	.debug_info
	.byte		1

	.section	.debug_abbrev
	.uleb128	DW_AT_location
	.uleb128	DW_FORM_block1
	.section	.debug_info
	.byte		5	; length of block
	.byte		DW_OP_addr
	.long		0x800000 + 0x880 + 0x0C

	.section	.debug_abbrev
	.uleb128	0
	.uleb128	0

;- - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
	;; DIE #437: variable HIRESC_CTRLA
	.section	.debug_info
	.uleb128	437	; ref to abbrev 437
	.section	.debug_abbrev
	.uleb128	437
	.uleb128	DW_TAG_variable
	.byte		DW_CHILDREN_no

	.uleb128	DW_AT_name
	.uleb128	DW_FORM_strp
	.section	.debug_str
.Lname437:
	.string		"HIRESC_CTRLA"
	.section	.debug_info
	.long		.Lname437

	.section	.debug_abbrev
	.uleb128	DW_AT_decl_file
	.uleb128	DW_FORM_data1
	.section	.debug_info
	.byte		0	; no source file information

	.section	.debug_abbrev
	.uleb128	DW_AT_decl_line
	.uleb128	DW_FORM_data1
	.section	.debug_info
	.byte		0	; no source line information

	.section	.debug_abbrev
	.uleb128	DW_AT_type
	.uleb128	DW_FORM_ref4
	.section	.debug_info
	.long		.Luint8_t - .Lssinfo

	.section	.debug_abbrev
	.uleb128	DW_AT_external
	.uleb128	DW_FORM_flag
	.section	.debug_info
	.byte		1

	.section	.debug_abbrev
	.uleb128	DW_AT_location
	.uleb128	DW_FORM_block1
	.section	.debug_info
	.byte		5	; length of block
	.byte		DW_OP_addr
	.long		0x800000 + 0x890 + 0x00

	.section	.debug_abbrev
	.uleb128	0
	.uleb128	0

;- - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
	;; DIE #438: variable USARTC0_DATA
	.section	.debug_info
	.uleb128	438	; ref to abbrev 438
	.section	.debug_abbrev
	.uleb128	438
	.uleb128	DW_TAG_variable
	.byte		DW_CHILDREN_no

	.uleb128	DW_AT_name
	.uleb128	DW_FORM_strp
	.section	.debug_str
.Lname438:
	.string		"USARTC0_DATA"
	.section	.debug_info
	.long		.Lname438

	.section	.debug_abbrev
	.uleb128	DW_AT_decl_file
	.uleb128	DW_FORM_data1
	.section	.debug_info
	.byte		0	; no source file information

	.section	.debug_abbrev
	.uleb128	DW_AT_decl_line
	.uleb128	DW_FORM_data1
	.section	.debug_info
	.byte		0	; no source line information

	.section	.debug_abbrev
	.uleb128	DW_AT_type
	.uleb128	DW_FORM_ref4
	.section	.debug_info
	.long		.Luint8_t - .Lssinfo

	.section	.debug_abbrev
	.uleb128	DW_AT_external
	.uleb128	DW_FORM_flag
	.section	.debug_info
	.byte		1

	.section	.debug_abbrev
	.uleb128	DW_AT_location
	.uleb128	DW_FORM_block1
	.section	.debug_info
	.byte		5	; length of block
	.byte		DW_OP_addr
	.long		0x800000 + 0x8A0 + 0x00

	.section	.debug_abbrev
	.uleb128	0
	.uleb128	0

;- - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
	;; DIE #439: variable USARTC0_STATUS
	.section	.debug_info
	.uleb128	439	; ref to abbrev 439
	.section	.debug_abbrev
	.uleb128	439
	.uleb128	DW_TAG_variable
	.byte		DW_CHILDREN_no

	.uleb128	DW_AT_name
	.uleb128	DW_FORM_strp
	.section	.debug_str
.Lname439:
	.string		"USARTC0_STATUS"
	.section	.debug_info
	.long		.Lname439

	.section	.debug_abbrev
	.uleb128	DW_AT_decl_file
	.uleb128	DW_FORM_data1
	.section	.debug_info
	.byte		0	; no source file information

	.section	.debug_abbrev
	.uleb128	DW_AT_decl_line
	.uleb128	DW_FORM_data1
	.section	.debug_info
	.byte		0	; no source line information

	.section	.debug_abbrev
	.uleb128	DW_AT_type
	.uleb128	DW_FORM_ref4
	.section	.debug_info
	.long		.Luint8_t - .Lssinfo

	.section	.debug_abbrev
	.uleb128	DW_AT_external
	.uleb128	DW_FORM_flag
	.section	.debug_info
	.byte		1

	.section	.debug_abbrev
	.uleb128	DW_AT_location
	.uleb128	DW_FORM_block1
	.section	.debug_info
	.byte		5	; length of block
	.byte		DW_OP_addr
	.long		0x800000 + 0x8A0 + 0x01

	.section	.debug_abbrev
	.uleb128	0
	.uleb128	0

;- - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
	;; DIE #440: variable USARTC0_CTRLA
	.section	.debug_info
	.uleb128	440	; ref to abbrev 440
	.section	.debug_abbrev
	.uleb128	440
	.uleb128	DW_TAG_variable
	.byte		DW_CHILDREN_no

	.uleb128	DW_AT_name
	.uleb128	DW_FORM_strp
	.section	.debug_str
.Lname440:
	.string		"USARTC0_CTRLA"
	.section	.debug_info
	.long		.Lname440

	.section	.debug_abbrev
	.uleb128	DW_AT_decl_file
	.uleb128	DW_FORM_data1
	.section	.debug_info
	.byte		0	; no source file information

	.section	.debug_abbrev
	.uleb128	DW_AT_decl_line
	.uleb128	DW_FORM_data1
	.section	.debug_info
	.byte		0	; no source line information

	.section	.debug_abbrev
	.uleb128	DW_AT_type
	.uleb128	DW_FORM_ref4
	.section	.debug_info
	.long		.Luint8_t - .Lssinfo

	.section	.debug_abbrev
	.uleb128	DW_AT_external
	.uleb128	DW_FORM_flag
	.section	.debug_info
	.byte		1

	.section	.debug_abbrev
	.uleb128	DW_AT_location
	.uleb128	DW_FORM_block1
	.section	.debug_info
	.byte		5	; length of block
	.byte		DW_OP_addr
	.long		0x800000 + 0x8A0 + 0x03

	.section	.debug_abbrev
	.uleb128	0
	.uleb128	0

;- - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
	;; DIE #441: variable USARTC0_CTRLB
	.section	.debug_info
	.uleb128	441	; ref to abbrev 441
	.section	.debug_abbrev
	.uleb128	441
	.uleb128	DW_TAG_variable
	.byte		DW_CHILDREN_no

	.uleb128	DW_AT_name
	.uleb128	DW_FORM_strp
	.section	.debug_str
.Lname441:
	.string		"USARTC0_CTRLB"
	.section	.debug_info
	.long		.Lname441

	.section	.debug_abbrev
	.uleb128	DW_AT_decl_file
	.uleb128	DW_FORM_data1
	.section	.debug_info
	.byte		0	; no source file information

	.section	.debug_abbrev
	.uleb128	DW_AT_decl_line
	.uleb128	DW_FORM_data1
	.section	.debug_info
	.byte		0	; no source line information

	.section	.debug_abbrev
	.uleb128	DW_AT_type
	.uleb128	DW_FORM_ref4
	.section	.debug_info
	.long		.Luint8_t - .Lssinfo

	.section	.debug_abbrev
	.uleb128	DW_AT_external
	.uleb128	DW_FORM_flag
	.section	.debug_info
	.byte		1

	.section	.debug_abbrev
	.uleb128	DW_AT_location
	.uleb128	DW_FORM_block1
	.section	.debug_info
	.byte		5	; length of block
	.byte		DW_OP_addr
	.long		0x800000 + 0x8A0 + 0x04

	.section	.debug_abbrev
	.uleb128	0
	.uleb128	0

;- - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
	;; DIE #442: variable USARTC0_CTRLC
	.section	.debug_info
	.uleb128	442	; ref to abbrev 442
	.section	.debug_abbrev
	.uleb128	442
	.uleb128	DW_TAG_variable
	.byte		DW_CHILDREN_no

	.uleb128	DW_AT_name
	.uleb128	DW_FORM_strp
	.section	.debug_str
.Lname442:
	.string		"USARTC0_CTRLC"
	.section	.debug_info
	.long		.Lname442

	.section	.debug_abbrev
	.uleb128	DW_AT_decl_file
	.uleb128	DW_FORM_data1
	.section	.debug_info
	.byte		0	; no source file information

	.section	.debug_abbrev
	.uleb128	DW_AT_decl_line
	.uleb128	DW_FORM_data1
	.section	.debug_info
	.byte		0	; no source line information

	.section	.debug_abbrev
	.uleb128	DW_AT_type
	.uleb128	DW_FORM_ref4
	.section	.debug_info
	.long		.Luint8_t - .Lssinfo

	.section	.debug_abbrev
	.uleb128	DW_AT_external
	.uleb128	DW_FORM_flag
	.section	.debug_info
	.byte		1

	.section	.debug_abbrev
	.uleb128	DW_AT_location
	.uleb128	DW_FORM_block1
	.section	.debug_info
	.byte		5	; length of block
	.byte		DW_OP_addr
	.long		0x800000 + 0x8A0 + 0x05

	.section	.debug_abbrev
	.uleb128	0
	.uleb128	0

;- - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
	;; DIE #443: variable USARTC0_BAUDCTRLA
	.section	.debug_info
	.uleb128	443	; ref to abbrev 443
	.section	.debug_abbrev
	.uleb128	443
	.uleb128	DW_TAG_variable
	.byte		DW_CHILDREN_no

	.uleb128	DW_AT_name
	.uleb128	DW_FORM_strp
	.section	.debug_str
.Lname443:
	.string		"USARTC0_BAUDCTRLA"
	.section	.debug_info
	.long		.Lname443

	.section	.debug_abbrev
	.uleb128	DW_AT_decl_file
	.uleb128	DW_FORM_data1
	.section	.debug_info
	.byte		0	; no source file information

	.section	.debug_abbrev
	.uleb128	DW_AT_decl_line
	.uleb128	DW_FORM_data1
	.section	.debug_info
	.byte		0	; no source line information

	.section	.debug_abbrev
	.uleb128	DW_AT_type
	.uleb128	DW_FORM_ref4
	.section	.debug_info
	.long		.Luint8_t - .Lssinfo

	.section	.debug_abbrev
	.uleb128	DW_AT_external
	.uleb128	DW_FORM_flag
	.section	.debug_info
	.byte		1

	.section	.debug_abbrev
	.uleb128	DW_AT_location
	.uleb128	DW_FORM_block1
	.section	.debug_info
	.byte		5	; length of block
	.byte		DW_OP_addr
	.long		0x800000 + 0x8A0 + 0x06

	.section	.debug_abbrev
	.uleb128	0
	.uleb128	0

;- - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
	;; DIE #444: variable USARTC0_BAUDCTRLB
	.section	.debug_info
	.uleb128	444	; ref to abbrev 444
	.section	.debug_abbrev
	.uleb128	444
	.uleb128	DW_TAG_variable
	.byte		DW_CHILDREN_no

	.uleb128	DW_AT_name
	.uleb128	DW_FORM_strp
	.section	.debug_str
.Lname444:
	.string		"USARTC0_BAUDCTRLB"
	.section	.debug_info
	.long		.Lname444

	.section	.debug_abbrev
	.uleb128	DW_AT_decl_file
	.uleb128	DW_FORM_data1
	.section	.debug_info
	.byte		0	; no source file information

	.section	.debug_abbrev
	.uleb128	DW_AT_decl_line
	.uleb128	DW_FORM_data1
	.section	.debug_info
	.byte		0	; no source line information

	.section	.debug_abbrev
	.uleb128	DW_AT_type
	.uleb128	DW_FORM_ref4
	.section	.debug_info
	.long		.Luint8_t - .Lssinfo

	.section	.debug_abbrev
	.uleb128	DW_AT_external
	.uleb128	DW_FORM_flag
	.section	.debug_info
	.byte		1

	.section	.debug_abbrev
	.uleb128	DW_AT_location
	.uleb128	DW_FORM_block1
	.section	.debug_info
	.byte		5	; length of block
	.byte		DW_OP_addr
	.long		0x800000 + 0x8A0 + 0x07

	.section	.debug_abbrev
	.uleb128	0
	.uleb128	0

;- - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
	;; DIE #445: variable USARTC1_DATA
	.section	.debug_info
	.uleb128	445	; ref to abbrev 445
	.section	.debug_abbrev
	.uleb128	445
	.uleb128	DW_TAG_variable
	.byte		DW_CHILDREN_no

	.uleb128	DW_AT_name
	.uleb128	DW_FORM_strp
	.section	.debug_str
.Lname445:
	.string		"USARTC1_DATA"
	.section	.debug_info
	.long		.Lname445

	.section	.debug_abbrev
	.uleb128	DW_AT_decl_file
	.uleb128	DW_FORM_data1
	.section	.debug_info
	.byte		0	; no source file information

	.section	.debug_abbrev
	.uleb128	DW_AT_decl_line
	.uleb128	DW_FORM_data1
	.section	.debug_info
	.byte		0	; no source line information

	.section	.debug_abbrev
	.uleb128	DW_AT_type
	.uleb128	DW_FORM_ref4
	.section	.debug_info
	.long		.Luint8_t - .Lssinfo

	.section	.debug_abbrev
	.uleb128	DW_AT_external
	.uleb128	DW_FORM_flag
	.section	.debug_info
	.byte		1

	.section	.debug_abbrev
	.uleb128	DW_AT_location
	.uleb128	DW_FORM_block1
	.section	.debug_info
	.byte		5	; length of block
	.byte		DW_OP_addr
	.long		0x800000 + 0x8B0 + 0x00

	.section	.debug_abbrev
	.uleb128	0
	.uleb128	0

;- - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
	;; DIE #446: variable USARTC1_STATUS
	.section	.debug_info
	.uleb128	446	; ref to abbrev 446
	.section	.debug_abbrev
	.uleb128	446
	.uleb128	DW_TAG_variable
	.byte		DW_CHILDREN_no

	.uleb128	DW_AT_name
	.uleb128	DW_FORM_strp
	.section	.debug_str
.Lname446:
	.string		"USARTC1_STATUS"
	.section	.debug_info
	.long		.Lname446

	.section	.debug_abbrev
	.uleb128	DW_AT_decl_file
	.uleb128	DW_FORM_data1
	.section	.debug_info
	.byte		0	; no source file information

	.section	.debug_abbrev
	.uleb128	DW_AT_decl_line
	.uleb128	DW_FORM_data1
	.section	.debug_info
	.byte		0	; no source line information

	.section	.debug_abbrev
	.uleb128	DW_AT_type
	.uleb128	DW_FORM_ref4
	.section	.debug_info
	.long		.Luint8_t - .Lssinfo

	.section	.debug_abbrev
	.uleb128	DW_AT_external
	.uleb128	DW_FORM_flag
	.section	.debug_info
	.byte		1

	.section	.debug_abbrev
	.uleb128	DW_AT_location
	.uleb128	DW_FORM_block1
	.section	.debug_info
	.byte		5	; length of block
	.byte		DW_OP_addr
	.long		0x800000 + 0x8B0 + 0x01

	.section	.debug_abbrev
	.uleb128	0
	.uleb128	0

;- - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
	;; DIE #447: variable USARTC1_CTRLA
	.section	.debug_info
	.uleb128	447	; ref to abbrev 447
	.section	.debug_abbrev
	.uleb128	447
	.uleb128	DW_TAG_variable
	.byte		DW_CHILDREN_no

	.uleb128	DW_AT_name
	.uleb128	DW_FORM_strp
	.section	.debug_str
.Lname447:
	.string		"USARTC1_CTRLA"
	.section	.debug_info
	.long		.Lname447

	.section	.debug_abbrev
	.uleb128	DW_AT_decl_file
	.uleb128	DW_FORM_data1
	.section	.debug_info
	.byte		0	; no source file information

	.section	.debug_abbrev
	.uleb128	DW_AT_decl_line
	.uleb128	DW_FORM_data1
	.section	.debug_info
	.byte		0	; no source line information

	.section	.debug_abbrev
	.uleb128	DW_AT_type
	.uleb128	DW_FORM_ref4
	.section	.debug_info
	.long		.Luint8_t - .Lssinfo

	.section	.debug_abbrev
	.uleb128	DW_AT_external
	.uleb128	DW_FORM_flag
	.section	.debug_info
	.byte		1

	.section	.debug_abbrev
	.uleb128	DW_AT_location
	.uleb128	DW_FORM_block1
	.section	.debug_info
	.byte		5	; length of block
	.byte		DW_OP_addr
	.long		0x800000 + 0x8B0 + 0x03

	.section	.debug_abbrev
	.uleb128	0
	.uleb128	0

;- - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
	;; DIE #448: variable USARTC1_CTRLB
	.section	.debug_info
	.uleb128	448	; ref to abbrev 448
	.section	.debug_abbrev
	.uleb128	448
	.uleb128	DW_TAG_variable
	.byte		DW_CHILDREN_no

	.uleb128	DW_AT_name
	.uleb128	DW_FORM_strp
	.section	.debug_str
.Lname448:
	.string		"USARTC1_CTRLB"
	.section	.debug_info
	.long		.Lname448

	.section	.debug_abbrev
	.uleb128	DW_AT_decl_file
	.uleb128	DW_FORM_data1
	.section	.debug_info
	.byte		0	; no source file information

	.section	.debug_abbrev
	.uleb128	DW_AT_decl_line
	.uleb128	DW_FORM_data1
	.section	.debug_info
	.byte		0	; no source line information

	.section	.debug_abbrev
	.uleb128	DW_AT_type
	.uleb128	DW_FORM_ref4
	.section	.debug_info
	.long		.Luint8_t - .Lssinfo

	.section	.debug_abbrev
	.uleb128	DW_AT_external
	.uleb128	DW_FORM_flag
	.section	.debug_info
	.byte		1

	.section	.debug_abbrev
	.uleb128	DW_AT_location
	.uleb128	DW_FORM_block1
	.section	.debug_info
	.byte		5	; length of block
	.byte		DW_OP_addr
	.long		0x800000 + 0x8B0 + 0x04

	.section	.debug_abbrev
	.uleb128	0
	.uleb128	0

;- - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
	;; DIE #449: variable USARTC1_CTRLC
	.section	.debug_info
	.uleb128	449	; ref to abbrev 449
	.section	.debug_abbrev
	.uleb128	449
	.uleb128	DW_TAG_variable
	.byte		DW_CHILDREN_no

	.uleb128	DW_AT_name
	.uleb128	DW_FORM_strp
	.section	.debug_str
.Lname449:
	.string		"USARTC1_CTRLC"
	.section	.debug_info
	.long		.Lname449

	.section	.debug_abbrev
	.uleb128	DW_AT_decl_file
	.uleb128	DW_FORM_data1
	.section	.debug_info
	.byte		0	; no source file information

	.section	.debug_abbrev
	.uleb128	DW_AT_decl_line
	.uleb128	DW_FORM_data1
	.section	.debug_info
	.byte		0	; no source line information

	.section	.debug_abbrev
	.uleb128	DW_AT_type
	.uleb128	DW_FORM_ref4
	.section	.debug_info
	.long		.Luint8_t - .Lssinfo

	.section	.debug_abbrev
	.uleb128	DW_AT_external
	.uleb128	DW_FORM_flag
	.section	.debug_info
	.byte		1

	.section	.debug_abbrev
	.uleb128	DW_AT_location
	.uleb128	DW_FORM_block1
	.section	.debug_info
	.byte		5	; length of block
	.byte		DW_OP_addr
	.long		0x800000 + 0x8B0 + 0x05

	.section	.debug_abbrev
	.uleb128	0
	.uleb128	0

;- - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
	;; DIE #450: variable USARTC1_BAUDCTRLA
	.section	.debug_info
	.uleb128	450	; ref to abbrev 450
	.section	.debug_abbrev
	.uleb128	450
	.uleb128	DW_TAG_variable
	.byte		DW_CHILDREN_no

	.uleb128	DW_AT_name
	.uleb128	DW_FORM_strp
	.section	.debug_str
.Lname450:
	.string		"USARTC1_BAUDCTRLA"
	.section	.debug_info
	.long		.Lname450

	.section	.debug_abbrev
	.uleb128	DW_AT_decl_file
	.uleb128	DW_FORM_data1
	.section	.debug_info
	.byte		0	; no source file information

	.section	.debug_abbrev
	.uleb128	DW_AT_decl_line
	.uleb128	DW_FORM_data1
	.section	.debug_info
	.byte		0	; no source line information

	.section	.debug_abbrev
	.uleb128	DW_AT_type
	.uleb128	DW_FORM_ref4
	.section	.debug_info
	.long		.Luint8_t - .Lssinfo

	.section	.debug_abbrev
	.uleb128	DW_AT_external
	.uleb128	DW_FORM_flag
	.section	.debug_info
	.byte		1

	.section	.debug_abbrev
	.uleb128	DW_AT_location
	.uleb128	DW_FORM_block1
	.section	.debug_info
	.byte		5	; length of block
	.byte		DW_OP_addr
	.long		0x800000 + 0x8B0 + 0x06

	.section	.debug_abbrev
	.uleb128	0
	.uleb128	0

;- - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
	;; DIE #451: variable USARTC1_BAUDCTRLB
	.section	.debug_info
	.uleb128	451	; ref to abbrev 451
	.section	.debug_abbrev
	.uleb128	451
	.uleb128	DW_TAG_variable
	.byte		DW_CHILDREN_no

	.uleb128	DW_AT_name
	.uleb128	DW_FORM_strp
	.section	.debug_str
.Lname451:
	.string		"USARTC1_BAUDCTRLB"
	.section	.debug_info
	.long		.Lname451

	.section	.debug_abbrev
	.uleb128	DW_AT_decl_file
	.uleb128	DW_FORM_data1
	.section	.debug_info
	.byte		0	; no source file information

	.section	.debug_abbrev
	.uleb128	DW_AT_decl_line
	.uleb128	DW_FORM_data1
	.section	.debug_info
	.byte		0	; no source line information

	.section	.debug_abbrev
	.uleb128	DW_AT_type
	.uleb128	DW_FORM_ref4
	.section	.debug_info
	.long		.Luint8_t - .Lssinfo

	.section	.debug_abbrev
	.uleb128	DW_AT_external
	.uleb128	DW_FORM_flag
	.section	.debug_info
	.byte		1

	.section	.debug_abbrev
	.uleb128	DW_AT_location
	.uleb128	DW_FORM_block1
	.section	.debug_info
	.byte		5	; length of block
	.byte		DW_OP_addr
	.long		0x800000 + 0x8B0 + 0x07

	.section	.debug_abbrev
	.uleb128	0
	.uleb128	0

;- - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
	;; DIE #452: variable USARTD0_DATA
	.section	.debug_info
	.uleb128	452	; ref to abbrev 452
	.section	.debug_abbrev
	.uleb128	452
	.uleb128	DW_TAG_variable
	.byte		DW_CHILDREN_no

	.uleb128	DW_AT_name
	.uleb128	DW_FORM_strp
	.section	.debug_str
.Lname452:
	.string		"USARTD0_DATA"
	.section	.debug_info
	.long		.Lname452

	.section	.debug_abbrev
	.uleb128	DW_AT_decl_file
	.uleb128	DW_FORM_data1
	.section	.debug_info
	.byte		0	; no source file information

	.section	.debug_abbrev
	.uleb128	DW_AT_decl_line
	.uleb128	DW_FORM_data1
	.section	.debug_info
	.byte		0	; no source line information

	.section	.debug_abbrev
	.uleb128	DW_AT_type
	.uleb128	DW_FORM_ref4
	.section	.debug_info
	.long		.Luint8_t - .Lssinfo

	.section	.debug_abbrev
	.uleb128	DW_AT_external
	.uleb128	DW_FORM_flag
	.section	.debug_info
	.byte		1

	.section	.debug_abbrev
	.uleb128	DW_AT_location
	.uleb128	DW_FORM_block1
	.section	.debug_info
	.byte		5	; length of block
	.byte		DW_OP_addr
	.long		0x800000 + 0x9A0 + 0x00

	.section	.debug_abbrev
	.uleb128	0
	.uleb128	0

;- - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
	;; DIE #453: variable USARTD0_STATUS
	.section	.debug_info
	.uleb128	453	; ref to abbrev 453
	.section	.debug_abbrev
	.uleb128	453
	.uleb128	DW_TAG_variable
	.byte		DW_CHILDREN_no

	.uleb128	DW_AT_name
	.uleb128	DW_FORM_strp
	.section	.debug_str
.Lname453:
	.string		"USARTD0_STATUS"
	.section	.debug_info
	.long		.Lname453

	.section	.debug_abbrev
	.uleb128	DW_AT_decl_file
	.uleb128	DW_FORM_data1
	.section	.debug_info
	.byte		0	; no source file information

	.section	.debug_abbrev
	.uleb128	DW_AT_decl_line
	.uleb128	DW_FORM_data1
	.section	.debug_info
	.byte		0	; no source line information

	.section	.debug_abbrev
	.uleb128	DW_AT_type
	.uleb128	DW_FORM_ref4
	.section	.debug_info
	.long		.Luint8_t - .Lssinfo

	.section	.debug_abbrev
	.uleb128	DW_AT_external
	.uleb128	DW_FORM_flag
	.section	.debug_info
	.byte		1

	.section	.debug_abbrev
	.uleb128	DW_AT_location
	.uleb128	DW_FORM_block1
	.section	.debug_info
	.byte		5	; length of block
	.byte		DW_OP_addr
	.long		0x800000 + 0x9A0 + 0x01

	.section	.debug_abbrev
	.uleb128	0
	.uleb128	0

;- - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
	;; DIE #454: variable USARTD0_CTRLA
	.section	.debug_info
	.uleb128	454	; ref to abbrev 454
	.section	.debug_abbrev
	.uleb128	454
	.uleb128	DW_TAG_variable
	.byte		DW_CHILDREN_no

	.uleb128	DW_AT_name
	.uleb128	DW_FORM_strp
	.section	.debug_str
.Lname454:
	.string		"USARTD0_CTRLA"
	.section	.debug_info
	.long		.Lname454

	.section	.debug_abbrev
	.uleb128	DW_AT_decl_file
	.uleb128	DW_FORM_data1
	.section	.debug_info
	.byte		0	; no source file information

	.section	.debug_abbrev
	.uleb128	DW_AT_decl_line
	.uleb128	DW_FORM_data1
	.section	.debug_info
	.byte		0	; no source line information

	.section	.debug_abbrev
	.uleb128	DW_AT_type
	.uleb128	DW_FORM_ref4
	.section	.debug_info
	.long		.Luint8_t - .Lssinfo

	.section	.debug_abbrev
	.uleb128	DW_AT_external
	.uleb128	DW_FORM_flag
	.section	.debug_info
	.byte		1

	.section	.debug_abbrev
	.uleb128	DW_AT_location
	.uleb128	DW_FORM_block1
	.section	.debug_info
	.byte		5	; length of block
	.byte		DW_OP_addr
	.long		0x800000 + 0x9A0 + 0x03

	.section	.debug_abbrev
	.uleb128	0
	.uleb128	0

;- - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
	;; DIE #455: variable USARTD0_CTRLB
	.section	.debug_info
	.uleb128	455	; ref to abbrev 455
	.section	.debug_abbrev
	.uleb128	455
	.uleb128	DW_TAG_variable
	.byte		DW_CHILDREN_no

	.uleb128	DW_AT_name
	.uleb128	DW_FORM_strp
	.section	.debug_str
.Lname455:
	.string		"USARTD0_CTRLB"
	.section	.debug_info
	.long		.Lname455

	.section	.debug_abbrev
	.uleb128	DW_AT_decl_file
	.uleb128	DW_FORM_data1
	.section	.debug_info
	.byte		0	; no source file information

	.section	.debug_abbrev
	.uleb128	DW_AT_decl_line
	.uleb128	DW_FORM_data1
	.section	.debug_info
	.byte		0	; no source line information

	.section	.debug_abbrev
	.uleb128	DW_AT_type
	.uleb128	DW_FORM_ref4
	.section	.debug_info
	.long		.Luint8_t - .Lssinfo

	.section	.debug_abbrev
	.uleb128	DW_AT_external
	.uleb128	DW_FORM_flag
	.section	.debug_info
	.byte		1

	.section	.debug_abbrev
	.uleb128	DW_AT_location
	.uleb128	DW_FORM_block1
	.section	.debug_info
	.byte		5	; length of block
	.byte		DW_OP_addr
	.long		0x800000 + 0x9A0 + 0x04

	.section	.debug_abbrev
	.uleb128	0
	.uleb128	0

;- - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
	;; DIE #456: variable USARTD0_CTRLC
	.section	.debug_info
	.uleb128	456	; ref to abbrev 456
	.section	.debug_abbrev
	.uleb128	456
	.uleb128	DW_TAG_variable
	.byte		DW_CHILDREN_no

	.uleb128	DW_AT_name
	.uleb128	DW_FORM_strp
	.section	.debug_str
.Lname456:
	.string		"USARTD0_CTRLC"
	.section	.debug_info
	.long		.Lname456

	.section	.debug_abbrev
	.uleb128	DW_AT_decl_file
	.uleb128	DW_FORM_data1
	.section	.debug_info
	.byte		0	; no source file information

	.section	.debug_abbrev
	.uleb128	DW_AT_decl_line
	.uleb128	DW_FORM_data1
	.section	.debug_info
	.byte		0	; no source line information

	.section	.debug_abbrev
	.uleb128	DW_AT_type
	.uleb128	DW_FORM_ref4
	.section	.debug_info
	.long		.Luint8_t - .Lssinfo

	.section	.debug_abbrev
	.uleb128	DW_AT_external
	.uleb128	DW_FORM_flag
	.section	.debug_info
	.byte		1

	.section	.debug_abbrev
	.uleb128	DW_AT_location
	.uleb128	DW_FORM_block1
	.section	.debug_info
	.byte		5	; length of block
	.byte		DW_OP_addr
	.long		0x800000 + 0x9A0 + 0x05

	.section	.debug_abbrev
	.uleb128	0
	.uleb128	0

;- - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
	;; DIE #457: variable USARTD0_BAUDCTRLA
	.section	.debug_info
	.uleb128	457	; ref to abbrev 457
	.section	.debug_abbrev
	.uleb128	457
	.uleb128	DW_TAG_variable
	.byte		DW_CHILDREN_no

	.uleb128	DW_AT_name
	.uleb128	DW_FORM_strp
	.section	.debug_str
.Lname457:
	.string		"USARTD0_BAUDCTRLA"
	.section	.debug_info
	.long		.Lname457

	.section	.debug_abbrev
	.uleb128	DW_AT_decl_file
	.uleb128	DW_FORM_data1
	.section	.debug_info
	.byte		0	; no source file information

	.section	.debug_abbrev
	.uleb128	DW_AT_decl_line
	.uleb128	DW_FORM_data1
	.section	.debug_info
	.byte		0	; no source line information

	.section	.debug_abbrev
	.uleb128	DW_AT_type
	.uleb128	DW_FORM_ref4
	.section	.debug_info
	.long		.Luint8_t - .Lssinfo

	.section	.debug_abbrev
	.uleb128	DW_AT_external
	.uleb128	DW_FORM_flag
	.section	.debug_info
	.byte		1

	.section	.debug_abbrev
	.uleb128	DW_AT_location
	.uleb128	DW_FORM_block1
	.section	.debug_info
	.byte		5	; length of block
	.byte		DW_OP_addr
	.long		0x800000 + 0x9A0 + 0x06

	.section	.debug_abbrev
	.uleb128	0
	.uleb128	0

;- - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
	;; DIE #458: variable USARTD0_BAUDCTRLB
	.section	.debug_info
	.uleb128	458	; ref to abbrev 458
	.section	.debug_abbrev
	.uleb128	458
	.uleb128	DW_TAG_variable
	.byte		DW_CHILDREN_no

	.uleb128	DW_AT_name
	.uleb128	DW_FORM_strp
	.section	.debug_str
.Lname458:
	.string		"USARTD0_BAUDCTRLB"
	.section	.debug_info
	.long		.Lname458

	.section	.debug_abbrev
	.uleb128	DW_AT_decl_file
	.uleb128	DW_FORM_data1
	.section	.debug_info
	.byte		0	; no source file information

	.section	.debug_abbrev
	.uleb128	DW_AT_decl_line
	.uleb128	DW_FORM_data1
	.section	.debug_info
	.byte		0	; no source line information

	.section	.debug_abbrev
	.uleb128	DW_AT_type
	.uleb128	DW_FORM_ref4
	.section	.debug_info
	.long		.Luint8_t - .Lssinfo

	.section	.debug_abbrev
	.uleb128	DW_AT_external
	.uleb128	DW_FORM_flag
	.section	.debug_info
	.byte		1

	.section	.debug_abbrev
	.uleb128	DW_AT_location
	.uleb128	DW_FORM_block1
	.section	.debug_info
	.byte		5	; length of block
	.byte		DW_OP_addr
	.long		0x800000 + 0x9A0 + 0x07

	.section	.debug_abbrev
	.uleb128	0
	.uleb128	0

;- - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
	;; DIE #459: variable SPIC_CTRL
	.section	.debug_info
	.uleb128	459	; ref to abbrev 459
	.section	.debug_abbrev
	.uleb128	459
	.uleb128	DW_TAG_variable
	.byte		DW_CHILDREN_no

	.uleb128	DW_AT_name
	.uleb128	DW_FORM_strp
	.section	.debug_str
.Lname459:
	.string		"SPIC_CTRL"
	.section	.debug_info
	.long		.Lname459

	.section	.debug_abbrev
	.uleb128	DW_AT_decl_file
	.uleb128	DW_FORM_data1
	.section	.debug_info
	.byte		0	; no source file information

	.section	.debug_abbrev
	.uleb128	DW_AT_decl_line
	.uleb128	DW_FORM_data1
	.section	.debug_info
	.byte		0	; no source line information

	.section	.debug_abbrev
	.uleb128	DW_AT_type
	.uleb128	DW_FORM_ref4
	.section	.debug_info
	.long		.Luint8_t - .Lssinfo

	.section	.debug_abbrev
	.uleb128	DW_AT_external
	.uleb128	DW_FORM_flag
	.section	.debug_info
	.byte		1

	.section	.debug_abbrev
	.uleb128	DW_AT_location
	.uleb128	DW_FORM_block1
	.section	.debug_info
	.byte		5	; length of block
	.byte		DW_OP_addr
	.long		0x800000 + 0x8C0 + 0x00

	.section	.debug_abbrev
	.uleb128	0
	.uleb128	0

;- - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
	;; DIE #460: variable SPIC_INTCTRL
	.section	.debug_info
	.uleb128	460	; ref to abbrev 460
	.section	.debug_abbrev
	.uleb128	460
	.uleb128	DW_TAG_variable
	.byte		DW_CHILDREN_no

	.uleb128	DW_AT_name
	.uleb128	DW_FORM_strp
	.section	.debug_str
.Lname460:
	.string		"SPIC_INTCTRL"
	.section	.debug_info
	.long		.Lname460

	.section	.debug_abbrev
	.uleb128	DW_AT_decl_file
	.uleb128	DW_FORM_data1
	.section	.debug_info
	.byte		0	; no source file information

	.section	.debug_abbrev
	.uleb128	DW_AT_decl_line
	.uleb128	DW_FORM_data1
	.section	.debug_info
	.byte		0	; no source line information

	.section	.debug_abbrev
	.uleb128	DW_AT_type
	.uleb128	DW_FORM_ref4
	.section	.debug_info
	.long		.Luint8_t - .Lssinfo

	.section	.debug_abbrev
	.uleb128	DW_AT_external
	.uleb128	DW_FORM_flag
	.section	.debug_info
	.byte		1

	.section	.debug_abbrev
	.uleb128	DW_AT_location
	.uleb128	DW_FORM_block1
	.section	.debug_info
	.byte		5	; length of block
	.byte		DW_OP_addr
	.long		0x800000 + 0x8C0 + 0x01

	.section	.debug_abbrev
	.uleb128	0
	.uleb128	0

;- - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
	;; DIE #461: variable SPIC_STATUS
	.section	.debug_info
	.uleb128	461	; ref to abbrev 461
	.section	.debug_abbrev
	.uleb128	461
	.uleb128	DW_TAG_variable
	.byte		DW_CHILDREN_no

	.uleb128	DW_AT_name
	.uleb128	DW_FORM_strp
	.section	.debug_str
.Lname461:
	.string		"SPIC_STATUS"
	.section	.debug_info
	.long		.Lname461

	.section	.debug_abbrev
	.uleb128	DW_AT_decl_file
	.uleb128	DW_FORM_data1
	.section	.debug_info
	.byte		0	; no source file information

	.section	.debug_abbrev
	.uleb128	DW_AT_decl_line
	.uleb128	DW_FORM_data1
	.section	.debug_info
	.byte		0	; no source line information

	.section	.debug_abbrev
	.uleb128	DW_AT_type
	.uleb128	DW_FORM_ref4
	.section	.debug_info
	.long		.Luint8_t - .Lssinfo

	.section	.debug_abbrev
	.uleb128	DW_AT_external
	.uleb128	DW_FORM_flag
	.section	.debug_info
	.byte		1

	.section	.debug_abbrev
	.uleb128	DW_AT_location
	.uleb128	DW_FORM_block1
	.section	.debug_info
	.byte		5	; length of block
	.byte		DW_OP_addr
	.long		0x800000 + 0x8C0 + 0x02

	.section	.debug_abbrev
	.uleb128	0
	.uleb128	0

;- - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
	;; DIE #462: variable SPIC_DATA
	.section	.debug_info
	.uleb128	462	; ref to abbrev 462
	.section	.debug_abbrev
	.uleb128	462
	.uleb128	DW_TAG_variable
	.byte		DW_CHILDREN_no

	.uleb128	DW_AT_name
	.uleb128	DW_FORM_strp
	.section	.debug_str
.Lname462:
	.string		"SPIC_DATA"
	.section	.debug_info
	.long		.Lname462

	.section	.debug_abbrev
	.uleb128	DW_AT_decl_file
	.uleb128	DW_FORM_data1
	.section	.debug_info
	.byte		0	; no source file information

	.section	.debug_abbrev
	.uleb128	DW_AT_decl_line
	.uleb128	DW_FORM_data1
	.section	.debug_info
	.byte		0	; no source line information

	.section	.debug_abbrev
	.uleb128	DW_AT_type
	.uleb128	DW_FORM_ref4
	.section	.debug_info
	.long		.Luint8_t - .Lssinfo

	.section	.debug_abbrev
	.uleb128	DW_AT_external
	.uleb128	DW_FORM_flag
	.section	.debug_info
	.byte		1

	.section	.debug_abbrev
	.uleb128	DW_AT_location
	.uleb128	DW_FORM_block1
	.section	.debug_info
	.byte		5	; length of block
	.byte		DW_OP_addr
	.long		0x800000 + 0x8C0 + 0x03

	.section	.debug_abbrev
	.uleb128	0
	.uleb128	0

;- - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
	;; DIE #463: variable SPID_CTRL
	.section	.debug_info
	.uleb128	463	; ref to abbrev 463
	.section	.debug_abbrev
	.uleb128	463
	.uleb128	DW_TAG_variable
	.byte		DW_CHILDREN_no

	.uleb128	DW_AT_name
	.uleb128	DW_FORM_strp
	.section	.debug_str
.Lname463:
	.string		"SPID_CTRL"
	.section	.debug_info
	.long		.Lname463

	.section	.debug_abbrev
	.uleb128	DW_AT_decl_file
	.uleb128	DW_FORM_data1
	.section	.debug_info
	.byte		0	; no source file information

	.section	.debug_abbrev
	.uleb128	DW_AT_decl_line
	.uleb128	DW_FORM_data1
	.section	.debug_info
	.byte		0	; no source line information

	.section	.debug_abbrev
	.uleb128	DW_AT_type
	.uleb128	DW_FORM_ref4
	.section	.debug_info
	.long		.Luint8_t - .Lssinfo

	.section	.debug_abbrev
	.uleb128	DW_AT_external
	.uleb128	DW_FORM_flag
	.section	.debug_info
	.byte		1

	.section	.debug_abbrev
	.uleb128	DW_AT_location
	.uleb128	DW_FORM_block1
	.section	.debug_info
	.byte		5	; length of block
	.byte		DW_OP_addr
	.long		0x800000 + 0x9C0 + 0x00

	.section	.debug_abbrev
	.uleb128	0
	.uleb128	0

;- - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
	;; DIE #464: variable SPID_INTCTRL
	.section	.debug_info
	.uleb128	464	; ref to abbrev 464
	.section	.debug_abbrev
	.uleb128	464
	.uleb128	DW_TAG_variable
	.byte		DW_CHILDREN_no

	.uleb128	DW_AT_name
	.uleb128	DW_FORM_strp
	.section	.debug_str
.Lname464:
	.string		"SPID_INTCTRL"
	.section	.debug_info
	.long		.Lname464

	.section	.debug_abbrev
	.uleb128	DW_AT_decl_file
	.uleb128	DW_FORM_data1
	.section	.debug_info
	.byte		0	; no source file information

	.section	.debug_abbrev
	.uleb128	DW_AT_decl_line
	.uleb128	DW_FORM_data1
	.section	.debug_info
	.byte		0	; no source line information

	.section	.debug_abbrev
	.uleb128	DW_AT_type
	.uleb128	DW_FORM_ref4
	.section	.debug_info
	.long		.Luint8_t - .Lssinfo

	.section	.debug_abbrev
	.uleb128	DW_AT_external
	.uleb128	DW_FORM_flag
	.section	.debug_info
	.byte		1

	.section	.debug_abbrev
	.uleb128	DW_AT_location
	.uleb128	DW_FORM_block1
	.section	.debug_info
	.byte		5	; length of block
	.byte		DW_OP_addr
	.long		0x800000 + 0x9C0 + 0x01

	.section	.debug_abbrev
	.uleb128	0
	.uleb128	0

;- - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
	;; DIE #465: variable SPID_STATUS
	.section	.debug_info
	.uleb128	465	; ref to abbrev 465
	.section	.debug_abbrev
	.uleb128	465
	.uleb128	DW_TAG_variable
	.byte		DW_CHILDREN_no

	.uleb128	DW_AT_name
	.uleb128	DW_FORM_strp
	.section	.debug_str
.Lname465:
	.string		"SPID_STATUS"
	.section	.debug_info
	.long		.Lname465

	.section	.debug_abbrev
	.uleb128	DW_AT_decl_file
	.uleb128	DW_FORM_data1
	.section	.debug_info
	.byte		0	; no source file information

	.section	.debug_abbrev
	.uleb128	DW_AT_decl_line
	.uleb128	DW_FORM_data1
	.section	.debug_info
	.byte		0	; no source line information

	.section	.debug_abbrev
	.uleb128	DW_AT_type
	.uleb128	DW_FORM_ref4
	.section	.debug_info
	.long		.Luint8_t - .Lssinfo

	.section	.debug_abbrev
	.uleb128	DW_AT_external
	.uleb128	DW_FORM_flag
	.section	.debug_info
	.byte		1

	.section	.debug_abbrev
	.uleb128	DW_AT_location
	.uleb128	DW_FORM_block1
	.section	.debug_info
	.byte		5	; length of block
	.byte		DW_OP_addr
	.long		0x800000 + 0x9C0 + 0x02

	.section	.debug_abbrev
	.uleb128	0
	.uleb128	0

;- - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
	;; DIE #466: variable SPID_DATA
	.section	.debug_info
	.uleb128	466	; ref to abbrev 466
	.section	.debug_abbrev
	.uleb128	466
	.uleb128	DW_TAG_variable
	.byte		DW_CHILDREN_no

	.uleb128	DW_AT_name
	.uleb128	DW_FORM_strp
	.section	.debug_str
.Lname466:
	.string		"SPID_DATA"
	.section	.debug_info
	.long		.Lname466

	.section	.debug_abbrev
	.uleb128	DW_AT_decl_file
	.uleb128	DW_FORM_data1
	.section	.debug_info
	.byte		0	; no source file information

	.section	.debug_abbrev
	.uleb128	DW_AT_decl_line
	.uleb128	DW_FORM_data1
	.section	.debug_info
	.byte		0	; no source line information

	.section	.debug_abbrev
	.uleb128	DW_AT_type
	.uleb128	DW_FORM_ref4
	.section	.debug_info
	.long		.Luint8_t - .Lssinfo

	.section	.debug_abbrev
	.uleb128	DW_AT_external
	.uleb128	DW_FORM_flag
	.section	.debug_info
	.byte		1

	.section	.debug_abbrev
	.uleb128	DW_AT_location
	.uleb128	DW_FORM_block1
	.section	.debug_info
	.byte		5	; length of block
	.byte		DW_OP_addr
	.long		0x800000 + 0x9C0 + 0x03

	.section	.debug_abbrev
	.uleb128	0
	.uleb128	0

;- - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
	;; DIE #467: variable IRCOM_CTRL
	.section	.debug_info
	.uleb128	467	; ref to abbrev 467
	.section	.debug_abbrev
	.uleb128	467
	.uleb128	DW_TAG_variable
	.byte		DW_CHILDREN_no

	.uleb128	DW_AT_name
	.uleb128	DW_FORM_strp
	.section	.debug_str
.Lname467:
	.string		"IRCOM_CTRL"
	.section	.debug_info
	.long		.Lname467

	.section	.debug_abbrev
	.uleb128	DW_AT_decl_file
	.uleb128	DW_FORM_data1
	.section	.debug_info
	.byte		0	; no source file information

	.section	.debug_abbrev
	.uleb128	DW_AT_decl_line
	.uleb128	DW_FORM_data1
	.section	.debug_info
	.byte		0	; no source line information

	.section	.debug_abbrev
	.uleb128	DW_AT_type
	.uleb128	DW_FORM_ref4
	.section	.debug_info
	.long		.Luint8_t - .Lssinfo

	.section	.debug_abbrev
	.uleb128	DW_AT_external
	.uleb128	DW_FORM_flag
	.section	.debug_info
	.byte		1

	.section	.debug_abbrev
	.uleb128	DW_AT_location
	.uleb128	DW_FORM_block1
	.section	.debug_info
	.byte		5	; length of block
	.byte		DW_OP_addr
	.long		0x800000 + 0x8F8 + 0x00

	.section	.debug_abbrev
	.uleb128	0
	.uleb128	0

;- - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
	;; DIE #468: variable IRCOM_TXPLCTRL
	.section	.debug_info
	.uleb128	468	; ref to abbrev 468
	.section	.debug_abbrev
	.uleb128	468
	.uleb128	DW_TAG_variable
	.byte		DW_CHILDREN_no

	.uleb128	DW_AT_name
	.uleb128	DW_FORM_strp
	.section	.debug_str
.Lname468:
	.string		"IRCOM_TXPLCTRL"
	.section	.debug_info
	.long		.Lname468

	.section	.debug_abbrev
	.uleb128	DW_AT_decl_file
	.uleb128	DW_FORM_data1
	.section	.debug_info
	.byte		0	; no source file information

	.section	.debug_abbrev
	.uleb128	DW_AT_decl_line
	.uleb128	DW_FORM_data1
	.section	.debug_info
	.byte		0	; no source line information

	.section	.debug_abbrev
	.uleb128	DW_AT_type
	.uleb128	DW_FORM_ref4
	.section	.debug_info
	.long		.Luint8_t - .Lssinfo

	.section	.debug_abbrev
	.uleb128	DW_AT_external
	.uleb128	DW_FORM_flag
	.section	.debug_info
	.byte		1

	.section	.debug_abbrev
	.uleb128	DW_AT_location
	.uleb128	DW_FORM_block1
	.section	.debug_info
	.byte		5	; length of block
	.byte		DW_OP_addr
	.long		0x800000 + 0x8F8 + 0x01

	.section	.debug_abbrev
	.uleb128	0
	.uleb128	0

;- - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
	;; DIE #469: variable IRCOM_RXPLCTRL
	.section	.debug_info
	.uleb128	469	; ref to abbrev 469
	.section	.debug_abbrev
	.uleb128	469
	.uleb128	DW_TAG_variable
	.byte		DW_CHILDREN_no

	.uleb128	DW_AT_name
	.uleb128	DW_FORM_strp
	.section	.debug_str
.Lname469:
	.string		"IRCOM_RXPLCTRL"
	.section	.debug_info
	.long		.Lname469

	.section	.debug_abbrev
	.uleb128	DW_AT_decl_file
	.uleb128	DW_FORM_data1
	.section	.debug_info
	.byte		0	; no source file information

	.section	.debug_abbrev
	.uleb128	DW_AT_decl_line
	.uleb128	DW_FORM_data1
	.section	.debug_info
	.byte		0	; no source line information

	.section	.debug_abbrev
	.uleb128	DW_AT_type
	.uleb128	DW_FORM_ref4
	.section	.debug_info
	.long		.Luint8_t - .Lssinfo

	.section	.debug_abbrev
	.uleb128	DW_AT_external
	.uleb128	DW_FORM_flag
	.section	.debug_info
	.byte		1

	.section	.debug_abbrev
	.uleb128	DW_AT_location
	.uleb128	DW_FORM_block1
	.section	.debug_info
	.byte		5	; length of block
	.byte		DW_OP_addr
	.long		0x800000 + 0x8F8 + 0x02

	.section	.debug_abbrev
	.uleb128	0
	.uleb128	0

	;; trailer
	.section	.debug_abbrev
	.uleb128	0

	.section	.debug_info
	.uleb128	0
.Leinfo:
