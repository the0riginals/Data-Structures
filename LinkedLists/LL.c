#include<stdio.h>
#include<conio.h>
#include<stdlib.h>

typedef struct Node{
    int data;
    struct Node * next;
}NODE;



NODE * insertBeg(NODE * start, int data){
    
    NODE * newNode = malloc(sizeof(NODE));
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

    newNode->data = data;
    newNode->next = start;
    start = newNode;
    return start;
}



NODE * insertEnd(NODE * start, int data){
    NODE * newNode = malloc(sizeof(NODE));
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

    NODE * currNode = start;
    while(currNode->next != NULL){
        currNode = currNode->next;
    }   
    newNode->data = data;
    newNode->next = NULL;
    currNode->next = newNode;
    return start;
}



NODE * insertAfter(NODE * start, int data, int after){
    NODE * newNode = malloc(sizeof(NODE));
    if(newNode == NULL){
        printf("\n\a!! OVERFLOW !!");
        return start;
    }

    if(start == NULL){
        printf("\n\a!! THE LIST IS EMPTY !!");
        return start;
    }

    NODE * currNode = start;
    while(currNode->data != after){
        if(currNode->next == NULL){
            printf("\n\a !! THE NODE WITH THE GIVEN VALUE WAS NOT FOUND !!");
            return start;
        }
        currNode = currNode->next;
    }
    newNode->data = data;
    newNode->next = currNode->next;
    currNode->next = newNode;
    return start;
}



NODE * deleteBeg(NODE * start){
    if(start == NULL){
        printf("\n\a!! UNDERFLOW !!");
        return start;
    }
    printf("Deleted Value: %d", start->data);
    return start->next;
}


//Some bug (if the value is not in the List then doesn't work properly)
NODE * deleteValue(NODE * start, int value){
    if(start == NULL){
        printf("\n\a!! UNDERFLOW !!");
        return start;
    }
    if(start->data == value){
        return deleteBeg(start);
    }

    NODE * currNode = start;
    while((currNode->next)->data != value){
        if((currNode->next)->next == NULL){
            printf("\n\a !! THE NODE WITH THE GIVEN VALUE WAS NOT FOUND !!");
            return start;
        }
        currNode = currNode->next;
    }
    currNode->next = (currNode->next)->next;
    return start;
}



NODE * deleteEnd(NODE * start){
    if(start == NULL){
        printf("\n\a!! UNDERFLOW !!");
        return start;
    }
    if(start->next == NULL){
        return NULL;
    }

    NODE * currNode = start;
    while(1){
        if((currNode->next)->next == NULL){
            printf("\nDeleted Node : %d", (currNode->next)->data);
            currNode->next = NULL;
            return start;
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
                start = insertBeg(start, temp);
                break;
            
            case 2:
                printf("\nEnter the new value: ");
                scanf("%d", &temp);
                start = insertEnd(start, temp);
                break;

            case 3:
                printf("\nEnter the new value: ");
                scanf("%d", &temp);
                printf("\nEnter the value after which to add the value: ");
                scanf("%d", &temp2);
                start = insertAfter(start, temp, temp2);
                break;

            case 4:
                start = deleteBeg(start);
                break;

            case 5:
                start = deleteEnd(start);
                break;

            case 6:
                printf("\nEnter the value to delete: ");
                scanf("%d", &temp);
                start = deleteValue(start, temp);
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
