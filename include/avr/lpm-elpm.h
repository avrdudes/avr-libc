#ifndef __LPM_ELPM_H_
#define __LPM_ELPM_H_

/* This header provides low-level macros for other parts of AVR-LibC
   that read from program memory by means of inline assembly that
   uses LPM and ELPM instructions.  */

/* Historically, avr/pgmspace.h used asm volatile in definitions of
   macros like pgm_read_byte(), though that's not required since there
   are no hidden side effects in them.  Though volatile may avoid
   undesired code reordering against (volatile) I/O accesses.  */

#ifndef __LPM_VOLATILE
#define __LPM_VOLATILE __volatile__
#endif

#ifndef __ELPM_VOLATILE
#define __ELPM_VOLATILE __volatile__
#endif

#if defined(__AVR_TINY__)
/* For Reduced Tiny devices, avr-gcc adds 0x4000 when it takes the address
   of a __progmem__ object.  This means we can use open coded C/C++ to read
   from progmem.  This assumes we have
   - GCC PR71948 - Make progmem work on Reduced Tiny (GCC v7 / 2016-08)  */
#define __LPM__1(res, addr)  res = *addr
#define __LPM__2(res, addr)  res = *addr
#define __LPM__3(res, addr)  res = *addr
#define __LPM__4(res, addr)  res = *addr
#define __LPM__8(res, addr)  res = *addr

#elif defined(__AVR_HAVE_LPMX__)
#define __LPM__1(res, addr)                             \
  __asm __LPM_VOLATILE ("lpm %0,%a1"                    \
                        : "=r" (res) : "z" (addr))

#define __LPM__2(res, addr)                               \
  __asm __LPM_VOLATILE ("lpm %A0,%a1+"            "\n\t"  \
                        "lpm %B0,%a1+"                    \
                        : "=r" (res), "+z" (addr))

#define __LPM__3(res, addr)                               \
  __asm __LPM_VOLATILE ("lpm %A0,%a1+"            "\n\t"  \
                        "lpm %B0,%a1+"            "\n\t"  \
                        "lpm %C0,%a1+"                    \
                        : "=r" (res), "+z" (addr))

#define __LPM__4(res, addr)                               \
  __asm __LPM_VOLATILE ("lpm %A0,%a1+"            "\n\t"  \
                        "lpm %B0,%a1+"            "\n\t"  \
                        "lpm %C0,%a1+"            "\n\t"  \
                        "lpm %D0,%a1+"                    \
                        : "=r" (res), "+z" (addr))

#define __LPM__8(res, addr)                               \
  __asm __LPM_VOLATILE ("lpm %r0+0,%a1+"          "\n\t"  \
                        "lpm %r0+1,%a1+"          "\n\t"  \
                        "lpm %r0+2,%a1+"          "\n\t"  \
                        "lpm %r0+3,%a1+"          "\n\t"  \
                        "lpm %r0+4,%a1+"          "\n\t"  \
                        "lpm %r0+5,%a1+"          "\n\t"  \
                        "lpm %r0+6,%a1+"          "\n\t"  \
                        "lpm %r0+7,%a1+"                  \
                        : "=r" (res), "+z" (addr))
#else /* Has no LPMx and no Reduced Tiny => Has LPM.  */
#define __LPM__1(res, addr)                                     \
  __asm __LPM_VOLATILE ("lpm $ mov %A0,r0"                      \
                        : "=r" (res) : "z" (addr) : "r0")

#define __LPM__2(res, addr)                                     \
  __asm __LPM_VOLATILE ("lpm $ mov %A0,r0 $ adiw %1,1"  "\n\t"  \
                        "lpm $ mov %B0,r0"                      \
                        : "=r" (res), "+z" (addr) :: "r0")

#define __LPM__3(res, addr)                                     \
  __asm __LPM_VOLATILE ("lpm $ mov %A0,r0 $ adiw %1,1"  "\n\t"  \
                        "lpm $ mov %B0,r0 $ adiw %1,1"  "\n\t"  \
                        "lpm $ mov %C0,r0"                      \
                        : "=r" (res), "+z" (addr) :: "r0")

#define __LPM__4(res, addr)                                     \
  __asm __LPM_VOLATILE ("lpm $ mov %A0,r0 $ adiw %1,1"  "\n\t"  \
                        "lpm $ mov %B0,r0 $ adiw %1,1"  "\n\t"  \
                        "lpm $ mov %C0,r0 $ adiw %1,1"  "\n\t"  \
                        "lpm $ mov %D0,r0"                      \
                        : "=r" (res), "+z" (addr) :: "r0")

