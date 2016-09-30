#include "csapp.h"
#include "bit.h"

typedef unsigned float_bits;

/* Return the position of leftmost one. The position starts at 1. When x = 0, return 0 */	
int leftmost_one_pos(unsigned x) {
	int high = 31;
	int low = 0;
	int middle;
	int result;
	int length = high - low;

	while (length >= 0) {
		middle = (low + high) / 2;
		result = x >> middle;
		if (result == 0x1)
			return middle + 1;
		else if (result > 0x1)
			low = middle + 1;
		else
			high = middle - 1;
		length = high - low;
	}
	return 0;
}

/* Compute (float) i */
float_bits float_i2f(int i) {
	//unsigned sign = f >> 31;
	//unsigned exp = f >> 23 & 0xff;
	//unsigned frac = f & 0x7fffff;
	unsigned sign;
	unsigned exp;;
	unsigned frac;
	unsigned round_to_even;
	int pos;

    //convert negative to positive
    if (i == INT_MIN) {
        return 0xcf000000;
    }
	else if (i < 0) {
		sign = 1;
		i = -i;
	}
	else 
		sign = 0;
    
    //Compute the the position of leftmost one of bit pattern of i
	pos = leftmost_one_pos(i);
    exp = pos + 126;

    if (pos == 0)
        return 0x0;
	else if (pos <= 24) {
        frac = (i & lower_ones(pos - 1)) << (24 - pos);
	}
	else if (pos > 24) {
		frac = ((i >> (pos - 24)) & lower_ones(23));
        unsigned lsb_frac = 0x1 & frac;
        unsigned round_off = i & lower_ones(pos - 24);
        
        if (lsb_frac == 0x0) {
            if (round_off > (1 << (pos - 25))) {
                frac += 1;
            }
        }
        else {
            if (round_off >= (1u << (pos - 25))) {
                if (frac == 0x7fffff) {
                    frac = 0;
                    exp = pos + 127;
                }
                else {
                    frac += 1;
                }
            }
        }
    }
	return (sign << 31) | (exp << 23) | frac;
}

int main() {
    int i = INT_MIN;
    do {
        printf("%d\n", i);
        unsigned u = float_i2f(i);
        if (isnan(u2f(u))) {
            if (!isnan((float) i))
                printf("The test failed when integer i = %d\n", i);
                return -1;
        }
        else if (u2f(u) != (float) i) {
            printf("The test failed when integer i = %d\n", i);
            return 1;
        }
    } while (++i != INT_MIN);
    printf("All test passed\n");
}
