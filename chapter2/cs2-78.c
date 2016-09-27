#include "csapp.h"

int mul3div4(int x) {
    //mul = 3 * x
    int mul = (x << 1) + x;
    int int_size = sizeof(int) << 3;

/* The following expression is equivalent to:
 * (mul < 0 ? mul + (1 << 2) - 1 : mul) >> 2;
 */
    return ((mul >> (int_size - 1) & 0x3) + mul) >> 2;
}

int main() {
    int i;
    int x = INT_MIN;

    for (i = -10; i <= 10; i++)
        if (mul3div4(i) != 3 * i / 4) {
            printf("When x = %d, the test failed\n", i);
            return 1;
        }
    for (i = INT_MAX - 5; i < INT_MAX; i++) {
        if (mul3div4(i) != 3 * i / 4) {
            printf("When x = %d, the test failed\n", i);
            return 1;
        }
    }
    for (i = INT_MIN; i <= INT_MIN + 5; i++) {
        if (mul3div4(i) != 3 * i / 4) {
            printf("When x = %d, the test failed\n", i);
            return 1;
        }
    }
    printf("All tests passed\n");
    return 0;
}
