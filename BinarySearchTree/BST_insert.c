#include<stdio.h>
#include<stdlib.h>

typedef struct Node{
    struct Node* lchild;
    struct Node* rchild;
    int data;
}Node;

Node* insertNode(int ele){
    Node* newNode =(Node*)malloc(sizeof(Node));
    newNode->lchild = NULL;
    newNode->rchild = NULL;
    newNode->data = ele;
    return newNode;
}

Node* insertInBst(Node* root,int ele){
    Node* temp = createNode(ele);
    if(root==NULL){
        return temp;   
    }
    Node* parent = NULL;
    Node* curr = root;
    while(curr!= NULL){
        parent = curr;
        if(curr->data == ele){
            printf("not possible");
            return root;
        }
        else if(curr->data > ele){
            curr = curr->lchild;
        }
        else{
            curr = curr->rchild;
        }
    }
    if(ele<parent->data){
        parent->lchild = temp;
    }else{
        parent->rchild = temp;
    }
    return root;
}