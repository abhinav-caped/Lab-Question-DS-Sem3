#include<stdio.h>
#include<stdlib.h>

typedef struct Node{
    struct Node* lchild;
    int data;
    struct Node* rchild;
}Node;

void itPreorder(Node* root){
    if(root == NULL) return;
    Node* s[100];
    int top =-1;
    s[++top] = root;
    while(top != -1){
        Node* node = s[top--];
        printf("%d",node->data);
        if(node->rchild) s[++top] = node->rchild;
        if(node->lchild) s[++top] = node->lchild;

    }


}
void itPostorder(Node* root ){
    if(root == NULL) return;
    Node* s[100];
    int top=-1;
    Node* lastVisited = NULL;
    while(top>=0 || root != NULL){
        if(root != NULL){
            s[++top] = root;
            root = root->lchild;
        }else{
            Node* peek = s[top];
            if(peek->rchild != NULL && lastVisited != peek->rchild){
                s[++top] = peek->rchild;
            }else{
                printf("%d",peek->data);
                lastVisited = s[top--];
            }
        }
    }

}

void itInorder(Node* root){
    Node* s[100];
    int top = -1;
    Node* curr =root;
    while(top>=0 || curr !=NULL){
        while(curr != NULL){
            s[++top] = curr;
            curr = curr->lchild;

        }
        curr = s[top--];
        printf("%d",curr->data);
        curr = curr->rchild;
        
    }
    
}