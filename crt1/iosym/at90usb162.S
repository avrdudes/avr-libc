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
	;; DIE #10: variable PORTD
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
	.string		"PORTD"
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
	.long		0x800000 + 0x00 + 0x2B

	.section	.debug_abbrev
	.uleb128	0
	.uleb128	0

;- - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
	;; DIE #11: variable DDRD
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
	.string		"DDRD"
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
	.long		0x800000 + 0x00 + 0x2A

	.section	.debug_abbrev
	.uleb128	0
	.uleb128	0

;- - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
	;; DIE #12: variable PIND
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
	.string		"PIND"
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
	.long		0x800000 + 0x00 + 0x29

	.section	.debug_abbrev
	.uleb128	0
	.uleb128	0

;- - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
	;; DIE #13: variable SPCR
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
	.string		"SPCR"
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
	.long		0x800000 + 0x00 + 0x4C

	.section	.debug_abbrev
	.uleb128	0
	.uleb128	0

;- - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
	;; DIE #14: variable SPSR
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
	.string		"SPSR"
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
	.long		0x800000 + 0x00 + 0x4D

	.section	.debug_abbrev
	.uleb128	0
	.uleb128	0

;- - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
	;; DIE #15: variable SPDR
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
	.string		"SPDR"
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
	.long		0x800000 + 0x00 + 0x4E

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
	;; DIE #17: variable EEAR
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
	.string		"EEAR"
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
	;; DIE #18: variable EEDR
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
	.string		"EEDR"
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
	.long		0x800000 + 0x00 + 0x40

	.section	.debug_abbrev
	.uleb128	0
	.uleb128	0

;- - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
	;; DIE #19: variable EECR
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
	.string		"EECR"
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
	.long		0x800000 + 0x00 + 0x3F

	.section	.debug_abbrev
	.uleb128	0
	.uleb128	0

;- - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
	;; DIE #20: variable OCR0B
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
	.string		"OCR0B"
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
	.long		0x800000 + 0x00 + 0x48

	.section	.debug_abbrev
	.uleb128	0
	.uleb128	0

;- - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
	;; DIE #21: variable OCR0A
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
	.string		"OCR0A"
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
	.long		0x800000 + 0x00 + 0x47

	.section	.debug_abbrev
	.uleb128	0
	.uleb128	0

;- - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
	;; DIE #22: variable TCNT0
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
	.string		"TCNT0"
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
	.long		0x800000 + 0x00 + 0x46

	.section	.debug_abbrev
	.uleb128	0
	.uleb128	0

;- - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
	;; DIE #23: variable TCCR0B
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
	.string		"TCCR0B"
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
	.long		0x800000 + 0x00 + 0x45

	.section	.debug_abbrev
	.uleb128	0
	.uleb128	0

;- - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
	;; DIE #24: variable TCCR0A
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
	.string		"TCCR0A"
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
	.long		0x800000 + 0x00 + 0x44

	.section	.debug_abbrev
	.uleb128	0
	.uleb128	0

;- - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
	;; DIE #25: variable TIMSK0
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
	.string		"TIMSK0"
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
	.long		0x800000 + 0x00 + 0x6E

	.section	.debug_abbrev
	.uleb128	0
	.uleb128	0

;- - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
	;; DIE #26: variable TIFR0
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
	.string		"TIFR0"
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
	.long		0x800000 + 0x00 + 0x35

	.section	.debug_abbrev
	.uleb128	0
	.uleb128	0

;- - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
	;; DIE #27: variable GTCCR
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
	.string		"GTCCR"
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
	.long		0x800000 + 0x00 + 0x43

	.section	.debug_abbrev
	.uleb128	0
	.uleb128	0

;- - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
	;; DIE #28: variable TCCR1A
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
	.string		"TCCR1A"
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
	.long		0x800000 + 0x00 + 0x80

	.section	.debug_abbrev
	.uleb128	0
	.uleb128	0

;- - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
	;; DIE #29: variable TCCR1B
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
	.string		"TCCR1B"
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
	.long		0x800000 + 0x00 + 0x81

	.section	.debug_abbrev
	.uleb128	0
	.uleb128	0

;- - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
	;; DIE #30: variable TCCR1C
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
	.string		"TCCR1C"
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
	.long		0x800000 + 0x00 + 0x82

	.section	.debug_abbrev
	.uleb128	0
	.uleb128	0

;- - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
	;; DIE #31: variable TCNT1
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
	.string		"TCNT1"
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
	.long		0x800000 + 0x00 + 0x84

	.section	.debug_abbrev
	.uleb128	0
	.uleb128	0

;- - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
	;; DIE #32: variable OCR1A
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
	.string		"OCR1A"
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
	;; DIE #33: variable OCR1B
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
	.string		"OCR1B"
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
	;; DIE #34: variable OCR1C
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
	.string		"OCR1C"
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
	.long		0x800000 + 0x00 + 0x8C

	.section	.debug_abbrev
	.uleb128	0
	.uleb128	0

;- - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
	;; DIE #35: variable ICR1
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
	.string		"ICR1"
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
	;; DIE #36: variable TIMSK1
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
	.string		"TIMSK1"
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
	.long		0x800000 + 0x00 + 0x6F

	.section	.debug_abbrev
	.uleb128	0
	.uleb128	0

;- - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
	;; DIE #37: variable TIFR1
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
	.string		"TIFR1"
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
	.long		0x800000 + 0x00 + 0x36

	.section	.debug_abbrev
	.uleb128	0
	.uleb128	0

;- - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
	;; DIE #38: variable PLLCSR
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
	.string		"PLLCSR"
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
	.long		0x800000 + 0x00 + 0x49

	.section	.debug_abbrev
	.uleb128	0
	.uleb128	0

;- - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
	;; DIE #39: variable UEINT
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
	.string		"UEINT"
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
	.long		0x800000 + 0x00 + 0xF4

	.section	.debug_abbrev
	.uleb128	0
	.uleb128	0

;- - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
	;; DIE #40: variable UEBCLX
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
	.string		"UEBCLX"
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
	.long		0x800000 + 0x00 + 0xF2

	.section	.debug_abbrev
	.uleb128	0
	.uleb128	0

;- - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
	;; DIE #41: variable UEDATX
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
	.string		"UEDATX"
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
	.long		0x800000 + 0x00 + 0xF1

	.section	.debug_abbrev
	.uleb128	0
	.uleb128	0

;- - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
	;; DIE #42: variable UEIENX
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
	.string		"UEIENX"
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
	.long		0x800000 + 0x00 + 0xF0

	.section	.debug_abbrev
	.uleb128	0
	.uleb128	0

;- - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
	;; DIE #43: variable UESTA1X
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
	.string		"UESTA1X"
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
	.long		0x800000 + 0x00 + 0xEF

	.section	.debug_abbrev
	.uleb128	0
	.uleb128	0

;- - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
	;; DIE #44: variable UESTA0X
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
	.string		"UESTA0X"
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
	.long		0x800000 + 0x00 + 0xEE

	.section	.debug_abbrev
	.uleb128	0
	.uleb128	0

;- - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
	;; DIE #45: variable UECFG1X
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
	.string		"UECFG1X"
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
	.long		0x800000 + 0x00 + 0xED

	.section	.debug_abbrev
	.uleb128	0
	.uleb128	0

;- - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
	;; DIE #46: variable UECFG0X
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
	.string		"UECFG0X"
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
	.long		0x800000 + 0x00 + 0xEC

	.section	.debug_abbrev
	.uleb128	0
	.uleb128	0

;- - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
	;; DIE #47: variable UECONX
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
	.string		"UECONX"
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
	.long		0x800000 + 0x00 + 0xEB

	.section	.debug_abbrev
	.uleb128	0
	.uleb128	0

;- - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
	;; DIE #48: variable UERST
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
	.string		"UERST"
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
	.long		0x800000 + 0x00 + 0xEA

	.section	.debug_abbrev
	.uleb128	0
	.uleb128	0

;- - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
	;; DIE #49: variable UENUM
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
	.string		"UENUM"
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
	.long		0x800000 + 0x00 + 0xE9

	.section	.debug_abbrev
	.uleb128	0
	.uleb128	0

;- - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
	;; DIE #50: variable UEINTX
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
	.string		"UEINTX"
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
	.long		0x800000 + 0x00 + 0xE8

	.section	.debug_abbrev
	.uleb128	0
	.uleb128	0

;- - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
	;; DIE #51: variable UDMFN
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
	.string		"UDMFN"
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
	.long		0x800000 + 0x00 + 0xE6

	.section	.debug_abbrev
	.uleb128	0
	.uleb128	0

;- - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
	;; DIE #52: variable UDFNUM
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
	.string		"UDFNUM"
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
	;; DIE #53: variable UDADDR
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
	.string		"UDADDR"
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
	.long		0x800000 + 0x00 + 0xE3

	.section	.debug_abbrev
	.uleb128	0
	.uleb128	0

;- - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
	;; DIE #54: variable UDIEN
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
	.string		"UDIEN"
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
	.long		0x800000 + 0x00 + 0xE2

	.section	.debug_abbrev
	.uleb128	0
	.uleb128	0

;- - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
	;; DIE #55: variable UDINT
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
	.string		"UDINT"
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
	.long		0x800000 + 0x00 + 0xE1

	.section	.debug_abbrev
	.uleb128	0
	.uleb128	0

;- - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
	;; DIE #56: variable UDCON
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
	.string		"UDCON"
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
	.long		0x800000 + 0x00 + 0xE0

	.section	.debug_abbrev
	.uleb128	0
	.uleb128	0

;- - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
	;; DIE #57: variable USBCON
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
	.string		"USBCON"
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
	.long		0x800000 + 0x00 + 0xD8

	.section	.debug_abbrev
	.uleb128	0
	.uleb128	0

;- - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
	;; DIE #58: variable REGCR
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
	.string		"REGCR"
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
	.long		0x800000 + 0x00 + 0x63

	.section	.debug_abbrev
	.uleb128	0
	.uleb128	0

;- - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
	;; DIE #59: variable UPOE
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
	.string		"UPOE"
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
	.long		0x800000 + 0x00 + 0xFB

	.section	.debug_abbrev
	.uleb128	0
	.uleb128	0

;- - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
	;; DIE #60: variable PS2CON
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
	.string		"PS2CON"
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
	.long		0x800000 + 0x00 + 0xFA

	.section	.debug_abbrev
	.uleb128	0
	.uleb128	0

;- - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
	;; DIE #61: variable SREG
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
	.string		"SREG"
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
	.long		0x800000 + 0x00 + 0x5F

	.section	.debug_abbrev
	.uleb128	0
	.uleb128	0

;- - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
	;; DIE #62: variable SP
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
	.string		"SP"
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
	.long		0x800000 + 0x00 + 0x5D

	.section	.debug_abbrev
	.uleb128	0
	.uleb128	0

;- - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
	;; DIE #63: variable MCUCR
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
	.string		"MCUCR"
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
	.long		0x800000 + 0x00 + 0x55

	.section	.debug_abbrev
	.uleb128	0
	.uleb128	0

;- - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
	;; DIE #64: variable MCUSR
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
	.string		"MCUSR"
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
	.long		0x800000 + 0x00 + 0x54

	.section	.debug_abbrev
	.uleb128	0
	.uleb128	0

;- - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
	;; DIE #65: variable OSCCAL
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
	.string		"OSCCAL"
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
	.long		0x800000 + 0x00 + 0x66

	.section	.debug_abbrev
	.uleb128	0
	.uleb128	0

;- - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
	;; DIE #66: variable CLKPR
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
	.string		"CLKPR"
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
	.long		0x800000 + 0x00 + 0x61

	.section	.debug_abbrev
	.uleb128	0
	.uleb128	0

;- - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
	;; DIE #67: variable SMCR
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
	.string		"SMCR"
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
	.long		0x800000 + 0x00 + 0x53

	.section	.debug_abbrev
	.uleb128	0
	.uleb128	0

;- - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
	;; DIE #68: variable EIND
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
	.string		"EIND"
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
	.long		0x800000 + 0x00 + 0x5C

	.section	.debug_abbrev
	.uleb128	0
	.uleb128	0

;- - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
	;; DIE #69: variable GPIOR2
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
	.string		"GPIOR2"
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
	.long		0x800000 + 0x00 + 0x4B

	.section	.debug_abbrev
	.uleb128	0
	.uleb128	0

;- - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
	;; DIE #70: variable GPIOR1
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
	.string		"GPIOR1"
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
	.long		0x800000 + 0x00 + 0x4A

	.section	.debug_abbrev
	.uleb128	0
	.uleb128	0

;- - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
	;; DIE #71: variable GPIOR0
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
	.string		"GPIOR0"
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
	.long		0x800000 + 0x00 + 0x3E

	.section	.debug_abbrev
	.uleb128	0
	.uleb128	0

;- - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
	;; DIE #72: variable PRR1
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
	.string		"PRR1"
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
	.long		0x800000 + 0x00 + 0x65

	.section	.debug_abbrev
	.uleb128	0
	.uleb128	0

;- - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
	;; DIE #73: variable PRR0
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
	.string		"PRR0"
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
	.long		0x800000 + 0x00 + 0x64

	.section	.debug_abbrev
	.uleb128	0
	.uleb128	0

;- - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
	;; DIE #74: variable CLKSTA
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
	.string		"CLKSTA"
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
	.long		0x800000 + 0x00 + 0xD2

	.section	.debug_abbrev
	.uleb128	0
	.uleb128	0

;- - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
	;; DIE #75: variable CLKSEL1
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
	.string		"CLKSEL1"
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
	.long		0x800000 + 0x00 + 0xD1

	.section	.debug_abbrev
	.uleb128	0
	.uleb128	0

;- - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
	;; DIE #76: variable CLKSEL0
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
	.string		"CLKSEL0"
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
	.long		0x800000 + 0x00 + 0xD0

	.section	.debug_abbrev
	.uleb128	0
	.uleb128	0

;- - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
	;; DIE #77: variable DWDR
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
	.string		"DWDR"
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
	.long		0x800000 + 0x00 + 0x51

	.section	.debug_abbrev
	.uleb128	0
	.uleb128	0

;- - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
	;; DIE #78: variable EICRA
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
	.string		"EICRA"
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
	.long		0x800000 + 0x00 + 0x69

	.section	.debug_abbrev
	.uleb128	0
	.uleb128	0

;- - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
	;; DIE #79: variable EICRB
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
	.string		"EICRB"
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
	.long		0x800000 + 0x00 + 0x6A

	.section	.debug_abbrev
	.uleb128	0
	.uleb128	0

;- - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
	;; DIE #80: variable EIMSK
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
	.string		"EIMSK"
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
	.long		0x800000 + 0x00 + 0x3D

	.section	.debug_abbrev
	.uleb128	0
	.uleb128	0

;- - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
	;; DIE #81: variable EIFR
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
	.string		"EIFR"
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
	.long		0x800000 + 0x00 + 0x3C

	.section	.debug_abbrev
	.uleb128	0
	.uleb128	0

;- - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
	;; DIE #82: variable PCMSK0
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
	.string		"PCMSK0"
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
	.long		0x800000 + 0x00 + 0x6B

	.section	.debug_abbrev
	.uleb128	0
	.uleb128	0

;- - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
	;; DIE #83: variable PCMSK1
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
	.string		"PCMSK1"
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
	.long		0x800000 + 0x00 + 0x6C

	.section	.debug_abbrev
	.uleb128	0
	.uleb128	0

;- - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
	;; DIE #84: variable PCIFR
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
	.string		"PCIFR"
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
	.long		0x800000 + 0x00 + 0x3B

	.section	.debug_abbrev
	.uleb128	0
	.uleb128	0

;- - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
	;; DIE #85: variable PCICR
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
	.string		"PCICR"
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
	.long		0x800000 + 0x00 + 0x68

	.section	.debug_abbrev
	.uleb128	0
	.uleb128	0

;- - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
	;; DIE #86: variable UDR1
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
	.string		"UDR1"
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
	.long		0x800000 + 0x00 + 0xCE

	.section	.debug_abbrev
	.uleb128	0
	.uleb128	0

;- - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
	;; DIE #87: variable UCSR1A
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
	.string		"UCSR1A"
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
	.long		0x800000 + 0x00 + 0xC8

	.section	.debug_abbrev
	.uleb128	0
	.uleb128	0

;- - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
	;; DIE #88: variable UCSR1B
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
	.string		"UCSR1B"
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
	.long		0x800000 + 0x00 + 0xC9

	.section	.debug_abbrev
	.uleb128	0
	.uleb128	0

;- - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
	;; DIE #89: variable UCSR1C
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
	.string		"UCSR1C"
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
	.long		0x800000 + 0x00 + 0xCA

	.section	.debug_abbrev
	.uleb128	0
	.uleb128	0

;- - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
	;; DIE #90: variable UCSR1D
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
	.string		"UCSR1D"
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
	.long		0x800000 + 0x00 + 0xCB

	.section	.debug_abbrev
	.uleb128	0
	.uleb128	0

;- - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
	;; DIE #91: variable UBRR1
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
	.string		"UBRR1"
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
	.long		0x800000 + 0x00 + 0xCC

	.section	.debug_abbrev
	.uleb128	0
	.uleb128	0

;- - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
	;; DIE #92: variable WDTCSR
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
	.string		"WDTCSR"
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
	.long		0x800000 + 0x00 + 0x60

	.section	.debug_abbrev
	.uleb128	0
	.uleb128	0

;- - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
	;; DIE #93: variable WDTCKD
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
	.string		"WDTCKD"
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
	.long		0x800000 + 0x00 + 0x62

	.section	.debug_abbrev
	.uleb128	0
	.uleb128	0

;- - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
	;; DIE #94: variable ACSR
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
	.string		"ACSR"
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
	.long		0x800000 + 0x00 + 0x50

	.section	.debug_abbrev
	.uleb128	0
	.uleb128	0

;- - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
	;; DIE #95: variable DIDR1
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
	.string		"DIDR1"
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
	.long		0x800000 + 0x00 + 0x7F

	.section	.debug_abbrev
	.uleb128	0
	.uleb128	0

;- - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
	;; DIE #96: variable PORTC
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
	.string		"PORTC"
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
	.long		0x800000 + 0x00 + 0x28

	.section	.debug_abbrev
	.uleb128	0
	.uleb128	0

;- - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
	;; DIE #97: variable DDRC
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
	.string		"DDRC"
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
	.long		0x800000 + 0x00 + 0x27

	.section	.debug_abbrev
	.uleb128	0
	.uleb128	0

;- - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
	;; DIE #98: variable PINC
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
	.string		"PINC"
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
	.long		0x800000 + 0x00 + 0x26

	.section	.debug_abbrev
	.uleb128	0
	.uleb128	0

	;; trailer
	.section	.debug_abbrev
	.uleb128	0

	.section	.debug_info
	.uleb128	0
.Leinfo:
