#include <stdio.h>
#include <stdlib.h>

#define Max 100

int queue[Max];
int rear=-1,front=-1;

void enQueue(int value){
    if(rear==Max-1){
        printf("OVERFLOW");
        return;
    }
    if(front ==-1 && rear ==-1){
        front=rear=0;
    }else rear++;
    queue[rear]=value;
}

int deQueue(){
    if (front == -1 || front > rear) {
        printf("UNDERFLOW\n");
        return -1;
    }
    int temp = queue[front];
    front++;
    return temp;
}

int peek(){
    if (front == -1 || front > rear) {
        printf("UNDERFLOW\n");
        return -1;
    }
    return queue[front];
}

void display(){
    for (int i = front; i <= rear; ++i) {
        printf("%d)%d   ",i+1,queue[i]);
    }
}

int main() {
    enQueue(10);
    enQueue(20);
    enQueue(30);
    enQueue(40);
    enQueue(50);
    enQueue(60);

    printf("6 element added:\n");
    display();

    deQueue();
    deQueue();

    printf("\n2 element removed:\n");
    display();

}