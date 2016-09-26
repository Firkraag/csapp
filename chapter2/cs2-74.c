#include <stdio.h> 
#include <limits.h>

//Determine whether arguments can be substracted without overflow
//This function should return 1 if the computation x - y does not overflow.
int tsub_ok(int x, int y) {
	int sum = x - y;

	return !((x >= 0 && y == INT_MIN) || (x < 0 && y > 0 && sum >= 0) || (x > 0 && y < 0 && y > INT_MIN && sum < 0));
}

int main() {
    int x = INT_MIN;
    int y = INT_MIN + 1;
	
    for (int i = -3; i < 3; i++) {
        if (tsub_ok(i, x))
            printf("%d and %d can be substracted without causing overflow\n", i, x);
        else
            printf("%d - %d causes overflow\n", i, x);
    }

    for (int i = -3; i < 3; i++) {
        if (tsub_ok(x, i))
            printf("%d and %d can be substracted without causing overflow\n", x, i);
        else
            printf("%d - %d causes overflow\n", x, i);
    }

    for (int i = -3; i < 3; i++) {
        if (tsub_ok(i, y))
            printf("%d and %d can be substracted without causing overflow\n", i, y);
        else
            printf("%d - %d causes overflow\n", i, y);
    }
}
