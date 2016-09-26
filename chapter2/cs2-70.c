#include <stdio.h>

/*Return 1 when x can be represented as an n-bit, 2's complement number; 0 otherwise. Assume 1 <= n <= w*/
int fits_bits(int x, int n) {
    unsigned head = (unsigned) x >> (n - 1);
	
    return head == 0 || head == 1;
}

int main() {
    int x = 1;
    int int_size = sizeof(int) << 3;

    printf("The heaxdecimal representation of x is 0x%x\n", x);
    for (int i = 1; i <= int_size; i++) {
        if (fits_bits(x, i))
            printf("0x%x can be represented as an %d-bit\n", x, i);
        else
            printf("0x%x cannot be represented as an %d-bit\n", x, i);

    }
}

