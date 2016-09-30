#include <stdio.h>	
#define POS_INFINITY  1 /  0.0 //0x7ff0000000000000
#define NEG_INFINITY  1 / -0.0 //0xfff0000000000000
#define NEG_ZERO     -0.0 //0x8000000000000000

int main() {
    printf("postive infinity = %f\n", POS_INFINITY);
    printf("negative infinity = %f\n", NEG_INFINITY);
    printf("negative zero = %f\n", NEG_ZERO);

}
