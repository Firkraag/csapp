#include <stdio.h>

int div16(int x) {
	int bias = (x >> 31) & 0xf;

	return (x + bias) >> 4;
}

int main() {
    for (int x = -100; x <= 100; x += 10)
        printf("%d / 16 = %d\n", x, div16(x));
}
