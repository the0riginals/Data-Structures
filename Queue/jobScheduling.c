#include<stdio.h>
#include<stdlib.h>

// typedef struct job{
//     int prkey;
//     int data;
// }JOB;

typedef struct Node{
    int data ;
    int prkey;
    struct Node * next;
}NODE;


NODE * insertNewJob(NODE * start, int data, int key){
    NODE * newNode = malloc(sizeof(NODE));
    if(newNode == NULL){
        printf("!! OVERFLOW !!");
        return start;
    }
    
    newNode->data = data;
    newNode->prkey = key;
    
    if(start == NULL){
        newNode->next = NULL;
        start = newNode;
        return start;
    }

    NODE * currNode = start;
    NODE * pred = NULL;

    if(start->prkey > newNode->prkey){
        newNode->next = start;
        start = newNode;
        return start;
    }

    while(currNode->prkey < newNode->prkey){
        if(currNode->next == NULL){
            newNode->next = NULL;
            currNode->next = newNode;
            return start;
        }
        pred = currNode;
        currNode = currNode->next;
    }
    newNode->next = pred->next;
    pred->next = newNode;
    return start;
}

NODE * getNextJob(NODE * start){
    if(start == NULL){
        printf("!! NO JOBS LEFT !!");
        return start;
    }
    printf("\nPriority : %d\t Data : %d", start->prkey, start->data);
    return start->next;
}

void traverseJobs(NODE * start){
    if(start != NULL){
        NODE * currNode = start;
        printf("\nPrKey\tData");
        while(currNode != NULL){
            printf("\n%d\t%d", currNode->prkey, currNode->data);
            currNode = currNode->next;
        }
    }
}

int main(){
    NODE * start;
    int choice = 0, tkey, tdata;

    while(choice != 4){
        printf("\n---- MENU----");
        printf("\n1. Add new Job");
        printf("\n2. get nextJob");
        printf("\n3. Show all jobs");
        printf("\n4. EXIT");

        printf("\nEnter choice : ");
        scanf("%d", &choice);

        switch(choice){
            case 1:
                printf("\nEnter the priority of the job : ");
                scanf("%d", &tkey);
                printf("\nEnter the data : ");
                scanf("%d", &tdata);
                start = insertNewJob(start, tdata, tkey);
                break;
            
            case 2:
                start = getNextJob(start);
                break;
            
            case 3:
                traverseJobs(start);
                break;
            
            case 4:
                break;
            
            default:
                printf("\nInvalid Choice");
        }
    }
    free(start);
}