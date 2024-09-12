/* manydice.c -- multiple dice rolls*/
/* compile with diceroll.c*/
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "diceroll.h"
#include <string.h>
#include <ctype.h>
/* and for roll_count*/
#define SIZE_BUFF 10

int get_sets();
int main(void)
{
    int dice, roll;
    int sides;
    int status;
    int sets = 0;
    int ch;
    char buff[SIZE_BUFF];
    int n;
    srand((unsigned int)time(0)); /* randomize seed */
    printf("Enter the number of sets; enter q to stop\n");
    while( (sets = get_sets()) != -1)
    {
        //printf(" sets: %d \n",sets);
        printf("How many sides and how many dice?\n");
        //scanf("%d %d",&sides, &dice);
        if((status = scanf("%d %d",&sides, &dice)) != 2)
        {
            if(status == EOF)
            {
                break;
            }
            else
            {
                printf("You should have entered an interger folow: [side]<space>[dice]\n");
                printf("Let's begin again.\n");
                while (getchar() != '\n'); /* clear the input - because scanf do not read '\n' character input, so it remain in buffer*/ 
                printf("How many sets? Enter q to stop: q\n");
                continue;
            }
        }
        while (getchar() != '\n'); 
       // printf("Sides:%d, dice:%d\n",sides, dice);
        printf(" Here are %d sets of %d %d-sided throws", sets, dice, sides);
        for( n = 0; n < sets; n++)
        {
           
            printf("  %d",roll_n_dice(dice, sides));
            if(n % 9 == 0|| n == sets -1)
            {
                printf("\n");
            }
        }
        printf("How many sets? Enter q to stop: q\n");
    }
}

int get_sets()
{
    char ch;
    int sets;
    while( (ch = getchar()) != '\n')
    {
        if(ch == 'q')
        {
            while (getchar() != '\n'); /* dispose of bad input */
            return -1;
        }
        if(!isdigit(ch))
        {
            printf("You should have entered an digital chracter\n");
            printf("Let's begin again.\n");
            while (getchar() != '\n'); /* dispose of bad input */
            printf(" How many sets? Enter q to stop:");
            continue; /* new loop cycle*/
        }
        sets = (ch - '0') + sets*10;
        //printf("How many sides and how many dice?\n");
    }
    return sets;
}