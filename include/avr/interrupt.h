/* Copyright (c) 2002,2005,2007 Marek Michalkiewicz
   Copyright (c) 2007, Dean Camera

   All rights reserved.

   Redistribution and use in source and binary forms, with or without
   modification, are permitted provided that the following conditions are met:

   * Redistributions of source code must retain the above copyright
     notice, this list of conditions and the following disclaimer.

   * Redistributions in binary form must reproduce the above copyright
     notice, this list of conditions and the following disclaimer in
     the documentation and/or other materials provided with the
     distribution.

   * Neither the name of the copyright holders nor the names of
     contributors may be used to endorse or promote products derived
     from this software without specific prior written permission.

  THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS "AS IS"
  AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE
  IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE
  ARE DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT OWNER OR CONTRIBUTORS BE
  LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR
  CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF
  SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS
  INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN
  CONTRACT, STRICT LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE)
  ARISING IN ANY WAY OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE
  POSSIBILITY OF SUCH DAMAGE. */

/* $Id$ */

#ifndef _AVR_INTERRUPT_H_
#define _AVR_INTERRUPT_H_

#include <avr/io.h>

#if !defined(__DOXYGEN__) && !defined(__STRINGIFY)
/* Auxiliary macro for ISR_ALIAS(). */
#define __STRINGIFY(x) #x
#endif /* !defined(__DOXYGEN__) */

/** \file */
/**@{*/


/** \name Global manipulation of the interrupt flag

    The global interrupt flag is maintained in the I bit of the status
    register (SREG).

    Handling interrupts frequently requires attention regarding atomic
    access to objects that could be altered by code running within an
    interrupt context, see <util/atomic.h>.

    Frequently, interrupts are being disabled for periods of time in
    order to perform certain operations without being disturbed; see
    \ref optim_code_reorder for things to be taken into account with
    respect to compiler optimizations.
*/

/** \def sei()
    \ingroup avr_interrupts

    Enables interrupts by setting the global interrupt mask. This function
    actually compiles into a single line of assembly, so there is no function
    call overhead.  However, the macro also implies a <i>memory barrier</i>
    which can cause additional loss of optimization.

    In order to implement atomic access to multi-byte objects,
    consider using the macros from <util/atomic.h>, rather than
    implementing them manually with cli() and sei().
*/
# define sei()  __asm__ __volatile__ ("sei" ::: "memory")

/** \def cli()
    \ingroup avr_interrupts

    Disables all interrupts by clearing the global interrupt mask. This function
    actually compiles into a single line of assembly, so there is no function
    call overhead.  However, the macro also implies a <i>memory barrier</i>
    which can cause additional loss of optimization.

    In order to implement atomic access to multi-byte objects,
    consider using the macros from <util/atomic.h>, rather than
    implementing them manually with cli() and sei().
*/
# define cli()  __asm__ __volatile__ ("cli" ::: "memory")


/** \name Macros for writing interrupt handler functions */


#if defined(__DOXYGEN__)
/** \def ISR(vector [, attributes])
    \ingroup avr_interrupts

    Introduces an interrupt handler function (interrupt service
    routine) that runs with global interrupts initially disabled
    by default with no attributes specified.

    The \c attributes are optional and alter the behaviour and resultant
    generated code of the interrupt routine. Multiple attributes may
    be used for a single function, with a space separating each
    attribute.

    Valid attributes are #ISR_BLOCK, #ISR_NOBLOCK, #ISR_NAKED,
    #ISR_FLATTEN, #ISR_NOICF, #ISR_NOGCCISR and ISR_ALIASOF(vect).

    \c vector must be one of the interrupt vector names that are
    valid for the particular MCU type.
*/
#  define ISR(vector, [attributes])
#else  /* real code */

#if (__GNUC__ == 4 && __GNUC_MINOR__ < 1) || (__GNUC__ < 4) || defined(__clang__)
#  define __INTR_ATTRS __used__
#else /* GCC > 4.1 */
#  define __INTR_ATTRS __used__, __externally_visible__
#endif

#ifdef __cplusplus
#  define ISR(vector, ...)            \
    extern "C" void vector (void) __attribute__ ((__signal__,__INTR_ATTRS)) __VA_ARGS__; \
    void vector (void)
