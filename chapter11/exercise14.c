/*
Write a power-law program that works on a command-line basis. The first command-line
argument should be the type double number to be raised to a certain power, and the
second argument should be the integer power.
*/

#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int main(int argc, char *argv[])
{
    if( argc != 3)
    {
        printf("Usage: %s <base> <exponent>",argv[0]);
        return 1;
    }
    
    double base = atof(argv[1]);
    int exponent = atoi(argv[2]);

    printf("%f raised to the power  of %d is: %f" ,base, exponent, pow(base, exponent));
    return 0;
}