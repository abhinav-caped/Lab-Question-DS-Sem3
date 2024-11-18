#include<stdio.h>
#include<stdlib.h>

typedef struct Node{
    struct Node* next;
    int ele;
}Node;

Node* createNode(int data){
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->ele = data;
    newNode->next = NULL;
    return newNode;
}

void printList(Node* head){
    Node* temp = head;
    while(temp != NULL){
        printf("%d ",temp->ele);
        temp = temp->next;
    }
    printf("\n");
}

Node* deleteDuplicates(Node* head){
    if(head ==NULL || head->next == NULL){
        return head;
    }
    Node* current = head;
    while(current->next!=NULL){
        Node* temp = current->next;
        if(current->ele == current->next->ele){
            current->next = temp->next;         
            free(temp);
        }else{
            current = current->next;
        }
        
    }
    return head;
}

int main(){
    Node* head = createNode(1);
    head->next = createNode(2);
    head->next->next = createNode(3);
    head->next->next->next = createNode(4);
    head->next->next->next->next = createNode(4);
    head->next ->next->next->next->next= createNode(5);
    printList(head);

    deleteDuplicates(head);
    printList(head);

    return 0;


}