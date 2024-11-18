#include<stdio.h>
#include<stdlib.h>

#define MAX 100

typedef struct Queue{
    char* arr[MAX];
    int front;
    int rear;
}Queue;

void initq(Queue* q){
    q->rear = -1;
    q->front =-1;
}

int isFull(Queue* q){
    return (q->front == 0 && q->rear == MAX - 1) || (q->rear == (q->front - 1) % (MAX - 1));
}

int isEmpty(Queue* q){
    return q->front ==-1;
}

void enqfront(Queue* q,char* x){
    if(isFull(q)){
        printf("queue is full");
        return;
    }
    if(isEmpty(q)){
        q->rear=0;
    }
    q->arr[++q->front]=x;  

}
void enqrear(Queue* q,char* x){
    if(isFull(q)){
        printf("queue is full");
    }
    if(isEmpty(q)){
        q->front=0;
    }
    q->arr[++q->rear]=x;
}
char* deq(Queue* q){
    if(isEmpty(q)){
        printf("queue is empty");
        return '\0';
    }
    char* item = q->arr[q->front];
    q->front++;
    return item;
}

int main() {
    Queue q;
    initq(&q);

    // Testing the output-restricted deque with string insertions
    enqrear(&q, "hello");
    enqrear(&q, "world");
    enqfront(&q, "first");
    enqrear(&q, "last");

    // Dequeue elements from the front
    printf("%s\n", deq(&q));  // Should output "first"
    printf("%s\n", deq(&q));  // Should output "hello"
    printf("%s\n", deq(&q));  // Should output "world"
    printf("%s\n", deq(&q));  // Should output "last"

    return 0;
}