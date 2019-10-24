 #include<stdio.h>
typedef struct student
{
    int roll_no;
    char name[30];
    char branch[4];
}stud;

void main()
{

    stud s1 = {23, "JaideepMore", "IT"};
    printf("\nRoll No : %d", s1.roll_no);
    printf("\nName : %s", s1.name);
    printf("\nBranch : %s", s1.branch);
}
