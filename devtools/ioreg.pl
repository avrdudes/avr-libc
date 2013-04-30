#!/usr/bin/perl

#- - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
# Converter from Atmels Device XML-Files via stylesheet to dwarf-2(!)
# debug information. This debug information is device specific added
# to the gcrt1-file
#
# Created by Knut Schwichtenberg
# DWARF-2 templates by Joerg Wunsch
#
# $Id$


# ----------------------------------------------------------------------------
# "THE BEER-WARE LICENSE" (Revision 42):
# Knut Schwichtenberg wrote this file.  As long as you retain this notice you
# can do whatever you want with this stuff. If we meet some day, and you think
# this stuff is worth it, you can buy me a beer in return.
# ----------------------------------------------------------------------------

########################################################################################
#
# Command line parameter
# -V     print version and exit
# -v     be verbose
# -x     path to saxon9
# -o     output file
#
# Return values:
#  0  Okay
#  1

#- - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
# Perl modules to be required
use strict;
use warnings;
use Getopt::Std 'getopts';
my $ContentTmplate;
my $StaticContent;
my $EepromTmplate;
my $Uint32Tmplate;

my $HaveUint32t = 0;

#- - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
# Static part of the DWARF file
#
$StaticContent = <<'EOST';
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

EOST

#- - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
#
#
$Uint32Tmplate = <<'EOU32';
;- - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
	;; DIE #%No: base type uint32_t
	.section	.debug_info
.Luint32_t:
	.uleb128	%No	; ref to abbrev %No
	.section	.debug_abbrev
	.uleb128	%No
	.uleb128	DW_TAG_base_type
	.byte		DW_CHILDREN_no

	.uleb128	DW_AT_name
	.uleb128	DW_FORM_strp
	.section	.debug_str
.Luint32_t_name:
	.string		"uint32_t"
	.section	.debug_info
	.long		.Luint32_t_name

	.section	.debug_abbrev
	.uleb128	DW_AT_byte_size
	.uleb128	DW_FORM_data1
	.section	.debug_info
	.byte		4

	.section	.debug_abbrev
	.uleb128	DW_AT_encoding
	.uleb128	DW_FORM_data1
	.section	.debug_info
	.byte		DW_ATE_unsigned

	.section	.debug_abbrev
	.uleb128	0
	.uleb128	0

EOU32

#- - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
#
#
$ContentTmplate = <<'EODY';
;- - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
	;; DIE #%No: variable %Reg
	.section	.debug_info
	.uleb128	%No	; ref to abbrev %No
	.section	.debug_abbrev
	.uleb128	%No
	.uleb128	DW_TAG_variable
	.byte		DW_CHILDREN_no

	.uleb128	DW_AT_name
	.uleb128	DW_FORM_strp
	.section	.debug_str
.Lname%No:
	.string		"%Reg"
	.section	.debug_info
	.long		.Lname%No

	.section	.debug_abbrev
	.uleb128	DW_AT_decl_file
	.uleb128	DW_FORM_data1
	.section	.debug_info
	.byte		0	; no source file information

	.section	.debug_abbrev
	.uleb128	DW_AT_decl_line
	.uleb128	DW_FORM_data1
	.section	.debug_info
	.byte		0	; no source line information

	.section	.debug_abbrev
	.uleb128	DW_AT_type
	.uleb128	DW_FORM_ref4
	.section	.debug_info
	.long		.Luint%Si_t - .Lssinfo

	.section	.debug_abbrev
	.uleb128	DW_AT_external
	.uleb128	DW_FORM_flag
	.section	.debug_info
	.byte		1

	.section	.debug_abbrev
	.uleb128	DW_AT_location
	.uleb128	DW_FORM_block1
	.section	.debug_info
	.byte		5	; length of block
	.byte		DW_OP_addr
	.long		0x800000 + %Ba + %Of

	.section	.debug_abbrev
	.uleb128	0
	.uleb128	0

EODY


#- - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
#
#
$EepromTmplate = <<'EOEE';
;- - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
	;; DIE #%No1: EEPROM array base type: uint8_t
	.section	.debug_info
