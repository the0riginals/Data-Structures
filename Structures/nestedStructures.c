#include<stdio.h>

typedef struct Date_Of_Birth
{
    int dd;
    int mm;
    int yy;
}DOB;

typedef struct Name
{
    char fname[20];
    char mname[20];
    char lname[20];
}NAME;

typedef struct Student
{
    int roll_no;
    NAME name;
    DOB dob;
    char branch[4];
}STUDENT;

void main()
{
    STUDENT s1;
    printf("\nNAME : ");
    scanf("%s %s %s", &s1.name.fname, &s1.name.mname, &s1.name.lname);
    printf("\nDOB : ");
    scanf("%d %d %d", &s1.dob.dd, &s1.dob.mm, &s1.dob.yy);
    printf("\nRollNo : ");
    scanf("%d", &s1.roll_no);
    printf("\nBranch : ");
    scanf("%d", &s1.branch);

    printf("\nName : %s %s %s", s1.name.fname, s1.name.mname, s1.name.lname);
    printf("\nDOB : %d/%d/%d", s1.dob.dd, s1.dob.mm, s1.dob.yy);
    printf("\nRollNo : %d", s1.roll_no);
    printf("\nBranch : %s", s1.branch);
}

