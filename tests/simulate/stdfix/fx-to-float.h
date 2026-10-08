typedef float DD;

typedef long long _Fract dq_t;
typedef long long _Accum ta_t;
typedef long _Accum da_t;
typedef unsigned long long _Fract udq_t;
typedef unsigned long long _Accum uta_t;
typedef unsigned long _Accum uda_t;

#define NI __attribute__((noipa))

#define MK_CONV(T)				\
  NI DD T##2d (T##_t x)				\
  {						\
    __asm ("" : "+r" (x));			\
    return (DD) x;				\
  }						\
						\
  NI T##_t d2##T (DD x)				\
  {						\
    __asm ("" : "+r" (x));			\
    return (T##_t) x;				\
  }

MK_CONV (da)
MK_CONV (ta)
MK_CONV (dq)

MK_CONV (uda)
MK_CONV (uta)
MK_CONV (udq)

#define dqbits(x) llrbits (x)
#define dabits(x) lkbits (x)
#define tabits(x) llkbits (x)

#define udqbits(x) ullrbits (x)
#define udabits(x) ulkbits (x)
#define utabits(x) ullkbits (x)
