#include <stdio.h>

/* Divide by power of two. Assume 0 <= k < w-1 */
int divide_power2(int x, int k) {
	int bias = (x >> ((sizeof(int) << 3) - 1)) & ((1 << k) - 1);

	return (x + bias) >> k;
}

int main() {
	int i;
    int x = 5000;

	for (i = 0; i <= 10; i++)
		printf("%d / 2^%d = %d\n", x, i, divide_power2(x, i));
}
