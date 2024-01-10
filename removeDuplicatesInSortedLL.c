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

// Function to remove duplicates from a sorted linked list
void removeDuplicates(struct Node* head) {
    if (head == NULL || head->next == NULL) {
        return; // Empty list or list with only one element
    }

    struct Node *p = head;
    while (p->next != NULL) {
        if (p->data == p->next->data) {
            struct Node *temp = p->next;
            p->next = p->next->next;
            free(temp);
        } 
        else {
            p = p->next;
        }
    }
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

int main() {
    struct Node* head = NULL;

    // Insert elements into the sorted linked list (including duplicates)
    insertAtEnd(&head, 1);
    insertAtEnd(&head, 2);
    insertAtEnd(&head, 2);
    insertAtEnd(&head, 3);
    insertAtEnd(&head, 4);
    insertAtEnd(&head, 4);
    insertAtEnd(&head, 4);
    insertAtEnd(&head, 5);

    printf("Original sorted linked list: ");
    displayLinkedList(head);

    // Remove duplicates from the sorted linked list
    removeDuplicates(head);

    printf("Sorted linked list after removing duplicates: ");
    displayLinkedList(head);

    return 0;
}