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

Node* createBST(){
    int val;
    printf("enter the value for the node(-1 for no value): ");
    scanf("%d",&val);
    if(val ==-1){
        return NULL;
    }
    Node* temp =  createNode(val);
    printf("enter the value for left node of %d \n",val);
    temp->lchild = createBST();
    printf("enter the value for right child of %d \n",val);
    temp->rchild = createBST();

    return temp;

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

int main(){
    Node* root = NULL;
    Node* root2 = NULL;
    root = createBST();

    root2 = copyTree(root);
    int a;
    a = areEqual(root,root2);
    printf("%d",a);


}