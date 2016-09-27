#include <stdio.h>

unsigned unsigned_high_prod(unsigned x, unsigned y);

/* Assuming we have access to a library function with prototype:
 * unsigned unsigned_high_prod(unsigned x, unsigned y),
 * computing the high-order w bits of x * y for two's-complement variables
 */
int signed_high_prod(int x, int y) {
    int int_size = sizeof(x) << 3;
    //most significant bit of x
    int msb_x = (unsigned) x >> (int_size - 1); 
    int msb_y = (unsigned) y >> (int_size - 1); 

    return (int) (unsigned_high_prod((unsigned) x, (unsigned) y) - msb_x * y - msb_y * x);
}
