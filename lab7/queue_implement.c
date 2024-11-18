#include<stdio.h>
#include<stdlib.h>

#define MAX 100

typedef struct Queue{
    int arr[MAX];
    int rear;
    int front;
}Queue;

void initq(Queue* q){
    q->rear = q->front =-1;
}
int isFull(Queue* q){
    return q->rear ==MAX-1;
}

int isEmpty(Queue* q){
    return q->front ==-1;
}

void enq(Queue* q,int x){
    if(isFull(q)){
        printf("queue full");
        return;
    }
    if(isEmpty(q)){
        q->front = 0; //you went wrong here
    }
    q->arr[++q->rear] =x;
}

int deq(Queue* q){
    if(isEmpty(q)){
        printf("queue is empty");
        return -1;
    }
    int item = q->arr[q->front];
    if(q->front>=q->rear){
        q->front = -1;
        q->rear = -1;
    }else{
        q->front++;
    }
    return item;

}

void displayq(Queue* q){
    if(q->front==-1 || q->front>q->rear){
        printf("empty queue");
    }
    else{
        printf("queue elements -----    ");
        for(int i=q->front;i<=q->rear;i++){
            printf("%d",q->arr[i]);
        }
    }
    printf("\n");
}
int main(){
    Queue q;
    initq(&q);
    enq(&q,1);
    enq(&q,2);
    enq(&q,3);
    enq(&q,4);
    enq(&q,5);
    displayq(&q);
    deq(&q);
    displayq(&q);
    return 0;
}