.Leeprom_t:
	.uleb128	%No1	; ref to abbrev %No1
	.section	.debug_abbrev
	.uleb128	%No1
	.uleb128	DW_TAG_array_type
	.byte		DW_CHILDREN_yes

	.uleb128	DW_AT_type
	.uleb128	DW_FORM_ref4
	.section	.debug_info
	.long		.Luint8_t - .Lssinfo

	.section	.debug_abbrev
	.uleb128	0
	.uleb128	0

	;; DIE #%No2: EEPROM array subtype (index type/bounds): uint16_t
	.section	.debug_info
	.uleb128	%No2	; ref to abbrev %No2
	.section	.debug_abbrev
	.uleb128	%No2
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
	.word		%Eesize - 1
	.section	.debug_abbrev
	.uleb128	0
	.uleb128	0

	.section	.debug_info
	.byte		0	; end of DIE #%No1 children

	;; DIE #%No3: EEPROM array variable (name)
	.section	.debug_info
	.uleb128	%No3	; ref to abbrev %No3
	.section	.debug_abbrev
	.uleb128	%No3
	.uleb128	DW_TAG_variable
	.byte		DW_CHILDREN_no

	.uleb128	DW_AT_name
	.uleb128	DW_FORM_strp
	.section	.debug_str
.Lname%No3:
	.string		"__eeprom"
	.section	.debug_info
	.long		.Lname%No3

	.section	.debug_abbrev
	.uleb128	DW_AT_decl_file
	.uleb128	DW_FORM_data1
	.section	.debug_info
	.byte		0	; no source file information

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
	.long		0x810000 + %Of

	.section	.debug_abbrev
	.uleb128	0
	.uleb128	0

EOEE

#- - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
# trailing part of the dwarf Info
#
my $trailer = <<'EOT';
	;; trailer
	.section	.debug_abbrev
	.uleb128	0

	.section	.debug_info
	.uleb128	0
.Leinfo:
EOT


#- - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
# All variables need have to be defined -> see  "use strict"
#
my @allRegister;
my $staticCmd;
my $OneRegister;
my @RegisterParameter;
my $DIE_No;              # Number of the Dwarf-DIE
my $DynDIE;
my ( $options, %opts ); # for the command line interpretation
my $outfile = undef;
my $XSLPath;

#- - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
# $Revision is a RCS Key-Word any other revision system will provide another key-word
my $VERSION = sprintf("%s",('$Revision: 1.0 $' =~ /(\d*\.\d*[\.\d*]*)/));

sub VERS_MESSAGE(){
    print STDERR "$0 version: $VERSION Copyright (c) by Knut Schwichtenberg\n";
    exit(0);
    die;
}

sub HELPMESSAGE(){
    print STDERR "$0 version: $VERSION Copyright (c) by Knut Schwichtenberg\n";
    print STDERR "Usage: $0\ [switches] AVR_XML_file\n";
    print STDERR "   -h This message\n";
    print STDERR "   -V Version\n";
    print STDERR "   -v Verbose\n";
    print STDERR "   -x path to saxon9\n";
    print STDERR "   -o output file otherwise STDOUT \n";
}

#- - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
# Handle the command line

#$Getopt::Std::STANDARD_HELP_VERSION=1;
$options = 'hVvx:o:';
getopts( $options, \%opts );
if( defined $opts{'h'} ){
    HELPMESSAGE();
    exit (0);
}
if( defined $opts{'V'} ){
    VERS_MESSAGE();
}
if(! @ARGV ){
    print "$0: missing file name\n";
    HELPMESSAGE();
    exit(-1);
}
if( defined $opts{'o'} ){
	$outfile = $opts{'o'}; #
	open STDOUT,">$outfile" || die "can't open $_[0]: $!\n";
}
if( defined $opts{'x'} ){
	$XSLPath = $opts{'x'}; #
} else {
    $XSLPath = "/usr/share/java/";
}

# If xsltproc is around, use it.  Otherwise, use Saxon9.
$staticCmd = "java -jar " . $XSLPath . "/saxon9.jar -xsl:findreg.xsl ";
my $dummy;
if ($dummy = `xsltproc -V`) {
    $staticCmd = "xsltproc findreg.xsl ";
    print STDERR "Using xsltproc for XSL transform\n" if $opts{'v'};
} else {
    print STDERR "Using Saxon for XSL transform\n" if $opts{'v'};
}

#- - - - - - - - - - - - - - - - - - - -
# Create the static part of the debug information
my $Filename = "ioreg_static.inc";
#$StaticContent = do{local $/; open(my $f1, '<', $Filename) or die $!; my $tmp1 = <$f1>; close $f1 or die $!; $tmp1};

