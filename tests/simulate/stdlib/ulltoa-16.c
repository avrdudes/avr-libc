#include <stdint.h>
#include <stdlib.h>
#include <avr/flash.h>

static char buf[20];

__attribute__((__noreturn__,noipa))
void bad (const __flash char *soll, const char *ist)
{
  (void) soll;
  (void) ist;
  __builtin_abort();
}

#define ARRAY_SIZE(X) ((int) (sizeof (X) / sizeof (*X)))

typedef struct
{
  uint64_t num;
  const __flash char *str;
} data_u64_t;

#define _(X)                                    \
  { UINT64_C(0x ## X), FLIT (#X) }

static const __flash data_u64_t data_u64[] =
  {
    _(1), _(0),
    _(10),
    _(100),
    _(1000),
    _(10000),
    _(100000),
    _(1000000),
    _(10000000),
    _(100000000),
    _(1000000000),
    _(10000000000),
    _(100000000000),
    _(1000000000000),
    _(10000000000000),
    _(100000000000000),
    _(1000000000000000),
    _(f),
    _(f0),
    _(e00),
    _(f000),
    _(f0000),
    _(f00100),
    _(f000000),
    _(80000000),
    _(f00000001),
    _(added0f000),
    _(f0000000000),
    _(f0000000cafe),
    _(f00babeface00),
    _(f00affe0000000),
    _(fffffffefffffff),
    _(ffffffffffffffff),
    _(8000000000000000),
  };

void test_u64 (void)
{
  int i;
  for (i = 0; i < ARRAY_SIZE (data_u64); ++i)
    {
      uint64_t num = data_u64[i].num;
      ulltoa (num, buf, 16);
      const __flash char* soll = data_u64[i].str;
      if (strcmp_F (buf, soll))
        bad (soll, buf);
    }
}

int main (void)
{
  test_u64();
  return 0;
}
