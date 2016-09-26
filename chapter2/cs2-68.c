#include <stdio.h>

/* Clear all but least significant n bits of x 
Examples: x = 0x78ABCDEF, n = 8 --> 0xEF, n = 16 --> 0xCDEF
Assume 1 <= n <= w */
int lower_bits(int x, int n) {
    int int_size = sizeof(int) << 3;
	int mask = (unsigned) (~0) >> (int_size - n);
	return mask & x;
}

int main() {
    int x = 0xffffffff;
    int i;

    for (i = 1; i <= 32; i++) {
        printf("Lease significant %.2d bits of 0x%.8x is 0x%.8x\n", i, x, lower_bits(x, i));
    }
}
