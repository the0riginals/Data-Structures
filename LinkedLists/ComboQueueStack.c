#include<stdio.h>
#include<conio.h>
#include<stdlib.h>

typedef struct node{
    int data;
    struct node *next;
}NODE;


// Add a new Node ath the end of the list
NODE* enqueue(NODE *start, int data){
    NODE *newNode = malloc(sizeof(NODE));
    if(newNode == NULL){
        printf("\n\a!! OVERFLOW !!");
        return start;
    }
    if(start == NULL){
        newNode->data = data;
        newNode->next = NULL;
        start = newNode;
        return start;
    }
    else{

        NODE *currNode = start;
        while(currNode->next != NULL){
            currNode = currNode->next;
        }
        newNode->data = data;
        newNode->next = NULL;
        currNode->next = newNode;
        return start;
    }
}


// Add a new Node at the beginning of the list
NODE * push(NODE* start, int data){

    NODE * newNode = malloc(sizeof(NODE));
    if (newNode == NULL){
        printf("\n\a!! OVERFLOW !!");
        return start;
    }

    if(start == NULL){
        newNode->data = data;
        newNode->next = NULL;
        start = newNode;
        return start;
    }

    else{
        newNode->data = data;
        newNode->next = start;
        start = newNode;
        return start;
    }
}


// Remove a node from the beginning of the list
NODE * pop(NODE * start){
    if(start == NULL){
        printf("\n\a!! UNDERFLOW !!");
        return start;
    }

    NODE * temp = start;
    start = start->next;
    printf("\nPopped Element : %d", temp->data);
    return start;  
}


// Remove a node from the beginning of the list
NODE * dequeue(NODE * start){
    if(start == NULL){
        printf("!! UNDERFLOW !!");
        return start;
    }

    NODE * temp = start;
    start = start->next;
    printf("Dequeued element : %d", temp->data);
    return start;
}


// Prints the contents of the linkedList from start to end
void traverse(NODE * start){
    NODE * currNode = start;
    if(currNode == NULL){
        printf("\n\aEmpty Queue...");
    }
    printf("\n");
    while(currNode != NULL){
        printf("%d -> ", currNode->data);
        currNode = currNode->next;
    }
}

void main(){
    NODE *start;
    start = NULL;
    int choice = 0, temp;
    while(choice != 6)
    {
        printf("\n=========MENU==========");
        printf("\n1.  Push");
        printf("\n2.  Pop");
        printf("\n3.  Enqueue");
        printf("\n4.  Dequeue");
        printf("\n5.  Display List");
        printf("\n6.  EXIT");
        printf("\nChoice :   ");
        scanf("%d", &choice);

        switch(choice)
        {
            case 1:
                printf("\nEnter the element to add : ");
                scanf("%d", &temp);
                start = push(start, temp);
                break;

            case 2:
                start = pop(start);
                break;

            case 3:
                printf("\nEnter the element to add : ");
                scanf("%d", &temp);
                start = enqueue(start, temp);
                break;
            
            case 4:
                start = dequeue(start);
                break;

            case  5:
                traverse(start);
                break;
            
            case 6:
                printf("!! The Originals !!");
                break;

            default:
                printf("\a\n!!Invalid Choice!!");
        }
    }
}