#define __LPM__8(res, addr)                                       \
  __asm __LPM_VOLATILE ("lpm $ mov %r0+0,r0 $ adiw %1,1"  "\n\t"  \
                        "lpm $ mov %r0+1,r0 $ adiw %1,1"  "\n\t"  \
                        "lpm $ mov %r0+2,r0 $ adiw %1,1"  "\n\t"  \
                        "lpm $ mov %r0+3,r0 $ adiw %1,1"  "\n\t"  \
                        "lpm $ mov %r0+4,r0 $ adiw %1,1"  "\n\t"  \
                        "lpm $ mov %r0+5,r0 $ adiw %1,1"  "\n\t"  \
                        "lpm $ mov %r0+6,r0 $ adiw %1,1"  "\n\t"  \
                        "lpm $ mov %r0+7,r0"                      \
                        : "=r" (res), "+z" (addr) :: "r0")
#endif /* LPM cases */


#if defined(__AVR_HAVE_ELPMX__)

#ifdef __AVR_HAVE_RAMPD__
/* For devices with EBI, reset RAMPZ to zero after.  */
#define __pgm_clr_RAMPZ_ "\n\t" "out  %i2,__zero_reg__"
#else
/* Devices without EBI: no need to reset RAMPZ.  */
#define __pgm_clr_RAMPZ_ /* empty */
#endif

#define __ELPM__1(res, addr, T)                         \
  __asm __ELPM_VOLATILE ("movw r30,%1"         "\n\t"   \
                         "out  %i2,%C1"        "\n\t"   \
                         "elpm %A0,Z"                   \
                         __pgm_clr_RAMPZ_               \
                         : "=r" (res)                   \
                         : "r" (addr), "n" (& RAMPZ)    \
                         : "r30", "r31")

#define __ELPM__2(res, addr, T)                         \
  __asm __ELPM_VOLATILE ("movw r30,%1"         "\n\t"   \
                         "out  %i2,%C1"        "\n\t"   \
                         "elpm %A0,Z+"         "\n\t"   \
                         "elpm %B0,Z+"                  \
                         __pgm_clr_RAMPZ_               \
                         : "=r" (res)                   \
                         : "r" (addr), "n" (& RAMPZ)    \
                         : "r30", "r31")

#define __ELPM__3(res, addr, T)                         \
  __asm __ELPM_VOLATILE ("movw r30,%1"         "\n\t"   \
                         "out  %i2,%C1"        "\n\t"   \
                         "elpm %A0,Z+"         "\n\t"   \
                         "elpm %B0,Z+"         "\n\t"   \
                         "elpm %C0,Z+"                  \
                         __pgm_clr_RAMPZ_               \
                         : "=r" (res)                   \
                         : "r" (addr), "n" (& RAMPZ)    \
                         : "r30", "r31")

#define __ELPM__4(res, addr, T)                         \
  __asm __ELPM_VOLATILE ("movw r30,%1"         "\n\t"   \
                         "out  %i2,%C1"        "\n\t"   \
                         "elpm %A0,Z+"         "\n\t"   \
                         "elpm %B0,Z+"         "\n\t"   \
                         "elpm %C0,Z+"         "\n\t"   \
                         "elpm %D0,Z+"                  \
                         __pgm_clr_RAMPZ_               \
                         : "=r" (res)                   \
                         : "r" (addr), "n" (& RAMPZ)    \
                         : "r30", "r31")

#define __ELPM__8(res, addr, T)                         \
  __asm __ELPM_VOLATILE ("movw r30,%1"         "\n\t"   \
                         "out  %i2,%C1"        "\n\t"   \
                         "elpm %r0+0,Z+"       "\n\t"   \
                         "elpm %r0+1,Z+"       "\n\t"   \
                         "elpm %r0+2,Z+"       "\n\t"   \
                         "elpm %r0+3,Z+"       "\n\t"   \
                         "elpm %r0+4,Z+"       "\n\t"   \
                         "elpm %r0+5,Z+"       "\n\t"   \
                         "elpm %r0+6,Z+"       "\n\t"   \
                         "elpm %r0+7,Z+"                \
                         __pgm_clr_RAMPZ_               \
                         : "=r" (res)                   \
                         : "r" (addr), "n" (& RAMPZ)    \
                         : "r30", "r31")

/* FIXME: AT43USB320 does not have RAMPZ but supports (external) program
   memory of 64 KiW, at least that's what the comments in io43usb32x.h are
   indicating.  A solution would be to put the device in a different
   multilib-set (see GCC PR78275), as io.h has  "#define FLASHEND 0x0FFFF".
   For now, just exclude AT43USB320 from code that uses RAMPZ. Also note
   that the manual asserts that the entire program memory can be accessed
   by LPM, implying only 64 KiB of program memory.  */
#elif defined(__AVR_HAVE_ELPM__) \
      && !defined(__AVR_AT43USB320__)
/* The poor devices without ELPMx: Do 24-bit addresses by hand... */
#define __ELPM__1(res, addr, T)                                         \
  __asm __ELPM_VOLATILE ("mov r30,%A1"    "\n\t"                        \
                         "mov r31,%B1"    "\n\t"                        \
                         "out %i2,%C1 $ elpm $ mov %A0,r0"              \
                         : "=r" (res)                                   \
                         : "r" (addr), "n" (& RAMPZ)                    \
                         : "r30", "r31", "r0")

