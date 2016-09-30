#include "csapp.h"
#include "bit.h"

//Generate mask indicating rightmost 1 in x. Assume w=32. For example 0xFF00 -> 0x100, and 0x6600 --> 0x200. If x = 0, then return 0.
int rightmost_one(unsigned x) {
	return -x & x;
}

//Generate mask indicating rightmost 0 in x. Assume w=32. For example 0xFF -> 0x100, and 0x66 --> 0x0. If x = 0, then return 0.
int rightmost_zero(unsigned x) {
	return rightmost_one(~x);
}

//Generate mask indicating leftmost 1 in x. Assume w=32. For example 0xFF00 -> 0x8000, and 0x6600 --> 0x4000. If x = 0, then return 0.
int leftmost_one(unsigned x) {
	x |= (x >> 1);
	x |= (x >> 2);
	x |= (x >> 4);
	x |= (x >> 8);
	x |= (x >> 16);

	//The following statement is not working for x = 0
	//return (x >> 1) + 1;
	//The following statement is not working for x = 0xffffffff
	//return (x + 1) >> 1;
	x -= (x >> 1);
	return x;
}

//Generate mask indicating leftmost 0 in x. Assume w=32. For example 0xff000000 -> 0x800000. If x = 0, then return 0x80000000. If x = ~0, return 0.
int leftmost_zero(unsigned x) {
	return leftmost_one(~x);
}	
	
int main() {
    int i;

    if (leftmost_one(0) != 0) {
            printf("The test failed when x = 0x0\n");
            return 1;
    }
    if (leftmost_one(~0) != 0x80000000) {
            printf("The test failed when x = 0x%x\n", ~0);
            return 1;
    }
    for (i = 0; i < 32; i++) {
        if (leftmost_one(1 << i) != (1 << i)) {
            printf("The test failed when x = 0x%x\n", 1 << i);
            return 1;
        }
    }
    printf("All tests of leftmost_one passed\n"); 
    
    if (leftmost_zero(0) != 0x80000000) {
            printf("The test failed when x = 0x0\n");
            return 1;
    }
    if (leftmost_zero(~0) != 0x0) {
            printf("The test failed when x = 0x%x\n", ~0);
            return 1;
    }
    for (i = 1; i < 32; i++) {
        if (leftmost_zero(higher_ones(i)) != (1 << (32 - i - 1))) {
            printf("The test failed when x = 0x%x\n", higher_ones(i));
            return 1;
        }
    }
    printf("All tests of leftmost_zero passed\n"); 
    
    if (rightmost_one(0) != 0) {
            printf("The test failed when x = 0x0\n");
            return 1;
    }
    if (rightmost_one(~0) != 0x1) {
            printf("The test failed when x = 0x%x\n", ~0);
            return 1;
    }
    for (i = 0; i < 32; i++) {
        if (rightmost_one(1 << i) != (1 << i)) {
            printf("The test failed when x = 0x%x\n", 1 << i);
            return 1;
        }
    }
    printf("All tests of rightmost_one passed\n"); 

    if (rightmost_zero(0) != 0x1) {
            printf("The test failed when x = 0x0\n");
            return 1;
    }
    if (rightmost_zero(~0) != 0x0) {
            printf("The test failed when x = 0x%x\n", ~0);
            return 1;
    }
    for (i = 1; i < 32; i++) {
        if (rightmost_zero(lower_ones(i)) != (1 << i)) {
            printf("The test failed when x = 0x%x\n", lower_ones(i));
            return 1;
        }
    }
    printf("All tests of rightmost_zero passed\n"); 
    
}
