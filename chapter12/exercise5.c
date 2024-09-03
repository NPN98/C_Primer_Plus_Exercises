/*
Write a program that generates a list of 100 random numbers in the range 1–10
in sorted decreasing order. (You can adapt the sorting algorithm from Chapter 11 ,
“Character Strings and String Functions,” to type int. In this case, just sort the numbers
themselves.)
*/

#include <stdio.h>
#include <stdlib.h>
#define SIZE 100
void rand_int(int *arr, int size);

int main()
{
    int list_arr[SIZE];
    int i;
    rand_int(list_arr, SIZE);

    for(i = 0; i < SIZE; i++)
    {
        printf("%d   ",list_arr[i]);
        if(i % 20 == 19)
        {
            printf("\n");
        }
    }

}

void rand_int(int *arr, int size)
{
    int num;
    int i, n;
    int term;
    for(i = 0; i <size; i++)
    {
        arr[i] = (int)rand()%10 + 1;
        // printf(" List of numbers after generated %d: %d \n",i,arr[i]);
    }

    for(i = 0; i < size -1; i++)
    {
        for(n = i; n < size; n++)
        {
            if(arr[i] < arr[n])
            {
                term = arr[i];
                arr[i] = arr[n];
                arr[n] = term;
            }
        }
    }
}