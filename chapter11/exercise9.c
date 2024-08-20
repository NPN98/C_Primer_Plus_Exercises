/*
Write a function that replaces the contents of a string with the string reversed. Test the
function in a complete program that uses a loop to provide input values for feeding to
the function.
*/

#include <stdio.h>
#include <string.h>
#define SIZE 100

void reverse_string(char *string);
int main()
{
    char str[SIZE];
    while(1)
    {
        printf("Enter the string ('quit' to exit)\n");
        fgets(str, SIZE, stdin);
        str[strcspn(str,"\n")] = '\0';
        if(strcmp(str,"quit") == 0)
        {
            break;
        }
        printf("String before reverse: %s\n" ,str);
        reverse_string(str);
        printf("String after reverse: %s\n" ,str);
    }
    return 0;
}

void reverse_string(char *string)
{
    int i;
    char term; 
    int leng = strlen(string);
    for(i = 0; i <leng/2; i++)
    {
        term = string[i];
        string[i] = string[leng - i -1];
        string[leng - i -1] = term;
    }
}