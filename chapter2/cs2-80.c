#include <stdio.h>
#include "bit.h"

unsigned bit_pattern_a(int n) {
    int int_size = sizeof(int) << 3;

    if (n == int_size)
        return 0;
    else {
        return higher_ones(int_size - n);
    }
}

unsigned bit_pattern_b(int n, int m) {
    int int_size = sizeof(int) << 3;

    if (n + m == 0)
        return 0;
    else if (m == int_size)
        return 0;
    else
        return higher_ones(int_size - m) & lower_ones(n + m);
}

int main() {
	int i;

	for (i = 0; i <= 32; i++)
		printf("When n = %.2d, bit pattern of type A is 0x%.8x\n", i, bit_pattern_a(i));
		
    printf("When n = %.2d, m = %.2d, bit pattern of type b is 0x%x\n", 0, 0, bit_pattern_b(0, 0));
    printf("When n = %.2d, m = %.2d, bit pattern of type b is 0x%x\n", 0, 32, bit_pattern_b(0, 32));
    i = 5;
    for (int m = 0; m <= i; m++) {
        printf("When n = %.2d, m = %.2d, bit pattern of type b is 0x%x\n", i - m, m, bit_pattern_b(i - m, m));
        
    }
}
