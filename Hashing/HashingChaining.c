//Hashing 
// Uses Chaining technique as a means for Collission Resolution


#include<stdio.h>
#include<stdlib.h>
#define mod 10

typedef struct hashNode{
    int data;
    struct hashNode * next;
}HashNode;

HashNode * hashTable[mod];

void __init__(){
    for(int i =0; i<mod; i++){
        hashTable[i] = NULL;
    }
}

int getKey(int data){
    return data % mod;
}

HashNode * insertNode(HashNode * start, int data){
    HashNode * newNode = malloc(sizeof(HashNode));
    if(newNode == NULL){
        printf("\n!! OVERFLOW !!");
        return start;
    }

    newNode->data = data;
    newNode->next = NULL;
    
    if(start == NULL){
        start = newNode;
        return start;
    }

    HashNode * currNode = start;
    while(currNode->next != NULL){
        currNode = currNode->next;
    }
    currNode->next = newNode;
    return start;
    
}

void insert(int data){
    int key = getKey(data);
    hashTable[key] = insertNode(hashTable[key], data);
}


void findDataHelper(HashNode * start, int data){
    HashNode * currNode = start;
    
    while(currNode->data != data){
        if(currNode->next == NULL){
            printf("\n!! Does Not Exist !!");
            return;
        }
        currNode = currNode->next;
    }
    printf("\n!! Exists !!");
}


void findData(int data){
    int key = getKey(data);
    findDataHelper(hashTable[key], data);
}


HashNode * deleteDataHelper(HashNode * start, int data){
    if(start == NULL){
        printf("\n!! Data Not Found !!");
        return start;
    }

    if(start->data == data){
        return start->next;
    }

    HashNode * currNode = start;

    while((currNode->next)->data != data){
        if((currNode->next)->next == NULL){
            printf("\n!! Data Not Found !!");
            return start;
        }
        currNode = currNode->next;
    }

    currNode->next = (currNode->next)->next;
    return start;
}


void deleteData(int data){
    int key = getKey(data);
    hashTable[key] = deleteDataHelper(hashTable[key], data);
}

void traverseHelper(HashNode * start){
    if(start != NULL){
        printf("\n");
        HashNode * currNode = start;
        while(currNode != NULL){
            printf("%d -> ", currNode->data);
            currNode = currNode->next;
        }
    }
}

void traverse(){
    for(int i = 0; i<mod; i++){
        traverseHelper(hashTable[i]);
    }
}


int main(){
   __init__();
    int choice = 0, temp;

    while(choice != 5){
        printf("\n---- MENU ----");
        printf("\n1.  insert Data");
        printf("\n2.  get Data");
        printf("\n3.  delete Data");
        printf("\n4.  Traverse");
        printf("\n5.  EXIT");
        printf("\nEnter your choice : ");
        scanf("%d", &choice);

        switch(choice){
            case 1:
                printf("\nEnter the new data: ");
                scanf("%d", &temp);
                insert(temp);
                break;
            
            case 2:
                printf("\nWhich data to fetch :");
                scanf("%d", &temp);
                findData(temp);
                break;
            
            case 3:
                printf("\nWhich data to delete : ");
                scanf("%d", &temp);
                deleteData(temp);

            case 4:
                traverse();
                break;
                
            case 5:
                break;

            default:
                printf("\n!! Invalid Choice !!");
        }
    } 
}