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
