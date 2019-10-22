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
            //Giving Segmentation fault
            int temp = findLargest((*root)->left);
            (*root)->data = temp;
            deleteNode(root, temp);
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


void main(){
    NODE * root = NULL;
    int temp, n;
    printf("\nEnter n: ");
    scanf("%d", &n);
    for(int i = 0; i<n; i++){
        scanf("%d", &temp);
        root = insertNode(root, temp);
    }
    printf("\ninorder Print\n");
    inorder(root);
    printf("\nLargest : %d", findLargest(root));
    printf("\nSmallest  %d", findSmallest(root));   
    deleteNode(&root, 5);

    printf("\ninorder Print\n");
    inorder(root);
}

