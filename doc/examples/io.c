#include <io.h>
/*
  return low byte of stack pointer
*/

void set_low_sp (unsigned char a)
{
  outp (a, SPL);
}

int foo ()
{
  return inp ( SPL );
}

int 
main ()
{
  set_low_sp (254);
  return foo ();
}
/*
  inp (arg) - arg must be constant !!
*/
