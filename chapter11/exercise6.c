/*
exercise7.c
Write a function called is_within() that takes a character and a string pointer as its two
function parameters. Have the function return a nonzero value (true) if the character is
in the string and zero (false) otherwise. Test the function in a complete program that uses
a loop to provide input values for feeding to the function
*/

#include <stdio.h>
#include <string.h>
#define MAX_LENGTH 100

int is_within(char character, char *string);
int main()
{
    int character;
    char string[MAX_LENGTH];
    while(1)
    { 
        printf(" \n Enter the character to search ('quit' to exit): ");
        character = getchar();
        while (getchar() != '\n'); // clear the input buffer 
        printf("\n Enter the string: ");
        fgets(string, MAX_LENGTH,stdin);
        string[strcspn(string,"\n")] = '\0'; // remove the newline character, alternative by terminate character of a string
        if(strcmp(string,"quit") == 0)
        {
            break;
        }
        if(is_within(character, string) == 0)
        {
            printf("\n Character %c is in string %s", character, string);
        }
        else
        {
            printf("\n Character %c is NOT in string %s", character, string);
        }
    }
    
}

int is_within(char character, char *string)
{
    while(*string != '\0')
    {
        if(*string == character)
        {
            return 0;
        }
        string++;
    }
    return 1;
}