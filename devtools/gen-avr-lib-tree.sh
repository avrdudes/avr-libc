#! /bin/sh
#
# Copyright (c) 2004,  Theodore A. Roth
# Copyright (c) 2005,2006,2007,2008,2009  Anatoly Sokolov
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
#
# $Id$
#

# This is a script to automate the generation of the avr/lib/ tree. Since
# there is a build directory for each device and each of those directories is
# virtually the same, it is easier to maintain a single file instead of an
# ever growing number of small Makefile.am fragments.

# Make sure that we are the top-level of the source tree. We will look for the
# the AUTHORS file in the current dir and the parent. After that, we complain
# and fatal error out.

# Define the special flags for special sub-targets.

PATH=/usr/xpg4/bin:$PATH

CFLAGS_SPACE="-mcall-prologues -Os"
CFLAGS_TINY_STACK="-msp8 -mcall-prologues -Os"
CFLAGS_BIG_MEMORY='-Os $(FNO_JUMP_TABLES)'
CFLAGS_SPEED="-Os"

ASFLAGS_SPEED="-DOPTIMIZE_SPEED"

AVR12_DEV_INFO="\
at90s1200:crts1200.o:${DEV_DEFS}:${CFLAGS_SPACE}:${DEV_ASFLAGS};\
attiny11:crttn11.o:${DEV_DEFS}:${CFLAGS_SPACE}:${DEV_ASFLAGS};\
attiny12:crttn12.o:${DEV_DEFS}:${CFLAGS_SPACE}:${DEV_ASFLAGS};\
attiny15:crttn15.o:${DEV_DEFS}:${CFLAGS_SPACE}:${DEV_ASFLAGS};\
attiny28:crttn28.o:${DEV_DEFS}:${CFLAGS_SPACE}:${DEV_ASFLAGS};\
at90s4414:crts4414.o:${DEV_DEFS}:${CFLAGS_SPACE}:${DEV_ASFLAGS};\
at90s4434:crts4434.o:${DEV_DEFS}:${CFLAGS_SPACE}:${DEV_ASFLAGS};\
at90s8515:crts8515.o:${DEV_DEFS}:${CFLAGS_SPACE}:${DEV_ASFLAGS};\
at90s8535:crts8535.o:${DEV_DEFS}:${CFLAGS_SPACE}:${DEV_ASFLAGS};\
at90c8534:crtc8534.o:${DEV_DEFS}:${CFLAGS_SPACE}:${DEV_ASFLAGS}\
"

AVR12TS_DEV_INFO="\
at90s2313:crts2313.o:${DEV_DEFS}:${CFLAGS_TINY_STACK}:${DEV_ASFLAGS};\
at90s2323:crts2323.o:${DEV_DEFS}:${CFLAGS_TINY_STACK}:${DEV_ASFLAGS};\
at90s2333:crts2333.o:${DEV_DEFS}:${CFLAGS_TINY_STACK}:${DEV_ASFLAGS};\
at90s2343:crts2343.o:${DEV_DEFS}:${CFLAGS_TINY_STACK}:${DEV_ASFLAGS};\
at90s4433:crts4433.o:${DEV_DEFS}:${CFLAGS_TINY_STACK}:${DEV_ASFLAGS};\
attiny22:crttn22.o:${DEV_DEFS}:${CFLAGS_TINY_STACK}:${DEV_ASFLAGS};\
attiny26:crttn26.o:${DEV_DEFS}:${CFLAGS_TINY_STACK}:${DEV_ASFLAGS}\
"

AVR25_DEV_INFO="\
at86rf401:crt86401.o:${DEV_DEFS}:${CFLAGS_SPACE}:${DEV_ASFLAGS};\
ata5272:crta5272.o:${DEV_DEFS}:${CFLAGS_SPACE}:${DEV_ASFLAGS};\
attiny4313:crttn4313.o:${DEV_DEFS}:${CFLAGS_SPACE}:${DEV_ASFLAGS};\
attiny43u:crttn43u.o:${DEV_DEFS}:${CFLAGS_SPACE}:${DEV_ASFLAGS};\
attiny44:crttn44.o:${DEV_DEFS}:${CFLAGS_SPACE}:${DEV_ASFLAGS};\
attiny44a:crttn44a.o:${DEV_DEFS}:${CFLAGS_SPACE}:${DEV_ASFLAGS};\
attiny45:crttn45.o:${DEV_DEFS}:${CFLAGS_SPACE}:${DEV_ASFLAGS};\
attiny461:crttn461.o:${DEV_DEFS}:${CFLAGS_SPACE}:${DEV_ASFLAGS};\
attiny461a:crttn461a.o:${DEV_DEFS}:${CFLAGS_SPACE}:${DEV_ASFLAGS};\
attiny48:crttn48.o:${DEV_DEFS}:${CFLAGS_SPACE}:${DEV_ASFLAGS};\
attiny828:crttn828.o:${DEV_DEFS}:${CFLAGS_SPACE}:${DEV_ASFLAGS};\
attiny84:crttn84.o:${DEV_DEFS}:${CFLAGS_SPACE}:${DEV_ASFLAGS};\
attiny84a:crttn84a.o:${DEV_DEFS}:${CFLAGS_SPACE}:${DEV_ASFLAGS};\
attiny85:crttn85.o:${DEV_DEFS}:${CFLAGS_SPACE}:${DEV_ASFLAGS};\
attiny861:crttn861.o:${DEV_DEFS}:${CFLAGS_SPACE}:${DEV_ASFLAGS};\
attiny861a:crttn861a.o:${DEV_DEFS}:${CFLAGS_SPACE}:${DEV_ASFLAGS};\
attiny87:crttn87.o:${DEV_DEFS}:${CFLAGS_SPACE}:${DEV_ASFLAGS};\
attiny88:crttn88.o:${DEV_DEFS}:${CFLAGS_SPACE}:${DEV_ASFLAGS}\
"

