#include <stdio.h>
#include <stdlib.h>
int main()
{
    int i,j,m,n,a[4][4],temp;
    //dimensions
    printf("Enter the dimensions of the matrix");
    scanf("%d%d",&m,&n);
    //input
    printf("Enter the elements of the matiex\n");
    for(i=0;i<m;i++)
    {
        for(j=0;j<n;j++)
        {
            scanf("%d",&a[i][j]);
        }
    }
    //switching diagonals
     for(i=0;i<m;i++)
    {
        for(j=0;j<n;j++)
        {
            if(i == j)
            {
                temp=a[i][j];
                a[i][j]=a[i][n-i-1];
                a[i][n-i-1]=temp;
            }
        }
    }
    printf("The changed matrix is\n");
    for(i=0;i<m;i++)
    {
        for(j=0;j<n;j++)
        {
            printf("\n");
            printf("\t%d",a[i][j]);
        }
    }
    return 0;
}