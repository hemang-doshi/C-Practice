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

// Function to display the linked list
void displayLinkedList(struct Node* head) {
    struct Node* current = head;
    while (current != NULL) {
        printf("%d ", current->data);
        current = current->next;
    }
    printf("\n");
}

// Function to find the union of two linked lists
struct Node* findUnion(struct Node* list1, struct Node* list2) {
    struct Node* result = NULL;

    while (list1 != NULL && list2 != NULL) {
        if (list1->data == list2->data) {
            insertAtEnd(&result, list1->data);
            list1 = list1->next;
            list2 = list2->next;
        } 
        else if (list1->data < list2->data) {
            insertAtEnd(&result, list1->data);
            list1 = list1->next;
        } 
        else {
            insertAtEnd(&result, list2->data);
            list2 = list2->next;
        }
    }

    // Copy remaining elements from list1, if any
    while (list1 != NULL) {
        insertAtEnd(&result, list1->data);
        list1 = list1->next;
    }

    // Copy remaining elements from list2, if any
    while (list2 != NULL) {
        insertAtEnd(&result, list2->data);
        list2 = list2->next;
    }

    return result;
}

// Function to find the intersection of two linked lists
struct Node* findIntersection(struct Node* list1, struct Node* list2) {
    struct Node* result = NULL;

    while (list1 != NULL && list2 != NULL) {
        if (list1->data == list2->data) {
            insertAtEnd(&result, list1->data);
            list1 = list1->next;
            list2 = list2->next;
        } 
        else if (list1->data < list2->data) {
            list1 = list1->next;
        } 
        else {
            list2 = list2->next;
        }
    }

    return result;
}

int main() {
    struct Node* list1 = NULL;
    struct Node* list2 = NULL;

    // Insert elements into the sorted linked lists
    insertAtEnd(&list1, 1);
    insertAtEnd(&list1, 2);
    insertAtEnd(&list1, 3);
    insertAtEnd(&list1, 4);
    insertAtEnd(&list1, 6);

    insertAtEnd(&list2, 2);
    insertAtEnd(&list2, 4);
    insertAtEnd(&list2, 6);
    insertAtEnd(&list2, 8);

    printf("List 1: ");
    displayLinkedList(list1);

    printf("List 2: ");
    displayLinkedList(list2);

    // Find and display the union of the lists
    struct Node* unionList = findUnion(list1, list2);
    printf("Union of List 1 and List 2: ");
    displayLinkedList(unionList);

    // Find and display the intersection of the lists
    struct Node* intersectionList = findIntersection(list1, list2);
    printf("Intersection of List 1 and List 2: ");
    displayLinkedList(intersectionList);

    return 0;
}