AVR25TS_DEV_INFO="\
attiny13:crttn13.o:${DEV_DEFS}:${CFLAGS_TINY_STACK}:${DEV_ASFLAGS};\
attiny13a:crttn13a.o:${DEV_DEFS}:${CFLAGS_TINY_STACK}:${DEV_ASFLAGS};\
attiny2313:crttn2313.o:${DEV_DEFS}:${CFLAGS_TINY_STACK}:${DEV_ASFLAGS};\
attiny2313a:crttn2313a.o:${DEV_DEFS}:${CFLAGS_TINY_STACK}:${DEV_ASFLAGS};\
attiny24:crttn24.o:${DEV_DEFS}:${CFLAGS_TINY_STACK}:${DEV_ASFLAGS};\
attiny24a:crttn24a.o:${DEV_DEFS}:${CFLAGS_TINY_STACK}:${DEV_ASFLAGS};\
attiny25:crttn25.o:${DEV_DEFS}:${CFLAGS_TINY_STACK}:${DEV_ASFLAGS};\
attiny261:crttn261.o:${DEV_DEFS}:${CFLAGS_TINY_STACK}:${DEV_ASFLAGS};\
attiny261a:crttn261a.o:${DEV_DEFS}:${CFLAGS_TINY_STACK}:${DEV_ASFLAGS}\
"

AVR3_DEV_INFO="\
at43usb355:crt43355.o:${DEV_DEFS}:${CFLAGS_SPACE}:${DEV_ASFLAGS};\
at76c711:crt76711.o:${DEV_DEFS}:${CFLAGS_SPACE}:${DEV_ASFLAGS}\
"

AVR31_DEV_INFO="\
atmega103:crtm103.o:${DEV_DEFS}:${CFLAGS_SPACE}:${DEV_ASFLAGS};\
at43usb320:crt43320.o:${DEV_DEFS}:${CFLAGS_SPACE}:${DEV_ASFLAGS}\
"

AVR35_DEV_INFO="\
at90usb82:crtusb82.o:${DEV_DEFS}:${CFLAGS_SPACE}:${DEV_ASFLAGS};\
at90usb162:crtusb162.o:${DEV_DEFS}:${CFLAGS_SPACE}:${DEV_ASFLAGS};\
ata5505:crta5505.o:${DEV_DEFS}:${CFLAGS_SPACE}:${DEV_ASFLAGS};\
atmega8u2:crtm8u2.o:${DEV_DEFS}:${CFLAGS_SPACE}:${DEV_ASFLAGS};\
atmega16u2:crtm16u2.o:${DEV_DEFS}:${CFLAGS_SPACE}:${DEV_ASFLAGS};\
atmega32u2:crtm32u2.o:${DEV_DEFS}:${CFLAGS_SPACE}:${DEV_ASFLAGS};\
attiny167:crttn167.o:${DEV_DEFS}:${CFLAGS_SPACE}:${DEV_ASFLAGS};\
attiny1634:crttn1634.o:${DEV_DEFS}:${CFLAGS_SPACE}:${DEV_ASFLAGS}\
"

AVR4_DEV_INFO="\
ata6285:crta6285.o:${DEV_DEFS}:${CFLAGS_SPACE}:${DEV_ASFLAGS};\
ata6286:crta6286.o:${DEV_DEFS}:${CFLAGS_SPACE}:${DEV_ASFLAGS};\
ata6289:crta6289.o:${DEV_DEFS}:${CFLAGS_SPACE}:${DEV_ASFLAGS};\
atmega48:crtm48.o:${DEV_DEFS}:${CFLAGS_SPACE}:${DEV_ASFLAGS};\
atmega48a:crtm48a.o:${DEV_DEFS}:${CFLAGS_SPACE}:${DEV_ASFLAGS};\
atmega48pa:crtm48pa.o:${DEV_DEFS}:${CFLAGS_SPACE}:${DEV_ASFLAGS};\
atmega48p:crtm48p.o:${DEV_DEFS}:${CFLAGS_SPACE}:${DEV_ASFLAGS};\
atmega8:crtm8.o:${DEV_DEFS}:${CFLAGS_SPACE}:${DEV_ASFLAGS};\
atmega8a:crtm8a.o:${DEV_DEFS}:${CFLAGS_SPACE}:${DEV_ASFLAGS};\
atmega88:crtm88.o:${DEV_DEFS}:${CFLAGS_SPACE}:${DEV_ASFLAGS};\
atmega88a:crtm88a.o:${DEV_DEFS}:${CFLAGS_SPACE}:${DEV_ASFLAGS};\
atmega88p:crtm88p.o:${DEV_DEFS}:${CFLAGS_SPACE}:${DEV_ASFLAGS};\
atmega88pa:crtm88pa.o:${DEV_DEFS}:${CFLAGS_SPACE}:${DEV_ASFLAGS};\
atmega8515:crtm8515.o:${DEV_DEFS}:${CFLAGS_SPACE}:${DEV_ASFLAGS};\
atmega8535:crtm8535.o:${DEV_DEFS}:${CFLAGS_SPACE}:${DEV_ASFLAGS};\
atmega8hva:crtm8hva.o:${DEV_DEFS}:${CFLAGS_SPACE}:${DEV_ASFLAGS};\
at90pwm1:crt90pwm1.o:${DEV_DEFS}:${CFLAGS_SPACE}:${DEV_ASFLAGS};\
at90pwm2:crt90pwm2.o:${DEV_DEFS}:${CFLAGS_SPACE}:${DEV_ASFLAGS};\
at90pwm2b:crt90pwm2b.o:${DEV_DEFS}:${CFLAGS_SPACE}:${DEV_ASFLAGS};\
at90pwm3:crt90pwm3.o:${DEV_DEFS}:${CFLAGS_SPACE}:${DEV_ASFLAGS};\
at90pwm3b:crt90pwm3b.o:${DEV_DEFS}:${CFLAGS_SPACE}:${DEV_ASFLAGS};\
at90pwm81:crt90pwm81.o:${DEV_DEFS}:${CFLAGS_SPACE}:${DEV_ASFLAGS}\
"

