#include <stdint.h>

#include "bits.h"

/*
 * Returns the n'th bit of the array A.
 */
int getN(uint64_t *A, size_t n)
{
    (void) A;
    (void) n;
    
    uint64_t elementIndex = n / 64;
    uint64_t elementBit = n % 64;
    uint64_t element = *(A + elementIndex);

    uint64_t mask = 1 << elementBit;
    uint64_t masked_n = element & mask;
    uint64_t bit = masked_n >> elementBit;
    return bit;
}

/*
 * Sets the n'th bit of the array A.
 */
void setN(uint64_t *A, size_t n)
{
    size_t element = n / 64;
    size_t bit = n % 64;

    uint64_t mask = (uint64_t) 1 << bit;

    A[element] |= mask;
}

/*
 * Clears the n'th bit of the array A.
 */
void clrN(uint64_t *A, size_t n)
{
    size_t element = n / 64;
    size_t bit = n % 64;
    uint64_t mask = (uint64_t) 1 << bit;
    A[element] &= ~mask;
}


/*
 * Rotates the integer i n bits to the right.
 */
uint64_t rot(uint64_t i, int n)
{
    n = ((n % 64) + 64) % 64;
    return  (i >> n) | (i << (64 - n));
}
