#include <stdio.h>
#include <stdlib.h>

#define Max 100
int queue[Max];
int front=-1;
int rear=-1;


void enQueue(int value){
    if((rear+1) % Max == front){
        printf("Queue is full!");
        return;
    }
    if(front == -1) front ++;
    rear= (rear+1)%Max;
    queue[rear]=value;
}

int deQueue(){
    if(front == -1){
        printf("UNDERFLOW!");
        return -1;
    }
    int data = queue[front];
    queue[front]= (int) NULL;
    front=(front+1)%Max;
    return data;
}

int peek(){
    if(front == -1){
        printf("UNDERFLOW!");
        return -1;
    }
    return queue[front];
}

void display(){
    int j=0;
    for (int i = front; i <=rear ; ++i) {
        j++;
        printf("%d)%d   ",j,queue[i]);
    }
    printf("\n");
}

int main()
{
    enQueue(10);
    enQueue(20);
    enQueue(30);
    display();

    display();

    return 0;
}
