#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define N 5

struct dynamicStack{
    int *arr;
    int top;
    int capacity;
};

struct dynamicStack *createDynamicStack(){
    //dynamically allocate memory for struct in heap
    struct dynamicStack *stack = (struct dynamicStack *)malloc(sizeof(struct dynamicStack));
    //set initial capacity
    stack->capacity = N;
    //set size of array to initial capacity dynamically
    stack->arr = (int *)malloc(stack->capacity*sizeof(int));
    //initialize top to -1
    stack->top = -1;

    return stack;
}

bool isFull(struct dynamicStack *ds){
    return (ds->top == ds->capacity-1);
}

bool isEmpty(struct dynamicStack *ds){
    return (ds->top == -1);
}

void increaseSize(struct dynamicStack *ds){
    ds->capacity *= 2;
    ds->arr = (int *)realloc(ds->arr,ds->capacity*sizeof(int));
}

void push(struct dynamicStack *ds, int element){
    if(isFull(ds)){
        increaseSize(ds);
        int i = ds->top += 1;
        ds->arr[i] = element;
    }
    else{
    ds->arr[++ds->top] = element;
    }
}

int pop(struct dynamicStack *ds){
    int poppedElement;
    if(isEmpty(ds))
        printf("Stack is Empty.\n");
    else{
        poppedElement = ds->arr[ds->top--];
    }
    return poppedElement;
}

void display(struct dynamicStack *ds){
    for(int i = 0; i<= ds->top;i++){
        printf("%d ",ds->arr[i]);
    }
    printf("\n");
}

int main(){
    struct dynamicStack *stack;
    int choice, element, poppedValue;
    stack = createDynamicStack();

    do{
        printf("Enter 1 to push\n");
        printf("Enter 2 to pop\n");
        printf("Enter 3 to display\n");
        printf("Enter 4 to exit\n");
        scanf("%d",&choice);

        if(choice == 1){
            printf("Enter element to push: \n");
            scanf("%d",&element);
            push(stack,element);
        }
        else if(choice == 2){
            poppedValue = pop(stack);
            printf("The element %d has been popped.\n",poppedValue);
        }
        else if(choice == 3){
            display(stack);
        }
        else
            printf("Exit successful.\n");

    }while(choice != 4);

    free(stack->arr);
    free(stack);

    return 0;
}