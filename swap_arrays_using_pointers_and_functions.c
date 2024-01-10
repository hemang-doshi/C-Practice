#include <stdio.h>
#include <stdlib.h>

void swapArrays(int *a1,int *a2){
        int temp;
        temp = *a1;
        *a1 = *a2;
        *a2 = temp;
    }

int main(){
    int arr1[5]={1,2,3,4,5};
    int arr2[5]={5,4,3,2,1};
    printf("The arrays BEFORE swap: \n");
    for(int i=0;i<5;i++){
        printf("%d ",arr1[i]);
    }
    printf("\n");
    for(int i=0;i<5;i++){
        printf("%d ",arr2[i]);
    }

    //function call

    for(int i=0;i<5;i++){
    swapArrays(&arr1[i], &arr2[i]);
    }

    //printing final result

    printf("\n");
    printf("The arrays AFTER swap: \n");
    for(int i=0;i<5;i++){
        printf("%d ",arr1[i]);
    }
    printf("\n");
    for(int i=0;i<5;i++){
        printf("%d ",arr2[i]);
    }
    return 0;
}