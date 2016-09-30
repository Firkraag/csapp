#include "csapp.h"
#include "bit.h"

typedef unsigned float_bits;

/* Compute -f. If f is NaN, then return f. */
float_bits float_negate(float_bits f) {
	unsigned sign = f >> 31;
	unsigned exp = (f >> 23) & 0xff;
	unsigned frac = f & 0x7FFFFF;

	if (exp == 0xff && frac != 0)
		return f;
	else {
        //flip the sign bit
		sign = sign ^ 1;
		return (sign << 31) | (exp << 23) | frac;
	}
}

int main() {
    unsigned i = 0;
    do {
        if (isnan(u2f(i))) {
            if (float_negate(i) != i)
                printf("The test failed when f = %f\n", u2f(i));
        }
        else if (u2f(float_negate(i)) != -u2f(i)) {
            printf("The test failed when f = %f\n", u2f(i));
            return 1;
        }
    } while (++i != 0);
    printf("All test passed\n");
}
