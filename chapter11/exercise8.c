/*
Write a function called string_in() that takes two string pointers as arguments. If
the second string is contained in the first string, have the function return the address
at which the contained string begins. For instance, string_in("hats", "at") would
return the address of the a in hats. Otherwise, have the function return the null pointer.
Test the function in a complete program that uses a loop to provide input values for
feeding to the function.
*/

#include <stdio.h>
#include <string.h>
#define SIZE 100
char *string_in(char *firststring, char *secondstring);

int main()
{
    char firststr[SIZE];
    char secondstr[SIZE];
    char *result;

    while(1)
    {
        printf("Enter the first string ('quit' to exit): \n");
        fgets(firststr, SIZE, stdin);
        firststr[strcspn(firststr,"\n")] = '\0'; // remove the newline character, is replace by terminate character of string
        if(strcmp(firststr,"quit") == 0)
        {
            break;
        }
        printf("Enter the second string: \n");
        fgets(secondstr, SIZE, stdin);
        secondstr[strcspn(secondstr,"\n")] = '\0';
        result = string_in(firststr, secondstr);

        if( result == NULL)
        {
            printf("The second string is not contained in the first string \n");
        }
        else
        {
            printf("The first string contain in second string start at %s \n", result);
        }
    }
    
}

char *string_in(char *firststring, char *secondstring)
{
    int i = 0;
    int n = 0;
    int instrsec = 0;

    while(firststring[i] != '\0')
    {
        if(firststring[i] == secondstring[0])
        {
            instrsec = i;
            break;
        }
        i++;
    }
    if(instrsec)
    {
        for(n = 0; n < strlen(secondstring); n++, i++)
        {
            if(firststring[i] != secondstring[n])
            {
                return NULL;
            }
        }
        return &firststring[instrsec];
    }
    else
    {
        return NULL;
    }
}