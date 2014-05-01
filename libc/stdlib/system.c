#include <errno.h>
#include <stdlib.h>

int
system (const char *s)
{
  if (s == NULL)
    return 0;
  errno = ENOSYS;
  return -1;
}
