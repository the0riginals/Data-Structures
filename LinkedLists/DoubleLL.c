#include<stdio.h>
#include<stdlib.h>

typedef struct node{
	int data;
	struct node * next;
	struct node * prev;
}NODE;


NODE * insertBeg(NODE * start, int data){
	NODE * newNode = malloc(sizeof(NODE));
	
	if(newNode == NULL){
		printf("\n!! OVERFLOW !!");
		return start;	
	}
	
	if(start == NULL){
		newNode->data = data;
		newNode->next = NULL;
		newNode->prev = NULL;
		return newNode;
	}
	
	newNode->data = data;
	newNode->next = start;
	newNode->prev = NULL;
	start = newNode;
	return start;
}


NODE * insertEnd(NODE * start, int data){
	NODE * newNode = malloc(sizeof(NODE));
	
	if(newNode == NULL){
		printf("\n!! OVERFLOW !!");
		return start;
	}
	
	if(start == NULL){
		newNode->data = data;
		newNode->next = NULL;
		newNode->prev = NULL;
		return newNode;
	}
	
	NODE * currNode = start;
	while(currNode->next != NULL){
		currNode = currNode->next;	
	}
	
	newNode->data = data;
	newNode->prev = currNode;
	newNode->next = currNode->next;
	currNode->next = newNode;
	return start;
}


NODE * deleteValue(NODE * start, int data){

	if(start == NULL){
		printf("\n The List is Empty");
		return start;
	}
	
	
	NODE * currNode = start;
	while(currNode->data != data){
		if(currNode->next == NULL){
			printf("\n The data was not found in the list");
			return start;
		}
		currNode = currNode->next;
	}
	
	(currNode->prev)->next = currNode->next;
	return start;
} 


void traverseLL(NODE * start){

	NODE * currNode = start; 
	
	if(start == NULL){
		printf("\nThe List is EMPTY");
		return;
	}
	printf("\n");
	while (currNode != NULL){
		printf("%d -> ", currNode->data);
		currNode = currNode->next;
	}
	printf("NULL");
}



void main(){

	int choice, temp;
	NODE * start = NULL;
	
	
	while(choice != 4){
	
		printf("\n==================");
		printf("\n        MENU      ");
		printf("\n==================");
		printf("\n1.  Insert Beginning");
		printf("\n2.  Insert End");
		printf("\n3.  Print List");
		printf("\n4.  Delete value");
		printf("\n5.     EXIT");
		
		printf("\nEnter your choice : ");
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
				traverseLL(start);
				break;
				
			case 4:
				printf("\nEnter the value to be deleted: ");
				scanf("%d", &temp);
				start = deleteValue(start, temp);
				break;
			
			case 5:
				printf("\n The Originals wish you a Good Luck");
				break;
				
			default:
				printf("\n INVALID CHOICE");
		}
	}
}

