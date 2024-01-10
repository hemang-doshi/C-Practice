#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define MAX_SIZE 100

struct Deque {
    int arr[MAX_SIZE];
    int front;
    int rear;
};

void initDeque(struct Deque* deque) {
    deque->front = -1;
    deque->rear = -1;
}

bool isFull(struct Deque* deque) {
    return (deque->front == 0 && deque->rear == MAX_SIZE - 1);
}

bool isEmpty(struct Deque* deque) {
    return deque->front == -1;
}

void insertFront(struct Deque* deque, int value) {
    if (isFull(deque)) {
        printf("Deque is full. Cannot insert at the front.\n");
        return;
    }

    if (isEmpty(deque)) {
        deque->front = 0;
        deque->rear = 0;
    } else if (deque->front == 0) {
        deque->front = MAX_SIZE - 1;
    } else {
        deque->front--;
    }

    deque->arr[deque->front] = value;
}

void insertRear(struct Deque* deque, int value) {
    if (isFull(deque)) {
        printf("Deque is full. Cannot insert at the rear.\n");
        return;
    }

    if (isEmpty(deque)) {
        deque->front = 0;
        deque->rear = 0;
    } else if (deque->rear == MAX_SIZE - 1) {
        deque->rear = 0;
    } else {
        deque->rear++;
    }

    deque->arr[deque->rear] = value;
}

int deleteFront(struct Deque* deque) {
    if (isEmpty(deque)) {
        printf("Deque is empty. Cannot delete from the front.\n");
        return -1; // Error code
    }

    int deletedValue = deque->arr[deque->front];

    if (deque->front == deque->rear) {
        deque->front = -1;
        deque->rear = -1;
    } else if (deque->front == MAX_SIZE - 1) {
        deque->front = 0;
    } else {
        deque->front++;
    }

    return deletedValue;
}

int deleteRear(struct Deque* deque) {
    if (isEmpty(deque)) {
        printf("Deque is empty. Cannot delete from the rear.\n");
        return -1; // Error code
    }

    int deletedValue = deque->arr[deque->rear];

    if (deque->front == deque->rear) {
        deque->front = -1;
        deque->rear = -1;
    } else if (deque->rear == 0) {
        deque->rear = MAX_SIZE - 1;
    } else {
        deque->rear--;
    }

    return deletedValue;
}

void display(struct Deque* deque) {
    if (isEmpty(deque)) {
        printf("Deque is empty.\n");
        return;
    }

    printf("Deque elements from front to rear: ");
    int i = deque->front;
    do {
        printf("%d ", deque->arr[i]);
        if (i == deque->rear && i != deque->front) {
            break;
        }
        i = (i + 1) % MAX_SIZE;
    } while (i != (deque->rear + 1) % MAX_SIZE);
    printf("\n");
}

int main() {
    struct Deque *deque = (struct Deque *)malloc(sizeof(struct Deque));
    initDeque(deque);

    insertFront(deque, 10);
    insertRear(deque, 20);
    insertFront(deque, 5);
    insertRear(deque, 30);

    display(deque);

    int frontValue = deleteFront(deque);
    printf("Deleted front element: %d\n", frontValue);

    int rearValue = deleteRear(deque);
    printf("Deleted rear element: %d\n", rearValue);

    display(deque);

    return 0;
}
