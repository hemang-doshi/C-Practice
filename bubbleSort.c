#include <stdio.h>

int main(){
    int arr[100],n,temp;
    printf("Enter the number of elements in the array: \n");
    scanf("%d",&n);
    printf("Enter elements of the array: \n");
    for(int i=0;i<n;i++){
        scanf("%d",&arr[i]);
    }
    for(int i=0;i<n-1;i++){
        for(int j=0;j<n-1-i;j++){
            if(arr[j]>arr[j+1]){
                temp = arr[j];
                arr[j] = arr[j+1];
                arr[j+1]=temp;
            }
        }
    }
    printf("Sorted array: \n");
    for(int i=0;i<n;i++){
        printf("%d,",arr[i]);
    }

    return 0;
}