#include<stdio.h>
#include<stdlib.h>

typedef struct node{
    int data;
    struct node * next;
}NODE;

NODE * insertEnd(NODE * start, int data){
    NODE * newnode = malloc(sizeof(NODE));
    if(newnode==NULL){
        printf("\nUnderflow");
        return start;
    }
    newnode->data = data;
    if(start==NULL){
        start = newnode;
        newnode->next = NULL;
        return start;
    }
    NODE * temp = start;
    while(temp->next!=NULL){
        temp = temp->next;
    }
    newnode->next = NULL;
    temp->next = newnode;
    return start;

}

NODE * copyList(NODE * start){
    if(start==NULL){
        return NULL;
    }
    else{
        NODE * newnode = malloc(sizeof(newnode));
        newnode->data = start->data;

        newnode->next = copyList(start->next);

        return newnode;
    }
}

void printList(NODE * start){
    if(start==NULL){
        printf("\nList is empty");

    }
    else{
        NODE * temp = start;
        printf("\n");
        while(temp){
            printf("%d->", temp->data);
            temp = temp->next;
        }
        printf("NULL");
    }
}

int main(){
    int ch, data;
    NODE * start = NULL;
    NODE *  newstart = NULL;
    do{
        printf("\n***MENU***");
        
        printf("\n1. Insert values into list");
        printf("\n2. Copy Linked list");
        printf("\n3. Print original list");
        printf("\n4. Print copy of list");
        printf("\n5. Exit");
        printf("\nEnter your choice: ");
        scanf("%d", &ch);
        switch (ch)
        {
        case 1:
            printf("\nEnter value: ");
            scanf("%d", &data);
            start = insertEnd(start, data);
            break;
        case 2:
            newstart = copyList(start);
            printf("\nList copied");
            break;
        case 3:
            printList(start);
            break;
        case 4:
            printList(newstart);
            break;
        case 5:
            printf("\nBye");   
            break; 
        
        default:
            printf("\nInvalid choice");
            break;
        }
    }while(ch!=5);


}
