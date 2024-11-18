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
void peek(Stack* s){
    if(isEmpty(s)){
        printf("empty stack\n");
        return;
    }
    else{
        printf("%d",s->array[s->top]);
        printf("\n");

    }
    
}
//a menu for the menu driven program
void menu(){
    printf("1: push\n");
    printf("2: pop\n");
    printf("3: peek\n");
    printf("4: exit\n");
}
int main(){
    Stack s;
    init(&s);
    int choice;
    int x;
    int r;
    do{
        menu();
        printf("enter your choice: ");
        scanf("%d",&choice);
        printf("\n");
        switch(choice){
            case 1:
                printf("enter the element to push: ");
                scanf("%d",&x);
                push(&s,x);
                break;
            case 2:
                r = pop(&s);
                if(r!=-1){
                    printf("%d is popped\n",r);
                }
                break;
            case 3:
                peek(&s);
                break;
            case 4:
                printf("exiting the program");
                break;
            default:
                printf("enter a valid choice\n");
        }

    }while(choice!=4);

    return 0;

}