#include <stdio.h>

//Judge the kth bit of x, if it is 1, return 1, otherwise return 0; 1 <= k <= 32 
//int bit(int x, int k) {
	//return 0x1 & (x >> k - 1);
//	
//} 
//Another version
int bit(int x, int k) {
	return !!((0x1 << (k - 1)) & x);
}

//Function sra performs an arithmetic right shift using a logical right shift given by value xsrl
int sra(int x, int k) {
	int xsrl = (unsigned) x >> k;
	int int_size = sizeof(int) << 3;
	int b = bit(x, int_size);
	
	if(b == 0)
		return xsrl;
	else
		return xsrl | (~0 << (int_size - k - 1));

}

//Function srl performs a logical right shift using an arithmetic right shift given by value xsra
unsigned srl(unsigned x, int k) {
	unsigned xsra = (int) x >> k;
	int int_size = sizeof(int) << 3;
    
    if (k == 0)
        return x;
    else
        return xsra & (~((~0x0) << (int_size - k))); 
}

int main() {
    int x = 0x40000000;
    int y = 0x80000000; 
    unsigned ux = (unsigned) x;
    unsigned uy = (unsigned) y;
    int i;

    printf("Perform arithmetic right shift\n");
    for (i = 0; i < 32; i++) {
        printf("0x%x >> %.2d = 0x%.8x, 0x%x >> %.2d = 0x%.8x\n", x, i, sra(x, i), y, i, sra(y, i));
    }
    printf("\nPerform logical right shift\n");
    for (i = 0; i < 32; i++) {
        printf("0x%x >> %.2d = 0x%.8x, 0x%x >> %.2d = 0x%.8x\n", ux, i, srl(ux, i), uy, i, srl(uy, i));
    }
	//printf("%x, %x\n",(unsigned) 0x87654321 >> 31, sra(0x87654321, 31));
	//printf("%x, %x\n",(int) 0x77654321 >> 30, srl(0xe7654321, 31));	
}
