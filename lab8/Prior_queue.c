#include<stdio.h>
#include<stdlib.h>

#define MAX 100

typedef struct Queue{
    int arr[MAX];
    int rear;
    int front;
}Queue;

void initq(Queue* q){
    q->rear = -1;
    q->front= -1;
}
int isFull(Queue* q){
    return q->rear ==MAX-1;
}

int isEmpty(Queue* q){
    return q->front ==-1 || q->front>q->rear;
}

void enq(Queue* q,int x){
    if(isFull(q)){
        printf("queue full");
        return;
    }
    if(isEmpty(q)){
        q->front =0;
        q->rear=0;
    }
    int i;
    for( i=q->rear-1;i>=q->front && q->arr[i]>x;i--){
        q->arr[i+1] = q->arr[i];
    }
    q->rear++;
    q->arr[i+1] =x;
    

}

int deq(Queue* q){
    if(isEmpty(q)){
        printf("queue is empty\n");
        return -1;
    }
    return q->arr[q->front++];
}

int main() {
    Queue q;
    initq(&q);

    // Insert elements into the ascending priority queue
    enq(&q, 30);
    enq(&q, 10);
    enq(&q, 20);
    enq(&q, 5);

    printf("Removed minimum element: %d\n", deq(&q));  // Should output 5
    printf("Removed minimum element: %d\n", deq(&q));  // Should output 10
    printf("Removed minimum element: %d\n", deq(&q));  // Should output 20
    printf("Removed minimum element: %d\n", deq(&q));  // Should output 30

    return 0;
}
