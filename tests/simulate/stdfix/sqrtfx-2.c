#include <stdint.h>
#include <stdlib.h>

/* Test all 8-bit square roots of 16-bit unsigned integers */
extern unsigned char __sqrthi (unsigned arg);

int main()
{
	uint8_t i;
	uint16_t j;
	uint16_t res;
	uint16_t sqr;
	uint16_t next_sqr;
	
	if (UINT8_MAX != 255) exit(UINT8_MAX);
	/* Start from i = 1 to avoid exit(0) on error. */
	for (i = 1; i < UINT8_MAX; i++)
	{
		sqr = i * i;
		next_sqr = (i + 1) * (i + 1);
		/* All square root values for an argument between two consecutive squares
		   must be equal to the integer part of the square root. */
		for (j = sqr; j < next_sqr; j++)
		{
			res = __sqrthi(j);
			if (res != i) exit(j);
		}
	}
	for (j = UINT8_MAX * UINT8_MAX; j < UINT16_MAX; j++)
	{
		res = __sqrthi(j);
		if (res != UINT8_MAX) exit(j);
	}
	res = __sqrthi(UINT16_MAX);
	if (res != UINT8_MAX) exit(UINT16_MAX);
	return 0;
}
