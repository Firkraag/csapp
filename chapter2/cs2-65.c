#include "csapp.h"

int bit(int x, int k) {
	return 0x1 & (x >> (k - 1));
}

//Return 1 when x contains an even number of 1s; 0 otherwise. You may assume that data type int has w = 32 bits
int even_ones(unsigned x) {
    x ^= (x >> 16);
    x ^= (x >> 8);
    x ^= (x >> 4);
    x ^= (x >> 2);
    x ^= (x >> 1);
    return !(x & 1);    
}	

int even_ones_verify(unsigned x) {
	int i;
	int counter = 0;

	for (i = 1; i <= 32; i++)
		if (bit(x, i) == 1)
			counter = counter + 1;
	return !(counter % 2);

}

int main() {
	int i;
	
    for (i = 0; i <= 256; i++) {
        if (even_ones_verify(i) != even_ones(i))
            printf("The test failed when x = %d\n", i);
    }
    printf("All tests passed\n");
}
