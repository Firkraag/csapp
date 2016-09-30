/*************************************************************************
	> File Name: cs2-83.c
	> Author: 
	> Mail: 
	> Created Time: Thu 29 Sep 2016 03:29:30 PM CST
 ************************************************************************/

#include "csapp.h"
#include "bit.h"

/* Test whether the first argument is greater than
 * or equal to the second argument, 
 * assuming neither arguments is NaN */
int float_ge(float x, float y) {
    unsigned ux = f2u(x);
    unsigned uy = f2u(y);
    unsigned sx = ux >> 31;
    unsigned sy = uy >> 31;

    return (sx == 0 && sy == 1) || (sx == 0 && sy == 0 && ux >= uy) || (sx == 1 && sy == 1 && ux <= uy);
}

int main() {
    int float_ge(float x, float y);
    float i;

    for (i = -5.0; i < 6.0; i++) {
       if ((i >= 0.0) != float_ge(i, 0)) 
       {
           printf("The test failed when x = %f, y = %f\n", i, 0.0);
           return 1;
       }
    }
    for (i = -5.0; i < 6.0; i++) {
       if ((i >= NEG_INFINITY) != float_ge(i, NEG_INFINITY)) 
       {
           printf("The test failed when x = %f, y = %f\n", i, NEG_INFINITY);
           return 1;
       }
    }
    for (i = -5.0; i < 6.0; i++) {
       if ((i <= POS_INFINITY) != float_ge(POS_INFINITY, i)) 
       {
           printf("The test failed when x = %f, y = %f\n", POS_INFINITY, i);
           return 1;
       }
    }
   if ((NEG_INFINITY <= POS_INFINITY) != float_ge(POS_INFINITY, NEG_INFINITY)) 
   {
       printf("The test failed when x = %f, y = %f\n", POS_INFINITY, NEG_INFINITY);
       return 1;
   }
    printf("All tests passed\n");

}