AVR5_DEV_INFO="\
at90can32:crtcan32.o:${DEV_DEFS}:${CFLAGS_SPACE}:${DEV_ASFLAGS};\
at90can64:crtcan64.o:${DEV_DEFS}:${CFLAGS_SPACE}:${DEV_ASFLAGS};\
at90pwm216:crt90pwm216.o:${DEV_DEFS}:${CFLAGS_SPACE}:${DEV_ASFLAGS};\
at90pwm316:crt90pwm316.o:${DEV_DEFS}:${CFLAGS_SPACE}:${DEV_ASFLAGS};\
at90pwm161:crt90pwm161.o:${DEV_DEFS}:${CFLAGS_SPACE}:${DEV_ASFLAGS};\
at90scr100:crt90scr100.o:${DEV_DEFS}:${CFLAGS_SPACE}:${DEV_ASFLAGS};\
at90usb646:crtusb646.o:${DEV_DEFS}:${CFLAGS_SPACE}:${DEV_ASFLAGS};\
at90usb647:crtusb647.o:${DEV_DEFS}:${CFLAGS_SPACE}:${DEV_ASFLAGS};\
at94k:crtat94k.o:${DEV_DEFS}:${CFLAGS_SPACE}:${DEV_ASFLAGS};\
ata5790:crta5790.o:${DEV_DEFS}:${CFLAGS_SPACE}:${DEV_ASFLAGS};\
ata5795:crta5795.o:${DEV_DEFS}:${CFLAGS_SPACE}:${DEV_ASFLAGS};\
atmega16:crtm16.o:${DEV_DEFS}:${CFLAGS_SPACE}:${DEV_ASFLAGS};\
atmega16a:crtm16a.o:${DEV_DEFS}:${CFLAGS_SPACE}:${DEV_ASFLAGS};\
atmega161:crtm161.o:${DEV_DEFS}:${CFLAGS_SPACE}:${DEV_ASFLAGS};\
atmega162:crtm162.o:${DEV_DEFS}:${CFLAGS_SPACE}:${DEV_ASFLAGS};\
atmega163:crtm163.o:${DEV_DEFS}:${CFLAGS_SPACE}:${DEV_ASFLAGS};\
atmega164a:crtm164a.o:${DEV_DEFS}:${CFLAGS_SPACE}:${DEV_ASFLAGS};\
atmega164p:crtm164p.o:${DEV_DEFS}:${CFLAGS_SPACE}:${DEV_ASFLAGS};\
atmega164pa:crtm164pa.o:${DEV_DEFS}:${CFLAGS_SPACE}:${DEV_ASFLAGS};\
atmega165:crtm165.o:${DEV_DEFS}:${CFLAGS_SPACE}:${DEV_ASFLAGS};\
atmega165a:crtm165a.o:${DEV_DEFS}:${CFLAGS_SPACE}:${DEV_ASFLAGS};\
atmega165p:crtm165p.o:${DEV_DEFS}:${CFLAGS_SPACE}:${DEV_ASFLAGS};\
atmega165pa:crtm165pa.o:${DEV_DEFS}:${CFLAGS_SPACE}:${DEV_ASFLAGS};\
atmega168:crtm168.o:${DEV_DEFS}:${CFLAGS_SPACE}:${DEV_ASFLAGS};\
atmega168a:crtm168a.o:${DEV_DEFS}:${CFLAGS_SPACE}:${DEV_ASFLAGS};\
atmega168p:crtm168p.o:${DEV_DEFS}:${CFLAGS_SPACE}:${DEV_ASFLAGS};\
atmega168pa:crtm168pa.o:${DEV_DEFS}:${CFLAGS_SPACE}:${DEV_ASFLAGS};\
atmega169:crtm169.o:${DEV_DEFS}:${CFLAGS_SPACE}:${DEV_ASFLAGS};\
atmega169a:crtm169a.o:${DEV_DEFS}:${CFLAGS_SPACE}:${DEV_ASFLAGS};\
atmega169p:crtm169p.o:${DEV_DEFS}:${CFLAGS_SPACE}:${DEV_ASFLAGS};\
atmega169pa:crtm169pa.o:${DEV_DEFS}:${CFLAGS_SPACE}:${DEV_ASFLAGS};\
atmega16hva:crtm16hva.o:${DEV_DEFS}:${CFLAGS_SPACE}:${DEV_ASFLAGS};\
atmega16hva2:crtm16hva2.o:${DEV_DEFS}:${CFLAGS_SPACE}:${DEV_ASFLAGS};\
atmega16hvb:crtm16hvb.o:${DEV_DEFS}:${CFLAGS_SPACE}:${DEV_ASFLAGS};\
atmega16hvbrevb:crtm16hvbrevb.o:${DEV_DEFS}:${CFLAGS_SPACE}:${DEV_ASFLAGS};\
atmega16m1:crtm16m1.o:${DEV_DEFS}:${CFLAGS_SPACE}:${DEV_ASFLAGS};\
atmega16u4:crtm16u4.o:${DEV_DEFS}:${CFLAGS_SPACE}:${DEV_ASFLAGS};\
atmega32:crtm32.o:${DEV_DEFS}:${CFLAGS_SPACE}:${DEV_ASFLAGS};\
atmega32a:crtm32a.o:${DEV_DEFS}:${CFLAGS_SPACE}:${DEV_ASFLAGS};\
atmega323:crtm323.o:${DEV_DEFS}:${CFLAGS_SPACE}:${DEV_ASFLAGS};\
atmega324a:crtm324a.o:${DEV_DEFS}:${CFLAGS_SPACE}:${DEV_ASFLAGS};\
atmega324p:crtm324p.o:${DEV_DEFS}:${CFLAGS_SPACE}:${DEV_ASFLAGS};\
atmega324pa:crtm324pa.o:${DEV_DEFS}:${CFLAGS_SPACE}:${DEV_ASFLAGS};\
atmega325:crtm325.o:${DEV_DEFS}:${CFLAGS_SPACE}:${DEV_ASFLAGS};\
atmega325a:crtm325a.o:${DEV_DEFS}:${CFLAGS_SPACE}:${DEV_ASFLAGS};\
atmega325p:crtm325p.o:${DEV_DEFS}:${CFLAGS_SPACE}:${DEV_ASFLAGS};\
atmega325pa:crtm325pa.o:${DEV_DEFS}:${CFLAGS_SPACE}:${DEV_ASFLAGS};\
atmega3250:crtm3250.o:${DEV_DEFS}:${CFLAGS_SPACE}:${DEV_ASFLAGS};\
atmega3250a:crtm3250a.o:${DEV_DEFS}:${CFLAGS_SPACE}:${DEV_ASFLAGS};\
atmega3250p:crtm3250p.o:${DEV_DEFS}:${CFLAGS_SPACE}:${DEV_ASFLAGS};\
atmega3250pa:crtm3250pa.o:${DEV_DEFS}:${CFLAGS_SPACE}:${DEV_ASFLAGS};\
atmega328:crtm328.o:${DEV_DEFS}:${CFLAGS_SPACE}:${DEV_ASFLAGS};\
atmega328p:crtm328p.o:${DEV_DEFS}:${CFLAGS_SPACE}:${DEV_ASFLAGS};\
atmega329:crtm329.o:${DEV_DEFS}:${CFLAGS_SPACE}:${DEV_ASFLAGS};\
atmega329a:crtm329a.o:${DEV_DEFS}:${CFLAGS_SPACE}:${DEV_ASFLAGS};\
atmega329p:crtm329p.o:${DEV_DEFS}:${CFLAGS_SPACE}:${DEV_ASFLAGS};\
atmega329pa:crtm329pa.o:${DEV_DEFS}:${CFLAGS_SPACE}:${DEV_ASFLAGS};\
atmega3290:crtm3290.o:${DEV_DEFS}:${CFLAGS_SPACE}:${DEV_ASFLAGS};\
atmega3290a:crtm3290a.o:${DEV_DEFS}:${CFLAGS_SPACE}:${DEV_ASFLAGS};\
atmega3290p:crtm3290p.o:${DEV_DEFS}:${CFLAGS_SPACE}:${DEV_ASFLAGS};\
atmega3290pa:crtm3290pa.o:${DEV_DEFS}:${CFLAGS_SPACE}:${DEV_ASFLAGS};\
atmega32c1:crtm32c1.o:${DEV_DEFS}:${CFLAGS_SPACE}:${DEV_ASFLAGS};\
atmega32hvb:crtm32hvb.o:${DEV_DEFS}:${CFLAGS_SPACE}:${DEV_ASFLAGS};\
atmega32hvbrevb:crtm32hvbrevb.o:${DEV_DEFS}:${CFLAGS_SPACE}:${DEV_ASFLAGS};\
atmega32m1:crtm32m1.o:${DEV_DEFS}:${CFLAGS_SPACE}:${DEV_ASFLAGS};\
atmega32u4:crtm32u4.o:${DEV_DEFS}:${CFLAGS_SPACE}:${DEV_ASFLAGS};\
atmega32u6:crtm32u6.o:${DEV_DEFS}:${CFLAGS_SPACE}:${DEV_ASFLAGS};\
atmega406:crtm406.o:${DEV_DEFS}:${CFLAGS_SPACE}:${DEV_ASFLAGS};\
atmega644rfr2:crtm644rfr2.o:${DEV_DEFS}:${CFLAGS_SPACE}:${DEV_ASFLAGS};\
atmega64rfr2:crtm64rfr2.o:${DEV_DEFS}:${CFLAGS_SPACE}:${DEV_ASFLAGS};\
atmega64:crtm64.o:${DEV_DEFS}:${CFLAGS_SPACE}:${DEV_ASFLAGS};\
atmega64a:crtm64a.o:${DEV_DEFS}:${CFLAGS_SPACE}:${DEV_ASFLAGS};\
atmega640:crtm640.o:${DEV_DEFS}:${CFLAGS_SPACE}:${DEV_ASFLAGS};\
atmega644:crtm644.o:${DEV_DEFS}:${CFLAGS_SPACE}:${DEV_ASFLAGS};\
atmega644a:crtm644a.o:${DEV_DEFS}:${CFLAGS_SPACE}:${DEV_ASFLAGS};\
atmega644p:crtm644p.o:${DEV_DEFS}:${CFLAGS_SPACE}:${DEV_ASFLAGS};\
atmega644pa:crtm644pa.o:${DEV_DEFS}:${CFLAGS_SPACE}:${DEV_ASFLAGS};\
atmega645:crtm645.o:${DEV_DEFS}:${CFLAGS_SPACE}:${DEV_ASFLAGS};\
atmega645a:crtm645a.o:${DEV_DEFS}:${CFLAGS_SPACE}:${DEV_ASFLAGS};\
atmega645p:crtm645p.o:${DEV_DEFS}:${CFLAGS_SPACE}:${DEV_ASFLAGS};\
atmega6450:crtm6450.o:${DEV_DEFS}:${CFLAGS_SPACE}:${DEV_ASFLAGS};\
atmega6450a:crtm6450a.o:${DEV_DEFS}:${CFLAGS_SPACE}:${DEV_ASFLAGS};\
atmega6450p:crtm6450p.o:${DEV_DEFS}:${CFLAGS_SPACE}:${DEV_ASFLAGS};\
atmega649:crtm649.o:${DEV_DEFS}:${CFLAGS_SPACE}:${DEV_ASFLAGS};\
atmega649a:crtm649a.o:${DEV_DEFS}:${CFLAGS_SPACE}:${DEV_ASFLAGS};\
atmega649p:crtm649p.o:${DEV_DEFS}:${CFLAGS_SPACE}:${DEV_ASFLAGS};\
atmega6490:crtm6490.o:${DEV_DEFS}:${CFLAGS_SPACE}:${DEV_ASFLAGS};\
atmega6490a:crtm6490a.o:${DEV_DEFS}:${CFLAGS_SPACE}:${DEV_ASFLAGS};\
atmega6490p:crtm6490p.o:${DEV_DEFS}:${CFLAGS_SPACE}:${DEV_ASFLAGS};\
atmega64c1:crtm64c1.o:${DEV_DEFS}:${CFLAGS_SPACE}:${DEV_ASFLAGS};\
atmega64hve:crtm64hve.o:${DEV_DEFS}:${CFLAGS_SPACE}:${DEV_ASFLAGS};\
atmega64m1:crtm64m1.o:${DEV_DEFS}:${CFLAGS_SPACE}:${DEV_ASFLAGS};\
m3000:crtm3000.o:${DEV_DEFS}:${CFLAGS_SPACE}:${DEV_ASFLAGS}\
"