#else
#  define ISR(vector, ...)            \
    void vector (void) __attribute__ ((__signal__,__INTR_ATTRS)) __VA_ARGS__; \
    void vector (void)
#endif

#endif /* DOXYGEN */

#if defined(__DOXYGEN__)
/** \def ISR_N(vector_num [, attributes])
    \ingroup avr_interrupts

    Introduces an interrupt handler function (interrupt service
    routine) that runs with global interrupts initially disabled
    by default with no attributes specified.

    \c vector_num must be a positive interrupt vector number that is
    valid for the particular MCU type.

    Contrary to the #ISR macro, #ISR_N does not provide a declarator for
    the ISR.  #ISR_N may be specified more than once, which can be used
    to define aliases.  For example, the following definition provides
    an ISR for IRQ numbers 3 and 4 on an ATmega328:
\code
    ISR_N (PCINT0_vect_num)
    ISR_N (PCINT1_vect_num)
    static void my_isr_handler (void)
    {
      // Code
    }
\endcode
    The \c attributes are optional and alter the behaviour and resultant
    generated code of the interrupt routine. Multiple attributes may
    be used for a single function, with a space separating each
    attribute.

    Valid attributes are #ISR_BLOCK, #ISR_NOBLOCK, #ISR_NAKED,
    #ISR_FLATTEN, #ISR_NOICF and #ISR_NOGCCISR.

    #ISR_N is only supported when the compiler supports the
    <tt>signal(n)</tt> attribute, i.e. the \c signal attribute with arguments.
    This is the case for
    <a href="https://gcc.gnu.org/gcc-15/changes.html#avr">GCC v15</a>
    and up.
*/
#  define ISR_N(vector_num, [attributes])
#else  /* real code */

#if defined __HAVE_SIGNAL_N__
/* Notice that "used" is implicit since v15, and that there is no requirement
   that the handler function is externally visible.  */
#define ISR_N(N, ...)				\
  __attribute__((__signal__(N))) __VA_ARGS__
#else /* HAVE_SIGNAL_N */
/* When GCC does not support "signal(n)", which is the case up to v14,
   then try to emit a helpful error message.  */
#define __ISR_N_error2(L)                                               \
  __attribute__((__used__,__error__(					\
    "ISR_N not supported by this version of the compiler")))            \
  int AVR_LibC_show_error##L (int x)					\
  {									\
    return x ? 1 : x * AVR_LibC_show_error##L (x - 1);			\
  }
#define __ISR_N_error1(L) __ISR_N_error2(L)
#define ISR_N(...) __ISR_N_error1(__LINE__)
#endif /* HAVE_SIGNAL_N */
#endif /* DOXYGEN ISR_N */

#if defined(__DOXYGEN__)
/** \def SIGNAL(vector)
    \ingroup avr_interrupts

    Introduces an interrupt handler function that runs with global interrupts
    initially disabled.

    This is the same as the ISR macro without optional attributes.
    \deprecated Do not use SIGNAL() in new code. Use ISR() or ISR_N() instead.
*/
#  define SIGNAL(vector)
#else  /* real code */

#ifdef __cplusplus
#  define SIGNAL(vector)					\
    extern "C" void vector(void) __attribute__ ((__signal__, __INTR_ATTRS));	\
    void vector (void)
#else
#  define SIGNAL(vector)					\
    void vector (void) __attribute__ ((__signal__, __INTR_ATTRS));		\
    void vector (void)
#endif

#endif /* DOXYGEN */

#if defined(__DOXYGEN__)
/** \def EMPTY_INTERRUPT(vector)
    \ingroup avr_interrupts

    Defines an empty interrupt handler function. This will not generate
    any prolog or epilog code and will only return from the #ISR. Do not
    define a function body as this will define it for you.
    Example:
    \code EMPTY_INTERRUPT(ADC_vect);\endcode */
#  define EMPTY_INTERRUPT(vector)
#else  /* real code */

#ifdef __cplusplus
#  define EMPTY_INTERRUPT(vector)                \
    extern "C" void vector(void) __attribute__ ((__signal__,__naked__,__INTR_ATTRS));    \
    void vector (void) {  __asm__ __volatile__ ("reti" ::: "memory"); }
