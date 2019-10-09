#include<stdio.h>
#include<stdlib.h>

typedef struct Node{
    int data;
    struct Node * next;
}NODE;



void insertBeg(NODE * * start, int data){
    
    NODE * newNode = malloc(sizeof(NODE));
    if(newNode == NULL){
        printf("\n\a!! OVERFLOW !!");
        return;
    }

    if(*start == NULL){
        newNode->data = data;
        newNode->next = NULL;
        *start = newNode;
        return;
    }

    newNode->data = data;
    newNode->next = *start;
    *start = newNode;
}



void insertEnd(NODE * * start, int data){
    NODE * newNode = malloc(sizeof(NODE));
    if(newNode == NULL){
        printf("\n\a!! OVERFLOW !!");
        return;
    }

    if(*start == NULL){
        newNode->data = data;
        newNode->next = NULL;
        *start = newNode;
        return;
    }

    NODE * currNode = *start;
    while(currNode->next != NULL){
        currNode = currNode->next;
    }   
    newNode->data = data;
    newNode->next = NULL;
    currNode->next = newNode;
}



void insertAfter(NODE * * start, int data, int after){
    NODE * newNode = malloc(sizeof(NODE));
    if(newNode == NULL){
        printf("\n\a!! OVERFLOW !!");
        return;
    }

    if(*start == NULL){
        printf("\n\a!! THE LIST IS EMPTY !!");
        return;
    }

    NODE * currNode = *start;
    while(currNode->data != after){
        if(currNode->next == NULL){
            printf("\n\a !! THE NODE WITH THE GIVEN VALUE WAS NOT FOUND !!");
            return;
        }
        currNode = currNode->next;
    }
    newNode->data = data;
    newNode->next = currNode->next;
    currNode->next = newNode;
}



void deleteBeg(NODE * * start){
    if(*start == NULL){
        printf("\n\a!! UNDERFLOW !!");
        return;
    }
    printf("Deleted Value: %d", (*start)->data);
    *start = (*start)->next;
}


void deleteValue(NODE * * start, int value){
    if(*start == NULL){
        printf("\n\a!! UNDERFLOW !!");
        return;
    }
    if((*start)->data == value){
        printf("Deleted Value: %d", (*start)->data);
        *start = (*start)->next;
        return;
    }

    NODE * currNode = *start;
    while((currNode->next)->data != value){
        if((currNode->next)->next == NULL){
            printf("\n\a !! THE NODE WITH THE GIVEN VALUE WAS NOT FOUND !!");
            return;
        }
        currNode = currNode->next;
    }
    currNode->next = (currNode->next)->next;
    return;
}



void deleteEnd(NODE * * start){
    if(*start == NULL){
        printf("\n\a!! UNDERFLOW !!");
        return ;
    }
    if((*start)->next == NULL){
        printf("\nDeleted Node : %d", (*start)->data);
        *start = NULL;
    }

    NODE * currNode = *start;
    while(1){
        if((currNode->next)->next == NULL){
            printf("\nDeleted Node : %d", (currNode->next)->data);
            currNode->next = NULL;
            return;
        }
        currNode = currNode->next;
    }
}



void traverseLL(NODE * start){
    if(start == NULL){
        printf("\n\a!! THE LIST IS EMPTY !!");    
    }
    else{
        NODE * currNode = start;
        printf("\n");
        while(currNode != NULL){
            printf("%d -> ", currNode->data);
            currNode = currNode->next;
        }
        printf("NULL");
    }
}



void main(){
    NODE * start;
    start = NULL;
    int length = 0, choice = 0, temp, temp2;

    while(choice != 8){
        printf("\n===================");
        printf("\n       MENU        ");
        printf("\n===================");
        printf("\n1.  Insert Beginning");
        printf("\n2.  Insert Ending");
        printf("\n3.  Insert After");
        printf("\n4.  Delete Beginning");
        printf("\n5.  Delete Ending");
        printf("\n6.  Delete Value");
        printf("\n7.  Traverse List");
        printf("\n8.  EXIT");        
    
        printf("\nEnter choice : ");
        scanf("%d", &choice);


        switch(choice){
            case 1:
                printf("\nEnter the new value: ");
                scanf("%d", &temp);
                insertBeg(&start, temp);
                break;
            
            case 2:
                printf("\nEnter the new value: ");
                scanf("%d", &temp);
                insertEnd(&start, temp);
                break;

            case 3:
                printf("\nEnter the new value: ");
                scanf("%d", &temp);
                printf("\nEnter the value after which to add the value: ");
                scanf("%d", &temp2);
                insertAfter(&start, temp, temp2);
                break;

            case 4:
                deleteBeg(&start);
                break;

            case 5:
                deleteEnd(&start);
                break;

            case 6:
                printf("\nEnter the value to delete: ");
                scanf("%d", &temp);
                deleteValue(&start, temp);
                break;
            
            case 7:
                traverseLL(start);
                break;
            
            case 8:
                break;
            
            default:
                printf("\n\a!! INVALID CHOICE !!");
        }
    }
}