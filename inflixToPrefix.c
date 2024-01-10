#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

#define N 100

struct STACK {
    char arr[N];
    int top;
};

void initialize(struct STACK *s) {
    s->top = -1;
}

bool isFull(struct STACK *s) {
    return s->top == N - 1;
}

bool isEmpty(struct STACK *s) {
    return s->top == -1;
}

void push(struct STACK *s, char element) {
    if (isFull(s))
        printf("Stack overflow.\n");
    else {
        s->arr[++s->top] = element;
    }
}

char pop(struct STACK *s) {
    char poppedValue;
    if (isEmpty(s)) {
        printf("Stack underflow.\n");
        exit(1);
    } else {
        poppedValue = s->arr[s->top--];
        return poppedValue;
    }
}

int precedence(char operator) {
    if (operator == '+' || operator == '-')
        return 1;
    if (operator == '*' || operator == '/')
        return 2;
    return 0;
}

bool isOperator(char symbol) {
    return (symbol == '+' || symbol == '-' || symbol == '*' || symbol == '/');
}

void infixToPrefix(char infix[], char prefix[]) {
    struct STACK stack;
    initialize(&stack);
    int infixLength = strlen(infix);
    int prefixIndex = 0;

    // Reverse the infix expression
    char reverseInfix[N];
    for (int i = 0; i < infixLength; i++) {
        if (infix[i] == '(')
            reverseInfix[i] = ')';
        else if (infix[i] == ')')
            reverseInfix[i] = '(';
        else
            reverseInfix[i] = infix[i];
    }
    reverseInfix[infixLength] = '\0';

    for (int i = 0; i < infixLength; i++) {
        char symbol = reverseInfix[i];
        if (symbol == ' ' || symbol == '\t')
            continue;

        if (!isOperator(symbol) && symbol != '(' && symbol != ')')
            prefix[prefixIndex++] = symbol;
        else if (symbol == ')')
            push(&stack, symbol);
        else if (symbol == '(') {
            while (!isEmpty(&stack) && stack.arr[stack.top] != ')') {
                prefix[prefixIndex++] = pop(&stack);
            }
            pop(&stack);
        } else {
            while (!isEmpty(&stack) && precedence(stack.arr[stack.top]) >= precedence(symbol)) {
                prefix[prefixIndex++] = pop(&stack);
            }
            push(&stack, symbol);
        }
    }
    while (!isEmpty(&stack)) {
        prefix[prefixIndex++] = pop(&stack);
    }
    prefix[prefixIndex] = '\0';

    // Reverse the prefix expression to get the correct order
    int len = strlen(prefix);
    for (int i = 0; i < len / 2; i++) {
        char temp = prefix[i];
        prefix[i] = prefix[len - i - 1];
        prefix[len - i - 1] = temp;
    }
}

int main() {
    char infix[N], prefix[N];
    printf("Enter an infix expression: \n");
    gets(infix);
    infixToPrefix(infix, prefix);
    printf("The prefix expression is: %s\n", prefix);

    return 0;
}
