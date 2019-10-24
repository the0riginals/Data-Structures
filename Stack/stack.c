#include<stdio.h>
#include<stdlib.h>
#define CAPACITY 50
int stack[CAPACITY], top = -1;

void push(int element)
{
    stack[++top] = element;
}

int pop()
{
    return stack[top--];
}

int peek()
{
    return stack[top];
}

void main()
{
    int choice = 0;
    int element;

    while(choice != 4)
    {
        printf("\n\n     Menu     ");
        printf("\n====================");
        printf("\n| 1 | Push element");
        printf("\n| 2 | Pop element");
        printf("\n| 3 | Peek element");
        printf("\n| 4 | EXIT");

        printf("Choice : ");
        scanf("%d", &choice);

        switch(choice)
        {
            case 1:
                printf("\nEnter the element to be pushed : ");
                scanf("%d", &element);
                push(element);
                break;
            
            case 2:
                printf("\n Popped Element : %d", pop());
                break;
            
            case 3:
                printf("\n Top : %d", peek());
                break;

            case 4:
                break;

            default:
                printf("\nInvalid Choice") ;   
        }
    }
}