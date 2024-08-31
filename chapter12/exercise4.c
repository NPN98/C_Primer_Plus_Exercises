/* Write and test in a loop a function that returns the number of times it has been called.*/

#include <stdio.h>

int main()
{
    int number; 
    int i;
    printf("Enter the number of time you want to function run: ");
    scanf("%d",&number);
    for(i = 0; i <= number; i++)
    {
        printf("Number of time function run:%d \n ",return_time_run());
    }
}

int return_time_run()
{
    static count;
    return count++;
}