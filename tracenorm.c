#include<stdio.h>
#include <math.h>
int main()
{
    int trace=0,norm=0,i,j,m,n,a[10][10],sum=0;
    //dimensions
    printf("Enter dimensions of matrix\n");
    scanf("%d%d",&m,&n);
    //input
    printf("Enter elements of matrix\n");
    for(i=0;i<m;i++)
    {
        for(j=0;j<n;j++)
        {
            scanf("%d",&a[i][j]);
        }
    }
    //trace
    for(i=0;i<m;i++)
    {
         trace=trace+a[i][i];
    }
    //norm
    for(i=0;i<m;i++)
    {
        for(j=0;j<n;j++)
        {
            sum=sum+(a[i][j]*a[i][j]);
        }
    }
    norm=sqrt(sum);
    printf("The trace and the norm of the given matrix is %d and %d",trace,norm);
    return 0;
}