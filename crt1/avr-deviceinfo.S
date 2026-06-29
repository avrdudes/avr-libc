/* Copyright (c) 2002, Marek Michalkiewicz <marekm@amelek.gda.pl>
   Copyright (c) 2007, 2008 Eric B. Weddington
   All rights reserved.

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

;;; Outsourced from gcrt1.S and included by:
;;;    crt1/gcrt1.S
;;;    libc/misc/deviceinfo.S

    .section .note.gnu.avr.deviceinfo, "", @note
#define NOTE_NAME "AVR"
#ifdef __AVR_DEVICE_NAME__
    #define DEVICE_NAME STR(__AVR_DEVICE_NAME__)
#else
    #define DEVICE_NAME ""
#endif

    .long .L__note_name_end - .L__note_name_start
    .long .L__desc_end - .L__desc_start
    .long 1 ; Type 1 - this is the only known note type for AVR.
.L__note_name_start:
    .asciz NOTE_NAME
    .balign 4
.L__note_name_end:
.L__desc_start:
#ifdef FLASHSTART
    .long FLASHSTART
#else
    .long 0
#endif
#ifdef PROGMEM_SIZE
    .long PROGMEM_SIZE
#elif FLASHEND > 0
    .long FLASHEND + 1
#else
    .long 0
#endif
    .long RAMSTART
#ifdef RAMSIZE
    .long RAMSIZE
#elif RAMEND > RAMSTART
    .long RAMEND - RAMSTART + 1
#else
    .long 0
#endif
#ifdef E2START
    .long E2START
#else
    .long 0
#endif
#ifdef EEPROM_SIZE
    .long EEPROM_SIZE
#elif E2END > 0
    .long E2END + 1
#else
    .long 0
#endif
    ;; String offsets table.
.L__stroffsettab_start:
    ;; Index 0: Size of index table in bytes.
    .long .L__stroffsettab_end - .L__stroffsettab_start
    ;; Index 1: Byte offset of device name.
    .long .L__device_name_start - .L__strtab_start
.L__stroffsettab_end:

    ;; String table for storing arbitrary strings.
    ;; Offsets are stored in the string offset table above.
.L__strtab_start:
    .byte 0
.L__device_name_start:
    .asciz DEVICE_NAME
.L__device_name_end:
    .byte 0
.L__strtab_end:
.L__desc_end:
    .balign 4


/* Set REGION_LENGTH symbol values for well known memory regions.
   The default linker script uses these symbols to set MEMORY
   region lengths, and by defining these here the linker can detect
   memory overflows accurately on a per device basis, since the
   values are picked up from the device header file.  */

#if defined (FLASHEND)
#if ! defined FLASHSTART
#define FLASHSTART 0
#endif
    ;; Some of the Automotive devices have Flash start at 0x8000,
    ;; but MEMORY region text starts at __TEXT_REGION_ORIGIN__ only
    ;; since Binutils PR31177 (v2.42 released 2024).  Older versions
    ;; of Binutils have text region start hard coded as 0x0.
    ;; Therefore, only provide strict text region layout for devices
    ;; where program memory starts at 0x0.
#if FLASHSTART == 0 || defined (HAVE_LDSCRIPT_PR31177)
    .weak __TEXT_REGION_ORIGIN__
    .set  __TEXT_REGION_ORIGIN__, (FLASHSTART)
    .weak __TEXT_REGION_LENGTH__
    .set  __TEXT_REGION_LENGTH__, 1 + (FLASHEND) - (FLASHSTART)
#endif /* FLASHSTART == 0 */
#endif /* FLASHEND */

;; The RAM virtual memory address used by Binutils to linearize memory.
#define RAM_VMA 0x800000

;; __DATA_REGION_ORIGIN__ is used since ld v2.40 / 2023-01-14 / PR29741.
;; Prior to that, a core specific default value $DATA_ORIGIN was used.
;; __DATA_REGION_LENGTH__ however is in use since 2015 / cb0728165e282b
;; which means that with Binutils older than v2.40 we may get a
;;    ld: address <X> of <FILE> section `.data' is not within region `data'
;; error from the linker when $DATA_ORIGIN is not __DATA_REGION_ORIGIN__.
#if defined (RAMSTART) && defined (RAMEND) && defined (HAVE_LDSCRIPT_PR29741)
    .weak __DATA_REGION_ORIGIN__
    .set  __DATA_REGION_ORIGIN__, (RAM_VMA) | (RAMSTART)
    .weak __DATA_REGION_LENGTH__
#if RAMEND > RAMSTART
    .set  __DATA_REGION_LENGTH__, 1 + (RAMEND) - (RAMSTART)
#else
    .set  __DATA_REGION_LENGTH__, 0
#endif
#endif /* have RAMSTART and RAMEND */

/* The VMA ORIGINs of other MEMORY regions are hard-coded in the ld scripts:
   eeprom:          0x810000
   fuse:            0x820000
   lock:            0x830000
   signature:       0x840000
   user_signatures: 0x850000
   rodata:          0xa00000  (only for the AVR64 and AVR128 devices)  */

#if defined (EEPROM_SIZE) && (EEPROM_SIZE) > 0
    .weak __EEPROM_REGION_LENGTH__
    .set  __EEPROM_REGION_LENGTH__, EEPROM_SIZE
#elif defined (E2END) && (E2END) > 0
    .weak __EEPROM_REGION_LENGTH__
    .set  __EEPROM_REGION_LENGTH__, 1 + (E2END)
#endif /* E2END > 0 */

#if defined (FUSES_SIZE) && (FUSES_SIZE) > 0
    .weak __FUSE_REGION_LENGTH__
    .set  __FUSE_REGION_LENGTH__, FUSES_SIZE
#elif defined (FUSE_MEMORY_SIZE) && (FUSE_MEMORY_SIZE) > 0
    .weak __FUSE_REGION_LENGTH__
    .set  __FUSE_REGION_LENGTH__, FUSE_MEMORY_SIZE
#endif

#if defined (LOCKBITS_SIZE) && (LOCKBITS_SIZE) > 0
    .weak __LOCK_REGION_LENGTH__
    .set  __LOCK_REGION_LENGTH__, LOCKBITS_SIZE
#endif

#if defined (USER_SIGNATURES_SIZE) && (USER_SIGNATURES_SIZE) > 0
    .weak __USER_SIGNATURE_REGION_LENGTH__
    .set  __USER_SIGNATURE_REGION_LENGTH__, USER_SIGNATURES_SIZE
#endif

#if defined (SIGNATURES_SIZE) && (SIGNATURES_SIZE) > 0
    .weak __SIGNATURE_REGION_LENGTH__
    .set  __SIGNATURE_REGION_LENGTH__, SIGNATURES_SIZE
#endif
