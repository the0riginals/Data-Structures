#include<stdio.h>
#include<stdlib.h>

typedef struct Node{
    int data;
    struct Node *next;
}NODE;

NODE* pop(NODE *top)
{
    if(top == NULL)
    {
        printf("!! Underflow !!");
    }
    else
    {
        printf("\nPopped element : %d", top->data);
        top = top->next;
        return top;
    }
}

NODE* push(NODE *top, int element)
{
    NODE *newNode = malloc(sizeof(NODE));
    if(newNode == NULL)
    {
        printf("!! Overflow !!");
        return top;
    }
    else
    {
        newNode->data = element;
        newNode->next = top;
        top = newNode;
        return top;
    }
}


void peek(NODE* top)
{
    if(top == NULL)
        printf("Empty Stack");
    else{
        printf("Top of the stack : %d", top->data);
    }
}

void displayLL(NODE *start)
{
    NODE *currNode;
    currNode = start;
    printf("\n");
    while(currNode != NULL)
    {
        printf("%d\t", currNode->data);
        currNode = currNode->next;
    }
}




void main()
{
    int choice = 0;
    int element;
    NODE *top = NULL;

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
                top = push(top, element);
                break;
            
            case 2:
                top = pop(top);
                break;
            
            case 3:
                peek(top);
                break;

            case 4:
                break;

            default:
                printf("\nInvalid Choice") ;   
        }
    }
}