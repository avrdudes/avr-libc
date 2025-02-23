#include <limits.h>
#include <stdfix.h>
#include <stdlib.h>

int
main (void)
{
  long fract r;
  r = lrdivi (0L, 1L);
  if (r != 0LR)
    exit (__LINE__);

  /* simple fractions */
  r = lrdivi (1L, 2L);
  if (r != 0.5LR)
    exit (__LINE__);
  r = lrdivi (1L, 4L);
  if (r != 0.25LR)
    exit (__LINE__);
  r = lrdivi (-1L, 4L);
  if (r != -0.25LR)
    exit (__LINE__);
  r = lrdivi (1L, -2L);
  if (r != -0.5LR)
    exit (__LINE__);
  r = lrdivi (1L, -4L);
  if (r != -0.25LR)
    exit (__LINE__);
  r = lrdivi (-1L, -2L);
  if (r != 0.5LR)
    exit (__LINE__);
  r = lrdivi (-1L, -4L);
  if (r != 0.25LR)
    exit (__LINE__);

  /* saturated values */
  r = lrdivi (1L, 1L);
  if (r != LFRACT_MAX)
    exit (__LINE__);
  r = lrdivi (-1L, 1L);
  if (r != LFRACT_MIN)
    exit (__LINE__);
  r = lrdivi (1L, -1L);
  if (r != LFRACT_MIN)
    exit (__LINE__);
  r = lrdivi (-1L, -1L);
  if (r != LFRACT_MAX)
    exit (__LINE__);
  r = lrdivi (LONG_MAX, 1L);
  if (r != LFRACT_MAX)
    exit (__LINE__);
  r = lrdivi (LONG_MIN, 1L);
  if (r != LFRACT_MIN)
    exit (__LINE__);
  r = lrdivi (LONG_MAX, LONG_MAX);
  if (r != LFRACT_MAX)
    exit (__LINE__);
  r = lrdivi (LONG_MIN, LONG_MIN);
  if (r != LFRACT_MAX)
    exit (__LINE__);
  r = lrdivi (LONG_MIN, LONG_MAX);
  if (r != LFRACT_MIN)
    exit (__LINE__);
  r = lrdivi (LONG_MAX, LONG_MIN);
  if (r != LFRACT_MIN)
    exit (__LINE__);
  r = lrdivi (LONG_MAX - 1, LONG_MAX);
  if (r != LFRACT_MAX - LFRACT_EPSILON)
    exit (__LINE__);

  /* values close to EPSILON */
  r = lrdivi (1L, LONG_MAX);
  if (r != LFRACT_EPSILON)
    exit (__LINE__);
  r = lrdivi (-1L, LONG_MAX);
  if (r != -LFRACT_EPSILON)
    exit (__LINE__);
  r = lrdivi (1L, LONG_MIN);
  if (r != -LFRACT_EPSILON)
    exit (__LINE__);
  r = lrdivi (-1L, LONG_MIN);
  if (r != LFRACT_EPSILON)
    exit (__LINE__);
  return 0;
}
