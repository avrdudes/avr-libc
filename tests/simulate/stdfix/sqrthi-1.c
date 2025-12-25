#include <stdint.h>
#include <stdlib.h>

#define FUN(x) sqrtu16_floor (x)

int main (void)
{
	uint8_t r;
	uint16_t sqr;
	/* Test limits first. */
	r = FUN (0UL);
	if (r != 0U) exit (__LINE__);
	r = FUN(1UL);
	if (r != 1U) exit (__LINE__);
	r = FUN (UINT16_MAX);
	if (r != UINT8_MAX) exit (__LINE__);
	/* Test all perfect squares. */
	for (uint16_t i = 1U; i < UINT8_MAX; i++)
	{
		sqr = (uint16_t) i * i;
		r = FUN (sqr);
		if (r != i) exit(__LINE__);
		uint8_t r2 = FUN (sqr - 1);
		if (r2 != r - 1) exit(__LINE__);
	}
	/* Test rounding down for large values. */
	sqr = (uint16_t) UINT8_MAX * UINT8_MAX;
	for (uint16_t j = sqr; j < UINT16_MAX; j++)
	{
		r = FUN (j);
		if (r != UINT8_MAX) exit (__LINE__);
	}
	return 0;
}