#else
#  define EMPTY_INTERRUPT(vector)                \
    void vector (void) __attribute__ ((__signal__,__naked__,__INTR_ATTRS));    \
    void vector (void) { __asm__ __volatile__ ("reti" ::: "memory"); }
#endif

#endif /* DOXYGEN */

#if defined(__DOXYGEN__)
/** \def ISR_ALIAS(vector, target_vector)
    \ingroup avr_interrupts

    Aliases a given vector to another one in the same manner as the
    ISR_ALIASOF attribute for the ISR() macro. Unlike the ISR_ALIASOF
    attribute macro however, this is compatible for all versions of
    GCC rather than just GCC version 4.2 onwards.

    \note This macro creates a trampoline function for the aliased
    macro.  This will result in a two cycle penalty for the aliased
    vector compared to the ISR the vector is aliased to, due to the
    JMP/RJMP opcode used.

    \deprecated
    For new code, the use of ISR(..., ISR_ALIASOF(...))  or #ISR_N is
    recommended.  Notice that using #ISR_N does \e not impose a
    JMP/RJMP overhead.

    Example:
    \code
    ISR (INT0_vect)
    {
        PORTB = 42;
    }

    ISR_ALIAS (INT1_vect, INT0_vect);

    // Alternative using ISR_N

    ISR_N (INT0_vect_num)
    ISR_N (INT1_vect_num)
    static void my_int01_handler (void)
    {
        PORTB = 42;
    }

    // or

    ISR (INT0_vect,
         [attributes]
         ISR_N (INT1_vect_num))
    {
        PORTB = 42;
    }
    \endcode
*/
#  define ISR_ALIAS(vector, target_vector)
#else /* real code */

#ifdef __cplusplus
#    define ISR_ALIAS(vector, tgt) extern "C" void vector (void) \
	__attribute__((__signal__, __naked__, __INTR_ATTRS)); \
	void vector (void) { __asm__ __volatile__ ("%~jmp " __STRINGIFY(tgt) ::); }
#else	  /* !__cplusplus */
#  define ISR_ALIAS(vector, tgt) void vector (void) \
	__attribute__((__signal__, __naked__, __INTR_ATTRS)); \
	void vector (void) { __asm__ __volatile__ ("%~jmp " __STRINGIFY(tgt) ::); }
#endif	/* __cplusplus */

#endif /* DOXYGEN */

/** \def reti()
    \ingroup avr_interrupts

    Returns from an interrupt routine, enabling global interrupts. This should
    be the last command executed before leaving an #ISR defined with the
    #ISR_NAKED attribute.

    This macro actually compiles into a single line of assembly, so there is
    no function call overhead.

    \note According to the GCC documentation, the only code supported in
    naked functions is \ref inline_asm "inline assembly".
*/
#  define reti()  __asm__ __volatile__ ("reti" ::: "memory")

#if defined(__DOXYGEN__)
/** \def BADISR_vect
    \ingroup avr_interrupts

    \code #include <avr/interrupt.h> \endcode

    This is a vector which is aliased to __vector_default, the vector
    executed when an IRQ fires with no accompanying ISR handler. This
    may be used along with the ISR() macro to create a catch-all for
    undefined but used ISRs for debugging purposes.
*/
#  define BADISR_vect
#else  /* !DOXYGEN */
#  define BADISR_vect __vector_default
#endif /* DOXYGEN */

/** \name ISR attributes */

#if defined(__DOXYGEN__)
/** \def ISR_BLOCK
    \ingroup avr_interrupts

    Identical to an ISR with no attributes specified. Global
    interrupts are initially disabled by the AVR hardware when
    entering the ISR, without the compiler modifying this state.

    Use this attribute in the \c attributes parameter of the #ISR
    and #ISR_N macros.
*/
#  define ISR_BLOCK

/** \def ISR_NOBLOCK
    \ingroup avr_interrupts

    ISR runs with global interrupts initially enabled.  The interrupt
    enable flag is activated by the compiler as early as possible
    within the ISR to ensure minimal processing delay for nested
    interrupts.

    This may be used to create nested ISRs, however care should be
    taken to avoid stack overflows, or to avoid infinitely entering
    the ISR for those cases where the AVR hardware does not clear the
    respective interrupt flag before entering the ISR.

    Use this attribute in the \c attributes parameter of the #ISR and
    #ISR_N macros.
*/
#  define ISR_NOBLOCK

