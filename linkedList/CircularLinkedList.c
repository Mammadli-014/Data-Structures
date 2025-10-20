#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
    int  id;
    struct Node *next;
} Node;


Node* create_node(int id) {
    Node *n = (Node*)malloc(sizeof(Node));
    n->id = id;
    n->next = NULL;
    return n;
}

Node* prepend(Node *head , Node *value) {
    if(head == NULL){
        value->next=value;
        return value;
    }

    Node* temp=head;
    while(temp->next != head){
        temp=temp->next;
    }
    temp->next=value;
    value->next = head;
    return value;
}

Node* append(Node *head , Node* value) {
    if(head == NULL){
        value->next=value;
        return value;
    }
    Node* temp=head;
    while(temp->next != head){
        temp=temp->next;
    }
    temp->next=value;
    value->next=head;
    return head;
}

Node* get(Node* head,int index){
    int i=0;
    Node* temp=head;
    do {
        if (i == index) return temp;
        temp = temp->next;
        i++;
    } while (temp != head);
    return NULL;
}

int size(Node* head){
    int i=0;
    Node* temp=head;
    do{
        i+=1;
        temp=temp->next;

    }while(temp!=head);
    return i;
}

Node* delete_by_id(Node *head,int id){
    Node* temp=head;
    Node* pre;

    if(head ==NULL) return NULL;

    if (head->id == id && head->next == head) {
        free(head);
        return NULL;
    }

    if (head->id == id) {
        Node *tail = head;
        while (tail->next != head) tail = tail->next;
        tail->next = head->next;
        temp = head->next;
        free(head);
        return temp;
    }

    do{
        if(id == temp->id){
            pre->next=temp->next;
            free(temp);
            return head;
        }
        pre=temp;
        temp=temp->next;

    }while(temp!=head);
    return head;
}

Node* delete_begining(Node *head) {
    if (head == NULL) return NULL;

    Node *old = head;
    Node* temp=head;
    while(temp->next != head){
        temp=temp->next;
    }
    head = old->next;
    temp->next=head;

    free(old);
    return head;
}

int contains(Node* head, int id){
    Node* temp=head;
   do{
        if(temp->id == id) return 1;
        temp=temp->next;
    } while(temp!=head);
    return 0;
}

void print_list(Node *head) {
    if (head == NULL) { puts("(empty)"); return; }
    int i = 1;
    Node * temp=head;
    do{
        printf("%d) %d\n", i , temp->id);
        temp = temp->next; i++;
    }while (temp !=head);
}