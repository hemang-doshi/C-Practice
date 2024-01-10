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

int search(struct Node *p, int key)
{
    int max, flag = 0; int count = 0;
    while(p != NULL)
    {
        if( key == p -> data)
            return count;
        else
        {
            p = p->next;
            count++;
        }

    }
}


int main(){
    int result,key;
    int A[]={1,3,5,7,9};
    create(A,5);
    display(first);
    printf("Enter element to be searched: ");
    scanf("%d",&key);
    result = search(first, key);
    if(result >= 0)
        printf("The element is found at node %d",result);
    else
        printf("The element is not found");
    return 0;
}
