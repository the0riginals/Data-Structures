#include<stdio.h>
#include<stdlib.h>

typedef struct node{
	int data;
	struct node * next;
}NODE;


NODE * append(NODE * start, int data){

	NODE * newNode = malloc(sizeof(NODE));

	
	if(newNode == NULL){
		printf("\n!! OVERFLOW !!");
		return start;
	}
	
	
	newNode->data = data;
	if(start == NULL){
		newNode->next = NULL;
		start = newNode;
		return start;
	}	
	
	NODE * currNode = start;
	
	while(currNode->next != NULL){
		currNode = currNode->next;
	}
	
	newNode->next = NULL;
	currNode->next = newNode;
	return start;
}


NODE * push(NODE * start, int data){

	NODE * newNode = malloc(sizeof(NODE));
	
	if(newNode == NULL){
		printf("\n!! OVERFLOW !!");
		return start;
	}
	
	newNode->data = data;
	newNode->next = start;
	start = newNode;
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
		printf("\n4.     EXIT");
		
		printf("\nEnter your choice : ");
		scanf("%d", &choice);
		
		
		switch(choice){
			case 1:
				printf("0\nEnter the new value: ");
				scanf("%d", &temp);
				start = push(start, temp);
				break;
			
			case 2:
				printf("0\nEnter the new value: ");
				scanf("%d", &temp);
				start = append(start, temp);
				break;
				
			case 3:
				traverseLL(start);
				break;
				
			case 4:
				break;
			
			default:
				printf("\n INVALID CHOICE");
		}
	}
}

