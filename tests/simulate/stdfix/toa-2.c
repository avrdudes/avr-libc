#if !defined(__AVR_TINY__)

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
      SUFF##toa (VAL##SUFF, buf, MODE);         \
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
  TST (uk, 99.8, FXTOA_ROUND | 0, "100");
  TST (uk, 99.8, FXTOA_ROUND | 1, "99.8");
  TST (uk, 99.8, FXTOA_ROUND | 2, "99.80");
  TST (uk, 99.8, FXTOA_ROUND | 3, "99.800");
  TST (uk, 99.8, FXTOA_ROUND | 4, "99.8000");

  TST (k, 99.8, FXTOA_ROUND | 0, "100");
  TST (k, 99.8, FXTOA_ROUND | 1, "99.8");
  TST (k, 99.8, FXTOA_ROUND | 2, "99.80");
  TST (k, 99.8, FXTOA_ROUND | 3, "99.800");
  TST (k, 99.8, FXTOA_ROUND | 4, "99.8000");

  TST (uk, 99.8, FXTOA_ROUND | FXTOA_NTZ | 0, "100");
  TST (uk, 99.8, FXTOA_ROUND | FXTOA_NTZ | 1, "99.8");
  TST (uk, 99.8, FXTOA_ROUND | FXTOA_NTZ | 2, "99.8");
  TST (uk, 99.8, FXTOA_ROUND | FXTOA_NTZ | 3, "99.8");
  TST (uk, 99.8, FXTOA_ROUND | FXTOA_NTZ | 4, "99.8");

  TST (k, 99.8, FXTOA_ROUND | FXTOA_NTZ | 0, "100");
  TST (k, 99.8, FXTOA_ROUND | FXTOA_NTZ | 1, "99.8");
  TST (k, 99.8, FXTOA_ROUND | FXTOA_NTZ | 2, "99.8");
  TST (k, 99.8, FXTOA_ROUND | FXTOA_NTZ | 3, "99.8");
  TST (k, 99.8, FXTOA_ROUND | FXTOA_NTZ | 4, "99.8");

  TST (k, -99.8, FXTOA_TRUNC | 0, "-99");
  TST (k, -99.8, FXTOA_TRUNC | 1, "-99.7");
  TST (k, -99.8, FXTOA_TRUNC | 2, "-99.79");
  TST (k, -99.8, FXTOA_TRUNC | 3, "-99.799");
  TST (k, -99.8, FXTOA_TRUNC | 4, "-99.7999");

  TST (k, -99.8, FXTOA_ROUND | FXTOA_NTZ | FXTOA_COMMA | 0, "-100");
  TST (k, -99.8, FXTOA_ROUND | FXTOA_NTZ | FXTOA_COMMA | 1, "-99,8");
  TST (k, -99.8, FXTOA_ROUND | FXTOA_NTZ | FXTOA_COMMA | 2, "-99,8");
  TST (k, -99.8, FXTOA_ROUND | FXTOA_NTZ | FXTOA_COMMA | 3, "-99,8");
  TST (k, -99.8, FXTOA_ROUND | FXTOA_NTZ | FXTOA_COMMA | 4, "-99,8");
  TST (k, -99.8, FXTOA_ROUND | FXTOA_NTZ | FXTOA_COMMA | 5, "-99,79998");

  TST (k, -99.96, FXTOA_ROUND | FXTOA_NTZ | FXTOA_COMMA | 0, "-100");
  TST (k, -99.96, FXTOA_ROUND | FXTOA_NTZ               | 1, "-100");

  TST (k, -99.8, FXTOA_ALL | FXTOA_COMMA, "-99,79998779296875");

  return 0;
}

#else
int main (void)
{
  return 0;
}
#endif