#- - - - - - - - - - - - - - - - - - - -
# For each IO-register a debug-information template is used. First read the template
$Filename = "ioreg_dyn.inc";
#$ContentTmplate = do{local $/; open(my $f1, '<', $Filename) or die $!; my $tmp1 = <$f1>; close $f1 or die $!; $tmp1};

#- - - - - - - - - - - - - - - - - - - -
# Convert via java from XML via XSL into text and put into array
@allRegister = `$staticCmd $ARGV[0]`;

#- - - - - - - - - - - - - - - - - - - -
# use STDOUT as output file
#
print $StaticContent;  # Enter constants and DIE 1-3

$DIE_No = 4;    # DIEs 1-3 are used by file, uint8_t, uint16_t

#- - - - - - - - - - - - - - - - - - - -
# Handle each array element (each register) as a DIE
#
foreach $OneRegister (@allRegister) {
 chomp @RegisterParameter;
 @RegisterParameter = split /\s+/,$OneRegister; # Register, Base, Offset, Size

 print STDERR "Adding entry for $RegisterParameter[0]\n" if $opts{'v'};

 if ($RegisterParameter[0] eq "eeprom") {
  # use EEPROM template
  $DynDIE = $EepromTmplate;
  $DynDIE =~ s/%No1/$DIE_No/g;
  $DIE_No++;
  $DynDIE =~ s/%No2/$DIE_No/g;
  $DIE_No++;
  $DynDIE =~ s/%No3/$DIE_No/g;
  $DIE_No++;
  $DynDIE =~ s/%Eesize/$RegisterParameter[3]/g;
  $DynDIE =~ s/%Of/$RegisterParameter[2]/g;
 } else {
  # use IO register template

  $RegisterParameter[3] *= 8; # 1 -> uint8_t, 2 -> uint16_t, 4 -> uint32_t
  if ($RegisterParameter[3] == 32 && !$HaveUint32t) {
   $HaveUint32t = 1;
   $DynDIE = $Uint32Tmplate;
   $DynDIE =~ s/%No/$DIE_No/g;
   $DIE_No++;
   print $DynDIE;
  }

  #- - - - - - - - - - - - - - - - - - - -
  # Replace variables by register values
  #
  ($DynDIE = $ContentTmplate) =~ s/%Reg/$RegisterParameter[0]/g;
  $DynDIE =~ s/%No/$DIE_No/g;
  $DynDIE =~ s/%Si/$RegisterParameter[3]/g;
  $DynDIE =~ s/%Ba/$RegisterParameter[1]/g;
  $DynDIE =~ s/%Of/$RegisterParameter[2]/g;
  $DIE_No++;
 }
 print $DynDIE;
}
print $trailer;
close;
__END__
=head1 NAME

ioreg.pl  - Create debug information from Atmel XML files for IO-Ports and EEProm

=head1 SYNOPSIS

	perl ioreg.pl xxxxx.XML   

=head1 DESCRIPTION

Using GDB and AVaRICE to debug AVR code requires to know the addresses of
IO registers! The GDB command "x PORTA" leads to an unknown address
error. Beginning with Atmel Studio 5 well formed XML file are deliverd 
as part of the installation. This script converts these XML-files using a 
stylesheet into dwarf-2 debug information. To prevent Atmel's debugger from
crashing only dwarf-2 can be used, while GDB could use debug information
up to dwarf-4. Similar to the handling of the IO-addresses the eeprom
start address can be accessed by the label __eeprom.  Its type is an CPU 
specific array of uint8_t.

This debug information is added to the device specific start-up code of 
avr-libc and now allows debugging symbolic 
names. 
It is possible to use dwarf-4 debug information for the 
application and mix it with dwarf-2 of the start-up code.

=head1 Preconditions

This script relies on

=over 3

=item *
Atmel's AVR XML files

=item *
Stylesheet file named "findreg.xsl". It has to be located in the same directory as ioreg.pl 

=item *
XSLT processor, either xsltproc or saxon9

=back

If xsltproc is used, it must be in the PATH. Using saxon9 gives a runtime warning which can be ignored.

=head1 Command line parameters

The following command line parameters are supported

=over 5

=item h

Print the help infomation to STDERR

=item V

Print the version information to STDERR

=item v

Print verbose information to STDERR

=item x

Sets the path to saxon9. Default: /usr/share/java

=item o

Set the output file otherwise STDOUT is used 

=back

=head1 Authors

Knut Schwichtenberg / Joerg Wunsch
