/* FIXME: The code below does a full test over all 2^24 = 16 Mio input values.
   When simulating with simulavr, the tests fails presumably because the
   code takes too long to simulate.

   The code was tested with avrtest, though.  Suppose avrtest is installed
   in $AVRTEST_HOME, then the test can be compiled and run by means of:

   > avr-gcc -mmcu=atmega128 -Os -std=c99 util/tweak-crc16.c -o tweak-crc16.elf $AVRTEST_HOME/exit-atmega128.o -DUSE_AVRTEST

   > $AVRTEST_HOME/avrtest -mmcu=avr51 tweak-crc16.elf -m 1000000000

   For avrtest, see  https://github.com/sprintersb/atest
*/

typedef __UINT8_TYPE__ uint8_t;
typedef __UINT16_TYPE__ uint16_t;

static __inline__ uint16_t
_crc_xmodem_update_OLD (uint16_t __crc, uint8_t __data)
{
    uint16_t __ret;             /* %B0:%A0 (alias for __crc) */
    uint8_t __tmp1;             /* %1 */
    uint8_t __tmp2;             /* %2 */
                                /* %3  __data */

    __asm__ __volatile__ (
        "eor    %B0,%3"          "\n\t" /* crc.hi ^ data */
        "mov    __tmp_reg__,%B0" "\n\t"
        "swap   __tmp_reg__"     "\n\t" /* swap(crc.hi ^ data) */

        /* Calculate the ret.lo of the CRC. */
        "mov    %1,__tmp_reg__"  "\n\t"
        "andi   %1,0x0f"         "\n\t"
        "eor    %1,%B0"          "\n\t"
        "mov    %2,%B0"          "\n\t"
        "eor    %2,__tmp_reg__"  "\n\t"
        "lsl    %2"              "\n\t"
        "andi   %2,0xe0"         "\n\t"
        "eor    %1,%2"           "\n\t" /* __tmp1 is now ret.lo. */

        /* Calculate the ret.hi of the CRC. */
        "mov    %2,__tmp_reg__"  "\n\t"
        "eor    %2,%B0"          "\n\t"
        "andi   %2,0xf0"         "\n\t"
        "lsr    %2"              "\n\t"
        "mov    __tmp_reg__,%B0" "\n\t"
        "lsl    __tmp_reg__"     "\n\t"
        "rol    %2"              "\n\t"
        "lsr    %B0"             "\n\t"
        "lsr    %B0"             "\n\t"
        "lsr    %B0"             "\n\t"
        "andi   %B0,0x1f"        "\n\t"
        "eor    %B0,%2"          "\n\t"
        "eor    %B0,%A0"         "\n\t" /* ret.hi is now ready. */
        "mov    %A0,%1"          "\n\t" /* ret.lo is now ready. */
        : "=d" (__ret), "=d" (__tmp1), "=d" (__tmp2)
        : "r" (__data), "0" (__crc)
        : "r0"
    );
    return __ret;
}

static __inline__ uint16_t
_crc_xmodem_update_NEW (uint16_t __crc, uint8_t __data)
{
    uint16_t __ret;             /* %B0:%A0 (alias for __crc) */
    uint8_t __tmp1;             /* %1 */
    uint8_t __tmp2;             /* %2 */
                                /* %3  __data */
    __asm__ __volatile__ (
        "eor    %B0,%3"          "\n\t"
        "mov    %1,%A0"          "\n\t"
        "mov    %2,%B0"          "\n\t"

        "mov    %A0,%B0"         "\n\t"
        "swap   %B0"             "\n\t"
        "eor    %A0,%B0"         "\n\t"

        "andi   %A0,0xf0"        "\n\t"
        "andi   %B0,0x0f"        "\n\t"

        "eor    %1,%A0"          "\n\t"
        "eor    %2,%B0"          "\n\t"

        "lsl    %A0"             "\n\t"
        "rol    %B0"             "\n\t"

        "eor    %B0,%1"          "\n\t"
        "eor    %A0,%2"          "\n\t"
        : "=d" (__ret), "=r" (__tmp1), "=r" (__tmp2)
        : "r" (__data), "0" (__crc)
    );
    return __ret;
}

int main (void)
{
#ifdef USE_AVRTEST
    uint16_t crc = 0;
    uint8_t data = 0;

    do
    {
        do
        {
            uint16_t res1 = _crc_xmodem_update_OLD (crc, data);
            uint16_t res2 = _crc_xmodem_update_NEW (crc, data);
            if (res1 != res2)
                return __LINE__;
        } while (++data);
    } while (++crc);
#endif /* USE_AVRTEST */

    return 0;
}
