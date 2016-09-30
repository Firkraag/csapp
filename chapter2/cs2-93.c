#include "csapp.h"
#include "bit.h"

typedef unsigned float_bits;

/* Compute 2*f. If f is NaN, then return f. */
float_bits float_twice(float_bits f) {
	unsigned sign = f >> 31;
	unsigned exp = (f >> 23) & 0xff;
	unsigned frac = f & 0x7FFFFF;
    
    /* When f is positive infinity, negative infinity or NaN */
    if (exp == 0xff) {
        return f;
    }
    /* Denormallized form */
    else if (exp == 0) {
		if (frac < 0x400000)
			frac = frac << 1;
		else {
			exp = 0x1;
			frac = (f << 1) & 0x7fffff;
		}
        return (sign << 31) | (exp << 23) | frac;
    }
    /* Normalized form */
    else {
        /* When 2 * f cause overflow */
        if (exp == 0xfe) {
            /* negative */
            if (sign == 1)
                /* negative infinity */
                return 0xff800000;
            else 
                /* positive infinity */
                return 0x7f800000;
        }
        else
            return (sign << 31) | (++exp << 23) | frac;
    }
}

int main() {
    unsigned i = 0;
    do {
        if (isnan(u2f(i))) {
            if (float_twice(i) != i)
                printf("The test failed when f = %f\n", u2f(i));
        }
        else if (u2f(float_twice(i)) != 2 * u2f(i)) {
            printf("The test failed when f = %f\n", u2f(i));
            return 1;
        }
    } while (++i != 0);
    printf("All test passed\n");
}
