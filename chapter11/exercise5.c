/*
exercise5.c
Design and test a function that searches the string specified by the first function
parameter for the first occurrence of a character specified by the second function
parameter. Have the function return a pointer to the character if successful, and a null
if the character is not found in the string. (This duplicates the way that the library
strchr() function works.) Test the function in a complete program that uses a loop to
provide input values for feeding to the function.

*/
#include <stdio.h>
#include <string.h>
#define SIZE 100

char *find_char(char *string_input, char character);
int main()
{
    char string_input[100];
    int character;
    char *position_chr_found;

    while (1)
    {
        printf("Enter the string (or \"quit\" to exit):");
        fgets(string_input, 100, stdin);

        string_input[strcspn(string_input, "\n")] = '\0'; // Remove newline character
        if(strcmp(string_input,"quit") == 0)
        {
            break;
        }
        printf("\nEnter the character to find: ");
        character = getchar(); 
        while (getchar() != '\n'); // Clear the input buffer
        position_chr_found = find_char(string_input,character);
        if( position_chr_found != NULL)
        {
            printf(" Chracter %c found at position %d:",character, position_chr_found - string_input);
        }
        else
        {
            printf(" Character not found");
        }
    }
}

char *find_char(char *string_input, char character)
{
    int i = 0;
    while(i < strlen(string_input))
    {
        if(character == string_input[i])
        {
            return string_input + i;
        }
        i++;
    }
    return NULL;
}