/*
Write a program that prompts the user to enter the day, month, and year. The month
can be a month number, a month name, or a month abbreviation. The program then
should return the total number of days in the year up through the given day. (Do take
leap years into account.)
*/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define SIZE_NAME 10

int countdayto( int day, char *monthstr, int year);
int isleapyear(int year);

struct month {
    char name[SIZE_NAME];
    char abbrev[4];
    int days;
    char monumb[3];
};

struct month months[12] =
{
    {"January", "jan", 31, "1"},
    {"February", "feb", 28, "2"},
    {"March", "mar", 31, "3"},
    {"April", "apr", 30, "4"},
    {"May", "may", 31, "5"},
    {"June", "jun", 30, "6"},
    {"July", "jul", 31, "7"},
    {"August", "aug", 31, "8"},
    {"September", "sep", 30, "9"},
    {"October", "oct", 31, "10"},
    {"November", "nov", 30, "11"},
    {"December", "dec", 31, "12"}
};

int main()
{
    int day, year, month, daycount;
    char monthstr[SIZE_NAME];

    printf("Enter the day:");
    scanf("%d",&day);
    while (getchar() != '\n');
    printf("Enter the month (month number, a month name, or a month abbreviation):");
    fgets(monthstr, SIZE_NAME, stdin);
    monthstr[strcspn(monthstr,"\n")] = '\0';
    printf("Enter the year:");
    scanf("%d",&year);
    while (getchar() != '\n');
    if(isleapyear(year))
    {
        months[12].days = 29;
    }
    daycount = countdayto(day, monthstr, year);
    if(daycount >= 0)
    {
        printf(" Total day up to %d - %s - %d: %d ", day, monthstr, year, daycount);
    }
}

int isleapyear(int year) {
    return (year % 4 == 0 && year % 100 != 0) || (year % 400 == 0);
}

int countdayto( int day, char *monthstr, int year)
{
    int i, monthnum;
    int totalday = 0;
    if( day < 0 || day > 30 )
    {
        printf(" Invalid day \n");
        return -1;
    }
    if(year < 0)
    {
       printf(" Invalid year \n");
        return -2; 
    }
   
    while (strcmp(monthstr,months[i].name) != 0 
    && strcmp(monthstr,months[i].abbrev) != 0 
    && strcmp(monthstr,months[i].monumb) != 0)
    {
        i++;
        if (i == 12)
        {
            break;
        }
    }
    if( i <= 12)
    {
        monthnum = i;
        for( i = 0; i < monthnum; i++)
        {
            totalday += months[i].days;
        }
        totalday += day;
        return totalday;
    }
    else
    {
        printf(" Invalid month \n");
        return -3;
    }
}