AVR51_DEV_INFO="\
atmega128:crtm128.o:${DEV_DEFS}:${CFLAGS_BIG_MEMORY}:${DEV_ASFLAGS};\
atmega128a:crtm128a.o:${DEV_DEFS}:${CFLAGS_BIG_MEMORY}:${DEV_ASFLAGS};\
atmega1280:crtm1280.o:${DEV_DEFS}:${CFLAGS_BIG_MEMORY}:${DEV_ASFLAGS};\
atmega1281:crtm1281.o:${DEV_DEFS}:${CFLAGS_BIG_MEMORY}:${DEV_ASFLAGS};\
atmega1284:crtm1284.o:${DEV_DEFS}:${CFLAGS_BIG_MEMORY}:${DEV_ASFLAGS};\
atmega1284p:crtm1284p.o:${DEV_DEFS}:${CFLAGS_BIG_MEMORY}:${DEV_ASFLAGS};\
atmega128rfa1:crtm128rfa1.o:${DEV_DEFS}:${CFLAGS_BIG_MEMORY}:${DEV_ASFLAGS};\
atmega1284rfr2:crtm1284rfr2.o:${DEV_DEFS}:${CFLAGS_SPACE}:${DEV_ASFLAGS};\
atmega128rfr2:crtm128rfr2.o:${DEV_DEFS}:${CFLAGS_SPACE}:${DEV_ASFLAGS};\
at90can128:crtcan128.o:${DEV_DEFS}:${CFLAGS_BIG_MEMORY}:${DEV_ASFLAGS};\
at90usb1286:crtusb1286.o:${DEV_DEFS}:${CFLAGS_BIG_MEMORY}:${DEV_ASFLAGS};\
at90usb1287:crtusb1287.o:${DEV_DEFS}:${CFLAGS_BIG_MEMORY}:${DEV_ASFLAGS}\
"

