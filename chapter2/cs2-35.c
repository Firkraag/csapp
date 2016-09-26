#include <stdio.h>
#include <limits.h>
/* Determine whether arguments can be multiplied without overflow */
/* When overflow, return 0; otherwise return 1 */
int tmul_ok(int x, int y) {
	int p = x * y;
    printf("%d\n", x);
    printf("%d\n", y);
    printf("%d\n", p);
    printf("%d\n", p / x);
	return !x || (p / x == y);
}

int main() {
    int x = INT_MIN;
    int y = INT_MAX;

    for (int i = -3; i < 3; i++) {
        if (tmul_ok(i, x))
            printf("%d and %d can be multiplied without causing overflow\n", i, x);
        else
            printf("%d * %d causes overflow\n", i, x);
    }

    for (int i = -3; i < 3; i++) {
        if (tmul_ok(i, y))
            printf("%d and %d can be multiplied without causing overflow\n", i, y);
        else
            printf("%d * %d causes overflow\n", i, y);
    }
}
