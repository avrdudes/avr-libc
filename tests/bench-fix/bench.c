#include <stdio.h>
#include <stdfix.h>
#include <stdint.h>
#include <string.h>
#include <stdbool.h>
#include <stdarg.h>
#include <stdlib.h>
#include <math.h>

#include <avr/pgmspace.h>

#include "avrtest.h"

#define STRY_(x) #x
#define STRY(x) STRY_(x)

#define GLUE_(A, X, B) A ## X ## B
#define GLUE(A, X, B) GLUE_(A, X, B)

#define GLUE4_(A, X, B, C) A ## X ## B ## C
#define GLUE4(A, X, B, C) GLUE4_(A, X, B, C)

typedef accum k_t;
typedef unsigned accum uk_t;
typedef short accum hk_t;
typedef unsigned short accum uhk_t;
typedef fract r_t;
typedef unsigned fract ur_t;
typedef short fract hr_t;
typedef unsigned short fract uhr_t;

typedef GLUE(RET, _t, ) ret_t;

const int FBITk  = 15;
const int FBITuk = 16;
const int FBIThk  = 7;
const int FBITuhk = 8;
const int FBITr  = 15;
const int FBITur = 16;
const int FBIThr  = 7;
const int FBITuhr = 8;

#define FXFUNC GLUE(Func, Suffix, Suf2)
#define FXBITS GLUE(Suffix, bits, )
#define BITSFX GLUE(bits, Suffix, )

#define AFUNC  GLUE4(avrtest_, Func, Suf2, f)
#define FXTOF  GLUE(avrtest_, Suffix, tof)
#define RXTOF  GLUE(avrtest_, RET, tof)
#define FTOFX  GLUE(avrtest_, fto, Suffix)

#define FBIT GLUE(FBIT, Suffix, )

typedef GLUE(Suffix, _t, ) fx_t;
#if SIGNED == 1
typedef GLUE(int_,  Suffix, _t) fxint_t;
#else
typedef GLUE(uint_, Suffix, _t) fxint_t;
#endif

static ret_t fxfunc (fx_t x)
{
    return FXFUNC (x);
}

float avrtest_exp2f (float x)
{
    return avrtest_powf (2, x);
}

float avrtest_exp2m1f (float x)
{
    return avrtest_subf (avrtest_powf (2, x), 1);
}

float avrtest_log21pf (float x)
{
    return avrtest_log2f (avrtest_addf (1, x));
}

float avrtest_cospi2f (float x)
{
    return avrtest_cosf (avrtest_mulf (x, M_PI_2));
}

float avrtest_sinpi2f (float x)
{
    return avrtest_sinf (avrtest_mulf (x, M_PI_2));
}

float avrtest_sin_degf (float x)
{
    return avrtest_sinf (avrtest_mulf (x, M_PI / 180));
}

float avrtest_cos_degf (float x)
{
    return avrtest_cosf (avrtest_mulf (x, M_PI / 180));
}

typedef struct
{
    float d_max;
    fx_t x_max;
    uint32_t cycles_avr, cycles_max;
} result_t;

typedef struct
{
    uint32_t n_vals;
    fx_t lo, hi;
    char *s_lo, *s_hi;
} args_t;


float get_delta (fx_t x, uint32_t *cyc)
{
    avrtest_cycles_call ();

    ret_t z = fxfunc (x);
    *cyc = avrtest_cycles ();
    float z0 = AFUNC (FXTOF (x));

    float d = avrtest_subf (RXTOF (z), z0);
    return d;
}


void print_result (const result_t *r, const args_t *a)
{
    LOG_PFMT_U32 (PSTR("cyc_avr=%u\n"), r->cycles_avr);
    LOG_PFMT_U32 (PSTR("cyc_max=%u\n"), r->cycles_max);
    LOG_PFMT_FLOAT (PSTR("d_max=%.2e\n"), r->d_max);
}


fx_t fxrand (fx_t lo, fx_t hi)
{
    float f = avrtest_prandf (FXTOF (lo), FXTOF (hi));
    fx_t x = FTOFX (f);
    if (x < lo) return lo;
    if (x > hi) return hi;
    return x;
}

void bench (result_t *r, const args_t *a)
{
    uint32_t cyc;
    uint32_t cycles = 0;

    for (uint32_t i = 0; i < a->n_vals; ++i)
    {
        fx_t x = fxrand (a->lo, a->hi);
        float d = get_delta (x, &cyc);

        if (cyc > r->cycles_max)
            r->cycles_max = cyc;
        cycles += cyc;

        d = fabsf (d);
        if (0 && avrtest_cmpf (d, 1) > 0)
        {
            LOG_FMT_U32 ("x=0x%x\n", BITSFX (x));
            LOG_FMT_FLOAT ("x=%e\n", FXTOF (x));
            ret_t y = fxfunc (x);
            LOG_FMT_U32 ("y=0x%x\n", BITSFX (y));
            LOG_FMT_FLOAT ("y=%e\n", RXTOF (y));
            LOG_FMT_FLOAT ("z=%e\n", AFUNC (FXTOF (x)));
            __builtin_abort();
        }
        if (avrtest_cmpf (d, r->d_max) >= 0)
        {
            r->d_max = d;
            r->x_max = x;
        }
    }

    r->cycles_avr = avrtest_divu32 (cycles, a->n_vals);
}


void error (const char *msg, ...)
{
    va_list args;
    va_start (args, msg);
    fprintf (stderr, "\nerror: ");
    vfprintf (stderr, msg, args);
    fprintf (stderr, "\n");
    va_end (args);

    exit (1);
}

/* Recognize sum of 2 terms: 1st is float, 2nd is int (fx as bits).
   For example, the smallest fixed > 0 can be written as "0+1" or "0+0x1". */

fx_t static get_fixed (const char *arg)
{
    char *end;
    float f = avrtest_strtof (arg, &end);
    if (end == arg)
        error ("unrecognized fixed %s: %s\n", arg, end);

    fx_t x = FTOFX (f);

    if (end[0] == '+' && end[1] == 0)
        x = FXBITS (BITSFX (x) + 1);
    else if (end[0] == '-' && end[1] == 0)
        x = FXBITS (BITSFX (x) - 1);
    else if (end[0])
        error ("unrecognized fixed %s: %s\n", arg, end);

    return x;
}


__attribute__((noreturn))
void bad_pack (const char *s, const char *end)
{
    LOG_PFMT_STR (PSTR("error: %s "), STRY (FUNC));
    LOG_PFMT_STR (PSTR("bad parameter pack \"%s\": "), s);
    LOG_PFMT_STR (PSTR("%s\n"), end);
    exit (__LINE__);
}

int main (int argc , char *argv[])
{
    args_t a;
    result_t r;
    a.n_vals = TIMES;

    if (argc != 3)
        error ("argc = %d", argc);
    a.s_lo = argv[1];
    a.s_hi = argv[2];
    a.lo = get_fixed (a.s_lo);
    a.hi = get_fixed (a.s_hi);

    bench (&r, &a);

    print_result (&r, &a);

    return 0;
}
