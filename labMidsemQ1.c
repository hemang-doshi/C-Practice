#include<stdio.h>
#include<stdlib.h>
#include<ctype.h>
typedef struct 
{
    int *marks;
    int top;
    int size;
}stack;
void sort(stack *q)
{
    int min,m,temp;
    for(int i=0;i<=q->top;i++)
    {
        min=q->marks[i];
        m=i;
        for(int j=i+1;j<=q->top;j++)
        {
            if(q->marks[j]<min)
            {
                min=q->marks[j];
                m=j;
            }
        }
        temp=q->marks[i];
        q->marks[i]=q->marks[m];
        q->marks[m]=temp;
    }
    printf("The sorted stack is: \n");
    for(int i=0;i<=q->top;i++)
    {
        printf("%d\t",q->marks[i]);
    }
    printf("\n");
}
void average(stack *q)
{
    int sum=0,avg,count=0;
    for(int i=q->top;i>=0;i--)
   {
    sum=sum+q->marks[i];
    count++;
   }
   avg=sum/count;
   printf("Average of the student's marks is %d\n",avg);
}
stack* create(int n)
{
    stack *sp;
    sp=(stack*)malloc(sizeof(stack));
    sp->marks=(int*)malloc(n*sizeof(int));
    sp->top=-1;
    sp->size=n;
    return sp;
}
void display(stack *q)
{
    for(int i=q->top;i>=0;i--)
    {
        printf("%d\t",q->marks[i]);
    }
    printf("\n");
}
void push(stack *q)
{
    int x;
    if(q->top==q->size-1)
    {
        printf("Stack overflow\n");
        display(q);
    }
    else
    {
        q->top++;
        printf("Enter no\n");
        scanf("%d",&x);
        q->marks[q->top]=x;
    }
}
void pop(stack *q)
{
    int y;
    if(q->top==-1)
    {
        printf("Stack underflow\n");
    }
    else
    {
         y=q->marks[q->top];
         q->top--;
         printf("No deleted from the stack is %d\n",y);
    }
}
int main()
{
    int n,d,no=1,key=0;
    printf("Enter no of marks of the student\n");
    scanf("%d",&n);
   stack *s=create(n);
   while(no)
   {
    printf("1-push,2-pop,3-display,4-sort,5-average\n");
    scanf("%d",&d);
    switch(d)
    {
         case 1:
         push(s);
         break;
         case 2:
         pop(s);
         break;
         case 3:
         display(s);
         break;
         case 4:
         sort(s);
         break;
         case 5:
         average(s);
         break;
    }
    printf("Do you want to continue 0 or 1\n");
    scanf("%d",&no);
    }
   return 0;
}