#include<stdio.h>
#include <stdlib.h>
int main()
{
    int i,j,m,n,p,q,k,a[10][10],b[10][10],c[10][10];
    //dimensions
    printf("Enter dimensions of a\n");
    scanf("%d%d",&m,&n);
    printf("Enter dimensions of b\n");
    scanf("%d%d",&p,&q);
    if(n!=p)
    {
        printf("Cannot multiply\n");
        exit(0);
    }
    //input
    printf("Enter elements of a\n");
    for(i=0;i<m;i++)
    {
        for(j=0;j<n;j++)
        {
            scanf("%d",&a[i][j]);
        }
    }
    printf("Enter elements of b\n");
    for(i=0;i<p;i++)
    {
        for(j=0;j<q;j++)
        {
            scanf("%d",&b[i][j]);
        }
    }
    //multiplication of matrices
    for(i=0;i<p;i++)
    {
        for(j=0;j<q;j++)
        {
            c[i][j]=0;
            for(k=0;k<n;k++)
            {
            c[i][j]=c[i][j]+a[i][k]*b[k][j];
            }
        }
    }
    printf("The product matrix is\n");
    for(i=0;i<m;i++)
    {
        for(j=0;j<n;j++)
        {
            printf("\t%d",c[i][j]);
            printf("\n");
        }
    }
    return 0;
}