/* Test case distilled from issue #674
   https://github.com/avrdudes/avr-libc/issues/674

   The "failing" tests from #674 were bogus.  "man strftime" says:

   RETURN VALUE
      Provided that the result string, including the terminating null byte,
      does not exceed max bytes, strftime() returns the number of bytes
      (excluding the terminating null byte) placed in the array s.
      If the length of the result string (including the terminating null
      byte) would exceed max_bytes, then strftime() returns 0, and the
      contents of the array are undefined.  */

#ifndef __AVR_TINY__

#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <avr/flash.h>

struct tm GlobalTime;

void runTest_F (size_t testNum, size_t bufSize, size_t expectedLen,
                const char *formatStr, const __flash char *expectedOutput)
{
    char buf[10 + expectedLen];
    buf[expectedLen] = '#';

    size_t len = strftime (buf, bufSize, formatStr, &GlobalTime);

    if (len != expectedLen)
        exit (testNum);

    if (expectedLen > 0)
    {
        if (strlen_F (expectedOutput) != expectedLen)
            exit (testNum);

        if (buf[expectedLen] != '\0')
            exit (testNum);

        if (strcmp_F (expectedOutput, buf) != 0)
            exit (testNum);
    }
}

#define runTest(a, b, c, d, e) runTest_F (a, b, c, d, FSTR (e))

void loop (void)
{
    // SUCCEEDING TESTS, last parameter is the expected output
    runTest (1, 4, 0, "", "");
    runTest (2, 5, 4, "%Y", "2000");
    runTest (3, 4, 2, "xx", "xx");
    runTest (4, 5, 4, "xxxx", "xxxx");
    runTest (5, 10, 8, "xxxx%Y", "xxxx2000");

    // FAILING TESTS, last parameter is the expected output
    // Needs a buffer of 5 at least.
    runTest (6, 4, 0, "%Y", "");

    // Needs a buffer of 5 at least.
    runTest (7, 4, 0, "xx%m", "");

    // Needs a buffer of 5 at least.
    runTest (8, 4, 0, "%mxx", "");

    // Needs a buffer of 5 at least.
    runTest (9, 4, 0, "xxxx", "");

    // Needs a buffer of 9 at least.
    runTest (10, 4, 0, "xxxxxxxx", "");
}

int main (void)
{
    time_t nowTime = time (0);
    localtime_r (&nowTime, &GlobalTime);

    loop ();

    return 0;
}

#else

int main (void)
{
    return 0;
}

#endif
