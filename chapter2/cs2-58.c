/*************************************************************************
	> File Name: ex2-58.c
	> Author: 
	> Mail: 
	> Created Time: Sat 24 Sep 2016 09:39:46 PM CST
 ************************************************************************/

#include<stdio.h>

/* return 1 when run on a big-endian machine, otherwise return 0 */
int is_big_endian() {
    int x = 0x100;
    unsigned char *ptr = (unsigned char *) &x;

    return *ptr == 0x0 ? 0 : 1;
}

int main() {
    if (is_big_endian())
        printf("It is a big_endian machine\n");
    else
        printf("It is a little_endian machine\n");
    return 0;
}
