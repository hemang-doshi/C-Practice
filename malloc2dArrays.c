#include <stdio.h>
#include <stdlib.h>



int main(){
    //method 1
    int *a[3];
    a[0]= (int *)malloc(4*sizeof(int));
    a[1]= (int *)malloc(4*sizeof(int));
    a[2]= (int *)malloc(4*sizeof(int));
    return 0;

    //method 2
    int **b;
    b = (int **)malloc(3*sizeof(int *));

    b[0]= (int *)malloc(4*sizeof(int));
    b[1]= (int *)malloc(4*sizeof(int));
    b[2]= (int *)malloc(4*sizeof(int));
}