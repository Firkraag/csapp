/*************************************************************************
	> File Name: cs2-89.c
	> Author: 
	> Mail: 
	> Created Time: Thu 29 Sep 2016 05:09:25 PM CST
 ************************************************************************/

#include "csapp.h"
#include "bit.h"

float fpwr2(int x) {
    /* Result exponent and fraction */
    unsigned exp, frac;
    unsigned u;

    if (x < -149) {
        /* Too small. Return 0.0 */
        exp = 0;
        frac = 0;
    }
    else if (x < -126) {
        /* Denormalized result */
        exp = 0;
        frac = 1 << (149 + x);
    }
    else if (x < 128) {
        exp = 127 + x;
        frac = 0;
    }
    else {
        exp = 0xff;
        frac = 0;
    }
    u = exp << 23 | frac;
    return u2f(u);
}

int main() {
    for (int i = -200; i < 200; i++) {
        if (fpwr2(i) != powf(2, i)) {
            printf("The test failed when x = %d\n", i);
            return 1;
        }
    }
    printf("All tests passed\n");
}

