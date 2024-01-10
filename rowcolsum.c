#include <stdio.h>
#include <stdlib.h>
int main()
{
    int i,j,m,n,a[10][10];
    int rowsum[10],colsum[10];
    printf("Enter dimensions of a\n");
    scanf("%d %d",&m,&n);
    printf("Enter elements for a\n");
    for(i=0;i<m;i++)
    {
        for(j=0;j<n;j++)
        {
            scanf("%d",&a[i][j]);
        }
    }
    for(i=0;i<m;i++)
    {
        rowsum[i]=0;
        for(j=0;j<n;j++)
        {
            rowsum[i]=rowsum[i]+a[i][j];
        }
    }
    for(j=0;j<n;j++)
    {
        colsum[j]=0;
        for(i=0;i<m;i++)
        {
            colsum[j]=colsum[j]+a[i][j];
        }
    }
    for(i=0;i<m;i++)
    {
        for(j=0;j<n;j++)
        {
            printf("\t %d",a[i][j]);
        }
        printf("\t");
        printf("%d\n",rowsum[i]);
    }
    printf("\n");
    for(i=0;i<n;i++)
    {
        printf("\t%d",colsum[i]);
    }
    return 0;
}