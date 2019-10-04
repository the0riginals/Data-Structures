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
		printf("\n\a!! UNDERFLOW !!");
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
	
	//(currNode->prev)->next = currNode->next;
	currNode = currNode->prev;
	currNode->next = (currNode->next)->next;
	return start;
} 


NODE * deleteBeg(NODE * start){
	if(start == NULL){
		printf("\n\a!! UNDERFLOW !!");
		return start;
	}
	printf("\nDeleted value: %d", start->data);
	start = start->next;
	start->prev = NULL;
	return start;
}


NODE * deleteEnd(NODE * start){
	if(start == NULL){
		printf("\n\a!! UNDERFLOW !!");
		return start;
	}

	NODE * currNode = start;
	while(currNode->next != NULL){
		currNode = currNode->next;
	}
	printf("\nDeleted Value: %d", currNode->data);
	currNode = currNode->prev;
	currNode->next = NULL;
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


void reverseTraverse(NODE * start){
	if(start == NULL){
		printf("\n\a!!The List is Empty!!");
		return;
	}
	NODE * currNode = start;
	while(currNode->next != NULL){
		currNode = currNode->next;
	}
	printf("\n");
	while(currNode != NULL){
		printf("%d -> ", currNode->data);
		currNode = currNode->prev;
	}
	printf("NULL");
}


void main(){

	int choice, temp;
	NODE * start = NULL;
	
	
	while(choice != 8){
	
		printf("\n====================");
		printf("\n         MENU       ");
		printf("\n====================");
		printf("\n1.  Insert Beginning");
		printf("\n2.  Insert End");
		printf("\n3.  Delete value");
		printf("\n4.  Delete Beg");
		printf("\n5.  Delete End");
		printf("\n6.  Print List");
		printf("\n7.  Reverse Traverse");
		printf("\n8.     EXIT");
		
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
				printf("\nEnter the value to be deleted: ");
				scanf("%d", &temp);
				start = deleteValue(start, temp);
				break;
			
			case 4:
				start = deleteBeg(start);
				break;
			
			case 5:
				start = deleteEnd(start);
				break;
			
			case 6:
				traverseLL(start);
				break;
		
			case 7:
				reverseTraverse(start);
				break;
			
			case 8:
				printf("\n!!!  The Originals wish you a Good Luck ;-)   !!!");
				break;
			
			default:
				printf("\n INVALID CHOICE");
		}
	}
}