AVR6_DEV_INFO="\
atmega2560:crtm2560.o:${DEV_DEFS}:${CFLAGS_BIG_MEMORY}:${DEV_ASFLAGS};\
atmega2561:crtm2561.o:${DEV_DEFS}:${CFLAGS_BIG_MEMORY}:${DEV_ASFLAGS};\
atmega2564rfr2:crtm2564rfr2.o:${DEV_DEFS}:${CFLAGS_SPACE}:${DEV_ASFLAGS};\
atmega256rfr2:crtm256rfr2.o:${DEV_DEFS}:${CFLAGS_SPACE}:${DEV_ASFLAGS}\
"

AVRXMEGA2_DEV_INFO="\
atxmega16a4:crtx16a4.o:${DEV_DEFS}:${CFLAGS_SPACE}:${DEV_ASFLAGS};\
atxmega16a4u:crtx16a4u.o:${DEV_DEFS}:${CFLAGS_SPACE}:${DEV_ASFLAGS};\
atxmega16c4:crtx16c4.o:${DEV_DEFS}:${CFLAGS_SPACE}:${DEV_ASFLAGS};\
atxmega16d4:crtx16d4.o:${DEV_DEFS}:${CFLAGS_SPACE}:${DEV_ASFLAGS};\
atxmega32a4:crtx32a4.o:${DEV_DEFS}:${CFLAGS_SPACE}:${DEV_ASFLAGS};\
atxmega32a4u:crtx32a4u.o:${DEV_DEFS}:${CFLAGS_SPACE}:${DEV_ASFLAGS};\
atxmega32c4:crtx32c4.o:${DEV_DEFS}:${CFLAGS_SPACE}:${DEV_ASFLAGS};\
atxmega32d4:crtx32d4.o:${DEV_DEFS}:${CFLAGS_SPACE}:${DEV_ASFLAGS}\
"

