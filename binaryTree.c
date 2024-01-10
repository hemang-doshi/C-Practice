#include <stdio.h>
#include <stdlib.h>

# define N 100

struct Node{
    int data;
    struct Node *leftChild;
    struct Node *rightChild;
};

struct Stack{
    struct Node *arr[N];
    int top;
};

int isEmpty(struct Stack *stack){
    if(stack->top == -1)
        return 1;
    else
        return 0;
}

void push(struct Stack *stack, struct Node *node){
    if(stack->top == N-1)
        printf("Stack overflow\n");
    else{
        stack->arr[++stack->top] = node;
    }
}

struct Node *pop(struct Stack *stack){
    return (stack->arr[stack->top--]);
}

struct Node *createNode(){
    struct Node *newNode = (struct Node *)malloc(sizeof(struct Node));
    newNode->leftChild = NULL;
    newNode->rightChild = NULL;
    
    return newNode;
}

struct Node *createBinaryTree(int data){
    int inputValue;
    if(data != -1){
        struct Node *newNode = createNode();
        newNode->data = data;
        printf("Enter left child of %d: \n",data);
        scanf("%d",&inputValue);
        newNode->leftChild = createBinaryTree(inputValue);
        printf("Enter right child of %d: \n",data);
        scanf("%d",&inputValue);
        newNode->rightChild = createBinaryTree(inputValue);

        return newNode;
    }

    return NULL;
}

void preOrder(struct Node *root){
    if(root != NULL){
        printf("%d ",root->data);
        preOrder(root->leftChild);
        preOrder(root->rightChild);
    }
}

void inOrder(struct Node *root){
    if(root != NULL){
        inOrder(root->leftChild);
        printf("%d ",root->data);
        inOrder(root->rightChild);
    }
}

void postOrder(struct Node *root){
    if(root != NULL){
        postOrder(root->leftChild);
        postOrder(root->rightChild);
        printf("%d ",root->data);
    }
}

void iterativeInorderTraversal(struct Node *root) {
    if (root == NULL) {
        printf("Empty tree\n");
        return;
    }

    struct Node *current = root;
    struct Stack *stack = (struct Stack *)malloc(sizeof(struct Stack));
    stack->top = -1;

    while (current != NULL || !isEmpty(stack)) {
        while (current != NULL) {
            push(stack, current);
            current = current->leftChild;
        }

        current = pop(stack);
        printf("%d ", current->data);

        current = current->rightChild;
    }

    free(stack);
}

void iterativePostorderTraversal(struct Node *root) {
    if (root == NULL) {
        printf("Empty tree\n");
        return;
    }

    struct Node *current = root;
    struct Stack *stack1 = (struct Stack *)malloc(sizeof(struct Stack));
    struct Stack *stack2 = (struct Stack *)malloc(sizeof(struct Stack));
    stack1->top = -1;
    stack2->top = -1;

    push(stack1, current);

    while (!isEmpty(stack1)) {
        current = pop(stack1);
        push(stack2, current);

        if (current->leftChild)
            push(stack1, current->leftChild);
        if (current->rightChild)
            push(stack1, current->rightChild);
    }

    while (!isEmpty(stack2)) {
        current = pop(stack2);
        printf("%d ", current->data);
    }

    free(stack1);
    free(stack2);
}

void iterativePreorderTraversal(struct Node *root) {
    if (root == NULL) {
        printf("Empty tree\n");
        return;
    }

    struct Node *current = root;
    struct Stack *stack = (struct Stack *)malloc(sizeof(struct Stack));
    stack->top = -1;

    push(stack, current);

    while (!isEmpty(stack)) {
        current = pop(stack);
        printf("%d ", current->data);

        if (current->rightChild)
            push(stack, current->rightChild);
        if (current->leftChild)
            push(stack, current->leftChild);
    }

    free(stack);
}


int main(){
    struct Node *root = NULL;
    int inputValue;
    printf("Enter the root node: \nEnter -1 for NULL:\n");
    scanf("%d",&inputValue);
    root = createBinaryTree(inputValue);

    printf("\nPreOrder traversal: \n");
    preOrder(root);

    printf("\nInOrder traversal: \n");
    inOrder(root);

    printf("\nPostOrder traversal: \n");
    postOrder(root);

    printf("\nIterative InOrder Traversal:\n");
    iterativeInorderTraversal(root);

    printf("\nIterative PostOrder Traversal:\n");
    iterativePostorderTraversal(root);

    printf("\nIterative PreOrder Traversal:\n");
    iterativePreorderTraversal(root);

    return 0;
}