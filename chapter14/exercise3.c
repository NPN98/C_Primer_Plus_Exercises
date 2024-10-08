/*
3. Revise the book-listing program in Listing 14.2 so that it prints the book descriptions in
the order entered, then alphabetized by title, and then in order of increased value
*/

/*manybook.c -- multiple book inventory */
#include <stdio.h>
#include <string.h>
char * s_gets(char * st, int);
#define MAXTITL 40
#define MAXAUTL 40
#define MAXBKS 100 /* maximum numbero of books */

struct book {
    char title[MAXTITL];
    char author[MAXAUTL];
    float value;
};

int main(void)
{
    struct book library[MAXBKS]; /* array of book structure*/
    int count = 0;
    int index, n;

    printf(" please enter the book title. \n");
    printf(" press [Enter] at the start of a line to stop. \n");
    while(count < MAXBKS && s_gets(library[count].title, MAXTITL) != NULL 
    && library[count].title[0] != '\0')
    {
        printf(" Now enter the author. \n");
        s_gets(library[count].author, MAXAUTL);
        printf(" Now enter the value. \n");
        scanf("%f", &library[count++].value);
        while(getchar() != '\n')
            continue; /*clear the input line*/
        if( count < MAXBKS)
        {
            printf(" Enter the next title .\n");
        }
    }
    if(count > 0)
    {
        printf(" Here is the list of your books: \n");
        for (index = 0; index < count; index++)
        {
            printf("%s by %s: $%.2f\n", library[index].title,
            library[index].author, library[index].value);
        }

        // print whith alphabet
        struct book termbook;
        for (index = 0; index < count - 1; index ++ )
        {
            for(n = index; n < count; n++)
            {
                if (strcmp(library[index].title, library[n].title) > 0)
                {
                    termbook = library[n];
                    library[n] = library[index];
                    library[index] = termbook;
                }
            }
        }
        // print with value
        for (index = 0; index < count - 1; index ++ )
        {
            for(n = index; n < count; n++)
            {
                if (library[index].value > library[n].value)
                {
                    termbook = library[n];
                    library[n] = library[index];
                    library[index] = termbook;
                }
            }
        }
        
        printf(" Here is the list of your books as alphabet: \n");
        for (index = 0; index < count; index++)
        {
            printf("%s by %s: $%.2f\n", library[index].title,
            library[index].author, library[index].value);
        }
    }
    else
    {
        printf(" No book? too bad. \n");
    }

    return 0;
}


char *s_gets(char *st, int n)
{
    char *ret_val;
    char *find;
    ret_val = fgets(st, n, stdin);
    if( ret_val)
    {
        find = strchr(st, '\n'); // look for new line
        if (find)
        {
            *find = '\0';
        }
        else
        {
            while(getchar() != '\n')
            {
                continue; // dispose of rest of line
            }
        }
    }
    return ret_val;
}