#include<stdio.h>
#include<stdlib.h>
#include<string.h>

typedef struct Student
{
    char name[30];
    char course[20];
    int fees;
    int r_no;
}STUDENT;

void main()
{
    STUDENT *ps[1];
    for(int i =0; i<1; i++)
    {
        ps[i] = malloc(sizeof(STUDENT));
        printf("\nEnter the details of the student : ");
        printf("\nEnter the name of the student : ");
        gets(ps[i]->name);        
        printf("\nEnter the course of the student :");
        gets(ps[i]->course);
        printf("\nEnter the roll no of the student : ");
        scanf("%d", &ps[i]->r_no);
        printf("\nEmter the fees of the student : ");
        scanf("%d", &ps[i]->fees);
    }
    for(int i = 0 ; i<1; i++)
    {
        printf("\nName : %s", ps[i]->name);
        printf("\nRoll No : %d", ps[i]->r_no);
        printf("\nCourse : %s", ps[i]->course);
        printf("\nFees : %d", ps[i]->fees);
    }
}
