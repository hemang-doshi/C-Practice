#include <stdio.h>
#include <stdlib.h>
int main()
{
   int i,j,p,q,m,n,a[10][10],b[10][10],c[10][10];
   printf("enter dimensionsfor a\n");
   scanf("%d %d",&m, &n);
   printf("enter dimension for b\n");
   scanf("%d %d",&p, &q);
   if (m!=p||n!=q){
    printf("Cannot add");
    exit(0);
   }
   printf("Enter the elemants for a\n");
   for(i=0;i<m;i++)
   {
    for(j=0;j<n;j++)
    {
        scanf("%d",&a[i][j]);
    }
   }
   printf("Enter the elemants for b\n");
   for(i=0;i<p;i++)
   {
    for(j=0;j<q;j++)
    {
        scanf("%d",&b[i][j]);
    }
   }
   for(i=0;i<m;i++)
   {
    for(j=0;j<n;j++)
    {
        c[i][j]=a[i][j]+b[i][j];
    }
   }
   printf("The final matrix is\n");
   for(i=0;i<m;i++)
   {
    for(j=0;j<n;j++)
    {
        printf("%d",c[i][j]);
        printf("\n");
    }
   }
   return 0;
}