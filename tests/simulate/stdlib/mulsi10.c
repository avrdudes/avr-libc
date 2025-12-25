#include <stdint.h>

extern uint32_t mul10 (uint32_t) __asm("__mulsi_const_10");

#ifndef __FLASH
#define __flash /* empty */
#endif

const __flash uint32_t data[] =
{
  0, 1, 2, 3, 4, -1ul, -2ul, 123456,
  0xcafebabe / 10,
  0xcafebabe / 10 + 1,
  0xcafebabe / 10 - 1,
  UINT32_MAX / 10,
  UINT32_MAX / 10 + 1,
  UINT32_MAX / 10 - 1,
  INT32_MAX / 10,
  INT32_MAX / 10 + 1,
  INT32_MAX / 10 - 1,
  (uint32_t) (INT32_MIN / 10),
  (uint32_t) (INT32_MIN / 10) + 1,
  (uint32_t) (INT32_MIN / 10) - 1
};

#define ARRAY_SIZE(X) (sizeof(X) / sizeof(*X))

int main (void)
{
  for (unsigned i = 0; i < ARRAY_SIZE (data); ++i)
    {
      uint32_t d = data[i];
      __asm ("" : "+r" (d));

      if (mul10 (d) != 10 * d)
        __builtin_abort();
    }

  return 0;
}