/** \def ISR_NAKED
    \ingroup avr_interrupts

    ISR is created with no prologue or epilogue code. The user code is
    responsible for preservation of the machine state including the
    SREG register, as well as placing a reti() at the end of the
    interrupt routine.

    Use this attribute in the \c attributes parameter of the #ISR and
    #ISR_N macros.

    \note According to GCC documentation, the only code supported in
    naked functions is \ref inline_asm "inline assembly".
*/
#  define ISR_NAKED

/** \def ISR_FLATTEN
    \ingroup avr_interrupts

    The compiler will try to inline all called function into the ISR.
    This has an effect with GCC 4.6 and newer only.

    Use this attribute in the \c attributes parameter of the #ISR and
    #ISR_N macros.
*/
#  define ISR_FLATTEN

/** \def ISR_NOICF
    \ingroup avr_interrupts

    Avoid identical-code-folding optimization against this ISR.
    This has an effect with GCC 5 and newer only.

    Use this attribute in the \c attributes parameter of the #ISR and
    #ISR_N macros.
*/
#  define ISR_NOICF

/** \def ISR_NOGCCISR
    \ingroup avr_interrupts

    Do not generate
    <a href="https://sourceware.org/binutils/docs/as/AVR-Pseudo-Instructions.html">\c __gcc_isr pseudo instructions</a>
    for this ISR.
    This has an effect with
    <a href="https://gcc.gnu.org/gcc-8/changes.html#avr">GCC 8</a>
    and newer only.

    Use this attribute in the \c attributes parameter of the #ISR and
    #ISR_N macros.
*/
#  define ISR_NOGCCISR

/** \def ISR_ALIASOF(target_vector)
    \ingroup avr_interrupts

    The ISR is linked to another ISR, specified by the vect parameter.
    This is compatible with GCC 4.2 and greater only.

    Use this attribute in the \c attributes parameter of the #ISR macro.
    Example:
    \code
    ISR (INT0_vect)
    {
        PORTB = 42;
    }

    ISR (INT1_vect, ISR_ALIASOF (INT0_vect));
    \endcode

    Notice that the #ISR_ALIASOF macro implements its own IRQ handler that
    jumps to the aliased ISR, which means there is a run-time overhead of
    a JMP/RJMP instruction.  For an alternative without overhead, see
    the #ISR_N macro.
*/
#  define ISR_ALIASOF(target_vector)
#else  /* !DOXYGEN */
#  define ISR_BLOCK /* empty */
/* FIXME: This won't work with older versions of avr-gcc as ISR_NOBLOCK
          will use `signal' and `interrupt' at the same time.  */
#  ifdef __HAVE_SIGNAL_N__
/* Use "noblock" if available.  This works rather like a flag that can be
   combined with "signal(n)" without imposing a specific function name,
   like "interrupt" would do.  */
#  define ISR_NOBLOCK    __attribute__((__noblock__))
#  else
#  define ISR_NOBLOCK    __attribute__((__interrupt__))
#  endif /* Have signal(n) and noblock */

#  define ISR_NAKED      __attribute__((__naked__))

#if (__GNUC__ == 4 && __GNUC_MINOR__ >= 6) || (__GNUC__ >= 5)
#  define ISR_FLATTEN    __attribute__((__flatten__))
#else
#  define ISR_FLATTEN    /* empty */
#endif /* has flatten (GCC 4.6+) */

#if defined (__has_attribute)
#if __has_attribute (__no_icf__)
#  define ISR_NOICF      __attribute__((__no_icf__))
#else
#  define ISR_NOICF      /* empty */
#endif /* has no_icf */

#if __has_attribute (__no_gccisr__)
#  define ISR_NOGCCISR      __attribute__((__no_gccisr__))
#else
#  define ISR_NOGCCISR      /* empty */
#endif /* has no_gccisr */
#endif /* has __has_attribute (GCC 5+) */

#  define ISR_ALIASOF(v) __attribute__((__alias__(__STRINGIFY(v))))
#endif /* DOXYGEN */

/**@}*/

#endif
