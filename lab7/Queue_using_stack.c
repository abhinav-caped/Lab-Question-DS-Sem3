#include<stdio.h>
#include<stdlib.h>

#define MAX 100   // defining the max size 

typedef struct{
    int array[MAX];
    int top;  
}Stack;    //creating structure for stack

//initialisation
void init(Stack* s){
    s->top = -1;
}
//creating isfull and isempty
int isFull(Stack* s){
    return s->top == MAX-1;
}
int isEmpty(Stack* s){
    return s->top == -1;
}
//push
void push(Stack* s,int x){
    if(isFull(s)){
        printf("stack overflow can't push %d \n",x);
        return;
    }
    else{
        s->array[++s->top] = x;
    }
    printf("pushed %d to the stack\n",x);
}
//pop
int pop(Stack* s){
    if(isEmpty(s)){
        printf("stack underflow");
        return -1;
    }
    else{
        return s->array[s->top--];
    }
}
int peek(Stack* s){
    if(isEmpty(s)){
        printf("empty stack\n");
        return -1;
    }
    else{
        return s->array[s->top];
        

    }
    
}
typedef struct Queue{
    Stack s1;
    Stack s2;
}Queue;

void initq(Queue* q){
    init(&q->s1);
    init(&q->s2);
}

void enq(Queue* q,int x){
    if(isFull(&q->s1)){
        printf("overflow");
        return;
    }else{
        push(&q->s1,x);

    }
    
}
int deq(Queue* q){
    if(isEmpty(&q->s1) && isEmpty(&q->s2)){
        printf("underflow");
        return -1;
    }
    if(isEmpty(&q->s2)){
        while(!isEmpty(&q->s1)){
            push(&q->s2,pop(&q->s1));

        }      
    }
    return pop(&q->s2);
}

int main() {
    Queue q;
    initq(&q);

    enq(&q, 10);
    enq(&q, 20);
    enq(&q, 30);

    printf("Dequeued element: %d\n", deq(&q));  // Should output 10
    printf("Dequeued element: %d\n", deq(&q));  // Should output 20

    enq(&q, 40);
    printf("Dequeued element: %d\n", deq(&q));  // Should output 30
    printf("Dequeued element: %d\n", deq(&q));  // Should output 40

    return 0;
}