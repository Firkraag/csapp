/*************************************************************************
	> File Name: bit.h
	> Author: 
	> Mail: 
	> Created Time: Sun 25 Sep 2016 05:40:42 PM CST
 ************************************************************************/

#ifndef _BIT_H
#define _BIT_H
#endif

typedef unsigned char *byte_pointer;
unsigned lower_ones(int n);
unsigned higher_ones(int n);
float u2f(unsigned u);
unsigned f2u(float f);

typedef unsigned char *byte_pointer;
void show_bytes(byte_pointer start, int len);
void show_int(int x);
void show_float(float x);
void show_pointer(void *x);
void show_short(short x);
void show_long(long x);
void show_double(double x);

