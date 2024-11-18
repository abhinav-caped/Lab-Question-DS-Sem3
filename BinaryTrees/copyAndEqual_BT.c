#include<stdio.h>
#include<stdlib.h>

typedef struct Node{
    struct Node* lchild;
    struct Node* rchild;
    int data;
}Node;

Node* createNode(int ele){
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->data = ele;
    newNode->lchild = newNode->rchild = NULL;
    return newNode;
}
Node* copyTree(Node* root){
    if(root == NULL) return NULL;
    Node* newRoot = createNode(root->data);
    newRoot->lchild = copyTree(root->lchild);
    newRoot->rchild = copyTree(root->rchild);
    return newRoot;
}
int areEqual(Node* root1,Node* root2){
    if(root1==NULL && root2 == NULL){
        return 1;
    }
    if(root1 != NULL && root2 != NULL){
        return(root1->data == root2->data && areEqual(root1->lchild,root2->lchild) && areEqual(root1->rchild,root2->rchild));
    }
    return 0;
}