AVRXMEGA4_DEV_INFO="\
atxmega64a3:crtx64a3.o:${DEV_DEFS}:${CFLAGS_BIG_MEMORY}:${DEV_ASFLAGS};\
atxmega64a3u:crtx64a3u.o:${DEV_DEFS}:${CFLAGS_BIG_MEMORY}:${DEV_ASFLAGS};\
atxmega64a4u:crtx64a4u.o:${DEV_DEFS}:${CFLAGS_BIG_MEMORY}:${DEV_ASFLAGS};\
atxmega64b1:crtx64b1.o:${DEV_DEFS}:${CFLAGS_BIG_MEMORY}:${DEV_ASFLAGS};\
atxmega64b3:crtx64b3.o:${DEV_DEFS}:${CFLAGS_BIG_MEMORY}:${DEV_ASFLAGS};\
atxmega64c3:crtx64c3.o:${DEV_DEFS}:${CFLAGS_BIG_MEMORY}:${DEV_ASFLAGS};\
atxmega64d3:crtx64d3.o:${DEV_DEFS}:${CFLAGS_BIG_MEMORY}:${DEV_ASFLAGS};\
atxmega64d4:crtx64d4.o:${DEV_DEFS}:${CFLAGS_BIG_MEMORY}:${DEV_ASFLAGS}\
"

AVRXMEGA5_DEV_INFO="\
atxmega64a1:crtx64a1.o:${DEV_DEFS}:${CFLAGS_BIG_MEMORY}:${DEV_ASFLAGS};\
atxmega64a1u:crtx64a1u.o:${DEV_DEFS}:${CFLAGS_BIG_MEMORY}:${DEV_ASFLAGS}\
"

AVRXMEGA6_DEV_INFO="\
atxmega128a3:crtx128a3.o:${DEV_DEFS}:${CFLAGS_BIG_MEMORY}:${DEV_ASFLAGS};\
atxmega128a3u:crtx128a3u.o:${DEV_DEFS}:${CFLAGS_BIG_MEMORY}:${DEV_ASFLAGS};\
atxmega128b1:crtx128b1.o:${DEV_DEFS}:${CFLAGS_BIG_MEMORY}:${DEV_ASFLAGS};\
atxmega128b3:crtx128b3.o:${DEV_DEFS}:${CFLAGS_BIG_MEMORY}:${DEV_ASFLAGS};\
atxmega128c3:crtx128c3.o:${DEV_DEFS}:${CFLAGS_BIG_MEMORY}:${DEV_ASFLAGS};\
atxmega128d3:crtx128d3.o:${DEV_DEFS}:${CFLAGS_BIG_MEMORY}:${DEV_ASFLAGS};\
atxmega128d4:crtx128d4.o:${DEV_DEFS}:${CFLAGS_BIG_MEMORY}:${DEV_ASFLAGS};\
atxmega192a3:crtx192a3.o:${DEV_DEFS}:${CFLAGS_BIG_MEMORY}:${DEV_ASFLAGS};\
atxmega192a3u:crtx192a3u.o:${DEV_DEFS}:${CFLAGS_BIG_MEMORY}:${DEV_ASFLAGS};\
atxmega192c3:crtx192c3.o:${DEV_DEFS}:${CFLAGS_BIG_MEMORY}:${DEV_ASFLAGS};\
atxmega192d3:crtx192d3.o:${DEV_DEFS}:${CFLAGS_BIG_MEMORY}:${DEV_ASFLAGS};\
atxmega256a3:crtx256a3.o:${DEV_DEFS}:${CFLAGS_BIG_MEMORY}:${DEV_ASFLAGS};\
atxmega256a3u:crtx256a3u.o:${DEV_DEFS}:${CFLAGS_BIG_MEMORY}:${DEV_ASFLAGS};\
atxmega256a3b:crtx256a3b.o:${DEV_DEFS}:${CFLAGS_BIG_MEMORY}:${DEV_ASFLAGS};\
atxmega256a3bu:crtx256a3bu.o:${DEV_DEFS}:${CFLAGS_BIG_MEMORY}:${DEV_ASFLAGS};\
atxmega256c3:crtx256c3.o:${DEV_DEFS}:${CFLAGS_BIG_MEMORY}:${DEV_ASFLAGS};\
atxmega256d3:crtx256d3.o:${DEV_DEFS}:${CFLAGS_BIG_MEMORY}:${DEV_ASFLAGS};\
atxmega384c3:crtx384c3.o:${DEV_DEFS}:${CFLAGS_BIG_MEMORY}:${DEV_ASFLAGS};\
atxmega384d3:crtx384d3.o:${DEV_DEFS}:${CFLAGS_BIG_MEMORY}:${DEV_ASFLAGS}\
"

