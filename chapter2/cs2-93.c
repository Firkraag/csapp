#include <stdio.h>

typedef unsigned float_bits;

/* Compute 2*f. If f is NaN, then return f. */
float_bits float_twice(float_bits f) {
	unsigned sign = f >> 31;
	unsigned exp = (f >> 23) & 0xff;
	unsigned frac = f & 0x7FFFFF;

	if (exp == 0) {
		if (frac < 0x400000)
			frac = frac << 1;
		else {
			exp = 0x1;
			frac = (f << 1) & 0x7fffff;
		}
	}
	else if (exp < 0xff) 
		exp++;
	else 
		return f;
	return (sign << 31) | (exp << 23) | frac;
}

main() {
	printf("0x%x\n", float_twice(0x0f800001));
}
