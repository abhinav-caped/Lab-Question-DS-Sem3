#include<stdio.h>
#include<stdlib.h>

typedef struct Node{
    struct Node* left;
    int data;
    struct Node* right;
}Node;

Node* createNode(int ele){
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->left = newNode->right = NULL;
    newNode->data = ele;
    return newNode;
}

Node* insertAtFront(Node* head,int ele){
    Node* newNode = createNode(ele);
    
    if(head==NULL){
        return newNode;
    }  
    newNode->right = head;
    head->left = newNode;
    head = newNode;

    return newNode;
}

Node* insertAtEnd(Node* head, int ele){
    Node* newNode = createNode(ele);
    Node* temp = head;
    if(head==NULL){
        return newNode;;
    }
    while(temp->right !=NULL){
        temp = temp->right;
    }
    temp->right = newNode;
    newNode->left = temp;
    
    return head;
}

Node* deleteAtEnd(Node* head){
    if(head ==NULL){
        printf("list empty\n");
        return head;
    }
    if(head->right ==NULL){
        free(head);
        return NULL;
    }
    Node* temp = head;
    while(temp->right !=NULL){
        temp = temp->right;
    } 
    temp->left->right =NULL;
    free(temp);
    return head;
}

Node* deleteAtFront(Node* head){
    if(head ==NULL){
        printf("list empty\n");
        return head;
    }
    if(head->right ==NULL){
        free(head);
        return NULL;
    }
    Node* temp = head;
    head = temp->right;
    head->left =NULL;

    free(temp);
    return head;
}

void printList(Node* head){
    Node* temp = head;
    while(temp !=NULL){
        printf("%d ",temp->data);
        temp = temp->right;
    }
    printf("\n");
}

int main(){
    Node* DLLA = NULL;
    int choice,val;
    do{
        printf("\n-----MENU-----\n");
        printf("1. Insert at front\n");
        printf("2. Insert at end\n");
        printf("3. Delete at front\n");
        printf("4. Delete at end\n");
        printf("5. Display list\n");
        printf("6.Exit\n");
        printf("enter your choice: ");
        scanf("%d",&choice);
        
        switch(choice){
            case 1:
                printf("enter value to insert: ");
                scanf("%d",&val);
                DLLA=insertAtFront(DLLA,val);
                break;
            case 2:
                printf("enter value to insert: ");
                scanf("%d",&val);
                DLLA=insertAtEnd(DLLA,val);
                break;
            case 3:
                DLLA=deleteAtFront(DLLA);
                break;
            case 4:
                DLLA=deleteAtEnd(DLLA);
                break;
            case 5:
                printList(DLLA);
                break;
            case 6:
                printf("exiting");
                break;
            default:
                printf("enter a valid choice");
                
        }
    }while(choice != 6);


    return 0;

}

