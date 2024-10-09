/*
Write a program that creates a structure template with two members according to the
following criteria:
a. The first member is a social security number. The second member is a structure
with three members. Its first member contains a first name, its second member
contains a middle name, and its final member contains a last name. Create and
initialize an array of five such structures. Have the program print the data in this
format:
Dribble, Flossie M. –– 302039823
Only the initial letter of the middle name is printed, and a period is added. Neither the
initial (of course) nor the period should be printed if the middle name member is empty.
Write a function to do the printing; pass the structure array to the function.
b. Modify part a. by passing the structure value instead of the address.
*/


#include <stdio.h>
#include <string.h>

#define SIZENAME 10
#define LENG 5

struct name {
    char firstname[SIZENAME];
    char midname[SIZENAME];
    char lastname[SIZENAME];
};

struct person {
    int ssn ;
    struct name nameperson;
};

void print_by_adr(struct person *people);
void print_by_val(struct person people);

int main()
{
    int i; 
    struct person peoples[LENG] = { 
        {111, {"Nguyen", "Van", "A"}},
        {222,{"Tran", "Quang", "B"}},
        {333,{"Le", "Thi", "C"}},
        {444,{"Ngo", "Thi", "D"}},
        {555,{"Hoang", "Van", "D"}}
    };

    printf("Print poples by adress \n");
    for (i = 0; i < LENG; i++)
    {
        print_by_adr(&peoples[i]);
    }

    printf("Print poples by Value \n");
    for( i = 0; i < LENG; i++)
    {
        print_by_val(peoples[i]);
    }
}

void print_by_adr(struct person *people)
{
    printf("%s, %s " ,people->nameperson.lastname, people->nameperson.firstname);
    if(strcmp(people->nameperson.midname,"") != 0)
    {
        printf("%c. -- ",people->nameperson.midname[0]);
    }
    printf("%d \n",people->ssn);
}

void print_by_val(struct person people)
{
    printf("%s, %s " ,people.nameperson.lastname, people.nameperson.firstname);
    if(strcmp(people.nameperson.midname,"") != 0)
    {
        printf("%c. -- ",people.nameperson.midname[0]);
    }
    printf("%d \n",people.ssn);
}