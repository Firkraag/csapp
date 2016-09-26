#include <stdio.h>

/* Determine whether arguments can be added without overflow */
/* This function should return 1 if arguments x and y can be added without causing overflow */
int uadd_ok(unsigned x, unsigned y) {
	unsigned sum = x + y;
	
	return sum >= x;
}

int main() {
	unsigned int x = 0xffffffff;
	unsigned int y = 0u;
	unsigned int z = 1u;

    if (uadd_ok(x, y))
        printf("%u and %u can be added without causing overflow\n", x, y);
    else
        printf("%u + %u causes overflow\n", x, y);

    if (uadd_ok(x, z))
        printf("%u and %u can be added without causing overflow\n", x, z);
    else
        printf("%u + %u causes overflow\n", x, z);

}
