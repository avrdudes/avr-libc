#ifndef __BITS_ATTRIBS_H_
#define __BITS_ATTRIBS_H_

#define __ATTR_ALWAYS_INLINE__ __inline__ __attribute__((__always_inline__))

#ifdef  __GNUC_STDC_INLINE__
#define __ATTR_GNU_INLINE__   __attribute__((__gnu_inline__))
#else
#define __ATTR_GNU_INLINE__
#endif

#define __ATTR_CONST__ __attribute__((__const__))

#define __ATTR_PURE__ __attribute__((__pure__))

#define __ATTR_MALLOC__ __attribute__((__malloc__))

#define __ATTR_NORETURN__ __attribute__((__noreturn__))

/* AVR specific */

#define __ATTR_PROGMEM__ __attribute__((__progmem__))

#endif /* __BITS_ATTRIBS_H_ */
