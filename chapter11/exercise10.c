/*
Write a function that takes a string as an argument and removes the spaces from the
string. Test it in a program that uses a loop to read lines until you enter an empty line.
The program should apply the function to each input string and display the result
*/

#include <stdio.h>
#include <string.h>
#define SIZE 100

char string[SIZE];

void remove_space(char *str);

int main()
{
    
    while (1)
    {
        printf("Enter the string( or press 'enter' to quit): \n");
        fgets(string, SIZE, stdin);
        if(string[0] == '\n')
        {
            break;
        }
        string[strcspn(string,"\n")] = '\0';
        printf("String input: %s\n",string);
        remove_space(string);
        printf("String is removed space: %s\n" ,string);
    }
}

void remove_space(char *str)
{
    int i = 0, j = 0;
    while (str[i]) {
        if (str[i] != ' ') {
            str[j] = str[i];
            j++;
        }
        i++;
    }
    str[j] = '\0';  // Null-terminate the string
}