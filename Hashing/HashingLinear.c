#include<stdio.h>
#define mod 10


//Collission Resolution using Linear Probing
 
int hash[10];

int findKey(int num){
    return num % mod; 
}

void insert(int data){
    int key = findKey(data);
    if(hash[key] == -1){
        hash[key] = data;
        return;
    }
    int i = key;
    while(i < mod){
        if(hash[i] == -1){
            hash[i] = data;
            return;
        }
        i += 1;
    }
    printf("!! OVERFLOW !!");
}

void traverse(){
    printf("\n");
    for(int i = 0; i<mod; i++){
        if(hash[i] == -1){
            printf("NULL\t");
        }
        else{
            printf("%d\t", hash[i]);
        }
    }
}

void getData(int data){
    int key = findKey(data);
    if(hash[key] == data){
        printf("Exists");
        return;
    }
    int i = key;
    while(i < mod){
        if(hash[i] == data){
            printf("\nExists");
            return;
        }else if(hash[i] == -1){
            printf("\nDoes Not Exist");
            break;
        }
        i += 1;
    }
    printf("\nDoes Not Exist");
    return;
}


int main(){
    //initializing hash table
    for(int i = 0; i<mod; i++){
        hash[i] = -1;
    }

    int choice = 0, temp;
    while(choice != 4){
        printf("\n---- MENU ----");
        printf("\n1.  insert Data");
        printf("\n2.  get Data");
        printf("\n3.  Traverse");
        printf("\n4.  EXIT");
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
                getData(temp);
                break;
            
            case 3:
                traverse();
                break;
            case 4:
                break;

            default:
                printf("\n!! Invalid Choice !!");
        }
    } 
}

