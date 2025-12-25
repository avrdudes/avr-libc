#if defined(USE_AVRTEST) && !defined(__AVR_TINY__)

#include <stdfix.h>
#include <stdint.h>
#include <stdbool.h>
#include <stdlib.h>
#include <string.h>

#include "avrtest.h"

uint8_t r_ibit, ur_ibit, hr_ibit, uhr_ibit;
uint8_t k_ibit, uk_ibit, hk_ibit, uhk_ibit;
uint8_t r_fbit, ur_fbit, hr_fbit, uhr_fbit;
uint8_t k_fbit, uk_fbit, hk_fbit, uhk_fbit;

// No real tests; just show some properties of ASCII results.
char buf[40];

#define SHOW(SUFF, VAL)                                         \
  do                                                            \
    {                                                           \
      SUFF##toa (SUFF##bits (VAL), buf, FXTOA_ALL);             \
      const char *dot = strchr (buf, '.');                      \
      if (!!dot != has_dot) exit (1111);                        \
      if (has_dot)                                              \
        {                                                       \
          SUFF##_ibit = (uint8_t) (dot - buf);                  \
          SUFF##_fbit = strlen (1 + dot);                       \
        }                                                       \
      else                                                      \
        {                                                       \
          SUFF##_ibit = strlen (buf);                           \
          SUFF##_fbit = 0;                                      \
        }                                                       \
      LOG_FMT_U8 (#SUFF "=%u", SUFF##_ibit);                    \
      LOG_FMT_U8 (".%u", SUFF##_fbit);                          \
      LOG_FMT_U16 ("\t#=%u  ", strlen (buf));                   \
      LOG_FMT_STR ("[%s]\n", buf);                              \
    }                                                           \
  while (0)


int main (void)
{
  bool has_dot = 1;
  LOG_STR ("\n\nOutput:\n");
  SHOW (uk,  0xffffffff);
  SHOW (k,   0x7fffffff);
  SHOW (uhk, 0xffff);
  SHOW (hk,  0x7fff);

  SHOW (ur,  0xffff);
  SHOW (r,   0x7fff);
  SHOW (uhr, 0xff);
  SHOW (hr,  0x7f);

  if (r_ibit != 1)    exit (__LINE__);
  if (ur_ibit != 1)   exit (__LINE__);
  if (hr_ibit != 1)   exit (__LINE__);
  if (uhr_ibit != 1)  exit (__LINE__);

  if (k_fbit != r_fbit)      exit (__LINE__);
  if (uk_fbit != ur_fbit)    exit (__LINE__);
  if (hk_fbit != hr_fbit)    exit (__LINE__);
  if (uhk_fbit != uhr_fbit)  exit (__LINE__);

  LOG_STR ("\n");
  has_dot = 0;
  SHOW (k,  0x80000000);
  SHOW (hk, 0x8000);
  SHOW (r,  0x8000);
  SHOW (hr, 0x80);

  return 0;
}

#else
int main (void)
{
  return 0;
}
#endif
