#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define N 10

struct STACK{
    int arr[N];
    int top;
};

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
    else
        s->arr[++s->top] = element;
}

int pop(struct STACK *s){
    int poppedValue;
    if(isEmpty(s)){
        printf("Stack underflow.\n");
        return -1;
    }
    else{
        poppedValue = s->arr[s->top--];
        return poppedValue;
    }
}

int main(){
    int remainder;
    char result[100];
    struct STACK stack;
    int decValue;
    printf("Enter a decimal number: ");
    scanf("%d",&decValue);
    initialize(&stack);
    int i=0;
    while(decValue != 0){
        remainder = decValue % 2;
        push(&stack, remainder);
        decValue = decValue/2;
    }
    while(!isEmpty(&stack)){
        result[i++] = pop(&stack);
    }
    int size = i;
    printf("The binary value is: \n");
    for(int j=0;j<size;j++){
        printf("%d", result[j]);
    }
    printf("\n");

    return 0;
}