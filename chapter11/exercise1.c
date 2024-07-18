/*
exercise1.c
1. Design and test a function that fetches the next n characters from input (including
blanks, tabs, and newlines), storing the results in an array whose address is passed as an
argument.
*/

#include <stdio.h>
#include <stdlib.h>

void fetch_next_n_char(char *buffer, int n);

int main ()
{
    int n;
    printf(" Enter the number of characters to fetch ");
    scanf("%d", &n);
    while (getchar() != '\n'); // clear the input buffer

    char *buffer = (char *)malloc((n+1)*sizeof(char)); // allocate memory for  buffer
    if(buffer == NULL)
    {
        printf(" Failed to alocate \n ");
        return 1;
    }
    
    printf(" Enter some text ");
    fetch_next_n_char(buffer,n);
    printf("Fetched character: %s\n",buffer);
    free(buffer);
    return 0;
}

void fetch_next_n_char(char *buffer, int n)
{
    int i;
    for(i = 0; i < n; i++)
    {
        int ch = getchar();
        if(ch == EOF)
        {
            break;
        }
        buffer[i] = (char)ch;
    }
    buffer[i] = '\0';
}