#include <stdio.h>
#include <stdlib.h>

struct Node{
    int data;
    struct Node *next;
    struct Node *prev;
};

void display(struct Node *head){
    struct Node *p = head;
    printf("\nDoubly Linked List: \n");
    while(p != NULL){
        printf("%d ",p->data);
        p = p->next;
    }
}

void displayReverse(struct Node *head){
    struct Node *p = head;
    printf("\nReverse Doubly Linked List: \n");
    while(p->next != NULL){
        p = p->next;
    }
    while(p != NULL){
        printf("%d ", p->data);
        p = p->prev;
    }
}

struct Node *insertAtBeginning(struct Node *head,int data){
    struct Node *ptr = (struct Node *)malloc(sizeof(struct Node));
    if(head == NULL){
        ptr->data = data;
        ptr->prev = NULL;
        ptr->next = NULL;
        head = ptr;
    }
    else{
        ptr->data = data;
        ptr->prev = NULL;
        ptr->next = head;
        head->prev = ptr;
        head = ptr;
    }

    return head;
}

struct Node *insertAtEnd(struct Node *head, int data){
    struct Node *ptr = (struct Node *)malloc(sizeof(struct Node));
    struct Node *p = head;
    ptr->data = data;
    while(p->next != NULL){
        p = p->next;
    }
    p->next = ptr;
    ptr->prev = p;
    ptr->next = NULL;

    return head;
}

struct Node *insertAtIndex(struct Node *head, int index, int data){
    struct Node *ptr = (struct Node *)malloc(sizeof(struct Node));
    struct Node *p = head;
    int i = 0;
    while(i != index-1){
        p = p->next;
        i++;
    }
    ptr->data = data;
    ptr->next = p->next;
    p->next->prev = ptr;
    p->next = ptr;
    ptr->prev = p;

    return head;
}

struct Node *deleteBeginning(struct Node *head){
    struct Node *p = head;
    head = p->next;
    p->next->prev = NULL;
    free(p);

    return head;
}

struct Node *deleteEnd(struct Node *head){
    struct Node *p = head;
    while(p->next != NULL){
        p = p->next;
    }
    p->prev->next = NULL;
    free(p);

    return head;
}

struct Node *deleteAtIndex(struct Node *head, int index){
    struct Node *p = head;
    int i = 0;
    while(i != index+1){
        p = p->next;
        i++;
    }
    p->prev->next = p->next;
    free(p);

    return head;
}

int main(){
    struct Node *head = NULL;
    head = insertAtBeginning(head,5);
    head = insertAtEnd(head,6);
    head = insertAtEnd(head,7);
    head = insertAtEnd(head,8);
    head = insertAtBeginning(head,10);
    head = insertAtBeginning(head,1);
    head = insertAtIndex(head,2,100);
    head = deleteBeginning(head);
    head = deleteEnd(head);
    head = deleteAtIndex(head,1);
    display(head);
    displayReverse(head);

    return 0;
}