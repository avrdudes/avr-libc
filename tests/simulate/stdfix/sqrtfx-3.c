#include <stdfix.h>
#include <stdlib.h>

int main()
{
	unsigned short fract r;
	short fract q;
	r = sqrtuhr(0.0UHR);
	if (r != 0.0UHR) exit(__LINE__);
	q = sqrthr(0.0HR);
	if (q != 0.0HR) exit(__LINE__);

	r = sqrtuhr(0.25UHR);
	if (r != 0.5UHR) exit(__LINE__);
	q = sqrthr(0.25HR);
	if (q != 0.5HR) exit(__LINE__);

	r = sqrtuhr(0.0625UHR);
	if (r != 0.25UHR) exit(__LINE__);
	q = sqrthr(0.0625HR);
	if (q != 0.25HR) exit(__LINE__);

	r = sqrtuhr(USFRACT_MAX);
	if (r != USFRACT_MAX) exit(__LINE__);
	q = sqrthr(SFRACT_MAX);
	if (q != SFRACT_MAX) exit(__LINE__);

	r = sqrtuhr(USFRACT_EPSILON);
	if (r != 0.0625UHR) exit(__LINE__);
	q = sqrthr(SFRACT_EPSILON);
	if (q != 0.0859375HR) exit(__LINE__); /* one bit of precision less */

	r = sqrtuhr(0.5UHR);
	/* 8-bit representation of 1/sqrt(2) = 0.70710678... */
	if (r != 0.70703125UHR) exit(__LINE__);
	q = sqrthr(0.5HR);
	if (q != 0.7109375HR) exit(__LINE__);

	r = sqrtuhr(0.1UHR); /* 0.1UHR is 25/256=0.09765625HR */
	if (r != 0.3125UHR) exit(__LINE__);
	q = sqrthr(0.1HR); /* 0.1HR is 12/128=0.09375HR */
	if (q != 0.3046875HR) exit(__LINE__);

	r = sqrtuhr(0.9UHR);
	if (r != 0.9453125UHR) exit(__LINE__);
	q = sqrthr(0.9HR);
	if (q != 0.9453125HR) exit(__LINE__);
	return 0;
}
