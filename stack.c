#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define N 10

struct STACK{
    int stack[N];
    int top;
};

//initialize//
void initialize(struct STACK *s){
    s->top = -1;
}

bool isFull(struct STACK *s){
    return s->top == N-1;
}

bool isEmpty(struct STACK *s){
    return s->top == -1;
}

void push(struct STACK *s, int element){
    if(isFull(s))
        printf("Stack overflow.\n");
    else{
        s->stack[++s->top] = element;
    }
}

int pop(struct STACK *s){
    if(isEmpty(s)){
        printf("Stack underflow.\n");
        return -1;
    }
    else{
        int poppedValue = s->stack[s->top--];
        return poppedValue;
    }
}

void display(struct STACK *s){
    printf("The stack is: \n");
    for(int i=0;i<=s->top;i++){
        printf("%d\n",s->stack[i]);
    }
    printf("\n");
}

int main(){

    struct STACK stack;
    initialize(&stack);

    int choice,element,poppedValue;
    do{
        printf("Enter 1 to push\n");
        printf("Enter 2 to pop\n");
        printf("Enter 3 to display\n");
        printf("Enter 4 to exit\n");
        scanf("%d",&choice);

        if(choice == 1){
            printf("Enter element to push: \n");
            scanf("%d",&element);
            push(&stack,element);
        }
        else if(choice == 2){
            poppedValue = pop(&stack);
            printf("The element %d has been popped.\n",poppedValue);
        }
        else if(choice == 3){
            display(&stack);
        }
        else
            printf("Exit successful.\n");

    }while(choice != 4);

    return 0;
}