#include <stdint.h>
#include <stdfix.h>

#include "fx-to-float.h"

#define TEST(T)					\
  do {						\
    T##_t fx = T##bits (u);			\
    DD y = T##2d (fx);				\
    T##_t fy = d2##T (y);			\
    if (fy != fx)				\
      __builtin_exit (__LINE__);		\
  } while (0)


NI void test (uint64_t u)
{
  TEST (da);
  TEST (ta);
  TEST (dq);
  TEST (uda);
  TEST (uta);
  TEST (udq);
}

int main (void)
{
  test (0);
  test (1);
  test (0x1ull << 63);
  test (0x7f123cull);
  test (0xff123cull);
  test (0x7f123cull << 63);
  test (0xff123cull << 63);
  test (0x7f123cull << 33);
  test (0xff123cull << 33);

  return 0;
}
