#include<stdio.h>
#include<stdlib.h>

#define MAX 100

typedef struct Stack{
    int arr[MAX];
    int top;
}Stack;

void initStack(Stack* s){
    s->top = -1;
}

int isFull(Stack* s){
    return s->top == MAX-1;
}

int isEmpty(Stack* s){
    return s->top == -1;
}

void push(Stack* s,int i){
    if(isFull(s)){
        printf("stack overflow");
        return;
    }else{
        s->arr[++s->top]= i;
    }
}

int pop(Stack* s){
    if(isEmpty(s)){
        printf("stack underflow");
        return -1;
    }else{
        return s->arr[s->top--];
    }
}

void deleteElements(int* arr,int n,int k){
    Stack s;
    initStack(&s);
    //outer loop to iterate through whole array
    for(int i =0;i<n;i++){
        //inner loop to compare array with the tos
        while(s.top != -1 && s.arr[s.top]<arr[i] && k>0){
            pop(&s);
            k--;
        }
        push(&s,arr[i]);
    }
    //now prinint the answer
    for(int i =0;i<=s.top;i++){
        printf("%d ",s.arr[i]);
    }
}

int main(){
    int arr[] = {20,10,25,30,40};
    int n = sizeof(arr)/sizeof(arr[0]);
    int k=2;
    deleteElements(arr,n,k);
}
// For the input {20, 10, 25, 30, 40} with k = 2:

// Initialize an empty stack.
// Process 20: Push 20 onto the stack since it’s the first element.
// Process 10: Push 10 onto the stack as it doesn’t trigger deletion (since 10 < 20).
// Process 25:
// 10 < 25 → Pop 10 and decrement k (now k = 1).
// 20 < 25 → Pop 20 and decrement k (now k = 0).
// Push 25 onto the stack.
// Process 30 and 40: Since k = 0, no more deletions are allowed. Push 30 and 40 onto the stack.