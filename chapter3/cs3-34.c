/* Compute the sum of bits in argument x */
int rfunc(unsigned x) {
    if (x == 0)
        return 0;
    unsigned nx = x >> 1;
    int rv = rfunc(nx);
    return rv + x & 1;
}
