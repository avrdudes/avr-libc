#include <signal.h>


SIGNAL (SIG_SPI)
{
  /* interrupt disabled in function body, but you can write `asm ("sei"::);' */
  /*
    ...
    ...
    ...
  */
}

INTERRUPT (SIG_INTERRUPT0)
{
  /* interrupt enabled in function body, but you can write `asm ("cli"::);' */
  /*
    ...
    ...
    ...
  */
}    
