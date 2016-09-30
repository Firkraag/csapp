#include "csapp.h"

/*int_size_is_32() yields 1 when run on a machine forwhich an int is 32 bits, and yields 0 otherwise. 
 * Run properly on any machine for which data type int is at least 32 bits
 */
int int_size_is_32() {
	return ((1 << 31) >> 31) != 1; 
}

/* Run properly on any machine for which data type int is at least 16 bits.
 * Yields 1 when run on a machine for which an int is 32 bits, and yields 0 otherwise.
 */
int int_size_is_32_16() {
	int left_shift = ((1 << 15) << 15) << 1;
	int right_shift = ((left_shift >> 15) >> 15) >> 1;

	return (right_shift != 1) && (right_shift != 0);
}

int main() {
    if (int_size_is_32())
        printf("On this machine an int is 32 bits\n");
    else
        printf("On this machine an int is not 32 bits\n");

    if (int_size_is_32_16())
        printf("On this machine an int is 32 bits\n");
    else
        printf("On this machine an int is not 32 bits\n");
}
