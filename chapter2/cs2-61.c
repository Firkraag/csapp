#include <stdio.h>

/* return 1 when any bit of x equals 1, otherwise return 0 */
int any_bit_equals_1(int x) {
	return !!x;
}

/* return 1 when any bit of x equals 0, otherwise return 0 */
int any_bit_equals_0(int x) { //return x != ~0;
	return !!(x ^ (~0));
}

//any bit in the most significant byte of x equals 1, return 1; otherwise return 0
int any_bit_in_msb_equals_1(int x) {
	return !!(x & (0xff << ((sizeof(int) - 1) << 3)));
}
//any bit in the least significant byte of x equals 0, return 1; otherwise return 1
int any_bit_in_lsb_equals_0(int x) {
	int lsb = x & 0xff;
	
	return !!(lsb ^ 0xff);
}

int main() {
	int i;

	for (i = 0; i < 30; i++) {
        printf("The hexadecimal representation of %d is 0x%x\n", i, i);
        if (any_bit_equals_1(i))
            printf("some bit of %d equals 1 \n", i);
        else 
            printf("no bits of %d equals 1 \n", i);
        if (any_bit_equals_0(i))
            printf("some bit of %d equals 0 \n", i);
        else 
            printf("no bits of %d equals 0 \n", i);
        if (any_bit_in_msb_equals_1(i)) 
            printf("some bit in the msb of %d equals 1\n", i);
        else
            printf("no bits in the msb of %d equals 1\n", i);
        if (any_bit_in_lsb_equals_0(i)) 
            printf("some bit in the lsb of %d equals 0\n", i);
        else
            printf("no bits in the lsb of %d equals 0\n", i);
        putchar('\n');
	}
}
