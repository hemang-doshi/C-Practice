#include <stdio.h>
#include <stdlib.h>

#define MAX_SIZE 100

struct Node {
    int data;
    struct Node *right;
    struct Node *left;
};

struct Stack {
    struct Node *nodeStack[MAX_SIZE];
    int top;
};

int isStackEmpty(struct Stack *stack) {
    if (stack->top == -1)
        return 1;
    else
        return 0;
}

void push(struct Stack *stack, struct Node *node) {
    if (stack->top == MAX_SIZE - 1) {
        printf("Stack Overflow");
        return;
    }
    stack->nodeStack[++stack->top] = node;
}

struct Node *pop(struct Stack *stack) {
    return (stack->nodeStack[stack->top--]);
}

struct Node *createNode() {
    return ((struct Node *)malloc(sizeof(struct Node)));
}

struct Node *createBinaryTree(int item) {
    int inputValue;
    if (item != -1) {
        struct Node *newNode = createNode();
        newNode->data = item;
        printf("Enter the left child of %d: ", item);
        scanf("%d", &inputValue);
        newNode->left = createBinaryTree(inputValue);
        printf("Enter the right child of %d: ", item);
        scanf("%d", &inputValue);
        newNode->right = createBinaryTree(inputValue);

        return newNode;
    }
    return NULL;
}

void inorderTraversal(struct Node *root) {
    if (root) {
        inorderTraversal(root->left);
        printf("%d ", root->data);
        inorderTraversal(root->right);
    }
}

void preorderTraversal(struct Node *root) {
    if (root) {
        printf("%d ", root->data);
        preorderTraversal(root->left);
        preorderTraversal(root->right);
    }
}

void postorderTraversal(struct Node *root) {
    if (root) {
        postorderTraversal(root->left);
        postorderTraversal(root->right);
        printf("%d ", root->data);
    }
}

void iterativeInorderTraversal(struct Node *root) {
    if (root == NULL) {
        printf("Empty Tree\n");
        return;
    }

    struct Stack *stack;
    stack->top = -1;
    struct Node *currentNode = root;

    while (currentNode != NULL || !isStackEmpty(stack)) {
        while (currentNode != NULL) {
            push(stack, currentNode);
            currentNode = currentNode->left;
        }
        currentNode = pop(stack);
        printf("%d ", currentNode->data);
        currentNode = currentNode->right;
    }
}


void iterativePreorderTraversal(struct Node *root) {
    struct Node *currentNode;
    struct Stack *stack;
    stack->top = -1;

    if (root == NULL) {
        printf("Empty Tree\n");
        return;
    }

    currentNode = root;
    push(stack, currentNode);

    while (!isStackEmpty(stack)) {
        currentNode = pop(stack);
        printf("%d ", currentNode->data);

        if (currentNode->right != NULL) {
            push(stack, currentNode->right);
        }
        if (currentNode->left != NULL) {
            push(stack, currentNode->left);
        }
    }
}


int main() {
    struct Node *root = NULL;
    int inputValue;

    printf("Creating the tree [enter -1 for NULL]: \n");
    scanf("%d", &inputValue);
    fflush(stdin);
    root = createBinaryTree(inputValue);

    printf("\nInorder Traversal:\n");
    inorderTraversal(root);

    printf("\nPreorder Traversal:\n");
    preorderTraversal(root);

    printf("\nPostorder Traversal:\n");
    postorderTraversal(root);

    printf("\nIterative Inorder Traversal:\n");
    iterativeInorderTraversal(root);

    printf("\nIterative Preorder Traversal:\n");
    iterativePreorderTraversal(root);

    return 0;
}