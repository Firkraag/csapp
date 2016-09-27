#include <stdio.h>

/* Declaration of data type where 4 bytes are packed
 into an unsigned */
typedef unsigned packed_t;

/* Extract byte from word. Return as signed integer
 * 0 <= bytenum <= 3
 */
int xbyte(packed_t word, int bytenum) {
    return (int) word << (24 - 8 * bytenum) >> 24;
}

int main() {
    int word = 0xf00ff101;

    for (int i = 0; i < 4; i++) {
        printf("the %dth byte of 0x%x\n is %d\n", i, word, xbyte(word, i));
    }
}

