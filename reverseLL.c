#include <stdio.h>
#include <stdlib.h>

// Node structure for a singly linked list
struct Node {
    int data;
    struct Node* next;
};

// Function to create a new node
struct Node* createNode(int data) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    if (newNode == NULL) {
        printf("Memory allocation failed\n");
        exit(1);
    }
    newNode->data = data;
    newNode->next = NULL;
    return newNode;
}

// Function to insert a node at the end of the linked list
void insertAtEnd(struct Node** headRef, int data) {
    struct Node* newNode = createNode(data);

    if (*headRef == NULL) {
        *headRef = newNode;
        return;
    }

    struct Node* current = *headRef;
    while (current->next != NULL) {
        current = current->next;
    }
    current->next = newNode;
}

// Function to display the linked list
void displayLinkedList(struct Node* head) {
    struct Node* current = head;
    while (current != NULL) {
        printf("%d ", current->data);
        current = current->next;
    }
    printf("\n");
}

// Function to reverse a singly linked list
struct Node* reverseLinkedList(struct Node* head) {
    struct Node *prev = NULL;
    struct Node *p = head;
    struct Node *next = NULL;

    while (p != NULL) {
        next = p->next;
        p->next = prev;

        prev = p;
        p = next;
    }

    head = prev;

    return head;
}

int main() {
    struct Node* head = NULL;

    // Insert elements into the linked list
    insertAtEnd(&head, 1);
    insertAtEnd(&head, 2);
    insertAtEnd(&head, 3);
    insertAtEnd(&head, 4);
    insertAtEnd(&head, 5);

    printf("Original Linked List: ");
    displayLinkedList(head);

    // Reverse the linked list
    head = reverseLinkedList(head);

    printf("Reversed Linked List: ");
    displayLinkedList(head);

    return 0;
}
