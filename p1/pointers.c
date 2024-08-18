#include "pointers.h"

int average(int *arrayPointer, unsigned int size)
{
    (void) arrayPointer;
    int newSize;

    if (size > INT16_MAX) {
        newSize = INT16_MAX;
    } else {
        newSize = (int)size;
    }

    int sum = 0;

    if(newSize == 0) {
        return 0;
    }

    for (int arrayIndex = 0; arrayIndex < newSize; arrayIndex++)
    {
        sum = sum + *(arrayPointer + arrayIndex);
    }
    
    return sum / newSize;
}

int averageIndirect(int **arrayPointer, unsigned int size)
{
    (void) arrayPointer;
    (void) size;
    return 0;
}
