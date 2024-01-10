#include <stdio.h>
#include <stdlib.h>



int main(){
    int i,j,n=5;
    int **a;
    a = (int **)malloc(n*sizeof(int));
    for(i=0;i<n;i++){
        *(a+i) = (int *)malloc((i+1)*sizeof(int));
    }
    printf("Enter values of jagged array: \n");
    for(i=0;i<n;i++){
        for(j=0;j<=i;j++){
            scanf("%d",*((a+i)+j));
        }
    }
    for(i=0;i<n;i++){
        for(j=0;j<=i;j++){
            printf("%d",*(*(a+i)+j));
        }
    }

    return 0;
}