/*************************************************************************
	> File Name: bit.c
	> Author: 
	> Mail: 
	> Created Time: Sun 25 Sep 2016 05:25:47 PM CST
 ************************************************************************/

#include "csapp.h"
#include "bit.h"

/* return an unsigned integer whose all but least significant n bits are 0 
 * 0 <= n <= 32
 */
unsigned lower_ones(int n) {
    int int_size = sizeof(int) << 3;
    return (n == 0) ? 0 : ((unsigned) ~0) >> (int_size - n);
}

/* return an unsigned integer whose all but most significant n bits are 0 
 * 0 <= n <= 32 
 */
unsigned higher_ones(int n) {
    int int_size = sizeof(int) << 3;

    if (n == 0)
        return 0;
    if (n == int_size)
        return ~0;
    else
        return ~lower_ones(int_size - n);
}


void show_bytes(byte_pointer start, int len) {
    int i;
    for (i = 0; i < len; i++)
	printf(" %.2x", start[i]);    //line:data:show_bytes_printf
    printf("\n");
}

void show_int(int x) {
    show_bytes((byte_pointer) &x, sizeof(int)); //line:data:show_bytes_amp1
}

void show_float(float x) {
    show_bytes((byte_pointer) &x, sizeof(float)); //line:data:show_bytes_amp2
}

void show_pointer(void *x) {
    show_bytes((byte_pointer) &x, sizeof(void *)); //line:data:show_bytes_amp3
}
/* $end show-bytes */

void show_short(short x) {
    show_bytes((byte_pointer) &x,
sizeof(short));
}

void show_long(long x) {
    show_bytes((byte_pointer) &x,
sizeof(long));
}

void show_double(double x) {
    show_bytes((byte_pointer) &x,
sizeof(double));
}

/* return a float number having the same bit representation as the unsigned argument */
float u2f(unsigned u) {
    float f;

    memcpy(&f, &u, sizeof(unsigned));
    return f;
    
}

/* return a unsigned number having the same bit representation as the float argument */
unsigned f2u(float x) {
    unsigned u;

    memcpy(&u, &x, sizeof(float));
    return u;
}

