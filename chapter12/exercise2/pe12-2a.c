/* pe12-2a.c*/

#include "pe12-2a.h"
#include <stdio.h>

void set_mode(int new_mode)
{
    if(new_mode < 2  && new_mode >= -1)
    {
        mode_show = new_mode;
    }
    else
    {
        if(mode_show = 1)
        {
            printf("Invalid mode specified. Mode 1(US) used.");
        }
        else
        {   
            printf("Invalid mode specified. Mode 0(METRIC) used.");
        }
    }

}

void get_info()
{
    if(mode_show == 0)
    {
        printf("Enter distance traveled in kilometers:");
        scanf("%f",&distance);
        printf("Enter fuel consumed in liters:");
        scanf("%f",&flue);
    }
    if(mode_show == 1)
    {
        printf("Enter distance traveled in miles:");
        scanf("%f",&distance);
        printf("Enter fuel consumed in gallons:");
        scanf("%f",&flue);
    }
}

void show_info()
{
    if (mode_show == 0)
    {
        printf("Fuel consumption is %.2f liters per 100 km.",flue/distance*100);
    }
    else
    {
        printf("Fuel consumption is %.2f miles per gallon",distance/flue);
    }
}