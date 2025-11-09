#include <stdio.h>
#include <stdlib.h>

#define MAX 10
int st[MAX];
int top =-1;


void push(int value){
    if(top==MAX-1){
        printf("Stack is full");
        return;
    }
    top++;
    st[top]=value;
}

int pop(){
    if(top == 0){
        printf("Stack is empty");
        return -1;
    }
    int temp=st[top];
    st[top]= (int) NULL;
    top--;
    return temp;
}

int peek(){
    if(top == -1){
        printf("Stack is empty");
        return -1;
    }
    return st[top];
}

void display(){
    for (int i = 0; i <=top; ++i) {
        printf("%d)%d\n",i+1,st[i]);
    }
}

int main(){
    push(3);
    printf("Top element: %d\n", peek());
    push(5);
    push(2);
    push(8);
    pop();
    pop();
    push(7);
    display();
}