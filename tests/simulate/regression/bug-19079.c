/* Copyright (c) 2008  Dmitry Xmelkov
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
   POSSIBILITY OF SUCH DAMAGE.
 */

/* bug #19079: sscanf %s eats 1 char too much
   $Id$	*/

#include <stdio.h>
#include <string.h>

int main ()
{
    char wsp_N[10];
    char wsp_E[11];
    int fixva = 0;
    int nr_sat = 0;
    char s[] = "$GP,194000.00,5001.4934,N,01954.5390,E,0,02,2.9";
    int nrconv;
    
    nrconv = sscanf (s, "$GP,%*u.%*u,%9s,N,%10s,E,%i,%i,%*s",
		     wsp_N, wsp_E, &fixva, &nr_sat);
    if (nrconv != 4) return __LINE__;
    if (strcmp (wsp_N, "5001.4934")) return __LINE__;
    if (strcmp (wsp_E, "01954.5390")) return __LINE__;
    if (fixva != 0) return __LINE__;
    if (nr_sat != 2) return __LINE__;
    
    return 0;
}
