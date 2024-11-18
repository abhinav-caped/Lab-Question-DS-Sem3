#include<stdio.h>
#include<stdlib.h>
#include<string.h>

#define MAX 5

typedef struct Cqueue{
    char arr[MAX][100];
    int front;
    int rear;
}Cqueue;
int isFull(Cqueue* q){
    return (q->rear+1)%MAX==q->front;
}
int isEmpty(Cqueue* q){
    return q->front ==-1;
}
void initcq(Cqueue* q){
    q->rear = q->front =-1;
}
void enq(Cqueue* q,char* str){
    if(isFull(q)){
        printf("queue full");
        return;
    }
    if(isEmpty(q)){
        q->front =0;
    }
    q->rear = (q->rear+1)%MAX;
    strcpy(q->arr[q->rear],str);
    printf("inserted %s\n",str);
}
void deq(Cqueue* q){
    if(isEmpty(q)){
        printf("queue empty");
        return;
    }
    if(q->rear==q->front){
        q->rear =-1;
        q->front=-1;
    }else{
        q->front = (q->front+1)%MAX;
    }
    
}
void displaycq(Cqueue* q){
    if(isEmpty(q)){
        printf("queue empty\n");
    }
    for(int i=q->front;i<=q->rear;i++){
        printf("%s\n",q->arr[i]);
    }
}
int main(){
    Cqueue q;
    initcq(&q);
    enq(&q,"string1");
    enq(&q,"string2");
    enq(&q,"strig3");
    displaycq(&q);
    deq(&q);
    displaycq(&q);
}
