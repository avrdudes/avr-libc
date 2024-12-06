#include <limits.h>
#include <stdfix.h>
#include <stdlib.h>

int main(void) {
	unsigned long fract r;
	r = ulrdivi(0UL, 1UL);
	if (r != 0ulr)
		exit(__LINE__);

	/* saturated values */
	r = ulrdivi(1UL, 1UL);
	if (r != ULFRACT_MAX)
		exit(__LINE__);
	r = ulrdivi(2UL, 1UL);
	if (r != ULFRACT_MAX)
		exit(__LINE__);
	r = ulrdivi(ULONG_MAX - 1, 1);
	if (r != ULFRACT_MAX)
		exit(__LINE__);
	r = ulrdivi(ULONG_MAX, 1);
	if (r != ULFRACT_MAX)
		exit(__LINE__);
	r = ulrdivi(ULONG_MAX, ULONG_MAX);
	if (r != ULFRACT_MAX)
		exit(__LINE__);

	/* simple fractions */
	r = ulrdivi(1UL, 2UL);
	if (r != 0.5ulr)
		exit(__LINE__);
	r = ulrdivi(1UL, 4UL);
	if (r != 0.25ulr)
		exit(__LINE__);
	r = ulrdivi(1UL, ULONG_MAX);
	if (r != ULFRACT_EPSILON)
		exit(__LINE__);
	r = ulrdivi(ULONG_MAX - 1, ULONG_MAX);
	if (r != ULFRACT_MAX - ULFRACT_EPSILON)
		exit(__LINE__);

	/* selected fractions */
	r = ulrdivi(1UL, 3UL);
        if (r != 0.33333333325572311878204345703125ULR)
                exit(__LINE__);
        r = ulrdivi(1UL, 10UL);
        if (r != 0.09999999986030161380767822265625ULR)
                exit(__LINE__);

	return 0;

}
