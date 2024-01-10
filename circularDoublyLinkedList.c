#include <stdio.h>
#include <stdlib.h>

struct Node{
    int data;
    struct Node *next;
    struct Node *prev;
};

void display(struct Node *head){
    struct Node *p = head;
    printf("\nCircular Doubly Linked List: \n");
    do{
        printf("%d ",p->data);
        p = p->next;
    }while(p != head);
}

void displayReverse(struct Node *head){
    struct Node *p = head->prev;
    printf("\nReverse Circular Doubly Linked List: \n");
    do{
        printf("%d ",p->data);
        p = p->prev;
    }while(p != head->prev);
}

struct Node *insertAtBeginning(struct Node *head, int data){
    struct Node *ptr = (struct Node *)malloc(sizeof(struct Node));
    if(head == NULL){
        ptr->data = data;
        ptr->next = ptr;
        ptr->prev = ptr;
        head = ptr;
    }
    else{
        struct Node *p = head;
        while(p->next != head){
            p = p->next;
        }
        ptr->data = data;
        p->next = ptr;
        ptr->prev = p;
        ptr->next = head;
        head->prev = ptr;
        head = ptr;
    }

    return head;
}

struct Node *insertAtEnd(struct Node *head, int data){
    struct Node *ptr = (struct Node *)malloc(sizeof(struct Node));
    struct Node *p = head->prev;
    ptr->data = data;
    ptr->next = head;
    head->prev = ptr;
    p->next = ptr;
    ptr->prev = p;
    
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
    struct Node *p = head->prev;
    struct Node *q = head->next;
    p->next = q;
    q->prev = p;
    free(head);
    head = q;

    return head;
}

struct Node *deleteEnd(struct Node *head){
    struct Node *p = head;
    while(p->next != head){
        p = p->next;
    }
    p->prev->next = head;
    head->prev = p->prev;
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
    p->next->prev = p->prev;
    p->prev->next = p->next;
    free(p);

    return head;
}

int main(){
    struct Node *head = NULL;
    head = insertAtBeginning(head,1);
    head = insertAtEnd(head,2);
    head = insertAtEnd(head,3);
    head = insertAtEnd(head,4);
    head = insertAtEnd(head,6);
    head = insertAtIndex(head,4,5);
    head = deleteBeginning(head);
    head = deleteEnd(head);
    head = deleteAtIndex(head,1);
    display(head);
    displayReverse(head);

    return 0;
}
