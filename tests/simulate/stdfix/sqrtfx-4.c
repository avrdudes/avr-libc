#include <stdfix.h>
#include <stdlib.h>

int main()
{
	unsigned long fract r;
	/* Sanity checks first */
	if (ULFRACT_FBIT != 32) exit (__LINE__);
	if (ULFRACT_EPSILON != 0.00000000023283064365386962890625ULR) exit (__LINE__);
	if (ULFRACT_MAX != 0.99999999976716935634613037109375ULR) exit (__LINE__);

	/* Limiting cases */
	r = sqrtulr(0.0ULR);
	if (r != 0.0ULR) exit (__LINE__);
	r = sqrtulr(ULFRACT_EPSILON); /* 2^{-16} is expected */
	if (r != 0.0000152587890625ULR) exit (__LINE__); 
	r = sqrtulr(ULFRACT_MAX); /* saturation expected */
	if (r != ULFRACT_MAX) exit (__LINE__);

	/* Special values */
	r = sqrtulr(0.5ULR);
	if (r != 0.70710678095929324626922607421875ULR) exit (__LINE__);
	r = sqrtulr(0.1ULR);
	if (r != 0.31622776575386524200439453125ULR) exit (__LINE__);
	r = sqrtulr(0.9ULR);
	if (r != 0.94868329796008765697479248046875ULR) exit (__LINE__);
	return 0;
}
