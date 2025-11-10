#include <stdio.h>
#include <stdlib.h>

#define Max 100

typedef struct Queue{
    int value;
    struct Queue* next;
}Queue;

Queue* front=NULL;
Queue* rear=NULL;

Queue* createNode(int value){
    Queue* new= (Queue*)malloc(sizeof (Queue));
    new->value=value;
    new->next=NULL;
    return new;
}

void enQueue(Queue* value){
    if(rear == NULL){
        front=rear=value;
        return;
    }
    rear->next=value;
    rear=value;
}

int peek(){
    if (front == NULL) {
        printf("UNDERFLOW\n");
        return -1;
    }
    return front->value;
}

int deQueue(){
    if (front == NULL) {
        printf("UNDERFLOW\n");
        return -1;
    }
    Queue* temp=front;
    int value=temp->value;
    front=front->next;

    if(front == NULL) rear= NULL;
    free(temp);
    return value;
}

void display(){
    Queue* temp=front;
    int i=1;
    while(temp != NULL){
        printf("%d)%d   ",i,temp->value);
        temp=temp->next;
        i++;
    }
}

int main() {
    enQueue(createNode(10));
    enQueue(createNode(20));
    enQueue(createNode(30));
    display();

    printf("\n");
    deQueue();
    deQueue();
    display();
}
