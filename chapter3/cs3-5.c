/*************************************************************************
	> File Name: cs3-5.c
	> Author: 
	> Mail: 
	> Created Time: Sat 01 Oct 2016 09:29:07 PM CST
 ************************************************************************/

#include<stdio.h>

void decode1(int *xp, int *yp, int *zp) {
    int x = *xp;
    int y = *yp;
    int z = *zp;

    *yp = x;
    *zp = y;
    *xp = z;
}
