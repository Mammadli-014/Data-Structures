#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
    struct Node *pre;
    int  id;
    struct Node *next;
} Node;


Node* create_node(int id) {
    Node *n = (Node*)malloc(sizeof(Node));
    n->id = id;
    n->next = NULL;
    n->pre=NULL;
    return n;
}

int size(Node* head){
    if(head == NULL){
        return 0;
    }
    int i=0;
    Node* temp=head;
    do {
        i++;
        temp=temp->next;
    }while(temp!=head);
    return i;
}

Node* insert_at(Node* head,int index,Node* n){
    if (head == NULL) {
        n->pre=n;
        n->next=n;
        return n;
    }

    if(size(head) < index){
        printf("Out of bounds!");
        return head;
    }

    Node *temp=head;
    int i=0;
    do {
        if(index == i){
         Node *pre=temp->pre;
         pre->next=n;
         n->pre=pre;

         n->next=temp;
         temp->pre=n;
         if (index == 0) return n;

         return head;
        }

        i++;
        temp=temp->next;

    }while(temp !=head);

    return head;
}

Node* prepend(Node *head , Node *n) {
    if (head == NULL) {
        n->pre = n;
        n->next = n;
        return n;
    }
    Node *tail=head->pre;

    tail->next=n;
    head->pre=n;

    n->next = head;
    n->pre=tail;

    return n;
}

Node* append(Node *head , Node *n) {
    if (head == NULL) {
        n->pre=n;
        n->next=n;
        return n;
    }
    Node *tail=head->pre;

    tail->next=n;
    head->pre=n;

    n->pre=tail;
    n->next=head;

    return head;
}

Node* get(Node* head,int index){
    int i=0;
    Node* temp=head;

    do {
        if(i == index){ return temp;}
        i++;
        temp=temp->next;
    }while(temp != head);
    return NULL;
}

Node* delete_begining(Node *head) {
    if (head == NULL) return NULL;
    if (head->next == head) {
        free(head);
        return NULL;
    }

    Node *tail=head->pre;
    Node* newHead=head->next;

    tail->next=newHead;
    newHead->pre=tail;


    free(head);
    return newHead;
}

Node* delete_by_id(Node *head, int id){
    if (head == NULL) return NULL;
    Node *temp = head;

    do {
        if (temp->id == id) {

            if (temp->next == temp) {
                free(temp);
                return NULL;
            }
            temp->pre->next = temp->next;
            temp->next->pre = temp->pre;

            if (temp == head) head = temp->next;

            free(temp);
            return head;
        }

        temp = temp->next;
    } while (temp != head);

    printf("ID not found!");
    return head;
}


int contains(Node* head, int id){
    if (head == NULL) return 0;
    Node* temp=head;
    do{
        if(temp->id == id) return 1;
        temp=temp->next;
    }while(temp!=head);
    return 0;
}

void print_list(Node *head) {
    if (head == NULL) { puts("(empty)"); return; }
    int i = 1;
    Node *temp=head;
    do {
        printf("%d) %d\n", i , temp->id);
        temp = temp->next; i++;
    }while(temp!=head);
}