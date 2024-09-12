/*
Redo Review Question 5, but make the argument the spelled-out name of the month
instead of the month number. (Don’t forget about strcmp().) Test the function in a
simple program.
*/
/*
review question 5: 
Redo Review Question 5, but make the argument the spelled-out name of the month
instead of the month number. (Don’t forget about strcmp().) Test the function in a
simple program.
*/
/*
review question 3:
Devise a structure template that will hold the name of a month, a three-letter
abbreviation for the month, the number of days in the month, and the month number. 
*/
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define SIZE_NAME 10

int countdayto( char *monthstr);

struct month {
    char name[SIZE_NAME];
    char abbrev[4];
    int days;
    int monumb;
};

struct month months[12] =
{
    {"January", "jan", 31, 1},
    {"February", "feb", 28, 2},
    {"March", "mar", 31, 3},
    {"April", "apr", 30, 4},
    {"May", "may", 31, 5},
    {"June", "jun", 30, 6},
    {"July", "jul", 31, 7},
    {"August", "aug", 31, 8},
    {"September", "sep", 30, 9},
    {"October", "oct", 31, 10},
    {"November", "nov", 30, 11},
    {"December", "dec", 31, 12}
};

int main()
{

    char namemonth[SIZE_NAME];
    int totalday;
    printf("Enter the full name of a month, capitalized (eg. March): ");
    fgets(namemonth, SIZE_NAME, stdin);
    namemonth[strcspn(namemonth,"\n")] = '\0';
    totalday = countdayto(namemonth);
    if (totalday < 0)
    {
        printf(" Invalid input month\n");
    }
    else
    {
        printf("Total number of days from the beginning of the year to %s: %d",namemonth,totalday);
    }

}

int countdayto( char *monthstr)
{
    int i = 0;
    int monthnum;
    int total = 0;
    while (strcmp(monthstr,months[i].name) != 0)
    {
        i++;
        if(i == 12)
        {
            break;
        }
    }
    if(i <= 12)
    {
        monthnum = i;
        for(i = 0; i <= monthnum; i++)
        {
            total += months[i].days;
        }
        return total;
    }
    else
    {
        return -1;
    }
}
