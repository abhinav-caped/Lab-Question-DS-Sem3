#include<stdio.h>
#include<stdlib.h>

//without header node

typedef struct Node{
    struct Node* next;
    int data;
}Node;

typedef struct Queue{
    Node* front;
    Node* rear;
}Queue;



void enq(Queue* q,int x){
    Node* new = (Node*)malloc(sizeof(Node));
    if(new == NULL){
        printf("memory allocation falied(space full)");
        return;
    }
    new->data = x;
    new->next = NULL;
    if(q->front ==NULL){
        q->front = q->rear =new;
    }else{
        q->rear->next= new;
        q->rear = new;
    }
    

}
int deq(Queue* q){
    if(q->front ==NULL){
        printf("queue is empty");
        return -1;
    }
    Node* temp = q->front;
    int ele = q->front->data;
    q->front = q->front->next;
    if(q->front ==NULL){
        q->rear = NULL;
    }
    free(temp);
    return ele;

}
int main() {
    Queue q = { NULL, NULL }; // Initialize an empty queue

    enq(&q, 10);
    enq(&q, 20);
    enq(&q, 30);

    printf("Dequeued: %d\n", deq(&q));
    printf("Dequeued: %d\n", deq(&q));
    printf("Dequeued: %d\n", deq(&q));

    return 0;
}

//with header node

typedef struct Node{
    struct Node* next;
    int data;
}Node;

typedef struct Queue{
    Node* front;
    Node* rear;
}Queue;

Node* createNode(int data){
    Node* newNode = (Node*)malloc(sizeof(Node));
    if(newNode==NULL){
        printf("memory allocation failed");
    }
    newNode->data = data;
    newNode->next = NULL;
    return newNode;
}

void enq(Queue* q, int x) {
    Node* new = createNode(x);  // Create the new node
    if (new == NULL) return;  // If node creation failed, return

    if (q->front == NULL) {
        // If the queue is empty, create the header node
        q->front = createNode(0);  // The header node (doesn't hold useful data)
        if (q->front == NULL) return; // Handle memory allocation failure

        q->rear = new;  // Set rear to the new node
        q->front->next = new;  // Link the header node to the new node
    } else {
        // If the queue is not empty, add the new node to the rear
        q->rear->next = new;  // Link the new node to the rear
        q->rear = new;         // Update rear to point to the new node
    }
}

int deq(Queue* q){
    if(q->front ==NULL ){
        printf("queue is empty");
        return -1;
    }
    Node* temp = q->front->next;
    int ele = temp->data;
    q->front->next = temp->next;
    if(q->front->next ==NULL){
        q->rear = NULL;
    }
    free(temp);
    return ele;

}
int main() {
    Queue q = { NULL, NULL }; // Initialize an empty queue

    enq(&q, 10);
    printf("enqued\n");
    enq(&q, 20);
    printf("enqued\n");
    enq(&q, 30);
    printf("enqued\n");

    printf("Dequeued: %d\n", deq(&q));
    printf("Dequeued: %d\n", deq(&q));
    printf("Dequeued: %d\n", deq(&q));

    return 0;
}