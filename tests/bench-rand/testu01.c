// https://simul.iro.umontreal.ca/testu01/tu01.html
// https://www.iro.umontreal.ca/~simardr/testu01/guideshorttestu01.pdf

#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>
#include <string.h>

// AVR-LibC's 31-bit do_random().
uint32_t alibc_random (uint32_t*);

// AVR-LibC v2.3's 15-bit do_rand().
// https://de.wikipedia.org/wiki/Xorshift
uint32_t alibc_rand (uint32_t*);

// AVR-LibC's up to v2.2.1.
uint32_t alibc_old_rand (uint32_t*);

#include "ulcg.h"
#include "unif01.h"
#include "bbattery.h"

// "Good" RNG generator, i.e. one that passes all bbattery_SmallCrush
// tests at least.  This is used to fill the vacant bits of RNGs that
// produce less than 32 bits.
unsigned good (void)
{
    static unif01_Gen *gen_good;
    if (!gen_good)
        gen_good = ulcg_CreateLCG ((1ul << 63) - 25, 2307085864, 0, 1);
    return gen_good->GetBits (gen_good->param, gen_good->state);
}

// Describes "mixing" of RNG values.
// Bits = 1 in mask tell which bits of the .rng() generator should be used.
// Bits = 0 in mask tell which bits are vacant and filled with good() values.
// Notice that less set bits in .mask yield better RNG performance since
// more bits are taken from the good() RNG.
// &.seed is passed to .rng().
typedef struct
{
    uint32_t mask;
    uint32_t (*rng)(uint32_t*);
    uint32_t seed;
    const char *name;
} mix_t;

mix_t *mix;

// Describes "mixing" of RNG values.
// Bits = 1 in mask tell which bits of the .rng() generator should be used.
// Bits = 0 in mask tell which bits are vacant and filled with good() values.
unsigned mix_rng (void)
{
    if (!mix)
        return good();

    const uint32_t mask = mix->mask;
    const uint32_t rr = mix->rng (& mix->seed);
    return (uint32_t) ((rr & mask) | (good() & ~mask));
}

// Some actual RNG's known to AVR-LibC now and then.
mix_t amix[] =
{
    { 0x7fffffff, alibc_random, 1,   "AVR-LibC random" },
    // Notes on failing TestU01's:
    // 8 MatrixRank:  Computes ranks of 60 x 60 matrices over GF(2) that are
    //         comprised of 10-bit chunks (bits 0xffc).  Most of the expected
    //         ranks have a small deficit of 0..2, but the new rand() has more
    //         linear dependencies and can only build matrices with much smaller
    //         ranks.
    { 0x7fff,     alibc_rand, 1,     "AVR-LibC rand" },
    { 0x7fff,     alibc_old_rand, 1, "AVR-LibC old rand" },
};

int main (int argc, char *argv[])
{
    int idx = 1;

    if (argc > 1)
    {
        const char *rng = argv[1];
        idx = 0?0
            : !strcmp (rng, "0") || !strcmp (rng, "random")  ? 0
            : !strcmp (rng, "1") || !strcmp (rng, "rand")    ? 1
            : !strcmp (rng, "2") || !strcmp (rng, "oldrand") ? 2
            : -1;
        if (idx < 0)
        {
            fprintf (stderr, "\nerror: unrecognized argv[1] = %s\n", rng);
            fprintf (stderr, "usage: make test TESTU01_HOME=<dir>"
                     " RNG=<rng> with <rng> in: random, rand, oldrand\n");
            exit (1);
        }
    }

    mix = &amix[idx];
    unif01_Gen *gen = unif01_CreateExternGenBits (mix->name, mix_rng);
    bbattery_SmallCrush (gen);
    unif01_DeleteExternGenBits (gen);

    return 0;
}


////////////////////////////////////////////////////////////////////////
// (Re-)Implementations of AVR-LibC's RNGs.


uint32_t alibc_random (uint32_t *ctx)
{
	/*
	 * Compute x = (7^5 * x) mod (2^31 - 1)
	 * wihout overflowing 31 bits:
	 *      (2^31 - 1) = 127773 * (7^5) + 2836
	 * From "Random number generators: good ones are hard to find",
	 * Park and Miller, Communications of the ACM, vol. 31, no. 10,
	 * October 1988, p. 1195.
	 */
	int32_t hi, lo, x;

	x = *ctx;
	/* Can't be initialized with 0, so use another value. */
	if (x == 0)
		x = 123459876L;
	hi = x / 127773L;
	lo = x % 127773L;
	x = 16807L * lo - 2836L * hi;
	if (x < 0)
		x += 0x7fffffffL;
	return *ctx = x;
}

#if 0
/* 1 + X^3 + X^5 + X^6 + X^7 + X^9 + X^10 + X^12 + X^15 + X^17 + X^19 + X^20 + X^21 + X^22 + X^24 */
#define POLY 0x17a96e9
#define DEGREE 24
#define ROOT 0x8b /* 1 + X + X^3 + X^7 */

typedef uint32_t poly;

#define MASK(b) \
	(((poly) 1) << (b))

static poly pprod (poly a, poly b)
{
    const poly mask = MASK (DEGREE);
    poly c = 0;

    while (b)
    {
        // Ist bit i in b gesetzt?
        if (b & 1)
            c ^= a;     // dann c += a * X^i
        a <<= 1;        // a *= X

        if (a & mask)   // a = a mod p
            a ^= POLY;

        b >>= 1;
    }

    return c & (mask - 1);
}

// Return in [0, 0x7fff].
uint32_t alibc_rand (poly *ctx)
{
    const poly mask = MASK (DEGREE);
    *ctx &= mask - 1;

    // Map ctx = 0 to something harmless.
    if (*ctx == 0)
        *ctx = 0xcc00;

    *ctx = pprod (*ctx, ROOT);

    // Involve all 24 bits in the result.
    uint8_t b2 = *ctx >> 16;
    uint32_t r = (*ctx ^ b2) + (b2 << 8);

    return r & 0x7fff;
}
#endif

//////////////////////////////////////////////////////////////////////////////

uint32_t alibc_old_rand (uint32_t *ctx)
{
    /*
     * Compute x = (7^5 * x) mod (2^31 - 1)
     * wihout overflowing 31 bits:
     *      (2^31 - 1) = 127773 * (7^5) + 2836
     * From "Random number generators: good ones are hard to find",
     * Park and Miller, Communications of the ACM, vol. 31, no. 10,
     * October 1988, p. 1195.
     */
    int32_t hi, lo, x;

    x = *ctx;
    /* Can't be initialized with 0, so use another value. */
    if (x == 0)
        x = 123459876L;
    hi = x / 127773L;
    lo = x % 127773L;
    x = 16807L * lo - 2836L * hi;
    if (x < 0)
        x += 0x7fffffffL;
    return (*ctx = x) % 0x8000;
}

// https://en.wikipedia.org/wiki/Xorshift
// The period of xorshift32 is 2^32 - 1.
uint32_t alibc_rand (uint32_t *ctx)
{
    uint32_t x = *ctx ? *ctx : 42 << 16;
    x ^= x << 13;
    x ^= x >> 17;
    x ^= x << 5;
    *ctx = x;
    return x & 0x7fff;
}