AVRXMEGA7_DEV_INFO="\
atxmega128a1:crtx128a1.o:${DEV_DEFS}:${CFLAGS_BIG_MEMORY}:${DEV_ASFLAGS};\
atxmega128a1u:crtx128a1u.o:${DEV_DEFS}:${CFLAGS_BIG_MEMORY}:${DEV_ASFLAGS};\
atxmega128a4u:crtx128a4u.o:${DEV_DEFS}:${CFLAGS_BIG_MEMORY}:${DEV_ASFLAGS}\
"

AVRTINY_DEV_INFO="\
attiny4:crttn4.o:${DEV_DEFS}:${CFLAGS_SPACE}:${DEV_ASFLAGS};\
attiny5:crttn5.o:${DEV_DEFS}:${CFLAGS_SPACE}:${DEV_ASFLAGS};\
attiny9:crttn9.o:${DEV_DEFS}:${CFLAGS_SPACE}:${DEV_ASFLAGS};\
attiny10:crttn10.o:${DEV_DEFS}:${CFLAGS_SPACE}:${DEV_ASFLAGS};\
attiny20:crttn20.o:${DEV_DEFS}:${CFLAGS_SPACE}:${DEV_ASFLAGS};\
attiny40:crttn40.o:${DEV_DEFS}:${CFLAGS_SPACE}:${DEV_ASFLAGS}\
"


LIB_DEFS="-D__COMPILING_AVR_LIBC__"

AVR_ARH_INFO="\
avr2::AVR12_DEV_INFO:${LIB_DEFS}:${CFLAGS_SPACE}:${DEV_ASFLAGS};\
avr2:tiny-stack:AVR12TS_DEV_INFO:${LIB_DEFS}:${CFLAGS_TINY_STACK}:${DEV_ASFLAGS};\
avr25::AVR25_DEV_INFO:${LIB_DEFS}:${CFLAGS_SPACE}:${DEV_ASFLAGS};\
avr25:tiny-stack:AVR25TS_DEV_INFO:${LIB_DEFS}:${CFLAGS_TINY_STACK}:${DEV_ASFLAGS};\
avr3::AVR3_DEV_INFO:${LIB_DEFS}:${CFLAGS_SPACE}:${DEV_ASFLAGS};\
avr31::AVR31_DEV_INFO:${LIB_DEFS}:${CFLAGS_SPACE}:${DEV_ASFLAGS};\
avr35::AVR35_DEV_INFO:${LIB_DEFS}:${CFLAGS_SPACE}:${DEV_ASFLAGS};\
avr4::AVR4_DEV_INFO:${LIB_DEFS}:${CFLAGS_SPACE}:${DEV_ASFLAGS};\
avr5::AVR5_DEV_INFO:${LIB_DEFS}:${CFLAGS_SPACE}:${DEV_ASFLAGS};\
avr51::AVR51_DEV_INFO:${LIB_DEFS}:${CFLAGS_BIG_MEMORY}:${DEV_ASFLAGS};\
avr6::AVR6_DEV_INFO:${LIB_DEFS}:${CFLAGS_BIG_MEMORY}:${DEV_ASFLAGS};\
avrxmega2::AVRXMEGA2_DEV_INFO:${LIB_DEFS}:${CFLAGS_SPACE}:${DEV_ASFLAGS};\
avrxmega4::AVRXMEGA4_DEV_INFO:${LIB_DEFS}:${CFLAGS_BIG_MEMORY}:${DEV_ASFLAGS};\
avrxmega5::AVRXMEGA5_DEV_INFO:${LIB_DEFS}:${CFLAGS_BIG_MEMORY}:${DEV_ASFLAGS};\
avrxmega6::AVRXMEGA6_DEV_INFO:${LIB_DEFS}:${CFLAGS_BIG_MEMORY}:${DEV_ASFLAGS};\
avrxmega7::AVRXMEGA7_DEV_INFO:${LIB_DEFS}:${CFLAGS_BIG_MEMORY}:${DEV_ASFLAGS};\
avrtiny::AVRTINY_DEV_INFO:${LIB_DEFS}:${CFLAGS_SPACE}:${DEV_ASFLAGS}\
"

