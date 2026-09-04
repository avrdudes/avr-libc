#ifndef FX_DEFS_H
#define FX_DEFS_H

#include <stdfix.h>

#define GLUE2_(A, B) A ## B
#define GLUE2(A, B) GLUE2_(A, B)

#define GLUE3_(A, B, C) A ## B ## C
#define GLUE3(A, B, C) GLUE3_(A, B, C)

typedef uint_uk_t int_uk_t;
typedef uint_ur_t int_ur_t;
typedef uint_uhk_t int_uhk_t;
typedef uint_uhr_t int_uhr_t;
typedef uint_ulk_t int_ulk_t;
typedef uint_ulr_t int_ulr_t;
typedef uint_ullk_t int_ullk_t;
typedef uint_ullr_t int_ullr_t;

typedef uint_uk_t uint_k_t;
typedef uint_ur_t uint_r_t;
typedef uint_uhk_t uint_hk_t;
typedef uint_uhr_t uint_hr_t;
typedef uint_ulk_t uint_lk_t;
typedef uint_ulr_t uint_lr_t;
typedef uint_ullk_t uint_llk_t;
typedef uint_ullr_t uint_llr_t;

typedef long long accum llk_t;
typedef unsigned long long accum ullk_t;
typedef long accum lk_t;
typedef unsigned long accum ulk_t;
typedef accum k_t;
typedef unsigned accum uk_t;
typedef short accum hk_t;
typedef unsigned short accum uhk_t;

typedef long long fract llr_t;
typedef unsigned long long fract ullr_t;
typedef long fract lr_t;
typedef unsigned long fract ulr_t;
typedef fract r_t;
typedef unsigned fract ur_t;
typedef short fract hr_t;
typedef unsigned short fract uhr_t;

typedef GLUE2 (FX, _t) fx_t;
typedef GLUE3 (int_,  FX, _t) int_t;
typedef GLUE3 (uint_, FX, _t) uint_t;
#define fxbits(x) GLUE3 (__builtin_avr_, FX, bits) (x)
#define bitsfx(x) GLUE2 (__builtin_avr_bits, FX) (x)
#define fx(x) GLUE2 (x, FX)
#define FMT GLUE2 (FMT, FX)

// For LOG_FMT
#define FMTuhr "02x"
#define FMThr  "02x"
#define FMTuhk "04x"
#define FMThk  "04x"
#define FMTur  "04x"
#define FMTr   "04x"
#define FMTuk  "08x"
#define FMTk   "08x"
#define FMTulr "08x"
#define FMTlr  "08x"
#define FMTulk  "016llx"
#define FMTlk   "016llx"
#define FMTullk "016llx"
#define FMTllk  "016llx"
#define FMTullr "016llx"
#define FMTllr  "016llx"

#define SBIThr  1
#define SBIThk  1
#define SBITr   1
#define SBITk   1
#define SBITlr  1
#define SBITlk  1
#define SBITllk 1
#define SBITllr 1
#define SBITuhr  0
#define SBITuhk  0
#define SBITur   0
#define SBITuk   0
#define SBITulr  0
#define SBITulk  0
#define SBITullk 0
#define SBITullr 0


#define FBIThr  7
#define FBIThk  7
#define FBITr   15
#define FBITk   15
#define FBITlr  31
#define FBITlk  31
#define FBITllk 47
#define FBITllr 63
#define FBITuhr  8
#define FBITuhk  8
#define FBITur   16
#define FBITuk   16
#define FBITulr  32
#define FBITulk  32
#define FBITullk 48
#define FBITullr 64

#define MINhr  fxbits (0x80)
#define MINhk  fxbits (0x8000)
#define MINr   fxbits (0x8000)
#define MINk   fxbits (0x80000000)
#define MINlr  fxbits (0x80000000)
#define MINlk  fxbits (0x8000000000000000)
#define MINllk fxbits (0x8000000000000000)
#define MINllr fxbits (0x8000000000000000)
#define MINuhr  fxbits (0)
#define MINuhk  fxbits (0)
#define MINur   fxbits (0)
#define MINuk   fxbits (0)
#define MINulr  fxbits (0)
#define MINulk  fxbits (0)
#define MINullk fxbits (0)
#define MINullr fxbits (0)

#define MAXhr  fxbits (0x7f)
#define MAXhk  fxbits (0x7fff)
#define MAXr   fxbits (0x7fff)
#define MAXk   fxbits (0x7fffffff)
#define MAXlr  fxbits (0x7fffffff)
#define MAXlk  fxbits (0x7fffffffffffffff)
#define MAXllk fxbits (0x7fffffffffffffff)
#define MAXllr fxbits (0x7fffffffffffffff)
#define MAXuhr  fxbits (0xff)
#define MAXuhk  fxbits (0xffff)
#define MAXur   fxbits (0xffff)
#define MAXuk   fxbits (0xffffffff)
#define MAXulr  fxbits (0xffffffff)
#define MAXulk  fxbits (0xffffffffffffffff)
#define MAXullk fxbits (0xffffffffffffffff)
#define MAXullr fxbits (0xffffffffffffffff)

#define NBITShr  8
#define NBITShk  16
#define NBITSr   16
#define NBITSk   32
#define NBITSlr  32
#define NBITSlk  64
#define NBITSllk 64
#define NBITSllr 64
#define NBITSuhr  8
#define NBITSuhk  16
#define NBITSur   16
#define NBITSuk   32
#define NBITSulr  32
#define NBITSulk  64
#define NBITSullk 64
#define NBITSullr 64

#define MASKhr  0xff
#define MASKhk  0xffff
#define MASKr   0xffff
#define MASKk   0xffffffff
#define MASKlr  0xffffffff
#define MASKlk  0xffffffffffffffff
#define MASKllk 0xffffffffffffffff
#define MASKllr 0xffffffffffffffff
#define MASKuhr  0xff
#define MASKuhk  0xffff
#define MASKur   0xffff
#define MASKuk   0xffffffff
#define MASKulr  0xffffffff
#define MASKulk  0xffffffffffffffff
#define MASKullk 0xffffffffffffffff
#define MASKullr 0xffffffffffffffff

#define SBIT    GLUE2 (SBIT, FX)
#define FBIT    GLUE2 (FBIT, FX)
#define NBIT    GLUE2 (NBITS, FX)
#define IBIT    (NBIT - SBIT - FBIT)
#define MINfx   GLUE2 (MIN, FX)
#define MAXfx   GLUE2 (MAX, FX)
#define MASKfx  GLUE2 (MASK, FX)

#endif /* FX_DEFS_H */
