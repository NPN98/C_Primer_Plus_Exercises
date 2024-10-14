/*
Write a program that fits the following recipe:
a. Externally define a name structure template with two members: a string to hold the
first name and a string to hold the second name.
b. Externally define a student structure template with three members: a name
structure, a grade array to hold three floating-point scores, and a variable to hold
the average of those three scores.
c. Have the main() function declare an array of CSIZE (with CSIZE = 4) student
structures and initialize the name portions to names of your choice. Use functions
to perform the tasks described in parts d., e., f., and g.
d. Interactively acquire scores for each student by prompting the user with a student
name and a request for scores. Place the scores in the grade array portion of the
appropriate structure. The required looping can be done in main() or in the
function, as you prefer.
e. Calculate the average score value for each structure and assign it to the proper
member.
f. Print the information in each structure.
g. Print the class average for each of the numeric structure members
*/


#include <stdio.h>
#define SIZENAME 10 
#define SIZESCORE 3
#define CSIZE 4
struct name {
    char first[SIZENAME];
    char second[SIZENAME];
};

struct student {
    struct name namestudent;
    float scores[SIZESCORE];
    float averagescore;
};
 
void getscore(struct student *Student);
void avergescore(struct student *Student);
void printinfo(struct student *Student);

int main()
{
    int i;
    struct student students[CSIZE] = {
        {.namestudent = {"aaa","bbb"}},
        {.namestudent = {"ccc","ddd"}},
        {.namestudent = {"eee","fff"}},
        {.namestudent = {"ggg","hhh"}},
    };
    for(i = 0; i < CSIZE; i++)
    {
        getscore(&students[i]);
    }
    for(i = 0; i < CSIZE; i++)
    {
        avergescore(&students[i]);
    }
    for(i = 0; i < CSIZE; i++)
    {
        printinfo(&students[i]);
    }

}

void getscore(struct student *Student)
{
    int i;
    printf("Enter scores student: %s\n",Student->namestudent.first, Student->namestudent.second);
    for (i = 0; i <SIZESCORE; i++)
    {
        printf("Enter the score %d:", i+1);
        scanf("%f",&Student->scores[i]);
    }
}

void avergescore(struct student *Student)
{
    int i;
    float total = 0;
    for (i = 0; i <SIZESCORE; i++)
    {
        total += Student->scores[i];
    }
    Student->averagescore = total/SIZESCORE;
}

void printinfo(struct student *Student)
{
    int i;
    printf(" Name: %s %s \n",Student->namestudent.first, Student->namestudent.second);
    for (i = 0; i <SIZESCORE; i++)
    {
        printf(" Score %d: %.2f \n",i+1, Student->scores[i]);
    }
    printf("Average score: %.2f\n ",Student->averagescore);
    printf("\n");
}

