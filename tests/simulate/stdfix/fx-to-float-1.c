#include "fx-to-float.h"

#define TEST(T)					\
  do {						\
    T##_t fx = d2##T (x);			\
    DD y = T##2d (fx);				\
    if (y != x)					\
      __builtin_exit (__LINE__);		\
  } while (0)


NI void test_s (DD x)
{
  TEST (da);
  TEST (ta);

  if (x < 1.0f && x >= -1.0f)
    TEST (dq);
}


NI void test_u (DD x)
{
  TEST (uda);
  TEST (uta);

  if (x < 1.0f)
    TEST (udq);
}

void test (DD x)
{
  if (x >= 0)
    test_u (x);

  test_s (x);
}

int main (void)
{
  test (+0.0f);
  test (-0.0f);

  test (+1.0f);
  test (-1.0f);

  test (-0x0.cafe3p0f);
  test (+0x0.cafe3p0f);

  test (+0x1234.cp0f);
  test (-0x1234.cp0f);

  return 0;
}
