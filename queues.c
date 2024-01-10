#include <stdio.h>
#include <stdlib.h>

#define N 3

struct QUEUE
{
    int arr[N];
    int front;
    int rear;
};

int isFull(struct QUEUE *queue){
    return (queue->rear == N-1);
}

int isEmpty(struct QUEUE *queue){
    return (queue->front == -1);
}

void enqueue(struct QUEUE *queue, int element){
    if(isFull(queue))
        printf("Queue is full.\n");
    else{
        if(isEmpty(queue))
            queue->front = 0;
        queue->rear++;
        queue->arr[queue->rear] = element;
    }
}

int dequeue(struct QUEUE *queue){
    int dequeuedElement;
    if(isEmpty(queue)){
        printf("Queue is empty.\n");
        return -1;
    }
    else{
        dequeuedElement = queue->arr[queue->front];
        if(queue->front == queue->rear){
            queue->front = -1;
            queue->rear = -1;
        }
        else{
            queue->front++;
        }
        return dequeuedElement;
    }
}

void display(struct QUEUE *queue){
    if(isEmpty(queue))
        printf("Queue is empty.\n");
    else{
        printf("Queue elements: \n");
        for(int i = queue->front; i <= queue->rear; i++){
            printf("%d ",queue->arr[i]);
        }
        printf("\n");
    }
}

int main(){
    struct QUEUE *q = (struct QUEUE *)malloc(sizeof(struct QUEUE));
    q->front = -1;
    q->rear = -1;
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
            enqueue(q, element);
        }
        else if(choice == 2){
            deququedElement = dequeue(q);
            printf("%d has been dequeued\n",deququedElement);
        }
        else if(choice == 3)
            display(q);
        else
            printf("Exit successful\n");
    }while(choice != 4);

    return 0;
}