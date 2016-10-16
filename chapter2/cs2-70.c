#include <stdio.h>

/*Return 1 when x can be represented as an n-bit, 2's complement number; 0 otherwise. Assume 1 <= n <= w*/
int fits_bits(int x, int n) {
    // Mask whose higher 33 - n bits are 1s, and lower bits are 0s.
    int mask = (~0) << (n + (~0));
    // most significant (33 - n) bits
    int msb = x & mask;

    // msb == all 0s or msb = all 1s
    return (!(msb ^ mask)) | (!(msb ^ 0));
}

int main() {
    int x = -31 ;
    int int_size = sizeof(int) << 3;

    printf("The heaxdecimal representation of x is 0x%x\n", x);
    for (int i = 1; i <= int_size; i++) {
        if (fits_bits(x, i))
            printf("0x%x can be represented as an %d-bit, 2's complement number\n", x, i);
        else
            printf("0x%x cannot be represented as an %d-bit, 2's complement number\n", x, i);

    }
}

