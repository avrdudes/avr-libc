#include <stdint.h>
#include <stdlib.h>
#include <avr/flash.h>

static char buf[30];

#include "/home/john/gnu/source/avrtest/avrtest.h"
#include <string.h>

__attribute__((__noreturn__,noipa))
void bad (const __flash char *soll, const char *ist)
{
    LOG_PFMT_U16 (FSTR ("Soll #=%u,"), strlen_F (soll));
    LOG_PFMT_U16 (FSTR (" ist #=%d\n"), strlen (ist));
    LOG_PFMT_PSTR (FSTR ("Soll ='%S'\n"), soll);
    LOG_PFMT_STR  (FSTR ("Ist  ='%s'\n"), ist);
  (void) soll;
  (void) ist;
  __builtin_abort();
}

#define ARRAY_SIZE(X) ((int) (sizeof (X) / sizeof (*X)))

typedef struct
{
  int64_t num;
  const __flash char *str;
} data_i64_t;

#define _(X)                                    \
    { INT64_C(X), FLIT (#X) },                  \
    { INT64_C(-X), FLIT ("-" #X) }

static const __flash data_i64_t data_i64[] =
  {
    { 0, FLIT("0") },
    _(1),
    _(9), _(10),
    _(99), _(100),
    _(999), _(1000),
    _(9999), _(10000),
    _(99999), _(100000),
    _(999999), _(1000000),
    _(9999999), _(10000000),
    _(99999999), _(100000000),
    _(999999999), _(1000000000),
    _(9999999999), _(10000000000),
    _(99999999999), _(100000000000),
    _(999999999999), _(1000000000000),
    _(9999999999999), _(10000000000000),
    _(99999999999999), _(100000000000000),
    _(999999999999999), _(1000000000000000),
    _(9999999999999999), _(10000000000000000),
    _(99999999999999999), _(100000000000000000),
    _(2147483647), _(2147483648), _(2147483649),
    _(4294967295), _(4290000000),
    _(1999999999), _(3999999999), _(2000000000), _(4000000000),
    _(4294967295),
    _(9223372036854775807),
    _(8999999999999999999), _(9000000000000000000),
    { INT64_MIN, FLIT("-9223372036854775808") },
  };

void test_i64 (void)
{
  int i;
  for (i = 0; i < ARRAY_SIZE (data_i64); ++i)
    {
      uint64_t num = data_i64[i].num;
      lltoa (num, buf, 10);
      const __flash char* soll = data_i64[i].str;
      if (strcmp_F (buf, soll))
        bad (soll, buf);
    }
}

int main (void)
{
  test_i64();
  return 0;
}
