#include<stdio.h>
#include<stdlib.h>

typedef struct Node
{
    int data;
    struct Node *next; 
}NODE;

int main()
{
    int n, tmp;
    NODE *start = NULL;
    NODE *temp;
    printf("\nHow many elements in the linked list : ");
    scanf("%d", &n);
    printf("\nEnter the elements : ");
    
    
    for(int i =0; i<n; i++)
    {
        scanf("%d", &tmp);
        NODE *new_node;
        new_node = malloc(sizeof(NODE));
        new_node->data = tmp;
        new_node->next = NULL;

        if(start == NULL)
        {
            start = new_node;
        }
        else{
            temp = start;
            while(temp->next != NULL)
                temp = temp->next;
            temp->next = new_node;
        }
    }

    temp = start;
    printf("\nThe data in LL : ");
    while(temp != NULL)
    {
        printf("%d\t", temp->data);
        temp = temp->next;
    }
}