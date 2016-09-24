/*************************************************************************
	> File Name: cs2-60.c
	> Author: 
	> Mail: 
	> Created Time: Sat 24 Sep 2016 09:54:54 PM CST
 ************************************************************************/

#include<stdio.h>

/* return an unsigned value in which byte i of argument x
 * replaced by byte b.
 * Examples:
 * put_byte(0x12345678, 0xab, 2) --> 0x12ab5678
 * put_byte(0x12345678, 0xab, 0) --> 0x123456ab
 * */
unsigned put_byte(unsigned x, unsigned char b, int i) {
    return (x & (~(0xff << (i * 8)))) | (b << (i * 8)); 
}

int main() {
    printf("0x%x\n", put_byte(0x12345678, 0xab, 2));
    printf("0x%x\n", put_byte(0x12345678, 0xab, 0));
    return 0;
}
