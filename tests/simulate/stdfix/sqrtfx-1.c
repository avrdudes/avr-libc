#include <stdlib.h>

extern unsigned char __sqrthi (unsigned arg);

int main()
{
	int res = -1;
	res = __sqrthi(0);
	if (res != 0) exit(__LINE__);
	res = __sqrthi(1);
	if (res != 1) exit(__LINE__);
	res = __sqrthi(4);
	if (res != 2) exit(__LINE__);
	res = __sqrthi(9);
	if (res != 3) exit(__LINE__);
	res = __sqrthi(16);
	if (res != 4) exit(__LINE__);
	res = __sqrthi(25);
	if (res != 5) exit(__LINE__);
	res = __sqrthi(225);
	if (res != 15) exit(__LINE__);
	res = __sqrthi(256);
	if (res != 16) exit(__LINE__);
	res = __sqrthi(625);
	if (res != 25) exit(__LINE__);
	res = __sqrthi(16129);
	if (res != 127) exit(__LINE__);
	res = __sqrthi(16383);
	if (res != 127) exit(__LINE__);
	return 0;
}
