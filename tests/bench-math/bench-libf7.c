#include <stdint.h>
#include <string.h>
#include <stdbool.h>
#include <stdlib.h>
#include <math.h>
#include <avr/pgmspace.h>

#include "avrtest.h"

#define STRY_(x) #x
#define STRY(x) STRY_(x)

#define FF long double

typedef struct
{
    FF d_max, x_max;
    uint32_t cycles_avr, cycles_max;
} result_t;

typedef struct
{
    uint32_t n_vals;
    FF lo, hi;
#if NARGS == 2 || NARGS == 22
    FF lo2, hi2;
#endif
} args_t;

#define NI __attribute__((__noipa__))

static NI FF addl (FF x, FF y) { return x + y; }
static NI FF subl (FF x, FF y) { return x - y; }
static NI FF mull (FF x, FF y) { return x * y; }
static NI FF divl (FF x, FF y) { return x / y; }
#define avrtest___builtin_powil avrtest_powil

void show_delta (FF x, FF y, FF z, FF z0, FF d, FF d10)
{
    (void) y;
    LOG_PFMT_LDOUBLE (PSTR("<!-- " STRY(FUNC) "(%e"), x);
#if NARGS == 2 || NARGS == 22
    LOG_PFMT_LDOUBLE (PSTR(", %e"), y);
#endif
    LOG_PFMT_LDOUBLE (PSTR(") = %e "), z);
    LOG_PFMT_LDOUBLE (PSTR("(z0=%e"), z0);
    LOG_PFMT_LDOUBLE (PSTR(",z-z0=%e)"), z-z0);
    LOG_PFMT_LDOUBLE (PSTR(": d=%e"), d);
    LOG_PFMT_LDOUBLE (PSTR(", d10=%e -->"), d10);
}

static FF rel_err (FF z, FF z0)
{
    FF ulp = avrtest_ulpl (z, z0);
    if (avrtest_cmpl (ulp, 0) == 0)
        return 0;
    FF d = avrtest_subl (z, z0);
    d = avrtest_divl (d, z0);
    return d;
}

#if NARGS == 2 || NARGS == 22
FF get_delta (FF x, FF y, uint32_t *cyc)
#else
FF get_delta (FF x, uint32_t *cyc)
#endif
{
    avrtest_cycles_call ();

#if NARGS == 1
    FF z = FUNC (x);
    *cyc = avrtest_cycles ();
    long double z0 = AFUNC (x);
#elif NARGS == 2
    FF z = FUNC (x, y);
    *cyc = avrtest_cycles ();
    long double z0 = AFUNC (x, y);
#elif NARGS == 11 // frexpf...
    int ii;
    FF z = FUNC (x, &ii);
    *cyc = avrtest_cycles ();
    long double z0 = AFUNC (x, &ii);
#elif NARGS == 12 // modff...
    FF y;
    long double ly;
    FF z = FUNC (x, &y);
    *cyc = avrtest_cycles ();
    long double z0 = AFUNC (x, &ly);
#elif NARGS == 22 // ldexp...
    int ex = (int) y;
    avrtest_cycles_call ();
    FF z = FUNC (x, ex);
    *cyc = avrtest_cycles ();
    long double z0 = AFUNC (x, ex);
#elif NARGS == 3 // sincos...
    {
        FF ss, cc;
        avrtest_cycles_call ();
        FUNC (x, &ss, &cc);
        *cyc = avrtest_cycles ();
        __asm ("" : "+r" (x));
        FF ss0 = avrtest_sinl (x);
        FF cc0 = avrtest_cosl (x);
        FF ds = rel_err (ss, ss0);
        FF dc = rel_err (cc, cc0);
        return avrtest_fabsl (ds) > avrtest_fabsl (dc) ? ds : dc;
    }
    FF z = 0, z0 = 0;
#else
#error NARGS=?
#endif

    return rel_err (z, z0);
}

__attribute__((const))
static bool is_int (FF x)
{
    return avrtest_cmpl (x, avrtest_roundl (x)) == 0;
}

