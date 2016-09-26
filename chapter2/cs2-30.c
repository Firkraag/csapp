#include <stdio.h>
#include <limits.h>

/*Determine whether arguments can be added without overflow
 * This function should return 1 if arguments x and y can be added without causing overflow */
int tadd_ok(int x, int y) {
	int sum = x + y;
	int neg_over = x < 0 && y < 0 && sum >= 0;
	int pos_over = x > 0 && y > 0 && sum < 0;
	
	return !neg_over && !pos_over; 
}

int main() {
	int x = INT_MIN;
	int y = INT_MAX;

    if (tadd_ok(x, y))
        printf("%d and %d can be added without causing overflow\n", x, y);
    else
        printf("%d + %d causes overflow\n", x, y);
    if (tadd_ok(x, x))
        printf("%d and %d can be added without causing overflow\n", x, x);
    else
        printf("%d + %d causes overflow\n", x, x);

    if (tadd_ok(y, y))
        printf("%d and %d can be added without causing overflow\n", y, y);
    else
        printf("%d + %d causes overflow\n", y, y);
}
