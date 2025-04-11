#if defined(USE_AVRTEST) && !defined(__AVR_TINY__)

#include <stdfix.h>
#include <stdlib.h>
#include <stdint.h>
#include <string.h>
#include <avr/pgmspace.h>

#ifdef USE_AVRTEST
#include "avrtest.h"
#endif

char buf[40];

void show (uint8_t mode, const char *str)
{
#ifdef USE_AVRTEST
  LOG_PFMT_U8 (PSTR ("\n\n BUG mode=0x%02x: "), mode);
  LOG_PFMT_STR (PSTR ("\"%s\" != "), buf);
  LOG_PFMT_PSTR (PSTR ("\"%s\"\n"), str);
#else
  (void) mode;
  (void) str;
#endif
}

#define TST(SUFF, VAL, MODE, STR)               \
  do                                            \
    {                                           \
      SUFF##toa (VAL, buf, MODE);               \
      const char *str = PSTR (STR);             \
      if (strcmp_P (buf, str))                  \
        {                                       \
          show (MODE, str);                     \
          exit (__LINE__);                      \
        }                                       \
    }                                           \
  while (0)


int main (void)
{
  TST (k,   kbits (1ul << 31), FXTOA_ALL, "-65536");
  TST (hk, hkbits (1ul << 15), FXTOA_ALL, "-256");
  TST (r,   rbits (1ul << 15), FXTOA_ALL, "-1");
  TST (hr, hrbits (1ul <<  7), FXTOA_ALL, "-1");

  TST (k,  65535.6k,  FXTOA_ROUND | 0, "65536");
  TST (hk,   255.6hk, FXTOA_ROUND | 0, "256");
  TST (r,      0.6r,  FXTOA_ROUND | 0, "1");
  TST (hr,     0.6hr, FXTOA_ROUND | 0, "1");

  TST (k, -65535.6k,  FXTOA_ROUND | 0, "-65536");
  TST (hk,  -255.6hk, FXTOA_ROUND | 0, "-256");
  TST (r,     -0.6r,  FXTOA_ROUND | 0, "-1");
  TST (hr,    -0.6hr, FXTOA_ROUND | 0, "-1");

  TST (uk,  65535.6uk,  FXTOA_ROUND | 0, "65536");
  TST (uhk,   255.6uhk, FXTOA_ROUND | 0, "256");
  TST (ur,      0.6ur,  FXTOA_ROUND | 0, "1");
  TST (uhr,     0.6uhr, FXTOA_ROUND | 0, "1");

  return 0;
}

#else
int main (void)
{
  return 0;
}
#endif

