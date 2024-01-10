#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <ctype.h>

// Node structure for a binary expression tree
struct Node {
    char data;
    struct Node* left;
    struct Node* right;
};

// Function to create a new node
struct Node* createNode(char data) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = data;
    newNode->left = newNode->right = NULL;
    return newNode;
}

// Function to check if the character is an operator
bool isOperator(char c) {
    return (c == '+' || c == '-' || c == '*' || c == '/');
}

// Function to construct a binary expression tree from a postfix expression
struct Node* constructExpressionTree(char postfix[]) {
    struct Node* stack[100];
    int top = -1;
    struct Node *t, *t1, *t2;

    for (int i = 0; postfix[i] != '\0'; i++) {
        if (!isOperator(postfix[i])) {
            // Create a new node for the operand and push it onto the stack
            t = createNode(postfix[i]);
            stack[++top] = t;
        } else {
            // Pop two operands from the stack
            t = createNode(postfix[i]);
            t1 = stack[top--];
            t2 = stack[top--];

            // Make them children of the operator node
            t->right = t1;
            t->left = t2;

            // Push the operator node onto the stack
            stack[++top] = t;
        }
    }
    // Return the root of the expression tree
    return stack[top];
}

// Function to perform inorder traversal of the expression tree
void inorder(struct Node* root) {
    if (root != NULL) {
        inorder(root->left);
        printf("%c ", root->data);
        inorder(root->right);
    }
}

int main() {
    char postfix[] = "ab+cde+**"; // Sample postfix expression (abc*+de*+)

    struct Node* root = constructExpressionTree(postfix);

    printf("Inorder traversal of the constructed expression tree: ");
    inorder(root);
    printf("\n");

    return 0;
}
