#include <limits.h>
#include <stdfix.h>
#include <stdlib.h>

int
main (void)
{
  fract r;
  r = rdivi (0, 1);
  if (r != 0r)
    exit (__LINE__);

  /* simple fractions */
  r = rdivi (1, 2);
  if (r != 0.5r)
    exit (__LINE__);
  r = rdivi (1, 4);
  if (r != 0.25r)
    exit (__LINE__);

  r = rdivi (-1, 2);
  if (r != -0.5r)
    exit (__LINE__);
  r = rdivi (-1, 4);
  if (r != -0.25r)
    exit (__LINE__);

  r = rdivi (1, -2);
  if (r != -0.5r)
    exit (__LINE__);
  r = rdivi (1, -4);
  if (r != -0.25r)
    exit (__LINE__);

  r = rdivi (-1, -2);
  if (r != 0.5r)
    exit (__LINE__);
  r = rdivi (-1, -4);
  if (r != 0.25r)
    exit (__LINE__);

  /* saturated values */
  r = rdivi (1, 1);
  if (r != FRACT_MAX)
    exit (__LINE__);
  r = rdivi (-1, 1);
  if (r != FRACT_MIN)
    exit (__LINE__);
  r = rdivi (1, -1);
  if (r != FRACT_MIN)
    exit (__LINE__);
  r = rdivi (-1, -1);
  if (r != FRACT_MAX)
    exit (__LINE__);
  r = rdivi (INT_MAX, 1);
  if (r != FRACT_MAX)
    exit (__LINE__);
  r = rdivi (INT_MIN, 1);
  if (r != FRACT_MIN)
    exit (__LINE__);
  r = rdivi (INT_MAX, INT_MAX);
  if (r != FRACT_MAX)
    exit (__LINE__);
  r = rdivi (INT_MIN, INT_MIN);
  if (r != FRACT_MAX)
    exit (__LINE__);
  r = rdivi (INT_MIN, INT_MAX);
  if (r != FRACT_MIN)
    exit (__LINE__);
  r = rdivi (INT_MAX, INT_MIN);
  if (r != FRACT_MIN)
    exit (__LINE__);
  r = rdivi (INT_MAX - 1, INT_MAX);
  if (r != FRACT_MAX - FRACT_EPSILON)
    exit (__LINE__);

  /* values close to EPSILON */
  r = rdivi (1, INT_MAX);
  if (r != FRACT_EPSILON)
    exit (__LINE__);
  r = rdivi (-1, INT_MAX);
  if (r != -FRACT_EPSILON)
    exit (__LINE__);
  r = rdivi (1, INT_MIN);
  if (r != -FRACT_EPSILON)
    exit (__LINE__);
  r = rdivi (-1, INT_MIN);
  if (r != FRACT_EPSILON)
    exit (__LINE__);

  return 0;
}
