#include <stdio.h>
#include <stdlib.h>
int main()
{
    int a[10][10],m,n,i,j,c1,c2,r1,r2,temp,flag=0,rc;
    printf("Enter value of m and n\n");
    scanf("%d%d",&m,&n);
    printf("Enter the elements of the %dx%d array\n",m,n);
    for(i=0;i<m;i++)
    {
        for(j=0;j<n;j++)
        {
            scanf("%d",&a[i][j]);
        }
    }
    printf("Enter 1 to interchange columns, and 2 to interchange rows");
    scanf("%d",&rc);
    if(rc == 1)
    {
        printf("Enter columns to be interchanged");
        scanf("%d%d",&c1,&c2);
        for(i=0;i<m;i++)
        {
            temp=a[i][c1-1];
            a[i][c1-1]=a[i][c2-1];
            a[i][c2-1]=temp;
        }
        printf("The new matrix is\n");
        for(i=0;i<m;i++)
        {
            for(j=0;j<n;j++)
            {
                printf("%d",a[i][j]);
            }
            printf("\n");
        }
        exit(0);
    }
    if (rc == 2)
    {
        printf("Enter rows to be interchanged");
        scanf("%d%d",&r1,&r2);
        for(i=0;i<m;i++)
        {
            temp=a[r1-1][j];
            a[r1-1][j]=a[r2-1][j];
            a[r2-1][j]=temp;
        }
        printf("The new matrix is\n");
        for(i=0;i<m;i++)
        {
            for(j=0;j<n;j++)
            {
                printf("%d",a[i][j]);
            }
            printf("\n");
        }
        exit(0);
    }
}