#define __ELPM__2(res, addr, T)                                         \
  __asm __ELPM_VOLATILE                                                 \
  ("mov r30,%A1"    "\n\t"                                              \
   "mov r31,%B1"    "\n\t"                                              \
   "mov %B0,%C1"    "\n\t"                                              \
   "out %i2,%B0 $ elpm $ mov %A0,r0 $ adiw r30,1 $ adc %B0,r1" "\n\t"   \
   "out %i2,%B0 $ elpm $ mov %B0,r0"                                    \
   : "=r" (res)                                                         \
   : "r" (addr), "n" (& RAMPZ)                                          \
   : "r30", "r31", "r0")

#define __ELPM__3(res, addr, T)                                         \
  __asm __ELPM_VOLATILE                                                 \
  ("mov r30,%A1"    "\n\t"                                              \
   "mov r31,%B1"    "\n\t"                                              \
   "mov %C0,%C1"    "\n\t"                                              \
   "out %i2,%C0 $ elpm $ mov %A0,r0 $ adiw r30,1 $ adc %C0,r1" "\n\t"   \
   "out %i2,%C0 $ elpm $ mov %B0,r0 $ adiw r30,1 $ adc %C0,r1" "\n\t"   \
   "out %i2,%C0 $ elpm $ mov %C0,r0"                                    \
   : "=r" (res)                                                         \
   : "r" (addr), "n" (& RAMPZ)                                          \
   : "r30", "r31", "r0")

#define __ELPM__4(res, addr, T)                                         \
  __asm __ELPM_VOLATILE                                                 \
  ("mov r30,%A1"    "\n\t"                                              \
   "mov r31,%B1"    "\n\t"                                              \
   "mov %D0,%C1"    "\n\t"                                              \
   "out %i2,%D0 $ elpm $ mov %A0,r0 $ adiw r30,1 $ adc %D0,r1" "\n\t"   \
   "out %i2,%D0 $ elpm $ mov %B0,r0 $ adiw r30,1 $ adc %D0,r1" "\n\t"   \
   "out %i2,%D0 $ elpm $ mov %C0,r0 $ adiw r30,1 $ adc %D0,r1" "\n\t"   \
   "out %i2,%D0 $ elpm $ mov %D0,r0"                                    \
   : "=r" (res)                                                         \
   : "r" (addr), "n" (& RAMPZ)                                          \
   : "r30", "r31", "r0")

#define __ELPM__8(res, addr, T)                                         \
  __asm __ELPM_VOLATILE                                                 \
  ("mov r30,%A1"    "\n\t"                                              \
   "mov r31,%B1"    "\n\t"                                              \
   "mov %r0+7,%C1"  "\n\t"                                              \
   "out %i2,%r0+7 $ elpm $ mov %r0+0,r0 $ adiw r30,1 $ adc %r0+7,r1" "\n\t" \
   "out %i2,%r0+7 $ elpm $ mov %r0+1,r0 $ adiw r30,1 $ adc %r0+7,r1" "\n\t" \
   "out %i2,%r0+7 $ elpm $ mov %r0+2,r0 $ adiw r30,1 $ adc %r0+7,r1" "\n\t" \
   "out %i2,%r0+7 $ elpm $ mov %r0+3,r0 $ adiw r30,1 $ adc %r0+7,r1" "\n\t" \
   "out %i2,%r0+7 $ elpm $ mov %r0+4,r0 $ adiw r30,1 $ adc %r0+7,r1" "\n\t" \
   "out %i2,%r0+7 $ elpm $ mov %r0+5,r0 $ adiw r30,1 $ adc %r0+7,r1" "\n\t" \
   "out %i2,%r0+7 $ elpm $ mov %r0+6,r0 $ adiw r30,1 $ adc %r0+7,r1" "\n\t" \
   "out %i2,%r0+7 $ elpm $ mov %r0+7,r0"                                \
   : "=r" (res)                                                         \
   : "r" (addr), "n" (& RAMPZ)                                          \
   : "r30", "r31", "r0")
#else
/* No ELPM: Fall back to __LPM__<N>.  */
#define __ELPM__1(r,a,T) const T *__a = (const T*)(uint16_t) a; __LPM__1(r,__a)
#define __ELPM__2(r,a,T) const T *__a = (const T*)(uint16_t) a; __LPM__2(r,__a)
#define __ELPM__3(r,a,T) const T *__a = (const T*)(uint16_t) a; __LPM__3(r,__a)
#define __ELPM__4(r,a,T) const T *__a = (const T*)(uint16_t) a; __LPM__4(r,__a)
#define __ELPM__8(r,a,T) const T *__a = (const T*)(uint16_t) a; __LPM__8(r,__a)
#endif /* ELPM cases */

#endif /* __LPM_ELPM_H_ */