echo "Generating source directories:"

top_dir="UNKNOWN"

if test -f AUTHORS
then
	top_dir="$PWD"
else
	cd ..
	if test -f AUTHORS
	then
		top_dir="$PWD"
	fi
fi

if test $top_dir = "UNKNOWN"
then
	echo "Can't determine the top level source dir. Aborting."
	exit 1
fi

test -d avr || mkdir avr
test -d avr/lib || mkdir avr/lib

cd avr/lib || exit 1

IFS=';'
ARH_SUBDIRS=""

for ath_lib in $AVR_ARH_INFO
do
	arh=`echo $ath_lib | cut -d ':' -f 1`
	sublib=`echo $ath_lib | cut -d ':' -f 2`
	dev_info=`echo $ath_lib | cut -d ':' -f 3`
	lib_defs=`echo $ath_lib | cut -d ':' -f 4`
	lib_cflags=`echo $ath_lib | cut -d ':' -f 5`
	lib_asflags=`echo $ath_lib | cut -d ':' -f 6`

	install_dir=$arh
	if [ $arh = avr2 ]
	then
		if [ -z "$sublib" ] ; then
			install_dir=""
		else
			install_dir=$sublib
		fi
	else
		if [ -z "$sublib" ] ; then
			install_dir=$arh
		else
			install_dir=$arh'/'$sublib
		fi
	fi

	# Install directory for sed substitution, the '/' character is masked.
	inst_dir_masked=`echo $install_dir | sed 's/\\//\\\\\\//'`

    # In build tree.
    subdir=${arh}${sublib:+/}${sublib}
    echo "  avr/lib/$subdir/"

    # The first record of each arch must be sublib-free.
    test -d $subdir || mkdir $subdir
    cd $subdir || exit 1

    DEV_SUBDIRS=""

	eval DEV_INFO=\"\$\{$dev_info\}\"

	for dev_crt in $DEV_INFO
	do
		dev=`echo $dev_crt | cut -d ':' -f 1`
		crt=`echo $dev_crt | cut -d ':' -f 2`
		crt_defs=`echo $dev_crt | cut -d ':' -f 3`
		crt_cflags=`echo $dev_crt | cut -d ':' -f 4`
		crt_asflags=`echo $dev_crt | cut -d ':' -f 5`

		echo "  avr/lib/$subdir/$dev"

		test -d $dev || mkdir $dev

		cat $top_dir/devtools/Device.am > $dev/Makefile.am

		sed -e "s/<<dev>>/$dev/g" \
		    -e "s/<<crt>>/$crt/g" \
		    -e "s/<<crt_defs>>/$crt_defs/g" \
		    -e "s/<<crt_cflags>>/$crt_cflags/g" \
		    -e "s/<<crt_asflags>>/$crt_asflags/g"  \
		    -e "s/<<install_dir>>/$inst_dir_masked/g" $dev/Makefile.am \
		    > $dev/tempfile && mv -f $dev/tempfile $dev/Makefile.am

		DEV_SUBDIRS="$DEV_SUBDIRS $dev"
	done

	cat $top_dir/devtools/Architecture.am > Makefile.am

	sed -e "s/<<dev_subdirs>>/$DEV_SUBDIRS/g" \
	    -e "s/<<arh>>/$arh/g" \
	    -e "s/<<lib_defs>>/$lib_defs/g" \
	    -e "s/<<lib_cflags>>/$lib_cflags/g" \
	    -e "s/<<lib_asflags>>/$lib_asflags/g" \
	    -e "s/<<install_dir>>/$inst_dir_masked/g" Makefile.am \
	    > tempfile && mv -f tempfile Makefile.am

	# Find the first and the last lines of <<dev>> block.
	n1=`grep -En '^if[[:blank:]]+HAS_<<dev>>' Makefile.am	\
	    | cut -d ':' -f 1`
	n2=`grep -En '^endif[[:blank:]]+#[[:blank:]]*<<dev>>' Makefile.am \
	    | cut -d ':' -f 1`

	# Before the <<dev>> block.
	head -n `expr $n1 - 1` Makefile.am > tempfile

	# Duplicate the <<dev>> block and substitute.
	for dev_crt in $DEV_INFO ; do
		dev=`echo $dev_crt | cut -d ':' -f 1`
		tail -n +$n1 Makefile.am	\
		    | head -n `expr $n2 - $n1 + 1`	\
		    | sed -e "s/<<dev>>/$dev/g" >> tempfile
	done

	# After the <<dev>> block.
	tail -n +`expr $n2 + 1` Makefile.am >> tempfile

	# Result.
	mv -f tempfile Makefile.am

	ARH_SUBDIRS="$ARH_SUBDIRS $subdir"

	cd .. || exit 1
	if [ -n "$sublib" ] ; then
		cd .. || exit 1
	fi
done

cat $top_dir/devtools/Lib.am > Makefile.am

sed -e "s/<<arh_subdirs>>/`echo $ARH_SUBDIRS | sed 's/\\//\\\\\\//g'`/g" \
    Makefile.am > tempfile && mv -f tempfile Makefile.am

cd ..

cat $top_dir/devtools/Avr.am > Makefile.am
