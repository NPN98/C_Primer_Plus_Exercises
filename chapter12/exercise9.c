/*
Write a program with the following behavior. First, it asks you how many words you
wish to enter. Then it has you enter the words, and then it displays the words. Use
malloc() and the answer to the first question (the number of words) to create a dynamic
array of the corresponding number of pointers-to-char. (Note that because each element
in the array is a pointer-to-char, the pointer used to store the return value of malloc()
should be a pointer-to-a-pointer-to-char.) When reading the string, the program should
read the word into a temporary array of char, use malloc() to allocate enough storage
to hold the word, and store the address in the array of char pointers. Then it should
copy the word from the temporary array into the allocated storage. Thus, you wind up
with an array of character pointers, each pointing to an object of the precise size needed
to store the particular word.
*/

#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>

#define LIMIT 200

char ** get_word( int num_word);
int main()
{
    char **arr_word;

    int n, i;
    printf("How many words do you wish to enter?");
    if(scanf("%d",&n) == 1 && n > 0)
    {
        while(getchar() != '\n');
        arr_word = get_word(n);
        printf("Here is your in put: \n");
        for(i = 0; i < n; i++)
        {
            printf("%s\n",arr_word[i]);
        }
        for(i = 0; i < n; i++)
        {
            free(arr_word[i]); // Free each allocated word
        }
        free(arr_word); // free the allocated of array poiter
    }
}

char ** get_word( int num_word)
{
    char temp[LIMIT];
    char **arr_p_word;
    int i;
    int n = 0;
    int start_word;
    int end_word;
    int size_word;
    arr_p_word = (char**)malloc(sizeof(char *)*num_word);

    char test[3][100];
    printf("Enter %d word now:",num_word);
    fgets(temp, LIMIT, stdin);
    for(i = 0; i < num_word; i++)
    {
        
        while (isspace(temp[n]))
        {
            n++;
        }
        start_word = n;
        
        while (!isspace(temp[n]))
        {
            n++;
        }
        end_word = n-1; 
        size_word = end_word - start_word + 1;
        //printf("Start word at:%d ,end word at:%d\n", start_word, end_word);
        arr_p_word[i] = (char*)malloc(sizeof(char)*(size_word +1));
        strncpy(arr_p_word[i], &temp[start_word], size_word);
        arr_p_word[i][size_word] = '\0';
        // printf(" Word copied: %s",arr_p_word[i]);
    }
    return arr_p_word;
}