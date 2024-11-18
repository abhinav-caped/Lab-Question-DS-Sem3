#include<stdio.h>
#include<stdlib.h>

#define MAX 10

typedef struct Cqueue{
    int arr[MAX];
    int front1,front2;
    int rear1,rear2;
}Cqueue;

void initq(Cqueue* q){
    q->front1 = q->rear1 =-1;
    q->front2 = q->rear2 = MAX/2;
}

int isFull1(Cqueue* q){
    return (q->rear1+1)%(MAX/2+1) == q->front1;

}
int isFull2(Cqueue* q){
    return q->front2 == (q->rear2+1)%((MAX/2+1)+MAX/2);
}
int isEmpty1(Cqueue* q){
    return q->front1 == -1;
}
int isEmpty2(Cqueue* q){
    return q->front2 == MAX/2;
}
void enq1(Cqueue* q,int x){
    if(isFull1(q)){
        printf("queue full");
    }
    if(isEmpty1(q)){
        q->front1 =0;
    }
    q->rear1 = (q->rear1+1)%(MAX/2+1);
    q->arr[q->rear1] =x;
}
void enq2(Cqueue* q,int x){
    if(isFull1(q)){
        printf("queue full");
    }
    if(isEmpty1(q)){
        q->front2 =0;
    }
    q->rear2 = (q->rear2+1)%(MAX/2+1+MAX/2) ;
    q->rear1 =x;
}
    


