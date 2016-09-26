#include <stdio.h>

//This function yields 1 when run on a machine that uses logical right shifts for data type int and yields 0 otherwise
int int_shifts_are_logical(void) {
	return ((~0) >> ((sizeof(int) << 3) - 1)) == 0x1;
}

int main() {
    printf(int_shifts_are_logical() ? "This machine uses logical right shifts for data type int\n" : "This machine uses arithmetic right shifts for data type int\n");
}
