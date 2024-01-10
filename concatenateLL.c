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

// Function to concatenate two singly linked lists
struct Node* concatenateLists(struct Node* list1, struct Node* list2) {
    if (list1 == NULL) {
        return list2;
    }
    if (list2 == NULL) {
        return list1;
    }

    struct Node* p = list1;
    while (p->next != NULL) {
        p = p->next;
    }
    p->next = list2;

    return list1;
}

int main() {
    struct Node* list1 = NULL;
    struct Node* list2 = NULL;

    // Insert elements into the first linked list
    insertAtEnd(&list1, 1);
    insertAtEnd(&list1, 2);
    insertAtEnd(&list1, 3);

    // Insert elements into the second linked list
    insertAtEnd(&list2, 4);
    insertAtEnd(&list2, 5);
    insertAtEnd(&list2, 6);

    printf("List 1: ");
    displayLinkedList(list1);

    printf("List 2: ");
    displayLinkedList(list2);

    // Concatenate the lists
    list1 = concatenateLists(list1, list2);

    printf("Concatenated List: ");
    displayLinkedList(list1);

    return 0;
}
