#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define initial_capacity 5

struct CIRCULARQUEUE{
    int *queue;
    int front;
    int rear;
    int capacity;
};

struct CIRCULARQUEUE *createCircularQueue();
bool isFull(struct CIRCULARQUEUE *cq);
bool isEmpty(struct CIRCULARQUEUE *cq);
void resize(struct CIRCULARQUEUE *cq);
void enqueue(struct CIRCULARQUEUE *cq, int element);
int dequeue(struct CIRCULARQUEUE *cq);
void display(struct CIRCULARQUEUE *cq);

int main(){
    struct CIRCULARQUEUE *circQ = createCircularQueue();
    int choice, element, deququedElement;
    do{
        printf("Enter 1 to enqueue\n");
        printf("Enter 2 to dequeue\n");
        printf("Enter 3 to display\n");
        printf("Enter 4 to exit\n");
        scanf("%d",&choice);

        if(choice == 1){
            printf("Enter element to be enqueued: \n");
            scanf("%d", &element);
            enqueue(circQ, element);
        }
        else if(choice == 2){
            deququedElement = dequeue(circQ);
            printf("%d has been dequeued\n",deququedElement);
        }
        else if(choice == 3)
            display(circQ);
        else
            printf("Exit successful\n");
    }while(choice != 4);

    free(circQ->queue);
    free(circQ);

    return 0;
}

struct CIRCULARQUEUE *createCircularQueue(){
    struct CIRCULARQUEUE *circQ;
    circQ = (struct CIRCULARQUEUE *)malloc(sizeof(struct CIRCULARQUEUE));
    circQ->capacity = initial_capacity;
    circQ->queue = (int *)malloc(circQ->capacity * sizeof(int));
    circQ->front = circQ->rear = -1;
    return circQ;
}

bool isFull(struct CIRCULARQUEUE *cq){
    return ((cq->front == 0 && cq->rear == cq->capacity -1));
}

bool isEmpty(struct CIRCULARQUEUE *cq){
    return (cq->front == -1);
}

void resize(struct CIRCULARQUEUE *cq){
    if(isFull(cq)){
        cq->capacity *= 2;
        cq->queue = (int *)realloc(cq->queue,cq->capacity * sizeof(int));
    }
}

void display(struct CIRCULARQUEUE *cq){
    for(int i = cq->front; i<= cq->rear;i++){
        printf("%d ",cq->queue[i]);
    }
    printf("\n");
}

void enqueue(struct CIRCULARQUEUE *cq, int element){
    if(isFull(cq)){
        resize(cq);
        cq->rear += 1;
    }
    else if(cq->front == -1){
        cq->front = cq->rear =0;
    }
    else{
        cq->rear = (cq->rear + 1) % cq->capacity;
    }
    cq->queue[cq->rear] = element;
}

int dequeue(struct CIRCULARQUEUE *cq){
    int dequeuedElement;
    if(isEmpty(cq)){
        printf("Queue is empty.\n");
        return -1;
    }
    else{
        dequeuedElement = cq->queue[cq->front];
        if(cq->front == cq->rear){
            cq->front = -1;
            cq->rear = -1;
        }
        else{
            cq->front = (cq->front + 1) % cq->capacity;
        }
        return dequeuedElement;
    }
}