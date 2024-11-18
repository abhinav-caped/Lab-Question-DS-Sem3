#include<stdio.h>
#include<stdlib.h>

#define MAX 100

typedef struct Stack{
    int arr[MAX];
    int top;
}Stack;

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
void push(Stack* s,int x){
    if(isFull(s)){
        printf("stack overflow can't push %d \n",x);
        return;
    }
    else{
        s->arr[++s->top] = x;
    }

}
int pop(Stack* s){
    if(isEmpty(s)){
        printf("stack underflow");
        return '\0';
    }
    else{
        return s->arr[s->top--];
    }
}
int peek(Stack* s){
    return s->arr[s->top];
}


void NGE(int* arr,int n){
    Stack s;
    init(&s);
    int nge[n];
    for(int i=n-1; i>=0; i--){
        while(!isEmpty(&s) && arr[i]>=peek(&s)){
            pop(&s);
        }
        
        if(isEmpty(&s)){
            nge[i]=-1;
        }else{
            nge[i] = peek(&s);
        }
        push(&s,arr[i]);
        

    }
    for (int i = 0; i < n; i++) {
        printf("Element %d -> NGE %d\n", arr[i], nge[i]);
    }
    
    

}
int main(){
    int arr[] = {13, 7, 6, 12};
    int n = sizeof(arr) / sizeof(arr[0]);

    NGE(arr, n);
}