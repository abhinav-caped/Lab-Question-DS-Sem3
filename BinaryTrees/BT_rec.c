#include<stdio.h>
#include<stdlib.h>
#include<string.h>

typedef struct Node{
    struct Node* lchild;
    struct Node* rchild;
    int data;
}Node;

Node* createNode(int ele){
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->lchild = newNode->rchild = NULL;
    newNode->data = ele;
    return newNode;
}

Node* createBT(){
    int val;
    printf("enter the element(-1 for no value): ");
    scanf("%d",&val);
    if(val == -1){
        return NULL;
    }
    //root node
    Node* temp = createNode(val);
    printf("node for left child of %d\n",val);
    temp->lchild = createBT();
    printf("node for right child of %d\n",val);
    temp->rchild  = createBT();

    return temp;


}
void inorder(Node* root)
{
  if(root != NULL)
  {
    inorder(root->lchild);
    printf("%d ", root->data);
    inorder(root->rchild);
  }
}

int main()
{
  Node* root = NULL;
  int ch, item, n, i;
  while(1)
  {
    printf("\n\n~~~~~~ Menu ~~~~~~");
    printf("\n1. Create a Binary Tree");
    printf("\n2. Inorder Display");
    printf("\n3. Exit");
    printf("\nEnter your choice: ");
    scanf("%d", &ch);

    switch(ch){
        case 1:
            root = createBT();
            break;
        case 2:
            inorder(root);
            break;
        case 3:
            printf("exiting");
            exit(0);
        default:
            printf("enter a vald choice");
    }
  }
 
  
  return 0;
}

