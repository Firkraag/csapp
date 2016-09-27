#include <stdio.h>
#include <limits.h>
/* Addition that saturates to TMin or TMax.
 * Instead of overflowing the way normal two’s-complement     addition does,
 * saturating addition returns TMax when there would be positive overflow, and TMin when there would be negative overflow.
 * Saturating arithmetic is commonly used in programs that perform digital signal processing. */
int saturating_add(int x, int y) {
	int sum = x + y;
	int neg_over = (x < 0 && y < 0 && sum >= 0);
	int pos_over = (x >= 0 && y >= 0 && sum < 0);
	
	if (neg_over)
		sum = INT_MIN;
	else if (pos_over)
		sum = INT_MAX;
	return sum;
}

int main() {
    int x = INT_MIN;
    int y = INT_MAX;

    printf("saturating_add(%d, %d) = %d\n", INT_MIN, -1, saturating_add(INT_MIN, -1));
    printf("saturating_add(%d, %d) = %d\n", INT_MAX, 1, saturating_add(INT_MAX, 1));
    printf("saturating_add(%d, %d) = %d\n", 1, -1, saturating_add(1, -1));
}
