/* Square root of unsigned long fract.
 *   unsigned long fract sqrtulr(unsigned long fract);
 */

#include "asmdef.h"

/* Reinterpret 32-bit unsigned long fract as a 64-bit value
 * provided in R25:R18, and call 64-bit integer square root.
 * The result is a 32-bit value in R25:R22.
*/

ENTRY sqrtulr
	clr    r18
	clr    r19
	clr    r20
	clr    r21
	XJMP   _U(__sqrtdi)
ENDFUNC

