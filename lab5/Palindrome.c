#include<stdio.h>
#include<stdlib.h>
#include<string.h>

#define MAX 100   // defining the max size 

typedef struct{
    char array[MAX];
    char top;  
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
void push(Stack* s,char x){
    if(isFull(s)){
        printf("stack overflow can't push %c \n",x);
        return;
    }
    else{
        s->array[++s->top] = x;
    }

}
char pop(Stack* s){
    if(isEmpty(s)){
        printf("stack underflow");
        return '\0';
    }
    else{
        return s->array[s->top--];
    }
}
//function to check palindrome
int checkPalindrome(const char* str){
    Stack s;
    init(&s);
    int len = strlen(str);
    for(int i =0;i<len;i++){
        push(&s,str[i]);
    }
    for(int i =0;i<len;i++){
        if(pop(&s) != str[i]){
            return 0;
        }
    }
    return 1;

}
int main(){
    char str[MAX];
    printf("enter a string: ");
    scanf("%s",str);
    if(checkPalindrome(str)){
        printf("the given string is a palindrome");
    }
    else{
        printf("the given string is not a palindrome");
    }
    return 0;
}