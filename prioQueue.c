#include <stdio.h>
#include <stdlib.h>

#define N 10

struct PriorityQueue {
    int arr[N];
    int front;
    int rear;
};

void initPriorityQueue(struct PriorityQueue *pq) {
    pq->front = -1;
    pq->rear = -1;
}

int isFull(struct PriorityQueue *pq) {
    return pq->front == 0 && pq->rear == N - 1;
}

int isEmpty(struct PriorityQueue *pq) {
    return pq->front == -1;
}

void enqueue(struct PriorityQueue *pq, int data) {
    if (isFull(pq)) {
        printf("Priority Queue is full. Cannot enqueue.\n");
        return;
    }

    if (isEmpty(pq)) {
        pq->front = 0;
        pq->rear = 0;
        pq->arr[pq->rear] = data;
    } else {
        int i = pq->rear;
        while (i >= pq->front && data < pq->arr[i]) {
            pq->arr[i + 1] = pq->arr[i];
            i--;
        }
        pq->arr[i + 1] = data;
        pq->rear++;
    }
}

void dequeue(struct PriorityQueue *pq) {
    if (isEmpty(pq)) {
        printf("Priority Queue is empty. Cannot dequeue.\n");
        return;
    }

    printf("Dequeued element with priority: %d\n", pq->arr[pq->front]);
    
    if (pq->front == pq->rear) {
        pq->front = -1;
        pq->rear = -1;
    } else {
        pq->front++;
    }
}

void display(struct PriorityQueue *pq) {
    if (isEmpty(pq)) {
        printf("Priority Queue is empty.\n");
        return;
    }

    printf("Priority Queue elements: ");
    for (int i = pq->front; i <= pq->rear; ++i) {
        printf("%d ", pq->arr[i]);
    }
    printf("\n");
}

int main() {
    struct PriorityQueue pq;
    initPriorityQueue(&pq);

    enqueue(&pq, 3);
    enqueue(&pq, 6);
    enqueue(&pq, 1);
    enqueue(&pq, 9);
    enqueue(&pq, 2);

    display(&pq);

    dequeue(&pq);
    dequeue(&pq);

    display(&pq);

    return 0;
}
