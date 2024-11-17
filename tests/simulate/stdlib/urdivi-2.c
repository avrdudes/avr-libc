#include <limits.h>
#include <stdfix.h>
#include <stdlib.h>

/* Test urdivi() function on 100 randomly generated test cases. */

int main(void) {
	unsigned fract r;
	r = urdivi(1236U, 2432U);
	if (r != 0.508209228515625UR)
		exit(__LINE__);
	r = urdivi(2236U, 16586U);
	if (r != 0.1348114013671875UR)
		exit(__LINE__);
	r = urdivi(16443U, 36963U);
	if (r != 0.4448394775390625UR)
		exit(__LINE__);
	r = urdivi(33623U, 37309U);
	if (r != 0.9011993408203125UR)
		exit(__LINE__);
	r = urdivi(2919U, 3546U);
	if (r != 0.8231658935546875UR)
		exit(__LINE__);
	r = urdivi(17664U, 43283U);
	if (r != 0.4080963134765625UR)
		exit(__LINE__);
	r = urdivi(35271U, 40338U);
	if (r != 0.8743743896484375UR)
		exit(__LINE__);
	r = urdivi(23223U, 41558U);
	if (r != 0.558807373046875UR)
		exit(__LINE__);
	r = urdivi(16861U, 19088U);
	if (r != 0.8833160400390625UR)
		exit(__LINE__);
	r = urdivi(4424U, 4866U);
	if (r != 0.9091644287109375UR)
		exit(__LINE__);
	r = urdivi(23874U, 29106U);
	if (r != 0.8202362060546875UR)
		exit(__LINE__);
	r = urdivi(14433U, 50410U);
	if (r != 0.2863006591796875UR)
		exit(__LINE__);
	r = urdivi(29879U, 39913U);
	if (r != 0.74859619140625UR)
		exit(__LINE__);
	r = urdivi(25692U, 48442U);
	if (r != 0.530364990234375UR)
		exit(__LINE__);
	r = urdivi(52506U, 56889U);
	if (r != 0.922943115234375UR)
		exit(__LINE__);
	r = urdivi(4053U, 14610U);
	if (r != 0.27740478515625UR)
		exit(__LINE__);
	r = urdivi(28887U, 32216U);
	if (r != 0.8966522216796875UR)
		exit(__LINE__);
	r = urdivi(5008U, 8238U);
	if (r != 0.60791015625UR)
		exit(__LINE__);
	r = urdivi(2674U, 14500U);
	if (r != 0.1844024658203125UR)
		exit(__LINE__);
	r = urdivi(20808U, 25695U);
	if (r != 0.8097991943359375UR)
		exit(__LINE__);
	r = urdivi(17266U, 24608U);
	if (r != 0.701629638671875UR)
		exit(__LINE__);
	r = urdivi(34076U, 53635U);
	if (r != 0.6353302001953125UR)
		exit(__LINE__);
	r = urdivi(5659U, 18222U);
	if (r != 0.310546875UR)
		exit(__LINE__);
	r = urdivi(16228U, 19828U);
	if (r != 0.8184356689453125UR)
		exit(__LINE__);
	r = urdivi(8158U, 55806U);
	if (r != 0.14617919921875UR)
		exit(__LINE__);
	r = urdivi(25968U, 51448U);
	if (r != 0.504730224609375UR)
		exit(__LINE__);
	r = urdivi(41632U, 64761U);
	if (r != 0.642852783203125UR)
		exit(__LINE__);
	r = urdivi(33693U, 60609U);
	if (r != 0.5558929443359375UR)
		exit(__LINE__);
	r = urdivi(175U, 58879U);
	if (r != 0.002960205078125UR)
		exit(__LINE__);
	r = urdivi(14147U, 45411U);
	if (r != 0.3115234375UR)
		exit(__LINE__);
	r = urdivi(364U, 41415U);
	if (r != 0.0087890625UR)
		exit(__LINE__);
	r = urdivi(31810U, 64358U);
	if (r != 0.4942626953125UR)
		exit(__LINE__);
	r = urdivi(32810U, 40357U);
	if (r != 0.81298828125UR)
		exit(__LINE__);
	r = urdivi(1424U, 18267U);
	if (r != 0.07794189453125UR)
		exit(__LINE__);
	r = urdivi(18070U, 27948U);
	if (r != 0.64654541015625UR)
		exit(__LINE__);
	r = urdivi(3746U, 22881U);
	if (r != 0.1637115478515625UR)
		exit(__LINE__);
	r = urdivi(15608U, 37359U);
	if (r != 0.4177703857421875UR)
		exit(__LINE__);
	r = urdivi(16928U, 23647U);
	if (r != 0.715850830078125UR)
		exit(__LINE__);
	r = urdivi(46055U, 46427U);
	if (r != 0.991973876953125UR)
		exit(__LINE__);
	r = urdivi(9575U, 18857U);
	if (r != 0.5077667236328125UR)
		exit(__LINE__);
	r = urdivi(394U, 24182U);
	if (r != 0.0162811279296875UR)
		exit(__LINE__);
	r = urdivi(33481U, 47283U);
	if (r != 0.7080841064453125UR)
		exit(__LINE__);
	r = urdivi(14162U, 18967U);
	if (r != 0.7466583251953125UR)
		exit(__LINE__);
	r = urdivi(1263U, 3894U);
	if (r != 0.3243408203125UR)
		exit(__LINE__);
	r = urdivi(27535U, 51433U);
	if (r != 0.5353546142578125UR)
		exit(__LINE__);
	r = urdivi(38886U, 57151U);
	if (r != 0.6804046630859375UR)
		exit(__LINE__);
	r = urdivi(3837U, 28824U);
	if (r != 0.13311767578125UR)
		exit(__LINE__);
	r = urdivi(53782U, 60011U);
	if (r != 0.8961944580078125UR)
		exit(__LINE__);
	r = urdivi(8121U, 12561U);
	if (r != 0.646514892578125UR)
		exit(__LINE__);
	r = urdivi(7236U, 42187U);
	if (r != 0.1715087890625UR)
		exit(__LINE__);
	r = urdivi(1627U, 1781U);
	if (r != 0.9135284423828125UR)
		exit(__LINE__);
	r = urdivi(5167U, 34313U);
	if (r != 0.15057373046875UR)
		exit(__LINE__);
	r = urdivi(5822U, 9142U);
	if (r != 0.6368408203125UR)
		exit(__LINE__);
	r = urdivi(12399U, 21205U);
	if (r != 0.584716796875UR)
		exit(__LINE__);
	r = urdivi(14632U, 15281U);
	if (r != 0.95751953125UR)
		exit(__LINE__);
	r = urdivi(20093U, 34763U);
	if (r != 0.5779876708984375UR)
		exit(__LINE__);
	r = urdivi(44331U, 63219U);
	if (r != 0.7012176513671875UR)
		exit(__LINE__);
	r = urdivi(8217U, 48726U);
	if (r != 0.1686248779296875UR)
		exit(__LINE__);
	r = urdivi(3238U, 16816U);
	if (r != 0.1925506591796875UR)
		exit(__LINE__);
	r = urdivi(14023U, 27026U);
	if (r != 0.51885986328125UR)
		exit(__LINE__);
	r = urdivi(27812U, 33527U);
	if (r != 0.82952880859375UR)
		exit(__LINE__);
	r = urdivi(10336U, 12030U);
	if (r != 0.8591766357421875UR)
		exit(__LINE__);
	r = urdivi(43594U, 48114U);
	if (r != 0.9060516357421875UR)
		exit(__LINE__);
	r = urdivi(7869U, 11117U);
	if (r != 0.70782470703125UR)
		exit(__LINE__);
	r = urdivi(43247U, 63808U);
	if (r != 0.677764892578125UR)
		exit(__LINE__);
	r = urdivi(2292U, 13699U);
	if (r != 0.16729736328125UR)
		exit(__LINE__);
	r = urdivi(12472U, 63950U);
	if (r != 0.1950225830078125UR)
		exit(__LINE__);
	r = urdivi(3755U, 10730U);
	if (r != 0.349945068359375UR)
		exit(__LINE__);
	r = urdivi(269U, 638U);
	if (r != 0.4216156005859375UR)
		exit(__LINE__);
	r = urdivi(6698U, 31469U);
	if (r != 0.21282958984375UR)
		exit(__LINE__);
	r = urdivi(21054U, 24173U);
	if (r != 0.8709716796875UR)
		exit(__LINE__);
	r = urdivi(2482U, 15347U);
	if (r != 0.161712646484375UR)
		exit(__LINE__);
	r = urdivi(3972U, 46642U);
	if (r != 0.08514404296875UR)
		exit(__LINE__);
	r = urdivi(1669U, 8647U);
	if (r != 0.1930084228515625UR)
		exit(__LINE__);
	r = urdivi(7241U, 52803U);
	if (r != 0.1371307373046875UR)
		exit(__LINE__);
	r = urdivi(10818U, 34228U);
	if (r != 0.3160552978515625UR)
		exit(__LINE__);
	r = urdivi(31321U, 43508U);
	if (r != 0.719879150390625UR)
		exit(__LINE__);
	r = urdivi(21932U, 36866U);
	if (r != 0.59490966796875UR)
		exit(__LINE__);
	r = urdivi(15238U, 64278U);
	if (r != 0.237060546875UR)
		exit(__LINE__);
	r = urdivi(7850U, 20702U);
	if (r != 0.379180908203125UR)
		exit(__LINE__);
	r = urdivi(23287U, 29803U);
	if (r != 0.7813568115234375UR)
		exit(__LINE__);
	r = urdivi(16359U, 26063U);
	if (r != 0.6276702880859375UR)
		exit(__LINE__);
	r = urdivi(46673U, 64458U);
	if (r != 0.7240753173828125UR)
		exit(__LINE__);
	r = urdivi(15804U, 45799U);
	if (r != 0.345062255859375UR)
		exit(__LINE__);
	r = urdivi(34698U, 35877U);
	if (r != 0.967132568359375UR)
		exit(__LINE__);
	r = urdivi(12959U, 40039U);
	if (r != 0.3236541748046875UR)
		exit(__LINE__);
	r = urdivi(52000U, 55674U);
	if (r != 0.9340057373046875UR)
		exit(__LINE__);
	r = urdivi(17259U, 26642U);
	if (r != 0.647796630859375UR)
		exit(__LINE__);
	r = urdivi(3250U, 28086U);
	if (r != 0.1157073974609375UR)
		exit(__LINE__);
	r = urdivi(36334U, 57178U);
	if (r != 0.6354522705078125UR)
		exit(__LINE__);
	r = urdivi(266U, 17600U);
	if (r != 0.015106201171875UR)
		exit(__LINE__);
	r = urdivi(15956U, 38537U);
	if (r != 0.414031982421875UR)
		exit(__LINE__);
	r = urdivi(13435U, 33976U);
	if (r != 0.395416259765625UR)
		exit(__LINE__);
	r = urdivi(5012U, 6619U);
	if (r != 0.7572021484375UR)
		exit(__LINE__);
	r = urdivi(15775U, 45315U);
	if (r != 0.348114013671875UR)
		exit(__LINE__);
	r = urdivi(8375U, 27925U);
	if (r != 0.299896240234375UR)
		exit(__LINE__);
	r = urdivi(8922U, 33961U);
	if (r != 0.2627105712890625UR)
		exit(__LINE__);
	r = urdivi(21203U, 26085U);
	if (r != 0.812835693359375UR)
		exit(__LINE__);
	r = urdivi(1956U, 3261U);
	if (r != 0.5998077392578125UR)
		exit(__LINE__);
	r = urdivi(857U, 1416U);
	if (r != 0.605224609375UR)
		exit(__LINE__);
	return 0;
}

