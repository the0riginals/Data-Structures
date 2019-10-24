#include<stdio.h>
#include<stdlib.h>


typedef struct Node{
    int data;
    struct Node * next;
}NODE;


NODE * enqueue(NODE * start, int data){
    NODE * newNode = malloc(sizeof(NODE));
    
    if(newNode == NULL){
        printf("\n!! OVERFLOW !!");
        return start;
    }
    newNode->data = data;
    if(start == NULL){
        newNode->next = NULL;
        return newNode;
    }
    else{
        newNode->next = start;
        start = newNode;
        return start;
    }
}


NODE * dequeue(NODE * start){
    if(start == NULL){
        printf("!! UNDERFLOW !!");
        return start;
    }
    NODE * temp = start;
    if(temp->next == NULL){
        return NULL;
    }
    else{
        while((temp->next)->next != NULL){
            temp = temp->next;
        }
        temp->next = NULL;
        return start;
    }
}


void traverseQueue(NODE * start){
    NODE * temp = start;
    printf("\n");
    while(temp != NULL){
        printf("%d -> ", temp->data);
        temp = temp->next;
    }
    printf("NULL");
}


int main(){
    NODE *start = NULL;
    int choice = 0;
    int temp;

    while(choice != 4){
        printf("\n---- MENU ----");
        printf("\n1. Enqueue");
        printf("\n2. Dequeue");
        printf("\n3. Traverse Queue");
        printf("\n4. EXIT");
        printf("\nEnter your choice : ");

        scanf("%d", &choice);

        switch(choice){
            case 1:
                printf("\nEMter the new element to be added : ");
                scanf("%d", &temp);
                start = enqueue(start, temp);
                break;

            case 2:
                start = dequeue(start);
                break;
            
            case 3:
                traverseQueue(start);
                break;
            
            case 4:
                break;
            
            default:
                printf("\n!! Invalid Choice !!");
        }   
    }
    free(start);
}