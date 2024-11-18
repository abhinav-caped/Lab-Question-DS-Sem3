#include<stdio.h>
#include<stdlib.h>

typedef struct Node{
    struct Node* lchild;
    struct Node* rchild;
    int data;
}Node;

Node* createNode(int ele){
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->lchild = newNode->rchild = NULL;
    newNode->data= ele;
    return newNode;
}
Node* insertBST(Node* root,int data){
    if(root == NULL){
        root = createNode(data);
        return root;
    }
    if(root->data>data){
        root->lchild = insertBST(root->lchild,data);
    }
    else if(root->data < data){
        root->rchild = insertBST(root->rchild,data);
    }
    else{
        printf("invalid input");
    }
    return root;


    
}
Node* inorderPredecessor(Node* root){
    root = root->lchild;
    while(root->rchild != NULL){
        root = root->rchild;
    }
    return root;

}

Node* deleteBST(Node* root,int key){
    Node* ipre;
    if(root ==NULL) return NULL;
    if(root->rchild == NULL && root->lchild ==NULL){
        free(root);
        return NULL;       
    }
    if(key>root->data){
        root->rchild = deleteBST(root->rchild,key);
    }
    else if(key<root->data){
        root->lchild = deleteBST(root->lchild,key);
    }
    else{
        ipre = inorderPredecessor(root);
        root->data = ipre->data;
        root->lchild = deleteBST(root->lchild,ipre->data);
    }
    return root;


}
void inorder(Node* root){
    if(root){
        printf("%d ",root->data);
        inorder(root->lchild);
        inorder(root->rchild);
    }
}


int main() {
    Node* root =NULL;
    root =insertBST(root,1);
    root = insertBST(root,2);
    root = insertBST(root,3);
    root = insertBST(root,4);
    root = insertBST(root,5);
    inorder(root);
    
    root=deleteBST(root,5);
    inorder(root);

    return 0;
}