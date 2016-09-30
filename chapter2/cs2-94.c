#include "csapp.h"
#include "bit.h"

typedef unsigned float_bits;

/* Compute 0.5 * f. If f is NaN, then return f. 
 * Float point standard requires round-to-even.
 */
float_bits float_half(float_bits f) {
	unsigned sign = f >> 31;
	unsigned exp = (f >> 23) & 0xff;
	unsigned frac = f & 0x7fffff;
	unsigned round_to_even = ((0x3 & frac) == 0x3);

    /* When f is positive infinity, negative infinity or NaN */
    if (exp == 0xff) {
        return f;
    }
    /* Denormallized form */
    else if (exp == 0) {
        frac = (frac >> 1) + round_to_even;
    }
    /* Normalized form */
    else {
        if (exp == 0x1)
        {
            exp = 0;
            frac = ((0x800000 | frac) >> 1) + round_to_even;
        }
        else {
            exp--;
        }
    }
	return (sign << 31) | (exp << 23) | frac;
}

int main() {
    unsigned i = 0;
    do {
        if (isnan(u2f(i))) {
            if (float_half(i) != i)
                printf("The test failed when f = %f\n", u2f(i));
        }
        else if (u2f(float_half(i)) != (u2f(i) / 2.0f)) {
            printf("%g\n", u2f(float_half(i)));
            printf("%g\n", u2f(i) / 2.0f);
            show_int(i); 
            show_float(u2f(float_half(i)));
            show_float(u2f(i) / 2.0f);
            printf("The test failed when f = %g\n", u2f(i));
            return 1;
        }
    } while (++i != 0);
    printf("All test passed\n");
}
