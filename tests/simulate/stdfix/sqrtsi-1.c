#include <stdint.h>
#include <stdlib.h>

extern uint16_t __sqrtsi (uint32_t);

int main(void)
{
	uint16_t r;
	uint32_t sqr;
	if (UINT16_MAX != 65535U) exit (__LINE__);
	if (UINT32_MAX != 4294967295UL) exit (__LINE__);
	/* Test limits first. */
	r = __sqrtsi (0UL);
	if (r != 0U) exit (__LINE__);
	r = __sqrtsi(1UL);
	if (r != 1U) exit (__LINE__);
	r = __sqrtsi (UINT32_MAX);
	if (r != UINT16_MAX) exit (__LINE__);
	/* Test all perfect squares. */
	for (uint16_t i = 1U; i < UINT16_MAX; i++)
	{
		sqr = (uint32_t) i * (uint32_t) i;
		r = __sqrtsi (sqr);
		if (r != i) exit(__LINE__);
		uint16_t r2 = __sqrtsi (sqr - 1);
		if (r2 != r - 1) exit(__LINE__);
	}
	/* Test rounding down for large values. */
	sqr = (uint32_t) UINT16_MAX * (uint32_t) UINT16_MAX;
	for (uint32_t j = sqr; j < UINT32_MAX; j++)
	{
		r = __sqrtsi (j);
		if (r != UINT16_MAX) exit (__LINE__);
	}
	return 0;
}
