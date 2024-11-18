#include<stdio.h>
#include<stdlib.h>

typedef struct Node{
    struct Node* next;
    int ele;
}Node;

Node* createNode(int data){
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->next = NULL;
    newNode->ele = data;
    return newNode;
}

Node* insertAtEnd(Node* head,int data){
    Node* newNode = createNode(data);
    if(head == NULL){
        head = newNode;
        return newNode;
    }
    Node* temp = head;
    while(temp->next != NULL){
        temp = temp->next;
    }
    temp->next = newNode;
    return head;
}


Node* mergeList(Node* classA,Node* classB){
    Node* mergedHead = NULL;
    Node* tail = NULL;

    while(classA != NULL && classB != NULL){
        Node* minNode;
        if(classA->ele < classB->ele){
            minNode = classA;
            classA = classA->next;

        }else{
            minNode = classB;
            classB = classB->next;
        }
        if(mergedHead == NULL){
            mergedHead = minNode;
            tail = minNode;
        }else{
            tail->next = minNode;
            tail = minNode;
        }
    }

    if(classA != NULL){
        tail->next = classA;
    }else if(classB != NULL){
        tail->next = classB;
    }
    return mergedHead;

    
}
Node* printList(Node* head){
    Node* temp = head;
    while(temp!=NULL){
        printf("%d ",temp->ele);
        temp= temp->next;
    }
    printf("\n");
}

int main(){
    Node* classA = NULL;
    Node* classB = NULL;
    Node* merged = NULL;

    int N1,N2,val;
    printf("insert the number of students in class A and B\n");
    scanf("%d %d",&N1,&N2);
    
    printf("enter heights for class A in sorted order");
    for(int i=0;i<N1;i++){
        scanf("%d",&val);
        classA = insertAtEnd(classA,val);       
    }
    printf("classA\n");
    printList(classA);

    printf("enter heights for class B in sorted order");
    for(int i=0;i<N2;i++){
        scanf("%d",&val);    
        classB = insertAtEnd(classB,val);
    }
    printf("class B\n");
    printList(classB);
    merged = mergeList(classA,classB);
    printList(merged);

    return 0;
    
}