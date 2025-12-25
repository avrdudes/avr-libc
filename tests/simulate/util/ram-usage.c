#include <stdint.h>
#include <util/ram-usage.h>

__attribute__((used))
uint16_t x;

extern uint8_t __heap_start[];
extern uint8_t __ram_color_value[];

int main (void)
{
  uint8_t color = (uint8_t) (uintptr_t) __ram_color_value;

  if (__heap_start[0] != color)
    __builtin_abort();

  x = _get_ram_unused ();

  return 0;
}
