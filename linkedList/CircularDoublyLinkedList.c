#include <stdio.h>
#include <malloc.h>

typedef struct Node{
    struct Node* pre;
    int value;
    struct Node* next;

}Node;


Node* createStruct(int value){
    Node* new= (Node*) malloc(sizeof (Node));
    new->pre=NULL;
    new->next=NULL;
    new->value=value;
    return new;
}

Node* add_end(Node* head,Node* str){
    if (head == NULL) {
        str->next = str;
        str->pre = str;
        return str;
    }

    Node* tail=head->pre;

    tail->next=str;
    str->pre=tail;

    str->next=head;
    head->pre=str;

    return head;

}

Node* add_beg(Node* head,Node* str){
    if (head == NULL) {
        str->next = str;
        str->pre = str;
        return str;
    }

    head->pre->next=str;
    str->pre=head->pre;
    str->next=head;
    head->pre=str;

    return str;
}

Node* del_beg(Node* head){
    if (head == NULL) return NULL;
    if (head->next == head) {
        free(head);
        return NULL;
    }
    Node* tail=head->pre;
    Node* newHead=head->next;

    tail->next=head->next;
    newHead->pre=tail;
    free(head);
    return newHead;
}

Node* del_end(Node* head){
    if (head == NULL) return NULL;
    if (head->next == head) {
        free(head);
        return NULL;
    }

    Node* tail=head->pre;
    Node* newTail=tail->pre;

    newTail->next=head;
    head->pre=newTail;

    free(tail);

    return head;

}

void printList(Node* head){
    if(head == NULL) {
        printf("List is empty.\n");
        return;
    }
    Node*temp=head;
    int i=1;
    do {
        printf("%d)value:%d\n",i,temp->value);
        temp=temp->next;
        i++;
    }while(temp != head);
}

void freeList(Node* head){
    if (head == NULL) return;

    Node* temp=head;
    do{
        Node* next=temp->next;
        free(temp);
        temp=next;
    }while(temp!=head);

}

int main() {
    Node* head = NULL;

    Node* n1 = malloc(sizeof(Node)); n1->value = 10;
    Node* n2 = malloc(sizeof(Node)); n2->value = 20;
    Node* n3 = malloc(sizeof(Node)); n3->value = 30;

    head = add_beg(head, n1);
    head = add_end(head, n2);
    head = add_end(head, n3);

    printf("List after additions:\n");
    printList(head);

    head = del_beg(head);
    printf("After deleting first:\n");
    printList(head);

    head = del_end(head);
    printf("After deleting last:\n");
    printList(head);

    freeList(head);
    return 0;
}