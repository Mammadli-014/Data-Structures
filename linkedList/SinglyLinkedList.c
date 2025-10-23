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

Node* insert_at(Node* head,int index,Node* value){
    Node* temp=head;
    Node* pre;
    int i=0;

    if (index == 0 || head == NULL) {
        value->next = head;
        return value;
    }

    while(temp != NULL && i<index){
        pre=temp;
        temp=temp->next;
        i++;
    }
    if(i!= index){
        printf("Out of bounds\n");
        return head;
    }

    pre->next=value;
    value->next =temp;

    return head;
}

Node* prepend(Node *head , int id) {
    Node *n = create_node(id);
    n->next = head;
    return n;
}

Node* append(Node *head , int id) {
    Node *n = create_node(id);
    if (head == NULL) return n;
    Node *cur = head;
    while (cur->next) cur = cur->next;
    cur->next = n;
    return head;
}

Node* get(Node* head,int index){
    int i=0;
    Node* temp=head;
    while(temp !=NULL && i<index){
        i+=1;
        temp=temp->next;
    }
    if (temp == NULL) {
        printf("Index out of bounds\n");
        return NULL;
    }
    return temp;
}

int size(Node* head){
    int i=0;
    Node* temp=head;
    while(temp!=NULL){
        i+=1;
        temp=temp->next;
    }
    return i;
}

Node* delete_by_id(Node *head,int id){
    Node* temp=head;
    Node* pre;

    if(head ==NULL) return NULL;
    if(head->id == id){
        head=head->next;
        free(temp);
        return head;
    }

    while(temp!=NULL && temp->id != id){
        pre=temp;
        temp=temp->next;
    }

    if(temp== NULL){
        printf("ID not found\n");
        return head;
    }

    pre->next=temp->next;
    free(temp);
    return head;
}

Node* delete_begining(Node *head) {
    if (head == NULL) return NULL;
    Node *old = head;
    head = old->next;
    free(old);
    return head;
}

int contains(Node* head, int id){
    Node* temp=head;
    while(temp!=NULL){
        if(temp->id == id) return 1;
        temp=temp->next;
    }
    return 0;
}

void print_list(Node *head) {
    if (head == NULL) { puts("(empty)"); return; }
    int i = 1;
    while (head) {
        printf("%d) %d\n", i , head->id);
        head = head->next; i++;
    }
}