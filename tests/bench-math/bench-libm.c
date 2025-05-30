#include <stdint.h>
#include <string.h>
#include <stdbool.h>
#include <stdlib.h>
#include <math.h>
#include <avr/pgmspace.h>

#include "avrtest.h"

#define STRY_(x) #x
#define STRY(x) STRY_(x)

typedef struct
{
    float d_max, x_max;
    uint32_t cycles_avr, cycles_max;
} result_t;

typedef struct
{
    uint32_t n_vals;
    float lo, hi;
#if NARGS == 2 || NARGS == 22
    float lo2, hi2;
#endif
} args_t;

extern float addf (float, float) __asm("__addsf3");
extern float subf (float, float) __asm("__subsf3");
extern float mulf (float, float) __asm("__mulsf3");
extern float divf (float, float) __asm("__divsf3");

#if NARGS == 2 || NARGS == 22
float get_delta (float x, float y, uint32_t *cyc)
#else
float get_delta (float x, uint32_t *cyc)
#endif
{
    avrtest_cycles_call ();

#if NARGS == 1
    float z = FUNC (x);
    *cyc = avrtest_cycles ();
    long double z0 = AFUNC (avrtest_ftol (x));
#elif NARGS == 2
    float z = FUNC (x, y);
    *cyc = avrtest_cycles ();
    long double z0 = AFUNC (avrtest_ftol (x), avrtest_ftol (y));
#elif NARGS == 11 // frexpf...
    int ii;
    float z = FUNC (x, &ii);
    *cyc = avrtest_cycles ();
    long double z0 = AFUNC (avrtest_ftol (x), &ii);
#elif NARGS == 12 // modff...
    float y;
    long double ly;
    float z = FUNC (x, &y);
    *cyc = avrtest_cycles ();
    long double z0 = AFUNC (avrtest_ftol (x), &ly);
#elif NARGS == 22 // ldexp...
    int ex = (int) y;
    avrtest_cycles_call ();
    float z = FUNC (x, ex);
    *cyc = avrtest_cycles ();
    long double z0 = AFUNC (avrtest_ftol (x), ex);
#else
#error NARGS=?
#endif

    float ulp = avrtest_ulpf (z, avrtest_ltof (z0));
    if (avrtest_cmpf (ulp, 0) == 0)
        return 0;
    long double d = avrtest_subl (avrtest_ftol (z), z0);
    d = avrtest_divl (d, z0);
    return avrtest_ltof (d);
}

__attribute__((const))
static bool is_int (float x)
{
    return x == roundf (x);
}

static const char* fname (void)
{
    const char *s = STRY (FUNC);
    return 0?""
        : !strcmp_P (s, PSTR("addf")) ? "+"
        : !strcmp_P (s, PSTR("subf")) ? "&ndash;"
        : !strcmp_P (s, PSTR("mulf")) ? "*"
        : !strcmp_P (s, PSTR("divf")) ? "/"
        : "#" STRY (FUNC);
}

static const char* fmt (float x)
{
    if (is_int (x))
        return avrtest_cmpf (fabsf (x), 1000) <= 0
            ? PSTR(" <td> %.0f")
            : PSTR(" <td> %.0e");
    return PSTR(" <td> %.2f");
}

void print_result (const result_t *r, const args_t *a)
{
    LOG_PFMT_STR (PSTR("  <tr><td> \\c %s"), fname ());
    LOG_PFMT_U32 (PSTR(" <td align='right'> %u"), SIZE);
    LOG_PFMT_FLOAT (fmt (a->lo), a->lo);
    LOG_PFMT_FLOAT (fmt (a->hi), a->hi);
#if NARGS == 2 || NARGS == 22
    LOG_PFMT_FLOAT (fmt (a->lo2), a->lo2);
    LOG_PFMT_FLOAT (fmt (a->hi2), a->hi2);
#endif
    LOG_PFMT_U32 (PSTR(" <td align=\"right\"> %u"), r->cycles_avr);
    LOG_PFMT_U32 (PSTR(" <td align=\"right\"> %u"), r->cycles_max);
#ifdef EXACT
    if (avrtest_cmpf (r->d_max, 0) == 0)
    {
        LOG_PSTR (PSTR(" <td align=\"center\"> -&infin;\n"));
        return;
    }
#endif
    float pe = avrtest_log10f (r->d_max);
    float p0 = avrtest_log10f (0x1.0p-24f);
    pe = avrtest_fmaxf (pe, p0);
    if (avrtest_cmpf (pe, -5.0f) <= 0)
        LOG_PFMT_FLOAT (PSTR(" <td align=\"center\"> %.2f"), pe);
    else
        LOG_PFMT_FLOAT (PSTR(" <td align=\"center\"> <b>%.2f</b>"), pe);
    LOG_PSTR (PSTR("\n"));
}

void bench (result_t *r, const args_t *a)
{
    uint32_t cyc;
    uint64_t cycles = 0;

    for (uint32_t i = 0; i < a->n_vals; ++i)
    {
        float x = avrtest_prandf (a->lo, a->hi);
#if NARGS == 2 || NARGS == 22
        float y = avrtest_prandf (a->lo2, a->hi2);
        float d = get_delta (x, y, &cyc);
#else
        float d = get_delta (x, &cyc);
#endif
        if (cyc > r->cycles_max)
            r->cycles_max = cyc;
        cycles += cyc;

        d = fabsf (d);
        if (avrtest_cmpf (d, r->d_max) >= 0)
        {
            r->d_max = d;
            r->x_max = x;
        }
    }

    r->cycles_avr = (uint32_t) avrtest_divu64 (cycles, a->n_vals);
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
    result_t R;
    args_t args;

    for (int i = 1; i < argc; ++i)
    {
        char *end;
        args_t a;
        result_t r;
        a.n_vals = strtoul (argv[i], &end, 10);
        if (*end != ',')  bad_pack (argv[i], end);
        a.n_vals *= TIMES;

        a.lo = avrtest_strtof (end + 1, &end);
        if (*end != ',')  bad_pack (argv[i], end);
        a.hi = avrtest_strtof (end + 1, &end);
#if NARGS == 2 || NARGS == 22
        if (*end != ',')  bad_pack (argv[i], end);
        a.lo2 = avrtest_strtof (end + 1, &end);
        if (*end != ',')  bad_pack (argv[i], end);
        a.hi2 = avrtest_strtof (end + 1, &end);
#endif
        if (*end != '\0')  bad_pack (argv[i], end);

        bench (&r, &a);

        if (i == 1)
        {
            R = r;
            args = a;
        }
        else
        {
            // More than one parameter pack: accumulate.
            // Take cycles_avr from the 1st pack, assuming that
            // the 1st interval is the relevant "big" master.
            args.lo = avrtest_fminf (args.lo, a.lo);
            args.hi = avrtest_fmaxf (args.hi, a.hi);
#if NARGS == 2 || NARGS == 22
            args.lo2 = avrtest_fminf (args.lo2, a.lo2);
            args.hi2 = avrtest_fmaxf (args.hi2, a.hi2);
#endif
            if (r.cycles_max > R.cycles_max)
                R.cycles_max = r.cycles_max;
            if (avrtest_cmpf (r.d_max, R.d_max) > 0)
            {
                R.d_max = r.d_max;
                R.x_max = r.x_max;
            }
        }
    }

    print_result (&R, &args);

    return 0;
}
