#include <stdio.h>
#include <stdlib.h>

typedef struct Stack{
    int value;
    struct Stack *next;
}Stack;

Stack * top=NULL;


Stack* createNode(int num){
    Stack* newNode=(Stack*) malloc(sizeof (Stack));
    newNode->value=num;
    newNode->next=NULL;
    return newNode;
}

void push(int num){
    Stack* value= createNode(num);
    value->next=top;
    top=value;
}

int pop(){
    if(top == NULL){
        printf("Stack is empty!\n");
        return -1;
    }
    Stack* temp=top;
    int value=temp->value;
    top=top->next;
    free(temp);
    return value;
}

int peek() {
    if (top == NULL) {
        printf("Stack bos!\n");
        return -1;
    }
    return top->value;
}

int size(){
    if(top ==NULL){
        printf("Stack is empty!\n");
        return 0;
    }
    int i=0;
    Stack* temp=top;
    while(temp !=NULL) {
        i++;
        temp=temp->next;
    };

    return i;
}

void clearStack(){
    if(top == NULL){
        printf("Stack is empty!\n");
        return;
    }
    Stack* temp=top;
    while(temp != NULL){
        Stack * old=temp;
        temp=temp->next;
        free(old);
    }
    top=NULL;
    printf("Stack cleared.\n");

}

void display(){
    if(top == NULL){
        printf("Stack is empty\n");
        return;
    }
    Stack* temp=top;
    int i=1;
    while(temp != NULL) {
        printf("%d) %d\n",i,temp->value);
        temp=temp->next;
        i++;
    }
}
int main() {
    push(10);
    push(20);
    push(30);

    printf("Current Stack:\n");
    display();

    printf("Top: %d\n", peek());
    printf("Size: %d\n", size());

    printf("Pop: %d\n", pop());
    printf("After pop:\n");
    display();

    clearStack();
    return 0;
}
