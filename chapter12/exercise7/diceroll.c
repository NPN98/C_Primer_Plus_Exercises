/*diceroll.c -- dice role simulation*/
/*compile with manydice.c*/
#include "diceroll.h"
#include <stdio.h>
#include <stdlib.h>

int roll_count = 0; // external linkage variable
int roll_n_dice(int dice, int sides);
static int rollem(int sides) /* private to this file*/
{
    int roll;
    roll = rand() % sides + 1;
    ++roll_count;
    return roll;
}

int roll_n_dice(int dice, int sides)
{
    int d;
    int total = 0;
    if (sides < 2)
    {
        printf("Need at least 2 sides");
        return -2;
    }

    if(dice < 1)
    {
        printf("Need at least 1 die.\n");
        return -1;
    }
    for( d = 0; d < dice; d++)
    {
        total += rollem(sides);
    }

    return total;
}