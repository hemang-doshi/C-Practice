#include <stdio.h>
#include <stdlib.h>

struct Node
{
    int data;
    struct Node *next;
}*first = NULL;

void create(int A[], int n)
{
    struct Node *t,*last;
    first = (struct Node *)malloc(sizeof(struct Node));
    first -> data = A[0];
    first -> next = NULL;
    last = first;

    for(int i=1;i<n;i++)
    {
        t = (struct Node *)malloc(sizeof(struct Node));
        t -> data = A[i];
        t -> next = NULL;
        last -> next = t;
        last = t;
    }
}

void insert(int index, int x)
{
    struct Node *t, *p;
    t = (struct Node *)malloc(sizeof(struct Node));
    t -> data = x;
    t -> next = NULL;

    if(index == 0)
    {
        t -> next = first;
        first = t;
    }
    else
    {
        p = first;
        for(int i=0;i<index-1;i++)
        {
            p = p -> next;
            t -> next = p -> next;
            p -> next = t;
        }
    }
}

void display(struct Node *p)
{
    while( p != 0)
    {
        printf("%d ", p -> data);
        p = p -> next;
    }
}

int main(){
    int A[]={12,3,6,14,19}; int index, x, n = 5;
    printf("Enter the index at which you want to insert the element: \n");
    scanf("%d",&index);
    printf("Enter the element: \n");
    scanf("%d",&x);
    create(A,5);
    insert(index, x);
    display(first);

    return 0;
}