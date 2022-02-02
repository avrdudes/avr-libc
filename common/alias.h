/* Redistribution and use in source and binary forms, with or without
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

#if !defined (__ASSEMBLER__)

#if __SIZEOF_DOUBLE__ == __SIZEOF_FLOAT__
#define DALIAS(X) __attribute__((__weak__,__alias__(#X)))
#else
#define DALIAS(X) /* empty */
#endif

#if __SIZEOF_LONG_DOUBLE__ == __SIZEOF_FLOAT__
#define LALIAS(X) __attribute__((__weak__,__alias__(#X)))
#else
#define LALIAS(X) /* empty */
#endif

#else /* Assembly */

.macro DALIAS name
#if __SIZEOF_DOUBLE__ == __SIZEOF_FLOAT__
.weak \name
\name:
#endif
.endm

.macro LALIAS name
#if __SIZEOF_LONG_DOUBLE__ == __SIZEOF_FLOAT__
.weak \name
\name:
#endif
.endm

#endif /* Assembly */
