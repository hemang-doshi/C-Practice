#include <stdio.h>
#include <stdlib.h>

struct Node{
    int data;
    struct Node *next;
};

struct Node * push(struct Node *head, int data){
    struct Node *ptr = (struct Node *)malloc(sizeof(struct Node));
    struct Node *p = head;
    if(head == NULL){
        ptr->data = data;
        head = ptr;
        ptr->next = NULL;
    }
    else{
        ptr->data = data;
        ptr->next = head;
        head = ptr;
        printf("Element %d has been pushed into the stack\n",data);
    }

    return head;
}

struct Node *pop(struct Node *head){
    struct Node *p = head;
    if(head == NULL){
        printf("Stack underflow.Cannot pop element");
    }
    else{
        printf("Element %d has been popped from the stack\n",p->data);
        head = p->next;
        free(p);
    }

    return head;
}

void display(struct Node *head){
    printf("Stack: \n");
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
        printf("\nEnter 1 to push\n");
        printf("Enter 2 to pop\n");
        printf("Enter 3 to display\n");
        printf("Enter 4 to exit\n");
        scanf("%d",&choice);
        if(choice == 1){
            printf("Enter element to be pushed: \n");
            scanf("%d",&data);
            head = push(head,data);
        }
        else if(choice == 2){
            head = pop(head);
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