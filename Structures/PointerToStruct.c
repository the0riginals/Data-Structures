#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<conio.h>
typedef struct Student
{
    char name[30];
    char course[20];
    int r_no;
    int fees;
}STUDENT;

int main()
{
    STUDENT s1;
    STUDENT *ps1;
    ps1 = &s1;
    printf("\nEnter the details of the student : ");
    printf("\nEnter the name of the student : ");
    gets(ps1->name);        
    printf("\nEnter the course of the student :");
    gets(ps1->course);                         //ps1->name is equivalent to (*ps1).name
    printf("\nEnter the roll no of the student : ");
    scanf("%d", &ps1->r_no);
    printf("\nEmter the fees of the student : ");
    scanf("%d", &ps1->fees);
    printf("\nDetails of Student");
    printf("\nName : %s", ps1->name);
    printf("\nRoll No : %d", ps1->r_no);
    printf("\nCourse : %s", ps1->course);
    printf("\nFees : %d", ps1->fees);
    return 0;
}