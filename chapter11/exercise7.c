/*
The strncpy(s1,s2,n) function copies exactly n characters from s2 to s1, truncating
s2 or padding it with extra null characters as necessary. The target string may not be
null-terminated if the length of s2 is n or more. The function returns s1. Write your own
version of this function; call it mystrncpy(). Test the function in a complete program
that uses a loop to provide input values for feeding to the function.
*/

#include <stdio.h>
#include <string.h>

#define SIZE 100
char *mystrncpy(char *dest, char *sourc, int n);

int main()
{
    char deststr[SIZE];
    char srcstr[SIZE];
    char *result;
    int n;
    while (1)
    {
        printf(" \nEnter the string ('quit' to exit): ");
        fgets(srcstr, SIZE, stdin);
        srcstr[strcspn(srcstr,"\n")] = '\0'; // remove the newline character, alternative by terminate character of a string
        if(strcmp(srcstr,"quit") == 0)
        {
            break;
        }
        printf(" \nEnter the number character to copy: ");
        scanf("%d",&n);
        while (getchar() != '\n'); // Clear the input buffer
        result = mystrncpy(deststr, srcstr, n);
        printf("\n Copied string: %s", result);
    }
    return 0;
}

char *mystrncpy(char *dest, char *sourc, int n)
{
    int i;
    for( i = 0; i < n && sourc[i] != '\0'; i++)
    {
        dest[i] = sourc[i];
    }
    for(; i < n; i++)
    {
        printf(" debug\n");
        dest[i] = '\0';
    }
    return dest;
}