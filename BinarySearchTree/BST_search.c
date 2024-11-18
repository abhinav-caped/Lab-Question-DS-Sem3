#include<stdio.h>
#include<stdlib.h>

typedef struct Node{
    struct Node* lchild;
    struct Node* rchild;
    int data;

}Node;

Node* createNode(int ele){
    Node* newNode = (Node*) malloc(sizeof(Node));
    newNode->lchild = newNode->rchild = NULL;
    newNode->data = ele;
    return newNode; 
}

Node* BSTsearchIterative(Node* root,int key){
    if(root == NULL){
        return root;
    }
    
    while(root!=NULL){
        if(root->data == key){
            return root;
        }
        if(key>root->data){
            root = root->rchild;
        }else{
            root = root->lchild;
        }

    }
    return NULL;
}

Node* BSTsearchRecursive(Node* root,int key){
    if(root==NULL) return root;
    if(root){
        if(root->data == key) return root;
        if(root->data>key){
            return BSTsearchRecursive(root->lchild,key);
        }else{
            return BSTsearchRecursive(root->rchild,key);
        }
    }
}