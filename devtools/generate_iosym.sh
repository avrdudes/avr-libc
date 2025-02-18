#! /bin/sh

# Allow to only generate for selected devices by providing DEVS.
# Only when DEVS is not defined use the devices below.
devs=${DEVS-"at43usb320 at43usb355 at76c711 at86rf401 at90c8534 at90can128 \
at90can32 at90can64 at90pwm1 at90pwm2 at90pwm216 at90pwm2b at90pwm3 \
at90pwm316 at90pwm3b at90pwm81 at90s1200 at90s2313 at90s2323 at90s2333 \
at90s2343 at90s4414 at90s4433 at90s4434 at90s8515 at90s8535 at90scr100 \
at90usb1286 at90usb1287 at90usb162 at90usb646 at90usb647 at90usb82 \
at94k ata6289 atmega103 atmega128 atmega1280 atmega1281 atmega1284p \
atmega1284rfr2 atmega128rfa1 atmega128rfr2 atmega16 atmega161 \
atmega162 atmega163 atmega164a atmega164p atmega165 atmega165a \
atmega165p atmega168 atmega168a atmega168p atmega169 atmega169a \
atmega169p atmega169pa atmega16a atmega16hva atmega16hva2 atmega16hvb \
atmega16hvbrevb atmega16m1 atmega16u2 atmega16u4 atmega2560 atmega2561 \
atmega2564rfr2 atmega256rfr2 atmega32 atmega323 atmega324a atmega324p \
atmega324pa atmega325 atmega3250 atmega3250a atmega3250p atmega325a \
atmega325p atmega328 atmega328p atmega329 atmega3290 atmega3290a \
atmega3290p atmega329a atmega329p atmega329pa atmega32c1 atmega32hvb \
atmega32hvbrevb atmega32m1 atmega32u2 atmega32u4 atmega32u6 atmega406 \
atmega48 atmega48a atmega48p atmega64 atmega640 atmega644 atmega644a \
atmega644p atmega644pa atmega644rfr2 atmega645 atmega6450 atmega6450a \
atmega6450p atmega645a atmega645p atmega649 atmega6490 atmega6490a \
atmega6490p atmega649a atmega649p atmega64c1 atmega64hve atmega64m1 \
atmega64rfr2 atmega8 atmega8515 atmega8535 atmega88 atmega88a \
atmega88p atmega88pa atmega8hva atmega8u2 attiny10 attiny102 attiny104 attiny11 \
attiny12 attiny13 attiny13a attiny15 attiny167 attiny20 attiny22 attiny2313 \
attiny2313a attiny24 attiny24a attiny25 attiny26 attiny261 attiny261a \
attiny28 attiny4 attiny40 attiny4313 attiny43u attiny44 attiny44a attiny441 \
attiny45 attiny461 attiny461a attiny48 attiny5 attiny84 attiny84a attiny841 \
attiny85 attiny861 attiny861a attiny87 attiny88 attiny9 atxmega128a1 \
attiny202 attiny204 attiny212 attiny214 attiny402 attiny404 attiny406 \
attiny412 attiny414 attiny416 attiny417 attiny424 attiny426 attiny427 \
attiny804 attiny806 attiny807 attiny814 attiny816 attiny817 \
attiny824 attiny826 attiny827 attiny1604 attiny1606 attiny1607 \
attiny1614 attiny1616 attiny1617 attiny1624 attiny1626 attiny1627 \
attiny3214 attiny3216 attiny3217 attiny3224 attiny3226 attiny3227 \
atmega808 atmega809 atmega1608 atmega1609 atmega3208 atmega3209 atmega4808 atmega4809 \
atxmega128a1u atxmega128a3 atxmega128d3 atxmega16a4 atxmega16d4 \
atxmega192a3 atxmega192d3 atxmega256a3 atxmega256a3b atxmega256d3 \
atxmega32a4 atxmega32d4 atxmega64a1 atxmega64a1u atxmega64a3 \
atxmega64d3 at90pwm161 ata5272 ata5505 ata5790 ata5791 ata5795 ata6285 \
ata6286 ata6616c atmega1284 atmega128a atmega164pa atmega165pa atmega168pa \
atmega168pb atmega328pb atmega324pb \
ata8210 ata8510 \
atmega3250pa atmega325pa atmega3290pa atmega32a atmega48pa atmega64a \
atmega8a attiny1634 attiny828 atxmega128a3u atxmega128a4u atxmega128b1 \
atxmega128b3 atxmega128c3 atxmega128d4 atxmega16a4u atxmega16c4 atxmega16e5 \
atxmega192a3u atxmega192c3 atxmega256a3bu atxmega256a3u atxmega256c3 \
atxmega32a4u atxmega32c4 atxmega384c3 atxmega384d3 atxmega64a3u \
atxmega64a4u atxmega64b1 atxmega64b3 atxmega64c3 atxmega64d4 ata6617c \
ata664251 ata6612c atmega48pb atmega88pb avr16dd14 avr16dd20 avr16dd28 \
avr16dd32 avr32da28 avr32da32 avr32da48 avr32db28 avr32db32 avr32db48 \
avr32dd14 avr32dd20 avr32dd28 avr32dd32 avr64da28 avr64da32 avr64da48 \
avr64da64 avr64db28 avr64db32 avr64db48 avr64db64 avr64dd14 avr64dd20 \
avr64dd28 avr64dd32 avr128da28 avr128da32 avr128da48 avr128da64 avr128db28 \
avr128db32 avr128db48 avr128db64 avr16ea28 avr16ea32 avr16ea48 avr16eb14 \
avr16eb20 avr16eb28 avr16eb32 avr32ea28 avr32ea32 avr32ea48 avr64ea28 avr64ea32 avr64ea48 \
avr16du14 avr16du20 avr16du28 avr16du32 \
"}

if [ x"$ATDFDIR" = x ]
then
    echo 'Please set $ATDFDIR in your environment' >&2
    exit 64
fi

for dev in $devs
do
    xmldev=$(echo $dev | tr '[a-z]' '[A-Z]' |\
             sed -e s/XMEGA/xmega/ -e s/MEGA/mega/ -e s/TINY/tiny/)
    if [ -f "${ATDFDIR}/${xmldev}.atdf" ]
    then
        echo "Generating ${dev}.S"
        ./ioreg.pl "${ATDFDIR}/${xmldev}.atdf" > ../crt1/iosym/${dev}.S
    fi
done
