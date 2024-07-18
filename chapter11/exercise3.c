/*
exercise3.c 
Design and test a function that reads the first word from a line of input into an array and
discards the rest of the line. It should skip over leading whitespace. Define a word as a
sequence of characters with no blanks, tabs, or newlines in it. Use getchar(), not
*/

#include <stdio.h>
#include <ctype.h>

void fetch_first_world(char *buffer, int max_len);

int main()
{
    char buffer[100];

    printf(" Enter a line of text: ");
    fetch_first_world(buffer, 100);
    printf(" First world: %s \n", buffer);
    return 0;
}

void fetch_first_world(char *buffer, int max_len)
{
    int i = 0; 
    int ch;

    // Skip leading whitespace 
    while((ch = getchar()) != EOF && isspace(ch) );
    // read the first world 
    while( ch != EOF && !isspace(ch) && i < max_len -1)
    {
        buffer[i++] = ch;
        ch = getchar();
    }
    // null - terminate the string
    buffer[i] = '\0';
    // discard the rest of line
    while (ch != EOF && ch != '\n')
    {
        ch = getchar();
    }

}