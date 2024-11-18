#include<stdio.h>
#include<stdlib.h>
#include<string.h>

#define MAX 15

typedef struct NodeP{
    struct Node* left;
    struct Node* right;
    char data[MAX];
}Node;

Node* createNode(char* str){
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->left = newNode->right = NULL;
    strcpy(newNode->data,str);
    return newNode;
}
Node* insertAtEnd(Node* head, char* str) {
    Node* newNode = createNode(str);
    if(head ==NULL){
        printf("empty list\n");
        return newNode;
    }
    Node* temp = head;
    while(temp->right != NULL){
        temp = temp->right;
    }
    temp->right = newNode;
    newNode->left = temp;
    return head;
}
void printList(Node* head){
    Node* temp = head;
    while(temp != NULL){
        printf("%s ->",temp->data);
        temp = temp->right;

    }
    printf("\n");
}


Node* reverseLL(Node* head) {
    Node* current = head;
    Node* temp = NULL;

    // Traverse the list and swap left and right pointers for each node
    while (current != NULL) {
        temp= current->left;
        current->left = current->right;
        current->right = temp;
        //swapped the two pointers
        current = current->left;

    }
    if(temp != NULL){
        head = temp->left;

    }



    return head;
}

int main(){
    Node* DLLA = NULL;
    DLLA = insertAtEnd(DLLA, "Hello");
    DLLA = insertAtEnd(DLLA, "World");
    DLLA = insertAtEnd(DLLA, "This");
    DLLA = insertAtEnd(DLLA, "Is");
    DLLA = insertAtEnd(DLLA, "Reversed");
    printf("original list\n");
    printList(DLLA);
    DLLA=reverseLL(DLLA);
    printf("reversed linked list\n");
    printList(DLLA);

    return 0;


}

