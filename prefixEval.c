#include <ctype.h>
#include <stdio.h>
#define MAX 20

typedef struct {
  int data[MAX];
  int top;
} stack;

void init(stack *s) {
    s->top = -1;
}

int empty(stack *s) {
  if (s->top == -1) {
    return (1);
  }
  return 0;
}

int full(stack *s) {
  if (s->top == MAX - 1) {
    return (1); // 1 if full
  }
  return 0;
}

int evaluate(char x, int op1, int op2) {
  if (x == '+') {
    return (op1 + op2);
  }
  if (x == '-') {
    return (op1 - op2);
  }
  if (x == '/') {
    return (op1 / op2);
  }
  if (x == '*') {
    return (op1 * op2);
  }
  if (x == '%') {
    return (op1 % op2);
  }
}

void push(stack *s, int x) {
  s->top = s->top + 1;
  s->data[s->top] = x;
}

int pop(stack *s) {
  int x;
  x = s->data[s->top];
  s->top = s->top - 1;
  return x;
}

int main() {

  stack s;
  char x;
  char x1[MAX];
  int i = 0;
  printf("Enter the expression: single digit operand and operators only ::  ");
  while ((x = getchar()) != '\n') {
    x1[i] = x;
    i++;
  }
  int op1, op2, val;
  init(&s);
  for (int j = i - 1; j >= 0; j--) {
    x = x1[j];
    if (isdigit(x)) {    // if int then push to stack
        push(&s, x - '0'); // ascii of x - ascii of 0 gives int
    }
    else{
        op1 = pop(&s);
        op2 = pop(&s);
        val = evaluate(x, op1, op2);
        push(&s, val);
    }
  }

  val = pop(&s);
  printf("value of expression is  %d ", val);

  return 0;
}