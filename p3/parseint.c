#include "parseint.h"

/*
 * Returns the value of c or -1 on error
 */
int parseDecimalChar(char c)
{
    (void)c;

    if (c >= '0' && c <= '9') {
        return c - '0';
    }

    return -1;
}

/**
 * Calculates the result of base^exponent with recursion.
 * This function makes the function parseInt easier and smaller.
 */
int power(int base, int exponent) {
    if (exponent == 0) {
        return 1;
    }
    int temp = power(base, exponent/2);
    if (exponent % 2 == 0){
        return temp * temp;
    } else {
        return base * temp * temp;
    }
}

/*
 * Parses a non-negative integer, interpreted as octal when starting with 0,
 * decimal otherwise. Returns -1 on error.
 */
int parseInt(char *string)
{
    (void)string;
    int length = 0;
    int base;
    int result = 0;

    while (string[length] != '\0') {
        length++;
    }

    if(length == 0) {
        return -1;
    }

    int firstDigit = parseDecimalChar(string[0]);

    if (firstDigit == 0) {
        base = 8;
    } else if (firstDigit != -1) {
        base = 10;
    } else {
        return -1;
    }

    for (int stringIndex = 0; stringIndex < length; stringIndex++)
    {
        int digit = parseDecimalChar(string[stringIndex]);

        if (digit == -1){
            return -1;
        } else if (digit == 0)
        {
            continue;
        } else {
            result += digit * power(base, length - 1 - stringIndex);
        }
        
    }

    return result;
}
