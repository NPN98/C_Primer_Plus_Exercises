/*
Write a program that generates 1,000 random numbers in the range 1–10. Don’t save or
print the numbers, but do print how many times each number was produced. Have the
program do this for 10 different seed values. Do the numbers appear in equal amounts?
You can use the functions from this chapter or the ANSI C rand() and srand()
functions, which follow the same format that our functions do. This is one way to
examine the randomness of a particular random-number generator.
*/

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define NUM_NUMBER 1000
#define RANGE 10
#define NUM_SEED 10

void generate_randum_number(int seed);
int main()
{
    int i;
    int seed;
    for( i = 0; i < NUM_SEED; i++)
    {
        seed = time(NULL) + i; // use time as base, increasing it
        printf("Seed value: %d \n",seed);
        generate_randum_number(seed);
        printf("\n");
    }

}

void generate_randum_number(int seed)
{

    int count_number[RANGE] = {0};
    int i, num_generate;
    srand(seed);
    for(i = 0; i < 1000; i++)
    {
        num_generate = rand()%RANGE +1;
        count_number[num_generate -1]++;
    }

    for( i = 0; i < 10; i++)
    {
        printf("Times number %d is generated: %d \n",i+1, count_number[i]);
    }

}