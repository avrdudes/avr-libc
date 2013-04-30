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
	.word		0x0200 - 1
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
	.long		0x810000 + 0x0000

	.section	.debug_abbrev
	.uleb128	0
	.uleb128	0

;- - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
	;; DIE #7: variable PORTB
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
	.string		"PORTB"
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
	.long		0x800000 + 0x00 + 0x25

	.section	.debug_abbrev
	.uleb128	0
	.uleb128	0

;- - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
	;; DIE #8: variable DDRB
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
	.string		"DDRB"
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
	.long		0x800000 + 0x00 + 0x24

	.section	.debug_abbrev
	.uleb128	0
	.uleb128	0

;- - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
	;; DIE #9: variable PINB
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
	.string		"PINB"
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
	.long		0x800000 + 0x00 + 0x23

	.section	.debug_abbrev
	.uleb128	0
	.uleb128	0

;- - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
	;; DIE #10: variable PORTC
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
	.string		"PORTC"
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
	.long		0x800000 + 0x00 + 0x28

	.section	.debug_abbrev
	.uleb128	0
	.uleb128	0

;- - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
	;; DIE #11: variable DDRC
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
	.string		"DDRC"
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
	.long		0x800000 + 0x00 + 0x27

	.section	.debug_abbrev
	.uleb128	0
	.uleb128	0

;- - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
	;; DIE #12: variable PINC
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
	.string		"PINC"
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
	.long		0x800000 + 0x00 + 0x26

	.section	.debug_abbrev
	.uleb128	0
	.uleb128	0

;- - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
	;; DIE #13: variable PORTD
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
	.string		"PORTD"
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
	.long		0x800000 + 0x00 + 0x2B

	.section	.debug_abbrev
	.uleb128	0
	.uleb128	0

;- - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
	;; DIE #14: variable DDRD
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
	.string		"DDRD"
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
	.long		0x800000 + 0x00 + 0x2A

	.section	.debug_abbrev
	.uleb128	0
	.uleb128	0

;- - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
	;; DIE #15: variable PIND
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
	.string		"PIND"
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
	.long		0x800000 + 0x00 + 0x29

	.section	.debug_abbrev
	.uleb128	0
	.uleb128	0

;- - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
	;; DIE #16: variable SPMCSR
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
	.string		"SPMCSR"
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
	.long		0x800000 + 0x00 + 0x57

	.section	.debug_abbrev
	.uleb128	0
	.uleb128	0

;- - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
	;; DIE #17: variable EUDR
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
	.string		"EUDR"
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
	.long		0x800000 + 0x00 + 0xCE

	.section	.debug_abbrev
	.uleb128	0
	.uleb128	0

;- - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
	;; DIE #18: variable EUCSRA
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
	.string		"EUCSRA"
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
	.long		0x800000 + 0x00 + 0xC8

	.section	.debug_abbrev
	.uleb128	0
	.uleb128	0

;- - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
	;; DIE #19: variable EUCSRB
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
	.string		"EUCSRB"
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
	.long		0x800000 + 0x00 + 0xC9

	.section	.debug_abbrev
	.uleb128	0
	.uleb128	0

;- - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
	;; DIE #20: variable EUCSRC
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
	.string		"EUCSRC"
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
	.long		0x800000 + 0x00 + 0xCA

	.section	.debug_abbrev
	.uleb128	0
	.uleb128	0

;- - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
	;; DIE #21: variable MUBRRH
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
	.string		"MUBRRH"
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
	.long		0x800000 + 0x00 + 0xCD

	.section	.debug_abbrev
	.uleb128	0
	.uleb128	0

;- - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
	;; DIE #22: variable MUBRRL
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
	.string		"MUBRRL"
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
	.long		0x800000 + 0x00 + 0xCC

	.section	.debug_abbrev
	.uleb128	0
	.uleb128	0

;- - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
	;; DIE #23: variable AC0CON
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
	.string		"AC0CON"
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
	.long		0x800000 + 0x00 + 0xAD

	.section	.debug_abbrev
	.uleb128	0
	.uleb128	0

;- - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
	;; DIE #24: variable AC1CON
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
	.string		"AC1CON"
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
	.long		0x800000 + 0x00 + 0xAE

	.section	.debug_abbrev
	.uleb128	0
	.uleb128	0

;- - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
	;; DIE #25: variable AC2CON
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
	.string		"AC2CON"
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
	.long		0x800000 + 0x00 + 0xAF

	.section	.debug_abbrev
	.uleb128	0
	.uleb128	0

;- - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
	;; DIE #26: variable ACSR
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
	.string		"ACSR"
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
	.long		0x800000 + 0x00 + 0x50

	.section	.debug_abbrev
	.uleb128	0
	.uleb128	0

;- - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
	;; DIE #27: variable DACH
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
	.string		"DACH"
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
	.long		0x800000 + 0x00 + 0xAC

	.section	.debug_abbrev
	.uleb128	0
	.uleb128	0

;- - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
	;; DIE #28: variable DACL
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
	.string		"DACL"
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
	.long		0x800000 + 0x00 + 0xAB

	.section	.debug_abbrev
	.uleb128	0
	.uleb128	0

;- - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
	;; DIE #29: variable DACON
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
	.string		"DACON"
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
	.long		0x800000 + 0x00 + 0xAA

	.section	.debug_abbrev
	.uleb128	0
	.uleb128	0

;- - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
	;; DIE #30: variable SREG
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
	.string		"SREG"
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
	.long		0x800000 + 0x00 + 0x5F

	.section	.debug_abbrev
	.uleb128	0
	.uleb128	0

;- - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
	;; DIE #31: variable SP
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
	.string		"SP"
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
	.long		0x800000 + 0x00 + 0x5D

	.section	.debug_abbrev
	.uleb128	0
	.uleb128	0

;- - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
	;; DIE #32: variable MCUCR
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
	.string		"MCUCR"
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
	.long		0x800000 + 0x00 + 0x55

	.section	.debug_abbrev
	.uleb128	0
	.uleb128	0

;- - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
	;; DIE #33: variable MCUSR
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
	.string		"MCUSR"
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
	.long		0x800000 + 0x00 + 0x54

	.section	.debug_abbrev
	.uleb128	0
	.uleb128	0

;- - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
	;; DIE #34: variable OSCCAL
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
	.string		"OSCCAL"
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
	.long		0x800000 + 0x00 + 0x66

	.section	.debug_abbrev
	.uleb128	0
	.uleb128	0

;- - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
	;; DIE #35: variable CLKPR
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
	.string		"CLKPR"
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
	.long		0x800000 + 0x00 + 0x61

	.section	.debug_abbrev
	.uleb128	0
	.uleb128	0

;- - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
	;; DIE #36: variable SMCR
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
	.string		"SMCR"
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
	.long		0x800000 + 0x00 + 0x53

	.section	.debug_abbrev
	.uleb128	0
	.uleb128	0

;- - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
	;; DIE #37: variable GPIOR3
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
	.string		"GPIOR3"
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
	.long		0x800000 + 0x00 + 0x3B

	.section	.debug_abbrev
	.uleb128	0
	.uleb128	0

;- - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
	;; DIE #38: variable GPIOR2
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
	.string		"GPIOR2"
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
	.long		0x800000 + 0x00 + 0x3A

	.section	.debug_abbrev
	.uleb128	0
	.uleb128	0

;- - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
	;; DIE #39: variable GPIOR1
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
	.string		"GPIOR1"
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
	.long		0x800000 + 0x00 + 0x39

	.section	.debug_abbrev
	.uleb128	0
	.uleb128	0

;- - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
	;; DIE #40: variable GPIOR0
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
	.string		"GPIOR0"
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
	.long		0x800000 + 0x00 + 0x3E

	.section	.debug_abbrev
	.uleb128	0
	.uleb128	0

;- - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
	;; DIE #41: variable PLLCSR
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
	.string		"PLLCSR"
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
	.long		0x800000 + 0x00 + 0x49

	.section	.debug_abbrev
	.uleb128	0
	.uleb128	0

;- - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
	;; DIE #42: variable PRR
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
	.string		"PRR"
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
	.long		0x800000 + 0x00 + 0x64

	.section	.debug_abbrev
	.uleb128	0
	.uleb128	0

;- - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
	;; DIE #43: variable PORTE
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
	.string		"PORTE"
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
	.long		0x800000 + 0x00 + 0x2E

	.section	.debug_abbrev
	.uleb128	0
	.uleb128	0

;- - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
	;; DIE #44: variable DDRE
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
	.string		"DDRE"
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
	.long		0x800000 + 0x00 + 0x2D

	.section	.debug_abbrev
	.uleb128	0
	.uleb128	0

;- - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
	;; DIE #45: variable PINE
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
	.string		"PINE"
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
	.long		0x800000 + 0x00 + 0x2C

	.section	.debug_abbrev
	.uleb128	0
	.uleb128	0

;- - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
	;; DIE #46: variable TIMSK0
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
	.string		"TIMSK0"
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
	.long		0x800000 + 0x00 + 0x6E

	.section	.debug_abbrev
	.uleb128	0
	.uleb128	0

;- - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
	;; DIE #47: variable TIFR0
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
	.string		"TIFR0"
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
	.long		0x800000 + 0x00 + 0x35

	.section	.debug_abbrev
	.uleb128	0
	.uleb128	0

;- - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
	;; DIE #48: variable TCCR0A
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
	.string		"TCCR0A"
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
	.long		0x800000 + 0x00 + 0x44

	.section	.debug_abbrev
	.uleb128	0
	.uleb128	0

;- - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
	;; DIE #49: variable TCCR0B
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
	.string		"TCCR0B"
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
	.long		0x800000 + 0x00 + 0x45

	.section	.debug_abbrev
	.uleb128	0
	.uleb128	0

;- - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
	;; DIE #50: variable TCNT0
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
	.string		"TCNT0"
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
	.long		0x800000 + 0x00 + 0x46

	.section	.debug_abbrev
	.uleb128	0
	.uleb128	0

;- - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
	;; DIE #51: variable OCR0A
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
	.string		"OCR0A"
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
	.long		0x800000 + 0x00 + 0x47

	.section	.debug_abbrev
	.uleb128	0
	.uleb128	0

;- - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
	;; DIE #52: variable OCR0B
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
	.string		"OCR0B"
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
	.long		0x800000 + 0x00 + 0x48

	.section	.debug_abbrev
	.uleb128	0
	.uleb128	0

;- - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
	;; DIE #53: variable GTCCR
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
	.string		"GTCCR"
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
	.long		0x800000 + 0x00 + 0x43

	.section	.debug_abbrev
	.uleb128	0
	.uleb128	0

;- - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
	;; DIE #54: variable TIMSK1
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
	.string		"TIMSK1"
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
	.long		0x800000 + 0x00 + 0x6F

	.section	.debug_abbrev
	.uleb128	0
	.uleb128	0

;- - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
	;; DIE #55: variable TIFR1
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
	.string		"TIFR1"
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
	.long		0x800000 + 0x00 + 0x36

	.section	.debug_abbrev
	.uleb128	0
	.uleb128	0

;- - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
	;; DIE #56: variable TCCR1A
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
	.string		"TCCR1A"
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
	.long		0x800000 + 0x00 + 0x80

	.section	.debug_abbrev
	.uleb128	0
	.uleb128	0

;- - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
	;; DIE #57: variable TCCR1B
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
	.string		"TCCR1B"
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
	.long		0x800000 + 0x00 + 0x81

	.section	.debug_abbrev
	.uleb128	0
	.uleb128	0

;- - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
	;; DIE #58: variable TCCR1C
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
	.string		"TCCR1C"
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
	.long		0x800000 + 0x00 + 0x82

	.section	.debug_abbrev
	.uleb128	0
	.uleb128	0

;- - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
	;; DIE #59: variable TCNT1
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
	.string		"TCNT1"
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
	.long		0x800000 + 0x00 + 0x84

	.section	.debug_abbrev
	.uleb128	0
	.uleb128	0

;- - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
	;; DIE #60: variable OCR1A
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
	.string		"OCR1A"
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
	.long		0x800000 + 0x00 + 0x88

	.section	.debug_abbrev
	.uleb128	0
	.uleb128	0

;- - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
	;; DIE #61: variable OCR1B
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
	.string		"OCR1B"
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
	.long		0x800000 + 0x00 + 0x8A

	.section	.debug_abbrev
	.uleb128	0
	.uleb128	0

;- - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
	;; DIE #62: variable ICR1
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
	.string		"ICR1"
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
	.long		0x800000 + 0x00 + 0x86

	.section	.debug_abbrev
	.uleb128	0
	.uleb128	0

;- - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
	;; DIE #63: variable GTCCR
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
	.string		"GTCCR"
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
	.long		0x800000 + 0x00 + 0x43

	.section	.debug_abbrev
	.uleb128	0
	.uleb128	0

;- - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
	;; DIE #64: variable ADMUX
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
	.string		"ADMUX"
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
	.long		0x800000 + 0x00 + 0x7C

	.section	.debug_abbrev
	.uleb128	0
	.uleb128	0

;- - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
	;; DIE #65: variable ADCSRA
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
	.string		"ADCSRA"
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
	.long		0x800000 + 0x00 + 0x7A

	.section	.debug_abbrev
	.uleb128	0
	.uleb128	0

;- - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
	;; DIE #66: variable ADC
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
	.string		"ADC"
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
	.long		0x800000 + 0x00 + 0x78

	.section	.debug_abbrev
	.uleb128	0
	.uleb128	0

;- - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
	;; DIE #67: variable ADCSRB
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
	.string		"ADCSRB"
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
	.long		0x800000 + 0x00 + 0x7B

	.section	.debug_abbrev
	.uleb128	0
	.uleb128	0

;- - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
	;; DIE #68: variable DIDR0
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
	.string		"DIDR0"
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
	.long		0x800000 + 0x00 + 0x7E

	.section	.debug_abbrev
	.uleb128	0
	.uleb128	0

;- - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
	;; DIE #69: variable DIDR1
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
	.string		"DIDR1"
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
	.long		0x800000 + 0x00 + 0x7F

	.section	.debug_abbrev
	.uleb128	0
	.uleb128	0

;- - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
	;; DIE #70: variable AMP0CSR
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
	.string		"AMP0CSR"
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
	.long		0x800000 + 0x00 + 0x76

	.section	.debug_abbrev
	.uleb128	0
	.uleb128	0

;- - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
	;; DIE #71: variable AMP1CSR
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
	.string		"AMP1CSR"
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
	.long		0x800000 + 0x00 + 0x77

	.section	.debug_abbrev
	.uleb128	0
	.uleb128	0

;- - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
	;; DIE #72: variable UDR
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
	.string		"UDR"
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
	.long		0x800000 + 0x00 + 0xC6

	.section	.debug_abbrev
	.uleb128	0
	.uleb128	0

;- - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
	;; DIE #73: variable UCSRA
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
	.string		"UCSRA"
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
	.long		0x800000 + 0x00 + 0xC0

	.section	.debug_abbrev
	.uleb128	0
	.uleb128	0

;- - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
	;; DIE #74: variable UCSRB
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
	.string		"UCSRB"
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
	.long		0x800000 + 0x00 + 0xC1

	.section	.debug_abbrev
	.uleb128	0
	.uleb128	0

;- - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
	;; DIE #75: variable UCSRC
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
	.string		"UCSRC"
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
	.long		0x800000 + 0x00 + 0xC2

	.section	.debug_abbrev
	.uleb128	0
	.uleb128	0

;- - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
	;; DIE #76: variable UBRRH
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
	.string		"UBRRH"
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
	.long		0x800000 + 0x00 + 0xC5

	.section	.debug_abbrev
	.uleb128	0
	.uleb128	0

;- - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
	;; DIE #77: variable UBRRL
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
	.string		"UBRRL"
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
	.long		0x800000 + 0x00 + 0xC4

	.section	.debug_abbrev
	.uleb128	0
	.uleb128	0

;- - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
	;; DIE #78: variable SPCR
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
	.string		"SPCR"
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
	.long		0x800000 + 0x00 + 0x4C

	.section	.debug_abbrev
	.uleb128	0
	.uleb128	0

;- - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
	;; DIE #79: variable SPSR
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
	.string		"SPSR"
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
	.long		0x800000 + 0x00 + 0x4D

	.section	.debug_abbrev
	.uleb128	0
	.uleb128	0

;- - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
	;; DIE #80: variable SPDR
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
	.string		"SPDR"
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
	.long		0x800000 + 0x00 + 0x4E

	.section	.debug_abbrev
	.uleb128	0
	.uleb128	0

;- - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
	;; DIE #81: variable WDTCSR
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
	.string		"WDTCSR"
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
	.long		0x800000 + 0x00 + 0x60

	.section	.debug_abbrev
	.uleb128	0
	.uleb128	0

;- - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
	;; DIE #82: variable EICRA
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
	.string		"EICRA"
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
	.long		0x800000 + 0x00 + 0x69

	.section	.debug_abbrev
	.uleb128	0
	.uleb128	0

;- - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
	;; DIE #83: variable EIMSK
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
	.string		"EIMSK"
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
	.long		0x800000 + 0x00 + 0x3D

	.section	.debug_abbrev
	.uleb128	0
	.uleb128	0

;- - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
	;; DIE #84: variable EIFR
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
	.string		"EIFR"
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
	.long		0x800000 + 0x00 + 0x3C

	.section	.debug_abbrev
	.uleb128	0
	.uleb128	0

;- - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
	;; DIE #85: variable EEAR
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
	.string		"EEAR"
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
	.long		0x800000 + 0x00 + 0x41

	.section	.debug_abbrev
	.uleb128	0
	.uleb128	0

;- - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
	;; DIE #86: variable EEDR
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
	.string		"EEDR"
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
	.long		0x800000 + 0x00 + 0x40

	.section	.debug_abbrev
	.uleb128	0
	.uleb128	0

;- - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
	;; DIE #87: variable EECR
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
	.string		"EECR"
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
	.long		0x800000 + 0x00 + 0x3F

	.section	.debug_abbrev
	.uleb128	0
	.uleb128	0

;- - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
	;; DIE #88: variable PICR0
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
	.string		"PICR0"
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
	.long		0x800000 + 0x00 + 0xDE

	.section	.debug_abbrev
	.uleb128	0
	.uleb128	0

;- - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
	;; DIE #89: variable PFRC0B
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
	.string		"PFRC0B"
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
	.long		0x800000 + 0x00 + 0xDD

	.section	.debug_abbrev
	.uleb128	0
	.uleb128	0

;- - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
	;; DIE #90: variable PFRC0A
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
	.string		"PFRC0A"
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
	.long		0x800000 + 0x00 + 0xDC

	.section	.debug_abbrev
	.uleb128	0
	.uleb128	0

;- - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
	;; DIE #91: variable PCTL0
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
	.string		"PCTL0"
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
	.long		0x800000 + 0x00 + 0xDB

	.section	.debug_abbrev
	.uleb128	0
	.uleb128	0

;- - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
	;; DIE #92: variable PCNF0
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
	.string		"PCNF0"
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
	.long		0x800000 + 0x00 + 0xDA

	.section	.debug_abbrev
	.uleb128	0
	.uleb128	0

;- - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
	;; DIE #93: variable OCR0RB
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
	.string		"OCR0RB"
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
	.long		0x800000 + 0x00 + 0xD8

	.section	.debug_abbrev
	.uleb128	0
	.uleb128	0

;- - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
	;; DIE #94: variable OCR0SB
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
	.string		"OCR0SB"
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
	.long		0x800000 + 0x00 + 0xD6

	.section	.debug_abbrev
	.uleb128	0
	.uleb128	0

;- - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
	;; DIE #95: variable OCR0RA
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
	.string		"OCR0RA"
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
	.long		0x800000 + 0x00 + 0xD4

	.section	.debug_abbrev
	.uleb128	0
	.uleb128	0

;- - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
	;; DIE #96: variable OCR0SA
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
	.string		"OCR0SA"
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
	.long		0x800000 + 0x00 + 0xD2

	.section	.debug_abbrev
	.uleb128	0
	.uleb128	0

;- - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
	;; DIE #97: variable PSOC0
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
	.string		"PSOC0"
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
	.long		0x800000 + 0x00 + 0xD0

	.section	.debug_abbrev
	.uleb128	0
	.uleb128	0

;- - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
	;; DIE #98: variable PIM0
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
	.string		"PIM0"
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
	.long		0x800000 + 0x00 + 0xA1

	.section	.debug_abbrev
	.uleb128	0
	.uleb128	0

;- - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
	;; DIE #99: variable PIFR0
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
	.string		"PIFR0"
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
	.long		0x800000 + 0x00 + 0xA0

	.section	.debug_abbrev
	.uleb128	0
	.uleb128	0

;- - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
	;; DIE #100: variable PICR1
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
	.string		"PICR1"
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
	.long		0x800000 + 0x00 + 0xEE

	.section	.debug_abbrev
	.uleb128	0
	.uleb128	0

;- - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
	;; DIE #101: variable PFRC1B
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
	.string		"PFRC1B"
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
	.long		0x800000 + 0x00 + 0xED

	.section	.debug_abbrev
	.uleb128	0
	.uleb128	0

;- - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
	;; DIE #102: variable PFRC1A
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
	.string		"PFRC1A"
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
	.long		0x800000 + 0x00 + 0xEC

	.section	.debug_abbrev
	.uleb128	0
	.uleb128	0

;- - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
	;; DIE #103: variable PCTL1
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
	.string		"PCTL1"
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
	.long		0x800000 + 0x00 + 0xEB

	.section	.debug_abbrev
	.uleb128	0
	.uleb128	0

;- - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
	;; DIE #104: variable PCNF1
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
	.string		"PCNF1"
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
	.long		0x800000 + 0x00 + 0xEA

	.section	.debug_abbrev
	.uleb128	0
	.uleb128	0

;- - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
	;; DIE #105: variable OCR1RB
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
	.string		"OCR1RB"
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
	.long		0x800000 + 0x00 + 0xE8

	.section	.debug_abbrev
	.uleb128	0
	.uleb128	0

;- - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
	;; DIE #106: variable OCR1SB
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
	.string		"OCR1SB"
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
	.long		0x800000 + 0x00 + 0xE6

	.section	.debug_abbrev
	.uleb128	0
	.uleb128	0

;- - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
	;; DIE #107: variable OCR1RA
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
	.string		"OCR1RA"
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
	.long		0x800000 + 0x00 + 0xE4

	.section	.debug_abbrev
	.uleb128	0
	.uleb128	0

;- - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
	;; DIE #108: variable OCR1SA
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
	.string		"OCR1SA"
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
	.long		0x800000 + 0x00 + 0xE2

	.section	.debug_abbrev
	.uleb128	0
	.uleb128	0

;- - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
	;; DIE #109: variable PSOC1
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
	.string		"PSOC1"
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
	.long		0x800000 + 0x00 + 0xE0

	.section	.debug_abbrev
	.uleb128	0
	.uleb128	0

;- - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
	;; DIE #110: variable PIM1
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
	.string		"PIM1"
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
	.long		0x800000 + 0x00 + 0xA3

	.section	.debug_abbrev
	.uleb128	0
	.uleb128	0

;- - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
	;; DIE #111: variable PIFR1
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
	.string		"PIFR1"
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
	.long		0x800000 + 0x00 + 0xA2

	.section	.debug_abbrev
	.uleb128	0
	.uleb128	0

;- - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
	;; DIE #112: variable PICR2
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
	.string		"PICR2"
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
	.long		0x800000 + 0x00 + 0xFE

	.section	.debug_abbrev
	.uleb128	0
	.uleb128	0

;- - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
	;; DIE #113: variable PFRC2B
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
	.string		"PFRC2B"
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
	.long		0x800000 + 0x00 + 0xFD

	.section	.debug_abbrev
	.uleb128	0
	.uleb128	0

;- - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
	;; DIE #114: variable PFRC2A
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
	.string		"PFRC2A"
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
	.long		0x800000 + 0x00 + 0xFC

	.section	.debug_abbrev
	.uleb128	0
	.uleb128	0

;- - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
	;; DIE #115: variable PCTL2
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
	.string		"PCTL2"
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
	.long		0x800000 + 0x00 + 0xFB

	.section	.debug_abbrev
	.uleb128	0
	.uleb128	0

;- - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
	;; DIE #116: variable PCNF2
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
	.string		"PCNF2"
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
	.long		0x800000 + 0x00 + 0xFA

	.section	.debug_abbrev
	.uleb128	0
	.uleb128	0

;- - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
	;; DIE #117: variable OCR2RB
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
	.string		"OCR2RB"
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
	.long		0x800000 + 0x00 + 0xF8

	.section	.debug_abbrev
	.uleb128	0
	.uleb128	0

;- - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
	;; DIE #118: variable OCR2SB
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
	.string		"OCR2SB"
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
	.long		0x800000 + 0x00 + 0xF6

	.section	.debug_abbrev
	.uleb128	0
	.uleb128	0

;- - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
	;; DIE #119: variable OCR2RA
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
	.string		"OCR2RA"
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
	.long		0x800000 + 0x00 + 0xF4

	.section	.debug_abbrev
	.uleb128	0
	.uleb128	0

;- - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
	;; DIE #120: variable OCR2SA
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
	.string		"OCR2SA"
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
	.long		0x800000 + 0x00 + 0xF2

	.section	.debug_abbrev
	.uleb128	0
	.uleb128	0

;- - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
	;; DIE #121: variable POM2
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
	.string		"POM2"
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
	.long		0x800000 + 0x00 + 0xF1

	.section	.debug_abbrev
	.uleb128	0
	.uleb128	0

;- - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
	;; DIE #122: variable PSOC2
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
	.string		"PSOC2"
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
	.long		0x800000 + 0x00 + 0xF0

	.section	.debug_abbrev
	.uleb128	0
	.uleb128	0

;- - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
	;; DIE #123: variable PIM2
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
	.string		"PIM2"
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
	.long		0x800000 + 0x00 + 0xA5

	.section	.debug_abbrev
	.uleb128	0
	.uleb128	0

;- - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
	;; DIE #124: variable PIFR2
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
	.string		"PIFR2"
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
	.long		0x800000 + 0x00 + 0xA4

	.section	.debug_abbrev
	.uleb128	0
	.uleb128	0

	;; trailer
	.section	.debug_abbrev
	.uleb128	0

	.section	.debug_info
	.uleb128	0
.Leinfo:
