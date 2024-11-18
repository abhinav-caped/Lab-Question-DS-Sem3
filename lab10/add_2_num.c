#include<stdio.h>
#include<stdlib.h>

typedef struct Node{
    int ele;
    struct Node* next;
}Node;

Node* createNode(int ele){
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->ele = ele;
    newNode->next = newNode; //points to itself for circular LL
    return newNode;
}
Node* insertEnd(Node* head, int ele) {
    Node* newNode = createNode(ele);
    if (head == NULL) {
        return newNode;
    }
    Node* temp = head;
    while (temp->next != head) {
        temp = temp->next;
    }
    temp->next = newNode;
    newNode->next = head;
    return head;
}
Node* addList(Node* listA,Node* listB){
    Node* result = NULL;
    int carry=0;
    Node* headA = listA;
    Node* headB = listB;
    do{
        int sum= carry;
        while(listA!=NULL){
            sum+=listA->ele;
            listA = listA->next;
            if(listA ==headA) listA =NULL;
        }
        while(listB!=NULL){
            sum+=listB->ele;
            listB = listB->next;
            if(listB ==headB) listB =NULL;
        }
        carry = sum/10;
        result = insertEnd(result,sum%10);
    }while(listA!=NULL||listB!=NULL||carry>0);

    return result;
}
void printList(Node* head){
    Node* temp = head;
    if(head==NULL) return; 
    
    do {
        printf("%d ", temp->ele);
        temp = temp->next;
    } while (temp != head);
    printf("\n");

}

int main(){
    Node* listA = NULL;
    Node* listB = NULL;
    Node* result = NULL;
    int N1,N2;
    printf("enter first number: ");
    scanf("%d",&N1);
    printf("enter second number: ");
    scanf("%d",&N2);
    while(N1 != 0){
        int val = N1%10;
        listA = insertEnd(listA,val);
        N1 = N1/10;
    }
    while(N2 != 0){
        int val = N2%10;
        listB = insertEnd(listB,val);
        N2 = N2/10;
    }
    printf("\n");
    printList(listA);
    printf("linked list after addition");
    result = addList(listA,listB);
    printList(result);

    return 0;
    
}
// #include <stdio.h>
// #include <stdlib.h>

// typedef struct Node {
//     int ele;
//     struct Node* next;
// } Node;

// Node* createNode(int ele) {
//     Node* newNode = (Node*)malloc(sizeof(Node));
//     newNode->ele = ele;
//     newNode->next = newNode; // Points to itself for circular LL
//     return newNode;
// }

// Node* insertEnd(Node* head, int ele) {
//     Node* newNode = createNode(ele);
//     if (head == NULL) {
//         return newNode;
//     }
//     Node* temp = head;
//     while (temp->next != head) {
//         temp = temp->next;
//     }
//     temp->next = newNode;
//     newNode->next = head;
//     return head;
// }

// Node* addList(Node* listA, Node* listB) {
//     Node* result = NULL;
//     int carry = 0;
//     Node *headA = listA, *headB = listB;

//     Node* currentA = headA;
//     Node* currentB = headB;
    
//     do {
//         int sum = carry;
//         if (currentA != NULL) {
//             sum += currentA->ele;
//             currentA = currentA->next;
//             if (currentA == headA) currentA = NULL;
//         }
//         if (currentB != NULL) {
//             sum += currentB->ele;
//             currentB = currentB->next;
//             if (currentB == headB) currentB = NULL;
//         }
//         carry = sum / 10;
//         result = insertEnd(result, sum % 10);
//     } while (currentA != NULL || currentB != NULL || carry > 0);

//     return result;
// }

// void printList(Node* head) {
//     Node* temp = head;
//     if (head == NULL) return;
//     do {
//         printf("%d ", temp->ele);
//         temp = temp->next;
//     } while (temp != head);
//     printf("\n");
// }

// int main() {
//     Node* listA = NULL;
//     Node* listB = NULL;
//     Node* result = NULL;
//     int N1, N2;
//     printf("Enter first number: ");
//     scanf("%d", &N1);
//     printf("Enter second number: ");
//     scanf("%d", &N2);
    
//     while (N1 != 0) {
//         int val = N1 % 10;
//         listA = insertEnd(listA, val);
//         N1 = N1 / 10;
//     }
//     while (N2 != 0) {
//         int val = N2 % 10;
//         listB = insertEnd(listB, val);
//         N2 = N2 / 10;
//     }

//     printf("Linked list after addition: ");
//     result = addList(listA, listB);
//     printList(result);

//     return 0;
// }
