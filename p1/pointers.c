#include "pointers.h"
#include <stdio.h>

int average(int *arrayPointer, unsigned int size)
{
    (void) arrayPointer;
    int newSize;

    if (size > INT16_MAX) {
        printf("Error: The maximum value of a int was overflowed, therefore the biggest possible integer will be picked");
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
    int newSize;

    if (size > INT16_MAX) {
        printf("Error: The maximum value of a int was overflowed, therefore the biggest possible integer will be picked");
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
        int* ptr = *(arrayPointer + arrayIndex);
        sum = sum + *ptr;
    }
    

    return sum / newSize;
}
