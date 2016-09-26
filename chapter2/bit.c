/*************************************************************************
	> File Name: bit.c
	> Author: 
	> Mail: 
	> Created Time: Sun 25 Sep 2016 05:25:47 PM CST
 ************************************************************************/

#include<stdio.h>

/* return an unsigned integer whose all but least significant n bits are 0 
 * 1 <= n <= 32
 */
unsigned lower_ones(int n) {
    int int_size = sizeof(int) << 3;
    return ((unsigned) ~0) >> (int_size - n);
}

/* return an unsigned integer whose all but most significant n bits are 0 
 * 1 <= n <= 32 
 */
unsigned higher_ones(int n) {
    int int_size = sizeof(int) << 3;
    if (n == 32)
        return ~0;
    else
        return ~lower_ones(int_size - n);
}
