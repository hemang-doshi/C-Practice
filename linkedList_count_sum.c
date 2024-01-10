#include <stdio.h>
#include <stdlib.h>

struct Node
{
    int data;
    struct Node *next;
}*first = NULL;

void create(int A[], int n)
{
    struct Node *t, *last;
    first = (struct Node *)malloc(sizeof(struct Node));
    first -> data = A[0];
    first -> next = NULL;
    last = first;

    for(int i=1;i<n;i++)
    {
        t = (struct Node *)malloc(sizeof(struct Node));
        t -> data = A[i];
        t -> next=NULL;
        last -> next = t;
        last = t;
    }
}

int sum(struct Node *p)
{
    int x=0;
    while(p != 0)
    {
        x += p->data;
        p = p->next;
    }
    return x;
}

int main(){
    int A[] = {2,4,6,8,10};
    int n = 5; int result;

    create(A,n);
    result = sum(first);
    printf("%d", result);
    return 0;
}