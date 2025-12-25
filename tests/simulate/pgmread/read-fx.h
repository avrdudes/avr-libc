#include <stdlib.h>
#include <stdfix.h>

#define XTEST(S, T, VAL, VAL2, VAL7)			\
  const T data[] PROGMEM =				\
    {							\
      VAL##S, VAL2##S, VAL7##S				\
    };							\
							\
__attribute__((noinline,noclone))			\
T get_val (uint8_t i)					\
{							\
  if (i == 0) return VAL##S;				\
  if (i == 1) return VAL2##S;				\
  if (i == 2) return VAL7##S;				\
  return 0##S;						\
}							\
							\
__attribute__((noinline,noclone))			\
void test (uint8_t i)					\
{							\
  if (pgm_read_##S (&data[0]) != get_val (0))		\
    exit (i);						\
							\
  if (pgm_read_##S (&data[i]) != get_val (i))		\
    exit (i);						\
}							\
							\
int main (void)						\
{							\
  test (1);						\
  test (2);						\
  return 0;						\
}

#define TEST2(S, T, VAL, VAL2, VAL7) XTEST (S, T, VAL, VAL2, VAL7)
#define TEST TEST2 (S, T, VAL, VAL2, VAL7)
