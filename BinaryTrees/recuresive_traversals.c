#include<stdio.h>
#include<stdlib.h>

typedef struct Node{
    struct Node* lchild;
    struct Node* rchild; 
    int data;
}Node;

void inorder(Node* root){
    if(root ){
        inorder(root->lchild);
        printf("%d",root->data);  
        inorder(root->rchild);
    }
}
void postorder(Node* root){
    if(root){
        postorder(root->lchild);
        postorder(root->rchild);
        printf("%d",root->data);         
    }
}
void preorder(Node* root){
    if(root ){
        printf("%d",root->data);
        preorder(root->lchild);        
        preorder(root->rchild);
    }
}