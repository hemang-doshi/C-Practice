#include <stdio.h>
#include <stdlib.h>

struct Node{
    int data;
    struct Node *next;
    struct Node *prev;
};

struct bst{
    int data;
    struct bst *leftChild;
    struct bst *rightChild;
};

struct bst *createNode(int data){
    struct bst *newNode = (struct bst *)malloc(sizeof(struct bst));
    newNode->data = data;
    newNode->leftChild = NULL;
    newNode->rightChild = NULL;

    return newNode;
}

void display(struct Node *head){
    struct Node *p = head;
    while(p != NULL){
        printf("%d ",p->data);
        p = p->next;
    }
}

struct Node *insertAtBeginning(struct Node *head, int data){
    struct Node *ptr = (struct Node *)malloc(sizeof(struct Node));
    if(head == NULL){
        ptr->data = data;
        head = ptr;
        ptr->next = NULL;
        ptr->prev = NULL;
    }
    else{
        ptr->data = data;
        ptr->next = head;
        head->prev = ptr;
        head = ptr;
    }

    return head;
}

struct Node *insertAtEnd(struct Node *head, int data){
    struct Node *ptr = (struct Node *)malloc(sizeof(struct Node));
    struct Node *p = head;
    while(p->next != NULL){
        p = p->next;
    }
    ptr->data = data;
    ptr->next = NULL;
    ptr->prev = p;
    p->next = ptr;

    return head;
}

struct Node *deleteEnd(struct Node *head){
    struct Node *p = head;
    while(p->next != NULL){
        p = p->next;
    }
    p->prev->next = NULL;
    free(p);

    return head;
}

struct bst *insert(struct bst *root, int data){
    if(root == NULL){
        return createNode(data);
    }
    if(data > root->data){
        root->rightChild = insert(root->rightChild,data);
    }
    else if(data < root->data){
        root->leftChild = insert(root->leftChild,data);
    }

    return root;
}

struct bst *createBSTfromLL(struct Node *head){
    struct bst *root = NULL;
    struct Node *p = head;
    while(p != NULL){
        root = insert(root,p->data);
        p = p->next;
    }

    return root;
} 

void displayBSTinOrder(struct bst *root){
    if(root != NULL){
        displayBSTinOrder(root->leftChild);
        printf("%d ",root->data);
        displayBSTinOrder(root->rightChild);
    }
}

int main(){
    struct Node *head = NULL;
    head = insertAtBeginning(head,1);
    head = insertAtEnd(head,3);
    head = insertAtEnd(head,6);
    head = insertAtEnd(head,4);
    head = insertAtEnd(head,5);
    head = deleteEnd(head);

    printf("\nDoubly linked list: \n");
    display(head);

    struct bst *root = createBSTfromLL(head);

    printf("\nBST inOrder traversal\n");
    displayBSTinOrder(root);

    return 0;
}