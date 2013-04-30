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
	.word		0x0100 - 1
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
	.long		0x800000 + 0x00 + 0x38

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
	.long		0x800000 + 0x00 + 0x37

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
	.long		0x800000 + 0x00 + 0x36

	.section	.debug_abbrev
	.uleb128	0
	.uleb128	0

;- - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
	;; DIE #10: variable ADCSRB
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
	.string		"ADCSRB"
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
	.long		0x800000 + 0x00 + 0x23

	.section	.debug_abbrev
	.uleb128	0
	.uleb128	0

;- - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
	;; DIE #11: variable ACSR
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
	.string		"ACSR"
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
	.long		0x800000 + 0x00 + 0x28

	.section	.debug_abbrev
	.uleb128	0
	.uleb128	0

;- - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
	;; DIE #12: variable DIDR0
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
	.string		"DIDR0"
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
	.long		0x800000 + 0x00 + 0x34

	.section	.debug_abbrev
	.uleb128	0
	.uleb128	0

;- - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
	;; DIE #13: variable ADMUX
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
	.string		"ADMUX"
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
	.long		0x800000 + 0x00 + 0x27

	.section	.debug_abbrev
	.uleb128	0
	.uleb128	0

;- - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
	;; DIE #14: variable ADCSRA
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
	.string		"ADCSRA"
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
	.long		0x800000 + 0x00 + 0x26

	.section	.debug_abbrev
	.uleb128	0
	.uleb128	0

;- - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
	;; DIE #15: variable ADC
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
	.string		"ADC"
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
	.long		0x800000 + 0x00 + 0x24

	.section	.debug_abbrev
	.uleb128	0
	.uleb128	0

;- - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
	;; DIE #16: variable ADCSRB
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
	.string		"ADCSRB"
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
	.long		0x800000 + 0x00 + 0x23

	.section	.debug_abbrev
	.uleb128	0
	.uleb128	0

;- - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
	;; DIE #17: variable DIDR0
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
	.string		"DIDR0"
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
	.long		0x800000 + 0x00 + 0x34

	.section	.debug_abbrev
	.uleb128	0
	.uleb128	0

;- - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
	;; DIE #18: variable USIBR
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
	.string		"USIBR"
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
	.long		0x800000 + 0x00 + 0x30

	.section	.debug_abbrev
	.uleb128	0
	.uleb128	0

;- - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
	;; DIE #19: variable USIDR
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
	.string		"USIDR"
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
	.long		0x800000 + 0x00 + 0x2F

	.section	.debug_abbrev
	.uleb128	0
	.uleb128	0

;- - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
	;; DIE #20: variable USISR
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
	.string		"USISR"
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
	.long		0x800000 + 0x00 + 0x2E

	.section	.debug_abbrev
	.uleb128	0
	.uleb128	0

;- - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
	;; DIE #21: variable USICR
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
	.string		"USICR"
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
	.long		0x800000 + 0x00 + 0x2D

	.section	.debug_abbrev
	.uleb128	0
	.uleb128	0

;- - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
	;; DIE #22: variable MCUCR
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
	.string		"MCUCR"
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
	.long		0x800000 + 0x00 + 0x55

	.section	.debug_abbrev
	.uleb128	0
	.uleb128	0

;- - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
	;; DIE #23: variable GIMSK
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
	.string		"GIMSK"
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
	.long		0x800000 + 0x00 + 0x5B

	.section	.debug_abbrev
	.uleb128	0
	.uleb128	0

;- - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
	;; DIE #24: variable GIFR
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
	.string		"GIFR"
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
	.long		0x800000 + 0x00 + 0x5A

	.section	.debug_abbrev
	.uleb128	0
	.uleb128	0

;- - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
	;; DIE #25: variable PCMSK
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
	.string		"PCMSK"
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
	.long		0x800000 + 0x00 + 0x35

	.section	.debug_abbrev
	.uleb128	0
	.uleb128	0

;- - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
	;; DIE #26: variable EEAR
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
	.string		"EEAR"
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
	.long		0x800000 + 0x00 + 0x3E

	.section	.debug_abbrev
	.uleb128	0
	.uleb128	0

;- - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
	;; DIE #27: variable EEDR
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
	.string		"EEDR"
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
	.long		0x800000 + 0x00 + 0x3D

	.section	.debug_abbrev
	.uleb128	0
	.uleb128	0

;- - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
	;; DIE #28: variable EECR
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
	.string		"EECR"
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
	.long		0x800000 + 0x00 + 0x3C

	.section	.debug_abbrev
	.uleb128	0
	.uleb128	0

;- - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
	;; DIE #29: variable WDTCR
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
	.string		"WDTCR"
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
	.long		0x800000 + 0x00 + 0x41

	.section	.debug_abbrev
	.uleb128	0
	.uleb128	0

;- - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
	;; DIE #30: variable TIMSK
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
	.string		"TIMSK"
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
	.long		0x800000 + 0x00 + 0x59

	.section	.debug_abbrev
	.uleb128	0
	.uleb128	0

;- - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
	;; DIE #31: variable TIFR
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
	.string		"TIFR"
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
	.long		0x800000 + 0x00 + 0x58

	.section	.debug_abbrev
	.uleb128	0
	.uleb128	0

;- - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
	;; DIE #32: variable TCCR0A
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
	.string		"TCCR0A"
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
	.long		0x800000 + 0x00 + 0x4A

	.section	.debug_abbrev
	.uleb128	0
	.uleb128	0

;- - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
	;; DIE #33: variable TCCR0B
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
	.string		"TCCR0B"
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
	.long		0x800000 + 0x00 + 0x53

	.section	.debug_abbrev
	.uleb128	0
	.uleb128	0

;- - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
	;; DIE #34: variable TCNT0
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
	.string		"TCNT0"
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
	.long		0x800000 + 0x00 + 0x52

	.section	.debug_abbrev
	.uleb128	0
	.uleb128	0

;- - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
	;; DIE #35: variable OCR0A
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
	.string		"OCR0A"
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
	.long		0x800000 + 0x00 + 0x49

	.section	.debug_abbrev
	.uleb128	0
	.uleb128	0

;- - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
	;; DIE #36: variable OCR0B
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
	.string		"OCR0B"
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
	.long		0x800000 + 0x00 + 0x48

	.section	.debug_abbrev
	.uleb128	0
	.uleb128	0

;- - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
	;; DIE #37: variable GTCCR
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
	.string		"GTCCR"
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
	.long		0x800000 + 0x00 + 0x4C

	.section	.debug_abbrev
	.uleb128	0
	.uleb128	0

;- - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
	;; DIE #38: variable TCCR1
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
	.string		"TCCR1"
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
	.long		0x800000 + 0x00 + 0x50

	.section	.debug_abbrev
	.uleb128	0
	.uleb128	0

;- - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
	;; DIE #39: variable TCNT1
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
	.string		"TCNT1"
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
	.long		0x800000 + 0x00 + 0x4F

	.section	.debug_abbrev
	.uleb128	0
	.uleb128	0

;- - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
	;; DIE #40: variable OCR1A
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
	.string		"OCR1A"
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
	.long		0x800000 + 0x00 + 0x4E

	.section	.debug_abbrev
	.uleb128	0
	.uleb128	0

;- - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
	;; DIE #41: variable OCR1B
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
	.string		"OCR1B"
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
	.long		0x800000 + 0x00 + 0x4B

	.section	.debug_abbrev
	.uleb128	0
	.uleb128	0

;- - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
	;; DIE #42: variable OCR1C
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
	.string		"OCR1C"
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
	.long		0x800000 + 0x00 + 0x4D

	.section	.debug_abbrev
	.uleb128	0
	.uleb128	0

;- - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
	;; DIE #43: variable TIMSK
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
	.string		"TIMSK"
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
	.long		0x800000 + 0x00 + 0x59

	.section	.debug_abbrev
	.uleb128	0
	.uleb128	0

;- - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
	;; DIE #44: variable TIFR
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
	.string		"TIFR"
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
	.long		0x800000 + 0x00 + 0x58

	.section	.debug_abbrev
	.uleb128	0
	.uleb128	0

;- - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
	;; DIE #45: variable GTCCR
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
	.string		"GTCCR"
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
	.long		0x800000 + 0x00 + 0x4C

	.section	.debug_abbrev
	.uleb128	0
	.uleb128	0

;- - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
	;; DIE #46: variable DTPS
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
	.string		"DTPS"
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
	.long		0x800000 + 0x00 + 0x43

	.section	.debug_abbrev
	.uleb128	0
	.uleb128	0

;- - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
	;; DIE #47: variable DT1A
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
	.string		"DT1A"
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
	.long		0x800000 + 0x00 + 0x45

	.section	.debug_abbrev
	.uleb128	0
	.uleb128	0

;- - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
	;; DIE #48: variable DT1B
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
	.string		"DT1B"
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
	;; DIE #49: variable SREG
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
	.string		"SREG"
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
	.long		0x800000 + 0x00 + 0x5F

	.section	.debug_abbrev
	.uleb128	0
	.uleb128	0

;- - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
	;; DIE #50: variable PRR
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
	.string		"PRR"
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
	.long		0x800000 + 0x00 + 0x40

	.section	.debug_abbrev
	.uleb128	0
	.uleb128	0

;- - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
	;; DIE #51: variable SP
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
	.string		"SP"
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
	;; DIE #52: variable MCUCR
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
	.string		"MCUCR"
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
	.long		0x800000 + 0x00 + 0x55

	.section	.debug_abbrev
	.uleb128	0
	.uleb128	0

;- - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
	;; DIE #53: variable MCUSR
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
	.string		"MCUSR"
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
	.long		0x800000 + 0x00 + 0x54

	.section	.debug_abbrev
	.uleb128	0
	.uleb128	0

;- - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
	;; DIE #54: variable OSCCAL
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
	.string		"OSCCAL"
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
	.long		0x800000 + 0x00 + 0x51

	.section	.debug_abbrev
	.uleb128	0
	.uleb128	0

;- - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
	;; DIE #55: variable CLKPR
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
	.string		"CLKPR"
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
	.long		0x800000 + 0x00 + 0x46

	.section	.debug_abbrev
	.uleb128	0
	.uleb128	0

;- - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
	;; DIE #56: variable PLLCSR
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
	.string		"PLLCSR"
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
	.long		0x800000 + 0x00 + 0x47

	.section	.debug_abbrev
	.uleb128	0
	.uleb128	0

;- - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
	;; DIE #57: variable DWDR
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
	.string		"DWDR"
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
	.long		0x800000 + 0x00 + 0x42

	.section	.debug_abbrev
	.uleb128	0
	.uleb128	0

;- - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
	;; DIE #58: variable GPIOR2
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
	.string		"GPIOR2"
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
	.long		0x800000 + 0x00 + 0x33

	.section	.debug_abbrev
	.uleb128	0
	.uleb128	0

;- - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
	;; DIE #59: variable GPIOR1
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
	.string		"GPIOR1"
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
	.long		0x800000 + 0x00 + 0x32

	.section	.debug_abbrev
	.uleb128	0
	.uleb128	0

;- - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
	;; DIE #60: variable GPIOR0
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
	.string		"GPIOR0"
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
	.long		0x800000 + 0x00 + 0x31

	.section	.debug_abbrev
	.uleb128	0
	.uleb128	0

;- - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
	;; DIE #61: variable SPMCSR
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
	.string		"SPMCSR"
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
	.long		0x800000 + 0x00 + 0x57

	.section	.debug_abbrev
	.uleb128	0
	.uleb128	0

	;; trailer
	.section	.debug_abbrev
	.uleb128	0

	.section	.debug_info
	.uleb128	0
.Leinfo:
