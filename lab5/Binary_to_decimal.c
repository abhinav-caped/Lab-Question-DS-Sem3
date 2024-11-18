#include<stdio.h>
#include<stdlib.h>

#define MAX 100   // defining the max size

typedef struct Stack{
    int arr[MAX];
    int top;
}Stack;

void initStack(Stack* s){
    s->top = -1;
}

void push(int i ,Stack* s){
    if(s->top == MAX-1){
        printf("stack is full");
        return;
    }else{
        s->arr[++s->top] = i;
    }
}

int pop(Stack* s){
    if(s->top == -1){
        printf("stack is empty");
        return -1;
    }else{
        return s->arr[s->top--];      
    }
}

int calculateDecimal(int num){
    Stack s;
    initStack(&s);
    while(num != 0){
        push(num%2,&s);
        num = num/2;
    }
    printf("binary: ");
    while(s.top !=-1){ //here s is a strucutre not a pointer that's why we are using . instead of ->
        printf("%d",pop(&s));    
    }  
    
}

int main(){
    int num;
    printf("enter a decimal value: ");
    scanf("%d",&num);
    calculateDecimal(num);
}
