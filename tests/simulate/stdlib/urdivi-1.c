#include <limits.h>
#include <stdfix.h>
#include <stdlib.h>

int main (void)
{
  unsigned fract r;
  r = urdivi (0, 1);
  if (r != 0ur)
    exit (__LINE__);
	
  /* Saturated values */
  r = urdivi (1, 1);
  if (r != UFRACT_MAX)
    exit (__LINE__);
  r = urdivi (2, 1);
  if (r != UFRACT_MAX)
    exit (__LINE__);
  r = urdivi (UINT_MAX - 1, 1);
  if (r != UFRACT_MAX)
    exit (__LINE__);
  r = urdivi (UINT_MAX, 1);
  if (r != UFRACT_MAX)
    exit (__LINE__);
  r = urdivi (UINT_MAX, UINT_MAX);
  if (r != UFRACT_MAX)
    exit (__LINE__);
	
  /* Simple fractions */
  r = urdivi (1, 2);
  if (r != 0.5ur)
    exit (__LINE__);
  r = urdivi (1, 4);
  if (r != 0.25ur)
    exit (__LINE__);
  r = urdivi (1, UINT_MAX);
  if (r != UFRACT_EPSILON)
    exit (__LINE__);
  r = urdivi (UINT_MAX - 1, UINT_MAX);
  if (r != UFRACT_MAX - UFRACT_EPSILON)
    exit (__LINE__);

  /* Selected fractions */
  r = urdivi (1, 10);
  if (r != 0x1.999p-4ur)
    exit (__LINE__);
  r = urdivi (4, 17);
  if (r != 0x1.e1ep-3ur)
    exit (__LINE__);
  r = urdivi (113, 355);
  if (r != 0x1.45fp-2ur)
    exit (__LINE__);
  r = urdivi (543, 1113);
  if (r != 0x1.f394p-2ur)
    exit (__LINE__);

  return 0;
}
