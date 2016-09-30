#include "csapp.h"

/* Compute 3x/4, no overflow */
int threefourths(int x) {
    /* the following expression is equivalent to 
     * if x < 0
     *     return x - (x >> 2)
     * elseif 0x3 & x == 0
     *     return x - (x >> 2)
     * else 
     *     return x - ((x >> 2) + 1)
     */
    return x - ((x >> 2) + ((!(x >> (INT_SIZE - 1))) & ((0x3 & x) != 0)));
}

int main() {
    int i;

    for (i = -10; i <= 10; i++) {
        if (threefourths(i) != 3 * i / 4) {
            printf("When x = %d, the test failed\n", i);
            return 1;
        }
    }
    for (i = INT_MIN; i < INT_MIN + 5; i++) {
        if (threefourths(i) != (int) (3 * (long  long ) i / 4)) {
            printf("When x = %d, the test failed\n", i);
            return 1;
        }
    }
    for (i = INT_MAX - 5; i < INT_MAX; i++) {
        printf("%d, %d, %d\n", i, threefourths(i), (int) (3 * (long long) i / 4));
        if (threefourths(i) != (int) (3 * (long  long ) i / 4))     
        {
            printf("When x = %d, the test failed\n", i);
            return 1;
        }
    }
    printf("All tests passed\n");
    return 0;
}
