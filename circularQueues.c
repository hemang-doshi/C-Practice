#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define N 5

struct CIRCULARQUEUE{
    int queue[N];
    int front;
    int rear;
};

struct CIRCULARQUEUE *createCircularQueue(){
    struct CIRCULARQUEUE *circQ;
    circQ = (struct CIRCULARQUEUE *)malloc(sizeof(struct CIRCULARQUEUE));
    circQ->front = circQ->rear = -1;
    return circQ;
}

bool isFull(struct CIRCULARQUEUE *cq){
    return (cq->front == 0 && cq->rear == N -1);
}

bool isEmpty(struct CIRCULARQUEUE *cq){
    return (cq->front == -1);
}

void enqueue(struct CIRCULARQUEUE *cq, int element){
    if(isFull(cq))
        printf("Queue is full. Cannot enqueue.\n");
    else if(cq->front == -1){
        cq->front = cq->rear = 0;
        cq->queue[cq->front] = element;
        printf("Element %d has been enqueued.\n",element);
    }
    else{
        cq->rear = (cq->rear + 1) % N;
        cq->queue[cq->rear] = element;
        printf("Element %d has been enqueued.\n",element);
    }
}

int dequeue(struct CIRCULARQUEUE *cq){
    int dequeuedElement;
    if(isEmpty(cq))
        printf("Queue is empty.\n");
    else{
        dequeuedElement = cq->queue[cq->front];
        if(cq->front == cq->rear)
            cq->front = cq->rear = -1;
        else{
            cq->front = (cq->front + 1) % N;
        }
    }
    return dequeuedElement;
}

void display(struct CIRCULARQUEUE *cq){
    int i;
    for(i=cq->front;i<=cq->rear;i++){
        printf("%d ",cq->queue[i]);
    }
}

int main(){
    struct CIRCULARQUEUE *circQ = createCircularQueue();
    int choice, dequeuedElement, element;
    do{
        printf("Enter 1 to Enqueue\n");
        printf("Enter 2 to Dequeue\n");
        printf("Enter 3 to Display\n");
        printf("Enter 4 to Exit\n");
        scanf("%d", &choice);

        if(choice == 1){
            printf("Enter element to be enqueued: ");
            scanf("%d",&element);
            enqueue(circQ,element);
        }
        else if(choice == 2){
            dequeuedElement = dequeue(circQ);
            printf("Element %d has been dequeued.\n",dequeuedElement);
        }
        else if(choice == 3)
            display(circQ);
        else
            printf("Exit successful.\n");
    }while(choice != 4);
    printf("\n");

    return 0;
}