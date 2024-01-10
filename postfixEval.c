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
    return (1);
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
    return op1 * op2;
  }
  if (x == '%') {
    return op1 % op2;
  }
}

void push(stack *s, int x) {
  s->data[++s->top] = x;
}

int pop(stack *s) {
  int x;
  x = s->data[s->top--];

  return x;
}

int main() {

  stack s;
  char x;
  int op1, op2, val;
  init(&s);
  printf("Enter the expression: single digit operand and operators only ::  ");
  while ((x = getchar()) != '\n') {
    if (isdigit(x)) {    // if int then push to stack
      push(&s, x - '0'); // ascii of x - ascii of 0 gives int
    } else {
      op2 = pop(&s);
      op1 = pop(&s);
      val = evaluate(x, op1, op2);
      push(&s, val);
    }
  };

  val = pop(&s);
  printf("value of expression is  %d ", val);

  return 0;
}