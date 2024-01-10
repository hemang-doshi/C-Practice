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

// Function to insert a node at the beginning of the linked list
struct Node* insertAtBeginning(struct Node* head, int data) {
    struct Node* newNode = createNode(data);
    newNode->next = head;
    return newNode;
}

// Function to perform Bubble Sort on a singly linked list
void bubbleSortLinkedList(struct Node* head) {
    if (head == NULL || head->next == NULL) {
        return; // Empty list or list with only one element is already sorted
    }

    int swapped;
    struct Node* ptr;
    struct Node* lastPtr = NULL;

    do {
        swapped = 0;
        ptr = head;

        while (ptr->next != lastPtr) {
            if (ptr->data > ptr->next->data) {
                int temp = ptr->data;
                ptr->data = ptr->next->data;
                ptr->next->data = temp;
                swapped = 1;
            }
            ptr = ptr->next;
        }
        lastPtr = ptr;
    } while (swapped);
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

    // Insert elements into the linked list
    head = insertAtBeginning(head, 5);
    head = insertAtBeginning(head, 3);
    head = insertAtBeginning(head, 8);
    head = insertAtBeginning(head, 1);
    head = insertAtBeginning(head, 6);

    printf("Original linked list: ");
    displayLinkedList(head);

    // Sort the linked list
    bubbleSortLinkedList(head);

    printf("Sorted linked list: ");
    displayLinkedList(head);

    return 0;
}
