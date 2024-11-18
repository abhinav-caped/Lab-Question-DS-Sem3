#include<stdio.h>
#include<stdlib.h>

typedef struct Node{
    struct Node* next;
    int ele;
}Node;

Node* createNode(int data){
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->ele =data;
    newNode->next = NULL;
    return newNode;
}

void printList(Node* head){
    Node* temp = head;
    while(temp != NULL){
        printf("%d",temp->ele);
        temp = temp->next;
    }
    printf("\n");
}

int existsInList(Node* head,int dat){
    Node* temp = head;
    while(temp != NULL){
        if(temp->ele ==dat){
            return 1;
        }
        temp=temp->next;
    }
    return 0;
}

Node* insertAtEnd(Node* head,int ele){
    Node* newNode = createNode(ele);
    if(head == NULL){
        head = newNode;
        return newNode;
    }
    Node* temp = head;
    
    while(temp->next !=NULL){
        temp = temp->next;
    }
    temp->next = newNode;
    return head;
}

Node* unionList(Node* listA,Node* listB){
    Node* result = NULL;
    Node* temp = listA;
    while(temp != NULL){
        result= insertAtEnd(result,temp->ele);
        temp= temp->next;  
    }
    temp = listB;
    while(temp != NULL){
        if(!existsInList(result,temp->ele)){
            result=insertAtEnd(result,temp->ele);
        }
        temp = temp->next;
    }
    return result;
}

Node* intersectionList(Node* listA,Node* listB){
    Node* result = NULL;
    Node* temp = listA;
    while(temp !=NULL){
        if(existsInList(listB,temp->ele)){
            result=insertAtEnd(result,temp->ele);
        }
        temp = temp->next;
    }
    return result;
}

int main(){
    Node* listA = NULL;
    Node* listB = NULL;

    
    listA = insertAtEnd(listA, 1);
    listA = insertAtEnd(listA, 2);
    listA = insertAtEnd(listA, 3);

    listB = insertAtEnd(listB, 3);
    listB = insertAtEnd(listB, 4);
    listB = insertAtEnd(listB, 5);

    printf("List A: ");
    printList(listA);
    printf("List B: ");
    printList(listB);

    Node* union_result = unionList(listA, listB);
    printf("Union: ");
    printList(union_result);

    Node* intersection_result = intersectionList(listA, listB);
    printf("Intersection: ");
    printList(intersection_result);

    
    return 0;
}

