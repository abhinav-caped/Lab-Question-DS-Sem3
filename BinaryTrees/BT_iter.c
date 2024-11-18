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

Node* createBT(Node* root,int data){
    Node* temp = createNode(data);
    if(root==NULL){
        return temp;
    }
    Node* curr = root;
    Node* prev = NULL;
    char direction[100];
    int i;
    printf("enter the direction in which you want to insert");
    scanf("%s",direction);
    for(i=0;i<strlen(direction);i++){
        prev = curr;
        if(direction[i]=='L'){
            curr = curr->lchild;
        }else{
            curr= curr->rchild;
        }

    }
    if(direction[i-1]=='L'){
        prev->lchild = temp;
    }else{
        prev->rchild = temp;
    }
    return root;
  
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
  
  do{
    printf("\n\n~~~~~~ Menu ~~~~~~");
    printf("\n1. Create a Binary Tree");
    printf("\n2. Inorder Display");
    printf("\n3. Exit");
    printf("\nEnter your choice: ");
    scanf("%d", &ch);

    switch(ch){
        case 1:
            printf("enter the number of node");
            scanf("%d",&n);
            for(i=0;i<n;i++){
                printf("enter the value to insert");
                scanf("%d",&item);
                root = createBT(root,item);
            }
            break;
        case 2:
            inorder(root);
            break;
        case 3:
            printf("exiting");
            break;
        default:
            printf("enter a vald choice");
    }
  }while(ch!=3);
 
  
  return 0;
}
