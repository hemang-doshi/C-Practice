#include <stdio.h>
#include <stdlib.h>

struct Node
{
    int data;
    struct Node *next;
}*first = NULL;

void create(int A[],int n)
{
    int i;
    struct Node *t, *last;
    first = (struct Node*)malloc(sizeof(struct Node));
    first->data=A[0];
    first->next=NULL;
    last = first;

    for(i=1;i<n;i++)
    {
        t = (struct Node*)malloc(sizeof(struct Node));
        t->data=A[i];
        t->next=NULL;
        last->next=t;
        last = t;
    }
}

void display(struct Node *p)
{
    while (p != NULL)
    {
        printf("%d ",p->data);
        p=p->next;
    }
    
}

int max(struct Node *p)
{
    int x=0;
    int max = INT32_MIN;
    while( p != NULL)
    {
        if(p->data > max)
            max = p->data;
        p = p->next;
    }
    return max;
}

int main(){
    int result;
    int A[]={2,34,6,8,10};
    create(A,5);
    display(first);
    result = max(first);
    printf("The maximum digit in this Linked List is: %d",result);
    return 0;
}