static const char* fname (void)
{
    const char *s = STRY (FUNC);
    return 0?""
        : !strcmp_P (s, PSTR("addl")) ? "+"
        : !strcmp_P (s, PSTR("subl")) ? "&ndash;"
        : !strcmp_P (s, PSTR("mull")) ? "*"
        : !strcmp_P (s, PSTR("divl")) ? "/"
        : "#" STRY (FUNC);
}

static const char* fmt (FF x)
{
    if (is_int (x))
        return avrtest_cmpl (fabsl (x), 1000) <= 0
            ? PSTR(" <td> %.0f")
            : PSTR(" <td> %.0e");
    return PSTR(" <td> %.2f");
}

void print_result (const result_t *r, const args_t *a)
{
    LOG_PFMT_STR (PSTR("  <tr><td> \\c %s"), fname ());
    LOG_PFMT_U32 (PSTR(" <td align='right'> %u"), SIZE);
    LOG_PFMT_LDOUBLE (fmt (a->lo), a->lo);
    LOG_PFMT_LDOUBLE (fmt (a->hi), a->hi);
#if NARGS == 2 || NARGS == 22
    LOG_PFMT_LDOUBLE (fmt (a->lo2), a->lo2);
    LOG_PFMT_LDOUBLE (fmt (a->hi2), a->hi2);
#endif
    LOG_PFMT_U32 (PSTR(" <td align=\"right\"> %u"), r->cycles_avr);
    LOG_PFMT_U32 (PSTR(" <td align=\"right\"> %u"), r->cycles_max);
#ifdef EXACT
    if (avrtest_cmpl (r->d_max, 0) == 0)
    {
        LOG_PSTR (PSTR(" <td align=\"center\"> -&infin;\n"));
        return;
    }
#endif
    FF pe = avrtest_log10l (r->d_max);
    FF p0 = avrtest_log10l (0x1.0p-53);
    pe = avrtest_fmaxl (pe, p0);
    LOG_PFMT_LDOUBLE (PSTR(" <td align=\"center\"> %.2f"), pe);
    LOG_PSTR (PSTR("\n"));
}

void bench (result_t *r, const args_t *a)
{
    uint32_t cyc;
    uint64_t cycles = 0;

    for (uint32_t i = 0; i < a->n_vals; ++i)
    {
        FF x = avrtest_prandl (a->lo, a->hi);
#if NARGS == 2 || NARGS == 22
        FF y = avrtest_prandl (a->lo2, a->hi2);
        FF d = get_delta (x, y, &cyc);
#else
        FF d = get_delta (x, &cyc);
#endif
        if (cyc > r->cycles_max)
            r->cycles_max = cyc;
        cycles += cyc;

        d = fabsl (d);
        if (avrtest_cmpl (d, r->d_max) >= 0)
        {
            r->d_max = d;
            r->x_max = x;
        }

        //FF d10 = avrtest_log10l (d);
        FF d10 = avrtest_log10l (d);
        if (avrtest_cmpl (d10, -10) > 0)
#if NARGS == 1
            show_delta (x, 0, FUNC (x), AFUNC (x), d, d10);
#elif NARGS == 2
            show_delta (x, y, FUNC (x, y), AFUNC (x, y), d, d10);
#else
            {}
#endif
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

        a.lo = avrtest_strtold (end + 1, &end);
        if (*end != ',')  bad_pack (argv[i], end);
        a.hi = avrtest_strtold (end + 1, &end);
#if NARGS == 2 || NARGS == 22
        if (*end != ',')  bad_pack (argv[i], end);
        a.lo2 = avrtest_strtold (end + 1, &end);
        if (*end != ',')  bad_pack (argv[i], end);
        a.hi2 = avrtest_strtold (end + 1, &end);
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
            args.lo = avrtest_fminl (args.lo, a.lo);
            args.hi = avrtest_fmaxl (args.hi, a.hi);
#if NARGS == 2 || NARGS == 22
            args.lo2 = avrtest_fminl (args.lo2, a.lo2);
            args.hi2 = avrtest_fmaxl (args.hi2, a.hi2);
#endif
            if (r.cycles_max > R.cycles_max)
                R.cycles_max = r.cycles_max;
            if (avrtest_cmpl (r.d_max, R.d_max) > 0)
            {
                R.d_max = r.d_max;
                R.x_max = r.x_max;
            }
        }
    }

    print_result (&R, &args);

    return 0;
}
