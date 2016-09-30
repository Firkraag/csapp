#include <stdio.h>
#include <limits.h>

/* Determine whether arguments can be multiplied without overflow.
 * When overflow, return 0; otherwise return 1. 
 * It is a version of tmul_ok that uses 64-bit precision of data type long  long for the case where data type int has 32 bits */
int tmul32_ok(int x, int y) {
	long long llp = (long long) x * y;

	return (int) llp == llp;
}

int main() {
    int x = INT_MIN;
    int y = INT_MAX;

    for (int i = -3; i < 3; i++) {
        if (tmul32_ok(i, x))
            printf("%d and %d can be multiplied without causing overflow\n", i, x);
        else
            printf("%d * %d causes overflow\n", i, x);
    }

    for (int i = -3; i < 3; i++) {
        if (tmul32_ok(i, y))
            printf("%d and %d can be multiplied without causing overflow\n", i, y);
        else
            printf("%d * %d causes overflow\n", i, y);
    }
}
