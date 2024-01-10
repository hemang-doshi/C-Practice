#include <stdio.h>
#include <stdlib.h>

struct Node{
    int data;
    struct Node *next;
};

//basically insert at end function
struct Node *enqueue(struct Node *head,int data){
    struct Node *ptr = (struct Node *)malloc(sizeof(struct Node));
    struct Node *p = head;
    if(head == NULL){
        ptr->data = data;
        head = ptr;
        ptr->next = NULL;
    }
    else{
        ptr->data = data;
        while(p->next != NULL){
            p = p->next;
        }
        p->next = ptr;
        ptr->next = NULL;
    }
    printf("Element %d has been enqueued",data);

    return head;
}

struct Node *dequeue(struct Node *head){
    struct Node *p = head;
    if(head == NULL){
        printf("cannot dequeue element");
    }
    else{
        printf("Element %d has been dequeued",p->data);
        head = p->next;
        free(p);
    }
    
    return head;
}

void display(struct Node *head){
    struct Node *p = head;
    while(p != NULL){
        printf("%d ",p->data);
        p = p->next;
    }
}

int main(){
    int choice,data;
    struct Node * head = NULL;
    do{
        printf("\nEnter 1 to enqueue\n");
        printf("Enter 2 to dequeue\n");
        printf("Enter 3 to display\n");
        printf("Enter 4 to exit\n");
        scanf("%d",&choice);
        if(choice == 1){
            printf("Enter element to be pushed: \n");
            scanf("%d",&data);
            head = enqueue(head,data);
        }
        else if(choice == 2){
            head = dequeue(head);
        }
        else if(choice == 3){
            display(head);
        }
        else{
            printf("Exit successful");
        }
    }while(choice != 4);

    return 0;
}