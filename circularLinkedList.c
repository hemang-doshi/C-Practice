#include <stdio.h>
#include <stdlib.h>

struct Node{
    char data;
    struct Node *next;
};

//traversal
void listTraversal(struct Node *head){
    struct Node *p = head;
    printf("\nCircular Linked List: \n");
    do{
        printf("%c ",p->data);
        p = p->next;
    }while(p != head);
}

//case 1
struct Node *insertAtBeginning(struct Node *head, char data){
    struct Node *ptr = (struct Node *)malloc(sizeof(struct Node));
    ptr->data = data;
    if(head == NULL){
        head = ptr;
        ptr->next = head;
    }
    else{
        struct Node *p = head;
        while(p->next != head){
            p = p->next;
        }
        p->next = ptr;
        ptr->next = head;
        head = ptr;
    }

    return head;
}

//case 2
struct Node *insertAtIndex(struct Node *head,int index, char data){
    struct Node *ptr = (struct Node *)malloc(sizeof(struct Node));
    struct Node *p = head;
    int i = 0;
    while(i != index-1){
        p = p->next;
        i++;
    }
    ptr->data = data;
    ptr->next = p->next;
    p->next = ptr;

    return head;
}

//case 3
struct Node *insertAtEnd(struct Node *head, char data){
    struct Node *ptr = (struct Node *)malloc(sizeof(struct Node));
    struct Node *p = head;
    ptr->data = data;
    while(p->next != head){
        p = p->next;
    }
    ptr->next = p->next;
    p->next = ptr;

    return head;
}

//case 1
struct Node *deleteEnd(struct Node *head){
    struct Node *p = head;
    struct Node *q = head->next;
    while(q->next != head){
        p = p->next;
        q = q->next;
    }
    p->next = head;
    free(q);

    return head;
}

//case 2
struct Node *deleteBeginning(struct Node *head){
    struct Node *p = head;
    struct Node *q = head->next;
    while(p->next != head){
        p = p->next;
        q = q->next;
    }
    p->next = q->next;
    head = q->next;
    free(q);

    return head;
}

//case 3
struct Node *deleteAtIndex(struct Node *head, int index){
    struct Node *p = head;
    struct Node *q = head->next;

    int i = 0;
    while(i != index-1){
        p = p->next;
        q = q->next;
    }
    p->next = q->next;
    free(q);

    return head;
}

int main(){

    struct Node *head = (struct Node *)malloc(sizeof(struct Node));
    head = NULL;

    head = insertAtBeginning(head,'a');
    head = insertAtEnd(head,'b');
    listTraversal(head);
    head = insertAtEnd(head,'c');
    head = insertAtEnd(head,'d');
    head = insertAtEnd(head,'e');
    head = insertAtEnd(head,'f');
    listTraversal(head);
    head = insertAtIndex(head,2,'z');
    listTraversal(head);
    head = deleteEnd(head);
    listTraversal(head);
    head = deleteBeginning(head);
    head = deleteAtIndex(head,3);
    listTraversal(head);

    return 0;
}