#include<stdio.h>
#include<stdlib.h>


typedef struct Node{
    int data;
    struct Node * left, *right;
}NODE;


int findLargest(NODE * root){
    if(root == NULL){
        return -1;
    }
    while(root->right != NULL){
        root = root->right;
    }
    return root->data;
}   


int findSmallest(NODE * root){
    if(root == NULL){
        return -1;
    }
    while(root->left != NULL){
        root = root->left;
    }
    return root->data;
}


NODE * insertNode(NODE * root, int data){
    NODE * newNode = malloc(sizeof(NODE));
    if(newNode == NULL){
        printf("\n!! OVERFLOW !!");
        return root;
    }
    newNode->data = data;
    newNode->left = newNode->right = NULL;

    if(root == NULL){
        root = newNode;
        return root;
    }

    NODE * parent = NULL;
    NODE * currNode = root;
    while(currNode != NULL){

        parent = currNode;

        if(data > currNode->data)
            currNode = currNode->right;
        else
            currNode = currNode->left;
    }

    if(data > parent->data)
        parent->right = newNode;
    else
        parent->left = newNode;

    return root;
}


NODE * searchNode(NODE * root, int data){
    if(root == NULL){
        printf("!! Data Not Found !!");
        return NULL;
    }
    if(root->data == data){
        return root;
    }
    else if(data < root->data){
        return searchNode(root->left, data);
    }
    else{
        return searchNode(root->right, data);
    }
}


void deleteNode(NODE * * root, int data){
    if(*root == NULL){
        printf("!! Value NOT Found !!");
        return;
    }
    else if((*root)->data > data){
        deleteNode(&(*root)->left, data);
    }
    else if((*root)->data < data){
        deleteNode(&(*root)->right, data);
    }
    else{
        if((*root)->left == NULL && (*root)->right == NULL){
            *root = NULL;
            return;
        }
        if((*root)->left != NULL && (*root)->right ==  NULL){
            (*root) = (*root)->left;
            return;
        }
        if((*root)->right != NULL && (*root)->left == NULL){
            (*root) = (*root)->right;
            return;
        }
        else{
            int temp = findLargest((*root)->left);
            (*root)->data = temp;
            deleteNode(&(*root)->left, temp);
        }
    }
}


void inorder(NODE * root){
    if(root != NULL){
        inorder(root->left);
        printf("%d\t", root->data);
        inorder(root->right);
    }
}


void preorder(NODE * root){
    if(root != NULL){
        printf("%d\t", root->data);
        preorder(root->left);
        preorder(root->right);
    }
}


void postorder(NODE * root){
    if(root != NULL){
        postorder(root->left);
        postorder(root->right);
        printf("%d\t", root->data);
    }
}


int countNodes(NODE * start){
    if(start != NULL){
        return(countNodes(start->left) + countNodes(start->right) + 1);
    }
}


int countExternalNodes(NODE * start){
    if(start == NULL)
        return 0;
    else if(start->left == NULL && start->right == NULL)
        return 1;
    else
        return (countExternalNodes(start->left) + countExternalNodes(start->right));
}


int countInternalNodes(NODE * start){
    if(start == NULL)
        return 0;
    if(start->left == NULL && start->right == NULL)
        return 0;
    else
        return (countExternalNodes(start->left) + countExternalNodes(start->right) + 1);
}


int main(){
    NODE * root = NULL;
    int temp, choice = 0;

    while(choice != 11){
        printf("\n---- MENU ----");
        printf("\n1.  Insert Node");
        printf("\n2.  Find Smallest");
        printf("\n3.  Find Greatest");
        printf("\n4.  Delete Node");
        printf("\n5.  In-Order Print");
        printf("\n6.  Pre-Order Print");
        printf("\n7.  Post-Order Print");
        printf("\n8.  Total Nodes");
        printf("\n9.  Total Internal Nodes");
        printf("\n10. Total External Nodes");
        printf("\n11. EXIT");
        printf("\nEnter your choice : ");
        scanf("%d", &choice);

        switch(choice)
        {
        case 1:
            printf("\nEnter the data to be added : ");
            scanf("%d", &temp);
            root = insertNode(root, temp);
            break;
        
        case 2:
            printf("\nSmallest : %d", findSmallest(root));
            break;
        
        case 3:
            printf("\nLargest : %d", findLargest(root));
            break;
        
        case 4:
            printf("\nEnter the data to delete:  ");
            scanf("%d", &temp);
            deleteNode(&root, temp);
            break;
        
        case 5:
            inorder(root);
            break;
        
        case 6:
            preorder(root);
            break;
        
        case 7:
            postorder(root);
            break;
        
        case 8:
            printf("\nTotal Nodes : %d",countNodes(root));
            break;
        
        case 9:
            printf("\nTotal Internal Nodes : %d", countInternalNodes(root));
            break;
        
        case 10:
            printf("\nTotal External Nodes : %d", countExternalNodes(root));
            break;
        
        case 11:
            break;

        default:
            printf("\n!! Invalid Choice !!");
        }

    }
    free(root);
}

