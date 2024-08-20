/* 
Write a program that echoes the command-line arguments in reverse word order. That
is, if the command-line arguments are see you later, the program should print later
you see.
*/
#include <stdio.h>

int main(int argc, char *argv[]) {
    // loop through the command-line argument in reserve order 
    int i;
    for (i = argc -1; i > 0; i --)
    {
        printf("%s" ,argv[i]);
        if(i > 1)
        {
            printf(" "); // print space between words
        }
    }
    printf("\n");
    return 0;
}