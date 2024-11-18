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
Node* createBST(Node* root,int ele){
    if(root == NULL){
        root = createNode(ele);
        return root;
    }
    else if(root->data <ele){
        root->rchild = createBST(root->rchild,ele);
    }
    else if(root->data > ele){
        root->lchild = createBST(root->rchild,ele);
    }
    else{
        printf("invalid input");
    }
    return root;
}
void inorder(Node* root)
{
	if (root!= NULL)
	{
		inorder(root->lchild);
		printf("%d ",root->data);
		inorder(root->rchild);
	}
}
int main()
{
  Node* root;
  int ch,item,n,i;
  while(1)
  {
    printf("\n\n~~~~~~Menu~~~~~~ ");
    printf("\n=>1. Create a Binary Search Tree");
    printf("\n=>2. Inorder Display");
    printf("\n=>3. Exit");
    printf("\nEnter your choice: ");
    scanf("%d", &ch);

    switch(ch)
    {
      case 1: root=NULL;
              printf("\nEnter the number of nodes:");
              scanf("%d", &n);
              printf("\nEnter the elements for BST: ");
              for(i=0;i<n;i++)
              {
                printf("\nEnter The Element ");
                scanf("%d", &item);
                root = createBST(root,item);
              }
              break;

      case 2: if (root == NULL)
              printf("\n Tree Is Not Created");
              else
              {
               printf("\nThe Inorder display: ");
               inorder(root);
              }
              break;
      case 3: exit(0);
      default: printf("Enter the valid choice \n");

    }
  }
   return 0;
}



