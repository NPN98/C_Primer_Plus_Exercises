/*
Write a program that reads input up to EOF and reports the number of words, the
number of uppercase letters, the number of lowercase letters, the number of punctuation
characters, and the number of digits. Use the ctype.h family of functions.
*/

#include <stdio.h>
#include <string.h>
#include <ctype.h>
#define MAX_SIZE 100

void check_letters(char *buff, int num_char);
int main()
{
    char buffer[MAX_SIZE];
    int ch;
    int i;
    printf("Enter the string: \n");

    while ((ch = getchar()) != EOF && ch != '\n')
    {
        buffer[i] = ch;
        i++;
    }
    check_letters(buffer, i);
}

void check_letters(char *buff, int num_char)
{
   
    int i;
    int uppercase = 0;
    int lowercase = 0;
    int punctuation = 0;
    int digital = 0;
    char ch;
    for( i = 0; i < num_char; i++)
    {
        ch = (int)buff[i];
         /* count lowercase */
        if ( islower(ch))
        {
            lowercase++;
        }
        /* count upercase*/
        else if (isupper(ch))
        {
            uppercase++;
        }
        /* count punctuation characters*/
        else if (ispunct(ch))
        {
            punctuation++;
        }
        /* count digital*/
        else if (isdigit(ch))
        {
            digital++;
        }
    }

    printf("input characters have:\n");
    printf("Upercase: %d\n", uppercase);
    printf("Lowercase: %d\n",lowercase);
    printf("Punctuation: %d\n", punctuation);
    printf("Digital: %d",digital);
}