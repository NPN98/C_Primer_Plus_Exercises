/* 
Write a program that reads in up to 10 strings or to EOF, whichever comes first. Have it
offer the user a menu with five choices: print the original list of strings, print the strings
in ASCII collating sequence, print the strings in order of increasing length, print the
strings in order of the length of the first word in the string, and quit. Have the menu
recycle until the user enters the quit request. The program, of course, should actually
perform the promised tasks.
*/

#include <stdio.h>
#include <string.h>
#define MAX_STRINGS 10
#define MAX_LENGTH 100

void print_original(char *strings[], int count);
void print_ascii_order( char *strings[], int count);
void print_by_length(char *strings[], int count);
void print_by_first_world_length(char *strings[], int count);
int get_first_world_length(char *str);

int main()
{
    char *strings[MAX_STRINGS];
    char buffer[MAX_LENGTH];
    int count = 0;

    printf("Enter up to %d string (or EOF to stop): \n", MAX_STRINGS);
    while (count < MAX_STRINGS && fgets(buffer, MAX_LENGTH, stdin))
    {
        buffer[strcspn(buffer, "\n")] = '\0'; // remove the newline character 
        strings[count] = (char *)malloc(strlen(buffer)+1); // +1 because strlen do not count '/0' character in end of sting
        strcpy(strings[count], buffer);
        count++;
    }

    int choice;

    do {
        printf("\n MENU \n");
        printf("1. Print original list of strings \n");
        printf("2. print string in ASCII colating sequence \n");
        printf("3. print string in order of creasing length\n");
        printf("4. print string in oder of the length of the first word \n");
        printf("5. Quit\n");
        scanf("%d", &choice);
        getchar(); // consume the newline left by scan

        switch (choice) {
            case 1:
                print_original(strings, count);
                break;
            case 2:
                print_ascii_order(strings, count);
                break;
            case 3:
                print_by_length(strings, count);
                break;
            case 4:
                print_by_first_world_length(strings, count);
                break;
            case 5:
                printf("Quit program. \n");
                break;
            default:
                printf("Invalid choice, please try again.\n");
        }
    }while(choice != 5);
    int i;
    for( i = 0; i < count; i++)
    {
        free(strings[i]);
    }
    return 0;
}

void print_original(char *strings[], int count)
{
    int i;
    printf("\nOriginal list string:\n");
    for(i = 0; i < count; i++)
    {
        printf("%s\n",strings[i]);
    }
}

void print_ascii_order(char *strings[], int count)
{
    char *temp;
    char *sorted_strings[MAX_STRINGS];
    int i, j;
    for(i = 0; i < count; i++)
    {
        sorted_strings[i] = strings[i];
    }

    for ( i = 0; i < count - 1; i++)
    {
        for(  j = i + 1; j < count ; j++)
        {
            if( strcmp(sorted_strings[i], sorted_strings [j]) > 0)
            {
                temp = sorted_strings[i];
                sorted_strings[i] = sorted_strings[j];
                sorted_strings[j] = temp;
            }
        }
    }

    printf("\n String in ASCII collating sequence: \n");
    for( i = 0; i < count; i++)
    {
        printf("%s\n", sorted_strings[i]);
    }
}

void print_by_length(char *strings[], int count)
{
    char *temp;
    char *sorted_strings[MAX_LENGTH];
    int i, j;
    for(i = 0; i < count; i++)
    {
        sorted_strings[i] = strings[i];
    }

    for ( i = 0; i < count - 1; i++)
    {
        for( j = i + 1; j < count ; j++)
        {
            if( strlen(sorted_strings[i]) > strlen(sorted_strings[j]))
            {
                temp = sorted_strings[i];
                sorted_strings[i] = sorted_strings[j];
                sorted_strings[j] = temp;
            }
        }
    }

    printf("\nStrings in order of increasing length:\n");
    for(i = 0; i < count; i++)
    {
        printf("%s\n", sorted_strings[i]);
    }
}

void print_by_first_world_length(char *strings[], int count)
{
    char *temp;
    char *sorted_strings[MAX_LENGTH];
    int i, j;

    for(i = 0; i < count; i++)
    {
        sorted_strings[i] = strings[i];
    }

    for (i = 0; i < count - 1; i++)
    {
        for(j = i + 1; j < count ; j++)
        {
            if( get_first_world_length(sorted_strings[i]) > get_first_world_length(sorted_strings[j]))
            {
                temp = sorted_strings[i];
                sorted_strings[i] = sorted_strings[j];
                sorted_strings[j] = temp;
            }
        }
    }

    printf("\nStrings in order of the length of the first word:\n");
    for(i = 0; i < count; i++)
    {
        printf("%s\n", sorted_strings[i]);
    }
}


int get_first_world_length( char *str)
{
    int length = 0;
    while (*str && *str != ' ')
    {
        length++;
        str++;
    }
    return length;
}