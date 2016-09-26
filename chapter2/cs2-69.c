#include <stdio.h>
/* Do rotating right shift. Assume 0 <= n < w
Examples when x = 0x12345678 and w = 32;
	n = 4 -> 0x81234567, n = 20 -> 0x45678123
*/

unsigned rotate_right(unsigned x, int n) {
    int unsigned_size = sizeof(unsigned) << 3;
	unsigned y = x >> n;

	x = x << ((unsigned_size - n) % unsigned_size);
	return x | y;
}

int main() {
    unsigned x = 1;
    int unsigned_size = sizeof(unsigned) << 3;
    int i;

    printf("Hexadecimal representation of x is 0x%x\n", x);
    for (i = 0; i < unsigned_size; i++) {
       printf("After right rotating %.2d bits, now the integer is 0x%.8x\n", i, rotate_right(x, i)); 
    }
}

